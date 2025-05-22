/// @file      RadioUnit.h
///            Implements Radio Backend Unit.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "RadioUnit.h"
#include "core_properties/CommonProperties.h"
#include "train_data_access/TrainDataAccessTypes.h"
#include "utility/Utilities.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "project_comms_structure/ProjectObjectDefinition.h"
#include "train_data_access/TrainDataAccess.h"
#include "CommsPropertyAccessors.h"

using namespace CTSProjectUtility;

namespace {

    const char * const STATION_LIST_FILE = "Station List File";
    const std::string POWER_ON_TIME = "Powerup Time";

    const double AUTO_BROADCAST_WATCH_DISTANCE = 150.0;
    const double AUTO_BROADCAST_WATCH_DISTANCE_NEXT = 250.0;
    const double AUTO_BROADCAST_WATCH_DISTANCE_NEXT_DOOR = 500.0;
    const std::string CSDE_CODE_PROPERTY = "CSDE Code";

    enum PlatformSide
    {
        LEFT_SIDE = 1,
        RIGHT_SIDE = 2,
        NONE = -1,
    };

    using AudioTypeToId = std::map<std::string, int>;
    const double REQUEST_FREQUENCY = 20.0;
}

RadioUnit::RadioUnit(
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
    m_properties(properties)
{
    try
    {
        Core::Database::Feature feature = Core::Database::Feature(data_access);

        auto hub_data = Core::GetHubData(scenario_data, Core::Properties::GetHubID(properties, data_access));

        m_scenario_id = scenario_data.scenario_id;
        m_scenario_train_id = hub_data.scenario_train_id;
        m_cab_vehicle_idx = hub_data.vehicle_index;

        auto trains = Train::Database::Train(data_access).GetScenarioTrains(scenario_data.scenario_id);
        auto train_it = std::find_if(trains.cbegin(), trains.cend(),
            [&](const Train::Data::ScenarioTrain& train)
            { return train.scenario_train_id == m_scenario_train_id; });

        const auto stations =
            Train::Database::Timetable(data_access).GetStations(
                Core::Database::Network(data_access).GetNetworkIDForScenario(m_scenario_id));

        const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);
        Comms::AddCreationCallback(m_gateway.GetRootObject(), MakeCallback(&RadioUnit::ObjectCreated, this));

        Start();
    }
    catch (CommonException &e)
    {
        Trace::GetLogger().STAMP(Trace::WARN) << e.what() << ".\n RadioUnit is not operational." << Trace::EndLog();
    }
}

void RadioUnit::RadioCabCancel(const Sim::Number &num_obj)
{
    if (num_obj.value < 0.5 || !m_power_on) { return; }
    if (m_state.m_radio_call_type == RADIO_CALL_INACTIVE || m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::INACTIVE)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "There is no Radio Call Request going on. No need to end the call" << Trace::EndLog();
        return;
    }

    std::lock_guard lock(m_lock);

    m_state.m_radio_call_type = RADIO_CALL_INACTIVE;
    m_state.m_radio_intercom_state = Project::TypeValue::RadioIntercomState::INACTIVE;
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE, Project::TypeValue::RadioIntercomState::INACTIVE);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_CALL_TYPE, RADIO_CALL_INACTIVE);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_DIALLED_NO, 0.0);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_GROUP_CALL, 0.0);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::CAB_SCC, Project::TypeValue::RadioScc::INACTIVE);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "RadioCabCancel" << Trace::EndLog();

}

void RadioUnit::RadioSccCancel(const Sim::Number &num_obj)
{
    if (num_obj.value < 0.5 || !m_power_on) { return; }
    if (m_state.m_radio_call_type == RADIO_CALL_INACTIVE || m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::INACTIVE)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "There is no Radio Call Request going on. No need to end the call" << Trace::EndLog();
        return;
    }

    std::lock_guard lock(m_lock);

    m_state.m_radio_call_type = RADIO_CALL_INACTIVE;
    m_state.m_radio_intercom_state = Project::TypeValue::RadioIntercomState::INACTIVE;
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE, Project::TypeValue::RadioIntercomState::INACTIVE);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_CALL_TYPE, RADIO_CALL_INACTIVE);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_DIALLED_NO, 0.0);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_GROUP_CALL, 0.0);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::CAB_SCC, Project::TypeValue::RadioScc::INACTIVE);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "RadioSccCancel" << Trace::EndLog();
}

