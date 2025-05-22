/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#ifndef DEADMAN_EMERGENCY_ABOVE_RULE_H
#define DEADMAN_EMERGENCY_ABOVE_RULE_H

#include "SessionAnalyserUnits/InfractionRule.h"

class DeadmanEmergencyAboveRule : public InfractionRule
{
public:
    DeadmanEmergencyAboveRule(
        InfractionUnit&                    unit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    // Configuration
    const double m_penalty;
    const double m_param_above_speed;

    // Comms
    double m_vehicle_speed;
    double m_number_vigilance_intervention;

    void CheckInfraction();
};

#endif // DEADMAN_EMERGENCY_ABOVE_RULE_H
