/// @file      PISAudio.cpp
///            Interface to Core's Audio Engine.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "PISAudio.h"

#include "CommsPropertyAccessors.h"

#include "common/StandardLogging.h"
#include "core_properties/CommonProperties.h"
#include "common/Callback.h"
#include "utility/Utilities.h"
#include "project_comms_structure/ProjectObjectConstants.h"
#include "project_comms_structure/ProjectObjectDefinition.h"
#include "sim_common/ObjectDefinition.h"
#include "core_types/AudioEngineTypes.h"
#include "CommsPISData.h"
#include "PISConstants.h"

#include <filesystem>

using namespace CTSProjectUtility;

PISAudio::PISAudio(
    Comms::Gateway &gateway,
    Common::Data::DataAccess &data_access,
    const Core::BaseScenarioData &scenario_data,
    const Common::Properties &properties)
    : m_gateway(gateway)
{
    try
    {
        auto hub_data = Core::GetHubData(scenario_data, Core::Properties::GetHubID(properties, data_access));
        m_scenario_train_id = hub_data.scenario_train_id;

        const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);
        Comms::AddCreationCallback(m_gateway.GetRootObject(), MakeCallback(&PISAudio::ObjectCreated, this));
    }
    catch (CommonException &e)
    {
        Trace::GetLogger().STAMP(Trace::WARN) << e.what() << ".\n PISAudio is not operational." << Trace::EndLog();
    }
}

PISAudio::~PISAudio()
{
    const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);
    m_sound_state_listener.RemoveAllCallbacks();
}

bool PISAudio::PlayMessageId(int id, BroadcastMessage msg)
{
    Trace::GetLogger().STAMP(Trace::INFO) << "Request to PLAY message title: " << msg.title << Trace::EndLog();

    pis::DVAPlayCommand play_command;
    play_command.title = msg.title;
    play_command.loop = false;
    for (size_t i = 0; i < msg.audio_ids.size(); ++i)
    {
        play_command.audio_ids.push_back(msg.audio_ids[i]);
    }
        
    if (m_pis_data)
        m_pis_data->SendPlayDvaCommand(play_command);
    else
        Trace::GetLogger().STAMP(Trace::ERR) << "PIS Comms Audio not available- ERROR : " << id << Trace::EndLog();


    return true;
}

bool PISAudio::PlayBuzzerInLoop()
{
    Trace::GetLogger().STAMP(Trace::INFO) << "Request to PLAY Call_Buzzer" << Trace::EndLog();

    pis::DVAPlayCommand play_command;
    play_command.title = "Call_Buzzer";
    play_command.loop = true;
    play_command.audio_ids.push_back(108);

    if (m_pis_data)
        m_pis_data->SendPlayDvaCommand(play_command);
    else
        Trace::GetLogger().STAMP(Trace::ERR) << "PIS Comms Audio (Call_Buzzer) not available- ERROR : " << Trace::EndLog();


    return true;
}


//void PISAudio::Stop(int id)
//{
//    Trace::GetLogger().STAMP(Trace::VERBOSE) << "Request to STOP message id : " << id << Trace::EndLog();
//
//    auto sound_comms = GetSoundCommsForId(id);
//
//    if (!sound_comms.IsValid())
//        return;
//
//    SetObjectPropertyNumber(sound_comms, Core::ValueName::SoundData::STATE, 0.0);
//}

void PISAudio::Stop()
{
    if (m_pis_data)
    {
        //m_pis_data->SetDvaStop(true);
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "STOP Audio command " << Trace::EndLog();
        m_pis_data->SendStopDvaCommand();
    }
    else
        Trace::GetLogger().STAMP(Trace::ERR) << "PIS Comms Audio not available- ERROR : " << Trace::EndLog();
}


void PISAudio::ObjectCreated(Comms::Object object)
{
    size_t class_id = Core::GetClassID(object);

    const std::lock_guard<Comms::Gateway> comms_lock(m_gateway);

    switch (class_id)
    {
    case Project::ClassID::WORLD:
        Comms::AddCreationCallback(object, MakeCallback(&PISAudio::ObjectCreated, this));
        break;
    case Project::ClassID::TRAIN:
    {
        if (GetObjectPropertyNumber<int>(object, Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&PISAudio::ObjectCreated, this));
        }
    }
    break;

    case Project::ClassID::VEHICLE:
    {
        if (GetObjectPropertyNumber<int>(object.GetParent(), Train::ValueName::Train::SCENARIO_TRAIN_ID) == m_scenario_train_id)
        {
            Comms::AddCreationCallback(object, MakeCallback(&PISAudio::ObjectCreated, this));
        }
    }
    break;
        case Project::ClassID::PIS:
        {
            Comms::AddCreationCallback(object, MakeCallback(&PISAudio::ObjectCreated, this));
        }
        break;
        case Project::ClassID::PIS_OUTPUTS:
        {
            m_pis_data = new pis::CommsPISData(object);
            Trace::GetLogger().STAMP(Trace::VERBOSE) << "COMS PIS data " << Trace::EndLog();
        }
        break;
    }

}