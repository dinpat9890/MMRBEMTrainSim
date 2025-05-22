#include "ObstructionCollisionInfractionRule.h"
#include "../../project_features/include/project_features/ProjectFeatureConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>
#include "core_comms_structure/CoreObjectConstants.h"

namespace
{
    constexpr auto rule_name{ "OBSTRCOL" };
    constexpr auto PARAMETER_PENALTY = "OBSTRCOL_P";
}

ObstructionCollisionInfractionRule::ObstructionCollisionInfractionRule(InfractionUnit&            unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
    : InfractionRule(unit, rule_name, scoring_parameters, true)
    , m_penalty(GetParameter(PARAMETER_PENALTY))
{
    //Watch all features of type Obstruction
    std::vector<int> feature_type_ids;
    auto feature_type_ids_obstruction = GetFeatureTypeIDsInGroup(GetDataAccess(), Project::FeatureTypeGroups::OBSTRUCTION);
    feature_type_ids.insert(feature_type_ids.end(), feature_type_ids_obstruction.begin(), feature_type_ids_obstruction.end());

    ///Watch all features of type HandSignaller - Track worker
    auto feature_type_ids_handsignaller = GetFeatureTypeIDsInGroup(GetDataAccess(), Project::FeatureTypeGroups::HANDSIGNALLER);
    feature_type_ids.insert(feature_type_ids.end(), feature_type_ids_handsignaller.begin(), feature_type_ids_handsignaller.end());
    
    WatchFeatureTypes(feature_type_ids);
    RequiresPath();

    std::vector<int> feature_states_vector;    
    Core::Database::Feature feature(GetDataAccess());

    //Horse -->On track
    auto feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_HORSE).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id));    
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Sheep -->On track
    feature_states_vector.clear();    
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_SHEEP).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Cow --->On track
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_COW).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;
    
    //Sleeper -->Visible
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_SLEEPER).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Tree ---> visible
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_TREE).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Car --->On track
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_CAR).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Broken Rail --> Sever break
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_BROKEN_RAIL).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::SEVERE_BREAK).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Banner flag -->Visible
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_BANNER_FLAG).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Kite ---> Visible
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_KITE).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Rope ---> Visible
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_ROPE).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Shirt ---> Visible
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_SHIRT).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Track Workers -->Working
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_WORKCREW).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::WORKING).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    //Unauthorised Personnel on the Track--> Idle or Idle Red flag or Waving Red flag
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_CIVILIAN).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::IDLE).feature_type_state_id));
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::IDLE_RED_FLAG).feature_type_state_id));
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::WAVING_RED_FLAG).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;
  
    //Fire ---> Visible
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_FIRE).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;    

    //Water --> High
    feature_states_vector.clear();
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTIONWATERONTRACK).feature_type_id;
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::HIGH).feature_type_state_id));
    feature_states_vector.push_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::MED).feature_type_state_id));    
    m_map_featureid_featurestate[feature_type_id] = feature_states_vector;

    assert(m_penalty >= 0);
}

void ObstructionCollisionInfractionRule::FeaturePassed(WorldAPI::PathFeatureWatcher::PassedObject passed_object)
{    
    //If obstruction feature is crossed, log infraction
    int feature_state = static_cast<int>(passed_object.object.Numbers().Store().Get(passed_object.object.Numbers().Info().GetID(Core::ValueName::Feature::STATE)).value);
    int feature_id = static_cast<int>(passed_object.object.Numbers().Store().Get(passed_object.object.Numbers().Info().GetID(Core::ValueName::Feature::TYPE)).value);

    Trace::g_plog->STAMP(Trace::VERBOSE) << "!!!!!!!Obstruction feature passed. feature_id =" << feature_id <<" feature_state ="<< feature_state << Trace::EndLog();

    auto iter_map_featureid_featurestate = m_map_featureid_featurestate.find(feature_id);
    if (iter_map_featureid_featurestate != m_map_featureid_featurestate.end())
    {
        const auto& feature_state_vect = iter_map_featureid_featurestate->second;
        if ( std::find(feature_state_vect.begin(), feature_state_vect.end(), feature_state) != feature_state_vect.end())
            RecordInfraction(m_penalty);
        else 
            Trace::g_plog->STAMP(Trace::VERBOSE) << "State is not found in feature_state_vect. feature_state ="<< feature_state <<Trace::EndLog();
    }
    else
        Trace::g_plog->STAMP(Trace::WARN) << "Obstruction feature passed is not in the m_map_featureid_featurestate feature_id =" << feature_id << Trace::EndLog();
}
