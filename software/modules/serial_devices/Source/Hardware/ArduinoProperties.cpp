//******************************************************************************
//
//  File:           ArduinoProperties.cpp
//
//  Description:    Structure containing all properties needed to use a Matrix
//                  Orbital device, with serialization from an ini file
//
//  Reference:      ELL
//
//  Author:         James Errington, Peter Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2012
//
//******************************************************************************
#include "ArduinoProperties.h"
using namespace std;

namespace
{
    const char *KEYPAD_SUBGROUP = " Keypad";
}

//  Function:       ArduinoProperties::ArduinoProperties
//
//  Description:    Cosntructor based off properties. Serializes them.
//
//  Parameters:
//      const std::string &module - Name of the module in the INI file. This 
//                          must have a group with that name.
//      const Sydac::Properties &raw_properties - Properties to read from.

ArduinoProperties::ArduinoProperties(const std::string &module, const Common::Properties &raw_properties)
{
    port    = raw_properties.GetProperty<std::string>(module, "Port", "COM Undefined");
    model   = raw_properties.GetProperty<std::string>(module, "Model", "");
    version = raw_properties.GetProperty<std::string>(module, "Version", "");
    key_hold_time = raw_properties.GetProperty<float>(module, "Key_Hold_Time", 1.0); 
}

