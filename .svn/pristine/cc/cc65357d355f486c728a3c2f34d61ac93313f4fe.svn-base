///
/// @file       OnBoardController.cpp
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

#include "OnBoardController.h"

#include "CBTCConstants.h"
#include "project_comms_structure/ProjectObjectDefinition.h"

#include "common/StandardLogging.h"

using namespace Project::CBTCOnBoard;

namespace
{
    const bool   DEBUG                        = false;
    const double MOMENTARY_SIGNAL_DELAY       = 0.25;
    const double POWERUP_TEST_DURATION        = 10.0;   // seconds
    const double RADIO_CONNECTION_TIME        = 3.0;    // seconds
    const double SAFETY_BRAKE_INHIBIT_TIMEOUT = 2;      // seconds
    const double STANDSTILL_SPEED             = 0.0001; // mps
    const double PSD_BYPASSED_MAX_SPEED_ALLOWED = 1.944; // 7kmph

    /// Helper function that extracts the initialisation data that is required by a Speed
    /// And Distance Monitoring module.
    ///
    /// @param init The initialisation data, as prepared for the OnBoard Controller
    ///
    /// @return The initialisation data as desired by a Speed And Distance Monitoring module

    AutomaticTrainOperationModule::Initialisation GetAutomaticTrainOperationInit(const OnBoardController::Initialisation& init)
    {
        AutomaticTrainOperationModule::Initialisation ret;
        return ret;
    }

    /// Helper function that extracts the initialisation data that is required by a Speed
    /// And Distance Monitoring module.
    ///
    /// @param init The initialisation data, as prepared for the OnBoard Controller
    ///
    /// @return The initialisation data as desired by a Speed And Distance Monitoring module

    SpeedAndDistanceMonitoringModule::Initialisation GetSpeedAndDistancingInit(const OnBoardController::Initialisation& init)
    {
        SpeedAndDistanceMonitoringModule::Initialisation ret;

        ret.auto_region_speed_limit            = init.auto_region_speed_limit;
        ret.rmf_speed_limit                    = init.rmf_speed_limit;
        ret.rmr_speed_limit                    = init.rmr_speed_limit;
        ret.ros_speed_limit                    = init.ros_speed_limit;
        ret.auto_skip_speed_limit              = init.auto_skip_speed_limit;
        ret.memorised_localisation_speed_limit = init.memorised_localisation_speed_limit;
        ret.max_reverse_distance               = init.max_reversing_zone;
        ret.train_length                       = init.train_length;

        ret.dbec                  = init.dbec;
        ret.ebd_rate              = init.ebd_rate;
        ret.sbd_rate              = init.sbd_rate;
        ret.ato_brake_demand_rate = init.ato_brake_demand_rate;
        ret.t_service_brake       = init.t_service_brake;
        ret.t_indication          = init.t_indication;

        ret.dv_ebi_min     = init.dv_ebi_min;
        ret.dv_ebi_max     = init.dv_ebi_max;
        ret.v_ebi_min      = init.v_ebi_min;
        ret.v_ebi_max      = init.v_ebi_min;
        ret.dv_sbi_min     = init.dv_sbi_min;
        ret.dv_sbi_max     = init.dv_sbi_max;
        ret.v_sbi_min      = init.v_sbi_min;
        ret.v_sbi_max      = init.v_sbi_max;
        ret.dv_warning_min = init.dv_warning_min;
        ret.dv_warning_max = init.dv_warning_max;
        ret.v_warning_min  = init.v_warning_min;
        ret.v_warning_max  = init.v_warning_max;
        ret.t_warning      = init.t_warning;
        ret.t_driver       = init.t_driver;
        ret.t_preindiction = init.t_preindiction;

        return ret;
    }

    /// Helper function that extracts the initialisation data that is required by a Automatic
    /// Train Protection module.
    ///
    /// @param init The initialisation data, as prepared for the OnBoard Controller
    ///
    /// @return The initialisation data as desired by a Automatic Train Protection module

    AutomaticTrainProtectionModule::Initialisation GetAutomaticTrainProtectionInit(const OnBoardController::Initialisation& init)
    {
        AutomaticTrainProtectionModule::Initialisation ret;

        ret.nv_tsm_eb_release_condition        = Project::CBTCOnBoard::TypeValue::NVEBReleaseCondition::STANDSTILL;
        ret.service_brake_intervention_enabled = init.fsb_enabled;
        ret.max_rollback_distance              = init.max_rollback_distance;
        ret.max_reverse_distance               = init.max_reversing_zone;
        ret.fsb_speed_overshoot                = init.fsb_speed_limit;

        return ret;
    }

    /// Helper function that extracts the initialisation data that is required by a Beacon
    /// Management module.
    ///
    /// @param init The initialisation data, as prepared for the OnBoard Controller
    ///
    /// @return The initialisation data as desired by a Beacon Management Module

    BeaconManagementModule::Initialisation GetBeaconManagementInit(const OnBoardController::Initialisation& init)
    {
        BeaconManagementModule::Initialisation ret;

        ret.memorised_localisation_validity_distance = init.memorised_localisation_validity_distance;
        return ret;
    }

    /// Helper function that extracts the initialisation data that is required by a Level
    /// Transition module.
    ///
    /// @param init The initialisation data, as prepared for the OnBoard Controller
    ///
    /// @return The initialisation data as desired by a Mode Transition Module

    ModeTransitionModule::Initialisation GetModeTransitionInit(const OnBoardController::Initialisation& init)
    {
        ModeTransitionModule::Initialisation ret;
        return ret;
    }

    /// Helper function that extracts the initialisation data that is required by a Text Management
    /// module.
    ///
    /// @param init The initialisation data, as prepared for the OnBoard Controller
    ///
    /// @return The initialisation data as desired by a Text Management Module

    TextManagementModule::Initialisation GetTextManagementInit(const OnBoardController::Initialisation& init)
    {
        TextManagementModule::Initialisation ret;
        ret.session_start_time = init.session_start_time;
        return ret;
    }

    /// Helper function that extracts the initialisation data that is required by a Trackside Data Management
    /// module.
    ///
    /// @param init The initialisation data, as prepared for the OnBoard Controller
    ///
    /// @return The initialisation data as desired by a Trackside Data Management Module

