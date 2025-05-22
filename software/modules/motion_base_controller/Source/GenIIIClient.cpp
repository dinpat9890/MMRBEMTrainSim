///
///  @file      GenIIIClient.cpp
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

#include "GenIIIClient.h"
#include "GenIIICommands.h"
#include "GenIIIResponses.h"
#include "MotionBaseParameters.h"
#include "MotionBaseProperties.h"
#include "MotionBaseExceptions.h"
#include "MotionBaseJournal.h"

#include "common/LexicalCast.h"
#include "common/StandardLogging.h"
#include <cassert>

#include <utility>
#include <cmath>

namespace ckas_interface
{   
    namespace
    {
        /// Sane default limits for the Hardware polling rate
        const double        MAX_POLL_RATE_HZ    = 100.0;
        const double        MIN_POLL_RATE_HZ    = 1.0;

        /// Retry period for connecting
        const double        CONNECT_RETRY_PERIOD_SECONDS = 1.0;

        /// Constant for when we're working with nanoseconds
        const double        ONE_BILLION         = std::pow(10.0, 9);
        
        
        /// Format the states as strings for logging.
        std::string session_state_to_string(MotionBase::SessionState state)
        {
            switch(state) 
            {
            case MotionBase::SessionState::Unknown:
                return "Unknown";
            
            case MotionBase::SessionState::Paused:
                return "Paused";

            case MotionBase::SessionState::Running:
                return "Running";
            
            case MotionBase::SessionState::Default:
                return "Default";
            
            default:
                // We shouldn't reach this, throw?
                return "unknown?";
            }
        }
    }

    /// Create the journal
    gen_3_client::gen_3_client(const Project::MotionBaseProperties &properties, std::unique_ptr<DataConnection> connection)
        : m_apply_motion(false),
          m_error_detected(false),
          m_connection(std::move(connection))
    {
        if(properties.IsJournalEnabled())
            m_journal.reset(new MotionBaseJournal());
        
        auto transmit_rate = properties.GetPollingRate();
        if (transmit_rate < MIN_POLL_RATE_HZ)
        {
            Trace::GetLogger().STAMP(Trace::WARN) 
                << "Requested transmit rate of " << transmit_rate 
                << "Hz raised to " << MIN_POLL_RATE_HZ << "Hz" 
                << Trace::EndLog();

            transmit_rate = MIN_POLL_RATE_HZ;
        }
        else if (transmit_rate > MAX_POLL_RATE_HZ)
        {
            Trace::GetLogger().STAMP(Trace::WARN) 
                << "Requested transmit rate of " << transmit_rate 
                << "Hz lowered to " << MAX_POLL_RATE_HZ << "Hz" 
                << Trace::EndLog();

            transmit_rate = MAX_POLL_RATE_HZ;
        }
        
        auto transmit_interval = 1.0 / transmit_rate;
        
        OS::OSTime  transmit_period;
        transmit_period.seconds = static_cast<int>(transmit_interval);        
        transmit_period.nano_seconds = static_cast<int>(
            (transmit_interval  - transmit_period.seconds) * ONE_BILLION);

        m_transmit_timer.Set(transmit_period, true, transmit_period);

        // Start the tx / rx threads - The transmit thread will manage the communication port.
        m_transmitThread.reset(new OS::Thread(
            std::bind(&gen_3_client::transmit_commands, this),
            "GenIII_Transmit"));
        m_receiveThread.reset(new OS::Thread(
            std::bind(&gen_3_client::receive_responses, this),
            "GenIII_Receive"));
    }

