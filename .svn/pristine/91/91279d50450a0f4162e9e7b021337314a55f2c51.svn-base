///
/// @file       CCTVState.cpp
///
///             Store current CCTV States.
///             whether external or internal, auto rotation on/off and other states
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "CCTVState.h"
#include "CCTVProperties.h"
#include "ITrainInterface.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "Common/StandardLogging.h"

namespace
{
    const std::string EXTERNAL = "External";
    const std::string INTERNAL = "Internal";
    std::string MakeCameraPerspectiveName(size_t train_id, size_t vehicle_index, size_t camera_id, const std::string &description)
    {
        std::stringstream return_name;
        return_name << "Train " << train_id << ", vehicle " << vehicle_index << ", camera " << camera_id << " (" << description << ")";
        return return_name.str();
    }
}

CCTVState::CarCameraInfo::CarCameraInfo()
    : m_car_orientation(FWD_ORIENTATION)
{
}

CCTVState::CarCameraInfo::~CarCameraInfo()
{
}

CCTVState::CameraGroupSequence::CameraGroupSequence()
    : m_current_group_index(0)
    , m_next_group_index(0)
{
}

CCTVState::CameraGroup CCTVState::CameraGroupSequence::GetCurrentGroup() const
{
    return m_camera_group_sequence[m_current_group_index % m_camera_group_sequence.size()];
}
void CCTVState::CameraGroupSequence::SetCurrentGroup(int veh_index)
{
    m_current_group_index = veh_index;
    m_next_group_index = (veh_index + 1) % m_camera_group_sequence.size();
}

CCTVState::CameraGroup CCTVState::CameraGroupSequence::GetGroupPostIncremental()
{
    m_current_group_index = m_next_group_index;
    m_next_group_index = (m_next_group_index + 1) % m_camera_group_sequence.size();
    return m_camera_group_sequence[m_current_group_index];
}

void CCTVState::CameraGroupSequence::ResetGroupIndex()
{
    m_current_group_index = 0;
    m_next_group_index = 0;
}

void CCTVState::CameraGroupSequence::AddCameraGroup(CameraGroup camera_group)
{
    m_camera_group_sequence.push_back(camera_group);
}

