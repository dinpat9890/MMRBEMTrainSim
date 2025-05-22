///
/// @file       CCTVState.h
///
///             Store current CCTV States.
///             whether external or internal, auto rotation on/off and other states
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#pragma once

#include "core_properties/CommonProperties.h"
#include "core_types/SessionData.h"
#include "sim_comms/Gateway.h"
#include "Source/Protobuf/SaloonCCTVProtos.pb.h"
#include "Common/DataAccess.h"
#include "train_data_access/TrainDataAccessTypes.h"
#include "ICCTVProperties.h"
#include "IVisionInterface.h"
#include <list>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace salooncctv::protos;
class ITrainInterface;

class CCTVState
{
public:

    enum CCTVViewModes
    {
        SINGLE_VIEW_MODE = 0,
        FOUR_VIEW_MODE = 1
    };

    enum CarType
    {
        T_TYPE,
        M_TYPE,
        DM_TYPE
    };
    enum TrainCabType
    {
        CAB_6 = 6,
        CAB_8 = 8
    };

    enum CarCameraType
    {
        NONE = 0,
        DM_FRONT_CAMERA_1 = 1,
        DM_TRACK_CAMERA_1 = 2,
        DM_EXTERIOR_CAMERA_1 = 3,
        DM_EXTERIOR_CAMERA_2 = 4,
        DM_DETRAINMENT_CAMERA_1 = 5,
        DM_ODD_CAMERA_1 = 6,
        DM_CAB_CAMERA_1 = 7,
        DM_SALOON_CAMERA_1 = 8,
        DM_SALOON_CAMERA_2 = 9,
        DM_SALOON_CAMERA_3 = 10,
        DM_SALOON_CAMERA_4 = 11,
        T_SALOON_CAMERA_1 = 12,
        T_SALOON_CAMERA_2 = 13,
        T_SALOON_CAMERA_3 = 14,
        T_SALOON_CAMERA_4 = 15,
        T_PANTO_CAMERA_1 = 16,
        M_SALOON_CAMERA_1 = 17,
        M_SALOON_CAMERA_2 = 18,
        M_SALOON_CAMERA_3 = 19,
        M_SALOON_CAMERA_4 = 20,
        M_EXTERIOR_CAMERA_1 = 21,
        M_EXTERIOR_CAMERA_2 = 22,
    };

    enum ExteriorCameraType
    {
        NA = 0,
        ECAM_L = 1,
        FCAM = 2,
        TCAM = 3,
        OCAM = 4,
        PCAM = 5,
        ECAM_R = 6,
    };

    enum ScreenID
    {
        BLACK_SCREEN_ID = 0,
        SINGLE_VIEW_SCREEN_ID = 1,
        POWER_ON_SCREEN = 2,
        FOUR_VIEW_SCREEN_ID = 4
    };

    enum CameraSelection
    {
        EXTERNAL_CAMERA_SELECTION = 0,
        INTERNAL_CAMERA_SELECTION = 1,
        INTERNAL_CAB_CAMERA_SELECTION = 2
    };
    enum AlarmMode
    {
        ALARM_OFF = 0,
        ALARM_ON = 1,
    };
    enum AlarmType
    {
        None = 0,
        ALARM_FIRE_1 = 1,
        ALARM_OBSTCL_SALOON_DR_2 = 2,
        ALARM_PECU_3 = 3,
        ALARM_DR_UNLK_4 = 4,
        ALARM_EMRG_DR_OPN_5 = 5,
        ALARM_DRVR_DSK_6 = 6, //not in scope
        ALARM_OBSTRUCTION_DEFLCT_7 = 7,
        ALARM_TRACK_EVENT_8 = 8,
        ALARM_EMRG_CCTV_9 = 9,//not in scope
        ALARM_OHE_10 = 10,
        ALARM_PANTO_11 = 11,
    };
    
    enum PlatformSide
    {
        LEFT_SIDE = 1,
        RIGHT_SIDE = 2,
    };

    typedef std::vector<CarCameraType> CameraGroup;

    class CameraGroupSequence
    {
    public:
        CameraGroupSequence();
        CameraGroup GetCurrentGroup() const;
        void SetCurrentGroup(int veh_index);
        CameraGroup GetGroupPostIncremental();
        void ResetGroupIndex();
        void AddCameraGroup(CameraGroup camera_group);
        size_t GetCurrentVehicleIndx() { return m_current_group_index; }

