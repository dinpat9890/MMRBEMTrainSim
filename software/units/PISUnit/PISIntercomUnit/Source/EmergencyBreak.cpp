// @file       EmergencyBreak declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#include "EmergencyBreak.h"

namespace PIS
{
    namespace Interface
    {
        void EmergencyBreak::Executer(const Message& message, const std::shared_ptr<MessageController> controller)
        {
            const auto button_state = message.GetButtonState();

            if (button_state == PIS::Intercom::ButtonState::PRESSED)
            {
                const auto is_active_cab_scc_ohp = controller->IsActiveCall(MessageType::IC_CAB) ||
                                                   controller->IsActiveCall(MessageType::IC_SCC) ||
                                                   controller->IsActiveCall(MessageType::IC_OHP);

                const auto is_active_ebm        = controller->IsActiveCall(MessageType::IC_EBM);
                const auto is_ongoing_active    = controller->IsCallActive();

                if (is_active_cab_scc_ohp)
                {
                    // End ongoing active call which is fully connected and have valid initiator & participant
                    controller->EndCall(message);
                    controller->MakeCall(message);
                }
                else if (!is_ongoing_active)
                {
                    // No ongoig active call present, mark this incoming Emergency Break call as an active call and mark is awaiting to join by any participant
                    controller->MakeCall(message);
                }
                else if (is_active_ebm)
                {
                    // Ongoing active call is fully connected, add this incoming call in Emergency Break Queue
                    controller->AddCall(message);
                }
            }
        }
    }
}
