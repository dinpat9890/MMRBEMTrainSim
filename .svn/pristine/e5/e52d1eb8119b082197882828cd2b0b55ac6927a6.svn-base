/// @file      PISUnit.h
///            Implements PIS Backend Unit.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "PISUnit.h"
#include "core_properties/CommonProperties.h"
#include "train_data_access/TrainDataAccessTypes.h"
#include "common/Callback.h"
#include "utility/Utilities.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "project_comms_structure/ProjectObjectDefinition.h"
#include "train_data_access/TrainDataAccess.h"
#include "CommsPropertyAccessors.h"
#include "Source/Protobuf/PAPISProtos.pb.h"
#include "train_data_access/Timetable.h"
#include "core_data_access/Network.h"
#include "network_definition/WorldDescription.h"
#include "ConstantDefined.h"
#include "file_access/XMLReader.h"
#include <vector>
#include <chrono>
#include "../../../config/project_features/include/project_features/ProjectFeatureConstants.h"

#include "../../../../project/include/project/Utilities/RawToString.h"

using namespace CTSProjectUtility;

namespace {

    const std::string PIS_SECTION = "PIS";
    const char * const STATION_LIST_FILE = "Station List File";
    const std::string POWER_ON_TIME = "Powerup Time";

    const double AUTO_BROADCAST_WATCH_DISTANCE = 150.0;
    const double AUTO_BROADCAST_WATCH_DISTANCE_NEXT = 250.0;
    const double AUTO_BROADCAST_WATCH_DISTANCE_NEXT_DOOR = 500.0;
    const double BROADCAST_WATCH_DISTANCE_NEXT_PLATFORM = 150.0;
    const double BROADCAST_WATCH_DISTANCE_CCTV_NEXT_PLATFORM = 300.0;
    const double STOPPING_POINT_FEATURE_STATE_SKIP = 2.0;
    const std::string CSDE_CODE_PROPERTY = "CSDE Code"; 

    using AudioTypeToId = std::map<std::string, int>;
    const double REQUEST_FREQUENCY = 20.0;

    const int DMC_1 = 1;
    const int DMC_6 = 6;
    const int DMC_8 = 8;
    const int MC_3 = 3;
    const int MC_4 = 4;
    const int MC_6 = 6;

    const double BLACK = 0.0;
    const double GREEN = 1.0;
    const double GREY  = 2.0;
    const double BLUE = 1.0;
}

PISUnit::PISUnit(
    Comms::Gateway &gateway,
    Common::Data::DataAccess &data_access,
    WorldAPI::WorldAccess &world_access,
    WorldAPI::TrainPathWatcher &path_watcher,
    const Core::BaseScenarioData &scenario_data,
    const Common::Properties &properties)
    : Comms::SteppingUnit(gateway),
      m_gateway(gateway),
      m_data_access(data_access),
      m_world_access(world_access),
      m_path_watcher(path_watcher),
      m_properties(properties),
      m_platform_stopping_point_type_id(-1),
      m_audio_engine(gateway, data_access, scenario_data, properties),
      m_messages_queue(m_audio_engine,m_state)
{
    try
    {
        Core::Database::Feature feature = Core::Database::Feature(data_access);
        m_platform_stopping_point_type_id = feature.GetFeatureType(Project::FeatureTypes::FETY_STOPPING_POINT).feature_type_id;

        m_powering_on_time_seconds = properties.GetProperty<double>(PIS_SECTION, POWER_ON_TIME, 30.0);

        auto hub_data = Core::GetHubData(scenario_data, Core::Properties::GetHubID(properties, data_access));

        m_scenario_id = scenario_data.scenario_id;
        m_scenario_train_id = hub_data.scenario_train_id;
        m_cab_vehicle_idx = hub_data.vehicle_index;

        auto trains = Train::Database::Train(data_access).GetScenarioTrains(scenario_data.scenario_id);
        auto train_it = std::find_if(trains.cbegin(), trains.cend(),
            [&](const Train::Data::ScenarioTrain& train)
            { return train.scenario_train_id == m_scenario_train_id; });

        if (train_it != trains.end())
            m_train_id = train_it->train_id;
        else
            Trace::GetLogger().STAMP(Trace::ERR) << "Scenario train is not found." << Trace::EndLog();

        const auto stations =
            Train::Database::Timetable(data_access).GetStations(
                Core::Database::Network(data_access).GetNetworkIDForScenario(m_scenario_id));

        for (const auto& station : stations)
        {
            m_dbId_stationId_map.insert(std::make_pair(station.id, station));
            m_station_name_map.insert(std::make_pair(station.name, station));

            if (station.feature_ids.size() == 0)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << "Auto broadcast mode might not work properly. No feature associated with station : "
                    << station.name << Trace::EndLog();

                continue;
            }

            for (const auto& feature_id : station.feature_ids)
            {
                m_feature_id_to_station_id[feature_id] = station.id;
                Trace::GetLogger().STAMP(Trace::VERBOSE)
                    << "Station \"" << station.name << "\" assiciated with feature : " << feature_id << Trace::EndLog();
            }
        }

        m_dva_audio_handler = std::make_shared< dva::DVAAudioConfigHandler>();
        std::string xml_file = properties.GetProperty<std::string>(PIS_SECTION, STATION_LIST_FILE, "PIS\\PIS_Station_List.xml");

        FileAccess::XMLReader xml_reader(*m_dva_audio_handler);
        xml_reader.Read(xml_file.c_str());
        if (xml_reader.AnyErrors())
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "Reading the Station List xml file '" << xml_file << "' Error : " << xml_reader.GetErrorLog() << Trace::EndLog();
        }

        //Route Details
        const auto network_id = Core::Database::Network(data_access).GetNetworkIDForScenario(scenario_data.scenario_id);
        const auto routes = Train::Database::Timetable(data_access).GetRoutes(network_id);
        for (const auto& route : routes)
        {
            m_route_code_data_map.insert(std::make_pair(route.code, route));
            Trace::GetLogger().STAMP(Trace::INFO) << "Route Id: " << route.id << " Code: " << route.code << Trace::EndLog();
            m_routeId_code_map.insert(std::make_pair(route.id, route.code));
        }

        const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);
        Comms::AddCreationCallback(m_gateway.GetRootObject(), MakeCallback(&PISUnit::ObjectCreated, this));

        m_skipList_listener.AddCallback(MakeCallback(&PISUnit::SkipListCallback, this));
        m_arrive_depart_msg_listener.AddCallback(MakeCallback(&PISUnit::arriveDepartMsgCallback, this));
        m_dva_stop_listener.AddCallback(MakeCallback(&PISUnit::DvaStopCallback, this));
        m_dva_start_listener.AddCallback(MakeCallback(&PISUnit::DvaStartCallback, this));
        m_intercom_state_listener.AddCallback(MakeCallback(&PISUnit::IntercomStateChanged, this));

        m_announcements.reset(new AnnouncementsPlay(m_state, m_dva_audio_handler, m_dbId_stationId_map, m_station_name_map, 
                                                     m_route_code_data_map, m_routeId_code_map));

        Start();
    }
    catch (CommonException &e)
    {
        Trace::GetLogger().STAMP(Trace::WARN) << e.what() << ".\n PISUnit is not operational." << Trace::EndLog();
    }
}

PISUnit::~PISUnit()
{
    DestroyAudioPlayThread();
    m_arrive_depart_msg_listener.RemoveAllCallbacks();
    m_skipList_listener.RemoveAllCallbacks();
    m_dva_stop_listener.RemoveAllCallbacks();
    m_dva_start_listener.RemoveAllCallbacks();
}

void PISUnit::SkipListCallback(Sim::Raw raw)
{
    //auto it = raw.value.begin();
    //std::string data ;
    //for (;it != raw.value.end(); ++it)
    //    data.push_back(*it);
    auto data = std::string{ raw.value.begin(), raw.value.end() };
    com::sydac::mmrbem::common::protos::SkipIDList list;
    list.ParseFromString(data);

    //SetObjectPropertyRaw(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SKIP_STATION_LIST, raw);  // can't set direct because Sim::Value<std::vector<unsigned char,std::allocator<_Ty>>> it doesn't directly support the begin() function for iteration.
    Sim::Raw raw_temp = m_pis_outputs_comms.Raws().Get(Project::ValueName::PISBEOutputs::SKIP_STATION_LIST);
    raw_temp.value.clear();
    raw_temp.value = raw;
    m_pis_outputs_comms.Raws().Store().Set(raw_temp);

    m_state.m_skip_station_list.clear();
    m_state.m_skip_station_map.clear();
    m_state.m_current_skip_count = 0;
    //for (auto it = list.idlist().cbegin(); it != list.idlist().cend(); it++)
    for(const auto& id: list.idlist())
    {
        //com::sydac::mmrbem::common::protos::SkipIDList::SkipId id = *it;
        int station_id = id.stationid();
        int db_station_id = m_announcements->ConvertXmlIdToDbId(station_id);
        if (m_state.getLastStation() == db_station_id)
        {
            Trace::GetLogger().STAMP(Trace::WARN) << "StationId: " << station_id << " cant be added in skip list, it is the last station" << Trace::EndLog();
            continue;
        }
        Trace::GetLogger().STAMP(Trace::INFO) << "Skip Id List, stationId: " << station_id << Trace::EndLog();
        m_state.m_skip_station_list.insert(std::make_pair(station_id, m_state.m_current_skip_count));
        m_state.m_skip_station_map.insert(std::make_pair(m_state.m_current_skip_count, station_id));
        ++m_state.m_current_skip_count;
    }
    m_state.m_current_skip_count = m_state.m_skip_station_list.size();
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "m_current_skip_count: " << m_state.m_current_skip_count << Trace::EndLog();
}

void PISUnit::arriveDepartMsgCallback(const Sim::Raw &raw)
{
    auto it = raw.value.begin();
    std::string data;
    for (;it != raw.value.end(); ++it)
        data.push_back(*it);
    com::sydac::mmrbem::common::protos::ManualAnnouncement manual_announcement_proto;
    manual_announcement_proto.ParseFromString(data);

    m_state.m_manual_anncmnt_msg.start_station_id = m_announcements->ConvertXmlIdToDbId(manual_announcement_proto.startstationid());
    m_state.m_manual_anncmnt_msg.next_station_id = m_announcements->ConvertXmlIdToDbId(manual_announcement_proto.nextstationid());
    m_state.m_manual_anncmnt_msg.msg_type = (ArriveDepartureType) manual_announcement_proto.arrivaldeparturetype();
    m_state.m_manual_anncmnt_msg.door_type = (DoorType)manual_announcement_proto.doorsideopen();

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "start_station_id: " << m_state.m_manual_anncmnt_msg.start_station_id 
                                             << " next_station_id: " << m_state.m_manual_anncmnt_msg.next_station_id
                                             << " msgType: " << (int)m_state.m_manual_anncmnt_msg.msg_type 
                                             << " doorType: " << (int)m_state.m_manual_anncmnt_msg.door_type  
                                             << Trace::EndLog();
}

void PISUnit::DvaStopCallback(const Sim::Number &num_obj)
{
    if (num_obj.id == m_dva_stop_id)
    {
        if (num_obj.value > 0.0)
        {
            {
                std::lock_guard lock(m_dva_lock);
                m_state.m_dva_start = false;
                m_state.m_dva_stop = false;
                if (m_state.m_emergency_msg_state.stop_status == false)
                    m_state.m_emergency_msg_state.stop_status = true;
                if (m_state.m_special_msg_state.stop_status == false)
                    m_state.m_special_msg_state.stop_status = true;
                if (m_state.m_special_msg_state.stop_status == false)
                    m_state.m_special_msg_state.stop_status = true;
            }
            //m_state.m_dva_stop = num_obj.value;
            //std::lock_guard lock(m_lock);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "DvaStopCallback: " << Trace::EndLog();
            m_messages_queue.ResetLastDequeuedMessage();
            m_wake_thread_cv.notify_one();

        }
    }
}

void PISUnit::DvaStartCallback(const Sim::Number &num_obj)
{
    if (num_obj.id == m_dva_start_id)
    {
        if (num_obj.value > 0.0)
        {
            std::lock_guard lock(m_dva_lock);
            m_state.m_dva_start = true;
            //m_state.m_dva_start = num_obj.value;
        }
    }
}

void PISUnit::IntercomStateChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.id == m_intercom_state_id && m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::INACTIVE)
    {
        if (num_obj.value > 0.5)
        {
            //m_audio_engine.Stop();
            m_state.m_intercom_status = true;
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom state: Enabled "  << Trace::EndLog();
        }
        else
        {
            m_state.m_intercom_status = false;
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom state: Disabled " << Trace::EndLog();
        }
    }
}

