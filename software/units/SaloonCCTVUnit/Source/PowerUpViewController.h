///
/// @file       PowerUpViewController.h
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI CCTV is started
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#pragma once

#include "CCTVViewController.h"

class PowerUpViewController : public CCTVViewController
{
public:
    PowerUpViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~PowerUpViewController();

    void Execute() override;
};
