///**************************************************************************************************
/// @file         TrackEventsUnit.cpp
///
/// Description : Unit for reporting track events that need to be sent to be reported by the CBTC Onboard
///
/// @author       Adam Zielinski
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************

#include "TrackEventsUnit.h"

#include "Project/FeatureNames.h"

#include "Project/Utilities/ScenarioTrainLengthService.h"
#include "train_data_access/TrainDataAccess.h"
#include "train_data_access/TrainDataAccessTypes.h"

#include "common/StandardLogging.h"

#include "Project/Utilities/IsLeadVehicle.h"
#include "Utility/Utilities.h"


namespace
{
    // Constants
    const auto STEP_REQUEST_FREQUENCY   = 1.0;
    const auto STEP_PERIOD              = 1.0 / STEP_REQUEST_FREQUENCY;
    const auto COMMS_REQUEST_FREQUENCY  = 0.0;
    
    const auto DEBUG                    = false;
}

/// Constructor
///
/// @param gateway            The comms gateway
/// @param data_access        Object to access the simulator database
/// @param world_access       Object to access World Access data
/// @param path_watcher       Object to access features on the trains path
/// @param scenario_train_id  Identifies the scenario train
///
TrackEventsUnit::TrackEventsUnit(Comms::Gateway                  &gateway, 
                                 Common::DataAccess              &data_access,
                                 WorldAPI::WorldAccess           &world_access,
                                 WorldAPI::TrainPathWatcher      &path_watcher,
                                 const double                     max_look_ahead,
                                 const double                     transition_zone_length,
                                 int                              scenario_train_id)
    : Comms::SteppingUnit(gateway),
      m_gateway(gateway),
      m_scenario_train_id(scenario_train_id),
      m_feature_region_data(gateway, data_access, world_access, path_watcher, max_look_ahead),
      m_stopping_point_data(gateway, data_access, world_access, path_watcher),
      m_work_zone_data(gateway, data_access, world_access, path_watcher,
                       ((new ScenarioTrainLengthService(gateway.GetScenarioData<Core::BaseScenarioData>().data.scenario_id, Train::Database::Train(data_access)))->GetTrainLength(scenario_train_id))),
      m_transition_zone_length(transition_zone_length)
{
    // We need a lock to access the root object
    OS::Lock<Comms::Gateway> lock(m_gateway);

    AddCreationCallback(m_gateway.GetRootObject(), [this](Comms::Object object) { this->RootChildCreated(object); });
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "TrackEventsUnit - Started" << Trace::EndLog();
}

/// Destructor
///
TrackEventsUnit::~TrackEventsUnit()
{
    OS::Lock<Comms::Gateway> lock(m_gateway);

    // Unmap all of our mapped Comms Objects and cancel the step function
    m_cbtc_onboard_inputs_object.UnMapCBTCOnboardInputsObject();
}

/// Returns a string holding the name of this unit.
///
std::string TrackEventsUnit::GetName() const
{
    return "Track Events Unit";
}

