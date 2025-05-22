///
/// @file       AlertPeopleInfractionRule.h
///
///             Alert People Infraction Rule
///
/// @ingroup    Oktal Sydac Tram Simulator
///

///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2023
///
#ifndef ALERT_PEOPLE_INFRACTION_RULE_H
#define ALERT_PEOPLE_INFRACTION_RULE_H

#include "SessionAnalyserUnits/InfractionRule.h"

class AlertPeopleInfractionRule : public InfractionRule
{
public:
    explicit AlertPeopleInfractionRule(InfractionUnit&                    unit,
        Scoring::ScoringParameterProvider& scoring_parameters);
    void RequiredAvailable() override;

private:
    // Triggers
    void HornChanged(Sim::Number number);
    void TimePositionChanged(TimePosition time_position);

    // Configuration
    double m_min_distance;
    double m_max_distance;
    double m_penalty;

    // Comms
    double m_number_horn_low;
    double m_number_horn_high;

    std::map<Comms::Object, bool> m_features_between_min_max;
    std::map<int, int> m_map_featureid_featurestate;
};

#endif // ALERT_PEOPLE_INFRACTION_RULE_H
