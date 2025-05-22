/// @file      PISAudio.h
///            Interface to Core's Audio Engine.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "Common/DataAccess.h"
#include "core_types/SessionData.h"
#include "sim_comms/Gateway.h"
#include "common/Properties.h"
#include "sim_common/Listener.h"

#include "IPISData.h"

#include <functional>

#ifndef PIS_AUDIO_H
#define PIS_AUDIO_H

// messages priorities from low to high
enum BroadcastMessagePriorities 
{ 
    MULTIMEDIA =0,
    DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY = 1,
    EMERGENCEY_SPECIAL_PRIORITY = 2, 
    DOOR_CLOSE_PRIORITY = 3,
    DOOR_CHIME_PRIORITY = 4,
    MANUAL_ANNOUNCEMENT_PRIORITY = 5,
    OCC_PRIORITY = 7
};

enum class AnnouncementType
{
    EMERGENCY_ANNOUNCEMENT = 1,
    SPECIAL_ANNOUNCEMENT = 2,
    OCC_ANNOUNCEMENT = 3,
    MANUAL_ANNOUNCEMENT = 4,
    DVA_ROUTE_START_DEPARTURE = 5,
    DVA_ROUTE_END_DEPARTURE = 6,
    DVA_ROUTE_MIDDLE_DEPARTURE = 7,
    DVA_ROUTE_END_ARRIVAL = 8,
    DVA_ROUTE_MIDDLE_ARRIVAL = 9,
};

enum class Language
{
    ENGLISH,
    MARATHI
};

struct BroadcastMessage
{
    BroadcastMessage() = delete;
    BroadcastMessage(unsigned int priority)
        : priority(priority), insertion_order(next_insertion_order++) {}

    int id = -1;
    unsigned int priority = DIGITAL_VOICE_ANNOUNCEMENT_PRIORITY;
    std::string      title;
    std::vector<int> audio_ids;

    // below is required to guarntee priority queue stability (i.e. same priority inserts have to be FIFO).
    unsigned int insertion_order;
    static unsigned int next_insertion_order;
};

class PISAudio
{
public:
    PISAudio(
        Comms::Gateway &gateway,
        Common::Data::DataAccess &data_access,
        const Core::BaseScenarioData &scenario_data,
        const Common::Properties &properties);
    ~PISAudio();

    // Play message with id.
    bool PlayMessageId(int id, BroadcastMessage msg);
    bool PlayBuzzerInLoop();

    // Stop message play.
    //void Stop(int id);
    void Stop();


private:
    Comms::Gateway &m_gateway;
    int m_scenario_train_id{ -1 };

    Comms::Object m_audio_engine_object;
    pis::IPISData * m_pis_data = nullptr;

    using WavId_To_Wave_Comms = std::map<int, Comms::Object>;
    WavId_To_Wave_Comms m_wave_id_to_comms;

    Sim::Listener<Sim::Number, Sim::NoQueueing, Sim::AllCallbacks<Sim::Number>> m_sound_state_listener;

    void ObjectCreated(Comms::Object object);
};

#endif