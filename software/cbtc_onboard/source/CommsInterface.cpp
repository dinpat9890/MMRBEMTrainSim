///
/// @file       CommsInterface.cpp
///
///             Implements the class that handles the communication between Comms and the CBTCOnBoard Controller.
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#include "CommsInterface.h"

#include "Comms/StandardComms.h"

#include "common/StandardLogging.h"
#include "project_comms_structure/ProjectObjectDefinition.h"
#include "utility/Utilities.h"

#include <array>
#include <cassert>

using namespace Project::CBTCOnBoard;

namespace
{
    const double INPUT_REQUEST_FREQ = 20.0;

    /// Helper function to make the serialization using protobuf syntactically nicer, although it
    /// is a little expensive to be copying data around like this. Serialization could be done
    /// directly into the vector if required in the future.
    ///
    /// @param s The string to convert into a Raw, probably produced by protobuf
    ///
    /// @return The corresponding byte array, to use within a raw

    Sim::Raw::Type StringToRaw(const std::string& s)
    {
        if (!s.empty())
            return Sim::Raw::Type(reinterpret_cast<const unsigned char*>(&*s.begin()),
                                  reinterpret_cast<const unsigned char*>(&*s.begin()) + s.size());
        return Sim::Raw::Type();
    }

    /// Helper function that gets the ID of a Number from an object. Because this ID is required it
    /// will throw if the property could not be found.
    ///
    /// @param object The object that the Number must below to.
    /// @param number The name of the number.
    ///
    /// @return The ID of the property requested.

    Sim::Number::ID GetRequiredNumbersID(Comms::Object object, const char* number)
    {
        assert(object.IsValid());
        assert(number);

        Sim::Number::ID ret = object.Numbers().Info().GetID(number);
        if (ret == Sim::INVALID_NUMBER)
            // Throw, as this is exceptional. Too bad if there were other properties that we don't
            // possess either!
            throw InvalidParameterException(FLSTAMP) << object.GetName() << " (" << object.GetID()
                                                     << ") did not have the required property '" << number << "'.";

        return ret;
    }

    /// Helper function that gets the ID of a Raw from an object. Because this ID is required it
    /// will throw if the property could not be found.
    ///
    /// @param object The object that the Number must below to.
    /// @param raw The name of the raw.
    ///
    /// @return The ID of the property requested.

    Sim::Raw::ID GetRequiredRawsID(Comms::Object object, const char* raw)
    {
        assert(object.IsValid());
        assert(raw);

        Sim::Raw::ID ret = object.Raws().Info().GetID(raw);
        if (ret == Sim::INVALID_RAW)
            // Throw, as this is exceptional. Too bad if there were other properties that we don't
            // possess either!
            throw InvalidParameterException(FLSTAMP)
              << object.GetName() << " (" << object.GetID() << ") did not have the required property '" << raw << "'.";

        return ret;
    }

    /// Helper function that gets the ID of a Tray from an object. Because this ID is required it
    /// will throw if the property could not be found.
    ///
    /// @param object The object that the Number must below to.
    /// @param tray The name of the tray.
    ///
    /// @return The ID of the property requested.

    Sim::Tray::ID GetRequiredTraysID(Comms::Object object, const char* tray)
    {
        assert(object.IsValid());
        assert(tray);

        Sim::Tray::ID ret = object.Trays().Info().GetID(tray);
        if (ret == Sim::INVALID_TRAY)
            // Throw, as this is exceptional. Too bad if there were other properties that we don't
            // possess either!
            throw InvalidParameterException(FLSTAMP)
              << object.GetName() << " (" << object.GetID() << ") did not have the required property '" << tray << "'.";

        return ret;
    }
}

/// Constructor
///
/// @param gateway          The comms gateway
/// @param train_id         Identifies the train on which the unit appears
/// @param vehicle_id       Identifies the vehicle on which the unit is located
///
CommsInterface::CommsInterface(Comms::Gateway& gateway, CBTCOnBoardProperties& properties, int train_id, int vehicle_id)
  : m_gateway(gateway), m_properties(properties), m_train_id(train_id), m_vehicle_id(vehicle_id)
{
}

/// This is called when the unit is ready to start getting notifications of object creations
///
/// Note that is does not happen in the construction since this registering needs to happen
/// during the initialisation of a session when the system is being resumed after being snapshoted.
///
void CommsInterface::RegisterWithComms()
{
    // We need a lock to access the root object
    OS::Lock<Comms::Gateway> lock(m_gateway);

    // Register for notification of object creation
    AddCreationCallback(m_gateway.GetRootObject(), [this](Comms::Object object) { this->ObjectCreated(object); });
}

/// This is called when the unit is ready to start getting notifications of object creations
///
/// @returns True when the Comms interface required by the CBTCOnBoard system have been initialised
///
const bool CommsInterface::IsCommsInitialisationComplete()
{
    return m_onboard_data.onboard_inputs_object.IsValid() && m_onboard_data.onboard_outputs_object.IsValid() &&
           m_train_data.cbtc_vehicle_inputs_object.IsValid() && m_train_data.cbct_vehicle_outputs_object.IsValid()
           && m_train_data.vehicle_inputs_object.IsValid();
}

