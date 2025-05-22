///
/// @file       StaticSingleViewController.h
///
///             It is Derrived class for CCTVView Controller
///             and updates Vision and UI when auto rotation is stopped for Single view
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#pragma once

#include "CCTVViewController.h"

class StaticSingleViewController : public CCTVViewController
{
public:
    StaticSingleViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    ~StaticSingleViewController();

    void Execute() override;
    void MarkExecutionCompleted() override;
    void EnableButtonsInternalCams();
    void EnableButtonsExternalCams();

private:
    bool m_executed;
};
