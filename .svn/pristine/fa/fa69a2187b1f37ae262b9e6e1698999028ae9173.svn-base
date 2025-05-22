///
/// @file       SpeedLimitTracker.h
///
///             Implements the SpeedLimitTracker class, a helper class to determine the speed limits
///             for any train (based on its path), for automatic driving, displaying or scoring.
///
/// @ingroup    Core Train Sim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#include "SpeedLimitTracker.h"

#include "FeatureHelpers.h"
#include "project_features/ProjectFeatureConstants.h"

#include "core_comms_structure/CoreObjectConstants.h"
#include "core_data_access/Feature.h"
#include "train_comms_structure/TrainObjectConstants.h"
#include "train_features/TrainFeatureConstants.h"

#include "common/CommonExceptions.h"
#include "common/StandardLogging.h"
#include "world_api/PointsWatcher.h"

#include <cassert>

// This makes the implementation significantly less wordy
using namespace Train::SpeedLimits;

namespace
{
    // Stop at the signal. The autodriver will pull up before
    const double SIGNAL_SPACE   = 5.0;
    const double SIGNAL_OVERRUN = 5.0;

    const double MAX_CROSSOVER_PROXIMITY_BEHIND = 5.0;
    const double MAX_CROSSOVER_PROXIMITY        = 100.0;
    const double MAX_CROSSOVER_LENGTH           = 200.0;
    const double EPSILON                        = 0.001;

    const std::string NO_STATE      = "";
    const int         ALWAYS_ACTIVE = -1;

    // Stop state constants
    const int    STOP_STATE_RED_OFF              = 1;
    const int    STOP_STATE_VIOLET               = 2;
    const int    STOP_STATE_GREEN                = 3;

    const double FIFTEEN_KM_HR    = 15.0 * 1000.0 / 3600.0;
    const double FORTY_KM_HR      = 40.0 * 1000.0 / 3600.0;
    const double SIXTY_FIVE_KM_HR = 65.0 * 1000.0 / 3600.0;
    const double EIGHTY_KM_HR     = 80.0 * 1000.0 / 3600.0;

    /// Given an object, this returns the value of thet state property, cast to an integer. If the
    /// object does not have a state number, a value of -1 is returned, which won't match any state.
    ///
    /// @param object The object, presumably a feature, to get the state of.
    ///
    /// @return The feature's state, or -1 if it doesn't have one

    inline int GetState(Comms::Object object)
    try
    {
        return static_cast<int>(object.Numbers().Get(Core::ValueName::Feature::STATE));
    }
    catch (...)
    {
        return ALWAYS_ACTIVE;
    };

    /// Given an object that is a feature, this returns the type of the feature, by checking it's
    /// type property and casting to an integer. If the object does not have a type, a value of -1
    /// is returned, which won't match any type.
    ///
    /// @param object The object, presumably a feature, to get the type of
    ///
    /// @return The feature's type, or -1 if it doesn't have one

    inline int GetFeatureType(Comms::Object object)
    try
    {
        return static_cast<int>(object.Numbers().Get(Core::ValueName::Feature::TYPE));
    }
    catch (...)
    {
        return -1;
    };

    /// Helper function that determines whether an object is in the active state and thus should be
    /// considered in the calculation of the speed limit profile. The active state has already been
    /// determined through previous database queries, so that is passed in to (in case the state of
    /// the object is used, rather than another property).
    ///
    /// @param object       The object to determine the activity state of
    /// @param active_state The state that the object must be in to be active
    ///
    /// @return True if the object is active and may impact the speed limit profile. False otherwise

    bool IsActive(Comms::Object object, int active_state)
    {
        // If there is no specific active state then we will consider this feature always active
        if (active_state == ALWAYS_ACTIVE)
            return true;

        // Get the ID of the State number for this object. If it does not have one then it can be
        // treated as always active.
        const Sim::Number::ID state_number_id = object.Numbers().Info().GetID(Core::ValueName::Feature::STATE);
        if (state_number_id == Sim::INVALID_NUMBER)
            return true;

        // Fetch the value of this state and compare it with the desired state
        return static_cast<int>(object.Numbers().Store().Get(state_number_id).value) == active_state;
    }

    /// A helper to get the speed limit from a TSR Board, which is defined by
    /// its state.
    /// @return The speed limit, in m/s, or std::numeric_limits<double>::max()
    ///         if the speed cannot be determined.
    /// @pre tsr_feature_object is valid.
    /// @pre Ownership of the Comms mutex.
    double GetTSRSpeedLimit(const Comms::Object& tsr_feature_object, const std::map<std::pair<int, int>, double>& state_id_to_speed)
    {
        assert(tsr_feature_object.IsValid());

        const auto state_number_id = tsr_feature_object.Numbers().Info().GetID(Core::ValueName::Feature::STATE);
        const auto feature_type_id = tsr_feature_object.Numbers().Info().GetID(Core::ValueName::Feature::TYPE);

        if ((state_number_id != Sim::INVALID_NUMBER) && (feature_type_id != Sim::INVALID_NUMBER))
        {
            const std::pair<int, int> lookup_key(GetFeatureType(tsr_feature_object), GetState(tsr_feature_object));
            const auto&               map_iterator = state_id_to_speed.find(lookup_key);
            if (map_iterator != state_id_to_speed.end())
            {
                const auto speed = map_iterator->second;
                return speed;
            }
        }

        return std::numeric_limits<double>::max();
    }

    /// Helper for determining if a TSR Board feature is "active", and hence its
    /// speed limit should be applied.
    /// @pre tsr_feature_object is valid.
    /// @pre Ownership of the Comms mutex.
    bool IsTSRStartActive(const Comms::Object& tsr_feature_object, const std::map<std::pair<int, int>, double>& state_id_to_speed)
    {
        assert(tsr_feature_object.IsValid());

        const auto state_number_id = tsr_feature_object.Numbers().Info().GetID(Core::ValueName::Feature::STATE);
        const auto feature_type_id = tsr_feature_object.Numbers().Info().GetID(Core::ValueName::Feature::TYPE);

        if ((state_number_id == Sim::INVALID_NUMBER) || (feature_type_id == Sim::INVALID_NUMBER))
            return false;

        // The speed limit should be applied if and only if the current state maps to a speed.
        const std::pair<int, int> lookup_key(GetFeatureType(tsr_feature_object), GetState(tsr_feature_object));
        const auto                lookup_iter = state_id_to_speed.find(lookup_key);

        return lookup_iter != state_id_to_speed.end();
    }

