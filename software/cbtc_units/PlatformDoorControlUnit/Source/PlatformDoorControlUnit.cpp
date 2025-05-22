///
/// @file       PlatformDoorControlUnit.cpp
///
///             Unit keeps track of all (PSD) Platform Screen Door features. 
///             When the features state changes, then the position of the doors 
///             Starts to increment from 0-100 after state is set to open
///             Starts to decrement from 100-0 after state is set to closed.
///             Time taken by door to completely open from closed state and
///             vice versa should be 3 seconds (duration is configurable via 
///             worldmodel.ini). This unit will not do any updates to door
///             position if the PSD feature state is automate.
///
/// @ingroup    PlatformDoorControlUnit.dll
///
/// @author     Raghu Gandi
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017

#include "PlatformDoorControlUnit.h"
#include "core_data_access/Feature.h"

#include "core_comms_structure/CoreObjectConstants.h"
#include "project_features/ProjectFeatureConstants.h"

#include "cbtc_common\FeatureProperties.h"
#include "common\Callback.h"

/// @brief Constructs platform door control unit.
/// 
/// @param gateway
/// @param data_access
/// @param properties
PlatformDoorControlUnit::PlatformDoorControlUnit(Comms::Gateway &gateway,
    Common::Data::DataAccess &data_access, Common::Properties &properties)
 : SteppingUnit(gateway), m_operation_turnaround_time(DEFAULT_OPERATION_TURNAROUND_TIME), m_state_id(Sim::INVALID_NUMBER),
   m_door_position_number_id(Sim::INVALID_NUMBER)
{
    // Obtain the feature type id corresponding to the FETY_CBTC_PSD(our feature of interest)
    // and hence its state-id's
    try
    {
        //look up for screen doors type id using simulator data 
        m_PSD_feature_type_id    = Core::Database::Feature(data_access).GetFeatureType(
                                   Project::FeatureTypes::FETY_PSD).feature_type_id;
        //look up for screen doors state id using simulator data
        m_open_state_id          = Core::Database::Feature(data_access).GetFeatureTypeState(m_PSD_feature_type_id,
                                   Project::FeatureStates::OPEN).feature_type_state_id;
        m_close_state_id         = Core::Database::Feature(data_access).GetFeatureTypeState(m_PSD_feature_type_id,
                                   Project::FeatureStates::CLOSED).feature_type_state_id;
    }
    catch (CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Querying database for Platform Screen Door object information");
        throw;
    }

    // Set up the feature filter to look for platform Screen doors 
    m_PSD_filter.SetAcceptableType(m_PSD_feature_type_id);
    m_PSD_watcher.SetFeatureTypeFilter(CreateFilterCallback(m_PSD_filter));
    m_PSD_watcher.SetRequestFrequency(REQUEST_FREQUENCY);

    // Set our callback up with the watcher
    m_PSD_watcher.AddCallback(MakeCallback(&PlatformDoorControlUnit::PSDObjectCallback, this));
    {
        OS::Lock<Comms::Gateway> lock(GetGateway());
        m_PSD_watcher.Attach(GetGateway().GetRootObject());
    }

    //Set Operation Turnaround Time. This value determines how long the door will
    //take to open fully from closed state or vice versa.
    SetOperationTurnAroundTime(properties);
}

/// @brief Destroys platform door control unit.
///
PlatformDoorControlUnit::~PlatformDoorControlUnit()
{
    //Detach from root
    m_PSD_watcher.Detach();
}