void PISUnit::TimerThread()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "TimerThread: Waiting for 60 seconds, thread_id: " << std::this_thread::get_id() << Trace::EndLog();
    int time_in_sec = 60;
    while (time_in_sec <= 60 && time_in_sec > 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        --time_in_sec;
    }
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Timer thread Ended: " << Trace::EndLog();
    if (time_in_sec == 0)
    {
        std::lock_guard lock(m_lock);

        int call_type = GetObjectPropertyNumber<int>(m_intercom_output_comms, Project::ValueName::IntercomOutputs::ACTIVE_CALL_TYPE);
        PIS::Intercom::ActiveCallType call_type_enum = static_cast<PIS::Intercom::ActiveCallType>(call_type);

        int ohp_status = GetObjectPropertyNumber<int>(m_ohp_output_comms, Project::ValueName::OHPOutputs::STATUS);
        PIS::Intercom::Status ohp_status_enum = static_cast<PIS::Intercom::Status>(ohp_status);

        Trace::GetLogger().STAMP(Trace::VERBOSE) << "After 60 seconds, ohp_status: " << ohp_status << ", call_type: " << call_type << Trace::EndLog();

        if (ohp_status_enum == PIS::Intercom::Status::CALLING && call_type_enum == PIS::Intercom::ActiveCallType::OHP)
        {
            int vehicle_idx = GetObjectPropertyNumber<int>(m_ohp_input_comms, Project::ValueName::OHPInputs::VEHICLE_ID);

            // Disconnect the OHP call (which is in progress)
            m_audio_engine.Stop();
            Trace::GetLogger().STAMP(Trace::INFO) << "Fault 131005 detected, stopping ongoing PE call " << Trace::EndLog();

            // Pulse to SCC Cancel in Intercom to reset all OHP status
            SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 1);
            SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 0);

            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            int ohp_status_after = static_cast<int>(PIS::Intercom::Status::FAULT);

            std::tuple<int, int> ohp_data = GetOHPVehicleNo();
            int veh_no = std::get<0>(ohp_data);
            int pecu_no = std::get<1>(ohp_data);

            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Timer - pecu_no: " << pecu_no << ", veh_no: " << veh_no << Trace::EndLog();
            if (veh_no > 0)
                SetObjectPropertyNumber(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA1_CALL_NOT_ACKNOWLEDGED, ohp_status_after);
            
            Trace::GetLogger().STAMP(Trace::INFO) << "After 60 seconds, ohp_status updated to: " << ohp_status_after << Trace::EndLog();
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "OHP call is either connected or disconnected, but not anymore in Progress " << Trace::EndLog();
        }
    }
}

void PISUnit::EventAcknowledge(const Sim::Number &num_obj)
{
    if (static_cast<int>(num_obj) == 1) 
    {
        std::lock_guard lock(m_lock);

        std::tuple<int, int> ohp_data = GetOHPVehicleNo();
        int veh_no = std::get<0>(ohp_data);

        int ohp_status_after = static_cast<int>(PIS::Intercom::Status::NORMAL);

        Trace::GetLogger().STAMP(Trace::INFO) << " PEA Fault : 131005     CALL ACKNOWLEDGED" << Trace::EndLog();
        SetObjectPropertyNumber(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA1_CALL_NOT_ACKNOWLEDGED, ohp_status_after);
    }
}

void PISUnit::PEAFaultDetection(const Sim::Number &num_obj)
{
    int fault_state = static_cast<int>(num_obj.value);
    Trace::GetLogger().STAMP(Trace::INFO) << "PEAFaultDetection: fault_state " << fault_state << Trace::EndLog();

    if (fault_state > 0.5)
    {
        std::lock_guard lock(m_lock);

        Comms::Object vehicle_object = GetGateway().GetObject(num_obj.object_id);
        Sim::Number::ID vehicle_number = vehicle_object.Numbers().Info().GetID("Index");
        const int veh_idx = static_cast<int>(vehicle_object.Numbers().Store().Get(vehicle_number).value);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "veh idx + 1 (veh no) : " << veh_idx + 1 << Trace::EndLog();

        int call_type = GetObjectPropertyNumber<int>(m_intercom_output_comms, Project::ValueName::IntercomOutputs::ACTIVE_CALL_TYPE);
        PIS::Intercom::ActiveCallType call_type_enum = static_cast<PIS::Intercom::ActiveCallType>(call_type);

        int ohp_status = GetObjectPropertyNumber<int>(m_ohp_output_comms, Project::ValueName::OHPOutputs::STATUS);
        PIS::Intercom::Status ohp_status_enum = static_cast<PIS::Intercom::Status>(ohp_status);

        if (((ohp_status_enum == PIS::Intercom::Status::CALLING) || (ohp_status_enum == PIS::Intercom::Status::TALKING ))
            && call_type_enum == PIS::Intercom::ActiveCallType::OHP)
        {
            std::tuple<int, int> ohp_data = GetOHPVehicleNo();
            int veh_no = std::get<0>(ohp_data);

            int pecu_no = std::get<1>(ohp_data);

            if (veh_idx + 1 == veh_no && veh_no == 1 && pecu_no == 1)
            {
                // Disconnect the OHP call (which is in progress)
                m_audio_engine.Stop();
                Trace::GetLogger().STAMP(Trace::INFO) << "Fault detected, stopping ongoing PE call " << Trace::EndLog();

                // Pulse to SCC Cancel in Intercom to reset all OHP status
                SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 1);
                SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 0);
            }
        }
    }
}

void PISUnit::PEA2FaultDetection(const Sim::Number &num_obj)
{
    int fault_state = static_cast<int>(num_obj.value);
    Trace::GetLogger().STAMP(Trace::INFO) << "PEAFaultDetection: fault_state " << fault_state << Trace::EndLog();

    if (fault_state > 0.5)
    {
        std::lock_guard lock(m_lock);

        Comms::Object vehicle_object = GetGateway().GetObject(num_obj.object_id);
        Sim::Number::ID vehicle_number = vehicle_object.Numbers().Info().GetID("Index");
        const int veh_idx = static_cast<int>(vehicle_object.Numbers().Store().Get(vehicle_number).value);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "veh idx + 1 (veh no) : " << veh_idx + 1 << Trace::EndLog();

        int call_type = GetObjectPropertyNumber<int>(m_intercom_output_comms, Project::ValueName::IntercomOutputs::ACTIVE_CALL_TYPE);
        PIS::Intercom::ActiveCallType call_type_enum = static_cast<PIS::Intercom::ActiveCallType>(call_type);

        int ohp_status = GetObjectPropertyNumber<int>(m_ohp_output_comms, Project::ValueName::OHPOutputs::STATUS);
        PIS::Intercom::Status ohp_status_enum = static_cast<PIS::Intercom::Status>(ohp_status);

        if (((ohp_status_enum == PIS::Intercom::Status::CALLING) || (ohp_status_enum == PIS::Intercom::Status::TALKING))
            && call_type_enum == PIS::Intercom::ActiveCallType::OHP)
        {
            std::tuple<int, int> ohp_data = GetOHPVehicleNo();
            int veh_no = std::get<0>(ohp_data);

            int pecu_no = std::get<1>(ohp_data);

            if (veh_idx + 1 == veh_no && veh_no == 1 && pecu_no == 2)
            {
                // Disconnect the OHP call (which is in progress)
                m_audio_engine.Stop();
                Trace::GetLogger().STAMP(Trace::INFO) << "Fault detected, stopping ongoing PE call " << Trace::EndLog();

                // Pulse to SCC Cancel in Intercom to reset all OHP status
                SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 1);
                SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 0);
            }
        }
    }
}

void PISUnit::PEA3FaultDetection(const Sim::Number &num_obj)
{
    int fault_state = static_cast<int>(num_obj.value);
    Trace::GetLogger().STAMP(Trace::INFO) << "PEAFaultDetection: fault_state " << fault_state << Trace::EndLog();

    if (fault_state > 0.5)
    {
        std::lock_guard lock(m_lock);

        Comms::Object vehicle_object = GetGateway().GetObject(num_obj.object_id);
        Sim::Number::ID vehicle_number = vehicle_object.Numbers().Info().GetID("Index");
        const int veh_idx = static_cast<int>(vehicle_object.Numbers().Store().Get(vehicle_number).value);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "veh idx + 1 (veh no) : " << veh_idx + 1 << Trace::EndLog();

        int call_type = GetObjectPropertyNumber<int>(m_intercom_output_comms, Project::ValueName::IntercomOutputs::ACTIVE_CALL_TYPE);
        PIS::Intercom::ActiveCallType call_type_enum = static_cast<PIS::Intercom::ActiveCallType>(call_type);

        int ohp_status = GetObjectPropertyNumber<int>(m_ohp_output_comms, Project::ValueName::OHPOutputs::STATUS);
        PIS::Intercom::Status ohp_status_enum = static_cast<PIS::Intercom::Status>(ohp_status);

        if (((ohp_status_enum == PIS::Intercom::Status::CALLING) || (ohp_status_enum == PIS::Intercom::Status::TALKING))
            && call_type_enum == PIS::Intercom::ActiveCallType::OHP)
        {
            std::tuple<int, int> ohp_data = GetOHPVehicleNo();
            int veh_no = std::get<0>(ohp_data);

            int pecu_no = std::get<1>(ohp_data);

            if (veh_idx + 1 == veh_no && veh_no == 3 && pecu_no == 3)
            {
                // Disconnect the OHP call (which is in progress)
                m_audio_engine.Stop();
                Trace::GetLogger().STAMP(Trace::INFO) << "Fault detected, stopping ongoing PE call " << Trace::EndLog();

                // Pulse to SCC Cancel in Intercom to reset all OHP status
                SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 1);
                SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 0);
            }
        }
    }
}

void PISUnit::PEAFaultDetectionIncomingCall(const Sim::Number &num_obj)
{
    int fault_state = static_cast<int>(num_obj.value);

    if (fault_state <= 0.5)
        return;

    std::tuple<int, int> ohp_data = GetOHPVehicleNo();
    int veh_no = std::get<0>(ohp_data);
    int pecu_no = std::get<1>(ohp_data);
    int veh_size = static_cast<int>(m_vehicle_comms_list.size());

    Trace::GetLogger().STAMP(Trace::VERBOSE) << veh_size << " <-veh_size   veh_no-> " << veh_no << Trace::EndLog();

    if (veh_no > veh_size || veh_no < 1)  // veh_no should be between (1 to 7) or (1 to 5)
    {
        Trace::GetLogger().STAMP(Trace::INFO) << "Invalid veh_no " << veh_no << Trace::EndLog();
        return;
    }

    bool flag = false;

    int ohp_status = GetObjectPropertyNumber<int>(m_ohp_output_comms, Project::ValueName::OHPOutputs::STATUS);

    int pea1failure = GetObjectPropertyNumber<int>(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA1_FAILURE);
    int pea2failure = GetObjectPropertyNumber<int>(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA2_FAILURE);
    int pea3failure = GetObjectPropertyNumber<int>(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA3_FAILURE);

    if (pea1failure == 1 && num_obj.value == 1)       //car dm1 pecu1
        flag = true;
    else if (pea2failure == 1 && num_obj.value == 2)  //car dm1 pecu2
        flag = true;
    else if (pea3failure == 1 && num_obj.value == 11) //car m3  pecu3
        flag = true;

    if (ohp_status >= 1 && flag)
    {
        // Disconnect the OHP call (which is in progress)
        m_audio_engine.Stop();
        Trace::GetLogger().STAMP(Trace::INFO) << "  Fault detected, stopping incoming PE call " << Trace::EndLog();

        // Pulse to SCC Cancel in Intercom to reset all OHP status
        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 1);
        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, 0);
    }

}

std::tuple<int, int> PISUnit::GetOHPVehicleNo()
{
    int pe_id = GetObjectPropertyNumber<int>(m_ohp_output_comms, Project::ValueName::OHPOutputs::PE_ID);
    int veh_no = pe_id / 4;
    int pecu_no = pe_id % 4;
    if (pecu_no != 0)
    {
        veh_no++;
    }
    else
    {
        pecu_no = 4;
    }

    std::tuple<int, int> ohp_data = { veh_no, pecu_no };
    return ohp_data;
}

