//*****************************************************************************
//
// @file       DVAAudioConfigHandler.h
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
//
//*****************************************************************************

#pragma once

#include "file_access/XMLHandler.h"
#include <map>

namespace dva
{
    //  Structure:      Station
    //
    //  Description:    Data that defines a Station
    //
    //  Notes:          The audio_id is initialized later by looking up the mapping
    //                  between station id and audio id from the dictionary xml file.
    //                  It is not included in the timetable xml file to avoid duplication.

    struct StationData
    {
        int station_id;
        std::string name_en;
        std::string short_name;
        std::string line_code;
        int audio_file_id_station_name_en;
        int audio_file_id_next_station_en;
        int audio_file_id_terminal_station_en;
        int audio_file_id_station_name_mr;
        int audio_file_id_next_station_mr;
        int audio_file_id_terminal_station_mr;
        int platform_length;
    };

    struct RouteData
    {
        int route_id;
        std::string route_code;
        std::string line_code;
        std::string line_name;
        std::string station_seq;
    };

    struct InterchangeStationData
    {
        int station_id;
        std::string interchange_station;
        std::string from_line;
        std::string to_line;
        std::string from_station;
        int audio_file_id_to_line_mr;
        int audio_file_id_to_line_en;
        std::string to_station;
    };

    //  Structure:      Message
    //
    //  Description:    Data that defines the mapping between AudioFile ID and Name.
    //
    //  Notes:          The Audio file section in the XML file also contains 
    //                  attributes Size and MD5hash.

    struct Message
    {
        int         id;
        std::string code;
        int         audio_file_id_mr;
        int         audio_file_id_en;
    };

    //  Structure:      DVAAudioConfigData
    //
    //  Description:    Configuration data required to build the sound 
    //                  representation of DVA messages.

    struct DVAAudioConfigData
    {
        // Map of Audio File Keyed on Audio ID
        std::map<int, std::string> audio_file_map;

        // Map for station data based on key = station name
        std::map<std::string, StationData> station_map;

        // Map for station data based on key = station id
        std::map<int, StationData> id_station_map;

        // Map of Audio data keyed on emergency message (Specially Emergency code)
        std::map<int, Message> emergency_message_map;

        // Map of Audio data keyed on special message (Specially Emergency code)
        std::map<int, Message> special_message_map;


        // Map of Audio data keyed on special message (Specially Emergency code)
        std::map<int, Message> occ_message_map;

        //Route Map, route id as a key
        std::map<int, RouteData> route_id_map;

        //Route Map, route code as a key
        std::map < std::string, RouteData> route_name_map;

        //Interchange Map, interchange station as a key and FromLine as a key for internal map
        std::map < std::string, std::map<std::string, InterchangeStationData>> interchange_station_map;

    };

    //  Class:          DVAAudioConfigHandler 
    //
    //  Description:    Reader of PIS DIctionary XML configuration files

    class DVAAudioConfigHandler : public FileAccess::XMLHandler
    {
    public:
        DVAAudioConfigHandler(); 
        // Overload the Interface Function
        void        StartElement(const std::string &element_name, const FileAccess::XMLAttributes &attrs) override;

        // Our Access Functions
        std::string GetAudioFileName(int file_id) const;
        StationData GetStationData(const std::string station_code) const;
        std::string GetAudioId(const int audio_id) const;
        Message     GetEmergencyMessageData(const int message_code) const;

        dva::DVAAudioConfigData m_dva_audio_data;
    };
}