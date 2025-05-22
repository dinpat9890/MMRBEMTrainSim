/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "JerkyDrivingInfractionRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
    constexpr auto rule_name{ "JRKYDRIV" };
    const double INFRACTION_TIMEOUT_SEC = 5.0;
    const double MIN_MOVING_SPEED = 0.1;
    namespace Parameters
    {
        constexpr auto penalty{ "JRKYDRIV_P" };
        constexpr auto limit_accl{ "LIMIT_ACCL" };
        constexpr auto limit_decl{ "LIMIT_DECL" };
    }
}

JerkyDrivingInfractionRule::JerkyDrivingInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, rule_name, scoring_parameters),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty)),
    m_limit_accleration(Scoring::GetPositiveParameter(scoring_parameters, Parameters::limit_accl)),
    m_limit_deceleration(Scoring::GetNegativeParameter(scoring_parameters, Parameters::limit_decl)),
    m_last_time_infraction_recorded(-INFRACTION_TIMEOUT_SEC),
    m_number_driver_mode_selection(0.0)
{
    Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DRIVER_MODE_SELECTION, &m_number_driver_mode_selection);

    // Lead car acceleration.
    Requires(
        SimPropertyWatcher::Group::TRAIN,
        Project::ValueName::Train::LLO_LEAD_LOCO_ACCELERATION,
        &m_last_known_acceleration,
        [this](const auto& value)
        {
        if (false == m_got_first_time_acceleration)
        {
            m_last_known_acceleration = value;
            m_last_known_time = GetCurrentTimePosition().time;
            m_got_first_time_acceleration = true;
        }
        else
        {            
            // Figure out the change in acceleration.
            const auto acceleration_delta{ value - m_last_known_acceleration };
            m_last_known_acceleration = value;

            // Determine how much time has elapsed.
            const auto now{ GetCurrentTimePosition().time };
            const auto elapsed_time{ now - m_last_known_time };
            m_last_known_time = now;

            // Calculate the rate of acceleration, but only if time has
            // actually elapsed (otherwise we'd get a divide by zero error).
            if (elapsed_time > 0)
            {                 
                const auto acceleration_rate{ acceleration_delta / elapsed_time };
                //Don't put jerky infraction if
                //a)CBTC EB applied
                //b)MCH position is at EB
                //c)Emergency stop button on op panel 5 is pressed.
                if ((acceleration_rate > m_limit_accleration ||
                    acceleration_rate < m_limit_deceleration) &&
                    (now - m_last_time_infraction_recorded) > INFRACTION_TIMEOUT_SEC &&
                    false == m_is_cbtc_emergency_break_active &&
                    !(-101 == m_master_contrl_handle_state) &&
                    !(0 == m_master_contrl_handle_state) &&
                    !(m_emergency_stop_button > 0.5))
                {             
                    if (m_number_driver_mode_selection != Project::TypeValue::DriverModeSelection::ATO)
                    {
                        RecordInfraction(m_penalty);
                        m_last_time_infraction_recorded = now;
                    }
                }
            }
        }
    });

    //Train speed
    Requires(
        SimPropertyWatcher::Group::TRAIN,
        Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
        &m_vehicle_speed,
        [this](const auto& value)
    {
        const auto train_has_stopped = abs(value) < MIN_MOVING_SPEED;
        if (train_has_stopped)
            m_got_first_time_acceleration = false;
        
    });

    //CBTC EB
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_INPUTS,
        Project::ValueName::CBTCVehicleInputs::NO_EMERGENCY_BRAKE_ORDER,
        nullptr,
        [this](const auto& value)
    {        
        //0 - Safety brake active
        //1 - No safety brake
        if (0.0 == value)
            m_is_cbtc_emergency_break_active = true;
        else
            m_is_cbtc_emergency_break_active = false;

    });

    //Master control handle - EB position
    Requires(
        SimPropertyWatcher::Group::VEHICLE_INPUTS,
        Project::ValueName::VehicleInputs::MASTER_CONTROLLER_HANDLE,
        &m_master_contrl_handle_state,
        [this](const auto& value)
    {
        m_master_contrl_handle_state = value;        
    });

    //Emergency stop button - Op. panel 5
    Requires(
        SimPropertyWatcher::Group::VEHICLE_INPUTS,
        Project::ValueName::VehicleInputs::EMERGENCY_STOP_PB,
        &m_emergency_stop_button,
        [this](const auto& value)
    {
        m_emergency_stop_button = value;        
    });

    assert(m_penalty >= 0);
    assert(m_limit_accleration > 0.0);
    assert(m_limit_deceleration < 0.0);
}