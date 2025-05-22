//******************************************************************************
//
//  File:           SerialDevices.cpp
//
//  Description:    Contains the main() function for the Serial Device Module
//                  that is comprised of many units
//
//  Reference:      PPP - AC07-015
//
//  Author:         Andy Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2009
//
//******************************************************************************

#include "Utility/ConsoleMain.h"
#include "SerialDeviceApplication.h"

namespace
{
    // Some constants for easy modification
    const char *const PROPERTIES_FILE = "SerialDevices.ini";
}

//  Function:       main
//
//  Description:    The main function. Defers to ConsoleMain as this is a
//                  console Application.

int main(int argc, char *argv[])
{

    return Core::ConsoleMain<SerialDeviceApplication>(PROPERTIES_FILE, argc, argv);

}