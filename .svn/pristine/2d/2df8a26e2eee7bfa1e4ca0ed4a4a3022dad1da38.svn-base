///**************************************************************************************************
/// @file WorkZone.h
///
/// @author    Adam zielinski
///
/// @copyright © SYDAC Pty Ltd, 2020
///**************************************************************************************************

#include "WorkZone.h"

#include "core_data_access/Feature.h"

#include "core_comms_structure/CoreObjectConstants.h"
#include "project_features/ProjectFeatureConstants.h"

#include "project_comms_structure\ProjectObjectConstants.h"

#include "cbtc_common/FeatureProperties.h"

#include "project/Utilities/RawToString.h"

#include "Utility/Utilities.h"

namespace
{
    const auto REQUEST_FREQUENCY   = 4.0;
    const auto INVALID_PLATFORM_ID = -1;
    const auto UNDEFINED_DISTANCE  = -1.0;

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

    /// Helper function that, given an object, attempts to get it's feature type as an integer and
    /// returns it. If the object does not exist a value of -1 is returned.
    ///
    /// @param object  The object to get the feature type ID for.
    ///
    double GetFeatureTypeId(Comms::Object object)
    {
        assert(object.IsValid());
        try
        {
            const auto FEATURE_TYPE_ID = object.Numbers().Info().GetID(Project::ValueName::Feature::TYPE);
            return object.Numbers().Store().Get(FEATURE_TYPE_ID).value;
        }
        catch (...)
        {
            return Sim::INVALID_NUMBER;
        }
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
WorkZone::WorkZone(Comms::Gateway                  &gateway,
                   Common::Data::DataAccess        &data_access,
                   WorldAPI::WorldAccess           &world_access,
                   WorldAPI::TrainPathWatcher      &path_watcher,
                   double                           train_length)
    : m_gateway(gateway), m_world_access(world_access), m_train_path_watcher(path_watcher), m_train_length(train_length)
{
    try
    {
        std::vector<int> feature_type_ids;

        // Determine the ID of our work zone feature types
        m_work_zone_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_WORK_ZONE).feature_type_id;
        feature_type_ids.push_back(m_work_zone_id);

        m_work_zone_end_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_WORK_ZONE_END).feature_type_id;
        feature_type_ids.push_back(m_work_zone_end_id);

        // Determine the ID of the states that we care about
        m_wz_state_ids.m_sp_10_kph_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_work_zone_id, Project::FeatureStates::D10_KPH).feature_type_state_id;
        m_wz_state_ids.m_sp_20_kph_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_work_zone_id, Project::FeatureStates::D20_KPH).feature_type_state_id;
        m_wz_state_ids.m_sp_30_kph_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_work_zone_id, Project::FeatureStates::D30_KPH).feature_type_state_id;
        m_wz_state_ids.m_sp_40_kph_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_work_zone_id, Project::FeatureStates::D40_KPH).feature_type_state_id;
        m_wz_state_ids.m_sp_50_kph_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_work_zone_id, Project::FeatureStates::D50_KPH).feature_type_state_id;
        m_wz_state_ids.m_sp_60_kph_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_work_zone_id, Project::FeatureStates::D60_KPH).feature_type_state_id;
        m_wz_state_ids.m_sp_70_kph_state = Core::Database::Feature(data_access).GetFeatureTypeState(m_work_zone_id, Project::FeatureStates::D70_KPH).feature_type_state_id;

        m_wz_feature_type_filter.SetAcceptableTypes(feature_type_ids);
    }
    catch (CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Failed to find required Work Zone feature Id. Work Zone feature states will not be updated.");
        Trace::GetLogger().LogException(e);
    }

    // Filter the feature watcher to only watch Work Zones and add a callback to handle updates
    m_wz_feature_watcher.SetFeatureTypeFilter(WorldAPI::CreateFilterCallback(m_wz_feature_type_filter));
    m_wz_feature_watcher.SetRequestFrequency(REQUEST_FREQUENCY);
    m_wz_feature_watcher.AddCallback(MakeCallback(&WorkZone::WZFeatureWatcherCallback, this));

    {
        const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
        m_wz_feature_watcher.Attach(m_gateway.GetRootObject());
    }
}

/// Destructor
///
WorkZone::~WorkZone()
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
    m_wz_feature_watcher.Detach();
}