    TrackSideDataModule::Initialisation GetTrackSideDataManagementInit(const OnBoardController::Initialisation& init)
    {
        TrackSideDataModule::Initialisation ret;
        ret.auto_skip_speed_limit    = init.auto_skip_speed_limit;
        ret.auto_skip_distance       = init.auto_skip_distance;
        ret.overshoot_distance       = init.overshoot_distance;
        ret.undershoot_distance      = init.undershoot_distance;
        ret.work_zone_alarm_distance = init.work_zone_alarm_distance;
        return ret;
    }
}

OnBoardController::OnBoardController(const Initialisation&  init,
                                     TrainInputSupplier&    train_inputs,
                                     CBTCDataInputSupplier& cbtc_data,
                                     OutputsReporter&       outputs_reporter)
  : CBTCModule<OnBoardController, OnBoardControllerIO>(init)
  , m_speed_and_distance_monitoring(GetSpeedAndDistancingInit(init))
  , m_beacon_management(GetBeaconManagementInit(init))
  , m_automatic_train_operation(GetAutomaticTrainOperationInit(init))
  , m_automatic_train_protection(GetAutomaticTrainProtectionInit(init))
  , m_mode_transition_machine(GetModeTransitionInit(init))
  , m_text_management(GetTextManagementInit(init))
  , m_trackside_data_management(GetTrackSideDataManagementInit(init))
  , m_train_inputs(train_inputs)
  , m_cbtc_data_input(cbtc_data)
  , m_outputs_reporter(outputs_reporter)
{
    // Our submodels have been created, and set their initial state, so now get them to use our
    // state, which will mean that when our state is updated their's is automatically updated
    // to. They will automatically set the new state to match their current.
    m_speed_and_distance_monitoring.SetStateObject(X().speed_and_distance_monitoring_module_state);
    m_beacon_management.SetStateObject(X().beacon_management_module_state);
    m_mode_transition_machine.SetStateObject(X().mode_transition_state);
    m_automatic_train_operation.SetStateObject(X().automatic_train_operation_state);
    m_automatic_train_protection.SetStateObject(X().automatic_train_protection_state);
    m_text_management.SetStateObject(X().text_management_state);
    m_trackside_data_management.SetStateObject(X().trackside_data_state);

    X().cbtc_current_mode           = Project::TypeValue::CBTCMode::NO_MODE;
    X().cbtc_target_speed           = 0.0;
    X().platform_status             = Project::TypeValue::PlatformStatus::NOT_DOCKED;
    X().emergency_brake_trigger     = Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED;
    X().s_info_start_time           = 0.0;
    X().text_alert_audio_start_time = 0.0;

    X().initial_scenario_mode             = Project::TypeValue::CBTCMode::NO_MODE;
    X().scenario_initialisation_completed = false;
    X().radio_setup_required              = false;
    X().power_up_test_completed           = false;
    X().power_up_test_start_time          = INVALID_TIME;
    X().start_up_test_stage               = Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_NOT_ACTIVE;
    X().connection_start_time             = INVALID_TIME;
    X().driver_mode_selection             = Project::TypeValue::DriverModeSelection::OFF;
    X().mode_selector_position            = Project::TypeValue::ModeSelector::OFF_UTO;
    // Initialise any outputs that are set durectly by the controller
    Y().audio_safety_brake_alarm       = Project::TypeValue::CBTCAudio::OFF;
    Y().audio_warning_alarm            = Project::TypeValue::CBTCAudio::OFF;
    Y().audio_departure_order          = Project::TypeValue::CBTCAudio::OFF;
    Y().audio_target_speed             = Project::TypeValue::CBTCAudio::OFF;
    Y().audio_high_priority_text_alert = Project::TypeValue::CBTCAudio::OFF;
    Y().audio_acknowledge              = Project::TypeValue::CBTCAudio::OFF;
}

/// Actions to be performed during each run cycle
///
///
/// @param time_step Identifies the time at which the step is running
///
void OnBoardController::Step(double time_step)
{
    ////////////////////
    // Populate the controllers input data
    m_train_inputs.GetTrainInputs(U());
    m_cbtc_data_input.SetPlatformOutputs(U());
    // Get  wakeup signal from train
    Y().wake_up_command    = U().train_wakeup;
    Y().atc_cab_activation = U().cab_activation;

    m_cbtc_data_input.GetOnBoardDataInputs(U());

    // Keep performing the CBTC Onboard system initialisation actions until complete
    if (!X().scenario_initialisation_completed)
        PerformCBTCOnboardSetup();

    // Handle the CBTC Systems Power up behaviour
    if (!X().power_up_test_completed)
        PerformSystemPowerupTest(time_step);

    // Handle the CBTC Systems Power down behaviour
    if (U().power_supply == Project::TypeValue::PowerSupply::NO_POWER)
    {
        // Need to reset the data so that the power up test is triggered when the CBTC is powered on again
        X().power_up_test_start_time = INVALID_TIME;
        X().start_up_test_stage      = Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_NOT_ACTIVE;
        X().power_up_test_completed  = false;
    }

    ////////////////////
    // Set the signals that are passed from the train model to the DMI
    Y().current_train_speed = U().current_train_speed;

    // Inverted train model value since DMI shows true when safety brake on wheras
    // train reports true when No Safety brake
    Y().safety_brake = !U().no_emergency_brake;

    // Invert the train model value of emergency door not open  to DMI
    Y().detrainment_door_status = !U().emergency_door_not_open;

    ////////////////////
    // Trigger the playing of any required audio
    PlayAudio(time_step);

    // Determine the status of the CBTC OnBoard systems
    DetermineOnboardStatus();

    // Manage the connection with the radio
    ManageRadioConnection(time_step);

    ////////////////////
    // Run the Modules
    // Note that order is important since the outputs of some modules
    // feed in as the inputs to a number of modules. Depending on the order
    // in which modules are run some modules may receive the output of a module
    // from either the current run cycle or previous run cycle. In order to keep
    // the input data of all modules in sync (ie in the case of cbtc driving mode) it is
    // necessary to store some outputs into state and used these state values
    // as the input data supplied to a module rather than passing the outputs directly
    // from one module to another.

    /*(1)*/ ProcessAutomaticTrainOperationModule(time_step);
    /*(2)*/ ProcessModeTransitionModuleModule(time_step);

    // Update the state data
    auto mt_outputs       = m_mode_transition_machine.GetOutputs();
    X().cbtc_current_mode = mt_outputs.cbtc_current_mode;

    /*(3)*/ ProcessBeaconManagementModule(time_step);
    /*(4)*/ ProcessTrackSideDataManagementModule(time_step);
    /*(5)*/ ProcessAutomaticTrainProtectionModule(time_step);
    /*(6)*/ ProcessSpeedAndDistanceMonitoringModule(time_step);
    /*(7)*/ ProcessTextManagementModule(time_step);

    // Report the Controller output data
    m_outputs_reporter.SetOnBoardDataOutputs(Y());
    m_outputs_reporter.SetTrainOutputs(Y());

    ////////////////////
    // Update state info for the next step
    auto& sdm_outputs = m_speed_and_distance_monitoring.GetOutputs();
    auto& atp_outputs = m_automatic_train_protection.GetOutputs();

    X().cbtc_target_speed       = sdm_outputs.cbtc_target_speed;
    X().emergency_brake_trigger = atp_outputs.emergency_brake_condition;
    X().driver_mode_selection   = U().driver_mode_selection;
    X().mode_selector_position  = U().mode_selector_position;
    X().platform_status         = U().platform_status;
    Y().emergency_brake_trigger = static_cast<int>(atp_outputs.emergency_brake_condition);
    Y().depot_indication        = U().depot_region;
    Y().atp_zone_status         = U().atp_zone_region;
    if (DEBUG)
    {
        auto& tdm_outputs = m_trackside_data_management.GetOutputs();

        Trace::GetLogger().STAMP(Trace::WARN)
          << "OnBoardController::Step (" << time_step << ") \n"
          << "------------------------------------------------------------\n"
          << "(train_position, train_speed) : " << U().current_train_position << ", " << U().current_train_speed << ")\n"

          << "(driving mode)       : (" << Y().current_driving_mode << ")\n"

          << "(loa distance, svl distance)  : (" << tdm_outputs.eoa_distance << ", " << tdm_outputs.stopping_distance << ")\n"

          << "(Audio)                       : (" << Y().audio_safety_brake_alarm << " " << Y().audio_warning_alarm
          << " " << Y().audio_departure_order << " " << Y().audio_target_speed << " " << Y().audio_acknowledge << " "
          << Y().audio_high_priority_text_alert << ")\n"
          << "------------------------------------------------------------\n"
          << Trace::EndLog();
    }
}

