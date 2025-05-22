/// @file      PISState.h
///            Capture the state of PIS subsystem.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#ifndef PIS_STATE_H
#define PIS_STATE_H

#include <vector>
#include <map>
#include <set>

enum class DoorType
{
    NONE = -1,
    DOOR_LEFT = 0,
    DOOR_RIGHT = 1,
};

enum PlatformSide
{
    LEFT_SIDE = 1,
    RIGHT_SIDE = 2,
    NONE = -1,
};

enum class ArriveDepartureType
{
    NONE = -1,
    ARRIVAL = 0,
    DEPARTURE = 1,
};


enum class StationLocation
{
    START_STATION = 0,
    TERMINAL_STATION
};

struct EmergencySpecialMsgState
{
    int id = -1;
    std::string code;
    bool stop_status = true;
    int count = 1;
};

struct ManualAnnoucementMsg
{
    int start_station_id{ -1 }; //db ids
    int next_station_id{ -1 };
    ArriveDepartureType msg_type{ ArriveDepartureType::NONE };
    DoorType door_type{ DoorType::NONE };
};

enum class CallState
{
    INACTIVE = 0,
    CALL_REQUEST = 1,
    CALL_CONNECTED = 2,
};
const int RADIO_CALL_INACTIVE = 0;

class PISState
{
public:
    PISState() {}
    ~PISState() {}

    enum class State { unknown, inactive, powering_on, auto_announce, semi_auto_announce, manual_announce };

    State getState() const { return m_state; }

    // Methods to set one of the states. They may fail and return false, if transition from current state to new state impossible.

    bool setInactive();
    bool setPoweringOn(double powering_on_start_time);
    bool setAutoAnnounce();
    bool setSemiAutoAnnounce();
    bool setManualAnnounce();
    void setRouteSelected(int id);
    void setRouteStations(const std::vector<int>& stations, int watch_behind_feature_id);
    void setWatchBehindFeatureId(int watch_behind_feature_id);
    void setArriveStationAnnounced(bool announced);
    void setStationAhead(int station_id);
    void setOpenDoorState(int door_state);
    void setTrainSpeed(double train_speed);

    // Getters for state details. They may fail and throw, if call does not make sense in current state.

    double getPoweringOnStartTime() const;

    int getRouteSelected() const;

    int getWatchBehindFeatureId() const;
    bool getArriveStationAnnounced() const;
    bool isStationInRoute(int station_id) const;
    bool isLastStationInRoute(int station_id) const;
    bool isFirstStationInRoute(int station_id) const;
    int getNextStationIdAfter(int station_id) const;
    int getStationAhead() const;
    int getLastStation() const;
    int getFirstStation() const;
    double getTrainSpeed() const;
    int getOpenDoorState() const;
    bool UpdateRouteStations(int station_id, StationLocation station_location);
    void CheckUpdateShortLoop(int terminal_station_db_id);
    PlatformSide getPlatformSide() const;
    void setPlatformSide(PlatformSide platform_side);


private:

    State m_state{ State::unknown };

    // uknown & inactive does not have any details.

    // powering_on has power on timestamp.
    double m_powering_on_start_time{ 0.0 };

    int m_selected_route_id{ -1 };

    std::vector<int> m_route_stations; //contains stations db ids
    std::vector<int> m_route_stations_complete; //contains complete stations db ids for route.
    int m_station_ahead_idx{ -1 };

    // auto mode related
    int m_watch_behind_feature_id{ -1 };
    bool m_arrive_station_announced{ false };

    // semi-auto mode related
    int m_door_open_state{ -1 };
    double m_train_speed{ 0.0 };

    //PSD platform side
    PlatformSide m_platform_side{ PlatformSide::NONE };

    void ResetStateInfo();

public:
    std::map<int, int>     m_skip_station_list; // map key = Station id and value = seq no
    std::map<int, int>     m_skip_station_map; // map key = seq no and value = station id (xml id)
    int                    m_current_station_id{ -1 };
    int                    m_current_skip_count{ 0 };
    int                    m_current_skip_station_id{ -1 };
    bool                   m_dva_stop{ false };
    bool                   m_dva_start{ false };

    int                    m_start_station_xml_id{ -1 };
    int                    m_terminal_station_xml_id{ -1 };
    int                    m_next_station_xml_id{ -1 };
    int                    m_announce_state{ 0 };
    int                    m_route_id{ -1 };

    EmergencySpecialMsgState      m_emergency_msg_state;
    EmergencySpecialMsgState      m_special_msg_state;
    EmergencySpecialMsgState      m_occ_msg_state;
    int                           m_next_station_id{ -1 };
    ManualAnnoucementMsg          m_manual_anncmnt_msg;
    bool                          m_short_loop{ false };
    std::set<int>                 m_short_loop_stations;
    bool                          m_intercom_status{ false };
    int                           m_intercom_output{ 0 };
    bool                          m_buzzer_active{ false };
    int                           m_radio_intercom_state{ 0 };
    bool                           m_is_train_near_to_station{ false };


};

#endif