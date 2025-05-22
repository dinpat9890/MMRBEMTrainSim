/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "ElectricEfficiencyInfractionRule.h"
#include "common/StandardLogging.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
    constexpr auto rule_name{ "EEFFI" };
    constexpr auto J_TO_KWH = 3600000.0;
    constexpr auto KG_TO_TON = 0.001102;

    namespace Parameters
    {
        constexpr auto ELECTRIC_EFFICIENCY_MIN{ "EFF_MIN" };
        constexpr auto ELECTRIC_EFFICIENCY_MAX{ "EFF_MAX" };
        constexpr auto PARAMETER_PENALTY{ "EEFFI_P" };
    }
}

ElectricEfficiencyInfractionRule::ElectricEfficiencyInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, rule_name, scoring_parameters),
    m_electric_efficiency_min(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::ELECTRIC_EFFICIENCY_MIN)),
    m_electric_efficiency_max(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::ELECTRIC_EFFICIENCY_MAX)),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::PARAMETER_PENALTY)),
    m_number_driver_mode_selection(0.0)
{
    // Current driving mode
    Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DRIVER_MODE_SELECTION, &m_number_driver_mode_selection);

    // Total energy consumption
    Requires(SimPropertyWatcher::Group::TRAIN, Project::ValueName::Train::TOTAL_ENERGY_CONSUMPTION, &m_energy_consumed);

    // Total train weight
    Requires(SimPropertyWatcher::Group::TCMS_VEHICLE_OUTPUT, Project::ValueName::TCMSVehicleOutputs::TOTAL_WEIGHT, &m_total_train_weight,
        [this](const auto& value)
        {
            m_total_train_weight = value;
        });

    // Total distance travelled
    Requires(SimPropertyWatcher::Group::TCMS_VEHICLE_OUTPUT, Project::ValueName::TCMSVehicleOutputs::ODOMETER, &m_total_distance_travelled,
        [this](const auto& value)
        {
            m_total_distance_travelled = value;
        });

    assert(m_penalty >= 0);
}

void ElectricEfficiencyInfractionRule::SessionProcessing()
{
    //Convert energy from J to KWH . Modelling will send energy value in J.
    const auto energy_consumed_in_kwh = m_energy_consumed / J_TO_KWH;
    const auto total_distance_travelled_in_km = m_total_distance_travelled / 1000.0;
    const auto total_train_weight_in_ton = m_total_train_weight * KG_TO_TON;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "energy_consumed_in_kwh = " << energy_consumed_in_kwh << Trace::EndLog();
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "total_distance_travelled_in_km = " << total_distance_travelled_in_km << Trace::EndLog();
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "total_train_weight_in_ton = " << total_train_weight_in_ton << Trace::EndLog();

    if (total_distance_travelled_in_km > 0.0 && total_train_weight_in_ton > 0.0 && energy_consumed_in_kwh > 0)
    {
        const auto efficiency_calculated = (energy_consumed_in_kwh / total_distance_travelled_in_km) / total_train_weight_in_ton;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "efficiency_calculated = " << efficiency_calculated << Trace::EndLog();
        if (efficiency_calculated < m_electric_efficiency_min || efficiency_calculated > m_electric_efficiency_max)
        {
            if (m_number_driver_mode_selection != Project::TypeValue::DriverModeSelection::ATO)
            {
                RecordPostSessionInfraction(m_penalty);
            }
        }
    }
}