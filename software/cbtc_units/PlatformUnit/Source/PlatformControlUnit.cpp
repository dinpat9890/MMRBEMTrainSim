///**************************************************************************************************
/// @file         PlatformControlUnit.cpp
///
/// Description : Unit for controlling CBTC functionality associated with a platform
///
/// @author       Adam Zielinski
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2016
///**************************************************************************************************

#include "PlatformControlUnit.h"

#include "core_types/SessionData.h"

#include <train_data_access/TrainDataAccess.h>

#include "Project/Utilities/IsLeadVehicle.h"
#include "Project/Utilities/ScenarioTrainLengthService.h"

#include "core_comms_structure/CoreObjectConstants.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "project_comms_structure/ProjectObjectDefinition.h"

#include "Utility/Utilities.h"

#include "common/StandardLogging.h"

using namespace FeatureInterfaces;
using namespace PlatformControl;

namespace
{
    const auto STEP_REQUEST_FREQUENCY     = 20.0;
    const auto COMMS_REQUEST_FREQUENCY    = 0.0;
    const auto INVALID_TIME               = -1.0;
    const auto MAX_ALLOWED_OVERSHOOT_6_car= 25.0;
    const auto MAX_ALLOWED_OVERSHOOT_8_car= 44.0;
    const auto STATIONARY_SPEED_THRESHOLD = 0.1;
    const auto MAX_LOOKAHEAD_DISTANCE     = 1000;

    const int NO_OF_DOOR_PAIRS_PER_VEHICLE = 4;

    const auto DEBUG = false;
}

///////////////////////////////////////////////////////////////////////////////////////////
// PlatformControlUnit Public functions
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
PlatformControlUnit::PlatformControlUnit(Comms::Gateway&             gateway,
                                         Common::Data::DataAccess&   data_access,
                                         WorldAPI::WorldAccess&      world_access,
                                         WorldAPI::TrainPathWatcher& path_watcher,
                                         const PlatformProperties&   properties,
                                         int                         scenario_train_id)
  : Comms::SteppingUnit(gateway)
  , m_gateway(gateway)
  , m_scenario_train_id(scenario_train_id)
  , m_feature_region_data(gateway, data_access, world_access, path_watcher, MAX_LOOKAHEAD_DISTANCE)
  , m_stopping_point_data(gateway, data_access, world_access, path_watcher)
  , m_plaform_screen_doors(gateway,
                           data_access,
                           world_access,
                           [this](const int platform_feature_id,
                                  const PlatformControl::PlatformScreenDoors::PlatformDoors::DoorState state) {})
  , m_docking_tolerance(properties.GetDockingTolerance())
  , m_psd_close_time(properties.GetPSDCloseTime())
  , m_psd_open_time(properties.GetPSDOpenTime())
  , m_train_door_open_time(properties.GetTrainDoorOpenTime())
  , m_train_door_close_time(properties.GetTrainDoorCloseTime())
  , m_close_warning_time(properties.GetCloseWarningTime())
  , m_max_door_closing_time(properties.GetMaxDoorClosingTime())
  , m_max_closed_and_locked_time(properties.GetMaxDoorClosedAndLockedTime())
  , m_max_train_doors_unlocking_time(properties.GetMaxTrainDoorUnlockingTime())
  , m_overshoot_distance(properties.GetOvershootDistance())
  , m_docked_at_station(false)
  , m_dwell_end_time(INVALID_TIME)
  , m_remaining_dwell_time(INVALID_TIME)
  , m_request_door_open_time(INVALID_TIME)
  , m_request_door_close_time(INVALID_TIME)
  , m_psd_present(false)
  , m_previous_train_speed(0.0)
  , m_previous_driving_mode(Project::TypeValue::CurrentDrivingMode::NO_MODE)
  , m_previous_mode_selector_position(Project::TypeValue::CurrentDrivingMode::NO_MODE)
  , m_open_door_request_pending(true)
{
    m_number_of_cars = 0;
    // We need a lock to access the root object
    const OS::Lock<Comms::Gateway> COMMS_LOCK(gateway);
    AddCreationCallback(gateway.GetRootObject(), [this](Comms::Object object) { this->RootChildCreated(object); });

    // Attach the feature requester now on the root object, and it should do its job for the session!
    m_feature_requester.Attach(GetGateway().GetRootObject());

    // Determine the number of platform doors
    m_number_of_platform_doors = 0;

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "PlatformControlUnit - Started" << Trace::EndLog();
}

/// Destructor
///
PlatformControlUnit::~PlatformControlUnit()
{
    OS::Lock<Comms::Gateway> lock(m_gateway);

    m_feature_requester.Detach();
}

/// Returns a string holding the name of this unit.
///
std::string PlatformControlUnit::GetName() const
{
    return "Platform Control Unit";
}

