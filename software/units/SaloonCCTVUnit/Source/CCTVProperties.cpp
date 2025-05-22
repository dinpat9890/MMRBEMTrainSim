///
/// @file       CCTVProperties.cpp
///
///             Get CCTV Properties from Sydac::Properties & Store it in parent class (ICCTVProperties) variables
///             It is abstract class for Production CCTV 
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022


#include "CCTVProperties.h"

//Check if these constants can be moved in different header file. It is defined in both ICCTVProperties & SaloonCCTVBackendUnit
namespace
{
    std::vector<std::string> GetButtonSequenceFromString(const std::string& button_seq_str)
    {
        std::vector<std::string> button_id_order;
        //Tokenizing button sequence and pouplating button_id_order
        const std::string WHITE_SPACE = " ";
        std::string::size_type pos = button_seq_str.find_first_of(WHITE_SPACE);
        std::string token = button_seq_str.substr(0, pos);
        button_id_order.push_back(token);
        std::string sequence = button_seq_str;
        while (pos != std::string::npos)
        {
            sequence = sequence.substr(pos + 1);
            pos = sequence.find_first_of(WHITE_SPACE);
            token = sequence.substr(0, pos);
            button_id_order.push_back(token);
        }

        return button_id_order;
    }
}

CCTVProperties::CCTVProperties(const Common::Properties &properties)
{
    //m_re_pea_req_delay = properties.GetProperty<double>(CCTV_SECTION, PEA_DELAY_KEY, DEFAULT_PEA_DELAY);
    m_powerup_time = properties.GetProperty<double>(CCTV_SECTION, POWERUP_TIME_KEY, 10.0);
    m_initialization_time = properties.GetProperty<double>(CCTV_SECTION, INITIALIZATION_TIME_KEY, 30.0);
    m_auto_rotation_time = properties.GetProperty<double>(CCTV_SECTION, AUTO_ROTATION_TIME_KEY, 5.0);
    m_canvas_x      = properties.GetProperty<double>(CCTV_SECTION, CANVAS_X, 14.0);
    m_canvas_y      = properties.GetProperty<double>(CCTV_SECTION, CANVAS_Y, 40.0);
    m_canvas_length = properties.GetProperty<double>(CCTV_SECTION, CANVAS_LENGTH, 636.0);
    m_canvas_height = properties.GetProperty<double>(CCTV_SECTION, CANVAS_HEIGHT, 482.0);

    m_stp_point_train_start_distance = properties.GetProperty<double>(CCTV_PLATFORM_SECTION, CCTV_STP_POINT_START_DISTANCE, 140.0);
    m_stp_point_train_end_distance = properties.GetProperty<double>(CCTV_PLATFORM_SECTION, CCTV_STP_POINT_END_DISTANCE, 40.0);

    std::string internal_button_sequence = properties.GetProperty<std::string>(CCTV_BUTTON_SEQ_SECTION, CCTV_BUTTON_INT_SEQ_KEY, "");
    std::string external_button_sequence = properties.GetProperty<std::string>(CCTV_BUTTON_SEQ_SECTION, CCTV_BUTTON_EXT_SEQ_KEY, "");

    m_internal_camera_sequence = GetButtonSequenceFromString(internal_button_sequence);
    m_external_camera_sequence = GetButtonSequenceFromString(external_button_sequence);

    for (size_t idx = 0; idx < m_internal_camera_sequence.size(); ++idx)
    {
        m_dmi_button_names_to_vehicle_internal_cams.push_back(std::make_pair(m_internal_camera_sequence[idx], properties.GetProperty<std::string>(CCTV_CAM_MAP_SECTION, m_internal_camera_sequence[idx], "")));
    }

    for (size_t idx = 0; idx < m_external_camera_sequence.size(); ++idx)
    {
        m_dmi_button_names_to_vehicle_external_cams.push_back(std::make_pair(m_external_camera_sequence[idx], properties.GetProperty<std::string>(CCTV_CAM_MAP_SECTION, m_external_camera_sequence[idx], "")));
    }
    m_cab_camera = properties.GetProperty<std::string>(CCTV_CAM_MAP_SECTION, DMC_CAB, DMC_7);
}

CCTVProperties::~CCTVProperties(void)
{
}