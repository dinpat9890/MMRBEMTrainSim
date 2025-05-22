///
/// @file       MotionBaseControllerFactory.cpp
///
///             Factory for creating the correct client.  Possibly overkill
///             as we only have one implementation (the GenIII version).
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018

#ifndef MOTION_BASE_CONTROLLER_FACTORY_H
#define MOTION_BASE_CONTROLLER_FACTORY_H

#include "MotionBaseController.h"
#include "MotionBaseProperties.h"
#include <memory>

class MotionBaseControllerFactory
{
public:
    MotionBaseControllerFactory(const Project::MotionBaseProperties &properties);

    std::unique_ptr<MotionBaseController>   create_controller();

private:
    const Project::MotionBaseProperties     m_motion_base_properties;
};

#endif