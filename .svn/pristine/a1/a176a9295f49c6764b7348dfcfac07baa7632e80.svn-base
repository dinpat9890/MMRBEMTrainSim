///**************************************************************************************************
///  @file           MappedTrainInputs.h
///
///  Description:    Train model into the Platform Controller
///                  - Mapped Objects for interfacing with Train Comms Object properties
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

/// Stucture for interfacing with the Train comms object
struct MappedVehicleInputs : MappableObject
{
    // Train model into the Platform Controller
    double door_obstruction_close;

    // Map LMA Object outputs to Numbers
    void MapVehicleInputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Train::ClassID::VEHICLE);

        MapObject(object, request_frequency);
        Sim::Number number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_DOOR_CLOSE_OBSTRUCTION);
        object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), request_frequency);
        // Map Class Parameters to Numbers
        MapNumber(&door_obstruction_close, Project::ValueName::Vehicle::FLT_DOOR_CLOSE_OBSTRUCTION);
        RequestAndRetrieve();
    }

    void UnMapVehicleInputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }
};


#pragma once
