/// @file      AnnouncementsPlay.h
///            Queing audio ids to play annaouncement for different scenarios .
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "AnnouncementsPlay.h"

namespace
{
    const int DINGDONG = 101;
    const int DOOR_CHIME = 102;
    const int DOOR_OPN_ARRVL_LEFT_MR = 10504;
    const int DOOR_OPN_ARRVL_RIGHT_MR = 10505;
    const int DOOR_OPN_ARRVL_LEFT_EN = 20504;
    const int DOOR_OPN_ARRVL_RIGHT_EN = 20505;
    const int TRAIN_TRMNT_ARRVL_MR = 10506;
    const int TRAIN_TRMNT_ARRVL_EN = 20506;
    const int TRAIN_TRMNT_THANKYOU_ARRVL_MR = 10507;
    const int TRAIN_TRMNT_THANKYOU_ARRVL_EN = 20507;
    const int WLCM_TO_MUMBAI_DEPART_MR = 10502;
    const int WLCM_TO_MUMBAI_DEPART_EN = 20502;
    const int NEXT_STATION_DEPART_MR = 10503;
    const int NEXT_STATION_DEPART_EN = 20503;
    const int CLEAR_OFF_DOOR_MR = 10501;
    const int CLEAR_OFF_DOOR_EN = 20501;
    const int STATION_MR = 10508;
    const int STATION_EN = 20508;
    const int THIS_IS_MR = 10526;
    const int THIS_IS_EN = 20526;
    //const int TRAIN_TRMNT_ARRVL_MR = 10506;
    const int SKIP_STATION_MR = 10509;
    const int SKIP_STATION_EN = 20509;
    const int NO_STOP_NEXT_STATION_MR = 10510;
    const int NO_STOP_NEXT_STATION_EN = 20510;
    const int CAN_INTERCHANGE_FOR_MR = 10512;
    const int CAN_INTERCHANGE_FOR_EN = 20512;
    const int INTERCHANGE_HERE_FOR_MR = 10513;
    const int INTERCHANGE_HERE_FOR_EN = 20513;

    const int TRAVEL_BEYOND_DEBOARD_PART_1_EN = 103; //511
    const int TRAVEL_BEYOND_DEBOARD_PART_2_EN = 104; //511
    const int TRAVEL_BEYOND_DEBOARD_PART_3_EN = 105; //511
    const int TRAVEL_BEYOND_DEBOARD_PART_1_MR = 106; //511
    const int TRAVEL_BEYOND_DEBOARD_PART_2_MR = 107; //511

}

AnnouncementsPlay::AnnouncementsPlay(PISState & pis_state, std::shared_ptr<dva::DVAAudioConfigHandler> dva_controller,
        std::unordered_map<int, Train::Data::Timetable::Station> & stationId_map,
        std::unordered_map<std::string, Train::Data::Timetable::Station> & station_name_map,
        std::unordered_map<std::string, Train::Data::Timetable::Route> & route_code_data_map,
        std::unordered_map<int, std::string> & routeId_code_map):
    m_state(pis_state),
    m_dva_audio_handler(dva_controller),
    m_dbId_stationId_map(stationId_map),
    m_station_name_map(station_name_map),
    m_route_code_data_map(route_code_data_map),
    m_routeId_code_map(routeId_code_map)
{
}

int AnnouncementsPlay::GetDbRouteID(int route_id)
{
    auto dva_audio_it = m_dva_audio_handler->m_dva_audio_data.route_id_map.find(route_id);
    if (dva_audio_it != m_dva_audio_handler->m_dva_audio_data.route_id_map.end())
    {
        auto route_data = dva_audio_it->second;
        std::string code = route_data.route_code;

        const auto route_code_itr = m_route_code_data_map.find(code);
        if (route_code_itr != m_route_code_data_map.end())
        {
            auto route_db_data = route_code_itr->second;
            //Trace::GetLogger().STAMP(Trace::VERBOSE) << "Route Code : " << code << ", Route Db Id: " << route_db_data.id << Trace::EndLog();
            return route_db_data.id;
        }
    }
    return -1;
}

