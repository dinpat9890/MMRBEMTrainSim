///**************************************************************************************************
/// @file         LMAUnit.cpp
///
/// Description : Unit for 
///
/// @author       Adam Zielinski
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2016
///**************************************************************************************************

#include "LMAUnit.h"

#include "core_types/SessionData.h"

#include <train_data_access/TrainDataAccess.h>

#include "Project/Utilities/ScenarioTrainLengthService.h"
#include "Project/Utilities/IsLeadVehicle.h"

#include "project_comms_structure/ProjectObjectConstants.h"
#include "core_comms_structure/CoreObjectConstants.h"

#include "Utility/Utilities.h"

#include "common/StandardLogging.h"

using namespace LMA;
using namespace FeatureInterfaces;

namespace
{
    const auto STEP_REQUEST_FREQUENCY   = 20.0;

    const auto UNDEFINED_POSITION       = std::numeric_limits<double>::max();
    const auto UNDEFINED_SPEED          = std::numeric_limits<double>::max();
    const auto INVALID_DISTANCE         = -1.0;
    const auto INVALID_VEHICLE_INDEX    = -1;
    const auto INVALID_FEATURE_ID       = -1;

    const auto COMMS_REQUEST_FREQUENCY  = 0.0;

    const auto DEBUG                    = false;

    const double DEFAULT_OSP_DISTANCE   =  0.0;
    const double DEFAULT_POP_DISTANCE   =  0.0;
    const double DEFAULT_POP_OFFSET     =  0.0;

    const double STOPPING_POINT_SEARCH_START = -25.0;
    const double STOPPING_POINT_SEARCH_END   =  5000.0;

    /// Helper function for detecting if the object class is a type of train, recognizing TRAIN
    /// AUTO_TRAIN classes.
    ///
    /// @param object The object to be class tested
    ///
    /// @return True if the class is a train.
    ///
    bool IsTrain(Comms::Object object)
    {
        int class_id = Core::GetClassID(object);
        return (class_id == Train::ClassID::TRAIN) || (class_id == Train::ClassID::AUTO_TRAIN);
    }

    /// Helper function for detecting if the object class is a type of vehicle, recognizing VEHICLE
    /// and AUTO_VEHICLE classes.
    ///
    /// @param object The object to be class tested
    ///
    /// @return True if the class is a vehicle.
    ///
    bool IsVehicle(Comms::Object object)
    {
        int class_id = Core::GetClassID(object);
        return (class_id == Train::ClassID::VEHICLE) || (class_id == Train::ClassID::AUTO_VEHICLE);
    }

    /// Helper function for detecting if the object class is a type of CBTC Onboard Inputs
    ///
    /// @param object The object to be class tested
    ///
    /// @return True if the class is a CBTC Onboard Inputs.
    ///
    bool IsCBTCOnboardInput(Comms::Object object)
    {
        return (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS);
    }

    /// Helper function for detecting if the object class is a type of CBTC Onboard Outputs
    ///
    /// @param object The object to be class tested
    ///
    /// @return True if the class is a CBTC Onboard Outputs.
    ///
    bool IsCBTCOnboardOutput(Comms::Object object)
    {
        return (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_OUTPUTS);
    }

    /// Helper function for getting the given objects parent train object
    ///
    /// @param object The object for which the paren train object is to be gotten
    ///
    /// @return Train Object that is a parent of the given object.
    ///
    Comms::Object GetParentTrainObject(Comms::Object object)
    {
        int class_id = Core::GetClassID(object);

        if (IsVehicle(object))
            return object.GetParent();
        else if (IsCBTCOnboardInput(object) || IsCBTCOnboardOutput(object))
            return object.GetParent().GetParent();

        Comms::Object invalid_train_object;
        return invalid_train_object;
    }

    /// Returns the Number ID corresponding to the train ID property in the object provided.
    ///
    /// @param object The object to get the Scenario Train ID of.
    ///
    /// @return The ID corresponding to the train ID Number, or INVALID_NUMBER if one does not exist
    ///         (or if the object is not a train).
    ///
    int GetScenarioTrainID(Comms::Object object)
    {
        int class_id = Core::GetClassID(object);
        assert((class_id == Train::ClassID::TRAIN) || (class_id == Train::ClassID::AUTO_TRAIN));

        int ret = Sim::INVALID_NUMBER;
        if(class_id == Train::ClassID::TRAIN)
            ret = static_cast<int>(object.Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID) + 0.5);
        else if(class_id == Train::ClassID::AUTO_TRAIN)
            ret = static_cast<int>(object.Numbers().Get(Train::ValueName::AutoTrain::SCENARIO_TRAIN_ID) + 0.5);

