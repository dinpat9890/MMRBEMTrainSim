///
/// @file       SpeedLimitUnit.cpp
///
///             Defines the SpeedLimitUnit class.
///
/// @ingroup    Core Train Sim
///
/// @author     Luke Errington
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2015
///

#include "SpeedLimitUnit.h"

#include "core_types/SessionData.h"

#include "Project/Utilities/ScenarioTrainLengthService.h"

#include "train_types/ScenarioTrainSelector.h"
#include "train_data_access/TrainDataAccess.h"
#include "train_data_access/TrainDataAccessTypes.h"

#include "Protobuf/CBTCOnboard.pb.h"
#include "Project/Utilities/IsLeadVehicle.h"

#include "train_comms_structure/TrainObjectConstants.h"
#include "train_comms_structure/TrainObjectDefinition.h"
#include "train_serialisation/speed_limits.pb.h"

#include "project_comms_structure\ProjectObjectConstants.h"

#include "utility/Utilities.h"
#include "world_api/TrainPathWatcher.h"

#include <cstring>
#include <functional> 

namespace
{
    // Note that while the request frequency is used by the TrainPathWatcher, we don't use it in
    // any of this Unit's own code because it doesn't request.
    // We own the speed limit object, and the other objects that we are interested in ... the
    // vehicle positions, the feature positions and states, the point states, etc are all
    // requested by the watchers that we are using (and the SpeedLimitTracker).
    // In replay we won't be running, so we don't care that ownership changes then.
    const double REQUEST_FREQUENCY = 1.0;
    const double UPDATE_FREQUENCY  = 20.0;

    const double INVALID_DISTANCE = -1.0;

    const bool DEBUG = false;

    /// Helper function to make the serialization using protobuf syntactically nicer, although it
    /// is a little expensive to be copying data around like this. Serialization could be done
    /// directly into the vector if required in the future.
    ///
    /// @param s The string to convert into a Raw, probably produced by protobuf
    ///
    /// @return The corresponding byte array, to use within a raw

    Sim::Raw::Type StringToRaw(const std::string &s)
    {
        if(!s.empty())
            return Sim::Raw::Type(reinterpret_cast<const unsigned char *>(&*s.begin()), reinterpret_cast<const unsigned char *>(&*s.begin()) + s.size());
        return Sim::Raw::Type();
    }

    /// Helper function that determines if two doubles (which will likely be distances or speed
    /// limits) are equal.
    ///
    /// @param a The first double to compare
    /// @param b The second double to compare
    ///
    /// @return True if the two values are sufficiently close to be considered equal

    inline bool Equal(double a, double b)
    {
        const double EPSILON = 1E-4;
        return fabs(a - b) < EPSILON;
    }

    /// Attempts to extract a scenario train ID from an object.
    ///
    /// @param The object to query.
    ///
    /// @return The object's scenario train ID, or -1 if it doesn't have one.
    ///
    /// @pre The object is valid.

    int GetScenarioTrainID(Comms::Object object)
    {
        assert(object.IsValid());

        // We're going to make a couple of assumptions. Firstly, that the value of the Train tag
        // on a simulated train is the same as that on an automatic train.
        // (As an aside, it would be really nice to statically assert this.)
        assert(std::strcmp(Train::ValueName::Train::TRAIN, Train::ValueName::AutoTrain::TRAIN) == 0);

        // Same deal with the name of the Scenario Train ID identifier.
        assert(std::strcmp(Train::ValueName::Train::SCENARIO_TRAIN_ID, Train::ValueName::AutoTrain::SCENARIO_TRAIN_ID) == 0);

        // Now the slightly scary one: we're going to assume that a Train tag indicates the
        // existence of a Scenario Train ID identifier. This is not guaranteed by the current
        // system, but hopefully will be in the future.
        assert(!object.Statics().Tags().Exists(Train::ValueName::Train::TRAIN) ||
               (object.Statics().Tags().Exists(Train::ValueName::Train::TRAIN) && object.Statics().Identifiers().Exists(Train::ValueName::Train::SCENARIO_TRAIN_ID)));

        return object.Statics().Tags().Exists(Train::ValueName::Train::TRAIN) ? object.Statics().Identifiers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID) : -1;
    }

    /// Helper function that applies a single change to a speed limit factor
    ///
    /// @param elements The elements of the speed limit factor, to be modified in place
    /// @param action   The change to apply

    void ApplyAction(std::stack<Train::SpeedLimits::Element> &elements, const Train::SpeedLimits::Action &action)
    {
        switch(action.type)
        {
        case Train::SpeedLimits::Action::Type::PUSH:
            elements.push(action.data);
            break;

        case Train::SpeedLimits::Action::Type::POP:
            if(!elements.empty())
                elements.pop();
            break;

        case Train::SpeedLimits::Action::Type::POP_ID:
            while(!elements.empty() && elements.top().id != action.data.id)
                elements.pop();
            if(!elements.empty())
                elements.pop();
            break;

        case Train::SpeedLimits::Action::Type::CLEAR:
            while(!elements.empty())
                elements.pop();
            break;
        }
    }

    /// Helper function that applies a set of changes to a speed limit factor.
    ///
    /// @param elements The elements of the speed limit factor, modified in-place
    /// @param actions  The changes to make

    void ApplyActions(std::stack<Train::SpeedLimits::Element> &elements, const std::vector<Train::SpeedLimits::Action> &actions)
    {
        for(const auto &action : actions)
            ApplyAction(elements, action);
    }

    /// Calculate the Length of a Path from the start offset to the End of the last segment.
    ///
    /// @param world_access   Gives Access to Segments
    /// @param path           The Path to work with
    ///
    /// @return               The Path length or -1 if its Looped
    ///
    double CalculatePathLength(WorldAPI::WorldAccess &world_access, WorldAPI::SegmentPath &path)
    {
        double distance = INVALID_DISTANCE;

        // Path is not Looping - Hopefully this will not happen in CrossRail?
        if (path.norepeat_end_index == -1)
        {
            int start_index;
            int end_index;

            // Get distance from path position to end of the first segment - The Segment orientation determines the way its calculated
            if (!path.segments[path.start_index].from_alpha)
                distance = path.start_offset;
            else
                distance = world_access.GetSegmentGeometry(path.segments[path.start_index].id).GetSegmentLength() - path.start_offset;

            start_index = path.start_index + 1;
            end_index = path.segments.size();


            // Add the Full length of the remaining segments on the Path
            for (int i = start_index; i < end_index; ++i)
                distance += world_access.GetSegmentGeometry(path.segments[i].id).GetSegmentLength();
        }

        return distance;
    }
}