void PISUnit::OHPOutputChanged(const Sim::Number &num_obj)
{
    int ohp_output_status = static_cast<int>(num_obj.value);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "OHPOutputChanged: ohp_output_status " << ohp_output_status << Trace::EndLog();
    bool fault_trigger = false;
    {
        std::lock_guard lock(m_lock);

        if (ohp_output_status == static_cast<int>(PIS::Intercom::Status::CALLING))
        {
            // OHP Call in Progress

            fault_trigger = true;
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Check Fault on PEA for 60 sec " << Trace::EndLog();

            std::tuple<int, int> ohp_data = GetOHPVehicleNo();
            int veh_no = std::get<0>(ohp_data);
            int pecu_no = std::get<1>(ohp_data);

            int vehicle_count = m_vehicle_comms_list.size();

            Trace::GetLogger().STAMP(Trace::VERBOSE) << "pecu_no: " << pecu_no << ", veh_no: " << veh_no << ",  vehicle_count: " << vehicle_count << Trace::EndLog();

            if (vehicle_count == 6)
            {
                if (veh_no == DMC_1 || veh_no == DMC_6)
                {
                    //SetObjectPropertyNumber(m_vehicle_comms_list[veh_no - 1],Project::ValueName::Vehicle::FLT_PEA1_ALARM_ACTIVE, 1.0);
                }
                else if (veh_no == MC_3 || veh_no == MC_4)
                {
                    //SetObjectPropertyNumber(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA2_ALARM_ACTIVE, 1.0);
                }
            }
            else if (vehicle_count == 8)
            {
                if (veh_no == DMC_1 || veh_no == DMC_8)
                {
                    //SetObjectPropertyNumber(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA1_ALARM_ACTIVE, 1.0);
                }
                else if (veh_no == MC_3 || veh_no == MC_4 || veh_no == MC_6)
                {
                    //SetObjectPropertyNumber(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA2_ALARM_ACTIVE, 1.0);
                }
            }
        }
    }

    if (fault_trigger == true)
    {
        auto timer_thread = std::thread(&PISUnit::TimerThread, this);
        timer_thread.detach();
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Timer thread detached: " << timer_thread.get_id() << Trace::EndLog();
    }
    else
    { 
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "No need to check for fault " << Trace::EndLog();
    }
}

void PISUnit::PeaAlarmActiveCallback(const Sim::Number &num_obj)
{
    int pe_id = static_cast<int>(num_obj.value);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "PE_ID: " << pe_id << Trace::EndLog();
    std::lock_guard lock(m_lock);

    if (num_obj.value == 0.0)
    {
        SetObjectPropertyNumber(m_vehicle_comms_list[0], Project::ValueName::Vehicle::FLT_PEA1_ALARM_ACTIVE, 0.0);
        SetObjectPropertyNumber(m_vehicle_comms_list[2], Project::ValueName::Vehicle::FLT_PEA2_ALARM_ACTIVE, 0.0);
    }

    std::tuple<int, int> ohp_data = GetOHPVehicleNo();
    int veh_no = std::get<0>(ohp_data);
    int pecu_no = std::get<1>(ohp_data);

    int vehicle_count = m_vehicle_comms_list.size();

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "pecu_no: " << pecu_no << ", veh_no: " << veh_no << ",  vehicle_count: " << vehicle_count << Trace::EndLog();

    if (veh_no == DMC_1 && pecu_no == 1)
    {
        SetObjectPropertyNumber(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA1_ALARM_ACTIVE, 1.0);
    }
    else if (veh_no == MC_3 && pecu_no == 2)
    {
        SetObjectPropertyNumber(m_vehicle_comms_list[veh_no - 1], Project::ValueName::Vehicle::FLT_PEA2_ALARM_ACTIVE, 1.0);
    }

    HandlePABRAndPOBRStatus(num_obj.value);

}

void PISUnit::HandlePABRAndPOBRStatus(const double value)
{
    m_is_pecu_active = false;
    if (0.0 == value)
    {
        //Reset PABR & POBR status
        //PABOR - BLACK
        //PABR - GREEN
        SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABOR_STATUS_DM1, BLACK);
        SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABOR_STATUS_DM2, BLACK);
        SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_STATUS_DM1, GREEN);
        SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_STATUS_DM2, GREEN);

        //store PABR state
        m_pabr_bypass_state_last = 0.0;

        //Write PABR Bypass status to IntercomOutputs to inform ATP module to reset PECU EB.
        SetObjectPropertyNumber(m_intercom_output_comms, Project::ValueName::IntercomOutputs::PABR_BYPASS_REQ, m_pabr_bypass_state_last);

        //Update VDUOutput for PABR Bypass staus - No need to UI
        //SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_BYPASS_REQ_BUTTON, m_pabr_bypass_state_last);
    }
    else if (value > 0.5)
    {
        m_is_pecu_active = true;
        //PABR - GREY
        //PABOR - BLACK
        SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABOR_STATUS_DM1, BLACK);
        SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABOR_STATUS_DM2, BLACK);
        SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_STATUS_DM1, GREY);
        SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_STATUS_DM2, GREY);
    }
}

void PISUnit::PABRBypassChanged(const Sim::Number &num_obj)
{    
    //Pulse from UI    
    //PECU active & PABR bypass press
    if (m_is_pecu_active && 0.0 == num_obj.value)
    {
        //If last state is not bypass req, then new status is PABR Bypass req
        if (0.0 == m_pabr_bypass_state_last)
        {
            //PABOR - BLUE
            //PABR - GREY
            SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABOR_STATUS_DM1, BLUE);
            SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABOR_STATUS_DM2, BLUE);
            SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_STATUS_DM1, GREY);
            SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_STATUS_DM2, GREY);

            //store PABR state
            m_pabr_bypass_state_last = 1.0;

            //Write PABR Bypass status to IntercomOutputs to inform ATP module to reset PECU EB.
            SetObjectPropertyNumber(m_intercom_output_comms, Project::ValueName::IntercomOutputs::PABR_BYPASS_REQ, m_pabr_bypass_state_last);

            //Update VDUOutput for PABR Bypass staus  - No need to UI
            //SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_BYPASS_REQ_BUTTON, m_pabr_bypass_state_last);
        }
        else if (1.0 == m_pabr_bypass_state_last)
        {
            //PABR - GREY
            //PABOR - BLACK
            SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABOR_STATUS_DM1, BLACK);
            SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABOR_STATUS_DM2, BLACK);
            SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_STATUS_DM1, GREY);
            SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_STATUS_DM2, GREY);

            //store PABR state
            m_pabr_bypass_state_last = 0.0;

            //Write PABR Bypass status to IntercomOutputs to inform ATP module to reset PECU EB.
            SetObjectPropertyNumber(m_intercom_output_comms, Project::ValueName::IntercomOutputs::PABR_BYPASS_REQ, m_pabr_bypass_state_last);

            //Update VDUOutput for PABR Bypass staus - No need to UI
            //SetObjectPropertyNumber(m_vdu_outputs_comms, Project::ValueName::VDUOutputs::PABR_BYPASS_REQ_BUTTON, m_pabr_bypass_state_last);
        }

    }

}


void PISUnit::VehicleOutputChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.value > 0.5)
        m_fist_mic_enable = true;
    else
        m_fist_mic_enable = false;

}

void PISUnit::IntercomOutputChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::INACTIVE)
    {
        // Receiving Call Request
        if (num_obj.value == static_cast<int>(CallState::CALL_REQUEST))
        {
            m_state.m_intercom_output = static_cast<int>(CallState::CALL_REQUEST);
            m_state.m_buzzer_active = true;
            m_audio_engine.Stop();
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom Output state: Calling " << Trace::EndLog();
        }
        // Call Connected
        else if (num_obj.value == static_cast<int>(CallState::CALL_CONNECTED))
        {
            m_audio_engine.Stop();
            m_state.m_intercom_output = static_cast<int>(CallState::CALL_CONNECTED);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom Output state: Call Active " << Trace::EndLog();
        }
        else if (num_obj.value < 0.5)
        {
            m_audio_engine.Stop();
            m_state.m_intercom_output = 0;
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom Output state: InActive " << Trace::EndLog();
        }
    }
}

void PISUnit::TrainIDChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.value > 0.5)
    {
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TRAIN_ID, num_obj.value);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Train ID changed " << num_obj.value << Trace::EndLog();
    }
}

//void PISUnit::RouteIDChanged(const Sim::Number &num_obj)
//{
//    std::lock_guard lock(m_lock);
//    if (num_obj.value > 0.5)
//    {
//        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_ROUTE_ID, num_obj.value);
//        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Route ID changed " << num_obj.value << Trace::EndLog();
//    }
//}

void PISUnit::StartStationChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.value > 0.5)
    {
        if (m_state.m_route_id != -1)
        {
            m_state.m_start_station_xml_id = static_cast<int>(num_obj.value);
            SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_START_STATION_ID, m_state.m_start_station_xml_id);

            auto start_station_db_id = m_announcements->ConvertXmlIdToDbId(m_state.m_start_station_xml_id);
            m_state.UpdateRouteStations(start_station_db_id, StationLocation::START_STATION);

            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Start Station ID changed " << num_obj.value << Trace::EndLog();

            SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TERMINAL_STATION_ID, -1);
            SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_NEXT_STATION_ID, -1);
            m_state.m_terminal_station_xml_id = -1;
            m_state.m_next_station_xml_id = -1;
        }
    }
}

void PISUnit::StationAnnouncementModeChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.value > 0.5)
    {
        m_announcement_mode = static_cast<int>(num_obj.value);
    }
}

void PISUnit::TerminalStationChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.value > 0.5)
    {
        if (m_state.m_route_id != -1)
        {
            auto terminal_station_db_id = m_announcements->ConvertXmlIdToDbId(static_cast<int>(num_obj.value));
            bool ret = m_state.UpdateRouteStations(terminal_station_db_id, StationLocation::TERMINAL_STATION); //it will update the short loop stations
            if (ret)
            {
                m_state.m_terminal_station_xml_id = static_cast<int>(num_obj.value);
                SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TERMINAL_STATION_ID, m_state.m_terminal_station_xml_id);
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Terminal Station ID changed " << num_obj.value << Trace::EndLog();
            }
            else
            {
                m_state.m_terminal_station_xml_id = -1;
                SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TERMINAL_STATION_ID, m_state.m_terminal_station_xml_id);
                Trace::GetLogger().STAMP(Trace::WARN) << "Incorrect Terminal Station ID selected " << num_obj.value << Trace::EndLog();
            }
        }
    }
}

void PISUnit::NextStationChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.value > 0.5)
    {
        if (m_state.m_route_id != -1)
        {
            m_state.m_next_station_xml_id = static_cast<int>(num_obj.value);
            SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_NEXT_STATION_ID, m_state.m_next_station_xml_id);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Next Station ID changed " << num_obj.value << Trace::EndLog();
        }
    }
}

void PISUnit::PublicAnnoucemntChanged(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.value > 0.5)
    {
        m_audio_engine.Stop();
        //m_state.m_intercom_output = 1;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Public Annoucemnt: start " << Trace::EndLog();
    }
    else 
    {
        //m_state.m_intercom_output = 0;
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Public Annoucemnt: stop " << Trace::EndLog();
    }
}

void PISUnit::RadioAudioEnable(const Sim::Number &num_obj) 
{
    m_state.m_radio_intercom_state = static_cast<int>(num_obj.value);
    if (num_obj.value == static_cast<int>(CallState::CALL_REQUEST))
    {
        std::lock_guard lock(m_lock);
        m_state.m_buzzer_active = true;
        m_audio_engine.Stop();
    }
    else if (num_obj.value == static_cast<int>(CallState::INACTIVE) || num_obj.value == static_cast<int>(CallState::CALL_CONNECTED))
    {
        std::lock_guard lock(m_lock);
        m_audio_engine.Stop();
    }
}