    /// Send the kill signal to the threads, close the connection and the journal.
    gen_3_client::~gen_3_client()
    {
        try 
        {
            m_thread_kill_signal.Signal();
            m_transmitThread->Join();
            m_receiveThread->Join();
            m_connection->Close();
            m_transmit_timer.Cancel();
            m_journal.release();
        }
        catch(CommonException &e)
        {
            e.AddStackTrace(FLSTAMP, "GenIIIClient destructor.");
            Trace::GetLogger().LogException(e);
        }
        catch(std::exception &e)
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "GenIIIClient destructor - " << e.what() << Trace::EndLog();
        }
    }

    /// Start the transmit / receive threads, send the "profile" commands.
    void gen_3_client::start(const Project::MotionBaseProperties &properties)
    {
        if (! m_connection->IsOpen())
        {
            try 
            {
                Trace::GetLogger().STAMP(Trace::INFO) << "Connect to CKAS" << Trace::EndLog();

                m_connection->Open();
            }
            catch(SocketException &e)
            {
                e.AddStackTrace(FLSTAMP, "Opening socket while trying to connect to Motion Base.");
                Trace::GetLogger().LogException(e);
            }
        }

        // Read the setup commands from the profile.
        for (auto command: properties.GetProfileCommands())
        {
            add_profile_command(command);
        }
    }
    
    
    /// Accept the latest motion base parameters from Comms.
    void gen_3_client::set_motion_parameters(const MotionBase::Parameters &parameters) 
    {
        if (parameters.IsValid())
        {
            const OS::SectionLock LOCK(m_client_lock);  
            m_motion_parameters = parameters;
        }
        else
        {
            Trace::GetLogger().STAMP(Trace::ERR) << "Invalid motion base parameters have been rejected." << Trace::EndLog();
        }
    }

    

    void gen_3_client::add_profile_command(const std::string &command) 
    {
        const OS::SectionLock LOCK(m_client_lock);
        
        m_waiting_commands.push(profile_command::create(command));
    }

    
    void gen_3_client::set_session_state(MotionBase::SessionState state)
    {
        if (m_session_state != state)
        {
            Trace::GetLogger().STAMP(Trace::INFO) 
                << "gen_3_client: session state changed to " << session_state_to_string(state) 
                << Trace::EndLog();

            if(m_journal)
                m_journal->mark_point_of_interest("Session state = " + session_state_to_string(state));

            m_session_state = state;
        }
    }


    void gen_3_client::set_apply_motion(const bool motion_active)
    {
        if (motion_active != m_apply_motion)
        {
            Trace::GetLogger().STAMP(Trace::INFO)
                << (motion_active ? "Start" : "Stop") << " applying motion." 
                << Trace::EndLog();

            m_apply_motion = motion_active;
        }
    }

    bool gen_3_client::transmission_permitted() const
    {
        auto is_active = m_apply_motion;
        auto session_state = m_session_state;
        
        return is_active && 
               (session_state == MotionBase::SessionState::Paused || 
                session_state == MotionBase::SessionState::Running);
    }
    
    /// Worker process for the transmit thread
    OS::ThreadReturnType    gen_3_client::transmit_commands()
    {
        Trace::GetLogger().STAMP(Trace::INFO) << "MotionBaseController: Transmitter thread started" << Trace::EndLog();
        
        try 
        {
            transmit_commands_impl();
        }
        catch(SocketException &e)
        {
            // We can't safely keep trying to use
            // the socket without reopening it...
            e.AddStackTrace(FLSTAMP, "In transmit thread.");
            Trace::GetLogger().LogException(e);
        }
        catch(CommonException &e)
        {
            // These are more general exceptions, showing
            // faults in the use of the UDPClient.
            e.AddStackTrace(FLSTAMP, "In transmit thread.");
            Trace::GetLogger().LogException(e);
        }

        // Get out and end the thread when the kill signal is received.
        m_connection->Close();

        Trace::GetLogger().STAMP(Trace::INFO) << "MotionBaseController: Transmit thread killed" << Trace::EndLog();

        return OS::CastToReturnType(0UL);
    }

    
    ///
    /// Most of the method runs in an infinite loop controlled by a timer and kill signal.  The loop
    /// includes logic to open (and reopen) the connection.
    void                    gen_3_client::transmit_commands_impl()
    {
        // The loop will be controlled by two events: a timer and a kill signal. The timer throttles
        // the rate that we send events and the kill signal ends the whole process.

        /// The Event Handles. 0 = Kill Event and 1 = the Polling Timer
        std::vector<OS::OSHandle> events; 
        events.push_back(m_thread_kill_signal.GetEvent().handle);
        events.push_back(m_transmit_timer.handle);

        const int timer_event_index = 1;
        
        // Keep track of the state changes between active / inactive
        bool currently_sending = false;

        // Track the last time we tried to open the connection to throttle how often we call Open().
        auto time_last_connect_retry = OS::GetCounter();

        //
        // Now we can start the main processing loop; this is an infinite loop that we only exit
        // when either we get the kill signal, or we got an error when transmitting
        //

        while (true)
        {
            // Wait for either the timer or kill signal events
            const int wait_result = OS::WaitForMultipleObjects(events, OS::INFINITE);

            // If we got the timer event, we keep processing, but for any other result we exit this loop
            if (wait_result != timer_event_index)
            {
                Trace::GetLogger().STAMP(Trace::INFO) << "Transmit thread: wait_result=" << wait_result << ", exit" << Trace::EndLog();
                break;
            }

            //
            // The following block of comments were present in the original code that this method
            // borrowed (it was formerly in MotionBaseController.cpp). I don't know whether the
            // points that they mention here still applies to the current motion base architecture.
            // In particular, the remarks about connecting to a separate PC that's running SimComm;
            // I don't believe that this is the way that the UDP communication works, I was under
            // the understanding that the CKAS controller itself was connected to the network and
            // presents a UDP connection point.  I leave these comments below in case there is a
            // point here that is relevant to some environment that we work in.
            //      -- PCB
            //

            // If we aren't connected, we need to connect Attempt at the defined rate. This code was
            // borrowed from the PPP Motionbase and may not be the best way of going about managing a
            // UDP port. We are not connecting to the actual hardware here. We connect to a PC
            // running the SimComm application. SimComm communicates with the Hardware via USB. This
            // is a uni-directional connection - We have no way of even knowing if the hardware is
            // turned on, misbehaving etc. This application relies on the Instructor monitoring any
            // use of the motion base and hitting the Kill switch if a problem arises.
            //
            // TODO - See what happens when SimComm is down or if the IP address/Com Port is incorrect

            if (!m_connection->IsOpen())
            {
                // If the socket isn't open, try to open it. This will hopefully recover from any
                // transient socket errors, but will also allow us to connect to the motion base as
                // soon we are able to communicate with it. On the real hardware the IP address does
                // not exist when it isn't on, so opening the socket will throw an exception. We
                // don't want this to happen on construction of this class, so we do this
                // periodically and catch these exceptions.
                if (OS::CalculateTimeDifference(time_last_connect_retry, OS::GetCounter()) > CONNECT_RETRY_PERIOD_SECONDS)
                {
                    try
                    {
                        time_last_connect_retry = OS::GetCounter();
                        Trace::GetLogger().STAMP(Trace::INFO) << "Transmit thread: Try to connect to CKAS" << Trace::EndLog();

                        m_connection->Open();
                    }
                    catch(SocketException &e)
                    {
                        e.AddStackTrace(FLSTAMP, "Connecting to CKAS.");
                        Trace::GetLogger().LogException(e);
                    }
                }
                
                // If we're still not connected, we can stop this iteration of
                // the loop now and just retry again on a later cycle
                if (!m_connection->IsOpen())
                {
                    continue;
                }
            }

            //
            // Check the client is active before we start sending data, and log
            // the state changes to/from active when they happen
            //

            if (transmission_permitted())
            {
                if (!currently_sending)
                {
                    Trace::GetLogger().STAMP(Trace::INFO) << "Transmit thread : start sending" << Trace::EndLog();                
                    currently_sending = true;
                }
            }
            else
            {
                if (currently_sending)
                {
                    Trace::GetLogger().STAMP(Trace::INFO) << "Transmit thread : stop sending" << Trace::EndLog();
                    currently_sending = false;
                }

                // Client isn't active, end this iteration now.
                continue; 
            }

            //
            // So now we are active and we have an open connection, it's time to 
            // try transmitting the next command
            // 

            auto next_command = determine_next_command();
            auto string_for_command = next_command->format_for_transmission();

            // Note the different implementations of DataConnection each report errors differently:
            // 
            // * SerialDeviceConnection returns false;
            // * UdpSocketClientConnection throws exceptions.
            //

            bool send_ok = m_connection->Send(string_for_command);

            if(m_journal)
                m_journal->add(std::move(next_command));

            if (!send_ok) 
            {
                // On any error from sending we break out of the loop and end the thread.
                Trace::GetLogger().STAMP(Trace::ERR) << "Transmit thread: connection failed to send." << Trace::EndLog();
                break;
            }
        }  // End of the while loop
    }
    

    /// Return the next command from either the waiting commands queue, generating 
    /// a move command from the current motion parameters, or a keep alive message,
    /// in that order.
    std::unique_ptr<gen3_command> gen_3_client::determine_next_command()
    {
        // First, checking the waiting command queue and the error state requires a lock to
        // coordinate with the thread that performs the detection and populates the queue.
        {
            const OS::SectionLock LOCK(m_client_lock);
            if (!m_waiting_commands.empty())
            {
                auto next_command = std::move(m_waiting_commands.front());
                m_waiting_commands.pop();

                return next_command;
            }

            // When the response processing thread has detected an error, we still need to send the
            // queued commands (that's where the generated park command goes) and then after that we
            // send nothing.
            if (m_error_detected)
            {
                return no_op::create();
            }
        }
            
        // Next, if we've got valid motion parameters, generate a move command
        // from them.
        MotionBase::Parameters current_parameters;
        {
            const OS::SectionLock LOCK(m_client_lock);
            current_parameters = m_motion_parameters;
        }
        if (current_parameters.IsValid())
        {
            return move_command::create(current_parameters);
        }

        // Finally, maintain a heartbeat to the CKAS and keep the connection alive.
        return keep_alive::create();
    }


    /// Entry point for the thread that listens for responses from the CKAS controller.
    ///
    OS::ThreadReturnType gen_3_client::receive_responses()
    {
        Trace::GetLogger().STAMP(Trace::INFO) << "MotionBaseController: Receiver thread started" << Trace::EndLog();
        
        try 
        {
            receive_responses_impl();
        }
        catch (SocketException e)
        {
            e.AddStackTrace(FLSTAMP, "Receiver thread.");
            Trace::GetLogger().LogException(e);
        }
        catch (CommonException e)
        {
            e.AddStackTrace(FLSTAMP, "Receiver thread.");
            Trace::GetLogger().LogException(e);
        }

        Trace::GetLogger().STAMP(Trace::INFO) << "MotionBaseController: Receiver thread ended" << Trace::EndLog();

        return OS::CastToReturnType(0UL);
    }

    /// Implementation for the response listener thread
    void gen_3_client::receive_responses_impl()
    {
        // Unlike the transmitter this thread doesn't use a timer, so the only event we consider is
        // the kill signal ...
        auto thread_kill_signal = m_thread_kill_signal.GetEvent().handle;

        // ... however sometimes the thread does sleep (when it's waiting for the 
        // transmit thread to establish the connection) 
        unsigned long wait_time_for_connection_ms = 100;

        // Now the actual processing loop

        while (true)
        {
            // Loop until a kill event is received
            if (OS::WaitForSingleObject(thread_kill_signal, 0) == 0)
                break;

            // Check we are still connected
            if (! m_connection->IsOpen()) 
            {
                // Reconnecting the port is handled in the transmitter thread, so
                // we'll just wait and then retry
                m_receiveThread->Sleep(wait_time_for_connection_ms);

                continue;
            }
            
            // And now we get the data from the connection
            //
            // TODO should we have a timeout in the connection code?
            //
            // TODO should we be gathering the data into lines or can we assume each datagram is an
            //      individual line?

            std::string response_string = m_connection->Receive();

            if(response_string.empty())
                continue;

            process_response(response_string);

        } // end of loop
    }
    


    /// Process the response string returned by the CKAS controller.  Check if
    /// the response indicates an error and what action should be taken
    ///
    /// @param response     The string returned by the controller, including the
    ///                     '@' prefix and optional CRC checksum bytes if they 
    ///                     were part of the reply.
    void gen_3_client::process_response(const std::string &response_string)
    {
        auto response = gen3_response::parse_response(response_string);

        // Check some specific response types to see if they report an error or warning that we
        // should pass on.
        //
        // This is a bit ugly with these dynamic casts, but this logic didn't seem to be worth
        // converting into something more encapsulated (eg a visitor pattern) unless we are going 
        // to make the whole check much more complex. As long as we're only interested in checking 
        // a couple of conditions, such as the status words in a move response, this seems like the
        // appropriate amount of complexity.

        // TODO - should we compare the responses with the sent commands to see if the commands have
        // received the responses they expect? The hard case are the commands that return a response
        // some time later than the command; the response to the park command comes a second or more
        // later. There are also the "unsolicited responses" that might not come in response to a
        // command. Doing that would require changes to the journal as well as the client as that
        // uses unique_ptr<journal_entry> (ie of commands and responses) and so takes control of the
        // objects when we add them to the journal.

        if (auto move = dynamic_cast<move_response const *>(response.get()))
        {
            if (move->is_error_response()) 
            {
                Trace::GetLogger().STAMP(Trace::ERR) << "Move response indicates an error: " << move << Trace::EndLog();
                if(m_journal)
                    m_journal->mark_point_of_interest("Move response indicates an error");

                park_platform_due_to_error();
            }
        }

        // The other cases we handle are all messages / diagnostics from the CKAS
        // that we pass along into the log: errors, warnings, and text messages.
        
        else if (auto error = dynamic_cast<error_message*>(response.get()))
        {
            Trace::GetLogger().STAMP(Trace::ERR) << *error << Trace::EndLog();

            // It's not clear what the best action to take is for this case since we'd have to parse
            // the content of the error message itself to determine what the actual error is. For now
            // we content ourselves with just reporting the error.
        }
        else if (auto warning = dynamic_cast<warning_message*>(response.get()))
        {
            Trace::GetLogger().STAMP(Trace::WARN) << *warning << Trace::EndLog();
        }
        else if (auto message = dynamic_cast<text_message*>(response.get()))
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << *message << Trace::EndLog();
        }
        else if (auto message_end = dynamic_cast<text_end_message*>(response.get()))
        {
            Trace::GetLogger().STAMP(Trace::VERBOSE) << *message_end << Trace::EndLog();
        }
        else if (auto parked = dynamic_cast<parked_response*>(response.get()))
        {
            Trace::GetLogger().STAMP(Trace::INFO) << *parked << Trace::EndLog();
        }

        if(m_journal)
            m_journal->add(std::move(response));
    }
    
    /// Respond to an error reported by the CKAS. Empty the waiting command queue and add a park
    /// platform command to the queue.
    void gen_3_client::park_platform_due_to_error()
    {
        auto park_command = park_platform::create();

        const OS::SectionLock LOCK(m_client_lock);

        while (!m_waiting_commands.empty())
        {
            m_waiting_commands.pop();
        }
        
        m_waiting_commands.push(std::move(park_command));
        
        m_error_detected = true;
    } 
} // namespace ckas_interface
