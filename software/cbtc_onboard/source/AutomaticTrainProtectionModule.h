///
/// @file       AutomaticTrainProtectionModule.h
///
///             Module that handles the functionality related to the automatic train protection function of the CBTC
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
        struct AutomaticTrainProtectionModuleIO
        {
            struct Initialisation
            {
                /// National value identifies when emergency brake triggered by EBI is to be
                /// released in TSM and CSM mode (standby or when under speed limit)
                TypeValue::NVEBReleaseCondition nv_tsm_eb_release_condition;

                bool   service_brake_intervention_enabled = false;
                double max_rollback_distance              = INVALID_DISTANCE;
                double max_reverse_distance               = INVALID_DISTANCE;
                double fsb_speed_overshoot                = INVALID_DISTANCE;
            };

            struct Inputs
            {
                //=========================================================================================
                // The following data is populated using Comms Data from the Train Model
                //=========================================================================================

                double current_train_position  = INVALID_DISTANCE;
                double current_train_speed     = INVALID_SPEED;
                double cabin_activation        = Project::TypeValue::CabinActivation::INACTIVE;
                bool   reset_safety_brake      = false; // Safety brake reset has been requested.
                bool   train_near_station      = false;
                bool   doors_closed_and_locked = false;
                bool   train_held_at_station   = false;
                double psd_door_close_status   = Project::TypeValue::PSDDoorStatus::UNAVAILABLE;
                double psd_interlock_override_status = Project::TypeValue::IndicatorState::OFF;

                double stopping_point_distance = INVALID_DISTANCE;

                //VehicleInputs
                double master_brake_controller = 0.0;

                //=========================================================================================
                // The following data is populated using outputs from the Mode Transition Module
                //=========================================================================================

                // Identifies the current CBTC Driving Mode
                double cbtc_current_mode = Project::TypeValue::CBTCMode::NO_MODE;
                
                /// Provides the mode selector position
                double mode_selector_position = Project::TypeValue::ModeSelector::OFF_UTO;
                //=========================================================================================
                // The following data is populated using outputs from the Speed & Distance Monitoring Module
                //=========================================================================================

                /// Identifies when SBI and EBI should be enabled and braking applied when
                /// supervised speeds are exceeded
                bool speed_monitoring_active = false;

                /// Identifies the current speed monitoring mode
                Project::CBTCOnBoard::TypeValue::MonitoringMode monitoring_mode = Project::CBTCOnBoard::TypeValue::MonitoringMode::CSM;

                /// Velocity for emergency brake intervention
                double eb_intervention_velocity = INVALID_SPEED;

                /// Velocity for service brake intervention
                double sb_intervention_velocity = INVALID_SPEED;

                /// Velocity for warning speed
                double warning_velocity = INVALID_SPEED;

                /// warning speed
                double warning_speed = INVALID_SPEED;

                double advisory_speed = INVALID_SPEED;

                /// Velocity for permitted speed
                double permitted_velocity = INVALID_SPEED;

                /// Flags whether or not the train has moved back more than the allowed distance in post trip mode
                bool max_reverse_distance_exceeded = false;

                /// Reports when EOA is exceeded
                bool movement_authority_exceeded = false;

                // Zero speed state of train
                double train_at_standstill = false; // NB: Implicit casting boolean to double to interface with comms

                //=========================================================================================
                // The following data is populated using outputs from the Beacon Management Module
                //=========================================================================================

                ///  Safety brake applied if localisation is lost
                double current_localisation_state = Project::TypeValue::LocalisationStatus::UNAVAILABLE;

                //=========================================================================================
                // The following data is populated using data produced by the Onboard Controller Module
                //=========================================================================================

                /// Current state of the connection with the CBTC radio
                double radio_communication_state = Project::TypeValue::RadioCommsStatus::COMMS_NOT_ESTABLISHED;

                //=========================================================================================
                // The following data is populated using CBTCInputData produced by the Platform unit
                //=========================================================================================

                /// Current platform status
                double platform_status = Project::TypeValue::PlatformStatus::NOT_DOCKED;

                /// Current docking info
                double train_docking_status = Project::TypeValue::TrainDockingStatus::UNKNOWN;

                double tcms_speed_limit;
                double tcms_speed_limit_cause;

                int active_call_type;
                int call_status;

				//PABR bypass req
				double pabr_bypass_req;
            };

            struct Outputs
            {
                // Identifies the imobilisation state of the train
                double immobilisation_state = Project::TypeValue::ImmobilisationState::IMMOBILSED;

                //=========================================================================================
                // The following data is outputed via Comms Data to the Train Model
                //=========================================================================================

                /// Used to control the application of the emergency brake
                double emergency_brake_request = Project::TypeValue::EmergencyBrakeOrder::NO_EB_BRAKE;

                /// Used to control the application of traction cuttoff
                bool traction_cutoff_active = false;

                /// Used to control the application of the service brake;
                double service_brake_request = Project::TypeValue::ServiceBrakeOrder::NO_SB_DEMAND;

                /// Safety brake reset is required to release the emergency brake
                bool request_safety_brake_reset = false;

                //=========================================================================================
                // The following data is outputted to Text Management Module for reporting to the DMI
                //=========================================================================================

                /// Identifies the reason for the emergency brake.
                Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger emergency_brake_condition =
                  Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED;
            };

            struct State
            {
                /// The train position in the previous runcycle
                double prev_train_position = 0;

                // Used to detect CBTC Driving mode transitions
                double cbtc_current_mode = Project::TypeValue::CBTCMode::NO_MODE;

                /// Provides the mode selector position
                double mode_selector_position = Project::TypeValue::ModeSelector::OFF_UTO;

                /// Records previously state of traction cutoff
                bool traction_cutoff_active = false;

                /// Records previously reported state of the service brake;
                double service_brake_request = Project::TypeValue::ServiceBrakeOrder::NO_SB_DEMAND;

                /// Records previously reported state of the emergency brake;
                Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger emergency_brake_trigger =
                  Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED;

                // Used to track how far the train moves while providing movement protection
                double rollback_movement_distance   = 0;
                double distance_travelled_backwards = 0;

                /// Records the time of full service brake to be applied.
                double full_service_brake_start_time = UNDEFINED_TIME_STAMP;
            };
        };

        /// This module handles the all of the functionality associated with controlling traction and the brakes.
        ///
        class AutomaticTrainProtectionModule : public CBTCModule<AutomaticTrainProtectionModule, AutomaticTrainProtectionModuleIO>
        {
        public:
            AutomaticTrainProtectionModule(const Initialisation& init);

            void Step(double time_step);

        private:
            // Functions to control the brakes and traction
            void ControlEmergencyBrake();
            void ControlServiceBrake(double time_step);
            void ControlTractionCutOff();

            // Helper function to report when movement protection has been triggered
            bool TriggerDelocalisation();
            bool TriggerRollawayProtection();
            bool TriggerReverseMovementProtection();
            bool TriggerChangeOnRun();
            bool TriggerDoorsUnlocked();
            bool TriggerPSDUnlocked();
            bool TriggerRadioLost();
            bool TriggerTrainHold();
            bool TriggerOverspeedIntervention(double intervention_velocity);
            bool TriggerPECActive();

            // Train Immobilisation Control
            void ControlTrainImmobilisation();

            // Test current speed against threshold (including delta for train model fluctuations)
            bool IsSpeedThresholdExceeded(double threshold_speed) const;
            bool sb_flag = false;
        };
    }
}
