///
/// @file       StaticSingleViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when auto rotation is stopped for Single view
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "StaticSingleViewController.h"

namespace
{
    const size_t CANVAS_SINGLE_VIEW_ID = 0;
    const double AUTO_ROTATTION_OFF = 0.0;
}

StaticSingleViewController::StaticSingleViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    :CCTVViewController(comms, canvas, state),
    m_executed(false)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}


StaticSingleViewController::~StaticSingleViewController()
{
}

void StaticSingleViewController::MarkExecutionCompleted()
{
    m_executed = false;
}
void StaticSingleViewController::Execute()
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

void StaticSingleViewController::EnableButtonsInternalCams()
{

    auto const& all_camera_buttons = m_saloon_cctv_state.m_external_camera_selected ?
        m_saloon_cctv_state.m_all_external_camera_buttons :
        m_saloon_cctv_state.m_all_internal_camera_buttons;

    auto const& last_active_single_view_camera_name = m_saloon_cctv_state.m_external_camera_selected ?
        m_saloon_cctv_state.m_last_active_single_view_external_camera_name :
        m_saloon_cctv_state.m_last_active_single_view_internal_camera_name;

    CameraViewButtons buttons;
    buttons.Clear();

    // Set auto rotation off
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, AUTO_ROTATTION_OFF);
    //m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SCREEN_ID, CCTVState::SINGLE_VIEW_SCREEN_ID);

    auto associated_vehicle_index = 0;

    auto buttons_itr = std::for_each(all_camera_buttons.begin(), all_camera_buttons.end(),
        [&](std::pair<size_t, CCTVState::CameraButtonDescriptor> item)
    {
        CameraViewButtons_Button button;
        button.Clear();
        bool activeFlg = false;
        CameraViewButtons_AssociatedView asso_view = CameraViewButtons_AssociatedView_NO_VIEW;
        item.second.button_state = CameraViewButtons_State_INACTIVE;

        if (item.second.camera_name == last_active_single_view_camera_name)
        {
            item.second.button_state = CameraViewButtons_State_ACTIVE;
            asso_view = CameraViewButtons_AssociatedView_SINGLE_FEED_VIEW;

            associated_vehicle_index = item.second.vehicle_index;
            auto associated_camera = item.second.camera_type;
            auto perspective_id = m_saloon_cctv_state.m_vehicle_cameras[associated_vehicle_index].GetPerspectiveOfCamera(associated_camera);

            m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], CANVAS_SINGLE_VIEW_ID, perspective_id);
            activeFlg = true;
        }

        //button.set_id(int(item.first));
        button.set_id(int(item.second.vehicle_index));
        button.set_name(item.second.camera_name);
        button.set_state(item.second.button_state);
        button.set_associatedview(asso_view);
        if (activeFlg)
            buttons.add_button()->CopyFrom(button);
    });

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "StaticSingleViewController:: Int Cam Vehicle Index : " << associated_vehicle_index + 1 << Trace::EndLog();
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, associated_vehicle_index + 1);

    std::string buttons_state;
    buttons.AppendToString(&buttons_state);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "StaticSingleViewController::Execute() Internal Buttons State : " << buttons.DebugString() << Trace::EndLog();

    m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);
}

void StaticSingleViewController::EnableButtonsExternalCams()
{

    // External
    auto & all_camera_buttons = m_saloon_cctv_state.m_ext_cam_group_seq.GetCameraAutoSingleSequence();

    auto last_iteration_button_indx = m_saloon_cctv_state.m_ext_cam_group_seq.GetLastIterationButtonIndx();
    auto & camera_info = all_camera_buttons[last_iteration_button_indx];

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "StaticSingleViewController:: Ext Cam Type Index : " << camera_info.ext_cam_type << Trace::EndLog();
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, camera_info.ext_cam_type);

    CameraViewButtons buttons;
    buttons.Clear();

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
    m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], CANVAS_SINGLE_VIEW_ID, perspective_id);

    button.set_state(camera_info.button_state);
    button.set_associatedview(associated_view);
    buttons.add_button()->CopyFrom(button);

    std::string buttons_state;
    buttons.AppendToString(&buttons_state);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "StaticSingleViewController::Execute() External Buttons State : " << buttons.DebugString() << Trace::EndLog();

    m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);
}
