///
/// @file       VehicleModuleViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI based on selected Vehicle Index
///             (only internal)
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "VehicleModuleViewController.h"

namespace
{
    const size_t ACTIVE_BUTTON_COUNT_MAX = 4;
}

VehicleModuleViewController::VehicleModuleViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    : CCTVViewController(comms, canvas, state)
    , m_executed(false)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

VehicleModuleViewController::~VehicleModuleViewController()
{
}

void VehicleModuleViewController::MarkExecutionCompleted()
{
    m_executed = false;
}

void VehicleModuleViewController::Execute()
{
    if (!m_executed)
    {
        m_executed = true;
        size_t buttons_remaining_to_activate = ACTIVE_BUTTON_COUNT_MAX;

        if (!m_saloon_cctv_state.m_external_camera_selected)
        {
            auto & all_camera_buttons = m_saloon_cctv_state.m_all_vehicle_internal_buttons;

            std::vector<size_t> perspective_ids;
            CameraViewButtons buttons;
            buttons.Clear();

            for (auto & button_indx_vehicle : all_camera_buttons[m_saloon_cctv_state.m_curr_vehicle_index])
            {
                CameraViewButtons_Button button;
                CameraViewButtons_AssociatedView associated_view = CameraViewButtons_AssociatedView_NO_VIEW;
                button.Clear();

                bool activeFlg = false;
                button.set_id(int(button_indx_vehicle.vehicle_index));
                button.set_name(button_indx_vehicle.camera_name);

                button_indx_vehicle.button_state = CameraViewButtons_State_INACTIVE;
                // Set next( next to previously selected buttons under auto rotation scheem) four buttons active, rest all inactive.
                if (buttons_remaining_to_activate > 0 && button_indx_vehicle.cam_int_ext == CCTVState::CameraSelection::INTERNAL_CAMERA_SELECTION)
                {
                    button_indx_vehicle.button_state = CameraViewButtons_State_ACTIVE;
                    activeFlg = true;
                    // switch on button IDs
                    switch (buttons_remaining_to_activate)
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
                    --buttons_remaining_to_activate;

                    // Populate the perspective ids of cameras associated to active buttons.
                    auto vehicle_index = button_indx_vehicle.vehicle_index;
                    auto cam_type = button_indx_vehicle.camera_type;
                    size_t perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(cam_type);
                    
                    // condition for Emergency/Detrainment door cameras DM_CAB_CAMERA_1
                    if (m_saloon_cctv_state.m_detrainment_cam_enable == true)
                    {
                        perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(CCTVState::CarCameraType::DM_CAB_CAMERA_1);
                    }
                    // below code (buttons_remaining_to_activate) is to add no view (or black screen) for other 3 views in four view mode
                    if (buttons_remaining_to_activate <= 2 && m_saloon_cctv_state.m_detrainment_cam_enable == true)
                    {
                        perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(CCTVState::CarCameraType::NONE);
                        associated_view = CameraViewButtons_AssociatedView_NO_VIEW;
                        button_indx_vehicle.button_state = CameraViewButtons_State_INACTIVE;
                    }

                    perspective_ids.push_back(perspective_id);
                }

                button.set_state(button_indx_vehicle.button_state);
                button.set_associatedview(associated_view);
                if (activeFlg)
                    buttons.add_button()->CopyFrom(button);
            }
            std::string buttons_state;
            buttons.AppendToString(&buttons_state);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "VehicleModuleViewController::Execute() Buttons State : " << buttons.DebugString() << Trace::EndLog();

            m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);

            m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE], perspective_ids);
            m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, m_saloon_cctv_state.m_curr_vehicle_index + 1);
            if (m_saloon_cctv_state.m_auto_rotation_active)
            {
                SetWaitTime(m_saloon_cctv_state.m_auto_rotation_time);
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "SetWaitTime" << Trace::EndLog();
            }
        }
    }
}
