///**************************************************************************************************
///  @file           MappedCBTCOnboardInputs.h
///
///  Description:    Platform Controller Interface out to the CBTC Onboard
///                  - Mapped Objects for interfacing with CBTC Onboard Inputs Comms Object properties
///
///  @author         Adam Zielinski
///
///  @copyright      (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************

#pragma once

#include "project/Utilities/MappableObject.h"

#include "Utility/Utilities.h"

#include "sim_comms/Object.h"

#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_comms_structure/CoreObjectConstants.h"

/// Stucture for interfacing with the CBTC Onboard Input comms object
struct MappedCBTCOnboardInputs : MappableObject
{
    // Platform Controller Interface out to the CBTC Onboard
    double platform_status;
    double train_near_platform;
    double psd_present;
    double lhs_platform_detection;
    double rhs_platform_detection;
    double depot_region;
	double atp_zone_region;

    // Map CBTC Onboard Inputs Object outputs to Numbers
    void MapCBTCOnboardInputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS);

        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&platform_status, Project::ValueName::CBTCOnboardInputs::PLATFORM_STATUS);
        MapNumber(&train_near_platform, Project::ValueName::CBTCOnboardInputs::TRAIN_NEAR_PLATFORM);
        MapNumber(&psd_present, Project::ValueName::CBTCOnboardInputs::PSD_PRESENT);
        MapNumber(&lhs_platform_detection, Project::ValueName::CBTCOnboardInputs::LHS_PLATFORM_DETECTION);
        MapNumber(&rhs_platform_detection, Project::ValueName::CBTCOnboardInputs::RHS_PLATFORM_DETECTION);
        MapNumber(&depot_region, Project::ValueName::CBTCOnboardInputs::DEPOT_REGION);
        MapNumber(&atp_zone_region, Project::ValueName::CBTCOnboardInputs::ATP_ZONE_REGION);
        RequestAndRetrieve();
    }

    void UnMapCBTCOnboardInputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }
};