/// Step function for the unit which call the LMA update function
///
void PlatformControlUnit::Step(double new_time)
{
    // Make sure that the unit has completed initialisation before continuing
    if (!m_mapped_cbtc_onboard_inputs.IsValid() && !m_mapped_cbtc_onboard_outputs.IsValid() &&
        !m_mapped_cbtc_platform_inputs.IsValid() && !m_mapped_cbtc_platform_outputs.IsValid() &&
        !m_mapped_cbtc_vehicle_outputs.IsValid() && !m_mapped_cbtc_vehicle_inputs.IsValid())
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE)
          << "PlatformControlUnit - Unit is Missing all required objects" << Trace::EndLog();
        return;
    }

    // Updating our model. Make sure that we have the lock
    OS::Lock<Comms::Gateway> lock(m_gateway);

    // Update the values being read from the Platform control interface
    // Using a polled architecture since we are not receiving any pulsed signals and we want to limit the update rate
    {
        m_mapped_train_inputs.Get();
        m_mapped_cbtc_onboard_outputs.Get();
        m_mapped_cbtc_platform_inputs.Get();
        m_mapped_cbtc_vehicle_outputs.Get();
        m_mapped_cbtc_vehicle_inputs.Get();
        m_mapped_vehicle_inputs.Get();
    }
    bool          find_whole_train_in_region = true;
    Comms::Object region_object;
    double        distance_to_feature_region = m_feature_region_data.GetDistanceToFeatureRegionEnd(
      m_scenario_train_id, FeatureRegion::RegionType::AUTOMATIC);

    if (m_feature_region_data.TrainFrontWithinFeatureRegion(m_scenario_train_id, FeatureRegion::RegionType::DEPOT, region_object))
    {
        m_mapped_cbtc_onboard_inputs.depot_region    = Project::TypeValue::DepotIndication::DEPOT;
    }
    else if (m_feature_region_data.GetDistanceToFeatureRegionEnd(m_scenario_train_id, FeatureRegion::RegionType::DEPOT) <= 0)
    {
        m_mapped_cbtc_onboard_inputs.depot_region = Project::TypeValue::DepotIndication::NO_DISPLAY;
    }

    if (m_feature_region_data.TrainFrontWithinFeatureRegion(m_scenario_train_id, FeatureRegion::RegionType::NON_ATC, region_object))
    {
        m_mapped_cbtc_onboard_inputs.atp_zone_region = Project::TypeValue::ATPZoneStatus::NON_ATP_ZONE;
    }
    else if (m_feature_region_data.GetDistanceToFeatureRegionEnd(m_scenario_train_id, FeatureRegion::RegionType::NON_ATC) <= 0)
    {
        m_mapped_cbtc_onboard_inputs.atp_zone_region = Project::TypeValue::ATPZoneStatus::OTHERWISE;
    }

    distance_to_feature_region = m_feature_region_data.GetDistanceToFeatureRegionEnd(m_scenario_train_id,
                                                                                     FeatureRegion::RegionType::DEPOT);

    if (m_feature_region_data.IsNextRegionAtDistance(m_scenario_train_id, FeatureRegion::RegionType::NON_ATC, 30) &&
        (!m_feature_region_data.TrainFrontWithinFeatureRegion(m_scenario_train_id, FeatureRegion::RegionType::NON_ATC, region_object)))
    {
        m_mapped_cbtc_onboard_inputs.atp_zone_region = Project::TypeValue::ATPZoneStatus::ABOUT_TO_LEAVE_ATP_ZONE;
    }

    // Find the data about the next station that the train is appproaching
    auto start_distance               = (-1.0 * MAX_ALLOWED_OVERSHOOT_6_car);

    if(m_number_of_cars == 8)
        start_distance                = (-1.0 * MAX_ALLOWED_OVERSHOOT_8_car);

    auto next_stopping_point_data     = m_stopping_point_data.GetNextStoppingPointData(start_distance, std::numeric_limits<double>::max(), m_scenario_train_id);
    auto next_stopping_point_distance = next_stopping_point_data.first;
    auto next_stopping_point          = next_stopping_point_data.second;

    // Determine if Platform Screen Doors are present at the next station
    auto next_plaform_screen_door = m_plaform_screen_doors.GetPlatformScreenDoor(next_stopping_point.GetPlatformFeatureId());
    if (next_plaform_screen_door != nullptr)
        m_psd_present = true;
    else
        m_psd_present = false;

    HandleTrainDocking(new_time, next_stopping_point_distance, next_stopping_point);

    if ((abs(m_previous_train_speed) > STATIONARY_SPEED_THRESHOLD && abs(m_mapped_train_inputs.train_speed) <= STATIONARY_SPEED_THRESHOLD) ||
        ((m_previous_driving_mode != m_mapped_cbtc_onboard_outputs.current_driving_mode) &&
        (abs(m_mapped_train_inputs.train_speed) <= STATIONARY_SPEED_THRESHOLD)))
    {
        if (m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::NO_BYPASS)
        {
            Comms::Object region_object;

            auto train_docking_status = CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_UNKNOWN;        
            
            //MMRBEM-4338 : Missed correct dock condition added. Speed drop at 10kmph at station issue resolved.
            if (m_docked_at_station && m_mapped_cbtc_onboard_inputs.train_near_platform == Project::TypeValue::PlatformRegion::WITHIN_REGION)
                train_docking_status = CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_CORRECTLY_DOCKED;
            else if ((next_stopping_point_distance > 0.0) && m_feature_region_data.TrainFrontWithinFeatureRegion(
                m_scenario_train_id, FeatureRegion::RegionType::STATION, region_object))
                train_docking_status = CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_SHORT_STOP;
            else if (abs(next_stopping_point_distance) < m_overshoot_distance)
                train_docking_status = CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_LONG_STOP;
            else if ((abs(next_stopping_point_distance) >= m_overshoot_distance) &&
                (next_stopping_point_distance < m_overshoot_distance))
                train_docking_status = CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_TOO_LONG_STOP;

            m_mapped_cbtc_platform_outputs.train_docking_status = static_cast<int>(train_docking_status);
            m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(train_docking_status, 0);
        }
    }
    else if ((m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP) &&
        (abs(m_mapped_train_inputs.train_speed) >= STATIONARY_SPEED_THRESHOLD) &&
        (next_stopping_point_distance <= 180) && (next_stopping_point_distance >= 0))
    {
        auto train_docking_status = CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_OPERATIONAL_SERVICE_STOPPING_DISTANCE;
        int  stopping_distance = static_cast<int>(next_stopping_point_distance + 0.5);

        m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(train_docking_status, stopping_distance);
    }
    else if ((m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::RMR) &&
        (abs(m_mapped_train_inputs.train_speed) >= STATIONARY_SPEED_THRESHOLD) &&
        (abs(next_stopping_point_distance) < m_overshoot_distance) && (next_stopping_point_distance <= 10) &&
        (next_stopping_point_distance >= -10))
    {
        auto train_docking_status = CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_OPERATIONAL_SERVICE_STOPPING_DISTANCE;
        int  stopping_distance = -1 * static_cast<int>(next_stopping_point_distance + 0.5);

        m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(train_docking_status, stopping_distance);
    }
    else if ((abs(next_stopping_point_distance) <= m_docking_tolerance) &&
             abs(m_mapped_train_inputs.train_speed) <= STATIONARY_SPEED_THRESHOLD &&
             m_mapped_cbtc_onboard_inputs.train_near_platform == Project::TypeValue::PlatformRegion::WITHIN_REGION &&
        ((m_mapped_cbtc_onboard_inputs.platform_status == Project::TypeValue::PlatformStatus::NOT_DOCKED) ||
         (m_mapped_cbtc_onboard_inputs.platform_status == Project::TypeValue::PlatformStatus::DOCKED) ||
        (m_mapped_cbtc_onboard_inputs.platform_status == Project::TypeValue::PlatformStatus::IMMEDIATE_DEPARTURE)) )
    {
        m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_CORRECTLY_DOCKED, 0);
    }
    else if (abs(m_mapped_train_inputs.train_speed) >= STATIONARY_SPEED_THRESHOLD)
        m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_UNKNOWN, 0);

    if (m_docked_at_station)
    {
        m_number_of_platform_doors = 0;
        m_number_of_platform_doors = m_number_of_cars * NO_OF_DOOR_PAIRS_PER_VEHICLE;
        // Trace::GetLogger().STAMP(Trace::INFO)
        //  << "PlatformControlUnit - Number of Platform Doors:" << m_number_of_platform_doors << Trace::EndLog();

        // Determine how many seconds until the dwell time repires
        m_remaining_dwell_time = m_dwell_end_time - new_time;

        // Clear the remaining dwell time if train is suppose to perform an immediate departure or dwell timer has
        // expired
        if ((next_stopping_point.GetDwellTime() == 0.0) || (m_remaining_dwell_time < 0.0))
            m_remaining_dwell_time = 0.0;

        // Added below condition to reset the dwell timer to "ZERO", if mode selector is changed after docking of train
        /*if ((m_previous_mode_selector_position != m_mapped_cbtc_vehicle_outputs.mode_selector_position) && 
            (m_mapped_cbtc_vehicle_outputs.mode_selector_position == Project::TypeValue::ModeSelector::ATP || m_mapped_cbtc_vehicle_outputs.mode_selector_position == Project::TypeValue::ModeSelector::ATO) ) 
        {
            m_remaining_dwell_time = 0.0;
        }
        else
        {
            m_previous_mode_selector_position = m_mapped_cbtc_vehicle_outputs.mode_selector_position;
        }*/

        HandleTrainDoorRequests(new_time);

        // Open and close the Platform doors if PSD present
        if (m_psd_present)
            ControlPlatformDoors(new_time, next_stopping_point, next_plaform_screen_door);
    }
    else
        m_previous_mode_selector_position = m_mapped_cbtc_vehicle_outputs.mode_selector_position;

    // Notify the CCTV unit when the train is near a platform with PSD/PSG
    if (m_mapped_cbtc_onboard_inputs.train_near_platform == Project::TypeValue::PlatformRegion::WITHIN_REGION)
        m_mapped_cctv_inputs.platform_cctv = m_mapped_cctv_inputs.PLATFORM_PRESENT;
    else if (m_mapped_cbtc_onboard_inputs.train_near_platform == Project::TypeValue::PlatformRegion::EXITING_REGION)
    {
        m_mapped_cctv_inputs.platform_cctv = m_mapped_cctv_inputs.LEAVING_PLATFORM;
        // PG Interlock override status should be reset once train start leaving station
        m_mapped_cbtc_platform_outputs.psd_interlock_override_status = Project::TypeValue::IndicatorState::OFF;
    }
    else
        m_mapped_cctv_inputs.platform_cctv = m_mapped_cctv_inputs.PLATFORM_NOT_PRESENT;

    // Set the Platform data that is to be reported to the DMI via plaform outputs
    // Added ATO in OR condition code so that train_door_status will be available in ATO mode also as per requirements
    if (
        ((m_mapped_cbtc_onboard_outputs.current_driving_mode != Project::TypeValue::CurrentDrivingMode::NO_MODE) 
         &&(m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::NO_BYPASS))
         || m_mapped_cbtc_vehicle_outputs.mode_selector_position == Project::TypeValue::ModeSelector::STANDBY
         || m_mapped_cbtc_vehicle_outputs.mode_selector_position == Project::TypeValue::ModeSelector::ATO
         || m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::BYPASS_ENABLED
        )
    {
        ReportDepartureInfo(next_stopping_point);
        ReportDepartureOrder(next_stopping_point);
        ReportTrainDoorStatus(new_time);
        ReportPSDDoorStatus(next_plaform_screen_door);
    }
    else
    {
        m_mapped_cbtc_platform_outputs.departure_order = Project::TypeValue::DepartureOrder::NO_ORDER;
        m_mapped_cbtc_platform_outputs.SetDepartureInfoRaw(CBTC::Protos::DepartureInformation_DepartureStatus_NO_INDICATION, 0);
        m_mapped_cbtc_platform_outputs.train_door_status    = Project::TypeValue::TrainDoorStatus::UNKNOWN;
        m_mapped_cbtc_platform_outputs.psd_door_status      = Project::TypeValue::PSDDoorStatus::UNAVAILABLE;
        m_mapped_cbtc_platform_outputs.train_docking_status = Project::TypeValue::TrainDockingStatus::UNKNOWN;
        //m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(CBTC::Protos::TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_UNKNOWN, 0);
    }

    // Set the Platform data that is to be reported to the CBTC Onboard
    ReportPlatformInfo(m_psd_present, next_stopping_point, next_stopping_point_distance);

    //Handle PSD ADCL status not available fault
    HandleAdclStatusNotAvailableFault();

    // Generate the ouput message and send the update LMA output data to the CBTC Onboard Inputs Comms object
    // Send the updates to the Updated Comms objects
    {
        m_mapped_cbtc_onboard_inputs.Set();
        m_mapped_cbtc_platform_outputs.Set();

        if (m_mapped_cctv_inputs.IsValid())
            m_mapped_cctv_inputs.Set();
    }

    // Record any data collected in the current time step so that we can determine how it changes in the next time step
    m_previous_train_speed  = m_mapped_train_inputs.train_speed;
    m_previous_driving_mode = m_mapped_cbtc_onboard_outputs.current_driving_mode;
}

