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
#ifndef ICCTVProperties_H
#define ICCTVProperties_H

#include<vector>

class ICCTVProperties
{
public:
    virtual ~ICCTVProperties()=0;
    virtual double GetConsecutivePEAReqDelay();
    virtual double GetSaloonCCTVPowerUpTime();
    virtual double GetSaloonCCTVInitializationTime();
    virtual double GetSaloonCCTVAutoRotationTime();
    virtual double GetCanvasX();
    virtual double GetCanvasY();
    virtual double GetCanvasLength();
    virtual double GetCanvasHeight();
    virtual std::string  GetCabCamera();
    virtual std::vector<std::pair<std::string, std::string>> GetSaloonCCTVButtontoInternalCamMap() const;
    virtual std::vector<std::pair<std::string, std::string>> GetSaloonCCTVButtontoExternalCamMap() const;
    virtual std::vector<std::string> GetInternalButtonSequence() const;
    virtual std::vector<std::string> GetExternalButtonSequence() const;
    virtual double  GetStpPointStartDistance() const;
    virtual double  GetStpPointEndDistance() const;

protected:
    double                  m_powerup_time;
    double                  m_re_pea_req_delay;
    double                  m_initialization_time;
    double                  m_auto_rotation_time;
    double                  m_canvas_x;
    double                  m_canvas_y;
    double                  m_canvas_length;
    double                  m_canvas_height;
    double                  m_stp_point_train_start_distance{ 140.0 };
    double                  m_stp_point_train_end_distance{ 40.0 };
    //'Button' name mapped to 'vehindex_cameraname'
    std::vector<std::pair<std::string, std::string>> m_dmi_button_names_to_vehicle_internal_cams;
    std::vector<std::pair<std::string, std::string>> m_dmi_button_names_to_vehicle_external_cams;
    std::vector<std::string> m_internal_camera_sequence;
    std::vector<std::string> m_external_camera_sequence;
    std::string                m_cab_camera;
};

#endif
