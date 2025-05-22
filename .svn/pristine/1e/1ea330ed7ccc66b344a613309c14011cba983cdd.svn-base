///
/// @file       CCTVCommsInterface.cpp
///
///             Interface to Sydac Comms unit.
///             It is fetch propeties from Sydac::Comms using watcher & also update output to it.
///
/// @ingroup    Mumbai L2-L7 CCTV
///
/// @author     Yatendra Gupta
///
/// @copyright  (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022
///

#pragma once

#include "CCTVCommsInterface.h"
#include "project_comms_structure/ProjectObjectDefinition.h"
#include "Utility/Utilities.h"
#include "sim_common/Listener.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "Common/StandardLogging.h"
#include <map>
#include <string>


namespace
{
    typedef Sim::Listener<Sim::Raw, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Raw>>        Comms_Raw_Listener_t;
    typedef Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::IndividualCallbacks<Sim::Number>>  Comms_Number_Listener_t;
}
void CCTVCommsInterface::RequestProperty(Comms::Object& object, const char* property)
{
    assert(property != nullptr);
    if (object.IsValid())
    {
        object.Numbers().Store().Request(
            object.Numbers().Info().GetInfo(object.Numbers().Info().GetID(property)),
            m_frequency);
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Invalid comms object: "<< object.GetID() << " " << object.GetName() << Trace::EndLog();
    }
}
void CCTVCommsInterface::SetObjectPropertyNumber(Comms::Object& object, const char* property, double value)
{
    if (!object.IsValid() || property == nullptr)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "Invalid comms object or null property ." << Trace::EndLog();

        return;
    }

    try {
        auto number = object.Numbers().Get(property);
        number.value = value;
        object.Numbers().Store().Set(number);
    }
    catch (CommonException &e)
    {
        Trace::GetLogger().STAMP(Trace::ERR) << e.what() << Trace::EndLog();
    }
}
CCTVCommsInterface::CCTVCommsInterface(Comms::Gateway &gateway, Core::BaseScenarioData::HubData &hub_data, double frequency) :
    m_gateway(gateway),
    m_hub_data(hub_data),
    m_frequency(frequency)
{
}

CCTVCommsInterface::~CCTVCommsInterface()
{
}

void CCTVCommsInterface::Start()
{
    const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);
    Comms::AddCreationCallback(m_gateway.GetRootObject(), MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
}

