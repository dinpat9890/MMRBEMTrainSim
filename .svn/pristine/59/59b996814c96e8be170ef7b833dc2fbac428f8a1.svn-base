///**************************************************************************************************
/// @file FeatureRegion.cpp
///
/// @author    Adam zielinski
///
/// @copyright © SYDAC Pty Ltd, 2020
///
///**************************************************************************************************

#include "FeatureRegion.h"

#include "project_features/ProjectFeatureConstants.h"

#include "core_data_access/Feature.h"
#include "core_comms_structure/CoreObjectConstants.h"

#include "project_comms_structure\ProjectObjectConstants.h"

namespace
{
    const auto REQUEST_FREQUENCY  = 4.0;
    const int  INVALID_REGION_ID = -1;

    const int  INVALID_DISTANCE = -1;

    /// Gets a point that corresponds to the requested path location
    ///
    /// @param world_access   World Access API
    /// @param path           Path on which the request point is located
    /// @param distance_ahead Distance along the path from the train to the 
    ///                       track location whose point data we want
    ///
    NetworkDefinition::Point GetTrackPoint(WorldAPI::WorldAccess &world_access,
                                           WorldAPI::SegmentPath  path,
                                           double                 distance_ahead)
    {
        WorldAPI::SegmentPosition lookaheadPosition;
        world_access.Advance(path, distance_ahead, lookaheadPosition);

        auto lookahead_pt = world_access.GetTrackPosition(lookaheadPosition).position;
        NetworkDefinition::Point lookahead_point(lookahead_pt.x, lookahead_pt.y, lookahead_pt.z);
        return lookahead_point;
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
        catch(...)
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
/// @param max_lookahead    Maximum distance to look ahead for a given region
///
FeatureRegion::FeatureRegion(Comms::Gateway&             gateway,
                             Common::Data::DataAccess&   data_access,
                             WorldAPI::WorldAccess&      world_access,
                             WorldAPI::TrainPathWatcher& path_watcher,
                             double                      max_lookahead)
  : m_gateway(gateway),
    m_world_access(world_access),
    m_train_path_watcher(path_watcher),
    m_max_lookahead_distance(max_lookahead),
    m_distance_til_end_of_automatic_region(max_lookahead),
    m_automatic_region_id(INVALID_REGION_ID),
    m_station_region_id(INVALID_REGION_ID), 
	m_depot_region_id(INVALID_REGION_ID),
    m_non_atc_region_id(INVALID_REGION_ID)
{
    try
    {
        std::vector<int> feature_type_ids;
        // Determine the ID of our Region feature types
        m_automatic_region_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_AUTOMATIC_REGION).feature_type_id;
        feature_type_ids.push_back(m_automatic_region_id);

        m_station_region_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_STATION).feature_type_id;
        feature_type_ids.push_back(m_station_region_id);

		m_depot_region_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_DEPOT_REGION).feature_type_id;
        feature_type_ids.push_back(m_depot_region_id);
        
        m_non_atc_region_id = Core::Database::Feature(data_access).GetFeatureType(Project::FeatureTypes::FETY_NON_ATC_REGION).feature_type_id;
        feature_type_ids.push_back(m_non_atc_region_id);

        m_feature_type_filter.SetAcceptableTypes(feature_type_ids);
    }
    catch(CommonException &e)
    {
        e.AddStackTrace(FLSTAMP, "Failed to find required CBTC/ETCS Region type feature Ids. CBTC/ETCS Region feature states will not be updated.");
        Trace::GetLogger().LogException(e);
    }

    // Filter the feature watcher to only watch cbtc/etcs(1/2) regions and add a callback to handle updates
    m_feature_watcher.SetFeatureTypeFilter(WorldAPI::CreateFilterCallback(m_feature_type_filter));
    m_feature_watcher.SetRequestFrequency(REQUEST_FREQUENCY);
    m_feature_watcher.AddCallback(MakeCallback(&FeatureRegion::RegionalFeatureWatcherCallback, this));

    {
        const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

        m_all_train_watcher = std::make_unique<WorldAPI::AllTrainWatcher>(gateway.GetRootObject(), 0.0);
        m_feature_watcher.Attach(m_gateway.GetRootObject());

        const std::lock_guard<WorldAPI::TrainPathWatcher> path_watcher_lock(m_train_path_watcher);
        m_train_path_watcher.AddRouteChangeCallback(MakeCallback(&FeatureRegion::RouteChangeDetected, this));
    }
}

/// Destructor
///
FeatureRegion::~FeatureRegion()
{
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);
    m_all_train_watcher.release();
}