void PISUnit::Step(double new_time)
{
    if (m_temp) {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " OHP_ID set to 0 " << Trace::EndLog();
        SetObjectPropertyNumber(m_ohp_input_comms, Project::ValueName::OHPInputs::OHP_ID, 0);

        for (auto itr : m_dbId_stationId_map) // from here we will get DB_id
        {
            dva::StationData station_data;

            m_announcements->GetStationData(itr.first, station_data); // Station data is for current db_id
            auto Station_Code = station_data.short_name;

            int xml_station_id = m_announcements->ConvertStationDbIdToXmlId(itr.first); // Conversion from db to xml_id

            m_station_code_xml_id_map.insert(std::make_pair(Station_Code, xml_station_id)); // Storing the data as (station_code , xml_id) in map
            // Now we Have a map of (Station_code : Xml_id),  All other maps have DB_id as key value
            // None of map have xml_id as key value
        }
        m_temp = false;
    }

    if (CheckHandleOffAndPoweringOn(new_time))
        return;

    const int station_announcement_mode = GetObjectPropertyNumber<int>(m_pis_inputs_comms, Project::ValueName::PISBEInputsValues::STATION_ANNOUNCEMENT_MODE);
    HandleFistAnnouncement();
    HandleOCCAnnouncement();
    HandleEmergencyAnnouncement();
    HandleSpecialAnnouncement();

    const int route_id = GetObjectPropertyNumber<int>(m_pis_inputs_comms, Project::ValueName::PISBEInputsValues::ROUTE_SELECTION_ID);
    auto route_selected  = m_announcements->GetDbRouteID(route_id);

    if (station_announcement_mode != -1 && station_announcement_mode != m_state.m_announce_state)
    {
        m_state.m_announce_state = station_announcement_mode;
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_MODE, m_state.m_announce_state);
    }

    if (route_id != m_state.m_route_id)
    {
        m_state.m_route_id = route_id;
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_ROUTE_ID, m_state.m_route_id);
        //Required by PSD
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_ROUTE_ID_PSD, m_state.m_route_id);

        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_START_STATION_ID, -1);
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TERMINAL_STATION_ID, -1);
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_NEXT_STATION_ID, -1);
        m_state.m_start_station_xml_id = -1;
        m_state.m_terminal_station_xml_id = -1;
        m_state.m_next_station_xml_id = -1;
    }

    const int door_open_state = GetObjectPropertyNumber<int>(m_papis_vehicle_outputs_comms, Project::ValueName::PAPISVehicleOutputs::DOOR_OPEN);
    const int door_close_state = GetObjectPropertyNumber<int>(m_papis_vehicle_outputs_comms, Project::ValueName::PAPISVehicleOutputs::DOOR_CLOSE);    
    const double train_speed = GetObjectPropertyNumber<double>(m_vehicle_comms, Project::ValueName::Vehicle::TDO_SPEED);

    if (door_open_state > 0 && m_state.m_current_station_id != -1 && train_speed == 0 && m_state.getOpenDoorState() != 1)
    {
        PlayDoorChime(m_state.m_current_station_id, true);
        m_state.setOpenDoorState(1);
    }  
    else if (door_close_state > 0 && m_state.getOpenDoorState() == 1)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "door_close Chime: " << door_close_state << ", door open state: " << m_state.getOpenDoorState() << Trace::EndLog();
        PlayDoorChime(m_state.m_current_station_id, false);
        m_state.setOpenDoorState(0);
        //m_state.m_current_station_id = -1;
    }

    if (m_state.m_announce_state == Project::TypeValue::StationAnnouncementMode::AUTO)
    {
        if (m_state.getState() != PISState::State::auto_announce || route_selected != m_state.getRouteSelected())
        {
            Trace::GetLogger().STAMP(Trace::INFO) << "Set auto announcement mode or selected route is changed." << Trace::EndLog();
            SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_START_STATION_ID, -1);
            SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TERMINAL_STATION_ID, -1);
            SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_NEXT_STATION_ID, -1);
            m_state.m_start_station_xml_id = -1;
            m_state.m_terminal_station_xml_id = -1;
            m_state.m_next_station_xml_id = -1;
            m_state.setAutoAnnounce();

            DetectRouteAndPosition(route_selected);
        }

        HandleAutoAnouncements();
    }
    else
    {
        if (route_selected != m_state.getRouteSelected())
        {
            const auto routes = Train::Database::Timetable(m_data_access).GetRoutes(
                Core::Database::Network(m_data_access).GetNetworkIDForScenario(m_scenario_id));

            const auto selected_route_it =
                std::find_if(routes.begin(), routes.end(), [route_selected](const Train::Data::Timetable::Route& route)
                {
                    return route.id == route_selected;
                });

            if (selected_route_it != routes.end())
            {
                Trace::GetLogger().STAMP(Trace::INFO) << "Changing stations to selected route. Route Id: " << route_selected << Trace::EndLog();

                std::vector<int> selected_route_stations;
                Trace::GetLogger().STAMP(Trace::INFO) << " Route stations: ";
                for (const auto& station : selected_route_it->stations)
                {
                    selected_route_stations.push_back(station.id);
                    Trace::GetLogger().STAMP(Trace::INFO) << " " << m_announcements->ConvertStationDbIdToXmlId(station.id); 
                }
                Trace::GetLogger().STAMP(Trace::INFO) << Trace::EndLog();
                m_state.setRouteStations(selected_route_stations, -1);

                size_t size = selected_route_stations.size();
                if (size > 0)
                {
                    m_state.m_start_station_xml_id = m_announcements->ConvertStationDbIdToXmlId(selected_route_stations[0]);
                    m_state.m_terminal_station_xml_id = m_announcements->ConvertStationDbIdToXmlId(size-1);;
                }
            }
            else
            {
                Trace::GetLogger().STAMP(Trace::ERR) << "Stations cannot be changed to unknown route : " << route_selected << Trace::EndLog();
            }
        }

        if (m_state.m_announce_state == Project::TypeValue::StationAnnouncementMode::SEMIAUTO)
        {
            if (m_state.getState() != PISState::State::semi_auto_announce)
            {
                Trace::GetLogger().STAMP(Trace::INFO) << "Set semi-auto announcement mode." << Trace::EndLog();
                m_state.setSemiAutoAnnounce();
                //SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_START_STATION_ID, -1);
                //SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TERMINAL_STATION_ID, -1);
                //SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_NEXT_STATION_ID, -1);
                //m_state.m_start_station_xml_id = -1;
                //m_state.m_terminal_station_xml_id = -1;
                //m_state.m_next_station_xml_id = -1;
            }

            HandleSemiAutoAnouncements(); //door_state, train_speed);
        }
        else
        {
            if (m_state.getState() != PISState::State::manual_announce)
            {
                Trace::GetLogger().STAMP(Trace::INFO) << "Set manual station broadcast mode." << Trace::EndLog();
                m_state.setManualAnnounce();
                //SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_START_STATION_ID, -1);
                //SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TERMINAL_STATION_ID, -1);
                //SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_NEXT_STATION_ID, -1);
                //m_state.m_start_station_xml_id = -1;
                //m_state.m_terminal_station_xml_id = -1;
                //m_state.m_next_station_xml_id = -1;
            }
            HandleManualAnnouncement();
        }
    }
    //m_state.setOpenDoorState(door_open_state);
    
    m_state.setRouteSelected(route_selected);
    m_state.setTrainSpeed(train_speed);
    
    //Data required by PSD application
    {
       //platform side
        auto platform_side = GetPlatformSide();
        if (platform_side != m_state.getPlatformSide())
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "PSD : Setting Platform side ==>"<< platform_side << Trace::EndLog();            
            if (platform_side == PlatformSide::LEFT_SIDE)
                CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::PLATFORM_SIDE_PSD, PlatformSide::LEFT_SIDE);
            else if (platform_side == PlatformSide::RIGHT_SIDE)
                CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::PLATFORM_SIDE_PSD, PlatformSide::RIGHT_SIDE);
            else
                CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::PLATFORM_SIDE_PSD, PlatformSide::NONE);
            m_state.setPlatformSide(static_cast<PlatformSide> (platform_side));
        }
    }

    //Data  required by TCMS - Hybrid mode
    {
        //platform side

        auto is_train_near_station = IsTrainNearStationArea();
        const auto tcms_train_near_station{ true == is_train_near_station ? 1 : 0 };
        if (is_train_near_station != m_state.m_is_train_near_to_station)
        {
            CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::TCMS_TRAIN_NEAR_STATION, tcms_train_near_station);
            m_state.m_is_train_near_to_station = is_train_near_station;
        }

    }
    
}

double PISUnit::GetPeriod() const
{
    return (1.0 / REQUEST_FREQ);
}

