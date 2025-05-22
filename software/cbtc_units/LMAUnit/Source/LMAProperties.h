///**************************************************************************************************
/// @file       LMAProperties.h
///
///             Declares all properties used by the LMA Unit
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************
#pragma once

#include "common/Properties.h"

/// Class containing the LMA properties contained within the properties file.
///
class LMAProperties
{
public:
    LMAProperties(const Common::Properties &properties)
        : m_properties(properties)
    { }

    double GetDefaultLMAAhead() const;
    double GetMinFollowingDistance() const;
    double GetUncertaintyDistance() const;

private:
    const Common::Properties &m_properties;
};