CCTVState::CCTVState(IVisionInterface &iVisionInterface, ICCTVProperties &ICCTVProperties, ITrainInterface &iITrainInterface)
    : m_default_active_single_internal_view_camera_name(DEFAULT_INTERNAL_SINGLE_VIEW_BUTTON)
    , m_last_active_single_view_internal_camera_name(DEFAULT_INTERNAL_SINGLE_VIEW_BUTTON)
    , m_last_active_single_view_external_camera_name(DEFAULT_EXTERNAL_SINGLE_VIEW_BUTTON)
    , m_trainInterface(iITrainInterface)
    , m_visionInterface(iVisionInterface)
{
    try
    {
        m_powerup_time = ICCTVProperties.GetSaloonCCTVPowerUpTime();
        m_initialization_time = ICCTVProperties.GetSaloonCCTVInitializationTime();
        m_auto_rotation_time = ICCTVProperties.GetSaloonCCTVAutoRotationTime();
        m_train_id = iITrainInterface.GetScenarioTrainId();

        m_train_vehcl_count_id = iITrainInterface.GetVehicleCountID();
        std::vector<Train::Data::ScenarioTrain> scenario_trains = iITrainInterface.GetScenarioTrains();

        // We assume that there will be only one scenario train.
        std::for_each(scenario_trains.begin(), scenario_trains.end(), [&](Train::Data::ScenarioTrain train)
        {
            if (train.is_simulated && (train.scenario_train_id == m_train_id))
            {
                const std::vector<Train::Data::TrainElement> &te = iITrainInterface.GetTrainElements(train.train_id);
                m_car_count = te.size();

                m_vehicle_cameras.resize(m_car_count);
                Trace::GetLogger().STAMP(Trace::INFO) << "Car Count : " << m_car_count << Trace::EndLog();

                const std::vector<Train::Data::TrainCamera> &cameras = iITrainInterface.GetTrainCamera(train.train_id);

                std::for_each(te.begin(), te.end(), [&](Train::Data::TrainElement train_elem)
                {
                    size_t veh_idx = train_elem.position;
                    std::string class_code = train_elem.class_code;
                    std::vector<Train::Data::TrainCamera> car_cameras;
                    size_t orientation = size_t(train_elem.orientation);

                    // Find the cameras for vehice with current index
                    std::for_each(cameras.begin(), cameras.end(), [&](Train::Data::TrainCamera cam)
                    {
                        if (cam.car_position == veh_idx)
                        {
                            car_cameras.push_back(cam);
                            std::string perspective_name = MakeCameraPerspectiveName(train.scenario_train_id, veh_idx, cam.camera_id, cam.camera_description);
                            m_camera_perspective_mapping.insert({ perspective_name, { veh_idx, cam.camera_id, -1 } });
                        }
                    });

                    CarCameraInfo car_camera_info;
                    car_camera_info.SetOrientation(orientation);
                    CarType car_type;

                    // Assuming there are only two types of car available:
                    // 1: TC type, 2: M type
                    Trace::GetLogger().STAMP(Trace::INFO) << "  " << class_code; 
                    if (class_code.find(CARTYPE_T) != std::string::npos)
                        car_type = CarType::T_TYPE;
                    else if (class_code.find(CARTYPE_M) != std::string::npos)
                        car_type = CarType::M_TYPE;
                    else
                        car_type = CarType::DM_TYPE;
                    
                    m_trainCabs.push_back(car_type);
                    car_camera_info.SetCarCameras(car_cameras);
                    car_camera_info.SetCarType(car_type);
                    m_vehicle_cameras[veh_idx] = car_camera_info;
                });
                Trace::GetLogger().STAMP(Trace::INFO) << Trace::EndLog();
            }
        });

        m_dmi_buttons_to_vehicle_internal_cams = ICCTVProperties.GetSaloonCCTVButtontoInternalCamMap();
        m_dmi_buttons_to_vehicle_external_cams = ICCTVProperties.GetSaloonCCTVButtontoExternalCamMap();

        std::vector<std::string> & internal_camera_sequence = ICCTVProperties.GetInternalButtonSequence();
        std::vector<std::string> & external_camera_sequence = ICCTVProperties.GetExternalButtonSequence();
        PopulateCameraSequence(internal_camera_sequence, m_internal_camera_sequence);
        PopulateCameraSequence(external_camera_sequence, m_external_camera_sequence);

        Trace::GetLogger().STAMP(Trace::INFO) << "------All Internal Camera Buttons ------------ " << Trace::EndLog();
        for (auto & x : m_internal_camera_sequence)
            Trace::GetLogger().STAMP(Trace::INFO) << " " << x; 
        Trace::GetLogger().STAMP(Trace::INFO) << "\n------All External Camera Buttons ------------ " << Trace::EndLog();
        for (auto & x : m_external_camera_sequence)
            Trace::GetLogger().STAMP(Trace::INFO) << " " << x ;

        // Now populate camera buttons map.
        PopulateButtonsMap();

        // interchanging the last two cams between ECAM_L and ECAM_R
        auto temp_ECAM_L = m_all_ext_cam_type_button_map[ECAM_L];
        auto temp_ECAM_R = m_all_ext_cam_type_button_map[ECAM_R];

        m_all_ext_cam_type_button_map[ECAM_L][2] = temp_ECAM_R[2];
        m_all_ext_cam_type_button_map[ECAM_L][3] = temp_ECAM_R[3];

        m_all_ext_cam_type_button_map[ECAM_R][2] = temp_ECAM_L[2];
        m_all_ext_cam_type_button_map[ECAM_R][3] = temp_ECAM_L[3];

        if (m_car_count == CAB_6)
        {
            Trace::GetLogger().STAMP(Trace::INFO) << "6 CABS" << Trace::EndLog();

            m_internal_cam_group_seq.AddCameraGroup({ DM_SALOON_CAMERA_1, DM_SALOON_CAMERA_2, DM_SALOON_CAMERA_3, DM_SALOON_CAMERA_4 }); // Group 1
            m_internal_cam_group_seq.AddCameraGroup({ T_SALOON_CAMERA_1, T_SALOON_CAMERA_2, T_SALOON_CAMERA_3, T_SALOON_CAMERA_4 }); // Group 2
            m_internal_cam_group_seq.AddCameraGroup({ M_SALOON_CAMERA_1, M_SALOON_CAMERA_2, M_SALOON_CAMERA_3, M_SALOON_CAMERA_4 }); // Group 3
            m_internal_cam_group_seq.AddCameraGroup({ M_SALOON_CAMERA_1, M_SALOON_CAMERA_2, M_SALOON_CAMERA_3, M_SALOON_CAMERA_4 }); // Group 4
            m_internal_cam_group_seq.AddCameraGroup({ T_SALOON_CAMERA_1, T_SALOON_CAMERA_2, T_SALOON_CAMERA_3, T_SALOON_CAMERA_4 }); // Group 5
            m_internal_cam_group_seq.AddCameraGroup({ DM_SALOON_CAMERA_1, DM_SALOON_CAMERA_2, DM_SALOON_CAMERA_3, DM_SALOON_CAMERA_4 }); // Group 6

            //m_external_cam_group_seq.AddCameraGroup({ DM_EXTERIOR_CAMERA_1, M_EXTERIOR_CAMERA_1, DM_EXTERIOR_CAMERA_1, M_EXTERIOR_CAMERA_1  }); // Group 1
            //m_external_cam_group_seq.AddCameraGroup({ DM_EXTERIOR_CAMERA_2, M_EXTERIOR_CAMERA_2, DM_EXTERIOR_CAMERA_2, M_EXTERIOR_CAMERA_2 }); // Group 2

            m_external_cam_group_seq.AddCameraGroup({ DM_EXTERIOR_CAMERA_1, M_EXTERIOR_CAMERA_1, M_EXTERIOR_CAMERA_1, DM_EXTERIOR_CAMERA_1 }); // Group 1
            m_external_cam_group_seq.AddCameraGroup({ DM_EXTERIOR_CAMERA_2, M_EXTERIOR_CAMERA_2, M_EXTERIOR_CAMERA_2, DM_EXTERIOR_CAMERA_2 }); // Group 2

            m_ext_cam_group_seq.AddCameraGroup(m_all_ext_cam_type_button_map[ECAM_L]); // Group 1
            m_ext_cam_group_seq.AddCameraGroup(m_all_ext_cam_type_button_map[ECAM_R]); // Group 2
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::INFO) << "8 CABS" << Trace::EndLog();

            m_internal_cam_group_seq.AddCameraGroup({ DM_SALOON_CAMERA_1, DM_SALOON_CAMERA_2, DM_SALOON_CAMERA_3, DM_SALOON_CAMERA_4 }); // Group 1
            m_internal_cam_group_seq.AddCameraGroup({ T_SALOON_CAMERA_1, T_SALOON_CAMERA_2, T_SALOON_CAMERA_3, T_SALOON_CAMERA_4 }); // Group 2
            m_internal_cam_group_seq.AddCameraGroup({ M_SALOON_CAMERA_1, M_SALOON_CAMERA_2, M_SALOON_CAMERA_3, M_SALOON_CAMERA_4 }); // Group 3
            //m_internal_cam_group_seq.AddCameraGroup({ M_SALOON_CAMERA_1, M_SALOON_CAMERA_2, M_SALOON_CAMERA_3, M_SALOON_CAMERA_4 }); // Group 4
            m_internal_cam_group_seq.AddCameraGroup({ T_SALOON_CAMERA_1, T_SALOON_CAMERA_2, T_SALOON_CAMERA_3, T_SALOON_CAMERA_4 }); // Group 5
            m_internal_cam_group_seq.AddCameraGroup({ M_SALOON_CAMERA_1, M_SALOON_CAMERA_2, M_SALOON_CAMERA_3, M_SALOON_CAMERA_4 }); // Group 4 --
            m_internal_cam_group_seq.AddCameraGroup({ M_SALOON_CAMERA_1, M_SALOON_CAMERA_2, M_SALOON_CAMERA_3, M_SALOON_CAMERA_4 }); // Group 6
            m_internal_cam_group_seq.AddCameraGroup({ T_SALOON_CAMERA_1, T_SALOON_CAMERA_2, T_SALOON_CAMERA_3, T_SALOON_CAMERA_4 }); // Group 7
            m_internal_cam_group_seq.AddCameraGroup({ DM_SALOON_CAMERA_1, DM_SALOON_CAMERA_2, DM_SALOON_CAMERA_3, DM_SALOON_CAMERA_4 }); // Group 8

            m_external_cam_group_seq.AddCameraGroup({ DM_EXTERIOR_CAMERA_1, M_EXTERIOR_CAMERA_1, M_EXTERIOR_CAMERA_1, DM_EXTERIOR_CAMERA_1 }); // Group 1
            m_external_cam_group_seq.AddCameraGroup({ DM_EXTERIOR_CAMERA_2, M_EXTERIOR_CAMERA_2, M_EXTERIOR_CAMERA_2, DM_EXTERIOR_CAMERA_2 }); // Group 2

            m_ext_cam_group_seq.AddCameraGroup(m_all_ext_cam_type_button_map[ECAM_L]); // Group 1
            m_ext_cam_group_seq.AddCameraGroup(m_all_ext_cam_type_button_map[ECAM_R]); // Group 2
        }

        //Populate view mode to mode name map
        m_view_mode_to_mode_name.insert(std::make_pair(CCTVViewModes::FOUR_VIEW_MODE, FOUR_VIEW_MODE_STR));
        m_view_mode_to_mode_name.insert(std::make_pair(CCTVViewModes::SINGLE_VIEW_MODE, SINGLE_VIEW_MODE_STR));

        if (ICCTVProperties.GetCabCamera() == DMC_7)
        {
            std::vector<std::string> cab_camera_sequence;
            cab_camera_sequence.push_back(DMC_CAB);
            PopulateCameraSequence(cab_camera_sequence, m_cab_camera_sequence);

            for (int i = 0; i < static_cast<int>(m_cab_camera_sequence.size()); i++)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Cab: " << m_cab_camera_sequence[i] << Trace::EndLog();
                std::string button_name = m_cab_camera_sequence[i].substr(0, (m_cab_camera_sequence[i]).find("_"));;
                std::string veh_index_str = m_cab_camera_sequence[i].substr(m_cab_camera_sequence[i].find_first_of("_") + 1);
                size_t veh_index = stoi(veh_index_str) - 1;//veh_index_str starts from 1 hence it is reduced by 1 to match with standard indexing
                m_all_vehicle_cab_buttons.insert({ (veh_index), { veh_index, m_cab_camera_sequence[i], CameraViewButtons_State_DISABLED,
                    GetCameraType(DMC_7), INTERNAL_CAB_CAMERA_SELECTION, i } });
            }
            //for (auto x : m_all_vehicle_cab_buttons)
            //{
            //    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Cab -- VehicleIdx:" << x.first << ",  idx: " << x.second.vehicle_index 
            //                                                                        << ", camera_name: " << x.second.camera_name 
            //                                                                        << ", button_state: " << x.second.button_state
            //                                                                        << ", camera_type: " << x.second.camera_type 
            //                                                                        << ", cam_int_ext: " << x.second.cam_int_ext 
            //                                                                        << ", button_id: " << x.second.button_id
            //                                                                        << ", ext_cam_type: " << x.second.ext_cam_type << Trace::EndLog();
            //}
        }
    }
    catch (CommonException &ex)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Exception: " << ex.what() << Trace::EndLog();
    }

    iVisionInterface.AddObjectCreationCallback(Project::ClassID::PERSPECTIVE, MakeCallback(&CCTVState::ObjectCreated, this));
}

