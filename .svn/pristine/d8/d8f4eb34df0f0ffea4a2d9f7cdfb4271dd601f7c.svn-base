///
/// @file       ModeTransitionModule.h
///
///             Module that handles the functionality related to the Mode transitions of the CBTC OnBoard System.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///             Amol Ganbavale
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#pragma once

#include "CBTCConstants.h"
#include "CBTCModule.h"

#include <map>
#include <memory>
#include <vector>

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Defines the standard structures required of a Module

        struct ModeTransitionIO
        {
            struct Initialisation
            {
            };

            struct Inputs
            {
                //=========================================================================================
                // The following data is populated using Comms Data from the Train Model
                //=========================================================================================

                double current_train_speed        = INVALID_SPEED; // The current train speed
                double selected_driving_mode      = Project::TypeValue::DriverModeSelection::OFF;
                bool   system_startup_complete    = false;
                double power_supply               = Project::TypeValue::PowerSupply::NO_POWER;
                double cab_activate               = Project::TypeValue::CabinActivation::INACTIVE;
                double atc_bypass_switch          = Project::TypeValue::ATCBypassState::NO_BYPASS;
                double tbc_position               = Project::TypeValue::TBCPosition::FULL_SB;
                double ato_driving_state          = Project::TypeValue::ATOState::NOT_IN_AM;
                double radio_communication_status = Project::TypeValue::RadioCommsStatus::COMMS_NOT_ESTABLISHED;
                bool   ros_indicator              = Project::TypeValue::IndicatorState::OFF;
                bool   uto_mode_active            = Project::TypeValue::UTOState::AM_UTO_DISABLED;
                double mode_selector_position     = Project::TypeValue::ModeSelector::OFF_UTO;

                // Folowing needed to determine mode availability
                double localisation_state            = Project::TypeValue::LocalisationStatus::UNAVAILABLE;
                double atc_status                    = Project::TypeValue::ATCStatus::HEALTHY;
                bool   max_reverse_distance_exceeded = false;
                double psd_present                   = Project::TypeValue::PSDPresent::PSD_NOT_PRESENT;
                bool   power_up_test_completed       = Project::CBTCOnBoard::INVALID_TIME;
                double driver_change_ends            = Project::TypeValue::DriverEventStatus::INACTIVE;
            };

            struct Outputs
            {
                CBTC::Protos::AvailableModesList available_driving_modes;

                double cbtc_current_mode    = Project::TypeValue::CBTCMode::NO_MODE;
                double current_driving_mode = Project::TypeValue::CurrentDrivingMode::NO_MODE;
                double atc_bypass_state     = Project::TypeValue::ATCBypassState::NO_BYPASS;
                bool   uto_pb_indicator     = Project::TypeValue::IndicatorState::OFF;
            };

            struct State
            {
                // Holds the current mode
                int cbtc_current_mode = Project::TypeValue::CBTCMode::NO_MODE;
            };
        };

        /// Module that handles the functionality related to the Mode Transition function of the CBTC OnBoard
        /// System.
        ///
        class ModeTransitionModule : public CBTCModule<ModeTransitionModule, ModeTransitionIO>
        {
        public:
            ModeTransitionModule(const Initialisation& init);
            ~ModeTransitionModule();

            void Step(double time_step);

            // Set the current mode
            void SetCurrentMode(int mode);

            // Getter functions
            double GetSelectedDrivingMode();
            double GetCBTCCurrentDrivingModeState();

            // Conditional functions declaration
            bool IsTrainStandstill();
            bool IsCabActive();
            bool IsCBTCPoweredOn();
            bool IsCBTCSystemStartupComplete();
            bool IsATPBypassOn();
            bool IsTBCFullSB();
            bool IsATODrivingEnabled();
            bool IsEoaAvailable();
            bool IsSelectedModeAvailable();
            bool IsROSIndicatorEnabled();
            bool IsUTOEnabled();
            bool IsATBEnabled();

        private:
            void                         DetermineAvailableDrivingModes();
            std::unique_ptr<class IMode> m_imode;
        };
    }
}
