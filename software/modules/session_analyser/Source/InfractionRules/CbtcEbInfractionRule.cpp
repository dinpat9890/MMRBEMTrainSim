/// @file
/// @copyright © 2023 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "CBTCEBInfractionRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
    constexpr auto MIN_MOVING_SPEED = 0.1; // m/s
}

CBTCEBInfractionRule::CBTCEBInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters,
    const std::string_view             rule_name,
    const std::string_view             penalty_name,
    const BrakeReason                  brake_reason_required_for_infraction)
  : InfractionRule(unit, std::string(rule_name), scoring_parameters),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, penalty_name)),
    m_brake_reason_required_for_infraction(brake_reason_required_for_infraction)
{
    // Train speed
    Requires(
        SimPropertyWatcher::Group::TRAIN,
        Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
        &m_vehicle_speed);

    // No safety break
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_INPUTS,
        Project::ValueName::CBTCVehicleInputs::NO_EMERGENCY_BRAKE_ORDER,
        &m_no_safety_break,
        [this](const auto& value)
        {
            m_no_safety_break = value;
            CheckInfraction();
        });

    // Emergency brake trigger - EB reason
    Requires(
        SimPropertyWatcher::Group::CBTC_ONBOARD_OUTPUTS,
        Project::ValueName::CBTCOnboardOutputs::EMERGENCY_BRAKE_TRIGGER,
        &m_atp_emergency_brake_reason,
        [this](const auto& value)
        {
            m_atp_emergency_brake_reason = value;
            CheckInfraction();
        });

    assert(m_penalty >= 0);
}

void CBTCEBInfractionRule::CheckInfraction()
{
    const auto train_is_moving{ std::abs(m_vehicle_speed) > MIN_MOVING_SPEED };
    const auto emergency_brake_ordered{ 0.0 == m_no_safety_break };

    if (train_is_moving &&
        emergency_brake_ordered &&
        static_cast<int>(m_atp_emergency_brake_reason) == static_cast<int>(m_brake_reason_required_for_infraction))
    {
        RecordInfraction(m_penalty);
    }
}