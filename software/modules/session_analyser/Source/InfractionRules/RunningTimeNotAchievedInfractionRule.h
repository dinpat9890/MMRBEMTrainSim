///
/// @file       RunningTimeNotAchievedInfractionRule.h
///
///             Running time not achieved infraction rule
///
/// @ingroup    Oktal Sydac Tram Simulator
///

///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2023
///
#ifndef RUNNING_TIME_NOT_ACHIEVED_INFRACTION_RULE_H
#define RUNNING_TIME_NOT_ACHIEVED_INFRACTION_RULE_H

#include "SessionAnalyserUnits/InfractionRule.h"

class RunningTimeNotAchievedInfractionRule : public InfractionRule
{
public:
    RunningTimeNotAchievedInfractionRule(
        InfractionUnit&                    unit,
        Scoring::ScoringParameterProvider& scoring_parameters);

    void SessionProcessing() override;
    void TimePositionChanged(TimePosition time_position) override;

private:
    void InitialiseTimeTableDataForScenario();
    double CalculateExpectedTime();
    void SetStationIdAndTime(const int station_id, const bool flag_first_station, const bool flag_last_station);

    // Configuration
    double m_limit_min_time;
    double m_limit_max_time;
    double m_min_penalty;
    double m_max_penalty;

    // Comms
    double m_number_driver_mode_selection = -1;
    double m_departure_order = -1;
    double m_vehicle_speed = 0.0;

    double m_session_play_time = -1;   
    int m_first_station_id = -1;
    int m_last_station_id = -1;
    Train::Data::Timetable::Run m_run;
    bool m_is_timetabledata_initialised = false;
    std::map<int, int> m_feature_id_to_station_id;
    int m_platform_feature_type_id = -1;

    double m_first_station_actual_arrival_or_dept_time = 0.0;
    double m_last_station_actual_arrival_or_dept_time = 0.0;
    bool m_first_station_arrival = false;
    bool m_last_station_departure = false;

    std::map<int, std::pair<bool, bool>> m_map_station_arrival_departure_flags;
};

#endif // RUNNING_TIME_NOT_ACHIEVED_INFRACTION_RULE_H