/// Execute the Run Cycle of the Beacon Management Module
///
/// @param time_step Time at which the function was run
///
void OnBoardController::ProcessBeaconManagementModule(double time_step)
{
    auto& bm_inputs = m_beacon_management.GetInputs();

    // Set the input data required by the beacon management module
    bm_inputs.current_train_position     = U().current_train_position;
    bm_inputs.initial_localisation_state = U().initial_localisation_state;
    bm_inputs.cabin_activation           = U().cabin_activation;
    bm_inputs.last_detected_beacon_id    = U().last_detected_beacon;

    // Manage the Beacon management function actions
    m_beacon_management.RunCycle(time_step);

    // DMI Data populated by the Beacon Management module
    auto& bm_outputs = m_beacon_management.GetOutputs();

    /*if (X().cbtc_current_mode != Project::TypeValue::CBTCMode::ATC_BYPASS)*/
        Y().localisation_status = bm_outputs.current_localisation_state;
    /*else
        Y().localisation_status = Project::TypeValue::LocalisationStatus::UNAVAILABLE;*/
}

/// Execute the Run Cycle of the Mode Transition Module
///
/// @param time_step Time at which the function was run
///
void OnBoardController::ProcessModeTransitionModuleModule(double time_step)
{
    auto& mt_inputs = m_mode_transition_machine.GetInputs();

    // Set the inputs which are populated using Train data
    mt_inputs.current_train_speed     = U().current_train_speed;
    mt_inputs.selected_driving_mode   = U().driver_mode_selection;
    mt_inputs.mode_selector_position  = U().mode_selector_position;
    mt_inputs.system_startup_complete = X().power_up_test_completed;
    mt_inputs.power_supply            = U().power_supply;
    mt_inputs.cab_activate            = U().cabin_activation;
    mt_inputs.atc_bypass_switch       = U().atc_bypass_state;
    mt_inputs.tbc_position            = U().tbc_position;
    // mt_inputs.in_automatic_region        = U().in_automatic_region;
    mt_inputs.radio_communication_status    = X().radio_communication_status;
    mt_inputs.atc_status                    = X().atc_status;
    mt_inputs.psd_present                   = U().psd_present;
    mt_inputs.power_up_test_completed       = X().power_up_test_completed;
    auto& ato_output                        = m_automatic_train_operation.GetOutputs();
    auto& bm_output                         = m_beacon_management.GetOutputs();
    auto& sdm_output                        = m_speed_and_distance_monitoring.GetOutputs();
    auto& tdm_output                        = m_trackside_data_management.GetOutputs();
    mt_inputs.ato_driving_state             = ato_output.ato_driving_state;
    mt_inputs.uto_mode_active               = ato_output.uto_mode_active;
    mt_inputs.ros_indicator                 = ato_output.ros_indicator;
    mt_inputs.localisation_state            = bm_output.current_localisation_state;
    mt_inputs.max_reverse_distance_exceeded = sdm_output.max_reverse_distance_exceeded;
    mt_inputs.driver_change_ends            = tdm_output.dmi_driver_event_change_ends;
    // Run the Movement Authority Module
    m_mode_transition_machine.RunCycle(time_step);

    // Set the updated CBTC OnBoard System outputs that need to be reported by the DMI
    auto& mt_outputs = m_mode_transition_machine.GetOutputs();

    Y().current_driving_mode    = mt_outputs.current_driving_mode;
    Y().available_driving_modes = mt_outputs.available_driving_modes;
    Y().atc_bypass_state        = mt_outputs.atc_bypass_state;
}