void PISUnit::ObjectCreated(Comms::Object object)
{
    size_t class_id = Core::GetClassID(object);

    const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);

    switch (class_id)
    {
    case Project::ClassID::WORLD:
        CreateAudioPlayThread();
        Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
        break;

    case Project::ClassID::TRAIN:
    {
        if (GetObjectPropertyNumber<int>(object, Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::DVA));
            Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
        }
    }
    break;

    case Project::ClassID::VEHICLE:
    {
        if (GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));

            int vehicle_index = GetObjectPropertyNumber<int>(object, Train::ValueName::Vehicle::INDEX);
            if (vehicle_index == m_cab_vehicle_idx)
            {
                m_vehicle_comms = object;

                RequestProperty(object, Project::ValueName::Vehicle::TDO_SPEED);

                object.CreateChild(Project::GetObjectDefinition(Project::ClassID::PIS_BE));
                object.CreateChild(Project::GetObjectDefinition(Project::ClassID::PIS));
            }
        }
        m_vehicle_comms_list.push_back(object);
        RequestProperty(object, Project::ValueName::Vehicle::FLT_PEA1_FAILURE);
        RequestProperty(object, Project::ValueName::Vehicle::FLT_PEA2_FAILURE);
        RequestProperty(object, Project::ValueName::Vehicle::FLT_PEA3_FAILURE);

        Comms_Number_Listener_t num_listener;
        //1
        Sim::Number number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_PEA1_FAILURE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_PEA1_FAILURE
                << " is not a valid number in Vehicle (FLT_PEA1_FAILURE), hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::PEAFaultDetection, this));
        }
        //2
        number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_PEA2_FAILURE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_PEA2_FAILURE
                << " is not a valid number in IntercomInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::PEA2FaultDetection, this));
        }
        //3
        number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_PEA3_FAILURE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_PEA3_FAILURE
                << " is not a valid number in IntercomInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::PEA3FaultDetection, this));
        }
        //4
        //   Commenting for the case of future requirement
        /*number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_MCB_PA_GROUP_OPEN);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_MCB_PA_GROUP_OPEN
                << " is not a valid number in IntercomInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::FaultMcbPaGroup, this));
        }*/

        object.Numbers().Store().AddListener(num_listener);
    }
    break;
    case Project::ClassID::VEHICLE_INPUTS:
    {
        Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
    }
    break;
    case Project::ClassID::VEHICLE_INPUTS_VALUES:
    {
        m_vehicle_inputs_values_comms = object;
        Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
        
        Comms_Number_Listener_t num_listener;
        Sim::Number number = object.Numbers().Get(Project::ValueName::VehicleInputsValues::MICROPHONE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VehicleInputsValues::MICROPHONE
                << " is not a valid number in VehicleInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::/*StopEmgSpc*/VehicleOutputChanged, this));
        }
        object.Numbers().Store().AddListener(num_listener);
        
    }
    break;

    case Project::ClassID::VDU:
    {
        Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
    }
    break;

    case Project::ClassID::VDU_INPUTS:
    {
        Comms_Number_Listener_t num_listener;
        Sim::Number number = object.Numbers().Get(Project::ValueName::VDUInputs::EVENT_ACKNOWLEDGE_BUTTON);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputs::EVENT_ACKNOWLEDGE_BUTTON
                << " is not a valid number in VDU_INPUTS, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::EventAcknowledge, this));
        }               

        object.Numbers().Store().AddListener(num_listener);
    }
    break;


    case Project::ClassID::VDU_OUTPUTS:
    {
        m_vdu_outputs_comms = object;
        RequestProperty(object, Project::ValueName::VDUOutputs::PABR_STATUS_DM1);
        RequestProperty(object, Project::ValueName::VDUOutputs::PABR_STATUS_DM2);
        RequestProperty(object, Project::ValueName::VDUOutputs::PABOR_STATUS_DM1);
        RequestProperty(object, Project::ValueName::VDUOutputs::PABOR_STATUS_DM2);        
    }
    break;

    case Project::ClassID::DVA:
    {
        if (GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            // Considering only our related scenario Train
            Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::DVA_OUTPUTS));
        }
    }
    break;

    case Project::ClassID::DVA_OUTPUTS:
    {
        if (GetObjectPropertyNumber<int>(object.GetParent().GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            m_dva_output_comms = object;

            m_dva_stop_id = m_dva_output_comms.Numbers().Info().GetID(Project::ValueName::DVAOutputs::DVA_STOPPED);
            Sim::NumberInfo numinfo = m_dva_output_comms.Numbers().Info().GetInfo(m_dva_stop_id);
            m_dva_output_comms.Numbers().Store().Request(numinfo, REQUEST_FREQUENCY);
            m_dva_output_comms.Numbers().Store().AddListener(m_dva_stop_listener);

            m_dva_start_id = m_dva_output_comms.Numbers().Info().GetID(Project::ValueName::DVAOutputs::DVA_STARTED);
            Sim::NumberInfo numinfo2 = m_dva_output_comms.Numbers().Info().GetInfo(m_dva_start_id);
            m_dva_output_comms.Numbers().Store().Request(numinfo2, REQUEST_FREQUENCY);
            m_dva_output_comms.Numbers().Store().AddListener(m_dva_start_listener);
        }
    }
    break;

    case Project::ClassID::INTERCOM:
    {
        if (GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            // Considering only our related scenario Train
            Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
        }
    }
    break;

    case Project::ClassID::INTERCOM_INPUTS:
    {
        m_intercom_input_comms = object;

        {
            RequestProperty(object, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON);
        }
    }
    break;

    case Project::ClassID::INTERCOM_OUTPUTS:
    {
        m_intercom_output_comms = object;

        RequestProperty(object, Project::ValueName::IntercomOutputs::ACTIVE_CALL_TYPE);
        RequestProperty(object, Project::ValueName::IntercomOutputs::PABR_BYPASS_REQ);
        Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));

        Comms_Number_Listener_t num_listener;
        Sim::Number number = object.Numbers().Get(Project::ValueName::IntercomOutputs::INTERCOM);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::IntercomOutputs::INTERCOM
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::IntercomOutputChanged, this));
        }

        number = object.Numbers().Get(Project::ValueName::IntercomOutputs::PUBLIC_ADDRESS);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::IntercomOutputs::PUBLIC_ADDRESS
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::PublicAnnoucemntChanged, this));
        }

        object.Numbers().Store().AddListener(num_listener);
    }
    break;

    case Project::ClassID::OHP_INPUTS:
    {
        m_ohp_input_comms = object;

        RequestProperty(object, Project::ValueName::OHPInputs::VEHICLE_ID);
    }
    case Project::ClassID::OHP_OUTPUTS:
    {
        m_ohp_output_comms = object;

        Comms_Number_Listener_t num_listener;
        Sim::Number number = object.Numbers().Get(Project::ValueName::OHPOutputs::STATUS);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::OHPOutputs::STATUS
                << " is not a valid number in OHPOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::OHPOutputChanged, this));
        }
        //2
        number = object.Numbers().Get(Project::ValueName::OHPOutputs::PE_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::OHPOutputs::PE_ID
                << " is not a valid number in OHPOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::PEAFaultDetectionIncomingCall, this));
            num_listener.AddCallback(number, MakeCallback(&PISUnit::PeaAlarmActiveCallback, this));
        }

        object.Numbers().Store().AddListener(num_listener);

        RequestProperty(object, Project::ValueName::OHPOutputs::PE_ID);
        RequestProperty(object, Project::ValueName::OHPOutputs::STATUS);
    }
    break;

    case Project::ClassID::PIS:
    {
        auto scenario_train_id = object.GetParent().GetParent().Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value;
        auto vehicle_index = object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value;
        if ((scenario_train_id == m_scenario_train_id) && (vehicle_index == m_cab_vehicle_idx))
        {
            Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::PIS_OUTPUTS));
        }
        
    }
    break;

    case Project::ClassID::RADIO_INTERCOM: 
    {
        if (GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
        }
    }
    break;

    case Project::ClassID::RADIO_INTERCOM_INPUTS_VALUES:
    {
        m_radio_inputs_comms = object;
    }
    break;
    
    case Project::ClassID::RADIO_INTERCOM_OUTPUTS:
    {
        Sim::Number number = object.Numbers().Get(Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE
                << " is not a valid number in RadioIntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            Comms_Number_Listener_t num_listener;
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::RadioAudioEnable, this));
            object.Numbers().Store().AddListener(num_listener);
        }
    }
    break;

    case Project::ClassID::PIS_BE:
    {
        auto scenario_train_id = object.GetParent().GetParent().Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value;
        auto vehicle_index = object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value;
        if ((scenario_train_id == m_scenario_train_id) && (vehicle_index == m_cab_vehicle_idx))
        {
            Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));

            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::PIS_BE_INPUTS));
            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::PIS_BE_OUTPUTS));
        }
    }
    break;

    case Project::ClassID::PIS_BE_OUTPUTS:
    {
        m_pis_outputs_comms = object;
    }
    break;

    case Project::ClassID::PIS_BE_INPUTS:
    {
        Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));

        object.CreateChild(Project::GetObjectDefinition(Project::ClassID::PIS_BE_INPUTS_VALUES));
        object.CreateChild(Project::GetObjectDefinition(Project::ClassID::PIS_BE_INPUTS_MODES));
    }
    break;

    case Project::ClassID::PIS_BE_INPUTS_VALUES:
    {
        m_pis_inputs_comms = object;

        RequestProperty(object, Project::ValueName::PISBEInputsValues::STATION_ANNOUNCEMENT_MODE);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::ROUTE_SELECTION_ID);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::INSTRUCTOR_ANNOUNCEMENT_ID);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::SPECIAL_ANNOUNCEMNT_ID);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::STOP_SPECIAL_ANNOUNCEMNT);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::SPECIAL_ANNONCMNT_COUNT);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::EMERGENCY_ANNOUNCEMNT_ID);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::STOP_EMERGENCY_ANNOUNCEMNT);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::EMERGENCY_ANNONCMNT_COUNT);
        RequestProperty(object, Project::ValueName::PISBEInputsValues::ANNOUNCEMENT_MODE_CHANGED_BTN);

        //const double REQUEST_FREQUENCY = 20.0;
        m_skip_list_id = m_pis_inputs_comms.Raws().Info().GetID(Project::ValueName::PISBEInputsValues::SKIP_STATION_LIST);
        Sim::RawInfo info = m_pis_inputs_comms.Raws().Info().GetInfo(m_skip_list_id);
        m_pis_inputs_comms.Raws().Store().Request(info, REQUEST_FREQUENCY);
        m_pis_inputs_comms.Raws().Store().AddListener(m_skipList_listener);

        m_arrive_depart_msg_id = m_pis_inputs_comms.Raws().Info().GetID(Project::ValueName::PISBEInputsValues::ARRIVE_DEPART_MSG);
        Sim::RawInfo info2 = m_pis_inputs_comms.Raws().Info().GetInfo(m_arrive_depart_msg_id);
        m_pis_inputs_comms.Raws().Store().Request(info2, REQUEST_FREQUENCY);
        m_pis_inputs_comms.Raws().Store().AddListener(m_arrive_depart_msg_listener);

        m_intercom_state_id = m_pis_inputs_comms.Numbers().Info().GetID(Project::ValueName::PISBEInputsValues::INTERCOM_STATUS);
        Sim::NumberInfo numinfo = m_pis_inputs_comms.Numbers().Info().GetInfo(m_intercom_state_id);
        m_pis_inputs_comms.Numbers().Store().Request(numinfo, REQUEST_FREQUENCY);
        m_pis_inputs_comms.Numbers().Store().AddListener(m_intercom_state_listener);

        Comms_Number_Listener_t num_listener;
        Sim::Number number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::START_STATION_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PISBEInputsValues::START_STATION_ID
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::StartStationChanged, this));
        }

        number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::STATION_ANNOUNCEMENT_MODE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PISBEInputsValues::STATION_ANNOUNCEMENT_MODE
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::StationAnnouncementModeChanged, this));
            num_listener.AddCallback(number, MakeCallback(&PISUnit::SkipStationFeature, this));
        }

        number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::STOP_EMERGENCY_ANNOUNCEMNT);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PISBEInputsValues::STOP_EMERGENCY_ANNOUNCEMNT
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::StopEmgSpc, this));
        }

        number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::STOP_SPECIAL_ANNOUNCEMNT);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PISBEInputsValues::STOP_SPECIAL_ANNOUNCEMNT
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::StopEmgSpc, this));
        }
        
        try
        {

            number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::ANNOUNCEMENT_MODE_CHANGED_BTN);
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::AnnouncementModeChanged, this));
        }
        catch (CommonException& e)
        {
            Trace::GetLogger().STAMP(Trace::ERR)
                << "Project::ValueName::PISBEInputsValues::ANNOUNCEMENT_MODE_CHANGED_BTN"
                << " is not a valid number, hence ignoring." << Trace::EndLog();
        }

        //number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::ROUTE_SELECTION_ID);
        //if (number.id == Sim::INVALID_NUMBER)
        //{
        //    Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PISBEInputsValues::ROUTE_SELECTION_ID
        //        << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        //}
        //else
        //{
        //    object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
        //    num_listener.AddCallback(number, MakeCallback(&PISUnit::PublicAnnoucemntChanged, this));
        //}

        number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::TERMINAL_STATION_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PISBEInputsValues::TERMINAL_STATION_ID
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::TerminalStationChanged, this));
        }

        number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::NEXT_STATION_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PISBEInputsValues::NEXT_STATION_ID
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::NextStationChanged, this));
        }
        number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::TRAIN_ID_CHANGE_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PISBEInputsValues::TRAIN_ID_CHANGE_REQUEST
                << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&PISUnit::TrainIDChanged, this));
        }

        number = object.Numbers().Get(Project::ValueName::PISBEInputsValues::PABR_STATUS);
        object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
        num_listener.AddCallback(number, MakeCallback(&PISUnit::PABRBypassChanged, this));

        object.Numbers().Store().AddListener(num_listener);
    }
    break;

    case Core::ClassID::FEATURES:
    {
        Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));
    }
    break;

    case Core::ClassID::FEATURE:
    {
        int feature_id = GetObjectPropertyNumber<int>(object, Train::ValueName::Feature::FEATURE_ID);

        if (m_feature_id_to_station_id.find(feature_id) != m_feature_id_to_station_id.end())
            Comms::AddCreationCallback(object, MakeCallback(&PISUnit::ObjectCreated, this));

        int feature_id_door = GetObjectPropertyNumber<int>(object, Core::ValueName::Feature::TYPE);
        if (feature_id_door == m_platform_stopping_point_type_id) 
        {
            m_platform_stopping_point.push_back(object);
            RequestProperty(object, Project::ValueName::Feature::STATE);

            Comms_Number_Listener_t num_listener;
            auto number = object.Numbers().Get(Project::ValueName::Feature::STATE);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Feature::STATE
                    << " is not a valid number in IntercomOutputs, hence ignoring." << Trace::EndLog();
            }
            else
            {
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
                num_listener.AddCallback(number, MakeCallback(&PISUnit::SkipStationFeature, this));
            }

            object.Numbers().Store().AddListener(num_listener);
        }

    }
    break;

    case Core::ClassID::TRACK_ASSOCIATION:
    {
        int feature_id = GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Feature::FEATURE_ID);

        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Add track association for feature id : " << feature_id << Trace::EndLog();

        m_track_association.AddAssociation(object);
    }
    break;

    case Project::ClassID::PAPIS_VEHICLE_OUTPUTS:
    {
        auto scenario_train_id = object.GetParent().GetParent().Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value;
        if ((scenario_train_id == m_scenario_train_id))
        {
            m_papis_vehicle_outputs_comms = object;
            RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER);
            RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::ALL_DOOR_CLOSE);
            RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::DOOR_CLOSE);            
            RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::DOOR_OPEN);
            RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::ZERO_SPEED);
            RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::EMERGENCY_DOOR_OPEN);
            RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::PECU_ALARM_ACTIVE);

            //Add callback for Project::ValueName::PAPISVehicleOutputs::DOOR_CLOSE_ANNOUNCEMENT
            Sim::Number number = object.Numbers().Get(Project::ValueName::PAPISVehicleOutputs::DOOR_CLOSE_ANNOUNCEMENT);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PAPISVehicleOutputs::DOOR_CLOSE_ANNOUNCEMENT
                    << " is not a valid number in PAPISVehicleOutputs, hence ignoring." << Trace::EndLog();
            }
            else
            {
                Comms_Number_Listener_t num_listener;
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
                num_listener.AddCallback(number, MakeCallback(&PISUnit::PlayDoorCloseAnnouncemnt, this));
                object.Numbers().Store().AddListener(num_listener);
            }

            //number = object.Numbers().Get(Project::ValueName::PAPISVehicleOutputs::COUPLE);
            //if (number.id == Sim::INVALID_NUMBER)
            //{
            //    Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PAPISVehicleOutputs::COUPLE
            //        << " is not a valid number in PAPISVehicleOutputs (COUPLE), hence ignoring." << Trace::EndLog();
            //}
            //else
            //{
            //    Comms_Number_Listener_t num_listener;
            //    object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            //    num_listener.AddCallback(number, MakeCallback(&PISUnit::PEAFaultDetection, this));
            //    object.Numbers().Store().AddListener(num_listener);
            //}
        }
    }
    break;
    }
}


void PISUnit::AnnouncementModeChanged(const Sim::Number &num_obj)
{
    if (num_obj.value > 0.5)
    {
        Sim::Number next_station_id;
        try
        {

            next_station_id = m_pis_inputs_comms.Numbers().Get(Project::ValueName::PISBEInputsValues::NEXT_STATION_ID);
            next_station_id = m_announcements->ConvertXmlIdToDbId(next_station_id);
        }
        catch (CommonException& e)
        {
            Trace::GetLogger().STAMP(Trace::ERR)
                << "Project::ValueName::PISBEInputsValues::NEXT_STATION_ID"
                << " is not a valid number, hence ignoring." << Trace::EndLog();
        }
        PlayStationNextAnnouncement(next_station_id);

    }
}

bool PISUnit::CheckHandleOffAndPoweringOn(double new_time)
{
    const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);

    const int cab_active = GetObjectPropertyNumber<int>(
        m_papis_vehicle_outputs_comms, Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER);

    if (cab_active == Project::TypeValue::ActiveInactive::INACTIVE)
    {
        if (m_state.getState() != PISState::State::inactive)
        {
            m_state.setInactive();

            SetObjectPropertyNumber(
                m_pis_outputs_comms,
                Project::ValueName::PISBEOutputs::POWER_STATE,
                Project::TypeValue::PISPowerState::POWER_OFF);

            Trace::GetLogger().STAMP(Trace::INFO) << "Comms PIS Power off." << Trace::EndLog();
        }

        return true;
    }
    else if (cab_active == Project::TypeValue::ActiveInactive::ACTIVE)
    {
        if (m_state.getState() == PISState::State::inactive || m_state.getState() == PISState::State::unknown)
        {
            // start powering on
            m_state.setPoweringOn(new_time);
            
            SetObjectPropertyNumber(
                m_pis_outputs_comms,
                Project::ValueName::PISBEOutputs::POWER_STATE,
                Project::TypeValue::PISPowerState::BOOTING);

            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Comms PIS Powering on." << Trace::EndLog();

            return true;
        }
        else if (m_state.getState() == PISState::State::powering_on)
        {
            if ((new_time - m_state.getPoweringOnStartTime()) >= m_powering_on_time_seconds)
            {
                SetObjectPropertyNumber(
                    m_pis_outputs_comms,
                    Project::ValueName::PISBEOutputs::POWER_STATE,
                    Project::TypeValue::PISPowerState::POWER_ON);

                Trace::GetLogger().STAMP(Trace::INFO) << "Comms PIS Power on." << Trace::EndLog();
            }
            else
            {
                // wait for m_powering_on_time_seconds sec.
                return true;
            }
        }
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::WARN) << "Comms PIS state invalid. Unknown power state: "
            << cab_active << Trace::EndLog();

        return true;
    }

    return false;
}