        return ret;
    }

    /// Returns the Number ID corresponding to the position property in the vehicle object provided. This
    /// hides the fact that vehicles and auto-vehicles may have different position properties.
    ///
    /// @param object The object to get the position Number ID of.
    ///
    /// @return  The ID corresponding to the position Number, or INVALID_NUMBER if one does not
    ///          exist (or if the object is not a vehicle).
    ///
    Sim::Number::ID GetPositionID(Comms::Object object)
    {
        auto position_id = Sim::INVALID_NUMBER;

        // If this object is a vehicle we can look for the position number's ID
        int class_id = Core::GetClassID(object);
        if(class_id == Train::ClassID::VEHICLE)
            position_id = object.Numbers().Info().GetID(Train::ValueName::Vehicle::TDO_VEHICLE_POSITION);
        else if(class_id == Train::ClassID::AUTO_VEHICLE)
            position_id = object.Numbers().Info().GetID(Train::ValueName::AutoVehicle::POSITION);

        return position_id;
    }

    /// Returns the index of the vehicle object provided. This hides the fact that vehicles and
    /// auto-vehicles may have different index properties.
    ///
    /// @param object The object, which is presumably a vehicle, to get the index of.
    ///
    /// @return The index corresponding to this vehicle. This is 0-based and indicates the vehicles
    ///         position in the consist. -1 is returned if the index property does not exist. 
    ///
    int GetVehicleIndex(Comms::Object object)
    {
        assert(IsVehicle(object));

        int vehicle_index = INVALID_VEHICLE_INDEX;
        int class_id = Core::GetClassID(object);

        if(class_id == Train::ClassID::VEHICLE)
            vehicle_index = static_cast<int>(object.Numbers().Get(Train::ValueName::Vehicle::INDEX) + 0.5);
        else if(class_id == Train::ClassID::AUTO_VEHICLE)
            vehicle_index = static_cast<int>(object.Numbers().Get(Train::ValueName::AutoVehicle::INDEX) + 0.5);

        return vehicle_index;
    }

    /// Returns the length of the vehicle object provided. This hides the fact that vehicles and
    /// auto-vehicles may have different length properties.
    ///
    /// @param object The object, which is presumably a vehicle, to get the index of.
    ///
    /// @return The length corresponding to this vehicle.  -1 is returned if the length property does not exist. 
    ///
    double GetVehicleLength(Comms::Object object)
    {
        assert(IsVehicle(object));

        double vehicle_length = INVALID_VEHICLE_INDEX;
        double class_id = Core::GetClassID(object);

        if(class_id == Train::ClassID::VEHICLE)
            vehicle_length = object.Numbers().Get(Train::ValueName::Vehicle::LENGTH);
        else if(class_id == Train::ClassID::AUTO_VEHICLE)
            vehicle_length = object.Numbers().Get(Train::ValueName::AutoVehicle::LENGTH);

        return vehicle_length;
    }
    
    /// Calculate the Length of a Path from the start offset to the End of the last segment.
    ///
    /// @param world_access   Gives Access to Segments
    /// @param path           The Path to work with
    ///
    /// @return              The Path length or -1 if its Looped
    ///
    double CalculateEndOfTrackPathLength(WorldAPI::WorldAccess &world_access,
                                         WorldAPI::SegmentPath &path)
    {
        double distance = INVALID_DISTANCE;

        // Path is not Looping - Hopefully this will not happen in CrossRail?
        if(path.norepeat_end_index == -1)
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
            for(int i = start_index ; i < end_index; ++i)
                distance += world_access.GetSegmentGeometry(path.segments[i].id).GetSegmentLength();
        }

        return distance;
    }

    /// Calculate the Length of a Path from the start offset to a position on a path segment.
    ///
    /// @param world_access              Gives Access to Segments
    /// @param path                      The Path to work with
    /// @param to                        The position on the path to measure to
    ///
    /// @return              The Path length or -1 if its Looped or the Position is not on one of the path segment
    ///
    double CalculatePathDistanceToPosition(WorldAPI::WorldAccess    &world_access,
                                          WorldAPI::SegmentPath     &path,
                                          WorldAPI::SegmentPosition &to)
    {
        double distance = INVALID_DISTANCE;

        if (path.norepeat_end_index == -1)
        {

            // First check if the two positions are on the same segment and if so 
            // just find the difference betweeen the two offsets
            if (path.segments[path.start_index].id == to.id)
            {
                distance = abs(path.start_offset - to.offset);
            }
            else
            {
                size_t num_segments = path.segments.size();

                // Get the distance to the end of segment 1
                if (!path.segments[path.start_index].from_alpha)
                    distance = path.start_offset;
                else
                    distance = world_access.GetSegmentGeometry(path.segments[path.start_index].id).GetSegmentLength() - path.start_offset;

                // If moving forward we want to look at the segments that are on the path ahead of the train
                // Add the lengths of segments up to the destination position located ahead of the train
                for (size_t i = path.start_index + 1; i < num_segments; ++i)
                {
                    if (to.id != path.segments[i].id)
                        distance += world_access.GetSegmentGeometry(path.segments[i].id).GetSegmentLength();
                    else
                    {
                        // Get the distance from the start to the offset of the last segment
                        if (path.segments[i].from_alpha)
                            distance += to.offset;
                        else
                            distance += (world_access.GetSegmentGeometry(path.segments[i].id).GetSegmentLength() - to.offset);

                        break;
                    }
                }
            }
        }

        return distance;
    }
}

namespace LMAObstacleType
{
    const int UNDEFINED    = -1;
    const int NO_OBSTACLE  = 0;
    const int TRAIN        = 1;
    const int END_OF_TRACK = 2;
    const int SIGNAL       = 3;
    const int CHANGE_ENDS  = 4;
    const int END_AUTO_REGION     = 5;
}

///////////////////////////////////////////////////////////////////////////////////////////
// LMAUnit Public functions
///////////////////////////////////////////////////////////////////////////////////////////

