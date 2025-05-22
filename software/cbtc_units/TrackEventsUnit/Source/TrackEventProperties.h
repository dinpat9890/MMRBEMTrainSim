///**************************************************************************************************
/// @file       TrackEventProperties.h
///
///             Declares all properties used by the LMA Unit
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************
#pragma once

#include "common/Properties.h"

/// Class containing the Track Event properties contained within the properties file.
///
class TrackEventProperties
{
public:
    TrackEventProperties(const Common::Properties &properties)
        : m_properties(properties)
    { }

    double GetMaxLookAhead() const;
    double GetTransitionZoneLength() const;

private:
    const Common::Properties &m_properties;
};

