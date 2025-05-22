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

#include "CCTVViewController.h"
#include "project_comms_structure/ProjectObjectConstants.h"

CCTVViewController::CCTVViewController(CommsInterface &comms, CanvasViewManager &canvas_mgr, CCTVState &state)
    :
    m_comms_interface(comms),
    m_canvas_view_manager(canvas_mgr),
    m_saloon_cctv_state(state),
    m_required_cycle(0)
{
}

CCTVViewController::~CCTVViewController(void)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "CCTVViewController Destructor" << Trace::EndLog();
}

// Set required cycles(with given frequency) to be completed to achieve desired wait time
void CCTVViewController::SetWaitTime(double seconds)
{
    m_required_cycle = size_t(m_saloon_cctv_state.m_execution_frequency * seconds);
}

bool CCTVViewController::IsWaitTimeOver()
{
    bool wait_over = false;

    if(m_required_cycle != 0)
        --m_required_cycle;
    else
        wait_over = true;

    return wait_over;
}
