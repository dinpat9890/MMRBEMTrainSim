///****************************************************************************************************************
/// @file         GradientProfileUnit.cpp
///
/// Description : This unit is responsible for generating the Gradient profile to be
///               provided to the ETCS On Board System
/// Reference   : https://adl-atlassian.corp.knorr-bremse.com/confluence/display/XRAIL/ETCS+Gradient+Profile+Unit
///
/// @author       Abhishek Rastogi
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2018
///****************************************************************************************************************

#include "GradientProfileUnit.h"

#include "train_types/ScenarioTrainSelector.h"
#include <train_data_access/TrainDataAccess.h>
#include <train_data_access/TrainDataAccessTypes.h>

#include "world_api/PointsWatcher.h"
#include "Protobuf/CBTCOnboard.pb.h"

#include "core_properties/CommonProperties.h"

#include "project_comms_structure\ProjectObjectConstants.h"

#include "train_comms_structure\TrainObjectConstants.h"

#include "Project/Utilities/IsLeadVehicle.h"

#include "utility\Utilities.h"
#include "common\Callback.h"

#include "common/StandardLogging.h"

#include <cassert>
#include <cmath>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>

namespace
{
    const bool DEBUG = false;

    const double STEP_REQUEST_FREQUENCY  = 20.0;
    const double COMMS_REQUEST_FREQUENCY = 20.0;
    const double INVALID_DISTANCE        = -1.0;
    const double PER_MILLE_UNITS         = 1000.0;

    // Configuration parameter names constants
    const std::string GRADIENT_CONFIG_SECTION_NAME  = "Gradient Profile Configuration";
    const std::string STEP_DISTANCE                 = "Step Distance";
    const std::string MIN_GRADIENT_DISTANCE         = "Min Gradient Distance";
    const std::string MIN_ACCEPTABLE_CHANGE         = "Min Acceptable Change";

    // Configuration parameter's default values
    const double      STEP_DISTANCE_DEFAULT         = 100.0; // In Meters
    const double      MIN_GRADIENT_DISTANCE_DEFAULT = 250.0; // In Meters
    const double      MIN_ACCEPTABLE_CHANGE_DEFAULT = 0.5; // Delta

    Sim::Number GetRequiredNumber(const Comms::Object &object, const std::string &number_property_name)
    {
        auto number_id = object.Numbers().Info().GetID(number_property_name);
        if(number_id != Sim::INVALID_NUMBER)
            return object.Numbers().Store().Get(number_id);

        Trace::GetLogger().STAMP(Trace::ERR) << object.GetName() << " object doesn't contain valid ID for Number " << number_property_name << Trace::EndLog();
        return Sim::Number();
    }

    Sim::Raw GetRequiredRaw(const Comms::Object &object, const std::string &raw_property_name)
    {
        auto raw_id = object.Raws().Info().GetID(raw_property_name);
        if(raw_id != Sim::INVALID_RAW)
            return object.Raws().Store().Get(raw_id);

        Trace::GetLogger().STAMP(Trace::ERR) << object.GetName() << " object doesn't contain valid ID for Raw " << raw_property_name << Trace::EndLog();
        return Sim::Raw();
    }

