///
/// @file       MotionBaseApplication.h
///
///             Defines the MotionBaseApplication class. The MotionBaseApplication class
///             establishes a connection with the MotionBase through a MotionBaseHardware
///             class. It is responsible for monitoring the Simulation Status and passing
///             any MotionBase related parameters to the Hardware class
///
/// @ingroup    MTM Simulator
///
/// @author     Andy Cooper
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///
#pragma once
#include "utility/SelectiveModule.h"
#include "core_types/SessionData.h"
#include "sim_comms/Object.h"
#include "MotionBaseProperties.h"
#include <atomic>
#include <memory>
#include <mutex>

namespace Common { class Properties; }
namespace Common { class DataAccess; }
class MotionBaseController;

/// The class that manages the MotionBase Hardware and Forwards related Train Numbers to it.
class MotionBaseApplication : public Core::SelectiveModules<Core::BaseScenarioData, Core::BaseSessionData, Core::FixedBehaviour<false, true>>::Hub
{
public:
    MotionBaseApplication(Common::Properties &properties, Common::DataAccess &data_access);
    ~MotionBaseApplication();

    // ScenarioProcessing
    Comms::UnitCreators DefineSession(Comms::Gateway &gateway) override;
    void ResetSession() override;

    // ActiveProcessing
    void StateChanged(Comms::State new_state) override;

    // Custom Listener Function
    void Process(const Comms::NumberStore::ListenerIterator first,
                 const Comms::NumberStore::ListenerIterator last);

private:
    mutable std::mutex m_mutex;

    void SetMotionEnabled(bool enable_motion);

    // Callbacks
    void ObjectCreated(Comms::Object object);
    void ObjectDestroyed(Comms::Object object);

    Common::DataAccess &m_data_access;
    const Project::MotionBaseProperties m_properties;

    std::atomic<bool> m_motion_enabled;
    std::atomic<bool> m_motion_enabled_this_session;

    int  m_simulator_id;
    int  m_scenario_train_id;
    int  m_car_index;
    int  m_hub_id;
    bool m_is_replay;

    // Connection to the MotionBase
    std::unique_ptr<MotionBaseController> m_controller;

    Comms::NumberStore::ListenerID m_listener_id;

    Comms::Object m_seat_object;

    Sim::Number m_linear_velocity_x;
    Sim::Number m_linear_velocity_y;
    Sim::Number m_linear_velocity_z;
    Sim::Number m_linear_acceleration_x;
    Sim::Number m_linear_acceleration_y;
    Sim::Number m_linear_acceleration_z;
    Sim::Number m_manual_position_x;
    Sim::Number m_manual_position_y;
    Sim::Number m_manual_position_z;
    Sim::Number m_angular_velocity_x;
    Sim::Number m_angular_velocity_y;
    Sim::Number m_angular_velocity_z;
    Sim::Number m_angular_acceleration_x;
    Sim::Number m_angular_acceleration_y;
    Sim::Number m_angular_acceleration_z;
    Sim::Number m_manual_orientation_x;
    Sim::Number m_manual_orientation_y;
    Sim::Number m_manual_orientation_z;
    Sim::Number m_gravitational_acceleration_x;
    Sim::Number m_gravitational_acceleration_y;
    Sim::Number m_gravitational_acceleration_z;
    Sim::Number m_rotation_matrix_00;
    Sim::Number m_rotation_matrix_01;
    Sim::Number m_rotation_matrix_02;
    Sim::Number m_rotation_matrix_10;
    Sim::Number m_rotation_matrix_11;
    Sim::Number m_rotation_matrix_12;
    Sim::Number m_rotation_matrix_20;
    Sim::Number m_rotation_matrix_21;
    Sim::Number m_rotation_matrix_22;
    Sim::Number m_apply_motion;
};