/// Called to perform the actions that need to be done periodically
///
/// @param current_time Time at which the function was scheduled for execution
///
/// @returns scheduled time at which this function is be next executed
///
void TrackEventsUnit::Step(double current_time)
{
    // Updating our model. Make sure that we have the lock
    OS::Lock<Comms::Gateway> lock(m_gateway);

    // Make sure that the unit has completed initialisation before continuing
    if (!CommsInitialisationCompleted())
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "TrackEventsUnit - Unit is Missing all required objects" << Trace::EndLog();
        return;
    }

    auto current_train_position = m_lead_vehicle_object.Numbers().Store().Get(m_position_id).value;

    // Get the current values of the CBTC Onboard Inputs Comms objects
    m_cbtc_onboard_inputs_object.Get();

    // handle detection and reporting of CBTC Track Events
    {
        m_track_event_map.clear();

        auto stopping_points = m_stopping_point_data.GetAllStoppingPointData(0, std::numeric_limits<double>::max());

        // Add all of the stopping point related track events (Skip, Change of Ends)
        for (auto &stopping_point : stopping_points)
        {
            CBTC::Protos::TrackEventList_TrackEvent track_event_data;
            track_event_data.set_distance(stopping_point.first);

            bool add_driver_event = false;
            if (stopping_point.second.IsSkip())
            {
                track_event_data.set_event(CBTC::Protos::TrackEventType::SKIP);
                track_event_data.set_station_code(stopping_point.second.GetStationCode());
                add_driver_event = true;
            }
            else if (stopping_point.second.IsChangeOfEnds())
            {
                track_event_data.set_event(CBTC::Protos::TrackEventType::CHANGE_OF_ENDS);
                track_event_data.set_station_code(stopping_point.second.GetStationCode());
                add_driver_event = true;
            }

            if (add_driver_event)
                m_track_event_map.insert(std::pair<double, CBTC::Protos::TrackEventList_TrackEvent>(stopping_point.first, track_event_data));
        }

        // Report when train is transitioning into automatic region
        Comms::Object region_object;
        if (m_feature_region_data.TrainTransitioningIntoFeatureRegion(m_scenario_train_id, m_transition_zone_length, FeatureInterfaces::FeatureRegion::RegionType::AUTOMATIC, region_object))
        {
            CBTC::Protos::TrackEventList_TrackEvent track_event_data;
            track_event_data.set_distance(0.0);
            track_event_data.set_event(CBTC::Protos::TrackEventType::ENTER_AUTOMATIC);

            // TBD - currently can only report this event once inside transition region and we do not know the length of the remaining transition region
            // This may or may not be important and we may be able to use sign features in order to determine this information

            m_track_event_map.insert(std::pair<double, CBTC::Protos::TrackEventList_TrackEvent>(0.0, track_event_data));
        }

        // Report when train is transitioning out of automatic region
        auto distance_to_end_of_automatic = m_feature_region_data.GetDistanceToFeatureRegionEnd(m_scenario_train_id, FeatureInterfaces::FeatureRegion::RegionType::AUTOMATIC);
        if ((distance_to_end_of_automatic <= m_transition_zone_length) &&
            (distance_to_end_of_automatic >= 0.0))
        {
            CBTC::Protos::TrackEventList_TrackEvent track_event_data;
            track_event_data.set_distance(0.0);
            track_event_data.set_event(CBTC::Protos::TrackEventType::EXIT_AUTOMATIC);
            track_event_data.set_length(distance_to_end_of_automatic);

            m_track_event_map.insert(std::pair<double, CBTC::Protos::TrackEventList_TrackEvent>(0.0, track_event_data));
        }

        // Add work zone related event
        auto next_work_zone = m_work_zone_data.GetNextWorkZoneData(current_train_position);
        if (next_work_zone.second.IsValid())
        {
            auto length_of_work_zone = next_work_zone.second.GetRemainingRegionLength(current_train_position);
            auto distance_to_work_zone = next_work_zone.second.GetDistanceToWorkZone(current_train_position);

            CBTC::Protos::TrackEventList_TrackEvent track_event_data;
            track_event_data.set_distance(distance_to_work_zone);
            track_event_data.set_event(CBTC::Protos::TrackEventType::WORK_ZONE);
            track_event_data.set_length(length_of_work_zone);

            m_track_event_map.insert(std::pair<double, CBTC::Protos::TrackEventList_TrackEvent>(distance_to_work_zone, track_event_data));
        }
    }

    // Send updates if any CBTC Onboard Inputs properties have been updated
    m_cbtc_onboard_inputs_object.SetTrackEventsRaw(current_train_position, m_track_event_map);
    m_cbtc_onboard_inputs_object.Set();
}


/// Gets the period of the step function
///
double TrackEventsUnit::GetPeriod() const
{
    return STEP_PERIOD;
}


///////////////////////////////////////////////////////////////////////////////////////////
// COMMS Object functions
///////////////////////////////////////////////////////////////////////////////////////////

/// Callback to handle creation of the Root object
///
/// @param object : Root Object
///
void TrackEventsUnit::RootChildCreated(Comms::Object object)
{
    if(Core::GetClassID(object) == Core::ClassID::WORLD)
        AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
}

/// Callback to handle creation of the COMMS objects
///
/// @param object : Comms Object that triggered the creation callback
///
void TrackEventsUnit::CommsObjectCreated(Comms::Object object)
{
    int class_id = Core::GetClassID(object);

    if (class_id == Train::ClassID::TRAIN)
    {
        // This is the train we are interested in
        double scenario_train_id = object.Numbers().Get(Project::ValueName::Train::SCENARIO_TRAIN_ID);

        if (scenario_train_id == m_scenario_train_id)
            AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
    }
    else if (class_id ==  Train::ClassID::VEHICLE)
    {
        if (Sim::Project::IsLeadVehicle(object))
        {
            m_lead_vehicle_object = object;
            m_position_id         = object.Numbers().Info().GetID(Train::ValueName::Vehicle::TDO_VEHICLE_POSITION);
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(m_position_id), COMMS_REQUEST_FREQUENCY);

            AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
            AddDestructionCallback(m_gateway.GetRootObject(), [this](Comms::Object object) { this->CommsObjectDestroyed(object); });
        }
    }
    else if (class_id == Project::ClassID::CBTC_ONBOARD_INPUTS)
    {
        m_cbtc_onboard_inputs_object.MapCBTCOnboardInputsObject(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(m_gateway.GetRootObject(), [this](Comms::Object object) { this->CommsObjectDestroyed(object); });
    }
}

/// Handles any invalidations that need to occur when an object is destroyed
///
/// @param object The object that was destroyed
///
void TrackEventsUnit::CommsObjectDestroyed(Comms::Object object)
{
    if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS)
        m_cbtc_onboard_inputs_object.UnMapCBTCOnboardInputsObject();

    else if (Core::GetClassID(object) == Train::ClassID::VEHICLE)
    {
        if(m_lead_vehicle_object == object)
            m_lead_vehicle_object.Invalidate();
    }
}

/// Return true if Comms initialisation has completed
///
/// @returns true if all required objects have been created
///
bool TrackEventsUnit::CommsInitialisationCompleted()
{
    return (m_cbtc_onboard_inputs_object.IsValid() &&
        m_lead_vehicle_object.IsValid() && 
        (m_position_id != Sim::INVALID_NUMBER));
}

