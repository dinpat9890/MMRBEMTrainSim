/// @file
/// @copyright © 2023 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "CBTC EB Red Signal overrun" infraction for the
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 3, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class RedSignalOverrunInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    RedSignalOverrunInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    // Scoring Parameters.
    const double m_penalty;

    // Inputs.        
    double m_number_driver_mode_selection = 0.0;

    std::unordered_map<int, std::vector<int>> m_map_featureid_featurestate;

    void FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject passed_object) override;
};
