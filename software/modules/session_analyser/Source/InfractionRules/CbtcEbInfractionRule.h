/// @file
/// @copyright © 2023 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"
#include <string_view>

/// Parent class for the various CBTC Emergency Braking infractions in the
/// Mumbai Metro L2 & L7 simulator.
///
/// @see 664AIL1A-DES-014 Driver Evaluation System Design.
class CBTCEBInfractionRule : public InfractionRule
{
public:
    enum class BrakeReason 
    {
        EB_OVERSPEED_INTERVENTION = 2,
        EB_MODE_CHANGE_ON_RUN = 5,
        EB_SIGNAL_OVERRUN = 7,
        EB_TRAIN_HOLD = 10
    };

    /// @throws CommonException if the scoring parameters are invalid or missing.
    CBTCEBInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters,
        std::string_view                   rule_name,
        std::string_view                   penalty_name,
        BrakeReason                        brake_reason_required_for_infraction);

private:
    // Scoring Parameters.
    const double m_penalty;

    // Configuration.
    const BrakeReason m_brake_reason_required_for_infraction;

    // Inputs (with defaults).
    double m_vehicle_speed              = 0.0;
    double m_no_safety_break            = 1.0;
    double m_atp_emergency_brake_reason = 0.0;

    void CheckInfraction();
};