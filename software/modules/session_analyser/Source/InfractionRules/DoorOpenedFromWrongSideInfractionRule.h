/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "Door opened from wrong side" infraction for the
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 14, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class DoorOpenedFromWrongSideInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    DoorOpenedFromWrongSideInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    // Scoring Parameters.
    const double m_penalty;

    // comms Inputs.
    double m_number_door_mode;
    double m_number_is_left_side_door_open_request;
    double m_number_is_right_side_door_open_request;
    double m_number_lhs_platform_detection;
    double m_number_rhs_platform_detection;

    void CheckInfraction();
};