void RadioUnit::RadioCabIntercomAccept(const Sim::Number &num_obj)
{
    const int CabScc = GetObjectPropertyNumber<int>(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::CAB_SCC);
    if (CabScc == Project::TypeValue::RadioScc::CAB)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Can't accept CAB Call Request with CAB " << Trace::EndLog();
        return;
    }

    if (num_obj.value > 0.5 && m_power_on)
    {
        std::lock_guard lock(m_lock);
        if (m_state.m_radio_call_type > RADIO_CALL_INACTIVE && m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::CALL_REQUEST)
        {
            m_state.m_radio_intercom_state = Project::TypeValue::RadioIntercomState::CALL_CONNECTED;
            SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE, Project::TypeValue::RadioIntercomState::CALL_CONNECTED);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "RadioCabIntercomAccept" << Trace::EndLog();
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "There is no Radio Call Request going on" << Trace::EndLog();
        }
    }
}

void RadioUnit::RadioSccIntercomAccept(const Sim::Number &num_obj)
{
    const int CabScc = GetObjectPropertyNumber<int>(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::CAB_SCC);
    if (CabScc == Project::TypeValue::RadioScc::SCC)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Can't accept SCC Call Request with SCC " << Trace::EndLog();
        return;
    }

    if (num_obj.value > 0.5 && m_power_on)
    {
        std::lock_guard lock(m_lock);
        if (m_state.m_radio_call_type > RADIO_CALL_INACTIVE && m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::CALL_REQUEST)
        {
            m_state.m_radio_intercom_state = Project::TypeValue::RadioIntercomState::CALL_CONNECTED;
            SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE, Project::TypeValue::RadioIntercomState::CALL_CONNECTED);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "RadioSccIntercomAccept" << Trace::EndLog();
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "There is no Radio Call Request going on" << Trace::EndLog();
        }
    }
}

void RadioUnit::RadioEmrgcyCallReq(const Sim::Number &num_obj)
{
    const int PisIntercom = GetObjectPropertyNumber<int>(m_intercom_output_comms, Project::ValueName::IntercomOutputs::INTERCOM);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom state : " << PisIntercom << Trace::EndLog();
	if (!m_power_on) 
	{
		Trace::GetLogger().STAMP(Trace::VERBOSE) << " Panto is not up " << Trace::EndLog();
		return;
	}
	if (num_obj.value < 0.5) 
	{
		return;
	}
    std::lock_guard lock(m_lock);
    if (PisIntercom != static_cast<int>(CallState::INACTIVE))
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Call Type : Emergency Call Rqst " << Trace::EndLog();
        //to generate pulse
        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, Project::TypeValue::IntercomConstant::CALL_REQUEST);
        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON, Project::TypeValue::IntercomConstant::INACTIVE);

        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::CAB_CANCEL_BUTTON, Project::TypeValue::IntercomConstant::CALL_REQUEST);
        SetObjectPropertyNumber(m_intercom_input_comms, Project::ValueName::IntercomInputs::CAB_CANCEL_BUTTON, Project::TypeValue::IntercomConstant::INACTIVE);
    }
    if (m_state.m_intercom_output != static_cast<int>(CallState::INACTIVE)
        || m_state.m_radio_call_type != RADIO_CALL_INACTIVE
        || m_state.m_radio_intercom_state != Project::TypeValue::RadioIntercomState::INACTIVE) 
    {
        //to cancel ongoing radio calls
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "scc_cancel" << Trace::EndLog();
        RadioSccCancel(1);
    }
    m_state.m_radio_call_type = Project::TypeValue::RadioCallType::RADIO_EMERGNECY;
    m_state.m_radio_intercom_state = Project::TypeValue::RadioIntercomState::CALL_REQUEST;
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE, Project::TypeValue::RadioIntercomState::CALL_REQUEST);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_CALL_TYPE, Project::TypeValue::RadioCallType::RADIO_EMERGNECY);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "RadioEmrgcyCallReq" << Trace::EndLog();
}