/// Populates the Train related comms data that appears in the OnBoard Controller input structure
///
/// @params inputs Reference to the CBTC OnBoard Controller input data that is to be populated by train
///
void CommsInterface::GetTrainInputs(OnBoardControllerIO::Inputs& inputs)
{
    // Make sure that comms is locked as the OnBoard Controller will be inspecting and writing to Comms
    // objects during its run cycle
    const OS::Lock<Comms::Gateway>    lock(m_gateway);
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    // No lock here because this will only be called during Stepping, when the lock is already held.
    assert(m_train_data.train_object.IsValid());
    assert(m_train_data.cbct_vehicle_outputs_object.IsValid());

    assert(m_train_data.lead_car_position_id != Sim::INVALID_NUMBER);
    assert(m_train_data.lead_car_speed_id != Sim::INVALID_NUMBER);
    assert(m_train_data.auto_power_on_id != Sim::INVALID_NUMBER);
    assert(m_train_data.train_wakeup_id != Sim::INVALID_NUMBER);
    assert(m_train_data.atc_eb_unable_to_reset_id != Sim::INVALID_NUMBER);
    assert(m_train_data.psd_door_not_opening_fault_id != Sim::INVALID_NUMBER);
	assert(m_train_data.psd_adcl_not_available_fault_id != Sim::INVALID_NUMBER);
	assert(m_train_data.psd_bypassed_fault_id != Sim::INVALID_NUMBER);
    assert(m_train_data.train_zero_speed_order_id != Sim::INVALID_NUMBER);
    /* assert(m_train_data.atc_loss_of_comms_error_id != Sim::INVALID_NUMBER);
     assert(m_train_data.initial_localisation_state_id != Sim::INVALID_NUMBER);
     assert(m_train_data.ato_position_error_id != Sim::INVALID_NUMBER);*/
    assert(m_train_data.power_supply_id != Sim::INVALID_NUMBER);
    assert(m_train_data.cabin_activation_id != Sim::INVALID_NUMBER);
    assert(m_train_data.driver_mode_selection_id != Sim::INVALID_NUMBER);
    assert(m_train_data.emergency_door_not_open_id != Sim::INVALID_NUMBER);
    assert(m_train_data.mode_selector_position_id != Sim::INVALID_NUMBER);
    assert(m_train_data.atc_bypass_state_id != Sim::INVALID_NUMBER);
    assert(m_train_data.tbc_position_id != Sim::INVALID_NUMBER);
    assert(m_train_data.ato_start_button_id != Sim::INVALID_NUMBER);
    assert(m_train_data.uto_start_button_id != Sim::INVALID_NUMBER);
    assert(m_train_data.wake_up_status_id != Sim::INVALID_NUMBER);
    assert(m_train_data.no_emergency_brake_id != Sim::INVALID_NUMBER);
    assert(m_train_data.atc_sb_reset_button_id != Sim::INVALID_NUMBER);
    assert(m_train_data.train_door_closed_and_locked_id != Sim::INVALID_NUMBER);
    assert(m_train_data.no_door_enable_bypass_id != Sim::INVALID_NUMBER);
    assert(m_train_data.tcms_speed_limit_id != Sim::INVALID_NUMBER);
    assert(m_train_data.tcms_speed_limit_cause_id != Sim::INVALID_NUMBER);
    assert(m_train_data.active_call_type_id != Sim::INVALID_NUMBER);
	assert(m_train_data.pabr_bypass_req_id != Sim::INVALID_NUMBER);	
    assert(m_train_data.call_status_id != Sim::INVALID_NUMBER);
    assert(m_train_data.emergency_brake_pb_id != Sim::INVALID_NUMBER);
    assert(m_train_data.emergency_stop_pb_id != Sim::INVALID_NUMBER);
    assert(m_train_data.master_controller_handle_id != Sim::INVALID_NUMBER);

    if (m_train_data.train_object.IsValid() && m_train_data.vehicle_object.IsValid() &&
        m_train_data.cbct_vehicle_outputs_object.IsValid() && m_train_data.cbtc_vehicle_inputs_object.IsValid()
        && m_train_data.vehicle_inputs_object.IsValid())
    {
        const double DELTA = 0.01;

        // Populate the train data provided through the train object
        inputs.current_train_speed = m_train_data.train_object.Numbers().Store().Get(m_train_data.lead_car_speed_id).value;
        inputs.auto_power_on = m_train_data.train_object.Numbers().Store().Get(m_train_data.auto_power_on_id).value;
        inputs.train_wakeup  = m_train_data.train_object.Numbers().Store().Get(m_train_data.train_wakeup_id).value;
        inputs.atc_eb_unable_to_reset = m_train_data.train_object.Numbers().Store().Get(m_train_data.atc_eb_unable_to_reset_id).value;
        inputs.train_zero_speed_order =m_train_data.train_object.Numbers().Store().Get(m_train_data.train_zero_speed_order_id).value;
        inputs.psd_door_not_opening = m_train_data.train_object.Numbers().Store().Get(m_train_data.psd_door_not_opening_fault_id).value;
		inputs.psd_adcl_not_available_fault = m_train_data.train_object.Numbers().Store().Get(m_train_data.psd_adcl_not_available_fault_id).value;
		inputs.psd_bypassed_fault = m_train_data.train_object.Numbers().Store().Get(m_train_data.psd_bypassed_fault_id).value;
		// Note that we want to increase the size of the delta for a current train position value since this value can
        // have small changes while the train is at standstill and this can cause issues when comparing the train
        // position to a previously recorded position
        auto new_train_position = m_train_data.train_object.Numbers().Store().Get(m_train_data.lead_car_position_id).value;
        if (abs(new_train_position - inputs.current_train_position) > DELTA)
            inputs.current_train_position =
              m_train_data.train_object.Numbers().Store().Get(m_train_data.lead_car_position_id).value;

        // Populate the train data provided through the vehicle object
        /* inputs.atc_loss_of_comms_error =
           m_train_data.vehicle_object.Numbers().Store().Get(m_train_data.atc_loss_of_comms_error_id).value;
         inputs.initial_localisation_state =
           m_train_data.vehicle_object.Numbers().Store().Get(m_train_data.initial_localisation_state_id).value;
         inputs.ato_position_error =
           m_train_data.vehicle_object.Numbers().Store().Get(m_train_data.ato_position_error_id).value;*/
        inputs.cab_activation = m_train_data.vehicle_object.Numbers().Store().Get(m_train_data.cab_activation_id).value;
        inputs.train_doors_not_opening_in_ato =
          m_train_data.vehicle_object.Numbers().Store().Get(m_train_data.train_doors_not_opening_in_ato_id).value;
        inputs.failure_of_trainborne_atc_equipment =
            m_train_data.vehicle_object.Numbers().Store().Get(m_train_data.fault_failure_of_trainborne_atc_equipment_id).value;
        // Populate the train data provided through the CBTCVehicleOutput object
        inputs.cabin_activation =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.cabin_activation_id).value;
        inputs.power_supply =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.power_supply_id).value;
        inputs.driver_mode_selection =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.driver_mode_selection_id).value;
        inputs.emergency_door_not_open =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.emergency_door_not_open_id).value;
        inputs.mode_selector_position =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.mode_selector_position_id).value;
        inputs.atc_bypass_state =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.atc_bypass_state_id).value;
        inputs.tbc_position =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.tbc_position_id).value;
        inputs.ato_start_button =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.ato_start_button_id).value;
        inputs.uto_start_button =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.uto_start_button_id).value;
        inputs.wake_up_status =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.wake_up_status_id).value;
        inputs.no_emergency_brake =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.no_emergency_brake_id).value;
        inputs.atc_sb_reset_button =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.atc_sb_reset_button_id).value;
        inputs.train_door_closed_and_locked =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.train_door_closed_and_locked_id).value;
        inputs.no_door_enable_bypass =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.no_door_enable_bypass_id).value;
        inputs.tcms_speed_limit =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.tcms_speed_limit_id).value;
        inputs.tcms_speed_limit_cause =
          m_train_data.cbct_vehicle_outputs_object.Numbers().Store().Get(m_train_data.tcms_speed_limit_cause_id).value;
        inputs.active_call_type =
          m_train_data.intercom_output_object.Numbers().Store().Get(m_train_data.active_call_type_id).value;
		inputs.pabr_bypass_req =
			m_train_data.intercom_output_object.Numbers().Store().Get(m_train_data.pabr_bypass_req_id).value;
        inputs.call_status = m_train_data.OHP_output_object.Numbers().Store().Get(m_train_data.call_status_id).value;
        inputs.emergency_brake_pb = m_train_data.vehicle_inputs_object.Numbers().Store().Get(m_train_data.emergency_brake_pb_id).value;
        inputs.emergency_stop_pb = m_train_data.vehicle_inputs_object.Numbers().Store().Get(m_train_data.emergency_stop_pb_id).value;
        inputs.master_brake_controller = m_train_data.vehicle_inputs_object.Numbers().Store().Get(m_train_data.master_controller_handle_id).value;
    }
}