void PISUnit::CreateAudioPlayThread()
{
    std::lock_guard guard(m_lock);
    if (!m_audio_play_thread.joinable())
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Create Audio Play thread." << Trace::EndLog();

        m_stop_audio_play_thread = false;
        m_audio_play_thread = std::thread(&PISUnit::AudioPlayThread, this);
    }
}

void PISUnit::DestroyAudioPlayThread()
{
    std::unique_lock lock(m_lock);
    if (m_audio_play_thread.joinable())
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Destroy Audio Play thread." << Trace::EndLog();

        m_stop_audio_play_thread = true;
        m_wake_thread_cv.notify_all();
        lock.unlock();
        m_audio_play_thread.join();
        lock.lock();
        m_audio_play_thread = std::thread();
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Audio Play thread has been destroyed." << Trace::EndLog();
    }
}

void PISUnit::AudioPlayThread()
{
    Trace::GetLogger().STAMP(Trace::INFO) << "Audio Play thread has been created." << Trace::EndLog();    
    
    std::unique_lock lock(m_lock);
    while (!m_stop_audio_play_thread)
    {
        if (m_state.m_dva_start == false)
        {
            if (m_state.m_intercom_status == false 
                && m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::INACTIVE)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Radio/PIS intercom state Disabled" << Trace::EndLog();
                auto message_to_play = m_messages_queue.DequeueBroadcastMessage();
                if (message_to_play)
                {
                    if (!m_audio_engine.PlayMessageId(message_to_play->id, message_to_play.value()))
                        continue;
                }
            }
            else if ((m_state.m_intercom_output == static_cast<int>(CallState::CALL_REQUEST)
                || m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::CALL_REQUEST)
                && m_state.m_buzzer_active == true)
            {
                m_state.m_buzzer_active = false;
                m_audio_engine.PlayBuzzerInLoop();
            }
        }
        Trace::GetLogger().STAMP(Trace::INFO) << "Audio Play thread Waiting....  m_state.m_dva_start: "<< m_state.m_dva_start << Trace::EndLog();
        m_wake_thread_cv.wait(lock);//, []() {return true;});
    }

    Trace::GetLogger().STAMP(Trace::INFO) << "Exit Audio Play thread." << Trace::EndLog();
}

// This function is responsible for preparing the route list (station ids in a sequence)
//std::variant<Train::Data::Timetable::Route, std::vector<int>>
void PISUnit::DetectRouteAndPosition(int selected_route_id)
{
    const auto routes = Train::Database::Timetable(m_data_access).GetRoutes(
        Core::Database::Network(m_data_access).GetNetworkIDForScenario(m_scenario_id));

    const auto selected_route_it =
        std::find_if(routes.begin(), routes.end(), [selected_route_id](const Train::Data::Timetable::Route& route)
        {
            return route.id == selected_route_id;
        });


    // To display first and last station on UI (TCMS/PIS). Here we are setting first and last station id to comms property 
    auto First_And_Last_Station = [&]()
    {
        auto terminal_station_id = m_state.getLastStation();
        auto station_xml_id = m_announcements->ConvertStationDbIdToXmlId(terminal_station_id);
        CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_TERMINAL_STATION_ID, station_xml_id);

        auto start_station_id = m_state.getFirstStation();
        station_xml_id = m_announcements->ConvertStationDbIdToXmlId(start_station_id);
        CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_START_STATION_ID, station_xml_id);
    };

    const auto &path = m_path_watcher.GetPath();
    const auto& features = m_world_access.GetPathFeatures(path, m_track_association);

    std::multimap<double, Comms::Object> features_line;

    for (const auto& feature : features)
        features_line.insert(std::pair(feature.first, feature.second));

    if (features_line.empty())
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "There is no station on train line." << Trace::EndLog();
        return;

        //if (selected_route_it != routes.end())
        //{
        //    int x = selected_route_it->id;
        //    return *selected_route_it;
        //}

        //Train::Data::Timetable::Route route;
        //route.id = -1;

        //return route;
    }

    const auto feature_in_front_it = features_line.upper_bound(0.0);

    int in_front_station_id = -1;

    if (feature_in_front_it != features_line.end())
    {
        int in_front_feature_id = GetObjectPropertyNumber<int>(feature_in_front_it->second, Core::ValueName::Feature::FEATURE_ID);
        in_front_station_id = m_feature_id_to_station_id[in_front_feature_id];

        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Station id / feature id in front of the train : "
            << in_front_station_id << " / " << in_front_feature_id << " distance : "
            << feature_in_front_it->first << Trace::EndLog();
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "There is no stations in front of the train." << Trace::EndLog();
    }

    int at_or_behind_feature_id = -1;
    int at_or_behind_station_id = -1;

    if (feature_in_front_it != features_line.begin())
    {
        auto feature_at_or_behind_it = feature_in_front_it;
        --feature_at_or_behind_it;

        at_or_behind_feature_id = GetObjectPropertyNumber<int>(feature_at_or_behind_it->second, Core::ValueName::Feature::FEATURE_ID);
        at_or_behind_station_id = m_feature_id_to_station_id[at_or_behind_feature_id];

        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Station id / feature id at/behind of the train : "
            << at_or_behind_station_id << " / " << at_or_behind_feature_id << " distance : "
            << feature_at_or_behind_it->first << Trace::EndLog();
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "There is no station behind the train." << Trace::EndLog();
    }

    std::vector<int> calculated_route;
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "calculated_route, station Id: " << Trace::EndLog();
    for (const auto& feature : features_line)
    {
        const auto feature_id = GetObjectPropertyNumber<int>(feature.second, Core::ValueName::Feature::FEATURE_ID);
        const auto station_id = m_feature_id_to_station_id[feature_id];

        Trace::GetLogger().STAMP(Trace::VERBOSE) << station_id << ", ";

        calculated_route.push_back(station_id);
    }
    
    // MMRBEM-3284 : For PSD , to set calculated route id.
    auto calculate_and_set_route_id = [&]()
    {
        //For this lambda, using 2 inputs from outside scope DetectRouteAndPosition()
        //in_front_station_id
        //at_or_behind_station_id
        auto ahead_station_id = in_front_station_id;
        auto behind_station_id = at_or_behind_station_id;
        
        //Prepare map route_id to vector of station ids
        // routes - From DB
        std::map<int, std::vector<int>> map_routeid_stations;
        for (auto route : routes)
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "ROUTE ID : "<< route.id << Trace::EndLog();
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "      Station IDs : "<< Trace::EndLog();
            std::vector<int> stations;
            stations.reserve(route.stations.size());
            for (unsigned int i = 0; i < route.stations.size(); i++)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << route.stations[i].id << Trace::EndLog();
                stations.push_back(route.stations[i].id);
            }
            map_routeid_stations[route.id] = stations;            
        }

        //Local lambda to check if station is start of route
        auto is_station_start_of_route = [&](const int station_id)
        {
            for (const auto &map_elem : map_routeid_stations)
            {
                if (map_elem.second.size() > 0)
                {
                    if (map_elem.second[0] == station_id)
                        return true;
                }
            }
            return false;
        };

        //Local lambda to check if station is end of route
        auto is_station_end_of_route = [&](const int station_id)
        {
            for (const auto &map_elem : map_routeid_stations)
            {
                if (map_elem.second.size() > 0)
                {
                    if (map_elem.second[map_elem.second.size()-1] == station_id)
                        return true;
                }
            }
            return false;
        };        

        //Case 1: No behind station - Train is positioned at start station in the route == = > Take 2 stations ahead
        //Case 2: No ahead station - Train is positioned at end station in the route == = > Take 2 stations behind
        //Case 3: Behind & ahead station - Train is positioned between start(after start) & end station(before end)
        std::vector<int> sequence_stations_vect;
        if (ahead_station_id != -1 && behind_station_id != -1) //Case 3 
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Case 3: Behind & ahead station - Train is positioned between start(after start) & end station(before end) " << Trace::EndLog();
            //If train is positioned before start station of route & behind station calculated is from different route,
            //then we don't get sequence of stations in any route. In this case, consider next station of ahead_station_id to
            //calculate exact route.
            //Postion train before 'Dahisar East' station which is start of L2A UP line. But previous station is 'Ovaripada' which is not in the route L2A UP
            // So get next station of 'Dahisar East' which is 'Anand Nagar' & use these 2 station sequence to calculate route id.
            if (is_station_start_of_route(ahead_station_id))
            {
                auto feature_in_front_it = features_line.upper_bound(0.0);
                feature_in_front_it++;
                if (feature_in_front_it != features_line.end())
                {
                    int ahead_feature_id = GetObjectPropertyNumber<int>(feature_in_front_it->second, Core::ValueName::Feature::FEATURE_ID);
                    auto ahead_station_id2 = m_feature_id_to_station_id[ahead_feature_id];

                    sequence_stations_vect.push_back(ahead_station_id);
                    sequence_stations_vect.push_back(ahead_station_id2);
                }
            }
            else
            {
                sequence_stations_vect.push_back(behind_station_id);
                sequence_stations_vect.push_back(ahead_station_id);
            }
                       
        }
        else if (ahead_station_id == -1 && behind_station_id != -1) //Case 2
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Case 2: No ahead station - Train is positioned at end station in the route == = > Take 2 stations behind" << Trace::EndLog();
            int behind_station1_id = -1;
            int behind_station2_id = -1;
            auto feature_behind_it = features_line.end();
            feature_behind_it--;
            if (feature_behind_it != features_line.end())
            {
                int behind_feature_id = GetObjectPropertyNumber<int>(feature_behind_it->second, Core::ValueName::Feature::FEATURE_ID);
                behind_station1_id = m_feature_id_to_station_id[behind_feature_id];
                if (feature_behind_it != features_line.begin())
                {
                    feature_behind_it--;
                    int behind_feature_id = GetObjectPropertyNumber<int>(feature_behind_it->second, Core::ValueName::Feature::FEATURE_ID);
                    behind_station2_id = m_feature_id_to_station_id[behind_feature_id];
                }
                else Trace::GetLogger().STAMP(Trace::ERR) << "Only one station in the route. Please check. !!" << Trace::EndLog(); 

            }
            sequence_stations_vect.push_back(behind_station2_id);
            sequence_stations_vect.push_back(behind_station1_id);

        }
        else if (behind_station_id == -1 && ahead_station_id != -1) // Case 1
        {
            Trace::GetLogger().STAMP(Trace::INFO) << "Case 1: No behind station - Train is positioned at start station in the route == = > Take 2 stations ahead" << Trace::EndLog();
            int ahead_station1_id = -1;
            int ahead_station2_id = -1;
            auto feature_ahead_it = features_line.begin();            
            if (feature_ahead_it != features_line.end())
            {
                int behind_feature_id = GetObjectPropertyNumber<int>(feature_ahead_it->second, Core::ValueName::Feature::FEATURE_ID);
                 ahead_station1_id = m_feature_id_to_station_id[behind_feature_id];
                
               feature_ahead_it++;
               if (feature_ahead_it != features_line.end())
                {                    
                    int ahead_feature_id = GetObjectPropertyNumber<int>(feature_ahead_it->second, Core::ValueName::Feature::FEATURE_ID);
                    ahead_station2_id = m_feature_id_to_station_id[ahead_feature_id];
                }
                else Trace::GetLogger().STAMP(Trace::ERR) << "Only one station in the route. Please check. !!" << Trace::EndLog();

            }
            sequence_stations_vect.push_back(ahead_station1_id);
            sequence_stations_vect.push_back(ahead_station2_id);
        }
        
        if (sequence_stations_vect.size() == 2)
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "sequence_stations_vect[0] : "<< sequence_stations_vect[0] << Trace::EndLog();
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "sequence_stations_vect[1] : " << sequence_stations_vect[1] << Trace::EndLog();
        }
        
        auto calculated_route_id = -1;
        for (auto map_elem : map_routeid_stations)
        {
           auto iter = std::search(map_elem.second.begin(), map_elem.second.end(), sequence_stations_vect.begin(), sequence_stations_vect.end());
           if (iter != map_elem.second.end())
           {
               calculated_route_id = map_elem.first;
               break;
           }
        }
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_ROUTE_ID, calculated_route_id);
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_ROUTE_ID_PSD, calculated_route_id);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "calculate_and_set_route_id  END  calculated_route_id : "<< calculated_route_id << Trace::EndLog();
    };

    // compare against currently selected route
    // if match, use selected, if not, use calculated (e.g. selected route might skip some stations/etc)

    if (selected_route_it != routes.end())
    {
        assert(selected_route_it->stations.size() >= 2);

        int start_station_id_in_selected_route = selected_route_it->stations[0].id;        

        const auto route_start_station_it =
            std::find_if(calculated_route.begin(), calculated_route.end(), [start_station_id_in_selected_route](const int station_id)
            {
                return start_station_id_in_selected_route == station_id;
            });

        int second_station_id_in_selected_route = selected_route_it->stations[1].id;        

        const auto route_second_station_it =
            std::find_if(calculated_route.begin(), calculated_route.end(), [second_station_id_in_selected_route](const int station_id)
            {
                return second_station_id_in_selected_route == station_id;
            });

        // if 2 first stations in selected route are in calculated route use selected route.
        if (route_start_station_it != calculated_route.end() && route_second_station_it != calculated_route.end() &&
            route_start_station_it < route_second_station_it)
        {
            bool behind_station_in_selected_route = false;
            std::vector<int> selected_route;
            for (const auto& station : selected_route_it->stations)
            {
                if (at_or_behind_station_id == station.id)
                    behind_station_in_selected_route = true;

                selected_route.push_back(station.id);
            }

            Trace::GetLogger().STAMP(Trace::INFO) << "Use selected route. Route ID: " << selected_route_id<< Trace::EndLog();

            if (behind_station_in_selected_route)
                m_state.setRouteStations(selected_route, at_or_behind_feature_id);
            else
                m_state.setRouteStations(selected_route, -1);

            m_state.setStationAhead(in_front_station_id);

            //Commenting First_And_Last_Station() & return statement.
            //First_And_Last_Station();

            //return *selected_route_it;
            //return;
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::WARN) << "Selected route is not within calculated route or train direction is WRONG. Using calculated route." << Trace::EndLog();
            m_state.setRouteStations(calculated_route, at_or_behind_feature_id);
            m_state.setStationAhead(in_front_station_id);
        }
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::WARN) << "No selected route found. Use calculated route." << Trace::EndLog();
        m_state.setRouteStations(calculated_route, at_or_behind_feature_id);
        m_state.setStationAhead(in_front_station_id);
        calculate_and_set_route_id();
    }

    First_And_Last_Station();

    //Set Next station
    {
        std::unique_lock<Comms::Gateway> comms_lock(m_gateway);
        auto station_xml_id = m_announcements->ConvertStationDbIdToXmlId(m_state.getStationAhead());
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_NEXT_STATION_ID, station_xml_id);

        station_xml_id = m_announcements->ConvertStationDbIdToXmlId(at_or_behind_station_id);
        SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_CURRENT_STATION_ID, station_xml_id);
    }

    //return calculated_route;
    return;
}