/// Execute the Run Cycle of the Speed And Distance Monitoring Module
///
/// @param time_step Time at which the function was run
///
void OnBoardController::ProcessSpeedAndDistanceMonitoringModule(double time_step)
{
    auto& sdm_inputs = m_speed_and_distance_monitoring.GetInputs();

    // Set the inputs which are populated using Train data
    sdm_inputs.current_train_position  = U().current_train_position;
    sdm_inputs.current_train_speed     = U().current_train_speed;

    sdm_inputs.dmi_driver_event_change_ends = Y().driver_event_change_ends;

    sdm_inputs.atc_sb_reset_button     = (U().atc_sb_reset_button == Project::TypeValue::ButtonState::PRESSED && 
                                        false == static_cast<bool>(U().atc_eb_unable_to_reset));

    sdm_inputs.train_front_in_platform = (U().train_near_platform != Project::TypeValue::PlatformRegion::OUTSIDE_REGION);
    sdm_inputs.train_near_platform     = U().train_near_platform;

    sdm_inputs.cbtc_current_mode = X().cbtc_current_mode;
    sdm_inputs.mode_selector_position = U().mode_selector_position;
    sdm_inputs.psd_door_status        = U().psd_door_status;
    // Set the inputs that need to be populated
    auto& ato_outputs = m_automatic_train_operation.GetOutputs();
    auto& atp_outputs = m_automatic_train_protection.GetOutputs();
    auto& bm_outputs  = m_beacon_management.GetOutputs();
    auto& tdm_outputs = m_trackside_data_management.GetOutputs();

    sdm_inputs.current_localisation_state = bm_outputs.current_localisation_state;
    sdm_inputs.emergency_brake_condition  = atp_outputs.emergency_brake_condition;
    sdm_inputs.service_brake_request      = atp_outputs.service_brake_request;

    sdm_inputs.speed_data_profile             = tdm_outputs.speed_data_profile;
    sdm_inputs.speed_profile_speed_limit      = tdm_outputs.speed_profile_speed_limit;
    sdm_inputs.path_gradient_profile          = tdm_outputs.path_gradient_profile;
    sdm_inputs.eoa_distance                   = tdm_outputs.eoa_distance;
    sdm_inputs.svl_distance                   = tdm_outputs.svl_distance;
    sdm_inputs.ma_shortened                   = tdm_outputs.ma_shortened;
    sdm_inputs.train_docking_status           = U().train_dock_status;
    sdm_inputs.stopping_point_distance        = tdm_outputs.stopping_distance;
    sdm_inputs.next_driver_event_skip_station = tdm_outputs.dmi_driver_event_skip_station;
    sdm_inputs.ato_active = (ato_outputs.ato_driving_state == Project::TypeValue::ATOState::AM_ATO_ENABLED ||
                             ato_outputs.uto_mode_active == Project::TypeValue::UTOState::AM_UTO_ENABLED);

    // Run the Speed and Distance Monitoring Module
    m_speed_and_distance_monitoring.RunCycle(time_step);

    // Set the Output Controller outputs
    auto& sdm_outputs = m_speed_and_distance_monitoring.GetOutputs();

    // Only report speed supervision related information when in ATP mode
    if ((X().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP || X().cbtc_current_mode == Project::TypeValue::CBTCMode::RMF ||
         X().cbtc_current_mode == Project::TypeValue::CBTCMode::RMR || X().cbtc_current_mode == Project::TypeValue::CBTCMode::ROS) &&
         U().train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED)
         //&& U().train_zero_speed_order == 0.0)  // Here also we can add fault condition to disable modification of target_speed
    {
        auto warning_status = Project::TypeValue::DMIWarningStatus::NORMAL;
        auto brake_status   = Project::TypeValue::SafetyBrakeState::INACTIVE;
        if (sdm_outputs.speed_status == Project::CBTCOnBoard::TypeValue::SpeedStatus::INDICATION)
            warning_status = Project::TypeValue::DMIWarningStatus::NORMAL;
        else if (sdm_outputs.speed_status == Project::CBTCOnBoard::TypeValue::SpeedStatus::WARNING)
        {
            warning_status = Project::TypeValue::DMIWarningStatus::WARNING;
            if (X().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP && atp_outputs.service_brake_request == Project::TypeValue::ServiceBrakeOrder::FULL_SB_DEMAND)
                brake_status = Project::TypeValue::SafetyBrakeState::FSB_ACTIVE;
        }
        else if (((sdm_outputs.speed_status == Project::CBTCOnBoard::TypeValue::SpeedStatus::INTERVENTION ||
                   sdm_outputs.speed_status == Project::CBTCOnBoard::TypeValue::SpeedStatus::OVER_SPEED) &&
                  X().cbtc_current_mode != Project::TypeValue::CBTCMode::ATP) ||
                 X().emergency_brake_trigger != Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED)
        {
            warning_status = Project::TypeValue::DMIWarningStatus::INTERVENTION;
            brake_status   = Project::TypeValue::SafetyBrakeState::ACTIVE;
        }
        else if (Y().safety_brake == Project::TypeValue::SafetyBrakeState::ACTIVE)
        {
            brake_status = Project::TypeValue::SafetyBrakeState::ACTIVE;
        }
        Y().warning_status       = warning_status;
        Y().cbtc_target_speed    = sdm_outputs.cbtc_target_speed;

        if (U().train_zero_speed_order == Project::TypeValue::IndicatorState::ON ||
            Y().localisation_status == Project::TypeValue::LocalisationStatus::NOT_LOCALISED ||
            (U().psd_door_status >= Project::TypeValue::PSDDoorStatus::PSD_OPENING &&
             U().psd_interlock_override_status == Project::TypeValue::IndicatorState::OFF))
        {
            Y().cbtc_target_speed = Project::CBTCOnBoard::INVALID_SPEED;
        }

        Y().cbtc_permitted_speed = sdm_outputs.cbtc_permitted_speed;
        Y().target_distance      = sdm_outputs.target_distance;
        Y().advisory_speed       = sdm_outputs.advisory_speed;
        Y().warning_speed        = sdm_outputs.warning_speed;
        Y().safety_brake         = brake_status;
    }
    else
    {
        Y().warning_status       = Project::TypeValue::DMIWarningStatus::NORMAL;
        Y().cbtc_target_speed    = Project::CBTCOnBoard::INVALID_SPEED;
        Y().cbtc_permitted_speed = Project::CBTCOnBoard::INVALID_SPEED;
        if (U().mode_selector_position == Project::TypeValue::ModeSelector::ATO &&
            U().train_zero_speed_order != Project::TypeValue::IndicatorState::ON) 
        {
            Y().cbtc_target_speed = sdm_outputs.cbtc_target_speed;
            Y().cbtc_permitted_speed = sdm_outputs.cbtc_permitted_speed;
        }

        if (U().psd_door_status >= Project::TypeValue::PSDDoorStatus::PSD_OPENING)
        {
            Y().cbtc_target_speed = Project::CBTCOnBoard::INVALID_SPEED;
            Y().cbtc_permitted_speed = Project::CBTCOnBoard::INVALID_SPEED;
        }

        Y().target_distance      = Project::CBTCOnBoard::INVALID_DISTANCE;
        Y().advisory_speed       = Project::CBTCOnBoard::INVALID_SPEED;
        Y().warning_speed        = Project::CBTCOnBoard::INVALID_SPEED;
    }

    //If ADCL not availale fault is ON && Driver operate interlock switch
    // then make cbtc_target_speed available
    if (1.0 == U().psd_adcl_not_available_fault &&
        U().psd_interlock_override_status == Project::TypeValue::IndicatorState::ON)
    {
        Y().cbtc_target_speed = sdm_outputs.cbtc_target_speed;
        Y().cbtc_permitted_speed = sdm_outputs.cbtc_permitted_speed;
    }    

    Y().zero_speed = sdm_outputs.zero_speed;

    // Note that permitted distance and speed will be zero when ATO is not enabled
    Y().ato_permitted_distance = sdm_outputs.ato_permitted_distance;
    Y().ato_permitted_speed    = sdm_outputs.ato_permitted_speed;

    //MMRBEM-4141: PSD bypassed fault - Target speed to 7 kmph i.e. 1.944 m/s
    if (1.0 == U().psd_bypassed_fault && U().train_near_platform != Project::TypeValue::PlatformRegion::OUTSIDE_REGION)
    {
        //Here, ovirriding target speed coming SDM module.
        //To dock exact at NSP, we compare target speed coming from SDM. If > 7kmph, then use traget speed coming from SDM otherwise 7kmph
        //If we don't check the following conditions, then train is long docked
        if (sdm_outputs.cbtc_target_speed > PSD_BYPASSED_MAX_SPEED_ALLOWED)
        {
            Y().cbtc_target_speed = PSD_BYPASSED_MAX_SPEED_ALLOWED;
            Y().cbtc_permitted_speed = PSD_BYPASSED_MAX_SPEED_ALLOWED;
            Y().ato_permitted_speed = PSD_BYPASSED_MAX_SPEED_ALLOWED;
        }
        else
        {
            Y().cbtc_target_speed = sdm_outputs.cbtc_target_speed;
            Y().cbtc_permitted_speed = sdm_outputs.cbtc_permitted_speed;
            Y().ato_permitted_speed = sdm_outputs.ato_permitted_speed;
        }
    }
}