/// Determines if front of the train is within a given region.
///
/// @param scenario_train_id  Identifies the train we want to check
/// @param feature_region     enum of the region for which the train is being checked
///
/// @returns True if any part of the train is within a CBTC Region Features boundary
///
bool FeatureRegion::TrainFrontWithinFeatureRegion(int scenario_train_id, RegionType feature_region, Comms::Object& region_object_out)
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    // Determine the Position of the front of the Train
    Comms::Object thisTrain = m_all_train_watcher->GetTrainObject(scenario_train_id);
    WorldAPI::SegmentPosition thisFrontPosition = m_all_train_watcher->GetTrainTrackPositions(thisTrain)[0];

    auto front_pt = m_world_access.GetTrackPosition(thisFrontPosition).position;
    NetworkDefinition::Point front_point(front_pt.x, front_pt.y, front_pt.z);

    // Test to see if the train falls within the given feature regions
    return PointInFeatureRegion(front_point, feature_region, region_object_out);
}

/// Determines if the train is totally within a given region.
///
/// @param scenario_train_id     Identifies the train we want to check
/// @param feature_region        enum of the region for which the train is being checked
/// @param whole_train_in_region Flags whether the whole train or only some part of the train
///                              must appear in region for the function to return true
///
/// @returns True if (all / any part) of the train is within a CBTC Region Features boundary
///
bool FeatureRegion::TrainWithinFeatureRegion(int scenario_train_id, RegionType feature_region, bool whole_train_in_region, Comms::Object& region_object_out)
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    // Determine the Position of the front of the Train
    Comms::Object thisTrain = m_all_train_watcher->GetTrainObject(scenario_train_id);

    bool train_within_region = whole_train_in_region;

    // Test to see if each of the train's vehicles fall within the given type of feature region
    auto vehiclePositions = m_all_train_watcher->GetTrainTrackPositions(thisTrain);
    if (vehiclePositions.size() == 0)
        train_within_region = false;
    else
    {
        for (auto &vehiclePosition : vehiclePositions)
        {
            auto vehicle_front_pt = m_world_access.GetTrackPosition(vehiclePosition).position;
            NetworkDefinition::Point front_point(vehicle_front_pt.x, vehicle_front_pt.y, vehicle_front_pt.z);

            // For the whole train all vehicles must appear in the region, otherwise we just need one vehicle to be in the region
            if (whole_train_in_region)
                train_within_region = train_within_region && PointInFeatureRegion(front_point, feature_region, region_object_out);
            else
                train_within_region = train_within_region || PointInFeatureRegion(front_point, feature_region, region_object_out);
        }
    }

    return train_within_region;
}

/// Determines if the train is transitioning into a given region.
///
/// @param scenario_train_id      Identifies the train we want to check
/// @param transition_area_length Length of the transition area into a given region
/// @param feature_region         enum of the region for which the train is being checked
///
/// @returns True if any part of the train is within a CBTC Region Features boundary
///
bool FeatureRegion::TrainTransitioningIntoFeatureRegion(int scenario_train_id, 
                                                        double transition_area_length,
                                                        RegionType feature_region,
                                                        Comms::Object& region_object_out)
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    // Determine if the front of the Train falls within the region
    Comms::Object thisTrain                     = m_all_train_watcher->GetTrainObject(scenario_train_id);
    WorldAPI::SegmentPosition thisFrontPosition = m_all_train_watcher->GetTrainTrackPositions(thisTrain)[0];

    auto current_pt = m_world_access.GetTrackPosition(thisFrontPosition).position;
    NetworkDefinition::Point current_point(current_pt.x, current_pt.y, current_pt.z);

    // If the front of the train falls within the given region we need to check whether or not the train
    // is still inside the transition region
    if (PointInFeatureRegion(current_point, feature_region, region_object_out))
    {
        WorldAPI::SegmentPath  path = [this]()
        {
            const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);
            return m_train_path_watcher.GetExtendedPath();
        }();

        // We can determine if the front of the Train is still in the transition area by moving the
        // current position of the train back by the length of the transition area and seeing whether
        // or not this point is still within the region. If the updated point is identified as not being
        // in the given region, then it implies that the train is still in the transition area.
        auto last_transition_pt = GetTrackPoint(m_world_access, path, -transition_area_length);
        bool transition_point_in_region = PointInFeatureRegion(last_transition_pt, feature_region);

        if (!transition_point_in_region)
            return true;
    }

    return false;
}

