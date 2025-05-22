//**************************************************************************************************
//
//  File:           PISInterfaceProperties.cpp
//
//  Description:    Defines the PISInterfaceProperties class which provides consistent access to
//                  properties.
//
//  Reference:      https://adl-atlassian.simulation.lan/confluence/display/BJSNA/PIS+-+Implementation
//
// ingroup         DVAUnit
//
//  Author:         Yogesh Warad
//
//  (C) Copyright:  SYDAC Pty Ltd, 2017
//
//**************************************************************************************************

#include "PISInterfaceProperties.h"
#include "common/StandardLogging.h"


using namespace dva;
using namespace std;

namespace
{
    
    const char * const DEBUG_SECTION              = "Debug";
    const char * const PEI_DEBUG_KEY              = "PEI";
    const char * const TIMETABLE_DEBUG_KEY        = "Timetable";
    const char * const DVA_DEBUG_KEY              = "DVA";

    const char * const DVA_SECTION                = "DVA";
    const char * const PIS_SECTION                = "PIS";
    const char * const TRACK_NAME                 = "TRACK_NAME";
    const char * const AUDIO_ENGINE_ID            = "Audio Engine ID";
    const char * const MIN_MSG_GAP                = "Minimum Message Gap";
    const char * const LAST_MESSAGE_TIMESTAMP     = "Last Message Time Stamp";
    const char * const MAX_MSG_DURATION           = "Maximum Message Duration";
    const char * const WAVE_ID_OFFSET             = "Wave ID Offset";
    const char * const STATION_BROADCAST_PATH     = "Station Broadcast Directory";
    const char * const EMERGENCY_BROADCAST_PATH   = "Emergency Broadcast Directory";
    const char * const TRACK_SHL7_NAME            = "SHL7";
    const char * const TRACK_SHL9_NAME            = "SHL9";
    const char * const TRACK_SHL11_NAME           = "SHL11";
    const char * const STATION_LIST_FILE		  = "Station List File";
    const char * const SPEAKER_X_POSITION         = "Speaker X Position";
    const char * const SPEAKER_Y_POSITION         = "Speaker Y Position";
    const char * const SPEAKER_Z_POSITION         = "Speaker Z Position";

    const char * const TIMETABLE_SECTION          = "Timetable";

    const char * const DVA_ROUTE_CATEGORY         = "dva_route_category";
    const char * const DVA_ARRIVAL_CATEGORY       = "dva_arrival_category";
    const char * const DVA_STOP_CATEGORY          = "dva_stop_category";
    const char * const DVA_DEPARTURE_CATEGORY     = "dva_departure_category";
    const char * const DVA_SPECIAL_CATEGORY       = "dva_special_category";
    const char * const DVA_WELCOME_MSG_ID         = "dva_welcome_msg_id";

    const char * const PIS_AUDIO_SECTION          = "PISAudio";

    const char * const PA_TONE_TIMOUT_ID          = "pa_tone_timeout";

    const string DESTINATION_SECTION              = "Destination";
    const string NEXT_STATION_SECTION_CN          = "NextStationCN";
    const string NEXT_STATION_SECTION_EN          = "NextStationEN";
    const string EMERGENCY_SECTION                = "Emergency";

    const char * const TRAIN_BACKWORD_ANNOUNCEMENT_DISTACE = "Train Backward Announcement Distace";
    const char * const TRAIN_FORWARD_ANNOUNCEMENT_DISTACE  = "Train Forward Announcement Distace";
    const char * const PLATFORM_ANNOUNCEMENT_RANGE	 = "Platform Announcement Range";

    const auto MINIMUM_PATH_SIZE                  = 2;
}


//  Function:           Properties::GetAudioEngineID
//
//  Description:        Get the ID of the audio engine
//
//  Return value:
//      int - The ID defaults to 1

int Properties::GetAudioEngineID() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<int>(DVA_SECTION, AUDIO_ENGINE_ID, 1);
}


//  Function:           Properties::GetNextStationCN
//
//  Description:        Get the ID of the Chinese audio file for next station
//
//  Return value:
//      int - The ID defaults to 1

std::string Properties::GetNextStationCN(const string& NEXT_STATION_ID_CN) const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<std::string>(NEXT_STATION_SECTION_CN, NEXT_STATION_ID_CN, "383");
}