/// Execute the Run Cycle of the Automatic Train Operation Module
///
/// @param time_step Time at which the function was run
///
void OnBoardController::ProcessAutomaticTrainOperationModule(double time_step)
{
    auto& ato_inputs = m_automatic_train_operation.GetInputs();

    // Set the inputs used for automatic train operation
    ato_inputs.current_train_position = U().current_train_position;
    ato_inputs.current_train_speed    = U().current_train_speed;
    ato_inputs.driver_mode_selection  = U().driver_mode_selection;
    ato_inputs.cbtc_current_mode      = X().cbtc_current_mode;
    ato_inputs.cabin_activation       = U().cabin_activation;
    ato_inputs.mode_selector_position = U().mode_selector_position;
    ato_inputs.lhs_platform_detection = U().lhs_platform_detection;
    ato_inputs.rhs_platform_detection = U().rhs_platform_detection;
    ato_inputs.platform_status        = U().platform_status;
    ato_inputs.train_door_closed = U().train_door_closed_and_locked; //MMRBEM-4447 To pass train door status to ATO module
    ato_inputs.train_door_closed_and_locked = ((U().train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED) ||
                                               (U().no_door_enable_bypass == Project::TypeValue::NoDoorInterlockBypass::BYPASS_ENABLED) ||
                                               (U().atc_bypass_state == Project::TypeValue::ATCBypassState::BYPASS_ENABLED));
    // ato_inputs.in_automatic_region    = U().in_automatic_region;
    ato_inputs.ato_start_button                    = U().ato_start_button;
    ato_inputs.uto_start_button                    = U().uto_start_button;
    ato_inputs.tbc_position                        = U().tbc_position;
    ato_inputs.wake_up_status                      = U().wake_up_status;
    ato_inputs.train_doors_not_opening_in_ato_mode = U().train_doors_not_opening_in_ato;
    ato_inputs.psd_doors_not_opening_fault_flag   = (0.0 ==  U().psd_door_not_opening) ? false : true;
    auto& tdm_outputs                              = m_trackside_data_management.GetOutputs();
    auto& sdm_outputs                              = m_speed_and_distance_monitoring.GetOutputs();
    auto& bm_outputs                               = m_beacon_management.GetOutputs();

    ato_inputs.eoa_distance            = tdm_outputs.eoa_distance;
    ato_inputs.stopping_point_distance = tdm_outputs.stopping_distance;
    ato_inputs.zero_speed              = sdm_outputs.zero_speed;
    ato_inputs.localisation_state      = bm_outputs.current_localisation_state;
    ato_inputs.emergency_brake_pressed = U().emergency_brake_pb;
    ato_inputs.emergency_stop_pressed = U().emergency_stop_pb;

    // Run the Automatic Train Operation Module
    m_automatic_train_operation.RunCycle(time_step);

    // Set the outputs populated by the Automatic Train Operation Module
    auto& ato_outputs = m_automatic_train_operation.GetOutputs();

    Y().ato_start_indicator          = ato_outputs.ato_start_indicator;
    Y().uto_pb_indicator             = ato_outputs.uto_pb_indicator;
    Y().traction_forward             = ato_outputs.traction_forward;
    Y().uto_mode_active              = ato_outputs.uto_mode_active;
    Y().ato_state                    = ato_outputs.ato_driving_state || ato_outputs.uto_mode_active;
    Y().ros_indicator                = ato_outputs.ros_indicator;
    Y().left_side_door_enable        = ato_outputs.left_side_door_enable;
    Y().right_side_door_enable       = ato_outputs.right_side_door_enable;
    Y().left_door_open_indicator     = ato_outputs.left_door_open_indicator;
    Y().left_door_release_indicator  = ato_outputs.left_door_release_indicator;
    Y().left_hold_door_close         = ato_outputs.left_hold_door_close;
    Y().right_hold_door_close        = ato_outputs.right_hold_door_close;
    Y().open_left_train_doors        = ato_outputs.open_left_doors;
    Y().right_door_open_indicator    = ato_outputs.right_door_open_indicator;
    Y().right_door_release_indicator = ato_outputs.right_door_release_indicator;
    Y().open_right_train_doors       = ato_outputs.open_right_doors;
}