/// Gets the period of the step function
///
double PlatformControlUnit::GetPeriod() const
{
    return 1.0 / STEP_REQUEST_FREQUENCY;
}

/// Manages the information associated with docking the train at a platform
///
/// Determines and reports the following output data:
///    - CBTCPlatformOutputs::TRAIN_DOCKING_INFO
///
/// @param current_time                 : Scenario time at which function called
/// @param next_stopping_point_distance : Distance to next stopping point
/// @param next_stopping_point          : Data associated with the next stopping point
///
void PlatformControlUnit::HandleTrainDocking(double current_time, double next_stopping_point_distance, StoppingPoint::FeatureData next_stopping_point)
{
    using namespace CBTC::Protos;

    TrainDockingInfo_TrainDockingStatus train_docking_status = TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_UNKNOWN;
    int                                 stopping_distance         = 0;
    bool                                clear_docking_information = false;

    // Docking Information is only managed by the platform control unit when
    // - CBTC is in ATP, ATO or RMR modes
    // - Train is approaching a stopping point which is not identifies as being a skip station
    if (((m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO) ||
         (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::UTO) ||
         (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP) ||
         (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::RMR) ||
         (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::RMF) ||
         (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::NO_MODE) ||
         (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATC_BYPASS)) &&
        (next_stopping_point.IsValid() /*&& !next_stopping_point.IsChangeOfEnds()*/ && !next_stopping_point.IsSkip()))
    {
        // Train has become parked or there was a mode change while the train was already parked, so determine the
        // docking information
        if ((abs(m_previous_train_speed) > STATIONARY_SPEED_THRESHOLD && abs(m_mapped_train_inputs.train_speed) <= STATIONARY_SPEED_THRESHOLD) ||
            ((m_previous_driving_mode != m_mapped_cbtc_onboard_outputs.current_driving_mode) &&
             (abs(m_mapped_train_inputs.train_speed) <= STATIONARY_SPEED_THRESHOLD)))
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "PlatformUnit - Train has Stopped" << Trace::EndLog();

            // Record when the train has become docked and the time at which it happens
            if ((abs(next_stopping_point_distance) <= m_docking_tolerance) &&
                ((m_mapped_cbtc_onboard_inputs.platform_status == Project::TypeValue::PlatformStatus::NOT_DOCKED) ||
                 (m_mapped_cbtc_onboard_inputs.platform_status == Project::TypeValue::PlatformStatus::IMMEDIATE_DEPARTURE)) /*&&
                (m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::NO_BYPASS)*/)
                //MMRBEM-4413 - Commented last condition to work PSD door open in safety cut ou mode
            {
                // In CM mode need to prompt the driver to open the doors after docking
                if (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP ||
                    m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO)
                    m_open_door_request_pending = true;

                m_docked_at_station = true;
                m_dwell_end_time    = current_time + next_stopping_point.GetDwellTime();
            }

            //  Need to determine the train docking status now that it has come to a standstill
            // Unknown if non of following true
            // - Docked   : within docking tolerance of SSP
            // - Short    : Stopped short of SSP while in station region
            // - Long     : Overshot by less than max reversing distance
            // - Too Long : Overshot by more than max reversing distance and less than max SSP lookback distance
            auto train_docking_status = TrainDockingInfo_TrainDockingStatus_UNKNOWN;

            if (m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::NO_BYPASS)
            {
                Comms::Object region_object;

                if (m_docked_at_station &&
                    m_mapped_cbtc_onboard_inputs.train_near_platform == Project::TypeValue::PlatformRegion::WITHIN_REGION)
                    train_docking_status = TrainDockingInfo_TrainDockingStatus_CORRECTLY_DOCKED;
                else if ((next_stopping_point_distance > 0.0) && m_feature_region_data.TrainFrontWithinFeatureRegion(
                                                                   m_scenario_train_id, FeatureRegion::RegionType::STATION, region_object))
                    train_docking_status = TrainDockingInfo_TrainDockingStatus_SHORT_STOP;
                else if (abs(next_stopping_point_distance) < m_overshoot_distance)
                    train_docking_status = TrainDockingInfo_TrainDockingStatus_LONG_STOP;
                else if ((abs(next_stopping_point_distance) >= m_overshoot_distance) &&
                         (next_stopping_point_distance < m_overshoot_distance))
                    train_docking_status = TrainDockingInfo_TrainDockingStatus_TOO_LONG_STOP;
                m_mapped_cbtc_platform_outputs.train_docking_status = static_cast<int>(train_docking_status);
                //m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(train_docking_status, 0);
            }
        }

        // Train has started moving away from station so clear the docking information
        else if (abs(m_previous_train_speed) < STATIONARY_SPEED_THRESHOLD && abs(m_mapped_train_inputs.train_speed) >= STATIONARY_SPEED_THRESHOLD)
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "PlatformUnit - Train has Departed" << Trace::EndLog();
            clear_docking_information                                    = true;
            //m_mapped_cbtc_platform_outputs.psd_interlock_override_status = Project::TypeValue::IndicatorState::OFF;
            //m_mapped_cbtc_platform_inputs.psd_interlock_override         = Project::TypeValue::IndicatorState::OFF;
        }
    }

    // Conditions for reporting train docking information are no longer being met
    else
        clear_docking_information = true;

    // If train is in CM mode and approaching the next stopping point we want to tell the driver how far they have to go
    if ((m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP) &&
        (abs(m_mapped_train_inputs.train_speed) >= STATIONARY_SPEED_THRESHOLD) &&
        (next_stopping_point_distance <= 180) && (next_stopping_point_distance >= 0))
    {
        auto train_docking_status = TrainDockingInfo_TrainDockingStatus_OPERATIONAL_SERVICE_STOPPING_DISTANCE;
        int  stopping_distance    = static_cast<int>(next_stopping_point_distance + 0.5);

        //m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(train_docking_status, stopping_distance);
    }

    else if ((m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::RMR) &&
             (abs(m_mapped_train_inputs.train_speed) >= STATIONARY_SPEED_THRESHOLD) &&
             (abs(next_stopping_point_distance) < m_overshoot_distance) && (next_stopping_point_distance <= 10) &&
             (next_stopping_point_distance >= -10))
    {
        auto train_docking_status = TrainDockingInfo_TrainDockingStatus_OPERATIONAL_SERVICE_STOPPING_DISTANCE;
        int  stopping_distance    = -1 * static_cast<int>(next_stopping_point_distance + 0.5);

        //m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(train_docking_status, stopping_distance);
    }

    else if (abs(m_mapped_train_inputs.train_speed) >= STATIONARY_SPEED_THRESHOLD)
    {
        auto train_docking_status = TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_UNKNOWN;
        auto stopping_distance    = 0;
        //m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(train_docking_status, stopping_distance);

        if (next_stopping_point_distance > 0)
            m_mapped_cbtc_platform_outputs.train_docking_status = Project::TypeValue::TrainDockingStatus::UNKNOWN;
    }

    // Need to clear train docking information
    if (clear_docking_information && !next_stopping_point.IsHold())
    {
        m_docked_at_station    = false;
        m_dwell_end_time       = INVALID_TIME;
        m_remaining_dwell_time = INVALID_TIME;

        auto train_docking_status = TrainDockingInfo_TrainDockingStatus::TrainDockingInfo_TrainDockingStatus_UNKNOWN;
        auto stopping_distance    = 0;
        //m_mapped_cbtc_platform_outputs.SetTrainDockingInfoRaw(train_docking_status, stopping_distance);
    }
}

