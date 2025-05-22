///
/// @file       ExternalCamTypeViewcontroller.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when external Camera type is selected
///             (only external)
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "ExternalCamTypeViewcontroller.h"

namespace
{
    const size_t ACTIVE_BUTTON_COUNT_MAX = 4;
}

ExternalCamTypeViewcontroller::ExternalCamTypeViewcontroller(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    : CCTVViewController(comms, canvas, state)
    , m_executed(false)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

ExternalCamTypeViewcontroller::~ExternalCamTypeViewcontroller()
{
}

void ExternalCamTypeViewcontroller::MarkExecutionCompleted()
{
    m_executed = false;
}

void ExternalCamTypeViewcontroller::Execute()
{
    if (!m_executed)
    {
        m_executed = true;

        // External camera

        auto & all_ext_button_map = m_saloon_cctv_state.m_all_ext_cam_type_button_map;
        auto curr_ext_cam_indx = m_saloon_cctv_state.m_curr_ext_cameraType_index;
        m_saloon_cctv_state.m_curr_vehicle_index = 0;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "ExternalCamTypeViewcontroller::EnableButtonsExternalCams: " << curr_ext_cam_indx << Trace::EndLog();

        auto button_itr = all_ext_button_map.find(curr_ext_cam_indx);
        if (button_itr != all_ext_button_map.end())
        {
            CameraViewButtons buttons;
            buttons.Clear();
            std::vector<size_t> perspective_ids; //perspective IDs to be updated on view
            //m_buttons_remaining_to_activate = MAX_ACTIVE_BUTTONS_COUNT;  // 4
            size_t buttons_remaining_to_activate = ACTIVE_BUTTON_COUNT_MAX;
            auto & button_list = button_itr->second;
            for (auto & camera_info : button_list)
            {
                CameraViewButtons_Button button;
                CameraViewButtons_AssociatedView associated_view = CameraViewButtons_AssociatedView_NO_VIEW;
                button.Clear();

                bool activeFlg = false;
                button.set_id(int(camera_info.ext_cam_type));
                button.set_name(camera_info.camera_name);

                camera_info.button_state = CameraViewButtons_State_INACTIVE;

                // Set next( next to previously selected buttons under auto rotation scheem) four buttons active, rest all inactive.
                if (buttons_remaining_to_activate > 0)
                {
                    camera_info.button_state = CameraViewButtons_State_ACTIVE;
                    activeFlg = true;

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
                    auto vehicle_index = camera_info.vehicle_index;
                    auto cam_type = camera_info.camera_type;
                    size_t perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(cam_type);

                    // condition for External cameras other than ECAM_L and ECAM_R
                    if (buttons_remaining_to_activate <= 1 && camera_info.ext_cam_type != CCTVState::ExteriorCameraType::ECAM_L && camera_info.ext_cam_type != CCTVState::ExteriorCameraType::ECAM_R)
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
            std::string buttons_state;
            buttons.AppendToString(&buttons_state);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "ExternalCamTypeViewcontroller::Execute() Buttons State : " << buttons.DebugString() << Trace::EndLog();

            m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);

            m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE], perspective_ids);
            if (m_saloon_cctv_state.m_auto_rotation_active)
            {
                SetWaitTime(m_saloon_cctv_state.m_auto_rotation_time);
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "SetWaitTime after Ext Cam Type Request" << Trace::EndLog();
            }
        }
    }
}