/// Populates the DMI related comms data that appears in a OnBoard Controllers input structure
///
/// @params inputs Reference to the OnBoard Controllers input data that is to be populated
///
void CommsInterface::GetOnBoardDataInputs(OnBoardControllerIO::Inputs& inputs)
{
    // Make sure that comms is locked as the OnBoard Controller will be inspecting and writing to Comms
    // objects during its run cycle
    const OS::Lock<Comms::Gateway>    lock(m_gateway);
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    assert(m_onboard_data.onboard_inputs_object.IsValid());

    assert(m_onboard_data.platform_status_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.in_platform_region_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.lhs_platform_detection_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.rhs_platform_detection_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.psd_present_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.depot_region_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.atp_zone_region_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.last_detected_beacon_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.cbtc_message_acknowledge_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.driver_event_list_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.gradient_discontinuities_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.movement_authority_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.speed_limit_profile_id != Sim::INVALID_NUMBER);

    if (m_onboard_data.onboard_inputs_object.IsValid())
    {
        // Platform Unit Data
        inputs.train_near_platform =
          m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.in_platform_region_id).value;
        inputs.platform_status =
          m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.platform_status_id).value;
        inputs.lhs_platform_detection =
          m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.lhs_platform_detection_id).value;
        inputs.rhs_platform_detection =
          m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.rhs_platform_detection_id).value;
        inputs.psd_present = m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.psd_present_id).value;
        inputs.depot_region = m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.depot_region_id).value;
        inputs.atp_zone_region = m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.atp_zone_region_id).value;
        // DMI data
        inputs.cbtc_message_acknowledge =
          m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.cbtc_message_acknowledge_id).value;

        // Trackside data
        inputs.last_detected_beacon =
          m_onboard_data.onboard_inputs_object.Numbers().Store().Get(m_onboard_data.last_detected_beacon_id).value;

        auto driver_event_list_raw = m_onboard_data.onboard_inputs_object.Raws().Store().Get(m_onboard_data.driver_event_list_id);
        if (!driver_event_list_raw.value.empty())
        {
            std::string serialized_driver_event_list;
            serialized_driver_event_list.assign(driver_event_list_raw.value.cbegin(), driver_event_list_raw.value.cend());
            inputs.track_event_data.ParseFromString(serialized_driver_event_list);
        }
        else
        {
            inputs.track_event_data.clear_reference_train_position();
        }

        auto gradient_discontinuities_raw = m_onboard_data.onboard_inputs_object.Raws().Store().Get(m_onboard_data.gradient_discontinuities_id);
        if (!gradient_discontinuities_raw.value.empty())
        {
            std::string serialized_gradient_discontinuities_list;
            serialized_gradient_discontinuities_list.assign(gradient_discontinuities_raw.value.cbegin(),
                                                            gradient_discontinuities_raw.value.cend());
            inputs.gradient_discontinuities.ParseFromString(serialized_gradient_discontinuities_list);
        }
        else
        {
            inputs.gradient_discontinuities.clear_reference_train_position();
        }

        auto movement_authority_raw = m_onboard_data.onboard_inputs_object.Raws().Store().Get(m_onboard_data.movement_authority_id);
        if (!movement_authority_raw.value.empty())
        {
            std::string serialized_movement_authority;
            serialized_movement_authority.assign(movement_authority_raw.value.cbegin(), movement_authority_raw.value.cend());
            inputs.movement_authority.ParseFromString(serialized_movement_authority);
        }
        else
        {
            inputs.movement_authority.clear_reference_train_position();
        }

        auto speed_limit_profile_raw = m_onboard_data.onboard_inputs_object.Raws().Store().Get(m_onboard_data.speed_limit_profile_id);
        if (!speed_limit_profile_raw.value.empty())
        {
            std::string serialized_speed_limit_profile;
            serialized_speed_limit_profile.assign(speed_limit_profile_raw.value.cbegin(), speed_limit_profile_raw.value.cend());
            inputs.speed_limit_profile.ParseFromString(serialized_speed_limit_profile);
        }
        else
        {
            inputs.speed_limit_profile.clear_reference_train_position();
        }
    }
}

/// Takes the outputs from the OnBoard Controller and updates any OnBoard Data Outputs Comms signals that are associated
/// with it
///
/// @param outputs Provides all of the OnBoard Controller outputs. Some of which may need to be sent to the DMI
///
void CommsInterface::SetPlatformOutputs(OnBoardControllerIO::Inputs& inputs)
{
    // Make sure that comms is locked as the OnBoard Controller will be inspecting and writing to Comms
    // objects during its run cycle
    const OS::Lock<Comms::Gateway>    lock(m_gateway);
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    assert(m_platform_data.platform_outputs_object.IsValid());
    assert(m_platform_data.train_docking_status_id != Sim::INVALID_NUMBER);
    if (m_platform_data.platform_outputs_object.IsValid())
    {
        inputs.train_dock_status =
          m_platform_data.platform_outputs_object.Numbers().Store().Get(m_platform_data.train_docking_status_id).value;
        inputs.psd_door_status =
          m_platform_data.platform_outputs_object.Numbers().Store().Get(m_platform_data.psd_door_status_id).value;
        inputs.psd_interlock_override_status =
          m_platform_data.platform_outputs_object.Numbers().Store().Get(m_platform_data.psd_interlock_override_status_id).value;
        inputs.departure_order_status =
          m_platform_data.platform_outputs_object.Numbers().Store().Get(m_platform_data.departure_order_id).value;
    }
}

/// Takes the outputs from the OnBoard Controller and updates any OnBoard Data Outputs Comms signals that are
/// associated
/// with it
///
/// @param outputs Provides all of the OnBoard Controller outputs. Some of which may need to be sent to the DMI
///
void CommsInterface::SetOnBoardDataOutputs(const OnBoardControllerIO::Outputs& outputs)
{
    // Make sure that comms is locked as the OnBoard Controller will be inspecting and writing to Comms
    // objects during its run cycle
    const OS::Lock<Comms::Gateway>    lock(m_gateway);
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    assert(m_onboard_data.onboard_outputs_object.IsValid());

    assert(m_onboard_data.current_train_speed_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.cbtc_target_speed_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.cbtc_permitted_speed_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.speed_status_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.atc_status_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.safety_brake_status_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.target_distance_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.localisation_status_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.advisory_speed_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.warning_speed_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.driver_event_skip_station_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.driver_event_change_ends_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.driver_event_work_zone_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.radio_communication_status_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.atc_bypass_state_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.current_driving_mode_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.available_driving_modes_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.cbtc_text_messages_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.emergency_brake_trigger_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.depot_indication_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.atp_zone_status_id != Sim::INVALID_NUMBER);
    assert(m_onboard_data.detrainment_door_status_id != Sim::INVALID_NUMBER);

    if (m_onboard_data.onboard_outputs_object.IsValid())
    {

        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.current_train_speed_id, outputs.current_train_speed);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.cbtc_target_speed_id, outputs.cbtc_target_speed);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.cbtc_permitted_speed_id, outputs.cbtc_permitted_speed);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.speed_status_id, outputs.warning_status);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.safety_brake_status_id, outputs.safety_brake);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.atc_status_id, outputs.atc_status);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.target_distance_id, outputs.target_distance);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.localisation_status_id, outputs.localisation_status);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.depot_indication_id, outputs.depot_indication);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.atp_zone_status_id, outputs.atp_zone_status);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.advisory_speed_id, outputs.advisory_speed);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.warning_speed_id, outputs.warning_speed);
        Core::AddIfChanged(m_export_numbers,
                           m_onboard_data.onboard_outputs_object,
                           m_onboard_data.emergency_brake_trigger_id,
                           outputs.emergency_brake_trigger);
        Core::AddIfChanged(m_export_numbers,
                           m_onboard_data.onboard_outputs_object,
                           m_onboard_data.driver_event_skip_station_id,
                           outputs.driver_event_skip_station);
        Core::AddIfChanged(m_export_numbers,
                           m_onboard_data.onboard_outputs_object,
                           m_onboard_data.detrainment_door_status_id,
                           outputs.detrainment_door_status);
        Core::AddIfChanged(m_export_numbers,
                           m_onboard_data.onboard_outputs_object,
                           m_onboard_data.driver_event_change_ends_id,
                           outputs.driver_event_change_ends);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.driver_event_work_zone_id, outputs.driver_event_work_zone);
        Core::AddIfChanged(m_export_numbers,
                           m_onboard_data.onboard_outputs_object,
                           m_onboard_data.radio_communication_status_id,
                           outputs.radio_communication_status);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.atc_bypass_state_id, outputs.atc_bypass_state);
        Core::AddIfChanged(
          m_export_numbers, m_onboard_data.onboard_outputs_object, m_onboard_data.current_driving_mode_id, outputs.current_driving_mode);

        Core::AddIfChanged(m_export_raws,
                           m_onboard_data.onboard_outputs_object,
                           m_onboard_data.available_driving_modes_id,
                           StringToRaw(outputs.available_driving_modes.SerializeAsString()));
        Core::AddIfChanged(m_export_raws,
                           m_onboard_data.onboard_outputs_object,
                           m_onboard_data.cbtc_text_messages_id,
                           StringToRaw(outputs.text_messages.SerializeAsString()));
    }
}

