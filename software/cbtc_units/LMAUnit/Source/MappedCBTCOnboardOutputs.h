///**************************************************************************************************
///  @file           MappedCBTCOnboardOutputs.h
///
///  Description:    Mapped Objects for interfacing with CBTC Onboard Outputs Comms Object properties
///
///  @author         Adam Zielinski
///
///  @copyright      (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************
#pragma once

#include "project/Utilities/MappableObject.h"

#include "Utility/Utilities.h"

#include "sim_comms/Object.h"
#include "sim_comms/Object.h"

#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_comms_structure/CoreObjectConstants.h"

/// Stucture for interfacing with the CBTC Onboard Output comms object
struct MappedCBTCOnboardOutputs : MappableObject
{
    // CBTC Onboard Interface into the Platform Controller
    double current_driving_mode;

    // Map CBTC Onboard Output Object outputs to Numbers
    void MapCBTCOnboardOutputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_OUTPUTS);

        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&current_driving_mode, Project::ValueName::CBTCOnboardOutputs::CURRENT_DRIVING_MODE);

        RequestAndRetrieve();
    }

    void UnMapCBTCOnboardOutputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }
};