/// Constructor
///
/// @param gateway            The comms gateway
/// @param data_access        Object to access the database
/// @param world_access       World Access object
/// @param points_watcher     Points watcher object
/// @param properties         Unit configuration data
/// @param scenario_train_id  Identifier associated with the scenario train
///
LMAUnit::LMAUnit(Comms::Gateway                &gateway,
                 Common::Data::DataAccess      &data_access,
                 WorldAPI::WorldAccess         &world_access,
                 const LMAProperties           &properties,
                 const int                     scenario_train_id)
    : Comms::SteppingUnit(gateway),
      m_gateway(gateway), m_world_access(world_access), m_data_access(data_access),
      m_train_length_service(new ScenarioTrainLengthService(gateway.GetScenarioData<Core::BaseScenarioData>().data.scenario_id, Train::Database::Train(data_access))),
      m_scenario_train_id(scenario_train_id),
      m_max_lma_ahead(properties.GetDefaultLMAAhead()),
      m_positional_uncertainty(properties.GetUncertaintyDistance()), 
      m_min_following_distance(properties.GetMinFollowingDistance())
{
    // Map the internal obstacle types to the protobuf type
    m_eoa_cause_map = { {LMAObstacleType::END_OF_TRACK, CBTC::Protos::EOACause::END_OF_TRACK},
         {LMAObstacleType::UNDEFINED, CBTC::Protos::EOACause::UNDEFINED},
         {LMAObstacleType::NO_OBSTACLE, CBTC::Protos::EOACause::UNDEFINED},
         {LMAObstacleType::SIGNAL, CBTC::Protos::EOACause::SIGNAL},
         {LMAObstacleType::TRAIN, CBTC::Protos::EOACause::TRAIN_REAR},
         {LMAObstacleType::CHANGE_ENDS, CBTC::Protos::EOACause::CHANGE_OVER},
         {LMAObstacleType::END_AUTO_REGION, CBTC::Protos::EOACause::END_AUTO_REGION},
    };

    // We need a lock to access the root object
    const OS::Lock<Comms::Gateway> COMMS_LOCK(gateway);

    AddCreationCallback(gateway.GetRootObject(), [this](Comms::Object object) { this->RootChildCreated(object); });

    m_pall_train_watcher.reset(new WorldAPI::AllTrainWatcher(gateway.GetRootObject(), COMMS_REQUEST_FREQUENCY));

    // NOTE BUG?: This line throws an assertion because the point_watcher expect to be detached from the root object when this call is made.
    // However the defalt contructor for the points_watcher_resource is already attaching to the root object.
    // The default request frequency is left unmodified & remains at the default, which in FeatureWatcher::m_request_frequency remains uninitialised.
    //m_points_watcher.SetRequestFrequency(COMMS_REQUEST_FREQUENCY);

    // Had to use our own PointsWatcher because the points_watcher_resource Attaches without allowing us to set the request frequency, 
    // In fact, the points_watcher_resources leaves m_request_frequency uninitialised...
    m_points_watcher.SetAcceptableTypes(m_data_access);
    m_points_watcher.SetRequestFrequency(COMMS_REQUEST_FREQUENCY);
    m_points_watcher.Attach(gateway.GetRootObject());

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "LMAUnit - Started" << Trace::EndLog();
}

/// Destructor
///
LMAUnit::~LMAUnit()
{
    // Detach our feature requester under the comms mutex while we can
    const OS::Lock<Comms::Gateway> COMMS_LOCK(m_gateway);
    m_pall_train_watcher.release();
}

/// Returns a string holding the name of this unit.
///
std::string LMAUnit::GetName() const
{
    return "LMA Unit";
}

/// Step function for the unit which call the LMA update function
///
void LMAUnit::Step(double sim_time)
{
    // Updating our model. Make sure that we have the lock
    OS::Lock<Comms::Gateway> lock(m_gateway);

    // Update the LMA data for each train
    for (auto &train_lma : m_train_lmas)
    {
        if (train_lma.second->IsSimulatedTrain())
            train_lma.second->Update(sim_time);
    }
}

/// Gets the period of the step function
///
double LMAUnit::GetPeriod() const
{
    return 1.0 / STEP_REQUEST_FREQUENCY;
}


///////////////////////////////////////////////////////////////////////////////////////////
// COMMS Object functions
///////////////////////////////////////////////////////////////////////////////////////////

/// Callback to handle creation of the Root object
///
/// @param object : Root Object
///
void LMAUnit::RootChildCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex>  DATA_LOCK(m_mutex);

    int class_id = Core::GetClassID(object);
    if(class_id == Core::ClassID::WORLD)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Core::ClassID::WORLD" << Trace::EndLog();
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
    }
}

