///**************************************************************************************************
///  @file           MappedCBTCOnboardOutputs.h
///
///  Description:    Platform Controller Interface out to the DMI
///                  - Mapped Objects for interfacing with CBTC Onboard Outputs Comms Object properties
///
///  @author         Adam Zielinski
///
///  @copyright      (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************
#pragma once

#include "project/Utilities/MappableObject.h"

#include "Protobuf/CBTCOnboard.pb.h"

#include "Utility/Utilities.h"

#include "sim_comms/Object.h"

#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_comms_structure/CoreObjectConstants.h"

/// Stucture for interfacing with the CBTC Onboard Output comms object
struct MappedCBTCPlatformOutputs : MappableObject
{
    // Platform Controller Interface out to the DMI
    double      train_door_status;
    double      psd_door_status;
    double      departure_order;
    double      psd_interlock_override_status;
    double      train_docking_status;
    std::string departure_information_string;
    std::string train_docking_info_string;
    std::string current_station_name;

    // Map CBTC Platform Output Object outputs to Numbers and Raws
    void MapCBTCPlatformOutputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Project::ClassID::CBTC_PLATFORM_OUTPUTS);

        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&train_door_status, Project::ValueName::CBTCPlatformOutputs::TRAIN_DOOR_STATUS);
        MapNumber(&psd_door_status, Project::ValueName::CBTCPlatformOutputs::PSD_DOOR_STATUS);
        MapNumber(&departure_order, Project::ValueName::CBTCPlatformOutputs::DEPARTURE_ORDER);
        MapNumber(&psd_interlock_override_status, Project::ValueName::CBTCPlatformOutputs::PSD_INTERLOCK_OVERRIDE_STATUS);
        MapNumber(&train_docking_status, Project::ValueName::CBTCPlatformOutputs::TRAIN_DOCKING_STATUS);
        
        // Map Class Parameters to Raws
        MapRaw(&departure_information_string, Project::ValueName::CBTCPlatformOutputs::DEPARTURE_INFORMATION);
        MapRaw(&train_docking_info_string, Project::ValueName::CBTCPlatformOutputs::TRAIN_DOCKING_INFO);
        MapRaw(&current_station_name, Project::ValueName::CBTCPlatformOutputs::CURRENT_STATION_NAME);

        RequestAndRetrieve();
    }

    void UnMapCBTCPlatformOutputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }

    void SetDepartureInfoRaw(CBTC::Protos::DepartureInformation_DepartureStatus departure_status,
                             int                                                remaining_dwell_time)
    {
        CBTC::Protos::DepartureInformation departure_info;

        departure_info.set_departurestatus(departure_status);
        departure_info.set_remainingtimebeforedeparture(remaining_dwell_time);

        departure_info.SerializeToString(&departure_information_string);

     //   Trace::GetLogger().STAMP(Trace::INFO) << "departure_status - " << departure_status << Trace::EndLog();
     //   Trace::GetLogger().STAMP(Trace::INFO) << "remaining_dwell_time - " << remaining_dwell_time << Trace::EndLog();
    }

    void SetTrainDockingInfoRaw(CBTC::Protos::TrainDockingInfo_TrainDockingStatus train_docking_status,
                                int                                               stopping_distance)
    {
        CBTC::Protos::TrainDockingInfo train_docking_info;

        train_docking_info.set_traindockingstatus(train_docking_status);
        train_docking_info.set_stoppingpointdisatnce(stopping_distance);

        train_docking_info.SerializeToString(&train_docking_info_string);


     //   Trace::GetLogger().STAMP(Trace::INFO) << "train_docking_status - " << train_docking_status << Trace::EndLog();
     //   Trace::GetLogger().STAMP(Trace::INFO) << "stopping_distance - " << stopping_distance << Trace::EndLog();
    }
};


#pragma once
