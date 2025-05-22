// @file       OHP declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "OHP.h"

namespace PIS
{
    namespace Interface
    {
        void OHP::Executer(const Message&                           message, const std::shared_ptr<MessageController> controller)
        {
            const auto button_state = message.GetButtonState();

            if (button_state == PIS::Intercom::ButtonState::PRESSED)
            {
                const auto is_ongoing_active = controller->IsCallActive();
                const auto queue_incoming    = controller->IsActiveCall(MessageType::IC_OHP) ||
                                               controller->IsActiveCall(MessageType::IC_CAB) ||
                                               controller->IsActiveCall(MessageType::IC_SCC);

                if (!is_ongoing_active)
                {
                    // If no ongoing is active make this incoming ohp call active and mark it awaiting
                    controller->MakeCall(message);
                }
                if (queue_incoming)
                {
                    // Queue incoming ohp call to OHP Queue 
                    controller->AddCall(message);
                }
            }
        }
    }
}
