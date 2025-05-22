///
/// @file       AutomaticTrainProtectionModule.cpp
///
///             Implements the AutomaticTrainProtectionModule class.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#include "AutomaticTrainProtectionModule.h"

#include "common/StandardLogging.h"

using namespace Project::CBTCOnBoard;

namespace
{
    const bool DEBUG = false;

    const double SPEED_DELTA       = 0.1;
    const double POSITION_DELTA    = 0.1;
    const double FSB_DELTA         = 1.38889; // 5 kmph
    const double WARNING_FSB_DELTA = 0.83333; // 3 kmph
    const double FSB_TRIGGER_TIME  = 3;
    bool         IsPositionEqual(double a, double b) { return std::abs(a - b) <= POSITION_DELTA; }
}

/// Constructor, which just initializes the members appropriately
///
/// @param init Initialisation data for the module
///
AutomaticTrainProtectionModule::AutomaticTrainProtectionModule(const Initialisation& init)
  : CBTCModule<AutomaticTrainProtectionModule, AutomaticTrainProtectionModuleIO>(init)
{
    // Initialise state data, if required
}

/// The Module function which, given the current inputs, adjusts the internal state and
/// populates the outputs.
///
/// @param time_step The amount of time to since the module was last run
///
void AutomaticTrainProtectionModule::Step(double time_step)
{
    // Control the train brakes
    ControlServiceBrake(time_step);
    ControlEmergencyBrake();
    ControlTractionCutOff();

    ControlTrainImmobilisation();

    // Update the mode recorded in the state
    X().cbtc_current_mode   = U().cbtc_current_mode;
    X().prev_train_position = U().current_train_position;
    X().mode_selector_position = U().mode_selector_position;
}