/// Callback to handle creation of a Comms Child object
///
/// @param object : Comms Object
///
void LMAUnit::ObjectCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex>  DATA_LOCK(m_mutex);

    if (IsTrain(object))
    {
        // Add the train into the map that maintains LMA Info associated with the train
        int scenario_train_id = GetScenarioTrainID(object);
        auto train_length = m_train_length_service->GetTrainLength(scenario_train_id);
        auto is_simulated_train = (scenario_train_id == m_scenario_train_id);

        m_train_lmas.insert(std::pair<Comms::Object, std::shared_ptr<TrainLMAInfo>>(object, std::make_shared<TrainLMAInfo>(m_gateway, m_data_access, m_world_access, m_points_watcher, *this, object, train_length, is_simulated_train)));

        // Add the train into the map that maintains vehicle information associated with the train
        m_train_vehicle_data.insert(std::pair<Comms::Object, std::shared_ptr<TrainVehicleData>>(object, std::make_shared<TrainVehicleData>()));

        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (IsVehicle(object))
    {
        assert(m_train_vehicle_data.find(GetParentTrainObject(object)) != m_train_vehicle_data.end());

        auto &train_vehicle_data = *(m_train_vehicle_data.find(GetParentTrainObject(object))->second);

        TrainVehicleData::Vehicle new_vehicle;
        new_vehicle.m_vehicle_object = object;
        new_vehicle.m_vehicle_length = GetVehicleLength(object);
        new_vehicle.m_vehicle_index = GetVehicleIndex(object);
        new_vehicle.m_position_id = GetPositionID(object);

        train_vehicle_data.m_vehicles[object] = new_vehicle;

        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });

        // If it is the lead vehicle we want to look at the child objects that are created
        if (Sim::Project::IsLeadVehicle(object))
            AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
    }
    else if (IsCBTCOnboardInput(object))
    {
        assert(m_train_lmas.find(GetParentTrainObject(object)) != m_train_lmas.end());

        auto &this_train = *(m_train_lmas.find(GetParentTrainObject(object))->second);
        this_train.MapCBTCOnboardInputObject(object, COMMS_REQUEST_FREQUENCY);

        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (IsCBTCOnboardOutput(object))
    {
        assert(m_train_lmas.find(GetParentTrainObject(object)) != m_train_lmas.end());

        auto &this_train = *(m_train_lmas.find(GetParentTrainObject(object))->second);
        this_train.MapCBTCOnboardOutputObject(object, COMMS_REQUEST_FREQUENCY);

        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
}

/// Handles any invalidations that need to occur when an object is destroyed
///
/// @param object this is the object that was destroyed
///
void LMAUnit::ObjectDestroyed(Comms::Object object)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (IsTrain(object))
    {
        assert(m_train_lmas.find(object) != m_train_lmas.end());

        // Remove the destroyed train
        m_train_lmas.erase(object);
        m_train_vehicle_data.erase(object);
    }
    else if (IsVehicle(object))
    {
        TrainVehicleData &this_train = *(m_train_vehicle_data.find(GetParentTrainObject(object))->second);
        this_train.m_vehicles.erase(object);
    }
    else if (IsCBTCOnboardInput(object))
    {
        assert(m_train_lmas.find(GetParentTrainObject(object)) != m_train_lmas.end());

        // Look for the parent and invalidate our understanding of this object
        auto train = m_train_lmas.find(object.GetParent().GetParent())->second;
        train->UnMapCBTCOnboardInputObject();
    }
    else if (IsCBTCOnboardOutput(object))
    {
        assert(m_train_lmas.find(GetParentTrainObject(object)) != m_train_lmas.end());

        // Look for the parent and invalidate our understanding of this object
        auto train = m_train_lmas.find(object.GetParent().GetParent())->second;
        train->UnMapCBTCOnboardOutputObject();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// LMAUnit::TrainLMAInfo functions
///////////////////////////////////////////////////////////////////////////////////////////


/// Constructor
///
/// @param gateway             Use to communicate with Comms
/// @param data_access         Simulator Database access object
/// @param world_access        World Access object
/// @param points_watcher      Points watcher object
/// @param lma_unit            Point back to the Unit for common member variables that we can't be bothered replicating
/// @param train_object        Train for which the LMA info is being provided for
/// @param train_length        Length of the train for which the LMA info is being provided for
/// @param is_simulated_train  Flags that train info belongs to a simulated train
/// 
LMAUnit::TrainLMAInfo::TrainLMAInfo(Comms::Gateway              &gateway,
                                    Common::Data::DataAccess    &data_access,
                                    WorldAPI::WorldAccess       &world_access,
                                    WorldAPI::PointsWatcher     &points_watcher,
                                    LMAUnit                     &lma_unit,
                                    Comms::Object                train_object,
                                    double                       train_length,
                                    bool                         is_simulated_train)
    : m_gateway(gateway),
      m_train_object(train_object), 
      m_scenario_train_id(GetScenarioTrainID(train_object)), 
      m_is_simulated_train(is_simulated_train), 
      m_train_length(train_length),
      m_path_watcher(new WorldAPI::TrainPathWatcher(world_access, points_watcher, COMMS_REQUEST_FREQUENCY, train_object)),
      m_lma_features(gateway, data_access, world_access, *m_path_watcher),
      m_stopping_point(gateway, data_access, world_access, *m_path_watcher),
      m_feature_region(gateway, data_access, world_access, *m_path_watcher, lma_unit.m_max_lma_ahead),
      m_lma_unit(lma_unit)
{
    assert(Core::GetClassID(train_object) == Train::ClassID::TRAIN || Core::GetClassID(train_object) == Train::ClassID::AUTO_TRAIN);

    // Keep track of the trains lead loco position so that we know the reference point from which the LMA was calculated
    if (m_is_simulated_train)
    {
        m_lead_loco_position_id = train_object.Numbers().Info().GetID(Train::ValueName::Train::LLO_LEAD_LOCO_POSITION);

        std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
        number_requests.push_back(train_object.Numbers().Info().GetInfo(m_lead_loco_position_id));
        train_object.Numbers().Store().Request(number_requests.begin(), number_requests.end(), COMMS_REQUEST_FREQUENCY);
    }
    else
        m_lead_loco_position_id = Sim::INVALID_NUMBER;
}

LMAUnit::TrainLMAInfo::~TrainLMAInfo()
{
    // Detach our feature requester under the comms mutex while we can
    const OS::Lock<Comms::Gateway> COMMS_LOCK(m_lma_unit.m_gateway);
    m_path_watcher.release();
}

/// Return true if Comms initialisation has completed
///
/// @returns true if all required objects have been created
///
bool LMAUnit::TrainLMAInfo::CommsInitialisationCompleted()
{
    return (m_mapped_cbtc_onboard_inputs.IsValid() && m_mapped_cbtc_onboard_outputs.IsValid());
}

/// Determines the trains LMA values when it is within a CBTC region.
///
/// As part of each update this function
/// - Gets the selected AR mode so that it can determine the direction the train is travelling
/// - Updates the information about the LMA features on the path
/// - Determines the Forward LMA if the selected AR mode is None or DTROF
/// - Determines the Reverse LMA if the selected AR mode is DTROB, ACC, UAR
/// - Determines the POS LMA if the next LMA feature or a previous LMA feature is in the POS state
/// - Determines the available AR mode by determining if the next LMA feature has been placed into an AR mode
/// - Updates the LMA data that is associated with the train
///
void LMAUnit::TrainLMAInfo::Update(double new_time)
{
    assert(m_is_simulated_train);

    // Make sure that the unit has completed initialisation before continuing
    if (!CommsInitialisationCompleted())
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "LMAUnit - Unit is Missing all required objects" << Trace::EndLog();
        return;
    }

    // Get the data from comms
    {
        // Updating our model. Make sure that we have the lock
        OS::Lock<Comms::Gateway> lock(m_gateway);

        m_mapped_cbtc_onboard_outputs.Get();
    }

    // Clear the existing LMA obstacles
    m_lma_obstacles.clear();

    // Update train path LMA feature information
    m_lma_features.UpdateLMAFeaturesOnForwardPath();

    // Add the default LMA obstacle at the max allowed LMA distance
    auto default_max_distance = m_lma_unit.m_max_lma_ahead;
    InsertLMAObstacle(m_lma_obstacles, default_max_distance, LMAObstacleType::NO_OBSTACLE);

    // Get the next stopping point position and data
    auto next_stopping_point = m_stopping_point.GetNextStoppingPointData(
      STOPPING_POINT_SEARCH_START, STOPPING_POINT_SEARCH_END, m_scenario_train_id);
    auto next_stopping_point_distance = next_stopping_point.first;
    auto next_stopping_point_feature = next_stopping_point.second;

    // Add any obstacles that are reported to us via the LMA related features
    SetLMAFeatureObstacles(m_lma_obstacles, m_lma_features, next_stopping_point_distance, next_stopping_point_feature);

    // Add an end of track LMA obstacle
    SetEndOfTrackObstacles(m_lma_obstacles);         
    
    // Add LMA obstacle if transitioning out of automatic region in AM mode
    auto distance_to_end_of_automatic = m_feature_region.GetDistanceToFeatureRegionEnd(m_scenario_train_id, FeatureInterfaces::FeatureRegion::RegionType::AUTOMATIC);
    if ((distance_to_end_of_automatic > 0) && (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO))
        InsertLMAObstacle(m_lma_obstacles, distance_to_end_of_automatic, LMAObstacleType::END_AUTO_REGION);

    // Add a LMA Obstacle to the rear of the nearest train on our path, if one exists
    SetClosestTrainLMAObstacle(m_lma_obstacles);

    // Get the data about the CBTCOnboardInput obstacle that is closest to the train
    double lma_ahead_osp;   // eoa
    double lma_ahead_pop;   // svl
    int    lma_ahead_type;
    GetClosestObstacle(m_lma_obstacles, lma_ahead_osp, lma_ahead_pop, lma_ahead_type, m_lma_unit.m_positional_uncertainty);

    // If simulated train it will have an LMA object associated with it and so we need to generate the ouput message 
    // and send the update LMA output data to the CBTC Onboard Inputs Comms object
    auto current_loco_position = m_train_object.Numbers().Store().Get(m_lead_loco_position_id).value;
    m_mapped_cbtc_onboard_inputs.SetCBTCMARawDataString(current_loco_position, lma_ahead_osp, lma_ahead_pop, m_lma_unit.m_eoa_cause_map[lma_ahead_type], next_stopping_point_distance);
    m_mapped_cbtc_onboard_inputs.Set();
}

/// Initialises the mapping between the CBTCOnboardInput object and the properties we are interested in
/// 
/// @param cbtc_onboard_inputs_object Object whose properties are to be mapped
/// @param request_frequency          Rate at which request for updates is to be made
///
void LMAUnit::TrainLMAInfo::MapCBTCOnboardInputObject(Comms::Object cbtc_onboard_inputs_object, double request_frequency)
{
    m_mapped_cbtc_onboard_inputs.MapCBTCOnboardInputs(cbtc_onboard_inputs_object, request_frequency);
}

/// Frees the mapping between the CBTCOnboardInput object and the properties we are interested in
/// 
void LMAUnit::TrainLMAInfo::UnMapCBTCOnboardInputObject()
{
    m_mapped_cbtc_onboard_inputs.UnMapCBTCOnboardInputs();
}

/// Initialises the mapping between the CBTCOnboardOutput object and the properties we are interested in
/// 
/// @param cbtc_onboard_outputs_object Object whose properties are to be mapped
/// @param request_frequency           Rate at which request for updates is to be made
///
void LMAUnit::TrainLMAInfo::MapCBTCOnboardOutputObject(Comms::Object cbtc_onboard_outputs_object, double request_frequency)
{
    m_mapped_cbtc_onboard_outputs.MapCBTCOnboardOutputs(cbtc_onboard_outputs_object, request_frequency);
}

/// Frees the mapping between the CBTCOnboardOutput object and the properties we are interested in
/// 
void LMAUnit::TrainLMAInfo::UnMapCBTCOnboardOutputObject()
{
    m_mapped_cbtc_onboard_outputs.UnMapCBTCOnboardOutputs();
}

/// Gets a position in terms of a path. Uses path clipping.
///
/// @note
///     Searches forward, and then in reverse for the index
///     of the segment along the path.
///     Throws an exception if the position is not on the path
///
/// @param path              Path to locate on
/// @param segment_position  Position to convert
///
/// @return the equivalent position on the path

WorldAPI::PathPosition GetPathPosition2(const WorldAPI::SegmentPath &path, const WorldAPI::SegmentPosition &segment_position)
{
    WorldAPI::PathPosition ret;
    ret.segment_position = segment_position.offset;

    bool have_ret = false;

    for (size_t i = path.start_index; i < path.segments.size(); ++i)
    {
        if (path.segments[i].id == segment_position.id)
        {
            ret.segment_index = static_cast<int>(i);
            ret.from_alpha = path.segments[i].from_alpha;

            if ((path.has_start_limit && ret < path.start_path_position) ||
                (path.has_end_limit && !(ret < path.end_path_position)))
                continue;

            have_ret = true;
            break;
        }
    }

    for (size_t i = path.start_index; i > 0; --i)
    {
        if (path.segments[i].id == segment_position.id)
        {
            ret.segment_index = static_cast<int>(i);
            ret.from_alpha = path.segments[i].from_alpha;

            if ((path.has_start_limit && ret < path.start_path_position) ||
                (path.has_end_limit && !(ret < path.end_path_position)))
                continue;

            have_ret = true;
            break;
        }
    }

    if (!have_ret)
        throw CommonException("Segment position not on path");

    return ret;
}



/// Gets the vehicle object that is closest to the start of the path.
///
/// Note that this is the same as the core function with the exception that the call to 
/// function GetPathPosition() has been replaced to call a local function. The original
/// function would throw an exception in all cases other than the case where the 
/// simulated train is moving forward and the train that appears on the path ahead is 
/// also travelling in the same direction. Throw an excepetion if train ahead is 
/// heading towards the simulated train or we look for closest vehicle in reverse direction
/// For related core bug refer CORETRAIN-3410 
///
/// @param path          Path to look on
/// @param ignore_train  Train object to ignore vehicles of
///
/// @return Vehicle object closest if there is one, otherwise an invalid object.

Comms::Object LMAUnit::TrainLMAInfo::GetClosestVehicle(const WorldAPI::SegmentPath &path, Comms::Object ignore_train) const
{
    std::vector<std::pair<WorldAPI::PathPosition, const Comms::Object*> > path_objects;

    // Clip the path so we only search the path ahead of or behind the train being ignored
    WorldAPI::SegmentPath clipped_path = path;
    {
        clipped_path.has_start_limit = true;
        clipped_path.has_end_limit = false;
        clipped_path.start_path_position.segment_index = path.start_index;
        clipped_path.start_path_position.segment_position = path.start_offset;
        clipped_path.start_path_position.from_alpha = path.segments[path.start_index].from_alpha;
    }

    // For each vehicle on the clipped path, add it to the array of path objects
    for (auto &next_train : m_lma_unit.m_train_vehicle_data)
    {
        if (next_train.first != ignore_train)
        {
            for (auto &nextVehicle : next_train.second->m_vehicles)
            {
                WorldAPI::SegmentPosition vehiclePosition = m_lma_unit.m_pall_train_watcher->GetVehicleTrackPosition(nextVehicle.first);

                if (IsPositionOnPath(clipped_path, vehiclePosition))
                    path_objects.push_back(std::make_pair(GetPathPosition2(clipped_path, vehiclePosition), &(nextVehicle.first)));
            }
        }
    }

    // Sort the array and pull off the vehicle from the appropriate end
    sort(path_objects.begin(), path_objects.end());

    Comms::Object ret;
    if (!path_objects.empty())
    {
        ret = *path_objects.front().second;
    }

    return ret;
}

/// Gets information about the distance to the nearest train on the path ahead and it direction of travel
///
/// @returns Pair containing the distance to the train in front of us and whether it is facing us. True if nearest train is facing us
///
std::pair<double, bool> LMAUnit::TrainLMAInfo::GetNearestTrainInfo()
{
    bool facing = false;
    double distance_to_train = INVALID_DISTANCE;

    try
    {
        // We cannot work out following distance until we have a Path
        WorldAPI::SegmentPath path = [this]()
        {
            const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(*m_path_watcher);
            return m_path_watcher->GetExtendedPath();
        }();

        // Find the nearest train vehicle
        Comms::Object thisTrain = m_lma_unit.m_pall_train_watcher->GetTrainObject(m_scenario_train_id);
        Comms::Object nearestVehicle = GetClosestVehicle(path, thisTrain);

        // Process only if there is a vehicle ahead on the current path
        if (nearestVehicle.IsValid())
        {
            // Lookup the nearest vehicles parent (Train)
            assert(m_lma_unit.m_train_vehicle_data.find(nearestVehicle.GetParent()) != m_lma_unit.m_train_vehicle_data.end());
            auto &train_vehicle_data = *(m_lma_unit.m_train_vehicle_data.find(nearestVehicle.GetParent())->second);

            WorldAPI::SegmentPosition thisFrontPosition = m_lma_unit.m_pall_train_watcher->GetTrainTrackPositions(thisTrain)[0];
            WorldAPI::SegmentPosition nearestVehiclePosition = m_lma_unit.m_pall_train_watcher->GetVehicleTrackPosition(nearestVehicle);

            // These Positions may be on the same or different Segments - Use the path offset to calculate distance.
            // The Train Ahead may be facing us or it may be in the same direction as us, in which case we need to subtract the
            // trains length from the Position to get the distance.

            // Find the Nearest Vehicle in the Vehicles vector and get its index in the train.
            // We also return whether the other train is facing us or not. If the nearest vehicle index is 0, its the front
            // of the facing train.
            facing = false;
            if (train_vehicle_data.m_vehicles.find(nearestVehicle) != train_vehicle_data.m_vehicles.end())
            {
                int nearest_vehicle_index = train_vehicle_data.m_vehicles[nearestVehicle].m_vehicle_index;
                facing = (nearest_vehicle_index == 0) ? true : false;

                // Calculate the Path offset between the vehicles.
                distance_to_train = CalculatePathDistanceToPosition(m_lma_unit.m_world_access, path, nearestVehiclePosition);

                // If its not facing us, subtract the length of the Vehicle to get the offset of the rear.
                if (!facing)
                    distance_to_train -= train_vehicle_data.m_vehicles[nearestVehicle].m_vehicle_length;


                if (DEBUG)
                    Trace::GetLogger().STAMP(Trace::ERR) << "<======================================================>\n nearest vehicle : " << nearestVehicle.GetID()
                    << ", \ndistance_to_train -  " << distance_to_train << "{" << facing << "}   "
                    << path.start_index << " - " << path.segments[path.start_index].id << "   " << nearestVehiclePosition.id
                    << "  -  " << path.start_offset << "   " << nearestVehiclePosition.offset
                    << "  -   " << path.segments[path.start_index].from_alpha << "   " << nearestVehiclePosition.from_alpha
                    << Trace::EndLog();
            }
        }
    }
    catch (CommonException &e)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Failed to Get Distance to nearest train! : " << e.what() << " for Train " << m_scenario_train_id << Trace::EndLog();
    }

    return std::pair<double, bool>(distance_to_train, facing);
}