/// Takes the outputs from the OnBoard Controller and updates any Train Comms signals that are associated with it
///
/// @param outputs Provides all of the OnBoard Controller outputs. Some of which may need to be sent to the Train Model
///
void CommsInterface::SetTrainOutputs(const OnBoardControllerIO::Outputs& outputs)
{
    // Make sure that comms is locked as the OnBoard Controller will be inspecting and writing to Comms
    // objects during its run cycle
    const OS::Lock<Comms::Gateway>    lock(m_gateway);
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    assert(m_train_data.cbtc_vehicle_inputs_object.IsValid());

    assert(m_train_data.emergency_brake_command_id != Sim::INVALID_NUMBER);
    assert(m_train_data.service_brake_command_id != Sim::INVALID_NUMBER);
    assert(m_train_data.immobilisation_state_id != Sim::INVALID_NUMBER);
    assert(m_train_data.audio_safety_brake_alarm_id != Sim::INVALID_NUMBER);
    assert(m_train_data.audio_warning_alarm_id != Sim::INVALID_NUMBER);
    assert(m_train_data.audio_departure_order_id != Sim::INVALID_NUMBER);
    assert(m_train_data.audio_target_speed_id != Sim::INVALID_NUMBER);
    assert(m_train_data.audio_high_priority_text_alert_id != Sim::INVALID_NUMBER);
    assert(m_train_data.audio_acknowledge_id != Sim::INVALID_NUMBER);
    assert(m_train_data.uto_mode_active_id != Sim::INVALID_NUMBER);
    assert(m_train_data.ato_state_id != Sim::INVALID_NUMBER);
    assert(m_train_data.ato_permitted_speed_id != Sim::INVALID_NUMBER);
    assert(m_train_data.ato_permitted_distance_id != Sim::INVALID_NUMBER);
    assert(m_train_data.ato_start_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.atc_cab_activation_id != Sim::INVALID_NUMBER);
    assert(m_train_data.traction_forward_id != Sim::INVALID_NUMBER);
    assert(m_train_data.ros_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.uto_pb_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.wake_up_command_id != Sim::INVALID_NUMBER);
    assert(m_train_data.atc_safety_brake_reset_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.left_side_door_enable_id != Sim::INVALID_NUMBER);
    assert(m_train_data.left_hold_door_close_id != Sim::INVALID_NUMBER);
    assert(m_train_data.right_hold_door_close_id != Sim::INVALID_NUMBER);
    assert(m_train_data.right_side_door_enable_id != Sim::INVALID_NUMBER);
    assert(m_train_data.left_door_open_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.left_door_release_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.open_left_train_doors_id != Sim::INVALID_NUMBER);
    assert(m_train_data.right_door_open_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.right_door_close_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.left_door_close_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.right_door_release_indicator_id != Sim::INVALID_NUMBER);
    assert(m_train_data.open_right_train_doors_id != Sim::INVALID_NUMBER);
    assert(m_train_data.zero_speed_id != Sim::INVALID_NUMBER);
    assert(m_train_data.rollback_detection_id != Sim::INVALID_NUMBER);

    if (m_train_data.cbtc_vehicle_inputs_object.IsValid())
    {
        Core::AddIfChanged(m_export_numbers,
                           m_train_data.cbtc_vehicle_inputs_object,
                           m_train_data.emergency_brake_command_id,
                           outputs.emergency_brake_request);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.service_brake_command_id, outputs.service_brake_request);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.immobilisation_state_id, outputs.immobilisation_state);
        Core::AddIfChanged(m_export_numbers,
                           m_train_data.cbtc_vehicle_inputs_object,
                           m_train_data.audio_safety_brake_alarm_id,
                           outputs.audio_safety_brake_alarm);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.audio_warning_alarm_id, outputs.audio_warning_alarm);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.audio_departure_order_id, outputs.audio_departure_order);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.audio_target_speed_id, outputs.audio_target_speed);
        Core::AddIfChanged(m_export_numbers,
                           m_train_data.cbtc_vehicle_inputs_object,
                           m_train_data.audio_high_priority_text_alert_id,
                           outputs.audio_high_priority_text_alert);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.audio_acknowledge_id, outputs.audio_acknowledge);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.uto_mode_active_id, outputs.uto_mode_active);
        Core::AddIfChanged(m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.ato_state_id, outputs.ato_state);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.ato_permitted_distance_id, outputs.ato_permitted_distance);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.ato_permitted_speed_id, outputs.ato_permitted_speed);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.ato_start_indicator_id, outputs.ato_start_indicator);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.atc_cab_activation_id, outputs.atc_cab_activation);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.traction_forward_id, outputs.traction_forward);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.ros_indicator_id, outputs.ros_indicator);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.uto_pb_indicator_id, outputs.uto_pb_indicator);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.wake_up_command_id, outputs.wake_up_command);
        Core::AddIfChanged(m_export_numbers,
                           m_train_data.cbtc_vehicle_inputs_object,
                           m_train_data.atc_safety_brake_reset_indicator_id,
                           outputs.atc_safety_brake_reset_indicator);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.left_side_door_enable_id, outputs.left_side_door_enable);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.left_hold_door_close_id, outputs.left_hold_door_close);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.right_hold_door_close_id, outputs.right_hold_door_close);
        Core::AddIfChanged(m_export_numbers,
                           m_train_data.cbtc_vehicle_inputs_object,
                           m_train_data.left_door_open_indicator_id,
                           outputs.left_door_open_indicator);
        Core::AddIfChanged(m_export_numbers,
                           m_train_data.cbtc_vehicle_inputs_object,
                           m_train_data.left_door_release_indicator_id,
                           outputs.left_door_release_indicator);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.open_left_train_doors_id, outputs.open_left_train_doors);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.right_side_door_enable_id, outputs.right_side_door_enable);
        Core::AddIfChanged(m_export_numbers,
                           m_train_data.cbtc_vehicle_inputs_object,
                           m_train_data.right_door_open_indicator_id,
                           outputs.right_door_open_indicator);
        Core::AddIfChanged(m_export_numbers,
                           m_train_data.cbtc_vehicle_inputs_object,
                           m_train_data.right_door_release_indicator_id,
                           outputs.right_door_release_indicator);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.open_right_train_doors_id, outputs.open_right_train_doors);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.zero_speed_id, outputs.zero_speed);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.rollback_detection_id, outputs.rollback_detected);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.left_door_close_indicator_id, outputs.left_door_close_indicator);
        Core::AddIfChanged(
          m_export_numbers, m_train_data.cbtc_vehicle_inputs_object, m_train_data.right_door_close_indicator_id, outputs.right_door_close_indicator);
    }
}

/// Takes the outputs that have been updated and sends them to Comms
///
/// @param current_time Time at which the request to send the updates was made
///
void CommsInterface::SendUpdates(double current_time)
{
    // Make sure that comms is locked as the OnBoard Controller will be inspecting and writing to Comms
    // objects during its run cycle
    const OS::Lock<Comms::Gateway>    lock(m_gateway);
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    // Output any number values that have changed
    if (!m_export_numbers.empty())
    {
        // First set the time on all Numbers that we are exporting, as they must apply to *now*.
        for (auto& n : m_export_numbers)
            n.time = current_time;

        // Now set these all in bulk
        m_gateway.SetNumbers(&m_export_numbers[0], &m_export_numbers[0] + m_export_numbers.size());
    }

    // Output any raw values that have changed
    if (!m_export_raws.empty())
    {
        // First set the time on all Numbers that we are exporting, as they must apply to *now*.
        for (auto& n : m_export_raws)
            n.time = current_time;

        // Now set these all in bulk
        m_gateway.SetRaws(&m_export_raws[0], &m_export_raws[0] + m_export_raws.size());
    }

    m_export_numbers.clear();
    m_export_raws.clear();
}