    private:
        size_t                      m_current_group_index;
        size_t                      m_next_group_index;
        std::vector<CameraGroup>    m_camera_group_sequence;
    };


    struct CameraButtonDescriptor
    {
        CameraButtonDescriptor(
            size_t                         index,
            std::string                    name,
            CameraViewButtons_State        state,
            CarCameraType                  type,
            CameraSelection                   ext_int,
            int                               b_id,
            CCTVState::ExteriorCameraType  extcam_type = NA)
            : vehicle_index(index)
            , camera_name(name)
            , button_state(state)
            , camera_type(type)
            , cam_int_ext (ext_int)
            , button_id (b_id)
            , ext_cam_type(extcam_type)
        {
        }

        size_t                            vehicle_index;
        std::string                       camera_name;
        CameraViewButtons_State           button_state;
        CarCameraType                     camera_type;
        CameraSelection                      cam_int_ext;
        int                               button_id;
        CCTVState::ExteriorCameraType     ext_cam_type;
    };

    struct AlarmVehicleType
    {
        AlarmType eventType;
        int vehicle_idx;
        int pecu_alarm_id;
        CameraViewButtons_AssociatedView asso_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;
        bool operator ()(AlarmVehicleType & left, AlarmVehicleType & right)
        {
            return (static_cast<int>(left.eventType) > static_cast<int>(right.eventType));
        }
    };

    class CarCameraInfo
    {
    public:
        CarCameraInfo();
        virtual ~CarCameraInfo();

        void SetCarCameras(std::vector<Train::Data::TrainCamera> &cameras);

        void SetPerspectiveOfCamera(size_t cam_id, size_t perspective_id);
        size_t GetPerspectiveOfCamera(const CarCameraType camera) const;

        void SetOrientation(size_t orientation);
        size_t GetOrientation() const;

        void SetCarType(CarType car_type);
        CarType GetCarType() const;

        /*std::map<CarCameraType, Train::Data::TrainCamera> GetMappedCameras() const;*/

    private:
        CarType                                             m_car_type;
        size_t                                              m_car_orientation;
        std::vector<Train::Data::TrainCamera>               m_car_camera_store;
        std::map<CarCameraType, Train::Data::TrainCamera>   m_mapped_cameras;
        std::map<size_t, size_t>                            m_camera_id_to_perspective_id;
    };

    struct VehicleCameraPerspective
    {
        VehicleCameraPerspective(
            size_t index,
            int camera_id,
            int perspective_id)
            : vehicle_index(index)
            , train_camera_id(camera_id)
            , camera_perspective_id(perspective_id)
        {
        }

        size_t vehicle_index;
        int    train_camera_id;
        int    camera_perspective_id;
    };

    class ExtCameraGroupSequence
    {
    public:
        ExtCameraGroupSequence() {}
        std::vector<CameraButtonDescriptor> GetCurrentGroup() const 
        {
            return m_camera_group_sequence[m_current_group_index % m_camera_group_sequence.size()];
        }
        void SetCurrentGroup(int ext_cam_type) 
        {
            m_current_group_index = ext_cam_type;
            m_next_group_index = (ext_cam_type + 1) % m_camera_group_sequence.size();
        }
        std::vector<CameraButtonDescriptor> GetGroupPostIncremental() 
        {
            m_current_group_index = m_next_group_index;
            m_next_group_index = (m_next_group_index + 1) % m_camera_group_sequence.size();
            return m_camera_group_sequence[m_current_group_index];
        }
        void ResetGroupIndex() 
        {
            m_current_group_index = 0;
            m_next_group_index = 0;
        }
        void AddCameraGroup(std::vector<CameraButtonDescriptor> camera_group) 
        {
            m_camera_group_sequence.push_back(camera_group);
            for (auto & item : camera_group) 
            {
                m_cam_auto_single_seq.push_back(item);
            }
        }
        std::vector<CameraButtonDescriptor> & GetCameraAutoSingleSequence() { return m_cam_auto_single_seq; }
        size_t GetCurrentExtCamTypeIndx() { return m_current_group_index; }
        size_t GetGrpSequenceSize() 
        { 
            std::vector<CameraButtonDescriptor> & v = m_camera_group_sequence[0];
            return (m_camera_group_sequence.size() * v.size()); 
        }
        void SetLastIterationButtonIndx(int indx) { m_last_iteration_button_indx = indx; }
        int GetLastIterationButtonIndx() { return m_last_iteration_button_indx ; }