void PISUnit::HandleAutoAnouncements()
{
    const auto &path = m_path_watcher.GetPath();

    auto door_side = GetDoorSide();

    const auto& features_in_front = m_world_access.GetPathFeatures(path, m_track_association, 0.0, AUTO_BROADCAST_WATCH_DISTANCE);

    if (!features_in_front.empty())
    {
        for (const auto feature : features_in_front)
        {
            const auto feature_id = GetObjectPropertyNumber<int>(feature.second, Core::ValueName::Feature::FEATURE_ID);
            const auto station_id = m_feature_id_to_station_id[feature_id];

            if (!m_state.getArriveStationAnnounced() && m_state.isStationInRoute(station_id))
            {
                PlayStationArrivedAnnouncement(station_id, door_side);
                auto station_xml_id = m_announcements->ConvertStationDbIdToXmlId(station_id);
                SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_CURRENT_STATION_ID, station_xml_id);
                m_state.m_current_station_id = station_id;

                m_state.setArriveStationAnnounced(true);
                m_state.setWatchBehindFeatureId(-1);
                m_state.setStationAhead(station_id);
                break;
            }
        }
    }
    else // nothing in front check behind
    {
        m_state.setArriveStationAnnounced(false);

        const auto& features_behind = m_world_access.GetPathFeatures(path, m_track_association, -AUTO_BROADCAST_WATCH_DISTANCE, 0.0);

        if (m_state.getWatchBehindFeatureId() != -1)
        {
            bool watched_feature_still_in_range = false;

            for (const auto feature : features_behind)
            {
                const auto feature_id = GetObjectPropertyNumber<int>(feature.second, Core::ValueName::Feature::FEATURE_ID);
                if (m_state.getWatchBehindFeatureId() == feature_id)
                {
                    watched_feature_still_in_range = true;
                    break;
                }
            }

            if (!watched_feature_still_in_range)
            {
                auto behind_station_id = m_feature_id_to_station_id[m_state.getWatchBehindFeatureId()];
                auto next_station_id = m_state.getNextStationIdAfter(m_feature_id_to_station_id[m_state.getWatchBehindFeatureId()]);
                if (m_state.isFirstStationInRoute(behind_station_id))
                {
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "FirstStationInRoute : " << behind_station_id << Trace::EndLog();
                    PlayRouteStartDepartAnnouncement(next_station_id);
                }
                else
                {
                    PlayStationNextAnnouncement(next_station_id);
                }
                auto station_xml_id = m_announcements->ConvertStationDbIdToXmlId(next_station_id);
                SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::SELECTED_NEXT_STATION_ID, station_xml_id);
                m_state.setWatchBehindFeatureId(-1);

            }
        }
        else
        {
            for (const auto feature : features_behind)
            {
                const auto feature_id = GetObjectPropertyNumber<int>(feature.second, Core::ValueName::Feature::FEATURE_ID);
                const auto station_id = m_feature_id_to_station_id[feature_id];

                if (m_state.isStationInRoute(station_id))
                {
                    m_state.setWatchBehindFeatureId(feature_id);
                    m_state.setStationAhead(m_state.getNextStationIdAfter(station_id));
                    break;
                }
            }
        }
    }
}

void PISUnit::HandleSemiAutoAnouncements() //int door_state, double train_speed)
{
    if (m_state.m_route_id != -1 &&
        m_state.m_start_station_xml_id != -1 &&
        m_state.m_terminal_station_xml_id != -1)
    {
        HandleAutoAnouncements();
    }
}

void PISUnit::PlayStationArrivedAnnouncement(int station_id, int door_side)
{
    dva::StationData station_data;
    if (m_announcements->GetStationData(station_id, station_data))
    {
        if (m_state.m_current_skip_station_id != station_data.station_id)
        {
            PlayStationAnnouncement(station_id, "arrived", door_side);
        }
        else
        {
            m_state.m_current_skip_station_id = -1;
            --m_state.m_current_skip_count;
        }
    }
}

void PISUnit::PlayStationNextAnnouncement(int station_id)
{
    PlayStationAnnouncement(station_id, "next");
}

void PISUnit::PlayDoorCloseAnnouncemnt(const Sim::Number &num_obj)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "PISUnit::PlayDoorCloseAnnouncemnt() . num_obj.value :"<< num_obj.value << Trace::EndLog();
    if (num_obj.value > 0)
    {
        BroadcastMessage msg(DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY);
        m_announcements->PlayDoorCloseAnnouncemnt(m_state.m_current_station_id, msg);

        auto last_dequed_msg = m_messages_queue.GetLastDequeueBroadcastMessage();        
        if (last_dequed_msg->title != msg.title)
        {
            std::lock_guard lock(m_lock);
            m_messages_queue.EnqueueBroadcastMessage(DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY, msg);
            m_wake_thread_cv.notify_one();
        }
        else
            Trace::GetLogger().STAMP(Trace::VERBOSE) << " Door close announcement is already enqued for playing !!" << Trace::EndLog();
    }
        
}

void PISUnit::PlayDoorChime(int station_id, bool door_open_flg)
{
    BroadcastMessage msg(DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY);
    m_announcements->PlayDoorChime(station_id, door_open_flg, msg);

    std::lock_guard lock(m_lock);
    m_messages_queue.EnqueueBroadcastMessage(DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY, msg);
    m_wake_thread_cv.notify_one();
}

// Departure Announcement (next station) with welcome message
void PISUnit::PlayRouteStartDepartAnnouncement(int station_id)
{
    BroadcastMessage msg(DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY);
    if (m_announcements->PlayRouteStartDepartAnnouncement(station_id, msg))
    {
        std::lock_guard lock(m_lock);
        m_messages_queue.EnqueueBroadcastMessage(DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY, msg);
        m_wake_thread_cv.notify_one();
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Invalid Welcome Annoucement after first station " << Trace::EndLog();
    }
}

void PISUnit::PlayStationAnnouncement(int station_id, const std::string& announcement_type, int door_side)
{
    BroadcastMessage msg(DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY);
    bool msg_enqued = false;
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "announcement_type: " << announcement_type << Trace::EndLog();
    msg_enqued = m_announcements->PlayStationAnnouncement(station_id, announcement_type, msg, door_side);

    if (msg_enqued)
    {
        std::lock_guard lock(m_lock);
        m_messages_queue.EnqueueBroadcastMessage(DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY, msg);
        m_wake_thread_cv.notify_one();
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "No " << announcement_type << " message for station id : " << station_id << Trace::EndLog();
    }
}

void PISUnit::HandleEmergencyAnnouncement()
{
    HandleEmergencyAnnouncement(EMERGENCEY_SPECIAL_PRIORITY, m_state.m_emergency_msg_state, 
                                 m_dva_audio_handler->m_dva_audio_data.emergency_message_map,
                                 AnnouncementType::EMERGENCY_ANNOUNCEMENT);
}

void PISUnit::HandleEmergencyAnnouncement(BroadcastMessagePriorities priority, EmergencySpecialMsgState & msg_state, 
                                            const std::map<int, dva::Message> & emrgncy_spcial_msg_map,
                                            AnnouncementType announcement_type)
{
    std::string pis_comms_msg_count_str;
    std::string pis_comms_msg_id_str;
    std::string pis_comms_msg_stop_str;
    std::string msg_title_str;

    switch (priority)
    {
        case EMERGENCEY_SPECIAL_PRIORITY:
            if (announcement_type == AnnouncementType::EMERGENCY_ANNOUNCEMENT)
            {
                pis_comms_msg_count_str = Project::ValueName::PISBEInputsValues::EMERGENCY_ANNONCMNT_COUNT;
                pis_comms_msg_id_str = Project::ValueName::PISBEInputsValues::EMERGENCY_ANNOUNCEMNT_ID;
                pis_comms_msg_stop_str = Project::ValueName::PISBEInputsValues::STOP_EMERGENCY_ANNOUNCEMNT;
                msg_title_str = "Emergency_msg_";
            }
            else if (announcement_type == AnnouncementType::SPECIAL_ANNOUNCEMENT)
            {
                pis_comms_msg_count_str = Project::ValueName::PISBEInputsValues::SPECIAL_ANNONCMNT_COUNT;
                pis_comms_msg_id_str = Project::ValueName::PISBEInputsValues::SPECIAL_ANNOUNCEMNT_ID;
                pis_comms_msg_stop_str = Project::ValueName::PISBEInputsValues::STOP_SPECIAL_ANNOUNCEMNT;
                msg_title_str = "Special_msg_";
            }

        break;
        case OCC_PRIORITY:
            pis_comms_msg_id_str = Project::ValueName::PISBEInputsValues::INSTRUCTOR_ANNOUNCEMENT_ID;
            msg_title_str = "OCC_msg_";
            break;
    }
    std::unique_lock<Comms::Gateway> comms_lock(m_gateway);

    if (priority == EMERGENCEY_SPECIAL_PRIORITY)
    {
        const int emergency_count = GetObjectPropertyNumber<int>(m_pis_inputs_comms, pis_comms_msg_count_str.c_str());
        msg_state.count = emergency_count;


        const int emergency_msg_stop = GetObjectPropertyNumber<int>(m_pis_inputs_comms, pis_comms_msg_stop_str.c_str());
        if (emergency_msg_stop > 0 && msg_state.stop_status == false)
        {
            SetObjectPropertyNumber(m_pis_inputs_comms, pis_comms_msg_stop_str.c_str(), 0);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Stop Emergency Message" << Trace::EndLog();
            //msg_state.stop_status = true;
            m_audio_engine.Stop();
        }
    }

    const int emergency_message_id = GetObjectPropertyNumber<int>(m_pis_inputs_comms, pis_comms_msg_id_str.c_str());
    if (emergency_message_id != -1)
    {
        // To handle multiple clicks/enqueing of special/emergency messages
        auto interrupted_message = m_messages_queue.GetLastDequeueBroadcastMessage();

        if (interrupted_message->id == emergency_message_id && interrupted_message->priority == static_cast<unsigned int>(announcement_type))
        {
            Trace::GetLogger().STAMP(Trace::WARN) << "Already Enqueued the Emergency/Special message id: " << emergency_message_id << Trace::EndLog();
            return;
        }

        SetObjectPropertyNumber(m_pis_inputs_comms, pis_comms_msg_id_str.c_str(), -1);
        comms_lock.unlock();

        auto it = emrgncy_spcial_msg_map.find(emergency_message_id);
        if (it != emrgncy_spcial_msg_map.end())
        {
            auto audio_id_mr = it->second.audio_file_id_mr;
            auto audio_id_en = it->second.audio_file_id_en;
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Found the audio ids, mr: " << audio_id_mr << ", en: " << audio_id_en << Trace::EndLog();
            BroadcastMessage msg(priority);
            msg.id = emergency_message_id;
            msg.title = msg_title_str + std::to_string(emergency_message_id) + "_" + std::to_string(msg_state.count);
            for (int i = 0; i < msg_state.count; i++)
            {
                msg.audio_ids.push_back(audio_id_mr);
                msg.audio_ids.push_back(audio_id_en);
            }

            //auto interrupted_message = m_messages_queue.GetLastDequeueBroadcastMessage();
            bool play_interrupted_msg_later = false;
            {
                std::lock_guard lock(m_dva_lock);
                msg_state.stop_status = false; //Set to false whenever any special/emergency msg is received. 
                                               // It is used when emergency/special msg need to be stopped based on stop command from UI
            }
            if (interrupted_message && m_state.m_dva_start == true && interrupted_message->priority < msg.priority)
            {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Interrupting low priority running audio: " << interrupted_message->title << Trace::EndLog();
                m_audio_engine.Stop();
                play_interrupted_msg_later = true;
            }

            {
                std::lock_guard lock(m_lock);
                m_messages_queue.EnqueueBroadcastMessage(priority, msg);
            }
            if (interrupted_message && m_state.m_dva_start == true && interrupted_message->priority < msg.priority)
            {
                std::lock_guard lock(m_dva_lock);
                m_state.m_dva_start = false;
            }
            m_wake_thread_cv.notify_one();

            if (play_interrupted_msg_later)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                {
                    std::lock_guard lock(m_dva_lock);
                    m_state.m_dva_start = true;
                }
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "Enqueing Interrupted Audio again: " << interrupted_message->title << Trace::EndLog();
                std::lock_guard lock(m_lock);
                m_messages_queue.EnqueueBroadcastMessage(interrupted_message->priority, *interrupted_message);
                //m_wake_thread_cv.notify_one();
            }
        }
    }
}

