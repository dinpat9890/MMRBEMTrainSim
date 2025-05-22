///
/// @file       SelectedCameraViewController.h
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

#pragma once

#include "CCTVViewController.h"

class SelectedCameraViewController : public CCTVViewController
{
public:
    SelectedCameraViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~SelectedCameraViewController();

    void Execute() override;
    void MarkExecutionCompleted() override;
    void EnableButtonExternalCam();
    void EnableButtonInternalCam();
    void EnableButtonInternalCabCam();

private:
    void UpdateUIAndVision(CCTVState::CameraButtonDescriptor & cameraDesc, CCTVState::CameraSelection int_ext_type);

private:
    bool m_executed;
};
