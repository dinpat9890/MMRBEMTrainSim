///**************************************************************************************************
/// @file WorkZone.h
///
/// @author    Adam Zielinski
///
/// @copyright © SYDAC Pty Ltd, 2020
///**************************************************************************************************
#pragma once

#include "sim_comms/ProcessingInterfaces.h"

#include "world_api/TrainPathWatcher.h"
#include "world_api/WorldAccess.h"
#include "world_api/FeatureWatcher.h"

#include "common/DataAccess.h"

#include <mutex>
#include <map>

namespace FeatureInterfaces
{
    // Class for managing the Work Zone features on the path
    class WorkZone
    {
    public:
        /// Structure for storing Work Zone state Ids
        struct WZStatesIds
        {
            int m_sp_10_kph_state;
            int m_sp_15_kph_state;
            int m_sp_20_kph_state;
            int m_sp_30_kph_state;
            int m_sp_40_kph_state;
            int m_sp_50_kph_state;
            int m_sp_60_kph_state;
            int m_sp_70_kph_state;

            WZStatesIds()
              : m_sp_10_kph_state(Sim::INVALID_NUMBER), m_sp_15_kph_state(Sim::INVALID_NUMBER),
                m_sp_20_kph_state(Sim::INVALID_NUMBER), m_sp_30_kph_state(Sim::INVALID_NUMBER),
                m_sp_40_kph_state(Sim::INVALID_NUMBER), m_sp_50_kph_state(Sim::INVALID_NUMBER),
                m_sp_60_kph_state(Sim::INVALID_NUMBER), m_sp_70_kph_state(Sim::INVALID_NUMBER) {}
        };

        /// Structure that represents the Work Zone feature data of interest
        class FeatureData
        {
        public:
            // Constructor
            FeatureData() { m_is_valid = false; };

            bool IsValid() { return m_is_valid; };

            // Function to get data from the Work Zone
//            int GetTemporarySpeed();
            double GetRemainingRegionLength(double current_train_position);
            double GetDistanceToWorkZone(double current_train_position);

        private:
            Comms::Object   m_object;

            int             m_work_zone_feature_id;
            int             m_work_zone_end_feature_id;
            Sim::Number     m_state_number;

            bool            m_is_valid;
            WZStatesIds     m_state_ids;

            double          m_work_zone_start_location;
            double          m_work_zone_end_location;

            friend class WorkZone;
        };

        typedef std::pair<double, FeatureData> WorkZoneFeatureOnPath;

    public:
        WorkZone(Comms::Gateway             &gateway,
                 Common::Data::DataAccess   &data_access,
                 WorldAPI::WorldAccess      &world_access,
                 WorldAPI::TrainPathWatcher &path_watcher,
                 double                      train_length);

        ~WorkZone();

        // Function for finding Work Zones of interest
        WorkZoneFeatureOnPath GetNextWorkZoneData(double current_train_position);

    private:

        void WZFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info);
        
        void DefineWorkZoneRegions(double current_train_position);

    private:
        Comms::Gateway                        &m_gateway;
        WorldAPI::WorldAccess                 &m_world_access;

        // Watching the path for Work Zones
        WorldAPI::TrainPathWatcher            &m_train_path_watcher;
        WorldAPI::FeatureTypeFilter            m_wz_feature_type_filter;
        WorldAPI::FeatureWatcher               m_wz_feature_watcher;
        WorldAPI::TrackAssociationMap          m_track_associations;

        // Ids of features of interest
        int m_work_zone_end_id;
        int m_work_zone_id;

        // Map the object Feature ID to our Work Zone data
        std::map<Sim::ObjectID, FeatureData>  m_feature_obj_id_to_wz_data;

        // Work Zones on the train path (absolute position, work zone data)
        std::vector<std::pair<double, FeatureData>>      m_path_work_zones;

        // Information about Work Zone features of interest
        WorkZoneFeatureOnPath m_fwd_next_stopping_point;

        // Precalculate our state IDs
        WZStatesIds                m_wz_state_ids;

        // Needed so that the profile correctly reports end of work zone
        // once the whole train has left the region
        double    m_train_length;

        // Syncronisation
        mutable std::mutex         m_mutex;

    };
}