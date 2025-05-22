///
/// @file       SelectedCameraViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when particular camera is selected
///             (external or internal)
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "SelectedCameraViewController.h"

namespace
{
    const size_t CANVAS_SINGLE_VIEW_ID = 0;
    const double AUTO_ROTATTION_OFF = 0.0;
}

SelectedCameraViewController::SelectedCameraViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    :CCTVViewController(comms, canvas, state),
    m_executed(false)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}


SelectedCameraViewController::~SelectedCameraViewController()
{
}

void SelectedCameraViewController::MarkExecutionCompleted()
{
    m_executed = false;
    //m_saloon_cctv_state.m_selected_button_id = m_saloon_cctv_state.m_external_camera_selected ?
    //                                            static_cast<double>(CCTVState::CarCameraType::DM_EXTERIOR_CAMERA_1) :
    //                                            static_cast<double>(CCTVState::CarCameraType::DM_SALOON_CAMERA_1);
}
void SelectedCameraViewController::Execute()
{
    if (!m_executed)
    {
        m_executed = true;
        if (!m_saloon_cctv_state.m_external_camera_selected && !m_saloon_cctv_state.m_detrainment_cam_enable)
        {
            EnableButtonInternalCam();
        }
        else if(m_saloon_cctv_state.m_detrainment_cam_enable) 
        {
            EnableButtonInternalCabCam();
        }
        else
        {
            EnableButtonExternalCam();
        }
    }
}
void SelectedCameraViewController::EnableButtonExternalCam()
{
    //external camera
    auto ext_cam_type_idx = m_saloon_cctv_state.m_curr_ext_cameraType_index;
    auto vehicle_idx = m_saloon_cctv_state.m_current_ext_cam_vehicle_idx;
    auto & all_ext_button_map = m_saloon_cctv_state.m_all_ext_cam_type_button_map;
    
    auto cam_type = 0;
    if (m_saloon_cctv_state.m_selected_button_id > 0.0)
        cam_type = size_t(m_saloon_cctv_state.m_selected_button_id);
    else
        return;
    bool camera_found = false;
    auto button_itr = all_ext_button_map.find(ext_cam_type_idx);
    if (button_itr != all_ext_button_map.end())
    {
        auto & all_buttons = button_itr->second;
        size_t i = 0;

        for (; i < all_buttons.size(); i++) 
        {
            if ((all_buttons[i].camera_type == cam_type) && (vehicle_idx == all_buttons[i].vehicle_index)) 
            {
                camera_found = true;
                break;
            }
        }

        if (camera_found)
        {
            auto & cameraDesc = all_buttons[i];
            UpdateUIAndVision(cameraDesc, CCTVState::CameraSelection::EXTERNAL_CAMERA_SELECTION);
        }
    }

    if (!camera_found)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "SelectedCameraViewController::Execute(): Provided button id : "
            << cam_type << " is not found in current selection of camera : EXTERNAL" << Trace::EndLog();
    }
}
void SelectedCameraViewController::EnableButtonInternalCam()
{
    auto cam_type = 0;
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Selected Camera button id: " << m_saloon_cctv_state.m_selected_button_id << Trace::EndLog();
    if (m_saloon_cctv_state.m_selected_button_id > 0.0)
        cam_type = size_t(m_saloon_cctv_state.m_selected_button_id);

    bool camera_found = false;

    auto it = m_saloon_cctv_state.m_all_vehicle_internal_buttons.find(m_saloon_cctv_state.m_curr_vehicle_index);
    if (it != m_saloon_cctv_state.m_all_vehicle_internal_buttons.end())
    {
        auto & all_buttons = it->second;
        size_t i = 0;

        for (; i < all_buttons.size(); i++) 
        {
            if (all_buttons[i].camera_type == cam_type) 
            {
                camera_found = true;
                break;
            }
        }

        if (camera_found)
        {
            auto & cameraDesc = all_buttons[i];
            UpdateUIAndVision(cameraDesc, CCTVState::CameraSelection::INTERNAL_CAMERA_SELECTION);
            m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, m_saloon_cctv_state.m_curr_vehicle_index + 1);
        }
    }
    if (!camera_found)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "SelectedCameraViewController::Execute(): Provided button id : "
            << cam_type << " is not found in current selection of camera : Internal" << Trace::EndLog();
    }
}

