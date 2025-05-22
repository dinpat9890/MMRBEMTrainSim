/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"
#include <optional>

/// Implements the rollback infraction for the Mumbai Metro L2 & L7 simulator.
/// @see Item 6, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class RollBackInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    RollBackInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters);

    void RequiredAvailable() override;
    void TimePositionChanged(TimePosition time_position) override;

private:
    // Scoring Parameters.
    const double m_min_rollback_distance;
    const double m_max_rollback_distance;
    const double m_min_penalty;
    const double m_max_penalty;

    // Inputs.
    double m_reverser_position;
    double m_vehicle_speed;

    // State.
    std::optional<TimePosition> m_time_position_when_rolling_began;

    // Callbacks.
    void ReverserChanged(double number);
    void SpeedChanged(double number);

    void CheckInfraction();
};