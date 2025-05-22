///**************************************************************************************************
/// @file LMAFeatures.h
///
/// @author    Adam Zielinski
///
/// @copyright © SYDAC Pty Ltd, 2017
///**************************************************************************************************
#pragma once

#include "sim_comms/ProcessingInterfaces.h"

#include "world_api/TrainPathWatcher.h"
#include "world_api/WorldAccess.h"
#include "world_api/FeatureWatcher.h"


#include <mutex>
#include <map>

namespace LMA
{
    // Class for managing the LMA features
    class LMAFeatures
    {
    public:
        // List of all types of LMA features we are interested in
        enum LMAFeatureType
        {
            UNKNOWN_TYPE,
            SIGNAL,
        };
        
        // Structure for keeping the data associated with an LMA feature
        struct LMAFeatureData
        {
            // Type of LMA Feature
            LMAFeatureType  m_lma_feature_type; 

            // Identifies signal stop states
            std::map<int, int> m_signal_stop_states;

            // Data required for all LMA feature
            Comms::Object   m_object;

            int             m_feature_id;
            int             m_state_value;

            double          m_osp;
            double          m_pop;

            bool            m_is_valid;

            // Constructor
            LMAFeatureData() : m_lma_feature_type(LMAFeatureType::UNKNOWN_TYPE), m_is_valid(false) {};

            int    GetFeatureId() { return m_feature_id; };
            void   SetInvalid() { m_is_valid = false; };
            bool   IsValid() { return m_is_valid; };

            // Functions to check the state of an LMA feature
            int    GetStateValue() const;
            bool   IsSignalStop() const;
        };

        // States an LMA feature can be in
        enum State
        {
            UNDEFINED,
            PROCEED,
            STOP,
        };

        typedef std::pair<double, LMAFeatureData> LMAFeatureOnPath;

    public:

        LMAFeatures(Comms::Gateway                  &gateway,
                    Common::Data::DataAccess        &data_access,
                    WorldAPI::WorldAccess           &world_access,
                    WorldAPI::TrainPathWatcher      &path_watcher);

        ~LMAFeatures();

        void UpdateLMAFeaturesOnForwardPath();

        // Functions for finding LMA Features on the path
        LMAFeatureOnPath GetNextLMAFeature() const;
        LMAFeatureOnPath GetPreviousLMAFeature() const;
        LMAFeatureOnPath GetNextStopLMAFeature() const;
        LMAFeatureOnPath GetLastLMAFeature() const;

        LMAFeatures::State GetLMAFeatureState(LMAFeatures::LMAFeatureData lma_feature) const;
    private:

        void LMAFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info);

        // Helper functions
        void GetFeaturesOnPathAhead(const std::vector<std::pair<double, Comms::Object>> &lma_features_on_path_ahead,
                                    LMAFeatures::LMAFeatureOnPath                       &next_lma_feature,
                                    LMAFeatures::LMAFeatureOnPath                       &next_stop_lma_feature,
                                    LMAFeatures::LMAFeatureOnPath                       &last_lma_feature);

        void GetFeaturesOnPathBehind(const std::vector<std::pair<double, Comms::Object>>  &lma_features_on_path_behind,
                                     LMAFeatures::LMAFeatureOnPath                        &previous_lma_feature);


    private:
        void init_feature_watcher();

        Comms::Gateway                        &m_gateway;
        WorldAPI::WorldAccess                 &m_world_access;
        Common::Data::DataAccess              &m_data_access;

        // Watching the path for lma features
        WorldAPI::TrainPathWatcher            &m_train_path_watcher;
        WorldAPI::FeatureTypeFilter            m_lma_feature_feature_type_filter;
        WorldAPI::FeatureWatcher               m_lma_feature_feature_watcher;
        WorldAPI::TrackAssociationMap          m_train_path_track_associations;

        // Map the object Feature ID to our lma feature data
        std::map<Sim::ObjectID, LMAFeatureData>  m_feature_obj_id_to_data;

        // Path features positions
        std::vector<std::pair<double, Comms::Object>> m_path_features_ahead;
        std::vector<std::pair<double, Comms::Object>> m_path_features_behind;

        // Information about LMA features of interest
        LMAFeatureOnPath m_next_lma_feature;
        LMAFeatureOnPath m_previous_lma_feature;
        LMAFeatureOnPath m_next_stop_lma_feature;
        LMAFeatureOnPath m_last_lma_feature;

        // Feature Ids of interest
        std::set<int>    m_signal_types;
        // Feature Ids to be ignored
        int m_main_line_signal_long_feature_id; 
        int m_shunt_signal_feature_id; 
        int m_main_line_signal_short_feature_id;

        // For each signal Feature, identifies which signal states are stop states 
        std::map<int, std::map<int, int>> m_signal_stop_states;

        // Syncronisation
        mutable std::mutex m_mutex;
        bool m_initialised;

    };
}
