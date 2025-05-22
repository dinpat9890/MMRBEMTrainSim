///**************************************************************************************************
/// @file         BeaconReader.cpp
///
/// Description : Unit for interfacing with the Beacon features
///
/// @author       Adam Zielinski
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************
#include "BeaconReader.h"

#include "core_data_access/Feature.h"
#include "project_features/ProjectFeatureConstants.h"

#include "project_comms_structure\ProjectObjectConstants.h"

#include "Utility/Utilities.h"

using namespace Beacon;

namespace
{
    const auto REQUEST_FREQUENCY            = 0.0;
    const auto DEFAULT_PATH_SEARCH_DISTANCE = 100.0;
    const auto DEBUG                        = false;

    const double UNKNOWN_BEACON_DETECTED    = 0.0;

    const auto UNDEFINED_DISTANCE           = std::numeric_limits<double>::infinity();

    /// Returns the value of the Feature ID of a feature object.
    ///
    /// @param object The object to get the Feature ID of.
    ///
    /// @return  The Feature ID Value corresponding to the position Number, or -1 if one does not
    ///          exist (or if the object is not a Feature).
    ///
    int GetFeatureID(Comms::Object object)
    {
        int ret;

        // Test the code in debug - we should never be calling this for a non feature object.
        assert (object.IsValid());
        assert (Core::GetClassID(object) == Core::ClassID::FEATURE);
            
        // If this object is a Feature we can look for the FEATUREID
        ret = static_cast<int>(object.Numbers().Get(Core::ValueName::Feature::FEATURE_ID).value);

        return ret;
    }

    /// Removes any beacon detection events that the train has moved past and returns the next
    /// beacon detection event to be detected
    ///
    /// @param beacon_detection_events Beacon Detection events that still need to be processed
    /// @param initial_position_offset Distance the train has travelled since the distances to the beacon detection 
    //                                 events were last determined 
    ///
    /// @returns Next Beacon detection event that is ahead of the trains current position
    ///
    BeaconReader::BeaconDetectionEvent GetNextEvent(BeaconReader::BeaconDetectionEvents  &beacon_detection_events,
                                                    double                                initial_position_offset)
    {
        // Remove any events that we have moved past
        beacon_detection_events.erase(std::remove_if(beacon_detection_events.begin(), beacon_detection_events.end(), 
                                            [&](BeaconReader::BeaconDetectionEvent event) 
                                            { 
                                                return (event.first - initial_position_offset) < 0.0; 
                                            }),
                                            beacon_detection_events.end());

        // Return the next beacon detection event if one exists or 
        if (beacon_detection_events.size() > 0)
            return beacon_detection_events.front();
        else
        {
            BeaconReader::BeaconDetectionEvent invalid_beacon_event;
            invalid_beacon_event.first = UNDEFINED_DISTANCE;
            return invalid_beacon_event;
        }
    }
}

/// Constructor
///
/// @param gateway          The comms gateway
/// @param simulator_data   Object to access the simulator database
/// @param world_access     World Access API
/// @param path_watcher     Path Watcher for the train path
///
BeaconReader::BeaconReader(Comms::Gateway                  &gateway,
                                               Common::DataAccess              &data_access,
                                               WorldAPI::WorldAccess           &world_access,
                                               WorldAPI::TrainPathWatcher      &path_watcher)
  : m_gateway(gateway), m_world_access(world_access), 
    m_train_path_watcher(path_watcher),
    m_route_changed(true)
{
    m_previous_event.first = 0.0;
    m_last_in_range_event.first = 0.0;

    m_previous_event.second.m_feature_id      = UNKNOWN_BEACON_DETECTED;
    m_last_in_range_event.second.m_feature_id = UNKNOWN_BEACON_DETECTED;

    try
    {
        // Determine the state ID of our position beacon feature types
        m_cbtc_beacon_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_CBTC_BEACON).feature_type_id;

        // Determine the ID of the states that we care about
        m_position_state_ids.m_normal_state   = Core::Database::Feature(data_access).GetFeatureTypeState(m_cbtc_beacon_id, Project::FeatureStates::NORMAL).feature_type_state_id;
        m_position_state_ids.m_faulty_state   = Core::Database::Feature(data_access).GetFeatureTypeState(m_cbtc_beacon_id, Project::FeatureStates::FAULTY).feature_type_state_id;

        m_previous_event.second.m_state_value      = m_position_state_ids.m_normal_state;
        m_last_in_range_event.second.m_state_value = m_position_state_ids.m_normal_state;

        // Determine the state ID of our position beacon feature types from depot
        m_cbtc_beacon_depot_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_CBTC_BEACON_DEPOT).feature_type_id;

        // Determine the ID of the states that we care about
        m_depot_position_state_ids.m_normal_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_cbtc_beacon_depot_id, Project::FeatureStates::NORMAL).feature_type_state_id;
        m_depot_position_state_ids.m_faulty_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_cbtc_beacon_depot_id, Project::FeatureStates::FAULTY).feature_type_state_id;

        m_previous_event.second.m_state_value      = m_depot_position_state_ids.m_normal_state;
        m_last_in_range_event.second.m_state_value = m_depot_position_state_ids.m_normal_state;

        // Set the Path watcher filter for our Position Beacon features of interest
        m_beacon_feature_type_filter.SetAcceptableTypes({ m_cbtc_beacon_id,m_cbtc_beacon_depot_id});  // Can use Initializer lists (from C++11) to create std::vector
    }
    catch(CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Failed to find required Beacon feature Id. Beacon feature states will not be updated.");
        Trace::GetLogger().LogException(e);
    }

    // Filter the feature watcher to only watch stopping points and add a callback to handle updates
    m_beacon_feature_watcher.SetFeatureTypeFilter(WorldAPI::CreateFilterCallback(m_beacon_feature_type_filter));
    m_beacon_feature_watcher.SetRequestFrequency(REQUEST_FREQUENCY);
    m_beacon_feature_watcher.AddCallback(MakeCallback(&BeaconReader::FeatureWatcherCallback, this));

    {
        const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

        auto root_object = m_gateway.GetRootObject();
        m_beacon_feature_watcher.Attach(root_object);
       
        const std::lock_guard<WorldAPI::TrainPathWatcher> path_watcher_lock(m_train_path_watcher);
        m_train_path_watcher.AddRouteChangeCallback(MakeCallback(&BeaconReader::RouteChangeDetected, this));
    }
}

