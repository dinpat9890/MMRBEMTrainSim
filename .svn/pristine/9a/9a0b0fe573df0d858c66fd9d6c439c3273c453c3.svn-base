/// @file      BroadcastMessageQueue.cpp
///            Handles PIS broadcast message priorities.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#include "BroadcastMessageQueue.h"
#include "project_comms_structure/ProjectObjectConstants.h"

unsigned int BroadcastMessage::next_insertion_order = 0;
    
bool operator<(const BroadcastMessage& a, const BroadcastMessage& b)
{
    if (a.priority != b.priority)
        return (a.priority < b.priority);

    return (a.insertion_order > b.insertion_order);
}

void BroadcastMessageQueue::EnqueueBroadcastMessage(unsigned int priority, BroadcastMessage msg)
{
    if (m_state.m_intercom_status == false && m_state.m_radio_intercom_state == Project::TypeValue::RadioIntercomState::INACTIVE)
    {
        m_broadcast_messages_queue.push(msg);
    }
    else
    {
        Trace::GetLogger().STAMP(Trace::VERBOSE) << "Dont Enqueue Audio msgs (intercom/RadioIntercom enabled)" << Trace::EndLog();
    }
}

std::optional<BroadcastMessage> BroadcastMessageQueue::DequeueBroadcastMessage()
{
    // Check if queue empty.
    if (m_broadcast_messages_queue.empty())
        return {};

    BroadcastMessage message(m_broadcast_messages_queue.top());
    m_broadcast_messages_queue.pop();
    m_last_dequeued_message = message;

    //Trace::GetLogger().STAMP(Trace::VERBOSE) << "Dequeue message id  / priority : "
    //    << m_last_dequeued_message->id << " / " << m_last_dequeued_message->priority << Trace::EndLog();

    return message;
}

void BroadcastMessageQueue::ClearQueue()
{
    Trace::GetLogger().STAMP(Trace::VERBOSE) << " Queue is Cleared " << Trace::EndLog();

    BroadcastMessage message(m_broadcast_messages_queue.top());

    while (!m_broadcast_messages_queue.empty()) 
    {
        m_broadcast_messages_queue.pop(); 
    }
}

void BroadcastMessageQueue::ResetLastDequeuedMessage()
{
    m_last_dequeued_message.reset();
}

std::optional<BroadcastMessage> BroadcastMessageQueue::GetLastDequeueBroadcastMessage()
{
    return m_last_dequeued_message;
}
