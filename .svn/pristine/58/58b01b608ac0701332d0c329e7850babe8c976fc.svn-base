///
/// @file       IMode.h
///
///             Interface class declaration for the Modes.
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#pragma once

#include "CBTCModule.h"
#include "ModeConditions.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Module that handles the functionality related to the Speed and Monitoring function of the CBTC OnBoard
        /// System.
        ///
        class IMode : public ModeConditions
        {
        public:
            IMode(class ModeTransitionModule& mc);
            ~IMode(){};
            virtual void Execute() = 0;

            void SetCurrentMode(int mode);

        private:
            class ModeTransitionModule& m_mc;
        };
    }
}
