///
/// @file       AutoRotateSingleViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when auto rotation is started for Single view
///             (external or internal)
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "AutoRotateSingleViewController.h"

namespace
{
    const double AUTO_ROTATE_WAIT_TIME      = 30.0; //seconds
    const double AUTO_ROTATTION_STATE_ON    = 1.0;
    const double AUTO_ROTATTION_STATE_OFF   = 0.0;
    const int    MAX_ACTIVE_BUTTONS_COUNT   = 1;
}

AutoRotateSingleViewController::AutoRotateSingleViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    : CCTVViewController(comms, canvas, state)
    , m_last_iteration_button(0)
    , m_buttons_remaining_to_activate(0)
    , m_first_internal_camera_iteration(true)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

AutoRotateSingleViewController::~AutoRotateSingleViewController()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateSingleViewController Destructor" << Trace::EndLog();
}

void AutoRotateSingleViewController::MarkExecutionCompleted()
{
    SetWaitTime(0);
    m_last_iteration_button = 0;
    m_buttons_remaining_to_activate = 0;
    m_first_internal_camera_iteration = true;
}

void AutoRotateSingleViewController::Execute()
{
    if(IsWaitTimeOver() && IsAutoRotationEnabled())
    {
        SetWaitTime(m_saloon_cctv_state.m_auto_rotation_time);

        size_t total_button_count = 0;
        if (m_saloon_cctv_state.m_external_camera_selected)
        {
            //m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, );
            total_button_count = m_saloon_cctv_state.m_ext_cam_group_seq.GetGrpSequenceSize();
        }
        else
        {
            //m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, );
            total_button_count = m_saloon_cctv_state.m_internal_camera_sequence.size();
        }

        CameraViewButtons buttons;
        buttons.Clear();
        std::vector<size_t> perspective_ids; //perspective IDs to be updated on view
        m_buttons_remaining_to_activate = MAX_ACTIVE_BUTTONS_COUNT;
        if (!m_saloon_cctv_state.m_external_camera_selected)
            EnableButtonsInternal(total_button_count, perspective_ids, buttons);
        else
            EnableButtonsExternal(total_button_count, perspective_ids, buttons);

        std::string buttons_state;
        buttons.AppendToString(&buttons_state);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateSingleViewController::Execute() Buttons State : " << buttons.DebugString() << Trace::EndLog();

        m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);

        m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], perspective_ids);
    }
}
void AutoRotateSingleViewController::EnableButtonsExternal(size_t total_button_count, std::vector<size_t> &perspective_ids, CameraViewButtons &buttons)
{
    // External
    auto & all_camera_buttons = m_saloon_cctv_state.m_ext_cam_group_seq.GetCameraAutoSingleSequence();
    
    if (m_saloon_cctv_state.m_external_camera_selected)
    {
        m_first_internal_camera_iteration = false;
    }
    m_last_iteration_button = (m_last_iteration_button + 1) % total_button_count;
    m_saloon_cctv_state.m_ext_cam_group_seq.SetLastIterationButtonIndx(m_last_iteration_button);

    auto & camera_info = all_camera_buttons[m_last_iteration_button];

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateSingleViewController:: Ext Cam Type Index : " << camera_info.ext_cam_type << Trace::EndLog();
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, camera_info.ext_cam_type);

    CameraViewButtons_Button button;
    button.Clear();

    button.set_id(int(camera_info.ext_cam_type));
    button.set_name(camera_info.camera_name);

    camera_info.button_state = CameraViewButtons_State_ACTIVE;
    CameraViewButtons_AssociatedView associated_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;

    // Populate the perspective ids of cameras associated to active buttons.
    auto vehicle_index = camera_info.vehicle_index;
    auto cam_type = camera_info.camera_type;
    size_t perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(cam_type);
    perspective_ids.push_back(perspective_id);

    button.set_state(camera_info.button_state);
    button.set_associatedview(associated_view);
    buttons.add_button()->CopyFrom(button);
}

