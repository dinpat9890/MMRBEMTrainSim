///**************************************************************************************************
/// @file       TrackEventProperties.cpp
///
///             Defines all properties that are required by Track Event functionality
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************

#include "TrackEventProperties.h"

#include <string>

namespace
{
    const std::string TRACK_EVENT_SECTION    = "Track Event";
    const std::string MAX_LOOK_AHEAD         = "Default Look Ahead";
    const std::string TRANSITION_ZONE_LENGTH = "Transition Zone Length";

    const double MAX_LOOK_AHEAD_DEFAULT         = 1000.0;  //In meters
    const double TRANSITION_ZONE_LENGTH_DEFAULT = 100.0;   //In meters
}

///  Description:    Returns the value from the properties file, which defines the maximum Look Ahead
///                  distance to be used when seaching for AM/CM transition regions.
///
/// @returns the Max Look Ahead distance
///
double TrackEventProperties::GetMaxLookAhead() const
{
    return m_properties.GetProperty<double>(TRACK_EVENT_SECTION, MAX_LOOK_AHEAD, MAX_LOOK_AHEAD_DEFAULT);
}

///  Description:    Returns the value from the properties file, which defines the length of an AM/CM transition zone
///
/// @returns length of transition region
///
double TrackEventProperties::GetTransitionZoneLength() const
{
    return m_properties.GetProperty<double>(TRACK_EVENT_SECTION, TRANSITION_ZONE_LENGTH, TRANSITION_ZONE_LENGTH_DEFAULT);
}