void SelectedCameraViewController::EnableButtonInternalCabCam()
{
    auto cam_type = 0;
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Selected Camera button id: " << m_saloon_cctv_state.m_selected_button_id << Trace::EndLog();
    if (m_saloon_cctv_state.m_selected_button_id > 0.0)
        cam_type = size_t(m_saloon_cctv_state.m_selected_button_id);

    bool camera_found = false;

    // exception condition added, as this camera is internal camera added in external sequence, so now modification of previous sequence could result in some abnormal behaviour
    if (cam_type == CCTVState::CarCameraType::DM_CAB_CAMERA_1)
    {
        auto it = m_saloon_cctv_state.m_all_vehicle_cab_buttons.find(m_saloon_cctv_state.m_curr_vehicle_index);
        if (it != m_saloon_cctv_state.m_all_vehicle_cab_buttons.end())
        {
            auto & all_buttons = it->second;
            size_t i = 0;

            if (all_buttons.camera_type == cam_type)
            {
                camera_found = true;
            }

            if (camera_found)
            {
                auto & cameraDesc = all_buttons;
                UpdateUIAndVision(cameraDesc, CCTVState::CameraSelection::INTERNAL_CAB_CAMERA_SELECTION);
                m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, m_saloon_cctv_state.m_curr_vehicle_index + 1);
            }
        }
        if (!camera_found)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "SelectedCameraViewController::Execute(): Provided button id : "
                << cam_type << " is not found in current selection of camera : Internal Cab Camera" << Trace::EndLog();
        }
    }
}

void SelectedCameraViewController::UpdateUIAndVision(CCTVState::CameraButtonDescriptor & cameraDesc, CCTVState::CameraSelection int_ext_type)
{
    m_saloon_cctv_state.m_current_button_name = cameraDesc.camera_name;
    
    CameraViewButtons buttons;
    buttons.Clear();
    CameraViewButtons_Button button;
    button.Clear();
    
    CameraViewButtons_AssociatedView asso_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;
    cameraDesc.button_state = CameraViewButtons_State_ACTIVE;
    std::string int_ext_str;
    if (int_ext_type == CCTVState::CameraSelection::INTERNAL_CAMERA_SELECTION)
    {
        button.set_id(int(cameraDesc.vehicle_index));
        int_ext_str = "Internal";
    }
    else if (int_ext_type == CCTVState::CameraSelection::EXTERNAL_CAMERA_SELECTION)
    {
        button.set_id(int(cameraDesc.ext_cam_type));
        int_ext_str = "External";
    }

    button.set_name(cameraDesc.camera_name);
    button.set_state(cameraDesc.button_state);
    button.set_associatedview(asso_view);
    
    buttons.add_button()->CopyFrom(button);
    
    std::string buttons_state;
    buttons.AppendToString(&buttons_state);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "SelectedCameraViewController::Execute() " << int_ext_str << " Buttons State : " << buttons.DebugString() << Trace::EndLog();
    
    m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);
    
    auto associated_vehicle_index = cameraDesc.vehicle_index;
    auto associated_camera = cameraDesc.camera_type;
    auto perspective_id = m_saloon_cctv_state.m_vehicle_cameras[associated_vehicle_index].GetPerspectiveOfCamera(associated_camera);
    
    m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], CANVAS_SINGLE_VIEW_ID, perspective_id);
    if (m_saloon_cctv_state.m_auto_rotation_active)
    {
        SetWaitTime(m_saloon_cctv_state.m_auto_rotation_time);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "SetWaitTime2" << Trace::EndLog();
    }
}



