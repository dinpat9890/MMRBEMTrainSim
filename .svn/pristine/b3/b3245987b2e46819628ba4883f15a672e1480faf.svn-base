///
/// @file       MotionBaseApplication.cpp
///
///             Implements the MotionBaseApplication class.
///
/// @ingroup    MTM Train Sim
///
/// @author     Andy Cooper
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///

#include "MotionBaseApplication.h"
#include "MotionBaseControllerFactory.h"
#include "MotionBaseParameters.h"

#include "sim_comms/Object.h"
#include "sim_comms/SystemList.h"
#include "core_data_access/CoreDataAccessNetwork.h"
#include "train_data_access/TrainDataAccess.h"
#include "common/Callback.h"
#include "common/StandardLogging.h"
#include "utility/Utilities.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include <string>
#include <cassert>
#include <algorithm>
#include <thread>
#include <cstdint>

namespace
{
    /// @throws
    Sim::Number FindAndRequest(Comms::Object object, const std::string &number_name, const double request_frequency)
    {
        assert(object.IsValid());

        auto object_number = object.Numbers().Get(number_name);

        object.Numbers().Store().Request(object.Numbers().Info().GetInfo(object_number.id), request_frequency);

        return object_number;
    }

    // The ID of the transmission received by this module which
    // specifies the state of the motion base.
    const uint16_t set_motion_base_state_transmission_id = 1444;

    // The ID of the transmission sent by this module to prompt
    // other modules for the state of the motion base.
    const uint16_t request_state_update_transmission_id = 4441;
}

/// The constructor operates in Hub mode - The MotionBase hardware is associated with a particular Hubs
/// train.

MotionBaseApplication::MotionBaseApplication(Common::Properties &properties, Common::DataAccess &data_access)
  : Core::SelectiveModules<Core::BaseScenarioData, Core::BaseSessionData, Core::FixedBehaviour<false, true>>::Hub(properties, data_access),
    m_data_access(data_access),
    m_properties(properties),
    m_motion_enabled(true),
    m_motion_enabled_this_session(true)
{
    Core::Database::RegisterCoreNetworkAspects(data_access);
    Train::Database::RegisterTrainAspects(data_access);

    // Set some member variables
    m_is_replay    = false;
    m_simulator_id = GetSimulatorID();
    m_hub_id       = GetHubID();
    m_car_index    = -1;
    m_scenario_train_id = -1;

    // Create the MotionBase Controller layer and Connect
    // As we will be sending datagrams, not USB Serial we dont have to worry about
    // connection status anymore. There is no way of telling if the target computer
    // is up or not.
    auto controllerFactory = MotionBaseControllerFactory(m_properties);

    m_controller = controllerFactory.create_controller();

    for (auto& system : GetSystemList())
    {
        // Add a transmission callback to handle any external requests to disable
        // the motion controller.
        system.AddTransmissionCallback(
            [this](Comms::ModuleID module_id, const Comms::Transmission& transmission)
            {
                if (transmission.type == set_motion_base_state_transmission_id)
                {
                    // Any non-empty text in this transmission is considered as
                    // a request to disable motion.
                    const auto disable_motion = !transmission.text.empty();
                    SetMotionEnabled(!disable_motion);
                    
                    Trace::GetLogger().STAMP(Trace::VERBOSE)
                        << "Received transmission to "
                        << (disable_motion ? "disable" : "enable")
                        << " motion." << Trace::EndLog();
                }
            });

        // Prompt other modules in this system to let us know what the state
        // should be. This basically handles the initial state.
        system.Transmit(Comms::Transmission(request_state_update_transmission_id));

        // Also prompt whenever the system status changes, which might cause a
        // bit of transmission spam, but seems more reliable than simply
        // sending the request once.
        system.AddStatusCallback(
            [](Comms::System& system)
            {
                system.Transmit(Comms::Transmission(request_state_update_transmission_id));
            });
    }
}

/// The destructor. Shutdown the controller

MotionBaseApplication::~MotionBaseApplication()
{
}

/// Initiates processing and registers creation callback on root object
///
/// @param data        session data
/// @param replay      whether the session is in simulation or replay

