///
/// @file       SpeedLimitTracker.h
///
///             Declares the SpeedLimitTracker class, a helper class to determine the speed limits
///             for any train (based on its path), for automatic driving, displaying or scoring.
///
/// @ingroup    Core Train Sim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#ifndef SPEED_LIMIT_TRACKER_H
#define SPEED_LIMIT_TRACKER_H

#include "SpeedLimitTrackerProperties.h"

#include "train_types/SpeedLimitTypes.h"

#include "world_api/FeatureWatcher.h"
#include "world_api/WorldAccess.h"

#include "sim_comms/Gateway.h"
#include "common/DataAccess.h"
#include "common/Utilities.h"

#include <map>
#include <set>

// Forward declarations
namespace Common { namespace Data { class DataAccess; } }
namespace WorldAPI { class PointsWatcher; }
namespace Sydac { class Properties; }

/// This class is responsible for determining the applicable speed limits along a path. Given a
/// path, it will calculate the speed limit changes, considering normal speed limits, crossover
/// speed limits and signals.

class SpeedLimitCBTCConfig : public Train::SpeedLimits::SpeedLimitConfig
{
public:
    /// Destructor so that the implementation classes' destructors are called
    virtual ~SpeedLimitCBTCConfig() {}

    virtual std::vector<std::shared_ptr<const Train::SpeedLimits::SpeedLimitType>> GetCBTCSpeedLimitTypes() = 0;
};

class SpeedLimitTracker : public SpeedLimitCBTCConfig
{
public:
    /// We used to store the partnering feature watcher and filter in a std::pair. However,
    /// FeatureWatcher was changed to be non-copyable, which is fair, but that meant that we
    /// couldn't use std::pair, which requires copy-construction. Hence, this structure was created.
    /// It is public because there are helper functions in the source file that use this structure.

    struct WatcherPair
    {
        WorldAPI::FeatureWatcher    watcher;
        WorldAPI::FeatureTypeFilter filter;

        // Store a TrackAssociationMap so that we can cache values
        WorldAPI::TrackAssociationMap association_map;
        bool                          refresh;

        WatcherPair()
        {
            refresh = false;
            watcher.AddCallback(MakeCallback(&WatcherPair::WatcherCallback, this));
        }

        // Custom callback to populate the map
        void WatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo info)
        {
            // We can probably be smarter than this
            refresh = true;
        }

        WorldAPI::TrackAssociationMap &GetMap()
        {
            // Whilst I am touching this to make it thread-safe, I don't have time to make more
            // wholesale changes. If I did, I would consider removing this whole refresh concept,
            // with a cached TrackAssociationMap, since that is what FeatureWatcher provides now
            // anyway. LAE 22/11/2016
            if(refresh)
            {
                refresh = false;
                association_map.Clear();
                association_map.AddFeatures(Core::Locked<WorldAPI::FeatureWatcher>(watcher)->GetObjects());
            }
            return association_map;
        }
    };

    // Constant for specifying explicitly not to request
    static const short NO_REQUEST = -1;

    // Constructor and destructor
    SpeedLimitTracker(Comms::Gateway &gateway,
                      Common::Data::DataAccess &data_access,
                      WorldAPI::WorldAccess &world_access,
                      WorldAPI::PointsWatcher &points_watcher,
                      const Common::Properties &properties,
                      double request_frequency);

    ~SpeedLimitTracker();

    // The main interface function which will be called once, after which
    // the types will be called directly.
    std::vector<std::shared_ptr<const Train::SpeedLimits::SpeedLimitType>> GetSpeedLimitTypes() override;
    std::vector<std::shared_ptr<const Train::SpeedLimits::SpeedLimitType>> GetCBTCSpeedLimitTypes() override;

    // For mainline speed boards, like standard and tunnel speed limits
    std::vector<Train::SpeedLimits::ChangePoint> GetMainlineProfilePoints(const WorldAPI::SegmentPath &path, int scenario_train_id);
    std::vector<Train::SpeedLimits::Action>      GetMainlineAdjustments(const WorldAPI::SegmentPath &path, const Train::SpeedLimits::Elements &elements, int scenario_train_id);

    // For temporary speed restrictions, paired
    std::vector<Train::SpeedLimits::ChangePoint> GetTemporaryProfilePoints(const WorldAPI::SegmentPath &path, int scenario_train_id);
    std::vector<Train::SpeedLimits::Action>      GetTemporaryAdjustments(const WorldAPI::SegmentPath &path, const Train::SpeedLimits::Elements &elements, int scenario_train_id);

    // For specialised cross-over restrictions
    std::vector<Train::SpeedLimits::ChangePoint> GetCrossoverProfilePoints(const WorldAPI::SegmentPath &path, int scenario_train_id);
    std::vector<Train::SpeedLimits::Action>      GetCrossoverAdjustments(const WorldAPI::SegmentPath &path, const Train::SpeedLimits::Elements &elements, int scenario_train_id);

    // For speeds associated with signals
    std::vector<Train::SpeedLimits::ChangePoint> GetSignalProfilePoints(const WorldAPI::SegmentPath &path, int scenario_train_id);
    std::vector<Train::SpeedLimits::Action>      GetSignalAdjustments(const WorldAPI::SegmentPath &path, const Train::SpeedLimits::Elements &elements, int scenario_train_id);

    // For speeds associated with signals (CBTC specific, which must ignore traffic light signals)
    std::vector<Train::SpeedLimits::ChangePoint> GetCBTCSignalProfilePoints(const WorldAPI::SegmentPath &path, int scenario_train_id);

