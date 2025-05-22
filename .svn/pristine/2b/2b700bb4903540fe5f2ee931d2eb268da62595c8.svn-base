/// @file PlatfromScreenDoors.h
///
/// @author    Adam Zielinski
///
/// @copyright © SYDAC Pty Ltd, 2017
#pragma once

#include "sim_comms/Object.h"
#include "sim_comms/NetworkModule.h"

#include "sim_common/Listener.h"

#include "world_api/WorldAccess.h"
#include "world_api/FeatureWatcher.h"

#include "core_types/SessionData.h"

#include "sim_comms/System.h"
#include "sim_comms/UnitDLL.h"

#include <mutex>
#include <map>



namespace PlatformControl
{

    // Class for managing the Platform Screen Doors feature
    class PlatformScreenDoors
    {
    public:
        /// Structure for storing Stopping Point state Ids
        struct PSDStatesIds
        {
            int  m_psd_open_state;
            int  m_psd_closed_state;

            PSDStatesIds()
                : m_psd_open_state(Sim::INVALID_NUMBER), m_psd_closed_state(Sim::INVALID_NUMBER) {}
        };

        class PlatformDoors
        {
        public:
            static const int INVALID_ID = -1;
            static const int SD_OPEN_ALL_DOORS = 0x00000000;
            static const int SD_CLOSE_ALL_DOORS = 0x00000000;
            static const int SD_INHIBIT_ALL_DOORS = 0xFFFFFFFF;

            /// Identifies the different PSD platform door states
            enum DoorState
            {
                UNDEFINED,
                OPEN,
                CLOSED,
                OPEN_WITH_FAULT,
                CLOSED_WITH_FAULT,
                OPENING,
                CLOSING,
                ALL_FAILED_TO_OPEN,
                ALL_FAILED_TO_CLOSE
            };

            typedef std::function<void(int platform_feature_id, const DoorState state)>  PlatformDoorsStateChangeCallback;

            PlatformDoors(WorldAPI::FeatureWatcher::CallbackInfo   psd_info,
                          Comms::Gateway                          &gateway,
                          PSDStatesIds                             psd_state_ids,
                          PlatformDoorsStateChangeCallback         state_change_callback);
            ~PlatformDoors();

            // Note that due to the way in which the PSD doors are ordered and the normal of direction of travel being opposite
            // to each other it is necessary to invert the SDO code sent to the PSD doors
            void OpenPlatformDoors(int sd_code, int sd_code_length, bool invert = true, bool psd_open_fault = false);
            void OpenAllPlatformDoors(int sd_code_length);
            void ClosePlatformDoors(int sd_code, int sd_code_length, bool invert = true, bool psd_close_fault = false);
            void CloseAllPlatformDoors(int sd_code_length);

            int GetPSDFeatureId();
            int GetPlatformFeatureId();
            DoorState GetPlatformDoorsState();

        private:
            typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Number>>  NumberListener;

            void PSDDoorPositionUpdated(Sim::Number number);

            Comms::Gateway &m_gateway;
            Comms::Object   m_object;
            int             m_psd_feature_id;

            // Properties of the PSD feature
            Sim::Number     m_state_number;
            Sim::Number     m_automatic_state_number;
            Sim::Number     m_platform_feature_id;
            Sim::Number     m_sd_code;
            Sim::Number     m_doors_position;
            int             m_number_platform_doors;

            bool m_is_valid;

            // Feature state Ids
            PSDStatesIds  m_psd_state_ids;

            // Current door state
            DoorState m_current_psd_state;
            int m_open_inhibit_code;
            int m_close_inhibit_code;
            bool m_psd_open_fault;
            bool m_psd_close_fault;
            PlatformDoors::PlatformDoorsStateChangeCallback m_state_change_callback;

            // Syncronisation
            mutable std::mutex                 m_mutex;
        };

        PlatformScreenDoors(Comms::Gateway                                  &gateway,
                            Common::Data::DataAccess                         &data_access,
                            WorldAPI::WorldAccess                            &world_access,
                            PlatformDoors::PlatformDoorsStateChangeCallback  state_change_callback);

        ~PlatformScreenDoors();

        std::shared_ptr<PlatformDoors> GetPlatformScreenDoor(int platform_feature_id);

    private:
        void PSDFeatureWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo callback_info);

        Comms::Gateway                    &m_gateway;
        WorldAPI::FeatureTypeFilter        m_psd_feature_type_filter;
        WorldAPI::FeatureWatcher           m_psd_feature_watcher;

        // PSD feature to Platform mapping
        std::map<Sim::ObjectID, int>                    m_psd_object_id_to_platform_feature_id;
        std::map<int, std::shared_ptr<PlatformDoors>>   m_platform_feature_id_to_psd_map;

        PlatformDoors::PlatformDoorsStateChangeCallback m_state_change_callback;

        // Feature state Ids
        PSDStatesIds  m_psd_state_ids;

        // Syncronisation
        mutable std::mutex                 m_mutex;

    };
}