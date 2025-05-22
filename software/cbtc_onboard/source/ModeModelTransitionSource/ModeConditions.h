///
/// @file       ModeConditions.h
///
///             Declares the Conditions which are used to have check for the mode transitions
///             Single mode transition may rely on one or many conditions
///
/// @author     Adam Zielinski
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020
///

#pragma once

#include "CBTCConstants.h"
#include "ModeTransitionModule.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        ///
        /// Module that handles the conditional check for Mode Transition
        ///
        class ModeConditions
        {
        public:
            ModeConditions(class ModeTransitionModule& mode_transition_module);

            virtual ~ModeConditions(){};

            // Check Functions for the transition NM modes to CM
            bool CheckCondition1();

            // Check Functions for the transition NM to RMF
            bool CheckCondition2();

            // Check Functions for the transition NM to RMR
            bool CheckCondition3();

            // Check Functions for the transition NM to DS
            bool CheckCondition4();

            // Check Functions for the transition CM/AM/RMF/RMR to DS
            bool CheckCondition5();

            // Check Functions for the transition DS to RMR
            bool CheckCondition6();

            // Check Functions for the transition DS to RMF
            bool CheckCondition7();

            // Check Functions for the transition DS to CM
            bool CheckCondition8();

            // Check Functions for the transition DS to NM
            bool CheckCondition9();

            // Check Functions for the transition CM/AM/RMF/RMR to NM
            bool CheckCondition10();

            // Check Functions for the transition CM/AM/RMF/RMR to NM
            bool CheckCondition11();

            // Check Functions for the transition CM/AM/RMF/RMR to NM
            bool CheckCondition12();

            // Check Functions for the transition CM/AM/RMF to RMR
            bool CheckCondition13();

            // Check Functions for the transition CM/AM/RMR to RMF
            bool CheckCondition14();

            // Check Functions for the transition RMF/RMR to CM
            bool CheckCondition15();

            // Check Functions for the transition AM to CM
            bool CheckCondition16();

            // Check Functions for the transition CM to AM
            bool CheckCondition17();

            // Check Functions for the transition CM, AM, RMF, RMR to NM
            bool CheckCondition18();

            // Check function for the transition ATP to ROS
            bool CheckCondition19();

            // Check function for the transition to UTO
            bool CheckCondition20();

            // Check function for the transition to ATB
            bool CheckCondition21();

        private:
            class ModeTransitionModule& m_mtm;
        };
    }
}