/// Inserts an LMA obstacle to the nearest train on our path, if one exists 
///
/// @param lma_obstacles      Vector into which LMA obstacle to be inserted
///
void LMAUnit::TrainLMAInfo::SetClosestTrainLMAObstacle(LMAObstacles &lma_obstacles)
{
    auto nearest_train_info = GetNearestTrainInfo();
    double following_distance = nearest_train_info.first;
    if (following_distance != INVALID_DISTANCE)
    {
        InsertLMAObstacle(lma_obstacles, following_distance, LMAObstacleType::TRAIN);
    }
}

/// This function adds the LMA feature obstacles into the map of LMA obstables
/// 
/// LMA Feature Obstables that can be added are
/// - Position of the next LMA feature that is in the Stop State
/// - Position of the next LMA feature in the POS state
/// - Position of the last LMA feature on the path
/// - A Zero LMA if location in an emergency stop region
/// - When end point is expected, either
///   -- A zero LMA if no end point found
///   -- Position of the next LMA feature that is in the End Point State
///
/// @param lma_obstacles             Vector into which the LMA obstacles to be inserted
/// @param lma_features              LMA features that appear on the train path
/// @param stopping_point_distance   LMA features that appear on the train path
/// @param stopping_points           Stopping point that appear on the train path
/// 
void LMAUnit::TrainLMAInfo::SetLMAFeatureObstacles(LMAUnit::LMAObstacles      &lma_obstacles,
                                                   const LMAFeatures          &lma_features,
                                                   const double               &stopping_point_distance,
                                                   StoppingPoint::FeatureData &next_stopping_point_feature)
{
    // Get the LMA features needed to determine LMA
    auto next_lma_feature = lma_features.GetNextLMAFeature();
    auto prev_lma_feature = lma_features.GetPreviousLMAFeature();
    auto next_stop_lma_feature = lma_features.GetNextStopLMAFeature();

    // If we have passed a stop feature need to keep reporting the EOA obstacle until the EOA obstacle is cleared
    if (m_next_eoa_obstacle.IsValid() && prev_lma_feature.second.IsValid() && (m_next_eoa_obstacle.GetFeatureId() == prev_lma_feature.second.GetFeatureId()))
    {
        // EOA obstacle that the train has passed is still in the stop feature so we continue reporting it as the location of our EOA
        if (prev_lma_feature.second.IsSignalStop())
        {
            prev_lma_feature.first = 0.0;
            InsertLMAObstacle(lma_obstacles, prev_lma_feature, LMAObstacleType::SIGNAL);
        }

        // EOA obstacle that the train has passed is no longer in the stop state so we stop reporting the EOA location 
        else
            m_next_eoa_obstacle.SetInvalid();
    }

    // If LMA stop feature found on the path ahead we want to record it into the map of LMA obstacles
    else if (next_stop_lma_feature.second.IsValid())
    {
        InsertLMAObstacle(lma_obstacles, next_stop_lma_feature, LMAObstacleType::SIGNAL);

        // Need to record m_next_eoa_obstacle so that if the train passes the EOA obstacle before it is cleared the EOA obstacle
        // will continue to be applied until it is cleared.
        //
        // The stop feature recorded in m_next_eoa_obstacle should be updated when
        // - (No EOA obstacle is currently recorded) OR
        // - (The recorded EOA obstacle is no longer an obstacle) OR
        // - (the EOA obstable of interest is not behind the train AND a new EOA obstable was detected on the track ahead)
        if (!m_next_eoa_obstacle.IsValid() ||
            !m_next_eoa_obstacle.IsSignalStop() ||
            ((prev_lma_feature.second.IsValid()) &&                           
             (m_next_eoa_obstacle.GetFeatureId() != prev_lma_feature.second.GetFeatureId()) &&
             (m_next_eoa_obstacle.GetFeatureId() != next_stop_lma_feature.second.GetFeatureId())))  
        {
            m_next_eoa_obstacle = next_stop_lma_feature.second;
        }
    }

    // Add a LMA Obstacle if the next stopping point is for a change of ends
    else if (next_stopping_point_feature.IsChangeOfEnds())
    {
        InsertLMAObstacle(m_lma_obstacles, stopping_point_distance, LMAObstacleType::CHANGE_ENDS);
    }
}