/// Execute the Run Cycle of the Automatic Train Protection Module
///
/// @param time_step Time at which the function was run
///
void OnBoardController::ProcessAutomaticTrainProtectionModule(double time_step)
{
    auto& atp_inputs = m_automatic_train_protection.GetInputs();
    auto& tdm_outputs = m_trackside_data_management.GetOutputs();

    // Set the inputs which are populated using Train data
    atp_inputs.current_train_position = U().current_train_position;
    atp_inputs.stopping_point_distance = tdm_outputs.stopping_distance;

    atp_inputs.current_train_speed    = std::abs(U().current_train_speed);
    atp_inputs.cabin_activation       = U().cabin_activation;
    atp_inputs.reset_safety_brake     = (U().atc_sb_reset_button == Project::TypeValue::ButtonState::PRESSED &&
                                     false == static_cast<bool>(U().atc_eb_unable_to_reset));
    atp_inputs.doors_closed_and_locked = ((U().train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED) ||
                                          (U().no_door_enable_bypass == Project::TypeValue::NoDoorInterlockBypass::BYPASS_ENABLED) ||
                                          (U().atc_bypass_state == Project::TypeValue::ATCBypassState::BYPASS_ENABLED));
    atp_inputs.psd_door_close_status         = U().psd_door_status;
    atp_inputs.psd_interlock_override_status = U().psd_interlock_override_status;
    atp_inputs.train_held_at_station         = (U().platform_status == Project::TypeValue::PlatformStatus::HOLD);
    atp_inputs.master_brake_controller       = U().master_brake_controller;

    atp_inputs.train_near_station = (U().train_near_platform == Project::TypeValue::PlatformRegion::ENTERING_REGION);
    atp_inputs.cbtc_current_mode  = X().cbtc_current_mode;
    atp_inputs.tcms_speed_limit   = U().tcms_speed_limit;
    atp_inputs.tcms_speed_limit_cause = U().tcms_speed_limit_cause;
    atp_inputs.mode_selector_position = X().mode_selector_position;
    atp_inputs.active_call_type       = U().active_call_type;
    atp_inputs.pabr_bypass_req        = U().pabr_bypass_req;
    atp_inputs.call_status            = U().call_status;
    // Set the inputs that are populated using data from other Modules
    auto& sdm_outputs = m_speed_and_distance_monitoring.GetOutputs();
    auto& bm_outputs  = m_beacon_management.GetOutputs();

    atp_inputs.current_localisation_state    = bm_outputs.current_localisation_state;
    atp_inputs.speed_monitoring_active       = sdm_outputs.speed_monitoring_active;
    atp_inputs.monitoring_mode               = sdm_outputs.monitoring_mode;
    atp_inputs.eb_intervention_velocity      = sdm_outputs.eb_intervention_velocity;
    atp_inputs.sb_intervention_velocity      = sdm_outputs.sb_intervention_velocity;
    atp_inputs.warning_velocity              = sdm_outputs.warning_velocity;
    atp_inputs.warning_speed                 = sdm_outputs.warning_speed;
    atp_inputs.advisory_speed                = sdm_outputs.advisory_speed;
    atp_inputs.permitted_velocity            = sdm_outputs.cbtc_permitted_speed;
    atp_inputs.max_reverse_distance_exceeded = sdm_outputs.max_reverse_distance_exceeded;
    atp_inputs.movement_authority_exceeded   = sdm_outputs.movement_authority_exceeded;
    atp_inputs.train_at_standstill = (sdm_outputs.zero_speed == Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN);
    atp_inputs.radio_communication_state = X().radio_communication_status;
    atp_inputs.platform_status           = U().platform_status;
    atp_inputs.train_docking_status      = U().train_dock_status;
    // Run the Automatic Train Protection Module
    m_automatic_train_protection.RunCycle(time_step);

    auto& atp_outputs = m_automatic_train_protection.GetOutputs();

    // Set the Automatic Train Protection outputs to the train model
    Y().emergency_brake_request = atp_outputs.emergency_brake_request;
    Y().service_brake_request   = atp_outputs.service_brake_request;
    if (U().train_zero_speed_order == Project::TypeValue::IndicatorState::ON || (U().psd_door_status >= Project::TypeValue::PSDDoorStatus::PSD_OPENING &&
             U().psd_interlock_override_status == Project::TypeValue::IndicatorState::OFF))
        Y().immobilisation_state = Project::TypeValue::ImmobilisationState::IMMOBILSED;
    else
        Y().immobilisation_state = atp_outputs.immobilisation_state;

    if (U().departure_order_status == Project::TypeValue::DepartureOrder::CLOSE_DOORS_ORDER)
    {
        if (Y().left_side_door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED)
            Y().left_door_close_indicator = Project::TypeValue::IndicatorState::ON;

        if (Y().right_side_door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED)
            Y().right_door_close_indicator = Project::TypeValue::IndicatorState::ON;
    }
    else
    {
        Y().left_door_close_indicator = Project::TypeValue::IndicatorState::OFF;
        Y().right_door_close_indicator = Project::TypeValue::IndicatorState::OFF;
    }

    if (atp_outputs.request_safety_brake_reset)
        Y().atc_safety_brake_reset_indicator = Project::TypeValue::IndicatorState::ON;
    else
        Y().atc_safety_brake_reset_indicator = Project::TypeValue::IndicatorState::OFF;

    if (atp_outputs.emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::ROLLWAY)
        Y().rollback_detected = Project::TypeValue::IndicatorState::ON;
    else
        Y().rollback_detected = Project::TypeValue::IndicatorState::OFF;
    // Useful debug information
    if (DEBUG)
    {
        Trace::GetLogger().STAMP(Trace::WARN)
          << atp_outputs.emergency_brake_request << " "
          << "emergency_brake_condition : " << static_cast<int>(atp_outputs.emergency_brake_condition)
          << " Request EB reset: " << atp_outputs.request_safety_brake_reset << Trace::EndLog();
    }
}

