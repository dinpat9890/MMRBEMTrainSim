/// @file      PISUnit.h
///            Implements PIS Backend Unit.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "sim_comms/Unit.h"
#include "Common/DataAccess.h"
#include "core_types/SessionData.h"
#include "PISState.h"
    
#include "PISAudio.h"
#include "world_api/WorldAccess.h"
#include "world_api/TrainPathWatcher.h"
#include <variant>
#include "DVAAudioConfigHandler.h"
#include "train_data_access/Timetable.h"
#include "AnnouncementsPlay.h"

#ifndef PIS_UNIT_H
#define PIS_UNIT_H

class PISUnit : public Comms::SteppingUnit
{
public:
    PISUnit(
        Comms::Gateway &gateway,
        Common::Data::DataAccess &data_access,
        WorldAPI::WorldAccess &world_access,
        WorldAPI::TrainPathWatcher &path_watcher,
        const Core::BaseScenarioData &scenario_data,
        const Common::Properties &properties);
    ~PISUnit();

    void Step(double new_time) override;
    double GetPeriod() const override;

private:
    Comms::Gateway  &m_gateway;
    Common::Data::DataAccess &m_data_access;
    WorldAPI::WorldAccess &m_world_access;
    WorldAPI::TrainPathWatcher &m_path_watcher;
    const Common::Properties &m_properties;
    int m_train_id{-1};
    int m_scenario_id{-1};
    int m_scenario_train_id{-1};
    int m_cab_vehicle_idx{-1};
    double m_powering_on_time_seconds{0.0};
    bool m_fist_mic_enable = false;
    bool m_is_pecu_active = false;
    double m_pabr_bypass_state_last = 0.0;

    // comms object for Project::ClassID::PAPIS_VEHICLE_OUTPUTS. Model provides power & door state through that.
    Comms::Object m_papis_vehicle_outputs_comms;

    // comms object for Project::ClassID::PIS_BE_INPUTS_VALUES
    Comms::Object m_pis_inputs_comms;

    // comms object for Project::ClassID::PIS_BE_OUTPUTS
    Comms::Object m_pis_outputs_comms;

    // comms object for Project::ClassID::RADIO_INPUTS
    Comms::Object m_radio_inputs_comms;
    
    // comms object for Project::ClassID::DVA_OUTPUTS
    Comms::Object m_dva_output_comms;

    // comms object for Project::ClassID::VEHICLE
    Comms::Object m_vehicle_comms;

    // comms object for Project::ClassID::VEHICLE_OUTPUTS
    Comms::Object m_vehicle_inputs_values_comms;

    std::vector<Comms::Object> m_vehicle_comms_list;

    // comms object for Project::ClassID::INTERCOM_INPUTS
    Comms::Object m_intercom_input_comms;

    // comms object for Project::ClassID::INTERCOM_OUTPUTS
    Comms::Object m_intercom_output_comms;

    // comms object for Project::ClassID::OHP_OUTPUTS
    Comms::Object m_ohp_output_comms;

    // comms object for Project::ClassID::OHP_INPUTS
    Comms::Object m_ohp_input_comms;

    // comms object for Project::ClassID::VDU_OUTPUT
    Comms::Object m_vdu_outputs_comms;

    // keeps the state seen at the last Step()
    PISState m_state;

    // Interface to Audio Engine.
    PISAudio m_audio_engine;

    // Auto station announcement mode variable
    using FeatureIdToStationId = std::map<int, int>;
    FeatureIdToStationId m_feature_id_to_station_id;
    WorldAPI::TrackAssociationMap m_track_association;

    int m_announcement_mode = -1;

    int m_platform_stopping_point_type_id;
    std::vector<Comms::Object> m_platform_stopping_point;

    BroadcastMessageQueue   m_messages_queue;

    std::thread m_audio_play_thread;
    bool        m_stop_audio_play_thread{ false };
    bool        m_temp{ true };

    // Audio XML handler and file data storage
    std::shared_ptr<dva::DVAAudioConfigHandler>   m_dva_audio_handler;
    
    // Create a sequence of audio ids based on the condition at runtime to send it to DVA
    std::unique_ptr<AnnouncementsPlay>       m_announcements;

    std::unordered_map<int, Train::Data::Timetable::Station>            m_dbId_stationId_map;
    std::unordered_map<std::string, Train::Data::Timetable::Station>    m_station_name_map;
    std::unordered_map<std::string, int>                                m_station_code_xml_id_map;
    std::unordered_map<int, Train::Data::Timetable::Line>               m_lineId_map;
    std::unordered_map<std::string, Train::Data::Timetable::Route>      m_route_code_data_map;
    std::unordered_map<int, std::string>                                m_routeId_code_map;