//  Function:           Properties::GetNextStationEN
//
//  Description:        Get the ID of the English audio file for next station
//
//  Return value:
//      int - The ID defaults to 1

std::string Properties::GetNextStationEN(const string& NEXT_STATION_ID_EN) const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<std::string>(NEXT_STATION_SECTION_EN, NEXT_STATION_ID_EN, "483");
}

//  Function:           Properties::GetNextStationEN
//
//  Description:        Get the ID of the English audio file for next station
//
//  Return value:
//      int - The ID defaults to 1

std::string Properties::GetEmergencyAnnouncement(const string& EMERGENCY_ANNOUNCEMENT_ID) const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<std::string>(EMERGENCY_SECTION, EMERGENCY_ANNOUNCEMENT_ID, "1");
}

//  Function:       Properties::GetMinimumMessageGap
//
//  Description:    Get the time in seconds that seperates two successive DVA 
//                  messages.
//
//  Return value:
//      double           - Minimum DVA message gap time in seconds.

double Properties::GetMinimumMessageGap() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<double>(DVA_SECTION, MIN_MSG_GAP, 2.0);
}

//  Function:       Properties::GetLastMessageTimeStamp
//
//  Description:    Get the time in seconds of last message timestamp 
//                  
//
//  Return value:
//      double           - Last DVA message timestamp in seconds.

double Properties::GetLastMessageTimeStamp() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<double>(DVA_SECTION, LAST_MESSAGE_TIMESTAMP, -2.0);
}


//  Function:       Properties::GetMaximumMessageDuration
//
//  Description:    Get the maximum duration of a DVA message in seconds. A  
//                  message played any longer will be deleted in order to 
//                  prevent the DVA unit to wait indefinitely for failed
//                  wav files to complete.
//
//  Return value:
//      double           - Maximum DVA message duration time in seconds.

double Properties::GetMaximumMessageDuration() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<double>(DVA_SECTION, MAX_MSG_DURATION, 300.0);
}

//  Function:       Properties::GetWaveIDOffset
//
//  Description:    Get the offset for Wave object ID numbering, used to avoid 
//                  ID clashes with scripted Wave objects.
//
//  Return value:
//      int              - Wave ID numbering offset for DVA wave objects.

int Properties::GetWaveIDOffset() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<int>(DVA_SECTION, WAVE_ID_OFFSET, 10000);
}

//  Function:       Properties::GetDVAStationBroadcastPath
//
//  Description:    Get the path of the directory containing the DVA sound files for station broadcast.
//
//  Return value:
//      std::string     - Path to DVA sound files for station broadcast.
//
//  Notes:          The path is returned with an \ at the end except for empty strings.

std::string Properties::GetDVAStationBroadcastPath() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    std::string path = m_properties.GetProperty<std::string>(DVA_SECTION, STATION_BROADCAST_PATH, "Sounds\\StationBroadcast");

    // Ensure the last character is '\'
    if(path.empty() || path.size() < MINIMUM_PATH_SIZE)
        Trace::GetLogger().STAMP(Trace::WARN) << "No sound data path is set" << Trace::EndLog();    
    else if(path[path.size()-2] != '\\')
        path += "\\";

    return path;
}


//  Function:       Properties::GetDVAEmergencyBroadcastDataPath
//
//  Description:    Get the path of the directory containing the DVA sound files for emergency broadcast.
//
//  Return value:
//      std::string     - Path to DVA sound files for emergency broadcast.
//
//  Notes:          The path is returned with an \ at the end except for empty strings.

std::string Properties::GetDVAEmergencyBroadcastDataPath() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    std::string path = m_properties.GetProperty<std::string>(DVA_SECTION, EMERGENCY_BROADCAST_PATH, "Sounds\\EmergencyBroadcast");

    // Ensure the last character is '\'
    if(path.empty() || path.size() < MINIMUM_PATH_SIZE)
        Trace::GetLogger().STAMP(Trace::WARN) << "No sound data path is set" << Trace::EndLog();    
    else if(path[path.size()-2] != '\\')
        path += "\\";

    return path;
}


//  Function:       Properties::GetStationListFile
//
//  Description:    Get the path of the directory containing the DVA sound files for emergency broadcast.
//
//  Return value:
//      std::string     - Path to DVA sound files for emergency broadcast.
//
//  Notes:          The path is returned with an \ at the end except for empty strings.

