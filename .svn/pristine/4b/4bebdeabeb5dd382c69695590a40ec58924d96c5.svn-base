/// @file
/// @copyright © 2022 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.
#include "EmergencyStopInfractionRule.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "../../project_features/include/project_features/ProjectFeatureConstants.h"
#include "ScoringParameterValidation.h"
#include <cassert>

namespace
{
    constexpr auto rule_name{ "ESTOP" };

    namespace Parameters
    {
        constexpr auto penalty{ "EMERPNLTY" };
        constexpr auto max_distance{ "MAX_DIST" };
    }
    const double MIN_MOVING_SPEED = 0.1;
    const double EMERGENCY_BRAKE_APPLIED = 1.0;
}

EmergencyStopInfractionRule::EmergencyStopInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, rule_name, scoring_parameters),
    m_penalty(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::penalty)),
    m_max_distance(Scoring::GetNonNegativeParameter(scoring_parameters, Parameters::max_distance)),
    m_vehicle_speed(0.0),
    m_emergency_button_state(0.0),
    m_emergency_stop_button(0.0),
    m_master_contrl_handle_state(0.0)
{
    //Emergency brake - Op. panel 1c soft plc 
    Requires(
        SimPropertyWatcher::Group::VEHICLE_INPUTS,
        Project::ValueName::VehicleInputs::EMERGENCY_BRAKE_PB,
        &m_emergency_button_state,
        [this](const auto& value)
        {
            m_emergency_button_state = value;
            CheckInfraction();
        });

    //Train speed
    Requires(
        SimPropertyWatcher::Group::TRAIN,
        Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
        &m_vehicle_speed);

    //Emergency stop button - Op. panel 5
    Requires(
        SimPropertyWatcher::Group::VEHICLE_INPUTS,
        Project::ValueName::VehicleInputs::EMERGENCY_STOP_PB,
        &m_emergency_stop_button,
        [this](const auto& value)
    {
        m_emergency_stop_button = value;
        CheckInfraction();
    });

    //Master control handle - EB position
    Requires(
        SimPropertyWatcher::Group::VEHICLE_INPUTS,
        Project::ValueName::VehicleInputs::MASTER_CONTROLLER_HANDLE,
        &m_master_contrl_handle_state,
        [this](const auto& value)
    {
        m_master_contrl_handle_state = value;
        CheckInfraction();
    });
    
    Core::Database::Feature feature(GetDataAccess());

    //Horse -->On track
    auto feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_HORSE).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id));


    //Sheep -->On track
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_SHEEP).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id));

    //Cow --->On track
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_COW).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id));
    
    //Sleeper -->Visible
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_SLEEPER).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));

    //Tree ---> visible    
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_TREE).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));

    //Car --->On track    
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_CAR).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));

    //Broken Rail --> Sever break
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_BROKEN_RAIL).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::SEVERE_BREAK).feature_type_state_id));

    //Banner flag -->Visible
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_BANNER_FLAG).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));

    //Kite ---> Visible
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_KITE).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));

    //Rope ---> Visible
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_ROPE).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));

    //Shirt ---> Visible
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_SHIRT).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));

    //Track Workers -->Working
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_WORKCREW).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::WORKING).feature_type_state_id));

    //Unauthorised Personnel on the Track--> Idle or Idle Red flag or Waving Red flag
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_CIVILIAN).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::IDLE).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::IDLE_RED_FLAG).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::WAVING_RED_FLAG).feature_type_state_id));

    //Fire ---> Visible
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_FIRE).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::VISIBLE).feature_type_state_id));

    //Water --> High
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTIONWATERONTRACK).feature_type_id;
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::HIGH).feature_type_state_id));
    m_map_featureid_featurestate[feature_type_id].emplace_back(static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::MED).feature_type_state_id));

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

void EmergencyStopInfractionRule::RequiredAvailable()
{
    CheckInfraction();
}

void EmergencyStopInfractionRule::CheckInfraction()
{
    const auto train_is_moving{std::abs(m_vehicle_speed) > MIN_MOVING_SPEED};
    const auto is_emergency_stop{m_emergency_button_state > 0.5 || m_emergency_stop_button  > 0.5 || -101 == m_master_contrl_handle_state };
    
    //Get features in front of the train within max distance 
    std::vector<std::pair<double, Comms::Object> > features_in_max_dist_range = GetWorldAccess().GetPathFeatures(GetPathWatcher().GetPath(),
        GetFeatureObjects(), true, false, 0, m_max_distance);

    if (train_is_moving && is_emergency_stop /*&& features_in_max_dist_range.empty()*/)
    {
        if(features_in_max_dist_range.empty())
          RecordInfraction(m_penalty);
        else
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Number of obstruction feature in the range of "<< m_max_distance <<"m =" << features_in_max_dist_range.size() << Trace::EndLog();
            //If there are some features in max distance range & if all have state which are not expected, then recordinfraction
            auto iter_features_in_max_dist_range = features_in_max_dist_range.begin();
            for ( ; iter_features_in_max_dist_range != features_in_max_dist_range.end(); iter_features_in_max_dist_range++)
            {
                int feature_state = static_cast<int>(iter_features_in_max_dist_range->second.Numbers().Store().Get(iter_features_in_max_dist_range->second.Numbers().Info().GetID(Core::ValueName::Feature::STATE)).value);
                int feature_id = static_cast<int>(iter_features_in_max_dist_range->second.Numbers().Store().Get(iter_features_in_max_dist_range->second.Numbers().Info().GetID(Core::ValueName::Feature::TYPE)).value);
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "feature_id = "<< feature_id << " feature_state ="<< feature_state << Trace::EndLog();
                const auto iter_m_map_featureid_featurestate = m_map_featureid_featurestate.find(feature_id);
                if (iter_m_map_featureid_featurestate != m_map_featureid_featurestate.end())
                {
                    //Found feature which has expected state. So pressed emergency stop is GOOD
                    if (std::find(iter_m_map_featureid_featurestate->second.begin(), iter_m_map_featureid_featurestate->second.end(), feature_state) != iter_m_map_featureid_featurestate->second.end())
                    { 
                        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Above obstruction feature id has expected state .(For Eg.VISIBLE or ON_TRACK or IDLE or IDLE_RED_FLAG or WAVING_RED_FLAG). So not recording EmergencyStopInfractionRule infraction." << feature_id << " feature_state =" << feature_state << Trace::EndLog();
                        break;
                    }
                }
            }

            if (iter_features_in_max_dist_range == features_in_max_dist_range.end())
                RecordInfraction(m_penalty);
        }
    }
}
