///**************************************************************************************************
/// @file BeaconReader.h
///
/// Description : Unit for interfacing with the Beacon features
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

#include <mutex>
#include <map>

namespace Beacon
{
    /// This class is responsible for detection of the Beacon features
    class BeaconReader
    {
    private:

         /// Structure containing the state Ids associated with the Beacon feature
        struct BeaconStateIds
        {
            int m_normal_state;
            int m_faulty_state;

            BeaconStateIds()
                : m_normal_state(Sim::INVALID_NUMBER), m_faulty_state(Sim::INVALID_NUMBER) {}
        };

       /// Structure containing the beacon feature data of interest 
        struct BeaconData
        {
            Comms::Object   m_object;
            double          m_feature_id;
            double          m_state_value;
        };

    public:

        typedef std::pair<double, BeaconData>     BeaconDetectionEvent;
        typedef std::vector<BeaconDetectionEvent> BeaconDetectionEvents;

    public:
        BeaconReader(Comms::Gateway               &gateway,
                       Common::DataAccess         &data_access,
                       WorldAPI::WorldAccess      &world_access,
                       WorldAPI::TrainPathWatcher &path_watcher);
        ~BeaconReader();

        bool IsBeaconDetected(double train_position, double detection_range);
        bool IsLastDetectedBeaconFaulty();

        double GetLastDetectedBeaconId();
        double GetLastDetectedBeaconLocation();

    private:
        // Feature Watcher related functions
        void FeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info);
        void RouteChangeDetected();

        // Helper functions
        BeaconDetectionEvent GetNextBeaconDetectionEvent(double current_position);

        void SetEventsVector(BeaconReader::BeaconDetectionEvents                 &path_beacon_detection_events,
                             const std::vector<std::pair<double, Comms::Object>> &path_beacon_features);

    private:
        Comms::Gateway                        &m_gateway;
        WorldAPI::WorldAccess                 &m_world_access;

        // Watching the path for beacon features
        WorldAPI::TrainPathWatcher            &m_train_path_watcher;
        WorldAPI::FeatureTypeFilter            m_beacon_feature_type_filter;
        WorldAPI::FeatureWatcher               m_beacon_feature_watcher;
        WorldAPI::TrackAssociationMap          m_beacon_track_associations;

        // Map the object Feature ID to our beacon feature data
        std::map<Sim::ObjectID, BeaconData>  m_feature_obj_id_to_data;

        // Forward path features positions
        std::vector<std::pair<double, Comms::Object>> m_fwd_path_beacon_features;

        // Used to maintain information about the event locations
        BeaconDetectionEvents  m_fwd_path_beacon_events;
        bool                   m_route_changed;
        double                 m_initial_position;

        // Used to detect the next beacon detection event
        BeaconDetectionEvent      m_previous_event;
        double                    m_previous_event_old_position;
        BeaconDetectionEvent      m_last_in_range_event;

        // Feature Ids of interest
        int                    m_cbtc_beacon_id;
        int                    m_cbtc_beacon_depot_id;

        // Precalculated state IDs
        BeaconStateIds m_position_state_ids;
        BeaconStateIds m_depot_position_state_ids;
    };
}