private:
    /// Remembers the type of the feature, the state which makes that feature active, and also
    /// the watcher that it is associated with. At some point we will cruise through all of our
    /// instances of this structure and register the desired feature types with the desired
    /// watchers.

    struct FeatureType
    {
        // The ID of the feature type this corresponds to
        int feature_type_id;

        // The state this feature must be in to be active
        int active_state;

        std::map<int, double> feature_type_states;

        // The watcher that this feature is associated with. This effectively categorizes the
        // feature type so that we don't need to deal with it individually any more.
        WatcherPair *watcher_pair;
    };

    // Store our world access for late usage
    Comms::Gateway          &m_gateway;
    WorldAPI::WorldAccess   &m_world_access;
    WorldAPI::PointsWatcher &m_points_watcher;

    // Configuration
    SpeedLimitTrackerProperties m_properties;

    // Watchers and filters
    WatcherPair m_mainline_limit_watcher;
    WatcherPair m_restriction_limit_watcher;
    WatcherPair m_end_restriction_limit_watcher;
    WatcherPair m_crossover_limit_watcher;
    WatcherPair m_signal_watcher;
    WatcherPair m_end_signal_speed_watcher;

    // Store our pre-calculated information about the feature types that we are interested in
    std::map<int, FeatureType> m_feature_types;

    // CBTC must ignore traffice_light signals
    int m_main_line_signal_long_feature_id;
    int m_main_line_signal_short_feature_id;

    // State maps
    std::map<std::pair<int, int>, int> m_signal_states;

    // To make the path points calculation efficient, we need an association map for that too
    WorldAPI::PointsAssociationMap m_points_association_map;
    bool                           m_points_association_refresh;

    // We need to know the point state that equates to branching too
    int                            m_branching_state;

    // Maps from a TSR feature's (type ID, state ID), to the corresponding speed limit in m/s.
    // Note that all values in this map are >= 0 (i.e. valid speed limits).
    std::map<std::pair<int, int>, double> m_tsr_feature_state_id_to_speed;

private:
    // Helper setup functions
    void SetupFeatureType(const std::string &feature_type, const std::string &active_state, WatcherPair &watcher_pair, Common::Data::DataAccess &data_access);
    void SetupWatcher(WatcherPair &watcher_pair, double request_frequency);

    // Helper query function
    bool IsActive(Comms::Object object) const;

    // Helper function applying limits, as there is a pattern to how they work
    std::vector<Train::SpeedLimits::ChangePoint> GetRegionProfilePoints(const WorldAPI::SegmentPath          &path,
                                                                        WatcherPair                          &start_watcher,
                                                                        WatcherPair                          &end_watcher,
                                                                        std::function<bool(Comms::Object)>   is_start_active,
                                                                        std::function<bool(Comms::Object)>   is_end_active,
                                                                        std::function<double(Comms::Object)> get_speed_limit);
    std::vector<Train::SpeedLimits::Action> GetRegionAdjustments(const WorldAPI::SegmentPath                  &path,
                                                                 const std::stack<Train::SpeedLimits::Element> &elements,
                                                                 WatcherPair                                  &start_watcher,
                                                                 WatcherPair                                  &end_watcher,
                                                                 std::function<bool(Comms::Object)>           is_start_active,
                                                                 std::function<bool(Comms::Object)>           is_end_active,
                                                                 std::function<double(Comms::Object)>         get_speed_limit);

    double GetSpeedLimit(const Comms::Object &object);
    double GetSpeedLimitFromState(const Comms::Object &object);
    // We need a callback to be notified when points are created/destroyed
    void                            PointsWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo info);
    WorldAPI::PointsAssociationMap &GetPointsMap();
};

#endif // SPEED_LIMIT_TRACKER_H
