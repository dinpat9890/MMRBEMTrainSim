/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#pragma once
#include "SessionAnalyserUnits/InfractionRule.h"

/// Implements the "Electric consumption" infraction for the
/// Mumbai Metro L2 & L7 simulator.
/// @see Item 23, Section 4.2.1, of 664AIL1A-DES-014 Driver Evaluation System Design.
class ElectricConsumptionInfractionRule : public InfractionRule
{
public:
    /// @throws CommonException if the scoring parameters are invalid or missing.
    ElectricConsumptionInfractionRule(
        InfractionUnit&                    punit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    void SessionProcessing() override;

    // Scoring Parameters.
    const double m_penalty;

    // Inputs.
    const double m_electric_consumption_min;
    const double m_electric_consumption_max;
    double m_energy_consumed;
    double m_number_driver_mode_selection;
};