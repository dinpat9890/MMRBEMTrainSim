/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#ifndef EMERGENCY_STOP_INFRACTION_RULE_H
#define EMERGENCY_STOP_INFRACTION_RULE_H
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "Emergency stop infraction"
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 1, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class EmergencyStopInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    EmergencyStopInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters);

    void RequiredAvailable() override;

private:
    // Scoring Parameters.
    const double m_penalty;
    const double m_max_distance;

    // Inputs.
    double m_vehicle_speed;
    double m_emergency_button_state;
    double m_emergency_stop_button;
    double m_master_contrl_handle_state;

    std::unordered_map<int, std::vector<int>> m_map_featureid_featurestate;    

    void CheckInfraction();    
};

#endif //EMERGENCY_STOP_INFRACTION_RULE_H
