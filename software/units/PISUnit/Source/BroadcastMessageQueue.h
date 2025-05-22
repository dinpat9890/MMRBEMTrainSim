/// @file      BroadcastMessageQueue.h
///            Handles PIS broadcast message priorities.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "PISAudio.h"
#include "PISState.h"

#include <queue>
#include <vector>
#include <optional>

#ifndef BROADCAST_MESSAGE_QUEUE_H
#define BROADCAST_MESSAGE_QUEUE_H

class BroadcastMessageQueue
{
public:
    BroadcastMessageQueue() = delete;
    BroadcastMessageQueue(PISAudio& audio_engine, PISState& pis_state) : m_audio_engine(audio_engine), m_state(pis_state) {}
    ~BroadcastMessageQueue() {}

    void EnqueueBroadcastMessage(unsigned int priority, BroadcastMessage msg);
    std::optional<BroadcastMessage> DequeueBroadcastMessage();
    void ResetLastDequeuedMessage();
    void ClearQueue();
    std::optional<BroadcastMessage> GetLastDequeueBroadcastMessage();

private:

    PISAudio& m_audio_engine;
    PISState& m_state;

    std::priority_queue<BroadcastMessage> m_broadcast_messages_queue;

    std::optional<BroadcastMessage> m_last_dequeued_message;
};

#endif