void RadioUnit::RadioFullDuplxReq(const Sim::Number &num_obj)
{
    const int PisIntercom = GetObjectPropertyNumber<int>(m_intercom_output_comms, Project::ValueName::IntercomOutputs::INTERCOM);
    const int RadioIntercomState = GetObjectPropertyNumber<int>(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE);
    const int CabScc = GetObjectPropertyNumber<int>(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::CAB_SCC);

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom state : " << PisIntercom << Trace::EndLog();
    if (!m_power_on)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Panto is not up " << Trace::EndLog();
        return;
    }
    if (num_obj.value < 0.5)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " PIS Intercom is in request/active state    Call Type : Full Duplex Rqst " << Trace::EndLog();
        return;
    }

    //to cancel ongoing radio or intercom calls, only from SCC not from CAB
    if (PisIntercom != static_cast<int>(CallState::INACTIVE) || RadioIntercomState != static_cast<int>(CallState::INACTIVE) && CabScc == Project::TypeValue::RadioScc::CAB)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "cab_cancel" << Trace::EndLog();
        RadioCabCancel(1);
    }

    std::lock_guard lock(m_lock);
    if (m_state.m_intercom_output != static_cast<int>(CallState::INACTIVE)
        || m_state.m_radio_call_type != RADIO_CALL_INACTIVE
        || m_state.m_radio_intercom_state != Project::TypeValue::RadioIntercomState::INACTIVE)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Already Radio Call is in progress: " << m_state.m_radio_call_type << Trace::EndLog();
        return;
    }
    m_state.m_radio_call_type = Project::TypeValue::RadioCallType::RADIO_FULL_DUPLEX;
    m_state.m_radio_intercom_state = Project::TypeValue::RadioIntercomState::CALL_REQUEST;
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE, Project::TypeValue::RadioIntercomState::CALL_REQUEST);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_CALL_TYPE, Project::TypeValue::RadioCallType::RADIO_FULL_DUPLEX);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_DIALLED_NO, num_obj.value);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "RadioFullDuplxReq" << Trace::EndLog();
}

void RadioUnit::RadioGroupCallReq(const Sim::Number &num_obj)
{
    const int PisIntercom = GetObjectPropertyNumber<int>(m_intercom_output_comms, Project::ValueName::IntercomOutputs::INTERCOM);
    const int RadioIntercomState = GetObjectPropertyNumber<int>(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE);

    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom state : " << PisIntercom << Trace::EndLog();
    if (!m_power_on)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Panto is not up " << Trace::EndLog();
        return;
    }
    if (num_obj.value < 0.5 || PisIntercom != static_cast<int>(CallState::INACTIVE))
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " PIS Intercom is in request/active state    Call Type : Group Call Rqst " << Trace::EndLog();
        return;
    }

    //to cancel ongoing radio or intercom calls
    if (PisIntercom != static_cast<int>(CallState::INACTIVE) || RadioIntercomState != static_cast<int>(CallState::INACTIVE))
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "cab_cancel" << Trace::EndLog();
        RadioCabCancel(1);
    }

    std::lock_guard lock(m_lock);
    if (m_state.m_intercom_output != static_cast<int>(CallState::INACTIVE)
        || m_state.m_radio_call_type != RADIO_CALL_INACTIVE
        || m_state.m_radio_intercom_state != Project::TypeValue::RadioIntercomState::INACTIVE)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Already Radio Call is in progress: " << m_state.m_radio_call_type << Trace::EndLog();
        return;
    }
    m_state.m_radio_call_type = Project::TypeValue::RadioCallType::RADIO_GROUP;
    m_state.m_radio_intercom_state = Project::TypeValue::RadioIntercomState::CALL_REQUEST;
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE, Project::TypeValue::RadioIntercomState::CALL_REQUEST);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_CALL_TYPE, Project::TypeValue::RadioCallType::RADIO_GROUP);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_GROUP_CALL, num_obj.value);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "RadioGroupCallReq" << Trace::EndLog();
}

