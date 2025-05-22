///**************************************************************************************************
/// @file         BeaconUnit.cpp
///
/// Description : Unit for interfacing the beacon features with the CBTC Onboard Inputs
///
/// @author       Adam Zielinski
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************

#include "BeaconUnit.h"

#include "Project/FeatureNames.h"

#include "common/StandardLogging.h"

#include "Project/Utilities/IsLeadVehicle.h"
#include "Utility/Utilities.h"

using namespace Beacon;

namespace
{
    // Constants
    const auto STEP_REQUEST_FREQUENCY   = 20.0;
    const auto STEP_PERIOD              = 1.0 / STEP_REQUEST_FREQUENCY;
    const auto COMMS_REQUEST_FREQUENCY  = 0.0;

    const auto SET_TRIGGER              = 1.0;
    const auto CLEAR_TRIGGER            = 0.0;
    const auto MAX_DETECTION_RANGE      = 10.0;
    const double MOMENTARY_SIGNAL_TIME  = 0.2;

    const auto DEBUG                    = false;
}

/// Constructor
///
/// @param gateway            The comms gateway
/// @param data_access        Object to access the simulator database
/// @param session_data       Data about the active Session
///
///
/// @param properties         Unit configuration data
/// @param scenario_train_id  Identifies the scenario train
///
BeaconUnit::BeaconUnit(Comms::Gateway                  &gateway, 
                       Common::DataAccess              &data_access,
                       WorldAPI::WorldAccess           &world_access,
                       WorldAPI::TrainPathWatcher      &path_watcher,
                       int                              scenario_train_id)
    : Comms::SteppingUnit(gateway),
      m_scenario_train_id(scenario_train_id),
      m_gateway(gateway),
      m_beacon_reader(gateway, data_access, world_access, path_watcher),
      m_clear_faulty_beacon_detection(false)
{
    // We need a lock to access the root object
    OS::Lock<Comms::Gateway> lock(m_gateway);
    AddCreationCallback(m_gateway.GetRootObject(), [this](Comms::Object object) { this->RootChildCreated(object); });
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "BeaconUnit - Started" << Trace::EndLog();
}

/// Destructor
///
BeaconUnit::~BeaconUnit()
{
    OS::Lock<Comms::Gateway> lock(m_gateway);

    // Unmap all of our mapped Comms Objects and cancel the step function
    m_cbtc_onboard_inputs_object.UnMapCBTCOnboardInputsObject();
}

/// Returns a string holding the name of this unit.
///
std::string BeaconUnit::GetName() const
{
    return "Beacon Unit";
}

/// Called to perform the actions that need to be done periodically
///
/// @param current_time Time at which the function was scheduled for execution
///
/// @returns scheduled time at which this function is be next executed
///
void BeaconUnit::Step(double current_time)
{
    // Updating our model. Make sure that we have the lock
    OS::Lock<Comms::Gateway> lock(m_gateway);

    // Make sure that the unit has completed initialisation before continuing
    if (!CommsInitialisationCompleted())
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "BeaconUnit - Unit is Missing all required objects" << Trace::EndLog();
        return;
    }

    // Get the current values of the CBTC Onboard Inputs Comms objects
    m_cbtc_onboard_inputs_object.Get();

    // handle detection and reporting of CBTC beacons
    {
        // Find the trains position and distance travelled since last call to step function
        // Detection range is set to being half the distance that the train travelled between 
        // consecutive calls to this step function
        auto train_position = m_lead_vehicle_object.Numbers().Store().Get(m_position_id).value;
        auto travelled_distance = abs(train_position - m_prev_train_position);
        auto detection_range = ((travelled_distance / 2.0) > MAX_DETECTION_RANGE) ? MAX_DETECTION_RANGE : (travelled_distance / 2.0);

        // If a beacon has been detected by the beacon reader the train needs to report the beacon detection to the CBTC Onbaord system.
        // If the beacon state is faulty, then the Onboard will be notifed about the detection of a faulty beacon
        if (m_beacon_reader.IsBeaconDetected(train_position, detection_range))
        {
            m_cbtc_onboard_inputs_object.m_last_detected_beacon = m_beacon_reader.GetLastDetectedBeaconId();

            // If the beacon was faulty then the faulty beacon Id should be reported to the Onboard
            if (m_beacon_reader.IsLastDetectedBeaconFaulty())
            {
                m_cbtc_onboard_inputs_object.m_last_detected_beacon = Project::TypeValue::BeaconStates::FAULTY;

                m_last_detection_time = current_time;
                m_clear_faulty_beacon_detection = true;

                if (DEBUG)
                    Trace::GetLogger().STAMP(Trace::INFO) << "(" << train_position << "," << detection_range << ")  :: Beacon Detected: " << 
                        m_beacon_reader.GetLastDetectedBeaconLocation() << ", " <<
                        m_beacon_reader.GetLastDetectedBeaconId() << "         -     " << m_clear_faulty_beacon_detection  << Trace::EndLog();
            }
        }
        
        // Need to reset the last detected beacon to unknown after a short period of time so that detection of two
        // consecutively faulty beacons can be reported correctly
        if (m_clear_faulty_beacon_detection && ((current_time - m_last_detection_time) > MOMENTARY_SIGNAL_TIME))
        {
            m_cbtc_onboard_inputs_object.m_last_detected_beacon = Project::TypeValue::BeaconStates::UNKNOWN;
            m_clear_faulty_beacon_detection = false;
        }
        
        // Record data about our current step that is to be used in the next step
        m_prev_train_position = train_position;
    }

    // Send updates if any CBTC Onboard Inputs properties have been updated
    m_cbtc_onboard_inputs_object.Set();
}


