/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
//This rule is not enabled from SessionAnalyser.ini as it is not part of requirement. Keeping cpp & .h if needed in future
#include "RedSignalOverrunInfractionRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "project_features/ProjectFeatureConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
    constexpr auto rule_name{ "" };
    namespace Parameters
    {
        constexpr auto penalty{ "" };
    }
    const double MIN_MOVING_SPEED = 0.1;
}

RedSignalOverrunInfractionRule::RedSignalOverrunInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
    : InfractionRule(unit, rule_name, scoring_parameters),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty))
{    
    
    //Driver mode selection
    Requires(
        SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS,
        Project::ValueName::CBTCVehicleOutputs::DRIVER_MODE_SELECTION,
        &m_number_driver_mode_selection,
        [this](const auto& value)
    {
        m_number_driver_mode_selection = value;
    });

    //Watch Main line signal feature
    Core::Database::Feature feature(GetDataAccess());

    auto feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_MAIN_LINE_SIGNAL_LONG).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::RED).feature_type_state_id));

    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_MAIN_LINE_SIGNAL_SHORT).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::RED).feature_type_state_id));

    //List map keys
    auto key_selector = [](auto pair) {return pair.first; };
    std::vector<int> feature_type_ids(m_map_featureid_featurestate.size());
    std::transform(m_map_featureid_featurestate.begin(), m_map_featureid_featurestate.end(), feature_type_ids.begin(), key_selector);    

    //Watch obstruction features
    WatchFeatureTypes(feature_type_ids);
    RequiresPath();

    assert(m_penalty >= 0);
    assert(feature_type_ids.size() == m_map_featureid_featurestate.size());
}

void RedSignalOverrunInfractionRule::FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject passed_object)
{    
    //Main line signal long or short passed.   
    // RMF mode
    if (Project::TypeValue::DriverModeSelection::RMF == m_number_driver_mode_selection)
    {        
        //Get feature id & state
        const auto featureState = static_cast<int>(passed_object.object.Numbers().Get(Project::ValueName::Feature::STATE).value);
        const auto featureId = static_cast<int>(passed_object.object.Numbers().Get(Project::ValueName::Feature::TYPE).value);

        //Find passed feature object id in map
        const auto iter_m_map_featureid_featurestate = m_map_featureid_featurestate.find(featureId);
        if (iter_m_map_featureid_featurestate != m_map_featureid_featurestate.end())
        {            
            //Check signal state is RED
            if (std::find(iter_m_map_featureid_featurestate->second.begin(), iter_m_map_featureid_featurestate->second.end(), featureState) != iter_m_map_featureid_featurestate->second.end())
            {
                //Record signal overrun infraction                   
                RecordInfraction(m_penalty);
            }
        }
    }
}