/// Execute the Run Cycle of the Text Management Module
///
/// @param time_step Time at which the function was run
///
void OnBoardController::ProcessTextManagementModule(double time_step)
{
    auto& tm_inputs = m_text_management.GetInputs();

    // Set the inputs that are populated using data from other Module
    auto& atp_outputs = m_automatic_train_protection.GetOutputs();
    auto& tdm_outputs = m_trackside_data_management.GetOutputs();
    auto& ato_outputs = m_automatic_train_operation.GetOutputs();

    tm_inputs.cabin_activation    = U().cabin_activation;
    tm_inputs.ack_text_message_id = U().cbtc_message_acknowledge;

    tm_inputs.cbtc_current_mode = X().cbtc_current_mode;

    tm_inputs.emergency_brake_condition = atp_outputs.emergency_brake_condition;
    tm_inputs.emergency_brake_ordered   = (atp_outputs.emergency_brake_request ==
                                         Project::TypeValue::EmergencyBrakeOrder::EMERGENCY_BRAKE_DEMAND);
    tm_inputs.safety_brake_state        = Y().safety_brake;
    tm_inputs.selected_driving_mode     = U().driver_mode_selection;
    tm_inputs.current_train_speed       = U().current_train_speed;
    // tm_inputs.mode_selector_position    = U().mode_selector_position;
    tm_inputs.start_up_test_stage = X().start_up_test_stage;
    tm_inputs.train_docking_status      = U().train_dock_status;
    tm_inputs.transition_into_automatic = tdm_outputs.transition_into_automatic;
    tm_inputs.ato_is_available          = ato_outputs.ato_is_available;

    // Run the text management Module
    m_text_management.RunCycle(time_step);

    const auto& tm_outputs = m_text_management.GetOutputs();

    X().new_high_priority_msg_reported = tm_outputs.new_high_priority_msg_reported;
    X().new_acknowledge_msg_reported   = tm_outputs.new_acknowledge_msg_reported;

    // Set the outputs populated by the Text Management module
    Y().text_messages = tm_outputs.cbtc_text_messages;

    if (DEBUG)
    {
        Trace::GetLogger().STAMP(Trace::WARN) << "Text message ID (" << Y().text_messages.cbtctextmessage().size() << ") : "
                                              << ((Y().text_messages.cbtctextmessage().size() > 0)
                                                    ? static_cast<int>(Y().text_messages.cbtctextmessage().begin()->id())
                                                    : -100)
                                              << "  " << static_cast<int>(X().start_up_test_stage) << " "
                                              << X().power_up_test_completed << "  " << X().power_up_test_start_time << " "
                                              << U().power_supply << "  " << U().driver_mode_selection << Trace::EndLog();
    }
}

/// Execute the Run Cycle of the Trackside Data Management Module
///
/// @param time_step Time at which the function was run
///
void OnBoardController::ProcessTrackSideDataManagementModule(double time_step)
{
    auto& tdm_inputs = m_trackside_data_management.GetInputs();

    // Set the inputs that are populated using data from other Module
    auto& ato_outputs = m_automatic_train_operation.GetOutputs();
    auto& sdm_outputs = m_speed_and_distance_monitoring.GetOutputs();

    tdm_inputs.ato_position_error      = U().ato_position_error;
    tdm_inputs.current_train_position  = U().current_train_position;
    tdm_inputs.current_train_speed     = U().current_train_speed;
    tdm_inputs.track_event_data        = U().track_event_data;
    tdm_inputs.movement_authority_data = U().movement_authority;
    tdm_inputs.gradient_profile_data   = U().gradient_discontinuities;
    tdm_inputs.speed_data_profile      = U().speed_limit_profile;
    tdm_inputs.train_front_near_platform = (U().train_near_platform != Project::TypeValue::PlatformRegion::OUTSIDE_REGION);
    tdm_inputs.train_door_closed_and_locked = U().train_door_closed_and_locked;
    tdm_inputs.no_door_enable_bypass        = U().no_door_enable_bypass;
    tdm_inputs.platform_status              = U().platform_status;
    tdm_inputs.radio_communication_state    = X().radio_communication_status;
    tdm_inputs.mode_selector_position       = U().mode_selector_position;
    tdm_inputs.cbtc_current_mode            = X().cbtc_current_mode;
    tdm_inputs.ato_is_available             = ato_outputs.ato_is_available;
    tdm_inputs.ros_is_available             = ato_outputs.ros_is_available;
    tdm_inputs.ato_driving_state            = ato_outputs.ato_driving_state;
    tdm_inputs.zero_speed                   = sdm_outputs.zero_speed;
    tdm_inputs.atp_zone_region              = U().atp_zone_region;

    // Run the trackside data management Module
    m_trackside_data_management.RunCycle(time_step);

    const auto& tdm_outputs = m_trackside_data_management.GetOutputs();

    // Set the outputs populated by the Trackside Data Management module
    Y().driver_event_skip_station = tdm_outputs.dmi_driver_event_skip_station;
    Y().driver_event_change_ends  = tdm_outputs.dmi_driver_event_change_ends;
    Y().driver_event_work_zone    = tdm_outputs.dmi_driver_event_work_zone;
}

/// Trigger the playing of the audio sounds
///
/// @param time_step Time at which the function was run
///
void OnBoardController::PlayAudio(double time_step)
{
    auto& sdm_outputs = m_speed_and_distance_monitoring.GetOutputs();
    auto& atp_outputs = m_automatic_train_protection.GetOutputs();

    // Trigger Warning alarm while the reported speed status is warning
    if (Y().warning_status == Project::TypeValue::DMIWarningStatus::WARNING)
        Y().audio_warning_alarm = Project::TypeValue::CBTCAudio::PLAY;
    else
        Y().audio_warning_alarm = Project::TypeValue::CBTCAudio::OFF;

    // Trigger EB alarm when the emergency brake is applied by OnBoard system
    if ((atp_outputs.emergency_brake_condition != X().emergency_brake_trigger) &&
        (atp_outputs.emergency_brake_condition != Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::NO_EB_REQUIRED))
    {
        Y().audio_safety_brake_alarm = Project::TypeValue::CBTCAudio::PLAY;
        X().s_info_start_time        = time_step;
    }

    // Trigger the Audio to alert the driver about a new Departure Order
    if ((X().platform_status != U().platform_status) && (U().platform_status == Project::TypeValue::PlatformStatus::READY_TO_DEPART))
    {
        Y().audio_departure_order = Project::TypeValue::CBTCAudio::PLAY;
        X().s_info_start_time     = time_step;
    }

    // Trigger the Audio to alert the driver about a new target speed
    if ((Y().target_distance > 0) && (U().current_train_speed >= sdm_outputs.cbtc_target_speed))
    {
        Y().audio_target_speed = Project::TypeValue::CBTCAudio::PLAY;
        X().s_info_start_time  = time_step;
    }

    // Clear the Departure Order / New Target Speed alert signals after the signal pulse time has expired
    if ((X().s_info_start_time + MOMENTARY_SIGNAL_DELAY) < time_step)
    {
        Y().audio_departure_order    = Project::TypeValue::CBTCAudio::OFF;
        Y().audio_target_speed       = Project::TypeValue::CBTCAudio::OFF;
        Y().audio_safety_brake_alarm = Project::TypeValue::CBTCAudio::OFF;
    }

    // Trigger the Audio to alert the driver about a High priority text message
    if (X().new_high_priority_msg_reported)
    {
        Y().audio_high_priority_text_alert = Project::TypeValue::CBTCAudio::PLAY;
        X().text_alert_audio_start_time    = time_step;
    }

    // Trigger the Audio to alert the driver about a text message that requires acknowldegement
    if (X().new_acknowledge_msg_reported)
    {
        Y().audio_acknowledge           = Project::TypeValue::CBTCAudio::PLAY;
        X().text_alert_audio_start_time = time_step;
    }

    // Clear the high priority / acknowledgement request text alert signals after the signal pulse time has expired
    if ((X().text_alert_audio_start_time + MOMENTARY_SIGNAL_DELAY) < time_step)
    {
        Y().audio_high_priority_text_alert = Project::TypeValue::CBTCAudio::OFF;
        Y().audio_acknowledge              = Project::TypeValue::CBTCAudio::OFF;
    }
}

