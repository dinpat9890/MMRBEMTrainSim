///**************************************************************************************************
/// @file StoppingPoint.h
///
/// @author    Adam zielinski
///
/// @copyright © SYDAC Pty Ltd, 2020
///**************************************************************************************************

#include "StoppingPointFeature.h"

#include "core_data_access/Feature.h"

#include "core_comms_structure/CoreObjectConstants.h"
#include "project_features/ProjectFeatureConstants.h"

#include "cbtc_common/FeatureProperties.h"

#include "project/Utilities/RawToString.h"

#include "Utility/Utilities.h"

#include "train_comms_structure\TrainObjectConstants.h"
namespace
{
    const auto REQUEST_FREQUENCY   = 4.0;
    const auto INVALID_PLATFORM_ID = -1;

    const auto MAX_LOOKAHEAD_DISTANCE = 1000;
    /// Returns the value of the Feature ID of a feature object.
    ///
    /// @param object The object to get the Feature ID of.
    ///
    /// @return  The Feature ID Value corresponding to the position Number, or -1 if one does not
    ///          exist (or if the object is not a Feature).
    int GetFeatureID(Comms::Object object)
    {
        int ret = -1;

        // Test the code in debug - we should never be calling this for a non feature object.
        assert(object.IsValid());
        assert(Core::GetClassID(object) == Core::ClassID::FEATURE);

        // If this object is a Feature we can look for the FEATUREID
        ret = static_cast<int>(object.Numbers().Get(Core::ValueName::Feature::FEATURE_ID).value);

        return ret;
    }
}

using namespace FeatureInterfaces;

/// Constructor
///
/// @param gateway          The comms gateway
/// @param simulator_data   Object to access the simulator database
/// @param world_access     World Access API
/// @param path_watcher     Path Watcher for the train path
///
StoppingPoint::StoppingPoint(Comms::Gateway&             gateway,
                             Common::Data::DataAccess&   data_access,
                             WorldAPI::WorldAccess&      world_access,
                             WorldAPI::TrainPathWatcher& path_watcher)
  : m_gateway(gateway)
  , m_world_access(world_access)
  , m_train_path_watcher(path_watcher)
  , m_feature_region_data(gateway, data_access, world_access, path_watcher, MAX_LOOKAHEAD_DISTANCE)
  
{
    try
    {
        // We need a lock to access the root object
        const OS::Lock<Comms::Gateway> COMMS_LOCK(gateway);

        AddCreationCallback(gateway.GetRootObject(), [this](Comms::Object object) { this->RootChildCreated(object); });

        // Determine the ID of our stpping point feature type
        auto stopping_point_id =
          Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_STOPPING_POINT).feature_type_id;

        // Determine the ID of the states that we care about
        m_sp_state_ids.m_sp_skip_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::SKIP).feature_type_state_id;
        m_sp_state_ids.m_sp_hold_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::HOLD).feature_type_state_id;
        m_sp_state_ids.m_sp_emergency_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::EMERGENCY).feature_type_state_id;
        m_sp_state_ids.m_sp_turnback_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::TURNBACK).feature_type_state_id;
        m_sp_state_ids.m_sp_0sec_state = Core::Database::Feature(data_access)
                                           .GetFeatureTypeState(stopping_point_id, Project::FeatureStates::IMMEDIATE_DEPARTURE)
                                           .feature_type_state_id;
        m_sp_state_ids.m_sp_inactive_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::INACTIVE).feature_type_state_id;
        m_sp_state_ids.m_sp_5sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D5_SEC).feature_type_state_id;
        m_sp_state_ids.m_sp_10sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D10_SEC).feature_type_state_id;
        m_sp_state_ids.m_sp_15sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D15_SEC).feature_type_state_id;
        m_sp_state_ids.m_sp_20sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D20_SEC).feature_type_state_id;
        m_sp_state_ids.m_sp_25sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D25_SEC).feature_type_state_id;
        m_sp_state_ids.m_sp_30sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D30_SEC).feature_type_state_id;
        m_sp_state_ids.m_sp_45sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D45_SEC).feature_type_state_id;
        m_sp_state_ids.m_sp_60sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D60_SEC).feature_type_state_id;
        m_sp_state_ids.m_sp_90sec_state =
          Core::Database::Feature(data_access).GetFeatureTypeState(stopping_point_id, Project::FeatureStates::D90_SEC).feature_type_state_id;

        m_sp_feature_type_filter.SetAcceptableType(stopping_point_id);
    }
    catch (CommonException& e)
    {
        e.AddStackTrace(FLSTAMP, "Failed to find required Stopping Point feature Id. Stopping Point feature states will not be updated.");
        Trace::GetLogger().LogException(e);
    }

    // Filter the feature watcher to only watch stopping points and add a callback to handle updates
    m_sp_feature_watcher.SetFeatureTypeFilter(WorldAPI::CreateFilterCallback(m_sp_feature_type_filter));
    m_sp_feature_watcher.SetRequestFrequency(REQUEST_FREQUENCY);
    m_sp_feature_watcher.AddCallback(MakeCallback(&StoppingPoint::SPFeatureWatcherCallback, this));

    {
        const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
        m_sp_feature_watcher.Attach(m_gateway.GetRootObject());
    }
}

