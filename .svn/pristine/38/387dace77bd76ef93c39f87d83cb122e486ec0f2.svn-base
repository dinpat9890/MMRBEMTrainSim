//******************************************************************************
//
//  File:           PlatformPassengersUnit.cpp
//
//  Description:    Defines the PlatformPassengersUnit class.
//
//  Reference:      Chiltern Train Sim
//
//  Author:         Luke Errington
//
//  (C) Copyright:  SYDAC Pty Ltd, 2006
//
//******************************************************************************

#include "PlatformPassengersUnit.h"
#include "PlatformPassengersProperties.h"
#include "Utility/Utilities.h"
#include "common/DataAccess.h"
#include "common/StandardLogging.h"
#include "core_data_access/Feature.h"
#include "core_types/SessionData.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "project_comms_structure/ProjectObjectDefinition.h"
#include "project_features/ProjectFeatureConstants.h"
#include "train_data_access/TrainDataAccess.h"
#include "common/DataAccessExceptions.h"
#include <cassert>

namespace
{
    const double REQUEST_FREQ = 20.0;
    const double PERIOD       = 1.0;

    // Constants for our animation states. These must be shared with the vision,
    // which will need to understand, use and modify these states. This makes
    // this not seem likely the ideal place to store the constants, but I'm not
    // convinced that putting them in the database is worth it.
    const int ANIM_IDLE      = 0;
    const int ANIM_MOVING    = 1;
    const int ANIM_MOVED     = 2;
    const int ANIM_RESETTING = 3;

    const char* DOOR_POSTION_NAMES[] = {Project::ValueName::VehicleOutputs::LEFT_DOOR_1_POSITION,
                                        Project::ValueName::VehicleOutputs::LEFT_DOOR_2_POSITION,
                                        Project::ValueName::VehicleOutputs::LEFT_DOOR_3_POSITION,
                                        Project::ValueName::VehicleOutputs::LEFT_DOOR_4_POSITION,
                                        Project::ValueName::VehicleOutputs::RIGHT_DOOR_1_POSITION,
                                        Project::ValueName::VehicleOutputs::RIGHT_DOOR_2_POSITION, 
                                        Project::ValueName::VehicleOutputs::RIGHT_DOOR_3_POSITION, 
                                        Project::ValueName::VehicleOutputs::RIGHT_DOOR_4_POSITION};

    constexpr auto AreScreenDoorsOpen(const double percentage_open)
    {
        return percentage_open > 50.0;
    }
}

namespace Project::FeatureProperties
{
    constexpr auto DOOR_POSITION{"Door Position"};
    constexpr auto PLATFORM_FEATURE_ID{"Platform Feature ID"};
}

//  Function:       PlatformPassengersUnit::PlatformPassengersUnit
//
//  Description:    Constructor Here we populate a few pieces of information
//                  from the database for later use. We also set up our points
//                  watcher which we will use for determine the path of trains
//                  later on (as trains are created).
//
//  Parameters:
//      Comms::Gateway &gateway - The gateway to use.
//      Sydac::Data::DataAccess &data_access - Access to the database.
//      WorldAPI::WorldAccess &world_access - The world access object to use.
//      Project::PlatformPassengerProperties &properties - The properties of this unit.

