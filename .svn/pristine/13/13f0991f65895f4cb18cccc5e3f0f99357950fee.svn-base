// @file       InPA declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "InPA.h"

namespace PIS
{
    namespace Interface
    {
        void InPA::Executer(const Message& message, const std::shared_ptr<MessageController> controller)
        {
           const auto button_state = message.GetButtonState();

            if (button_state == ButtonState::PRESSED)
            {
                const auto is_ongoing_active = controller->IsCallActive();
                const auto incoming          = controller->IsActiveCall(MessageType::IC_OHP) ||
                                               controller->IsActiveCall(MessageType::IC_CAB) ||
                                               controller->IsActiveCall(MessageType::IC_SCC) ||
                                               controller->IsActiveCall(MessageType::IC_EBM);

                if (is_ongoing_active && incoming)
                {
                    controller->EndCall(message);
                }

                const auto type = message.GetMessageType();
                controller->StartAnnouncement(type);
            }
            else if (button_state == ButtonState::RELEASED)
            {
                const auto type = message.GetMessageType();
                controller->StopAnnouncement(type);
            }
        }
    }
}
