///
/// @file       BeaconManagementModule.h
///
///             Module that handles the functionality related to the Beacon Management function of the CBTC OnBoard
///             System.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#pragma once

#include "CBTCConstants.h"
#include "CBTCModule.h"

namespace Project
{
    namespace CBTCOnBoard
    {
        /// Defines the standard structures required of a Module
        struct BeaconManagementModuleIO
        {
            struct Initialisation
            {
                double memorised_localisation_validity_distance = INVALID_DISTANCE;
            };

            struct Inputs
            {
                //=========================================================================================
                // The following data is populated using Comms Data from the Train Model
                //=========================================================================================

                double current_train_position = INVALID_DISTANCE;

                /// Identifies the trains localisation state when a scenario is started
                double initial_localisation_state = Project::CBTCOnBoard::TrainTypeValues::MEMORISED_LOCATION;

                // Identifies if cab is active
                double cabin_activation = Project::TypeValue::CabinActivation::INACTIVE;

                //=========================================================================================
                // The following data is populated using Comms Data from the CBTC OnBoard Inputs
                //=========================================================================================

                // Value > 0 indicates last detected beacon feature Id. (<0 indicates a fault, 0 indicates unknown)
                double last_detected_beacon_id = 0;
            };

            struct Outputs
            {
                /// Reports current localisation state
                double current_localisation_state = Project::TypeValue::LocalisationStatus::UNAVAILABLE;
            };

            struct State
            {
                /// Current localisation state
                double current_localisation_state = Project::TypeValue::LocalisationStatus::NOT_LOCALISED;

                // Records the trains position when it was started
                double start_location = 0;

                /// Records the Id of the last beacon that was detected
                double last_detected_beacon_id = Project::TypeValue::BeaconStates::UNKNOWN;

                /// Initial localisation beacon detection
                double initial_localise_beacon_detected = false; // Implicit casting boolean to double for comms
                                                                 // compatibility
            };
        };

        /// This module handles the all of the functionality associated with radio communications.
        ///
        class BeaconManagementModule : public CBTCModule<BeaconManagementModule, BeaconManagementModuleIO>
        {
        public:
            BeaconManagementModule(const Initialisation& init);

            void Step(double time_step);

        private:
            void UpdateLocalisationState();
        };
    }
}