/// Destructor
///
StoppingPoint::~StoppingPoint()
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
    m_sp_feature_watcher.Detach();
}
///////////////////////////////////////////////////////////////////////////////////////////
// COMMS Object functions
///////////////////////////////////////////////////////////////////////////////////////////

/// Callback to handle creation of the Root object
///
/// @param object : Root Object
///
void StoppingPoint::RootChildCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    int class_id = Core::GetClassID(object);
    if (class_id == Core::ClassID::WORLD)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Core::ClassID::WORLD" << Trace::EndLog();
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
    }
}

/// Callback to handle creation of a Comms Child object
///
/// @param object : Comms Object
///
void StoppingPoint::ObjectCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);
    int                               class_id = Core::GetClassID(object);

    if (class_id == Train::ClassID::TRAIN)
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });    
    else if (class_id == Train::ClassID::VEHICLE)
    {
        m_number_of_cars++;
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); }); 
	}  
	if (m_number_of_cars == 6)
        m_index_of_ssp = Project::FeatureProperties::NUM_OF_CARS::SIX_CARS;
    else if (m_number_of_cars == 8)
        m_index_of_ssp = Project::FeatureProperties::NUM_OF_CARS::EIGHT_CARS;  
}
/*/// Handles any invalidations that need to occur when an object is destroyed
///
/// @param object this is the object that was destroyed
///
void StoppingPoint::ObjectDestroyed(Comms::Object object)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    int                         class_id = Core::GetClassID(object);
    // delete object;
    // if (Core::GetClassID(object) == Train::ClassID::TRAIN)
    //    m_mapped_train_inputs.UnMapTrainInputs();
}*/
/// Returns the feature data for the first stopping point feature, found between the
/// given start and end points
///
/// @param start_position    Start Point of the search path
/// @param end_position      End Point of the search path
///
/// @returns feature data about the Stopping point feature which is in the emergency state
///
StoppingPoint::StoppingPointFeatureOnPath StoppingPoint::GetNextStoppingPointData(double start_position, double end_position, int m_scenario_train_id)
{
    const std::lock_guard<std::mutex>     DATA_MEMBER_LOCK(m_mutex);
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    StoppingPoint::StoppingPointFeatureOnPath first_stopping_point;

    // Find all of the stopping points between the given start and stop position
    std::vector<std::pair<double, Comms::Object>> sp_features_found;
    {
        // Features on the train path
        sp_features_found = [&]()
        {
            const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);

            if (m_train_path_watcher.HasPath())
            {
                const WorldAPI::SegmentPath& path = m_train_path_watcher.GetExtendedPath();
                return m_world_access.GetPathFeatures(path, m_track_associations, start_position, end_position);
            }

            return std::vector<std::pair<double, Comms::Object>>();
        }();
    }

    try
    {
        // Find the train id to bifuricate the stopping for the 6 car train and 8 car train
        // m__train_vehicle_count_id =Traintype = 1 for 6car and 2 for 8 car
        // Find the first stopping point within the identified train path area
        if (sp_features_found.size() > 0)
        {
            for (auto& sp : sp_features_found)
            {

                Comms::Object region_object;
                auto&   sp_front = sp;
                if (m_feature_region_data.TrainFrontWithinFeatureRegion(
                      m_scenario_train_id, FeatureRegion::RegionType::STATION, region_object))
                {
                    sp_front = sp_features_found.at(m_index_of_ssp); 
                }
                else
                {
                    sp_front = sp;
                }
                //const auto& sp_front     = sp ;//sp_features_found.at(m_index_of_ssp); // front();
                const auto  sp_dist      = sp_front.first;
                const auto& sp_object    = sp_front.second;
                const auto& sp_object_id = sp_object.GetID();
                const auto  sp_data      = m_feature_obj_id_to_sp_data[sp_object_id];

                // Skip the stopping point that is in the Inactive state
                if (!sp_data.IsInactive())
                {
                    first_stopping_point.first  = sp_dist;
                    first_stopping_point.second = sp_data;
                    break;
                }
            }
        }
    }
    catch (std::exception& ex) // Couldn't figure out the stopping point data for this stopping point id.
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "GetNextStoppingPointData ERROR : " << ex.what() << Trace::EndLog();
    }

    return first_stopping_point;
}

