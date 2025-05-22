///**************************************************************************************************
/// @file       LMAProperties.cpp
///
///             Defines all properties that are required by LMA functionality
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************

#include "LMAProperties.h"

#include <string>

namespace
{
    const std::string LMA_SECTION                = "LMA";
    const std::string DEFAULT_LMA_AHEAD          = "Default LMA Ahead";
    const std::string MIN_FOLLOWING_DISTANCE     = "Minimum Following Distance";
    const std::string UNCERTAINTY_DISTANCE       = "Uncertainty Distance";

    const double DEFAULT_LMA_AHEAD_DEFAULT       = 32000.0;  //In meters
    const double MIN_FOLLOWING_DISTANCE_DEFAULT  = 100.0;
    const double UNCERTAINTY_DISTANCE_DEFAULT    = 1.0;
}

///  Description:    Returns the value from the properties file, which defines the maximum Ahead LMA
///                  distance to be used when no LMA obstacles are detected in front of the train.
///
/// @returns the LMA Ahead distance
///
double LMAProperties::GetDefaultLMAAhead() const
{
    return m_properties.GetProperty<double>(LMA_SECTION, DEFAULT_LMA_AHEAD, DEFAULT_LMA_AHEAD_DEFAULT);
}

///  Description:    Returns the value from the properties file, which defines the minimum distance
///                  at which one train can follow another.
///
/// @returns the minimum safe distance at which one train can follow another
///
double LMAProperties::GetMinFollowingDistance() const
{
     return m_properties.GetProperty<double>(LMA_SECTION, MIN_FOLLOWING_DISTANCE, MIN_FOLLOWING_DISTANCE_DEFAULT);
}

///  Description:    Returns the value from the properties file, which defines the uncertainty in LMA
///                  the reported LMA distances.
///
/// Note the uncertainty distance is subtracted from the distance to the next LMA obstacle
///
/// @returns the LMA Behind distance
///
double LMAProperties::GetUncertaintyDistance() const
{
    return m_properties.GetProperty<double>(LMA_SECTION, UNCERTAINTY_DISTANCE, UNCERTAINTY_DISTANCE_DEFAULT);
}
