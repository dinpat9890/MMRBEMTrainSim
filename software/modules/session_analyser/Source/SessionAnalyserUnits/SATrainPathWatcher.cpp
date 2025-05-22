///
/// @file       SATrainPathWatcher.cpp
///
///             Definition of a watcher of trains with features special to
///             the session analyser
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///
#include "SATrainPathWatcher.h"

#include <train_comms_structure/TrainObjectConstants.h>
#include <utility/Utilities.h>
#include <common/StandardLogging.h>

/// Constructor. Initializes current time position to (0, 0) and register callbacks for train
/// creation and position change
///
/// @note
///     Bug 23461 doesn't like us watching auto-trains that have the scenario train ID
///     that we are looking for. To fix this ScenarioTrainPathWatcher was modified to
///     be more discerning in this regard, and we just have to specify in its
///     constructor that we are only interested in simulated trains.
///
/// @param gateway            Gateway, used for root object and timing
/// @param world_access       World Access. Required for duration of object
/// @param points_watcher     Points Watcher. Required for duration of object
/// @param request_frequency  requests on lead vehicle position at this frequency
/// @param scenario_train_id  Scenario Train ID of the train to watch

SATrainPathWatcher::SATrainPathWatcher(Comms::Gateway &gateway, WorldAPI::WorldAccess &world_access,
                                       WorldAPI::PointsWatcher &points_watcher, double request_frequency,
                                       int scenario_train_id)
    : ScenarioTrainPathWatcher(world_access, points_watcher, request_frequency, gateway.GetRootObject(), scenario_train_id, ScenarioTrainPathWatcher::SIMULATED_TRAIN)
    , m_gateway(gateway)
    , m_request_frequency(request_frequency)
{
    // Initial time and position is 0.0 when no position has been found
    m_position_number.value = 0.0;
    m_time                  = 0.0;

    {
        m_satpw_train_creation_cb_id = Core::Locked<SATrainPathWatcher>(*this)->AddTrainCreationCallback(MakeCallback(&SATrainPathWatcher::TrainCreation, this));
        m_satpw_route_change_cb_id   = Core::Locked<SATrainPathWatcher>(*this)->AddPositionChangeCallback(MakeCallback(&SATrainPathWatcher::PositionChanged, this));
    }
}

/// Destructor. Removes callbacks, cancels requests, cleans up on callbacks

SATrainPathWatcher::~SATrainPathWatcher()
{
    Core::Locked<SATrainPathWatcher>(*this)->RemoveTrainCreationCallback(m_satpw_train_creation_cb_id);
    Core::Locked<SATrainPathWatcher>(*this)->RemoveRouteChangeCallback(m_satpw_route_change_cb_id);

    if (m_vehicle_object.IsValid())
    {
        m_vehicle_object.Numbers().Store().Cancel(m_position_number.id);
        m_vehicle_object.Invalidate();
    }

    for (auto &time_position_cb : m_timeposition_change_cb)
    {
        delete time_position_cb; 
    }
}

/// The train to be watched has been created. Register for creation of its children.

void SATrainPathWatcher::TrainCreation(Comms::Object object)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    AddCreationCallback(object, [&](Comms::Object object){ TrainChildCreation(object); });
}

/// A child of the train has been created. If it is a vehicle with index 0 (the lead vehicle),
/// then we request and retrieve on its position.

void SATrainPathWatcher::TrainChildCreation(Comms::Object object)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (Core::GetClassID(object) == Train::ClassID::VEHICLE)
    {
        // Only use the lead vehicle
        try
        {
            if (object.Numbers().Get(Train::ValueName::Vehicle::INDEX).value == 0)
            {
                m_position_number = object.Numbers().Get(Train::ValueName::Vehicle::TDO_VEHICLE_POSITION);
                Sim::NumberInfo info = object.Numbers().Info().GetInfo(m_position_number.id);

                object.Numbers().Store().Retrieve(m_position_number);
                object.Numbers().Store().Request(info, m_request_frequency);

                // No exceptions, so we have an updateable position. This will
                // be updated in synchronization with the track position.
                m_vehicle_object = object;
            }
        }
        catch(CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "Getting vehicle index");
            Trace::g_plog->LogException(e);
        }
    }
    else if (Core::GetClassID(object) == Train::ClassID::SPEED_LIMIT)
    {
        // Try and resolve the speed limit number
        const auto speed_limit_number_id = object.Numbers().Info().GetID(Train::ValueName::SpeedLimit::MAX_ALLOWABLE_SPEED);
        if (speed_limit_number_id != Sim::INVALID_NUMBER)
        {
            m_speed_limit_object       = object;
            m_speed_limit_number.id    = speed_limit_number_id;
            m_speed_limit_number.value = object.Numbers().Store().Get(speed_limit_number_id).value;

            // Request for updates of this
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(speed_limit_number_id), m_request_frequency);
        }
    }
}

