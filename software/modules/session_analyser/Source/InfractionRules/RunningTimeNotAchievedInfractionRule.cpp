///
/// @file       RunningTimeNotAchievedInfractionRule.cpp
///
///
/// @ingroup    Oktal Sydac Tram Simulator
///

///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2023
///

#include "RunningTimeNotAchievedInfractionRule.h"
#include "ScoringParameterValidation.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "../../project_features/include/project_features/ProjectFeatureConstants.h"
#include "train_data_access/Timetable.h"

namespace
{
    const std::string RULE_NAME = "RUNTIME";
    const std::string PARAMETER_LIMIT_MIN_TIME = "LMT_MN_TM";
    const std::string PARAMETER_LIMIT_MAX_TIME = "LMT_MX_TM";
    const std::string PARAMETER_MIN_PENALTY = "RNTM_P_MN";
    const std::string PARAMETER_MAX_PENALTY = "RNTM_P_MX";
    const double MIN_MOVING_SPEED = 0.1;
}

RunningTimeNotAchievedInfractionRule::RunningTimeNotAchievedInfractionRule(
    InfractionUnit&             unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
  : InfractionRule(unit, RULE_NAME, scoring_parameters)
    , m_limit_min_time(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_LIMIT_MIN_TIME))
    , m_limit_max_time(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_LIMIT_MAX_TIME))
    , m_min_penalty(GetParameter(PARAMETER_MIN_PENALTY))
    , m_max_penalty(GetParameter(PARAMETER_MAX_PENALTY))
{
    InitialiseTimeTableDataForScenario();

    //Prepare map feature id to station Id - m_feature_id_to_station_id
    const auto stations =
        Train::Database::Timetable(GetDataAccess()).GetStations(
            Core::Database::Network(GetDataAccess()).GetNetworkIDForScenario(GetScenarioId()));

    for (const auto& station : stations)
    {
        if (station.feature_ids.size() == 0)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "RunningTimeNotAchievedInfractionRule might not work properly. No feature associated with station : "
                << station.name << Trace::EndLog();

            continue;
        }

        for (const auto& feature_id : station.feature_ids)
        {
            m_feature_id_to_station_id[feature_id] = station.id;
            Trace::GetLogger().STAMP(Trace::VERBOSE)
                << "Station \"" << station.name << "\" associated with feature : " << feature_id << Trace::EndLog();
        }
    }

    ///Driver mode selection
    Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DRIVER_MODE_SELECTION, &m_number_driver_mode_selection);

    //Departure order
    Requires(SimPropertyWatcher::Group::CBTC_PLATFORM_OUTPUTS, Project::ValueName::CBTCPlatformOutputs::DEPARTURE_ORDER, &m_departure_order);

    //Train speed
    Requires(SimPropertyWatcher::Group::TRAIN, Project::ValueName::Train::LLO_LEAD_LOCO_SPEED, &m_vehicle_speed);

    //Watch Platform feature
    m_platform_feature_type_id = Core::Database::Feature(GetDataAccess()).GetFeatureType(Project::FeatureTypes::PLATFORM).feature_type_id;

    WatchFeatureTypes({m_platform_feature_type_id});

    RequiresPath();
}

void RunningTimeNotAchievedInfractionRule::InitialiseTimeTableDataForScenario()
{
    const auto timetable = Train::Database::Timetable(GetDataAccess());
    const auto timetables = timetable.GetScenarioTimetables(GetScenarioId());

    if (!timetables.empty())
    {        
        //As discussed with Prajakta(Java team), currently we are allowing only 1 timetable to scenario.
        //Currently , I am getting 1st from vector.
        //Get TimeTable which contains courses
        const auto timetable_id = timetables[0].timetable_id;
        if (timetable_id > 0)
        {
            const auto timetable_data = timetable.GetTimetable(timetable_id);

            //Currently , I am getting 1st Course from vector.
            if (!timetable_data.courses.empty())
            {
                //From Course , get Run
                const auto course = timetable_data.courses[0];

                //Get 1st Run
                if (course.runs.size() > 0)
                {
                    m_run = course.runs[0];
                    m_is_timetabledata_initialised = true;
                    if (m_run.stations.size() > 0)
                    {
                        for (const auto &iter : m_run.stations)
                        {
                            Trace::GetLogger().STAMP(Trace::VERBOSE) << "arrival_time  = "<< iter.arrival_time << " departure_time="<< iter.departure_time << "Id =" <<iter.id << Trace::EndLog();
                        }
                    }
                }
            }
        }
    }
}