void PISUnit::StopEmgSpc(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (num_obj.value > 0.5)
    {
        m_audio_engine.Stop();
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " StopEmgSpc() callback : Stop Emergency/Special Message " << num_obj.value << Trace::EndLog();
    }
}

void PISUnit::HandleSpecialAnnouncement()
{
    HandleEmergencyAnnouncement(EMERGENCEY_SPECIAL_PRIORITY, m_state.m_special_msg_state,
                                  m_dva_audio_handler->m_dva_audio_data.special_message_map,
                                  AnnouncementType::SPECIAL_ANNOUNCEMENT);
}

void PISUnit::SkipStationFeature(const Sim::Number &num_obj)
{
    std::vector<std::pair<double, Comms::Object>> vect_platform_stopping_unit;
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "SkipStationFeature() callback" << Trace::EndLog();

    if (!m_path_watcher.HasPath())
        return;

    vect_platform_stopping_unit = m_world_access.GetPathFeatures(m_path_watcher.GetPath(), m_platform_stopping_point, true, false, 0, std::numeric_limits<double>::max());

    if (vect_platform_stopping_unit.size() == 0)
        return;
    if (m_announcement_mode == 3)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Skip Station announcement does not work in Manual Announcement Mode" << Trace::EndLog();
        return;
    }

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Vector size = " << vect_platform_stopping_unit.size() << Trace::EndLog();
    m_state.m_current_skip_count = 0;
    m_state.m_skip_station_list.clear();
    m_state.m_skip_station_map.clear();

    for (auto stop_pt : vect_platform_stopping_unit)
    {
        auto stop_point_state = stop_pt.second.Numbers().Get(Core::ValueName::Feature::STATE).value;   // Below is another way to get Feature::STATE
        //auto stop_point_state = stop_pt.second.Numbers().Store().Get(stop_pt.second.Numbers().Info().GetID(Core::ValueName::Feature::STATE)).value;

        auto feature_name = stop_pt.second.GetName(); //getting data from feature name, whether train is 6 car or 8 car
        auto char_6_or_8_car = feature_name[feature_name.length() - 4];
        std::string six_or_eight_car; 
        
        six_or_eight_car = six_or_eight_car + char_6_or_8_car;
        auto veh_size = std::to_string(m_vehicle_comms_list.size());

        if (stop_point_state == STOPPING_POINT_FEATURE_STATE_SKIP && six_or_eight_car == veh_size)
        {
            auto string_station_code = Comms::Project::RawToString(stop_pt.second.Raws().Get("Station Code"));

            auto itr_station_code = m_station_code_xml_id_map.find(string_station_code);
            
            int xml_skip_station_id = 1; //Default value initialisation
            if(itr_station_code != m_station_code_xml_id_map.end())
                xml_skip_station_id = itr_station_code->second;

            //Below 4 line code is just for the purpose of printing skipped station name
            auto db_skip_station_id = m_announcements->ConvertXmlIdToDbId(xml_skip_station_id);
            auto itr_station_name = m_dbId_stationId_map.find(db_skip_station_id);
            auto station_name = itr_station_name->second.name;
            Trace::GetLogger().STAMP(Trace::VERBOSE) <<"Station name : "<< station_name << ", Feature name : " << feature_name << ", stopping_point_state = " << stop_point_state << Trace::EndLog();

            Trace::GetLogger().STAMP(Trace::INFO) << "Feature's STATE, Skip Id List, xml_stationId: " << xml_skip_station_id << Trace::EndLog();
            m_state.m_skip_station_list.insert(std::make_pair(xml_skip_station_id, m_state.m_current_skip_count));
            m_state.m_skip_station_map.insert(std::make_pair(m_state.m_current_skip_count, xml_skip_station_id));
            m_state.m_current_skip_count++;
        }
    }
}

void PISUnit::HandleOCCAnnouncement()
{
    HandleEmergencyAnnouncement(OCC_PRIORITY, m_state.m_occ_msg_state,
        m_dva_audio_handler->m_dva_audio_data.occ_message_map,
        AnnouncementType::OCC_ANNOUNCEMENT);
}

void PISUnit::HandleFistAnnouncement()
{
    if (m_fist_mic_enable)
    {
        m_audio_engine.Stop();
    }
}

void PISUnit::PlayManualAnnouncement(const ManualAnnoucementMsg & manual_announcmnt, int door_side)
{

    if (manual_announcmnt.msg_type == ArriveDepartureType::ARRIVAL)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Arriving station in Manual Mode: " << manual_announcmnt.start_station_id << Trace::EndLog();
        PlayStationArrivedAnnouncement(manual_announcmnt.start_station_id, door_side);
        m_state.setStationAhead(manual_announcmnt.start_station_id);
    }
    else // ArriveDepartureType::DEPARTURE
    {
        if (m_state.isFirstStationInRoute(manual_announcmnt.start_station_id))
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "First StationInRoute crossed in Manual Mode, next station: " << manual_announcmnt.next_station_id << Trace::EndLog();
            PlayRouteStartDepartAnnouncement(manual_announcmnt.next_station_id);
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "Next station in Manual Mode: " << manual_announcmnt.next_station_id << Trace::EndLog();
            PlayStationNextAnnouncement(manual_announcmnt.next_station_id);
        }
        m_state.setStationAhead(manual_announcmnt.next_station_id);
    }
    m_state.m_manual_anncmnt_msg.start_station_id = -1;
    m_state.m_manual_anncmnt_msg.next_station_id = -1;
}

void PISUnit::HandleManualAnnouncement()
{
    if (m_state.m_route_id != -1 && 
        m_state.m_manual_anncmnt_msg.start_station_id != -1 &&
        m_state.m_manual_anncmnt_msg.next_station_id != -1)
    {
        if (m_state.isStationInRoute(m_state.m_manual_anncmnt_msg.start_station_id)
            && m_state.isStationInRoute(m_state.m_manual_anncmnt_msg.next_station_id))
        {
            int door_side = -1;
            if (m_state.m_manual_anncmnt_msg.door_type == DoorType::DOOR_LEFT)
                door_side = PlatformSide::LEFT_SIDE;
            else if (m_state.m_manual_anncmnt_msg.door_type == DoorType::DOOR_RIGHT)
                door_side = PlatformSide::RIGHT_SIDE;
            
            PlayManualAnnouncement(m_state.m_manual_anncmnt_msg, door_side);
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "Invalid Manual annoouncement. Either Current Station or Next Station not found in the Route station list " << Trace::EndLog();
        }
        m_state.m_manual_anncmnt_msg.start_station_id = -1;
        m_state.m_manual_anncmnt_msg.next_station_id = -1;
    }
    //else
    //{
    //    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Either Start Station or Next Station not set " << Trace::EndLog();
    //}
}

int PISUnit::GetDoorSide()
{
    std::vector<std::pair<double, Comms::Object>> platform_stopping_unit;

    platform_stopping_unit = m_world_access.GetPathFeatures(m_path_watcher.GetPath(), m_platform_stopping_point,
        true, false, 0, AUTO_BROADCAST_WATCH_DISTANCE_NEXT_DOOR);

    int door_side = -1;
    if (platform_stopping_unit.size() > 0)
    {
        DoorType::DOOR_LEFT;

        door_side = static_cast<int>(platform_stopping_unit.begin()->second.Numbers().Get(CSDE_CODE_PROPERTY).value);
        if (door_side == PlatformSide::LEFT_SIDE)        
            CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::DOOR_OPENING_SIDE, PlatformSide::LEFT_SIDE);                    
        else if (door_side == PlatformSide::RIGHT_SIDE)        
            CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::DOOR_OPENING_SIDE, PlatformSide::RIGHT_SIDE);                
        else        
            CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::DOOR_OPENING_SIDE, PlatformSide::NONE);                
    }
    else 
    {
        CTSProjectUtility::SetObjectPropertyNumber(m_pis_outputs_comms, Project::ValueName::PISBEOutputs::DOOR_OPENING_SIDE, PlatformSide::NONE);
    }
    return door_side;
}

int PISUnit::GetPlatformSide()
{
    std::vector<std::pair<double, Comms::Object>> platform_stopping_unit;

    platform_stopping_unit = m_world_access.GetPathFeatures(m_path_watcher.GetPath(), m_platform_stopping_point,
        true, false, 0, BROADCAST_WATCH_DISTANCE_NEXT_PLATFORM);

    int platform_side = -1;
    if (platform_stopping_unit.size() > 0)
    {       
        platform_side = static_cast<int>(platform_stopping_unit.begin()->second.Numbers().Get(CSDE_CODE_PROPERTY).value);       
    }
   
    return platform_side;
}

void PISUnit::FaultPea2Failure(const Sim::Number &num_obj)
{
    if (static_cast<int>(num_obj.value) == 1) 
    {
        Trace::GetLogger().STAMP(Trace::INFO) << " FAULT : PEA 2 Failure " << Trace::EndLog();
        std::lock_guard lock(m_lock);
        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::CAB_CANCEL_BUTTON, 1);
        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::CAB_CANCEL_BUTTON, 0);
    }
}

void PISUnit::FaultMcbPaGroup(const Sim::Number &num_obj) 
{
    if (static_cast<int>(num_obj.value) == 1)
    {
        Trace::GetLogger().STAMP(Trace::INFO) << " FAULT : MCB PA Group " << Trace::EndLog();
        
        std::lock_guard lock(m_lock);
        m_audio_engine.Stop();

        m_messages_queue.ClearQueue();

        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::CAB_IN_PA_BUTTON, 0);
    }
}

bool PISUnit::IsTrainNearStationArea()
{
    int is_train_near_station = false;

    std::vector<std::pair<double, Comms::Object>> platform_stopping_unit;

    platform_stopping_unit = m_world_access.GetPathFeatures(m_path_watcher.GetPath(), m_platform_stopping_point,
        true, false, -AUTO_BROADCAST_WATCH_DISTANCE_NEXT, BROADCAST_WATCH_DISTANCE_CCTV_NEXT_PLATFORM);

    int door_side = -1;

    if (platform_stopping_unit.size() > 0)
    {
        //Trace::GetLogger().STAMP(Trace::INFO) << "platform_stopping_unit size" << platform_stopping_unit.size() << "  Distance = " << platform_stopping_unit.begin()->first << Trace::EndLog();
        door_side = static_cast<int>(platform_stopping_unit.begin()->second.Numbers().Get(CSDE_CODE_PROPERTY).value);
        if (door_side == PlatformSide::LEFT_SIDE || door_side == PlatformSide::RIGHT_SIDE)
            is_train_near_station = true;
        else
            return is_train_near_station;
    }
    return is_train_near_station;
}