Comms::UnitCreators MotionBaseApplication::DefineSession(Comms::Gateway &gateway)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "MotionBaseApplication::Define" << Trace::EndLog();
    m_is_replay = gateway.IsReplay();

    const auto session_data = gateway.GetSessionData<Core::BaseSessionData>();
    if(!session_data.data.preview)
    {
        try
        {
            const auto scenario_data = gateway.GetScenarioData<Core::BaseScenarioData>();

            const auto hub = std::find_if(scenario_data.data.hub_data.cbegin(),
                                          scenario_data.data.hub_data.cend(),
                                          [this](const Core::BaseScenarioData::HubData &hub_data) { return hub_data.hub_id == m_hub_id; });
            if(hub != scenario_data.data.hub_data.cend())
            {
                if(Train::Database::Train(m_data_access).HasScenarioTrain(scenario_data.data.scenario_id, hub->scenario_train_id))
                {
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Found train for scenario with ID = " << hub->scenario_train_id << Trace::EndLog();
                    m_scenario_train_id = hub->scenario_train_id;
                    m_car_index         = hub->vehicle_index;

                    // Add Creation Callbacks
                    {
                        Trace::GetLogger().STAMP(Trace::VERBOSE) << "MotionBaseApplication::Define - Add Creation Callback" << Trace::EndLog();
                        const std::lock_guard<Comms::Gateway> comms_lock(GetGateway());
                        Comms::AddCreationCallback(GetGateway().GetRootObject(), MakeCallback(&MotionBaseApplication::ObjectCreated, this));
                    }
                }
            }

        }
        catch(CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "During Define");
            Trace::GetLogger().LogException(e);
        }
    }

    m_motion_enabled_this_session.store(m_motion_enabled);

    Trace::GetLogger().STAMP(Trace::INFO)
        << "Motion has been "
        << (m_motion_enabled_this_session ? "enabled" : "disabled")
        << " for this session." << Trace::EndLog();

    return Comms::UnitCreators();
}

/// Stops processing, clears objects to watch and removes root creation callback.
void MotionBaseApplication::ResetSession()
{
    // Reset to the default configuration.
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "MotionBaseApplication::Terminate" << Trace::EndLog();
}

/// Handles change in session state. If transitioning to SESSION_RUNNING a flag is set to issue
/// all MotionBase Events. Parameters newstate - new session state
void MotionBaseApplication::StateChanged(Comms::State new_state)
{
    // If the m_controller is not setup just return.

    if (m_controller.get() == nullptr)
    {
        Trace::GetLogger().STAMP(Trace::WARN)
            << "MotionBaseApplication: controller not created before state changed to " << Comms::Format(new_state)
            << ", controller might not get the correct state" << Trace::EndLog();
        return;
    }

    // Write new state to logger if state has changed to Running, Paused or
    // Stopped.
    switch (new_state)
    {
    case Comms::State::RUNNING:
        m_controller->set_session_state(MotionBase::SessionState::Running);
        break;

    case Comms::State::PAUSED:
        m_controller->set_session_state(MotionBase::SessionState::Paused);
        break;

        // All The Non Running/Paused states map to default

    case Comms::State::LOADED:
        m_controller->start(m_properties);
        m_controller->set_session_state(MotionBase::SessionState::Default);
        break;

    case Comms::State::IDLE:
    case Comms::State::PROCESSING:
    case Comms::State::LOADING:
    case Comms::State::SEEKING:
    case Comms::State::SHUTTLE:
    case Comms::State::UNLOADING:
    case Comms::State::INITIALISING:
    case Comms::State::RESETTING:
        m_controller->set_session_state(MotionBase::SessionState::Default);
        break;

    case Comms::State::UNKNOWN:
        m_controller->set_session_state(MotionBase::SessionState::Unknown);
        break;
    }
}

/// Object Destruction Callback function.
///
/// @param object The object being created
void MotionBaseApplication::ObjectDestroyed(Comms::Object object)
{
    const std::lock_guard<std::mutex> data_lock(m_mutex);

    assert(object.GetID() == m_seat_object.GetID());

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "MotionBaseApplication::ObjectDestroyed = Motion Base" << Trace::EndLog();
    // The TrainModel has died

    m_seat_object.Numbers().Store().RemoveListener(m_listener_id);

    // Return the seat to the upright position if we lose our Train
    if (m_controller != nullptr)
        m_controller->set_session_state(MotionBase::SessionState::Unknown);

    m_seat_object.Invalidate();
}

void MotionBaseApplication::SetMotionEnabled(const bool enable_motion)
{
    // Handle disabling motion as quickly as possible.
    if (!enable_motion)
    {
        // Set this first, so that any concurrent calls to Process()
        // will know that motion is disabled.
        const auto previously_enabled = m_motion_enabled_this_session.exchange(false);

        // Now notify the motion controller. I don't think I need
        // to use the data_lock here, as m_controller only gets
        // assigned in the ctor, and I believe its methods are
        // threadsafe.
        if (m_controller != nullptr)
        {
            m_controller->set_apply_motion(false);
        }

        if (previously_enabled)
        {
            Trace::GetLogger().STAMP(Trace::INFO)
                << "Motion has been disabled for the remainder of this session."
                << Trace::EndLog();
        }
    }

    m_motion_enabled = enable_motion;
}

