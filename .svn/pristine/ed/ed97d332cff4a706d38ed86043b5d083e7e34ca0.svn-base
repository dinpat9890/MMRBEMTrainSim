///
/// @file       AutoRotateSingleViewController.h
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

#pragma once

#include "CCTVViewController.h"

class AutoRotateSingleViewController : public CCTVViewController
{
public:
    AutoRotateSingleViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~AutoRotateSingleViewController();

    void Execute() override;
    void MarkExecutionCompleted() override;

private:
    int m_last_iteration_button;
    int m_buttons_remaining_to_activate;
    bool m_first_internal_camera_iteration;
    bool IsAutoRotationEnabled();
    void EnableButtonsInternal(size_t total_button_count, std::vector<size_t> &perspective_ids, CameraViewButtons &buttons);
    void EnableButtonsExternal(size_t total_button_count, std::vector<size_t> &perspective_ids, CameraViewButtons &buttons);
};
