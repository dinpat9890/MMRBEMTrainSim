///
/// @file       PowerUpViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI CCTV is started
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "PowerUpViewController.h"

namespace
{
    // These time durations are in seconds.
    const double BOOTUP_WAIT_TIME = 10.0;
    const double INITIALIZATION_WAIT_TIME = 60.0;
}

PowerUpViewController::PowerUpViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    :CCTVViewController(comms, canvas, state)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

PowerUpViewController::~PowerUpViewController()
{
}

void PowerUpViewController::Execute()
{
    //Trace::GetLogger().STAMP(Trace::VERBOSE) << "PowerUpViewController CHECK" << Trace::EndLog();
    if (IsWaitTimeOver())
    {        
        if (m_saloon_cctv_state.m_just_powered_up)
        {
            m_saloon_cctv_state.m_just_powered_up = false;
            SetWaitTime(m_saloon_cctv_state.m_powerup_time);

            m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SCREEN_ID, double(CCTVState::BLACK_SCREEN_ID));
            m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::TRAIN_ID, double(m_saloon_cctv_state.m_train_id));
            CameraViewButtons buttons;
            buttons.Clear();

            for (auto itr = m_saloon_cctv_state.m_all_internal_camera_buttons.begin(); itr != m_saloon_cctv_state.m_all_internal_camera_buttons.end(); ++itr)
            {
                CameraViewButtons_Button button;
                button.Clear();
                button.set_id(int(itr->first));
                button.set_name(itr->second.camera_name);
                button.set_state(itr->second.button_state);
                button.set_associatedview(CameraViewButtons_AssociatedView_NO_VIEW);
                if ( itr->second.vehicle_index == 0)
                    buttons.add_button()->CopyFrom(button);
            }
            std::string buttons_state;
            buttons.AppendToString(&buttons_state);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "PowerUpViewController::Execute() Buttons State : " << buttons.DebugString() << Trace::EndLog();

            m_comms_interface.SetOutputRaw(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, buttons_state);
        }
        else if (!m_saloon_cctv_state.m_initialization_started)
        {
            // Flow should reach here when BOOTUP_WAIT_TIME expires.
            m_saloon_cctv_state.m_initialization_started = true;
            SetWaitTime(m_saloon_cctv_state.m_initialization_time);

            m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SCREEN_ID, double(CCTVState::POWER_ON_SCREEN));
        }
        else
        {
            m_saloon_cctv_state.m_initialization_completed = true;
        }
            
        std::vector<size_t> perspective_ids{ 0, 0, 0, 0 };
        m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE], perspective_ids);
        m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], 0, 0);
    }
}