    /// Calculate the Length of a Path from the start offset to the End of the last segment.
    ///
    /// @param world_access  Gives Access to Segments
    /// @param path          The Path to work with
    /// @param moving_forward True if we are looking ahead of the train and false if behind
    /// @param train_length   Length of train
    ///
    /// @return              The Path length or -1 if its Looped
    ///
    double CalculatePathLength(const WorldAPI::WorldAccess &world_access, const WorldAPI::SegmentPath &path, bool moving_forward, double train_length)
    {
        double distance = INVALID_DISTANCE;

        // Path is not Looping - Hopefully this will not happen in CrossRail?
        if(path.norepeat_end_index == -1)
        {
            int start_index;
            int end_index;
            if (moving_forward)
            {
                // Get distance from path position to end of the first segment - The Segment orientation determines the way its calculated
                if (!path.segments[path.start_index].from_alpha)
                    distance = path.start_offset;
                else
                    distance = world_access.GetSegmentGeometry(path.segments[path.start_index].id).GetSegmentLength() - path.start_offset;

                start_index = path.start_index + 1;
                end_index = path.segments.size();
            }
            else
            {
                // Get distance from path position to end of the first segment - The Segment orientation determines the way its calculated
                if (!path.segments[path.start_index].from_alpha)
                    distance = world_access.GetSegmentGeometry(path.segments[path.start_index].id).GetSegmentLength() - path.start_offset;
                else
                    distance = path.start_offset;

                distance -= train_length;
                start_index = 0;
                end_index = path.start_index;
            }

            // Add the Full length of the remaining segments on the Path
            for(int i = start_index ; i < end_index; ++i)
                distance += world_access.GetSegmentGeometry(path.segments[i].id).GetSegmentLength();
        }

        return distance;
    }

    void LogGradientProfileList(const std::list<GradientProfileUnit::GradientInfo> &gradients_info)
    {
        std::stringstream str_stream;
        str_stream << ":::: GRADIENT PROFILE ::::\n";
        for(const auto &gradient_info : gradients_info)
        {
            str_stream << "GRADIENT : " << gradient_info.second << " %o, DISTANCE : " << gradient_info.first << " m\n";
        }

        Trace::GetLogger().STAMP(Trace::INFO) << str_stream.str() << Trace::EndLog();
    }
}

/// Constructor
///
/// @param gateway                  The comms gateway
/// @param data_access              Object to perform database access
/// @param world_access             Object to access world data
/// @param scenario_data            Data about the scenario
/// @param point_watcher            PointWatcher resource object
/// @param properties               Unit configuration data
/// @param scenario_train_id        Identifies the scenario train
///
GradientProfileUnit::GradientProfileUnit(Comms::Gateway &gateway,
                        Common::DataAccess              &data_access,
                        WorldAPI::WorldAccess           &world_access,
                        Core::BaseScenarioData          &scenario_data,
                        const Common::Properties        &properties,
                        const int                        scenario_train_id)
    : Comms::SteppingUnit(gateway),
      m_path_geometry_calculated(false),
      m_gradients_calculated(false),
      m_scenario_train_id(scenario_train_id),
      m_last_loco_position(0.0),
      m_current_loco_position(0.0),
      m_train_length_service(scenario_data.scenario_id, Train::Database::Train(data_access)),
      m_gateway(gateway),
      m_world_access(world_access)
{
    // We need a lock to access the root object
    const OS::Lock<Comms::Gateway> COMMS_LOCK(gateway);

    // Read configurations
    m_step_distance         = properties.GetProperty<double>(GRADIENT_CONFIG_SECTION_NAME, STEP_DISTANCE, STEP_DISTANCE_DEFAULT);
    m_min_gradient_distance = properties.GetProperty<double>(GRADIENT_CONFIG_SECTION_NAME, MIN_GRADIENT_DISTANCE, MIN_GRADIENT_DISTANCE_DEFAULT);
    m_min_acceptable_change = properties.GetProperty<double>(GRADIENT_CONFIG_SECTION_NAME, MIN_ACCEPTABLE_CHANGE, MIN_ACCEPTABLE_CHANGE_DEFAULT);

    auto hub_id   = Core::Properties::GetHubID(properties, data_access);
    auto hub_data = Core::GetHubData(scenario_data, hub_id);
    m_driving_vehicle_index = hub_data.vehicle_index;

    m_train_length = m_train_length_service.GetTrainLength(m_scenario_train_id);

    // NOTE BUG?: This line throws an assertion because the point_watcher expect to be detached from the root object when this call is made.
    // However the defalt contructor for the points_watcher_resource is already attaching to the root object.
    // The default request frequency is left unmodified & remains at the default, which in FeatureWatcher::m_request_frequency remains uninitialised.
    //m_points_watcher.SetRequestFrequency(COMMS_REQUEST_FREQUENCY);

    // Had to use our own PointsWatcher because the points_watcher_resource Attaches without allowing us to set the request frequency, 
    // In fact, the points_watcher_resources leaves m_request_frequency uninitialised...
    m_points_watcher.SetAcceptableTypes(data_access);
    m_points_watcher.SetRequestFrequency(COMMS_REQUEST_FREQUENCY);
    m_points_watcher.Attach(gateway.GetRootObject());

    m_geometry.reset();
    m_track_gradient_info.clear();
    m_pscenario_train_path_watcher.reset();

    AddCreationCallback(gateway.GetRootObject(), [this](Comms::Object object) { this->ObjectCreated(object); });
}

