/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "DoorOpenedCmdHeldTooLongInfractionRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
    constexpr auto rule_name{ "DOPHLDL" };
    namespace Parameters
    {
        constexpr auto penalty{ "DOPHLDL_P" };
        constexpr auto max_press_time{ "MAX_PRS_TM" };
    }
}

DoorOpenedCmdHeldTooLongInfractionRule::DoorOpenedCmdHeldTooLongInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, rule_name, scoring_parameters),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty)),
    m_max_press_time(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::max_press_time)),
    m_number_door_mode(0.0),
    m_number_left_side_door_enable(0.0),
    m_number_right_side_door_enable(0.0),
    m_number_is_left_side_door_open_request(0.0),
    m_number_is_right_side_door_open_request(0.0),
    m_left_button_press_time_in_seconds(GetCurrentTimePosition()),
    m_left_button_release_time_in_seconds(GetCurrentTimePosition()),
    m_right_button_press_time_in_seconds(GetCurrentTimePosition()),
    m_right_button_release_time_in_seconds(GetCurrentTimePosition()),
    m_bool_is_left_side_door_open_request(false),
    m_bool_is_right_side_door_open_request(false)
{
    //Door mode
    Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DOOR_MODE, &m_number_door_mode);

    //Left door enable status
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_INPUTS,
        Project::ValueName::CBTCVehicleInputs::LEFT_SIDE_DOOR_ENABLE,
        &m_number_left_side_door_enable,
        [this](const auto& value)
        {
            m_number_left_side_door_enable = value;
        });

    //Right door enable status
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_INPUTS,
        Project::ValueName::CBTCVehicleInputs::RIGHT_SIDE_DOOR_ENABLE,
        &m_number_right_side_door_enable,
        [this](const auto& value)
        {
            m_number_right_side_door_enable = value;
        });

    //Left door open request.
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS,
        Project::ValueName::CBTCVehicleOutputs::LEFT_SIDE_DOOR_OPEN_REQUEST,
        &m_number_is_left_side_door_open_request,
        [this](const auto& value)
        {
            m_number_is_left_side_door_open_request = value;
            if (m_number_is_left_side_door_open_request < 0.5) //Check infraction when button is released.
            {
                m_left_button_release_time_in_seconds = GetCurrentTimePosition();
                CheckInfraction();

                //Reset after release button
                m_bool_is_left_side_door_open_request = false;

            }
            else //Pressed
            {
                m_bool_is_left_side_door_open_request = true;
                m_left_button_press_time_in_seconds = GetCurrentTimePosition();
            }
        });

    //Right door open request.
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS,
        Project::ValueName::CBTCVehicleOutputs::RIGHT_SIDE_DOOR_OPEN_REQUEST,
        &m_number_is_right_side_door_open_request,
        [this](const auto& value)
        {
            m_number_is_right_side_door_open_request = value;
            if (m_number_is_right_side_door_open_request < 0.5) //Check infraction when button is released.
            {
                m_right_button_release_time_in_seconds = GetCurrentTimePosition();
                CheckInfraction();

                //Reset after release button
                m_bool_is_right_side_door_open_request = false;
            }
            else //Pressed
            {
                m_bool_is_right_side_door_open_request = true;
                m_right_button_press_time_in_seconds = GetCurrentTimePosition();
            }
        });

    assert(m_penalty >= 0);
}

void DoorOpenedCmdHeldTooLongInfractionRule::CheckInfraction()
{
    const auto is_door_control_mode_manual{ Project::TypeValue::DoorMode::MANUAL == m_number_door_mode };
    if (is_door_control_mode_manual)
    {
        const auto is_left_door_enabled{ m_number_left_side_door_enable > 0.5 };
        const auto is_right_door_enabled{ m_number_right_side_door_enable > 0.5 };

        //Left door open
        if (is_left_door_enabled && m_bool_is_left_side_door_open_request)
        {
            auto left_button_press_time = m_left_button_release_time_in_seconds.time - m_left_button_press_time_in_seconds.time ;
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Left Button Press time : press_time : " << left_button_press_time << Trace::EndLog();
            if (left_button_press_time > m_max_press_time)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Left door open command held too long.. " << Trace::EndLog();
                RecordInfraction(m_penalty);
            }
        }

        //Right door open
        if (is_right_door_enabled && m_bool_is_right_side_door_open_request)
        {
            auto right_button_press_time = m_right_button_release_time_in_seconds.time - m_right_button_press_time_in_seconds.time ;
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Right Button Press time : press_time : " << right_button_press_time << Trace::EndLog();
            if (right_button_press_time > m_max_press_time)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Right door open command held too long. " << Trace::EndLog();
                RecordInfraction(m_penalty);
            }
        }
    }
}