CCTVState::~CCTVState()
{
}


void CCTVState::CarCameraInfo::SetCarCameras(std::vector<Train::Data::TrainCamera> &cameras)
{
    m_car_camera_store = cameras;

    std::for_each(m_car_camera_store.begin(), m_car_camera_store.end(), [&](Train::Data::TrainCamera cam)
    {
        if (cam.camera_description.find(DMC_1) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_FRONT_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(DMC_2) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_TRACK_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(DMC_2) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_TRACK_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(DMC_3) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_EXTERIOR_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(DMC_4) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_EXTERIOR_CAMERA_2, cam));
        }
        else if (cam.camera_description.find(DMC_5) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_DETRAINMENT_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(DMC_6) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_ODD_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(DMC_7) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_CAB_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(DMC_8) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_SALOON_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(DMC_9) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_SALOON_CAMERA_2, cam));
        }
        else if (cam.camera_description.find(DMC_10) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_SALOON_CAMERA_3, cam));
        }
        else if (cam.camera_description.find(DMC_11) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::DM_SALOON_CAMERA_4, cam));
        }
        else if (cam.camera_description.find(TC_1) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::T_SALOON_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(TC_2) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::T_SALOON_CAMERA_2, cam));
        }
        else if (cam.camera_description.find(TC_3) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::T_SALOON_CAMERA_3, cam));
        }
        else if (cam.camera_description.find(TC_4) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::T_SALOON_CAMERA_4, cam));
        }
        else if (cam.camera_description.find(TC_5) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::T_PANTO_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(MC_1) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::M_SALOON_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(MC_2) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::M_SALOON_CAMERA_2, cam));
        }
        else if (cam.camera_description.find(MC_3) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::M_SALOON_CAMERA_3, cam));
        }
        else if (cam.camera_description.find(MC_4) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::M_SALOON_CAMERA_4, cam));
        }
        else if (cam.camera_description.find(MC_5) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::M_EXTERIOR_CAMERA_1, cam));
        }
        else if (cam.camera_description.find(MC_6) != std::string::npos)
        {
            m_mapped_cameras.insert(std::make_pair(CarCameraType::M_EXTERIOR_CAMERA_2, cam));
        }

    });
}