/// Object Created Callback function.
///
/// @param object The object being created
void MotionBaseApplication::ObjectCreated(Comms::Object object)
{
    const auto class_id = Core::GetClassID(object);

    if(class_id == Core::ClassID::WORLD)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "MotionBaseApplication::ObjectCreated = World" << Trace::EndLog();
        Comms::AddCreationCallback(object, MakeCallback(&MotionBaseApplication::ObjectCreated, this));
    }
    else if(class_id == Train::ClassID::TRAIN)
    {
        if(static_cast<int>(object.Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value) == m_scenario_train_id)
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "MotionBaseApplication::ObjectCreated = Our Scenario Train" << Trace::EndLog();
            Comms::AddCreationCallback(object, MakeCallback(&MotionBaseApplication::ObjectCreated, this));
        }
    }
    else if(class_id == Train::ClassID::VEHICLE)
    {
        // If this matches the vehicle index for the Hub, register for child creations
        const auto index = static_cast<int>(object.Numbers().Get(Project::ValueName::Vehicle::INDEX));
        if (index == m_car_index)
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "MotionBaseApplication::ObjectCreated = Our Vehicle. Index = " << index << Trace::EndLog();
            Comms::AddCreationCallback(object, MakeCallback(&MotionBaseApplication::ObjectCreated, this));
        }
    }
    else if(class_id == Project::ClassID::MOTION_BASE)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "MotionBaseApplication::ObjectCreated = MotionBase" << Trace::EndLog();

        try
        {
            const auto request_frequency = m_properties.GetRequestFrequency();

            // The following calls might throw if the properties don't exist,
            // so we'll assign them to local variables first. This way our
            // member variables won't end up semi-populated if an exception
            // is thrown.
            const auto apply_motion                 = ::FindAndRequest(object, Project::ValueName::MotionBase::APPLY_MOTION, request_frequency);
            const auto linear_velocity_x            = ::FindAndRequest(object, Project::ValueName::MotionBase::LINEAR_VELOCITY_X, request_frequency);
            const auto linear_velocity_y            = ::FindAndRequest(object, Project::ValueName::MotionBase::LINEAR_VELOCITY_Y, request_frequency);
            const auto linear_velocity_z            = ::FindAndRequest(object, Project::ValueName::MotionBase::LINEAR_VELOCITY_Z, request_frequency);
            const auto linear_acceleration_x        = ::FindAndRequest(object, Project::ValueName::MotionBase::LINEAR_ACCELERATION_X, request_frequency);
            const auto linear_acceleration_y        = ::FindAndRequest(object, Project::ValueName::MotionBase::LINEAR_ACCELERATION_Y, request_frequency);
            const auto linear_acceleration_z        = ::FindAndRequest(object, Project::ValueName::MotionBase::LINEAR_ACCELERATION_Z, request_frequency);
            const auto manual_position_x            = ::FindAndRequest(object, Project::ValueName::MotionBase::MANUAL_POSITION_X, request_frequency);
            const auto manual_position_y            = ::FindAndRequest(object, Project::ValueName::MotionBase::MANUAL_POSITION_Y, request_frequency);
            const auto manual_position_z            = ::FindAndRequest(object, Project::ValueName::MotionBase::MANUAL_POSITION_Z, request_frequency);
            const auto angular_velocity_x           = ::FindAndRequest(object, Project::ValueName::MotionBase::ANGULAR_VELOCITY_X, request_frequency);
            const auto angular_velocity_y           = ::FindAndRequest(object, Project::ValueName::MotionBase::ANGULAR_VELOCITY_Y, request_frequency);
            const auto angular_velocity_z           = ::FindAndRequest(object, Project::ValueName::MotionBase::ANGULAR_VELOCITY_Z, request_frequency);
            const auto angular_acceleration_x       = ::FindAndRequest(object, Project::ValueName::MotionBase::ANGULAR_ACCELERATION_X, request_frequency);
            const auto angular_acceleration_y       = ::FindAndRequest(object, Project::ValueName::MotionBase::ANGULAR_ACCELERATION_Y, request_frequency);
            const auto angular_acceleration_z       = ::FindAndRequest(object, Project::ValueName::MotionBase::ANGULAR_ACCELERATION_Z, request_frequency);
            const auto manual_orientation_x         = ::FindAndRequest(object, Project::ValueName::MotionBase::MANUAL_ORIENTATION_X, request_frequency);
            const auto manual_orientation_y         = ::FindAndRequest(object, Project::ValueName::MotionBase::MANUAL_ORIENTATION_Y, request_frequency);
            const auto manual_orientation_z         = ::FindAndRequest(object, Project::ValueName::MotionBase::MANUAL_ORIENTATION_Z, request_frequency);
            const auto gravitational_acceleration_x = ::FindAndRequest(object, Project::ValueName::MotionBase::GRAVITATIONAL_ACCELERATION_X, request_frequency);
            const auto gravitational_acceleration_y = ::FindAndRequest(object, Project::ValueName::MotionBase::GRAVITATIONAL_ACCELERATION_Y, request_frequency);
            const auto gravitational_acceleration_z = ::FindAndRequest(object, Project::ValueName::MotionBase::GRAVITATIONAL_ACCELERATION_Z, request_frequency);
            const auto rotation_matrix_00           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM00, request_frequency);
            const auto rotation_matrix_01           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM01, request_frequency);
            const auto rotation_matrix_02           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM02, request_frequency);
            const auto rotation_matrix_10           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM10, request_frequency);
            const auto rotation_matrix_11           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM11, request_frequency);
            const auto rotation_matrix_12           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM12, request_frequency);
            const auto rotation_matrix_20           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM20, request_frequency);
            const auto rotation_matrix_21           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM21, request_frequency);
            const auto rotation_matrix_22           = ::FindAndRequest(object, Project::ValueName::MotionBase::RM22, request_frequency);

            // Theoretically we should only ever find a single motion base
            // object, but we'll play it very safe and lock anyway. This
            // guarantees some level of protection in case something
            // unexpected happens in the Comms data hierarchy.
            const std::lock_guard<std::mutex> data_lock(m_mutex);

            m_seat_object = object;

            m_apply_motion                 = apply_motion;
            m_linear_velocity_x            = linear_velocity_x;
            m_linear_velocity_y            = linear_velocity_y;
            m_linear_velocity_z            = linear_velocity_z;
            m_linear_acceleration_x        = linear_acceleration_x;
            m_linear_acceleration_y        = linear_acceleration_y;
            m_linear_acceleration_z        = linear_acceleration_z;
            m_manual_position_x            = manual_position_x;
            m_manual_position_y            = manual_position_y;
            m_manual_position_z            = manual_position_z;
            m_angular_velocity_x           = angular_velocity_x;
            m_angular_velocity_y           = angular_velocity_y;
            m_angular_velocity_z           = angular_velocity_z;
            m_angular_acceleration_x       = angular_acceleration_x;
            m_angular_acceleration_y       = angular_acceleration_y;
            m_angular_acceleration_z       = angular_acceleration_z;
            m_manual_orientation_x         = manual_orientation_x;
            m_manual_orientation_y         = manual_orientation_y;
            m_manual_orientation_z         = manual_orientation_z;
            m_gravitational_acceleration_x = gravitational_acceleration_x;
            m_gravitational_acceleration_y = gravitational_acceleration_y;
            m_gravitational_acceleration_z = gravitational_acceleration_z;
            m_rotation_matrix_00           = rotation_matrix_00;
            m_rotation_matrix_01           = rotation_matrix_01;
            m_rotation_matrix_02           = rotation_matrix_02;
            m_rotation_matrix_10           = rotation_matrix_10;
            m_rotation_matrix_11           = rotation_matrix_11;
            m_rotation_matrix_12           = rotation_matrix_12;
            m_rotation_matrix_20           = rotation_matrix_20;
            m_rotation_matrix_21           = rotation_matrix_21;
            m_rotation_matrix_22           = rotation_matrix_22;

            // Atomic Listener (Allows Processing of Numbers that change atomically)
            // See the Process() function in this class which turns it into a listener.
            m_listener_id = m_seat_object.Numbers().Store().AddListener([this](Comms::NumberStore::ListenerIterator first, Comms::NumberStore::ListenerIterator last) { Process(first, last); });

            Comms::AddDestructionCallback(m_seat_object, MakeCallback(&MotionBaseApplication::ObjectDestroyed, this));
        }
        catch(CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "Setting Up Motion Base Listeners");
            Trace::GetLogger().LogException(e);
        }
    }
}

