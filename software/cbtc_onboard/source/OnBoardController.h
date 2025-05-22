///
/// @file       OnBoardController.h
///
///             Declares the controller that controls a number of functional submodules in order to simulate
///             an CBTC Protection system.
///
/// @ingroup    Core Train Sim
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#pragma once

#include "AutomaticTrainOperationModule.h"
#include "AutomaticTrainProtectionModule.h"
#include "BeaconManagementModule.h"
#include "ModeModelTransitionSource/ModeTransitionModule.h"
#include "SpeedAndDistanceMonitoringModule.h"
#include "TextManagementModule.h"
#include "TrackSideDataModule.h"

#include "Protobuf/CBTCOnboard.pb.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Defines the standard IO structures required by a Module
        /// The controller provides this IO structure in order to received the initialisations
        /// data that is required by its submodules and in order to propagate the state of its
        /// submodules back to the parent unit which is responsible for snapshoting and restoring
        /// the state of the CBTC OnBoard System

        struct OnBoardControllerIO
        {
            struct Initialisation
            {
                // Configuration data read from the OnBoard config file
                double train_position_uncertainty;
                double dbec;
                double ebd_rate;
                double sbd_rate;
                double ato_brake_demand_rate;
                double t_service_brake;
                double t_indication;
                double auto_region_speed_limit;
                double rmf_speed_limit;
                double rmr_speed_limit;
                double ros_speed_limit;
                double auto_skip_speed_limit;
                double auto_skip_distance;
                double memorised_localisation_speed_limit;
                double memorised_localisation_validity_distance;
                double max_rollback_distance;
                double max_reversing_zone;
                double fsb_speed_limit;
                double long_docking_distance;
                double overshoot_distance;
                double undershoot_distance;
                double work_zone_alarm_distance;
                double train_length;
                bool   fsb_enabled;

                double dv_ebi_min;
                double dv_ebi_max;
                double v_ebi_min;
                double v_ebi_max;
                double dv_sbi_min;
                double dv_sbi_max;
                double v_sbi_min;
                double v_sbi_max;
                double dv_warning_min;
                double dv_warning_max;
                double v_warning_min;
                double v_warning_max;
                double t_warning;
                double t_driver;
                double t_preindiction;

                // Session Start time from Session Data
                unsigned long session_start_time;
            };

            struct Inputs
            {
                // All inputs populated from the train model via train interface
                double current_train_speed;
                double current_train_position;
                double auto_power_on; // Valid values given by Project::TypeValues::AutoPowerOn
                double train_wakeup;
                double cab_activation;
                //Faults
                double atc_eb_unable_to_reset;
                double train_doors_not_opening_in_ato;
                double train_zero_speed_order;
                double psd_door_not_opening;
				double psd_adcl_not_available_fault;
				double psd_bypassed_fault;
                double failure_of_trainborne_atc_equipment;

                // All inputs populated from the train model via vehicle interface
                double atc_loss_of_comms_error; // Valid values given by Project::CBTCOnBoard::TypeValues::CommsStatus
                double initial_localisation_state; // Valid values given by
                                                   // Project::CBTCOnBoard::TypeValue::LocalisationState
                double ato_position_error; // Valid values given by Project::CBTCOnBoard::TypeValue::ATOPositionError

                // All inputs populated from the train model via CBTCVehicleOutput interface
                double power_supply;                 // Valid values given by Project::TypeValue::PowerSupply
                double cabin_activation;             // Valid values given by Project::TypeValue::CabinActivation
                double driver_mode_selection;        // Valid values given by Project::TypeValue::DriverModeSelection
                double emergency_door_not_open;      // Valid values given by Project::TypeValue::DetrainmentDoorStatus
                double atc_bypass_state;             // Valid values given by Project::TypeValue::ATCBypassState
                double tbc_position;                 // Valid values given by Project::TypeValue::TBCPosition
                double ato_start_button;             // Valid values given by Project::TypeValue::ButtonState
                double uto_start_button;             // Valid values given by Project::TypeValue::ButtonState
                double wake_up_status;               // Valid values given by Project::TypeValue::ButtonState
                double mode_selector_position;       // Valid values given by Project::TypeValue::mode_selector_position
                double train_door_closed_and_locked; // Valid values given by Project::TypeValue::TrainDoorInterlock
                double no_emergency_brake;           // Valid values given by Project::TypeValue::SafetyBrakeStatus
                double atc_sb_reset_button;          // Valid values given by Project::TypeValue::ButtonState
                double no_door_enable_bypass;        // Valid values given by Project::TypeValue::NoDoorInterlockBypass
                double tcms_speed_limit;
                double tcms_speed_limit_cause;

                // All inputs populated from the CBTC world units via CBTCOnBoardInput interface
                double                       last_detected_beacon; // Feature ID of last detected beacon. -1 means fault
                CBTC::Protos::TrackEventList track_event_data;
                CBTC::Protos::GradientProfile   gradient_discontinuities;
                CBTC::Protos::MovementAuthority movement_authority;
                CBTC::Protos::SpeedLimitList    speed_limit_profile;

                // CBTC Platform Unit to CBTCOnBoardInput interface
                double platform_status;        // Valid values given by Project::TypeValue::PlatformStatus
                double train_near_platform;    // Valid values given by Project::TypeValue::PlatformRegion
                double lhs_platform_detection; // Valid values given by Project::TypeValue::PlatformDetection
                double rhs_platform_detection; // Valid values given by Project::TypeValue::PlatformDetection
                double psd_present;            // Valid values given by Project::TypeValue::PSDPresent
                double depot_region;           // Valid values given by Project::TypeValue::DepotIndication
                double atp_zone_region;        // Valid values given by Project::TypeValue::ATPZoneStatus
                double train_dock_status;      // Valid values given by Project::TypeValue::TrainDockingStatus
                double psd_door_status;        // Valid values given by Project::TypeValue::PSDDoorStatus
                double psd_interlock_override_status;
                double departure_order_status;
                // DMI to CBTCOnBoardInput interface
                double cbtc_message_acknowledge; /// Unique ID that identifies the message that has been acknowledged
                int    active_call_type;
                int    call_status;
				double pabr_bypass_req;
                //Vehicle inputs
                int       emergency_brake_pb;
                int       emergency_stop_pb;
                double master_brake_controller;
            };

            struct Outputs
            {
                // All inputs sent to the train model via CBTCVehicleInputs interface
                double service_brake_request;          // Valid values given by Project::TypeValues::ServiceBrakeOrder
                double emergency_brake_request;        // Valid values given by Project::TypeValues::EmergencyBrakeOrder
                double immobilisation_state;           // Valid values given by Project::TypeValues::ImmobilisationState
                double left_door_close_indicator;
                double right_door_close_indicator;
                double audio_safety_brake_alarm;       // Valid values given by Project::TypeValues::CBTCAudio
                double audio_warning_alarm;            // Valid values given by Project::TypeValues::CBTCAudio
                double audio_departure_order;          // Valid values given by Project::TypeValues::CBTCAudio
                double audio_target_speed;             // Valid values given by Project::TypeValues::CBTCAudio
                double audio_high_priority_text_alert; // Valid values given by Project::TypeValues::CBTCAudio
                double audio_acknowledge;              // Valid values given by Project::TypeValues::CBTCAudio
                double uto_mode_active;                // Valid values given by Project::TypeValues::IndicatorState
                double ato_state;                      // Project::TypeValues::ATOState
                double ato_permitted_speed;            // speed in m/sec
                double ato_permitted_distance;         // distance in m
                double ato_start_indicator;            // Valid values given by Project::TypeValues::IndicatorState
                double atc_cab_activation;             // Valid values given by Project::TypeValues::IndicatorState
                double traction_forward;               // Valid values given by Project::TypeValues::IndicatorState
                double ros_indicator;                  // Valid values given by Project::TypeValues::IndicatorState
                double uto_pb_indicator;               // Valid values given by Project::TypeValues::IndicatorState
                double wake_up_command;                // Valid values given by Project::TypeValues::IndicatorState
                double atc_safety_brake_reset_indicator; // Valid values given by Project::TypeValues::IndicatorState
                double left_side_door_enable;        // Valid values given by Project::TypeValues::CorrectSideDoorEnable
                double right_side_door_enable;       // Valid values given by Project::TypeValues::CorrectSideDoorEnable
                double left_door_open_indicator;     // Valid values given by Project::TypeValues::IndicatorState
                double left_door_release_indicator;  // Valid values given by Project::TypeValues::IndicatorState
                double left_hold_door_close;         // Valid values given by Project::TypeValues::IndicatorState
                double right_hold_door_close;        // Valid values given by Project::TypeValues::IndicatorState
                double open_left_train_doors;        // Valid values given by Project::TypeValues::OpenDoorRequest
                double right_door_open_indicator;    // Valid values given by Project::TypeValues::IndicatorState
                double right_door_release_indicator; // Valid values given by Project::TypeValues::IndicatorState
                double open_right_train_doors;       // Valid values given by Project::TypeValues::OpenDoorRequest
                double zero_speed;                   // Valid values given by Project::TypeValues::ZeroSpeedState
                double rollback_detected;            // Valid values given by Project::TypeValue::IndicatorState

                // CBTCOnBoardOutput interface to DMI
                double current_train_speed;        // Speed in m/sec
                double cbtc_target_speed;          // Speed in m/sec
                double cbtc_permitted_speed;       // Speed in m/sec
                double warning_status;             // Valid values given by Project::TypeValue::DMIWarningStatus
                double safety_brake;               // Valid values given by Project::TypeValue::SafetyBrakeState
                double atc_status;                 // Valid values given by Project::TypeValue::ATCStatus
                double target_distance;            // Distance in meters
                double localisation_status;        // Valid values given by Project::TypeValue::LocalisationStatus
                double advisory_speed;             // Speed in m/sec
                double warning_speed;              // Speed in m/sec
                double driver_event_skip_station;  // Valid values given by Project::TypeValue::DriverEventStatus
                double driver_event_change_ends;   // Valid values given by Project::TypeValue::DriverEventStatus
                double driver_event_work_zone;     // Valid values given by Project::TypeValue::DriverEventStatus
                double detrainment_door_status;    // Valid values given by Project::TypeValue::DetrainmentDoorStatus
                double radio_communication_status; // Valid values given by Project::TypeValue::RadioCommsStatus
                double atc_bypass_state;           // Valid values given by Project::TypeValue::ATCBypassState
                double emergency_brake_trigger;    // Valid values given by Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger
                double depot_indication;           // Valid values given by Project::TypeValue::DepotIndication
                double atp_zone_status;            // Valid values given by Project::TypeValue::ATPZoneStatus
                CBTC::Protos::CBTCTextMessages   text_messages;
                CBTC::Protos::AvailableModesList available_driving_modes;

                // CBTCOnBoardOutput interface to both DMI and Platform Unit
                // Valid values given by Project::TypeValue::CBTCMode
                double current_driving_mode = Project::TypeValue::CBTCMode::NO_MODE;
            };

            struct State
            {
                // The state includes the state of the different submodules.
                SpeedAndDistanceMonitoringModule::State speed_and_distance_monitoring_module_state;
                BeaconManagementModule::State           beacon_management_module_state;
                ModeTransitionModule::State             mode_transition_state;
                AutomaticTrainOperationModule::State    automatic_train_operation_state;
                AutomaticTrainProtectionModule::State   automatic_train_protection_state;
                TextManagementModule::State             text_management_state;
                TrackSideDataModule::State              trackside_data_state;

                /// Flags when scenario initialisation of Onboard system is completed
                bool scenario_initialisation_completed;

                /// Flags when scenario initialisation requires a radio connection
                bool radio_setup_required;

                /// Initial mode a scenario should start up in
                double initial_scenario_mode;

                // =========================================================================================
                // The following state data is required for playing audio sounds
                // =========================================================================================

                /// Used to report the display of a new message that require audio to be played
                bool new_high_priority_msg_reported;
                bool new_acknowledge_msg_reported;

                /// previous value of target speed
                double cbtc_target_speed;

                /// previous value of platform Status
                double platform_status;

                // previous value of brake trigger
                Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger emergency_brake_trigger;

                /// Time at which EB brake, Departure Order or New Target Speed audio was triggered
                double s_info_start_time;

                /// Time at which High Priority Text Alert or Acknowledge Text Alert audio was triggered
                double text_alert_audio_start_time;

                // =========================================================================================
                // The following state data is required for power up tests
                // =========================================================================================

                /// Identifies what stage of the CBTC startup test process we are currently at
                Project::CBTCOnBoard::TypeValue::StartupTestStage start_up_test_stage;

                /// Determines when the system has completed the system power up tests
                bool power_up_test_completed;

                /// Records the time at which the power up tests were started
                double power_up_test_start_time;

                // =========================================================================================
                // The following state data is required for managing sytem status and the radio connection
                // =========================================================================================

                // Onboard System status information maintained by the Onboard Controller
                double atc_status;
                double radio_communication_status;

                // Identifies the time at which a connection request was initiated
                double connection_start_time;

                // =========================================================================================
                // The following additional state data is required to be kept between each run cycle
                // =========================================================================================

                // CBTC Mode to be used by modules in the current run cycle
                double cbtc_current_mode;

                // Records the previous position of the driver mode selector
                double driver_mode_selection;

                // Records the position of the driver mode selector
                double mode_selector_position;
            };
        };

        /// This Controller is the owner of the functional modules that compose the CBTC OnBoard system
        ///
        /// The Controller is responsible for
        ///   - Creating and initialising the CBTC Onboard functional submodules
        ///   - Getting the Inputs from the External systems and passing these onto the functional modules
        ///   - Calling the runcycles of the functional modules and passing the outputs from one module to the inputs of
        ///   another
        ///   - Recording as state any module outputs that need to be provided as inputs in the controllers next run
        ///   cycle
        ///   - Taking the outputs of the functional submodules and reporting them to the external world

        class OnBoardController : public CBTCModule<OnBoardController, OnBoardControllerIO>
        {
        public:
            /// The interface that a class that supplies Train and Vehicle data must provide in order to
            /// be used by the OnBoard controller.
            class TrainInputSupplier
            {
            public:
                virtual ~TrainInputSupplier() {}

                virtual void GetTrainInputs(OnBoardControllerIO::Inputs& inputs) = 0;
            };

            /// The interface that a class that supplies CBTC Onboard input data must provide in order to
            /// be used by the OnBoard controller.
            class CBTCDataInputSupplier
            {
            public:
                virtual ~CBTCDataInputSupplier() {}

                // Get the DMI related input data
                virtual void GetOnBoardDataInputs(OnBoardControllerIO::Inputs& inputs) = 0;
                virtual void SetPlatformOutputs(OnBoardControllerIO::Inputs& inputs)   = 0;
            };

            /// The interface that a class that processes outputs must provide in order to report data to comms.
            class OutputsReporter
            {
            public:
                virtual ~OutputsReporter() {}

                virtual void SetOnBoardDataOutputs(const OnBoardControllerIO::Outputs& outputs) = 0;
                virtual void SetTrainOutputs(const OnBoardControllerIO::Outputs& outputs)       = 0;
            };

        public:
            OnBoardController(const Initialisation&  init,
                              TrainInputSupplier&    train_inputs,
                              CBTCDataInputSupplier& cbtc_data,
                              OutputsReporter&       outputs_reporter);

            void Step(double time_step);

        private:
            void ProcessAutomaticTrainOperationModule(double time_step);
            void ProcessAutomaticTrainProtectionModule(double time_step);
            void ProcessBeaconManagementModule(double time_step);
            void ProcessModeTransitionModuleModule(double time_step);
            void ProcessSpeedAndDistanceMonitoringModule(double time_step);
            void ProcessTextManagementModule(double time_step);
            void ProcessTrackSideDataManagementModule(double time_step);

            void PerformSystemPowerupTest(double time_step);
            void PerformCBTCOnboardSetup();

            void PlayAudio(double time_step);
            void DetermineOnboardStatus();
            void ManageRadioConnection(double time_step);

        private:
            // The submodules that implement the functionality of the CBTC OnBoard System:
            SpeedAndDistanceMonitoringModule m_speed_and_distance_monitoring;
            BeaconManagementModule           m_beacon_management;
            AutomaticTrainOperationModule    m_automatic_train_operation;
            AutomaticTrainProtectionModule   m_automatic_train_protection;
            ModeTransitionModule             m_mode_transition_machine;
            TextManagementModule             m_text_management;
            TrackSideDataModule              m_trackside_data_management;

            // Interfaces through which the OnBoard Controller sends and receives information to/from
            // the Systems it interacts with
            TrainInputSupplier&    m_train_inputs;
            CBTCDataInputSupplier& m_cbtc_data_input;
            OutputsReporter&       m_outputs_reporter;
        };
    }
}
