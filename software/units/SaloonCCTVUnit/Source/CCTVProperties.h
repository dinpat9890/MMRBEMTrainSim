///
/// @file       CCTVProperties.h
///
///             Get CCTV Properties from Sydac::Properties & Store it in parent class (ICCTVProperties) variables
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2017


#pragma once
#include "ICCTVProperties.h"
#include "core_properties/CommonProperties.h"

// Under CCTV Section
const std::string CCTV_SECTION = "CCTV";
const std::string POWERUP_TIME_KEY = "Saloon CCTV Powerup Time";
const std::string INITIALIZATION_TIME_KEY = "Saloon CCTV Initialization Time";
const std::string AUTO_ROTATION_TIME_KEY = "Auto Rotation Time";
const std::string CANVAS_X = "Canvas X";
const std::string CANVAS_Y = "Canvas Y";
const std::string CANVAS_LENGTH = "Canvas Length";
const std::string CANVAS_HEIGHT = "Canvas Height";

// Under CCTV Button Sequence
//This sequence represents the creation order of buttons on DMI and it should contain all the buttons.
const std::string CCTV_BUTTON_SEQ_SECTION = "CCTV Button Sequence";
const std::string CCTV_BUTTON_INT_SEQ_KEY = "InternalSequence";
const std::string CCTV_BUTTON_EXT_SEQ_KEY = "ExternalSequence";

// Under CCTV Cam Map. CCTV Camera Labels and their Descriptions
const std::string CCTV_CAM_MAP_SECTION = "CCTV Cam Map";
// Internal Cameras
const std::string DMC_8 = "DMC Saloon CCTV Camera 1";
const std::string DMC_9 = "DMC Saloon CCTV Camera 2";
const std::string DMC_10 = "DMC Saloon CCTV Camera 3";
const std::string DMC_11 = "DMC Saloon CCTV Camera 4";
const std::string TC_1 = "TC Saloon CCTV Camera 1";
const std::string TC_2 = "TC Saloon CCTV Camera 2";
const std::string TC_3 = "TC Saloon CCTV Camera 3";
const std::string TC_4 = "TC Saloon CCTV Camera 4";
const std::string MC_1 = "MC Saloon CCTV Camera 1";
const std::string MC_2 = "MC Saloon CCTV Camera 2";
const std::string MC_3 = "MC Saloon CCTV Camera 3";
const std::string MC_4 = "MC Saloon CCTV Camera 4";

// External Cameras
const std::string DMC_1 = "Driver's Forward View";
const std::string DMC_2 = "DMC Driver's Track Camera";
const std::string DMC_3 = "DMC Driver's Left Exterior Camera";
const std::string DMC_4 = "DMC Driver's Right Exterior Camera";
const std::string DMC_5 = "DMC Detrainment Camera";
const std::string DMC_6 = "DMC ODD Camera";
const std::string DMC_7 = "DMC CCTV Cab Camera";
const std::string TC_5 = "TC Pantograph Camera";
const std::string MC_5 = "MC Driver's Left Exterior Camera";
const std::string MC_6 = "MC Driver's Right Exterior Camera";

//CCTV Platform
const std::string CCTV_PLATFORM_SECTION = "CCTV Platform";
const std::string CCTV_STP_POINT_START_DISTANCE = "Distance To STP Point";
const std::string CCTV_STP_POINT_END_DISTANCE = "Distance From STP Point";

const size_t FWD_ORIENTATION = 1;
const size_t REV_ORIENTATION = 2;

const std::string SINGLE_VIEW_MODE_STR = "SingleView";
const std::string FOUR_VIEW_MODE_STR = "FourView";

const size_t FOUR_VIEW_COUNT = 4;
const size_t SINGLE_VIEW_COUNT = 1;

const size_t FIRST_VIEW = 0;
const size_t SECOND_VIEW = 1;
const size_t THIRD_VIEW = 2;
const size_t FOURTH_VIEW = 3;

const std::string DEFAULT_INTERNAL_SINGLE_VIEW_BUTTON = "DMC-8_1";
const std::string DEFAULT_EXTERNAL_SINGLE_VIEW_BUTTON = "DMC-3_1";

const std::string DMC_CAB = "DMC-7";

//CAR Type
const std::string CARTYPE_T = "T";
const std::string CARTYPE_M = "M";
const std::string CARTYPE_DM = "DM";

// 6 Cab and 8 cab Train ID
const size_t SIX_CAB = 1;
const size_t EIGHT_CAB = 2;

const size_t MAX_EXTERIOR_CAMERA_TYPE = 6;

const size_t     VEHICLE_1 = 0;
const size_t     VEHICLE_2 = 1;
const size_t     VEHICLE_3 = 2;
const size_t     VEHICLE_4 = 3;
const size_t     VEHICLE_5 = 4;
const size_t     VEHICLE_6 = 5;
const size_t     VEHICLE_7 = 6;
const size_t     VEHICLE_8 = 7;


class CCTVProperties :
    public ICCTVProperties
{
public:
    CCTVProperties(const Common::Properties &properties);
    ~CCTVProperties(void);
private :

};
