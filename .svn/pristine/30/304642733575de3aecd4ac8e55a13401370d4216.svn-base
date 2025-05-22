///**************************************************************************************************
/// @file       PlatformProperties.h
///
///             Declares all properties used by the Platform Unit
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************
#pragma once

#include "common/Properties.h"

#include <string>
#include <map>

/// Class containing the Platform properties contained within the properties file.
///
class PlatformProperties
{
private:
    enum class PlatformConfigElement
    {
        DOCKING_TOLERANCE,
        PSD_OPEN_TIME,
        PSD_CLOSE_TIME,
        TRAIN_DOOR_OPEN_TIME,
        TRAIN_DOOR_CLOSE_TIME,
        CLOSE_WARNING_TIME,
        MAX_DOOR_CLOSING_TIME,
        MAX_DOOR_CLOSED_AND_LOCKED_TIME,
        MAX_TRAIN_DOOR_UNLOCKING_TIME,
        OVERSHOOT_DISTANCE
    };

public:
    PlatformProperties(const Common::Properties &properties);

    double GetDockingTolerance() const           { return PlatformControlConfigData(PlatformConfigElement::DOCKING_TOLERANCE); };
    double GetPSDOpenTime() const                { return PlatformControlConfigData(PlatformConfigElement::PSD_OPEN_TIME); };
    double GetPSDCloseTime() const               { return PlatformControlConfigData(PlatformConfigElement::PSD_CLOSE_TIME); };
    double GetTrainDoorOpenTime() const          { return PlatformControlConfigData(PlatformConfigElement::TRAIN_DOOR_OPEN_TIME); };
    double GetTrainDoorCloseTime() const         { return PlatformControlConfigData(PlatformConfigElement::TRAIN_DOOR_CLOSE_TIME); };
    double GetCloseWarningTime() const           { return PlatformControlConfigData(PlatformConfigElement::CLOSE_WARNING_TIME); };
    double GetMaxDoorClosingTime() const         { return PlatformControlConfigData(PlatformConfigElement::MAX_DOOR_CLOSING_TIME); };
    double GetMaxDoorClosedAndLockedTime() const { return PlatformControlConfigData(PlatformConfigElement::MAX_DOOR_CLOSED_AND_LOCKED_TIME); };
    double GetMaxTrainDoorUnlockingTime() const  { return PlatformControlConfigData(PlatformConfigElement::MAX_TRAIN_DOOR_UNLOCKING_TIME); };
    double GetOvershootDistance() const          { return PlatformControlConfigData(PlatformConfigElement::OVERSHOOT_DISTANCE); };

private:
    double PlatformControlConfigData(PlatformConfigElement speed_config_element) const;

    const Common::Properties &m_properties;
    std::map<PlatformConfigElement, std::pair<std::string, double>>   default_platform_config_data;
};

