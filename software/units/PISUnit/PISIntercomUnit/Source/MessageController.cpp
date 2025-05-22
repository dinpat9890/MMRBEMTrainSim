/// @file MessageController.cpp
///
/// @author    Nand Kumar Sharma
///
/// @copyright © SYDAC Pty Ltd, 2020

#include "MessageController.h"

#include "Source/Protobuf/PISProjectAnnouncementProtos.pb.h"
#include <project_comms_structure/ProjectObjectConstants.h>

#include <common/StandardLogging.h>

namespace 
{
    const auto EXPIRE_TIME_IN_SECONDS = 90;
}

namespace PIS
{
    namespace Announcement
    {
        /// Constructor
        ///
        /// @param audio_controller PIS Audio controller that needs to be notified when PA is started/stopped
        /// @param cb               Callback that is to be called when the PA state changes in the audio controller

        MessageController::MessageController(Comms::Gateway&                                gateway,
                                             std::shared_ptr<OutputCommsInterface>          output_object)
            : m_gateway(gateway), m_output_objects(output_object)
        {
            // Current active Announcement object
            m_active_announcement   = std::make_shared<AnnouncementObject>(std::make_shared<PIS::Audio::PublicAnnouncement>(PIS::Announcement::Protos::DRIVER_PUBLIC_ANNOUNCEMENT),
                AnnouncementState::STOPPED);

            m_active_call           = std::make_shared<IntercomInfo>(MessageType::NONE);
        }

        void MessageController::MakeCall(const Message& msg)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto incoming_type = msg.GetMessageType();
            const auto incoming_state = msg.GetMessageState();
            const auto is_ongoing_active = IsCallActive();

            switch (incoming_type)
            {
            case MessageType::IC_CAB:
            {
                // Intercom Button is pressed and no ongoing active call
                auto call = std::make_shared<IntercomInfo>(incoming_type, incoming_state);
                m_active_call = call;

                // RFI raised to mark Comms Intercom Light FLASHING/ON, for now assuming it FLASHING
                m_output_objects->SetIntercomState(IntercomCallState::CALL_REQUEST);
                m_output_objects->SetIntercomLightState(IO::FLASHING);
                m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB);
            }
            break;