/// Start position of the path has changed. The linear position can now be updated along with the
/// current system time. Registered callbacks are called.

void SATrainPathWatcher::PositionChanged()
{
    // If the position changed our speed limit may have too, so update that
    if (m_speed_limit_object.IsValid())
    {
        m_speed_limit_object.Numbers().Store().Get(m_speed_limit_number); 
    }

    if (m_vehicle_object.IsValid())
    {
        m_time = m_gateway.GetTiming().GetCurrentSysTime();
        m_vehicle_object.Numbers().Store().Get(m_position_number);

        std::for_each(m_timeposition_change_cb.begin(), m_timeposition_change_cb.end(), std::mem_fn(&Callback<void, void>::operator()));
    }
}

/// External trigger to update the synchronized time position to use the current time. Registered
/// callbacks are called.

void SATrainPathWatcher::NextPeriod()
{
    // We obtain the lock here for the path watcher. Whilst this may seem unnecessary, it is important
    // that we provide the same locking conditions for time position change callbacks. If this wasn't here
    // and a TimePositionChangedCallback attempted to obtain the PathWatcher mutex, a deadlock is possible.
    // We could have the case where 1 thread enters this class via PositionChanged, and is attempting to obtain
    // the m_mutex and already has the PathWatcher mutex. Another thread is in this function and has m_mutex but
    // is attempting to obtain the PathWatcher mutex inside the TimePositionChange callback. Boom. Deadlock.
    // See https://adl-atlassian.corp.knorr-bremse.com/jira/browse/CMDL-3071 for details.
    // Whilst this is not the most elegant solution since we are preemptively acquiring a lock that we "may" not
    // need, it is the safest. Please do not change the following lines of code ordering - we must acquire the
    // PathWatcher lock prior to m_mutex.

    const auto LOCK = Lock();

    // Independent update of time with position left as is
    m_time = m_gateway.GetTiming().GetCurrentSysTime();

    // Copying callbacks so we don't need to hold mutex when executing.
    std::vector<Callback<void,void> *> callbacks;
    {
        std::lock_guard<std::mutex> mutex(m_mutex);
        callbacks = m_timeposition_change_cb;
    }
    // Must be executed outside the mutex to eliminate re-entrant code
    for_each(callbacks.begin(), callbacks.end(), std::mem_fn(&Callback<void, void>::operator()));
}

/// Gets the time of the (time, position) synchronized pair

double SATrainPathWatcher::GetTime() const
{
    return m_time;
}

/// Gets the position of the (time, position) synchronized pair

double SATrainPathWatcher::GetPosition() const
{
    return m_position_number.value;
}

/// Gets the current speed limit of the train, as reported in Comms

double SATrainPathWatcher::GetSpeedLimit() const
{
    return m_speed_limit_number.value;
}

/// Adds a time position callback. This is notified whenever the position or system time changes.
///
/// @param cb  callback to add

void SATrainPathWatcher::AddTimePositionCallback(const Callback<void,void> &cb)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    m_timeposition_change_cb.push_back(cb.Clone());
}

/// Removes a time position callback. This is notified whenever the position or system time changes.
///
/// @param cb  callback to remove

void SATrainPathWatcher::RemoveTimePositionCallback(const Callback<void,void> &cb)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    for (std::vector<Callback<void,void> *>::iterator iter = m_timeposition_change_cb.begin(); iter != m_timeposition_change_cb.end(); ++iter)
    {
        if (**iter == cb)
        {
            delete *iter;
            m_timeposition_change_cb.erase(iter);
            break;
        }
    }
}