/// Handles the requests that report when the request to open and close train doors is triggered
///
/// @param current_time  : Scenario time at which function called
///
void PlatformControlUnit::HandleTrainDoorRequests(double current_time)
{
    // Driver or Onboard has sent request to open the train doors
    if ((m_request_door_open_time == INVALID_TIME) &&
          ((m_mapped_cbtc_vehicle_outputs.lhs_door_open_request == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED ||
            m_mapped_cbtc_vehicle_inputs.lhs_auto_door_open_request == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED) &&
           m_mapped_cbtc_vehicle_inputs.lhs_door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED) ||
        ((m_mapped_cbtc_vehicle_outputs.rhs_door_open_request == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED ||
          m_mapped_cbtc_vehicle_inputs.rhs_auto_door_open_request == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED) &&
         m_mapped_cbtc_vehicle_inputs.rhs_door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED))

    {
        // When ATC orders doors to open, until train doors open, the platform unit needs to report train door
        // opening
        if ((m_mapped_cbtc_vehicle_inputs.lhs_auto_door_open_request == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED) ||
            (m_mapped_cbtc_vehicle_inputs.rhs_auto_door_open_request == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED))
        {
            m_open_door_request_pending = true;
        }

        m_request_door_open_time  = current_time;
        m_request_door_close_time = INVALID_TIME;
    }
    else if ((m_request_door_open_time == INVALID_TIME) &&
             (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP) &&
             (m_mapped_cbtc_vehicle_outputs.lhs_door_open_request == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED ||
              m_mapped_cbtc_vehicle_outputs.rhs_door_open_request == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED))
    {
        m_request_door_open_time = current_time;
        m_request_door_close_time = INVALID_TIME;
    }

    //Door close request
    if ((m_request_door_close_time == INVALID_TIME) &&
        ((m_mapped_cbtc_vehicle_outputs.lhs_door_close_request == Project::TypeValue::CloseDoorRequest::CLOSE_DOOR_REQUESTED &&
          m_mapped_cbtc_vehicle_inputs.lhs_door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED) ||
         (m_mapped_cbtc_vehicle_outputs.rhs_door_close_request == Project::TypeValue::CloseDoorRequest::CLOSE_DOOR_REQUESTED &&
          m_mapped_cbtc_vehicle_inputs.rhs_door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED)))
    {
        m_request_door_open_time  = INVALID_TIME;
        m_request_door_close_time = current_time;
    }
	//MMRBEM-4449 : door_enable condition checked to avaoid door open/close by wrong side door open PB.
    else if ((m_request_door_close_time == INVALID_TIME) &&
             (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP || m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO) &&
             ((m_mapped_cbtc_vehicle_outputs.lhs_door_close_request == Project::TypeValue::CloseDoorRequest::CLOSE_DOOR_REQUESTED && m_mapped_cbtc_vehicle_inputs.lhs_door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED) ||
              (m_mapped_cbtc_vehicle_outputs.rhs_door_close_request == Project::TypeValue::CloseDoorRequest::CLOSE_DOOR_REQUESTED && m_mapped_cbtc_vehicle_inputs.rhs_door_enable == Project::TypeValue::CorrectSideDoorEnable::SIDE_ENABLED)))
    {
        m_request_door_open_time  = INVALID_TIME;
        m_request_door_close_time = current_time;
    }
}