std::string Properties::GetStationListFile() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<std::string>(PIS_SECTION, STATION_LIST_FILE, "PIS\\PIS_Station_List.xml");
}

//  Function:       Properties::GetPlatformAnnouncementRange
//
//  Description:    Get the range of the platform for At Platform Announcement
//
//  Return value:
//      double     - Range of the platform for At Platform Announcement
//
//  Notes:          The path is returned with an \ at the end except for empty strings.

double Properties::GetPlatformAnnouncementRange() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<double>(PIS_SECTION, PLATFORM_ANNOUNCEMENT_RANGE, 25.0);
}

//  Function:       Properties::GetTrainBackwordAnnouncementDistace
//
//  Description:    Get the  
//
//  Return value:
//      std::string     - Path to DVA sound files for emergency broadcast.
//
//  Notes:          The path is returned with an \ at the end except for empty strings.

double Properties::GetTrainBackwordAnnouncementDistace() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<double>(PIS_SECTION, TRAIN_BACKWORD_ANNOUNCEMENT_DISTACE, 70.0);
}

//  Function:       Properties::GetPlatformAnnouncementRange
//
//  Description:    Get the range of the platform for At Platform Announcement
//
//  Return value:
//      std::string     - Path to DVA sound files for emergency broadcast.
//
//  Notes:          The path is returned with an \ at the end except for empty strings.

double Properties::GetTrainForwordAnnouncementDistace() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<double>(PIS_SECTION, TRAIN_FORWARD_ANNOUNCEMENT_DISTACE, 100.0);
}

//  Function:       Properties::GetTrackSHL7Name
//
//  Description:    Get the Track name of line 7. Defalult is "SHL7".
//
//  Return value:
//      std::string     - Track name of line 7 

std::string Properties::GetTrackSHL7Name() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<std::string>(TRACK_NAME, TRACK_SHL7_NAME, TRACK_SHL7_NAME);
}

//  Function:       Properties::GetTrackSHL9Name
//
//  Description:    Get the Track name of line 9. Defalult is "SHL9".
//
//  Return value:
//      std::string     - Track name of line 9 

std::string Properties::GetTrackSHL9Name() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<std::string>(TRACK_NAME, TRACK_SHL9_NAME, TRACK_SHL9_NAME);
}

//  Function:       Properties::GetTrackSHL11Name
//
//  Description:    Get the Track name of line 11. Defalult is "SHL11".
//
//  Return value:
//      std::string     - Track name of line 11 

std::string Properties::GetTrackSHL11Name() const
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << __FUNCTION__ << Trace::EndLog(); 
    return m_properties.GetProperty<std::string>(TRACK_NAME, TRACK_SHL11_NAME, TRACK_SHL11_NAME);
}

//  Function:       Properties::GetSpeakerXPosition
//
//  Description:    Get the X position of the DVA speaker relative to the 
//                  Observer. Defaults to 0.
//
//  Return value:
//      double           - X position of DVA speaker relative to observer.

double Properties::GetSpeakerXPosition() const
{
    return m_properties.GetProperty<double>(DVA_SECTION, SPEAKER_X_POSITION, 0.0);
}


//  Function:       Properties::GetSpeakerXPosition
//
//  Description:    Get the Y position of the DVA speaker relative to the 
//                  Observer. Defaults to 0.
//
//  Return value:
//      double           - Y position of DVA speaker relative to observer.

double Properties::GetSpeakerYPosition() const
{
    return m_properties.GetProperty<double>(DVA_SECTION, SPEAKER_Y_POSITION, 0.0);
}


//  Function:       Properties::GetSpeakerXPosition
//
//  Description:    Get the Z position of the DVA speaker relative to the 
//                  Observer. Defaults to 0.
//
//  Return value:
//      double           - Z position of DVA speaker relative to observer.

double Properties::GetSpeakerZPosition() const
{
    return m_properties.GetProperty<double>(DVA_SECTION, SPEAKER_Z_POSITION, 0.0);
}


//  Function:           Properties::IsPEIDebugEnabled
//
//  Description:        Get if the PEI unit Debug flag is set
//
//  Return value:
//      bool - true if it is enabled

bool Properties::IsPEIDebugEnabled() const
{
    return (m_properties.GetProperty<int>(DEBUG_SECTION, PEI_DEBUG_KEY, 0) != 0);
}