/// Returns all stopping point feature data found between the given start and end points
///
/// @param start_position    Start Point of the search path
/// @param end_position      End Point of the search path
///
/// @returns all stopping point feature data that appears in our search area
///
std::vector<StoppingPoint::StoppingPointFeatureOnPath> StoppingPoint::GetAllStoppingPointData(double start_position, double end_position)
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    std::vector<StoppingPoint::StoppingPointFeatureOnPath> stopping_points_on_path;

    // Find all of the stopping points between the given start and stop position
    std::vector<std::pair<double, Comms::Object>> sp_features_found;
    {
        // Features on the train path
        sp_features_found = [&]()
        {
            const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);

            if (m_train_path_watcher.HasPath())
                return m_world_access.GetPathFeatures(
                  m_train_path_watcher.GetExtendedPath(), m_track_associations, start_position, end_position);

            return std::vector<std::pair<double, Comms::Object>>();
        }();
    }

    try
    {
        // Find the stopping point features that appear within the identified train path area
        // For MMRBEM m_train_vehcl_coundid =0 for 6car and 1 for 8car
        for (auto& sp_feature : sp_features_found)
        {
            const auto& sp_front  = sp_features_found.at(m_index_of_ssp); // front();
            const auto& sp_object = sp_front.second;
            const auto  sp_data   = m_feature_obj_id_to_sp_data.at(sp_object.GetID());
            stopping_points_on_path.push_back(std::pair<double, FeatureData>(sp_front.first, sp_data));
        }
    }
    catch (std::exception& ex) // Couldn't figure out the stopping point data for this stopping point id.
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "GetNextStoppingPointData ERROR : " << ex.what() << Trace::EndLog();
    }

    return stopping_points_on_path;
}

