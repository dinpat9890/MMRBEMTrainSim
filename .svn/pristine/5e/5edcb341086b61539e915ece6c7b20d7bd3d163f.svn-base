    /// @file      PISState.cpp
///            Capture the state of PIS subsystem implementation.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "PISState.h"

#include "project_comms_structure/ProjectObjectConstants.h"

#include "common/CommonExceptions.h"
#include "common/StandardLogging.h"
#include <algorithm>

void PISState::ResetStateInfo()
{
    m_state = State::unknown;
    m_powering_on_start_time = 0.0;
    m_selected_route_id = -1;
    m_route_stations.clear();
    m_station_ahead_idx = -1;
    m_watch_behind_feature_id = -1;
    m_arrive_station_announced = false;
    m_door_open_state = -1;
    m_train_speed = 0.0;
}

bool PISState::setInactive()
{
    ResetStateInfo();
    m_state = State::inactive;

    return true;
}

bool PISState::setPoweringOn(double powering_on_start_time)
{
    if (m_state == State::unknown || m_state == State::inactive)
    {
        ResetStateInfo();
        m_state = State::powering_on;
        m_powering_on_start_time = powering_on_start_time;

        return true;
    }

    Trace::GetLogger().STAMP(Trace::ERR) <<
        "Powering on can happen either in inactive or unknown state. Current PIS state: " <<
        static_cast<int>(m_state) << Trace::EndLog();

    return false;
}

bool PISState::setAutoAnnounce()
{
    ResetStateInfo();
    m_state = State::auto_announce;

    return true;
}

bool PISState::setSemiAutoAnnounce()
{
    m_watch_behind_feature_id = -1;
    m_arrive_station_announced = false;
    m_state = State::semi_auto_announce;

    return true;
}

bool PISState::setManualAnnounce()
{
    m_watch_behind_feature_id = -1;
    m_arrive_station_announced = false;
    m_state = State::manual_announce;

    return true;
}

void PISState::setRouteSelected(int id)
{
    m_selected_route_id = id;
}

void PISState::setRouteStations(const std::vector<int>& stations, int watch_behind_feature_id)
{
    int station_ahead_id = getStationAhead();

    m_route_stations = stations;
    m_route_stations_complete = stations;
    m_watch_behind_feature_id = watch_behind_feature_id;

    setStationAhead(station_ahead_id);
}

void PISState::setWatchBehindFeatureId(int watch_behind_feature_id)
{
    m_watch_behind_feature_id = watch_behind_feature_id;
}

void PISState::setArriveStationAnnounced(bool announced)
{
    m_arrive_station_announced = announced;
}

void PISState::setStationAhead(int station_id)
{
    const auto it = std::find(m_route_stations.begin(), m_route_stations.end(), station_id);

    if (it != m_route_stations.end())
        m_station_ahead_idx = it - m_route_stations.begin();
    else
        m_station_ahead_idx = -1;
}

void PISState::setOpenDoorState(int door_state)
{
    m_door_open_state = door_state;
}

void PISState::setTrainSpeed(double train_speed)
{
    m_train_speed = train_speed;
}

double PISState::getPoweringOnStartTime() const
{
    if (m_state == State::powering_on)
        return m_powering_on_start_time;

    CommonException wrong_state(__FILE__, __LINE__, "Call is not applicable to current PIS state: ");
    wrong_state << static_cast<int>(m_state);

    throw wrong_state;
}

int PISState::getRouteSelected() const
{
    return m_selected_route_id;
}

int PISState::getWatchBehindFeatureId() const
{
    return m_watch_behind_feature_id;
}

bool PISState::getArriveStationAnnounced() const
{
    return m_arrive_station_announced;
}

bool PISState::isStationInRoute(int station_id) const
{
    const auto it = std::find(m_route_stations.begin(), m_route_stations.end(), station_id);

    return it != m_route_stations.end();
}

bool PISState::isLastStationInRoute(int station_id) const
{
    auto station_count = m_route_stations.size();

    if (station_count != 0)
        return (m_route_stations[station_count - 1] == station_id);

    return false;
}

bool PISState::isFirstStationInRoute(int station_id) const
{
    auto station_count = m_route_stations.size();

    if (station_count != 0)
        return (m_route_stations[0] == station_id);

    return false;
}

