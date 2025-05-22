///
///  @file      GenIIIClient.h
///
///             Client for the CKAS controller using the GenIII protocol.
///             Parses the responses sent by the controller and determines the
///             commands to send.  Handles formatting the commands as strings.
///
/// @ingroup    KSRTC Simulator
///
/// @author     Peter Byrne
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2018
///

#ifndef GENIIICLIENT_H
#define GENIIICLIENT_H

#include "MotionBaseController.h"
#include "MotionBaseParameters.h"
#include "DataConnection.h"
#include "common/OSClasses.h"
#include "common/OSThreadClasses.h"
#include "common/Utilities.h"
#include <queue>
#include <string>
#include <atomic>
#include <memory>


namespace ckas_interface
{
    // Forward declarations of classes referred to in this interface
    class gen3_command;
    class gen3_response;
    class MotionBaseJournal;

    class gen_3_client : public MotionBaseController
    {
    public:

        gen_3_client(const Project::MotionBaseProperties &properties, std::unique_ptr<DataConnection> connection);
        ~gen_3_client();

        /// Add a command from the profile (i.e. from the INI file) to the 
        /// transmit queue.
        void                add_profile_command(const std::string &command);
    
        void                start(const Project::MotionBaseProperties &properties) override;

        void                set_session_state(MotionBase::SessionState state) override;
    
        void                set_motion_parameters(const MotionBase::Parameters &parameters) override;

        void                set_apply_motion(bool motion_active) override;

    private:
        /// Worker process for the transmit thread.
        OS::ThreadReturnType                transmit_commands();
        void                                transmit_commands_impl();

        /// Worker process for the receiver thread
        OS::ThreadReturnType                receive_responses();
        void                                receive_responses_impl();

        /// Either take a command from the waiting command queue or send a move 
        /// command using the current parameters.
        std::unique_ptr<gen3_command>       determine_next_command();

        /// Parse the response string from the CKAS and check if it reports an error.
        void                                process_response(const std::string &response);

        /// Empty the waiting command queue and add a park platform command to the queue.
        void                                park_platform_due_to_error();

        /// Determine if the client is allowed to transmit commands to the CKAS
        bool                                transmission_permitted() const;

        /// Connection to the CKAS controller
        std::unique_ptr<DataConnection>     m_connection;

        /// Threads for handling the transmit and receive channels.
        std::unique_ptr<OS::Thread>         m_transmitThread;
        std::unique_ptr<OS::Thread>         m_receiveThread;

        /// Signal for killing the transmit and receive threads.
        OS::Signaller                       m_thread_kill_signal;
        
        /// Timer to run the transmit thread at about 100Hz
        OS::Timer                           m_transmit_timer;
        
        typedef std::queue<std::unique_ptr<gen3_command>> CommandQueue;

        /// Buffer of commands to transmit. If this queue is empty, we transmit a "move" command
        /// using the latest parameters.
        CommandQueue                        m_waiting_commands;

        /// Latest motion parameters from the model
        MotionBase::Parameters              m_motion_parameters;

        /// Flag when we receive an error response to stop transmitting 
        bool                                m_error_detected;

        /// Control access to the command queue, the motion parameters and the error detected flag.
        OS::CriticalSection                 m_client_lock;

        /// Simplified version of the Comms session state
        ///
        /// @remarks Although this gets set on a different thread than it's read from, is it overkill
        ///          to make this atomic?
        MotionBase::SessionState            m_session_state;
        
        /// Value of the "apply motion" parameter from the model.
        ///
        /// @remarks Although this gets set on a different thread than it's read from, is it overkill
        ///          to make this atomic?
        bool                                m_apply_motion;

        /// Logging all the interactions with the CKAS 
        std::unique_ptr<MotionBaseJournal>  m_journal;
    };

}

#endif // UDP_CLIENT_H