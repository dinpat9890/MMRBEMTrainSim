/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "ElectricConsumptionInfractionRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
    constexpr auto rule_name{ "ECON" };
    const double J_TO_KWH = 3600000;
    namespace Parameters
    {
        constexpr auto electric_consum_min{ "EL_CON_MIN" };
        constexpr auto electric_consum_max{ "EL_CON_MAX" };
        const std::string PARAMETER_PENALTY = "ECON_P";
    }
}

ElectricConsumptionInfractionRule::ElectricConsumptionInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
    : InfractionRule(unit, rule_name, scoring_parameters),
    m_electric_consumption_min(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::electric_consum_min)),
    m_electric_consumption_max(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::electric_consum_max)),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::PARAMETER_PENALTY)),
    m_energy_consumed(m_electric_consumption_min),
    m_number_driver_mode_selection(0.0)
{
    Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DRIVER_MODE_SELECTION, &m_number_driver_mode_selection);
    Requires(SimPropertyWatcher::Group::TRAIN, Project::ValueName::Train::TOTAL_ENERGY_CONSUMPTION, &m_energy_consumed);
    assert(m_penalty >= 0);
}

void ElectricConsumptionInfractionRule::SessionProcessing()
{   
    //Convert energy from J to KWH . Modelling will send energy value in J.
    const double energy_consumed = m_energy_consumed / J_TO_KWH;   

    if (energy_consumed < m_electric_consumption_min || energy_consumed > m_electric_consumption_max)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "m_energy_consumed in J(From train model) ="<< m_energy_consumed << " energy_consumed in KWH = "<< energy_consumed <<  Trace::EndLog();
        if (m_number_driver_mode_selection != Project::TypeValue::DriverModeSelection::ATO)
        {
            RecordPostSessionInfraction(m_penalty);
        }
    }
}