double RunningTimeNotAchievedInfractionRule::CalculateExpectedTime()
{
    //This method calculates expected running time by referencing actual timetable from db.
    //As start position of train could be at any station & trainee can end session at any station, we store
    //start station & last station and calculate expected running time.
    const auto iter_start_station_timing
        = std::find_if(m_run.stations.begin(), m_run.stations.end(),
            [this](Train::Data::Timetable::Run::StationTiming &station_timing) { return station_timing.id == m_first_station_id; });
    if (iter_start_station_timing == m_run.stations.end())
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "RunningTimeNotAchievedInfractionRule::CalculateExpectedTime(). m_first_station_id "<< m_first_station_id << " is not found in reference DB timetable m_run.stations !! Please, check if timetable is loaded from db!! " << Trace::EndLog();
        return -1;
    }
    const auto iter_last_station_timing
        = std::find_if(m_run.stations.begin(), m_run.stations.end(),
            [this](Train::Data::Timetable::Run::StationTiming &station_timing) { return station_timing.id == m_last_station_id; });
    if (iter_last_station_timing == m_run.stations.end())
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "RunningTimeNotAchievedInfractionRule::CalculateExpectedTime(). m_last_station_id " << m_last_station_id << " is not found in reference DB timetable m_run.stations !! Please, check if timetable is loaded from db!! " << Trace::EndLog();
        return -1;
    }

    if (!(iter_start_station_timing < iter_last_station_timing))
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "RunningTimeNotAchievedInfractionRule::CalculateExpectedTime(). iter_start_station_timing >=iter_last_station_timing  " << Trace::EndLog();
        return -1;
    }

    const auto start_station_time = (m_first_station_arrival) ? iter_start_station_timing->arrival_time : iter_start_station_timing->departure_time;
    const auto last_station_time = (m_last_station_departure) ? iter_last_station_timing->departure_time : iter_last_station_timing->arrival_time;

    assert(start_station_time <= last_station_time);
    return (last_station_time - start_station_time);
}

void RunningTimeNotAchievedInfractionRule::SessionProcessing()
{
    if (m_is_timetabledata_initialised)
    {
        if (m_first_station_id != -1 && m_last_station_id != -1)
        {
            const auto expected_running_time = CalculateExpectedTime();
            if (expected_running_time > 0)
            {
                Trace::GetLogger().STAMP(Trace::INFO) << "RunningTimeNotAchievedInfractionRule::SessionProcessing .......=>expected_running_time=" << expected_running_time << Trace::EndLog();
                //Here check if need to record infraction
                if (m_number_driver_mode_selection == Project::TypeValue::CBTCMode::ATP ||
                    m_number_driver_mode_selection == Project::TypeValue::CBTCMode::ATO)
                {
                    //const auto session_save_time = GetCurrentTimePosition().time;
                    const auto total_time_between_first_and_last_station = m_last_station_actual_arrival_or_dept_time - m_first_station_actual_arrival_or_dept_time;
                    Trace::GetLogger().STAMP(Trace::INFO) << "RunningTimeNotAchievedInfractionRule::SessionProcessing .......=> total_time_between_first_and_last_station = " << total_time_between_first_and_last_station << Trace::EndLog();

                    const auto time_difference = std::abs(total_time_between_first_and_last_station - expected_running_time);
                    Trace::GetLogger().STAMP(Trace::INFO) << "RunningTimeNotAchievedInfractionRule::SessionProcessing .......=>time_difference=" << time_difference << "m_limit_min_time ="<< m_limit_min_time<< Trace::EndLog();
                    if (time_difference > m_limit_min_time)
                    {
                        const auto penalty = CalculatePenalty(time_difference, m_limit_min_time, m_limit_max_time, m_min_penalty, m_max_penalty);
                        Trace::GetLogger().STAMP(Trace::VERBOSE) << "penalty=" << penalty << Trace::EndLog();
                        RecordPostSessionInfraction(penalty);
                    }
                }
                else
                    Trace::GetLogger().STAMP(Trace::WARN) << "RunningTimeNotAchievedInfractionRule::SessionProcessing(). Not Checking RunningTimeNotAchievedInfractionRule infraction rule as driving mode is not ATP or ATO !!!!" << Trace::EndLog();
            }
            else
                Trace::GetLogger().STAMP(Trace::ERR) << "RunningTimeNotAchievedInfractionRule::SessionProcessing(). Failed CalculateExpectedTime()!!!!" << Trace::EndLog();
        }
        else
            Trace::GetLogger().STAMP(Trace::WARN) << "RunningTimeNotAchievedInfractionRule::SessionProcessing(). Not Checking RunningTimeNotAchievedInfractionRule infraction rule as number of travelled station are <= 1" << Trace::EndLog();
    }
    else
        Trace::GetLogger().STAMP(Trace::ERR) << "RunningTimeNotAchievedInfractionRule::SessionProcessing(). Timetable data is not initialised !!!!" << Trace::EndLog();
}


