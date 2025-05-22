//******************************************************************************
//
//  File:           ArduinoProperties.h
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
#ifndef ARDUINO_PROPERTIES_H
#define ARDUINO_PROPERTIES_H

#include "common/Properties.h"

//  Structure:      ArduinoProperties
//
//  Description:    All properties needed to use a Matrix Orbital device.

struct ArduinoProperties
{
    std::string port;
    std::string model;
    std::string version;
    float key_hold_time;

    ArduinoProperties() { }
    ArduinoProperties(const std::string &module, const Common::Properties &raw_properties);
};

#endif // ARDUINO_PROPERTIES_H
