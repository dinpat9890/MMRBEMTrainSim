///
/// @file       TrackEventManagementModuleModule.h
///
///             Module that handles the functionality related to the Track Event Management function
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///             Amol Ganbavale
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#pragma once

#include "CBTCConstants.h"
#include "CBTCModule.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        // Skip station event (absolute path distance, station code)
        using SkipStationEvent  = std::pair<double, std::string>;
        using SkipStationEvents = std::vector<SkipStationEvent>;

        // Transition/Driver track events ahead of the train (absolute path distance, track event)
        using TrackEvent  = std::pair<double, CBTC::Protos::TrackEventList::TrackEvent>;
        using TrackEvents = std::vector<TrackEvent>;

        /// Defines the standard structures required of a Module
        struct TrackSideDataModuleIO
        {
            struct Initialisation
            {
                // CBTC Speed Limits
                double auto_skip_speed_limit = INVALID_SPEED;

                // Auto Skip Distance is configurable to control when tram slows down
                double auto_skip_distance = INVALID_DISTANCE;

                // Stopping distance offset when train overshoots/undershoots a platform stopping point
                double overshoot_distance  = INVALID_DISTANCE;
                double undershoot_distance = INVALID_DISTANCE;

                // When to start reporting that the train is approaching a work zone
                double work_zone_alarm_distance = INVALID_DISTANCE;
            };

            struct Inputs
            {
                // Injects a fault into the stopping point distance used to stop the trainreported Fault from the SCC
                double ato_position_error; // Valid values given by Project::TypeValues::ATOPositionError

                //=========================================================================================
                // The following data is populated using Comms Data from the Train Model
                //=========================================================================================

                /// The current train speed
                double current_train_speed = INVALID_SPEED;

                /// The current train position
                double current_train_position = INVALID_DISTANCE;

                //=========================================================================================
                // The following data is populated using Comms Data from the CBTC OnBoard Inputs
                //=========================================================================================

                // Reported track event data
                CBTC::Protos::TrackEventList track_event_data;

                /// Movement Authority data packet
                CBTC::Protos::MovementAuthority movement_authority_data;

                /// Gradient Profile data packet
                /// Note : Distances are incremental from the previous profile point, with the first
                ///        distance being relative to the train's current position
                CBTC::Protos::GradientProfile gradient_profile_data;

                /// Speed Profile data packet
                /// Note that distances are relative to the given train path position
                CBTC::Protos::SpeedLimitList speed_data_profile;

                // Should be set to true when the front of the train is near a platform
                bool train_front_near_platform = false;

                //=========================================================================================
                // The following data is populated using Data from the Mode Transitions Module
                //=========================================================================================

                /// Provides the current CBTC Driving mode
                double cbtc_current_mode = Project::TypeValue::CBTCMode::NO_MODE;

                //=========================================================================================
                // The following data is populated using Data from the Auto Train Operation Module
                //=========================================================================================

                // Identifies when ATO is available for selection
                bool ato_is_available = false;

                // Identifies when ROS is available for selection
                bool ros_is_available = false;

                // Identifies whether ATO is currently active
                double ato_driving_state = Project::TypeValue::ATOState::NOT_IN_AM;

                // Used to identify whether or not MA to be shortened due to train doors being open
                double train_door_closed_and_locked = Project::TypeValue::TrainDoorInterlock::NO_INTERLOCK;

                // Used to identify train door enable bypass
                double no_door_enable_bypass = Project::TypeValue::NoDoorInterlockBypass::NO_BYPASS;

                // Used to determine when train is at standstill
                double zero_speed = Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN;

                // Reports current platform status
                double platform_status = Project::TypeValue::PlatformStatus::NOT_DOCKED;

                // Reports radio comms status
                double radio_communication_state = Project::TypeValue::RadioCommsStatus::COMMS_NOT_ESTABLISHED;

                // Reperts mode selector position
                double mode_selector_position = Project::TypeValue::ModeSelector::OFF_UTO;

                double atp_zone_region; // Valid values given by Project::TypeValue::ATPZoneStatus
            };

            struct Outputs
            {
                /// Speed Profile data  as (train path location, speed limit)
                SpeedProfilePoints speed_data_profile;

                /// Identifies the speed limit that applies to the train at the start of the speed profile
                double speed_profile_speed_limit = INVALID_SPEED;

                // Reports the gradient profile data as (train path location, gradient)
                GradientProfilePoints path_gradient_profile;

                /// Reports next track event that is to be reported to the DMI
                CBTC::Protos::TrackEventList::TrackEvent next_track_event;

                /// Flags when the train is in the transition area associated with entering into the automatic region
                bool transition_into_automatic = false;

                /// Identifies the driver events to be reported to the DMI
                double dmi_driver_event_skip_station = Project::TypeValue::DriverEventStatus::INACTIVE;
                double dmi_driver_event_change_ends  = Project::TypeValue::DriverEventStatus::INACTIVE;
                double dmi_driver_event_work_zone    = Project::TypeValue::DriverEventStatus::INACTIVE;

                // Stopping distance is reported for train model in ATO Driving for accurate docking
                double stopping_distance = INVALID_DISTANCE;

                // Movement Authority data required for distance monitoring
                double eoa_distance = INVALID_DISTANCE;
                double svl_distance = INVALID_DISTANCE;
                bool   ma_shortened = false;
            };

            struct State
            {
                double track_event_reference_position = INVALID_DISTANCE;

                // List of all skip stations (absolute path distance, station code)
                SkipStationEvents skip_station_events;

                // List of all transition track events ahead of the train (absolute path distance, track event)
                TrackEvents transition_track_events;

                // List of all driver track events ahead of the train (absolute path distance, track event)
                TrackEvents driver_track_events;

                double gradient_reference_position = INVALID_DISTANCE;

                // Reports the gradient profile data as (absolute path location, gradient)
                GradientProfilePoints path_gradient_profile;

                double speed_reference_position = INVALID_DISTANCE;

                /// Speed Profile data  as (train path location, speed limit)
                //  - Speed profile points deleted as the train moves past them
                SpeedProfilePoints speed_data_profile;

                /// Flags that ATO was disabled due to a stopping point being reached and that the current stopping
                /// point should be ignored when determining the distance to the next stopping point
                bool ignore_next_stopping_point = false;

                // Flags that a skip station speed limit has been injected into the speed profile
                bool skipping_station = false;

                // Record speed limit values whose units need to be converted
                double auto_skip_speed_limit_kph = INVALID_SPEED;

                // Movement Authority data
                double eoa_distance      = INVALID_DISTANCE;
                double svl_distance      = INVALID_DISTANCE;
                double stopping_distance = INVALID_DISTANCE;

                double previous_train_position = INVALID_DISTANCE;

                // Points to the injected speed limit so that it can be removed if the station stops being skipped
                double skip_station_speed_profile_location = INVALID_DISTANCE;
            };
        };

        /// This module handles the all of the functionality associated with radio communications.
        ///
        class TrackSideDataModule : public CBTCModule<TrackSideDataModule, TrackSideDataModuleIO>
        {
        public:
            TrackSideDataModule(const Initialisation& init);

            void Step(double time_step);

        private:
            void ProcessMovementAuthorityData();
            void ProcessSpeedProfileData();
            void UpdateTracksideData();
            void ProcessGradientProfileData();
            void ProcessTrackEventList();
            void ManageTrackEvents();

            bool IgnoreNextStoppingPoint();
        };
    }
}
