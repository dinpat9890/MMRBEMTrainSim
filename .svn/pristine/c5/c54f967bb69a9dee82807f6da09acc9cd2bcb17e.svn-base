///**************************************************************************************************
/// @file         LMAUnit.h
///
/// Description : Unit for determining the Forward, reverse and POS Movement Authority distances
///               within a CBTC region
///
/// @author       Adam Zielinski
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2016
///**************************************************************************************************

#pragma once

#include "sim_comms/Unit.h"
#include "world_api/TrainPathWatcher.h"
#include "world_api/AllTrainWatcher.h"

#include "core_types/SessionData.h"
#include "core_properties/CommonProperties.h"

#include "common/Properties.h"

#include "Project/Utilities/ScenarioTrainLengthService.h"

#include "MappedCBTCOnboardInputs.h"
#include "MappedCBTCOnboardOutputs.h"
#include "LMAProperties.h"
#include "LMAFeatures.h"
#include "feature_interfaces/FeatureRegion.h"
#include "feature_interfaces/StoppingPointFeature.h"
#include "Protobuf/CBTCOnboard.pb.h"


/// This unit uses features on the track to detrmine the trains ETCS MA
///
class LMAUnit : public Comms::SteppingUnit
{
public:
    LMAUnit(Comms::Gateway              &gateway,
            Common::Data::DataAccess    &data_access,
            WorldAPI::WorldAccess       &world_access,
            const LMAProperties         &properties,
            const int                   scenario_train_id);

    ~LMAUnit();

    std::string GetName() const override;

    void Step(double new_time) override;
    double GetPeriod() const override;

private:

    // Comms Object Callbacks
    void RootChildCreated(Comms::Object object);
    void ObjectCreated(Comms::Object object);
    void ObjectDestroyed(Comms::Object object);

private:
    /// Structure representing the data associated with an LMA obstacle
    class LMAObstacleData
    {
    public:
        double   m_osp;
        double   m_pop;
        int      m_obstacle_type;

        // Constructors
        LMAObstacleData();
        LMAObstacleData(int obstacle_type);
        LMAObstacleData(int obstacle_type, double osp, double pop);
        LMAObstacleData(LMA::LMAFeatures::LMAFeatureOnPath lma_feature, int obstacle_type);
    };
    typedef std::pair<double, LMAObstacleData> LMAObstacle;
    typedef std::map<double, LMAObstacleData> LMAObstacles;

private:
    /// Class that determines and reports the LMA information associate with a single train
    class TrainLMAInfo
    {
    public:
        TrainLMAInfo(Comms::Gateway             &gateway,
                     Common::Data::DataAccess  &data_access,
                     WorldAPI::WorldAccess      &world_access,
                     WorldAPI::PointsWatcher    &points_watcher,
                     LMAUnit                    &lma_unit,
                     Comms::Object               train,
                     double                      train_length,
                     bool                        is_simulated_train);
        ~TrainLMAInfo();

        // This is the function that, called cyclically, will update the LMA information
        // in Comms. It is easiest to place it here, with all of the variables that it will use.
        void Update(double sim_time);

        // Maps the Inputs to the CBTCOnboardInputs object
        void MapCBTCOnboardInputObject(Comms::Object cbtc_onboard_inputs_object, double request_frequency);
        void UnMapCBTCOnboardInputObject();
        void MapCBTCOnboardOutputObject(Comms::Object cbtc_onboard_outputs_object, double request_frequency);
        void UnMapCBTCOnboardOutputObject();

        bool IsSimulatedTrain() { return m_is_simulated_train; };

    private:

        bool CommsInitialisationCompleted();

        // Functions for finding and adding obstacles into the map of LMA obstacles
        void SetClosestTrainLMAObstacle(LMAObstacles &m_lma_obstacles);
        void SetLMAFeatureObstacles(LMAUnit::LMAObstacles                          &lma_obstacles,
                                    const LMA::LMAFeatures                         &lma_features,
                                    const double                                   &stopping_point_distance,
                                    FeatureInterfaces::StoppingPoint::FeatureData  &next_stopping_point_feature);
        void SetEndOfTrackObstacles(LMAUnit::LMAObstacles      &lma_obstacles);

        Comms::Object GetClosestVehicle(const WorldAPI::SegmentPath &path, Comms::Object ignore_train) const;
        std::pair<double, bool> GetNearestTrainInfo();

        // Helper Functions
        void InsertLMAObstacle(LMAUnit::LMAObstacles &lma_obstacles, LMA::LMAFeatures::LMAFeatureOnPath &lma_feature, int obstacle_type);
        void InsertLMAObstacle(LMAUnit::LMAObstacles &lma_obstacles, double offset, int obstacle_type);
        void GetClosestObstacle(LMAUnit::LMAObstacles &lma_obstacles,
            double &osp, double &pop, int &obstacle_type,
            const double pos_uncertainty = 0.0);

    private:
        // Comms data
        Comms::Gateway                             &m_gateway;
        Comms::Object                               m_train_object;
        MappedCBTCOnboardInputs                     m_mapped_cbtc_onboard_inputs;
        MappedCBTCOnboardOutputs                    m_mapped_cbtc_onboard_outputs;

        // Config data
        int                                         m_scenario_train_id;
        bool                                        m_is_simulated_train;
        double                                      m_train_length;

        // Data for determining the LMA obstacles on the train path
        std::unique_ptr<WorldAPI::TrainPathWatcher> m_path_watcher;
        LMA::LMAFeatures                            m_lma_features;
        FeatureInterfaces::StoppingPoint            m_stopping_point;
        FeatureInterfaces::FeatureRegion            m_feature_region;

        LMAObstacles                                m_lma_obstacles;
        LMA::LMAFeatures::LMAFeatureData            m_next_eoa_obstacle;

        // Current Location of train
        Sim::Number::ID m_lead_loco_position_id;

        // Point back to the Unit for common member variables that we can't be bothered replicating
        LMAUnit &m_lma_unit;
    };

    // Train data we are interested in
    struct TrainVehicleData
    {
        // Vehicle Data of interest
        struct Vehicle
        {
           Comms::Object      m_vehicle_object;
           Sim::Number::ID    m_position_id;
           int                m_vehicle_index;
           double             m_vehicle_length;

        };

        // These vehicle objects are used when determing which train is the closest train to the
        // train whose LMA is being determined
        std::map<Comms::Object,Vehicle> m_vehicles;
    };

private:
    // Comms and Paths
    Comms::Gateway                               &m_gateway;
    Common::Data::DataAccess                     &m_data_access;
    WorldAPI::WorldAccess                        &m_world_access;
    
    // Not using points_watcher_resources because of potential unitialised variable in FeatureWatcher constructor
    WorldAPI::PointsWatcher                      m_points_watcher;

    std::unique_ptr<WorldAPI::AllTrainWatcher>    m_pall_train_watcher;
    std::unique_ptr<ScenarioTrainLengthService>   m_train_length_service;
    int                                           m_scenario_train_id;

    std::map<int, CBTC::Protos::EOACause>         m_eoa_cause_map;

    // Configuration
    double m_max_lma_ahead;
    double m_min_following_distance;
    double m_positional_uncertainty;

    // Train path watchers for all of the trains that we find. This also helps us to track which
    // trains have been found.
    std::map<Comms::Object, std::shared_ptr<TrainLMAInfo>>      m_train_lmas;

    // Train data specific to each train 
    std::map<Comms::Object, std::shared_ptr<TrainVehicleData>>  m_train_vehicle_data;

    // Synchronisation
    std::mutex                              m_mutex;
};