/// Called when an object is created on the root or world object.
///
/// @param object The newly created object.
///
void CommsInterface::ObjectCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    assert(object.IsValid());

    if ((Core::GetClassID(object) == Core::ClassID::WORLD))
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
    else if (Core::GetClassID(object) == Train::ClassID::TRAIN)
    {
        double scenario_train_id = object.Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID);
        if (scenario_train_id == m_train_id)
        {
            m_train_data.train_object = object;

            m_train_data.lead_car_speed_id = GetRequiredNumbersID(object, Train::ValueName::Train::LLO_LEAD_LOCO_SPEED);
            m_train_data.lead_car_position_id = GetRequiredNumbersID(object, Train::ValueName::Train::LLO_LEAD_LOCO_POSITION);
            m_train_data.auto_power_on_id = GetRequiredNumbersID(object, Project::ValueName::Train::AUTO_POWER_ON);
            m_train_data.train_wakeup_id  = GetRequiredNumbersID(object, Project::ValueName::Train::TRAIN_WAKEUP);
            // Faults and events
            m_train_data.atc_eb_unable_to_reset_id = GetRequiredNumbersID(object, Project::ValueName::Train::FLT_ATC_EB_UNABLE_TO_RESET);
            m_train_data.train_zero_speed_order_id = GetRequiredNumbersID(object, Project::ValueName::Train::FLT_TRAIN_GETTING_ZERO_SPEED_ORDER);
            m_train_data.psd_door_not_opening_fault_id = GetRequiredNumbersID(object, Project::ValueName::Train::FLT_PLATFORM_SCREEN_DOOR_NOT_WORKING);
			m_train_data.psd_bypassed_fault_id = GetRequiredNumbersID(object, Project::ValueName::Train::FLT_ONE_PSD_BYPASSED_AT_STATION_IN_OPEN_CONDITION);
			m_train_data.psd_adcl_not_available_fault_id = GetRequiredNumbersID(object, Project::ValueName::Train::FLT_PSD_ADCL_STATUS_NOT_AVAILABLE);
            std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
            number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.lead_car_speed_id));
            number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.lead_car_position_id));
            number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.auto_power_on_id));
            number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.train_wakeup_id));
            number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.atc_eb_unable_to_reset_id));
            number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.psd_door_not_opening_fault_id));
			number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.psd_adcl_not_available_fault_id));
			number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.psd_bypassed_fault_id));
            number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.train_zero_speed_order_id));
            object.Numbers().Store().Request(number_requests.begin(), number_requests.end(), INPUT_REQUEST_FREQ);
            AddCreationCallback(object, [this](Comms::Object object) { this->IntercomCreated(object); });
            AddCreationCallback(object, [this](Comms::Object object) { this->VehicleCreated(object); });
        }
    }
}

/// Called when a new intercom object is created
///
/// @param object The newly created object.
///
void CommsInterface::IntercomCreated(Comms::Object object) 
{

    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    // If this is the vehicle with the CBTCOnBoard System then add the OnBoard signals to the vehicle
    if (Core::GetClassID(object) == Project::ClassID::INTERCOM)
    {
        AddCreationCallback(object, [this](Comms::Object object) { this->IntercomOutputCreated(object); });
    }
}

/// Called when a new intercom output object is created
///
/// @param object The newly created object.
///
void CommsInterface::IntercomOutputCreated(Comms::Object object)
{

    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    // If this is the vehicle with the CBTCOnBoard System then add the OnBoard signals to the vehicle
    if (Core::GetClassID(object) == Project::ClassID::INTERCOM_OUTPUTS)
    {
        m_train_data.intercom_output_object = object;
        m_train_data.active_call_type_id = GetRequiredNumbersID(object, Project::ValueName::IntercomOutputs::ACTIVE_CALL_TYPE);
		m_train_data.pabr_bypass_req_id = GetRequiredNumbersID(object, Project::ValueName::IntercomOutputs::PABR_BYPASS_REQ);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
        std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
        number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.active_call_type_id));
		number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.pabr_bypass_req_id));
        object.Numbers().Store().Request(number_requests.begin(), number_requests.end(), INPUT_REQUEST_FREQ);
        AddCreationCallback(object, [this](Comms::Object object) { this->OHPOutputCreated(object); });
    }
}

/// Called when a new OHP output object is created
///
/// @param object The newly created object.
///
void CommsInterface::OHPOutputCreated(Comms::Object object)
{

    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    // If this is the vehicle with the CBTCOnBoard System then add the OnBoard signals to the vehicle
    if (Core::GetClassID(object) == Project::ClassID::OHP_OUTPUTS)
    {
        m_train_data.OHP_output_object = object;
        m_train_data.call_status_id = GetRequiredNumbersID(object, Project::ValueName::OHPOutputs::STATUS);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
        std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
        number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.call_status_id));
        object.Numbers().Store().Request(number_requests.begin(), number_requests.end(), INPUT_REQUEST_FREQ);
    }
}

/// Called when a new vehicle object is created
///
/// @param object The newly created object.
///
void CommsInterface::VehicleCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    // If this is the vehicle with the CBTCOnBoard System then add the OnBoard signals to the vehicle
    if ((Core::GetClassID(object) == Train::ClassID::VEHICLE) &&
        (object.Numbers().Get(Train::ValueName::Vehicle::INDEX).value == m_vehicle_id))
    {
        m_train_data.vehicle_object = object;
        std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
        m_train_data.cab_activation_id = GetRequiredNumbersID(object, Project::ValueName::Vehicle::CAB_ACTIVATION);
        m_train_data.train_doors_not_opening_in_ato_id = GetRequiredNumbersID(
          object, Project::ValueName::Vehicle::FLT_TRAIN_DOORS_NOT_OPENING_IN_ATO_MODE);
        m_train_data.fault_failure_of_trainborne_atc_equipment_id = GetRequiredNumbersID(
            object, Project::ValueName::Vehicle::FLT_FAILURE_OF_TRAINBORNE_ATC_EQUIPMENT);
        number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.cab_activation_id));
        number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.train_doors_not_opening_in_ato_id));
        number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.fault_failure_of_trainborne_atc_equipment_id));
        // Temp commented as faults not defined yet
        /*m_train_data.atc_loss_of_comms_error_id    = GetRequiredNumbersID(object,
          Project::ValueName::Vehicle::FLT_CBTC_ATC_LOSS_OF_COMMUNICATION); m_train_data.initial_localisation_state_id =
          GetRequiredNumbersID(object,Project::ValueName::Vehicle::CBTC_LOCALISATION);
          m_train_data.ato_position_error_id         = GetRequiredNumbersID(object,
          Project::ValueName::Vehicle::FLT_CBTC_ATO_POSITION_ERROR);

          std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
          number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.atc_loss_of_comms_error_id));
          number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.initial_localisation_state_id));
          number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.ato_position_error_id));*/

        object.Numbers().Store().Request(number_requests.begin(), number_requests.end(), INPUT_REQUEST_FREQ);

        // Create CBTC_ONBOARD_INPUTS and CBTC_ONBOARD_OUTPUTS objects
        object.CreateChild(Project::GetObjectDefinition(Project::ClassID::CBTC_ONBOARD_INPUTS));
        object.CreateChild(Project::GetObjectDefinition(Project::ClassID::CBTC_ONBOARD_OUTPUTS));

        AddCreationCallback(object, [this](Comms::Object object) { this->VehicleChildCreated(object); });
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
}

