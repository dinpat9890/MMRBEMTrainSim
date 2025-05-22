///
/// @file       SpeedLimitProperties.cpp
///
///             Defines all properties that are required by SpeedLimitUnits
///
/// @ingroup    CoreTrainSim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#include "SpeedLimitProperties.h"

using namespace Common;

namespace
{
    const std::string SPEED_LIMITS_SECTION = "Speed Limits";
    const std::string MAX_SPEED_LIMIT      = "Maximum Speed Limit";

    const int    DEFAULT_LEAD_VEHICLE_ONLY = 0;
    const double DEFAULT_MAX_SPEED_LIMIT   = 120.0 / 3.6;

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

// Speed Limit Properties
// ======================

/// @return A speed limit, in metres per second, that is the maximum for the track. This
///         effectively serves as a default speed limit in absence of any other.

double SpeedLimitProperties::GetMaxSpeedLimit() const
{
    return m_properties.GetProperty<double>(SPEED_LIMITS_SECTION, MAX_SPEED_LIMIT, DEFAULT_MAX_SPEED_LIMIT);
}
