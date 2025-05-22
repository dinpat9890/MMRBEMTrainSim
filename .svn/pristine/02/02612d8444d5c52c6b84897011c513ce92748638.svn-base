///
/// @file       CCTVViewController.cpp
///
///             It is base abstract class for View Controller
///             and updates Vision and UI based on request type by calling appropriate concrete class function
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#pragma once

#include "CanvasViewManager.h"
#include "CommsInterface.h"
#include "CCTVState.h"

#include "Source/Protobuf/SaloonCCTVProtos.pb.h"

#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_services/CanvasObjectPerspectiveControl.h"

class CCTVViewController
{
public:
    CCTVViewController(CommsInterface &comms, CanvasViewManager &canvas, CCTVState &state);
    virtual ~CCTVViewController();

    virtual void Execute() = 0;
    virtual void MarkExecutionCompleted() {}
    bool IsWaitTimeOver();

protected:
    void SetWaitTime(double seconds);
    //bool IsWaitTimeOver();

    CommsInterface      &m_comms_interface;
    CanvasViewManager   &m_canvas_view_manager;
    CCTVState     &m_saloon_cctv_state;
    size_t              m_required_cycle;
};
