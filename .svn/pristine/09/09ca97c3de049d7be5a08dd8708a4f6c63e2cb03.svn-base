/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "Jerky Driving" infraction for the Mumbai Metro L2 & L7 simulator.
/// @see Item 20, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class JerkyDrivingInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    JerkyDrivingInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    // Scoring Parameters.
    const double m_penalty;
    const double m_limit_accleration;
    const double m_limit_deceleration;

    double m_last_known_acceleration = 0.0;
    double m_last_known_time         = 0.0;
    double m_last_time_infraction_recorded;
    bool m_got_first_time_acceleration = false;
    double m_vehicle_speed = 0.0;
    bool m_is_cbtc_emergency_break_active = false;
    double m_master_contrl_handle_state = 0.0;
    double m_emergency_stop_button = 0.0;
    double m_number_driver_mode_selection;
};
