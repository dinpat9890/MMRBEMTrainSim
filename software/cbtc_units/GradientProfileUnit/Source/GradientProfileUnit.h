///***************************************************************************************
/// @file         GradientProfileUnit.h
///
/// Description : This unit is responsible for generating the Gradient profile to be
///               provided to the ETCS On Board System
///
/// @author       Abhishek Rastogi
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2018
///***************************************************************************************

#pragma once

#include "sim_comms/Unit.h"
#include "sim_comms/Object.h"
#include "core_types/SessionData.h"
#include "Project/Utilities/ScenarioTrainLengthService.h"
#include "common/Properties.h"
#include "utility/Locking.h"
#include "world_api/WorldAccess.h"
#include "world_api/TrainPathWatcher.h"
#include "world_api/PointsWatcher.h"

#include <list>
#include <memory>
#include <mutex>

///
/// The GradientProfileUnit is responsible for notifying
/// the ETCS Data Reporter unit via ETCSMessageNotifier
/// resource to send message to the ETCS On Board System
///
class GradientProfileUnit : public Comms::SteppingUnit, Core::Locking<std::mutex>
{
public:
    /// Gradient info is pair of the distance, and the value(in ratio) of the gradient
    /// example: A Gradient of 1:500 for the distance of 1543.0 meters => (1543.0, 500)
    typedef std::pair<double/*Distance*/, double/*Gradient*/>   GradientInfo;

    GradientProfileUnit(Comms::Gateway              &gateway,
                        Common::DataAccess          &data_access,
                        WorldAPI::WorldAccess       &world_access,
                        Core::BaseScenarioData      &scenario_data,
                        const Common::Properties    &properties,
                        const int                    scenario_train_id
                        );

    ~GradientProfileUnit();

    std::string GetName() const override;
    void Step(double new_time) override;
    double GetPeriod() const override;

private:
    /// Callback to monitor object creation
    void ObjectCreated(Comms::Object object);

    /// Reports when the unit has all the data it requires
    bool IsRequiredDataAvailable() const;

    // Callback for Train route changed
    void RouteChanged();

    bool IsGradientCalculationRequired() const;
    double CalculateInitialGradient(const WorldAPI::SegmentPath &path);
    void PopulateGradientProfile();
    void UpdateGradientProfile();
    void ReduceNoiseFromGradientProfile();

    double CalculatePerMilleGradientAtPosition(double position);
    bool IsGradientChanged(double last_gradient, double current_gradient) const;
    const std::shared_ptr<WorldAPI::SegmentPathGeometry> GetPathGeometry();

    // Configuration
    double                                          m_step_distance;
    double                                          m_min_gradient_distance;
    double                                          m_min_acceptable_change;

    bool                                            m_path_geometry_calculated;
    bool                                            m_gradients_calculated;
    int                                             m_scenario_train_id;
    int                                             m_driving_vehicle_index;
    double                                          m_last_loco_position;
    double                                          m_current_loco_position;
    double                                          m_train_length;

    Sim::Number::ID                                 m_loco_pos_id;

    Sim::Raw                                        m_gradient_profile_raw;

    Comms::Object                                   m_train_object;
    Comms::Object                                   m_gradient_object;

    ScenarioTrainLengthService                      m_train_length_service;

    std::shared_ptr<WorldAPI::SegmentPathGeometry>  m_geometry;
    std::list<GradientInfo>                         m_track_gradient_info;

    // Resources
    Comms::Gateway                                 &m_gateway;
    WorldAPI::WorldAccess                          &m_world_access;

    // Not using points_watcher_resources because of potential unitialised variable in FeatureWatcher constructor
    WorldAPI::PointsWatcher                         m_points_watcher;

    std::unique_ptr<WorldAPI::TrainPathWatcher>     m_pscenario_train_path_watcher;
};
