///
/// @file       AutoRotateFourViewController.h
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
///

#pragma once

#include "CCTVViewController.h"

class AutoRotateFourViewController : public CCTVViewController
{
public:
    AutoRotateFourViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~AutoRotateFourViewController();

    void Execute() override;
    void MarkExecutionCompleted() override;

private:
    int m_buttons_remaining_to_activate;
    bool IsAutoRotationEnabled();
    void EnableButtonsInternalCams(size_t total_button_count, std::vector<size_t> &perspective_ids, CameraViewButtons &buttons);
    void EnableButtonsExternalCams(size_t total_button_count, std::vector<size_t> &perspective_ids, CameraViewButtons &buttons);
};
