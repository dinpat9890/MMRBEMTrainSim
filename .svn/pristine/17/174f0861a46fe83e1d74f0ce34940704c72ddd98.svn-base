/// @file       OnBoardProperties.h
///
///             Declares all properties used by the CBTC Onboard System
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
#pragma once

#include "common/Properties.h"

#include <map>
#include <string>

/// Class containing the CBTC OnBoard System properties contained within the properties file.
///
class CBTCOnBoardProperties
{
public:
    enum class OnboardConfigElement
    {
        CBTC_ACTIVE_VEHICLE_INDEX,
        POSITION_UNCERTAINTY,
        FSB_SPEED_LIMIT
    };
    enum class SpeedConfigElement
    {
        DBEC,
        T_SERVICE_BRAKE,
        T_INDICATION,
        EBD,
        SBD,
        ATO_BRAKE_DEMAND,
        AUTO_SPEED_LIMIT,
        SEMI_AUTO_SPEED_LIMIT,
        RMF_SPEED_LIMIT,
        RMR_SPEED_LIMIT,
        ROS_SPEED_LIMIT,
        SEMI_AUTO_SKIP_SPEED_LIMIT,
        AUTO_SKIP_SPEED_LIMIT,
        MEMORISED_LOCALISATION_SPEED_LIMIT,
        MEMORISED_LOCALISATION_VALIDITY_DISTANCE,
        ROLLBACK_DISTANCE,
        MAX_REVERSING_ZONE,
        LONG_DOCKING_DISTANCE,
        OVERSHOOT_DISTANCE,
        UNDERSHOOT_DISTANCE,
        WORK_ZONE_ALARM_DISTANCE,
        TRAIN_LENGTH,
        FSB_ENABLED,
        AUTO_SKIP_DISTANCE,
    };
    enum class SpeedCurveElement
    {
        DV_EBI_MIN,
        DV_EBI_MAX,
        V_EBI_MIN,
        V_EBI_MAX,
        DV_SBI_MIN,
        DV_SBI_MAX,
        V_SBI_MIN,
        V_SBI_MAX,
        DV_WARNING_MIN,
        DV_WARNING_MAX,
        V_WARNING_MIN,
        V_WARNING_MAX,
        T_WARNING,
        T_DRIVER,
        T_PREINDICATION,
    };

    CBTCOnBoardProperties(const Common::Properties& properties);

    int GetCBTCActiveVehicleIndex() const
    {
        return static_cast<int>(OnboardConfigData(OnboardConfigElement::CBTC_ACTIVE_VEHICLE_INDEX));
    };
    double GetTrainPositionUncertainty() const
    {
        return OnboardConfigData(OnboardConfigElement::POSITION_UNCERTAINTY);
    };

    double GetFSBSpeedLimit() const
    {
        return OnboardConfigData(OnboardConfigElement::FSB_SPEED_LIMIT);
    };

