///
/// @file       ShutdownViewController.h
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI CCTV is stopped
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#pragma once

#include "CCTVViewController.h"

class ShutdownViewController : public CCTVViewController
{
public:
    ShutdownViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~ShutdownViewController();

    void Execute() override;
};