void RunningTimeNotAchievedInfractionRule::SetStationIdAndTime(const int station_id, const bool flag_first_station, const bool flag_last_station)
{
    m_last_station_departure = flag_last_station;
    if (m_first_station_id == -1) //Get first station id only once
    {
        m_first_station_arrival = flag_first_station;
        m_first_station_actual_arrival_or_dept_time = GetCurrentTimePosition().time;
        m_first_station_id = station_id;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "RunningTimeNotAchievedInfractionRule::TimePositionChanged: Got m_first_station_id =  " << m_first_station_id << Trace::EndLog();
    }
    else   //If first station id aleady got, initialise m_last_station_id. This will replace each station
    {
        m_last_station_actual_arrival_or_dept_time = GetCurrentTimePosition().time;
        m_last_station_id = station_id;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "RunningTimeNotAchievedInfractionRule::TimePositionChanged: UPDATED m_last_station_id =  " << m_last_station_id << Trace::EndLog();
    }
}
void RunningTimeNotAchievedInfractionRule::TimePositionChanged(TimePosition time_position)
{
    //Check if train is departed from station
    //Get station Id
    //Store departure time for station in map
    if (m_is_timetabledata_initialised) //If timetable data initialised from DB for the scenario
    {
        if (m_number_driver_mode_selection == Project::TypeValue::CBTCMode::ATP ||
            m_number_driver_mode_selection == Project::TypeValue::CBTCMode::ATO)  // ATP or ATO mode
        {
            const auto train_is_moving{ std::abs(m_vehicle_speed) > MIN_MOVING_SPEED };                        
            const auto platform_features_in_range = GetWorldAccess().GetPathFeatures(GetPathWatcher().GetPath(),
                    GetFeatureObjects(), true, false, -150, 0);

                if (!platform_features_in_range.empty())
                {
                    const auto platform_feature_id = static_cast<int>(platform_features_in_range.back().second.Numbers().Get(Core::ValueName::Feature::FEATURE_ID).value);
                    const auto platform_feature_type_id = platform_features_in_range.back().second.Numbers().Get(Core::ValueName::Feature::TYPE).value;
                    const auto iter = m_feature_id_to_station_id.find(platform_feature_id);
                    if (iter != m_feature_id_to_station_id.end() && platform_feature_type_id == m_platform_feature_type_id)
                    {
                        const auto station_id = iter->second;

                        if (m_map_station_arrival_departure_flags.find(station_id) == m_map_station_arrival_departure_flags.end())
                            m_map_station_arrival_departure_flags[station_id] = { false, false };

                        //If departure order from CBTC && traction is given by Driver ==>Means train is departed.
                        if (m_departure_order == Project::TypeValue::DepartureOrder::START_ORDER 
                            && train_is_moving 
                            && false == m_map_station_arrival_departure_flags[station_id].second ) //To avoid multiple time execution
                        {
                            SetStationIdAndTime(station_id, false, true);
                            m_map_station_arrival_departure_flags[station_id].second = true;                           
                        }
                        else if (m_departure_order == Project::TypeValue::DepartureOrder::OPEN_DOORS_ORDER 
                            && !train_is_moving
                            && false == m_map_station_arrival_departure_flags[station_id].first) //Train arrived
                        {
                            SetStationIdAndTime(station_id, true, false);
                            m_map_station_arrival_departure_flags[station_id].first = true;                            
                        }
                    }
                    else
                        Trace::GetLogger().STAMP(Trace::ERR) << " platform_feature_id " << platform_feature_id << " is not found in map m_feature_id_to_station_id" << Trace::EndLog();
                }
                
           
        }
    }
}