    /// Helper for determining if a TSR End is "active".
    bool IsTSREndActive(Comms::Object)
    {
        // At the time of writing, the TSR End feature type is always active,
        // as it only has one state.
        return true;
    }

    bool IsInterestingStopState(int stop_state)
    {
        // We care about the clear state too
        return ((stop_state == STOP_STATE_RED_OFF) || (stop_state == STOP_STATE_GREEN) || (stop_state == STOP_STATE_VIOLET));
    }
    /// Helper function to help determine the speed that the object, or its stop state, corresponds
    /// to. Various information is passed in so that the speed can be determined in different ways
    /// depending on the feature type.
    ///
    /// @param object        The comms object representing this feature
    /// @param stop_state    The stop state that this feature is in, according to its feature state
    /// @param default_limit The default limit of the line, which can be used when a stop state
    ///                      corresponds to 'clear'
    ///
    /// @return The speed limit that this feature corresponds to
    ///
    /// @note This is really a bit dumb, since it isn't really generic at all, we aren't using
    ///       the object, there is no possibility of caching on a stand-alone function, and we
    ///       really want the line limit, not the default limit.

    double GetStopStateSpeed(Comms::Object object, int stop_state, double default_limit)
    {
        // We care about the medium and also the normal states. This is because the normal state
        // will clearly drop the speed limit behind the line speed, but if we don't handle the
        // clear state the next signal we pass will never raise the speed limit back up again!
        // Note that a clear aspect means the default limit. This will always be brought down to
        // whatever the line limit is at this point anyway.
        // We also care about the low speed state, which has its own speed limit.
        // For MMRBEM stop state green as well as stop state violet will default speed 
        if (stop_state == STOP_STATE_GREEN || stop_state == STOP_STATE_VIOLET)
            return default_limit;

        return 0.0;
    }
}

/// Constructor. Because this class really only has two working functions, and this is one of
/// them, we do all of our setup work here. This involves determining all the state for all of
/// the features that we are interested in. It also involves setting up our feature watchers
/// and filters to monitor for the features that we care about.
///
/// @param gateway           The gateway to use
/// @param data_access       The data access to use.
/// @param world_access      The world access to use.
/// @param points_watcher    We are supplied with the points watcher to use (for determining
///                          crossovers) so that we don't need to create a new one.
/// @param request_frequency If a global requester is not being used, and it is necessary to
///                          request on the features that we are interested in, set this to be
///                          the frequency to request at >= 0.0. If a value < 0.0 is used then
///                          no request will be made.

