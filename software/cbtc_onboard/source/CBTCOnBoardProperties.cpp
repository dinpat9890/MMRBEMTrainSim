/// @file       OnBoardProperties.cpp
///
///             Defines all properties that are required by CBTC OnBoard System
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "CBTCOnBoardProperties.h"

#include <map>
#include <string>

namespace
{
    const std::string ONBOARD_CONFIG_SECTION     = "OnBoard Configuration";
    const std::string SPEED_MONITORING_SECTION   = "Speed Monitoring";
    const std::string SPEED_CURVE_CONFIG_SECTION = "Speed Curve Config";
}

CBTCOnBoardProperties::CBTCOnBoardProperties(const Common::Properties& properties) : m_properties(properties)
{
    // Properties defined under ONBOARD_CONFIG_SECTION
    default_onboard_config_data[OnboardConfigElement::CBTC_ACTIVE_VEHICLE_INDEX] = std::make_pair(
      std::string("CBTC Active Vehicle Index"), 0.0);
    default_onboard_config_data[OnboardConfigElement::POSITION_UNCERTAINTY] = std::make_pair(
      std::string("Train Position Uncertainty"), 8.0);
    default_onboard_config_data[OnboardConfigElement::FSB_SPEED_LIMIT] = std::make_pair(
      std::string("FSB active speed limit"), 3.0);

    // Properties defined under SPEED_MONITORING_SECTION
    default_speed_monitor_config_data[SpeedConfigElement::DBEC] = std::make_pair(std::string("Dbec"), 2.0);
    default_speed_monitor_config_data[SpeedConfigElement::T_SERVICE_BRAKE] = std::make_pair(std::string("Service Brake Time"), 0.0);
    default_speed_monitor_config_data[SpeedConfigElement::T_INDICATION] = std::make_pair(std::string("Indication Time"), 3.0);
    default_speed_monitor_config_data[SpeedConfigElement::EBD]          = std::make_pair(std::string("EBD"), 2.39);
    default_speed_monitor_config_data[SpeedConfigElement::SBD]          = std::make_pair(std::string("SBD"), 1.18);
    default_speed_monitor_config_data[SpeedConfigElement::ATO_BRAKE_DEMAND] = std::make_pair(std::string("ATO Brake Demand"), 0.8);
    default_speed_monitor_config_data[SpeedConfigElement::AUTO_SPEED_LIMIT] = std::make_pair(std::string("Auto Speed Limit"), 80.0);
    default_speed_monitor_config_data[SpeedConfigElement::RMF_SPEED_LIMIT] = std::make_pair(std::string("RMF Speed Limit"), 25.0);
    default_speed_monitor_config_data[SpeedConfigElement::RMR_SPEED_LIMIT] = std::make_pair(std::string("RMR Speed Limit"), 10.0);
    default_speed_monitor_config_data[SpeedConfigElement::ROS_SPEED_LIMIT] = std::make_pair(std::string("ROS Speed Limit"), 25.0);
    default_speed_monitor_config_data[SpeedConfigElement::AUTO_SKIP_SPEED_LIMIT] = std::make_pair(
      std::string("Auto Skip Speed Limit"), 40.0);
    default_speed_monitor_config_data[SpeedConfigElement::AUTO_SKIP_DISTANCE] = std::make_pair(std::string("Auto Skip Distance"), 120.0);
    default_speed_monitor_config_data[SpeedConfigElement::MEMORISED_LOCALISATION_SPEED_LIMIT] = std::make_pair(
      std::string("Memorised Localisation Speed Limit"), 10.0);
    default_speed_monitor_config_data[SpeedConfigElement::MEMORISED_LOCALISATION_VALIDITY_DISTANCE] = std::make_pair(
      std::string("Memorised Localisation Validity Distance"), 4.0);
    default_speed_monitor_config_data[SpeedConfigElement::ROLLBACK_DISTANCE] = std::make_pair(std::string("Rollback Distance"), 2.0);
    default_speed_monitor_config_data[SpeedConfigElement::MAX_REVERSING_ZONE] = std::make_pair(std::string("Max Reverse Zone"), 10.0);
    default_speed_monitor_config_data[SpeedConfigElement::LONG_DOCKING_DISTANCE] = std::make_pair(
      std::string("Long Docking Distance"), 10.0);
    default_speed_monitor_config_data[SpeedConfigElement::OVERSHOOT_DISTANCE] = std::make_pair(
      std::string("Overshoot Distance"), 3.0); // Default TBD
    default_speed_monitor_config_data[SpeedConfigElement::UNDERSHOOT_DISTANCE] = std::make_pair(
      std::string("Undershoot Distance"), 3.0); // Default TBD
    default_speed_monitor_config_data[SpeedConfigElement::WORK_ZONE_ALARM_DISTANCE] = std::make_pair(
      std::string("Work Zone Alarm Distance"), 1000.0);
    default_speed_monitor_config_data[SpeedConfigElement::TRAIN_LENGTH] = std::make_pair(std::string("Train Length"), 200.0); // Default TBD
    default_speed_monitor_config_data[SpeedConfigElement::FSB_ENABLED] = std::make_pair(std::string("FSB Enable"), 1);

    // Properties defined to control creation of braking curves
    /// Speed difference between Permitted speed and Emergency Brake Intervention supervision limits, minimum
    /// value (km/h)
    default_speed_curve_config_data[SpeedCurveElement::DV_EBI_MIN] = std::make_pair(std::string("Min EBI DV"), 7.5);

    /// Speed difference between Permitted speed and Emergency Brake Intervention supervision limits, maximum
    /// value (km/h)
    default_speed_curve_config_data[SpeedCurveElement::DV_EBI_MAX] = std::make_pair(std::string("Max EBI DV"), 15.0);

    /// Value of MRSP where dV_ebi starts to increase to dV_ebi_max (km/h)
    default_speed_curve_config_data[SpeedCurveElement::V_EBI_MIN] = std::make_pair(std::string("Min EBI Velocity"), 110.0);

    /// Value of MRSP where dV_ebi stops to increase to dV_ebi_max (km/h)
    default_speed_curve_config_data[SpeedCurveElement::V_EBI_MAX] = std::make_pair(std::string("Max EBI Velocity"), 210.0);

    /// Speed difference between Permitted speed and Service Brake Intervention supervision limits, minimum
    /// value (km/h)
    default_speed_curve_config_data[SpeedCurveElement::DV_SBI_MIN] = std::make_pair(std::string("Min SBI DV"), 5.5);
    const double dv_sbi_min                                        = 5.5;

    /// Speed difference between Permitted speed and Service Brake Intervention supervision limits, maximum
    /// value (km/h)
    default_speed_curve_config_data[SpeedCurveElement::DV_SBI_MAX] = std::make_pair(std::string("Max SBI DV"), 10.0);

    /// Value of MRSP where dV_sbi starts to increase to dV_sbi_max (km/h)
    default_speed_curve_config_data[SpeedCurveElement::V_SBI_MIN] = std::make_pair(std::string("Min SBI Velocity"), 110.0);

    /// Value of MRSP where dV_sbi stops to increase to dV_sbi_max (km/h)
    default_speed_curve_config_data[SpeedCurveElement::V_SBI_MAX] = std::make_pair(std::string("Max SBI Velocity"), 210.0);

    /// Speed difference between Permitted speed and Warning supervision limits, minimum value (km/h)
    default_speed_curve_config_data[SpeedCurveElement::DV_WARNING_MIN] = std::make_pair(std::string("Min Warning DV"), 4.0);

    /// Speed difference between Permitted speed and Warning supervision limits, maximum value (km/h)
    default_speed_curve_config_data[SpeedCurveElement::DV_WARNING_MAX] = std::make_pair(std::string("Max Warning DV"), 5.0);

    /// Value of MRSP where dV_warning starts to increase to dV_warning_max (km/h)
    default_speed_curve_config_data[SpeedCurveElement::V_WARNING_MIN] = std::make_pair(std::string("Min Warning Velocity"), 110.0);

    /// Value of MRSP where dV_warning stops to increase to dV_warning_max (km/h)
    default_speed_curve_config_data[SpeedCurveElement::V_WARNING_MAX] = std::make_pair(std::string("Max Warning Velocity"), 140.0);

    /// Time between Warning supervision limit and SBI (sec)
    default_speed_curve_config_data[SpeedCurveElement::T_WARNING] = std::make_pair(std::string("Warning Time"), 2.0);

    /// Driver reaction time between Permitted speed supervision limit and SBI (sec)
    default_speed_curve_config_data[SpeedCurveElement::T_DRIVER] = std::make_pair(std::string("Driver Time"), 4.0);

    /// Time between the pre-indication location and the indication supervision limit valid for MRSP speed.
    /// (sec)
    default_speed_curve_config_data[SpeedCurveElement::T_PREINDICATION] = std::make_pair(std::string("Prediction Time"), 0.0);
}

