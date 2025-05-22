/// @file      RadioUnit.h
///            Implements Radio Backend Unit.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "sim_comms/Unit.h"
#include "Common/DataAccess.h"
#include "core_types/SessionData.h"
#include "RadioState.h"
#include "world_api/WorldAccess.h"
#include "world_api/TrainPathWatcher.h"
#include <variant>
#include "train_data_access/Timetable.h"

#ifndef RADIO_UNIT_H
#define RADIO_UNIT_H

class RadioUnit : public Comms::SteppingUnit
{
public:
    RadioUnit(
        Comms::Gateway &gateway,
        Common::Data::DataAccess &data_access,
        WorldAPI::WorldAccess &world_access,
        WorldAPI::TrainPathWatcher &path_watcher,
        const Core::BaseScenarioData &scenario_data,
        const Common::Properties &properties);

    void Step(double new_time) override;
    double GetPeriod() const override;

private:
    Comms::Gateway  &m_gateway;
    Common::Data::DataAccess &m_data_access;
    WorldAPI::WorldAccess &m_world_access;
    WorldAPI::TrainPathWatcher &m_path_watcher;
    const Common::Properties &m_properties;
    int m_scenario_id{-1};
    int m_scenario_train_id{-1};
    int m_cab_vehicle_idx{-1};

    // comms object for Project::ClassID::PAPIS_VEHICLE_OUTPUTS. Model provides power & door state through that.
    Comms::Object m_papis_vehicle_outputs_comms;

    // comms object for Project::ClassID::RADIO_INTERCOM_INPUTS_VALUES
    Comms::Object m_radio_inputs_comms;

    // comms object for Project::ClassID::RADIO_INTERCOM_OUTPUTS
    Comms::Object m_radio_outputs_comms;
    
    // comms object for Project::ClassID::DVA_OUTPUTS
    Comms::Object m_dva_output_comms;

    // comms object for Project::ClassID::VEHICLE
    Comms::Object m_vehicle_comms;

    // comms object for Project::ClassID::INTERCOM_INPUTS
    Comms::Object m_intercom_input_comms;

    // comms object for Project::ClassID::INTERCOM_OUTPUTS
    Comms::Object m_intercom_output_comms;

    // keeps the state seen at the last Step()
    RadioState m_state;

    // Auto station announcement mode variable
    using FeatureIdToStationId = std::map<int, int>;
    FeatureIdToStationId m_feature_id_to_station_id;
    WorldAPI::TrackAssociationMap m_track_association;

    std::thread m_audio_play_thread;
    bool        m_stop_audio_play_thread{ false };

    std::unordered_map<int, Train::Data::Timetable::Station>            m_stationId_map;
    std::unordered_map<std::string, Train::Data::Timetable::Station>    m_station_name_map;
    std::unordered_map<int, Train::Data::Timetable::Line>               m_lineId_map;
    std::unordered_map<std::string, Train::Data::Timetable::Route>      m_route_code_data_map;
    std::unordered_map<int, std::string>                                m_routeId_code_map;

    std::mutex              m_lock;
    std::mutex              m_dva_lock;
    std::condition_variable m_wake_thread_cv;

    typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Number>>  Comms_Number_Listener_t;

    typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::AllCallbacks<Sim::Number> > NumberListener;

    void RadioCabCancel(const Sim::Number &num_obj);
    void RadioSccCancel(const Sim::Number &num_obj);
    void RadioCabIntercomAccept(const Sim::Number &num_obj);
	void RadioSccIntercomAccept(const Sim::Number &num_obj);
    void RadioEmrgcyCallReq(const Sim::Number &num_obj);
    void RadioFullDuplxReq(const Sim::Number &num_obj);
    void RadioGroupCallReq(const Sim::Number &num_obj);
    void RadioHalfDuplxReq(const Sim::Number &num_obj);
    void SetCabScc_CAB(const Sim::Number &num_obj);
    void SetCabScc_SCC(const Sim::Number &num_obj);

    void ObjectCreated(Comms::Object object);
    void PowerStateChanged(bool power_on);
    bool m_power_on = false;
};

#endif