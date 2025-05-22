//ObstructionCollisionInfractionRule
#ifndef OBSTRUCTION_COLLISION_INFRACTION_RULE_H
#define OBSTRUCTION_COLLISION_INFRACTION_RULE_H

#include "SessionAnalyserUnits/InfractionRule.h"

class ObstructionCollisionInfractionRule : public InfractionRule
{
public:
    ObstructionCollisionInfractionRule(InfractionUnit&                    unit,
        Scoring::ScoringParameterProvider& scoring_parameters);
    void FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject passed_object) override;

private:
    double m_penalty;
    std::map<int, std::vector<int>> m_map_featureid_featurestate;

};

#endif //OBSTRUCTION_COLLISION_INFRACTION_RULE_H
