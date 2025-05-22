/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "PantographOperatedInMotionInfractionRule.h"
#include "common/CommonExceptions.h"
#include "CreateCallback.h"
#include "fmt/format.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>
#include <cmath>

namespace
{
    constexpr auto rule_name{"PANTO"};

    namespace Parameters
    {
        constexpr auto penalty{"PTPNLTY"};
    }
}

PantographOperatedInMotionInfractionRule::PantographOperatedInMotionInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, rule_name, scoring_parameters),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty)),
    m_vehicle_speed(0.0),
    m_panto_up_button_state(0.0),
    m_panto_down_button_state(0.0)
{
    Requires(
        SimPropertyWatcher::Group::VEHICLE_INPUTS,
        Project::ValueName::VehicleInputs::PANTO_UP_PB,
        &m_panto_up_button_state,
        [this](const auto& value)
        {
            m_panto_up_button_state = value;
            CheckInfraction();
        });

    Requires(
        SimPropertyWatcher::Group::VEHICLE_INPUTS,
        Project::ValueName::VehicleInputs::PANTO_DOWN_PB,
        &m_panto_down_button_state,
        [this](const auto& value)
        {
            m_panto_down_button_state = value;
            CheckInfraction();
        });

    Requires(
        SimPropertyWatcher::Group::TRAIN,
        Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
        &m_vehicle_speed);

    assert(m_penalty >= 0);
}

void PantographOperatedInMotionInfractionRule::RequiredAvailable()
{
    CheckInfraction();
}

void PantographOperatedInMotionInfractionRule::CheckInfraction()
{
    constexpr auto speed_threshold{0.1}; // m/s

    const auto train_is_moving{std::abs(m_vehicle_speed) > speed_threshold};

    const auto panto_operation_requested{
        m_panto_down_button_state > 0.5 || m_panto_up_button_state > 0.5};

    if (train_is_moving && panto_operation_requested)
        RecordInfraction(m_penalty);
}