/// @file       MessageController declaration
///
/// @author     Nand Kumar Sharma
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020

#ifndef  MESSAGE_CONTROLLER_H
#define  MESSAGE_CONTROLLER_H

#include "PublicAnnouncement.h"

#include "InputCommsInterface.h"
#include "ConstantDefined.h"
#include "OutputCommsInterface.h"
#include "Clock.h"

#include <map>
#include <functional>
#include <memory>

using namespace PIS::Intercom;

namespace PIS
{
    namespace Announcement
    {
        /// Enumeration of the different announcement states that the PA Message Controller can be in
        ///
        enum class AnnouncementState
        {
            PLAYING,
            PAUSED,
            STOPPED,
            ABORTED
        };

        struct AnnouncementObject
        {
            std::shared_ptr<PIS::Audio::PublicAnnouncement> m_public_announcement;
            AnnouncementState                               m_announcement_state; 
            MessageType                                     m_active_type;
            MessageType                                     m_joined_type;

            AnnouncementObject( std::shared_ptr<PIS::Audio::PublicAnnouncement> public_announcement, AnnouncementState announcement_state)
                : m_public_announcement(public_announcement), m_announcement_state(announcement_state), m_active_type(MessageType::NONE), m_joined_type(MessageType::NONE)
            {}
        };

        /// Class for notifying an Audio controller about the starting and stopping of public announcements and Intercom Request
        ///
        class MessageController
        {
        public:
            using Announcement = std::shared_ptr<PIS::Audio::PublicAnnouncement>;
            MessageController(Comms::Gateway&                                       gateway, 
                              std::shared_ptr<PIS::Intercom::OutputCommsInterface>  output_object);

            //  MakeCall : Trigger new intercom call 
            //
            void MakeCall(const Message& msg);

            // JoinCall : Joins a intercom call already triggered by other
            //
            void JoinCall(const Message& msg);

            // EndCall : End current ongoing call
            //
            void EndCall(const Message& msg);

            // EndCall : End current ongoing call
            //
            void AddCall(const Message& msg);

            // IsActiveCall : Verify if current active call is of specific type
            //
            bool IsActiveCall(const MessageType msg_type) const;

            // IsActiveCall : Verify if current active call is of specific type
            //
            bool IsCallActive() const;

            // IsParticipant: Verify if participant of active call is of specific type
            //
            bool IsParticipantActive(const MessageType msg_type) const;

            // StartAnnouncement :  Starts specific message type announcement
            //
            void StartAnnouncement(MessageType an_type);

            // StopAnnouncement :  Stops ongoing announcement
            //
            void StopAnnouncement(MessageType an_type);

            // Get IntecomOutput Object
            std::shared_ptr<PIS::Intercom::OutputCommsInterface> GetIntercomOutput() const;

        private:

            // IntercomInfo :: Keep active intercom call information
            struct IntercomInfo
            {
                IntercomInfo(const MessageType     type,
                             const MessageState    state = MessageState::AWAITING)
                    : initiator(-1,-1,-1), participant(MessageType::NONE), state(state), type(type)
                {
                }

                IntercomInfo(const MessageID        initiator,
                             const MessageType      type,
                             const MessageState     state = MessageState::AWAITING)
                    : initiator(initiator), participant(MessageType::NONE), state(state), type(type)
                {
               
                }

                MessageID     initiator;       // Initiator of Call
                MessageType   participant;     // Participant of Call
                MessageType   type;            // Type of incoming Call
                MessageState  state;           // State 
            };

            // Emergency OHP Call Information
            struct OHPCallInfo
            {
                OHPCallInfo(const OHPID ohp_id, const Comms::SessionOperations::TimerID timer_id, const Clock start_time)
                    : m_ohp_id(ohp_id), m_timer_id(timer_id), m_clock(start_time), m_state(MessageState::AWAITING)
                {  }

                OHPID                               m_ohp_id;       // OHP ID
                MessageState                        m_state;        // State
                Comms::SessionOperations::TimerID   m_timer_id;     // Timer ID
                Clock                               m_clock;        // Message initiation time
            };

            // Emergency Break leaver Call Information
            struct EBCallInfo
            {
                EBCallInfo(const OHPID ohp_id, const int emergency_break_id, Comms::SessionOperations::TimerID timer_id)
                    : m_ohp_id(ohp_id), m_ebl_id(emergency_break_id), m_timer_id(timer_id), m_state(MessageState::AWAITING)
                {  }

                OHPID                               m_ohp_id;     // OHP ID
                int                                 m_ebl_id;     // Emergency Break Leaver ID
                MessageState                        m_state;      // State
                Comms::SessionOperations::TimerID   m_timer_id;   // Timer ID
            };

            // SCC Intercom Call Information
            struct SCCCallInfo {
                SCCCallInfo(const MessageState message_state, const Clock start_time)
                    : m_state(message_state), m_clock(start_time)
                {  }
                MessageState                m_state;        // State
                Clock                       m_clock;        // Message initiation time
            };

            // IN/OUT Public Announcement callbacks registered with  Audio Controller
            void AnnouncementStarted(const Announcement& announcement);
            void AnnouncementPaused(const Announcement&  announcement);
            void AnnouncementStopped(const Announcement& announcement);
            void AnnouncementAborted(const Announcement& announcement);

            // Callback functions for Emergency OHP & Break Leaver calls
            double EmergencyOHPCallTimer(OHPID ohp_id);
            double EmergencyBreakLeaverCallTimer(OHPID ohp_id, int break_leaver_id);

            // Get initiator MessageID
            MessageID GetActiveCallID() const;

            //  Process next item present in queue
            void ProcessNextQueued(const MessageType msg_type);

            // Is queue empty
            bool IsQueueEmpty(const MessageType message_type);

            // IsMakingAnnouncement :  Verify if current announcement is playing
            //
            bool IsMakingAnnouncement() const;

            // IsActiveType :  Verify if active announcement is of requested type
            //
            bool IsActiveType(const MessageType type) const;

            // IsJoinedType :  Verify if joinee of ongoing announcement is of requested type
            //
            bool IsJoinedType(const MessageType type) const;

            // IsActiveAnnouncement :  Verify if active announcement is of requested type
            //
            bool IsActiveAnnouncement(const Announcement& announcement) const;

            std::recursive_mutex                                    m_mutex;
            
            Comms::Gateway&                                         m_gateway;                      // Comms Gateway

            std::shared_ptr<PIS::Intercom::OutputCommsInterface>    m_output_objects;               // Output Comms Interface Object

            std::shared_ptr<AnnouncementObject>                     m_active_announcement;          // Active Announcement Object
            std::shared_ptr<IntercomInfo>                           m_active_call;                  // Active Intercom Object
            

            std::deque<OHPCallInfo>                                 m_emergency_ohp_call_queue;     // Queue for OHP Calls
            std::deque<EBCallInfo>                                  m_emergency_break_call_queue;   // Queue for Emergency Break Calls
            std::unique_ptr<SCCCallInfo>                            m_awaiting_scc_call;            // SCC Call awaiting during OHP Calls ongoing.
        };

    } // namespace Announcement
} // namespace Intercom

#endif // ! MESSAGE_CONTROLLER_H
