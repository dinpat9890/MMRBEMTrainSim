///
/// @file       AlertPeopleInfractionRule.cpp
///
///             Alert People Infraction Rule
///
/// @ingroup    Oktal Sydac Tram Simulator
///

///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2023
///

#include "AlertPeopleInfractionRule.h"
#include "ScoringParameterValidation.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "../../project_features/include/project_features/ProjectFeatureConstants.h"

namespace
{
    const auto HORN_ON = 0.5;
    const std::string RULE_NAME = "ALERTPPL";
    const std::string PARAMETER_MIN_DIST = "AP_DIS_MIN";
    const std::string PARAMETER_MAX_DIST = "AP_DIS_MAX";
    const std::string PARAMETER_PENALTY = "AP_P";
}

AlertPeopleInfractionRule::AlertPeopleInfractionRule(InfractionUnit&             unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
    : InfractionRule(unit, RULE_NAME, scoring_parameters)
    , m_min_distance(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_MIN_DIST))
    , m_max_distance(GetParameter(PARAMETER_MAX_DIST))
    , m_penalty(GetParameter(PARAMETER_PENALTY))
{
    //Horn low
    Requires(
        SimPropertyWatcher::Group::VEHICLE_AUDIO_OUTPUT,
        Project::ValueName::AudioOutput::HORN_LOW,
        &m_number_horn_low,
        [this](const auto &value) {
        m_number_horn_low = value;
        HornChanged(m_number_horn_low);
    });

    //Horn high
    Requires(
        SimPropertyWatcher::Group::VEHICLE_AUDIO_OUTPUT,
        Project::ValueName::AudioOutput::HORN_HIGH,
        &m_number_horn_high,
        [this](const auto &value) {
        m_number_horn_high = value;
        HornChanged(m_number_horn_high);
    });

    //Alert to obstruction features like Cow, sheep ,horse , track workers
    //Initialise m_map_featureid_featurestate
    //horse, sheep, cow-- > OnTrack(3)    
    std::vector<int> feature_type_ids;
    Core::Database::Feature feature(GetDataAccess());
    /*auto feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_HORSE).feature_type_id;
    m_map_featureid_featurestate[feature_type_id] = static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id);
    feature_type_ids.emplace_back(feature_type_id);

    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_SHEEP).feature_type_id;
    m_map_featureid_featurestate[feature_type_id] = static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id);
    feature_type_ids.emplace_back(feature_type_id);

    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_OBSTRUCTION_COW).feature_type_id;
    m_map_featureid_featurestate[feature_type_id] = static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::ON_TRACK).feature_type_state_id);
    feature_type_ids.emplace_back(feature_type_id);*/

    //Track worker
    auto feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_WORKCREW).feature_type_id;
    m_map_featureid_featurestate[feature_type_id] = static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::WORKING).feature_type_state_id);
    feature_type_ids.emplace_back(feature_type_id);

    //Unauthorized Person
    feature_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_CIVILIAN).feature_type_id;
    m_map_featureid_featurestate[feature_type_id] = static_cast<int>(feature.GetFeatureTypeState(feature_type_id, Project::FeatureStates::IDLE).feature_type_state_id);
    feature_type_ids.emplace_back(feature_type_id);

    //Alert to platform passangers, Child, crew
    //auto feature_type_ids_1 = GetFeatureTypeIDsInGroup(GetDataAccess(), Project::FeatureTypeGroups::CHILDREN);
    //auto feature_type_ids_2 = GetFeatureTypeIDsInGroup(GetDataAccess(), Project::FeatureTypeGroups::WORK_CREW);
    //auto feature_type_ids_3 = GetFeatureTypeIDsInGroup(GetDataAccess(), Project::FeatureTypeGroups::PLATFORM_PASSENGER);
    //auto feature_type_ids_4 = GetFeatureTypeIDsInGroup(GetDataAccess(), Project::FeatureTypeGroups::HANDSIGNALLER);

    //feature_type_ids.insert(feature_type_ids.end(), feature_type_ids_1.begin(), feature_type_ids_1.end());
    //feature_type_ids.insert(feature_type_ids.end(), feature_type_ids_2.begin(), feature_type_ids_2.end());
    //feature_type_ids.insert(feature_type_ids.end(), feature_type_ids_3.begin(), feature_type_ids_3.end());
    //feature_type_ids.insert(feature_type_ids.end(), feature_type_ids_4.begin(), feature_type_ids_4.end());

    WatchFeatureTypes(feature_type_ids);

    RequiresPath();
}

