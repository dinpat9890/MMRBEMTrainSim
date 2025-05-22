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
		int platform_length;
    };

    //  Structure:      Message
    //
    //  Description:    Data that defines the mapping between AudioFile ID and Name.
    //
    //  Notes:          The Audio file section in the XML file also contains 
    //                  attributes Size and MD5hash.

    struct Message
    {
        std::string text;
        int         audio_file_id_cn;
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

        // Map of Audio data keyed on Station code
        std::map<std::string, StationData> station_map;

        // Map of Audio data keyed on emergency message (Specially Emergency code)
        std::map<int, Message> emergency_message_map;

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

    private:
        dva::DVAAudioConfigData m_dva_audio_data;
    };
}