/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "Pantograph Operated in Motion" infraction for the
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 11, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class PantographOperatedInMotionInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    PantographOperatedInMotionInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters);

    void RequiredAvailable() override;

private:
    // Scoring Parameters.
    const double m_penalty;

    // Inputs.
    double m_vehicle_speed;
    double m_panto_up_button_state;
    double m_panto_down_button_state;

    void CheckInfraction();
};