//std::vector<Train::Data::TrainCamera> CCTVState::CarCameraInfo::GetCarCameras() const
//{
//    return m_car_camera_store;
//}

//Train::Data::TrainCamera CCTVState::CarCameraInfo::GetCarCamera(CarCameraType camera)
//{
//    Train::Data::TrainCamera ret_camera;
//    auto cam_itr = m_mapped_cameras.find(camera);
//    if (cam_itr != m_mapped_cameras.end())
//    {
//        ret_camera = cam_itr->second;
//    }
//
//    return ret_camera;
//}

void CCTVState::CarCameraInfo::SetOrientation(size_t orientation)
{
    m_car_orientation = orientation;
}

size_t CCTVState::CarCameraInfo::GetOrientation() const
{
    return m_car_orientation;
}

void CCTVState::CarCameraInfo::SetCarType(CarType car_type)
{
    m_car_type = car_type;
}

CCTVState::CarType CCTVState::CarCameraInfo::GetCarType() const
{
    return m_car_type;
}

//std::map<CCTVState::CarCameraType, Train::Data::TrainCamera> CCTVState::CarCameraInfo::GetMappedCameras() const
//{
//    return m_mapped_cameras;
//}

void CCTVState::CarCameraInfo::SetPerspectiveOfCamera(size_t cam_id, size_t perspective_id)
{
    m_camera_id_to_perspective_id.insert(std::make_pair(cam_id, perspective_id));
}

size_t CCTVState::CarCameraInfo::GetPerspectiveOfCamera(const CarCameraType camera) const
{
    size_t perspective_id = -1;

    auto cam_itr = m_mapped_cameras.find(camera);
    if (cam_itr != m_mapped_cameras.end())
    {
        auto perspective_itr = m_camera_id_to_perspective_id.find(cam_itr->second.camera_id);
        if (perspective_itr != m_camera_id_to_perspective_id.end())
        {
            perspective_id = perspective_itr->second;
        }
    }

    return perspective_id;
}