PlatformPassengersUnit::PlatformPassengersUnit(Comms::Gateway&                    gateway,
                                               Common::Data::DataAccess&          data_access,
                                               WorldAPI::WorldAccess&             world_access,
                                               const PlatformPassengerProperties& properties)
  : Comms::SteppingUnit(gateway), m_world_access(world_access), m_properties(properties), m_num_platforms(-1)
{
    const auto& scenario_data = gateway.GetScenarioData<Core::BaseScenarioData>().data;

    // There is some work we need to do involving data access. We don't watch
    // for exceptions though, because if any of these commands fail we really
    // can't do our job anyway.

    // Firstly populate, our points watcher
    m_points_watcher.SetAcceptableTypes(data_access);

    // Also determines the type IDs for the feature types that we are
    // interested in.
    try
    {
        const Core::Database::Feature feature{data_access};

        m_passengers_type_id = feature.GetFeatureType(Project::FeatureTypes::PLATFORM_PASSENGER).feature_type_id;
        m_platform_type_id   = feature.GetFeatureType(Project::FeatureTypes::PLATFORM).feature_type_id;

        m_platform_screen_doors_type_ids.emplace(
            feature.GetFeatureType(Project::FeatureTypes::FETY_PSD).feature_type_id);

        // Establish train lengths
        std::vector<Train::Data::ScenarioTrain> scenario_trains =
          Train::Database::Train(data_access).GetScenarioTrains(scenario_data.scenario_id);

        Common::Data::CachingByID<std::vector<Train::Data::TrainElement>, Train::Database::Train, &Train::Database::Train::GetTrainElements> train_elements_cache(
          data_access);
        for (std::vector<Train::Data::ScenarioTrain>::const_iterator i = scenario_trains.begin(); i != scenario_trains.end(); ++i)
        {
            const std::vector<Train::Data::TrainElement>& te = train_elements_cache(i->train_id);

            double train_length = 0.0;
            for (size_t ii = 0; ii < te.size(); ++ii)
                train_length += te[ii].length;
            m_train_lengths.insert(std::make_pair(i->scenario_train_id, train_length));
            m_stopped.insert(std::make_pair(i->scenario_train_id, false));
        }

        // Our points watcher also needs to be attached to the root object
        {
            const OS::Lock<Comms::Gateway> COMMS_LOCK(GetGateway());
            m_points_watcher.Attach(GetGateway().GetRootObject());

            // Register our own interest too!
            AddCreationCallback(GetGateway().GetRootObject(),
                                std::bind(&PlatformPassengersUnit::ObjectCreated, this, std::placeholders::_1));
        }
    }
    catch (CommonException& e)
    {
        Trace::GetLogger().STAMP(Trace::WARN) << e.what() << ".\nPlatform passengers will not be functional." << Trace::EndLog();
        m_passengers_type_id = m_platform_type_id = -1;
    }
}

//  Function:       PlatformPassengersUnit::~PlatformPassengersUnit
//
//  Description:    Destructor. Some objects need to be detached from comms, and
//                  possibly destroyed, under the comms mutex.

PlatformPassengersUnit::~PlatformPassengersUnit()
{
    // m_passengers_type_id is set to -1 in the constructor if passenger or platform features are not available.
    // In this case, the points watcher and callbacks are not hooked up, and m_trains will be empty.
    if (m_passengers_type_id != -1)
    {
        const OS::Lock<Comms::Gateway> COMMS_LOCK(GetGateway());

        // We need to destroy all of our train path watchers that we still have
        // hanging around.
        for (size_t i = 0; i < m_trains.size(); ++i)
            delete m_trains[i];

        // With these gone we also need to detach our points watcher.
        m_points_watcher.Detach();
    }
}

/// This is the workhouse function as there is no internal state within the unit. It runs completely
/// off the exposed comms state on a cyclic basis. We determine the platforms that each train is
/// parked at, or approaching, and thus work out the desired state of each train's doors, along with
/// the animation state of each passenger. These properties are then set as appropriate.
///
/// @param new_time The time this cycle corresponds to.

