///**************************************************************************************************
///  @file           MappedCBTCVehicleOutputs.h
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

/// Stucture for interfacing with the CBTC Vehicle Ouput comms object
struct MappedCBTCVehicleOutputs : MappableObject
{
    // CBTC Train Model Interface into the Platform Controller
    double lhs_door_open_request;
    double rhs_door_open_request;
    double lhs_door_close_request;
    double rhs_door_close_request;
    double train_door_closed_and_locked;
    double tbc_poisition;
    double atc_bypass_state;
    double no_door_enable_bypass;
    double mode_selector_position;

    // Map CBTC Vehicle Outputs Object to Numbers
    void MapCBTCVehicleOutputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_OUTPUTS);

        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&lhs_door_open_request, Project::ValueName::CBTCVehicleOutputs::LEFT_SIDE_DOOR_OPEN_REQUEST);
        MapNumber(&rhs_door_open_request, Project::ValueName::CBTCVehicleOutputs::RIGHT_SIDE_DOOR_OPEN_REQUEST);
        MapNumber(&lhs_door_close_request, Project::ValueName::CBTCVehicleOutputs::LEFT_SIDE_DOOR_CLOSE_REQUEST);
        MapNumber(&rhs_door_close_request, Project::ValueName::CBTCVehicleOutputs::RIGHT_SIDE_DOOR_CLOSE_REQUEST);
        MapNumber(&train_door_closed_and_locked, Project::ValueName::CBTCVehicleOutputs::TRAIN_DOOR_CLOSED_AND_LOCKED);
        MapNumber(&atc_bypass_state, Project::ValueName::CBTCVehicleOutputs::ATC_BYPASS_STATE);
        MapNumber(&no_door_enable_bypass, Project::ValueName::CBTCVehicleOutputs::NO_DOOR_ENABLE_BYPASS);
        MapNumber(&mode_selector_position, Project::ValueName::CBTCVehicleOutputs::MODE_SELECTOR_POSITION);
        MapNumber(&tbc_poisition, Project::ValueName::CBTCVehicleOutputs::TBC_POSITION);
        RequestAndRetrieve();
    }

    void UnMapCBTCVehicleOutputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }
};