void CCTVState::ObjectCreated(size_t class_id)
{
    switch (class_id)
    {
    case Project::ClassID::PERSPECTIVE:
    {
        for_each(m_camera_perspective_mapping.begin(), m_camera_perspective_mapping.end(), [&](std::pair<std::string, VehicleCameraPerspective > map_pair)
        {
            const auto perspective_id = m_visionInterface.GetPerspectiveId(map_pair.first);

            if (perspective_id != -1)
            {
                map_pair.second.camera_perspective_id = perspective_id;
                size_t vehicle_index = map_pair.second.vehicle_index;
                size_t cam_id = map_pair.second.train_camera_id;
                m_vehicle_cameras[vehicle_index].SetPerspectiveOfCamera(cam_id, perspective_id);
            }
        });
    }
    break;

    default:
        break;
    }
}

void CCTVState::SetDefaultLastActiveSingleViewCameraName()
{
    m_last_active_single_view_internal_camera_name = DEFAULT_INTERNAL_SINGLE_VIEW_BUTTON;
    m_last_active_single_view_external_camera_name = DEFAULT_EXTERNAL_SINGLE_VIEW_BUTTON;
}


CCTVState::CarCameraType CCTVState::GetCameraType(const std::string &camera_name)
{
    CCTVState::CarCameraType car_camera_type = CarCameraType::NONE;

    if (camera_name.find(DMC_1) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_FRONT_CAMERA_1;
    }
    else if (camera_name.find(DMC_2) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_TRACK_CAMERA_1;
    }
    else if (camera_name.find(DMC_3) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_EXTERIOR_CAMERA_1;
    }
    else if (camera_name.find(DMC_4) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_EXTERIOR_CAMERA_2;
    }
    else if (camera_name.find(DMC_5) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_DETRAINMENT_CAMERA_1;
    }
    else if (camera_name.find(DMC_6) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_ODD_CAMERA_1;
    }
    else if (camera_name.find(DMC_7) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_CAB_CAMERA_1;
    }
    else if (camera_name.find(DMC_8) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_SALOON_CAMERA_1;
    }
    else if (camera_name.find(DMC_9) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_SALOON_CAMERA_2;
    }
    else if (camera_name.find(DMC_10) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_SALOON_CAMERA_3;
    }
    else if (camera_name.find(DMC_11) != std::string::npos)
    {
        car_camera_type = CarCameraType::DM_SALOON_CAMERA_4;
    }
    else if (camera_name.find(TC_1) != std::string::npos)
    {
        car_camera_type = CarCameraType::T_SALOON_CAMERA_1;
    }
    else if (camera_name.find(TC_2) != std::string::npos)
    {
        car_camera_type = CarCameraType::T_SALOON_CAMERA_2;
    }
    else if (camera_name.find(TC_3) != std::string::npos)
    {
        car_camera_type = CarCameraType::T_SALOON_CAMERA_3;
    }
    else if (camera_name.find(TC_4) != std::string::npos)
    {
        car_camera_type = CarCameraType::T_SALOON_CAMERA_4;
    }
    else if (camera_name.find(TC_5) != std::string::npos)
    {
        car_camera_type = CarCameraType::T_PANTO_CAMERA_1;
    }
    else if (camera_name.find(MC_1) != std::string::npos)
    {
        car_camera_type = CarCameraType::M_SALOON_CAMERA_1;
    }
    else if (camera_name.find(MC_2) != std::string::npos)
    {
        car_camera_type = CarCameraType::M_SALOON_CAMERA_2;
    }
    else if (camera_name.find(MC_3) != std::string::npos)
    {
        car_camera_type = CarCameraType::M_SALOON_CAMERA_3;
    }
    else if (camera_name.find(MC_4) != std::string::npos)
    {
        car_camera_type = CarCameraType::M_SALOON_CAMERA_4;
    }
    else if (camera_name.find(MC_5) != std::string::npos)
    {
        car_camera_type = CarCameraType::M_EXTERIOR_CAMERA_1;
    }
    else if (camera_name.find(MC_6) != std::string::npos)
    {
        car_camera_type = CarCameraType::M_EXTERIOR_CAMERA_2;
    }
    return car_camera_type;
}
std::string CCTVState::GetCameraName(CarCameraType camera_type)
{
    std::string camera_name = "NO_CAMERA_FOUND";
    switch (camera_type)
    {
    case CarCameraType::DM_FRONT_CAMERA_1:
        camera_name = "DC-1";
        break;

    case CarCameraType::DM_TRACK_CAMERA_1:
        camera_name = "DC-2";
        break;
    case CarCameraType::DM_EXTERIOR_CAMERA_1:
        camera_name = "DC-3";
        break;

    case CarCameraType::DM_EXTERIOR_CAMERA_2:
        camera_name = "DC-4";
        break;

    case CarCameraType::DM_DETRAINMENT_CAMERA_1:
        camera_name = "DC-5";
        break;

    case CarCameraType::DM_ODD_CAMERA_1:
        camera_name = "DC-6";
        break;
    case CarCameraType::DM_CAB_CAMERA_1:
        camera_name = "DC-7";
        break;

    case CarCameraType::DM_SALOON_CAMERA_1:
        camera_name = "DC-8";
        break;

    case CarCameraType::DM_SALOON_CAMERA_2:
        camera_name = "DC-9";
        break;

    case CarCameraType::DM_SALOON_CAMERA_3:
        camera_name = "DC-10";
        break;
    case CarCameraType::DM_SALOON_CAMERA_4:
        camera_name = "DC-11";
        break;

    case CarCameraType::T_SALOON_CAMERA_1:
        camera_name = "TC-1";
        break;
    case CarCameraType::T_SALOON_CAMERA_2:
        camera_name = "TC-2";
        break;

    case CarCameraType::T_SALOON_CAMERA_3:
        camera_name = "TC-3";
        break;
    case CarCameraType::T_SALOON_CAMERA_4:
        camera_name = "TC-4";
        break;

    case CarCameraType::T_PANTO_CAMERA_1:
        camera_name = "TC-5";
        break;

    case CarCameraType::M_SALOON_CAMERA_1:
        camera_name = "MC-1";
        break;

    case CarCameraType::M_SALOON_CAMERA_2:
        camera_name = "MC-2";
        break;
    case CarCameraType::M_SALOON_CAMERA_3:
        camera_name = "MC-3";
        break;

    case CarCameraType::M_SALOON_CAMERA_4:
        camera_name = "MC-4";
        break;
    case CarCameraType::M_EXTERIOR_CAMERA_1:
        camera_name = "MC-5";
        break;

    case CarCameraType::M_EXTERIOR_CAMERA_2:
        camera_name = "MC-6";
        break;
    }
    return camera_name;
}

