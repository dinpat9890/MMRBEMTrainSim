///
/// @file       ModeTransitionMachine.h
///
///             Module that handles the functionality related to the Mode transitions of the CBTC OnBoard System.
///             Declares the Classes which are responsible for transiting to other modes.
///
/// @author     Adam Zielinski
///             Amol Ganbavale
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#pragma once

#include "IMode.h"
#include <mutex>

namespace Project
{
    namespace CBTCOnBoard
    {
        /// NoMode Mode class declaration
        class NoMode : public IMode
        {
        public:
            NoMode(ModeTransitionModule& mc);

            void Execute() override;
        };

        /// ATO Mode class declaration
        class ATO : public IMode
        {
        public:
            ATO(ModeTransitionModule& mc);
            void Execute() override;
        };

        /// ATP Mode class declaration
        class ATP : public IMode
        {
        public:
            ATP(ModeTransitionModule& mc);
            void Execute() override;
        };

        /// RMF Mode class declaration
        class RMF : public IMode
        {
        public:
            RMF(ModeTransitionModule& mc);
            void Execute() override;
        };

        /// RMR Mode class declaration
        class RMR : public IMode
        {
        public:
            RMR(ModeTransitionModule& mc);
            void Execute() override;
        };

        /// ROS Mode class declaration
        class ROS : public IMode
        {
        public:
            ROS(ModeTransitionModule& mc);
            void Execute() override;
        };

        /// UTO Mode class declaration
        class UTO : public IMode
        {
        public:
            UTO(ModeTransitionModule& mc);
            void Execute() override;
        };

        /// ATB Mode class declaration
        class ATB : public IMode
        {
        public:
            ATB(ModeTransitionModule& mc);
            void Execute() override;
        };

        /// ATPBypass Mode class declaration
        class ATPBypass : public IMode
        {
        public:
            ATPBypass(ModeTransitionModule& mc);
            void Execute() override;
        };
    }
}