    private:
        size_t                                              m_current_group_index = 0;
        size_t                                              m_next_group_index = 0;
        std::vector<std::vector<CameraButtonDescriptor>>    m_camera_group_sequence;
        std::vector<CameraButtonDescriptor>                 m_cam_auto_single_seq;
        size_t                                              m_last_iteration_button_indx = 0;
    };

public:
    CCTVState(IVisionInterface &iVisionInterface, ICCTVProperties &iCCTVProperties, ITrainInterface &iTrainInterface);
    ~CCTVState();

    void ResetState();
    void ObjectCreated(size_t class_id);
    void SetDefaultLastActiveSingleViewCameraName();
    CarCameraType GetCameraType(const std::string &camera_name);
    std::string   GetCameraName(CarCameraType camera_type);
    void PopulateVehicleButtonsMap(std::map<size_t, CameraButtonDescriptor> & all_camera_buttons, 
        std::map<size_t, std::vector<CameraButtonDescriptor>> & all_vehicle_button_map);
    
    void CCTVState::PopulateCameraSequence(std::vector<std::string> & camera_sequence_source, std::vector<std::string> & camera_sequence_destination);
    void PopulateExtCamTypButtonMap();

    size_t                         m_car_count;
    double                         m_selected_button_id = 0.0;
    double                         m_execution_frequency = 0.0;
    double                         m_powerup_time;
    double                         m_initialization_time;
    double                         m_auto_rotation_time;
    size_t                         m_train_id = 0;
    bool                           m_just_powered_up = false;
    bool                           m_initialization_started = false;
    bool                           m_initialization_completed = false;
    bool                           m_cctv_started = false;
    bool                           m_auto_rotation_active = false;
    bool                           m_external_camera_selected = false;
    bool                           m_detrainment_cam_enable = false;
    size_t                         m_train_vehcl_count_id;
    int                            m_curr_vehicle_index = 0;
    ExteriorCameraType             m_curr_ext_cameraType_index = ECAM_L;
    int                            m_current_ext_cam_vehicle_idx = 0;
    std::string                    m_current_button_name;
    bool                           m_alarm_mode = false;
    AlarmType                      m_current_alarm_event = None;


    std::string                                           m_last_active_single_view_internal_camera_name;
    std::string                                           m_last_active_single_view_external_camera_name;
    std::string                                           m_default_active_single_internal_view_camera_name;
                                                          
    std::vector<int>                                      m_trainCabs;
    //button name mapped to vehindex_cameraname              
    std::vector<std::pair<std::string, std::string>>      m_dmi_buttons_to_vehicle_internal_cams;
    std::vector<std::pair<std::string, std::string>>      m_dmi_buttons_to_vehicle_external_cams;
    
    // Camera Sequence for rotation, using button names
    std::vector<std::string>                              m_internal_camera_sequence;
    std::vector<std::string>                              m_external_camera_sequence;
    std::vector<std::string>                              m_cab_camera_sequence;

    // Vector train vehicle's and it's all cameras' info
    std::vector<CarCameraInfo>                            m_vehicle_cameras;

    CameraGroupSequence                                   m_internal_cam_group_seq;
    CameraGroupSequence                                   m_external_cam_group_seq;
    ExtCameraGroupSequence                                m_ext_cam_group_seq;

    // map of camera button ID and Camera_Button_Descriptor_t
    std::map<size_t, CameraButtonDescriptor>              m_all_internal_camera_buttons;
    std::map<size_t, CameraButtonDescriptor>              m_all_external_camera_buttons;

    std::map<size_t, std::vector<CameraButtonDescriptor>> m_all_vehicle_internal_buttons;
    std::map<size_t, std::vector<CameraButtonDescriptor>> m_all_vehicle_external_buttons;
    std::map<size_t, CameraButtonDescriptor>              m_all_vehicle_cab_buttons;

    std::map<CCTVViewModes, std::string>                  m_view_mode_to_mode_name;
    std::map<std::string, VehicleCameraPerspective>       m_camera_perspective_mapping;
    
    // map of exterior camera type and camera button dscriptor
    std::map<ExteriorCameraType, std::vector<CameraButtonDescriptor>>                      m_all_ext_cam_type_button_map;
    std::priority_queue<AlarmVehicleType, std::vector<AlarmVehicleType>, AlarmVehicleType> m_alarm_events;
    std::set<int> m_current_alarm_list;

private:
    void PopulateButtonsMap();
    ITrainInterface &m_trainInterface;
    IVisionInterface &m_visionInterface;
};