///
///
/// @param current_time         : Scenario time at which function called
/// @param next_stopping_point  : Data associated with the next stopping point
/// @param next_platform_psd
///
///
void PlatformControlUnit::ControlPlatformDoors(double                                              current_time,
                                               StoppingPoint::FeatureData                          next_stopping_point,
                                               std::shared_ptr<PlatformScreenDoors::PlatformDoors> next_platform_psd)
{
    // Nothing to do if not stopped at a platform with PSD doors
    if (!next_stopping_point.IsValid() || (next_platform_psd == nullptr))
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "ControlPlatformDoors: Has invalid input data: "
                                             << (!next_stopping_point.IsValid() ? " Stopping point is Invalid." : "")
                                             << ((next_platform_psd == nullptr) ? " No PSD Present." : "") << Trace::EndLog();
        return;
    }

    // Platform doors are only controlled when CBTC in ATP,ATO and UTO mode
    // Commented below code, as we need to control the PSD, in all modes
    /*if ((m_mapped_cbtc_onboard_outputs.current_driving_mode != Project::TypeValue::CurrentDrivingMode::UTO) &&
        (m_mapped_cbtc_onboard_outputs.current_driving_mode != Project::TypeValue::CurrentDrivingMode::ATO) &&
        (m_mapped_cbtc_onboard_outputs.current_driving_mode != Project::TypeValue::CurrentDrivingMode::ATP))
    {
        return;
    }*/

    // If the train has docked at a station then we can control the PSD doors if they exist
    if (m_docked_at_station)
    {
        auto csde_code = next_stopping_point.GetCSDECode();

        if (((m_request_door_open_time != INVALID_TIME) &&
             ((m_request_door_open_time + m_train_door_open_time - current_time) < m_psd_open_time)) ||
            m_mapped_cbtc_platform_inputs.psd_open_req == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED)
        {
            //MMRBEM-4248 : Open Platform door if PDS door not opening fault is not active
            //                OR
            // if PDS door not opening fault is active  && open door request from PSL
            if (0 == m_mapped_cbtc_platform_inputs.psd_not_working ||
                (1 == m_mapped_cbtc_platform_inputs.psd_not_working && 
                m_mapped_cbtc_platform_inputs.psd_open_req == Project::TypeValue::OpenDoorRequest::OPEN_DOOR_REQUESTED)) 
            {
                if ((csde_code == StoppingPoint::CSDE_CODE::LHS) || (csde_code == StoppingPoint::CSDE_CODE::BOTH))
                    next_platform_psd->OpenPlatformDoors(m_mapped_cbtc_platform_inputs.lhs_sd_open_inhibit_code, m_number_of_platform_doors);

                if ((csde_code == StoppingPoint::CSDE_CODE::RHS) || (csde_code == StoppingPoint::CSDE_CODE::BOTH))
                    next_platform_psd->OpenPlatformDoors(m_mapped_cbtc_platform_inputs.rhs_sd_open_inhibit_code, m_number_of_platform_doors);
            }
        }

        else if (((m_request_door_close_time != INVALID_TIME) &&
                  ((m_request_door_close_time + m_train_door_close_time - current_time) < m_psd_close_time)) ||
                 m_mapped_cbtc_platform_inputs.psd_close_req == Project::TypeValue::CloseDoorRequest::CLOSE_DOOR_REQUESTED)
        {
            if ((csde_code == StoppingPoint::CSDE_CODE::LHS) || (csde_code == StoppingPoint::CSDE_CODE::BOTH))
                next_platform_psd->ClosePlatformDoors(m_mapped_cbtc_platform_inputs.lhs_sd_close_inhibit_code, m_number_of_platform_doors);

            if ((csde_code == StoppingPoint::CSDE_CODE::RHS) || (csde_code == StoppingPoint::CSDE_CODE::BOTH))
                next_platform_psd->ClosePlatformDoors(m_mapped_cbtc_platform_inputs.rhs_sd_close_inhibit_code, m_number_of_platform_doors);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// Reporting Helper functions
///////////////////////////////////////////////////////////////////////////////////////////

/// Responsible for determining the current Train Door Status
///
/// Determines and reports the following platform datato CBTC Onboard:
///    - CBTCPlatformOutputs::TRAIN_DOOR_STATUS
///
/// @param current_time : Scenario time at which function called
///
void PlatformControlUnit::ReportTrainDoorStatus(double current_time)
{
    // Determine door state when interlock signal indicates doors are closed
    if (m_mapped_cbtc_vehicle_outputs.train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED)
    {
        // Report doors are opening if open door request has been received due to door being automatically
        // opened and train doors are in the process of opening. ie Doors are still closed after request to
        // automatically open doors has been sent.
        if ((m_request_door_open_time != INVALID_TIME) &&
            (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO) && m_open_door_request_pending)
        {
            m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_OPENING;
        }

        // Otherwise report the train doors are correctly closed
        else
            m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_CLOSED;
    }

    else
    {
        // Report doors are open if open door request has been received and train doors have completed opening
        if (m_request_door_open_time != INVALID_TIME)
        {
            if ((current_time - m_request_door_open_time) > m_max_train_doors_unlocking_time)
            {
                m_open_door_request_pending                      = false;
                m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_OPEN;
            }
            else
                m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_OPENING;
        }

        // Report a door opening warning if doors opened without ATC Authorisation
        else if ((m_request_door_open_time == INVALID_TIME) && (m_request_door_close_time == INVALID_TIME))
        {
            // TBD - Not sure if we keep reporting open warning or closed.
            if (m_mapped_cbtc_vehicle_outputs.no_door_enable_bypass == Project::TypeValue::NoDoorInterlockBypass::BYPASS_ENABLED)
                m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_CLOSED;
            else
                m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_WARNING_OPEN;
        }

        // Report a door closing warning if close door request has not completed within m_max_door_closing_time
        // seconds
        else if (m_request_door_close_time != INVALID_TIME)
        {
            // TBD - Not sure if we keep reporting open warning or closed.
            if ((current_time - m_request_door_close_time) > m_max_door_closing_time && m_mapped_vehicle_inputs.door_obstruction_close == 0)
                m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_CLOSED;
            else
                m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_WARNING_CLOSING;
        }

        // Report doors open if no other condition is met
        else
        {
            m_open_door_request_pending                      = false;
            m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_OPEN;
        }
    }

    // MMRBEM-4413 : Manage train door status cut Out Mode 
    if (m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::BYPASS_ENABLED)
    {
        if (m_mapped_cbtc_vehicle_outputs.train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED)
            m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_CLOSED;
        else
            m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_OPEN;
    }

    //Overriden when PSD not opening fault set
    if (m_mapped_cbtc_platform_inputs.psd_not_working == 1)
        m_mapped_cbtc_platform_outputs.train_door_status = Project::TypeValue::TrainDoorStatus::DOOR_CLOSED;
}

/// Responsible for determining the current PSD Door Status
///
/// Determines and reports the following platform datato CBTC Onboard:
///    - CBTCPlatformOutputs::PSD_DOOR_STATUS
///
void PlatformControlUnit::ReportPSDDoorStatus(std::shared_ptr<PlatformControl::PlatformScreenDoors::PlatformDoors> next_plaform_screen_door)
{
    m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::UNAVAILABLE;

    if ((next_plaform_screen_door != nullptr) &&
        (m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::NO_BYPASS) &&
        (m_mapped_cbtc_onboard_inputs.train_near_platform != Project::TypeValue::PlatformRegion::OUTSIDE_REGION))
    {
        auto current_psd_state = next_plaform_screen_door->GetPlatformDoorsState();
        if (m_mapped_cbtc_onboard_outputs.localisation_status == Project::TypeValue::LocalisationStatus::LOCALISED ||
            m_mapped_cbtc_onboard_outputs.localisation_status == Project::TypeValue::LocalisationStatus::MEMORISED_LOCALISATION)
        {
            if (current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::CLOSED)
                m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::PSD_CLOSED;
            else if (current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::CLOSING)
                m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::PSD_CLOSING;
            else if (current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::OPEN)
                m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::PSD_OPENED;
            else if (current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::OPENING)
                m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::PSD_OPENING;
            else if ((current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::CLOSED_WITH_FAULT) ||
                     (current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::ALL_FAILED_TO_CLOSE))
              m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::PSD_CLOSING_FAILURE;
            else if (current_psd_state == PlatformScreenDoors::PlatformDoors::DoorState::OPEN_WITH_FAULT)
              m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::UNKNOWN;
            else
                m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::UNKNOWN;

            //Overriden when PSD is bypassed or when PSD Unknown fault is set
            if (m_mapped_cbtc_platform_inputs.psd_not_working == 1)
                m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::UNKNOWN;            
            
        }
    }
}

void PlatformControlUnit::HandleAdclStatusNotAvailableFault()
{
    //MMRBEM-4141 - Implementing as per documents provided by customer
    //Fault ADCL status not available  
    //Fault ACTIVE , Train docked ,PSD doors are not opened.
    double psd_door_status_to_restore = m_mapped_cbtc_platform_outputs.psd_door_status;
    if (m_docked_at_station && m_mapped_train_inputs.m_fault_adcl_status_not_available == 1 &&
        m_mapped_cbtc_platform_outputs.psd_door_status != Project::TypeValue::PSDDoorStatus::PSD_OPENED)
    {
        //Train is stopped at platform
        if (abs(m_mapped_train_inputs.train_speed) <= STATIONARY_SPEED_THRESHOLD) 
        {
            //PSD no interlock override  
            if (m_mapped_cbtc_platform_outputs.psd_interlock_override_status == Project::TypeValue::IndicatorState::OFF) 
            {
                //Make DMI door icon as PSD_CLOSING_FAILURE
                m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::PSD_CLOSING_FAILURE;

                /*assert(m_psd_outputs_object.IsValid());

                //5.Update UI ADCL lamp - OFF to show that PSD doors are open though they actually closed.
                OS::Lock<Comms::Gateway> lock(GetGateway());
                Sim::Number psd_status_number;
                psd_status_number.id = m_psd_status_id;
                psd_status_number.value = Project::TypeValue::PSDDoorStatus::PSD_OPENED;  //OFF
                m_psd_outputs_object.Numbers().Store().Set(psd_status_number);*/
                
            }

            //If driver operate PSD interlock override, restore actual PSD door status. 
            if (m_mapped_cbtc_platform_outputs.psd_interlock_override_status == Project::TypeValue::IndicatorState::ON)
            {                
                m_mapped_cbtc_platform_outputs.psd_door_status = Project::TypeValue::PSDDoorStatus::PSD_CLOSED;
                m_mapped_cbtc_platform_outputs.departure_order = Project::TypeValue::DepartureOrder::START_ORDER;                
            }
        }
    }
    else //    If fault not ACTIVE or Train is not docked or Doors are opened
        m_mapped_cbtc_platform_outputs.psd_door_status = psd_door_status_to_restore;

}

/// Handles the reporting of information about the next platform to the CBTC Onboard
///
/// Determines and reports the following platform datato CBTC Onboard:
///    - CBTCOnboardInputs::PLATFORM_STATUS
///    - CBTCOnboardInputs::PSD_PRESENT
///    - CBTCOnboardInputs::TRAIN_NEAR_PLATFORM
///    - CBTCOnboardInputs::LHS_PLATFORM_DETECTION
///    - CBTCOnboardInputs::RHS_PLATFORM_DETECTION
///
/// @param psd_present          : Next station has platform screen doors
/// @param next_stopping_point  : Data associated with the next station's stopping point
///
void PlatformControlUnit::ReportPlatformInfo(bool psd_present, StoppingPoint::FeatureData next_stopping_point, double next_stopping_point_distance)
{
    // Determine and report the current platform status
    m_mapped_cbtc_onboard_inputs.platform_status = Project::TypeValue::PlatformStatus::NOT_DOCKED;
    if (m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::NO_BYPASS)
    {
        if (m_docked_at_station && (next_stopping_point.IsHold()))
            m_mapped_cbtc_onboard_inputs.platform_status = Project::TypeValue::PlatformStatus::HOLD;
        else if (m_docked_at_station &&
                 (//m_remaining_dwell_time == 0.0 ||
                  (m_remaining_dwell_time < next_stopping_point.GetDwellTime() - 5 &&
                   m_mapped_cbtc_vehicle_outputs.train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED &&
                   m_mapped_cbtc_vehicle_outputs.tbc_poisition == Project::TypeValue::TBCPosition::TRACTION)))
            m_mapped_cbtc_onboard_inputs.platform_status = Project::TypeValue::PlatformStatus::IMMEDIATE_DEPARTURE;
        else if (m_mapped_cbtc_platform_outputs.departure_order == Project::TypeValue::DepartureOrder::START_ORDER)
            m_mapped_cbtc_onboard_inputs.platform_status = Project::TypeValue::PlatformStatus::READY_TO_DEPART;
        else if (m_docked_at_station && m_mapped_cbtc_platform_outputs.psd_door_status == Project::TypeValue::PSDDoorStatus::PSD_CLOSING_FAILURE 
            && m_mapped_train_inputs.m_fault_adcl_status_not_available == 0.0)
            m_mapped_cbtc_onboard_inputs.platform_status = Project::TypeValue::PlatformStatus::PSD_UNLOCKED;
        else if (m_docked_at_station)
            m_mapped_cbtc_onboard_inputs.platform_status = Project::TypeValue::PlatformStatus::DOCKED;

        //MMRBEM-4378 : Report ready to depart in case driver closes door after doors opened automatically &  before dwell time remains 5 secs or less - ATO
        if (m_docked_at_station && m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO)
        {
            if (m_remaining_dwell_time != INVALID_TIME && m_remaining_dwell_time > 5 &&
                m_remaining_dwell_time < next_stopping_point.GetDwellTime() - 4 &&
                m_mapped_cbtc_platform_outputs.train_door_status == Project::TypeValue::TrainDoorStatus::DOOR_CLOSED &&
                m_mapped_cbtc_platform_outputs.psd_door_status == Project::TypeValue::PSDDoorStatus::PSD_CLOSED &&
                m_mapped_cbtc_platform_outputs.departure_order != Project::TypeValue::DepartureOrder::START_ORDER)
                m_mapped_cbtc_onboard_inputs.platform_status = Project::TypeValue::PlatformStatus::READY_TO_DEPART;
        }
    }

    // Determine where the train is in relation to the next platform and report this to the CBTC Onboard
    // Note that the order of the following conditions is important to get the correct value being set
    bool          find_whole_train_in_region = true;
    Comms::Object region_object;

    if (m_feature_region_data.TrainWithinFeatureRegion(
          m_scenario_train_id, FeatureRegion::RegionType::STATION, find_whole_train_in_region, region_object))
    {
        m_mapped_cbtc_onboard_inputs.train_near_platform    = Project::TypeValue::PlatformRegion::WITHIN_REGION;
        m_mapped_cbtc_platform_outputs.current_station_name = region_object.GetName(); // Handle the case of
                                                                                       // train starting fully
                                                                                       // inside a region
    }
    else if (m_feature_region_data.TrainFrontWithinFeatureRegion(m_scenario_train_id, FeatureRegion::RegionType::STATION, region_object))
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE)
          << "[ReportPlatformInfo] Entered Station:" << region_object.GetName() << Trace::EndLog();

        m_mapped_cbtc_onboard_inputs.train_near_platform    = Project::TypeValue::PlatformRegion::ENTERING_REGION;
        m_mapped_cbtc_platform_outputs.current_station_name = region_object.GetName();
    }
    else if (m_feature_region_data.TrainWithinFeatureRegion(
               m_scenario_train_id, FeatureRegion::RegionType::STATION, !find_whole_train_in_region, region_object))
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE)
          << "[ReportPlatformInfo] Exiting Station:" << region_object.GetName() << Trace::EndLog();

        m_mapped_cbtc_onboard_inputs.train_near_platform = Project::TypeValue::PlatformRegion::EXITING_REGION;
    }
    else
    {
        m_mapped_cbtc_onboard_inputs.train_near_platform = Project::TypeValue::PlatformRegion::OUTSIDE_REGION;
    }

    // Only report Platform Screen Doors are present at the next station if any part of the train is within the
    // platform region of a platform that has a PSD
    if (psd_present && (m_mapped_cbtc_onboard_inputs.train_near_platform != Project::TypeValue::PlatformRegion::OUTSIDE_REGION) &&
        (abs(next_stopping_point_distance) < m_overshoot_distance) &&
        (m_mapped_cbtc_vehicle_outputs.atc_bypass_state == Project::TypeValue::ATCBypassState::NO_BYPASS))
    {
        m_mapped_cbtc_onboard_inputs.psd_present = Project::TypeValue::PSDPresent::PSD_PRESENT;
    }
    else
        m_mapped_cbtc_onboard_inputs.psd_present = Project::TypeValue::PSDPresent::PSD_NOT_PRESENT;

    // When we are docked at a station we need to tell the CBTC Onboard which side of the train the platform
    // appears on
    if (m_docked_at_station)
    {
        auto csde_code                                      = next_stopping_point.GetCSDECode();
        m_mapped_cbtc_onboard_inputs.lhs_platform_detection = Project::TypeValue::PlatformDetection::NO_PLATFORM_DETECTED;
        m_mapped_cbtc_onboard_inputs.rhs_platform_detection = Project::TypeValue::PlatformDetection::NO_PLATFORM_DETECTED;
        if ((csde_code == StoppingPoint::CSDE_CODE::LHS) || (csde_code == StoppingPoint::CSDE_CODE::BOTH))
            m_mapped_cbtc_onboard_inputs.lhs_platform_detection = Project::TypeValue::PlatformDetection::PLATFORM_DETECTED;
        if ((csde_code == StoppingPoint::CSDE_CODE::RHS) || (csde_code == StoppingPoint::CSDE_CODE::BOTH))
            m_mapped_cbtc_onboard_inputs.rhs_platform_detection = Project::TypeValue::PlatformDetection::PLATFORM_DETECTED;
    }

    // No platform detection occurs when train is not docked
    else
    {
        m_mapped_cbtc_onboard_inputs.lhs_platform_detection = Project::TypeValue::PlatformDetection::NO_PLATFORM_DETECTED;
        m_mapped_cbtc_onboard_inputs.rhs_platform_detection = Project::TypeValue::PlatformDetection::NO_PLATFORM_DETECTED;
    }
}