/// Controls the enabling/disabling of the Emergency brake
///
/// Note that some emergency brake conditions require an ack to be released while other don't
///
void AutomaticTrainProtectionModule::ControlEmergencyBrake()
{
    const auto previous_eb_trigger = X().emergency_brake_trigger;
    auto       current_eb_trigger  = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED;
	const auto flag_is_pecu_active = TriggerPECActive();

    ////////////////////////////////////
    // Determine the Current Emergency brake condition
    ////////////////////////////////////

    // Apply delocalised emergency brake when
    // - Driving mode is AM/CM/RMR
    // - Train not at standstill
    // - Train becomes delocalised
    if (TriggerDelocalisation())
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_TRAIN_DELOCALISED;
    }
    // Apply emergency brakes when
    // - Train rolls back in the opposite direction to the direction of travel
    else if (TriggerRollawayProtection())
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::ROLLWAY;
    }
    // Apply emergency brakes while
    // - Max allowed reverse direction movement exceeded
    else if (TriggerReverseMovementProtection())
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::MAX_REVERSE_EXCEEDED;
    }
    // Apply Mode Change On Run emergency brakes when
    // - Driving mode has changed while train on then move and train has not yet come to a standstill
    // Note that transition into and out of AM mode is allowed on the move
    else if (TriggerChangeOnRun())
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_MODE_CHANGE_ON_RUN;
    }
    // Apply train door unlocked emergency brakes when
    // - Train is not at standstill
    // - Train doors not closed and locked
    // - Train outside of station area
    else if (TriggerDoorsUnlocked())
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_TRAIN_DOOR_UNLOCKED;
    }

    else if (flag_is_pecu_active && 0.0 == U().pabr_bypass_req)
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_PEC_REQUEST;
    }

    // Apply psd door unlocked emergency brakes when
    // - Train is entering or leaving the station
    // - PSD doors not closed
    else if (TriggerPSDUnlocked())
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_PSD_UNLOCKED;
    }
    // Apply signal overrun emergency brakes while
    // - Train does not have a valid movement authority
    else if (U().movement_authority_exceeded)
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_SIGNAL_OVERRUN;
    }
    // Apply Comms lost emergency brakes while
    // - Driving mode is AM/CM
    // - Radio connection is lost
    else if (TriggerRadioLost())
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_COMMS_LOST;
    }
    // Apply Departure on Train Hold emergency brakes if
    // - Driving mode is AM/CM
    // - Train is not at standstill
    // - Train is being held at station
    else if (TriggerTrainHold())
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_TRAIN_HOLD;
    }
    // EB Intervention true if in TSM or CSM mode and either
    // - Current train speed > EBI speed
    // - The previously reported brake state was EB_Intervention and either
    //   -- (Current train speed > permitted speed)
    //   -- EB Release condition is standstill and train not at standstill
    else if (TriggerOverspeedIntervention(U().eb_intervention_velocity))
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_OVERSPEED_INTERVENTION;
    }

    // (refer 3.13.10.2.3 & 3.13.10.2.4)
    // IF service brake intervention is disabled then the Emergency brakes are applied at the SBI curve
    // EB Intervention true if in TSM mode, no permission to use service brakes and either
    // - Current train speed > SBI speed
    // - The previously reported brake state was EB_Intervention and either
    //   -- (Current train speed > permitted speed)
    //   -- EB Release condition is standstill and train not at standstill
    else if (!K().service_brake_intervention_enabled && TriggerOverspeedIntervention(U().sb_intervention_velocity))
    {
        current_eb_trigger = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_OVERSPEED_INTERVENTION;
    }

    ////////////////////////////////////
    // Determine if Emergency brake requires a driver reset before it can be cleared.
    // EB Reset is required for all cases except the following
    // - EB while cab is not active
    // - Overspeed EB release condition is "Under speed limit" and speed drops below permitted speed
	const bool is_pabr_bypass_active = (flag_is_pecu_active && 1.0 == U().pabr_bypass_req);
    bool brake_reset_required = true;
    if ((U().cabin_activation == Project::TypeValue::CabinActivation::INACTIVE) ||
        (previous_eb_trigger == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED) ||
        ((previous_eb_trigger == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_OVERSPEED_INTERVENTION) &&
         (K().nv_tsm_eb_release_condition == Project::CBTCOnBoard::TypeValue::NVEBReleaseCondition::UNDER_SPEED_LIMIT)) ||
		is_pabr_bypass_active)
    {
        brake_reset_required = false;
    }

    // EB reset enabled when the EB Condition clears,
    // The CBTC is current set to a valid mode,
    // the train comes to a standstill and EB reset request is yet to be received.
    bool brake_reset_enabled = false;
    if ((previous_eb_trigger != Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED) && (U().cbtc_current_mode != Project::TypeValue::CBTCMode::NO_MODE) &&
        (U().train_at_standstill && !U().reset_safety_brake) && IsPositionEqual(U().current_train_position, X().prev_train_position))
    {

        Trace::GetLogger().STAMP(Trace::VERBOSE)
          << "*********** Enable Brake Reset"
          << "\n U().cbtc_current_mode:" << U().cbtc_current_mode << "\n previous_eb_trigger:" << (int) previous_eb_trigger
          << "\n current_eb_trigger:" << (int) current_eb_trigger << Trace::EndLog();

        brake_reset_enabled = true;
    }

    // Emergency Brake is NOT applied if no brake condition active and either
    // - No Ack required
    // - Required brake ack received
    Y().emergency_brake_request = Project::TypeValue::EmergencyBrakeOrder::EMERGENCY_BRAKE_DEMAND;
    if ((!brake_reset_required || U().reset_safety_brake) &&
        (current_eb_trigger == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED))
    {
        Y().emergency_brake_request = Project::TypeValue::EmergencyBrakeOrder::NO_EB_BRAKE;
    }
    // Update the reported EB brake state if
    // - an emergency brake trigger has not yet been reported
    // - we are not required to wait for the emergency brake to be reset
    // - we require the safety brake to be reset and the reset request has been received
    if ((previous_eb_trigger == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED) ||
        !brake_reset_required || U().reset_safety_brake)
    {
        X().emergency_brake_trigger = current_eb_trigger;
    }

    // Update the remaining outputs
    Y().emergency_brake_condition  = X().emergency_brake_trigger;
    Y().request_safety_brake_reset = brake_reset_enabled;

    if (DEBUG && ((current_eb_trigger != Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED) ||
                  Y().request_safety_brake_reset))
    {
        Trace::GetLogger().STAMP(Trace::WARN)
          << "Rollback Distance: " << X().rollback_movement_distance << "\nDist Travelled Backwards:" << X().distance_travelled_backwards
          << "\nLast Reported Emergency Brake Condition: " << (int) previous_eb_trigger
          << "\nCurrent Emergency Brake Condition: " << (int) current_eb_trigger
          << "\nCurrent Train Pos: " << U().current_train_position << "\nPrevious Train Pos: " << X().prev_train_position
          << ", AreEqual(" << IsPositionEqual(U().current_train_position, X().prev_train_position) << ")"
          << "\nReset Safety Brake:" << U().reset_safety_brake << "\nBrake Reset Reqd:" << brake_reset_required
          << "\nBrake Reset Enabled:" << brake_reset_enabled
          << "\nEmergency Brake Trigger:" << (int) X().emergency_brake_trigger << Trace::EndLog();
    }
}

