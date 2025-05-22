//**************************************************************************************************
//
//  File:           Project.cpp
//
//  Description:    Project specific system level Unigine script file
//
//  Reference:      95809A9A
//
//  Author:         Craig Biggs
//
//  (C) Copyright:  SYDAC Pty Ltd, 2012
//
//**************************************************************************************************

#ifndef SYSTEM_PROJECT_CPP
#define SYSTEM_PROJECT_CPP

// Include the System.us.cpp of other vision packages that we are using
#include <system/System.us.cpp>
#include <train_framework/SystemTrain.us.cpp>

/******************************************************************************\
*
* init/shutdown
*
\******************************************************************************/

// These are the functions that Unigine will call. We need to call off to the init and shutdown of
// the packages that we are using, and then add any additional functionality that the project
// requires.

int init()
{
    System::Core::init();
    System::Train::init();
    
    // Project specific init - add project specific console commands here
    
    return 1;
}

int shutdown()
{
    // Project specific system level shutdown - remove console commands here
    
    System::Train::shutdown();
    System::Core::shutdown();
    
    return 1;
}

/******************************************************************************\
*
* update/render
*
\******************************************************************************/

int update()
{
    System::Core::update();
    
    // Project specific system level update - add project code here
    
    return 1;
}

int render()
{
    System::Core::render();

    return 1;
}

#endif