/// This is the callback function registered with the feature watcher. It handles the actions required to
/// occur upon the creation and destruction of a stopping point object.
///
/// @param callback_info Describes the feature object that has changed, and why we are being notified.
///
void StoppingPoint::SPFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const auto& stopping_point_object = callback_info.object;

    if (stopping_point_object.IsValid())
    {
        const auto stopping_point_object_id = stopping_point_object.GetID();
        assert(stopping_point_object_id != Sim::INVALID_NUMBER);

        switch (callback_info.reason)
        {
        case WorldAPI::FeatureWatcher::CallbackInfo::CREATION:
        {
            try
            {
                auto platform_id_property_id = callback_info.object.Numbers().Info().GetID(
                  Project::FeatureProperties::STOPPING_POINT::PLATFORM_FEATURE_ID);
                auto csde_code_property_id = callback_info.object.Numbers().Info().GetID(
                  Project::FeatureProperties::STOPPING_POINT::CSDE_CODE);
                auto station_code_property_id = callback_info.object.Raws().Info().GetID(
                  Project::FeatureProperties::STOPPING_POINT::STATION_CODE);

                // Only add the stopping point if all the required properties have been defined
                if (platform_id_property_id != Sim::INVALID_NUMBER && csde_code_property_id != Sim::INVALID_NUMBER &&
                    station_code_property_id != Sim::INVALID_NUMBER)
                {
                    // Add the new Stopping Point feature into our feature data map and the track path associations
                    FeatureData new_stopping_point;
                    new_stopping_point.m_object     = stopping_point_object;
                    new_stopping_point.m_feature_id = GetFeatureID(stopping_point_object);
                    new_stopping_point.m_state_number = stopping_point_object.Numbers().Get(Core::ValueName::Feature::STATE);
                    new_stopping_point.m_is_valid          = true;
                    new_stopping_point.m_state_ids         = m_sp_state_ids;
                    new_stopping_point.platform_feature_id = stopping_point_object.Numbers()
                                                               .Get(Project::FeatureProperties::STOPPING_POINT::PLATFORM_FEATURE_ID)
                                                               .value;
                    new_stopping_point.csde_code =
                      stopping_point_object.Numbers().Get(Project::FeatureProperties::STOPPING_POINT::CSDE_CODE).value;
                    new_stopping_point.station_code = Comms::Project::RawToString(
                      stopping_point_object.Raws().Get(Project::FeatureProperties::STOPPING_POINT::STATION_CODE));

                    {
                        const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

                        m_feature_obj_id_to_sp_data.insert(std::make_pair(stopping_point_object_id, new_stopping_point));
                        m_track_associations.AddFeature(stopping_point_object);
                    }
                }
                else
                {
                    Trace::GetLogger().STAMP(Trace::ERR) << "Stopping Point '" << callback_info.object.GetName() << "' found without '";
                    if (platform_id_property_id == Sim::INVALID_NUMBER)
                        Trace::GetLogger().STAMP(Trace::ERR)
                          << Project::FeatureProperties::STOPPING_POINT::PLATFORM_FEATURE_ID << "  ";
                    if (csde_code_property_id == Sim::INVALID_NUMBER)
                        Trace::GetLogger().STAMP(Trace::ERR) << Project::FeatureProperties::STOPPING_POINT::CSDE_CODE << "  ";
                    if (station_code_property_id == Sim::INVALID_NUMBER)
                        Trace::GetLogger().STAMP(Trace::ERR) << Project::FeatureProperties::STOPPING_POINT::STATION_CODE << "  ";
                    Trace::GetLogger().STAMP(Trace::ERR) << "' property!" << Trace::EndLog();
                }
            }
            catch (CommonException& e)
            {
                Trace::GetLogger().LogException(e);
                Trace::GetLogger().STAMP(Trace::ERR)
                  << "Failed to extract properties for Stopping point feature\"" << stopping_point_object.GetName()
                  << "\" (Object ID: " << stopping_point_object_id << "). This feature will be ignored." << Trace::EndLog();
            }

            break;
        }
        case WorldAPI::FeatureWatcher::CallbackInfo::DESTRUCTION:
        {
            // Remove the Stopping Point feature from our feature data map and the track path associations
            const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);
            m_feature_obj_id_to_sp_data.erase(stopping_point_object_id);
            m_track_associations.RemoveFeature(stopping_point_object);

            break;
        }
        case WorldAPI::FeatureWatcher::CallbackInfo::STATE_CHANGE:
        {
            const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

            // Update the state of the stopping point feature upon a state change
            auto id_to_sp_feature_data_iter = m_feature_obj_id_to_sp_data.find(stopping_point_object_id);
            if (id_to_sp_feature_data_iter != m_feature_obj_id_to_sp_data.end() &&
                id_to_sp_feature_data_iter->second.m_object.IsValid())
            {
                // The feature watcher fires a callback when a feature changes.
                // Read the data directly into the "m_feature_obj_id_to_sp_data" map.
                const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
                id_to_sp_feature_data_iter->second.m_object.Numbers().Store().Get(id_to_sp_feature_data_iter->second.m_state_number);
            }

            break;
        }
        }
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract Stopping Point feature object" << Trace::EndLog();
    }
}

/// Returns the number of seconds that the train is to dwell at the next station
///
/// @returns stopping point dwell time
/// Turnback state is also stopping point. Before turnback car should dock and passenger exchange should be performed
double StoppingPoint::FeatureData::GetDwellTime()
{
    if (!m_is_valid)
        return -1;

    if (m_state_number.value == m_state_ids.m_sp_0sec_state)
        return 0.0;
    else if (m_state_number.value == m_state_ids.m_sp_5sec_state)
        return 5.0;
    else if (m_state_number.value == m_state_ids.m_sp_10sec_state)
        return 10.0;
    else if (m_state_number.value == m_state_ids.m_sp_15sec_state)
        return 15.0;
    else if (m_state_number.value == m_state_ids.m_sp_20sec_state)
        return 20.0;
    else if (m_state_number.value == m_state_ids.m_sp_25sec_state)
        return 25.0;
    else if (m_state_number.value == m_state_ids.m_sp_30sec_state || m_state_number.value == m_state_ids.m_sp_turnback_state)
        return 30.0;
    else if (m_state_number.value == m_state_ids.m_sp_45sec_state)
        return 45.0;
    else if (m_state_number.value == m_state_ids.m_sp_60sec_state)
        return 60.0;
    else if (m_state_number.value == m_state_ids.m_sp_90sec_state)
        return 90.0;

    return -1;
}

