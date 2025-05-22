///
/// @file       BeaconManagementModule.cpp
///
///             Implements the BeaconManagementModule class.
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#include "BeaconManagementModule.h"

#include "common/StandardLogging.h"

using namespace Project::CBTCOnBoard;

/// Constructor, which just initializes the members appropriately
///
/// @param init Initialisation data for the module
///
BeaconManagementModule::BeaconManagementModule(const Initialisation& init)
  : CBTCModule<BeaconManagementModule, BeaconManagementModuleIO>(init)
{
    // Initialise state data, if required
}

/// The Module function which, given the current inputs, adjusts the internal state and
/// populates the outputs.
///
/// @param time_step The amount of time to since the module was last run
///
void BeaconManagementModule::Step(double time_step)
{
    // Perform actions associated with determining the trains current localisation state
    UpdateLocalisationState();

    // Set the outputs associated with train localisation
    Y().current_localisation_state = X().current_localisation_state;
}

/// Update Onboard localisation state based on the state of the newly detected beacon
///
/// When a beacon is correctly detected the beacon Id will have a positive value that can be
/// used to identify the detected beacon.
///
/// Train losses localisation if it travels to far with a memorised location
///
/// In the case of detecting a faulty beacon, the module expects a Id that represents a faulty
/// beacon detection to be the reported beacon Id.
///
/// Note that in order to be able to have multiple faulty beacon detections the last beacon
/// detection will be reported as Unknown shortly after the faulty detection is reported
/// An Unknown beacon detection will also be reported when the first beacon has not yet been detected
///
void BeaconManagementModule::UpdateLocalisationState()
{
    // On cab deactivation, reset the localisation state to be the one that was provided
    // as the trains initial localisation state
    //
    // TBD - May want to limit this to the start of a scenario
    if (U().cabin_activation == Project::TypeValue::CabinActivation::INACTIVE)
    {
        if (U().initial_localisation_state == Project::CBTCOnBoard::TrainTypeValues::MEMORISED_LOCATION)
            X().current_localisation_state = Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION;
        else if (U().initial_localisation_state == Project::CBTCOnBoard::TrainTypeValues::LOCALISED)
            X().current_localisation_state = Project::TypeValue::LocalisationStatus::LOCALISED;
        else if (U().initial_localisation_state == Project::CBTCOnBoard::TrainTypeValues::DELOCALISED)
        {
            X().current_localisation_state       = Project::TypeValue::LocalisationStatus::NOT_LOCALISED;
            X().initial_localise_beacon_detected = false;
        }

        X().start_location = U().current_train_position;
    }

    // If a new beacon is detected
    if (X().last_detected_beacon_id != U().last_detected_beacon_id)
    {
        // Update the localisation state based on the Id of the last detected beacon
        if (U().last_detected_beacon_id > Project::TypeValue::BeaconStates::UNKNOWN)
        {
            // Need to detect 2 beacons in order for train to becom localised
            if (X().initial_localise_beacon_detected)
            {
                X().current_localisation_state = Project::TypeValue::LocalisationStatus::LOCALISED;
            }

            X().initial_localise_beacon_detected = true;
        }
        else if (U().last_detected_beacon_id == Project::TypeValue::BeaconStates::FAULTY)
        {
            X().current_localisation_state       = Project::TypeValue::LocalisationStatus::NOT_LOCALISED;
            X().initial_localise_beacon_detected = false;
        }

        X().last_detected_beacon_id = U().last_detected_beacon_id;
    }

    // Memorised localisation is lost if the train travels by more than the allowed distance without detecting
    // a beacon
    if (X().current_localisation_state == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION)
    {
        if ((U().current_train_position - X().start_location) > K().memorised_localisation_validity_distance &&
            static_cast<bool>(X().initial_localise_beacon_detected) == false)
        {
            X().current_localisation_state = Project::TypeValue::LocalisationStatus::NOT_LOCALISED;
        }
        else if (static_cast<bool>(X().initial_localise_beacon_detected) == true)
        {
            X().current_localisation_state = Project::TypeValue::LocalisationStatus::LOCALISED;
        }
    }
}