/// Inserts an LMA obstacle for the end of the trains's path 
///
/// @param lma_obstacles      Vector into which LMA obstacle to be inserted
///
void LMAUnit::TrainLMAInfo::SetEndOfTrackObstacles(LMAUnit::LMAObstacles &lma_obstacles)
{
    WorldAPI::SegmentPath path = [this]()
    {
        const std::lock_guard<WorldAPI::TrainPathWatcher> PATH_WATCHER_LOCK(*m_path_watcher);
        return m_path_watcher->GetPath();
    }();

    auto end_of_track_distance = CalculateEndOfTrackPathLength(m_lma_unit.m_world_access, path);
    if (end_of_track_distance > 0)
        InsertLMAObstacle(m_lma_obstacles, end_of_track_distance, LMAObstacleType::END_OF_TRACK);

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::INFO) << "End Of Track is located at " << end_of_track_distance << Trace::EndLog();
}

/// Inserts an LMA feature into the map of LMA obstacles
///
/// @param lma_obstacles  The Map of LMA obstacles to insert into.
/// @param lma_feature    LMA feature to be added into the map of LMA obstacles
/// @param obstacle_type  Type of obstacle represented by the LMA feature
///
void LMAUnit::TrainLMAInfo::InsertLMAObstacle(LMAUnit::LMAObstacles &lma_obstacles, LMAFeatures::LMAFeatureOnPath &lma_feature, int obstacle_type)
{
    auto next_lma_obstacle = LMAUnit::LMAObstacleData(lma_feature, obstacle_type);
    lma_obstacles.insert(LMAUnit::LMAObstacle(lma_feature.first, next_lma_obstacle));

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Inserted (" << obstacle_type << ") obstacle at position " << lma_feature.first << Trace::EndLog();
}

