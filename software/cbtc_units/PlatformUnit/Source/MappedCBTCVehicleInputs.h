///**************************************************************************************************
///  @file           MappedCBTCVehicleInputs.h
///
///  Description:    Train Model Interface into the Platform Controller
///                  - Mapped Objects for interfacing with CBTC Vehicle Outputs Comms Object properties
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

/// Stucture for interfacing with the CBTC Vehicle Input comms object
struct MappedCBTCVehicleInputs : MappableObject
{
    double lhs_auto_door_open_request;
    double rhs_auto_door_open_request;
    double lhs_door_enable;
    double rhs_door_enable;
    double atc_bypass_state;

    // Map CBTC Vehicle Inputs Object to Numbers
    void MapCBTCVehicleInputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_INPUTS);

        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&lhs_auto_door_open_request, Project::ValueName::CBTCVehicleInputs::OPEN_LEFT_TRAIN_DOORS);
        MapNumber(&rhs_auto_door_open_request, Project::ValueName::CBTCVehicleInputs::OPEN_RIGHT_TRAIN_DOORS);
        MapNumber(&lhs_door_enable, Project::ValueName::CBTCVehicleInputs::LEFT_SIDE_DOOR_ENABLE);
        MapNumber(&rhs_door_enable, Project::ValueName::CBTCVehicleInputs::RIGHT_SIDE_DOOR_ENABLE);
        RequestAndRetrieve();
    }

    void UnMapCBTCVehicleInputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }
};
