///
/// @file       SpeedLimitProperties.h
///
///             Declares all properties used by the SpeedLimitUnits
///
/// @ingroup    CoreTrainSim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#ifndef SPEED_LIMIT_PROPERTIES_H
#define SPEED_LIMIT_PROPERTIES_H

#include "common/Properties.h"

/// Defines the information that can be extracted from a properties object relating to
/// speed limit calculation.

class SpeedLimitProperties
{
public:
    /// Constructor, which just remembers our properties object for later use
    ///
    /// @param properties The properties object to use

    SpeedLimitProperties(const Common::Properties &properties)
        : m_properties(properties)
    { }

    double GetMaxSpeedLimit() const;

private:
    const Common::Properties &m_properties;
};

#endif // SPEED_LIMIT_PROPERTIES_H
