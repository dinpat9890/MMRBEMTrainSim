///**************************************************************************************************
///  @file           MappedLMAObject.h
///
///  Description:    Mapped Objects for interfacing with CBTCOnboardInputs Object properties
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

/// Stucture for interfacing with the CBTC Onboard Input comms object
struct MappedCBTCOnboardInputs : MappableObject
{
    // Movement Authority Interface into CBTC Onboard
    std::string cbtc_movement_authority;

    // Map LMA Object outputs to Numbers
    void MapCBTCOnboardInputs(Comms::Object &object, double request_frequency)
    {
        assert(Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS);

        MapObject(object, request_frequency);

        // Map Class Parameters to Raws
        MapRaw(&cbtc_movement_authority, Project::ValueName::CBTCOnboardInputs::MOVEMENT_AUTHORITY);

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

    void SetCBTCMARawDataString(double current_loco_position, 
                                double eoa, double svl, 
                                CBTC::Protos::EOACause eoa_cause, 
                                double next_stopping_point_distance)
    {
        CBTC::Protos::MovementAuthority movement_authority_data;

        movement_authority_data.set_reference_train_position(current_loco_position);
        movement_authority_data.set_svl_distance(svl);
        movement_authority_data.set_eoa_distance(eoa);
        movement_authority_data.set_eoa_cause(eoa_cause);
        movement_authority_data.set_stopping_distance(next_stopping_point_distance);

        movement_authority_data.SerializeToString(&cbtc_movement_authority);
    }
};


