/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
///
/// Please read the infraction 2 from the mentioned link, for understanding functionality has been written..
/// https://adl-atlassian.simu.lan/confluence/display/MMRBEM/664AIL1A-DES-014+Driver+Evaluation+System+Design
#include "DeadmanEmergencyBelowRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "ScoringParameterValidation.h"
#include <string>

namespace
{
    const auto MOVING_SPEED = 0.1;
    const std::string RULE_NAME_BEL = "DEAD_BEL";
    const std::string PARAMETER_PENALTY = "PNTY_BEL";
    const std::string PARAMETER_BELOW_SPEED = "DD_SPD_LES";
    const double KM_PER_HR = 3.6;
}

DeadmanEmergencyBelowRule::DeadmanEmergencyBelowRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, RULE_NAME_BEL, scoring_parameters),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_PENALTY)),
    m_param_below_speed(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_BELOW_SPEED)),
    m_vehicle_speed(0.0),
    m_number_vigilance_intervention(0.0)
{
    //How to get automatic emergency break applied after deadman timeout ??
    //As checked with modeler team:
    //a)There is no deadman alarm time out. Means as soon as deadman button released, automatic emergency break is applied.
    //b)VIGILANCE_INTERVENTION needs to use to detect deadman infraction which handle automatic break applied internally.

    //Vigilance intervention
    Requires(
        SimPropertyWatcher::Group::VEHICLE,
        Project::ValueName::Vehicle::VIGILANCE_INTERVENTION,
        &m_number_vigilance_intervention,
        [this](const auto& value)
        {
            m_number_vigilance_intervention = value;
            CheckInfraction();
        });

    //Train speed
    Requires(
        SimPropertyWatcher::Group::TRAIN,
        Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
        &m_vehicle_speed,
        [this](const auto& value)
        {
            m_vehicle_speed = value;
        });
}

void DeadmanEmergencyBelowRule::CheckInfraction()
{
    const auto abs_speed(abs(m_vehicle_speed * KM_PER_HR));
    if ((abs_speed > (MOVING_SPEED * KM_PER_HR))
        && (abs_speed <= m_param_below_speed) //speed is below 40 km/h
        && (m_number_vigilance_intervention > 0.5))   //Deadman is not pressed & automatic emergency break applied.
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Deadman Infraction has been recorded for speed : " << m_vehicle_speed << Trace::EndLog();
        RecordInfraction(m_penalty);
    }
}
