///
/// @file       ICCTVProperties.h
///
///             Store CCTV Properties.
///             It is abstract class for Production CCTV
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#pragma once

#include "ICCTVProperties.h"

double ICCTVProperties::GetConsecutivePEAReqDelay()
{
    return m_re_pea_req_delay;
}
double ICCTVProperties::GetSaloonCCTVPowerUpTime()
{
    return m_powerup_time;
}
double ICCTVProperties::GetSaloonCCTVInitializationTime()
{
    return m_initialization_time;
}
double ICCTVProperties::GetSaloonCCTVAutoRotationTime() 
{
    return m_auto_rotation_time;
}
double ICCTVProperties::GetCanvasX() 
{
    return m_canvas_x;
}
double ICCTVProperties::GetCanvasY() 
{
    return m_canvas_y;
}
double ICCTVProperties::GetCanvasLength() 
{
    return m_canvas_length;
}
double ICCTVProperties::GetCanvasHeight() 
{
    return m_canvas_height;
}

std::vector<std::pair<std::string, std::string>> ICCTVProperties::GetSaloonCCTVButtontoExternalCamMap() const
{
    return m_dmi_button_names_to_vehicle_external_cams;
}

std::vector<std::pair<std::string, std::string>> ICCTVProperties::GetSaloonCCTVButtontoInternalCamMap() const
{
    return m_dmi_button_names_to_vehicle_internal_cams;
}

std::vector<std::string> ICCTVProperties::GetInternalButtonSequence() const
{
    return m_internal_camera_sequence;
}

std::vector<std::string> ICCTVProperties::GetExternalButtonSequence() const
{
    return m_external_camera_sequence;
}

 std::string  ICCTVProperties::GetCabCamera()
{
     return m_cab_camera;
}
ICCTVProperties::~ICCTVProperties()
{

}

double  ICCTVProperties::GetStpPointStartDistance() const
{
    return m_stp_point_train_start_distance;
}
double  ICCTVProperties::GetStpPointEndDistance() const
{
    return m_stp_point_train_end_distance;
}