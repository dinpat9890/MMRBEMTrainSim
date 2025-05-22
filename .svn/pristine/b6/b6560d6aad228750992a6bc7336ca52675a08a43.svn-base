///
/// @file       TimetableNotFollowedInfractionRule.cpp
///
///
/// @ingroup    Oktal Sydac Tram Simulator
///

///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2023
///

#include "TimetableNotFollowedInfractionRule.h"
#include "ScoringParameterValidation.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "../../project_features/include/project_features/ProjectFeatureConstants.h"
#include "train_data_access/Timetable.h"
#include "core_types/SessionData.h"
#include "common/StandardLogging.h"
#include <string>
#include <vector>

namespace
{
    const std::string RULE_NAME = "TIMETABL";
    const std::string PARAMETER_LIMIT_MIN_TIME = "LMT_MN_TM1";
    const std::string PARAMETER_LIMIT_MAX_TIME = "LMT_MX_TM1";
    const std::string PARAMETER_MIN_PENALTY = "RNTM_P_MN1";
    const std::string PARAMETER_MAX_PENALTY = "RNTM_P_MX1";
    const double MIN_MOVING_SPEED = 0.1;
    const auto NUMBER_OF_SECONDS_IN_A_DAY = 86400;
}

TimetableNotFollowedInfractionRule::TimetableNotFollowedInfractionRule(
    InfractionUnit&                    unit,
    Scoring::ScoringParameterProvider& scoring_parameters)
    : InfractionRule(unit, RULE_NAME, scoring_parameters)
    , m_limit_min_time(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_LIMIT_MIN_TIME))
    , m_limit_max_time(Scoring::GetNonNegativeParameter(scoring_parameters, PARAMETER_LIMIT_MAX_TIME))
    , m_min_penalty(GetParameter(PARAMETER_MIN_PENALTY))
    , m_max_penalty(GetParameter(PARAMETER_MAX_PENALTY))
{
    InitialiseTimeTableDataForScenario();

    //Prepare map feature id to station Id - m_feature_id_to_station_id
    for (const auto& station : Train::Database::Timetable(GetDataAccess()).GetStations(Core::Database::Network(GetDataAccess()).GetNetworkIDForScenario(GetScenarioId())))
    {
        if (station.feature_ids.empty())
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "TimetableNotFollowedInfractionRule might not work properly. No feature associated with station : "
                << station.name << Trace::EndLog();

            continue;
        }

        for (const auto& feature_id : station.feature_ids)
        {
            m_feature_id_to_station_id[feature_id] = station.id;
        }
    }

    ///Driver mode selection
    Requires(SimPropertyWatcher::Group::CBTC_VEHICLE_OUTPUTS, Project::ValueName::CBTCVehicleOutputs::DRIVER_MODE_SELECTION, &m_number_driver_mode_selection);

    //Departure order
    Requires(SimPropertyWatcher::Group::CBTC_PLATFORM_OUTPUTS, Project::ValueName::CBTCPlatformOutputs::DEPARTURE_ORDER, &m_departure_order);

    //Train speed
    Requires(
        SimPropertyWatcher::Group::TRAIN,
        Project::ValueName::Train::LLO_LEAD_LOCO_SPEED,
        &m_vehicle_speed);

    //Watch Platform feature
    std::vector<int> feature_type_ids;
    Core::Database::Feature feature(GetDataAccess());
    m_platform_feature_type_id = feature.GetFeatureType(Project::FeatureTypes::PLATFORM).feature_type_id;
    feature_type_ids.emplace_back(m_platform_feature_type_id);
    WatchFeatureTypes(feature_type_ids);
    RequiresPath();
}

void TimetableNotFollowedInfractionRule::InitialiseTimeTableDataForScenario()
{
    const auto scenario_id = GetScenarioId();
    const auto timetable   = Train::Database::Timetable(GetDataAccess());
    const auto timetables  = timetable.GetScenarioTimetables(GetScenarioId());

    if (!timetables.empty())
    {
        // For one scenario, there could be multiple timetables associated. How to get exact which timetable to use????
        // start_datetime need to consider ????????????
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
                if (!course.runs.empty())
                {
                    m_run = course.runs[0];
                    m_is_timetabledata_initialised = true;

                    // Adjust the run times to be in session time (session time being 0
                    // at the start of the session).
                    const auto session_data       = GetGateway().GetSessionData<Core::BaseSessionData>().data;
                    const auto session_start_time = session_data.date_time;

                    // Start by calculating the start of the day in session time. This is
                    // a negative value, as it happened sometime in the past.
                    const auto start_of_day_in_session_time = -static_cast<double>(session_data.date_time % NUMBER_OF_SECONDS_IN_A_DAY);

                    // Now determine the start of the run, in session time. The start of the
                    // run is given as a number of seconds since midnight on the start day,
                    // so all we need to do is add it to the value above.
                    const auto start_of_run_in_session_time = start_of_day_in_session_time + m_run.start_time;

                    // Finally, adjust the individual timings.
                    for (auto &station_timing : m_run.stations)
                    {
                        // FIXME: The documentation claims that StationTiming::arrival_time is
                        //        ideally stored as the number of seconds since the start of the run,
                        //        but is *actually* stored as number of seconds since the start of
                        //        the day. Hence we don't end up using start_of_run_in_session_time,
                        //        even though we should.
                        station_timing.arrival_time   += start_of_day_in_session_time;
                        station_timing.departure_time += start_of_day_in_session_time;
                    }
                }
            }
        }
    }
}

void TimetableNotFollowedInfractionRule::TimePositionChanged(TimePosition time_position)
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
            //If departure order from CBTC && traction is given by Driver ==>Means train is departed.
            if (m_departure_order == Project::TypeValue::DepartureOrder::START_ORDER && train_is_moving)
            {
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
                        const auto actual_departure_time = time_position.time;

                        const auto iter_station_timing
                            = std::find_if(m_run.stations.begin(), m_run.stations.end(),
                                [station_id](Train::Data::Timetable::Run::StationTiming &station_timing) { return station_timing.id == station_id; });
                        if (iter_station_timing != m_run.stations.end())
                        {
                            const auto expected_departure_time = iter_station_timing->departure_time;

                            const auto time_difference = std::abs(expected_departure_time - actual_departure_time);

                            if (time_difference > m_limit_min_time &&
                                m_set_stationids_infractionrecorded.find(station_id) == m_set_stationids_infractionrecorded.end())
                            {
                                const double penalty = CalculatePenalty(time_difference, m_limit_min_time, m_limit_max_time, m_min_penalty, m_max_penalty);

                                RecordInfraction(penalty);
                                m_set_stationids_infractionrecorded.emplace(station_id);
                            }
                        }
                        else
                            Trace::GetLogger().STAMP(Trace::ERR) << " station_id " << station_id << " is not found in reference DB timetable m_run.stations !! Please, check if timetable is loaded from db!! " << Trace::EndLog();
                    }
                    else
                        Trace::GetLogger().STAMP(Trace::ERR) << " platform_feature_id " << platform_feature_id << " is not found in map m_feature_id_to_station_id" << Trace::EndLog();
                }
                else
                    Trace::GetLogger().STAMP(Trace::ERR) << "!!!Failed to get PLATFORMfeature back 150m distance." << Trace::EndLog();
            }
        }
    }
}
