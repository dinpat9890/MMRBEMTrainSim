///
/// @file       ModeTransitionMachine.cpp
///
///             Implements the Classes which are responsible for transiting to other modes.
///
/// @author     Adam Zielinski
///             Amol Ganbavale
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#include "ModeTransitionMachine.h"

#include "project_comms_structure/ProjectObjectConstants.h"

#include "common/StandardLogging.h"

using namespace Project::CBTCOnBoard;

/// Initializes a new instance of the NoMode Mode class.
///
/// @param mc reference to ModeTransitionModule

NoMode::NoMode(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void NoMode::Execute()
{
    //    Trace::GetLogger().STAMP(Trace::ERR) << "NoMode::Execute - " << CheckCondition1() << Trace::EndLog();

    if (CheckCondition1())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATP);
    else if (CheckCondition17())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATO);
    else if (CheckCondition2())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMF);
    else if (CheckCondition3())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMR);
    else if (CheckCondition4())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATC_BYPASS);
    else if (CheckCondition20())
        SetCurrentMode(Project::TypeValue::CBTCMode::UTO);
}

/// Initializes a new instance of the ATO Mode class.
///
/// @param mc reference to ModeTransitionModule
ATO::ATO(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void ATO::Execute()
{
    //    Trace::GetLogger().STAMP(Trace::ERR) << "AM::Execute - " << CheckCondition5() << Trace::EndLog();

    if (CheckCondition15())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATP);
    else if (CheckCondition14())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMF);
    else if (CheckCondition13())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMR);
    else if (CheckCondition5())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATC_BYPASS);
    else if (CheckCondition20())
        SetCurrentMode(Project::TypeValue::CBTCMode::UTO);
    else if (CheckCondition21())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATB);
}

/// Initializes a new instance of the ATP Mode class.
///
/// @param mc reference to ModeTransitionModule
ATP::ATP(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void ATP::Execute()
{
    //    Trace::GetLogger().STAMP(Trace::ERR) << "AM::Execute - " << CheckCondition5() << Trace::EndLog();
    if (CheckCondition19())
        SetCurrentMode(Project::TypeValue::CBTCMode::ROS);
    else if (CheckCondition17())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATO);
    else if (CheckCondition14())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMF);
    else if (CheckCondition13())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMR);
    else if (CheckCondition5())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATC_BYPASS);
    else if (CheckCondition20())
        SetCurrentMode(Project::TypeValue::CBTCMode::UTO);
}

/// Initializes a new instance of the RMF Mode class.
///
/// @param mc reference to ModeTransitionModule

RMF::RMF(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void RMF::Execute()
{
    //    Trace::GetLogger().STAMP(Trace::ERR) << "RMF::Execute - " << CheckCondition15() << Trace::EndLog();

    if (CheckCondition17())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATO);
    else if (CheckCondition15())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATP);
    else if (CheckCondition13())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMR);
    else if (CheckCondition5())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATC_BYPASS);
    else if (CheckCondition20())
        SetCurrentMode(Project::TypeValue::CBTCMode::UTO);
}

/// Initializes a new instance of the ROS Mode class.
///
/// @param mc reference to ModeTransitionModule

ROS::ROS(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void ROS::Execute()
{
    if (CheckCondition15())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATP);
}

/// Initializes a new instance of the RMR Mode class.
///
/// @param mc reference to ModeTransitionModule

RMR::RMR(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void RMR::Execute()
{
    if (CheckCondition17())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATO);
    else if (CheckCondition15())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATP);
    else if (CheckCondition14())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMF);
    else if (CheckCondition5())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATC_BYPASS);
    else if (CheckCondition20())
        SetCurrentMode(Project::TypeValue::CBTCMode::UTO);
}
/// Initializes a new instance of the UTO Mode class.
///
/// @param mc reference to ModeTransitionModule

UTO::UTO(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void UTO::Execute()
{
    if (CheckCondition15())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATP); // CM);
    else if (CheckCondition14())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMF);
    else if (CheckCondition13())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMR);
    else if (CheckCondition5())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATC_BYPASS);
    else if (CheckCondition17())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATO);
}
/// Initializes a new instance of the ATB Mode class.
///
/// @param mc reference to ModeTransitionModule

ATB::ATB(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void ATB::Execute()
{
    //    Trace::GetLogger().STAMP(Trace::ERR) << "RMR::Execute - " << CheckCondition5() << Trace::EndLog();

    if (CheckCondition10() || CheckCondition11() || CheckCondition12() || CheckCondition18())
        SetCurrentMode(Project::TypeValue::CBTCMode::NO_MODE);
    else if (CheckCondition15())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATP); // CM);
    else if (CheckCondition14())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMF);
    else if (CheckCondition5())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATC_BYPASS);
}
/// Initializes a new instance of the ATPBypass Mode class.
///
/// @param mc reference to ModeTransitionModule

ATPBypass::ATPBypass(ModeTransitionModule& mc) : IMode(mc) {}

/// Executes this instance to enter into other modes.
/// Checks for the conditions which leads to transition
/// to other modes

void ATPBypass::Execute()
{
    //    Trace::GetLogger().STAMP(Trace::ERR) << "BYPASS::Execute - " << CheckCondition11() << Trace::EndLog();

    if (CheckCondition9() || CheckCondition10() || CheckCondition11())
        SetCurrentMode(Project::TypeValue::CBTCMode::NO_MODE);
    else if (CheckCondition8())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATP);
    else if (CheckCondition17())
        SetCurrentMode(Project::TypeValue::CBTCMode::ATO);
    else if (CheckCondition7())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMF);
    else if (CheckCondition6())
        SetCurrentMode(Project::TypeValue::CBTCMode::RMR);
}