int AnnouncementsPlay::ConvertXmlIdToDbId(int xml_station_id) const
{
    //xml_station_id is station id defined in PIS Station XML file
    const auto dva_audio_it = m_dva_audio_handler->m_dva_audio_data.id_station_map.find(xml_station_id);
    if (dva_audio_it != m_dva_audio_handler->m_dva_audio_data.id_station_map.end())
    {
        auto station_name_itr = m_station_name_map.find(dva_audio_it->second.name_en);
        if (station_name_itr != m_station_name_map.end())
        {
            //Trace::GetLogger().STAMP(Trace::VERBOSE) << "XML Id: " << xml_station_id << ", DB Id: " << it2->second.id << Trace::EndLog();
            return station_name_itr->second.id;
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "DB Id not found for XML Id: "<< xml_station_id << Trace::EndLog();
        }
    }
    return -1;
}

int AnnouncementsPlay::ConvertStationDbIdToXmlId(int db_station_id)
{
    //db id is station id in Database
    std::string station_name = m_dbId_stationId_map[db_station_id].name;
    const auto it = m_dva_audio_handler->m_dva_audio_data.station_map.find(station_name);
    if (it != m_dva_audio_handler->m_dva_audio_data.station_map.end())
    {
        //Trace::GetLogger().STAMP(Trace::VERBOSE) << "DB Id: " << db_station_id << ", XML Id: " << it->second.station_id << Trace::EndLog();
        return it->second.station_id;
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "XML Id not found for db id: " << db_station_id << Trace::EndLog();
    }
    return -1;
}

// Get audio id for station name in english based on xml station id
int AnnouncementsPlay::GetEngStationNameAudioId(int station_id)
{
    const auto it = m_dva_audio_handler->m_dva_audio_data.id_station_map.find(station_id);
    if (it != m_dva_audio_handler->m_dva_audio_data.id_station_map.end())
    {
        return it->second.audio_file_id_next_station_en;
    }
    return -1;
}

// Get audio id for station name in marathi based on xml station id
int AnnouncementsPlay::GetMarathiStationNameAudioId(int station_id)
{
    const auto it = m_dva_audio_handler->m_dva_audio_data.id_station_map.find(station_id);
    if (it != m_dva_audio_handler->m_dva_audio_data.id_station_map.end())
    {
        return it->second.audio_file_id_next_station_mr;
    }
    return -1;
}

// convert station db id to station xml name/id and corresponding audio details fetched from xml
bool AnnouncementsPlay::GetStationData(int db_station_id, dva::StationData & station_data)
{
    const std::string station_name = m_dbId_stationId_map[db_station_id].name;
    const auto it = m_dva_audio_handler->m_dva_audio_data.station_map.find(station_name);
    if (it != m_dva_audio_handler->m_dva_audio_data.station_map.end())
    {
        station_data = it->second;
        return true;
    }
    else
    {
        return false;
    }
}