int PISState::getNextStationIdAfter(int station_id) const
{
    auto it = std::find(m_route_stations.begin(), m_route_stations.end(), station_id);

    if (it != m_route_stations.end())
    {
        ++it;

        if (it != m_route_stations.end())
            return *it;
    }

    return -1;
}

int PISState::getStationAhead() const
{
    if (m_station_ahead_idx >= 0 && m_station_ahead_idx < static_cast<int>(m_route_stations.size()))
        return m_route_stations[m_station_ahead_idx];

    return -1;
}

int PISState::getLastStation() const
{
    auto station_count = m_route_stations.size();

    if (station_count != 0)
        return m_route_stations[station_count - 1];

    return -1;
}

int PISState::getFirstStation() const
{
    auto station_count = m_route_stations.size();

    if (station_count != 0)
        return m_route_stations[0];

    return -1;
}

int PISState::getOpenDoorState() const
{
    return m_door_open_state;
}

double PISState::getTrainSpeed() const
{
    return m_train_speed;
}

bool PISState::UpdateRouteStations(int start_terminal_station_id, StationLocation station_location)
{
    bool ret = true;;
    std::vector<int> new_route_stations;
    auto it = std::find_if(m_route_stations_complete.begin(), m_route_stations_complete.end(), [start_terminal_station_id](int station_db_id)
    {
        return start_terminal_station_id == station_db_id;
    });

    if (it != m_route_stations_complete.end())
    {
        if (station_location == StationLocation::START_STATION)
        {
            new_route_stations.assign(it, m_route_stations_complete.end());
        }
        else if (station_location == StationLocation::TERMINAL_STATION)
        {
            //int distance = std::distance(m_route_stations.begin(), it);
            //new_route_stations.assign(m_route_stations.begin(), m_route_stations.begin() + distance);
            auto start_station_id = *(m_route_stations.begin());
            auto start_station_iter = std::find(m_route_stations_complete.begin(), m_route_stations_complete.end(), start_station_id);
            if (start_station_iter != m_route_stations_complete.end() && start_station_iter < it)
            {
                new_route_stations.assign(start_station_iter, ++it);
            }
            else
            {
                ret = false;
                Trace::GetLogger().STAMP(Trace::WARN) << "start_station_id " << start_station_id << " not found in m_route_stations_complete !!!" << Trace::EndLog();
            }
        }


        if (station_location == StationLocation::TERMINAL_STATION && m_route_stations.size() > new_route_stations.size() && !new_route_stations.empty())
        {
            m_short_loop = true;
            size_t size = new_route_stations.size();
            for (int i = 1; i <= 3 && (size - i) >= 0; i++)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "ShortLoop stations: " << new_route_stations[size - i] << Trace::EndLog();
                m_short_loop_stations.insert(new_route_stations[size - i]);
            }
        }
        m_route_stations.clear();
        m_route_stations = new_route_stations;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Updated Route stations id(db) list: "; // 
    }
    else
    {
        ret = false;;
    }
    for (const auto & station_db_id: m_route_stations)
        Trace::GetLogger().STAMP(Trace::VERBOSE) << station_db_id << "  ";

    Trace::GetLogger().STAMP(Trace::VERBOSE) <<Trace::EndLog();
    return ret;
}

void PISState::CheckUpdateShortLoop(int terminal_station_db_id)
{
    auto it = std::find_if(m_route_stations.begin(), m_route_stations.end(), [terminal_station_db_id](int station_db_id)
    {
        return terminal_station_db_id == station_db_id;
    });

    if (it != m_route_stations.end())
    {
        size_t distance1 = std::distance(m_route_stations.begin(), it);
        int distance2 = std::distance(m_route_stations.begin(), m_route_stations.end());
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Distnce from first station: " << distance1 << " Last station distance: " << distance2 
            << ", Total stations: " << m_route_stations.size() << Trace::EndLog(); 
        if (distance1 < m_route_stations.size())
        {
            m_short_loop = true;
        }
    }
}

PlatformSide PISState::getPlatformSide() const
{
    return m_platform_side;
}

void PISState::setPlatformSide(PlatformSide platform_side)
{
    m_platform_side = platform_side;
}