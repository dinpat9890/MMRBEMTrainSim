///
/// @file       TimetableNotFollowedInfractionRule.h
///
///             Running time not achieved infraction rule
///
/// @ingroup    Oktal Sydac Tram Simulator
///

///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2023
///
#ifndef TIMETABLE_NOT_FOLLOWED_INFRACTION_RULE_H
#define TIMETABLE_NOT_FOLLOWED_INFRACTION_RULE_H

#include "SessionAnalyserUnits/InfractionRule.h"
#include "train_data_access/TrainDataAccessTypes.h"
#include <map>
#include <set>

class TimetableNotFollowedInfractionRule : public InfractionRule
{
public:
    explicit TimetableNotFollowedInfractionRule(
        InfractionUnit&                    unit,
        Scoring::ScoringParameterProvider& scoring_parameters);

private:
    void TimePositionChanged(TimePosition time_position) override;
    void InitialiseTimeTableDataForScenario();

    // Configuration
    const double m_limit_min_time;
    const double m_limit_max_time;
    const double m_min_penalty;
    const double m_max_penalty;

    // Comms
    double m_number_driver_mode_selection = -1;
    double m_departure_order = -1;
    double m_vehicle_speed = 0.0;

    Train::Data::Timetable::Run m_run;
    bool m_is_timetabledata_initialised = false;
    std::map<int, int> m_feature_id_to_station_id;
    int m_platform_feature_type_id = -1;
    std::set<int> m_set_stationids_infractionrecorded;  //To avoid multiple infraction recording for same station
};

#endif // TIMETABLE_NOT_FOLLOWED_INFRACTION_RULE_H
