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
///
#include "MotionBaseControllerFactory.h"
#include "MotionBaseDataConnectionFactory.h"
#include "GenIIIClient.h"

MotionBaseControllerFactory::MotionBaseControllerFactory(const Project::MotionBaseProperties &properties)
    : m_motion_base_properties(properties)
{}

std::unique_ptr<MotionBaseController> MotionBaseControllerFactory::create_controller()
{
    auto factory = MotionBaseDataConnectionFactory(m_motion_base_properties);
    
    auto connection = factory.GetDataConnection();

    return std::unique_ptr<ckas_interface::gen_3_client> ( 
            new ckas_interface::gen_3_client(m_motion_base_properties, std::move(connection)) 
        );
}