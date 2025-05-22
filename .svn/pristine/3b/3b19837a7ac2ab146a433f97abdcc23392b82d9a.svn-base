///**************************************************************************************************
///  @file           MappedCCTVInputs.h
///
///  Description:    Platform Controller into the CCTV Unit
///                  - Mapped Objects for interfacing with CCTV Inputs Comms Object properties
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

/// Stucture for interfacing with the CCTV Input comms object
struct MappedCCTVInputs : MappableObject
{
    double platform_cctv;

    const double PLATFORM_NOT_PRESENT = 0;
    const double PLATFORM_PRESENT = 1;
    const double LEAVING_PLATFORM = 2;

    // Map CBTC Vehicle Inputs Object to Numbers
    void MapCCTVInputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Project::ClassID::CCTV_INPUTS_VALUES);

        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&platform_cctv, Project::ValueName::CCTVInputsValues::PLATFORM_CCTV);

        RequestAndRetrieve();
    }

    void UnMapCCTVInputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }
};
