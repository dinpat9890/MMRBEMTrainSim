///**************************************************************************************************
/// @file         PlatformControlUnit.h
///
/// Description : Unit for controlling CBTC functionality associated with a platform
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
#include "MappedCBTCPlatformOutputs.h"
#include "MappedCBTCPlatformInputs.h"
#include "MappedCBTCVehicleOutputs.h"
#include "MappedCBTCVehicleInputs.h"
#include "MappedTrainInputs.h"
#include "MappedVehicleInputs.h"
#include "MappedCCTVInputs.h"
#include "PlatformProperties.h"

#include "feature_interfaces/FeatureRegion.h"
#include "feature_interfaces/StoppingPointFeature.h"
#include "PlatformScreenDoors.h"

#include "Protobuf/CBTCOnboard.pb.h"

/// This unit handles the interfacing between the platform and CBTC system. 
///
class PlatformControlUnit : public Comms::SteppingUnit
{
public:
    PlatformControlUnit(Comms::Gateway                  &gateway,
                        Common::Data::DataAccess        &data_access,
                        WorldAPI::WorldAccess           &world_access,
                        WorldAPI::TrainPathWatcher      &path_watcher,
                        const PlatformProperties        &properties,
                        int                              scenario_train_id);

    ~PlatformControlUnit();

    std::string GetName() const override;

    void Step(double new_time) override;
    double GetPeriod() const override;

private:

    // Comms Object Callbacks
    void RootChildCreated(Comms::Object object);
    void ObjectCreated(Comms::Object object);
    void ObjectDestroyed(Comms::Object object);

    // Functions to control passenger exchange at a platform
    void HandleTrainDocking(double new_time,
                            double next_stopping_point_distance, 
                            FeatureInterfaces::StoppingPoint::FeatureData next_stopping_point);
    void ControlPlatformDoors(double current_time, 
                              FeatureInterfaces::StoppingPoint::FeatureData next_stopping_point, 
                              std::shared_ptr<PlatformControl::PlatformScreenDoors::PlatformDoors> next_platform_psd);
    void HandleTrainDoorRequests(double current_time);

    // Functions that help with reporting platform control data
    void ReportTrainDoorStatus(double current_time);
    void ReportPSDDoorStatus(std::shared_ptr<PlatformControl::PlatformScreenDoors::PlatformDoors> next_plaform_screen_door);
    void ReportPlatformInfo(bool psd_present, 
        FeatureInterfaces::StoppingPoint::FeatureData next_stopping_point,
        double next_stopping_point_distance);
    void ReportDepartureInfo(FeatureInterfaces::StoppingPoint::FeatureData next_stopping_point);
    void ReportDepartureOrder(FeatureInterfaces::StoppingPoint::FeatureData next_stopping_point);
	void HandleAdclStatusNotAvailableFault();

private:
    // Comms and Paths
    Comms::Gateway                               &m_gateway;
    int                                           m_scenario_train_id;
    int                                           m_number_of_cars;
    const int                                     REQUEST_FREQUENCY = 20;
    int                                           m_vehicle_id;

    // Need to create the FeatureRequester here in order for the points state's to be
    // updated within a module. If at least one unit within a module doesn't have this
    // the the Path watcher will fail to trigger the routechange callback when any
    // of the points along the path are updated.
    WorldAPI::FeatureRequester m_feature_requester; // TBD may be able to remove this if bug is fixed

    // Route data and features controlled by unit
    FeatureInterfaces::FeatureRegion        m_feature_region_data;
    FeatureInterfaces::StoppingPoint        m_stopping_point_data;
    PlatformControl::PlatformScreenDoors    m_plaform_screen_doors;
    std::shared_ptr<PlatformControl::PlatformScreenDoors::PlatformDoors> m_next_plaform_screen_door;

    // Comms data
    MappedCCTVInputs                            m_mapped_cctv_inputs;
    MappedCBTCOnboardInputs                     m_mapped_cbtc_onboard_inputs;
    MappedCBTCOnboardOutputs                    m_mapped_cbtc_onboard_outputs;
    MappedCBTCVehicleOutputs                    m_mapped_cbtc_vehicle_outputs;
    MappedCBTCVehicleInputs                     m_mapped_cbtc_vehicle_inputs;
    MappedCBTCPlatformInputs                    m_mapped_cbtc_platform_inputs;
    MappedCBTCPlatformOutputs                   m_mapped_cbtc_platform_outputs;
    MappedTrainInputs                           m_mapped_train_inputs;
    MappedVehicleInputs                         m_mapped_vehicle_inputs;

	/*Comms::Object m_psd_outputs_object;
	Sim::ValueID::ID m_psd_status_id;*/

    // Configuration Data
    double m_docking_tolerance;
    double m_psd_open_time;
    double m_psd_close_time;
    double m_train_door_open_time;
    double m_train_door_close_time;
    double m_close_warning_time;
    double m_max_door_closing_time;
    double m_max_closed_and_locked_time;
    double m_max_train_doors_unlocking_time;
    double m_overshoot_distance;

    // Platform Information
    bool   m_docked_at_station;
    double m_dwell_end_time;
    double m_remaining_dwell_time;
    double m_request_door_open_time;
    double m_request_door_close_time;
    int    m_number_of_platform_doors;
    bool   m_psd_present;

    // State information
    double m_previous_train_speed;
    double m_previous_driving_mode;
    double m_previous_mode_selector_position;
    bool m_open_door_request_pending;

    // Synchronisation
    std::mutex                              m_mutex;

    std::chrono::steady_clock::time_point psd_interlock_override_timer = std::chrono::steady_clock::time_point::max();
};