void RadioUnit::RadioHalfDuplxReq(const Sim::Number &num_obj)
{
    const int PisIntercom = GetObjectPropertyNumber<int>(m_intercom_output_comms, Project::ValueName::IntercomOutputs::INTERCOM);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Intercom state : "<< PisIntercom << Trace::EndLog();
    if (!m_power_on)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " Panto is not up " << Trace::EndLog();
        return;
    }
    if (num_obj.value < 0.5 || PisIntercom != static_cast<int>(CallState::INACTIVE))
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << " PIS Intercom is in request/active state    Call Type : Half Duplex Rqst " << Trace::EndLog();
        return;
    }

    std::lock_guard lock(m_lock);
    if (m_state.m_intercom_output != static_cast<int>(CallState::INACTIVE)
        || m_state.m_radio_call_type != RADIO_CALL_INACTIVE
        || m_state.m_radio_intercom_state != Project::TypeValue::RadioIntercomState::INACTIVE)
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Already Radio Call is in progress: " << m_state.m_radio_call_type << Trace::EndLog();
        return;
    }
    m_state.m_radio_call_type = Project::TypeValue::RadioCallType::RADIO_HALF_DUPLEX;
    m_state.m_radio_intercom_state = Project::TypeValue::RadioIntercomState::CALL_REQUEST;
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::RADIO_INTERCOM_STATE, Project::TypeValue::RadioIntercomState::CALL_REQUEST);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_CALL_TYPE, Project::TypeValue::RadioCallType::RADIO_HALF_DUPLEX);
    SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::SELECTED_RADIO_DIALLED_NO, num_obj.value);
    Trace::GetLogger().STAMP(Trace::VERBOSE) << "RadioHalfDuplxReq" << Trace::EndLog();
}

void RadioUnit::Step(double new_time)
{
}

double RadioUnit::GetPeriod() const
{
    return (1.0 / REQUEST_FREQ);
}

