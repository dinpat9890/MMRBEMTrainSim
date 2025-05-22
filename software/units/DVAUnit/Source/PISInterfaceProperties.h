//**************************************************************************************************
//
//  File:           PISInterfaceProperties.h
//
//  Description:    Declares the PISInterfaceProperties class which provides consistent access to
//                  properties.
//
//  Reference:      https://adl-atlassian.simulation.lan/confluence/display/BJSNA/PIS+-+Implementation
//
//  ingroup         DVAUnit
//
//  Author:         Yogesh Warad
//
//  (C) Copyright:  SYDAC Pty Ltd, 2017
//
//**************************************************************************************************

#pragma once

#include "core_properties/CommonProperties.h"

#include <vector>
#include <string>

namespace dva
{
    

    //  Class:          Properties
    //
    //  Description:    Provides consistent access to PIS property file data. 
    
    class Properties
    {
    public:
        Properties(const Common::Properties &properties)
            : m_properties(properties)
        { }

        int                                 GetAudioEngineID() const;
        std::string                         GetNextStationCN(const std::string& nextstation_cn) const;
        std::string                         GetNextStationEN(const std::string& nextstation_en) const;
        std::string                         GetEmergencyAnnouncement(const std::string& emergencyannouncementid) const;
        double                              GetMinimumMessageGap() const;
        double                              GetMaximumMessageDuration() const;
        std::string                         GetDVAStationBroadcastPath() const;
        std::string                         GetDVAEmergencyBroadcastDataPath() const;
        std::string                         GetStationListFile() const;
        double                              GetPlatformAnnouncementRange() const;
        double                              GetTrainBackwordAnnouncementDistace() const;
        double                              GetTrainForwordAnnouncementDistace() const;
        std::string                         GetTrackSHL7Name() const;
        std::string                         GetTrackSHL9Name() const;
        std::string                         GetTrackSHL11Name() const;
        int                                 GetWaveIDOffset() const;
        double                              GetSpeakerXPosition() const;
        double                              GetSpeakerYPosition() const;
        double                              GetSpeakerZPosition() const;
        double                              GetLastMessageTimeStamp() const;

        // Debug Properties
        bool                                IsTimetableDebugEnabled() const;
        int                                 GetPEIDebugLevel() const;
        bool                                IsPEIDebugEnabled() const;
        int                                 GetTimetableDebugLevel() const;
        bool                                IsDVADebugEnabled() const; //F
        int                                 GetDVADebugLevel() const; //F

        // Timetable Unit Properties
        std::string                         GetDVARouteCategory() const;
        std::string                         GetDVAArrivalCategory() const;
        std::string                         GetDVAStopCategory() const;
        std::string                         GetDVADepartureCategory() const;
        std::string                         GetDVASpecialCategory() const;
        std::string                         GetDVAWelcomeMessageID() const;

        // PIS Audio Properties (In PEI unit)
        double                              GetPAToneTimeout() const;

    private:
        const Common::Properties &m_properties;
    };
}