/// Returns the feature data for the first Work Zone feature, found on the path ahead.
///
/// Note that the train may either be approaching or within the returned work zone region
///
/// @param current_train_position Current location of the train
///
/// @returns data associated with the next Work Zone region
///
WorkZone::WorkZoneFeatureOnPath WorkZone::GetNextWorkZoneData(double current_train_position)
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

    WorkZone::WorkZoneFeatureOnPath work_zone_to_report;

    DefineWorkZoneRegions(current_train_position);

    // Find the work zone region to report
    for (auto &work_zone_region : m_path_work_zones)
    {
        auto work_zone_data = work_zone_region.second;

        // Nothing to do if the rear of the train has moved past the work zone
        if (work_zone_data.m_work_zone_end_location < current_train_position)
            continue;

        // Part of the train is inside of a work zone region
        else if (work_zone_data.m_work_zone_start_location < current_train_position)
        {
            work_zone_to_report.first = current_train_position;
            work_zone_to_report.second = work_zone_data;
            break;
        }

        // We are approaching the next work zone region
        else
        {
            work_zone_to_report.first = work_zone_data.m_work_zone_start_location;
            work_zone_to_report.second = work_zone_data;
            break;
        }
    }

    return work_zone_to_report;
}

/// Records the data associated with each work Zone region on the track
///
/// @param current_train_position Current location of the train 
///
void WorkZone::DefineWorkZoneRegions(double current_train_position)
{
    // Find all of the Work Zone features on the train path
    std::vector<std::pair<double, Comms::Object>> train_path_work_zone_features;
    {
        // Features on the train path ahead
        train_path_work_zone_features = [&]()
        {
            const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);

            if (m_train_path_watcher.HasPath())
                return m_world_access.GetPathFeatures(m_train_path_watcher.GetExtendedPath(), m_track_associations, -std::numeric_limits<double>::max(), std::numeric_limits<double>::max());

            return std::vector<std::pair<double, Comms::Object>>();
        }();
    }

    std::vector<Comms::Object> pending_start_work_zones;

    // If any work zone features appear on the path then associate the start and end work zone features with each other
    // in order to define the work zone regions 
    for (auto &work_zone_feature : train_path_work_zone_features)
    {
        const auto work_zone_start_location = work_zone_feature.first;
        const auto work_zone_object = work_zone_feature.second;
        const auto work_zone_feature_type_id = GetFeatureTypeId(work_zone_object);

        // If this is the start of a work zone then we need to record it. This is so that we can define a new work zone 
        // region once the end of the work zone is found.
        if (work_zone_feature_type_id == m_work_zone_id)
        {
            auto wz_data = m_feature_obj_id_to_wz_data.find(work_zone_object.GetID());

            wz_data->second.m_work_zone_start_location = current_train_position + work_zone_feature.first;
            pending_start_work_zones.push_back(work_zone_object);
        }

        // If this is the end of a work zone then the work zone region with which it is associated can be defined. 
        else
        {
            if (pending_start_work_zones.size() > 0)
            {
                // Find the work zone region data that needs to be updated
                const auto start_work_zone_object = pending_start_work_zones.front();
                auto wz_data = m_feature_obj_id_to_wz_data.find(start_work_zone_object.GetID());

                wz_data->second.m_work_zone_end_location = current_train_position + work_zone_feature.first + m_train_length;
                wz_data->second.m_work_zone_end_feature_id = GetFeatureID(work_zone_feature.second);
                wz_data->second.m_is_valid = true;

                pending_start_work_zones.erase(pending_start_work_zones.begin());

                m_path_work_zones.push_back(std::pair<double, FeatureData>(wz_data->second.m_work_zone_start_location, wz_data->second));
            }
            else
                // Could not define a work zone region since no start of Work Zone feature could be found
                Trace::GetLogger().STAMP(Trace::ERR) << "No start of Work Zone could be associated with Work Zone End : "
                << work_zone_object.GetID() << Trace::EndLog();
        }
    }
}