            case MessageType::IC_SCC:
            {
                if (!IsQueueEmpty(MessageType::IC_OHP))
                {
                    // Handle the incoming SCC and OHP priority? Based on time of arrival FIFO
                    const auto system_time = m_gateway.GetTiming().GetCurrentSysTime();
                    const auto start_time = std::chrono::milliseconds(static_cast<long long>(system_time * 1000.0));
                    m_awaiting_scc_call.reset(new SCCCallInfo(MessageState::AWAITING, start_time));
                    m_output_objects->SetIntercomState(IntercomCallState::CALL_REQUEST);
                    m_output_objects->SetIntercomLightState(IO::FLASHING);
                    m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB); 
                    
                }
                else
                {
                    auto call = std::make_shared<IntercomInfo>(incoming_type, incoming_state);
                    m_active_call = call;
                    m_output_objects->SetIntercomState(IntercomCallState::CALL_REQUEST);
                    m_output_objects->SetIntercomLightState(IO::FLASHING);
                    //m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB); 
                    m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB_INSTRUCTOR); //Added one more call type when call is initiated from SCC for cab to cab
                }
            }
            break;

            case MessageType::IC_OHP:
            {
                // If queue is empty, process incoming Emergency OHP call
                if (IsQueueEmpty(incoming_type))
                {
                    const auto msg_id = msg.GetMessageID();
                    auto call = std::make_shared<IntercomInfo>(msg_id, incoming_type, incoming_state);
                    m_active_call = call;

                    //auto ohp_output_object = m_output_objects->GetOHPOutputObject(msg_id);
                    auto ohp_output_object = m_output_objects->GetIntercomOHPObject();
                    m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::WAIT_INDICATOR, IO::ON);
                    m_output_objects->SetOHPStatus(ohp_output_object, Status::CALLING);
                    m_output_objects->SetIntercomState(IntercomCallState::CALL_REQUEST);
                    m_output_objects->SetIntercomLightState(IO::FLASHING);
                    m_output_objects->SetOHPChimeState(State::ACTIVE);
                    m_output_objects->SetActiveCallType(ActiveCallType::OHP);

                    auto vehicle_id = msg.GetMessageID().m_vehicle_id;
                    auto ohp_id = msg.GetMessageID().m_ohp_id;
                    int pe_id = (vehicle_id - 1) * 4 + ohp_id;
                    m_output_objects->SetPEId(ohp_output_object, pe_id);
                    m_output_objects->SetVehId(ohp_output_object, vehicle_id);
                    m_output_objects->SetOHPId(ohp_output_object, ohp_id);
                    
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "MakeCall MessageType::IC_OHP, vehicle_id: " << vehicle_id << ", ohp_id: " << ohp_id 
                        << ", pe_id: " << pe_id << Trace::EndLog();
                    
                    // std::string pe_name_str = "PECU_TEST"; 
                    //m_output_objects->SetOHPPEName(ohp_output_object, pe_name_str);

                }
                else
                {
                    // If queue already have waiting calls, enqueue incoming OHP call
                    AddCall(msg);

                    // Process next queued OHP call
                    ProcessNextQueued(MessageType::IC_OHP);
                }
            }
            break;

            case MessageType::IC_EBM:
            {
                // If queue is empty, process Emergency Break Leaver call
                if (m_emergency_break_call_queue.empty())
                {
                    const auto msg_id = msg.GetMessageID();
                    auto call = std::make_shared<IntercomInfo>(msg_id, incoming_type, MessageState::CONNECTED);
                    m_active_call = call;

                   // auto ohp_output_object = m_output_objects->GetOHPOutputObject(msg_id);
                    auto ohp_output_object = m_output_objects->GetIntercomOHPObject();
                    m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::ON);
                    m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::ON);
                    m_output_objects->SetOHPStatus(ohp_output_object, Status::TALKING);
                    m_output_objects->SetIntercomLightState(IO::ON);
                    m_output_objects->SetIntercomState(IntercomCallState::ACTIVE);
                    m_output_objects->SetActiveCallType(ActiveCallType::OHP);

                    const auto active_call_participant = MessageType::IC_SCC;
                    m_active_call->participant = active_call_participant;
                }
                else
                {
                    // If queue already have waiting calls, enqueue incoming Emergency Break call
                    AddCall(msg);

                    // Process next queued Emergency Break call
                    ProcessNextQueued(MessageType::IC_EBM);
                }
            }
            break;
            }
        }

        void PIS::Announcement::MessageController::JoinCall(const Message& msg)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto incoming_type    = msg.GetMessageType();
            const auto incoming_state   = msg.GetMessageState();

            const auto is_active_cab = IsActiveCall(MessageType::IC_CAB);
            const auto is_active_scc = IsActiveCall(MessageType::IC_SCC);
            const auto is_active_ohp = IsActiveCall(MessageType::IC_OHP);

            if (m_active_call != nullptr && m_active_call->state != MessageState::CONNECTED)
            {
                switch (incoming_type)
                {
                case MessageType::IC_CAB:
                    {
                        if (is_active_scc)
                        {
                            const auto active_call_participant  = MessageType::IC_CAB;
                            m_active_call->participant          = active_call_participant;

                            m_output_objects->SetIntercomLightState(IO::ON);
                            m_output_objects->SetIntercomState(IntercomCallState::ACTIVE);
                            m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB);

                            m_active_call->state = MessageState::CONNECTED;
                        }
                        else if (is_active_ohp)
                        {
                            const auto active_call_participant = MessageType::IC_CAB;

                            const auto message_uid = GetActiveCallID();
                           // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_uid);
                            auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                            m_output_objects->SetOHPStatus(ohp_output_object, Status::TALKING);
                            m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::WAIT_INDICATOR, IO::OFF);
                            m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::ON);
                            m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::ON);
                            m_output_objects->SetIntercomLightState(IO::ON);
                            m_output_objects->SetIntercomState(IntercomCallState::ACTIVE);
                            m_output_objects->SetActiveCallType(ActiveCallType::OHP);
                            m_output_objects->SetOHPChimeState(State::INACTIVE);

                            m_active_call->state        = MessageState::CONNECTED;
                            m_active_call->participant  = active_call_participant;
                        }
                    }
                    break;
                case MessageType::IC_SCC:
                    {
                        if (is_active_cab)
                        {
                            const auto active_call_participant = MessageType::IC_SCC;

                            m_output_objects->SetIntercomLightState(IO::ON);
                            m_output_objects->SetIntercomState(IntercomCallState::ACTIVE);
                            //m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB); 
                            m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB_INSTRUCTOR); //Added one more call type when call is initiated from SCC for cab to cab

                            m_active_call->state        = MessageState::CONNECTED;
                            m_active_call->participant  = active_call_participant;
                        }
                    }
                    break;
                }
            }
        }

        void PIS::Announcement::MessageController::EndCall(const Message& msg)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto incoming_type    = msg.GetMessageType();
            const auto incoming_state   = msg.GetMessageState();

            const auto is_active_cab = IsActiveCall(MessageType::IC_CAB);
            const auto is_active_scc = IsActiveCall(MessageType::IC_SCC);
            const auto is_active_ohp = IsActiveCall(MessageType::IC_OHP);
            const auto is_active_ebc = IsActiveCall(MessageType::IC_EBM);

            Trace::GetLogger().STAMP(Trace::VERBOSE) << "is_active_cab: " << is_active_cab
                << ", is_active_scc: " << is_active_scc << ", is_active_ohp: " << is_active_ohp << Trace::EndLog();

            const auto is_participant_none = IsParticipantActive(MessageType::NONE);


            switch (incoming_type)
            {
            case MessageType::IC_CANCEL:
                {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "EndCall ,  IC_CANCEL: " << Trace::EndLog();
                    if ((is_active_cab || is_active_scc) && !is_participant_none)
                    {
                        m_active_call = nullptr;
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);

                        if (!IsQueueEmpty(MessageType::IC_OHP))
                        {
                            ProcessNextQueued(MessageType::IC_OHP);
                        }
                    }
                    else if ((is_active_cab || is_active_scc) && is_participant_none)
                    {
                        m_active_call = nullptr;
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                    }
                    else if (is_active_ohp)
                    {
                        const auto message_uid = GetActiveCallID();
                        m_active_call = nullptr;

                       // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_uid);
                        auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                        m_output_objects->SetOHPStatus(ohp_output_object, Status::NORMAL);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::OFF);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::OFF);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                        m_output_objects->SetOHPChimeState(State::INACTIVE);
                        m_output_objects->SetPEId(ohp_output_object, static_cast<int>(State::INACTIVE));
                        m_output_objects->SetVehId(ohp_output_object, static_cast<int>(State::INACTIVE));
                        m_output_objects->SetOHPId(ohp_output_object, static_cast<int>(State::INACTIVE));

                        if (!IsQueueEmpty(MessageType::IC_OHP))
                        {
                            ProcessNextQueued(MessageType::IC_OHP);
                        }
                    }
                    else if (is_active_ebc)
                    {
                        const auto message_uid = GetActiveCallID();

                        m_active_call          = nullptr;
                       // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_uid);
                        auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::OFF);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::OFF);
                        m_output_objects->SetOHPStatus(ohp_output_object, Status::NORMAL);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);

                        if (!IsQueueEmpty(MessageType::IC_EBM))
                        {
                            ProcessNextQueued(MessageType::IC_EBM);
                        }
                    }
                }
                break;
            case MessageType::IC_SCC_CANCEL:
                {
                Trace::GetLogger().STAMP(Trace::VERBOSE) << "EndCall ,  IC_SCC_CANCEL: " << Trace::EndLog();
                    if ((is_active_cab || is_active_scc) && !is_participant_none)
                    {
                        m_active_call = nullptr;
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                    }
                    else if ((is_active_cab || is_active_scc) && is_participant_none)
                    {
                        m_active_call = nullptr;
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                    }
                    else if (is_active_ohp) // && m_awaiting_scc_call)
                    {
                        m_awaiting_scc_call = nullptr;
                        const auto message_uid = GetActiveCallID();
                        m_active_call = nullptr;

                        // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_uid);
                        auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                        m_output_objects->SetOHPStatus(ohp_output_object, Status::NORMAL);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::OFF);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::OFF);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                        m_output_objects->SetOHPChimeState(State::INACTIVE);
                        m_output_objects->SetPEId(ohp_output_object, static_cast<int>(State::INACTIVE));
                        m_output_objects->SetVehId(ohp_output_object, static_cast<int>(State::INACTIVE));
                        m_output_objects->SetOHPId(ohp_output_object, static_cast<int>(State::INACTIVE));

                        if (!IsQueueEmpty(MessageType::IC_OHP))
                        {
                            ProcessNextQueued(MessageType::IC_OHP);
                        }
                    }
                }
                break;
            case MessageType::IC_EBM:
                {
                    if (is_active_cab || is_active_scc)
                    {
                        m_active_call = nullptr;
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                    }
                    if (is_active_ohp)
                    {
                        const auto message_uid = GetActiveCallID();
                        m_active_call = nullptr;

                       // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_uid);
                        auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                        m_output_objects->SetOHPStatus(ohp_output_object, Status::NORMAL);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::OFF);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::OFF);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                    }
                }
                break;
            case MessageType::PA_IN:
            case MessageType::PA_OUT:
                {
                    if (is_active_cab || is_active_scc)
                    {
                        m_active_call = nullptr;
                    }
                    if (is_active_ohp)
                    {
                        const auto message_uid = GetActiveCallID();
                        m_active_call = nullptr;

                      //  auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_uid);
                        auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                        m_output_objects->SetOHPStatus(ohp_output_object, Status::NORMAL);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::OFF);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::OFF);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                    }
                    else if (is_active_ebc)
                    {
                        const auto message_uid = GetActiveCallID();

                        m_active_call = nullptr;
                       // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_uid);
                        auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::OFF);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::OFF);
                        m_output_objects->SetOHPStatus(ohp_output_object, Status::NORMAL);
                        m_output_objects->SetIntercomLightState(IO::OFF);
                        m_output_objects->SetIntercomState(IntercomCallState::INACTIVE);
                        m_output_objects->SetActiveCallType(ActiveCallType::INACTIVE);
                    }
                }
                break;
            }
        }

        void PIS::Announcement::MessageController::AddCall(const Message& msg)
        {
            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto incoming_type  = msg.GetMessageType();
            const auto incoming_state = msg.GetMessageState();

            switch (incoming_type)
            {
            case MessageType::IC_OHP:
                {
                    // OHP ID
                    const auto msg_id = msg.GetMessageID();
                    const OHPID incoming_ohp_id(msg_id.m_vehicle_id, msg_id.m_ohp_id);

                    const auto timeout = m_gateway.GetTiming().GetCurrentModuleTime() + EXPIRE_TIME_IN_SECONDS;

                    // Create a timer that expires in 90  seconds
                    // If we don't respond to this emergency call beforer expires, we shoud drop it
                    const auto timer_id = m_gateway.ScheduleTimerCallback([&, incoming_ohp_id](double time) { return this->EmergencyOHPCallTimer(incoming_ohp_id); }, timeout);

                    const auto system_time = m_gateway.GetTiming().GetCurrentSysTime();
                    const auto start_time  = std::chrono::milliseconds(static_cast<long long>(system_time * 1000.0));
                    /*Trace::GetLogger().STAMP(Trace::INFO) << " Enqueue Vehicle_ID = " << msg_id.m_vehicle_id << " OHP_ID = " << msg_id.m_ohp_id << " Timer = " << timer_id << Trace::EndLog();*/
                    m_emergency_ohp_call_queue.emplace_back(incoming_ohp_id, timer_id, start_time);

                    // Set OHP Output Objects for Incoming new OHP Request
                    // auto ohp_output_object = m_output_objects->GetOHPOutputObject(msg_id);
                    auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                    m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::WAIT_INDICATOR, IO::ON);
                    m_output_objects->SetOHPStatus(ohp_output_object, Status::CALLING);

                    auto vehicle_id = msg.GetMessageID().m_vehicle_id;
                    auto ohp_id = msg.GetMessageID().m_ohp_id;
                    int pe_id = (vehicle_id) * 4 + ohp_id + 1;
                    m_output_objects->SetPEId(ohp_output_object, pe_id);
                    m_output_objects->SetVehId(ohp_output_object, vehicle_id);
                    m_output_objects->SetOHPId(ohp_output_object, ohp_id);
                    Trace::GetLogger().STAMP(Trace::VERBOSE) << "AddCall MessageType::IC_OHP, vehicle_id: " << vehicle_id << ", ohp_id: " << ohp_id
                        << ", pe_id: " << pe_id << Trace::EndLog();
                }
                break;
            case MessageType::IC_EBM:
                {
                    const auto msg_id = msg.GetMessageID();
                    const OHPID incoming_ohp_id(msg_id.m_vehicle_id, msg_id.m_ohp_id);
                    const auto  incoming_break_leaver_id(msg_id.m_break_leaver_id);

                    auto timeout = m_gateway.GetTiming().GetCurrentModuleTime() + EXPIRE_TIME_IN_SECONDS;

                    // Create a timer that expires in 90  seconds
                    // If we don't respond to this emergency call beforer expires, we shoud drop it
                    const auto timer_id = m_gateway.ScheduleTimerCallback([&, incoming_ohp_id, incoming_break_leaver_id](double time) {
                        return this->EmergencyBreakLeaverCallTimer(incoming_ohp_id, incoming_break_leaver_id);}, timeout);

                    auto emergency_break_call = EBCallInfo(incoming_ohp_id, incoming_break_leaver_id, timer_id);

                    m_emergency_break_call_queue.emplace_back(emergency_break_call);
                }
                break;
            case MessageType::IC_SCC:
                {
                    // Handle the incoming SCC and OHP priority? Based on time of arrival FIFO
                    const auto system_time = m_gateway.GetTiming().GetCurrentSysTime();
                    const auto start_time  = std::chrono::milliseconds(static_cast<long long>(system_time * 1000.0));
                    m_awaiting_scc_call.reset(new SCCCallInfo(MessageState::AWAITING, start_time));
                    m_output_objects->SetIntercomState(IntercomCallState::CALL_REQUEST);
                    m_output_objects->SetIntercomLightState(IO::FLASHING);
                    //m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB); 
                    m_output_objects->SetActiveCallType(ActiveCallType::CAB_TO_CAB_INSTRUCTOR); //Added one more call type when call is initiated from SCC for cab to cab
                }
                break;
            }
        }


        bool MessageController::IsActiveCall(const MessageType msg_type) const
        {
            if (m_active_call != nullptr)
            {
                if (m_active_call->type == msg_type)
                {
                    return true;
                }
            }
            return false;
        }

        bool MessageController::IsCallActive() const
        {
            if (m_active_call != nullptr && !IsActiveCall(MessageType::NONE))
            {
                return true;
            }

            return false;
        }

        bool MessageController::IsParticipantActive(const MessageType msg_type) const
        {
            if (m_active_call != nullptr)
            {
                if (m_active_call->participant == msg_type)
                {
                    return true;
                }
            }
            return false;
        }

        MessageID MessageController::GetActiveCallID() const
        {
            if (m_active_call)
            {
                return m_active_call->initiator;
            }
            else
            {
                return MessageID();
            }
        }

        void PIS::Announcement::MessageController::ProcessNextQueued(const MessageType msg_type)
        {
            switch (msg_type)
            {
            case MessageType::IC_OHP:
                {
                    if (!m_emergency_ohp_call_queue.empty())
                    {
                        auto ohp_id = m_emergency_ohp_call_queue.front();

                        if (m_awaiting_scc_call && (m_awaiting_scc_call->m_clock.GetTime() <= ohp_id.m_clock.GetTime()))
                        {
                            auto call = std::make_shared<IntercomInfo>(MessageType::IC_SCC, m_awaiting_scc_call->m_state);
                            m_active_call = call;
                            m_awaiting_scc_call = nullptr;
                            m_output_objects->SetIntercomState(IntercomCallState::CALL_REQUEST);
                            m_output_objects->SetIntercomLightState(IO::FLASHING);
                            m_output_objects->SetActiveCallType(ActiveCallType::OHP);
                        }
                        else
                        {
                            m_gateway.CancelTimerCallback(ohp_id.m_timer_id);
                            const auto invalid_emergency_break_id = -1;

                            MessageID message_id(ohp_id.m_ohp_id.m_vehicle_id, ohp_id.m_ohp_id.m_ohp_id, invalid_emergency_break_id);
                            auto call = std::make_shared<IntercomInfo>(message_id, msg_type, MessageState::AWAITING);
                            m_active_call = call;

                            m_emergency_ohp_call_queue.pop_front();

                           // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_id);
                            auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                            m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::WAIT_INDICATOR, IO::ON);
                            m_output_objects->SetOHPStatus(ohp_output_object, Status::CALLING);
                            m_output_objects->SetIntercomLightState(IO::FLASHING);
                            m_output_objects->SetIntercomState(IntercomCallState::CALL_REQUEST);
                            m_output_objects->SetOHPChimeState(State::ACTIVE);
                            m_output_objects->SetActiveCallType(ActiveCallType::OHP);
                        }
                    }
                }
                break;
            case MessageType::IC_EBM:
                {
                    if (!m_emergency_break_call_queue.empty())
                    {
                        const auto queued_break_leaver_id = m_emergency_break_call_queue.front();
                        m_gateway.CancelTimerCallback(queued_break_leaver_id.m_timer_id);

                        MessageID message_id(queued_break_leaver_id.m_ohp_id.m_vehicle_id, queued_break_leaver_id.m_ohp_id.m_ohp_id, queued_break_leaver_id.m_ebl_id);
                        auto call = std::make_shared<IntercomInfo>(message_id, msg_type, MessageState::CONNECTED);
                        m_active_call = call;

                        m_emergency_break_call_queue.pop_front();

                        // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_id);
                        auto ohp_output_object = m_output_objects->GetIntercomOHPObject();
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::LISTEN_INDICATOR, IO::ON);
                        m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::SPEAK_INDICATOR, IO::ON);
                        m_output_objects->SetOHPStatus(ohp_output_object, Status::TALKING);
                        m_output_objects->SetIntercomLightState(IO::ON);
                        m_output_objects->SetIntercomState(IntercomCallState::ACTIVE);
                        m_output_objects->SetActiveCallType(ActiveCallType::OHP);

                        const auto active_call_participant = MessageType::IC_SCC;
                        m_active_call->participant = active_call_participant;
                    }
                }
                break;
            }
        }

        bool MessageController::IsQueueEmpty(const MessageType message_type)
        {
            if ((message_type == MessageType::IC_OHP) && m_emergency_ohp_call_queue.empty())
            {
                return true;
            }
            else if (message_type == MessageType::IC_EBM && m_emergency_break_call_queue.empty())
            {
                return true;
            }

            return false;
        }

        /// Notifies Audio controller about the start of a public announcement
        ///

        void MessageController::StartAnnouncement(MessageType an_type)
        {
            // Request AudioController to do the priority management and start PA call
            if (IsActiveType(MessageType::NONE))
            {
                if (an_type == MessageType::PA_IN && !IsMakingAnnouncement())
                {
                    /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::StartAnnouncement, IN_PA starting " << Trace::EndLog();*/
                    m_active_announcement->m_public_announcement    = std::make_shared<PIS::Audio::PublicAnnouncement>(PIS::Announcement::Protos::DRIVER_PUBLIC_ANNOUNCEMENT);
                    m_active_announcement->m_announcement_state     = AnnouncementState::PLAYING;
                    m_active_announcement->m_active_type            = MessageType::PA_IN;

                    this->AnnouncementStarted(m_active_announcement->m_public_announcement);

                }
                else if (an_type == MessageType::PA_OUT && !IsMakingAnnouncement())
                {
                    /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::StartAnnouncement, OUT_PA starting " << Trace::EndLog();*/
                    m_active_announcement->m_public_announcement = std::make_shared<PIS::Audio::PublicAnnouncement>(PIS::Announcement::Protos::DRIVER_PUBLIC_ANNOUNCEMENT);
                    m_active_announcement->m_announcement_state  = AnnouncementState::PLAYING;
                    m_active_announcement->m_active_type         = MessageType::PA_OUT;

                    this->AnnouncementStarted(m_active_announcement->m_public_announcement);
                }
            }
            else
            {
                if (an_type == MessageType::PA_IN && IsActiveType(MessageType::PA_OUT))
                {
                    /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::StartAnnouncement, IN_PA starting " << Trace::EndLog();*/
                    m_output_objects->SetPALightState(PAOutput::PA_IN_LIGHT, IO::ON);
                    m_active_announcement->m_joined_type = MessageType::PA_IN;
                }
                else if (an_type == PIS::Intercom::MessageType::PA_OUT && IsActiveType(MessageType::PA_IN))
                {
                    /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::StartAnnouncement, IN_PA starting " << Trace::EndLog();*/
                    m_output_objects->SetPALightState(PAOutput::PA_OUT_LIGHT, IO::ON);
                    m_active_announcement->m_joined_type = MessageType::PA_OUT;
                }
            }
        }

        /// Notifies Audio controller about the stopping of a public announcement
        ///

        void MessageController::StopAnnouncement(MessageType an_type)
        {
            if (an_type == PIS::Intercom::MessageType::PA_IN)
            {
                if (IsActiveType(MessageType::PA_IN) && IsJoinedType(MessageType::NONE) && IsMakingAnnouncement())
                {
                    /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::StopAnnouncement, IN_PA stoping " << Trace::EndLog();*/
                    AnnouncementStopped(m_active_announcement->m_public_announcement);
                }
                else if (IsActiveType(MessageType::PA_IN) && IsJoinedType(MessageType::PA_OUT) && IsMakingAnnouncement())
                {
                    /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::StopAnnouncement, IN_PA stoping " << Trace::EndLog();*/
                    m_output_objects->SetPALightState(PAOutput::PA_IN_LIGHT, IO::OFF);
                    m_active_announcement->m_active_type = MessageType::PA_OUT;
                    m_active_announcement->m_joined_type = MessageType::NONE;
                }
                else if (IsActiveType(MessageType::PA_OUT) && IsJoinedType(MessageType::PA_IN) && IsMakingAnnouncement())
                {
                    m_output_objects->SetPALightState(PAOutput::PA_IN_LIGHT, IO::OFF);
                    m_active_announcement->m_joined_type = MessageType::NONE;
                }
            }
            else if (an_type == PIS::Intercom::MessageType::PA_OUT)
            {
                if (IsActiveType(MessageType::PA_OUT) && IsJoinedType(MessageType::NONE) && IsMakingAnnouncement())
                {
                    /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::StopAnnouncement, OUT_PA stoping " << Trace::EndLog();*/
                    AnnouncementStopped(m_active_announcement->m_public_announcement);
                }
                else if (IsActiveType(MessageType::PA_OUT) && IsJoinedType(MessageType::PA_IN) && IsMakingAnnouncement())
                {
                    m_output_objects->SetPALightState(PAOutput::PA_OUT_LIGHT, IO::OFF);
                    m_active_announcement->m_active_type = MessageType::PA_IN;
                    m_active_announcement->m_joined_type = MessageType::NONE;
                }
                else if (IsActiveType(MessageType::PA_IN) && IsJoinedType(MessageType::PA_OUT) && IsMakingAnnouncement())
                {
                    m_output_objects->SetPALightState(PAOutput::PA_OUT_LIGHT, IO::OFF);
                    m_active_announcement->m_joined_type = MessageType::NONE;
                }
            }
        }

        /// Notifies Returns true if Audio controller is making a public announcement
        ///

        bool MessageController::IsMakingAnnouncement() const
        {
            if (m_active_announcement->m_announcement_state == AnnouncementState::PLAYING)
            {
                /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::IsMakingAnnouncement " << Trace::EndLog();*/
                return true;
            }

            return false;
        }

        /// Notifies Returns true if active Public Announcement is of specific type
        ///
        bool MessageController::IsActiveType(const MessageType type) const
        {
            if (m_active_announcement->m_active_type == type)
            {
                return true;
            }

            return false;
        }

        /// Notifies Returns true if participant of Public Announcement is of specific type
        ///

        bool MessageController::IsJoinedType(const MessageType type) const
        {
            if (m_active_announcement->m_joined_type == type)
            {
                return true;
            }

            return false;
        }

        /// Notifies Returns true if active Public Announcement is of specific type object
        ///

        bool MessageController::IsActiveAnnouncement(const Announcement & announcement) const
        {
            if (announcement == m_active_announcement->m_public_announcement)
                return true;

            return false;
        }

        /// Notifies Returns IntercomOutput object which do all comms output operations
        ///

        std::shared_ptr<OutputCommsInterface> MessageController::GetIntercomOutput() const
        {
            return m_output_objects;
        }

        /// Callback that is called when audio controller starts making a public announcement
        ///
        /// @param announcement Public Announcement being made

        void MessageController::AnnouncementStarted(const Announcement& announcement)
        {
            if (IsActiveAnnouncement(announcement))
            {
                Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::AnnouncementStarted " << Trace::EndLog();

                const auto is_intercom_active = IsActiveCall(MessageType::IC_CAB) || IsActiveCall(MessageType::IC_SCC) || IsActiveCall(MessageType::IC_OHP) || IsActiveCall(MessageType::IC_EBM);

                if (IsActiveType(MessageType::PA_IN))
                {
                    m_output_objects->SetPALightState(PAOutput::PA_IN_LIGHT, IO::ON);
                    m_output_objects->SetPAState(IO::ON);
                }
                else if (IsActiveType(MessageType::PA_OUT))
                {
                    m_output_objects->SetPALightState(PAOutput::PA_OUT_LIGHT, IO::ON);
                    m_output_objects->SetPAState(IO::ON);
                }

                m_active_announcement->m_announcement_state = AnnouncementState::PLAYING;
            }
        }

        /// Callback that is called when audio controller pauses the current public announcement
        ///
        /// @param announcement Public Announcement being made

        void MessageController::AnnouncementPaused(const Announcement& announcement)
        {
            if (IsActiveAnnouncement(announcement))
            {
                /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::AnnouncementPaused " << Trace::EndLog();*/
                // TODO: If any action required?
                m_active_announcement->m_announcement_state = AnnouncementState::PAUSED;
            }
        }

        /// Callback that is called when audio controller stops the current IN public announcement
        /// Note that currently the audio controller fails to call this callback and so the 
        /// callback should be called after sending the Stop request to the audio controller
        ///
        /// @param announcement Public Announcement being made

        void MessageController::AnnouncementStopped(const Announcement& announcement)
        {
            if (IsActiveAnnouncement(announcement))
            {
                /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::AnnouncementStopped " << Trace::EndLog();*/

                if (IsActiveType(MessageType::PA_IN))
                {
                    m_output_objects->SetPALightState(PAOutput::PA_IN_LIGHT, IO::OFF);
                    m_output_objects->SetPAState(IO::OFF);

                }
                else if (IsActiveType(MessageType::PA_OUT))
                {
                    m_output_objects->SetPALightState(PAOutput::PA_OUT_LIGHT, IO::OFF);
                    m_output_objects->SetPAState(IO::OFF);

                }
                m_active_announcement->m_announcement_state = AnnouncementState::STOPPED;
                m_active_announcement->m_active_type = MessageType::NONE;
            }
        }

        /// Callback that is called when audio controller aborts the current public announcement
        ///
        /// @param announcement Public Announcement being made

        void MessageController::AnnouncementAborted(const Announcement& announcement)
        {
            if (IsActiveAnnouncement(announcement))
            {
                /*Trace::GetLogger().STAMP(Trace::INFO) << " MessageController::AnnouncementAborted " << Trace::EndLog();*/
                // TODO: If any action required?
                m_active_announcement->m_announcement_state = AnnouncementState::ABORTED;
            }
        }

        double MessageController::EmergencyOHPCallTimer(OHPID ohp_id)
        {
            // We need a lock to access the root object
            OS::Lock<Comms::Gateway> gateway_lock(m_gateway);

            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto initiated_by_this_ohp = [ohp_id](const OHPCallInfo call) { return call.m_ohp_id == ohp_id && call.m_state != MessageState::CONNECTED; };

            const auto iterator = std::find_if(m_emergency_ohp_call_queue.begin(), m_emergency_ohp_call_queue.end(), initiated_by_this_ohp);

            if (iterator != m_emergency_ohp_call_queue.end())
            {
                iterator->m_timer_id = Comms::SessionOperations::TimerID::Invalid();

                // Disable all enabled features of a OHP 
                const auto local_ohp_uid = iterator->m_ohp_id;
                m_emergency_ohp_call_queue.erase(iterator);

                const auto message_uid = MessageID(local_ohp_uid.m_vehicle_id, local_ohp_uid.m_ohp_id);
                /*Trace::GetLogger().STAMP(Trace::INFO) << " Dropped Queue CALL Vehicle_ID = " << local_ohp_uid.m_vehicle_id << " OHP_ID = " << local_ohp_uid.m_ohp_id << Trace::EndLog();*/

               // auto ohp_output_object = m_output_objects->GetOHPOutputObject(message_uid);
                auto ohp_output_object = m_output_objects->GetIntercomOHPObject();

                m_output_objects->SetOHPIndicatorState(ohp_output_object, OHPOutputs::WAIT_INDICATOR, IO::OFF);
                m_output_objects->SetOHPStatus(ohp_output_object, Status::NORMAL);
                m_output_objects->SetOHPChimeState(State::INACTIVE);
            }
            // FIXME:
            //  Comms::SessionOperations::CANCEL_TIMER causes an infinite loop
            //  std::numeric_limits<double>::max() seems to work fine
            //
            // return Comms::SessionOperations::CANCEL_TIMER;
            return std::numeric_limits<double>::max();
        }

        double  MessageController::EmergencyBreakLeaverCallTimer(OHPID ohp_id, int break_leaver_id)
        {

            // We need a lock to access the root object
            OS::Lock<Comms::Gateway> gateway_lock(m_gateway);

            const std::lock_guard<std::recursive_mutex> lock(m_mutex);

            const auto initiated_by_this_ebl = [ohp_id, break_leaver_id](const EBCallInfo call)
            { return call.m_ohp_id == ohp_id && call.m_ebl_id == break_leaver_id && call.m_state != MessageState::CONNECTED; };

            const auto iterator = std::find_if(m_emergency_break_call_queue.begin(), m_emergency_break_call_queue.end(), initiated_by_this_ebl);
            if (iterator != m_emergency_break_call_queue.end())
            {
                iterator->m_timer_id = Comms::SessionOperations::TimerID::Invalid();
                m_emergency_break_call_queue.erase(iterator);
            }
            return std::numeric_limits<double>::max();
        }
    }
}