// if next station is in skip list, it will return true along with next non skip station data
// Else it will return false
bool AnnouncementsPlay::GetNonSkipStationId(const dva::StationData & cur_skip_station_data, dva::StationData & next_station_data1)
{
    //const auto it = m_state.m_skip_station_list.find(cur_skip_station_data.station_id);
    if (m_state.m_skip_station_list.find(cur_skip_station_data.station_id) == m_state.m_skip_station_list.end())
    {
        return false;
    }
    Trace::GetLogger().STAMP(Trace::INFO) << "Next station is skipped: " << cur_skip_station_data.name_en << Trace::EndLog();
    bool next_non_skip_found = false;
    int curr_skip_station_db_id = ConvertXmlIdToDbId(cur_skip_station_data.station_id);

    while (!next_non_skip_found)
    {
        int next_station_db_id = m_state.getNextStationIdAfter(curr_skip_station_db_id);
        if (next_station_db_id != -1)
        {
            dva::StationData next_station_data2;
            if (GetStationData(next_station_db_id, next_station_data2))
            {
                auto it = m_state.m_skip_station_list.find(next_station_data2.station_id);
                if (it != m_state.m_skip_station_list.end())
                {
                    curr_skip_station_db_id = ConvertXmlIdToDbId(next_station_data2.station_id);
                    Trace::GetLogger().STAMP(Trace::INFO) << "NExt station is skipped: " << next_station_data2.name_en << Trace::EndLog();
                    if (curr_skip_station_db_id == -1)
                    {
                        break;
                    }
                }
                else
                {
                    next_non_skip_found = true;
                    next_station_data1 = next_station_data2;
                    Trace::GetLogger().STAMP(Trace::INFO) << "current Skip station: " << cur_skip_station_data.name_en << ", Next Station found: " << next_station_data2.name_en << Trace::EndLog();
                    return next_non_skip_found;
                }
            }
        }
        else
        {
            break;
        }
    }
    return next_non_skip_found;
}


// station id is db station id
bool AnnouncementsPlay::PlayStationAnnouncement(int station_id, const std::string& announcement_type, BroadcastMessage & msg, int door_side)
{
    bool msg_enqued = false;
    const std::string station_name = m_dbId_stationId_map[station_id].name;
    const auto it = m_dva_audio_handler->m_dva_audio_data.station_map.find(station_name);
    //Trace::GetLogger().STAMP(Trace::VERBOSE) << " station name : " << station_name << Trace::EndLog();

    if (it != m_dva_audio_handler->m_dva_audio_data.station_map.end())
    {
        const dva::StationData stationData = it->second;

        //bool isLastStation = false;
        //if (m_state.isLastStationInRoute(station_id))
        //{
        //    isLastStation = true;
        //}

        if (m_state.isLastStationInRoute(station_id) == true)
        {
            if (announcement_type == "arrived")
            {
                msg.title = "DVA_" + stationData.name_en + "_" + announcement_type + "_" + "routeEnd";
                msg.audio_ids.push_back(DINGDONG);
                msg.audio_ids.push_back(stationData.audio_file_id_station_name_mr);

                if (door_side == PlatformSide::RIGHT_SIDE)
                    msg.audio_ids.push_back(DOOR_OPN_ARRVL_RIGHT_MR); //10505
                else
                    msg.audio_ids.push_back(DOOR_OPN_ARRVL_LEFT_MR); //10504

                //interchange for last arrival marathi 10513 and Get line (10516) based on Interchange station and FromLine
                CheckInterChangeStation(stationData, msg, AnnouncementType::DVA_ROUTE_END_ARRIVAL, Language::MARATHI);

                msg.audio_ids.push_back(TRAIN_TRMNT_ARRVL_MR); //10506
                msg.audio_ids.push_back(TRAIN_TRMNT_THANKYOU_ARRVL_MR); //10507
                msg.audio_ids.push_back(stationData.audio_file_id_station_name_en);

                if (door_side == PlatformSide::RIGHT_SIDE)
                    msg.audio_ids.push_back(DOOR_OPN_ARRVL_RIGHT_EN); //20505
                else
                    msg.audio_ids.push_back(DOOR_OPN_ARRVL_LEFT_EN); //20504
                
                //interchange for last arrival english 20513 and Get line (20516) based on Interchange station and FromLine
                CheckInterChangeStation(stationData, msg, AnnouncementType::DVA_ROUTE_END_ARRIVAL, Language::ENGLISH);

                msg.audio_ids.push_back(TRAIN_TRMNT_ARRVL_EN); //20506
                msg.audio_ids.push_back(TRAIN_TRMNT_THANKYOU_ARRVL_EN); //20507
                msg_enqued = true;
                Trace::GetLogger().STAMP(Trace::INFO) << msg.title << " Last Station Arrived" << Trace::EndLog();
            }
            else if (announcement_type == "next")
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << " Last Station NEXT" << Trace::EndLog();
                msg_enqued = PlayNextStation(stationData, msg, AnnouncementType::DVA_ROUTE_END_DEPARTURE); //send END instead of false
            }
        }
        else
        {
            if (announcement_type == "arrived")
            {
                msg.title = "DVA_" + stationData.name_en + "_" + announcement_type;
                msg.audio_ids.push_back(DINGDONG);
                msg.audio_ids.push_back(stationData.audio_file_id_station_name_mr);
                
                if (door_side == PlatformSide::RIGHT_SIDE)
                    msg.audio_ids.push_back(DOOR_OPN_ARRVL_RIGHT_MR); //10505
                else
                    msg.audio_ids.push_back(DOOR_OPN_ARRVL_LEFT_MR); //10504
                
                //interchange for last arrival marathi 10513 and Get line (10516) based on Interchange station and FromLine
                CheckInterChangeStation(stationData, msg, AnnouncementType::DVA_ROUTE_MIDDLE_ARRIVAL, Language::MARATHI);

                msg.audio_ids.push_back(stationData.audio_file_id_station_name_en);
                
                if (door_side == PlatformSide::RIGHT_SIDE)
                    msg.audio_ids.push_back(DOOR_OPN_ARRVL_RIGHT_EN); //20505
                else
                    msg.audio_ids.push_back(DOOR_OPN_ARRVL_LEFT_EN); //20504

                //interchange for last arrival marathi 10513 and Get line (10516) based on Interchange station and FromLine
                CheckInterChangeStation(stationData, msg, AnnouncementType::DVA_ROUTE_MIDDLE_ARRIVAL, Language::ENGLISH);

                msg_enqued = true;
                Trace::GetLogger().STAMP(Trace::VERBOSE) << msg.title << " Middle Station Arrived" << Trace::EndLog();
            }
            else if (announcement_type == "next")
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << " Middle Station NEXT" << Trace::EndLog();
                msg_enqued = PlayNextStation(stationData, msg, AnnouncementType::DVA_ROUTE_MIDDLE_DEPARTURE); //send MIDDLE instead of false
            }
        }
    }
    return msg_enqued;
}

