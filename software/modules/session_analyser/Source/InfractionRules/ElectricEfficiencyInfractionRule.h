/// @file ElectricEfficiencyInfractionRule.h
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "Electric efficiency" infraction for the
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 24, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class ElectricEfficiencyInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    ElectricEfficiencyInfractionRule(
        InfractionUnit&                    unit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    void SessionProcessing() override;

    // Scoring Parameters.
    const double m_penalty;
    const double m_electric_efficiency_min;
    const double m_electric_efficiency_max;

    // Inputs.
    double m_energy_consumed = 0.0;
    double m_total_train_weight = 0.0;
    double m_total_distance_travelled = 0.0;
    double m_number_driver_mode_selection;
};