void CCTVState::PopulateCameraSequence(std::vector<std::string> & camera_sequence_source, std::vector<std::string> & camera_sequence_destination)
{
    for (size_t i = 0; i < m_trainCabs.size(); ++i)
    {    
        for (size_t j = 0; j < camera_sequence_source.size(); ++j)
        {
            if (camera_sequence_source[j].find("DMC-") != std::string::npos)
            {
                if (m_car_count == CAB_6 && (i == VEHICLE_1 || i == VEHICLE_6))
                    camera_sequence_destination.push_back(camera_sequence_source[j] + "_" + std::to_string(i + 1));
                else if (m_car_count == CAB_8 && (i == VEHICLE_1 || i == VEHICLE_8))
                    camera_sequence_destination.push_back(camera_sequence_source[j] + "_" + std::to_string(i + 1));
            }
            else if (camera_sequence_source[j].find("TC-") != std::string::npos)
            {
                if (m_car_count == CAB_6 && (i == VEHICLE_2 || i == VEHICLE_5))
                    camera_sequence_destination.push_back(camera_sequence_source[j] + "_" + std::to_string(i + 1));
                //else if (m_car_count == CAB_8 && (i == VEHICLE_2 || i == VEHICLE_5 || i == VEHICLE_7))
                else if (m_car_count == CAB_8 && (i == VEHICLE_2 || i == VEHICLE_4 || i == VEHICLE_7))
                    camera_sequence_destination.push_back(camera_sequence_source[j] + "_" + std::to_string(i + 1));
            }
            else if (camera_sequence_source[j].find("MC-") != std::string::npos)
            {
                //Trace::GetLogger().STAMP(Trace::INFO) << "m_train_vehcl_count_id: " << m_train_vehcl_count_id << Trace::EndLog();
                if (m_car_count == CAB_6 && (i == VEHICLE_3 || i == VEHICLE_4))
                    camera_sequence_destination.push_back(camera_sequence_source[j] + "_" + std::to_string(i + 1));
                //else if (m_car_count == CAB_8 && (i == VEHICLE_3 || i == VEHICLE_4 || i == VEHICLE_6))
                else if (m_car_count == CAB_8 && (i == VEHICLE_3 || i == VEHICLE_5 || i == VEHICLE_6))
                {
                    camera_sequence_destination.push_back(camera_sequence_source[j] + "_" + std::to_string(i + 1));
                    //Trace::GetLogger().STAMP(Trace::INFO) << "i: " << i << "value: " << internal_camera_sequence[j] + "_" + std::to_string(i) << Trace::EndLog();
                }
            }
        }
    }
}