SpeedLimitTracker::SpeedLimitTracker(Comms::Gateway&           gateway,
                                     Common::Data::DataAccess& data_access,
                                     WorldAPI::WorldAccess&    world_access,
                                     WorldAPI::PointsWatcher&  points_watcher,
                                     const Common::Properties& properties,
                                     double                    request_frequency)
  : m_gateway(gateway), m_world_access(world_access), m_points_watcher(points_watcher), m_properties(properties)
{
    Trace::GetLogger().STAMP(Trace::INFO) << "#### SpeedLimitTracker Loaded\n";

    // The first step is to use the database to generate our state maps.
    // DataAccess forces us to get all of the states at once, so we will only
    // do this once instead of three times.
    std::vector<Core::Data::FeatureTypeState> all_states;
    Core::Database::Feature                   feature_access(data_access);

    try
    {
        all_states = feature_access.GetAllFeatureTypeStates();
      /*  m_main_line_signal_long_feature_id =
          feature_access.GetFeatureType(Project::FeatureTypes::FETY_MAIN_LINE_SIGNAL_LONG).feature_type_id;
        m_main_line_signal_short_feature_id =
          feature_access.GetFeatureType(Project::FeatureTypes::FETY_MAIN_LINE_SIGNAL_SHORT).feature_type_id;*/
    }
    catch (CommonException& e)
    {
        e.AddStackTrace(FLSTAMP, "Querying for a list of all possible feature states.");
        throw;
    }

    // Note: A fair bit of the following is commented out because these features are not actually in
    //       core, but they provide a sample of how to implement this

    // Determine the IDs of the features that we care about. It is recommended that the speed limit is stored in a
    // property, rather than a state. We use the state to see if the speed limit is active/visible.
    // Following features present in NTATRL are commented in MMRBEM as it is NA
    /* SetupFeatureType(Project::FeatureTypes::FETY_PSR_DECREASE_POLE, NO_STATE, m_mainline_limit_watcher, data_access);
     SetupFeatureType(Project::FeatureTypes::FETY_PSR_DECREASE_TUNNEL, NO_STATE, m_mainline_limit_watcher, data_access);
     SetupFeatureType(Project::FeatureTypes::FETY_PSR_INCREASE_POLE, NO_STATE, m_mainline_limit_watcher, data_access);
     SetupFeatureType(Project::FeatureTypes::FETY_PSR_INCREASE_TUNNEL, NO_STATE, m_mainline_limit_watcher,
     data_access);*/
    SetupFeatureType(Project::FeatureTypes::FETY_MAIN_LINE_SIGNAL_LONG, Project::FeatureStates::RED, m_mainline_limit_watcher, data_access);
    SetupFeatureType(Project::FeatureTypes::FETY_MAIN_LINE_SIGNAL_SHORT, Project::FeatureStates::RED, m_mainline_limit_watcher, data_access);
    SetupFeatureType(Project::FeatureTypes::FETY_SPEED_RESTRICTION_MARKER_BOARD, NO_STATE, m_mainline_limit_watcher, data_access);

    // Temporary speed restrictions, and the same simple pattern can be used for any limits that have a start and an end
    // feature
    // SetupFeatureType(Project::FeatureTypes::FETY_START_TSR, NO_STATE, m_restriction_limit_watcher, data_access);
    // SetupFeatureType(Project::FeatureTypes::FETY_END_TSR, NO_STATE, m_end_restriction_limit_watcher, data_access);

    // const auto tsr_board_feature_type_id =
    // feature_access.GetFeatureType(Project::FeatureTypes::FETY_START_TSR).feature_type_id;

    //// Add Work Area TSR Types - Note that mixing the above and below types will probably work.
    auto work_zone_feature_type_id = feature_access.GetFeatureType(Project::FeatureTypes::FETY_WORK_ZONE).feature_type_id;
    SetupFeatureType(Project::FeatureTypes::FETY_WORK_ZONE, NO_STATE, m_restriction_limit_watcher, data_access);
    SetupFeatureType(Project::FeatureTypes::FETY_WORK_ZONE_END, NO_STATE, m_end_restriction_limit_watcher, data_access);

    // const auto work_area_tsr_feature_type_id =
    // feature_access.GetFeatureType(Project::FeatureTypes::FETY_CBTC_TSR).feature_type_id;

    // Crossovers
    // SetupFeatureType(Project::FeatureTypes::FETY_SPEED_RESTRICT,         NO_STATE, m_crossover_limit_watcher,
    // data_access);

    // The early termination of the effect of signals, if necessary ... quite powerful where required
    // SetupFeatureType(Project::FeatureTypes::FETY_SPEED_SIGNAL_END, Project::FeatureStates::ACTIVE,
    // m_end_signal_speed_watcher, data_access);

    // Populate a map of stop states for signals.
    // To do this we just run through all of our states and look for the states
    // that correspond to a stop state!
    // Track the signal types to set our filter with later.
    std::set<int> signal_types;
    for (auto feature_state : all_states)
    {
         if(IsInterestingStopState(feature_state.stop_state))
         {
             m_signal_states[std::pair<int, int>(feature_state.feature_type_id, feature_state.feature_type_state_id)] =feature_state.stop_state; 
             signal_types.insert(feature_state.feature_type_id);
         }

        // HACK: Piggy-back on the iteration through states to determine
        //       which Work Zone states map to a speed limit.
        if (feature_state.feature_type_id == work_zone_feature_type_id)
        {
            const auto speed_value = feature_state.state_value;
            // We will only consider values that make sense. This way the
            // feature type can easily define states that don't map to a limit
            // by using negative values.
            if (speed_value >= 0.0)
            {
                const auto feature_id = feature_state.feature_type_id;
                const auto state_id   = feature_state.feature_type_state_id;
                m_tsr_feature_state_id_to_speed[std::pair<int, int>(feature_state.feature_type_id, feature_state.feature_type_state_id)] = speed_value;
            }
        }

        // HACK: Piggy-back on the iteration through states to determine
        //       which TSR states map to a speed limit.
        // if(feature_state.feature_type_id == tsr_board_feature_type_id)
        //{
        //    const auto speed_value = feature_state.state_value;
        //    // We will only consider values that make sense. This way the
        //    // feature type can easily define states that don't map to a limit
        //    // by using negative values.
        //    if(speed_value >= 0.0)
        //    {
        //        const auto feature_id = feature_state.feature_type_id;
        //        const auto state_id = feature_state.feature_type_state_id;
        //        m_tsr_feature_state_id_to_speed[std::pair<int, int>(feature_state.feature_type_id,
        //        feature_state.feature_type_state_id)] = speed_value;

        //        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Mapping TSR state " << feature_state.state_name << " to
        //        speed of " << speed_value << "m/s." << Trace::EndLog();
        //    }
        //}
    }

    // Set up watchers for the feature types that we are interested in
    SetupWatcher(m_mainline_limit_watcher, request_frequency);
    SetupWatcher(m_restriction_limit_watcher, request_frequency);
    SetupWatcher(m_end_restriction_limit_watcher, request_frequency);
    SetupWatcher(m_crossover_limit_watcher, request_frequency);
    SetupWatcher(m_end_signal_speed_watcher, request_frequency);

    // Set up our signal watcher too, although we will have to set the types manually
    m_signal_watcher.watcher.SetFeatureTypeFilter(CreateFilterCallback(m_signal_watcher.filter));
    m_signal_watcher.watcher.SetRequestFrequency(request_frequency);
    m_signal_watcher.filter.SetAcceptableTypes(std::vector<int>(signal_types.begin(), signal_types.end()));

    // Determine the state for branching points
    try
    {
        // Find the feature type for points
        auto points_type = feature_access.GetFeatureType(Project::FeatureTypes::POINT);

        // To avoid another database query, which appears to be slow, we will
        // just linearly iterate through the list of states.
        for (auto feature_state : all_states)
        {
            if ((feature_state.feature_type_id == points_type.feature_type_id) &&
                (feature_state.state_name == Project::FeatureStates::BRANCH_LINE_LEFT_OF_MAIN))
            {
                m_branching_state = feature_state.feature_type_state_id;
                break;
            }
        }
    }
    catch (CommonException& e)
    {
        e.AddStackTrace(FLSTAMP, "Determining branching point state");
        throw;
    }

    // We still need to attach the feature watchers, with the comms layer locked
    {
        OS::Lock<Comms::Gateway> lock(m_gateway);
        m_mainline_limit_watcher.watcher.Attach(m_gateway.GetRootObject());
        m_restriction_limit_watcher.watcher.Attach(m_gateway.GetRootObject());
        m_end_restriction_limit_watcher.watcher.Attach(m_gateway.GetRootObject());
        m_crossover_limit_watcher.watcher.Attach(m_gateway.GetRootObject());
        m_signal_watcher.watcher.Attach(m_gateway.GetRootObject());
        m_end_signal_speed_watcher.watcher.Attach(m_gateway.GetRootObject());

        // Mark our map as needing to be refreshed, and add a callback to the points watcher for
        // notification on change of point information.
        m_points_association_refresh = true;
        m_points_watcher.AddCallback(MakeCallback(&SpeedLimitTracker::PointsWatcherCallback, this));
    }
}

/// Destructor. We just have to detach our watchers from the root object.

SpeedLimitTracker::~SpeedLimitTracker()
{
    // Detach our feature watchers
    OS::Lock<Comms::Gateway> lock(m_gateway);
    m_mainline_limit_watcher.watcher.Detach();
    m_restriction_limit_watcher.watcher.Detach();
    m_end_restriction_limit_watcher.watcher.Detach();
    m_crossover_limit_watcher.watcher.Detach();
    m_signal_watcher.watcher.Detach();
    m_end_signal_speed_watcher.watcher.Detach();

    // Remember to remove the callback with the points watcher too!
    m_points_watcher.RemoveCallback(MakeCallback(&SpeedLimitTracker::PointsWatcherCallback, this));
}

/// Queried to determine all of the speed limit types that we need to track.
///
/// @return All of the speed limit types as shared pointers to the SpeedLimitType interface,
///         which allows us to use them to also determine profile points and adjustments for
///         their type.