/// Customised Listener for atomic updates
/// Comms lock is applied so be brief.
void MotionBaseApplication::Process(const Comms::NumberStore::ListenerIterator , const Comms::NumberStore::ListenerIterator)
{
    // We don't use m_mutex here because these number change callbacks are
    // never called at the same time as object creation/destruction (which is
    // the other spot in which we mess with our member variables).
    assert(m_seat_object.IsValid());

    // Ignore the changes and simply grab the entire state of the motion base.
    m_seat_object.Numbers().Store().Get(m_apply_motion);
    m_seat_object.Numbers().Store().Get(m_linear_velocity_x);
    m_seat_object.Numbers().Store().Get(m_linear_velocity_y);
    m_seat_object.Numbers().Store().Get(m_linear_velocity_z);
    m_seat_object.Numbers().Store().Get(m_linear_acceleration_x);
    m_seat_object.Numbers().Store().Get(m_linear_acceleration_y);
    m_seat_object.Numbers().Store().Get(m_linear_acceleration_z);
    m_seat_object.Numbers().Store().Get(m_manual_position_x);
    m_seat_object.Numbers().Store().Get(m_manual_position_y);
    m_seat_object.Numbers().Store().Get(m_manual_position_z);
    m_seat_object.Numbers().Store().Get(m_angular_velocity_x);
    m_seat_object.Numbers().Store().Get(m_angular_velocity_y);
    m_seat_object.Numbers().Store().Get(m_angular_velocity_z);
    m_seat_object.Numbers().Store().Get(m_angular_acceleration_x);
    m_seat_object.Numbers().Store().Get(m_angular_acceleration_y);
    m_seat_object.Numbers().Store().Get(m_angular_acceleration_z);
    m_seat_object.Numbers().Store().Get(m_manual_orientation_x);
    m_seat_object.Numbers().Store().Get(m_manual_orientation_y);
    m_seat_object.Numbers().Store().Get(m_manual_orientation_z);
    m_seat_object.Numbers().Store().Get(m_gravitational_acceleration_x);
    m_seat_object.Numbers().Store().Get(m_gravitational_acceleration_y);
    m_seat_object.Numbers().Store().Get(m_gravitational_acceleration_z);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_00);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_01);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_02);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_10);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_11);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_12);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_20);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_21);
    m_seat_object.Numbers().Store().Get(m_rotation_matrix_22);

    if (m_controller != nullptr)
    {
        m_controller->set_apply_motion(m_motion_enabled_this_session && m_apply_motion.value > 0.5);

        const glm::dvec3 vehicle_velocity(m_linear_velocity_x.value, m_linear_velocity_y.value, m_linear_velocity_z.value);
        const glm::dvec3 vehicle_acceleration(m_linear_acceleration_x.value, m_linear_acceleration_y.value, m_linear_acceleration_z.value);
        const glm::dvec3 vehicle_angular_velocity(m_angular_velocity_x.value, m_angular_velocity_y.value, m_angular_velocity_z.value);
        const glm::dvec3 vehicle_angular_acceleration(m_angular_acceleration_x.value, m_angular_acceleration_y.value, m_angular_acceleration_z.value);
        const glm::dvec3 simulator_platform_manual_position(m_manual_position_x.value, m_manual_position_y.value, m_manual_position_z.value);
        const glm::dvec3 vehicle_gravity_acceleration_projection(m_gravitational_acceleration_x.value, m_gravitational_acceleration_y.value, m_gravitational_acceleration_z.value);
        const glm::dvec3 simulator_platform_manual_orientation(m_manual_orientation_x.value, m_manual_orientation_y.value, m_manual_orientation_z.value);

        // Create matrix and set the values
        glm::dmat3 rotation_matrix;
        rotation_matrix[0][0] = m_rotation_matrix_00.value; rotation_matrix[1][0] = m_rotation_matrix_01.value; rotation_matrix[2][0] = m_rotation_matrix_02.value;   // First Row
        rotation_matrix[0][1] = m_rotation_matrix_10.value; rotation_matrix[1][1] = m_rotation_matrix_11.value; rotation_matrix[2][1] = m_rotation_matrix_12.value;   // Second Row
        rotation_matrix[0][2] = m_rotation_matrix_20.value; rotation_matrix[1][2] = m_rotation_matrix_21.value; rotation_matrix[2][2] = m_rotation_matrix_22.value;   // Third Row

        // FIXME: Need to transform values to motion base coordinates
        auto motion_parameters = MotionBase::Parameters(vehicle_velocity,
                                                        vehicle_acceleration,
                                                        rotation_matrix,
                                                        vehicle_angular_velocity,
                                                        vehicle_angular_acceleration,
                                                        simulator_platform_manual_position,
                                                        simulator_platform_manual_orientation,
                                                        vehicle_gravity_acceleration_projection);
        m_controller->set_motion_parameters(motion_parameters);
    }
}