/// Constructor, which remembers references to the necessary resources, configuration properties,
/// and hooks up a root callback so that we can watch for all trains.
///
/// @param gateway        The Gateway to use to have access to Comms
/// @param world_access   The WorldAccess object to use
/// @param points_watcher The PointsWatcher to use to monitor points state, in determining path
/// @param simulator_data The simulator data to use, used to determine the train length
/// @param speed_limits   The speed limit tracker to use, provided by the project
/// @param max_limit      The maximum speed limit to use, particularly when there are no other
///                       speed-limiting features on the path

SpeedLimitUnit::SpeedLimitUnit(Comms::Gateway                       &gateway,
                               WorldAPI::WorldAccess                &world_access,
                               WorldAPI::PointsWatcher              &points_watcher,
                               Common::DataAccess                   &data_access,
                               SpeedLimitCBTCConfig                 &speed_limits,
                               double max_limit)
  : Comms::SteppingUnit(gateway), m_world_access(world_access), m_points_watcher(points_watcher), m_limits(speed_limits), m_max_limit(max_limit),
    m_train_length_service(new ScenarioTrainLengthService(gateway.GetScenarioData<Core::BaseScenarioData>().data.scenario_id, Train::Database::Train(data_access)))
{
    // Call the speed limits objects and configure ourselves with our factors
    m_limit_types      = speed_limits.GetSpeedLimitTypes();
    m_cbtc_limit_types = speed_limits.GetCBTCSpeedLimitTypes();

    // We want to look for every train that is in the world, and place a speed limit object on its
    // lead vehicle. There is no helper that finds all trains, so we will just look for them
    // ourselves.
    {
        const OS::Lock<Comms::Gateway> lock(GetGateway());

        // Need to set the request frequency in order for the points state's to be updated correctly within the unit.
        // PointsWatcher resource has a bug and point change notification fails if request frequency isnt set
        // within the unit
        m_points_watcher.SetRequestFrequency(REQUEST_FREQUENCY);

        AddCreationCallback(GetGateway().GetRootObject(), MakeCallback(&SpeedLimitUnit::RootChildCreated, this));
    }
}

/// Destructor, which just cleans up resources.

SpeedLimitUnit::~SpeedLimitUnit()
{
    // Remove the root callback so it is no longer called
    {
        const OS::Lock<Comms::Gateway> lock(GetGateway());

        // We have ownership of some memory which we should clean up. It is best to do this with
        // the comms lock too as they could be responsible for being called back by comms (although
        // we shouldn't be being destroyed unless the session has ended, in which case this
        // shouldn't really happen).
        for(std::map<Comms::Object, SpeedLimitInfo>::iterator iter = m_trains.begin(); iter != m_trains.end(); ++iter)
            delete iter->second.path_watcher;
    }
}

/// Called regularly (but not frequently) this runs through all known trains and updates their
/// speed limit information in Comms, if required.
///
/// @param new_time The simulation time that this cycle corresponds to

void SpeedLimitUnit::Step(double new_time)
{
    // Make sure that comms is locked as we are about to inspect objects
    const OS::Lock<Comms::Gateway> lock(GetGateway());

    // The rest of the work is to be done here. Other implementations may like to work on change,
    // but we will just be dumb and cyclically calculate the speed limit profile for all trains
    // that we know about.
    for(std::map<Comms::Object, SpeedLimitInfo>::iterator iter = m_trains.begin(); iter != m_trains.end(); ++iter)
    {
        assert(iter->first.IsValid());
        assert(iter->second.path_watcher);

        // Patch off to the SpeedLimitInfo's Update function which does all of our work. We need
        // to lock its path watcher before doing so, to simulate a call from the path watcher.
        std::lock_guard<WorldAPI::PathWatcher> path_watcher_lock(*iter->second.path_watcher);

        // Trigger the reporting of the speed data to the CBTC Onboard at the required rate
        iter->second.Update();
    }
}