    double GetDbec() const { return SpeedMonitoringConfigData(SpeedConfigElement::DBEC); };
    double GetTServiceBrake() const { return SpeedMonitoringConfigData(SpeedConfigElement::T_SERVICE_BRAKE); };
    double GetTIndication() const { return SpeedMonitoringConfigData(SpeedConfigElement::T_INDICATION); };
    double GetEBD() const { return SpeedMonitoringConfigData(SpeedConfigElement::EBD); };
    double GetSBD() const { return SpeedMonitoringConfigData(SpeedConfigElement::SBD); };
    double Get_ATO_Brake_Demand() const { return SpeedMonitoringConfigData(SpeedConfigElement::ATO_BRAKE_DEMAND); };
    double GetAutoSpeedLimit() const { return SpeedMonitoringConfigData(SpeedConfigElement::AUTO_SPEED_LIMIT); };
    double GetRMFSpeedLimit() const { return SpeedMonitoringConfigData(SpeedConfigElement::RMF_SPEED_LIMIT); };
    double GetRMRSpeedLimit() const { return SpeedMonitoringConfigData(SpeedConfigElement::RMR_SPEED_LIMIT); };
    double GetROSSpeedLimit() const { return SpeedMonitoringConfigData(SpeedConfigElement::ROS_SPEED_LIMIT); };
    double GetAutoSkipSpeedLimit() const
    {
        return SpeedMonitoringConfigData(SpeedConfigElement::AUTO_SKIP_SPEED_LIMIT);
    };
    double GetAutoSkipDistance() const { return SpeedMonitoringConfigData(SpeedConfigElement::AUTO_SKIP_DISTANCE); };
    double GetMemorisedLocalisationSpeedLimit() const
    {
        return SpeedMonitoringConfigData(SpeedConfigElement::MEMORISED_LOCALISATION_SPEED_LIMIT);
    };
    double GetMemorisedLocalisationValidityDistance() const
    {
        return SpeedMonitoringConfigData(SpeedConfigElement::MEMORISED_LOCALISATION_VALIDITY_DISTANCE);
    };
    double GetRollbackDistance() const { return SpeedMonitoringConfigData(SpeedConfigElement::ROLLBACK_DISTANCE); };
    double GetMaxReverseZone() const { return SpeedMonitoringConfigData(SpeedConfigElement::MAX_REVERSING_ZONE); };
    double GetLongDockingDistance() const
    {
        return SpeedMonitoringConfigData(SpeedConfigElement::LONG_DOCKING_DISTANCE);
    };
    double GetOvershootDistance() const { return SpeedMonitoringConfigData(SpeedConfigElement::OVERSHOOT_DISTANCE); };
    double GetUndershootDistance() const { return SpeedMonitoringConfigData(SpeedConfigElement::UNDERSHOOT_DISTANCE); };
    double GetWorkZoneAlarmDistance() const
    {
        return SpeedMonitoringConfigData(SpeedConfigElement::WORK_ZONE_ALARM_DISTANCE);
    };
    double GetTrainLength() const { return SpeedMonitoringConfigData(SpeedConfigElement::TRAIN_LENGTH); };
    bool   GetFSBEnabled() const { return (SpeedMonitoringFSBConfig(SpeedConfigElement::FSB_ENABLED) > 0); };

    double GetMinEBIDv() const { return SpeedCurveConfigData(SpeedCurveElement::DV_EBI_MIN); };
    double GetMaxEBIDv() const { return SpeedCurveConfigData(SpeedCurveElement::DV_EBI_MAX); };
    double GetMinEBIVelocity() const { return SpeedCurveConfigData(SpeedCurveElement::V_EBI_MIN); };
    double GetMaxEBIVelocity() const { return SpeedCurveConfigData(SpeedCurveElement::V_EBI_MAX); };
    double GetMinSBIDv() const { return SpeedCurveConfigData(SpeedCurveElement::DV_SBI_MIN); };
    double GetMaxSBIDv() const { return SpeedCurveConfigData(SpeedCurveElement::DV_SBI_MAX); };
    double GetMinSBIVelocity() const { return SpeedCurveConfigData(SpeedCurveElement::V_SBI_MIN); };
    double GetMaxSBIVelocity() const { return SpeedCurveConfigData(SpeedCurveElement::V_SBI_MAX); };
    double GetMinWarningDv() const { return SpeedCurveConfigData(SpeedCurveElement::DV_WARNING_MIN); };
    double GetMaxWarningDv() const { return SpeedCurveConfigData(SpeedCurveElement::DV_WARNING_MAX); };
    double GetMinWarningVelocity() const { return SpeedCurveConfigData(SpeedCurveElement::V_WARNING_MIN); };
    double GetMaxWarningVelocity() const { return SpeedCurveConfigData(SpeedCurveElement::V_WARNING_MAX); };
    double GetWarningTime() const { return SpeedCurveConfigData(SpeedCurveElement::T_WARNING); };
    double GetDriverTime() const { return SpeedCurveConfigData(SpeedCurveElement::T_DRIVER); };
    double GetPreindicationTime() const { return SpeedCurveConfigData(SpeedCurveElement::T_PREINDICATION); };

private:
    double OnboardConfigData(OnboardConfigElement onboard_config_element) const;
    double SpeedMonitoringConfigData(SpeedConfigElement speed_config_element) const;
    int    SpeedMonitoringFSBConfig(SpeedConfigElement speed_config_element) const;
    double SpeedCurveConfigData(SpeedCurveElement speed_curve_config_element) const;

    const Common::Properties&                                      m_properties;
    std::map<OnboardConfigElement, std::pair<std::string, double>> default_onboard_config_data;
    std::map<SpeedConfigElement, std::pair<std::string, double>>   default_speed_monitor_config_data;
    std::map<SpeedCurveElement, std::pair<std::string, double>>    default_speed_curve_config_data;
};
