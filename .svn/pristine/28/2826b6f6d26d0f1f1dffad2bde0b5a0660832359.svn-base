///**************************************************************************************************
/// @file         TrackEventsUnit.h
///
/// Description : Unit for reporting track events that need to be sent to be reported by the CBTC Onboard
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

#include "feature_interfaces/FeatureRegion.h"
#include "feature_interfaces/StoppingPointFeature.h"
#include "WorkZone.h"

#include "Protobuf/CBTCOnboard.pb.h"

#include "MappedCBTCOnboardInputs.h"


///
/// The Track Event Unit is responsible for reporting Track Event detections to the CBTC Onboard Inputs. These events are
/// - Transition into and out of the automatic region
/// - Work Zones
/// - Skip Stations
/// - Change of Ends
///
class TrackEventsUnit : public Comms::SteppingUnit
{
public:
    struct TrackEvent
    {
        double                       distance;
        CBTC::Protos::TrackEventType event_type;
        std::string                  station_code;
        double                       length;
    };

public:
    TrackEventsUnit(Comms::Gateway                  &gateway, 
               Common::DataAccess              &data_access,
               WorldAPI::WorldAccess           &world_access,
               WorldAPI::TrainPathWatcher      &path_watcher,
               const double                     max_look_ahead,
               const double                     transition_zone_length,
               int                              scenario_train_id);

    ~TrackEventsUnit();

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
    Comms::Gateway                    &m_gateway;
    MappedCBTCOnboardInputsObject     m_cbtc_onboard_inputs_object;

    // Track event data for the path ahead
    std::map<double, CBTC::Protos::TrackEventList_TrackEvent> m_track_event_map;

    // configuration data
    double m_transition_zone_length;

    // Feature Data required to populate the track event data
    FeatureInterfaces::FeatureRegion  m_feature_region_data;
    FeatureInterfaces::StoppingPoint  m_stopping_point_data;
    FeatureInterfaces::WorkZone       m_work_zone_data;

    // Information about the train
    int                               m_scenario_train_id;
    Comms::Object                     m_lead_vehicle_object;
    Sim::Number::ID                   m_position_id;
};