/// @return The period that RunCycle() should be called at

double SpeedLimitUnit::GetPeriod() const
{
    return 1.0 / UPDATE_FREQUENCY;
}

/// Called when a child of the root is created, we are looking for the world object to drill down
/// this tree.
///
/// @param object The newly created object.

void SpeedLimitUnit::RootChildCreated(Comms::Object object)
{
    // If this is the world then we are interested in following it
    if(Core::GetClassID(object) == Train::ClassID::WORLD)
        AddCreationCallback(object, MakeCallback(&SpeedLimitUnit::WorldChildCreated, this));
}

/// Called when a child of the world object is created, we are looking for any train that we can
/// find to drill down further (and also create the SpeedLimit object under each train).
///
/// @param object The newly created object.

void SpeedLimitUnit::WorldChildCreated(Comms::Object object)
{
    // If this is the train then we have a few things to do
    const int class_id = Core::GetClassID(object);

    // The Speed Limit Unit must function differently for CBTC (simulated trains) compared to auto-trains.
    // CBTC must completely ignore traffic light signals but respond to changes in all other signals.
    // Auto Trains also respond to traffic light signals by automatically coming to a stop when signal is retrictive.
    if (class_id == Train::ClassID::TRAIN)
    {
        InitTrainObject(object, m_cbtc_limit_types, true);
    }
    else if (class_id == Train::ClassID::AUTO_TRAIN)
    {
        InitTrainObject(object, m_limit_types, false);
    }
}

void SpeedLimitUnit::InitTrainObject(Comms::Object object, const SpeedLimitTypes& speed_limit_types, const bool is_simulated)
{
    // Firstly, we need to register for further object creations (as we are about to create an
    // object.
    AddCreationCallback(object, MakeCallback(&SpeedLimitUnit::TrainChildCreated, this));

    // Add a dummy LocatedElements for each type, back an -max().
    SpeedLimitInfo::LocatedElements le;
    le.position            = -std::numeric_limits<double>::max();
    le.applicable_position = -std::numeric_limits<double>::max();

    // Next, we need to create a train path watcher on this train so that we can quickly
    // calculate the path.
    SpeedLimitInfo new_info;
    new_info.is_simulated            = is_simulated;
    new_info.speed_limit_types       = &speed_limit_types;
    new_info.path_watcher            = new WorldAPI::TrainPathWatcher(m_world_access, m_points_watcher, REQUEST_FREQUENCY, object);
    new_info.unit                    = this;
    new_info.limit_number.id         = Sim::INVALID_NUMBER;
    new_info.max_allowable_number.id = Sim::INVALID_NUMBER;
    new_info.profile_raw.id          = Sim::INVALID_RAW;
    new_info.cbtc_profile_raw.id     = Sim::INVALID_RAW;

    new_info.conceptual_position     = 0.0;
    new_info.m_train_length = m_train_length_service->GetTrainLength(GetScenarioTrainID(object));
    new_info.last_profile.resize(speed_limit_types.size(), std::vector<SpeedLimitInfo::LocatedElements>(1, le));
    m_trains[object] = new_info;

    // Because we just created a train watcher and associated it with this object, and we can't
    // listen on the train watcher for destruction of the train, we will have to listen for it
    // ourselves.
    AddDestructionCallback(object, MakeCallback(&SpeedLimitUnit::TrainDestroyed, this));

    // Now register for the Update() function of this SpeedLimitInfo to be called back whenever
    // the route changes. We have to make sure that it is in its final resting place in memory
    // before doing this! Because we are using a map that is fine.
    // Now, whenever the route changes, we will be called to update, which will adjust this
    // profile. Normally the route won't update too much, but it will particularly at startup
    // - which is what we want. This ensures that even before the simulator has started
    // running that the profile will be correct.
    // It is possible that the route will be complete before we see the SpeedLimit object in
    // Comms (as it is yet to be created). We handle that by doing a forced update when we
    // see our SpeedLimit object.
    std::map<Comms::Object, SpeedLimitInfo>::iterator new_iter = m_trains.find(object);
    {
        std::lock_guard<WorldAPI::PathWatcher> path_watcher_lock(*new_iter->second.path_watcher);
        new_iter->second.path_watcher->AddRouteChangeCallback(MakeCallback(&SpeedLimitInfo::RouteUpdate, &new_iter->second));
    }

    // Finally, we need to create the speed limit object. There is currently only one per train,
    // and we calculate speed limits for presumed forward motion.
    Sim::ObjectDefinition obj_def = Train::GetObjectDefinition(Train::ClassID::SPEED_LIMIT);

    // Set up the Raw to hold an empty list, for the moment, until we start processing
    // The moment that we see this object created we will hook up for route callbacks, which
    // will result in us populating this properly (before we start running).
    // It is hard to get the initial value correct because we don't have a vehicle object nor
    // a track position, so we don't know where the train is.
    obj_def.SetRawInitial(Train::ValueName::SpeedLimit::SPEED_LIMIT_PROFILE, StringToRaw(""));

    // Create the object
    object.CreateChild(obj_def);
}


/// Called when a child of a train object is created, we are looking for the Speed Limit object that
/// we created, so that we can remember details about it (and hook up callbacks so that we start
/// populating it).
///
/// @param object The newly created object.

