///
/// @file       IMode.h
///
///             Interface class declaration for the Modes.
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#include "IMode.h"
#include "ModeTransitionModule.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Interface for the modes.
        ///
        IMode::IMode(class ModeTransitionModule& mc) : ModeConditions(mc), m_mc(mc) {}

        void IMode::SetCurrentMode(int mode) { m_mc.SetCurrentMode(mode); }
    }
}