/// This is the callback function registered with the feature watcher. It handles the actions required to
/// occur upon the creation and destruction of a Work Zone object. 
///
/// @param callback_info Describes the feature object that has changed, and why we are being notified.
///
void WorkZone::WZFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const auto &work_zone_object = callback_info.object;

    if (work_zone_object.IsValid())
    {
        const auto work_zone_object_id = work_zone_object.GetID();
        assert(work_zone_object_id != Sim::INVALID_NUMBER);

        const auto feature_region_object_type_id = GetFeatureTypeId(work_zone_object);

        switch (callback_info.reason)
        {
        case WorldAPI::FeatureWatcher::CallbackInfo::CREATION:
        {
            try
            {
                // Attempt to add to the map
                assert(feature_region_object_type_id != Sim::INVALID_NUMBER);

                // If the feature defines the start of a work zone, add a new Work Zone feature into our feature data map
                // and add the feature into the track associations.
                if (feature_region_object_type_id == m_work_zone_id)
                {
                    // Note that the end of the new Work Zone data still need to be determined
                    FeatureData new_work_zone;
                    new_work_zone.m_object = callback_info.object;
                    new_work_zone.m_work_zone_feature_id = GetFeatureID(callback_info.object);
                    new_work_zone.m_work_zone_end_feature_id = Sim::INVALID_NUMBER;
                    new_work_zone.m_state_number = callback_info.object.Numbers().Get(Core::ValueName::Feature::STATE);
                    new_work_zone.m_is_valid = false;
                    new_work_zone.m_state_ids = m_wz_state_ids;

                    {
                        const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

                        m_feature_obj_id_to_wz_data.insert(std::make_pair(work_zone_object_id, new_work_zone));
                        m_track_associations.AddFeature(work_zone_object);
                    }
                }

                // Otherwise the feature is the end of the work zone so we just add it into the track associations
                else
                    m_track_associations.AddFeature(work_zone_object);
            }
            catch (CommonException &e)
            {
                Trace::GetLogger().LogException(e);
                Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract properties for Work Zone feature\""
                    << work_zone_object.GetName() << "\" (Object ID: " << work_zone_object_id
                    << "). This feature will be ignored." << Trace::EndLog();
            }

            break;
        }
        case WorldAPI::FeatureWatcher::CallbackInfo::DESTRUCTION:
        {
            const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);
         
            // Attempt to remove from the map
            assert(feature_region_object_type_id != Sim::INVALID_NUMBER);

            // If the feature defines the start of a work zone, remove the Work Zone from our feature data map
            if (feature_region_object_type_id == m_work_zone_id)
                m_feature_obj_id_to_wz_data.erase(work_zone_object_id);
            
            // Remove a Work Zone or Work Zone End feature from our track associations
            m_track_associations.RemoveFeature(work_zone_object);

            break;
        }
        case WorldAPI::FeatureWatcher::CallbackInfo::STATE_CHANGE:
        {
            const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);

            // Update the state of the work zone feature upon a state change
            assert(feature_region_object_type_id != Sim::INVALID_NUMBER);

            if (feature_region_object_type_id == m_work_zone_id)
            {
                auto id_to_wz_feature_data_iter = m_feature_obj_id_to_wz_data.find(work_zone_object_id);
                if (id_to_wz_feature_data_iter != m_feature_obj_id_to_wz_data.end() && id_to_wz_feature_data_iter->second.m_object.IsValid())
                {
                    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
                    id_to_wz_feature_data_iter->second.m_object.Numbers().Store().Get(id_to_wz_feature_data_iter->second.m_state_number);
                }
            }

            break;
        }
        }
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed to extract Work Zone feature object" << Trace::EndLog();
    }
}

/// Reports the length of the work zone that the train still needs to pass through
///
/// @param current_train_position Reports the trains current location.
///
/// @returns Length of the work zone or if inside, distance until end is reached 
///
double WorkZone::FeatureData::GetRemainingRegionLength(double current_train_position)
{
    double work_zone_length;
        
    // Train approaching the work zone
    if (m_work_zone_start_location > current_train_position)
        work_zone_length = (m_work_zone_end_location - m_work_zone_start_location);

    // Train inside the work zone
    else if (m_work_zone_end_location > current_train_position)
        work_zone_length = (m_work_zone_end_location - current_train_position);

    // Train beyond the work zone
    else
        work_zone_length = 0.0;
        
    return work_zone_length;
}

/// Reports distance train needs to travel before entering the work zone
///
/// @param current_train_position Reports the trains current location.
///
/// @returns Distance until work zone is reached or zero if already inside 
///
double WorkZone::FeatureData::GetDistanceToWorkZone(double current_train_position)
{
    if (m_work_zone_start_location > current_train_position)
        return m_work_zone_start_location - current_train_position;
    else if (m_work_zone_end_location > current_train_position)
        return 0.0;
    else
        return UNDEFINED_DISTANCE;
}