void CCTVCommsInterface::ObjectCreated(Comms::Object object)
{
    size_t class_id = Core::GetClassID(object);

    switch (class_id)
    {
    case Project::ClassID::WORLD:
        Comms::AddCreationCallback(object, MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
        break;

    case Core::ClassID::FEATURES:
    {
        Comms::AddCreationCallback(object, MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
    }
    break;

    case Core::ClassID::FEATURE:
    {
        int feature_id_station = GetObjectPropertyNumber<int>(object, Core::ValueName::Feature::TYPE);
        //Trace::GetLogger().STAMP(Trace::INFO) << "Station Feature Type - Comms Object: " << object.GetName() << " feature_id_station: " 
        //    << feature_id_station << " m_station_feature_type: " << m_station_feature_type << Trace::EndLog();

        if (feature_id_station == m_stopping_point)
        {
            m_station_features_list.push_back(object);
            //Trace::GetLogger().STAMP(Trace::INFO) << "Station Feature Type - Comms Object: " << object.GetName()<< Trace::EndLog();
        }
    }
    break;

    case Project::ClassID::TRAIN:
    {
        if (object.Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value == m_hub_data.scenario_train_id)
        {
            RequestProperty(object, Project::ValueName::Train::FLT_DAMAGED_OHE);
            RequestProperty(object, Project::ValueName::Train::FLT_TRACK_CIRCUIT_OCCUPIED);
            RequestProperty(object, Project::ValueName::Train::DERAILMENT);

            m_trains_comms = object;
            //1
            Sim::Number number = object.Numbers().Get(Project::ValueName::Train::AUTO_POWER_ON);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Train::AUTO_POWER_ON
                    << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
            }
            else
            {
                Comms_Number_Listener_t num_listener;
                m_input_numbers.insert(std::make_pair(Project::ValueName::Train::AUTO_POWER_ON, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
                object.Numbers().Store().AddListener(num_listener);
            }
            //2
            number = object.Numbers().Get(Project::ValueName::Train::DERAILMENT);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Train::DERAILMENT
                    << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
            }
            else
            {
                Comms_Number_Listener_t num_listener;
                m_input_numbers.insert(std::make_pair(Project::ValueName::Train::DERAILMENT, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
                object.Numbers().Store().AddListener(num_listener);
            }

            Comms::AddCreationCallback(object, MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
        }

    }
    break;

    case Project::ClassID::INTERCOM:
    {
        Comms::AddCreationCallback(object, MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
    }
    break;

    case Project::ClassID::INTERCOM_OUTPUTS:
    {
        Comms::AddCreationCallback(object, MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
    }
    break;

    case Project::ClassID::OHP_OUTPUTS:
    {
        RequestProperty(object, Project::ValueName::OHPOutputs::PE_ID);
        m_ohp_outputs_comms = object;

        Comms_Number_Listener_t num_listener;
        Trace::GetLogger().STAMP(Trace::INFO) << "OHP_OUTPUTS object created" << Trace::EndLog();

        Sim::Number number = object.Numbers().Get(Project::ValueName::OHPOutputs::PE_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::OHPOutputs::PE_ID
                << " is not a valid number in SaloonCCTVOuputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::OHPOutputs::PE_ID, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        object.Numbers().Store().AddListener(num_listener);
    }
    break;

    case Project::ClassID::VEHICLE:
    {
        if (object.GetParent().Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value == m_hub_data.scenario_train_id)
        {
    /*        const double vehicle_index = object.Numbers().Get(Train::ValueName::Vehicle::INDEX).value;
            if (vehicle_index == m_hub_data.vehicle_index)
                object.CreateChild(Project::GetObjectDefinition(Project::ClassID::VDU));*/

            RequestProperty(object, Project::ValueName::Vehicle::FLT_DOOR_CLOSE_OBSTRUCTION);
            RequestProperty(object, Project::ValueName::Vehicle::FLT_DOOR_OPEN_OBSTRUCTION);
            RequestProperty(object, Project::ValueName::Vehicle::FLT_PANTOGRAPH_RAISE_FAILURE);
            RequestProperty(object, Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ADD_INTERVENTION);
            RequestProperty(object, Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ORD_INTERVENTION);


            RequestProperty(object, Project::ValueName::Vehicle::FLT_DOOR_UNEXPECTED_UNLOCKING);
            RequestProperty(object, Project::ValueName::Vehicle::FLT_HVAC_1_FIRE_MODE);
            RequestProperty(object, Project::ValueName::Vehicle::FLT_ODD_FAILURE);

            RequestProperty(object, Project::ValueName::Vehicle::FLT_OBSTACLE_DETECTED_RIGHT_SIDE);

            Comms_Number_Listener_t num_listener;
            Sim::Number number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_OBSTACLE_DETECTED_RIGHT_SIDE);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_OBSTACLE_DETECTED_RIGHT_SIDE
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_OBSTACLE_DETECTED_RIGHT_SIDE, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }
            //2
            number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_DOOR_CLOSE_OBSTRUCTION);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_DOOR_CLOSE_OBSTRUCTION
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_DOOR_CLOSE_OBSTRUCTION, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }
            //3
            number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_DOOR_OPEN_OBSTRUCTION);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_DOOR_OPEN_OBSTRUCTION
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_DOOR_OPEN_OBSTRUCTION, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }
            //3
            number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_PANTOGRAPH_RAISE_FAILURE);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_PANTOGRAPH_RAISE_FAILURE
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_PANTOGRAPH_RAISE_FAILURE, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }
            //4
            number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ADD_INTERVENTION);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ADD_INTERVENTION
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ADD_INTERVENTION, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }
            //5
            number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ORD_INTERVENTION);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ORD_INTERVENTION
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_PANTOGRAPH_DOWN_FOR_ORD_INTERVENTION, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }
            //6
            number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_DOOR_UNEXPECTED_UNLOCKING);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_DOOR_UNEXPECTED_UNLOCKING
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_DOOR_UNEXPECTED_UNLOCKING, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }
            //7
            number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_HVAC_1_FIRE_MODE);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_HVAC_1_FIRE_MODE
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_HVAC_1_FIRE_MODE, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }
            //8
            number = object.Numbers().Get(Project::ValueName::Vehicle::FLT_ODD_FAILURE);
            if (number.id == Sim::INVALID_NUMBER)
            {
                Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::Vehicle::FLT_ODD_FAILURE
                    << " is not a valid number in VEHICLE, hence ignoring." << Trace::EndLog();
            }
            else
            {
                m_input_events_numbers.push_back(std::make_pair(Project::ValueName::Vehicle::FLT_ODD_FAILURE, std::make_pair(number.id, number)));
                object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
                num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
            }

            object.Numbers().Store().AddListener(num_listener);

            int vehicle_index = GetObjectPropertyNumber<int>(object, "Index");
            m_vehicles_comms[vehicle_index] = object;
            Comms::AddCreationCallback(object, MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
        }
    }
    break;

    case Project::ClassID::PAPIS_VEHICLE_OUTPUTS:
    {
        RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::PECU_ALARM_ACTIVE);
        RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::EMERGENCY_DOOR_OPEN);
        RequestProperty(object, Project::ValueName::PAPISVehicleOutputs::FRONT_OBSTACLE_DETECTED);

        int vehicle_index = GetObjectPropertyNumber<int>(object.GetParent(), "Index");

        m_papis_vehicles_comms[vehicle_index] = object;

        Comms_Number_Listener_t num_listener;
        Sim::Number number = object.Numbers().Get(Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER
                << " is not a valid number in PAPIS_VEHICLE_OUTPUTS, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_events_numbers.push_back(std::make_pair(Project::ValueName::PAPISVehicleOutputs::PAPIS_CCTV_POWER, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
        }

        //2
        number = object.Numbers().Get(Project::ValueName::PAPISVehicleOutputs::EMERGENCY_DOOR_OPEN);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PAPISVehicleOutputs::EMERGENCY_DOOR_OPEN
                << " is not a valid number in PAPIS_VEHICLE_OUTPUTS, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_events_numbers.push_back(std::make_pair(Project::ValueName::PAPISVehicleOutputs::EMERGENCY_DOOR_OPEN, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
        }

        //3
        number = object.Numbers().Get(Project::ValueName::PAPISVehicleOutputs::FRONT_OBSTACLE_DETECTED);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::PAPISVehicleOutputs::FRONT_OBSTACLE_DETECTED
                << " is not a valid number in PAPIS_VEHICLE_OUTPUTS, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_events_numbers.push_back(std::make_pair(Project::ValueName::PAPISVehicleOutputs::FRONT_OBSTACLE_DETECTED, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberEventsChanged, static_cast<ICommsInterface *>(this)));
        }

        object.Numbers().Store().AddListener(num_listener);
    }
    break;

    case Project::ClassID::VEHICLE_INPUTS:
    {
        if (object.GetParent().GetParent().Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value == m_hub_data.scenario_train_id)
        {
            double vehicle_index = object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value;
            if (vehicle_index == m_hub_data.vehicle_index)
            {
                Comms_Number_Listener_t num_listener;

                Sim::Number number1 = object.Numbers().Get(Project::ValueName::VehicleInputs::CONTROL_KEY);
                if (number1.id == Sim::INVALID_NUMBER)
                {
                    Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VehicleInputs::CONTROL_KEY
                        << " is not a valid number in VehicleInputs, hence ignoring." << Trace::EndLog();
                }
                else
                {
                    m_input_numbers.insert(std::make_pair(Project::ValueName::VehicleInputs::CONTROL_KEY, std::make_pair(number1.id, number1)));
                    object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number1.id), m_frequency);
                    num_listener.AddCallback(number1, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
                    object.Numbers().Store().AddListener(num_listener);
                }
            }
        }
    }
    break;
    case Project::ClassID::VDU:
    {
        Trace::GetLogger().STAMP(Trace::INFO) << "VDU object created" << Trace::EndLog();
        auto scenario_train_id = object.GetParent().GetParent().Numbers().Get(Train::ValueName::Train::SCENARIO_TRAIN_ID).value;
        auto vehicle_index = object.GetParent().Numbers().Get(Train::ValueName::Vehicle::INDEX).value;
        if ((scenario_train_id == m_hub_data.scenario_train_id) && (vehicle_index == m_hub_data.vehicle_index))
        {
            //object.CreateChild(Project::GetObjectDefinition(Project::ClassID::VDU_INPUTS));
            //object.CreateChild(Project::GetObjectDefinition(Project::ClassID::VDU_OUTPUTS));
            Comms::AddCreationCallback(object, MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
        }
    }
    break;
    case Project::ClassID::VDU_INPUTS:
    {
        Trace::GetLogger().STAMP(Trace::INFO) << "VDU_INPUTS object created" << Trace::EndLog();
        //object.CreateChild(Project::GetObjectDefinition(Project::ClassID::VDU_INPUTS_MODES));
        //object.CreateChild(Project::GetObjectDefinition(Project::ClassID::VDU_INPUTS_VALUES));
        Comms::AddCreationCallback(object, MakeCallback(&CCTVCommsInterface::ObjectCreated, this));
        Comms::AddDestructionCallback(object, [this](const Comms::Object& object) { DestroyVDUObjectsCallback(object); });
    }
    break;
    case Project::ClassID::VDU_INPUTS_VALUES:
    {
        m_saloon_cctv_inputs_object = object;
        Comms_Number_Listener_t num_listener;
        Trace::GetLogger().STAMP(Trace::INFO) << "VDU_INPUTS_VALUES object created" << Trace::EndLog();

        Sim::Number number = object.Numbers().Get(Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::AUTO_ROTATION_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::VIEW_SELECTION_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::VIEW_SELECTION_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::VIEW_SELECTION_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }
        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::SELECTED_CAMERA_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::SELECTED_CAMERA_ID
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::SELECTED_CAMERA_ID, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }
        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::CURRENT_SELECTED_VEHICLE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::CURRENT_SELECTED_VEHICLE
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::CURRENT_SELECTED_VEHICLE, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }
        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::PREVIOUS_ARROW_PRESSED_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::PREVIOUS_ARROW_PRESSED_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::PREVIOUS_ARROW_PRESSED_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }
        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::NEXT_ARROW_PRESSED_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::NEXT_ARROW_PRESSED_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::NEXT_ARROW_PRESSED_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }
        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::EXT_CAMERA_TYPE_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::SELECTED_EXT_CAMTYP_VEHICLE_REQ);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::SELECTED_EXT_CAMTYP_VEHICLE_REQ
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::SELECTED_EXT_CAMTYP_VEHICLE_REQ, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::ALARM_MODE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::ALARM_MODE
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::ALARM_MODE, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::ALARM_TYPE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::ALARM_TYPE
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::ALARM_TYPE, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::ALARM_TYPE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::ALARM_TYPE
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::ALARM_TYPE, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::CCTV_SETTING_QUIT_BUTTON_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::CCTV_SETTING_QUIT_BUTTON_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::CCTV_SETTING_QUIT_BUTTON_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::CCTV_SETTING_PANEL_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::CCTV_SETTING_PANEL_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::CCTV_SETTING_PANEL_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        number = object.Numbers().Get(Project::ValueName::VDUInputsValues::CCTV_NORMAl_EVENT_SWITCH_REQUEST);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUInputsValues::CCTV_NORMAl_EVENT_SWITCH_REQUEST
                << " is not a valid number in SaloonCCTVInputs, hence ignoring." << Trace::EndLog();
        }
        else
        {
            m_input_numbers.insert(std::make_pair(Project::ValueName::VDUInputsValues::CCTV_NORMAl_EVENT_SWITCH_REQUEST, std::make_pair(number.id, number)));
            object.Numbers().Store().Request(object.Numbers().Info().GetInfo(number.id), m_frequency);
            num_listener.AddCallback(number, MakeCallback(&CCTVCommsInterface::NumberChanged, static_cast<ICommsInterface *>(this)));
        }

        object.Numbers().Store().AddListener(num_listener);
    }
    break;
    case Project::ClassID::VDU_INPUTS_MODES:
    {
    }
    break;
    case Project::ClassID::VDU_OUTPUTS:
    {
        m_saloon_cctv_outputs_object = object;

        Sim::Number number = object.Numbers().Get(Project::ValueName::VDUOutputs::SCREEN_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::SCREEN_ID
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::SCREEN_ID, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::AUTO_ROTATION_ON
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::AUTO_ROTATION_ON, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::TRAIN_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::TRAIN_ID
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::TRAIN_ID, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::EXTERNAL_OR_INTERNAL_VIEW);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::EXTERNAL_OR_INTERNAL_VIEW
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::EXTERNAL_OR_INTERNAL_VIEW, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::SELECTED_VEHICLE_IDX, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::SELECTED_EXT_CAM_TYP, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::NORMAL_OR_EVENT_VIEW);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::NORMAL_OR_EVENT_VIEW
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::NORMAL_OR_EVENT_VIEW, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::ALARM_ACTIVE_TYPE_INDEX, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::FIRE_ALARM_1);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::FIRE_ALARM_1
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::FIRE_ALARM_1, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::OBSTCL_SALOON_DR_ALARM_2);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::OBSTCL_SALOON_DR_ALARM_2
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::OBSTCL_SALOON_DR_ALARM_2, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::PECU_ALARM_3);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::PECU_ALARM_3
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::PECU_ALARM_3, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::DR_UNLK_ALARM_4);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::DR_UNLK_ALARM_4
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::DR_UNLK_ALARM_4, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::EMRG_DR_OPN_ALARM_5);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::EMRG_DR_OPN_ALARM_5
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::EMRG_DR_OPN_ALARM_5, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::DRVR_DSK_ALARM_6);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::DRVR_DSK_ALARM_6
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::DRVR_DSK_ALARM_6, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::OBSTRUCTION_DEFLCT_ALARM_7);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::OBSTRUCTION_DEFLCT_ALARM_7
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::OBSTRUCTION_DEFLCT_ALARM_7, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::TRACK_EVENT_ALARM_8);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::TRACK_EVENT_ALARM_8
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::TRACK_EVENT_ALARM_8, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::EMRG_CCTV_ALARM_9);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::EMRG_CCTV_ALARM_9
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::EMRG_CCTV_ALARM_9, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::OHE_ALARM_10);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::OHE_ALARM_10
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::OHE_ALARM_10, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::PANTO_ALARM_11);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::PANTO_ALARM_11
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::PANTO_ALARM_11, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::DETRAINMENT_CAMERA_STATE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::DETRAINMENT_CAMERA_STATE
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::DETRAINMENT_CAMERA_STATE, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::CCTV_DETRAINMENT_CAMERA_ID);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::CCTV_DETRAINMENT_CAMERA_ID
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::CCTV_DETRAINMENT_CAMERA_ID, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::CCTV_SETTING_QUIT_BUTTON_STATE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::CCTV_SETTING_QUIT_BUTTON_STATE
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::CCTV_SETTING_QUIT_BUTTON_STATE, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::CCTV_SETTING_PANEL_STATE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::CCTV_SETTING_PANEL_STATE
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::CCTV_SETTING_PANEL_STATE, std::make_pair(number.id, number)));

        number = object.Numbers().Get(Project::ValueName::VDUOutputs::CCTV_NORMAl_EVENT_SWITCH_STATE);
        if (number.id == Sim::INVALID_NUMBER)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::CCTV_NORMAl_EVENT_SWITCH_STATE
                << " is not a valid number in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_numbers.insert(std::make_pair(Project::ValueName::VDUOutputs::CCTV_NORMAl_EVENT_SWITCH_STATE, std::make_pair(number.id, number)));

        Sim::Raw raw = object.Raws().Get(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE);
        if (raw.id == Sim::INVALID_RAW)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE
                << " is not a valid raw in VDUOutputs, hence ignoring." << Trace::EndLog();
        }
        else
            m_output_raws.insert(std::make_pair(Project::ValueName::VDUOutputs::CAMERA_VIEW_BUTTONS_STATE, std::make_pair(raw.id, raw)));


    }
    break;

    default:
        break;
    }
}

