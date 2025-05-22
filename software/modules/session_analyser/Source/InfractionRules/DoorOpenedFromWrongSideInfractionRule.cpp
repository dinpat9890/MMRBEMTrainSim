/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "DoorOpenedFromWrongSideInfractionRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
    constexpr auto rule_name{ "WRGDROP" };

    namespace Parameters
    {
        constexpr auto penalty{ "WRGDROP_P" };
    }
}

DoorOpenedFromWrongSideInfractionRule::DoorOpenedFromWrongSideInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, rule_name, scoring_parameters),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty)),
    m_number_door_mode(0.0),
    m_number_is_left_side_door_open_request(0.0),
    m_number_is_right_side_door_open_request(0.0),
    m_number_lhs_platform_detection(0.0),
    m_number_rhs_platform_detection(0.0)
{
    //Door mode
    Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DOOR_MODE, &m_number_door_mode);

    //Left door open request.
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS,
        Project::ValueName::CBTCVehicleOutputs::LEFT_SIDE_DOOR_OPEN_REQUEST,
        &m_number_is_left_side_door_open_request,
        [this](const auto& value)
        {
            m_number_is_left_side_door_open_request = value;
            if (m_number_is_left_side_door_open_request > 0.5)
                CheckInfraction();
        });

    //Right door open request.
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS,
        Project::ValueName::CBTCVehicleOutputs::RIGHT_SIDE_DOOR_OPEN_REQUEST,
        &m_number_is_right_side_door_open_request,
        [this](const auto& value)
        {
            m_number_is_right_side_door_open_request = value;
            if (m_number_is_right_side_door_open_request > 0.5)
                CheckInfraction();
        });

    //Left side platform detection
    Requires(
        SimPropertyWatcher::Group::CBTC_ONBOARD_INPUTS,
        Project::ValueName::CBTCOnboardInputs::LHS_PLATFORM_DETECTION,
        &m_number_lhs_platform_detection,
        [this](const auto& value)
        {
            m_number_lhs_platform_detection = value;
        });

    //Right side platform detection
    Requires(
        SimPropertyWatcher::Group::CBTC_ONBOARD_INPUTS,
        Project::ValueName::CBTCOnboardInputs::RHS_PLATFORM_DETECTION,
        &m_number_rhs_platform_detection,
        [this](const auto& value)
        {
            m_number_rhs_platform_detection = value;
        });

    assert(m_penalty >= 0);
}

void DoorOpenedFromWrongSideInfractionRule::CheckInfraction()
{
    //Door mode
    const auto is_door_control_mode_manual{ Project::TypeValue::DoorMode::MANUAL == m_number_door_mode };

    //check infraction. If (Platform is on LHS and doors opened on RHS OR Platform is on RHS and doors opened on LHS)
    if (is_door_control_mode_manual)
    {
        //As per comment in the task MMRBEM 2400 'There is some logic on Karlsruhe that might be able to be used to determine the platform side.'
        //If following platform detection logic will not work, then need to refere from
        //http://svn-adl/svn/KarlsruheTramSim/trunk/Software/SessionAnalyser/Source/InfractionRules/DoorsOpenWrongSideInfractionRule.cpp
        //Platform detection LHS/RHS
        const auto b_lhs_platform_detected{ m_number_lhs_platform_detection == Project::TypeValue::PlatformDetection::PLATFORM_DETECTED };
        const auto b_rhs_platform_detected{ m_number_rhs_platform_detection == Project::TypeValue::PlatformDetection::PLATFORM_DETECTED };

        //Disabling 1st condition as door enable cb is not hitting.
        //Door opening detection lhs/rhs
        const auto lhs_doors_opening{  m_number_is_left_side_door_open_request > 0.5 };
        const auto rhs_doors_opening{  m_number_is_right_side_door_open_request > 0.5 };

        if (b_rhs_platform_detected && lhs_doors_opening)
            RecordInfraction(m_penalty);

        if (b_lhs_platform_detected && rhs_doors_opening)
            RecordInfraction(m_penalty);
    }
}