void RadioUnit::ObjectCreated(Comms::Object object)
{
    size_t class_id = Core::GetClassID(object);

    const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);

    switch (class_id)
    {
    case Project::ClassID::WORLD:
        Comms::AddCreationCallback(object, MakeCallback(&RadioUnit::ObjectCreated, this));
        break;

    case Project::ClassID::TRAIN:
    {
        if (GetObjectPropertyNumber<int>(object, Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&RadioUnit::ObjectCreated, this));
            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::RADIO_INTERCOM));
        }
    }
    break;

    case Project::ClassID::INTERCOM:
    {
        if (GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&RadioUnit::ObjectCreated, this));
        }
    }
    break;

    case Project::ClassID::INTERCOM_INPUTS:
    {
        m_intercom_input_comms = object;
        //RequestProperty(object, Project::ValueName::IntercomInputs::SCC_INTERCOM_CANCEL_BUTTON);
    }
    break;

    case Project::ClassID::INTERCOM_OUTPUTS:
    {
        m_intercom_output_comms = object;
        RequestProperty(object, Project::ValueName::IntercomOutputs::INTERCOM);
    }
    break;

    case Project::ClassID::VEHICLE:
    {
        if (GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&RadioUnit::ObjectCreated, this));

            int vehicle_index = GetObjectPropertyNumber<int>(object, Train::ValueName::Vehicle::INDEX);
            if (vehicle_index == m_cab_vehicle_idx)
            {
                m_vehicle_comms = object;

                RequestProperty(object, Project::ValueName::Vehicle::TDO_SPEED);
            }
        }
    }
    break;
    
    case Project::ClassID::PAPIS_VEHICLE_OUTPUTS:
    {
        auto scenario_train_id = object.GetParent().GetParent().Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value;
        if ((scenario_train_id == m_scenario_train_id))
        {
            m_papis_vehicle_outputs_comms = object;

            Comms_Number_Listener_t num_listener;
            Sim::Number number = object.Numbers().Get(Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER
                    << " is not a valid number in PAPIS_CCTV_POWER, hence ignoring." << Trace::EndLog();
            }
            else
            {
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
                num_listener.AddCallback(number, MakeCallback(&RadioUnit::PowerStateChanged, this));
            }
            object.Numbers().Store().AddListener(num_listener);
        }
    }
    break;
    
    case Project::ClassID::RADIO_INTERCOM:
    {
        if (GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&RadioUnit::ObjectCreated, this));

            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::RADIO_INTERCOM_INPUTS_VALUES));
            object.CreateChild(Project::GetObjectDefinition(Project::ClassID::RADIO_INTERCOM_OUTPUTS));
        }
    }
    break;

    case Project::ClassID::RADIO_INTERCOM_INPUTS_VALUES:
    {
        m_radio_inputs_comms = object;

        Comms_Number_Listener_t num_listener;
        
        //1
        Sim::Number number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_CAB_CANCEL);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_CAB_CANCEL
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioCabCancel, this));
        }

        //2
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_CAB_INTERCOM);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_CAB_INTERCOM
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioCabIntercomAccept, this));
        }

        //3
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_EMRGNCY_CALL_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_EMRGNCY_CALL_REQ
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioEmrgcyCallReq, this));
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::SetCabScc_CAB, this));
        }

        //4
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_FULL_DUPLEX_CALL_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_FULL_DUPLEX_CALL_REQ
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioFullDuplxReq, this));
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::SetCabScc_CAB, this));
        }

        //5
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_GROUP_CALL_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_GROUP_CALL_REQ
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioGroupCallReq, this));
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::SetCabScc_CAB, this));
        }

        //6
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_HALF_DUPLEX_CALL_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_HALF_DUPLEX_CALL_REQ
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioHalfDuplxReq, this));
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::SetCabScc_CAB, this));
        }

        //7
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_CANCEL);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_CANCEL
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioSccCancel, this));
        }

        //8
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_INTERCOM);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_INTERCOM
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioSccIntercomAccept, this));
        }

        //9
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_EMRGNCY_CALL_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_EMRGNCY_CALL_REQ
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioEmrgcyCallReq, this));
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::SetCabScc_SCC, this));
        }

        //10
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_FULL_DUPLEX_CALL_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_FULL_DUPLEX_CALL_REQ
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioFullDuplxReq, this));
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::SetCabScc_SCC, this));
        }

        //11  Commented as group call can't be initiated from SCC
        /*number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_GROUP_CALL_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_GROUP_CALL_REQ
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioGroupCallReq, this));
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::SetCabScc_SCC, this));
        }*/

        //12
        number = object.Numbers().Get(Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_HALF_DUPLEX_CALL_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::RadioIntercomInputsValues::RADIO_SCC_HALF_DUPLEX_CALL_REQ
                << " is not a valid number in RadioIntercomInputsValues, hence ignoring." << Trace::EndLog();
        }
        else
        {
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), REQUEST_FREQ);
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::RadioHalfDuplxReq, this));
            num_listener.AddCallback(number, MakeCallback(&RadioUnit::SetCabScc_SCC, this));
        }

        object.Numbers().Store().AddListener(num_listener);
    }
    break;

    case Project::ClassID::RADIO_INTERCOM_OUTPUTS:
    {
        m_radio_outputs_comms = object;
    }
    break;
    }
}

void RadioUnit::PowerStateChanged(bool power_on)
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << " PowerStateChanged has changed to : " << power_on << Trace::EndLog();
    if (power_on)
    {
        m_power_on = true;
    }
    else
        m_power_on = false;
}

void RadioUnit::SetCabScc_CAB(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if(static_cast<int>(num_obj.value) > Project::TypeValue::RadioScc::INACTIVE)
        SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::CAB_SCC, Project::TypeValue::RadioScc::CAB);
}

void RadioUnit::SetCabScc_SCC(const Sim::Number &num_obj)
{
    std::lock_guard lock(m_lock);
    if (static_cast<int>(num_obj.value) > Project::TypeValue::RadioScc::INACTIVE)
        SetObjectPropertyNumber(m_radio_outputs_comms, Project::ValueName::RadioIntercomOutputs::CAB_SCC, Project::TypeValue::RadioScc::SCC);
}