/// Determines the ATC status of onboard system
///
void OnBoardController::DetermineOnboardStatus()
{
    // ATC Onboard is always in a healty state
    X().atc_status = Project::TypeValue::ATCStatus::HEALTHY;

    //Check ATC failure fault active
    if (1.0 == U().failure_of_trainborne_atc_equipment)
        X().atc_status = Project::TypeValue::ATCStatus::DEGRADED;
    else
        X().atc_status = Project::TypeValue::ATCStatus::HEALTHY;

    Y().atc_status = X().atc_status;
}

/// Manages connection/disconnection to the Trackside Radio System
///
/// @param time_step Time at which the function was run
///
void OnBoardController::ManageRadioConnection(double time_step)
{
    if (X().radio_communication_status == Project::TypeValue::RadioCommsStatus::COMMS_NOT_ESTABLISHED)
    {
        // Radio connection is to be established after the cab is actived and train is localised
        if ((U().power_supply == Project::TypeValue::PowerSupply::POWER_ON) &&
            (U().cabin_activation == Project::TypeValue::CabinActivation::ACTIVE ||
             U().cab_activation == Project::TypeValue::CabinActivation::ACTIVE) &&
            (Y().localisation_status == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION ||
             Y().localisation_status == Project::TypeValue::LocalisationStatus::LOCALISED))
        {
            // If scenario needs the radio connection then connect immediately
            if (X().radio_setup_required)
                X().connection_start_time = time_step;

            // Start the timer used to simulate the time take for the radio connection to be established
            else if (X().connection_start_time == INVALID_TIME)
                X().connection_start_time = time_step + RADIO_CONNECTION_TIME;

            // Report the connection once the connection time has expired
            if (X().connection_start_time <= time_step || X().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO)
            {
                X().radio_communication_status = Project::TypeValue::RadioCommsStatus::COMMS_ESTABLISHED;
                X().connection_start_time      = INVALID_TIME;
            }
        }
    }

    // Handle the connection being disconnected when cab is powered off or deactivated
    else
    {
        if ((U().power_supply == Project::TypeValue::PowerSupply::NO_POWER) ||
            (U().cabin_activation == Project::TypeValue::CabinActivation::INACTIVE &&
             U().cab_activation == Project::TypeValue::CabinActivation::INACTIVE))
        {
            X().radio_communication_status = Project::TypeValue::RadioCommsStatus::COMMS_NOT_ESTABLISHED;
            X().connection_start_time      = INVALID_TIME;
        }
    }
    Y().radio_communication_status = X().radio_communication_status;
}

/// Performs actions required to occur during the pwerup of the CBTC system
///
/// @param time_step Time at which the function was run
///
void OnBoardController::PerformSystemPowerupTest(double time_step)
{
    // Nothing to do if test has been completed
    if (X().power_up_test_completed)
        return;

    // Perform combined test when the train is first powered on and cab is activated
    if ((U().power_supply == Project::TypeValue::PowerSupply::POWER_ON) &&
        (U().cabin_activation == Project::TypeValue::CabinActivation::ACTIVE))
    {
        // Start the power up test running
        if (!X().power_up_test_completed && (X().power_up_test_start_time == INVALID_TIME))
        {
            X().start_up_test_stage      = Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_STARTED;
            X().power_up_test_start_time = time_step;
        }
    }

    // TBD : Not sure if any actions needs to be done while CBTC is powering up

    // Report test succeeded when power up time has expired
    if ((X().power_up_test_start_time != INVALID_TIME) && (X().power_up_test_start_time + POWERUP_TEST_DURATION < time_step))
    {
        X().start_up_test_stage      = Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_SUCCESS;
        X().power_up_test_start_time = INVALID_TIME;
        X().power_up_test_completed  = true;
    }

    // Terminate the test if ATC is bypassed upon train powerup
    if (U().atc_bypass_state == Project::TypeValue::ATCBypassState::BYPASS_ENABLED)
    {
        X().start_up_test_stage      = Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_NOT_ACTIVE;
        X().power_up_test_start_time = INVALID_TIME;
        X().power_up_test_completed  = true;
    }
}

/// Perform the system initialisation required for when a new scenario is started
///
void OnBoardController::PerformCBTCOnboardSetup()
{
    if (X().scenario_initialisation_completed)
        return;

    // If auto power is on then we skip the system power up tests and determine if the setup required a connection
    // with the radio to be immediately established once the cab is activated
    if (U().auto_power_on == Project::CBTCOnBoard::TrainTypeValues::AutoPowerOn::AUTO_POWER_ON)
    {
        X().start_up_test_stage      = Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_SUCCESS;
        X().power_up_test_start_time = INVALID_TIME;
        X().power_up_test_completed  = true;

        // In case where the train is localised and there are no comms errors, the radio connection must be
        // established before flagging that the scenario initialisation was completed
        // Otherwise no radio setup is required as part of the onboard setup
        if (((Y().localisation_status == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION) ||
             (Y().localisation_status == Project::TypeValue::LocalisationStatus::LOCALISED)) &&
            (U().atc_loss_of_comms_error == Project::CBTCOnBoard::TrainTypeValues::CommsStatus::COMMS_OK))
        {
            X().radio_setup_required = true;
        }
    }

    // Setup is considered complete if cab activated and
    // - No radio connection is required
    // - Required radio connection has been established
    if ((U().cabin_activation == Project::TypeValue::CabinActivation::ACTIVE ||
         U().cab_activation == Project::TypeValue::CabinActivation::ACTIVE) &&
        (!X().radio_setup_required || (X().radio_communication_status == Project::TypeValue::RadioCommsStatus::COMMS_ESTABLISHED)))
        X().scenario_initialisation_completed = true;
}
