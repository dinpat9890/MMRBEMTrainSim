///**************************************************************************************************
/// @file       PlatformProperties.cpp
///
///             Defines all properties that are required by Platform functionality
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************

#include "PlatformProperties.h"

#include <string>
#include <map>

namespace
{
    const std::string PLATFORM_CONTROL_CONFIG_SECTION = "Platform Controller";
}

PlatformProperties::PlatformProperties(const Common::Properties& properties)
    : m_properties(properties)
{
    // Properties defined under PLATFORM_CONTROL_CONFIG_SECTION
    default_platform_config_data[PlatformConfigElement::DOCKING_TOLERANCE] = std::make_pair(
        std::string("Docking Tolerance"), 0.5);
    default_platform_config_data[PlatformConfigElement::PSD_OPEN_TIME] = std::make_pair(
        std::string("PSD Open Time"), 3.0);
    default_platform_config_data[PlatformConfigElement::PSD_CLOSE_TIME] = std::make_pair(
        std::string("PSD Close Time"), 3.0);
    default_platform_config_data[PlatformConfigElement::TRAIN_DOOR_OPEN_TIME] = std::make_pair(
        std::string("Train Door Open Time"), 5.3);
    default_platform_config_data[PlatformConfigElement::TRAIN_DOOR_CLOSE_TIME] = std::make_pair(
        std::string("Train Door Close Time"), 5.3);
    default_platform_config_data[PlatformConfigElement::CLOSE_WARNING_TIME] = std::make_pair(
        std::string("Close Warning Time"), 2.5);
    default_platform_config_data[PlatformConfigElement::MAX_DOOR_CLOSING_TIME] = std::make_pair(
        std::string("Max Door Closing Time"), 5.8);
    default_platform_config_data[PlatformConfigElement::MAX_DOOR_CLOSED_AND_LOCKED_TIME] = std::make_pair(
        std::string("Max Door Closed and Locked Time"), 2.5);
    default_platform_config_data[PlatformConfigElement::MAX_TRAIN_DOOR_UNLOCKING_TIME] = std::make_pair(
        std::string("Max Train Doors Unlocking Time"), 3.0);
    default_platform_config_data[PlatformConfigElement::OVERSHOOT_DISTANCE] = std::make_pair(
        std::string("Overshoot Distance"), 10.0);
}

///  Description: Returns the index of the requested platform control config data
///
/// @returns  data read from the configuration file or default if no value specified
///
double PlatformProperties::PlatformControlConfigData(PlatformConfigElement platform_config_element) const
{
    auto default_config_data = default_platform_config_data.find(platform_config_element)->second;
    return m_properties.GetProperty<double>(PLATFORM_CONTROL_CONFIG_SECTION, default_config_data.first, default_config_data.second);
}