///  Description: Returns the index of the requested onboard config data
///
/// @returns  data read from the configuration file or default if no value specified
///
double CBTCOnBoardProperties::OnboardConfigData(OnboardConfigElement onboard_config_element) const
{
    auto default_config_data = default_onboard_config_data.find(onboard_config_element)->second;
    return m_properties.GetProperty<double>(ONBOARD_CONFIG_SECTION, default_config_data.first, default_config_data.second);
}

///  Description: Returns the index of the requested speed monitoring config data
///
/// @returns  data read from the configuration file or default if no value specified
///
double CBTCOnBoardProperties::SpeedMonitoringConfigData(SpeedConfigElement speed_config_element) const
{
    auto default_config_data = default_speed_monitor_config_data.find(speed_config_element)->second;
    return m_properties.GetProperty<double>(
      SPEED_MONITORING_SECTION, default_config_data.first, static_cast<double>(default_config_data.second));
}
int CBTCOnBoardProperties::SpeedMonitoringFSBConfig(SpeedConfigElement speed_config_element) const
{
    auto default_config_data = default_speed_monitor_config_data.find(speed_config_element)->second;
    return m_properties.GetProperty<int>(
      SPEED_MONITORING_SECTION, default_config_data.first, static_cast<int>(default_config_data.second));
}

///  Description: Returns the index of the requested speed curve config data
///
/// @returns  data read from the configuration file or default if no value specified
///
double CBTCOnBoardProperties::SpeedCurveConfigData(SpeedCurveElement speed_curve_config_element) const
{
    auto default_config_data = default_speed_curve_config_data.find(speed_curve_config_element)->second;
    return m_properties.GetProperty<double>(SPEED_CURVE_CONFIG_SECTION, default_config_data.first, default_config_data.second);
}