/// Gets the period of the step function
///
double BeaconUnit::GetPeriod() const
{
    return STEP_PERIOD;
}


///////////////////////////////////////////////////////////////////////////////////////////
// COMMS Object functions
///////////////////////////////////////////////////////////////////////////////////////////

/// Callback to handle creation of the Root object
///
/// @param object : Root Object
///
void BeaconUnit::RootChildCreated(Comms::Object object)
{
    if(Core::GetClassID(object) == Core::ClassID::WORLD)
        AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
}

/// Callback to handle creation of the COMMS objects
///
/// @param object : Comms Object that triggered the creation callback
///
void BeaconUnit::CommsObjectCreated(Comms::Object object)
{
    int class_id = Core::GetClassID(object);

    if (class_id == Train::ClassID::TRAIN)
    {
        // This is the train we are interested in
        double scenario_train_id = object.Numbers().Get(Project::ValueName::Train::SCENARIO_TRAIN_ID);

        if (scenario_train_id == m_scenario_train_id)
            AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
    }
    else if (class_id ==  Train::ClassID::VEHICLE)
    {
        if (Sim::Project::IsLeadVehicle(object))
        {
            m_lead_vehicle_object = object;
            m_position_id         = object.Numbers().Info().GetID(Train::ValueName::Vehicle::TDO_VEHICLE_POSITION);
            m_prev_train_position = m_lead_vehicle_object.Numbers().Store().Get(m_position_id).value;
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(m_position_id), COMMS_REQUEST_FREQUENCY);

            AddCreationCallback(object, [this](Comms::Object object) { this->CommsObjectCreated(object); });
            AddDestructionCallback(m_gateway.GetRootObject(), [this](Comms::Object object) { this->CommsObjectDestroyed(object); });
        }
    }
    else if (class_id == Project::ClassID::CBTC_ONBOARD_INPUTS)
    {
        m_cbtc_onboard_inputs_object.MapCBTCOnboardInputsObject(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(m_gateway.GetRootObject(), [this](Comms::Object object) { this->CommsObjectDestroyed(object); });
    }
}

/// Handles any invalidations that need to occur when an object is destroyed
///
/// @param object The object that was destroyed
///
void BeaconUnit::CommsObjectDestroyed(Comms::Object object)
{
    if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS)
        m_cbtc_onboard_inputs_object.UnMapCBTCOnboardInputsObject();
    else if (Core::GetClassID(object) == Train::ClassID::VEHICLE)
    {
        if(m_lead_vehicle_object == object)
            m_lead_vehicle_object.Invalidate();
    }
}

/// Return true if Comms initialisation has completed
///
/// @returns true if all required objects have been created
///
bool BeaconUnit::CommsInitialisationCompleted()
{
    return (m_cbtc_onboard_inputs_object.IsValid() &&
        m_lead_vehicle_object.IsValid() && 
        (m_position_id != Sim::INVALID_NUMBER));
}
