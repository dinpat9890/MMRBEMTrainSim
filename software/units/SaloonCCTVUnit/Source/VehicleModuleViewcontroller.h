///
/// @file       VehicleModuleViewController.h
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI based on selected Vehicle Index
///             (only internal)
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#pragma once

#include "CCTVViewController.h"

class VehicleModuleViewController : public CCTVViewController
{
public:
    VehicleModuleViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~VehicleModuleViewController();

    void Execute() override;
    void MarkExecutionCompleted() override;

private:
    bool m_executed=false;
};