bool AnnouncementsPlay::PlayNextStation(const dva::StationData & station_data, BroadcastMessage & msg, AnnouncementType startFlg)
{
    msg.title = "DVA_" + station_data.name_en + "_next";
    int last_station_id = m_state.getLastStation();
    dva::StationData last_station_data;
    if (GetStationData(last_station_id, last_station_data))
    {
        int last_station_audio_id_mr = last_station_data.audio_file_id_terminal_station_mr;
        int last_station_audio_id_en = last_station_data.audio_file_id_terminal_station_en;
        bool next_station_skip = false;
        std::vector<int> skip_audio_id_msgs_en;
        std::vector<int> skip_audio_id_msgs_mr;

        if (m_state.m_skip_station_list.size() > 0)
        {
            next_station_skip = CheckSkipStation(station_data, msg, skip_audio_id_msgs_mr, skip_audio_id_msgs_en);
        }

        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Middle Station Next" << Trace::EndLog();

        msg.audio_ids.push_back(DINGDONG);

        if (next_station_skip)// && (m_state.m_skip_station_list.size() > m_state.m_current_skip_count))
        {
            for (const auto & id : skip_audio_id_msgs_mr)
            {
                msg.audio_ids.push_back(id);
            }
            for (const auto & id : skip_audio_id_msgs_en)
            {
                msg.audio_ids.push_back(id);
            }
        }
        else
        {
            if (startFlg == AnnouncementType::DVA_ROUTE_START_DEPARTURE)
            {
                msg.title = "DVA_" + station_data.name_en + "_RouteStart";
                msg.audio_ids.push_back(WLCM_TO_MUMBAI_DEPART_MR); //10502
                Trace::GetLogger().STAMP(Trace::VERBOSE) << msg.title << Trace::EndLog();
            }

            msg.audio_ids.push_back(last_station_audio_id_mr);
            msg.audio_ids.push_back(NEXT_STATION_DEPART_MR); //10503
            msg.audio_ids.push_back(station_data.audio_file_id_next_station_mr);
            for (const auto & id : skip_audio_id_msgs_mr)
            {
                msg.audio_ids.push_back(id);
            }

            //ShortLoop marathi
            CheckShortLoop(station_data, last_station_data, msg, Language::MARATHI);

            // Interchange station marathi
            CheckInterChangeStation(station_data, msg, AnnouncementType::DVA_ROUTE_END_DEPARTURE, Language::MARATHI);

            if (startFlg == AnnouncementType::DVA_ROUTE_START_DEPARTURE)
            {
                msg.audio_ids.push_back(WLCM_TO_MUMBAI_DEPART_EN); //20502
            }
            msg.audio_ids.push_back(last_station_audio_id_en);
            msg.audio_ids.push_back(NEXT_STATION_DEPART_EN); //20503
            msg.audio_ids.push_back(station_data.audio_file_id_next_station_en);
            for (const auto & id : skip_audio_id_msgs_en)
            {
                msg.audio_ids.push_back(id);
            }
            //ShortLoop english
            CheckShortLoop(station_data, last_station_data, msg, Language::ENGLISH);

            // Interchange station english
            CheckInterChangeStation(station_data, msg, AnnouncementType::DVA_ROUTE_END_DEPARTURE, Language::ENGLISH);

            m_state.m_current_station_id = -1;
            m_state.setOpenDoorState(0);

        }
        return true;
    }
    else
    {
        return false;
    }
}