/// Inserts an LMA feature into the map of LMA obstacles
///
/// @param lma_obstacles  The Map of LMA obstacles to insert into.
/// @param offset         Offset from the trains current location
/// @param obstacle_type  Type of obstacle represented by the LMA feature
///
void LMAUnit::TrainLMAInfo::InsertLMAObstacle(LMAUnit::LMAObstacles &lma_obstacles, double offset, int obstacle_type)
{
    LMAUnit::LMAObstacleData next_lma_obstacle;

    // For the change of ends and end of auto region obstacles, the offset represents the OSP
    if ((obstacle_type == LMAObstacleType::CHANGE_ENDS) || (obstacle_type == LMAObstacleType::END_AUTO_REGION))
        next_lma_obstacle = LMAUnit::LMAObstacleData(obstacle_type, offset, (offset + 2.0));

    // For train and the end of track obstacles, the offset represents the POP 
    else if ((obstacle_type == LMAObstacleType::TRAIN) || (obstacle_type == LMAObstacleType::END_OF_TRACK))
        next_lma_obstacle = LMAUnit::LMAObstacleData(obstacle_type, (offset - 2.0), offset);
    else
        next_lma_obstacle = LMAUnit::LMAObstacleData(obstacle_type);

    lma_obstacles.insert(LMAUnit::LMAObstacle(offset, next_lma_obstacle));

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Inserted obstacle (" << obstacle_type << ") at position " << offset << Trace::EndLog();
}