//  Function:           Properties::GetPEIDebugLevel
//
//  Description:        Get the PEI Debug level is set
//
//  Return value:
//      bool - true if it is enabled

int Properties::GetPEIDebugLevel() const
{
    return m_properties.GetProperty<int>(DEBUG_SECTION, PEI_DEBUG_KEY, 0);
}

//  Function:           Properties::IsTimetableDebugEnabled
//
//  Description:        Get if the Timetable unit Debug flag is set
//
//  Return value:
//      bool - true if it is enabled

bool Properties::IsTimetableDebugEnabled() const
{
    return (m_properties.GetProperty<int>(DEBUG_SECTION, TIMETABLE_DEBUG_KEY, 0) != 0);
}

//  Function:           Properties::GetTimetableDebugLevel
//
//  Description:        Get if the Timetable unit Debug flag is set
//
//  Return value:
//      bool - true if it is enabled

int Properties::GetTimetableDebugLevel() const
{
    return m_properties.GetProperty<int>(DEBUG_SECTION, TIMETABLE_DEBUG_KEY, 0);
}

//  Function:           Properties::IsDVADebugEnabled
//
//  Description:        Get the DVA Unit Debug Enabled flag is set
//
//  Return value:
//      bool - true if it is enabled

bool Properties::IsDVADebugEnabled() const
{
    return m_properties.GetProperty<bool>(DEBUG_SECTION, DVA_DEBUG_KEY, false);
}

//  Function:           Properties::GetDVADebugLevel
//
//  Description:        Get if the DVA unit Debug flag is set
//
//  Return value:
//      bool - true if it is enabled

int Properties::GetDVADebugLevel() const
{
    return m_properties.GetProperty<int>(DEBUG_SECTION, DVA_DEBUG_KEY, 0);
}

//  Function:           Properties::GetDVARouteCategory
//
//  Description:        Get the Route Message Category
//
//  Return value:
//      std::string     Category

std::string Properties::GetDVARouteCategory() const
{
    return m_properties.GetProperty<std::string>(TIMETABLE_SECTION, DVA_ROUTE_CATEGORY, "Route");
}

//  Function:           Properties::GetDVAArrivalCategory
//
//  Description:        Get the Arrival Message Category
//
//  Return value:
//      std::string     Category

std::string Properties::GetDVAArrivalCategory() const
{
    return m_properties.GetProperty<std::string>(TIMETABLE_SECTION, DVA_ARRIVAL_CATEGORY, "Arrival");
}

//  Function:           Properties::GetDVAStopCategory
//
//  Description:        Get the Stop Message Category
//
//  Return value:
//      std::string     Category

std::string Properties::GetDVAStopCategory() const
{
    return m_properties.GetProperty<std::string>(TIMETABLE_SECTION, DVA_STOP_CATEGORY, "Stop");
}

//  Function:           Properties::GetDVADepartureCategory
//
//  Description:        Get the Departure Message Category
//
//  Return value:
//      std::string     Category

std::string Properties::GetDVADepartureCategory() const
{
    return m_properties.GetProperty<std::string>(TIMETABLE_SECTION, DVA_DEPARTURE_CATEGORY, "Departure");
}

//  Function:           Properties::GetDVASpecialCategory
//
//  Description:        Get the Special Message Category
//
//  Return value:
//      std::string     Category

std::string Properties::GetDVASpecialCategory() const
{
    return m_properties.GetProperty<std::string>(TIMETABLE_SECTION, DVA_SPECIAL_CATEGORY, "Special");
}

//  Function:           Properties::GetDVAWelcomeMessageID
//
//  Description:        Get ID of the Welcome Message (the Special Message Category)
//
//  Return value:
//      std::string     ID This will throw if its not defined in the config file as it is the most likely to change

std::string Properties::GetDVAWelcomeMessageID() const
{
    return m_properties.GetProperty<std::string>(TIMETABLE_SECTION, DVA_WELCOME_MSG_ID);
}


    //  Function:           Properties::GetPAToneTimeout
//
//  Description:        Time to wait for PA tone to complete playing before connecting PA to handset
//
//  Return value:
//      double          Timeout in seconds (Default = 5 seconds) 

double Properties::GetPAToneTimeout() const
{
    return m_properties.GetProperty<double>(PIS_AUDIO_SECTION, PA_TONE_TIMOUT_ID,5);
}


