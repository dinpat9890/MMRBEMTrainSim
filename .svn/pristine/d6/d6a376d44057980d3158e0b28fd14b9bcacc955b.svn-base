///
/// @file       AutoRotateFourViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when auto rotation is started for Four view
///             (external or internal)
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "AutoRotateFourViewController.h"

namespace
{
    const double AUTO_ROTATE_WAIT_TIME      = 30.0; //seconds
    const double AUTO_ROTATTION_STATE_ON    = 1.0;
    const double AUTO_ROTATTION_STATE_OFF   = 0.0;
    const int    MAX_ACTIVE_BUTTONS_COUNT   = 4;
}

AutoRotateFourViewController::AutoRotateFourViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    :CCTVViewController(comms, canvas, state)
    , m_buttons_remaining_to_activate(0)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

AutoRotateFourViewController::~AutoRotateFourViewController()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateFourViewController Destructor" << Trace::EndLog();
}

void AutoRotateFourViewController::MarkExecutionCompleted()
{
    SetWaitTime(0);
}

void AutoRotateFourViewController::Execute()
{
    if(IsWaitTimeOver() && IsAutoRotationEnabled())
    {
        SetWaitTime(m_saloon_cctv_state.m_auto_rotation_time);

        size_t total_button_count = m_saloon_cctv_state.m_external_camera_selected ?
                                    m_saloon_cctv_state.m_external_camera_sequence.size() :
                                    m_saloon_cctv_state.m_internal_camera_sequence.size();

        CameraViewButtons buttons;
        buttons.Clear();
        std::vector<size_t> perspective_ids; //perspective IDs to be updated on view
        m_buttons_remaining_to_activate = MAX_ACTIVE_BUTTONS_COUNT;  // 4

        if (!m_saloon_cctv_state.m_external_camera_selected)
            EnableButtonsInternalCams(total_button_count, perspective_ids, buttons);
        else
            EnableButtonsExternalCams(total_button_count, perspective_ids, buttons);

        std::string buttons_state;
        buttons.AppendToString(&buttons_state);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateFourViewController::Execute() Buttons State : " << buttons.DebugString() << Trace::EndLog();

        m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);

        m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE], perspective_ids);
    }
}

