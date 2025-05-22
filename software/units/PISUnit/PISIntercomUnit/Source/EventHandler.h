// @file       EventHandler declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#pragma once

#include "ICommand.h"

using namespace PIS::Intercom;
using namespace PIS::Interface;
using namespace PIS::Announcement;

namespace PIS
{
    namespace Interface
    {
        class EventHandler
        {
        public:
            void RegisterEvent(const MessageType command_type, const std::shared_ptr<ICommand> command);
            void HandleEvent(const Message& message, const std::shared_ptr<MessageController> controller);

        private:
            std::map<MessageType, std::shared_ptr<ICommand>> m_registered_events;
        };
    }
}
