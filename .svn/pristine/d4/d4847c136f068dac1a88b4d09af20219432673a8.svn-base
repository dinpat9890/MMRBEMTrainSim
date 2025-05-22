///
/// @file       PlatformPassengersProperties.h
///
///             Declares all properties used by the PlatformPassengersUnits
///
/// @ingroup    CoreTrainSim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#ifndef PLATFORM_PASSENGERS_PROPERTIES_H
#define PLATFORM_PASSENGERS_PROPERTIES_H

#include "common/Properties.h"

/// Class containing the platform passenger properties contained within the properties file.

class PlatformPassengerProperties
{
public:
    explicit PlatformPassengerProperties(const Common::Properties &properties)
        : m_properties(properties)
    { }

    double GetInRangeThreshold() const;
    double GetStationarySpeedThreshold() const;
    double GetParkingThreshold() const;
    double GetDefaultPlatformLength() const;

private:
    const Common::Properties &m_properties;
};

#endif // PLATFORM_PASSENGERS_PROPERTIES_H
