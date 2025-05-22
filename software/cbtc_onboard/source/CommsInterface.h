///
/// @file       CommsInterface.h
///
///             Handles the communication between Comms and the CBTC OnBoard Controller.
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#pragma once

#include "CBTCOnBoardProperties.h"
#include "OnBoardController.h"

#include "sim_comms/Unit.h"
#include "utility/Locking.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Class that implements the interface classes through which the CBTC OnBoard Controller
        /// interacts with the Comms interface.
        ///
        /// When the update functions in the Outputs Receiver interface are called, the updates are
        /// not immediately sent to Comms but rather buffered for future transmission. In order for the
        /// Updates to be sent to Comms it is necessary to call the SendUpdates() method.
        ///
        class CommsInterface : public OnBoardController::TrainInputSupplier,
                               public OnBoardController::CBTCDataInputSupplier,
                               public OnBoardController::OutputsReporter
        {
        public:
            CommsInterface(Comms::Gateway& gateway, CBTCOnBoardProperties& properties, int train_id, int vehicle_id);

            void RegisterWithComms();

            const bool IsCommsInitialisationComplete();

            // OnBoardController::TrainInputSupplier
            void GetTrainInputs(OnBoardControllerIO::Inputs& inputs) override;

            // OnBoardController::CBTCDataInputSupplier
            void GetOnBoardDataInputs(CBTCOnBoard::OnBoardControllerIO::Inputs& inputs) override;

            // OnBoardController::OutputsReporter
            void SetOnBoardDataOutputs(const CBTCOnBoard::OnBoardControllerIO::Outputs& outputs) override;
            void SetTrainOutputs(const CBTCOnBoard::OnBoardControllerIO::Outputs& outputs) override;
            void SetPlatformOutputs(CBTCOnBoard::OnBoardControllerIO::Inputs& inputs) override;

            // Send all of the updated outputs
            void SendUpdates(double current_time);

        public:
            // Monitors for object creation
            void ObjectCreated(Comms::Object object);
            void IntercomCreated(Comms::Object object);
            void IntercomOutputCreated(Comms::Object object);
            void OHPOutputCreated(Comms::Object object);
            void VehicleCreated(Comms::Object object);
            void VehicleChildCreated(Comms::Object object);
            void CBTCVehicleInputsCreated(Comms::Object object);
            void CBTCVehicleOutputsCreated(Comms::Object object);
            void CBTCOnBoardInputsCreated(Comms::Object object);
            void CBTCOnBoardOutputsCreated(Comms::Object object);
            void CBTCPlatformOutputsCreated(Comms::Object object);
            void VehicleInputsCreated(Comms::Object object);
            // Monitor for object destruction
            void ObjectDestroyed(Comms::Object object);

        private:
            /// Information on train data related Comms objects, mostly holding precalculated IDs.
            struct TrainInfo
            {
                // =========================================================================================
                // The objects and property Ids that hold the input data received from the Train model.
                // =========================================================================================
                Comms::Object train_object;
                Comms::Object vehicle_object;
                Comms::Object cbct_vehicle_outputs_object;

                // The train object property Ids
                Sim::Number::ID lead_car_speed_id;
                Sim::Number::ID lead_car_position_id;
                Sim::Number::ID auto_power_on_id;
                Sim::Number::ID train_wakeup_id;
                //Faults
                Sim::Number::ID atc_eb_unable_to_reset_id;
                Sim::Number::ID train_zero_speed_order_id;
                Sim::Number::ID psd_door_not_opening_fault_id;
				Sim::Number::ID psd_adcl_not_available_fault_id;
				Sim::Number::ID psd_bypassed_fault_id;

                // The vehicle object property Ids
                Sim::Number::ID position_id; // Not used - Currently using lead car position
                Sim::Number::ID speed_id;    // Not used - Currently using lead car speed
                Sim::Number::ID atc_loss_of_comms_error_id;
                Sim::Number::ID initial_localisation_state_id;
                Sim::Number::ID ato_position_error_id;
                Sim::Number::ID cab_activation_id;
                Sim::Number::ID train_doors_not_opening_in_ato_id;
                Sim::Number::ID fault_failure_of_trainborne_atc_equipment_id;

                // The CBTC Vehicle Outputs object property Ids
                Sim::Number::ID power_supply_id;
                Sim::Number::ID cabin_activation_id;
                Sim::Number::ID driver_mode_selection_id;
                Sim::Number::ID mode_selector_position_id;
                Sim::Number::ID emergency_door_not_open_id;
                Sim::Number::ID atc_bypass_state_id;
                Sim::Number::ID tbc_position_id;
                Sim::Number::ID ato_start_button_id;
                Sim::Number::ID uto_start_button_id;
                Sim::Number::ID no_emergency_brake_id;
                Sim::Number::ID atc_sb_reset_button_id;
                Sim::Number::ID no_door_enable_bypass_id;
                Sim::Number::ID train_door_closed_and_locked_id;
                Sim::Number::ID wake_up_status_id;
                Sim::Number::ID tcms_speed_limit_id;
                Sim::Number::ID tcms_speed_limit_cause_id;

                // =========================================================================================
                // The objects and property Ids that hold the output data sent to the Train model.
                // =========================================================================================
                Comms::Object cbtc_vehicle_inputs_object;

                // The CBTC Vehicle Inputs object property Ids
                Sim::Number::ID service_brake_command_id;
                Sim::Number::ID emergency_brake_command_id;
                Sim::Number::ID immobilisation_state_id;
                Sim::Number::ID audio_safety_brake_alarm_id;
                Sim::Number::ID audio_warning_alarm_id;
                Sim::Number::ID audio_departure_order_id;
                Sim::Number::ID audio_target_speed_id;
                Sim::Number::ID audio_high_priority_text_alert_id;
                Sim::Number::ID audio_acknowledge_id;
                Sim::Number::ID uto_mode_active_id;
                Sim::Number::ID ato_state_id;
                Sim::Number::ID ato_permitted_distance_id;
                Sim::Number::ID ato_permitted_speed_id;
                Sim::Number::ID ato_start_indicator_id;
                Sim::Number::ID atc_cab_activation_id;
                Sim::Number::ID traction_forward_id;
                Sim::Number::ID ros_indicator_id;
                Sim::Number::ID uto_pb_indicator_id;
                Sim::Number::ID wake_up_command_id;
                Sim::Number::ID atc_safety_brake_reset_indicator_id;
                Sim::Number::ID left_side_door_enable_id;
                Sim::Number::ID right_side_door_enable_id;
                Sim::Number::ID left_hold_door_close_id;
                Sim::Number::ID right_hold_door_close_id;
                Sim::Number::ID left_door_open_indicator_id;
                Sim::Number::ID left_door_release_indicator_id;
                Sim::Number::ID open_left_train_doors_id;
                Sim::Number::ID right_door_open_indicator_id;
                Sim::Number::ID right_door_release_indicator_id;
                Sim::Number::ID open_right_train_doors_id;
                Sim::Number::ID zero_speed_id;
                Sim::Number::ID rollback_detection_id;
                Sim::Number::ID left_door_close_indicator_id;
                Sim::Number::ID right_door_close_indicator_id;

                Comms::Object intercom_output_object;

                Sim::Number::ID active_call_type_id;
				Sim::Number::ID pabr_bypass_req_id;

                Comms::Object OHP_output_object;

                Sim::Number::ID call_status_id;

                // =========================================================================================
                // The object and property Ids that hold the Vehicle Inputs information.
                // =========================================================================================
                Comms::Object vehicle_inputs_object;
                
                // Emergency buttons
                Sim::Number::ID emergency_brake_pb_id;
                Sim::Number::ID emergency_stop_pb_id;
                Sim::Number::ID master_controller_handle_id;
            };

            /// Information on the CBTC OnBoard Inputs and Outputs Comms objects, mostly holding precalculated IDs.
            struct OnBoardDataInfo
            {
                // =========================================================================================
                // The object and property Ids that hold the CBTC Onboard system Input information.
                // =========================================================================================
                Comms::Object onboard_inputs_object;

                // Information reported by platform unit
                Sim::Number::ID platform_status_id;
                Sim::Number::ID in_platform_region_id;
                Sim::Number::ID lhs_platform_detection_id;
                Sim::Number::ID rhs_platform_detection_id;
                Sim::Number::ID psd_present_id;
                Sim::Number::ID depot_region_id;
                Sim::Number::ID atp_zone_region_id;
                // Information from DMI
                Sim::Number::ID cbtc_message_acknowledge_id;

                // Information reported by various trackside data units
                Sim::Number::ID last_detected_beacon_id;
                Sim::Raw::ID    driver_event_list_id;
                Sim::Raw::ID    gradient_discontinuities_id;
                Sim::Raw::ID    movement_authority_id;
                Sim::Raw::ID    speed_limit_profile_id;

                // =========================================================================================
                // The object and property Ids that hold the CBTC Onboard system Output information.
                // =========================================================================================
                Comms::Object onboard_outputs_object;

                // Information Reported to DMI
                Sim::Number::ID current_train_speed_id;
                Sim::Number::ID cbtc_target_speed_id;
                Sim::Number::ID cbtc_permitted_speed_id;
                Sim::Number::ID speed_status_id;
                Sim::Number::ID safety_brake_status_id;
                Sim::Number::ID atc_status_id;
                Sim::Number::ID target_distance_id;
                Sim::Number::ID localisation_status_id;
                Sim::Number::ID advisory_speed_id;
                Sim::Number::ID warning_speed_id;
                Sim::Number::ID driver_event_skip_station_id;
                Sim::Number::ID driver_event_change_ends_id;
                Sim::Number::ID driver_event_work_zone_id;
                Sim::Number::ID detrainment_door_status_id;
                Sim::Number::ID radio_communication_status_id;
                Sim::Number::ID atc_bypass_state_id;
                Sim::Number::ID emergency_brake_trigger_id;
                Sim::Number::ID depot_indication_id;
                Sim::Number::ID atp_zone_status_id;
                Sim::Raw::ID available_driving_modes_id;
                Sim::Raw::ID cbtc_text_messages_id;

                // Information reported to DMI and platform unit
                Sim::Number::ID current_driving_mode_id;
            };
            struct PlatformInfo
            {
                // =========================================================================================
                // The object and property Ids that hold the CBTC Onboard system Output information.
                // =========================================================================================
                Comms::Object platform_outputs_object;
                
                // Information reported from platform unit
                Sim::Number::ID train_docking_status_id;
                Sim::Number::ID psd_door_status_id;
                Sim::Number::ID psd_interlock_override_status_id;
                Sim::Number::ID departure_order_id;
            };
        private:
            // Interface related data
            Comms::Gateway&       m_gateway;
            CBTCOnBoardProperties m_properties;
            int                   m_train_id;
            int                   m_vehicle_id;
            int                   m_vehicle_count;
            TrainInfo             m_train_data;
            OnBoardDataInfo       m_onboard_data;
            PlatformInfo          m_platform_data;
            // Exported Comms data
            std::vector<Sim::TimedNumber> m_export_numbers;
            std::vector<Sim::TimedRaw>    m_export_raws;

            // Syncronisation
            std::mutex m_mutex;
        };
    }
}