StoppingPoint::CSDE_CODE StoppingPoint::FeatureData::GetCSDECode()
{
    // Return the CSDE Code
    if (m_object.IsValid())
    {
        if (csde_code == Project::FeatureProperties::STOPPING_POINT::CSDE_CODE_ENUM::LHS)
            return CSDE_CODE::LHS;
        else if (csde_code == Project::FeatureProperties::STOPPING_POINT::CSDE_CODE_ENUM::RHS)
            return CSDE_CODE::RHS;
        else if (csde_code == Project::FeatureProperties::STOPPING_POINT::CSDE_CODE_ENUM::BOTH)
            return CSDE_CODE::BOTH;
        else
            return CSDE_CODE::UNDEFINED_CODE;
    }
    else
    {
        // Log Warning about unknown CSDE code
        Trace::GetLogger().STAMP(Trace::ERR)
          << "Failed to get stopping point CSDE Code for station " << station_code << Trace::EndLog();
        return CSDE_CODE::UNDEFINED_CODE;
    }
}

int StoppingPoint::FeatureData::GetPlatformFeatureId()
{
    // Return the Platform Id
    if (m_object.IsValid())
        return static_cast<int>(platform_feature_id);
    else
    {
        // Log Warning about unknown Platform Id code
        Trace::GetLogger().STAMP(Trace::ERR)
          << "Failed to get stopping point Platform Id for station " << station_code << Trace::EndLog();
        return INVALID_PLATFORM_ID;
    }
}

std::string StoppingPoint::FeatureData::GetStationCode()
{
    return station_code;
}

/// Returns true if the state of the stopping point is Proceed
///
/// @returns true if the stopping point is set to Proceed
///
bool StoppingPoint::FeatureData::IsSkip() const
{
    if (m_is_valid && m_state_number.value == m_state_ids.m_sp_skip_state)
        return true;

    return false;
}

/// Returns true if the state of the stopping point is Hold
///
/// @returns true if the stopping point is set to Hold
///
bool StoppingPoint::FeatureData::IsHold() const
{
    if (m_is_valid && m_state_number.value == m_state_ids.m_sp_hold_state)
        return true;

    return false;
}

/// Returns true if the state of the stopping point is Stop
///
/// @returns true if the stopping point is set to Stop
///
bool StoppingPoint::FeatureData::IsStop() const
{
    if (m_is_valid &&
        ((m_state_number.value == m_state_ids.m_sp_hold_state) || (m_state_number.value == m_state_ids.m_sp_0sec_state) ||
         (m_state_number.value == m_state_ids.m_sp_5sec_state) || (m_state_number.value == m_state_ids.m_sp_10sec_state) ||
         (m_state_number.value == m_state_ids.m_sp_15sec_state) || (m_state_number.value == m_state_ids.m_sp_20sec_state) ||
         (m_state_number.value == m_state_ids.m_sp_25sec_state) || (m_state_number.value == m_state_ids.m_sp_30sec_state) ||
         (m_state_number.value == m_state_ids.m_sp_45sec_state) || (m_state_number.value == m_state_ids.m_sp_60sec_state) ||
         (m_state_number.value == m_state_ids.m_sp_90sec_state)))
    {
        return true;
    }

    return false;
}

/// Returns true if the stopping point is set to Emergency state
///
/// @returns true if the stopping point is set to emergency
///
bool StoppingPoint::FeatureData::IsEmergency() const
{
    if (m_is_valid && m_state_number.value == m_state_ids.m_sp_emergency_state)
        return true;

    return false;
}

/// Returns true if the stopping point is set to Turnback state
///
/// @returns true if the stopping point is set to turnback
///
bool StoppingPoint::FeatureData::IsChangeOfEnds() const
{
    if (m_is_valid && m_state_number.value == m_state_ids.m_sp_turnback_state)
        return true;

    return false;
}

/// Returns true if the state of the stopping point is Inactive
///
/// @returns true if the stopping point is set to Inactive
///
bool StoppingPoint::FeatureData::IsInactive() const
{
    if (m_is_valid && m_state_number.value == m_state_ids.m_sp_inactive_state)
        return true;

    return false;
}