//External camera type and camera button map 
// Each external cam type should have exactly 4 camera buttons to support four view
// in case of autorotation/static 4 view and external cam type selection
void CCTVState::PopulateExtCamTypButtonMap()
{
    auto addCameraType = [](CarCameraType cam_type, ExteriorCameraType ext_cam_type, std::vector< CameraButtonDescriptor> & button_list, 
        std::map<ExteriorCameraType, std::vector<CameraButtonDescriptor>> & all_ext_cam_type_button_map)
    {
        auto iter = std::find_if(button_list.begin(), button_list.end(), [&](CameraButtonDescriptor item)
        {
            return (cam_type == item.camera_type);
        });

        if (iter != button_list.end())
        {
            (*iter).ext_cam_type = ext_cam_type;
            auto it2 = all_ext_cam_type_button_map.find(ext_cam_type);
            if (it2 == all_ext_cam_type_button_map.end())
            {
                std::vector<CameraButtonDescriptor> v;
                v.push_back(*iter);
                all_ext_cam_type_button_map.insert({ ext_cam_type,  std::move(v) });
            }
            else
            {
                it2->second.push_back(*iter);
            }
        }
    };
    auto it = m_all_vehicle_external_buttons.begin();
    int veh_idx = 0;
    for ( ; it != m_all_vehicle_external_buttons.end(); it++)
    {
        auto & button_list = it->second;
        // ECAM Left and ECAM Right
        addCameraType(CarCameraType::DM_EXTERIOR_CAMERA_1, ExteriorCameraType::ECAM_L, button_list, m_all_ext_cam_type_button_map);
        addCameraType(CarCameraType::DM_EXTERIOR_CAMERA_2, ExteriorCameraType::ECAM_R, button_list, m_all_ext_cam_type_button_map);
        if (veh_idx == VEHICLE_3)
        {
            addCameraType(CarCameraType::M_EXTERIOR_CAMERA_1, ExteriorCameraType::ECAM_L, button_list, m_all_ext_cam_type_button_map);
            addCameraType(CarCameraType::M_EXTERIOR_CAMERA_2, ExteriorCameraType::ECAM_R, button_list, m_all_ext_cam_type_button_map);
        }
        else
        {
            if ( (m_car_count == CAB_6 && veh_idx == VEHICLE_4)
                || (m_car_count == CAB_8 && veh_idx == VEHICLE_6) )
            {
                addCameraType(CarCameraType::M_EXTERIOR_CAMERA_1, ExteriorCameraType::ECAM_L, button_list, m_all_ext_cam_type_button_map);
                addCameraType(CarCameraType::M_EXTERIOR_CAMERA_2, ExteriorCameraType::ECAM_R, button_list, m_all_ext_cam_type_button_map);
            }
        }

		//Commented below addCameraType() as per respective cam requirements
        // FCAM
        addCameraType(CarCameraType::DM_FRONT_CAMERA_1, ExteriorCameraType::FCAM, button_list, m_all_ext_cam_type_button_map);
        //addCameraType(CarCameraType::DM_TRACK_CAMERA_1, ExteriorCameraType::FCAM, button_list, m_all_ext_cam_type_button_map);
        // TCAM
        addCameraType(CarCameraType::DM_TRACK_CAMERA_1, ExteriorCameraType::TCAM, button_list, m_all_ext_cam_type_button_map);
        //addCameraType(CarCameraType::DM_FRONT_CAMERA_1, ExteriorCameraType::TCAM, button_list, m_all_ext_cam_type_button_map);
        // OCAM
        addCameraType(CarCameraType::DM_ODD_CAMERA_1, ExteriorCameraType::OCAM, button_list, m_all_ext_cam_type_button_map);
        //addCameraType(CarCameraType::DM_DETRAINMENT_CAMERA_1, ExteriorCameraType::OCAM, button_list, m_all_ext_cam_type_button_map);
        // PCAM
        addCameraType(CarCameraType::T_PANTO_CAMERA_1, ExteriorCameraType::PCAM, button_list, m_all_ext_cam_type_button_map);
        
        ++veh_idx;
    }

    for (auto it = m_all_ext_cam_type_button_map.begin(); it != m_all_ext_cam_type_button_map.end(); it++)
    {
        auto ext_cam_type = it->first;
        if (m_all_ext_cam_type_button_map[ext_cam_type].size() == 0)
            continue;
        int counter = 0;
        while (m_all_ext_cam_type_button_map[ext_cam_type].size() < FOUR_VIEW_SCREEN_ID) {
            auto & v = m_all_ext_cam_type_button_map[ext_cam_type];
            v.push_back(v[counter]);
            ++counter;
        }
    }
}

