///
/// @file       AutomaticTrainOperationModule.cpp
///
///             Module that handles the functionality related to the Automatic Train Operation function of the CBTC
///             OnBoard System.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///             Amol Ganbavale
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#include "AutomaticTrainOperationModule.h"

#include "common/StandardLogging.h"

#include <algorithm>
#include <chrono>

using namespace Project::CBTCOnBoard;

/// Constructor, which just initializes the members appropriately
///
/// @param init Initialisation data for the module
///
AutomaticTrainOperationModule::AutomaticTrainOperationModule(const Initialisation& init)
  : CBTCModule<AutomaticTrainOperationModule, AutomaticTrainOperationModuleIO>(init)
{
    // Initialise state data, if required
}

/// The Module function which, given the current inputs, adjusts the internal state and
/// populates the outputs.
///
/// @param time_step Current simulator time step
///
void AutomaticTrainOperationModule::Step(double time_step)
{
    ManageTrainDoorOperation(time_step);
    SetATOStartIndicator(time_step);
    SetATODrivingState();
    SetROSStartIndicator(time_step);
    SetUTOStartIndicator(time_step);
    SetUTODrivingState();
}

/// Performs the actions required to manage operation of the train doors at a station
///
/// @param time_step Current simulator time step
///
void AutomaticTrainOperationModule::ManageTrainDoorOperation(double time_step)
{
    // Holding doors closed avoid passengers to get off the train at wrong side or wrong moment
    // In ATP/ATO/UTO modes the control of the doors and door indicators needs to be managed by the CBTC Onboard
    if ((U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATP) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATO) ||
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO) ||
        (U().mode_selector_position == Project::TypeValue::ModeSelector::ATO && Y().ato_is_available ))
    {
        // Train is docked at a station then we enable the train doors
        if ((U().platform_status == Project::TypeValue::PlatformStatus::DOCKED) ||
            (U().platform_status == Project::TypeValue::PlatformStatus::READY_TO_DEPART) ||
            (U().platform_status == Project::TypeValue::PlatformStatus::HOLD))
        {
            X().door_enable = Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED;
            if (U().lhs_platform_detection == Project::TypeValue::PlatformDetection::PLATFORM_DETECTED)
                Y().left_hold_door_close = Project::TypeValue::IndicatorState::OFF;
            else if (U().rhs_platform_detection == Project::TypeValue::PlatformDetection::PLATFORM_DETECTED)
                Y().right_hold_door_close = Project::TypeValue::IndicatorState::OFF;
        }
        else
        {
            X().door_enable           = Project::TypeValue::CorrectSideDoorEnable::SIDE_DISABLED;
            Y().left_hold_door_close  = Project::TypeValue::IndicatorState::ON;
            Y().right_hold_door_close = Project::TypeValue::IndicatorState::ON;
            X().pulse_start_time      = UNDEFINED_TIME_STAMP;
        }

        // Once train doors are enabled it will be possible for the doors to open
        if (X().door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED)
        {
            // Automatically open train doors when
            // - Door mode switch indicates doors to be opened automatically in ATO and UTO mode
            // - Train has just arrived at the station. train_doors_not_opening_in_ato_mode(fault for door opening in ATO mode)
            if (((U().mode_selector_position == Project::TypeValue::ModeSelector::ATO) ||
                 (U().cbtc_current_mode == Project::TypeValue::CBTCMode::UTO)) &&
                (U().platform_status == Project::TypeValue::PlatformStatus::DOCKED || U().platform_status == Project::TypeValue::PlatformStatus::HOLD) && 
                false == U().train_doors_not_opening_in_ato_mode &&
                false == U().psd_doors_not_opening_fault_flag)
            {
                // Pulse the open train door signal to open the train doors
                if (X().pulse_start_time == UNDEFINED_TIME_STAMP)
                {
                    X().auto_door_open_request = Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED;
                    X().pulse_start_time       = time_step;
                }
            }

            // Otherwise if the doors aren't open then we need to notify the driver that they can open the train doors
            else if (U().train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED)
            {
                // Train doors can only be released when train is not in the underground region
                X().door_release_indicator = Project::TypeValue::IndicatorState::ON;
                X().door_open_indicator    = Project::TypeValue::IndicatorState::ON;
            }

            else
            {
                X().door_release_indicator = Project::TypeValue::IndicatorState::OFF;
                X().door_open_indicator    = Project::TypeValue::IndicatorState::OFF;
            }

            // Turn off the pulsed signal once the pulse time expires
            if ((X().pulse_start_time + PULSE_SIGNAL_DURATION) < time_step)
                X().auto_door_open_request = Project::TypeValue::OpenDoorRequest::NO_OPEN_DOOR_REQUEST;
            }
        else
        {
            X().auto_door_open_request = Project::TypeValue::OpenDoorRequest::NO_OPEN_DOOR_REQUEST;
            X().door_release_indicator = Project::TypeValue::IndicatorState::OFF;
            X().door_open_indicator    = Project::TypeValue::IndicatorState::OFF;
        }
    }
    else
    {
        X().auto_door_open_request = Project::TypeValue::OpenDoorRequest::NO_OPEN_DOOR_REQUEST;
        X().door_release_indicator = Project::TypeValue::IndicatorState::OFF;
        X().door_open_indicator    = Project::TypeValue::IndicatorState::OFF;
        X().door_enable            = Project::TypeValue::CorrectSideDoorEnable::SIDE_DISABLED;
    }

    // Set the outputs associated with LHS train doors
    if (U().lhs_platform_detection == Project::TypeValue::PlatformDetection::PLATFORM_DETECTED)
    {
        Y().left_side_door_enable       = X().door_enable;
        Y().left_door_release_indicator = X().door_release_indicator;
        Y().left_door_open_indicator    = X().door_open_indicator;
        Y().open_left_doors             = X().auto_door_open_request;
    }
    else
    {
        Y().left_side_door_enable       = Project::TypeValue::CorrectSideDoorEnable::SIDE_DISABLED;
        Y().left_door_release_indicator = Project::TypeValue::IndicatorState::OFF;
        Y().left_door_open_indicator    = Project::TypeValue::IndicatorState::OFF;
        Y().open_left_doors             = Project::TypeValue::OpenDoorRequest::NO_OPEN_DOOR_REQUEST;
    }

    // Set the outputs associated with RHS train doors
    if (U().rhs_platform_detection == Project::TypeValue::PlatformDetection::PLATFORM_DETECTED)
    {
        Y().right_side_door_enable       = X().door_enable;
        Y().right_door_release_indicator = X().door_release_indicator;
        Y().right_door_open_indicator    = X().door_open_indicator;
        Y().open_right_doors             = X().auto_door_open_request;
    }
    else
    {
        Y().right_side_door_enable       = Project::TypeValue::CorrectSideDoorEnable::SIDE_DISABLED;
        Y().right_door_release_indicator = Project::TypeValue::IndicatorState::OFF;
        Y().right_door_open_indicator    = Project::TypeValue::IndicatorState::OFF;
        Y().open_right_doors             = Project::TypeValue::OpenDoorRequest::NO_OPEN_DOOR_REQUEST;
    }
}

