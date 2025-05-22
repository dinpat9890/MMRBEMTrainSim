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
struct MappedTrainInputs : MappableObject
{
    // Train model into the Platform Controller
    double train_speed;
	double m_fault_adcl_status_not_available;

    // Map LMA Object outputs to Numbers
    void MapTrainInputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Train::ClassID::TRAIN);

        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&train_speed, Train::ValueName::Train::LLO_LEAD_LOCO_SPEED);
		MapNumber(&m_fault_adcl_status_not_available, Project::ValueName::Train::FLT_PSD_ADCL_STATUS_NOT_AVAILABLE);

        RequestAndRetrieve();
    }

    void UnMapTrainInputs()
    {
        UnMapObject();
    }

    bool IsValid()
    {
        return GetObject().IsValid();
    }
};


#pragma once