    std::mutex              m_lock;
    std::mutex              m_dva_lock;
    std::condition_variable m_wake_thread_cv;

    Sim::Number::ID         m_skip_list_id;
    Sim::Number::ID         m_arrive_depart_msg_id;
    Sim::Number::ID         m_dva_stop_id;
    Sim::Number::ID         m_dva_start_id;
    Sim::Number::ID         m_intercom_state_id;

    typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Number>>  Comms_Number_Listener_t;
    // Listener for SkipList
    typedef Sim::Listener<Sim::Raw, Sim::NoQueueing, Sim::AllCallbacks<Sim::Raw> > RawListener;
    typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::AllCallbacks<Sim::Number> > NumberListener;
    
    RawListener             m_skipList_listener;
    RawListener             m_arrive_depart_msg_listener;
    NumberListener          m_dva_stop_listener;
    NumberListener          m_dva_start_listener;
    NumberListener          m_intercom_state_listener;


    void SkipListCallback(Sim::Raw raw);
    void arriveDepartMsgCallback(const Sim::Raw &raw);
    void DvaStopCallback(const Sim::Number &num_obj);
    void DvaStartCallback(const Sim::Number &num_obj);
    void IntercomStateChanged(const Sim::Number &num_obj);
    void IntercomOutputChanged(const Sim::Number &num_obj);
    void VehicleOutputChanged(const Sim::Number &num_obj);
    void PublicAnnoucemntChanged(const Sim::Number &num_obj);
    void OHPOutputChanged(const Sim::Number &num_obj);
    void PeaAlarmActiveCallback(const Sim::Number &num_obj);
    void HandlePABRAndPOBRStatus(const double value);
    void PABRBypassChanged(const Sim::Number &num_obj);
    void PEAFaultDetection(const Sim::Number &num_obj);
    void PEA2FaultDetection(const Sim::Number &num_obj);
    void PEA3FaultDetection(const Sim::Number &num_obj);
    void EventAcknowledge(const Sim::Number &num_obj);
    void PEAFaultDetectionIncomingCall(const Sim::Number &num_obj);
    void RadioAudioEnable(const Sim::Number &num_obj);

    void ObjectCreated(Comms::Object object);

    bool CheckHandleOffAndPoweringOn(double new_time);

    void CreateAudioPlayThread();
    void DestroyAudioPlayThread();
    void AudioPlayThread();
    void TimerThread();

    //std::variant<Train::Data::Timetable::Route, std::vector<int>> 
    void DetectRouteAndPosition(int  selected_route_id);
    void HandleAutoAnouncements();
    void HandleSemiAutoAnouncements();
    bool IsTrainNearStationArea();
    void PlayStationArrivedAnnouncement(int station_id, int door_side = -1);
    void PlayStationNextAnnouncement(int station_id);
    void PlayStationAnnouncement(int station_id, const std::string& announcement_type, int door_side = -1);
    void PlayDoorChime(int station_id, bool door_open_flg);    
    void PlayDoorCloseAnnouncemnt(const Sim::Number &num_obj);
    void PlayRouteStartDepartAnnouncement(int station_id);
    void PlayManualAnnouncement(const ManualAnnoucementMsg & manual_announcmnt, int door_side = -1);
    void HandleEmergencyAnnouncement();
    void HandleEmergencyAnnouncement(BroadcastMessagePriorities priority, EmergencySpecialMsgState & msg_state, 
                   const std::map<int, dva::Message> & emrgncy_spcial_msg_map,
                   AnnouncementType announcement_type);
    void HandleSpecialAnnouncement();
    void SkipStationFeature(const Sim::Number &num_obj);
    void HandleOCCAnnouncement();
    void HandleFistAnnouncement();
    void HandleManualAnnouncement();
    int GetDoorSide();
    int GetPlatformSide();
    void TrainIDChanged(const Sim::Number &num_obj);
    //void RouteIDChanged(const Sim::Number &num_obj);
    void StartStationChanged(const Sim::Number &num_obj);
    void TerminalStationChanged(const Sim::Number &num_obj);
    void NextStationChanged(const Sim::Number &num_obj);
    void StopEmgSpc(const Sim::Number &num_obj);
    void FaultPea2Failure(const Sim::Number &num_obj);
    void FaultMcbPaGroup(const Sim::Number &num_obj);
    void StationAnnouncementModeChanged(const Sim::Number &num_obj);
    std::tuple<int, int> GetOHPVehicleNo();

    void AnnouncementModeChanged(const Sim::Number &num_obj);
};

#endif