void AutoRotateFourViewController::EnableButtonsExternalCams(size_t total_button_count, std::vector<size_t> &perspective_ids, CameraViewButtons &buttons)
{
    // external camera
    auto current_camera_group = m_saloon_cctv_state.m_ext_cam_group_seq.GetGroupPostIncremental();
    auto all_camera_buttons = m_saloon_cctv_state.m_ext_cam_group_seq;
    
    m_saloon_cctv_state.m_curr_ext_cameraType_index = current_camera_group[0].ext_cam_type;
    m_saloon_cctv_state.m_curr_vehicle_index = 0;
    
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateFourViewController:: Ext Cam Type Index : " << m_saloon_cctv_state.m_curr_ext_cameraType_index << Trace::EndLog();
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, m_saloon_cctv_state.m_curr_ext_cameraType_index);
        
    for (auto & camera_info : current_camera_group)
    {
        //m_saloon_cctv_state.m_curr_ext_cameraType_index = camera_info.ext_cam_type;

        CameraViewButtons_Button button;
        CameraViewButtons_AssociatedView associated_view = CameraViewButtons_AssociatedView_NO_VIEW;
        button.Clear();

        bool activeFlg = false;
        button.set_id(int(camera_info.ext_cam_type));
        button.set_name(camera_info.camera_name);

        camera_info.button_state = CameraViewButtons_State_INACTIVE;

        // Set next( next to previously selected buttons under auto rotation scheem) four buttons active, rest all inactive.
        if (m_buttons_remaining_to_activate > 0)
        {
            camera_info.button_state = CameraViewButtons_State_ACTIVE;
            activeFlg = true;

            switch (m_buttons_remaining_to_activate)
            {
            case 4:
                associated_view = CameraViewButtons_AssociatedView_FIRST_VIEW;
                break;
            case 3:
                associated_view = CameraViewButtons_AssociatedView_SECOND_VIEW;
                break;
            case 2:
                associated_view = CameraViewButtons_AssociatedView_THIRD_VIEW;
                break;
            case 1:
                associated_view = CameraViewButtons_AssociatedView_FOURTH_VIEW;
                break;
            }
            --m_buttons_remaining_to_activate;

            // Populate the perspective ids of cameras associated to active buttons.
            const auto vehicle_index = camera_info.vehicle_index;
            const auto cam_type = camera_info.camera_type;
            size_t perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(cam_type);

            // condition for External cameras other than ECAM_L and ECAM_R
            if (m_buttons_remaining_to_activate <= 1 && camera_info.ext_cam_type != CCTVState::ExteriorCameraType::ECAM_L && camera_info.ext_cam_type != CCTVState::ExteriorCameraType::ECAM_R)
            {
                perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(CCTVState::CarCameraType::NONE);
                associated_view = CameraViewButtons_AssociatedView_NO_VIEW;
                camera_info.button_state = CameraViewButtons_State_INACTIVE;
            }
            perspective_ids.push_back(perspective_id);
        }

        button.set_state(camera_info.button_state);
        button.set_associatedview(associated_view);
        if (activeFlg)
            buttons.add_button()->CopyFrom(button);
    }
}
void AutoRotateFourViewController::EnableButtonsInternalCams(size_t total_button_count, std::vector<size_t> &perspective_ids, CameraViewButtons &buttons)
{
    auto CarCameraTypeMatched = [&](CCTVState::CarCameraType lhs_camera_type, CCTVState::CameraGroup camera_group)
    {
        bool matched = false;
        auto iter = std::find_if(camera_group.begin(), camera_group.end(), [&](CCTVState::CarCameraType rhs_camera_type) { return (lhs_camera_type == rhs_camera_type); });

        if (iter != camera_group.end())
            matched = true;

        return matched;
    };

    auto current_camera_group = m_saloon_cctv_state.m_internal_cam_group_seq.GetGroupPostIncremental();
    auto current_cam_sequence = m_saloon_cctv_state.m_internal_camera_sequence;
    auto all_camera_buttons   = m_saloon_cctv_state.m_all_internal_camera_buttons;
    
    m_saloon_cctv_state.m_curr_vehicle_index = m_saloon_cctv_state.m_internal_cam_group_seq.GetCurrentVehicleIndx();
    m_saloon_cctv_state.m_curr_ext_cameraType_index = CCTVState::ExteriorCameraType::ECAM_L;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateFourViewController:: Int Cam Vehicle Index : " << m_saloon_cctv_state.m_curr_vehicle_index+1 << Trace::EndLog();
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, m_saloon_cctv_state.m_curr_vehicle_index+1);

    for (auto const& camera_name : current_cam_sequence)
    {
        CameraViewButtons_Button button;
        CameraViewButtons_AssociatedView associated_view = CameraViewButtons_AssociatedView_NO_VIEW;
        button.Clear();

        auto buttons_itr = std::find_if(
            all_camera_buttons.begin(),
            all_camera_buttons.end(),
            [&](std::pair<size_t, CCTVState::CameraButtonDescriptor> item)
            {
                return (camera_name == item.second.camera_name);    
            });

        if (buttons_itr != all_camera_buttons.end())
        {
            bool activeFlg = false;
            button.set_id(int(buttons_itr->second.vehicle_index));
            button.set_name(buttons_itr->second.camera_name);

            buttons_itr->second.button_state = CameraViewButtons_State_INACTIVE;

            // Set next( next to previously selected buttons under auto rotation scheem) four buttons active, rest all inactive.
            if (CarCameraTypeMatched(buttons_itr->second.camera_type, current_camera_group) && (buttons_itr->second.vehicle_index == m_saloon_cctv_state.m_curr_vehicle_index) &&
                    m_buttons_remaining_to_activate > 0)
            {
                buttons_itr->second.button_state = CameraViewButtons_State_ACTIVE;
                activeFlg = true;
                // switch on button IDs
                switch (m_buttons_remaining_to_activate)
                {
                case 4:
                    associated_view = CameraViewButtons_AssociatedView_FIRST_VIEW;
                    break;
                case 3:
                    associated_view = CameraViewButtons_AssociatedView_SECOND_VIEW;
                    break;
                case 2:
                    associated_view = CameraViewButtons_AssociatedView_THIRD_VIEW;
                    break;
                case 1:
                    associated_view = CameraViewButtons_AssociatedView_FOURTH_VIEW;
                    break;
                }
                --m_buttons_remaining_to_activate;

                // Populate the perspective ids of cameras associated to active buttons.
                auto vehicle_index = buttons_itr->second.vehicle_index;
                auto cam_type = buttons_itr->second.camera_type;
                size_t perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(cam_type);
                
                //Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateFourViewController:: perspective_id " << perspective_id << Trace::EndLog();
                perspective_ids.push_back(perspective_id);
            }

            button.set_state(buttons_itr->second.button_state);
            button.set_associatedview(associated_view);
            if (activeFlg)
                buttons.add_button()->CopyFrom(button);
        }
    }
}

bool AutoRotateFourViewController::IsAutoRotationEnabled()
{
    double auto_rotate_status = m_saloon_cctv_state.m_auto_rotation_active ? AUTO_ROTATTION_STATE_ON : AUTO_ROTATTION_STATE_OFF;
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, auto_rotate_status);
    return m_saloon_cctv_state.m_auto_rotation_active;
}