void SpeedLimitUnit::TrainChildCreated(Comms::Object object)
{
    // If this is our speed limit object then we just want to remember it (and also watch for it
    // being destroyed)
    const int class_id = Core::GetClassID(object);
    if(class_id == Train::ClassID::SPEED_LIMIT)
    {
        assert(m_trains.find(object.GetParent()) != m_trains.end());

        // Watch for the destruction
        AddDestructionCallback(object, MakeCallback(&SpeedLimitUnit::SpeedLimitDestroyed, this));

        // Find the train object that we have created this under. There is no way that we can not
        // know about our parent (unless it was destroyed and we saw that before we see this
        // creation ... which is a serious issue in comms!).
        SpeedLimitInfo &this_info = m_trains.find(object.GetParent())->second;
        this_info.speed_limit_object = object;

        // Resolve the IDs
        this_info.limit_number.id         = object.Numbers().Info().GetID(Train::ValueName::SpeedLimit::SPEED_LIMIT);
        this_info.max_allowable_number.id = object.Numbers().Info().GetID(Train::ValueName::SpeedLimit::MAX_ALLOWABLE_SPEED);
        this_info.profile_raw.id          = object.Raws().Info().GetID(Train::ValueName::SpeedLimit::SPEED_LIMIT_PROFILE);

        // Get the default values
        if(this_info.limit_number.id != Sim::INVALID_NUMBER)
            this_info.limit_number.value         = object.Numbers().Info().GetInfo(this_info.limit_number.id).initial;
        if(this_info.max_allowable_number.id != Sim::INVALID_NUMBER)
            this_info.max_allowable_number.value = object.Numbers().Info().GetInfo(this_info.max_allowable_number.id).initial;

        // Make sure that we update this speed limit object with the correct profile for what we
        // know of the path. This is particularly critical if the route is complete and will not
        // change again (and we consequently won't get a notification).
        // Yes, we are setting the values on an object immediately on seeing it in construction, but
        // I can't see that this will be a problem in this case. (We don't listen for properties
        // changing on it ourselves, so there is no feedback.)
        // (If there is a problem then the desired speed limit profile needs to be stored even
        // before we have a speed limit object, and applied when the speed limit object is first
        // seen.)
        std::map<Comms::Object, SpeedLimitInfo>::iterator new_iter = m_trains.find(object.GetParent());

        std::lock_guard<WorldAPI::PathWatcher> path_watcher_lock(*new_iter->second.path_watcher);
        new_iter->second.Update();
    }
    else if (class_id == Train::ClassID::VEHICLE)
    {
        if (Sim::Project::IsLeadVehicle(object))
        {
            // Listen for the creation of lead vehicle child objects
            AddCreationCallback(object, MakeCallback(&SpeedLimitUnit::VehicleChildCreated, this));
        }
    }
}

///
/// @param object The newly created object.

void SpeedLimitUnit::VehicleChildCreated(Comms::Object object)
{
    // If this is our speed limit object then we just want to remember it (and also watch for it
    // being destroyed)
    const int class_id = Core::GetClassID(object);
    if (class_id == Project::ClassID::CBTC_ONBOARD_INPUTS)
    {
        assert(m_trains.find(object.GetParent().GetParent()) != m_trains.end());

        // Watch for the destruction
        AddDestructionCallback(object, MakeCallback(&SpeedLimitUnit::CBTCSpeedLimitDestroyed, this));

        SpeedLimitInfo &this_info = m_trains.find(object.GetParent().GetParent())->second;
        this_info.cbtc_speed_limit_object = object;

        // Resolve the CBTC Speed Limit Profile ID
        this_info.cbtc_profile_raw.id = object.Raws().Info().GetID(Project::ValueName::CBTCOnboardInputs::SPEED_LIMIT_DATA);
    }
}
/// Called when a train object is destroyed, we want to remove all memory of it.
///
/// @paramm object The object that is about to be destroyed

void SpeedLimitUnit::TrainDestroyed(Comms::Object object)
{
    assert(m_trains.find(object) != m_trains.end());
    assert(!m_trains.find(object)->second.speed_limit_object.IsValid());

    // It is a serious thing if we do not know of this train (despite having registered a
    // destruction callback on it!
    delete m_trains.find(object)->second.path_watcher;
    m_trains.erase(object);
}

/// Called when a Speed Limit object is destroyed, we want to remove all memory of it.
///
/// @paramm object The object that is about to be destroyed

void SpeedLimitUnit::SpeedLimitDestroyed(Comms::Object object)
{
    assert(m_trains.find(object.GetParent()) != m_trains.end());
    assert(m_trains.find(object.GetParent())->second.speed_limit_object.IsValid());

    // Look for the parent and invalidate our understanding of all speed limit objects
    m_trains.find(object.GetParent())->second.speed_limit_object.Invalidate();
}

/// Called when a CBTC Speed Limit object is destroyed, we want to remove all memory of it.
///
/// @paramm object The object that is about to be destroyed

void SpeedLimitUnit::CBTCSpeedLimitDestroyed(Comms::Object object)
{
    assert(m_trains.find(object.GetParent().GetParent()) != m_trains.end());
    assert(m_trains.find(object.GetParent().GetParent())->second.cbtc_speed_limit_object.IsValid());

    // Look for the parent and invalidate our understanding of all speed limit objects
    m_trains.find(object.GetParent().GetParent())->second.cbtc_speed_limit_object.Invalidate();
}


