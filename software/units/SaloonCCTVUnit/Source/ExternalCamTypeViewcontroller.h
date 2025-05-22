///
/// @file       ExternalCamTypeViewcontroller.h
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

#pragma once

#include "CCTVViewController.h"

class ExternalCamTypeViewcontroller : public CCTVViewController
{
public:
    ExternalCamTypeViewcontroller(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~ExternalCamTypeViewcontroller();

    void Execute() override;
    void MarkExecutionCompleted() override;

private:
    bool m_executed = false;
};