void AlertPeopleInfractionRule::RequiredAvailable()
{
    HornChanged(m_number_horn_low);
    HornChanged(m_number_horn_high);
}

void AlertPeopleInfractionRule::HornChanged(Sim::Number number)
{
    if (number.value > HORN_ON)
    {
        for (auto &feature_between_min_max : m_features_between_min_max)
            feature_between_min_max.second = true;
    }
}

void AlertPeopleInfractionRule::TimePositionChanged(TimePosition time_position)
{

    //1.Get features in front of the train within max distance 
    std::vector<std::pair<double, Comms::Object> > features_in_max_dist_range = GetWorldAccess().GetPathFeatures(GetPathWatcher().GetPath(),
        GetFeatureObjects(), true, false, 0, m_max_distance);

    if (!features_in_max_dist_range.empty())
    {
        //Commenting sort() call as GetPathFeatures(..) returns vector with sorted oreder from nearest to far
        //2.Sort ascending order of distance
        //std::sort(features_in_max_dist_range.begin(), features_in_max_dist_range.end());

        //3.Go though all items in features_in_max_dist_range that are within min distance & check if horn is not pressed, put infraction
        // Also, add entry if it is not present in m_features_between_min_max & between min & max distance
        std::set<Comms::Object> set_feature_obj_in_max_distance;
        std::set<double> set_distances;  //Multiple fetures at same distance. No need to put infraction again.
        for (const auto feature_in_max : features_in_max_dist_range)
        {
            auto iter_map = m_features_between_min_max.find(feature_in_max.second);
            if (feature_in_max.first <= m_min_distance && iter_map != m_features_between_min_max.end())
            {
                if (set_distances.find(feature_in_max.first) == set_distances.end()  //Check if infraction is put already for distance feature_in_max.first
                    && false == iter_map->second) //if horn is not pressed, put infraction
                {
                    int feature_state = static_cast<int>(feature_in_max.second.Numbers().Store().Get(feature_in_max.second.Numbers().Info().GetID(Core::ValueName::Feature::STATE)).value);
                    int feature_id = static_cast<int>(feature_in_max.second.Numbers().Store().Get(feature_in_max.second.Numbers().Info().GetID(Core::ValueName::Feature::TYPE)).value);
                    auto iter_map_featureid_featurestate = m_map_featureid_featurestate.find(feature_id);
                    //auto is_human_feature{ iter_map_featureid_featurestate == m_map_featureid_featurestate.end() };

                    //For horse or cow or sheep or track workers , put infraction only if state is OnTrack 
                    if (/*is_human_feature ||*/ feature_state == iter_map_featureid_featurestate->second)
                    {
                        RecordInfraction(m_penalty);
                        set_distances.emplace(feature_in_max.first);
                    }
                }
                m_features_between_min_max.erase(iter_map);
            }
            else if (iter_map == m_features_between_min_max.end() && feature_in_max.first > m_min_distance) //missing in map
            {
                m_features_between_min_max[feature_in_max.second] = false;
            }

            //Collect set of Comm object within max distance to use in the next step 4
            set_feature_obj_in_max_distance.emplace(feature_in_max.second);
        }

        //4.Go through m_features_between_min_max and remove any item from it that is not in features_in_max_dist_range        
        auto iter_map = m_features_between_min_max.begin();
        while (iter_map != m_features_between_min_max.end())
        {
            if (set_feature_obj_in_max_distance.find(iter_map->first) == set_feature_obj_in_max_distance.end())
            {
                iter_map = m_features_between_min_max.erase(iter_map);
            }
            else iter_map++;
        }

    }
    // If there is single feature which is in max range & before min range. But train starts to reverse
   //& greater than  max range. So now that feature is not in the max range . But m_features_between_min_max contain
   //this feature which needs to clear in else brach.
    else if (!m_features_between_min_max.empty())
        m_features_between_min_max.clear();
}