/// Destructor
///
BeaconReader::~BeaconReader()
{
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
    m_beacon_feature_watcher.Detach();
}

/// Returns true when beacon reader is within the detection range of a beacon. 
/// 
/// Beacon Reader is considered as being able to detect a beacon when either
/// - Distance to the next beacon event is Less than the minimum detection range distance
/// - The train has passed the next beacon detection event location and not yet reported a detection
///
/// Last detected can be retrieved with a call to GetLastDetectedBeacon()
///
/// @param current_position  Position at which train is located
/// @param detection_range   Minimum distance a train must be away from an event before it is in range
///
/// @returns true if we are close enough to the event for it to be detected
///
bool BeaconReader::IsBeaconDetected(double current_position, double detection_range)
{
    auto event_detected = false;

    auto next_beacon_detection_event = GetNextBeaconDetectionEvent(current_position);

    // Calculate the distance to the previous event relative to the current position
    double new_distance_to_previous_event = m_previous_event.first - (current_position - m_previous_event_old_position);

    // Next event is detectable if its ahead of the train and within our detection range 
    if (next_beacon_detection_event.first <= detection_range)
    {
        m_last_in_range_event = next_beacon_detection_event;
        event_detected = true;
    }

    // Next event is detectable if we have moved past the event and it has not yet been detected
    else if ((new_distance_to_previous_event < 0.0) && (m_last_in_range_event.first != m_previous_event.first))
    {
        m_last_in_range_event.first = new_distance_to_previous_event;
        m_last_in_range_event.second = m_previous_event.second;

        event_detected = true;
    }

    m_previous_event = next_beacon_detection_event;
    m_previous_event_old_position = current_position;

    return event_detected;
}

/// Reports whether the last detected beacon was faulty
/// 
/// @returns true if the last detected beacon was faulty 
///
bool BeaconReader::IsLastDetectedBeaconFaulty()
{
    return (m_last_in_range_event.second.m_state_value == m_position_state_ids.m_faulty_state ||
            m_last_in_range_event.second.m_state_value == m_depot_position_state_ids.m_faulty_state);
}

/// Returns the beacon Id recorded in the event that was found in the last call to the IsBeaconDetected() function
/// 
/// @returns Beacon Id associated with the last event that was within detection range 
///
double BeaconReader::GetLastDetectedBeaconId()
{
    return m_last_in_range_event.second.m_feature_id;
}

/// Returns the location of the event that was found in the last call to the IsBeaconDetected() function
/// 
/// @returns location associated with the last event that was within detection range 
///
double BeaconReader::GetLastDetectedBeaconLocation()
{
    return m_last_in_range_event.first;
}

