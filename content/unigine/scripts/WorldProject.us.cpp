    //**************************************************************************************************
//
//  File:           WorldProject.cpp
//
//  Description:    Project specific world level Unigine script file
//
//  Reference:      95809A9A
//
//  Author:         Craig Biggs
//
//  (C) Copyright:  SYDAC Pty Ltd, 2012
//
//**************************************************************************************************

#ifndef WORLD_PROJECT_CPP
#define WORLD_PROJECT_CPP

// Include any feature scripts that are not auto-generated, but may come from an ivy module

// Include the world-level entry functions of other vision packages that we are using
#include <framework/Core.us.cpp>
#include <train_framework/Train.us.cpp>

// These should have a Vehicles/ prefix at least (or Vehicles/Scripts, etc)
#include <m_vehicle.us.cpp>
#include <dm_vehicle.us.cpp>
#include <t_vehicle.us.cpp>

#include <PassengerInfo.us.cpp>

namespace World
{
    /******************************************************************************\
    *
    * init/shutdown
    *
    \******************************************************************************/

    // These are the functions that Unigine will call. We need to call off to the init and shutdown of
    // the packages that we are using, and then add any additional functionality that the project
    // requires.

    void init()
    {
        Core::init();
        Train::init();
        
        // Register your train types here
		VehicleManager::registerVehicleType(new Vehicles::m_vehicle_type());
		VehicleManager::registerVehicleType(new Vehicles::dm_vehicle_type());
        VehicleManager::registerVehicleType(new Vehicles::t_vehicle_type());
        
        Passengers::registerPassengerInfo();
        
        // Project specific init - add project specific console commands here
    }

    void shutdown()
    {
        // Project specific system level shutdown - remove console commands here
        Train::shutdown();
        Core::shutdown();
    }

    /******************************************************************************\
    *
    * update/flush/render
    *
    \******************************************************************************/

    void update()
    {
        Core::update();
        Train::update();
        
        // Project specific system level update - add project code here
    }

    void flush()
    {
        Core::flush();
        Train::flush();
    }
}

#endif
