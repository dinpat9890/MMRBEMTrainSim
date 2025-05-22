///
/// @file       ShutdownViewController.cpp
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI CCTV is stopped
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "ShutdownViewController.h"

namespace
{
    const double AUTO_ROTATTION_OFF = 0.0;
}

ShutdownViewController::ShutdownViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state)
    :CCTVViewController(comms, canvas, state)
{
    std::vector<std::string> view_modes;
    view_modes.push_back(state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE]);
    canvas.AddCameraViewModes(view_modes);
}

ShutdownViewController::~ShutdownViewController()
{
}

void ShutdownViewController::Execute()
{
    std::vector<size_t> perspective_ids{ 0, 0, 0, 0 };
    m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::FOUR_VIEW_MODE], perspective_ids);
    m_canvas_view_manager.UpdateView(m_saloon_cctv_state.m_view_mode_to_mode_name[CCTVState::SINGLE_VIEW_MODE], 0, 0);

    //m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::SCREEN_ID, CCTVState::BLACK_SCREEN_ID);
    m_comms_interface.SetOutputNumber(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, AUTO_ROTATTION_OFF);
}