/// Returns an event describing the next beacon to be detected by the beacon reader
///
/// Beacon detection events may be for either a normal or faulty beacon detection
///
/// @param current_position Current train position
/// 
/// @returns Returns the next beacon detection event
///
BeaconReader::BeaconDetectionEvent BeaconReader::GetNextBeaconDetectionEvent(double current_position)
{
    // Update the route if it has changed
    if (m_route_changed)
    {
        // Record the position where the path was determined
        m_initial_position = current_position;
        m_previous_event_old_position = current_position;

        // Find all of the beacon features on the path ahead of a train
        m_fwd_path_beacon_features = [this]()
        {
            const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);

            if(m_train_path_watcher.HasPath())
                return m_world_access.GetPathFeatures(m_train_path_watcher.GetExtendedPath(), m_beacon_track_associations, 0.0, std::numeric_limits<double>::max());

            return std::vector<std::pair<double, Comms::Object>>();
        }();

        // Create the vector of beacon detection events on the path ahead of a train
        SetEventsVector(m_fwd_path_beacon_events, m_fwd_path_beacon_features);

        m_route_changed = false;
    }

    // Determine the next beacon detection event
    double initial_position_offset;
    BeaconDetectionEvent next_beacon_detection_event;

    {
        initial_position_offset = current_position - m_initial_position;
        next_beacon_detection_event = GetNextEvent(m_fwd_path_beacon_events, initial_position_offset);

        // Debug Logging
        if (DEBUG)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "GetNextCBTCBeaconDetetction - Number of Forward Events :  " <<  m_fwd_path_beacon_events.size() <<  "\n==================\n";  
            for (auto &event : m_fwd_path_beacon_events)
                Trace::GetLogger().STAMP(Trace::ERR) << "(" << event.first - initial_position_offset << ", "
                << event.second.m_feature_id << ", " << event.second.m_state_value << ") " ;
            Trace::GetLogger().STAMP(Trace::ERR) << Trace::EndLog();
        }
    }

    // If a beacon detection has been found then we need to update the location of the position to be relative to the
    // trains current position. Otherwise we want to leave the distance with the undefined value.
    if (next_beacon_detection_event.first != UNDEFINED_DISTANCE)
        next_beacon_detection_event.first = next_beacon_detection_event.first - initial_position_offset;

    return next_beacon_detection_event;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Functions related to feature watcher
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// This is the callback function registered with the feature watcher. It handles the actions required to
/// occur upon the creation and destruction of a beacon Feature object. 
///
/// @param callback_info Describes the feature object that has changed, and why we are being notified.
///
void BeaconReader::FeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const auto &beacon_feature_object = callback_info.object;

    if (beacon_feature_object.IsValid()) 
    {
        const auto beacon_feature_object_id = beacon_feature_object.GetID();
        assert(beacon_feature_object_id != Sim::INVALID_NUMBER);

        switch(callback_info.reason)
        {
            case WorldAPI::FeatureWatcher::CallbackInfo::CREATION:
            {
                try
                {
                    BeaconData new_beacon_feature;
                    new_beacon_feature.m_object                 = callback_info.object;
                    new_beacon_feature.m_feature_id             = GetFeatureID(callback_info.object);
                    new_beacon_feature.m_state_value            = callback_info.object.Numbers().Get(Core::ValueName::Feature::STATE).value;

                    {
                        m_feature_obj_id_to_data.insert(std::make_pair(beacon_feature_object_id, new_beacon_feature));
                        m_beacon_track_associations.AddFeature(beacon_feature_object, false);
                    }

                    m_route_changed = true;
                }
                catch(CommonException &e)
                {
                    Trace::GetLogger().LogException(e);
                    Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract properties for Beacon feature\""
                                                            << beacon_feature_object.GetName() << "\" (Object ID: " << beacon_feature_object_id
                                                            << "). This feature will be ignored." << Trace::EndLog();
                }
                break;
            }
            case WorldAPI::FeatureWatcher::CallbackInfo::DESTRUCTION:
            {
                // Remove the Beacon feature
                m_feature_obj_id_to_data.erase(beacon_feature_object_id);
                m_beacon_track_associations.RemoveFeature(beacon_feature_object);

                m_route_changed = true;
                break;
            }
            case WorldAPI::FeatureWatcher::CallbackInfo::STATE_CHANGE:
            {
                // Update the state of the Beacon feature upon a state change
                auto id_to_beacon_feature_data_iter = m_feature_obj_id_to_data.find(beacon_feature_object_id);
                if (id_to_beacon_feature_data_iter != m_feature_obj_id_to_data.end() && id_to_beacon_feature_data_iter->second.m_object.IsValid())
                {
                    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
                    id_to_beacon_feature_data_iter->second.m_state_value = beacon_feature_object.Numbers().Get(Core::ValueName::Feature::STATE).value;
                    m_route_changed = true;
                }

                break;
            }
        }
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract CBTC Beacon feature object" << Trace::EndLog();
    }
}

/// Reports the beacon detection events that appear on the path ahead of the train
///
/// @param beacon_detection_events  Beacon detection events created from the given path_beacon_features
/// @param path_beacon_features     Beacon features that appear on the path ahead of the train
///
void BeaconReader::SetEventsVector(BeaconReader::BeaconDetectionEvents                 &beacon_detection_events,
                                   const std::vector<std::pair<double, Comms::Object>> &path_beacon_features)
{
    beacon_detection_events.clear();
    for (auto &beacon : path_beacon_features)
    {
        const auto beacon_feature_object_id = beacon.second.GetID();
        assert(beacon_feature_object_id != Sim::INVALID_NUMBER);

        auto id_to_beacon_feature_data_iter = m_feature_obj_id_to_data.find(beacon_feature_object_id);

        if (id_to_beacon_feature_data_iter != m_feature_obj_id_to_data.end() && 
            id_to_beacon_feature_data_iter->second.m_object.IsValid())
        {
            auto beacon_position = beacon.first;
            auto beacon_event = id_to_beacon_feature_data_iter->second;

            beacon_detection_events.emplace_back(BeaconDetectionEvent(beacon_position, beacon_event));
        }
    }
}


/// Sets the flag that indicates that the train path has changed 
///
void BeaconReader::RouteChangeDetected()
{
    m_route_changed = true;
}