/// Updates the provided OSP, POP and obstacle type parameters to the values found in the closest LMA obstacle
///
/// @param lma_obstacles            Map of the known LMA obstacle
/// @param osp                      Returns distance to the OSP of the nearest LMA obstacle 
/// @param pop                      Returns distance to the POP of the nearest LMA obstacle 
/// @param obstacle_type            Returns type Of closest LMA obstacle that was found
/// @param pos_uncertainty          Amount of uncertainty to be applied to the OSP and POP distances
///
void LMAUnit::TrainLMAInfo::GetClosestObstacle(LMAUnit::LMAObstacles &lma_obstacles,
    double &osp, double &pop, int &obstacle_type, const double pos_uncertainty)
{
    // Set OSP and POP distances to be the distance to OSP and POP of the closest LMA obstacle.
    if (lma_obstacles.size() > 0)
    {
        // For the closest LMA obstacle we need to apply the OSP and POP offsets to the
        // features current position and subtract the uncertainty value to get the actual LMA
        auto closest_lma = *lma_obstacles.begin();
        osp = closest_lma.first + closest_lma.second.m_osp - pos_uncertainty;
        pop = closest_lma.first + closest_lma.second.m_pop - pos_uncertainty;

        // If the LMA ends at a train obstacle, then if the trains are facing each other the
        // LMA needs to be halved so that the trains stop at the half way point between them
        if (closest_lma.second.m_obstacle_type == LMAObstacleType::TRAIN)
        {
            auto nearest_train_info = GetNearestTrainInfo();
            bool facing = nearest_train_info.second;

            if (facing)
            {
                // If trains are facing each other give each half the space between them.
                // Note: Facing trains are probably not going to be a good idea in this simulator
                // In reality a Train stopped at a platform will have an LMA obstruction set to the start
                // of the platforms exit block. An Auto Train on the opposite line, but with crossover
                // points set to reverse making it a facing train on the same path, may set the exit blocks
                // LMA Occupied state which may affect the state of the Exit blocks signal. It will be up to the
                // instructor to ensure that facing train situations do not arise.
                osp = osp / 2.0;
                pop = pop / 2.0;
            }

            // Need to add to the MA the minimum allowed MA separation distance between trains
            osp = (osp - m_lma_unit.m_min_following_distance);
            pop = (pop - m_lma_unit.m_min_following_distance);
        }

        osp = (osp < 0.0) ? 0.0 : osp;
        pop = (pop < 0.0) ? 0.0 : pop;

        obstacle_type = closest_lma.second.m_obstacle_type;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// LMAUnit::LMAObstacleData Constructors
///////////////////////////////////////////////////////////////////////////////////////////

LMAUnit::LMAObstacleData::LMAObstacleData()
    : m_osp(DEFAULT_OSP_DISTANCE), m_pop(DEFAULT_POP_DISTANCE),
    m_obstacle_type(LMAObstacleType::UNDEFINED)
{
}

LMAUnit::LMAObstacleData::LMAObstacleData(int obstacle_type)
    : m_osp(DEFAULT_OSP_DISTANCE), m_pop(DEFAULT_POP_DISTANCE),
    m_obstacle_type(obstacle_type)
{
}

LMAUnit::LMAObstacleData::LMAObstacleData(int obstacle_type, double osp, double pop)
    : m_osp(osp), m_pop(pop),
    m_obstacle_type(obstacle_type)
{
}

LMAUnit::LMAObstacleData::LMAObstacleData(LMA::LMAFeatures::LMAFeatureOnPath lma_feature, int obstacle_type)
    : m_osp(lma_feature.second.m_osp), m_pop(lma_feature.second.m_pop),
    m_obstacle_type(obstacle_type)
{
}
