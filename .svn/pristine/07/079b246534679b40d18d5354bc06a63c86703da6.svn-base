///
/// @file       SATrainPathWatcher.h
///
///             Declaration of a watcher of trains with features special to
///             the session analyser
///
/// @ingroup    Integrated Scenarios, AC05-004
///
/// @author     James Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2005
///
#ifndef SESSION_ANALYSER_TRAIN_PATH_WATCHER_H
#define SESSION_ANALYSER_TRAIN_PATH_WATCHER_H

#include "world_api/TrainPathWatcher.h"
#include "sim_comms/Gateway.h"

/// A watcher of trains with features special to the session analyser. This is the ability to
/// track the linear lead loco position, in association with the current time.

class SATrainPathWatcher : public WorldAPI::ScenarioTrainPathWatcher
{
public:
    // Constructor
    SATrainPathWatcher(Comms::Gateway &gateway, WorldAPI::WorldAccess &world_access, WorldAPI::PointsWatcher &points_watcher, double request_frequency, int scenario_train_id);
    ~SATrainPathWatcher();

    // Accessors
    double GetTime() const;
    double GetPosition() const;
    double GetSpeedLimit() const;

    // Callback called when the recorded collective time position changes
    void AddTimePositionCallback(const Callback<void,void> &cb);
    void RemoveTimePositionCallback(const Callback<void,void> &cb);

public:
    // External Trigger
    void NextPeriod();

private:
    mutable std::mutex m_mutex;

    const Comms::Gateway &m_gateway;

    // Configuration
    double m_request_frequency;

    // Internal Callbacks
    void PositionChanged();

    void TrainCreation(Comms::Object object);
    void TrainChildCreation(Comms::Object object);

    // Time, position tracking
    Comms::Object m_vehicle_object;
    Sim::Number   m_position_number;
    double        m_time;

    Comms::Object m_speed_limit_object;
    Sim::Number   m_speed_limit_number;

    std::vector<Callback<void,void> *> m_timeposition_change_cb;

    // Remember the train creation and route change callbacks for removal
    Comms::CallbackID m_satpw_train_creation_cb_id;
    Comms::CallbackID m_satpw_route_change_cb_id;
};

#endif // SESSION_ANALYSER_TRAIN_PATH_WATCHER_H
