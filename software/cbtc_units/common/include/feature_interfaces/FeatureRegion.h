///**************************************************************************************************
/// @file FeatureRegion.h
///
/// @author    Adam Zielinski
///
/// @copyright © SYDAC Pty Ltd, 2020
///**************************************************************************************************
#pragma once

#include "sim_comms/ProcessingInterfaces.h"

#include "network_definition/Boundaries/ConvexPolygonBoundary.h"

#include "world_api/TrainPathWatcher.h"
#include "world_api/AllTrainWatcher.h"
#include "world_api/WorldAccess.h"
#include "world_api/FeatureWatcher.h"


#include <mutex>
#include <map>

namespace FeatureInterfaces
{
    // Class for intefacing with the CBTC Region features that appear on a trains path
    class FeatureRegion
    {
    private:
        /// Structure that represents the CBTC Region feature data
        struct RegionalFeatureData
        {
            Comms::Object                                     m_object;

            NetworkDefinition::MultiConvexPolygonBoundaryTest m_boundary;

            RegionalFeatureData(const NetworkDefinition::MultiConvexPolygonBoundaryTest &_boundary)
                : m_boundary(_boundary) { }
        };

        typedef std::pair<double, RegionalFeatureData> RegionalFeatureDataOnPath;

    public:
        enum class RegionType
        {
            AUTOMATIC,
            STATION,
			DEPOT,
            NON_ATC,
        };

        FeatureRegion(Comms::Gateway&             gateway,
                      Common::Data::DataAccess&   data_access,
                      WorldAPI::WorldAccess&      world_access,
                      WorldAPI::TrainPathWatcher& path_watcher,
                      double                      max_lookahead);

        ~FeatureRegion();

        // Function for finding if train within a given Region
        bool TrainFrontWithinFeatureRegion(int scenario_train_id, RegionType feature_region, Comms::Object& region_object_out);
        bool TrainWithinFeatureRegion(int scenario_train_id, RegionType feature_region, bool whole_train_in_region, Comms::Object& region_object_out);
        bool TrainTransitioningIntoFeatureRegion(int scenario_train_id,
                                                 double transition_area_length,
                                                 RegionType feature_region,
                                                 Comms::Object& region_object_out);

        //Return true if the train position after the given distance is in the required region. 
        bool IsNextRegionAtDistance(int scenario_train_id, RegionType feature_region, double distance);

        // Returns distance to end of a region
        double GetDistanceToFeatureRegionEnd(int scenario_train_id, RegionType feature_region);

    private:
        void RegionalFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info);
        void RouteChangeDetected();

        // Helper functions
        bool AnyPointInFeatureRegion(const NetworkDefinition::Point &p1, const NetworkDefinition::Point &p2, RegionType region, Comms::Object& region_object_out);
        bool AnyPointInFeatureRegion(const NetworkDefinition::Point &p1, const NetworkDefinition::Point &p2, RegionType region);
        bool PointInFeatureRegion(const NetworkDefinition::Point &p1, RegionType region, Comms::Object& region_object_out);
        bool PointInFeatureRegion(const NetworkDefinition::Point &p1, RegionType region);

    private:

        Comms::Gateway                    &m_gateway;
        WorldAPI::WorldAccess             &m_world_access;

        // Getting the train path
        WorldAPI::TrainPathWatcher        &m_train_path_watcher;
        std::unique_ptr<WorldAPI::AllTrainWatcher>         m_all_train_watcher;

        // Regional features
        WorldAPI::FeatureTypeFilter        m_feature_type_filter;
        WorldAPI::FeatureWatcher           m_feature_watcher;
        std::vector<RegionalFeatureData>   m_automatic_regions;
        std::vector<RegionalFeatureData>   m_station_regions;
        std::vector<RegionalFeatureData>   m_depot_regions;
        std::vector<RegionalFeatureData>   m_non_atc_regions;

        int                                m_automatic_region_id;
        int                                m_station_region_id;
        int                                m_depot_region_id;
        int                                m_non_atc_region_id;

        double                             m_max_lookahead_distance;
        double                             m_distance_til_end_of_automatic_region;

        // Syncronisation
        mutable std::mutex                 m_mutex;

    };
}