/// Destructor
///
GradientProfileUnit::~GradientProfileUnit()
{
}

/// Returns a string holding the name of this unit.
///
std::string GradientProfileUnit::GetName() const
{
    return "Gradient Profile Unit";
}

/// Called when a comms object of interest is created.
///
/// @param object The newly created object.
///
void GradientProfileUnit::ObjectCreated(Comms::Object object)
{
    assert(object.IsValid());
    const auto local_lock = Lock();

    const int object_class_id = Core::GetClassID(object);

    switch(object_class_id)
    {
    case Core::ClassID::WORLD:
        Comms::AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
        break;

    case Train::ClassID::TRAIN:
        {
            auto number = GetRequiredNumber(object, Train::ValueName::Train::SCENARIO_TRAIN_ID);
            if(number.id != Sim::INVALID_NUMBER)
            {
                if(static_cast<int>(number.value) == m_scenario_train_id)
                {
                    m_train_object  = object;
                    m_pscenario_train_path_watcher.reset(new WorldAPI::TrainPathWatcher(m_world_access, m_points_watcher, COMMS_REQUEST_FREQUENCY, object));
                    if(m_pscenario_train_path_watcher)
                    {
                        const std::lock_guard<WorldAPI::TrainPathWatcher> path_watcher_lock(*m_pscenario_train_path_watcher);
                        m_pscenario_train_path_watcher->AddRouteChangeCallback(MakeCallback(&GradientProfileUnit::RouteChanged, this));
                    }

                    m_loco_pos_id   = GetRequiredNumber(object, Project::ValueName::Train::LLO_LEAD_LOCO_POSITION).id;

                    // Note that as part of its initialisation the train could change these values and so it is 
                    // necessary to make sure that the value is periodically refreshed
                    std::vector<Sim::RequestInfo<Sim::Number>> number_requests;
                    number_requests.push_back(object.Numbers().Info().GetInfo(m_loco_pos_id));

                    object.Numbers().Store().Request(number_requests.begin(), number_requests.end(), COMMS_REQUEST_FREQUENCY);

                    // Listen for the creation of train child objects
                    Comms::AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
                }
            }
        }
        break;

    case Train::ClassID::VEHICLE:
        {
            if (Sim::Project::IsLeadVehicle(object))
            {
                // Listen for the creation of vehicle child objects
                Comms::AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
            }
        }
        break;

    case Project::ClassID::CBTC_ONBOARD_INPUTS:
        {
             m_gradient_object = object;
             m_gradient_profile_raw = GetRequiredRaw(object, Project::ValueName::CBTCOnboardInputs::GRADIENT_DATA);
        }
        break;
    }
}

/// Returns true if all the required data is available
bool GradientProfileUnit::IsRequiredDataAvailable() const
{
    const auto local_lock = Lock();
    return (m_gradient_object.IsValid() && m_train_object.IsValid() && m_pscenario_train_path_watcher);
}

/// Callback for route change
void GradientProfileUnit::RouteChanged()
{
    assert(m_pscenario_train_path_watcher->HasLock());
    const auto local_lock = Lock();

    m_path_geometry_calculated = false;
    m_gradients_calculated = false;
}

