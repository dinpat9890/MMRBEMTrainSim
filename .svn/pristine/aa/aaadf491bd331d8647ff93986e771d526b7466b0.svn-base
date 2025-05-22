// @file       EventHandler declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "EventHandler.h"

void EventHandler::RegisterEvent(const MessageType command_type, const std::shared_ptr<ICommand> command)
{
    //m_registered_events.insert(std::make_pair(command_type, command));
    m_registered_events.emplace(command_type, std::move(command));
}

void EventHandler::HandleEvent(const Message& call_data, const std::shared_ptr<MessageController> controller)
{
    const auto type           = call_data.GetMessageType();
    const auto command_itr    = m_registered_events.find(type);

    if (command_itr != m_registered_events.end())
    {
        auto command = command_itr->second;

        if (command != nullptr)
        {
            command->Executer(call_data, controller);
        }
    }
}
