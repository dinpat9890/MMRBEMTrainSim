///
/// @file       PlatformPassengersProperties.cpp
///
///             Defines all properties that are required by platform passengers functionality
///
/// @ingroup    CoreTrainSim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#include "PlatformPassengersProperties.h"

#include <string>

namespace
{
    const std::string PLATFORM_PASSENGER_SECTION    = "Platform Passenger";
    const std::string IN_RANGE_THRESHOLD            = "In Range Threshold";
    const std::string STATIONARY_SPEED_THRESHOLD    = "Stationary Speed Threshold";
    const std::string PARKING_THRESHOLD             = "Parking Threshold";
    const std::string DEFAULT_PLATFORM_LENGTH       = "Default Platform Length";

    /// Helper function that removes trailing and leading whitespace
    ///
    /// @param s The string to trim
    ///
    /// @return The trimmed string

    std::string Trim(std::string s)
    {
        // Rather inefficient - a single find and erase would be quicker, but requires more
        // thinking to code and maintain :)
        while(!s.empty() && isspace(s.back()))
            s.pop_back();
        while(!s.empty() && isspace(s.front()))
            s.erase(s.begin());
        return s;
    }
}

// Platform Passenger Properties
// =============================

//  Function:       PlatformPassengerProperties::GetInRangeThreshold
//
//  Description:    Returns the value in the properties file, defining when
//                  a train is within range of a Platform, so that we should have idle passengers.

double PlatformPassengerProperties::GetInRangeThreshold() const
{
    return m_properties.GetProperty<double>(PLATFORM_PASSENGER_SECTION, IN_RANGE_THRESHOLD, 200.0);
}

//  Function:       PlatformPassengerProperties::GetStationarySpeedThreshold
//
//  Description:    Returns the value in the properties file, defining the speed at which the train is considered
//                  stopped.

double PlatformPassengerProperties::GetStationarySpeedThreshold() const
{
    return m_properties.GetProperty<double>(PLATFORM_PASSENGER_SECTION, STATIONARY_SPEED_THRESHOLD, 0.1);
}

//  Function:       PlatformPassengerProperties::GetParkingThreshold
//
//  Description:    Returns the value in the properties file, which allows us to determine
//                  whether a train is parked at a platform.

double PlatformPassengerProperties::GetParkingThreshold() const
{
    return m_properties.GetProperty<double>(PLATFORM_PASSENGER_SECTION, PARKING_THRESHOLD, 100.0);
}

//  Function:       PlatformPassengerProperties::GetDefaultPlatformLength
//
//  Description:    Returns the value in the properties file, defining the 
//                  default platform length when one is not available on a platform feature.

double PlatformPassengerProperties::GetDefaultPlatformLength() const
{
    return m_properties.GetProperty<double>(PLATFORM_PASSENGER_SECTION, DEFAULT_PLATFORM_LENGTH, 200.0);
}