// station id is db station id
void AnnouncementsPlay::PlayDoorCloseAnnouncemnt(int station_id, BroadcastMessage & msg)
{
    dva::StationData station_data;
    GetStationData(station_id, station_data);
    msg.title = "DVA_" + station_data.name_en + "_DoorCloseAnncmnt";

    msg.audio_ids.push_back(DINGDONG);
    msg.audio_ids.push_back(CLEAR_OFF_DOOR_MR); //10501
    msg.audio_ids.push_back(CLEAR_OFF_DOOR_EN); //20501
}

// station id is db station id
void AnnouncementsPlay::PlayDoorChime(int station_id, bool door_open_flg, BroadcastMessage & msg)
{
    std::string str = door_open_flg ? "Open" : "Close";

    if (door_open_flg)
    {
        dva::StationData station_data;
        GetStationData(station_id, station_data);
        msg.title = "DVA_" + station_data.name_en + "_DoorChime_" + str;

        //msg.audio_ids.push_back(DOOR_CHIME);
        msg.audio_ids.push_back(THIS_IS_MR); //10526
        msg.audio_ids.push_back(station_data.audio_file_id_next_station_mr);
        msg.audio_ids.push_back(STATION_MR); //10508
        msg.audio_ids.push_back(THIS_IS_EN); //20526
        msg.audio_ids.push_back(station_data.audio_file_id_next_station_en);
        msg.audio_ids.push_back(STATION_EN); //20508
    }
    else
    {
        int next_station_id = m_state.getNextStationIdAfter(station_id);
        dva::StationData station_data;
        GetStationData(next_station_id, station_data);
        msg.title = "DVA_" + station_data.name_en + "_DoorChime_" + str;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "door_close Chime Msg Title: " << msg.title << Trace::EndLog();
		
		// commented as next station announcement was no more required after door closing, only required when train leaves the platform
		// also modified put the DOOR_CHIME audio in script, so removing DOOR_CHIME from here
        //msg.audio_ids.push_back(DOOR_CHIME);
        //msg.audio_ids.push_back(NEXT_STATION_DEPART_MR); //10503
        //msg.audio_ids.push_back(station_data.audio_file_id_next_station_mr);
        //msg.audio_ids.push_back(NEXT_STATION_DEPART_EN); //20503
        //msg.audio_ids.push_back(station_data.audio_file_id_next_station_en);
    }
}