/// Updated the distance to the point where the train is no longer within a required region 
///
/// Assumes that the train is moving towards the edge of the required region and that provided that
/// the path doesn't change this value will always be decreasing as the edge of the region
/// draws closer. Note that the value wont start to decrement until the edge of the region is
/// within the max lookahead distance and may increase if the route is changed.
///
/// @param scenario_train_id  Identifies the train we want to check
/// @param feature_region     enum of the region for which the end is being calculated
///
/// @returns the distance to the end of the automatic region or -1 if outside
///
double FeatureRegion::GetDistanceToFeatureRegionEnd(int scenario_train_id, 
                                                    RegionType feature_region)
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    // Determine the Position of the front of the Train
    Comms::Object thisTrain                     = m_all_train_watcher->GetTrainObject(scenario_train_id);
    WorldAPI::SegmentPosition thisFrontPosition = m_all_train_watcher->GetTrainTrackPositions(thisTrain)[0];

    auto front_pt = m_world_access.GetTrackPosition(thisFrontPosition).position;
    NetworkDefinition::Point front_point(front_pt.x, front_pt.y, front_pt.z);

    // Return -1 if the front of the train isn't in a CBTC region
    if (!PointInFeatureRegion(front_point, feature_region))
        return INVALID_DISTANCE;

    // Get the current train path that we want to search
    WorldAPI::SegmentPath  path = [this]()
        {
            const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);
            return m_train_path_watcher.GetExtendedPath();
        }();

    double &distance_to_region_end = m_distance_til_end_of_automatic_region;

    // Determine the path track position at max_lookahead distance in front the Train
    NetworkDefinition::Point lookahead_point;
    lookahead_point = GetTrackPoint(m_world_access, path, distance_to_region_end);

    // If lookahead point is not in a given region, Move the lookahead point back towards the
    // train in 1m increments until we find a point that is. This now becomes the new distance
    // to the edge of the region
    while ((distance_to_region_end > 0 ) && !PointInFeatureRegion(lookahead_point, feature_region))
    {
        distance_to_region_end--;
        lookahead_point = GetTrackPoint(m_world_access, path, distance_to_region_end);
    }

    return distance_to_region_end;
}

/// Return true if the train position after the given distance is in the required region.
/// @param scenario_train_id Identifies the train we want to check
/// @param feature_region     enum of the region for which the end is being calculated
/// @param distance           forward distance from the currunt train position 
///
/// @returns the true if the train position after the given distance is in the required region.
bool FeatureRegion::IsNextRegionAtDistance(int scenario_train_id, RegionType feature_region, double distance) 
{
    // Get the current train path that we want to search
    WorldAPI::SegmentPath path = [this]() {
        const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(m_train_path_watcher);
        return m_train_path_watcher.GetExtendedPath();
    }();

    NetworkDefinition::Point lookahead_point;
    lookahead_point = GetTrackPoint(m_world_access, path, distance);

    return PointInFeatureRegion(lookahead_point, feature_region);
}

/// This is the callback function registered with our feature watcher. It will notify us of every
/// creation and destruction of a region objects.
///
/// @param callback_info Describes the feature object that has changed, and why we are being notified.
///
void FeatureRegion::RegionalFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info)
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    const auto &feature_region_object = callback_info.object;

    if (feature_region_object.IsValid()) 
    {
        // Attempt to add to the map
        const auto feature_region_object_type_id = GetFeatureTypeId(feature_region_object);
        assert(feature_region_object_type_id != Sim::INVALID_NUMBER);

        if(callback_info.reason == WorldAPI::FeatureWatcher::CallbackInfo::CREATION)
        {
            try
            {
                RegionalFeatureData new_feature_region(NetworkDefinition::MultiConvexPolygonBoundaryTest(m_world_access.GetFeatureGeometryData(feature_region_object)));
                new_feature_region.m_object  = feature_region_object;

                // Add to vector of Automatic regions
                if (feature_region_object_type_id == m_automatic_region_id)
                {
                    m_automatic_regions.push_back(new_feature_region);
                    m_distance_til_end_of_automatic_region = m_max_lookahead_distance;
                }

                // Add to vector of Station regions
                else if (feature_region_object_type_id == m_station_region_id)
                {
                    m_station_regions.push_back(new_feature_region);
                }

				// Add to vector of Depot regions
                else if (feature_region_object_type_id == m_depot_region_id)
                {
                    m_depot_regions.push_back(new_feature_region);
                }

                // Add to vector of Non ATC regions
                else if (feature_region_object_type_id == m_non_atc_region_id)
                {
                    m_non_atc_regions.push_back(new_feature_region);
                }
            }
            catch(CommonException &e)
            {
                e.AddStackTrace(FLSTAMP, "Retrieving required information from Region Object.");
                Trace::g_plog->LogException(e);
            }
        }
        else if(callback_info.reason == WorldAPI::FeatureWatcher::CallbackInfo::DESTRUCTION)
        {
            // Remove from the vector of CBTC regions

            if(feature_region_object_type_id == m_automatic_region_id)
            {
                m_automatic_regions.erase(remove_if(m_automatic_regions.begin(),
                                       m_automatic_regions.end(),
                                       [callback_info](const RegionalFeatureData &automatic_region) { return automatic_region.m_object == callback_info.object; }),
                                       m_automatic_regions.end());
            }
            else if (feature_region_object_type_id == m_station_region_id)
            {
                m_station_regions.erase(remove_if(m_station_regions.begin(),
                    m_station_regions.end(),
                    [callback_info](const RegionalFeatureData &station_regions) { return station_regions.m_object == callback_info.object; }),
                    m_station_regions.end());
            }
            else if (feature_region_object_type_id == m_depot_region_id)
            {
                m_depot_regions.erase(remove_if(m_depot_regions.begin(),
                                                  m_depot_regions.end(),
                                                  [callback_info](const RegionalFeatureData& depot_regions) {
                                                      return depot_regions.m_object == callback_info.object;
                                                  }),
                                        m_depot_regions.end());
            }
            else if (feature_region_object_type_id == m_non_atc_region_id)
            {
                m_non_atc_regions.erase(remove_if(m_non_atc_regions.begin(),
                                                  m_non_atc_regions.end(),
                                                [callback_info](const RegionalFeatureData& non_atc_regions) {
                                                    return non_atc_regions.m_object == callback_info.object;
                                                }),
                                        m_non_atc_regions.end());
            }
        }
    }
}

