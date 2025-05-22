///
/// @file       SpeedLimitUnit.h
///
///             Declares the SpeedLimitUnit class.
///
/// @ingroup    Core Train Sim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///

#ifndef SPEED_LIMIT_UNIT_H
#define SPEED_LIMIT_UNIT_H

#include "train_types/SpeedLimitTypes.h"

#include "Project/Utilities/ScenarioTrainLengthService.h"
#include "core_types/SessionData.h"

#include "sim_comms/Unit.h"

#include "../../speed_limit_tracker_resources/Source/SpeedLimitTracker.h"

// Forward declarations
namespace WorldAPI { class PointsWatcher; }
namespace WorldAPI { class TrainPathWatcher; }
namespace WorldAPI { class WorldAccess; }

class ScenarioTrainLengthService;

/// This Unit is responsible for creating and populating all of the SpeedLimit objects, one under
/// each train, during a simulation. It does this using the SpeedLimitTracker provided. If some
/// other functionality is required a project may replace this.

class SpeedLimitUnit : public Comms::SteppingUnit
{
public:
    using SpeedLimitTypes = std::vector<std::shared_ptr<const Train::SpeedLimits::SpeedLimitType>>;

    // Constructor and destructor
    SpeedLimitUnit(Comms::Gateway&          gateway,
                   WorldAPI::WorldAccess&   world_access,
                   WorldAPI::PointsWatcher& points_watcher,
                   Common::DataAccess&      data_access,
                   SpeedLimitCBTCConfig&    speed_limits,
                   double                   max_limit);
    ~SpeedLimitUnit();

    std::string GetName() const override { return "Speed Limit Unit"; }

    void   Step(double new_time) override;
    double GetPeriod() const override;

private:
    // Object creation callbacks, to help us find our trains (and our created speed limit objects)
    void RootChildCreated(Comms::Object object);
    void WorldChildCreated(Comms::Object object);
    void TrainChildCreated(Comms::Object object);
    void VehicleChildCreated(Comms::Object object);
    void TrainDestroyed(Comms::Object object);
    void SpeedLimitDestroyed(Comms::Object object);
    void CBTCSpeedLimitDestroyed(Comms::Object object);

    void InitTrainObject(Comms::Object object, const SpeedLimitTypes& speed_limit_types, const bool is_simulated);

private:
    /// Holds objects and references associated with a train and its corresponding SpeedLimit
    /// object. Precalculated IDs and stored copies of the current value are also stored.
    /// It also holds the function that updates the train's speed limit, so that it can be
    /// called back by the TrainPathWatcher.

    struct SpeedLimitInfo
    {
        /// Store the stacks as they change with distance. This allows us to track the changes with
        /// each limit type down the track, rather than compiling them all into snapshots of all
        /// limit types for each position. This is more efficiency memory-wise, and also
        /// processing-wise.
        
        struct LocatedElements
        {
            double                       position;
            double                       applicable_position;
            Train::SpeedLimits::Elements elements;
        };

        bool                        is_simulated;   // Is simulated or auto-train
        const SpeedLimitTypes*      speed_limit_types;
        WorldAPI::TrainPathWatcher* path_watcher;

        // Remember the last path that we were on, so that we can work out how far we moved
        WorldAPI::SegmentPath last_path;

        Comms::Object speed_limit_object;
        Sim::Number   limit_number;
        Sim::Number   max_allowable_number;
        Sim::Raw      profile_raw;
 
        Comms::Object cbtc_speed_limit_object;
        Sim::Raw      cbtc_profile_raw;

        // Remember our current profile, which is our located elements for each limit type. These
        // are sorted by position seen, rather than the applicable position.
        std::vector<std::vector<LocatedElements>> last_profile;

        // Needed so that the profile correctly reports distance to speed increases which start 
        // when the back of the train passes the speed sign
        double    m_train_length;

        // Since there are positions in our last profile, but we are always conceptually 0-based, as
        // we recalculate our path anew each time, we should remember what our last conceptual
        // position was.
        double conceptual_position;

        // Point back to the Unit for member variables that we can't be bothered replicating
        SpeedLimitUnit *unit;

        // This is the function that, called cyclically, will update the speed limit information
        // in Comms. It is easiest to place it here, with all of the variables that it will use.
        void Update();

        // This function records that an update is being performed due to a route change before calling the 
        // standard Update function
        void RouteUpdate();
    };

    // Give the SpeedLimitInfo's Update() function access to some behavioural properties
    // and helper classes within the Unit.
    friend SpeedLimitInfo;

private:
    // Remember our speed limit tracker, along with our other resources
    Train::SpeedLimits::SpeedLimitConfig& m_limits;
    WorldAPI::WorldAccess&                m_world_access;
    WorldAPI::PointsWatcher&              m_points_watcher;

    // Behaviour
    double m_max_limit;

    // Used to determine the train length
    std::unique_ptr<ScenarioTrainLengthService>    m_train_length_service;

    // Train path watchers for all of the trains that we find. This also helps us to track which
    // trains have been found.
    std::map<Comms::Object, SpeedLimitInfo> m_trains;

    // Remember the types of our speed limits, which we will also copy into the information for each
    // vehicle that we find.
    SpeedLimitTypes m_limit_types;
    // CBTC (simulated trains) need to ignore traffic light signals, so we have to handle sim/auto trains differently
    SpeedLimitTypes m_cbtc_limit_types;
};

#endif // SPEED_LIMIT_UNIT_H