/// Sets the start ROS driving indicator state
///
/// @param time_step Current simulator time step
///
void AutomaticTrainOperationModule::SetROSStartIndicator(double time_step)
{
    // ROS indicator should flash in the case where Localisation is inactive/unavailable and train is standstill
    if ((U().localisation_state == Project::TypeValue::LocalisationStatus::NOT_LOCALISED ||
         U().localisation_state == Project::TypeValue::LocalisationStatus::UNAVAILABLE) &&
        (U().zero_speed == Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN) &&
        U().mode_selector_position == Project::TypeValue::ModeSelector::ATP)
    {
        Y().ros_indicator = Project::TypeValue::IndicatorState::ON;
    }

    // ROS indicator will be disabled once localisation is available.
    else if (U().localisation_state == Project::TypeValue::LocalisationStatus::LOCALISED ||
             U().localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION ||
             U().mode_selector_position != Project::TypeValue::ModeSelector::ATP)
    {
        Y().ros_indicator = Project::TypeValue::IndicatorState::OFF;
    }
}

/// Determines and sets the ATO driving state
///
void AutomaticTrainOperationModule::SetATODrivingState()
{
    // If inside Automatic region, train is localised and a ATO mode is selected. ATO may
    // be available if TBC position is on FULLSB. ATO can be also available for ATO mode once mode selector is in UTO
    // mode.
    // cab is inactive and ATO indicator is on
    if ((U().localisation_state == Project::TypeValue::LocalisationStatus::LOCALISED ||
         U().localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION) &&
        ((U().mode_selector_position == Project::TypeValue::ModeSelector::ATO) ||
         (U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATB &&
          U().cabin_activation == Project::TypeValue::CabinActivation::INACTIVE)))
    {
        // ATO available if
        // - train is not docked or being held at a station
        // - train doors are closed then ATO driving is available for selection
        // - train is not in transition area or ATO has already been activated (and so should remains actived)
        // - movement authority available
        if ((U().tbc_position == Project::TypeValue::TBCPosition::FULL_SB) && (U().eoa_distance > -2.0)
            && (!U().emergency_brake_pressed) && (!U().emergency_stop_pressed))
        {
            X().ato_is_available = true;
        }
        else
            X().ato_is_available = false;
    }
    else
        X().ato_is_available = false;

    // If train is required to depart immediately we need to disable the ATO first before doing any other
    // checks. If this is not done the train ATO will kick in immediately after the train docks.
    // Need to disable ATO first so that the driver is forced to press the start button in order for the
    // train to leave the station
    if (U().platform_status == Project::TypeValue::PlatformStatus::IMMEDIATE_DEPARTURE ||
        U().platform_status == Project::TypeValue::PlatformStatus::READY_TO_DEPART)
        X().ato_driving_state = Project ::TypeValue::ATOState::AM_ATO_DISABLED;

    // Report driving state as ATO enabled if the ATO start button is pressed while ATO driving is available.
    // Once enabled, continue reporting ATO enabled until ATO becomes unavailable
    if (X().ato_is_available && ((U().ato_start_button == Project::TypeValue::ButtonState::PRESSED) ||
                                 (X().ato_driving_state == Project ::TypeValue::ATOState::AM_ATO_ENABLED)))
    {
        // added below logic for 3 seconds long press on ATO PB
        auto current_time = std::chrono::steady_clock::now();
        if (ato_driving_three_sec_timer == std::chrono::steady_clock::time_point::max())
            ato_driving_three_sec_timer = current_time + std::chrono::seconds(3);
        if (ato_driving_three_sec_timer <= current_time)
            X().ato_driving_state = Project::TypeValue::ATOState::AM_ATO_ENABLED;
    }

    // Report driving state as ATO disabled if ATO driving becomes unavailable while in AM mode or ATO in MMRBEM
    // ie. This can happen when the train docks at a station and is waiting for dwell time to expire
    else if ((U().mode_selector_position == Project::TypeValue::ModeSelector::ATO) &&
             (!X().ato_is_available || (U().platform_status == Project::TypeValue::PlatformStatus::IMMEDIATE_DEPARTURE ||
                                        U().platform_status == Project::TypeValue::PlatformStatus::READY_TO_DEPART)))
    {
        X().ato_driving_state = Project ::TypeValue::ATOState::AM_ATO_DISABLED;
    }

    // Report driving state not in AM mode when train is not in AM mode
    else
    {
        X().ato_driving_state = Project ::TypeValue::ATOState::NOT_IN_AM;
    }

    // below condition is added to reset the 3 seconds timer of ATO PB
    if (U().ato_start_button == Project::TypeValue::ButtonState::UNPRESSED || U().stopping_point_distance <= 0.0)
        ato_driving_three_sec_timer = std::chrono::steady_clock::time_point::max();

    Y().ato_is_available  = X().ato_is_available;
    Y().ato_driving_state = X().ato_driving_state;
}

