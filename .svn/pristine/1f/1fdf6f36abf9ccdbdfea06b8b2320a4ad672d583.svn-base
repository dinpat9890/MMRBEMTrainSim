///
/// @file       ModeConditions.cpp
///
///             Implements the Conditions which are used to have check for the mode transitions
///             Single mode transition may rely on one or many conditions
///
/// @author     Adam Zielinski
///             Amol Ganbavale
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#include "ModeConditions.h"

#include "common/StandardLogging.h"

using namespace Project::CBTCOnBoard;

/// Constructor, Initializes a new instance of the <see cref="ModeConditions"/> class.
///
/// @param mtm mode transition module reference
ModeConditions::ModeConditions(class ModeTransitionModule& mtm) : m_mtm(mtm) {}

/// Checks the condition1.
///
/// @return true if • Cab Activate
///                 • System Powerup completed
///                 • Selected Driver Mode is ATP
///                 • ATP ByPass is Off
///                 • EOA is available
///                 • Select Driving mode is available
///         otherwise false
bool ModeConditions::CheckCondition1()
{
    if (m_mtm.IsCabActive() && m_mtm.IsCBTCSystemStartupComplete() &&
        (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::ATP) && !m_mtm.IsATPBypassOn() &&
        m_mtm.IsEoaAvailable() && m_mtm.IsSelectedModeAvailable())
        return true;
    return false;
}

/// Checks the condition2.
///
/// @return true if • Cab Activate
///                 • System Powerup completed
///                 • Selected Driver Mode is RMF
///                 • ATP ByPass is Off
///                 • Select Driving mode is available
///         otherwise false
bool ModeConditions::CheckCondition2()
{
    if (m_mtm.IsCabActive() && m_mtm.IsCBTCSystemStartupComplete() && !m_mtm.IsATPBypassOn() &&
        (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::RMF) && m_mtm.IsSelectedModeAvailable())
        return true;
    return false;
}

/// Checks the condition3.
///
/// @return true if • Cab Activate
///                 • System Powerup completed
///                 • Selected Driver Mode is RMR
///                 • ATP ByPass is Off
///                 • Select Driving mode is available
///         otherwise false
bool ModeConditions::CheckCondition3()
{
    if (m_mtm.IsCabActive() && m_mtm.IsCBTCSystemStartupComplete() && !m_mtm.IsATPBypassOn() &&
        (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::RMR) && m_mtm.IsSelectedModeAvailable())
        return true;
    return false;
}

/// Checks the condition4.
///
/// @return true if • Cab Activate
///                 • System Powerup completed
///                 • ATP ByPass is On
///         otherwise false
bool ModeConditions::CheckCondition4()
{
    if (m_mtm.IsCabActive() && m_mtm.IsCBTCSystemStartupComplete() && m_mtm.IsATPBypassOn())
        return true;
    return false;
}

/// Checks the condition6. Not Simulated for Now Probabely simulated later
///
/// @return true if •ATP ByPass is On
///        otherwise false.
bool ModeConditions::CheckCondition5()
{
    if (m_mtm.IsATPBypassOn())
        return true;
    return false;
}

/// Checks the condition6. Not Simulated for Now Probabely simulated later
///
/// @return true if •ATP ByPass is Off
///                 •Selected Driver Mode is RMR
///        otherwise false.
bool ModeConditions::CheckCondition6()
{
    if (!m_mtm.IsATPBypassOn() && (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::RMR))
        return true;
    return false;
}

/// Checks the condition7. Bit different from the design as Trip Acknowledgment would be checked by ModeTransitionModule
///
/// @return true if •ATP ByPass is Off
///                 •Selected Driver Mode is RMF
///        otherwise false.
bool ModeConditions::CheckCondition7()
{
    if (!m_mtm.IsATPBypassOn() && (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::RMF))
        return true;
    return false;
}

/// Checks the condition8.
///
/// @return true if •ATP ByPass is Off
///                 •Selected Driver Mode is ATP
///       otherwise false.
bool ModeConditions::CheckCondition8()
{
    if (!m_mtm.IsATPBypassOn() && (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::ATP))
        return true;
    return false;
}

/// Checks the condition9.
///
/// @return true if •ATP ByPass is Off
///                 •Selected Driver Mode is Off
///       otherwise false.
bool ModeConditions::CheckCondition9()
{
    if (!m_mtm.IsATPBypassOn() && (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::OFF))
        return true;
    return false;
}

/// Checks the condition10.
///
/// @return true if •CBTC is powered Off
///        otherwise false
bool ModeConditions::CheckCondition10()
{
    if (!m_mtm.IsCBTCPoweredOn())
        return true;
    return false;
}

/// Checks the condition11.
/// FS/OS->TR
///
/// @return true if •Cab Deactivated
///        otherwise false
bool ModeConditions::CheckCondition11()
{
    if (!m_mtm.IsCabActive())
        return true;
    return false;
}

/// Checks the condition12.
///
/// @return true if •Selected Driver Mode is Off
///       otherwise false.
bool ModeConditions::CheckCondition12()
{
    if (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::OFF)
        return true;
    return false;
}

/// Checks the condition13.
///
/// @return true if • Selected Driver Mode is RMR
///                 • Select Driving mode is available
///       otherwise false.
bool ModeConditions::CheckCondition13()
{
    if ((m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::RMR) && m_mtm.IsSelectedModeAvailable())
        return true;
    return false;
}

/// Checks the condition14.
///
/// @return true if • Selected Driver Mode is RMF
///                 • Select Driving mode is available
///         otherwise false
bool ModeConditions::CheckCondition14()
{
    if ((m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::RMF) && m_mtm.IsSelectedModeAvailable())
        return true;
    return false;
}

/// Checks the condition15.
///
/// @return true if • Selected Driver Mode is ATP
///                 • Select Driving mode is available
///        otherwise false
bool ModeConditions::CheckCondition15()
{
    if ((m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::ATP) && m_mtm.IsSelectedModeAvailable())
        return true;
    return false;
}

/// Checks the condition16.
///
/// @return true if •TBC not equal to coast
///        otherwise false
bool ModeConditions::CheckCondition16()
{
    if (!m_mtm.IsTBCFullSB())
        return true;
    return false;
}

/// Checks the condition17.
///
/// @return true if •TBC equals FullSB
///                 •ATO Driving enabled
///      otherwise false.
bool ModeConditions::CheckCondition17()
{
    if (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::ATO && m_mtm.IsSelectedModeAvailable())
        return true;
    return false;
}

/// Checks the condition18.
///
/// @return true if • Selected Driver Mode is not available
///        otherwise false
bool ModeConditions::CheckCondition18()
{
    if (!m_mtm.IsSelectedModeAvailable())
        return true;
    return false;
}

/// Checks the condition19.
///
/// @return true if • Selected Driver Mode is not available
///        otherwise false
bool ModeConditions::CheckCondition19()
{
    if (m_mtm.IsSelectedModeAvailable() && m_mtm.IsROSIndicatorEnabled())
        return true;
    return false;
}

/// Checks the condition20.
///
/// @return true if • Selected Driver Mode is not available
///        otherwise false
bool ModeConditions::CheckCondition20()
{
    if (m_mtm.GetSelectedDrivingMode() == Project::TypeValue::DriverModeSelection::UTO && m_mtm.IsUTOEnabled())
        return true;
    return false;
}

/// Checks the condition21.
///
/// @return true if • Selected Driver Mode is not available
///        otherwise false
bool ModeConditions::CheckCondition21()
{
    if (m_mtm.IsSelectedModeAvailable() && m_mtm.IsATBEnabled())
        return true;
    return false;
}