std::vector<std::shared_ptr<const Train::SpeedLimits::SpeedLimitType>> SpeedLimitTracker::GetSpeedLimitTypes()
{
    std::vector<std::shared_ptr<const SpeedLimitType>> ret;

    if (m_properties.EnableMainlineLimits())
    {

        ret.push_back(std::shared_ptr<const SpeedLimitType>(new SpeedLimitTypeDelegator(
          std::bind(&SpeedLimitTracker::GetMainlineProfilePoints, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&SpeedLimitTracker::GetMainlineAdjustments, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
          true)));
    }

    if (m_properties.EnableTemporaryLimits())
        ret.push_back(std::shared_ptr<const SpeedLimitType>(new SpeedLimitTypeDelegator(
          std::bind(&SpeedLimitTracker::GetTemporaryProfilePoints, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&SpeedLimitTracker::GetTemporaryAdjustments, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
          true)));

    if (m_properties.EnableCrossoverLimits())
        ret.push_back(std::shared_ptr<const SpeedLimitType>(new SpeedLimitTypeDelegator(
          std::bind(&SpeedLimitTracker::GetCrossoverProfilePoints, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&SpeedLimitTracker::GetCrossoverAdjustments, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
          true)));

    if (m_properties.EnableSignalLimits())
        ret.push_back(std::shared_ptr<const SpeedLimitType>(new SpeedLimitTypeDelegator(
          std::bind(&SpeedLimitTracker::GetSignalProfilePoints, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&SpeedLimitTracker::GetSignalAdjustments, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
          false)));

    return ret;
}

std::vector<std::shared_ptr<const Train::SpeedLimits::SpeedLimitType>> SpeedLimitTracker::GetCBTCSpeedLimitTypes()
{
    std::vector<std::shared_ptr<const SpeedLimitType>> ret;

    if (m_properties.EnableMainlineLimits())
    {

        ret.push_back(std::shared_ptr<const SpeedLimitType>(new SpeedLimitTypeDelegator(
          std::bind(&SpeedLimitTracker::GetMainlineProfilePoints, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&SpeedLimitTracker::GetMainlineAdjustments, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
          true)));
    }

    if (m_properties.EnableTemporaryLimits())
        ret.push_back(std::shared_ptr<const SpeedLimitType>(new SpeedLimitTypeDelegator(
          std::bind(&SpeedLimitTracker::GetTemporaryProfilePoints, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&SpeedLimitTracker::GetTemporaryAdjustments, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
          true)));

    if (m_properties.EnableCrossoverLimits())
        ret.push_back(std::shared_ptr<const SpeedLimitType>(new SpeedLimitTypeDelegator(
          std::bind(&SpeedLimitTracker::GetCrossoverProfilePoints, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&SpeedLimitTracker::GetCrossoverAdjustments, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
          true)));

    if (m_properties.EnableSignalLimits())
        ret.push_back(std::shared_ptr<const SpeedLimitType>(new SpeedLimitTypeDelegator(
          std::bind(&SpeedLimitTracker::GetCBTCSignalProfilePoints, this, std::placeholders::_1, std::placeholders::_2),
          std::bind(&SpeedLimitTracker::GetSignalAdjustments, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),
          false)));

    return ret;
}

/// Queried to determine what the change points are on the path ahead, generally relating to where
/// the speed limits change for this speed limit type.
///
/// @param path              The current path, where the train is at the origin
/// @param scenario_train_id The Scenario Train ID that identifies the train
///                          travelling on this path
/// @return The points ahead of us where the mainline speed limit profile changes

std::vector<ChangePoint> SpeedLimitTracker::GetMainlineProfilePoints(const WorldAPI::SegmentPath& path, int scenario_train_id)
{
    std::vector<ChangePoint> ret;

    // Add each mainline speed limit into the profile
    std::vector<std::pair<double, Comms::Object>> mainline_limits = m_world_access.GetPathFeatures(
      path, m_mainline_limit_watcher.GetMap(), 0.0);

    for (const auto& limit : mainline_limits)
    {
        if (IsActive(limit.second))
        {
            ChangePoint point(limit.first);
            point.actions.push_back(Action(Action::Type::CLEAR));
            point.actions.push_back(Action(Action::Type::PUSH, GetSpeedLimit(limit.second)));
            ret.push_back(point);
        }
    }

    return ret;
}

/// Queried to determine what changes should be made to the current element stack for
/// this speed limit type.
///
/// @param path              The current path, where the train is at the origin
/// @param elements          The current element stack (for the closest change point prior to the
///                          train's current location) that may need modification.
/// @param scenario_train_id The Scenario Train ID that identifies the train
///                          travelling on this path
///
/// @return The changes that we should make to our current memory of mainline speed limits,
///         possibly to apply limits behind us that we didn't actually drive over but
///         nevertheless should be aware of.

std::vector<Action> SpeedLimitTracker::GetMainlineAdjustments(const WorldAPI::SegmentPath& path, const Elements& elements, int scenario_train_id)
{
    std::vector<Action> ret;

    // If we do not have any elements then possibly there was a main line limit behind us. If
    // there was, regardless of how far it was behind us, then set it as our mainline limit.
    if (elements.empty())
    {
        const auto mainline_limits = m_world_access.GetPathFeatures(
          path, m_mainline_limit_watcher.GetMap(), -std::numeric_limits<double>::max(), 0.0);
        if (!mainline_limits.empty())
            ret.push_back(Action(Action::Type::PUSH, GetSpeedLimit(mainline_limits.back().second)));
    }

    return ret;
}

/// Queried to determine what the change points are on the path ahead, generally relating to where
/// the speed limits change for this speed limit type.
///
/// @param path              The current path, where the train is at the origin
/// @param scenario_train_id The Scenario Train ID that identifies the train
///                          travelling on this path
///
/// @return The points ahead of us where the restriction speed limit profile changes

std::vector<ChangePoint> SpeedLimitTracker::GetTemporaryProfilePoints(const WorldAPI::SegmentPath& path, int scenario_train_id)
{
    return GetRegionProfilePoints(
      path,
      m_restriction_limit_watcher,
      m_end_restriction_limit_watcher,
      [this](Comms::Object object) { return IsTSRStartActive(object, m_tsr_feature_state_id_to_speed); },
      [](Comms::Object object) { return IsTSREndActive(object); },
      [this](Comms::Object object) { return GetTSRSpeedLimit(object, m_tsr_feature_state_id_to_speed); });
}

/// Queried to determine what changes should be made to the current element stack for
/// this speed limit type.
///
/// @param path              The current path, where the train is at the origin
/// @param elements          The current element stack (for the closest change point prior to the
///                          train's current location) that may need modification.
/// @param scenario_train_id The Scenario Train ID that identifies the train
///                          travelling on this path
///
/// @return The changes that we should make to our current memory of restriction speed limits,
///         possibly to apply limits behind us that we didn't actually drive over but
///         nevertheless should be aware of.

std::vector<Action> SpeedLimitTracker::GetTemporaryAdjustments(const WorldAPI::SegmentPath& path, const Elements& elements, int scenario_train_id)
{
    return GetRegionAdjustments(
      path,
      elements,
      m_restriction_limit_watcher,
      m_end_restriction_limit_watcher,
      [this](Comms::Object object) { return IsTSRStartActive(object, m_tsr_feature_state_id_to_speed); },
      [](Comms::Object object) { return IsTSREndActive(object); },
      [this](Comms::Object object) { return GetTSRSpeedLimit(object, m_tsr_feature_state_id_to_speed); });
}

/// Queried to determine what the change points are on the path ahead, generally relating to where
/// the speed limits change for this speed limit type.
///
/// @param path              The current path, where the train is at the origin
/// @param scenario_train_id The Scenario Train ID that identifies the train
///                          travelling on this path
///
/// @return The points ahead of us where the restriction speed limit profile changes

std::vector<ChangePoint> SpeedLimitTracker::GetCrossoverProfilePoints(const WorldAPI::SegmentPath& path, int scenario_train_id)
{
    std::vector<ChangePoint> ret;

    // Firstly, get a list of all points and crossover limits on the path
    const auto crossover_limits = m_world_access.GetPathFeatures(path, m_crossover_limit_watcher.GetMap());
    const auto points           = m_world_access.GetPathPoints(path, GetPointsMap());

    // Then, for each limit determine the set of points that it corresponds to,
    // and check if we are going to branch here. If so, the limit applies.
    for (size_t i = 0; i < crossover_limits.size(); ++i)
    {
        // if this is not active then move on
        if (!IsActive(crossover_limits[i].second))
            continue;

        // Find the first point after this limit that is within our range and
        // which is facing and which is set to the branching state.
        auto start_iter = points.begin();
        for (; start_iter != points.end(); ++start_iter)
        {
            if (start_iter->is_facing && (start_iter->offset > crossover_limits[i].first) &&
                (start_iter->offset < (crossover_limits[i].first + MAX_CROSSOVER_PROXIMITY)) &&
                (GetState(start_iter->object) == m_branching_state))
            {
                break;
            }
        }

        // Now, if we have found our start point, start looking for the points
        // at the other end of the crossover.
        if (start_iter != points.end())
        {
            // Find the first point after the start point that is within the
            // crossover length, which is not facing, and which is also in
            // the branching state.
            auto end_iter = start_iter;
            for (++end_iter; end_iter != points.end(); ++end_iter)
            {
                if (!end_iter->is_facing && (end_iter->offset > start_iter->offset) &&
                    (end_iter->offset < (start_iter->offset + MAX_CROSSOVER_LENGTH)) &&
                    (GetState(end_iter->object) == m_branching_state))
                {
                    break;
                }
            }

            // If we have the end point too then we have found the
            // crossover, and need to inject these into our current list
            // of speed limits.
            if (end_iter != points.end())
            {
                // Add the two change points. The first is at the first point, applies immediately, and has the limit
                // associated with the feature
                ChangePoint start_point(start_iter->offset);
                start_point.actions.push_back(Action(Action::Type::PUSH, GetSpeedLimit(crossover_limits[i].second)));
                ret.push_back(start_point);

                // The second clears any crossover limits, associated with the point
                ChangePoint end_point(end_iter->offset);
                end_point.actions.push_back(Action(Action::Type::CLEAR));
                ret.push_back(end_point);
            }
        }
    }

    return ret;
}

/// Queried to determine what changes should be made to the current element stack for
/// this speed limit type.
///
/// @param path              The current path, where the train is at the origin
/// @param elements          The current element stack (for the closest change point prior to the
///                          train's current location) that may need modification.
/// @param scenario_train_id The Scenario Train ID that identifies the train
///                          travelling on this path
///
/// @return The changes that we should make to our current memory of crossover speed limits,
///         possibly to apply limits behind us that we didn't actually drive over but
///         nevertheless should be aware of.

std::vector<Action> SpeedLimitTracker::GetCrossoverAdjustments(const WorldAPI::SegmentPath& path, const Elements& elements, int scenario_train_id)
{
    // Actually, for the moment we won't do any adjustments
    return std::vector<Action>();
}

/// Queried to determine what the change points are on the path ahead, generally relating to where
/// the speed limits change for this speed limit type.
///
/// @param path              The current path, where the train is at the origin
/// @param scenario_train_id The Scenario Train ID that identifies the train
///                          travelling on this path
///
/// @return The points ahead of us where the signal speed limit profile changes

std::vector<ChangePoint> SpeedLimitTracker::GetSignalProfilePoints(const WorldAPI::SegmentPath& path, int scenario_train_id)
{
    std::vector<ChangePoint> ret;

    // Inject the signals, simply by getting a list of the signals along the path and injecting
    // them. A signal's region is only up to the next signal (or for the rest of the track if it
    // is the last signal). Additionally, it depends on the aspect. For instance:
    //  * STOP aspect will mean a target speed of 0
    //  * MEDIUM aspect will mean a different target speed, potentially dependent on other
    //      properties on the signal
    //  * NORMAL aspect will mean a normal speed. This won't be applied as a limit, even though
    //      it could be necessary to take a previous medium speed up to a normal speed, because
    //      each signal will now be applied as a region, so the medium speed is already
    //      returning to a normal speed.

    // We look at all signals ahead of us on our track. The signals that we have already seen
    // are stored in our state.
    std::vector<std::pair<double, Comms::Object>> signals = m_world_access.GetPathFeatures(path, m_signal_watcher.GetMap(), 0.0);

    for (auto& signal : signals)
    {
        // We have to check the signal (stop) state, which requires knowing the feature type
        // This is quite an expensive line, so in the future we may need to pay attention to
        // caching the feature type, maybe the state, and possibly using faster than a map for
        // lookup
        const auto                feature_type = GetFeatureType(signal.second);
        const std::pair<int, int> lookup_key(feature_type, GetState(signal.second));
        const auto                lookup_iter = m_signal_states.find(lookup_key);

        if (lookup_iter != m_signal_states.end())
        {
            double speed_limit = GetStopStateSpeed(signal.second, lookup_iter->second, std::numeric_limits<double>::max());

            // Create a change point. Note that signals only apply to the front of a train. We
            // also apply the signal limit a little in advance so that the train tries to stop
            // a bit before a signal.
            ChangePoint point(signal.first - SIGNAL_SPACE, ChangePoint::Application::DRIVER);

            // This will automatically clear the effect of any previous signal, if there was one
            // and it hasn't already been cleared
            point.actions.push_back(Action(Action::Type::CLEAR));

            // If the signal carries a speed limit then add it
            if(speed_limit < std::numeric_limits<double>::max())
                point.actions.push_back(Action(Action::Type::PUSH, speed_limit));

            ret.push_back(point);
        }
    }

    // Add all the end signal positions too
    std::vector<std::pair<double, Comms::Object>> end_signals = m_world_access.GetPathFeatures(
      path, m_end_signal_speed_watcher.GetMap(), 0.0);

    for (auto& end_signal : end_signals)
    {
        // Add each one that is active
        if (IsActive(end_signal.second))
        {
            // Note that end signal points apply to the whole train, as they are generally tied
            // to some rule like 'once the train has cleared the points'
            // Clear the effect of all signals
            ChangePoint point(end_signal.first);
            point.actions.push_back(Action(Action::Type::CLEAR));
            ret.push_back(point);
        }
    }

    // Sort these and return
    std::sort(
      ret.begin(), ret.end(), [](const ChangePoint& lhs, const ChangePoint& rhs) { return lhs.position < rhs.position; });
    return ret;
}

/// Queried to determine what changes should be made to the current element stack for
/// this speed limit type.
///
/// @param path              The current path, where the train is at the origin
/// @param elements          The current element stack (for the closest change point prior to the
///                          train's current location) that may need modification.
/// @param scenario_train_id The Scenario Train ID that identifies the train
///                          travelling on this path
/// @return The changes that we should make to our current memory of signal speed limits,
///         possibly to clear the effect of any signals we passed at stop, where appropriate

std::vector<Action> SpeedLimitTracker::GetSignalAdjustments(const WorldAPI::SegmentPath& path, const Elements& elements, int scenario_train_id)
{
    std::vector<Action> ret;

    // We won't add signals in that are behind us because they will either be in our state, or
    // the driver hasn't seen them.
    // However, if we have a speed limit of 0.0, but the immediate signal behind us is not
    // calling for a limit of 0.0 then we will presume that it has changed state on us and we
    // can remove this speed limit.
    if (!elements.empty() && (elements.top().speed == 0.0))
    {
        // If we have a signal behind us, look at its state. We don't need to consider end
        // signal features, because we can't have passed one. We also consider up to the signal
        // stopping distance ahead of us, because that could have given us a stop speed of 0 too.
        std::vector<std::pair<double, Comms::Object>> signals = m_world_access.GetPathFeatures(
          path, m_signal_watcher.GetMap(), -std::numeric_limits<double>::max(), SIGNAL_SPACE);

        if (!signals.empty())
        {
            // The same lookup approach ...
            const auto                feature_type_id = GetFeatureType(signals.back().second);
            const auto                feature_state   = GetState(signals.back().second);
            const std::pair<int, int> lookup_key(feature_type_id, feature_state);
            const auto                lookup_iter = m_signal_states.find(lookup_key);
            if (lookup_iter != m_signal_states.end())
            {
                // Check the speed limit that this called for. If it is not zero then we should
                // clear any signal records that we have (since we don't nest them anyway, and
                // the entry of 0.0 is no longer applicable.
                if (GetStopStateSpeed(signals.back().second, lookup_iter->second, std::numeric_limits<double>::max()) != 0.0)
                    ret.push_back(Action(Action::Type::CLEAR));
            }
            else
            {
                // In this case, the signal has changed from a state we recognise,
                // to one we don't. We will assume it's okay to proceed now.
                ret.push_back(Action(Action::Type::CLEAR));
            }
        }
    }

    return ret;
}

std::vector<ChangePoint> SpeedLimitTracker::GetCBTCSignalProfilePoints(const WorldAPI::SegmentPath& path, int scenario_train_id)
{
    std::vector<ChangePoint> ret;

    // Inject the signals, simply by getting a list of the signals along the path and injecting
    // them. A signal's region is only up to the next signal (or for the rest of the track if it
    // is the last signal). Additionally, it depends on the aspect. For instance:
    //  * STOP aspect will mean a target speed of 0
    //  * MEDIUM aspect will mean a different target speed, potentially dependent on other
    //      properties on the signal
    //  * NORMAL aspect will mean a normal speed. This won't be applied as a limit, even though
    //      it could be necessary to take a previous medium speed up to a normal speed, because
    //      each signal will now be applied as a region, so the medium speed is already
    //      returning to a normal speed.

    // We look at all signals ahead of us on our track. The signals that we have already seen
    // are stored in our state.
    std::vector<std::pair<double, Comms::Object>> signals = m_world_access.GetPathFeatures(path, m_signal_watcher.GetMap(), 0.0);

    for (auto& signal : signals)
    {
        // We have to check the signal (stop) state, which requires knowing the feature type
        // This is quite an expensive line, so in the future we may need to pay attention to
        // caching the feature type, maybe the state, and possibly using faster than a map for
        // lookup
        const auto                feature_type = GetFeatureType(signal.second);
        const std::pair<int, int> lookup_key(feature_type, GetState(signal.second));
        const auto                lookup_iter = m_signal_states.find(lookup_key);

        // NOTE: CBTC must ignore traffic light signals
        if (lookup_iter != m_signal_states.end() /*&& ((feature_type == m_main_line_signal_long_feature_id || feature_type == m_main_line_signal_short_feature_id)*/)
        {
            double speed_limit = GetStopStateSpeed(signal.second, lookup_iter->second,std::numeric_limits<double>::max());

            // Create a change point. Note that signals only apply to the front of a train. We
            // also apply the signal limit a little in advance so that the train tries to stop
            // a bit before a signal.
            ChangePoint point(signal.first - SIGNAL_SPACE, ChangePoint::Application::DRIVER);

            // This will automatically clear the effect of any previous signal, if there was one
            // and it hasn't already been cleared
            point.actions.push_back(Action(Action::Type::CLEAR));

            // If the signal carries a speed limit then add it
            if(speed_limit < std::numeric_limits<double>::max())
              point.actions.push_back(Action(Action::Type::PUSH, speed_limit));

            ret.push_back(point);
        }
    }

    // Add all the end signal positions too
    std::vector<std::pair<double, Comms::Object>> end_signals = m_world_access.GetPathFeatures(
      path, m_end_signal_speed_watcher.GetMap(), 0.0);

    for (auto& end_signal : end_signals)
    {
        // Add each one that is active
        if (IsActive(end_signal.second))
        {
            // Note that end signal points apply to the whole train, as they are generally tied
            // to some rule like 'once the train has cleared the points'
            // Clear the effect of all signals
            ChangePoint point(end_signal.first);
            point.actions.push_back(Action(Action::Type::CLEAR));
            ret.push_back(point);
        }
    }

    // Sort these and return
    std::sort(
      ret.begin(), ret.end(), [](const ChangePoint& lhs, const ChangePoint& rhs) { return lhs.position < rhs.position; });

    return ret;
}

/// Helper function to register a feature type as being interesting to us, and also specifying
/// the category of speed limit type that it corresponds to by identifying the watcher that
/// should watch for it.
/// This performs necessary database queries and sets up internal records for later use.
///
/// @param feature_type The name of the feature type
/// @param active_state The name of the state that the feature must be in to be considered active
/// @param watcher_pair The watcher that should watch for this feature type, categorizing it
/// @param data_access  Access to the database, for any necessary queries

void SpeedLimitTracker::SetupFeatureType(const std::string&        feature_type,
                                         const std::string&        active_state,
                                         WatcherPair&              watcher_pair,
                                         Common::Data::DataAccess& data_access)
{
    // Resolve this to a feature id
    FeatureType             ft;
    Core::Database::Feature feature_access(data_access);
    ft.feature_type_id = feature_access.GetFeatureType(feature_type).feature_type_id;

    // Log if we couldn't find this and don't do anything else
    if (ft.feature_type_id == -1)
        Trace::GetLogger().STAMP(Trace::WARN)
          << "Could not find an ID for the feature type '" << feature_type << "'" << Trace::EndLog();
    else
    {
        // Resolve the state ID too. If this doesn't exist then the feature is always active.
        // If the active state is an empty string then there isn't one ... presumably this means
        // that the feature doesn't have a state. There is no point even trying to resolve this
        // in the database then.
        if (active_state.empty())
            ft.active_state = ALWAYS_ACTIVE;
        else
        {
            try
            {
                ft.active_state = feature_access.GetFeatureTypeState(ft.feature_type_id, active_state).feature_type_state_id;
            }
            catch (...)
            {
                ft.active_state = ALWAYS_ACTIVE;

                // Better log this, just in case it is an error
                Trace::GetLogger().STAMP(Trace::WARN) << "Could not find state: '" << active_state
                                                      << "' for feature type '" << feature_type << "'" << Trace::EndLog();
            }
        }

        // Store the watcher pair that this is associated with
        ft.watcher_pair = &watcher_pair;

        auto feature_type_states = feature_access.GetAllFeatureTypeStates();
        for (auto& feature_type_state : feature_type_states)
        {
            if (feature_type_state.feature_type_id == ft.feature_type_id)
                ft.feature_type_states[feature_type_state.feature_type_state_id] = feature_type_state.state_value;
        }

        // This type is ready to go into our map now
        m_feature_types[ft.feature_type_id] = ft;
    }
}

/// Helper functino to set up a watcher, which essentially involves determining all of the
/// feature types that it should watch for and setting it up to do so, using the filter, and
/// also specifying the request frequency.
///
/// @param watcher_pair      The watcher (and filter) to set up
/// @param request_frequency The frequency that the watcher should request for updates at

void SpeedLimitTracker::SetupWatcher(WatcherPair& watcher_pair, double request_frequency)
{
    // Run through all of our registered feature types to see who are interested in this watcher
    std::vector<int> feature_types;
    for (std::map<int, FeatureType>::const_iterator iter = m_feature_types.begin(); iter != m_feature_types.end(); ++iter)
    {
        if (iter->second.watcher_pair == &watcher_pair)
            feature_types.push_back(iter->second.feature_type_id);
    }

    // Set up our watcher and filter. What if there are no registered feature types? Previous
    // implementations chose this to mean that there is no filter, and thus the watcher is
    // interested in all feature types. However, this isn't very likely when considering a speed
    // limit tracker. True, the watcher pair probably shouldn't even be in use if it is not
    // interested in any features, but it is a real possibility that projects will use this sample
    // code and just comment out setup lines - they wouldn't be expecting that suddenly the watcher
    // would pick up all feature types! Additionally, if, for some reason, the feature type of
    // interest isn't present, or is temporarily unavaiable, we would want the feature watch to not
    // find any features, rather than all of them. Thus, we register the empty list of interesting
    // features regardless ...
    watcher_pair.filter.SetAcceptableTypes(feature_types);
    watcher_pair.watcher.SetFeatureTypeFilter(CreateFilterCallback(watcher_pair.filter));
    if (request_frequency >= 0.0)
        watcher_pair.watcher.SetRequestFrequency(request_frequency);
}

/// @param object The object to test to see if it is active
///
/// @return True if the object is active, which is if its state matches the predetermined
///         active state for that feature type, or if it doesn't have a state.

bool SpeedLimitTracker::IsActive(Comms::Object object) const
{
    // Firstly we need to know this feature's type
    std::map<int, FeatureType>::const_iterator iter = m_feature_types.find(GetFeatureType(object));

    // If we don't know about this feature type (which is some pretty major bustage,) then
    // ignore the feature
    if (iter == m_feature_types.end())
        return false;

    // We have a helper function that gets the state and compares against the active state
    return ::IsActive(object, iter->second.active_state);
}

/// @return The change points associated with two watcher that provide points for starting and
///         end speed reduction regions.

std::vector<ChangePoint> SpeedLimitTracker::GetRegionProfilePoints(const WorldAPI::SegmentPath&         path,
                                                                   WatcherPair&                         start_watcher,
                                                                   WatcherPair&                         end_watcher,
                                                                   std::function<bool(Comms::Object)>   is_start_active,
                                                                   std::function<bool(Comms::Object)>   is_end_active,
                                                                   std::function<double(Comms::Object)> get_speed_limit)
{
    std::vector<ChangePoint> ret;

    // Get the start positions for the limits
    std::vector<std::pair<double, Comms::Object>> start_limits = m_world_access.GetPathFeatures(path, start_watcher.GetMap(), 0.0);

    // Get the end positions for the limits
    std::vector<std::pair<double, Comms::Object>> end_limits = m_world_access.GetPathFeatures(path, end_watcher.GetMap(), 0.0);

    // Add in each independently, and then sort
    for (const auto& start_limit : start_limits)
    {
        if (is_start_active(start_limit.second))
        {
            // Simply pop the start of the region on, which allows us to nest them
            ChangePoint point(start_limit.first);
            point.actions.push_back(Action(Action::Type::PUSH, get_speed_limit(start_limit.second)));
            ret.push_back(point);
        }
    }

    for (const auto& end_limit : end_limits)
    {
        if (is_end_active(end_limit.second))
        {
            // We will allow the regions to be nested, so we will just pop off the last one.
            // We could alternatively pop them all off, or pop to some ID
            ChangePoint point(end_limit.first);
            point.actions.push_back(Action(Action::Type::POP));
            ret.push_back(point);
        }
    }

    // Sort these and return
    std::sort(
      ret.begin(), ret.end(), [](const ChangePoint& lhs, const ChangePoint& rhs) { return lhs.position < rhs.position; });
    return ret;
}

/// @return The changes that should be made to the current memory for a particular speed limit
///         type that deals with speed limits regions denoted by start and end features.

std::vector<Action> SpeedLimitTracker::GetRegionAdjustments(const WorldAPI::SegmentPath&         path,
                                                            const std::stack<Element>&           elements,
                                                            WatcherPair&                         start_watcher,
                                                            WatcherPair&                         end_watcher,
                                                            std::function<bool(Comms::Object)>   is_start_active,
                                                            std::function<bool(Comms::Object)>   is_end_active,
                                                            std::function<double(Comms::Object)> get_speed_limit)
{
    std::vector<Action> ret;

    // If we do not have any elements then possibly there was a limit behind us.
    // Actually, possibly there were many, nested, but we probably don't need to bother
    // implementing that until it actually proves to be an issue
    if (elements.empty())
    {
        std::vector<std::pair<double, Comms::Object>> start_limits = m_world_access.GetPathFeatures(
          path, start_watcher.GetMap(), -std::numeric_limits<double>::max(), 0.0);

        const auto closest_active_start_limit_behind_us = std::find_if(
          start_limits.crbegin(),
          start_limits.crend(),
          [is_start_active](const std::pair<double, Comms::Object>& distance_object_pair)
          { return is_start_active(distance_object_pair.second); });

        if (closest_active_start_limit_behind_us != start_limits.crend())
        {
            std::vector<std::pair<double, Comms::Object>> end_limits = m_world_access.GetPathFeatures(
              path, end_watcher.GetMap(), -std::numeric_limits<double>::max(), 0.0);

            const auto closest_active_end_limit_behind_us = std::find_if(
              end_limits.crbegin(),
              end_limits.crend(),
              [is_end_active](const std::pair<double, Comms::Object>& distance_object_pair)
              { return is_end_active(distance_object_pair.second); });

            if (closest_active_end_limit_behind_us == end_limits.crend() ||
                closest_active_end_limit_behind_us->first < closest_active_start_limit_behind_us->first)
            {
                ret.push_back(Action(Action::Type::PUSH, get_speed_limit(closest_active_start_limit_behind_us->second)));
            }
        }
    }

    return ret;
}

//  Function:       SpeedLimitTracker::PointsWatcherCallback
//
//  Description:    This is a callback registered with the points watcher. If we are called some
//                  points have presumable been created or destroyed. We mark our association map as
//                  needing to be refreshed.

void SpeedLimitTracker::PointsWatcherCallback(WorldAPI::FeatureWatcher::CallbackInfo info)
{
    // We will need to update the points association map
    m_points_association_refresh = true;
}

//  Function:       SpeedLimitTracker::GetPointsMap
//
//  Description:    This function is called to get the points association map, rather than accessing
//                  it directly, because here we check if it needs to be refreshed, and then do so
//                  if that is the case.

WorldAPI::PointsAssociationMap& SpeedLimitTracker::GetPointsMap()
{
    // Whilst I am touching this to make it thread-safe, I don't have time to make more wholesale
    // changes. If I did, I would consider removing this whole refresh concept, with a cached
    // TrackAssociationMap, since that is what FeatureWatcher provides now anyway. LAE 22/11/2016
    if (m_points_association_refresh)
    {
        m_points_association_refresh = false;
        m_points_association_map.Clear();
        m_points_association_map.AddPoints(Core::Locked<WorldAPI::PointsWatcher>(m_points_watcher)->GetObjects());
    }
    return m_points_association_map;
}

/// Helper function that retrieves the speed limit associated with the object. This will usually
/// be achieved by querying a particular property of the object.
///
/// @param object The object to get the associated speed limit for
///
/// @return The correspondig speed limit, in m/s

double SpeedLimitTracker::GetSpeedLimit(const Comms::Object& object)
{
    const std::string METRIC_LIMIT = "Metric Speed";

    // This is clearly inefficient, as we are going to resolve the Number ID EVERY TIME
    // This can be optimized by caching it, but that is a lot of caching and IDs to
    // remember and creations and destructions to monitor, so we will do it the simple way
    // first in an effort to avoid premature optimization.
    const Sim::Number::ID metric_limit_id = object.Numbers().Info().GetID(METRIC_LIMIT);

    // If this object doesn't have this property we're going to use its state instead
    if (metric_limit_id != Sim::INVALID_NUMBER)
    {
        // Use the store instead of the library, allowing for the speed limit to change!
        return object.Numbers().Store().Get(metric_limit_id).value;
    }

    return GetSpeedLimitFromState(object);
}

/// A helper to get the speed limit from a TSR Board, which is defined by its state.
/// @return The speed limit, in m/s, or std::numeric_limits<double>::max()
///         if the speed cannot be determined.
/// @pre tsr_feature_object is valid.
/// @pre Ownership of the Comms mutex.
double SpeedLimitTracker::GetSpeedLimitFromState(const Comms::Object& object)
{
    assert(object.IsValid());

    const auto feature_type_id  = Project::GetTypeOfObject(object);
    const auto feature_state_id = static_cast<int>(Project::GetStateOfObject(object));

    if ((feature_type_id != INVALID_TYPE) && (feature_state_id != INVALID_STATE))
    {
        auto feature_type = m_feature_types.find(feature_type_id);
        if (feature_type != m_feature_types.end())
        {
            auto feature_type_states = feature_type->second.feature_type_states;
            auto feature_value       = feature_type_states.find(feature_state_id);
            if (feature_value != feature_type_states.end())
            {
                return feature_value->second;
            }
        }
    }

    return std::numeric_limits<double>::max();
}
