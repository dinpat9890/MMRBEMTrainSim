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

#include "Utility/Utilities.h"

/// Provides the interface to the properties belonging to the CBTC Onboard Inputs Comms object
///
struct MappedCBTCOnboardInputsObject : MappableObject 
{
    // Members Variables to map CBTC Onboard Input object properties
    double         m_last_detected_beacon;

    void MapCBTCOnboardInputsObject(Comms::Object &object, double request_frequency)
    {
        MapObject(object, request_frequency);

        // Map Class Parameters to Numbers
        MapNumber(&m_last_detected_beacon, Project::ValueName::CBTCOnboardInputs::LAST_DETECTED_BEACON); 

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
};

