/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "Door Command Held Too Long" infraction for the
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 16, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class DoorOpenedCmdHeldTooLongInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    DoorOpenedCmdHeldTooLongInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    // Scoring Parameters.
    const double m_penalty;
    const double m_max_press_time;

    // Comms Inputs.
    double m_number_door_mode;
    double m_number_left_side_door_enable;
    double m_number_right_side_door_enable;
    double m_number_is_left_side_door_open_request;
    double m_number_is_right_side_door_open_request;

    TimePosition m_left_button_press_time_in_seconds;
    TimePosition m_left_button_release_time_in_seconds;
    TimePosition m_right_button_press_time_in_seconds;
    TimePosition m_right_button_release_time_in_seconds;

    bool m_bool_is_left_side_door_open_request;
    bool m_bool_is_right_side_door_open_request;

    void CheckInfraction();
};
