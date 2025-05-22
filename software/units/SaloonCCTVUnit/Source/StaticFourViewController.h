///
/// @file       StaticFourViewController.h
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when auto rotation is stopped for Four view
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#pragma once

#include "CCTVViewController.h"

class StaticFourViewController : public CCTVViewController
{
public:
    StaticFourViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~StaticFourViewController();

    void Execute() override;
    void MarkExecutionCompleted() override;
    void EnableButtonsInternalCams();
    void EnableButtonsExternalCams();

private:
    bool m_executed;
};