// station id is db station id
bool AnnouncementsPlay::PlayRouteStartDepartAnnouncement(int station_id, BroadcastMessage & msg)
{
    std::string station_name = m_dbId_stationId_map[station_id].name;
    auto it = m_dva_audio_handler->m_dva_audio_data.station_map.find(station_name);

    if (it != m_dva_audio_handler->m_dva_audio_data.station_map.end())
    {
        dva::StationData stationData = it->second;
        msg.title = stationData.name_en + "_" + "RouteStart";

        dva::StationData station_data;
        GetStationData(station_id, station_data);
        if (PlayNextStation(station_data, msg, AnnouncementType::DVA_ROUTE_START_DEPARTURE))
        {
            return true;
        }
    }
    return false;
}

bool AnnouncementsPlay::CheckSkipStation(const dva::StationData & station_data, BroadcastMessage & msg,
    std::vector<int>& skip_audio_id_msgs_mr, std::vector<int>& skip_audio_id_msgs_en)
{
    dva::StationData next_station_data;
    bool next_station_skip = GetNonSkipStationId(station_data, next_station_data);

    Trace::GetLogger().STAMP(Trace::VERBOSE) << " Skip Size > 0, current_skip_station_id: " << m_state.m_current_skip_station_id << Trace::EndLog();

    if (!next_station_skip) //m_state.m_skip_station_list.size() == m_state.m_current_skip_count)
    {
        msg.title = msg.title + "_SkipList";
        skip_audio_id_msgs_mr.push_back(SKIP_STATION_MR); //10509
        for (const auto & station_id : m_state.m_skip_station_map)
        {
            auto audio_id = GetMarathiStationNameAudioId(station_id.second);
            if (audio_id != -1)
            {
                skip_audio_id_msgs_mr.push_back(audio_id);
                skip_audio_id_msgs_mr.push_back(STATION_MR);
            }

        }
        skip_audio_id_msgs_en.push_back(SKIP_STATION_EN); //20509
        for (const auto & station_id : m_state.m_skip_station_map)
        {
            auto audio_id = GetEngStationNameAudioId(station_id.second);
            if (audio_id != -1)
            {
                skip_audio_id_msgs_en.push_back(audio_id);
                skip_audio_id_msgs_en.push_back(STATION_EN);
            }
        }
        Trace::GetLogger().STAMP(Trace::VERBOSE) << msg.title << Trace::EndLog();
    }
    else
    {
        msg.title = msg.title + "_SkipStation";
        if (next_station_data.station_id != -1)
        {
            m_state.m_current_skip_station_id = station_data.station_id;
            int index = m_state.m_skip_station_list[m_state.m_current_skip_station_id];
            m_state.m_skip_station_list.erase(m_state.m_current_skip_station_id);
            m_state.m_skip_station_map.erase(index);
            Trace::GetLogger().STAMP(Trace::INFO) << msg.title << " Current Skip station: " << station_data.name_en << ", Next Station: " << next_station_data.name_en << Trace::EndLog();
            skip_audio_id_msgs_mr.push_back(NO_STOP_NEXT_STATION_MR); //10510
            skip_audio_id_msgs_mr.push_back(next_station_data.audio_file_id_next_station_mr);
            skip_audio_id_msgs_en.push_back(NO_STOP_NEXT_STATION_EN); //20510
            skip_audio_id_msgs_en.push_back(next_station_data.audio_file_id_next_station_en);
        }
    }
    return next_station_skip;
}

