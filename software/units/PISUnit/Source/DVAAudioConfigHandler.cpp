//*****************************************************************************
//
// @file       DVAAudioConfigHandler.cpp
//
//             Defines the Audio Config Handler. It reads audio config file for stations, emergency, occ etc sounds.
//
//  Reference:      https://adl-atlassian.simulation.lan/confluence/display/BJSNA/PIS+-+Implementation
//
// @ingroup    DVAUnit
//
// @author     Yogesh Warad
//
// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017
//
//*****************************************************************************

#include "DVAAudioConfigHandler.h"
#include <common\StandardLogging.h>

namespace dva
{

//  Function:       DVAAudioConfigHandler
//
//  Description:    Constructor

DVAAudioConfigHandler::DVAAudioConfigHandler() 
{}

//  Function:       DVAAudioConfigHandler::StartElement
//
//  Description:    Handles each element as it comes in and packs it into the configuration data 
//                  structure, without any manipulation.

void DVAAudioConfigHandler::StartElement(const std::string &element_name, const FileAccess::XMLAttributes &attrs)
{
     //Top Element
    if(element_name == "AudioFile")
    {
        std::string file_name;
        int            file_id;
        DefineAttribute(attrs, L"ID", &file_id);
        //We will consider common audio files and audio files of current track only
        DefineAttribute(attrs, L"Name", &file_name);

        m_dva_audio_data.audio_file_map.insert(std::make_pair(file_id, file_name));
        Trace::GetLogger().STAMP(Trace::VERBOSE) << file_id  << "  " << file_name << Trace::EndLog();
    }
    else if(element_name == "Station")
    {   
        StationData station_data;

        DefineAttribute(attrs, L"ID", &station_data.station_id);
        DefineAttribute(attrs, L"Name_EN", &station_data.name_en);
        DefineAttribute(attrs, L"StationCode", &station_data.short_name); 
        DefineAttribute(attrs, L"LineCode", &station_data.line_code);
        DefineAttribute(attrs, L"AudioFileID_StationName_EN", &station_data.audio_file_id_station_name_en, -1);
        DefineAttribute(attrs, L"AudioFileID_Next_Station_EN", &station_data.audio_file_id_next_station_en, -1);
        DefineAttribute(attrs, L"AudioFileID_Terminal_Station_EN", &station_data.audio_file_id_terminal_station_en, -1);
        DefineAttribute(attrs, L"AudioFileID_StationName_MR", &station_data.audio_file_id_station_name_mr, -1);
        DefineAttribute(attrs, L"AudioFileID_Next_Station_MR", &station_data.audio_file_id_next_station_mr, -1);
        DefineAttribute(attrs, L"AudioFileID_Terminal_Station_MR", &station_data.audio_file_id_terminal_station_mr, -1);

        m_dva_audio_data.station_map.insert(std::make_pair(station_data.name_en, station_data));
        m_dva_audio_data.id_station_map.insert(std::make_pair(station_data.station_id, station_data));
        

    }
    else if (element_name == "Route")
    {
        RouteData route_data;

        DefineAttribute(attrs, L"ID", &route_data.route_id);
        DefineAttribute(attrs, L"Code", &route_data.route_code);
        DefineAttribute(attrs, L"LineCode", &route_data.line_code);
        DefineAttribute(attrs, L"Name", &route_data.line_name);
        DefineAttribute(attrs, L"StationSequence", &route_data.station_seq);
        m_dva_audio_data.route_id_map.insert(std::make_pair(route_data.route_id, route_data));
        m_dva_audio_data.route_name_map.insert(std::make_pair(route_data.route_code, route_data));

    }
    else if(element_name == "EmergencyMessage")
    {
        Message message_data;

        DefineAttribute(attrs, L"ID", &message_data.id);
        DefineAttribute(attrs, L"Code", &message_data.code);
        DefineAttribute(attrs, L"AudioFileID_MR", &message_data.audio_file_id_mr, 0);
        DefineAttribute(attrs, L"AudioFileID_EN", &message_data.audio_file_id_en, 0);

        m_dva_audio_data.emergency_message_map.insert(std::make_pair(message_data.id, message_data));
    }

    else if (element_name == "SpecialMessage")
    {
        Message message_data;

        DefineAttribute(attrs, L"ID", &message_data.id);
        DefineAttribute(attrs, L"Code", &message_data.code);
        DefineAttribute(attrs, L"AudioFileID_MR", &message_data.audio_file_id_mr, 0);
        DefineAttribute(attrs, L"AudioFileID_EN", &message_data.audio_file_id_en, 0);

        m_dva_audio_data.special_message_map.insert(std::make_pair(message_data.id, message_data));
    }

    else if (element_name == "OCCMessage")
    {
        Message message_data;

        DefineAttribute(attrs, L"ID", &message_data.id);
        DefineAttribute(attrs, L"Code", &message_data.code);
        DefineAttribute(attrs, L"AudioFileID_MR", &message_data.audio_file_id_mr, 0);
        DefineAttribute(attrs, L"AudioFileID_EN", &message_data.audio_file_id_en, 0);

        m_dva_audio_data.occ_message_map.insert(std::make_pair(message_data.id, message_data));
    }
    else if (element_name == "InterchangeStation")
    {
        InterchangeStationData interchange_data;
        DefineAttribute(attrs, L"StationID", &interchange_data.station_id);
        DefineAttribute(attrs, L"station", &interchange_data.interchange_station);
        DefineAttribute(attrs, L"FromLine", &interchange_data.from_line);
        DefineAttribute(attrs, L"ToLine", &interchange_data.to_line);
        DefineAttribute(attrs, L"FromStation", &interchange_data.from_station);
        DefineAttribute(attrs, L"ToStation", &interchange_data.to_station);
        DefineAttribute(attrs, L"ToLineAudio_mr", &interchange_data.audio_file_id_to_line_mr);
        DefineAttribute(attrs, L"ToLineAudio_en", &interchange_data.audio_file_id_to_line_en);

        std::map<std::string, InterchangeStationData> from_line_interchange_data_map;
        from_line_interchange_data_map.insert(std::make_pair(interchange_data.from_line, interchange_data));
        m_dva_audio_data.interchange_station_map.insert(std::make_pair(interchange_data.interchange_station, std::move(from_line_interchange_data_map)));
    }

}

//  Function:       DVAAudioConfigHandler::GetAudioFile
//
//  Description:    Searches for the audio file with the given ID and returns 
//                  the audio filename. If there is no audio file with the 
//                  requested ID an empty string is returned.
//
//  Parameters:
//      int file_id      - D of the requested audio file
//
//  Return value:
//      std::string      - Name of the requested audio file.

std::string DVAAudioConfigHandler::GetAudioFileName(int file_id) const
{
    // Search for the audio file with the requested file ID
    std::map<int, std::string>::const_iterator it = m_dva_audio_data.audio_file_map.find(file_id);

    if( it != m_dva_audio_data.audio_file_map.end() )
    {
        // Found the audio file, return the filename
        return it->second;
    }
    else
    {
        // No audio file with the requested ID, return an empty string
        return "";
    }
}

//  Function:       DVAAudioConfigHandler::GetStation
//
//  Description:    Returns the station with matching Code
//
//  Return value:
//    Station         Throws an Exception if not found.
StationData DVAAudioConfigHandler::GetStationData(const std::string station_code) const
{
    std::map<std::string, StationData>::const_iterator mapping = m_dva_audio_data.station_map.find(station_code);

    if (mapping == m_dva_audio_data.station_map.end())
    {
        throw InvalidParameterException(FLSTAMP) << "Could not find Station with code " << station_code;
    }

    return mapping->second;
}


//  Function:       DVAAudioConfigHandler::GetAudioId
//
//  Description:    Returns the audio id with matching code
//
//  Return value:
//    Station         Throws an Exception if not found.
std::string DVAAudioConfigHandler::GetAudioId(const int audio_id) const
{
    std::map<int, std::string>::const_iterator itr = m_dva_audio_data.audio_file_map.find(audio_id) ;

    if (itr == m_dva_audio_data.audio_file_map.end())
    {
        throw InvalidParameterException(FLSTAMP) << "Could not find Station with code " << audio_id;
    }

    return itr->second;
}


//  Function:       DVAAudioConfigHandler::GetEmergencyMessageData
//
//  Description:    Returns the message with matching Code
//
//  Return value:
//    Station         Throws an Exception if not found.
Message DVAAudioConfigHandler::GetEmergencyMessageData(const int message_code) const
{
    std::map<int, Message>::const_iterator mapping = m_dva_audio_data.emergency_message_map.find(message_code);

    if (mapping == m_dva_audio_data.emergency_message_map.end())
    {
        throw InvalidParameterException(FLSTAMP) << "Could not find message data for ID: " << message_code;
    }

    return mapping->second;
}

}