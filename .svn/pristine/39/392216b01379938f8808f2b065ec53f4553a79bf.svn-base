//******************************************************************************
//
//  File:           ProjectInitializationTypes.h
//
//  Description:    Defines the structures used to transfer initialization 
//                  information into the DLL. It is expected that this is a 
//                  common file used by both the DLL code to interpret the 
//                  incoming intialization data, and the wrapping code to 
//                  understand how to formulate the initialization data.
//
//  Reference:      KSRTCBusSim
//
//  Author:         Chris Dyer
//
//  (C) Copyright:  SYDAC Pty Ltd, 2017
//
//******************************************************************************

#ifndef PROJECT_INITIALIZATION_TYPES_H
#define PROJECT_INITIALIZATION_TYPES_H

#include <memory.h>

namespace ProjectInitialization
{    
    //  Structure:      VehicleInfo
    //
    //  Description:    Holds the information for a particular vehicle in the 
    //                  train.
    
    struct VehicleInfo
    {
        int    vehicle_id;
        int    vehicle_type;
        int    vehicle_class;
        int    orientation;
        double length;
        double height;
        double width;
        double tare;
        double gross;
        double loading;
        double diameter;
        int    axle_count;
    };
}

#endif // PROJECT_INITIALIZATION_TYPES_H