/// Handles actions required to happen when teh route changes
///
void FeatureRegion::RouteChangeDetected()
{
    const std::lock_guard<std::mutex> DATA_MEMBER_LOCK(m_mutex);
    
    // Resets the region edge distance to the max lookahead distance 
    m_distance_til_end_of_automatic_region = m_max_lookahead_distance;
}

/////////////////////////////////////////////////////////////////////////////////
// Helper Functions
/////////////////////////////////////////////////////////////////////////////////

/// Test if whole train is within the given boundaries of a specific type of region
///
/// @param p1 Point representing one end of the train
/// @param p2 Point representing the other end of the train
///
/// @returns True if both points are within the Region
///
bool FeatureRegion::AnyPointInFeatureRegion(const NetworkDefinition::Point &p1, const NetworkDefinition::Point &p2, RegionType region, Comms::Object& region_object_out)
{
    std::vector<RegionalFeatureData> feature_region;

    if(region == RegionType::AUTOMATIC)
        feature_region = m_automatic_regions;
    else if (region == RegionType::STATION)
        feature_region = m_station_regions;
    else if (region == RegionType::DEPOT)
        feature_region = m_depot_regions;
    else if (region == RegionType::NON_ATC)
        feature_region = m_non_atc_regions;

    for(auto &region : feature_region)
    {
        if(region.m_boundary.IsPointInsideBoundary(p1) || region.m_boundary.IsPointInsideBoundary(p2))
        {
            region_object_out = region.m_object;
            return true;
        }
    }

    return false;
}

bool FeatureRegion::AnyPointInFeatureRegion(const NetworkDefinition::Point &p1, const NetworkDefinition::Point &p2, RegionType region)
{
    Comms::Object region_object_out;
    return AnyPointInFeatureRegion(p1, p2, region, region_object_out);
}

/// Test if a given point is within the boundaries of a specific type of region
///
/// @param p1 Point representing one end of the train
/// @param region the region type
/// @param region_object_out The Comms Object for the region type, if found
///
/// @returns True if given point is within the Region
///
bool FeatureRegion::PointInFeatureRegion(const NetworkDefinition::Point &p1, RegionType region, Comms::Object& region_object_out)
{
    std::vector<RegionalFeatureData> feature_region;

    if (region == RegionType::AUTOMATIC)
        feature_region = m_automatic_regions;
    else if (region == RegionType::STATION)
        feature_region = m_station_regions;
	else if (region == RegionType::DEPOT)
        feature_region = m_depot_regions;
    else if (region == RegionType::NON_ATC)
        feature_region = m_non_atc_regions;

    for(auto &region : feature_region)
    {
        if(region.m_boundary.IsPointInsideBoundary(p1))
        {
            region_object_out = region.m_object;
            return true;
        }
    }

    return false;
}

bool FeatureRegion::PointInFeatureRegion(const NetworkDefinition::Point &p1, RegionType region)
{
    Comms::Object region_object;
    return PointInFeatureRegion(p1, region, region_object);
}