/// @brief Sets Operation Turnaround Time based on the follwing:
///        1. If the section "Platform Door Control" is present in world model.ini, 
///        Sets to the value mentioned.
///        2. If the value is less than 1 or more than 10 secs, will default to 3 sec.
///        3. If the section "Platform Door Control" is missing from world model.ini,
///        will default to 3 sec.
///
/// @param properties
void PlatformDoorControlUnit::SetOperationTurnAroundTime(Common::Properties &properties)
{
    //Set door operation duration. This value determines how long the door will take to open or close.
    m_operation_turnaround_time = properties.GetProperty<double>("Platform Door Control",
                        "Operation Turnaround Time", DEFAULT_OPERATION_TURNAROUND_TIME);

    if (m_operation_turnaround_time < MINIMUM_OPERATION_TURNAROUND_TIME ||
        m_operation_turnaround_time > MAXIMUM_OPERATION_TURNAROUND_TIME)
    {
        Trace::GetLogger().STAMP(Trace::WARN) << "Insane Open Time of "
            << m_operation_turnaround_time << " Reset to 3 seconds (default)" << Trace::EndLog();
        m_operation_turnaround_time = DEFAULT_OPERATION_TURNAROUND_TIME;
    }
}

/// @brief  Monitors periodically Platform Screen Door feature at all platforms 
///         for any state change. Based on state change, updates the door position
///         number from 0 to 100 to open the door or updates the door position number 
///         from 100 to 0 to close the door in 3 secs (default).
///         This function will not do any updates to door position if the state is automate.
///
/// @param new_time This is session time. Step function will not be called when session is in paused state.
void PlatformDoorControlUnit::Step(double new_time)
{
    //RAII lock acquired. This lock is for m_PSD_objects list.
    std::lock_guard<std::mutex> lock(m_mutex);
    //Look for the state change in PSD feature at all platforms.
    std::for_each(m_PSD_objects.begin(), m_PSD_objects.end(),
    [this](PSDObject &psd_object)
    {
        OS::Lock<Comms::Gateway> lock(GetGateway());
        if(psd_object.IsValid())
        {
            int state_id = static_cast<int>(psd_object.Numbers().Store().Get(m_state_id).value);
            Sim::Number door_pos = psd_object.Numbers().Store().Get(m_door_position_number_id);
            if((m_open_state_id == state_id) || (m_close_state_id == state_id))
            {
                DoorState door_state = (m_open_state_id == state_id) ? 
                                        DoorState::OPEN_STATE : DoorState::CLOSE_STATE;
                double prev_door_pos = door_pos.value;
                door_pos.value = CalculateDoorPosition(door_state, m_operation_turnaround_time, prev_door_pos);

                // Update the value if it has changed
                if (prev_door_pos != door_pos.value)
                    psd_object.Numbers().Store().Set(door_pos);
            }
        }
    }
    );
}

/// @brief This returns the frequency at which this unit is called.
/// @return Returns the frequency at which this unit is called.
double PlatformDoorControlUnit::GetPeriod() const
{
    return PERIOD;
}

/// @brief This is the callback function registered with our feature watcher. 
///        It will notify us of every creation and destruction of a 
///        Platform Screen Doors object.
///        On creation, PSD object is added to the list.
///        On destruction, the same PSD object is removed from the list.
/// @param info Describes the feature object that has changed and reason for the change.
void PlatformDoorControlUnit::PSDObjectCallback(WorldAPI::FeatureWatcher::CallbackInfo info)
{
    //RAII lock acquired. This lock is for m_PSD_objects list.
    std::lock_guard<std::mutex> lock(m_mutex);
    //Add this PSD object to the list
    if(info.reason == WorldAPI::FeatureWatcher::CallbackInfo::CREATION)
    {
        if(Sim::INVALID_NUMBER == m_state_id)
            m_state_id = info.object.Numbers().Info().GetID(Core::ValueName::Feature::STATE);

        if(Sim::INVALID_NUMBER == m_door_position_number_id)
            m_door_position_number_id = info.object.Numbers().Info().GetID(Project::FeatureProperties::PLATFORM_SCREEN_DOORS::DOOR_POSITION);

        m_PSD_objects.push_back(info.object);
    }
    //Remove this PSD object from the list
    if(info.reason == WorldAPI::FeatureWatcher::CallbackInfo::DESTRUCTION)
    {
        psd_object_itr pos = std::find_if(m_PSD_objects.begin(), m_PSD_objects.end(),
        [info](const PSDObject &psd_object)
        {
            return (psd_object == info.object);
        }
        );
        if(pos != m_PSD_objects.end())
            m_PSD_objects.erase(pos);
    }
}