/// Called when a new vehicle child object, on a vehicle of interest, is created
///
/// @param object The newly created object.
///
void CommsInterface::VehicleChildCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    if (Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_INPUTS)
        CBTCVehicleInputsCreated(object);
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_OUTPUTS)
        CBTCVehicleOutputsCreated(object);
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS)
        CBTCOnBoardInputsCreated(object);
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_OUTPUTS)
        CBTCOnBoardOutputsCreated(object);
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_PLATFORM_OUTPUTS)
        CBTCPlatformOutputsCreated(object);
    else if (Core::GetClassID(object) == Project::ClassID::VEHICLE_INPUTS)
        VehicleInputsCreated(object);
}

/// Called when a new CBTCVehicleInputs object is created
///
/// @param object The newly created object.
///
void CommsInterface::CBTCVehicleInputsCreated(Comms::Object object)
{
    m_train_data.cbtc_vehicle_inputs_object = object;

    using namespace Project::ValueName;
    m_train_data.service_brake_command_id   = GetRequiredNumbersID(object, CBTCVehicleInputs::NO_SERVICE_BRAKE_ORDER);
    m_train_data.emergency_brake_command_id = GetRequiredNumbersID(object, CBTCVehicleInputs::NO_EMERGENCY_BRAKE_ORDER);
    m_train_data.immobilisation_state_id    = GetRequiredNumbersID(object, CBTCVehicleInputs::IMMOBILISATION_STATE);
    m_train_data.audio_safety_brake_alarm_id = GetRequiredNumbersID(object, CBTCVehicleInputs::AUDIO_SAFETY_BRAKE_ALARM);
    m_train_data.audio_warning_alarm_id      = GetRequiredNumbersID(object, CBTCVehicleInputs::AUDIO_WARNING_ALARM);
    m_train_data.audio_departure_order_id    = GetRequiredNumbersID(object, CBTCVehicleInputs::AUDIO_DEPARTURE_ORDER);
    m_train_data.audio_target_speed_id       = GetRequiredNumbersID(object, CBTCVehicleInputs::AUDIO_TARGET_SPEED);
    m_train_data.audio_high_priority_text_alert_id = GetRequiredNumbersID(object, CBTCVehicleInputs::AUDIO_HIGH_PRIORITY_TEXT_ALERT);
    m_train_data.audio_acknowledge_id              = GetRequiredNumbersID(object, CBTCVehicleInputs::AUDIO_ACKNOWLEDGE);
    m_train_data.uto_mode_active_id                = GetRequiredNumbersID(object, CBTCVehicleInputs::UTO_MODE_ACTIVE);
    m_train_data.ato_state_id                      = GetRequiredNumbersID(object, CBTCVehicleInputs::ATO_STATE);
    m_train_data.ato_permitted_speed_id    = GetRequiredNumbersID(object, CBTCVehicleInputs::ATO_PERMITTED_SPEED);
    m_train_data.ato_permitted_distance_id = GetRequiredNumbersID(object, CBTCVehicleInputs::ATO_PERMITTED_DISTANCE);
    m_train_data.ato_start_indicator_id    = GetRequiredNumbersID(object, CBTCVehicleInputs::ATO_START_INDICATOR);
    m_train_data.atc_cab_activation_id     = GetRequiredNumbersID(object, CBTCVehicleInputs::ATC_CAB_ACTIVATION);
    m_train_data.traction_forward_id       = GetRequiredNumbersID(object, CBTCVehicleInputs::TRACTION_FORWARD);
    m_train_data.ros_indicator_id          = GetRequiredNumbersID(object, CBTCVehicleInputs::ROS_INDICATOR);
    m_train_data.uto_pb_indicator_id       = GetRequiredNumbersID(object, CBTCVehicleInputs::UTO_PB_INDICATOR);
    m_train_data.wake_up_command_id        = GetRequiredNumbersID(object, CBTCVehicleInputs::WAKE_UP_COMMAND);
    m_train_data.atc_safety_brake_reset_indicator_id = GetRequiredNumbersID(object, CBTCVehicleInputs::ATC_SB_RESET_INDICATOR);
    //    m_train_data.in_automatic_region_id = GetRequiredNumbersID(object, CBTCVehicleInputs::IN_AUTOMATIC_REGION);

    m_train_data.left_side_door_enable_id    = GetRequiredNumbersID(object, CBTCVehicleInputs::LEFT_SIDE_DOOR_ENABLE);
    m_train_data.right_side_door_enable_id   = GetRequiredNumbersID(object, CBTCVehicleInputs::RIGHT_SIDE_DOOR_ENABLE);
    m_train_data.left_hold_door_close_id     = GetRequiredNumbersID(object, CBTCVehicleInputs::LEFT_HOLD_DOOR_CLOSE);
    m_train_data.right_hold_door_close_id    = GetRequiredNumbersID(object, CBTCVehicleInputs::RIGHT_HOLD_DOOR_CLOSE);
    m_train_data.left_door_open_indicator_id = GetRequiredNumbersID(object, CBTCVehicleInputs::LEFT_DOOR_OPEN_INDICATOR);
    m_train_data.right_door_open_indicator_id = GetRequiredNumbersID(object, CBTCVehicleInputs::RIGHT_DOOR_OPEN_INDICATOR);
    m_train_data.left_door_close_indicator_id = GetRequiredNumbersID(object, CBTCVehicleInputs::LEFT_DOOR_CLOSE_INDICATOR);
    m_train_data.right_door_close_indicator_id = GetRequiredNumbersID(object, CBTCVehicleInputs::RIGHT_DOOR_CLOSE_INDICATOR);
    m_train_data.left_door_release_indicator_id = GetRequiredNumbersID(object, CBTCVehicleInputs::LEFT_DOOR_RELEASE_INDICATOR);
    m_train_data.right_door_release_indicator_id = GetRequiredNumbersID(object, CBTCVehicleInputs::RIGHT_DOOR_RELEASE_INDICATOR);
    m_train_data.open_left_train_doors_id  = GetRequiredNumbersID(object, CBTCVehicleInputs::OPEN_LEFT_TRAIN_DOORS);
    m_train_data.open_right_train_doors_id = GetRequiredNumbersID(object, CBTCVehicleInputs::OPEN_RIGHT_TRAIN_DOORS);
    m_train_data.zero_speed_id             = GetRequiredNumbersID(object, CBTCVehicleInputs::ZERO_SPEED);
    m_train_data.rollback_detection_id     = GetRequiredNumbersID(object, CBTCVehicleInputs::ROLLBACK_DETECTED);
    AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });

    std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.service_brake_command_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.emergency_brake_command_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.immobilisation_state_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.audio_safety_brake_alarm_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.audio_warning_alarm_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.audio_departure_order_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.audio_target_speed_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.audio_high_priority_text_alert_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.audio_acknowledge_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.uto_mode_active_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.ato_state_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.ato_permitted_speed_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.ato_permitted_distance_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.ato_start_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.atc_cab_activation_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.traction_forward_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.ros_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.uto_pb_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.wake_up_command_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.atc_safety_brake_reset_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.left_side_door_enable_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.right_side_door_enable_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.left_hold_door_close_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.right_hold_door_close_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.left_door_open_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.left_door_release_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.open_left_train_doors_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.right_door_open_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.left_door_close_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.right_door_close_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.right_door_release_indicator_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.open_right_train_doors_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.zero_speed_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.rollback_detection_id));
    object.Numbers().Store().Request(number_requests.begin(), number_requests.end(), INPUT_REQUEST_FREQ);
}

