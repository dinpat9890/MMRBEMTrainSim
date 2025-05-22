///**************************************************************************************************
/// @file         BeaconUnit.h
///
/// Description : Unit for interfacing the beacon features with the CBTC Onboard Inputs
///
/// @author       Adam Zielinski
///
/// @copyright    (C) Copyright:  SYDAC Pty Ltd, 2020
///**************************************************************************************************

#pragma once

#include "sim_comms/Unit.h"
#include "sim_comms/ProcessingInterfaces.h"


#include "world_api/TrainPathWatcher.h"

#include "core_types/SessionData.h"
#include "core_properties/CommonProperties.h"

#include "MappedCBTCTrainInputsObject.h"
#include "BeaconReader.h"


///
/// The Bailse Unit is responsible for reporting beacon detections to the CBTC Onboard Inputs
/// - When beacon is in normal state, it's feature ID is reported
/// - When beacon is in faulty state, -1 (Fault Detection) is reported initially reported, followed shortly after by value 0 (Unknown) 
///
class BeaconUnit : public Comms::SteppingUnit
{
public:
    BeaconUnit(Comms::Gateway                  &gateway, 
               Common::DataAccess              &data_access,
               WorldAPI::WorldAccess           &world_access,
               WorldAPI::TrainPathWatcher      &path_watcher,
               int                              scenario_train_id);

    ~BeaconUnit();

    std::string GetName() const override;

    // In order to step ...
    void Step(double new_time) override;
    double GetPeriod() const override;

private:

    bool CommsInitialisationCompleted();

    // Comms Object Callbacks
    void RootChildCreated(Comms::Object  object);
    void CommsObjectCreated(Comms::Object object);
    void CommsObjectDestroyed(Comms::Object object);

private:

    // Comms
    Comms::Gateway                     &m_gateway;

    MappedCBTCOnboardInputsObject         m_cbtc_onboard_inputs_object;

    // Information about the train
    int                                 m_scenario_train_id;
    Comms::Object                       m_lead_vehicle_object;
    Sim::Number::ID                     m_position_id;

    double                              m_prev_train_position;

    // Beacon Detection
    Beacon::BeaconReader                m_beacon_reader;

    // Used for momentary signalling of triggered events
    double                              m_last_detection_time;
    bool                                m_clear_faulty_beacon_detection;
};