bool AnnouncementsPlay::CheckInterChangeStation(const dva::StationData & stationData, BroadcastMessage & msg,
    AnnouncementType annoucement_type, Language language)
{
    const auto & interchange_station_itr = m_dva_audio_handler->m_dva_audio_data.interchange_station_map.find(stationData.name_en);
    if (interchange_station_itr != m_dva_audio_handler->m_dva_audio_data.interchange_station_map.end())
    {
        auto it_route = m_dva_audio_handler->m_dva_audio_data.route_id_map.find(m_state.m_route_id);
        if (it_route != m_dva_audio_handler->m_dva_audio_data.route_id_map.end())
        {
            auto from_line = it_route->second.line_code;
            auto it2 = interchange_station_itr->second.find(from_line);
            if (it2 != interchange_station_itr->second.end())
            {
                const dva::InterchangeStationData & interchange_data = it2->second;
                auto to_line = interchange_data.to_line;
                if (!to_line.empty())
                {
                    Trace::GetLogger().STAMP(Trace::INFO) << "Found Interchange station: " << stationData.name_en << "Interchange to New Line: " << to_line << Trace::EndLog();
                    if (language == Language::ENGLISH)
                    {
                        if (annoucement_type == AnnouncementType::DVA_ROUTE_END_DEPARTURE)
                            msg.audio_ids.push_back(CAN_INTERCHANGE_FOR_EN); //20512
                        else
                            msg.audio_ids.push_back(INTERCHANGE_HERE_FOR_EN); //20513
                        msg.audio_ids.push_back(interchange_data.audio_file_id_to_line_en);
                    }
                    else if (language == Language::MARATHI)
                    {
                        if (annoucement_type == AnnouncementType::DVA_ROUTE_END_DEPARTURE)
                            msg.audio_ids.push_back(CAN_INTERCHANGE_FOR_MR); //10512
                        else
                            msg.audio_ids.push_back(INTERCHANGE_HERE_FOR_MR); //10513
                        msg.audio_ids.push_back(interchange_data.audio_file_id_to_line_mr);
                    }
                    return true;
                }

            }
        }
    }
    return false;
}

bool AnnouncementsPlay::CheckShortLoop(const dva::StationData & station_data, const dva::StationData & last_station_data,
    BroadcastMessage & msg, Language language)
{
    if (m_state.m_short_loop)
    {
        auto station_db_id = ConvertXmlIdToDbId(station_data.station_id);
        auto it = m_state.m_short_loop_stations.find(station_db_id);
        if (it != m_state.m_short_loop_stations.end())
        {
            Trace::GetLogger().STAMP(Trace::INFO) << "ShortLoop Detected" << Trace::EndLog();
            if (language == Language::MARATHI)
            {
                auto station_name_audio_id = last_station_data.audio_file_id_next_station_mr;
                msg.audio_ids.push_back(station_name_audio_id);
                msg.audio_ids.push_back(TRAVEL_BEYOND_DEBOARD_PART_1_MR); //106
                msg.audio_ids.push_back(station_name_audio_id);
                msg.audio_ids.push_back(TRAVEL_BEYOND_DEBOARD_PART_2_MR); //107
                return true;
            }
            else if (language == Language::ENGLISH)
            {
                auto station_name_audio_id = last_station_data.audio_file_id_next_station_en;
                msg.audio_ids.push_back(TRAVEL_BEYOND_DEBOARD_PART_1_EN); //103
                msg.audio_ids.push_back(station_name_audio_id);
                msg.audio_ids.push_back(TRAVEL_BEYOND_DEBOARD_PART_2_EN); //104
                msg.audio_ids.push_back(station_name_audio_id);
                msg.audio_ids.push_back(TRAVEL_BEYOND_DEBOARD_PART_3_EN); //105
                return true;
            }
        }
    }
    return false;
}