bool AutomaticTrainProtectionModule::TriggerDelocalisation()
{
    const auto is_train_delocalised = (U().current_localisation_state == Project::TypeValue::LocalisationStatus::NOT_LOCALISED) ||
                                      (U().current_localisation_state == Project::TypeValue::LocalisationStatus::UNAVAILABLE);

    const auto is_eb_trigger_delocalised = (X().emergency_brake_trigger ==
                                            Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_TRAIN_DELOCALISED);

    const auto current_mode_requires_localisation = (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
                                                    (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
                                                    (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO);
    return ((!U().train_at_standstill) && is_train_delocalised && (current_mode_requires_localisation || is_eb_trigger_delocalised));
}

/// Returns whether the condition that triggers Rollaway Protection is active
///
/// @returns true if train moves more than the Max rollback distance
///
bool AutomaticTrainProtectionModule::TriggerRollawayProtection()
{
    // No protection if ATC is bypassed and train is in Driver supervision
    if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATC_BYPASS)
        return false;

    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMF))
    {
        // Update the distance traveled if train moves backwards
        if (U().current_train_position > X().prev_train_position)
            X().rollback_movement_distance = 0.0;
        else
            X().rollback_movement_distance += (U().current_train_position - X().prev_train_position);
    }
    else if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMR)
    {
        // Update the distance traveled if train moves forwards
        if (U().current_train_position < X().prev_train_position)
            X().rollback_movement_distance = 0.0;
        else
            X().rollback_movement_distance += (U().current_train_position - X().prev_train_position);
    }
    else if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::NO_MODE)
    {
        // Assume that the train is applying the brakes whenever CBTC Onboard is in the No_Mode State so
        // we don't need to record rollback movement distance
    }

    // Reset the rollback distance once train comes to a standstill due to rollback EB brake being applied
    if (U().train_at_standstill && (X().emergency_brake_trigger == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::ROLLWAY))
    {
        X().rollback_movement_distance = 0.0;
    }

    if (abs(X().rollback_movement_distance) > K().max_rollback_distance)
        return true;

    return false;
}

