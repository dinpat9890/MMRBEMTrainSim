// @file       SCC declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "SCC.h"

namespace PIS
{
    namespace Interface
    {
        void SCC::Executer(const Message& message, const std::shared_ptr<MessageController> controller)
        {
            const auto button_state = message.GetButtonState();

            const auto is_ongoing_active = controller->IsCallActive();
            const auto is_active_cab = controller->IsActiveCall(MessageType::IC_CAB);
            const auto is_active_ohp = controller->IsActiveCall(MessageType::IC_OHP);


            if (button_state == ButtonState::PRESSED)
            {
                if (is_ongoing_active && is_active_cab)
                {
                    // JoinCall : Join current ongoing awaiting call as a participant
                    controller->JoinCall(message);
                }
                if (is_ongoing_active && is_active_ohp)
                {
                    // AddCall : Add incoming call in waiting 
                    controller->AddCall(message);
                }
                else if (!is_ongoing_active)
                {
                    // MakeCall : No ongoing active call 
                    controller->MakeCall(message);
                }
            }
        }
    }
}