/// Called when a new CBTCVehicleOutputs object is created
///
/// @param object The newly created object.
///
void CommsInterface::CBTCVehicleOutputsCreated(Comms::Object object)
{
    m_train_data.cbct_vehicle_outputs_object = object;

    using namespace Project::ValueName;
    m_train_data.power_supply_id           = GetRequiredNumbersID(object, CBTCVehicleOutputs::POWER_SUPPLY);
    m_train_data.cabin_activation_id       = GetRequiredNumbersID(object, CBTCVehicleOutputs::CABIN_ACTIVATION);
    m_train_data.driver_mode_selection_id  = GetRequiredNumbersID(object, CBTCVehicleOutputs::DRIVER_MODE_SELECTION);
    m_train_data.emergency_door_not_open_id= GetRequiredNumbersID(object, CBTCVehicleOutputs::EMERGENCY_DOOR_NOT_OPEN);
    m_train_data.mode_selector_position_id = GetRequiredNumbersID(object, CBTCVehicleOutputs::MODE_SELECTOR_POSITION);
    m_train_data.atc_bypass_state_id       = GetRequiredNumbersID(object, CBTCVehicleOutputs::ATC_BYPASS_STATE);
    m_train_data.tbc_position_id           = GetRequiredNumbersID(object, CBTCVehicleOutputs::TBC_POSITION);
    m_train_data.ato_start_button_id       = GetRequiredNumbersID(object, CBTCVehicleOutputs::ATO_START_BUTTON);
    m_train_data.uto_start_button_id       = GetRequiredNumbersID(object, CBTCVehicleOutputs::UTO_START_BUTTON);
    m_train_data.wake_up_status_id         = GetRequiredNumbersID(object, CBTCVehicleOutputs::WAKE_UP_STATUS);
    m_train_data.no_emergency_brake_id     = GetRequiredNumbersID(object, CBTCVehicleOutputs::NO_EMERGENCY_BRAKE);
    m_train_data.atc_sb_reset_button_id    = GetRequiredNumbersID(object, CBTCVehicleOutputs::ATC_SB_RESET_BUTTON);
    m_train_data.train_door_closed_and_locked_id = GetRequiredNumbersID(object, CBTCVehicleOutputs::TRAIN_DOOR_CLOSED_AND_LOCKED);
    m_train_data.no_door_enable_bypass_id = GetRequiredNumbersID(object, CBTCVehicleOutputs::NO_DOOR_ENABLE_BYPASS);
    m_train_data.tcms_speed_limit_id       = GetRequiredNumbersID(object, CBTCVehicleOutputs::TCMS_SPEED_LIMIT);
    m_train_data.tcms_speed_limit_cause_id = GetRequiredNumbersID(object, CBTCVehicleOutputs::TCMS_SPEED_LIMIT_CAUSE);

    AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });

    // Note that as part of its initialisation the train could change these values and so it is
    // necessary to make sure that the value is periodically refreshed
    std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.power_supply_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.cabin_activation_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.driver_mode_selection_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.emergency_door_not_open_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.mode_selector_position_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.atc_bypass_state_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.tbc_position_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.ato_start_button_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.uto_start_button_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.wake_up_status_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.no_emergency_brake_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.atc_sb_reset_button_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.train_door_closed_and_locked_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.no_door_enable_bypass_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.tcms_speed_limit_id));
    number_requests.push_back(object.Numbers().Info().GetInfo(m_train_data.tcms_speed_limit_cause_id));

    object.Numbers().Store().Request(number_requests.begin(), number_requests.end(), INPUT_REQUEST_FREQ);
}

/// Called when a new CBTCOnBoardInputs object is created
///
/// @param object The newly created object.
///
void CommsInterface::CBTCOnBoardInputsCreated(Comms::Object object)
{
    m_onboard_data.onboard_inputs_object = object;

    using namespace Project::ValueName;
    m_onboard_data.in_platform_region_id     = GetRequiredNumbersID(object, CBTCOnboardInputs::TRAIN_NEAR_PLATFORM);
    m_onboard_data.platform_status_id        = GetRequiredNumbersID(object, CBTCOnboardInputs::PLATFORM_STATUS);
    m_onboard_data.lhs_platform_detection_id = GetRequiredNumbersID(object, CBTCOnboardInputs::LHS_PLATFORM_DETECTION);
    m_onboard_data.rhs_platform_detection_id = GetRequiredNumbersID(object, CBTCOnboardInputs::RHS_PLATFORM_DETECTION);
    m_onboard_data.psd_present_id            = GetRequiredNumbersID(object, CBTCOnboardInputs::PSD_PRESENT);
    m_onboard_data.depot_region_id           = GetRequiredNumbersID(object, CBTCOnboardInputs::DEPOT_REGION);
    m_onboard_data.atp_zone_region_id        = GetRequiredNumbersID(object, CBTCOnboardInputs::ATP_ZONE_REGION);
    m_onboard_data.cbtc_message_acknowledge_id = GetRequiredNumbersID(object, CBTCOnboardInputs::CBTC_MESSAGE_ACKNOWLEDGE);

    m_onboard_data.last_detected_beacon_id = GetRequiredNumbersID(object, CBTCOnboardInputs::LAST_DETECTED_BEACON);

    m_onboard_data.driver_event_list_id        = GetRequiredRawsID(object, CBTCOnboardInputs::TRACK_EVENTS);
    m_onboard_data.gradient_discontinuities_id = GetRequiredRawsID(object, CBTCOnboardInputs::GRADIENT_DATA);
    m_onboard_data.movement_authority_id       = GetRequiredRawsID(object, CBTCOnboardInputs::MOVEMENT_AUTHORITY);
    m_onboard_data.speed_limit_profile_id      = GetRequiredRawsID(object, CBTCOnboardInputs::SPEED_LIMIT_DATA);

    AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });

    // Ensure that we are notified of the changes. We don't need a listener
    // though because we will just read these inputs in on a cyclic basis.
    std::vector<Sim::RequestInfo<Sim::Number>> cbtc_number_requests;
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.platform_status_id));
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.in_platform_region_id));
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.lhs_platform_detection_id));
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.rhs_platform_detection_id));
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.psd_present_id));
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.depot_region_id));
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.atp_zone_region_id));
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.cbtc_message_acknowledge_id));
    cbtc_number_requests.push_back(object.Numbers().Info().GetInfo(m_onboard_data.last_detected_beacon_id));

    object.Numbers().Store().Request(cbtc_number_requests.begin(), cbtc_number_requests.end(), INPUT_REQUEST_FREQ);

    // Get updates for our raw object
    std::vector<Sim::RequestInfo<Sim::Raw>> cbtc_raw_requests;
    cbtc_raw_requests.push_back(object.Raws().Info().GetInfo(m_onboard_data.driver_event_list_id));
    cbtc_raw_requests.push_back(object.Raws().Info().GetInfo(m_onboard_data.gradient_discontinuities_id));
    cbtc_raw_requests.push_back(object.Raws().Info().GetInfo(m_onboard_data.movement_authority_id));
    cbtc_raw_requests.push_back(object.Raws().Info().GetInfo(m_onboard_data.speed_limit_profile_id));

    object.Raws().Store().Request(cbtc_raw_requests.begin(), cbtc_raw_requests.end(), INPUT_REQUEST_FREQ);
}

/// Called when a new CBTCPlatformOutputs object is created
///
/// @param object The newly created object.
///
void CommsInterface::CBTCPlatformOutputsCreated(Comms::Object object)
{
    m_platform_data.platform_outputs_object = object;

    using namespace Project::ValueName;
    m_platform_data.train_docking_status_id = GetRequiredNumbersID(object, CBTCPlatformOutputs::TRAIN_DOCKING_STATUS);
    m_platform_data.psd_door_status_id      = GetRequiredNumbersID(object, CBTCPlatformOutputs::PSD_DOOR_STATUS);
    m_platform_data.psd_interlock_override_status_id = GetRequiredNumbersID(object, CBTCPlatformOutputs::PSD_INTERLOCK_OVERRIDE_STATUS);
    m_platform_data.departure_order_id = GetRequiredNumbersID(object, CBTCPlatformOutputs::DEPARTURE_ORDER);
    AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });

    std::vector<Sim::RequestInfo<Sim::Number>> cbtc_number_request;
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_platform_data.train_docking_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_platform_data.psd_door_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_platform_data.psd_interlock_override_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_platform_data.departure_order_id));
    object.Numbers().Store().Request(cbtc_number_request.begin(), cbtc_number_request.end(), INPUT_REQUEST_FREQ);
}

