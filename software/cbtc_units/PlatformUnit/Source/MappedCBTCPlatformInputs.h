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
#include "sim_comms/Object.h"

#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_comms_structure/CoreObjectConstants.h"

/// Stucture for interfacing with the CBTC Platform Inputs comms object
struct MappedCBTCPlatformInputs : MappableObject
{
    // Platform Controller Interface out to the DMI
    int lhs_sd_open_inhibit_code;
    int rhs_sd_open_inhibit_code;
    int lhs_sd_close_inhibit_code;
    int rhs_sd_close_inhibit_code;
    int    psd_open_req;
    int    psd_close_req;
    int    psd_interlock_override;
    double psd_not_working;
    double psd_close_fault;

    // Map CBTC Platform Output Object outputs to Numbers and Raws
    void MapCBTCPlatformInputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Project::ClassID::CBTC_PLATFORM_INPUTS);

        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&lhs_sd_open_inhibit_code, Project::ValueName::CBTCPlatformInputs::LHS_SD_OPEN_INHIBIT_CODE);
        MapNumber(&rhs_sd_open_inhibit_code, Project::ValueName::CBTCPlatformInputs::RHS_SD_OPEN_INHIBIT_CODE);
        MapNumber(&lhs_sd_close_inhibit_code, Project::ValueName::CBTCPlatformInputs::LHS_SD_CLOSE_INHIBIT_CODE);
        MapNumber(&rhs_sd_close_inhibit_code, Project::ValueName::CBTCPlatformInputs::RHS_SD_CLOSE_INHIBIT_CODE);
        MapNumber(&psd_not_working, Project::ValueName::CBTCPlatformInputs::PSD_NOT_WORKING);
        MapNumber(&psd_close_fault, Project::ValueName::CBTCPlatformInputs::PSD_CLOSE_FAULT);
        MapNumber(&psd_open_req, Project::ValueName::CBTCPlatformInputs::PLATFORM_DOOR_OPEN_REQUEST);
        MapNumber(&psd_close_req, Project::ValueName::CBTCPlatformInputs::PLATFORM_DOOR_CLOSE_REQUEST);
        MapNumber(&psd_interlock_override, Project::ValueName::CBTCPlatformInputs::PLATFORM_DOOR_INTERLOCK_OVERRIDE);
        RequestAndRetrieve();
    }

    void UnMapCBTCPlatformInputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }
};


#pragma once
