/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "RollbackInfractionRule.h"
#include "CreateCallback.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <algorithm>
#include <cassert>
#include <cmath>

namespace
{
    constexpr auto rule_name{"ROLLBACK"};

    namespace Parameters
    {
        constexpr auto min_rollback_distance{"RBMINDIST"};
        constexpr auto max_rollback_distance{"RBMAXDIST"};
        constexpr auto min_penalty{"RBMINPNLTY"};
        constexpr auto max_penalty{"RBMAXPNLTY"};
    }
}

RollBackInfractionRule::RollBackInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, rule_name, scoring_parameters),
    m_min_rollback_distance(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::min_rollback_distance)),
    m_max_rollback_distance(Scoring::GetParameterGreaterThan(m_min_rollback_distance, scoring_parameters, Parameters::max_rollback_distance)),
    m_min_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::min_penalty)),
    m_max_penalty(Scoring::GetParameterGreaterThanOrEqualTo(m_min_penalty, scoring_parameters, Parameters::max_penalty)),
    m_reverser_position(0.0),
    m_vehicle_speed(0.0)
{
    Requires(
        SimPropertyWatcher::Group::VEHICLE_INPUTS,
        Project::ValueName::VehicleInputs::MODE_SELECTOR,
        &m_reverser_position,
        CreateCallback(&RollBackInfractionRule::ReverserChanged, this));

    Requires(
        SimPropertyWatcher::Group::TRAIN,
        Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
        &m_vehicle_speed,
        CreateCallback(&RollBackInfractionRule::SpeedChanged, this));

    assert(m_min_rollback_distance >= 0);
    assert(m_max_rollback_distance > m_min_rollback_distance);
    assert(m_min_penalty >= 0);
    assert(m_max_penalty >= m_min_penalty);
}

void RollBackInfractionRule::RequiredAvailable()
{
    CheckInfraction();
}

void RollBackInfractionRule::TimePositionChanged(TimePosition time_position)
{
    CheckInfraction();
}

void RollBackInfractionRule::ReverserChanged(const double number)
{
    m_reverser_position = number;
    CheckInfraction();
}

void RollBackInfractionRule::SpeedChanged(const double number)
{
    m_vehicle_speed = number;
    CheckInfraction();
}

void RollBackInfractionRule::CheckInfraction()
{
    constexpr auto speed_threshold{0.1}; // m/s
    constexpr auto forward_reverser_position{3};
    constexpr auto reverse_reverser_position{1};
    constexpr auto atp_mode_position{ 4 };

    const auto current_time_position{GetCurrentTimePosition()};

    const auto train_is_rolling{
        (m_vehicle_speed < -speed_threshold && static_cast<int>(m_reverser_position) == forward_reverser_position) ||
        (m_vehicle_speed >  speed_threshold && static_cast<int>(m_reverser_position) == reverse_reverser_position) ||
        (m_vehicle_speed < -speed_threshold && static_cast<int>(m_reverser_position) == atp_mode_position) }; //Rllback in ATP mode

    if (train_is_rolling)
    {
        // If we haven't already recorded the time at which rolling began, do so now.
        if (!m_time_position_when_rolling_began)
            m_time_position_when_rolling_began = current_time_position;

        assert(m_time_position_when_rolling_began);

        // Apply the max penalty whenever the train rolls more than the maximum
        // allowable distance.
        if (const auto distance_rolled{
                std::abs(current_time_position.position - m_time_position_when_rolling_began->position)};
            distance_rolled >= m_max_rollback_distance)
        {
            // Calculate the penalty duration (although this is inprecise
            // every time the distance rolled is greater than the maximum
            // allowed, it probably won't matter too much).
            const auto duration{current_time_position.time - m_time_position_when_rolling_began->time};
            assert(duration >= 0.0); // Assuming time isn't moving backwards.

            RecordInfraction(m_max_penalty, duration);

            // Reset the time/position so that a new infraction can be recorded
            // if the train continues to roll too far.
            m_time_position_when_rolling_began->time = current_time_position.time;

            // This might be a Bad Idea™, but instead of simply taking the current
            // position, instead we can adjust it by the maximum allowable
            // distance (accounting for direction of travel). This should increase
            // the accuracy of the demerits, but DECREASE the accuracy of the
            // penalty duration (which is probably less important anyway).
            const auto rolling_forwards{current_time_position.position > m_time_position_when_rolling_began->position};
            m_time_position_when_rolling_began->position += rolling_forwards ? m_max_rollback_distance : -m_max_rollback_distance;
        }
    }
    else // ...the train is not rolling
    {
        // If the train was rolling, determine if it went far enough to warrant a penalty.
        if (m_time_position_when_rolling_began)
        {
            if (const auto distance_rolled{
                    std::abs(current_time_position.position - m_time_position_when_rolling_began->position)};
                distance_rolled >= m_min_rollback_distance)
            {
                const auto normalised_roll_distance{
                    (distance_rolled - m_min_rollback_distance) /
                    (m_max_rollback_distance - m_min_rollback_distance)};

                const auto penalty{
                    std::clamp(
                        m_min_penalty + normalised_roll_distance * (m_max_penalty - m_min_penalty),
                        m_min_penalty,
                        m_max_penalty)};

                const auto duration{current_time_position.time - m_time_position_when_rolling_began->time};
                assert(duration >= 0.0); // Assuming time isn't moving backwards.

                RecordInfraction(penalty, duration);
            }

            m_time_position_when_rolling_began.reset();
        }

        // At this point we should never have a value for this, as the train isn't rolling.
        assert(!m_time_position_when_rolling_began);
    }
}