/// Called when a new CBTCOnBoardOutputs object is created
///
/// @param object The newly created object.
///
void CommsInterface::CBTCOnBoardOutputsCreated(Comms::Object object)
{
    m_onboard_data.onboard_outputs_object = object;

    using namespace Project::ValueName;
    m_onboard_data.current_train_speed_id = GetRequiredNumbersID(object, CBTCOnboardOutputs::CURRENT_TRAIN_SPEED);

    m_onboard_data.cbtc_target_speed_id    = GetRequiredNumbersID(object, CBTCOnboardOutputs::CBTC_TARGET_SPEED);
    m_onboard_data.cbtc_permitted_speed_id = GetRequiredNumbersID(object, CBTCOnboardOutputs::CBTC_PERMITTED_SPEED);
    m_onboard_data.speed_status_id         = GetRequiredNumbersID(object, CBTCOnboardOutputs::WARNING_STATUS);
    m_onboard_data.safety_brake_status_id  = GetRequiredNumbersID(object, CBTCOnboardOutputs::SAFETY_BRAKE_STATUS);
    m_onboard_data.atc_status_id           = GetRequiredNumbersID(object, CBTCOnboardOutputs::ATC_STATUS);
    m_onboard_data.target_distance_id      = GetRequiredNumbersID(object, CBTCOnboardOutputs::TARGET_DISTANCE);
    m_onboard_data.localisation_status_id  = GetRequiredNumbersID(object, CBTCOnboardOutputs::LOCALISATION_STATUS);
    m_onboard_data.advisory_speed_id       = GetRequiredNumbersID(object, CBTCOnboardOutputs::ADVISORY_SPEED);
    m_onboard_data.warning_speed_id        = GetRequiredNumbersID(object, CBTCOnboardOutputs::WARNING_SPEED);
    m_onboard_data.driver_event_skip_station_id = GetRequiredNumbersID(object, CBTCOnboardOutputs::DRIVER_EVENT_SKIP_STATION);
    m_onboard_data.driver_event_change_ends_id = GetRequiredNumbersID(object, CBTCOnboardOutputs::DRIVER_EVENT_CHANGE_ENDS);
    m_onboard_data.driver_event_work_zone_id = GetRequiredNumbersID(object, CBTCOnboardOutputs::DRIVER_EVENT_WORK_ZONE);
    m_onboard_data.detrainment_door_status_id = GetRequiredNumbersID(object, CBTCOnboardOutputs::DETRAINMENT_DOOR_STATUS);
    m_onboard_data.radio_communication_status_id = GetRequiredNumbersID(object, CBTCOnboardOutputs::RADIO_COMMUNICATION_STATUS);
    m_onboard_data.current_driving_mode_id    = GetRequiredNumbersID(object, CBTCOnboardOutputs::CURRENT_DRIVING_MODE);
    m_onboard_data.emergency_brake_trigger_id = GetRequiredNumbersID(object, CBTCOnboardOutputs::EMERGENCY_BRAKE_TRIGGER);
    m_onboard_data.atc_bypass_state_id        = GetRequiredNumbersID(object, CBTCOnboardOutputs::ATC_BYPASS_STATE);
    m_onboard_data.depot_indication_id        = GetRequiredNumbersID(object, CBTCOnboardOutputs::DEPOT_INDICATION);
    m_onboard_data.atp_zone_status_id         = GetRequiredNumbersID(object, CBTCOnboardOutputs::ATP_ZONE_STATUS);
    m_onboard_data.available_driving_modes_id = GetRequiredRawsID(object, CBTCOnboardOutputs::AVAILABLE_MODES);
    m_onboard_data.cbtc_text_messages_id      = GetRequiredRawsID(object, CBTCOnboardOutputs::CBTC_TEXT_MESSAGES);

    AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });

    // Ensure that we are notified of the changes. We don't need a listener
    // though because we will just read these inputs in on a cyclic basis.
    std::vector<Sim::RequestInfo<Sim::Number>> cbtc_number_request;
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.current_train_speed_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.cbtc_target_speed_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.cbtc_permitted_speed_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.speed_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.safety_brake_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.atc_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.target_distance_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.localisation_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.advisory_speed_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.warning_speed_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.driver_event_skip_station_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.driver_event_change_ends_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.driver_event_work_zone_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.detrainment_door_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.radio_communication_status_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.atc_bypass_state_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.current_driving_mode_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.emergency_brake_trigger_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.depot_indication_id));
    cbtc_number_request.push_back(object.Numbers().Info().GetInfo(m_onboard_data.atp_zone_status_id));
    object.Numbers().Store().Request(cbtc_number_request.begin(), cbtc_number_request.end(), INPUT_REQUEST_FREQ);

    std::vector<Sim::RequestInfo<Sim::Raw>> cbtc_raw_requests;
    cbtc_raw_requests.push_back(object.Raws().Info().GetInfo(m_onboard_data.available_driving_modes_id));
    cbtc_raw_requests.push_back(object.Raws().Info().GetInfo(m_onboard_data.cbtc_text_messages_id));
    object.Raws().Store().Request(cbtc_raw_requests.begin(), cbtc_raw_requests.end(), INPUT_REQUEST_FREQ);
}

void CommsInterface::VehicleInputsCreated(Comms::Object object)
{
    m_train_data.vehicle_inputs_object = object;
    
    using namespace Project::ValueName;
    m_train_data.emergency_brake_pb_id = GetRequiredNumbersID(object, VehicleInputs::EMERGENCY_BRAKE_PB);
    m_train_data.emergency_stop_pb_id = GetRequiredNumbersID(object, VehicleInputs::EMERGENCY_STOP_PB);
    m_train_data.master_controller_handle_id = GetRequiredNumbersID(object, VehicleInputs::MASTER_CONTROLLER_HANDLE);
    
    AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    
    std::vector<Sim::RequestInfo<Sim::Number>> number_request;
    number_request.push_back(object.Numbers().Info().GetInfo(m_train_data.emergency_brake_pb_id));
    number_request.push_back(object.Numbers().Info().GetInfo(m_train_data.emergency_stop_pb_id));
    number_request.push_back(object.Numbers().Info().GetInfo(m_train_data.master_controller_handle_id));
    
    object.Numbers().Store().Request(number_request.begin(), number_request.end(), INPUT_REQUEST_FREQ);
}

/// Called when an object is destroyed
///
/// @param object The object being destroy.
///
void CommsInterface::ObjectDestroyed(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    if ((Core::GetClassID(object) == Train::ClassID::TRAIN) && (object == m_train_data.train_object))
        m_train_data.vehicle_object.Invalidate();
    else if ((Core::GetClassID(object) == Train::ClassID::VEHICLE) && (object == m_train_data.vehicle_object))
        m_train_data.vehicle_object.Invalidate();
    else if ((Core::GetClassID(object) == Project::ClassID::INTERCOM_OUTPUTS) && (object == m_train_data.intercom_output_object))
        m_train_data.vehicle_object.Invalidate();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_INPUTS)
        m_train_data.cbtc_vehicle_inputs_object.Invalidate();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_OUTPUTS)
        m_train_data.cbct_vehicle_outputs_object.Invalidate();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS)
        m_onboard_data.onboard_inputs_object.Invalidate();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_OUTPUTS)
        m_onboard_data.onboard_outputs_object.Invalidate();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_PLATFORM_OUTPUTS)
        m_platform_data.platform_outputs_object.Invalidate();
    else if (Core::GetClassID(object) == Project::ClassID::VEHICLE_INPUTS)
        m_train_data.vehicle_inputs_object.Invalidate();
}