void CCTVCommsInterface::SetOutputNumber(const std::string &number_name, double number_value)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    auto num_data_itr = m_output_numbers.find(number_name);
    if (num_data_itr != m_output_numbers.end() && m_saloon_cctv_outputs_object.IsValid())
    {
        num_data_itr->second.second.value = number_value;

        const OS::Lock<Comms::Gateway> gateway_lock(m_gateway);
        m_saloon_cctv_outputs_object.Numbers().Store().Set(num_data_itr->second.second);
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "SetOutputNumber: Number property : [" << number_name << "] not found in VDUOutputs object." << Trace::EndLog();
    }
}

void CCTVCommsInterface::SetOutputRaw(const std::string &raw_name, const std::string &raw_value)
{
    std::lock_guard<std::recursive_mutex> local_lock(m_mutex);

    auto raw_data_itr = m_output_raws.find(raw_name);
    if (raw_data_itr != m_output_raws.end() && m_saloon_cctv_outputs_object.IsValid())
    {
        raw_data_itr->second.second.value.clear();
        raw_data_itr->second.second.value.insert(raw_data_itr->second.second.value.begin(), raw_value.begin(), raw_value.end());

        const OS::Lock<Comms::Gateway> gateway_lock(m_gateway);
        m_saloon_cctv_outputs_object.Raws().Store().Set(raw_data_itr->second.second);
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::ERR) << "SetOutputRaw: Raw property : [" << raw_name << "] not found in VDUOutputs object." << Trace::EndLog();
    }
}