/// This is the work horse function. When called it will calculate the speed limit information (for
/// both the Numbers and the Raw) and populate them as necessary (if they have changed) for the
/// train that this SpeedLimitInfo object belongs to.

void SpeedLimitUnit::SpeedLimitInfo::RouteUpdate()
{
    this->Update();
}

/// This is the work horse function. When called it will calculate the speed limit information (for
/// both the Numbers and the Raw) and populate them as necessary (if they have changed) for the
/// train that this SpeedLimitInfo object belongs to.

void SpeedLimitUnit::SpeedLimitInfo::Update()
{
    // It is required that we have the comms lock on entry into this function, and also that we have
    // the path watcher locked, since we may actually be called by a callback from the path watcher.

    // Don't bother looking at this unless we have a valid train and speed limit object. (It
    // shouldn't be possible for the train to be invalid though.
    if(speed_limit_object.IsValid())
    {
        // Build up the profiles to serialize
        Core::SpeedLimitList speed_limit_list;
        // CBTC needs to handle some speed limits differently that the default.
        // eg. CBTC should ignore traffic light controlled signals. Even when they change to retrictive (red), the CBTC system should ignore them
        // because CBTC is not integrated with the traffic light controllers in any way - the 2 systems are independent.
        // The SpeedLimitInfo::speed_limit_types holds different speed limit information from the SpeedLimitTracker
        // depending upon whether we're processing simulated/Auto trains.
        //
        // The speed_limit_list & cbtc_speed_limit_list are updated for both types of trains,
        // - speed_limit_list is used in general (eg. from auto trains)
        // - cbtc_speed_limit_list is only used by the cbtc system on simulated trains
        CBTC::Protos::SpeedLimitList cbtc_speed_limit_list;


        // Check if we have a path. If we don't have a path then the speed limit profile is as
        // if we have no track left.
        if(path_watcher->HasPath())
        {
            // Work out how far we have travelled. We can then look into our last profile to work
            // out where we sit for each element. This allows us to advance past speed limit change
            // points that we will no longer pick up. This allows us to actually go back through our
            // states too!
            if(path_watcher->HasPath() && !last_path.segments.empty())
            {
                const WorldAPI::SegmentPosition current_position = path_watcher->GetPosition();
                const WorldAPI::SegmentPosition last_position    = { last_path.segments[last_path.start_index].id, last_path.start_offset, last_path.segments[last_path.start_index].from_alpha };

                // Try and find this position on our previous path. If not then it would appear
                // that some points ahead of us switched and we have moved on to the new segment
                double distance_moved = 0.0;
                if(unit->m_world_access.IsPositionOnPath(last_path, current_position))
                    distance_moved = unit->m_world_access.GetPathPosition(last_path, current_position).first;
                // ... in which case the old position should be on our current path
                else if(unit->m_world_access.IsPositionOnPath(path_watcher->GetExtendedPath(), last_position))
                    distance_moved = -unit->m_world_access.GetPathPosition(path_watcher->GetExtendedPath(), last_position).first;
                else
                    // Oooh. Hyperspace! Well, not necessarily ... there is a possibility that
                    // through quick movement through a series of appropriate configured points
                    // that are then changed behind the train (which is going to be awkward as
                    // trains have length) this could be achieved.
                    // We could handle this through faster updating, or through also considering
                    // the odometer change of the train (which would avoid the need to do the
                    // above work), or even through a dedicated watcher to watch the passing of
                    // features.
                    // For the moment, though, we will just log
                    Trace::GetLogger().STAMP(Trace::WARN) << "Train " << GetScenarioTrainID(speed_limit_object.GetParent()) << " appears to have hyperspaced - can't determine if speed limits were passed." << Trace::EndLog();

                // Update our conceptual distance
                conceptual_position += distance_moved;
            }

            // For the moment we can now handle each limit type independently.
            //  * Run through and find the last change point. This may correspond to the last
            //      feature passed. It will not necessarily be the applicable point. However, we
            //      need to look for the last one that is behind or equal to us, as this one is our
            //      current state. If we have, for instance, passed and end curve board, then we
            //      will speed up once our rear has passed that board, and it applies even though it
            //      is no longer in front of us.
            // * Get the state for that change point
            // * Query the limit type for any adjustments that need to be made. If there are some
            //      then they are applied at the current position and a new change point is created.
            //      If the existing change point is at the current position too then that is
            //      overwritten.
            // * Cull all forward change points
            // * Query the limit type for any change points that are ahead of us
            // * Run through these and turn them into a forward profile, appending to our existing
            //      profile. This involves adding the current conceptual position too.
            // * Remember this profile for the next cycle.

            // Each limit type is going to want to know the scenario train ID, so we'll
            // grab it before we start iterating.
            const auto scenario_train_id = GetScenarioTrainID(path_watcher->GetTrainObject());

            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::INFO) << "type_profile (" << conceptual_position << ")\n==========================\n";

            // As we go we can build up the next change iterators for each type (as an index).
            std::vector<size_t> current_indices(speed_limit_types->size(), 0);
            for(size_t i = 0; i < last_profile.size(); ++i)
            {
                auto &type_profile = last_profile[i];

                // Hopefully there aren't too many entries and we can find the current through a
                // linear search. Otherwise we do have a binary search available to us as it is
                // sorted.
                auto current_iter = std::find_if(type_profile.begin(), type_profile.end(), [this](const LocatedElements &e) { return e.position > conceptual_position; });

                // There will always be at least one LocatedElements, behind us, and we have found
                // the first position above us, so we can always step back one.
                --current_iter;

                // Get the adjustments for this state
                const auto adjustments = speed_limit_types->at(i)->GetAdjustments(path_watcher->GetExtendedPath(), current_iter->elements, scenario_train_id);
                if(!adjustments.empty())
                {
                    // Either create a new point, or add update the existing one
                    if(Equal(current_iter->position, conceptual_position))
                        ApplyActions(current_iter->elements, adjustments);
                    else
                    {
                        // Adjustments are always applied at the current position
                        LocatedElements le;
                        le.position            = conceptual_position;
                        le.applicable_position = conceptual_position;
                        le.elements            = current_iter->elements;
                        ApplyActions(le.elements, adjustments);

                        // Insert this into our list and update our iterator
                        current_iter = type_profile.insert(current_iter + 1, le);
                    }
                }

                // Set the current position index for this type. Do this now before the iterator is
                // invalidate, not for the following erase, but for all the pushing back that may
                // later occur as we apply the change points
                current_indices[i] = std::distance(type_profile.begin(), current_iter);

                // Cull any forward change points as we are going to overwrite them
                type_profile.erase(current_iter + 1, type_profile.end());

                // Determine the change points ahead of us
                auto changes = speed_limit_types->at(i)->GetProfilePoints(path_watcher->GetExtendedPath(), scenario_train_id);

                // Run through these and add them to our profile. 
                auto current_elements = current_iter->elements;
                auto current_limit = current_elements.empty() ? unit->m_max_limit : current_elements.top().speed;
                for(auto &change : changes)
                {
                    // Modify according to the current conceptual position
                    change.position += conceptual_position;

                    // Apply the changes to our current elements and save off
                    ApplyActions(current_elements, change.actions);

                    // Start to create the LocatedElements
                    LocatedElements new_le;
                    new_le.position            = change.position;
                    new_le.applicable_position = change.position;
                    new_le.elements            = current_elements;

                    // To apply the train-based limits we need to know the speed limit at the change point. This is not
                    // necessarily the speed limit of the prior change point, because that may have a different
                    // applicable location. Actually, the current speed limit is the speed limit at the change point
                    // with the applicable location which is closest to us (but behind us). It is unfortunate that usage
                    // of this will be O(n^2). Optimisation is not simple, so I will use this until it proves to be a
                    // problem.
                    const auto calc_current_limit = [](const std::vector<LocatedElements> &this_profile, double position, double max_limit)
                    {
                        double best_position = -std::numeric_limits<double>::max();
                        double best_limit    = max_limit;
                        for (const auto &cp : this_profile)
                        {
                            // This is our best yet if it is closer to us, but not ahead of us
                            if ((cp.applicable_position >= best_position) && (cp.applicable_position <= position) && !cp.elements.empty())
                            {
                                best_position = cp.applicable_position;
                                best_limit    = cp.elements.empty() ? max_limit : cp.elements.top().speed;
                            }
                        }

                        return best_limit;
                    };

                    // The applicable position depends on the change type. If it applies to the
                    // whole train, and the speed limit is increasing, then we need to push it out
                    // by the length of the train so that we do not accelerate until our rear is
                    // past this point.
                    const auto new_limit = current_elements.empty() ? unit->m_max_limit : current_elements.top().speed;
                    if (change.application == Train::SpeedLimits::ChangePoint::Application::TRAIN)
                    {
                        // Note that we need to use >= when comparing speed limits here since if we don't the additional train length will stop
                        // being addded as soon as the train passes the speed sign and the train will never step up to the new speed.
                        if (new_limit >= current_limit)
                            new_le.applicable_position += m_train_length;

                        if (DEBUG)
                            Trace::GetLogger().STAMP(Trace::INFO) << "(1) m_train_length " << new_limit << " >= " << current_limit << "\n";
                    }

                    // Update our current limit for the next iteration
                    current_limit = new_limit;

                    if (DEBUG)
                        Trace::GetLogger().STAMP(Trace::INFO) << "   => push_back (" << new_le.position << ", " << new_le.applicable_position
                        << ", " << new_le.elements.top().speed
                        << ") - (" << current_limit << " -> " << new_limit << ")\n";

                    // Add this as a new located element
                    type_profile.push_back(new_le);
                }
            }

            // With the current position indices can we can immediately work out the current line
            // limit, which doesn't care about applicable position.
            double line_limit = unit->m_max_limit;
            for(size_t i = 0; i < last_profile.size(); ++i)
            {
                // Only consider if this type contributes to the line limit, and we have some
                // elements at the current position
                if (speed_limit_types->at(i)->IsLineLimit() && !last_profile[i][current_indices[i]].elements.empty())
                    line_limit = std::min(line_limit, last_profile[i][current_indices[i]].elements.top().speed);
            }

            // Now that we have the current located profile for each type, we need to turn this into
            // a forward profile.
            // * Run backwards for each type, back to our current position, and remove any whose
            //      applicable distance is greater than the one after it.
            // * Run forwards, with all indices at the same time, for all types, continually picking
            //      off the next applicable distance, determining the allowable speed, and adding to
            //      the profile. This run occurs from the very start, in case their are change
            //      positions behind us with applicable positions ahead of us.
            for(auto &type_profile : last_profile)
            {
                for(size_t index = type_profile.size() - 1; index > 0; --index)
                {
                    // If we are here we are guaranteed that there is a profile point before us.
                    // Check that it should not be applied after us. If it should then we will
                    // remove it.
                    if (type_profile[index - 1].applicable_position >= type_profile[index].applicable_position)
                        type_profile.erase(type_profile.begin() + (index - 1));
                }
            }

            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::INFO) << Trace::EndLog();

            // Now we run forwards and determine the entire allowable speed profile, for the whole
            // path. We really only need to do this as far back as there is an applicable position
            // ahead of us (and then one behind that, for each type, to get the current allowable
            // speed). That all gets a bit complex though - so just do it from the start!
            std::vector<std::vector<LocatedElements>::const_iterator> iters;
            for(auto &type_profile : last_profile)
                iters.push_back(type_profile.begin());

            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::INFO) << "List of Profile Points\n==========================\n";

            // Keep advancing until there is no 'next position'
            std::vector<std::pair<double, double>> profile;
            while(true)
            {
                // Find the next position as the lowest of all of the next iters
                double this_position = std::numeric_limits<double>::max();
                for(size_t i = 0; i < iters.size(); ++i)
                {
                    if ((iters[i] + 1) != last_profile[i].end())
                        this_position = std::min(this_position, (iters[i] + 1)->applicable_position);
                }

                // If we couldn't find the next position, probably because our change iterators
                // are all at their end, then we have finished applying the changes.
                if (this_position == std::numeric_limits<double>::max())
                    break;

                if (DEBUG)
                    Trace::GetLogger().STAMP(Trace::INFO) << this_position << ", ";

                // Run through the speed limits according to all of our current located elements to
                // determine the allowable speed for this position
                double this_limit = unit->m_max_limit;
                for(size_t i = 0; i < iters.size(); ++i)
                {
                    // Advance this if the next position is this applicable position
                    if(((iters[i] + 1) != last_profile[i].end()) && Equal((iters[i] + 1)->applicable_position, this_position))
                        ++iters[i];

                    // Now use wherever this is pointing to contribute to the allowable speed
                    if(!iters[i]->elements.empty())
                        this_limit = std::min(this_limit, iters[i]->elements.top().speed);
                }

                // We have determined the speed limit for this position, so add it to our profile
                profile.push_back(std::make_pair(this_position, this_limit));
                if (DEBUG)
                    Trace::GetLogger().STAMP(Trace::INFO) << "," << this_limit << "\n";
            }
            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::INFO) << " Total = " << profile.size() << Trace::EndLog();

            // Now that we have the profile, we can determine the maximum allowable speed for the
            // current position.
            auto max_allowable_speed = unit->m_max_limit;
            auto profile_index       = std::distance(profile.begin(), std::find_if(profile.begin(), profile.end(), [this](const std::pair<double, double> &e) { return e.first > conceptual_position; }));
            if(profile_index > 0)
                max_allowable_speed = profile[profile_index - 1].second;

            // Turn the profile into something based around our current position (0 offset)
            for(auto &p : profile)
                p.first -= conceptual_position;

            // Add a 0 limit at the end of the track.
            WorldAPI::SegmentPath path = path_watcher->GetPath();
            if(path.norepeat_end_index == -1)
            {
                // Run through from the current location on the path to the end to determine how
                // much track we have ahead of us. Note that we are not using the extended path so
                // we will pick up when we hit the rear of points that aren't switched in our
                // direction.
                double end_distance = path.segments[path.start_index].from_alpha ? (unit->m_world_access.GetSegmentGeometry(path.segments[path.start_index].id).GetSegmentLength() - path.start_offset) : path.start_offset;
                for(size_t i = path.start_index + 1; i < path.segments.size(); ++i)
                    end_distance += unit->m_world_access.GetSegmentGeometry(path.segments[i].id).GetSegmentLength();

                // Inject a 0 speed limit at this distance
                profile.push_back(std::pair<double, double>(end_distance, 0.0));
            }

            // Then we have to reduce the duplicates in this list
            if(!profile.empty())
            {
                std::vector<std::pair<double, double>> reduced_profile(1, profile.front());
                for(size_t i = 1; i < profile.size(); ++i)
                {
                    if(!Equal(profile[i].second, reduced_profile.back().second))
                        reduced_profile.push_back(profile[i]);
                }

                profile.swap(reduced_profile);
            }

            // Add a 0 limit at the end of the track.
            // Note that this must happen after the duplicates have been removed. This is due to the fact that when the change
            // position is set to train it results in an item being inserted into the profile causing the profile items to no
            // longer be sorted. By removing duplicates it returns the profile back into a sorted state.
            {
                WorldAPI::SegmentPath path = path_watcher->GetPath();
                auto end_distance = CalculatePathLength(unit->m_world_access, path);

                if (end_distance != INVALID_DISTANCE)
                {
                    // Need to keep the profile sorted by position so insert a 0 speed limit at the given distance
                    std::vector<std::pair<double, double> >::iterator start_iter = std::upper_bound(profile.begin(), profile.end(), std::pair<double, double>(end_distance, end_distance));
                    profile.insert(start_iter, std::pair<double, double>(end_distance, 0.0));
                }
                else
                    Trace::GetLogger().STAMP(Trace::ERR) << "Failed to calculate distance to the end of the track" << Trace::EndLog();
            }

            // Cull all speed limits prior to (and including) our current position
            std::vector<std::pair<double, double> >::iterator start_iter = std::upper_bound(profile.begin(), profile.end(), std::pair<double, double>(0.0, 0.0));
            profile.erase(profile.begin(), start_iter);

            // Then we cull all speed limits ahead of the lead vehicle that are past the first
            // limit of 0.
            for(std::vector<std::pair<double, double>>::iterator cull_iter = profile.begin(); cull_iter != profile.end(); ++cull_iter)
            {
                if(cull_iter->second <= 0.0)
                {
                    profile.erase(cull_iter + 1, profile.end());
                    break;
                }
            }

            // We know everything to set our Numbers, if we need to
            if(!Equal(limit_number.value, line_limit) || !Equal(max_allowable_number.value, max_allowable_speed))
            {
                limit_number.value         = line_limit;
                max_allowable_number.value = max_allowable_speed;

                Sim::Number numbers_to_set[2] = { limit_number, max_allowable_number };
                speed_limit_object.Numbers().Store().Set(&numbers_to_set[0], &numbers_to_set[0] + 2);
            }

            // Now we know everything necessary to populate our speed limit object.
            speed_limit_list.set_start_speed(max_allowable_speed);

            // Add all of the limits
            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR) << " Speed Profile\n==========================\n";
            for(size_t i = 0; i < profile.size(); ++i)
            {
                Core::SpeedLimitList_SpeedLimit *new_limit = speed_limit_list.add_speed_limits();
                new_limit->set_distance(profile[i].first);
                new_limit->set_speed(profile[i].second);
                if (DEBUG)
                    Trace::GetLogger().STAMP(Trace::ERR) << " (" << profile[i].first << "," << profile[i].second << ") ";

                // Update the CBTC speed limit profile
                CBTC::Protos::SpeedLimitList_SpeedLimit *new_cbtc_limit = cbtc_speed_limit_list.add_speed_limits();
                new_cbtc_limit->set_distance(profile[i].first);
                new_cbtc_limit->set_speed(profile[i].second);
            }
            if (DEBUG)
                Trace::GetLogger().STAMP(Trace::ERR) << "\n" << Trace::EndLog();

            // Update the understanding of where the train was at when the profile was created
            speed_limit_list.set_start_segment(path_watcher->GetPosition().id);
            speed_limit_list.set_start_offset(path_watcher->GetPosition().offset);
            speed_limit_list.set_start_heading(path_watcher->GetPosition().from_alpha);

            // Update for our next cycle
            last_path = path_watcher->GetExtendedPath();
        }
        else
        {
            // Just add a zero speed entry in the list, at where we are
            Core::SpeedLimitList_SpeedLimit *new_limit = speed_limit_list.add_speed_limits();
            new_limit->set_distance(0.0);
            new_limit->set_speed(0.0);

            CBTC::Protos::SpeedLimitList_SpeedLimit *new_cbtc_limit = cbtc_speed_limit_list.add_speed_limits();
            new_cbtc_limit->set_distance(0.0);
            new_cbtc_limit->set_speed(0.0);

            // The start speed limit is whatever it was previously
            speed_limit_list.set_start_speed(max_allowable_number.value);

            // We don't really have a valid start segment, offset and heading. We could use what
            // it previously was, but we don't remember that (at the moment). If necessary, we
            // can rememmber that. Of course, to not have a position means that the train is
            // not on the track, so the speed profile should not be useful anyway. Possibly it
            // would help with potential timing issues regarding when different modules see the
            // track position object get destroyed.
            speed_limit_list.set_start_segment(-1);
            speed_limit_list.set_start_offset(0.0);
            speed_limit_list.set_start_heading(true);
        }


        // Update this Raw if it has changed. We can't do the Raw and the Numbers atomically at
        // the moment, hence why we do the Raw here and the Numbers elsewhere.
        Sim::Raw::Type new_value = StringToRaw(speed_limit_list.SerializeAsString());
        if((new_value != profile_raw.value) && (profile_raw.id != Sim::INVALID_RAW))
        {
            profile_raw.value = new_value;
            speed_limit_object.Raws().Store().Set(profile_raw);
        }

        // Set the CBTC Speed limit object data if the object exists
        if (cbtc_speed_limit_object.IsValid())
        {
            cbtc_speed_limit_list.set_reference_train_position(conceptual_position);
            cbtc_speed_limit_list.set_current_speed_limit(max_allowable_number.value);           
            
            Sim::Raw::Type new_value = StringToRaw(cbtc_speed_limit_list.SerializeAsString());
            if ((new_value != cbtc_profile_raw.value) && (cbtc_profile_raw.id != Sim::INVALID_RAW))
            {
                cbtc_profile_raw.value = new_value;
                cbtc_speed_limit_object.Raws().Store().Set(cbtc_profile_raw);
            }
        }
    }

}

