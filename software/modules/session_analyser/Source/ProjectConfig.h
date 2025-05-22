///
/// @file       ProjectConfig.h
///
///             Declares the functions that need to be modified by a project to configure
///             SessionAnalyser's functionality.
///
/// @ingroup    Core Train Sim
///
/// @author     Dijon Page
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2009
///

#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H

#include <vector>
#include <string_view>
#include <memory>

class InterpretedTrainProperties;
class InfractionUnit;
class InfractionRule;

namespace Project
{
    class SessionAnalyserProperties;

    std::unique_ptr<InterpretedTrainProperties>  CreateInterpretedTrainProperties(
        InfractionUnit*  punit,
        InfractionRule*  prule,
        std::string_view car_class);
    
    std::vector<std::unique_ptr<InfractionRule>> CreateInfractionRules(
        InfractionUnit*                  punit,
        const SessionAnalyserProperties& props,
        std::string_view                 car_class,
        std::string_view                 hub_mode);
}

#endif // PROJECT_CONFIG_H
