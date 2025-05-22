
// @file       CAB declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "Intercom.h"

namespace PIS
{
    namespace Interface
    {
        void CAB::Executer(const Message& message, const std::shared_ptr<MessageController> controller)
        {
            const auto button_state = message.GetButtonState();

            if (button_state == ButtonState::PRESSED)
            {
                const auto is_ongoing_active    = controller->IsCallActive();
                const auto is_active_scc        = controller->IsActiveCall(MessageType::IC_SCC);
                const auto is_active_ohp        = controller->IsActiveCall(MessageType::IC_OHP);
                const auto is_active_cab        = controller->IsActiveCall(MessageType::NONE);

                if (is_ongoing_active && (is_active_scc || is_active_ohp))
                {
                    // ongoing calls OHP or SCC is awating, join this ongoing call as a participant
                    controller->JoinCall(message);
                }
                else if (!is_ongoing_active)
                {
                    // No ongoing active call, make this incoming an active call and mark it awaiting
                    controller->MakeCall(message);
                }
            }
        }
    }
}