/// Determines and sets the UTO driving state
///
void AutomaticTrainOperationModule::SetUTOStartIndicator(double time_step)
{
    // If inside Automatic region, train is localised and a CBTC mode (CM/AM or ATP/ATO in MMRBEM) is selected ATO may
    // be available
    if ((U().localisation_state == Project::TypeValue::LocalisationStatus::LOCALISED ||
         U().localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION) &&
        (U().zero_speed == Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN))
    {
        // UTO available if
        // - train is not docked or being held at a station
        // - train doors are closed then UTO driving is available for selection
        // - train is not in transition area or UTO has already been activated (and so should remains actived)
        if (U().tbc_position == Project::TypeValue::TBCPosition::FULL_SB &&
            U().wake_up_status == Project::TypeValue::IndicatorState::ON &&
            U().cabin_activation == Project::TypeValue::IndicatorState::OFF &&
            U().mode_selector_position == Project::TypeValue::ModeSelector::OFF_UTO &&
            X().uto_mode_active == Project::TypeValue::UTOState::AM_UTO_DISABLED && 
            U().cbtc_current_mode != Project::TypeValue::CBTCMode::ATB)
        {
            Y().uto_pb_indicator = Project::TypeValue::IndicatorState::ON;
            X().uto_is_available = true;
        }
        else
        {
            Y().uto_pb_indicator = Project::TypeValue::IndicatorState::OFF;
            Y().traction_forward = Project::TypeValue::IndicatorState::OFF;
        }
    }
}
void AutomaticTrainOperationModule::SetUTODrivingState()
{
    // If train is required to depart immediately we need to disable the UTO first before doing any other
    // checks. If this is not done the train UTO will kick in immediately after the train docks.
    // Need to disable UTO first so that the driver is forced to press the start button in order for the
    // train to leave the station
    if (U().platform_status == Project::TypeValue::PlatformStatus::IMMEDIATE_DEPARTURE)
        X().uto_mode_active = Project::TypeValue::UTOState::AM_UTO_DISABLED;

    // Report driving state as ATO enabled if the ATO start button is pressed while ATO driving is available.
    // Once enabled, continue reporting ATO enabled until ATO becomes unavailable
    if (X().uto_is_available && U().driver_mode_selection == Project::TypeValue::DriverModeSelection::UTO)
    {
        X().uto_mode_active  = Project::TypeValue::UTOState::AM_UTO_ENABLED;
        Y().traction_forward = Project::TypeValue::IndicatorState::ON;
        Y().uto_pb_indicator = Project::TypeValue::IndicatorState::OFF;
    }

    // Report driving state as ATO disabled if ATO driving becomes unavailable while in AM mode or ATO in MMRBEM
    // ie. This can happen when the train docks at a station and is waiting for dwell time to expire
    else
    {
        X().uto_mode_active = Project ::TypeValue::UTOState::AM_UTO_DISABLED;
    }
    Y().uto_is_available = X().uto_is_available;
    Y().uto_mode_active  = X().uto_mode_active;
}
///
/// @param time_step Current simulator time step
///
void AutomaticTrainOperationModule::SetATOStartIndicator(double time_step)
{
    // ATO indicator should flash in the case where ATO is available and ato state not enabled
    if (X().ato_is_available && (X().ato_driving_state != Project::TypeValue::ATOState::AM_ATO_ENABLED))
    {
        // Flash the indicator if train is standstill, otherwise just turn it on
        if (U().zero_speed == Project::TypeValue::ZeroSpeedState::SPEED_BELOW_MIN)
        {             
            //MMRBEM-4447 - ATO indicator ON only if train doors are closed
            if (U().train_door_closed == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED)
                Y().ato_start_indicator = Project::TypeValue::IndicatorState::ON;                
            else
                Y().ato_start_indicator = Project::TypeValue::IndicatorState::OFF;
                        
            // added below logic to stop the ATO indicator from glowing when train is moving
            if (U().current_train_speed > 0.0 || U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATC_BYPASS)            
                Y().ato_start_indicator = Project::TypeValue::IndicatorState::OFF;                
            
        }
    }

    // Following covers the case where the train is leaving the automated region
    // In this case ATO will remain active if train in AM mode but will not be able to be activated if train in CM mode
    else if (!X().ato_is_available || X().ato_driving_state == Project::TypeValue::ATOState::AM_ATO_DISABLED)    
        Y().ato_start_indicator = Project::TypeValue::IndicatorState::OFF;        
    
    // Otherwise state of indicator is just determined by ATO availability
    else
    {
        //MMRBEM-4447 - ATO indicator OFF if train doors are open        
        if (U().train_door_closed == Project::TypeValue::TrainDoorInterlock::NO_INTERLOCK)        
            Y().ato_start_indicator = Project::TypeValue::IndicatorState::OFF;                    
        else        
            Y().ato_start_indicator = X().ato_is_available;            
        
        // added below logic to stop the ATO indicator from glowing when train is moving
        if (U().current_train_speed > 0.0)                    
            Y().ato_start_indicator = Project::TypeValue::IndicatorState::OFF;
        
    }
}