bool GradientProfileUnit::IsGradientCalculationRequired() const
{
    const auto local_lock = Lock();
    return (!m_gradients_calculated);
}

/// Gets the geometry of the path, which is cached until the path changes
const std::shared_ptr<WorldAPI::SegmentPathGeometry> GradientProfileUnit::GetPathGeometry()
{
    assert(m_pscenario_train_path_watcher->HasLock());
    assert(HasLock());

    if(m_pscenario_train_path_watcher->HasPath())
    {
        if(!m_path_geometry_calculated)
        {
            m_geometry.reset(new WorldAPI::SegmentPathGeometry(m_world_access.GetSegmentPathGeometry(m_pscenario_train_path_watcher->GetPath())));
            m_path_geometry_calculated = true;
        }
    }

    return m_geometry;
}

/// Called to perform the actions that need to be done periodically
///
/// @param new_time Time at which step is run
///
void GradientProfileUnit::Step(double new_time)
{
    const std::lock_guard<Comms::Gateway> COMMS_LOCK(m_gateway);

    // Check that all of the object we required exist before doing any processing
    if (!IsRequiredDataAvailable())
        return;

    // Record the current train position 
    m_current_loco_position = m_train_object.Numbers().Store().Get(m_loco_pos_id).value;

    if(IsGradientCalculationRequired())
    {
        //Note: sequence of locks is important.
        const auto path_lock = m_pscenario_train_path_watcher->Lock();
        const auto local_lock = Lock();

        PopulateGradientProfile();
        ReduceNoiseFromGradientProfile();
        UpdateGradientProfile();

        m_gradients_calculated = true;

        // To prevent the updation of the same gradient profile, which
        // just been updated above, the below line of code will fail
        // the condition check to update gradient in same iteration
        m_last_loco_position = m_current_loco_position;
    }

    // Update gradient profile in comms object Train::Gradient only if train is moving, so
    // that unnecessary comms overhead of writing same profile in each step can be avoided
    if(std::abs(m_current_loco_position - m_last_loco_position) > 0.0)
    {
        const auto local_lock = Lock();
        UpdateGradientProfile();
        m_last_loco_position = m_current_loco_position;
    }
}

/// Gets the period of the step function
///
double GradientProfileUnit::GetPeriod() const
{
    return 1.0 / STEP_REQUEST_FREQUENCY;
}

/// This method calculates the initial gradient profile
/// of the track wrt train's current position(loco's front).
/// To avoide noisy gradient profile, this method starts
/// calculating gradients in backward direction till it finds
/// two consicutive same gardients, having configured step 
/// distance gap between them, and returns this same gradient
/// as initial gradient value in per-mille(%o).
double GradientProfileUnit::CalculateInitialGradient(const WorldAPI::SegmentPath &path)
{
    assert(m_pscenario_train_path_watcher->HasLock());
    assert(HasLock());

    double gradient_position = m_step_distance;
    double current_gradient  = 0.0;
    double past_gradient     = 0.0;
    bool different_gradient  = true;

    // Calculate path beginning distance behind the train, so that position of gradient calculation
    // won't exceed behind the beginning.
    // CalculatePathLength() gives the path length behind the train from the last vehicle,
    // hence train length needs to be added into this path length to consider it from loco's front.
    // Note: The beginning of the path is behind the loco, hence taking this distance in -ive from loco.
    double path_beginning_distance = -(CalculatePathLength(m_world_access, path, false, m_train_length) + m_train_length);

    do
    {
        gradient_position  -= m_step_distance;
        current_gradient    = CalculatePerMilleGradientAtPosition(gradient_position);
        past_gradient       = CalculatePerMilleGradientAtPosition(gradient_position - m_step_distance);
        different_gradient  = IsGradientChanged(past_gradient, current_gradient);
    }
    while(different_gradient && ((gradient_position - m_step_distance) > path_beginning_distance));

    return current_gradient;
}