void PlatformPassengersUnit::Step(double new_time)
{
    // Get the comms lock
    const OS::Lock<Comms::Gateway> COMMS_LOCK(GetGateway());

    // Protect our own variables from being changed by comms callbacks
    const auto our_lock = Lock();

    // As we run through each train we determine the state of the platforms.
    // It would be nice to use an enum here, but we couldn't template on it.
    const int        CLEAR    = 0;
    const int        IN_RANGE = 1;
    const int        BOARDING = 2;
    std::vector<int> passenger_states(m_animation_states.size(), CLEAR);
    std::vector<int> passenger_trains(m_animation_states.size(), 0);

    // We also need to track what we want to the doors of each train
    const int DONT_CARE   = 0;
    const int OPEN_DOORS  = 1;
    const int CLOSE_DOORS = 2;

    // Run through each train that we are watching
    // Bear in mind that the train may have since been destroyed so we also
    // have to check if we should remove the watcher
    for (std::vector<WorldAPI::TrainPathWatcher*>::iterator iter = m_trains.begin(); iter != m_trains.end();)
    {
        const auto train_object = (*iter)->GetTrainObject();

        if (train_object.IsValid())
        {
            int scenario_train_id = static_cast<int>(
              train_object.Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value);

            // We also need to check if this train has a path. We just ignore
            // it if it doesn't yet have one.
            std::lock_guard<WorldAPI::TrainPathWatcher> path_watcher_lock(**iter);
            if ((*iter)->HasPath())
            {
                const double PARKING_THRESHOLD    = m_properties.GetParkingThreshold();
                const double IN_RANGE_THRESHOLD   = m_properties.GetInRangeThreshold();
                const double STATIONARY_THRESHOLD = m_properties.GetStationarySpeedThreshold();

                // Of a platform
                const std::string LENGTH_PROPERTY = "Length";
                const double      DEFAULT_LENGTH  = m_properties.GetDefaultPlatformLength();

                // We may need to know the train's speed
                Sim::Number::ID speed_num_id = train_object.Numbers().Info().GetID(Project::ValueName::Train::LLO_LEAD_LOCO_SPEED);
                double speed = (speed_num_id != Sim::INVALID_NUMBER) ? train_object.Numbers().Store().Get(speed_num_id).value : 0.0;

                // Get the path for this train
                WorldAPI::SegmentPath path = (*iter)->GetPath();

                // Prepare a vector of all known platform passengers. We will
                // definitely use this in the future.
                std::vector<Comms::Object> passengers;
                for (size_t j = 0; j < m_animation_states.size(); ++j)
                    passengers.push_back(m_animation_states[j].GetParent());

                // Determine where our platforms lie on this path. We only need
                // to test for those within our parking threshold. For
                // approaching we only need to test passengers, not platforms.
                // Therefore, we don't need to do any of this if we are not
                // stationary.
                if (std::abs(speed) < STATIONARY_THRESHOLD)
                {
                    bool just_stopped = false;
                    if (!m_stopped[scenario_train_id])
                    {
                        just_stopped                 = true;
                        m_stopped[scenario_train_id] = true;
                        Trace::GetLogger().STAMP(Trace::VERBOSE)
                          << "Train ID : " << scenario_train_id << " just stopped" << Trace::EndLog();
                    }

                    std::vector<std::pair<double, Comms::Object>> path_platforms = m_world_access.GetPathFeatures(
                      path, m_platforms, true, false, -PARKING_THRESHOLD - 200.0, PARKING_THRESHOLD);
                    int num_platforms = static_cast<int>(path_platforms.size());
                    if (m_num_platforms != num_platforms)
                    {
                        Trace::GetLogger().STAMP(Trace::VERBOSE)
                          << num_platforms << " platform" << (num_platforms != 1 ? "s" : "") << " in range."
                          << Trace::EndLog();
                        m_num_platforms = num_platforms;
                    }

                    // Find number of open doors
                    int open_door_count = 0;
                    for (const auto& train_child : train_object)
                    {
                        const auto train_child_class_id = Core::GetClassID(train_child);
                        if (train_child_class_id == Train::ClassID::VEHICLE)
                        {
                            const auto vehicle_object = train_child;
                            for (auto& vehicle_child : vehicle_object)
                            {
                                const auto vehicle_child_class_id = Core::GetClassID(vehicle_child);
                                if (vehicle_child_class_id == Train::ClassID::VEHICLE_OUTPUTS)
                                {
                                    const auto vehicle_outputs_object = vehicle_child;

                                    const auto MIN_DOO_OPEN_POSITION = 0.25;

                                    for (const auto door_position_name : DOOR_POSTION_NAMES)
                                        open_door_count += vehicle_outputs_object.Numbers().Get(door_position_name).value > MIN_DOO_OPEN_POSITION
                                                             ? 1
                                                             : 0;
                                }
                            }
                        }
                    }

                    for (size_t i = 0; i < path_platforms.size(); ++i)
                    {
                        const auto& platform_object{path_platforms[i].second};

                        {
                            // Check for any platform screen doors, and only continue
                            // if they are open.
                            assert(platform_object.Numbers().Info().GetID(Core::ValueName::Feature::FEATURE_ID) != Sim::INVALID_NUMBER);
                            const auto platform_feature_id{static_cast<int>(platform_object.Numbers().Get(Core::ValueName::Feature::FEATURE_ID).value)};

                            if (const auto map_iterator{m_platform_feature_id_to_screen_doors_open.find(platform_feature_id)};
                                map_iterator != std::cend(m_platform_feature_id_to_screen_doors_open))
                            {
                                const auto screen_doors_closed{!map_iterator->second};
                                if (screen_doors_closed)
                                    continue;
                            }
                        }

                        // Now check that we line up with the platform. We can
                        // do this by using the length property of the platform.
                        Sim::Number::ID length_num_id = platform_object.Numbers().Info().GetID(LENGTH_PROPERTY);
                        double          length        = (length_num_id != Sim::INVALID_NUMBER)
                                          ? platform_object.Numbers().Info().GetInfo(length_num_id).initial
                                          : DEFAULT_LENGTH;

                        // Note: There is some inconsistency in the numbers, so we apply a safety
                        //       factor.
                        length *= 2.0;

                        double train_length = m_train_lengths[scenario_train_id];

                        if (just_stopped)
                            Trace::GetLogger().STAMP(Trace::VERBOSE)
                              << "Platform " << path_platforms[i].second.GetName() << " Length = " << length
                              << " At Offset " << path_platforms[i].first << Trace::EndLog();

                        // Confirm that the entire train is within the platform length, or else
                        // doors would open to oblivion.
                        if ((path_platforms[i].first > (-0.5 * length)) && (path_platforms[i].first + train_length < (0.5 * length)))
                        {
                            if (just_stopped)
                                Trace::GetLogger().STAMP(Trace::VERBOSE)
                                  << "Train is Stopped at Platform " << platform_object.GetName() << Trace::EndLog();

                            // So we have parked at this platform! Now determine
                            // what side of us the platform is on.
                            if (!(*iter)->GetVehicleObjects().empty() &&
                                WorldAPI::HasTrackPosition((*iter)->GetVehicleObjects().front()))
                            {
                                // The Function below that creates a Vector to calculate the Side that a Platform
                                // feature is on has a flaw. If the Platform is Curved and Long enough and the Offset of
                                // the Platform to the Left or Right is Small enough then the algorithm can get the side
                                // incorrect. Instead of calculating the Side from the Position of the Train when
                                // Stopped after the platform, we advance the position back (or forward) to the Platform
                                // Get the Position of the train on the path as if it was reversed (Or forwarded) to the
                                // Platform. Use the Advance function to move the Segment Position by that distance
                                // (Which we know from the path_platforms) NB! The Path was obtained from the
                                // TrainPathWatcher so its Index is at the Trains Current Position!
                                WorldAPI::SegmentPosition train_platform_position;

                                m_world_access.Advance(path, path_platforms[i].first, train_platform_position);
                                WorldAPI::Placement train_placement = m_world_access.GetTrackPosition(train_platform_position);

                                WorldAPI::Placement platform_placement = m_world_access.GetFeaturePosition(
                                  path_platforms[i].second);

                                // We can determine if it is on the LHS use some
                                // simple geometry ...
                                // Given a line segment P0(x0,y0) to P1(x1,y1)
                                // and a point P(x,y) compute
                                //   result = (y-y0)(x1-x0)-(x-x0)(y1-y0)
                                // If result < 0, P is on LHS of line

                                // This comes from the cross-product. If it is
                                // greater than 0 then angle < 180 degrees.
                                // Note that the length of P0P1 isn't really
                                // important so we can just use the heading
                                // returned in the placement information.
                                bool lhs = ((platform_placement.position.y - train_placement.position.y) *
                                              train_placement.heading.x -
                                            (platform_placement.position.x - train_placement.position.x) *
                                              train_placement.heading.y) > 0.0;

                                if (just_stopped)
                                    Trace::GetLogger().STAMP(Trace::VERBOSE)
                                      << "Platform " << path_platforms[i].second.GetName() << " is on the "
                                      << (lhs ? "left" : "right") << " hand side." << Trace::EndLog();

                                std::vector<std::pair<double, Comms::Object>> path_passengers = m_world_access.GetPathFeatures(
                                  path,
                                  passengers,
                                  true,
                                  false,
                                  path_platforms[i].first - length / 2.0,
                                  path_platforms[i].first + length / 2.0);

                                if (just_stopped)
                                    Trace::GetLogger().STAMP(Trace::VERBOSE)
                                      << "Platform " << path_platforms[i].second.GetName() << " Has "
                                      << path_passengers.size() << " Passengers to process" << Trace::EndLog();
                                
                                for (size_t j = 0; j < path_passengers.size(); ++j)
                                {
                                    // If this passenger is on the same side as the platform then mark it to be
                                    // boarding.
                                    WorldAPI::Placement passenger_placement = m_world_access.GetFeaturePosition(
                                      path_passengers[j].second);
                                    bool this_lhs = ((passenger_placement.position.y - train_placement.position.y) *
                                                       train_placement.heading.x -
                                                     (passenger_placement.position.x - train_placement.position.x) *
                                                       train_placement.heading.y) > 0.0;

                                    if (just_stopped)
                                        Trace::GetLogger().STAMP(Trace::VERBOSE)
                                          << "Passenger " << path_passengers[j].second.GetName() << " is on the "
                                          << (this_lhs ? "left" : "right") << " hand side." << Trace::EndLog();

                                    if (lhs == this_lhs && open_door_count > 0)
                                    {
                                        // Find the passenger in our list and
                                        // set the desired state.
                                        std::vector<Comms::Object>::iterator pass_iter = std::find(
                                          passengers.begin(), passengers.end(), path_passengers[j].second);
                                        assert(pass_iter != passengers.end());

                                        passenger_states[pass_iter - passengers.begin()] = BOARDING;
                                        passenger_trains[pass_iter - passengers.begin()] = scenario_train_id;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (m_stopped[scenario_train_id])
                    {
                        m_stopped[scenario_train_id] = false;
                        Trace::GetLogger().STAMP(Trace::VERBOSE)
                          << "Train ID : " << scenario_train_id << " just started moving " << Trace::EndLog();
                    }
                }

                auto& path_passengers = m_world_access.GetPathFeatures(path, passengers, true, false, -IN_RANGE_THRESHOLD, IN_RANGE_THRESHOLD);
                if (!path_passengers.empty())
                {
                    auto feature_id_id = path_passengers.back().second.Numbers().Info().GetID(Project::ValueName::Feature::FEATURE_ID);
                    if (feature_id_id != Sim::INVALID_NUMBER)
                    {
                        for (size_t i = 0; i < passengers.size(); ++i)
                        {
                            for (const auto& path_passenger : path_passengers)
                            {
                                if (path_passenger.second.Numbers().Store().Get(feature_id_id).value ==
                                    passengers[i].Numbers().Store().Get(feature_id_id).value)
                                {
                                    if (passenger_states[i] != BOARDING)
                                    {
                                        passenger_states[i] = IN_RANGE;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // Increment the iterator. This isn't done as part of the for loop
            // construct because we may instead erase this iterator (below).
            ++iter;
        }
        else
        {
            // The train has since been destroyed, so we need to remove this
            // watcher.
            delete *iter;
            iter = m_trains.erase(iter);
        }
    }

    // So, at this point we have considered all trains and we have the desired
    // door states for each train, and the desired passenger states for all
    // passengers on our paths. By default we don't care about any other
    // passengers so CLEAR is an appropriate state.

    // Now we need to run through all of our platform passenger objects, or
    // rather, their animation states, and determine if we need to change their
    // state.
    // Instead of packaging all of the sets temporally together (although they
    // have to be made individually on individual objects) we just make the sets
    // as necessary as we own the objects so they will occur immediately.
    for (size_t i = 0; i < m_animation_states.size(); ++i)
    {
        // Determine the current state of this passenger
        Sim::Number::ID anim_state_num_id = m_animation_states[i].Numbers().Info().GetID(
          Project::ValueName::PlatformPassengerAnimation::STATE);
        assert(anim_state_num_id != Sim::INVALID_NUMBER);

        int anim_state     = static_cast<int>(m_animation_states[i].Numbers().Store().Get(anim_state_num_id).value);
        int new_anim_state = anim_state;
        switch (anim_state)
        {
        case ANIM_IDLE:
            // If idle then the passengers can stay that way unless they now
            // need to board a train, in which case they need to change state.
            if (passenger_states[i] == BOARDING)
                new_anim_state = ANIM_MOVING;
            break;

        case ANIM_MOVING:
        case ANIM_MOVED:
            // If our state is MOVING, or MOVED, but analysis shows that there
            // is no stationary train at the platform then we should be
            // resetting.
            if (passenger_states[i] == CLEAR)
                new_anim_state = ANIM_RESETTING;
            break;

        case ANIM_RESETTING:
            // If we are resetting we don't switch back to IDLE until the last
            // possible moment, which will be when a train is approaching or
            // boarding.
            if (passenger_states[i] == CLEAR)
                new_anim_state = ANIM_IDLE;
            break;

        default:
            Trace::GetLogger().STAMP(Trace::WARN) << "Platform passenger found in unknown animation state!" << Trace::EndLog();
        }

        if (anim_state != new_anim_state)
        {
            int scenario_train_id = passenger_trains[i];
            if (new_anim_state == ANIM_IDLE)
                scenario_train_id = 0;

            Sim::Number::ID scenario_train_id_id = m_animation_states[i].Numbers().Info().GetID(
              Project::ValueName::PlatformPassengerAnimation::SCENARIO_TRAIN_ID);

            std::vector<Sim::Number> numbers;
            numbers.push_back(Sim::Number(new_anim_state, anim_state_num_id));
            numbers.push_back(Sim::Number(scenario_train_id, scenario_train_id_id));
            m_animation_states[i].Numbers().Store().Set(numbers.begin(), numbers.end());
        }
    }
}

/// Queries the period that the Step() function should be run at.
///
/// @return The desired period of processing, in seconds.

double PlatformPassengersUnit::GetPeriod() const
{
    return PERIOD;
}

//  Function:       PlatformPassengersUnit::ObjectCreated
//
//  Description:    This is the callback we register whenever we are interested
//                  in the creation of objects. We are interested in the World
//                  object, certain types of feature objects, the platform
//                  passengers animation state object that we create, and train
//                  objects. This generally involves registering for more
//                  creation callbacks, some destruction callbacks, and setting
//                  up member variables so that RunCycke processes correctly.
//
//  Parameters:
//      Comms::Object object - The object being created.

void PlatformPassengersUnit::ObjectCreated(Comms::Object object)
{
    const auto our_lock = Lock();

    // Determine the class of this object
    int class_id = Core::GetClassID(object);
    if (class_id == Project::ClassID::WORLD)
        AddCreationCallback(object, std::bind(&PlatformPassengersUnit::ObjectCreated, this, std::placeholders::_1));
    else if (class_id == Project::ClassID::FEATURES)
        AddCreationCallback(object, std::bind(&PlatformPassengersUnit::ObjectCreated, this, std::placeholders::_1));

    // If this is a train then we need to create a train watcher for it
    else if (class_id == Project::ClassID::TRAIN)
    {
        m_trains.push_back(new WorldAPI::TrainPathWatcher(m_world_access, m_points_watcher, REQUEST_FREQ, object));

        // Since we are considering this train we will need to know what
        // it's speed is.
        Sim::RequestInfo<Sim::Number> request_info;
        request_info.id = object.Numbers().Info().GetID(Project::ValueName::Train::LLO_LEAD_LOCO_SPEED);
        if (request_info.id != Sim::INVALID_NUMBER)
        {
            request_info.delta = object.Numbers().Info().GetInfo(request_info.id).delta;
            object.Numbers().Store().Request(request_info, REQUEST_FREQ);
        }
        request_info.id = object.Numbers().Info().GetID(Project::ValueName::Train::LLO_LEAD_LOCO_POSITION);
        if (request_info.id != Sim::INVALID_NUMBER)
        {
            request_info.delta = object.Numbers().Info().GetInfo(request_info.id).delta;
            object.Numbers().Store().Request(request_info, REQUEST_FREQ);
        }

        AddCreationCallback(object, std::bind(&PlatformPassengersUnit::ObjectCreated, this, std::placeholders::_1));
    }
    else if (class_id == Project::ClassID::VEHICLE)
    {
        AddCreationCallback(object, std::bind(&PlatformPassengersUnit::ObjectCreated, this, std::placeholders::_1));
    }
    else if (class_id == Project::ClassID::VEHICLE_OUTPUTS)
    {
        for (const auto door_position_name : DOOR_POSTION_NAMES)
        {
            const auto door_number_id = object.Numbers().Info().GetID(door_position_name);
            if (door_number_id != Sim::INVALID_NUMBER)
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(door_number_id), REQUEST_FREQ);
        }
    }

    // There are some features that we are interested in
    else if (class_id == Project::ClassID::FEATURE)
    {
        // Determine the type of the feature
        Sim::Number::ID feature_type_id = object.Numbers().Info().GetID(Project::ValueName::Feature::TYPE);
        if (feature_type_id != Sim::INVALID_NUMBER)
        {
            int feature_type = static_cast<int>(object.Numbers().Store().Get(feature_type_id).value);

            // If this is a platform we just want to remember it, and register
            // for destruction so we can stop remembering it.
            if (feature_type == m_platform_type_id)
            {
                m_platforms.push_back(object);
                AddDestructionCallback(object, std::bind(&PlatformPassengersUnit::PlatformDestroyed, this, std::placeholders::_1));
            }

            // If this is a platform passengers feature we want to add the
            // animation state as a child, and register for child creation.
            else if (feature_type == m_passengers_type_id)
            {
                object.CreateChild(Project::GetObjectDefinition(Project::ClassID::PLATFORM_PASSENGER_ANIMATION));
                AddCreationCallback(object, std::bind(&PlatformPassengersUnit::ObjectCreated, this, std::placeholders::_1));
            }
            else
            {
                if (const auto is_platform_screen_doors_feature{
                        m_platform_screen_doors_type_ids.find(feature_type) != std::cend(m_platform_screen_doors_type_ids)})
                {
                    // Find the ID of the associated platform.
                    const auto platform_feature_id_number_id{object.Numbers().Info().GetID(Project::FeatureProperties::PLATFORM_FEATURE_ID)};
                    if (platform_feature_id_number_id != Sim::INVALID_NUMBER)
                    {
                        const auto platform_feature_id{static_cast<int>(object.Numbers().Store().Get(platform_feature_id_number_id).value)};
                        
                        // We're going to assume there's only one set of screen doors per platform.
                        assert(m_platform_feature_id_to_screen_doors_open.find(platform_feature_id) == std::cend(m_platform_feature_id_to_screen_doors_open));

                        // Now look for the number that specifies how much the doors are open.
                        const auto door_position_number_id{object.Numbers().Info().GetID(Project::FeatureProperties::DOOR_POSITION)};
                        if (door_position_number_id != Sim::INVALID_NUMBER)
                        {
                            object.Numbers().Store().Request(
                                object.Numbers().Info().GetInfo(door_position_number_id),
                                REQUEST_FREQ);

                            // Get the initial state.
                            m_platform_feature_id_to_screen_doors_open.emplace(
                                platform_feature_id,
                                AreScreenDoorsOpen(object.Numbers().Store().Get(door_position_number_id)));

                            // Listen to changes in the door state.
                            Comms::AddIndividualListener(
                                object.Numbers().Store(),
                                [this, door_position_number_id, platform_feature_id](const auto& number)
                                {
                                    if (number.id == door_position_number_id)
                                    {
                                        std::scoped_lock lock{*this};
                                        m_platform_feature_id_to_screen_doors_open[platform_feature_id] = AreScreenDoorsOpen(number);
                                    }
                                });

                            Comms::AddDestructionCallback(
                                object,
                                [this, platform_feature_id](const auto object)
                                {
                                    std::scoped_lock lock{*this};
                                    m_platform_feature_id_to_screen_doors_open.erase(platform_feature_id);
                                });

                            Trace::GetLogger().STAMP(Trace::VERBOSE)
                                << "Discovered platform screen door feature "
                                << object.GetName()
                                << "." << Trace::EndLog();
                        }
                        else
                        {
                            Trace::GetLogger().STAMP(Trace::ERR)
                                << "Feature " << object.GetName()
                                << " is missing required property "
                                << Project::FeatureProperties::DOOR_POSITION
                                << "." << Trace::EndLog();
                        }
                    }
                    else
                    {
                        Trace::GetLogger().STAMP(Trace::ERR)
                            << "Feature " << object.GetName()
                            << " is missing required property "
                            << Project::FeatureProperties::PLATFORM_FEATURE_ID
                            << "." << Trace::EndLog();
                    }
                }
            }
        }
    }

    // The final object type we are interested in is our animation state,
    // which we also want to keep a list of these objects for.
    else if (class_id == Project::ClassID::PLATFORM_PASSENGER_ANIMATION)
    {
        // We want to track all of these, for cyclic processing. This means that
        // we need to watch for their destruction too (to stop using them).
        m_animation_states.push_back(object);
        AddDestructionCallback(object, std::bind(&PlatformPassengersUnit::AnimationStateDestroyed, this, std::placeholders::_1));
    }
}

//  Function:       PlatformPassengersUnit::PlatformDestroyed
//
//  Description:    Called specifically when a platform feature object is
//                  destroyed. We remove this from our vector and the next time
//                  that RunCycle is called it will handle this seamlessly.
//
//  Parameters:
//      Comms::Object object - The object being destroyed.

void PlatformPassengersUnit::PlatformDestroyed(Comms::Object object)
{
    const auto our_lock = Lock();

    // Something is wrong if we don't know about this object
    assert(std::find(m_platforms.begin(), m_platforms.end(), object) != m_platforms.end());

    // Simply remove this entry from our vector
    m_platforms.erase(std::find(m_platforms.begin(), m_platforms.end(), object));
}

//  Function:       PlatformPassengersUnit::AnimationStateDestroyed
//
//  Description:    Called specifically when a passenger animation state object
//                  is destroyed. As we own these this will typically only be at
//                  the end of a session. However, RunCycle could still be being
//                  called so we need to remove this object from our vector so
//                  that RunCycle doesn't try to use it.
//
//  Parameters:
//      Comms::Object object - The object being destroyed.

void PlatformPassengersUnit::AnimationStateDestroyed(Comms::Object object)
{
    const auto our_lock = Lock();

    // Something is wrong if we don't know about this object
    assert(std::find(m_animation_states.begin(), m_animation_states.end(), object) != m_animation_states.end());

    // Simply remove this entry from our vector
    m_animation_states.erase(std::find(m_animation_states.begin(), m_animation_states.end(), object));
}
