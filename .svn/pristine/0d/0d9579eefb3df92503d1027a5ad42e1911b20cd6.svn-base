///
/// @file       StaticFourViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when auto rotation is stopped for Four view
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "StaticFourViewController.h"

namespace
{
    const size_t ACTIVE_BUTTON_COUNT_MAX = 4;
}

StaticFourViewController::StaticFourViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    : CCTVViewController(comms, canvas, state)
    , m_executed(false)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

StaticFourViewController::~StaticFourViewController()
{
}

void StaticFourViewController::MarkExecutionCompleted()
{
    m_executed = false;
}
void StaticFourViewController::Execute()
{
    if (!m_executed)
    {
        m_executed = true;

        if (!m_saloon_cctv_state.m_external_camera_selected)
            EnableButtonsInternalCams();
        else
            EnableButtonsExternalCams();
    }
}
void StaticFourViewController::EnableButtonsExternalCams()
{
    // External camera
    
    auto & all_ext_button_map = m_saloon_cctv_state.m_all_ext_cam_type_button_map;
    auto curr_ext_cam_indx = m_saloon_cctv_state.m_curr_ext_cameraType_index;
    m_saloon_cctv_state.m_curr_vehicle_index = 0;
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "StaticFourViewController:: Ext Cam Type Index : " << curr_ext_cam_indx << Trace::EndLog();
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, curr_ext_cam_indx);

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
                perspective_ids.push_back(perspective_id);
            }

            button.set_state(camera_info.button_state);
            button.set_associatedview(associated_view);
            if (activeFlg)
                buttons.add_button()->CopyFrom(button);
        }
        std::string buttons_state;
        buttons.AppendToString(&buttons_state);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "StaticFourViewController::Execute() Buttons State : " << buttons.DebugString() << Trace::EndLog();

        m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);
        m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, 0.0);

        m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE], perspective_ids);
    }
}

void StaticFourViewController::EnableButtonsInternalCams()
{
    size_t buttons_remaining_to_activate = ACTIVE_BUTTON_COUNT_MAX;

    auto CarCameraTypeMatched = [&](CCTVState::CarCameraType lhs_camera_type, CCTVState::CameraGroup camera_group)
    {
        bool matched = false;
        auto iter = std::find_if(camera_group.begin(), camera_group.end(), [&](CCTVState::CarCameraType rhs_camera_type) { return (lhs_camera_type == rhs_camera_type); });

        if (iter != camera_group.end())
            matched = true;

        return matched;
    };

    auto current_camera_group = m_saloon_cctv_state.m_external_camera_selected ?
        m_saloon_cctv_state.m_external_cam_group_seq.GetCurrentGroup() :
        m_saloon_cctv_state.m_internal_cam_group_seq.GetCurrentGroup();

    auto current_cam_sequence = m_saloon_cctv_state.m_external_camera_selected ?
        m_saloon_cctv_state.m_external_camera_sequence :
        m_saloon_cctv_state.m_internal_camera_sequence;

    auto all_camera_buttons = m_saloon_cctv_state.m_external_camera_selected ?
        m_saloon_cctv_state.m_all_external_camera_buttons :
        m_saloon_cctv_state.m_all_internal_camera_buttons;

    std::vector<size_t> perspective_ids;
    CameraViewButtons buttons;
    buttons.Clear();
    auto vehicle_index = 0;

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
            //button.set_id(int(buttons_itr->first));
            button.set_id(int(buttons_itr->second.vehicle_index));
            button.set_name(buttons_itr->second.camera_name);

            buttons_itr->second.button_state = CameraViewButtons_State_INACTIVE;
            // Set next( next to previously selected buttons under auto rotation scheem) four buttons active, rest all inactive.
            if (CarCameraTypeMatched(buttons_itr->second.camera_type, current_camera_group) && (buttons_itr->second.vehicle_index == m_saloon_cctv_state.m_curr_vehicle_index) &&
                buttons_remaining_to_activate > 0)
            {
                buttons_itr->second.button_state = CameraViewButtons_State_ACTIVE;
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

                //m_saloon_cctv_state.m_view_associated_camera_button[associated_view] = buttons_itr->first;

                // Populate the perspective ids of cameras associated to active buttons.
                vehicle_index = buttons_itr->second.vehicle_index;
                auto cam_type = buttons_itr->second.camera_type;
                size_t perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(cam_type);
                perspective_ids.push_back(perspective_id);
            }

            button.set_state(buttons_itr->second.button_state);
            button.set_associatedview(associated_view);
            if (activeFlg)
                buttons.add_button()->CopyFrom(button);
        }
    }

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "StaticFourViewController:: Int Cam Vehicle Index : " << vehicle_index + 1 << Trace::EndLog();
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, vehicle_index + 1);

    std::string buttons_state;
    buttons.AppendToString(&buttons_state);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "StaticFourViewController::Execute() Buttons State : " << buttons.DebugString() << Trace::EndLog();

    m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, 0.0);

    m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE], perspective_ids);
}

