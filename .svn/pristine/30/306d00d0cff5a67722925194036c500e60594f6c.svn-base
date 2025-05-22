/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#ifndef DEADMAN_EMERGENCY_BELOW_RULE_H
#define DEADMAN_EMERGENCY_BELOW_RULE_H

#include "SessionAnalyserUnits/InfractionRule.h"

class DeadmanEmergencyBelowRule : public InfractionRule
{
public:
    DeadmanEmergencyBelowRule(
        InfractionUnit&                    unit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    // Configuration
    const double m_penalty;
    const double m_param_below_speed;

    // Comms
    double m_vehicle_speed;
    double m_number_vigilance_intervention;

    void CheckInfraction();
};

#endif // DEADMAN_EMERGENCY_BELOW_RULE_H