void CCTVState::PopulateVehicleButtonsMap(std::map<size_t, CameraButtonDescriptor> & all_camera_buttons, 
    std::map<size_t, std::vector<CameraButtonDescriptor>> & all_vehicle_button_map)
{
    auto it = all_camera_buttons.begin();
    for (; it != all_camera_buttons.end(); it++)
    {
        auto it2 = all_vehicle_button_map.find(it->second.vehicle_index);
        if (it2 == all_vehicle_button_map.end())
        {
            std::vector<CameraButtonDescriptor> v;
            v.push_back({ it->second.vehicle_index, it->second.camera_name, CameraViewButtons_State_DISABLED, it->second.camera_type, it->second.cam_int_ext, it->second.button_id });
            all_vehicle_button_map.insert({ (it->second.vehicle_index),  std::move(v)});
        }
        else
        {
            it2->second.push_back({ it->second.vehicle_index, it->second.camera_name, CameraViewButtons_State_DISABLED, it->second.camera_type, it->second.cam_int_ext, it->second.button_id });
        }    
    }
}
void CCTVState::PopulateButtonsMap()
{
    const std::string delimiter = "_";
    size_t button_id = 0;

    auto ButtonMapper = [&](std::vector<std::string> button_sequence,
                        std::vector<std::pair<std::string, std::string>> dmi_buttons_to_vehicle_cams,
                        std::map<size_t, CameraButtonDescriptor>& all_camera_buttons, CameraSelection ext_int_cam)
    {
        for (size_t index = 0; index < button_sequence.size(); ++index)
        {
            std::string button_name = button_sequence[index].substr(0, (button_sequence[index]).find(delimiter));
            std::string veh_index_str = button_sequence[index].substr(button_sequence[index].find_first_of(delimiter) + 1);
            
            auto iter = std::find_if(dmi_buttons_to_vehicle_cams.begin(), dmi_buttons_to_vehicle_cams.end(), [&](std::pair<std::string, std::string> item)
            {
                return (button_name == item.first);
            });

            if (iter != dmi_buttons_to_vehicle_cams.end())
            {
                std::string camera_name = iter->second;

                size_t veh_index = stoi(veh_index_str) - 1;//veh_index_str starts from 1 hence it is reduced by 1 to match with standard indexing

                CCTVState::CarCameraType camera_type = GetCameraType(iter->second.substr(iter->second.find_first_of(delimiter) + 1));
                
                std::string ext_int_cam_str;
                if (ext_int_cam == CameraSelection::EXTERNAL_CAMERA_SELECTION)
                    ext_int_cam_str = EXTERNAL;
                else if (ext_int_cam == CameraSelection::INTERNAL_CAMERA_SELECTION)
                    ext_int_cam_str = INTERNAL;

                Trace::GetLogger().STAMP(Trace::VERBOSE) << ext_int_cam_str << ": Vehicle # " << veh_index+1 << ", Button name: " << button_name << ", Cam Type: " << camera_type
                            << ", Cam Name: " << camera_name << Trace::EndLog();

                if (CarCameraType::NONE == camera_type)
                {
                    Trace::GetLogger().STAMP(Trace::ERR) << camera_type << " value is not a valid camera type." << Trace::EndLog();
                }
                ++button_id;
                all_camera_buttons.insert({ (button_id), { veh_index, button_sequence[index], CameraViewButtons_State_DISABLED, camera_type, ext_int_cam, (int)button_id } });
            }
        }
    };

    // Below sequence of mapping should remain same, i.e. mapping of internal cameras
    // first then mapping of external cameras, so that it can maintain button ids as:
    // 1_18 for Internal camera buttons;
    // 19_23 for external camera buttons;
    ButtonMapper(m_internal_camera_sequence, m_dmi_buttons_to_vehicle_internal_cams, m_all_internal_camera_buttons, INTERNAL_CAMERA_SELECTION);
    PopulateVehicleButtonsMap(m_all_internal_camera_buttons, m_all_vehicle_internal_buttons);
    
    ButtonMapper(m_external_camera_sequence, m_dmi_buttons_to_vehicle_external_cams, m_all_external_camera_buttons, EXTERNAL_CAMERA_SELECTION);
    PopulateVehicleButtonsMap(m_all_external_camera_buttons, m_all_vehicle_external_buttons);
    Trace::GetLogger().STAMP(Trace::INFO) << "Total count of Cameras, Internal: " << m_all_internal_camera_buttons.size() << ", External: " << m_all_external_camera_buttons.size()  << Trace::EndLog();

    PopulateExtCamTypButtonMap();
    for (auto& item : m_all_ext_cam_type_button_map)
    {
        for (int i = 0; i < static_cast<int>(item.second.size()); i++)
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Exterior Type: " << item.first << " ButtonName: " << item.second[i].camera_name << " CamType: " << item.second[i].camera_type << Trace::EndLog();
        }
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "-------------------------------------------------" << Trace::EndLog();
    }
}

void CCTVState::ResetState()
{
    m_just_powered_up = false;
    m_initialization_started = false;
    m_initialization_completed = false;
    m_auto_rotation_active = false;
    m_external_camera_selected = false;
    m_all_internal_camera_buttons.clear();
    PopulateButtonsMap();
    m_selected_button_id = 0.0;
    m_internal_cam_group_seq.ResetGroupIndex();
    m_external_cam_group_seq.ResetGroupIndex();
    m_ext_cam_group_seq.ResetGroupIndex();
    m_last_active_single_view_internal_camera_name = DEFAULT_INTERNAL_SINGLE_VIEW_BUTTON;
    m_last_active_single_view_external_camera_name = DEFAULT_EXTERNAL_SINGLE_VIEW_BUTTON;
    m_curr_vehicle_index = 0;
    m_curr_ext_cameraType_index = ECAM_L;
    m_current_ext_cam_vehicle_idx = 0;
}