/// This method calculates all gradient profiles from
/// train's current position till track end, having
/// gradient distance in multiple of configured step distance
void GradientProfileUnit::PopulateGradientProfile()
{
    assert(m_pscenario_train_path_watcher->HasLock());
    assert(HasLock());

    m_track_gradient_info.clear();

    const WorldAPI::SegmentPath &path = m_pscenario_train_path_watcher->GetPath();

    double path_end_position = CalculatePathLength(m_world_access, path, true, m_train_length);

    double last_gradient_position    = 0.0;
    double last_gradient             = CalculateInitialGradient(path);
    double current_gradient_position = m_step_distance;

    while(current_gradient_position < path_end_position)
    {
        double current_gradient = CalculatePerMilleGradientAtPosition(current_gradient_position);

        if(IsGradientChanged(last_gradient, current_gradient))
        {
            GradientInfo gradient_info;
            gradient_info.first  = current_gradient_position - last_gradient_position;
            gradient_info.second = last_gradient;

            m_track_gradient_info.push_back(gradient_info);

            last_gradient = current_gradient;
            last_gradient_position = current_gradient_position;
        }
        current_gradient_position += m_step_distance;
    }

    GradientInfo last_gradient_info;
    last_gradient_info.first  = path_end_position - last_gradient_position;
    last_gradient_info.second = last_gradient;

    m_track_gradient_info.push_back(last_gradient_info);

    if(DEBUG)
        LogGradientProfileList(m_track_gradient_info);
}

/// Retruns true if the difference between given gradients
/// is at least configured value of min acceptable change.
bool GradientProfileUnit::IsGradientChanged(double last_gradient, double current_gradient) const
{
    assert(HasLock());

    bool changed = false;

    if(std::abs(last_gradient - current_gradient) >= m_min_acceptable_change)
        changed = true;

    return changed;
}

/// This method calculates the gradient in per-mille at given position.
/// It uses path geometry to get gradient value at given position relative
/// to train's front location on the track.
double GradientProfileUnit::CalculatePerMilleGradientAtPosition(double position)
{
    assert(m_pscenario_train_path_watcher->HasLock());
    assert(HasLock());

    double gradient_per_mille = 0.0;
    auto path_geometry = GetPathGeometry();

    if(path_geometry)
        gradient_per_mille = path_geometry->GetHeading(position).z * PER_MILLE_UNITS;

    return gradient_per_mille;
}

/// This method updates the remaining gradient distance of
/// the first gradient profile as per the train's current
/// position, and writes the updated profile into the comms.
void GradientProfileUnit::UpdateGradientProfile()
{
    assert(HasLock());

    if(!m_track_gradient_info.empty())
    {
        double last_travelled_distance = m_current_loco_position - m_last_loco_position;
        m_track_gradient_info.front().first -= last_travelled_distance;

        if(m_track_gradient_info.front().first <= 0.0)
            m_track_gradient_info.pop_front();

        if(!m_track_gradient_info.empty())
        {
            CBTC::Protos::GradientProfile gradient_profile;
            for(const auto &gradient_info : m_track_gradient_info)
            {
                auto gradient_profile_point = gradient_profile.add_gradient_profile();
                gradient_profile_point->set_distance(gradient_info.first);
                gradient_profile_point->set_gradient(gradient_info.second);
            }
            
            gradient_profile.set_reference_train_position(m_current_loco_position);

            std::string serialized_gradient_profile;
            gradient_profile.SerializeToString(&serialized_gradient_profile);

            m_gradient_profile_raw.value.clear();
            m_gradient_profile_raw.value.assign(serialized_gradient_profile.cbegin(), serialized_gradient_profile.cend());

            if(m_gradient_object.IsValid() && m_gradient_profile_raw.id != Sim::INVALID_RAW)
                m_gradient_object.Raws().Store().Set(m_gradient_profile_raw);
        }
    }
}

