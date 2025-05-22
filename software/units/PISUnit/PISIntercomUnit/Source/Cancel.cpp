// @file        Cancel declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "Cancel.h"

namespace PIS
{
    namespace Interface
    {
        void Cancel::Executer(const Message& message, const std::shared_ptr<MessageController> controller)
        {
            auto button_state = message.GetButtonState();

            if (button_state == ButtonState::PRESSED)
            {
                const auto is_active_cab_or_scc = controller->IsActiveCall(MessageType::IC_CAB) || controller->IsActiveCall(MessageType::IC_SCC);
                const auto is_active_ohp        = controller->IsActiveCall(MessageType::IC_OHP);
                const auto is_active_ebm        = controller->IsActiveCall(MessageType::IC_EBM);

                const auto is_participant_cab   = controller->IsParticipantActive(MessageType::IC_CAB);
                const auto is_participant_scc   = controller->IsParticipantActive(MessageType::IC_SCC);

                if (is_active_cab_or_scc || is_active_ohp)
                {
                    // Stop ongoing active call or ongoing ohp call
                    controller->EndCall(message);
                }
                else if (is_active_ohp && is_participant_cab)
                {
                    // Stop ongoing OHP active call
                    controller->EndCall(message);
                }
                else if (is_active_ebm)
                {
                    // Stop ongoing Emergency Break leaver active call
                    controller->EndCall(message);
                }
            }
        }
    }
}