/// Returns whether the condition that triggers Reverse Movement Protection is active
///
/// @returns true if train moves more than the max reverse movement distance
///
bool AutomaticTrainProtectionModule::TriggerReverseMovementProtection()
{
    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMF))
    {
        // Determine if the train has travelled backwards and record by how far.
        if ((U().current_train_position < X().prev_train_position) || (X().distance_travelled_backwards < 0.0))
        {
            // Negative value indicates the train has moved backwards
            X().distance_travelled_backwards += (U().current_train_position - X().prev_train_position);

            // Update distance travelled backward to be zero if the value ever becomes positive
            if (X().distance_travelled_backwards > 0.0)
                X().distance_travelled_backwards = 0.0;
        }

        // Max reverse distance exceeded is reported when in AM/CM mode and the distance travelled exceeds
        // the maximum allowed reverse movement distance
        if (((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
             (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
             (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO)) &&
            ((std::abs(X().distance_travelled_backwards) > K().max_reverse_distance)))
            return true;
        else
            return false;
    }

    else if (U().cbtc_current_mode == Project::TypeValue::CBTCMode::RMR)
    {
        // Train reverse movement protection triggered if the train reverses by more than
        // the max allowed reversing distance
        if (U().max_reverse_distance_exceeded || U().train_docking_status == Project::TypeValue::TrainDockingStatus::TOO_LONG_STOP)
            return true;
        else
            return false;
    }

    return false;
}

bool AutomaticTrainProtectionModule::TriggerChangeOnRun()
{
    const auto has_mode_changed = (X().mode_selector_position != U().mode_selector_position);
    // For MMRBEM mode transition from ROS to ATP on the fly once localisation status is available.
    const auto mode_trans = (U().cbtc_current_mode != Project::TypeValue::CBTCMode::ATO && // current
                             X().cbtc_current_mode != Project::TypeValue::CBTCMode::ROS); // previous
    
    const auto is_eb_trigger_change_on_run = (X().emergency_brake_trigger ==
                                              Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_MODE_CHANGE_ON_RUN);

    return ((!U().train_at_standstill) && ((has_mode_changed && mode_trans) || is_eb_trigger_change_on_run));
}

bool AutomaticTrainProtectionModule::TriggerDoorsUnlocked()
{
    return (!U().train_at_standstill && !U().doors_closed_and_locked && !U().train_near_station);
}

bool AutomaticTrainProtectionModule::TriggerPSDUnlocked()
{
    const auto psd_status = (U().psd_door_close_status == Project::TypeValue::PSDDoorStatus::PSD_OPENED ||
                             U().psd_door_close_status == Project::TypeValue::PSDDoorStatus::PSD_CLOSING_FAILURE) &&
                            U().psd_interlock_override_status == Project::TypeValue::IndicatorState::OFF;
    return (psd_status && U().doors_closed_and_locked &&
            U().platform_status == Project::TypeValue::PlatformStatus::IMMEDIATE_DEPARTURE && U().current_train_speed > 0.1);
}

bool AutomaticTrainProtectionModule::TriggerRadioLost()
{
    const auto is_cbtc_active = (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
                                (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
                                (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO);

    return (is_cbtc_active && (U().radio_communication_state == Project::TypeValue::RadioCommsStatus::COMMS_NOT_ESTABLISHED));
}

bool AutomaticTrainProtectionModule::TriggerTrainHold()
{
    const auto is_cbtc_active = (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
                                (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
                                (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO);
	
	//return (is_cbtc_active && (!U().train_at_standstill) && (U().train_held_at_station));
	//MMRBEM-4350
	//Trigger EB when driver tries to traction & HOLD is applied & cbtc active
    return (is_cbtc_active && (U().master_brake_controller > 0.0) && (U().train_held_at_station));
}

bool AutomaticTrainProtectionModule::TriggerOverspeedIntervention(double intervention_velocity)
{
    const auto is_monitoring_mode_valid = ((U().monitoring_mode == Project::CBTCOnBoard::TypeValue::MonitoringMode::TSM) ||
                                           (U().monitoring_mode == Project::CBTCOnBoard::TypeValue::MonitoringMode::PIM) ||
                                           (U().monitoring_mode == Project::CBTCOnBoard::TypeValue::MonitoringMode::CSM));

    const auto is_eb_trigger_overspeed       = (X().emergency_brake_trigger ==
                                          Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_OVERSPEED_INTERVENTION);
    const auto is_eb_release_cond_standstill = (K().nv_tsm_eb_release_condition ==
                                                Project::CBTCOnBoard::TypeValue::NVEBReleaseCondition::STANDSTILL);
    const auto is_standstill_violated        = (is_eb_release_cond_standstill && !U().train_at_standstill);

    const auto is_intervention_required = (IsSpeedThresholdExceeded(intervention_velocity) ||
                                           (is_eb_trigger_overspeed &&
                                            (IsSpeedThresholdExceeded(U().permitted_velocity) || is_standstill_violated)));

    return (U().speed_monitoring_active && is_monitoring_mode_valid && is_intervention_required);
}

bool AutomaticTrainProtectionModule::TriggerPECActive()
{
    bool active_call = false;
    if (U().active_call_type == 2 && U().call_status != 0)
        active_call = true;
    
    return (active_call && (U().train_at_standstill || U().platform_status != Project::TypeValue::PlatformStatus::NOT_DOCKED ||
                            U().stopping_point_distance < 0.1));
}

/// Controls the enabling/disabling of the Service brake
///
/// Note that some service brake conditions require an ack to be released while other don't
///
void AutomaticTrainProtectionModule::ControlServiceBrake(double timestep)
{
    // Service brake intervention is applied when we have
    // (service brake intervention enable and current mode is ATP) and either
    // - current train speed is greater than the service brake intervention speed OR
    // - Service Brack Intervention is active and (Current train speed > permitted speed)
    // MMRBEM-3313 - When  overspeed happens FSB should be apply until speed is reduced by 5 kmph. i.e.1.39(FSB_DELTA)
    //MMRBEM-3550 - FSB symbol should not appear on every overspeed
    double fsb_brake = U().permitted_velocity - FSB_DELTA;
    double fsb_speed_limit = K().fsb_speed_overshoot * 0.28;    // conversion from km/h to m/s

    if ((U().speed_monitoring_active) &&
          (K().service_brake_intervention_enabled && (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP)) &&
        (IsSpeedThresholdExceeded(fsb_brake)) &&
        U().train_docking_status != Project::TypeValue::TrainDockingStatus::SHORT_STOP && U().warning_speed < 0)
    {
        // below commented code is default logic dependent on time duration of FSB_TRIGGER_TIME, kept it for future use
        // Start the timer used to simulate the time take for the radio connection to be established
        /*if (X().full_service_brake_start_time == INVALID_TIME)
            X().full_service_brake_start_time = timestep + FSB_TRIGGER_TIME;
        if (X().full_service_brake_start_time <= timestep)
            Y().service_brake_request = Project::TypeValue::ServiceBrakeOrder::FULL_SB_DEMAND;*/


        // if speed is above 3 kmph (0.84 m/s) of permitted velocity, FSB will be triggered
        if ( U().current_train_speed > (U().permitted_velocity + fsb_speed_limit) || 
           (U().tcms_speed_limit_cause > 0.0 && U().current_train_speed > U().tcms_speed_limit))
          Y().service_brake_request = Project::TypeValue::ServiceBrakeOrder::FULL_SB_DEMAND;
    }

    // Update the remaining outputs
    //  Y().service_brake_request = X().service_brake_request;
    else if ((( (U().warning_speed > 0 && IsSpeedThresholdExceeded(U().advisory_speed + WARNING_FSB_DELTA))) &&
             U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) || ((U().train_docking_status == Project::TypeValue::TrainDockingStatus::SHORT_STOP) &&
         U().current_train_speed > 2.7))
        Y().service_brake_request = Project::TypeValue::ServiceBrakeOrder::FULL_SB_DEMAND;
    else
    {
        Y().service_brake_request = Project::TypeValue::ServiceBrakeOrder::NO_SB_DEMAND;
        X().full_service_brake_start_time = INVALID_TIME;
    }

    if (DEBUG && (X().service_brake_request == Project::TypeValue::ServiceBrakeOrder::FULL_SB_DEMAND))
        Trace::GetLogger().STAMP(Trace::WARN) << "ControlServiceBrake : " << X().service_brake_request << Trace::EndLog();
}

/// Controls the enabling/disabling of Traction Cutoff
///
void AutomaticTrainProtectionModule::ControlTractionCutOff()
{
    //  In TSM mode Traction disabled when either
    // - warning velocity exceeded
    // - Traction previously disabled and train speed greater than permitted speed
    // - Emergency brake is being applied
    // - Service brake is being applied
    if ((U().speed_monitoring_active && (IsSpeedThresholdExceeded(U().warning_velocity) ||
                                         (U().warning_speed > 0 && IsSpeedThresholdExceeded(U().warning_speed)) ||
                                         ((X().traction_cutoff_active) && IsSpeedThresholdExceeded(U().permitted_velocity)))) ||
        (X().emergency_brake_trigger != Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED) ||
        (X().service_brake_request == Project::TypeValue::ServiceBrakeOrder::FULL_SB_DEMAND))
    {
        Y().traction_cutoff_active = true;
    }
    else
        Y().traction_cutoff_active = false;

    // Update the state
    Y().traction_cutoff_active = X().traction_cutoff_active;

    if (DEBUG && X().traction_cutoff_active)
        Trace::GetLogger().STAMP(Trace::WARN) << "ControlTractionCutOff : " << X().traction_cutoff_active << Trace::EndLog();
}

/// Controls Train Immobilisation
///
/// The on-board system shall trigger train immobilisation in following situations :
/// -  Passenger Exchange - When train is correctly docked at platform train immobilisation is activated and will not
///    be released until the departure time of a new movement
/// -  Immobilisation due to Emergency Brake
/// -  Immobilisation after end of train movement(in front of switch, red lights etc.) and will not be released until
///    the new movement authority is received.
///
void AutomaticTrainProtectionModule::ControlTrainImmobilisation()
{
    // The following conditions shall trigger train immobilisation :
    // - Docked at a station
    // - Train doors are not closed and locked
    // - Emergency Brake is being applied
    // - CBTC Mode is No Mode
    // TBD : Need to determine if there are additional conditions that trigger immobilisation
    if ((U().platform_status == Project::TypeValue::PlatformStatus::DOCKED) || !U().doors_closed_and_locked ||
        (Y().emergency_brake_condition != Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED) ||
        U().cbtc_current_mode == Project::TypeValue::CBTCMode::NO_MODE || U().train_held_at_station)
    {
        Y().immobilisation_state = Project::TypeValue::ImmobilisationState::IMMOBILSED;
    }
    else
        Y().immobilisation_state = Project::TypeValue::ImmobilisationState::MOVEMENT_ALLOWED;
}

bool Project::CBTCOnBoard::AutomaticTrainProtectionModule::IsSpeedThresholdExceeded(double threshold_speed) const
{
    return (std::abs(GetInputs().current_train_speed) > (threshold_speed + SPEED_DELTA));
}