/// This method reduces the Noise present in gradient profile caused by noisy track.
/// Noise in gradient profile are basically those profiles, which are having shorter
/// gradient distances(lesser than m_min_gradient_distance). Hence to reduce such noise
/// the mean gradient value gets calculated of such continuous profiles(if any), and
/// these profiles gets replaced by the calculated mean gradient profile.
void GradientProfileUnit::ReduceNoiseFromGradientProfile()
{
    assert(HasLock());

    if(!m_track_gradient_info.empty())
    {
        auto iter_current = m_track_gradient_info.begin();
        auto iter_last = iter_current;
        auto iter_first_participating_gradient = iter_current;

        double mean_gradient_dividend = 0.0;
        double mean_gradient_divisor = 0.0;
        bool first_iteration = true; // Need this flag to determine when first element in list needs to be deleted

        while(iter_current != m_track_gradient_info.end())
        {
            bool current_iterator_incremented = false;
            if (((iter_current->first + mean_gradient_divisor) < m_min_gradient_distance) && 
                (std::next(iter_current) != m_track_gradient_info.end()))
            {
                mean_gradient_dividend += (iter_current->first * iter_current->second);
                mean_gradient_divisor += iter_current->first;

                if((iter_current == m_track_gradient_info.begin()) || first_iteration)
                    iter_first_participating_gradient = m_track_gradient_info.begin();
                else
                    iter_first_participating_gradient = std::next(iter_last);
            }
            else
            {
                first_iteration = false;
                if(mean_gradient_divisor > 0.0)
                {
                    double mean_gradient = 0.0;
                    auto iterator_to_erase = iter_current;
                    if(mean_gradient_divisor < m_min_gradient_distance)
                    {
                        // Add current gradient profile in calculating mean gradient.
                        mean_gradient_dividend += (iter_current->first * iter_current->second);
                        mean_gradient_divisor += iter_current->first;

                        iterator_to_erase = std::next(iter_current);
                    }

                    // Calculate the mean gradient
                    mean_gradient = mean_gradient_dividend / mean_gradient_divisor;

                    // Replace all mean gradient calculation participent
                    // gradient profiles, with this calculated mean gradient
                    // 1. Erase all participating gradient profiles.
                    iter_current = m_track_gradient_info.erase(iter_first_participating_gradient, iterator_to_erase);
                    // 2. Insert the mean gradient before iter_current position
                    iter_last = m_track_gradient_info.insert(iter_current, std::make_pair(mean_gradient_divisor, mean_gradient));

                    current_iterator_incremented = true;
                    mean_gradient_dividend = 0.0;
                    mean_gradient_divisor = 0.0;
                }
                else
                {
                    iter_last = iter_current;
                }
            }

            if(iter_current != m_track_gradient_info.end() && (!current_iterator_incremented))
                ++iter_current;
        }

        // As a second pass, rounding off the gradient value to its
        // nearest integer, and merge any equivalent gradient profile
        // which may got introduced due to mean gradient insertions.
        iter_current = m_track_gradient_info.begin();
        iter_last = iter_current;

        while(iter_current != m_track_gradient_info.end())
        {
            //Round off the gradient value to its nearest integer
            iter_current->second = std::floor(iter_current->second + 0.5);

            // Skip the first profile because no any past profile
            // available to compare it with.
            if(iter_current == m_track_gradient_info.begin())
            {
                ++iter_current;
                continue;
            }

            // If current gradient is equivalent to last gradient
            // then increase the distance of last gradient till
            // current gradient distance and remove current profile.
            if(!IsGradientChanged(iter_last->second, iter_current->second))
            {
                iter_last->first += iter_current->first;
                iter_current = m_track_gradient_info.erase(iter_current);
            }
            else
            {
                iter_last = iter_current;
                ++iter_current;
            }
        }
    }

    if(DEBUG)
        LogGradientProfileList(m_track_gradient_info);
}
