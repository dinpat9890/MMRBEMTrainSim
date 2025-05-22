/// @file      AnnouncementsPlay.h
///            Queing audio ids to play annaouncement for different scenarios .
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#ifndef ANNOUNCEMENTS_PLAY_H
#define ANNOUNCEMENTS_PLAY_H

#include "PISState.h"
#include "DVAAudioConfigHandler.h"
#include "BroadcastMessageQueue.h"
#include "train_data_access/Timetable.h"
#include <vector>
#include <map>

class AnnouncementsPlay
{
public:
    AnnouncementsPlay(PISState & pis_state, std::shared_ptr<dva::DVAAudioConfigHandler> dva_controller,
        std::unordered_map<int, Train::Data::Timetable::Station> & stationId_map,
        std::unordered_map<std::string, Train::Data::Timetable::Station> & station_name_map,
        std::unordered_map<std::string, Train::Data::Timetable::Route> & route_code_data_map,
        std::unordered_map<int, std::string> & routeId_code_map);
    ~AnnouncementsPlay() {}

private:
    // keeps the state seen at the last Step()
    PISState & m_state;

    // Audio XML handler and file data storage
    std::shared_ptr<dva::DVAAudioConfigHandler> m_dva_audio_handler;

    std::unordered_map<int, Train::Data::Timetable::Station> &                m_dbId_stationId_map;
    const std::unordered_map<std::string, Train::Data::Timetable::Station> &  m_station_name_map;
    const std::unordered_map<std::string, Train::Data::Timetable::Route> &    m_route_code_data_map;
    const std::unordered_map<int, std::string> &                              m_routeId_code_map;


public:
    int GetDbRouteID(int route_id);
    int ConvertXmlIdToDbId(int xml_id) const;
    int ConvertStationDbIdToXmlId(int db_id);
    bool GetNonSkipStationId(const dva::StationData & cur_skip_station_data, dva::StationData & next_station_data1);
    bool PlayNextStation(const dva::StationData & station_data, BroadcastMessage & msg, AnnouncementType startFlg);
    int GetEngStationNameAudioId(int station_id);
    int GetMarathiStationNameAudioId(int station_id);
    bool GetStationData(int station_id, dva::StationData & station_data);
    void PlayDoorCloseAnnouncemnt(int station_id, BroadcastMessage & msg);
    void PlayDoorChime(int station_id, bool door_open_flg, BroadcastMessage & msg);
    bool PlayRouteStartDepartAnnouncement(int station_id, BroadcastMessage & msg);
    bool PlayStationAnnouncement(int station_id, const std::string& announcement_type, BroadcastMessage & msg, int door_side);

    bool CheckSkipStation(const dva::StationData & station_data, BroadcastMessage & msg,
        std::vector<int>& skip_audio_id_msgs_mr, std::vector<int>& skip_audio_id_msgs_en);
    bool CheckInterChangeStation(const dva::StationData & stationData, BroadcastMessage & msg,
        AnnouncementType annoucement_type, Language language);
    bool CheckShortLoop(const dva::StationData & station_data, const dva::StationData & last_station_data,
        BroadcastMessage & msg, Language language);
};

#endif