void AutoRotateSingleViewController::EnableButtonsInternal(size_t total_button_count, std::vector<size_t> &perspective_ids, CameraViewButtons &buttons)
{
    auto current_camera_sequence = m_saloon_cctv_state.m_external_camera_selected ?
                                   m_saloon_cctv_state.m_external_camera_sequence :
                                   m_saloon_cctv_state.m_internal_camera_sequence;

    auto all_camera_buttons = m_saloon_cctv_state.m_external_camera_selected ?
                              m_saloon_cctv_state.m_all_external_camera_buttons :
                              m_saloon_cctv_state.m_all_internal_camera_buttons;

    auto& last_active_single_view_camera_name = m_saloon_cctv_state.m_external_camera_selected ?
                                                m_saloon_cctv_state.m_last_active_single_view_external_camera_name :
                                                m_saloon_cctv_state.m_last_active_single_view_internal_camera_name;

    if (m_saloon_cctv_state.m_external_camera_selected)
    {
        m_first_internal_camera_iteration = false;
    }
    size_t vehicle_index = 0;

    for (auto const& camera_name : current_camera_sequence)
    {
        CameraViewButtons_Button button;
        button.Clear();

        CameraViewButtons_AssociatedView associated_view = CameraViewButtons_AssociatedView_NO_VIEW;

        auto buttons_itr = std::find_if(
            all_camera_buttons.begin(),
            all_camera_buttons.end(),
            [&](std::pair<size_t, CCTVState::CameraButtonDescriptor> item)
        {
            return (camera_name == item.second.camera_name);
        });

        if (buttons_itr != all_camera_buttons.end())
        {
            auto SetButtonActive = [&]()
            {
                //last_active_single_view_camera_name = buttons_itr->second.camera_name;
                buttons_itr->second.button_state = CameraViewButtons_State_ACTIVE;
                --m_buttons_remaining_to_activate;
                m_last_iteration_button = (m_last_iteration_button + 1) % total_button_count;

                // m_saloon_cctv_state.m_view_associated_camera_button[CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW] = buttons_itr->first;
                associated_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;
                // Populate the perspective ids of cameras associated to active buttons.
                vehicle_index = buttons_itr->second.vehicle_index;
                auto cam_type = buttons_itr->second.camera_type;
                size_t perspective_id = m_saloon_cctv_state.m_vehicle_cameras[vehicle_index].GetPerspectiveOfCamera(cam_type);
                perspective_ids.push_back(perspective_id);
            };

            //button.set_id(int(buttons_itr->first));
            button.set_id(int(buttons_itr->second.vehicle_index));
            button.set_name(buttons_itr->second.camera_name);

            buttons_itr->second.button_state = CameraViewButtons_State_INACTIVE;

            auto button_sequence = m_saloon_cctv_state.m_external_camera_selected ?
                (buttons_itr->first - m_saloon_cctv_state.m_internal_camera_sequence.size()) :
                buttons_itr->first;
            bool activeFlag = false;
            // Set next( next to previously selected buttons under auto rotation scheem) four buttons active, rest all inactive.
            if (m_first_internal_camera_iteration)
            {
                if (camera_name == m_saloon_cctv_state.m_default_active_single_internal_view_camera_name)
                {
                    m_first_internal_camera_iteration = false;
                    SetButtonActive();
                    activeFlag = true;
                }
                else
                {
                    m_last_iteration_button = (m_last_iteration_button + 1) % total_button_count;
                }
            }
            else if (button_sequence == (m_last_iteration_button + 1) &&
                m_buttons_remaining_to_activate > 0)
            {
                SetButtonActive();
                activeFlag = true;
            }

            button.set_state(buttons_itr->second.button_state);
            button.set_associatedview(associated_view);
            if (activeFlag)
                buttons.add_button()->CopyFrom(button);
        }
    }
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AutoRotateSingleViewController:: Int Cam Vehicle Index : " << vehicle_index+1 << Trace::EndLog();
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, vehicle_index+1);
}

bool AutoRotateSingleViewController::IsAutoRotationEnabled()
{
    double auto_rotate_status = m_saloon_cctv_state.m_auto_rotation_active ? AUTO_ROTATTION_STATE_ON : AUTO_ROTATTION_STATE_OFF;
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, auto_rotate_status);
    return m_saloon_cctv_state.m_auto_rotation_active;
}
