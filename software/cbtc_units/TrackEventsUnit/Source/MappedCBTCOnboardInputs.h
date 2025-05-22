///**************************************************************************************************
///  @file           MappedCBTCOnboardInputsObject.h
///
///  Description:    A Mapped Object for interfacing with CBTCOnboardInputs Comms Object properties
///
///  @author         Adam Zielinski
///
///  @copyright      (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************

#pragma once

#include "Project/Utilities/MappableObject.h"

#include "sim_comms/Object.h"

#include "project_comms_structure\ProjectObjectConstants.h"

#include "Protobuf/CBTCOnboard.pb.h"

#include "Utility/Utilities.h"


/// Provides the interface to the properties belonging to the CBTC Onboard Inputs Comms object
///
struct MappedCBTCOnboardInputsObject : MappableObject 
{
    static const bool DEBUG = false;

    // Members Variables to map CBTC Onboard Input object properties
    std::string track_event_raw;

    void MapCBTCOnboardInputsObject(Comms::Object &object, double request_frequency)
    {
        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapRaw(&track_event_raw, Project::ValueName::CBTCOnboardInputs::TRACK_EVENTS);

        RequestAndRetrieve();
    }

    void UnMapCBTCOnboardInputsObject()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }

    void SetTrackEventsRaw(double                                                    current_train_position,
                           std::map<double, CBTC::Protos::TrackEventList_TrackEvent> track_events)
    {
        CBTC::Protos::TrackEventList track_event_list;

        track_event_list.set_reference_train_position(current_train_position);

        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::ERR) << "TrackEventsUnit -------> \n" ;

        for (auto &track_event_data : track_events)
        {
            auto track_event = track_event_list.add_track_event_list();
            track_event->CopyFrom(track_event_data.second);

            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR)
                    << track_event_data.second.distance() << "  " << static_cast<int>(track_event_data.second.event())
                    << " " << (track_event_data.second.has_length() ? track_event_data.second.length() : -1.0)
                    << " " << (track_event_data.second.has_station_code() ? track_event_data.second.station_code() : " ") << "\n";


        }

        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::ERR)  << Trace::EndLog();

        track_event_list.SerializeToString(&track_event_raw);
    }
};

