///**************************************************************************************************
/// @file StoppingPoint.h
///
/// @author    Adam Zielinski
///
/// @copyright © SYDAC Pty Ltd, 2020
///**************************************************************************************************
#pragma once

#include "sim_comms/ProcessingInterfaces.h"

#include "world_api/FeatureWatcher.h"
#include "world_api/TrainPathWatcher.h"
#include "world_api/WorldAccess.h"

#include "feature_interfaces/FeatureRegion.h"

#include "common/DataAccess.h"

#include <map>
#include <mutex>

namespace FeatureInterfaces
{
    // Class for managing the Stoping point features on the path
    class StoppingPoint
    {
    public:
        /// Structure for storing Stopping Point state Ids
        struct SPStatesIds
        {
            int m_sp_skip_state;
            int m_sp_hold_state;
            int m_sp_emergency_state;
            int m_sp_turnback_state;
            int m_sp_inactive_state;
            int m_sp_0sec_state;
            int m_sp_5sec_state;
            int m_sp_10sec_state;
            int m_sp_15sec_state;
            int m_sp_20sec_state;
            int m_sp_25sec_state;
            int m_sp_30sec_state;
            int m_sp_45sec_state;
            int m_sp_60sec_state;
            int m_sp_90sec_state;

            SPStatesIds()
              : m_sp_skip_state(Sim::INVALID_NUMBER)
              , m_sp_hold_state(Sim::INVALID_NUMBER)
              , m_sp_emergency_state(Sim::INVALID_NUMBER)
              , m_sp_turnback_state(Sim::INVALID_NUMBER)
              , m_sp_0sec_state(Sim::INVALID_NUMBER)
              , m_sp_5sec_state(Sim::INVALID_NUMBER)
              , m_sp_10sec_state(Sim::INVALID_NUMBER)
              , m_sp_15sec_state(Sim::INVALID_NUMBER)
              , m_sp_20sec_state(Sim::INVALID_NUMBER)
              , m_sp_25sec_state(Sim::INVALID_NUMBER)
              , m_sp_30sec_state(Sim::INVALID_NUMBER)
              , m_sp_45sec_state(Sim::INVALID_NUMBER)
              , m_sp_60sec_state(Sim::INVALID_NUMBER)
              , m_sp_90sec_state(Sim::INVALID_NUMBER)
            {
            }
        };

        enum CSDE_CODE
        {
            UNDEFINED_CODE,
            LHS,
            RHS,
            BOTH
        };

        /// Structure that represents the stopping point feature data of interest
        class FeatureData
        {
        public:
            // Constructor
            FeatureData() { m_is_valid = false; };

            bool IsValid() { return m_is_valid; };

            // Function to get data from the stopping point
            double      GetDwellTime();
            CSDE_CODE   GetCSDECode();
            int         GetPlatformFeatureId();
            std::string GetStationCode();

            // Functions to check a Stopping Point's state
            bool IsSkip() const;
            bool IsHold() const;
            bool IsChangeOfEnds() const;
            bool IsStop() const;
            bool IsEmergency() const;
            bool IsInactive() const;

        private:
            Comms::Object m_object;

            int         m_feature_id;
            Sim::Number m_state_number;

            bool        m_is_valid;
            SPStatesIds m_state_ids;

            std::string station_code;
            double      platform_feature_id;
            double      csde_code;

            friend class StoppingPoint;
        };

        typedef std::pair<double, FeatureData> StoppingPointFeatureOnPath;

    public:
        StoppingPoint(Comms::Gateway&             gateway,
                      Common::Data::DataAccess&   data_access,
                      WorldAPI::WorldAccess&      world_access,
                      WorldAPI::TrainPathWatcher& path_watcher);

        ~StoppingPoint();

        // Function for finding stopping points of interest
        StoppingPointFeatureOnPath GetNextStoppingPointData(double start_position, double end_position, int m_scenario_train_id);
        std::vector<StoppingPointFeatureOnPath> GetAllStoppingPointData(double start_position, double end_position);

    private:
        void SPFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info);

    private:
        Comms::Gateway&        m_gateway;
        WorldAPI::WorldAccess& m_world_access;

        // Watching the path for stopping points
        WorldAPI::TrainPathWatcher&   m_train_path_watcher;
        WorldAPI::FeatureTypeFilter   m_sp_feature_type_filter;
        WorldAPI::FeatureWatcher      m_sp_feature_watcher;
        WorldAPI::TrackAssociationMap m_track_associations;

        // Map the object Feature ID to our stopping point data
        std::map<Sim::ObjectID, FeatureData> m_feature_obj_id_to_sp_data;

        // Information about stopping point features of interest
        StoppingPointFeatureOnPath m_fwd_next_stopping_point;

        // Precalculate our state IDs
        SPStatesIds m_sp_state_ids;

        
        // Feature Data required to populate the track event data
        FeatureInterfaces::FeatureRegion m_feature_region_data;

        // Syncronisation
        mutable std::mutex m_mutex;
        int                m_number_of_cars =0;
        int                m_index_of_ssp = 0;
        // Comms Object Callbacks
        void RootChildCreated(Comms::Object object);
        void ObjectCreated(Comms::Object object);
        //void ObjectDestroyed(Comms::Object object);
    };
}