/// Handles the reporting of departure information to the DMI
///
/// @param next_stopping_point : Data associated with the next stopping point
///
void PlatformControlUnit::ReportDepartureInfo(FeatureInterfaces::StoppingPoint::FeatureData next_stopping_point)
{
    // Set the defaut departure information
    auto departure_info = CBTC::Protos::DepartureInformation_DepartureStatus_NO_INDICATION;

    // Only report departure information in CM and AM modes
    if ((m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::UTO) ||
        (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO) ||
        (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP))
    {
        // Departure information only shown when train is docked at a station and there is no change of ends
        if (m_docked_at_station)
        {
            if (next_stopping_point.IsHold())
                departure_info = CBTC::Protos::DepartureInformation_DepartureStatus_TRAIN_HOLD;
            else // if (!next_stopping_point.IsChangeOfEnds())
                departure_info = CBTC::Protos::DepartureInformation_DepartureStatus_REMAINING_TIME;
        }
    }

    m_mapped_cbtc_platform_outputs.SetDepartureInfoRaw(departure_info, static_cast<int>(m_remaining_dwell_time));
}

/// Handles the reporting of departure order to the DMI
///
/// @param next_stopping_point : Data associated with the next stopping point
///
void PlatformControlUnit::ReportDepartureOrder(FeatureInterfaces::StoppingPoint::FeatureData next_stopping_point)
{
    // Set the defaut departure order
    m_mapped_cbtc_platform_outputs.departure_order = Project::TypeValue::DepartureOrder::NO_ORDER;

    // Only report departure order in CM and AM modes
    if ((m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO) ||
        (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::UTO) ||
        (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP))
    {
        // Determine the departure order when train is docked at a station and train is not being held at the
        // station
        if (m_docked_at_station && !next_stopping_point.IsHold())
        {
            // Departure Order is set to Open Doors Order if driver to open the train doors
            if ((m_mapped_cbtc_vehicle_outputs.train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED) &&
                ((m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATP) ||
                  //MMRBEM-4378:Commenting as no need to show door open order on ATO mode as doors are opened automatically
                 /*(m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::ATO) ||*/
                 (m_mapped_cbtc_onboard_outputs.current_driving_mode == Project::TypeValue::CurrentDrivingMode::UTO)) &&
                (m_open_door_request_pending))
            {
                m_mapped_cbtc_platform_outputs.departure_order = Project::TypeValue::DepartureOrder::OPEN_DOORS_ORDER;
            }

            // Closing of train doors is requested x seconds before the dwell time expires so that the train
            // and platform doors can finish closing by the time that the dwell time expires
            if ( //(m_remaining_dwell_time <= (m_max_door_closing_time+ 1.0)) &&
                ((m_mapped_cbtc_vehicle_outputs.train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::NO_INTERLOCK) ||
                (m_psd_present && (m_mapped_cbtc_platform_outputs.psd_door_status != Project::TypeValue::PSDDoorStatus::PSD_CLOSED))))
            {
                if(m_remaining_dwell_time <= 5 /*&& m_mapped_cbtc_platform_outputs.train_door_status == Project::TypeValue::TrainDoorStatus::DOOR_OPEN*/)
                    m_mapped_cbtc_platform_outputs.departure_order = Project::TypeValue::DepartureOrder::CLOSE_DOORS_ORDER;
                else if(m_open_door_request_pending &&
                      (m_mapped_cbtc_onboard_outputs.current_driving_mode != Project::TypeValue::CurrentDrivingMode::ATO)) //MMRBEM-4378:No need to show door open order on ATO mode as doors are opened automatically
                    m_mapped_cbtc_platform_outputs.departure_order = Project::TypeValue::DepartureOrder::OPEN_DOORS_ORDER;

            }
            // Train can depart if the dwell time has expired, train and platform doors are closed
            if ((//(m_remaining_dwell_time == 0.0) &&
                 ((m_mapped_cbtc_vehicle_outputs.train_door_closed_and_locked == Project::TypeValue::TrainDoorInterlock::DOORS_INTERLOCKED) ||
                  ((m_mapped_cbtc_vehicle_outputs.no_door_enable_bypass == Project::TypeValue::NoDoorInterlockBypass::BYPASS_ENABLED))) &&
                 (!m_psd_present || (m_mapped_cbtc_platform_outputs.psd_door_status == Project::TypeValue::PSDDoorStatus::PSD_CLOSED))) ||
                m_mapped_cbtc_platform_inputs.psd_interlock_override == Project::TypeValue::IndicatorState::ON)
            {
                if (m_mapped_cbtc_platform_outputs.departure_order != Project::TypeValue::DepartureOrder::OPEN_DOORS_ORDER &&
                    m_mapped_cbtc_platform_outputs.departure_order != Project::TypeValue::DepartureOrder::CLOSE_DOORS_ORDER &&
                    m_remaining_dwell_time == 0.0) //Departure order only when dwell time is 0
                    {
                           m_mapped_cbtc_platform_outputs.departure_order = Project::TypeValue::DepartureOrder::START_ORDER;
                    }
                if (m_mapped_cbtc_platform_inputs.psd_interlock_override == Project::TypeValue::IndicatorState::ON)
                    {
                        auto current_time                                            = std::chrono::steady_clock::now();
                        if (psd_interlock_override_timer == std::chrono::steady_clock::time_point::max())
                            psd_interlock_override_timer = current_time + std::chrono::seconds(60);
                        if (psd_interlock_override_timer <= current_time)
                        {
                            m_mapped_cbtc_platform_outputs.psd_interlock_override_status = Project::TypeValue::IndicatorState::OFF;
                            m_mapped_cbtc_platform_inputs.psd_interlock_override = Project::TypeValue::IndicatorState::OFF;
                            psd_interlock_override_timer = std::chrono::steady_clock::time_point::max();
                        }
                        else
                            m_mapped_cbtc_platform_outputs.psd_interlock_override_status = Project::TypeValue::IndicatorState::ON;
                    }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
// COMMS Object functions
///////////////////////////////////////////////////////////////////////////////////////////

/// Callback to handle creation of the Root object
///
/// @param object : Root Object
///
void PlatformControlUnit::RootChildCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);

    int class_id = Core::GetClassID(object);
    if (class_id == Core::ClassID::WORLD)
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
}

/// Callback to handle creation of a Comms Child object
///
/// @param object : Comms Object
///
void PlatformControlUnit::ObjectCreated(Comms::Object object)
{
    // The Comms mutex is implicitly in scope for the duration of this function.
    const std::lock_guard<std::mutex> DATA_LOCK(m_mutex);
    int                               class_id = Core::GetClassID(object);

    if (class_id == Train::ClassID::TRAIN)
    {
        m_mapped_train_inputs.MapTrainInputs(object, COMMS_REQUEST_FREQUENCY);

        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (class_id == Train::ClassID::VEHICLE)
    {
        // If it is the lead vehicle we want to
        // - Create the platform input/ouput objects
        // - look at the child objects that are created
        if (Sim::Project::IsLeadVehicle(object))
        {
            m_mapped_vehicle_inputs.MapVehicleInputs(object, COMMS_REQUEST_FREQUENCY);
            // Create CBTC_ONBOARD_INPUTS and CBTC_ONBOARD_OUTPUTS objects
            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::CBTC_PLATFORM_INPUTS));
            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::CBTC_PLATFORM_OUTPUTS));
        }
        m_number_of_cars++;
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
    }
    else if (class_id == Project::ClassID::PSD)
    {
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
    }
    //else if (Core::GetClassID(object) == Project::ClassID::PSD_OUTPUTS)
    //{
    //    //TO manage ADCL lamp indicator for ADCL fault
    //    m_psd_outputs_object = object;        
    //    m_psd_status_id = object.Numbers().Get(Project::ValueName::PSDOutputs::PSD_DOOR_STATUS).id;        
    //}
    else if (Core::GetClassID(object) == Project::ClassID::CCTV)
    {
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
    }
    else if (Core::GetClassID(object) == Project::ClassID::CCTV_INPUTS)
    {
        AddCreationCallback(object, [this](Comms::Object object) { this->ObjectCreated(object); });
    }
    else if (Core::GetClassID(object) == Project::ClassID::CCTV_INPUTS_VALUES)
    {
        m_mapped_cctv_inputs.MapCCTVInputs(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS)
    {
        m_mapped_cbtc_onboard_inputs.MapCBTCOnboardInputs(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_OUTPUTS)
    {
        m_mapped_cbtc_onboard_outputs.MapCBTCOnboardOutputs(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_OUTPUTS)
    {
        m_mapped_cbtc_vehicle_outputs.MapCBTCVehicleOutputs(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_INPUTS)
    {
        m_mapped_cbtc_vehicle_inputs.MapCBTCVehicleInputs(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_PLATFORM_INPUTS)
    {
        m_mapped_cbtc_platform_inputs.MapCBTCPlatformInputs(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_PLATFORM_OUTPUTS)
    {
        m_mapped_cbtc_platform_outputs.MapCBTCPlatformOutputs(object, COMMS_REQUEST_FREQUENCY);
        AddDestructionCallback(object, [this](Comms::Object object) { this->ObjectDestroyed(object); });
    }
}

/// Handles any invalidations that need to occur when an object is destroyed
///
/// @param object this is the object that was destroyed
///
void PlatformControlUnit::ObjectDestroyed(Comms::Object object)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    int                         class_id = Core::GetClassID(object);

    if (Core::GetClassID(object) == Train::ClassID::TRAIN)
        m_mapped_train_inputs.UnMapTrainInputs();
    else if (Core::GetClassID(object) == Train::ClassID::VEHICLE)
        m_mapped_vehicle_inputs.UnMapVehicleInputs();
    else if (Core::GetClassID(object) == Project::ClassID::CCTV_INPUTS)
        m_mapped_cctv_inputs.UnMapCCTVInputs();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_INPUTS)
        m_mapped_cbtc_onboard_inputs.UnMapCBTCOnboardInputs();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_ONBOARD_OUTPUTS)
        m_mapped_cbtc_onboard_outputs.UnMapCBTCOnboardOutputs();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_OUTPUTS)
        m_mapped_cbtc_vehicle_outputs.UnMapCBTCVehicleOutputs();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_VEHICLE_INPUTS)
        m_mapped_cbtc_vehicle_inputs.UnMapCBTCVehicleInputs();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_PLATFORM_INPUTS)
        m_mapped_cbtc_platform_inputs.UnMapCBTCPlatformInputs();
    else if (Core::GetClassID(object) == Project::ClassID::CBTC_PLATFORM_OUTPUTS)
        m_mapped_cbtc_platform_outputs.UnMapCBTCPlatformOutputs();
}
