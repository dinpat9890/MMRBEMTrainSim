///
/// @file       AutomaticTrainOperationModule.h
///
///             Module that handles the functionality related to the Automatic Train Operation function of the CBTC
///             OnBoard System.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#pragma once

#include "CBTCConstants.h"
#include "CBTCModule.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Defines the standard structures required of a Module
        struct AutomaticTrainOperationModuleIO
        {
            struct Initialisation
            {
            };

            struct Inputs
            {
                //=========================================================================================
                // The following data is populated using Comms Data from the Train Model
                //=========================================================================================

                double current_train_position = INVALID_DISTANCE;
                double current_train_speed    = INVALID_SPEED;
                // Trains current door interlock state
                double train_door_closed_and_locked = Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED;
                //MMRBEM-4447: train_door_closed_and_locked is not exact train door status. It is set with multiple conditions in OnBoardController::ProcessAutomaticTrainOperationModule
                //So, added new train_door_closed member to get train door status.
                double train_door_closed = Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED;

                // Train front is located inside automatic region
                // double in_automatic_region = Project::TypeValue::Region::INSIDE_REGION;

                // Identifies when ATO start button is pressed
                double ato_start_button = Project::TypeValue::ButtonState::UNPRESSED;

                // Identifies when ATO start button is pressed
                double uto_start_button = Project::TypeValue::ButtonState::UNPRESSED;

                // Reports traction brake controller position
                double tbc_position = Project::TypeValue::TBCPosition::FULL_SB;

                //=========================================================================================
                // The following data is populated using CBTCOnboardInputs data provided by Platform unit
                //=========================================================================================

                /// Information about the platform status
                double platform_status = Project::TypeValue::PlatformStatus::NOT_DOCKED;

                /// Reports detection of accessable platform on the LHS of the train
                double lhs_platform_detection = Project::TypeValue::PlatformDetection::NO_PLATFORM_DETECTED;

                /// Reports detection of accessable platform on the RHS of the train
                double rhs_platform_detection = Project::TypeValue::PlatformDetection::NO_PLATFORM_DETECTED;

                /// Reports the trains current localisation state
                double localisation_state = Project::TypeValue::LocalisationStatus::UNAVAILABLE;

                //=========================================================================================
                // The following data is populated using Data from the Trackside Data Management Module
                //=========================================================================================

                /// Distance to the End Of Authority
                double eoa_distance = INVALID_DISTANCE;

                /// Distance to the Stopping Point
                double stopping_point_distance = INVALID_DISTANCE;

                //=========================================================================================
                // The following data is populated using Data from the Speed and Distance Monitoring Module
                //=========================================================================================

                // Reports whether train speed below the minimum speed to be considered at standstill
                double zero_speed = Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN;

                //=========================================================================================
                // The following data is populated using Data from the Mode Transitions Module
                //=========================================================================================

                /// Provides the current CBTC Driving mode
                double cbtc_current_mode = Project::TypeValue::CBTCMode::NO_MODE;

                /// Provides the mode selector position
                double mode_selector_position = Project::TypeValue::ModeSelector::OFF_UTO;

                // Provide the driver mode selection
                double driver_mode_selection = Project::TypeValue::DriverModeSelection::OFF;

                /// Populated using inputs from the Train Model
                double cabin_activation = Project::TypeValue::CabinActivation::INACTIVE;
                double uto_pb_indicator = Project::TypeValue::IndicatorState::OFF;
                double wake_up_status   = Project::TypeValue::IndicatorState::OFF;

                /// Fault for door opening in ATO mode
                bool train_doors_not_opening_in_ato_mode = false;
                bool psd_doors_not_opening_fault_flag = false;

                bool emergency_brake_pressed = false;
                bool emergency_stop_pressed = false;
            };

            struct Outputs
            {
                // Reports when ATO driving is to be active
                double ato_driving_state = Project::TypeValue::ATOState::NOT_IN_AM;

                // Reports when ATO driving is to be active
                double uto_mode_active = Project::TypeValue::UTOState::AM_UTO_DISABLED;

                // Flags whether or not ATO driving is available for activation
                bool ato_is_available = false;

                // Flags whether or not UTO driving is available for activation
                bool uto_is_available = false;

                // Flags whether or not ROS driving is available for activation
                bool ros_is_available = false;

                // Controls the indicator that is used to notify the driver that ATO is available
                double ato_start_indicator = Project::TypeValue::IndicatorState::OFF;

                // Controls the wakeup is available for UTO mode
                //  double wake_up_command = Project::TypeValue::IndicatorState::OFF;

                // Controls the indicator that is used to notify the driver that ROS is available
                double ros_indicator = Project::TypeValue::IndicatorState::OFF;

                // Controls the indicator that is used to notify the driver that UTO is available
                double uto_pb_indicator = Project::TypeValue::IndicatorState::OFF;

                // Controls the indicator that is used to notify the driver the direction of travel. i.e. Forward
                double traction_forward = Project::TypeValue::IndicatorState::OFF;

                // LHS train door indicators and controls
                double left_side_door_enable       = Project::TypeValue::CorrectSideDoorEnable::SIDE_DISABLED;
                double left_door_open_indicator    = Project::TypeValue::IndicatorState::OFF;
                double left_door_release_indicator = Project::TypeValue::IndicatorState::OFF;
                double left_hold_door_close        = Project::TypeValue::IndicatorState::ON;
                double open_left_doors             = Project::TypeValue::OpenDoorRequest::NO_OPEN_DOOR_REQUEST;

                // RHS train door indicators and controls
                double right_side_door_enable       = Project::TypeValue::CorrectSideDoorEnable::SIDE_DISABLED;
                double right_door_open_indicator    = Project::TypeValue::IndicatorState::OFF;
                double right_door_release_indicator = Project::TypeValue::IndicatorState::OFF;
                double right_hold_door_close        = Project::TypeValue::IndicatorState::ON;
                double open_right_doors             = Project::TypeValue::OpenDoorRequest::NO_OPEN_DOOR_REQUEST;
            };

            struct State
            {

                // Records the state of the door indicators and controls
                // Note : These values will be mapped to either the LHS or RHS outputs depending on
                //        which side of the train a platform has been detected on
                double door_enable            = Project::TypeValue::CorrectSideDoorEnable::SIDE_DISABLED;
                double door_open_indicator    = Project::TypeValue::IndicatorState::OFF;
                double door_release_indicator = Project::TypeValue::IndicatorState::OFF;
                double auto_door_open_request = Project::TypeValue::OpenDoorRequest::NO_OPEN_DOOR_REQUEST;

                // Used to control the duration for which a pulsed signal is pulsed
                double pulse_start_time = UNDEFINED_TIME_STAMP;

                // Flags when ATO driving is to be active
                double ato_driving_state = Project::TypeValue::ATOState::AM_ATO_DISABLED;

                // Flags when UTO driving is to be active
                double uto_mode_active = Project::TypeValue::UTOState::AM_UTO_DISABLED;

                // Flags whether or not ATO driving is available for activation
                bool ato_is_available = false;

                // Flags whether or not UTO driving is available for activation
                bool uto_is_available = false;
            };
        };

        /// This module handles the all of the functionality associated with automatic train operation.
        ///
        class AutomaticTrainOperationModule : public CBTCModule<AutomaticTrainOperationModule, AutomaticTrainOperationModuleIO>
        {
        public:
            AutomaticTrainOperationModule(const Initialisation& init);

            void Step(double time_step);

        private:
            void ManageTrainDoorOperation(double time_step);
            void SetATOStartIndicator(double time_step);
            std::chrono::steady_clock::time_point ato_driving_three_sec_timer = std::chrono::steady_clock::time_point::max();
            void SetROSStartIndicator(double time_step);
            void SetATODrivingState();
            void SetUTOStartIndicator(double time_step);
            void SetUTODrivingState();
        };
    }
}
