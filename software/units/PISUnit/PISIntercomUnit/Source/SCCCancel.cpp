/// @file
/// @copyright © 2021 Oktal Sydac
/// This is unpublished proprietary source code. The copyright notice above
/// does not evidence any actual or intended publication of such source code.

#include "SCCCancel.h"

namespace PIS
{
    namespace Interface
    {
        void SCCCancel::Executer(const Message& message, const std::shared_ptr<MessageController> controller)
        {
            const auto button_state = message.GetButtonState();

            const auto is_ongoing_active = controller->IsCallActive();
            const auto is_active_cab = controller->IsActiveCall(MessageType::IC_CAB);
            const auto is_active_ohp = controller->IsActiveCall(MessageType::IC_OHP);

            if (button_state == ButtonState::PRESSED)
            {
                auto is_active_scc = controller->IsActiveCall(MessageType::IC_SCC);

                if (is_active_cab || is_active_scc || is_active_ohp)
                {
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "SCCCancel execution command" << Trace::EndLog();
                    // End ongoing active call 
                    controller->EndCall(message);
                }
            }
        }
    }
}
