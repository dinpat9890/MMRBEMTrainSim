///
/// @file       FlightSimHardware.cpp
///
///             Implements the FlightSimHardware class. 
///
/// @ingroup    MTM Train Sim
///
/// @author     Andy Cooper
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///

#include "FlightSimHardware.h"

#include "SydacCommon/Profiler.h"

#include <memory>
#include <stdlib.h>
#include <cassert>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <WinBase.h>

#define LOG_PROFILE
#ifdef LOG_PROFILE
#include <fstream>
std::ofstream debug_log("flightsim_debug.log");
#endif

namespace
{
    // Polled Command Control bytes
    const int START_BYTE       = 0x00;
    const int CHECK_BYTE       = 0xAA;
    const int END_BYTE         = 0xFF;

    unsigned char end_byte_pair[2]={CHECK_BYTE, END_BYTE};
    const FlightSimHardware::RawBufferType END_BYTE_PAIR(&end_byte_pair[0], &end_byte_pair[0]+2);

    // Polled Command Byte
    const int STATUS_COMMAND   = 0xA7; 

    // Response Buffer is a fixed 25 byte buffer
    const int POLL_RESPONSE_SIZE     = 25;

    // Poll Loop Period
    const double DEFAULT_POLL_PERIOD    = 50;    // Default is 50 mSecs
    const int    DEFAULT_POLL_RETRIES   = 3;     // Maximum poll loops to wait for a reponse.
    const double DEFAULT_COMMAND_DELAY  = 0.55;  // Delay for each command character in mSecs

    /// Convert a data buffer into a hex string
    std::string hexdump(const FlightSimHardware::RawBufferType &command)
    {
        std::string returnstr;
        std::ostringstream oss;
        oss << std::hex << std::setfill('0');

        for(size_t i = 0; i < command.size(); i++)
        {
            int temp = command[i];
            oss << std::setw(2)  << temp << " ";
        }

        returnstr = oss.str();

        return returnstr;
    }
}

/// Constructs the object, given the connection details required to create the serial port. If
/// initialization fails this constructor will throw.
///

FlightSimHardware::FlightSimHardware(const std::string &port, int baud_rate, int data_bits, int parity, int stop_bits, double poll_period, int poll_retries, double cmd_delay)
    : m_running(false), m_port(port),m_poll_period(poll_period), m_poll_retries(poll_retries), m_command_delay(cmd_delay)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "Openening Com port " << m_port << Trace::EndLog();
        
    // Open the serial port.
    m_hport = CreateFile (m_port.c_str(),                // Pointer to the name of the port
                          GENERIC_READ | GENERIC_WRITE,  // Access (read-write) mode
                          0,                             // Share mode
                          NULL,                          // Pointer to the security attribute
                          OPEN_EXISTING,                 // How to open the serial port
                          0,                             // Port attributes
                          NULL);                         // Handle to port with attribute

    if(m_hport == INVALID_HANDLE_VALUE)
        throw SydacException(FLSTAMP, "Could not open COM port");

    DCB PortDCB;

    // Initialize the DCBlength member. 
    PortDCB.DCBlength = sizeof (DCB); 

    // Get the default port setting information.
    GetCommState (m_hport, &PortDCB);

    // Change the DCB structure settings.

    PortDCB.fBinary           = TRUE;                 // Binary mode; no EOF check 
    PortDCB.fParity           = FALSE;                // Enable parity checking 
    PortDCB.fOutxCtsFlow      = FALSE;                // No CTS output flow control 
    PortDCB.fOutxDsrFlow      = FALSE;                // No DSR output flow control 
    PortDCB.fDtrControl       = DTR_CONTROL_DISABLE;  // DTR flow control type 
    PortDCB.fDsrSensitivity   = FALSE;                // DSR sensitivity 
    PortDCB.fTXContinueOnXoff = TRUE;                 // XOFF continues Tx 
    PortDCB.fOutX             = FALSE;                // No XON/XOFF out flow control 
    PortDCB.fInX              = FALSE;                // No XON/XOFF in flow control 
    PortDCB.fErrorChar        = FALSE;                // Disable error replacement 
    PortDCB.fNull             = FALSE;                // Disable null stripping 
    PortDCB.fRtsControl       = RTS_CONTROL_DISABLE;  // RTS flow control 
    PortDCB.fAbortOnError     = FALSE;                // Do not abort reads/writes on error

    // Parameters that we can specify
    PortDCB.BaudRate          = baud_rate;            // Current baud
    PortDCB.ByteSize          = data_bits;            // Number of bits/byte, 4-8 
    PortDCB.Parity            = parity;               // 0-4=no,odd,even,mark,space 
    PortDCB.StopBits          = stop_bits;            // 0,1,2 = 1, 1.5, 2 

    // Configure the port according to the specifications of the DCB 
    // structure.
    if (!SetCommState (m_hport, &PortDCB))
    {
        CloseHandle(m_hport);
        throw SydacException(FLSTAMP, "Could not set CommState");
    }

    // Retrieve the time-out parameters for all read and write operations
    // on the port.
    COMMTIMEOUTS CommTimeouts;
    GetCommTimeouts (m_hport, &CommTimeouts);

    // Change the COMMTIMEOUTS structure settings to timeout immediately
    CommTimeouts.ReadIntervalTimeout = MAXDWORD;
    CommTimeouts.ReadTotalTimeoutMultiplier = MAXDWORD;
    CommTimeouts.ReadTotalTimeoutConstant = 0;

    // Set the time-out parameters for all read and write operations
    // on the port.
    if (!SetCommTimeouts (m_hport, &CommTimeouts))
    {
        CloseHandle(m_hport);
        throw SydacException(FLSTAMP, "Could not set CommTimeouts");
    }

    // Pre-Populate the Poll Buffer (The Address Byte is all that changes)
    m_poll_send_buffer.push_back(START_BYTE);
    m_poll_send_buffer.push_back(0x00);
    m_poll_send_buffer.push_back(0x07);
    m_poll_send_buffer.push_back(STATUS_COMMAND);
    m_poll_send_buffer.push_back(CHECK_BYTE);
    m_poll_send_buffer.push_back(CHECK_BYTE);
    m_poll_send_buffer.push_back(END_BYTE);

}

/// Destroys the object after stopping the thread and removing registered callbacks.

FlightSimHardware::~FlightSimHardware()
{
    // Stop the thread if it hasnt already been stopped with the Shutdown command.
    Shutdown();

    const OS::MutexLock LOCK_SEND(m_mutex_polled_control);
    {
        // Remove all registered callbacks.
        for(std::map<int, PolledCallbackType *>::iterator i = m_callbacks.begin(); i != m_callbacks.end(); ++i)
            delete i->second;

        m_current_device = m_callbacks.end();
    }

    CloseHandle(m_hport);

}

/// Signal the thread to end and wait for it.

void FlightSimHardware::Shutdown()
{
    {
        const OS::MutexLock LOCK_SEND(m_mutex_polled_control);
        m_running = false;
    }

    // Protect from joining a dead thread
    if (m_pcommandThread.get())
    {
        m_command_thread_kill_signal.Signal();
        m_pcommandThread->Join();
        m_pcommandThread.reset(0);
    }

    
    
}

/// Start the Processing thread. Note that no further Callback
/// registration/de-registrations will be available once the
/// thread is running.

void FlightSimHardware::Startup()
{
    // Idiot proof the poll period. This is based on observed poll times
    if (m_poll_period < 40 || m_poll_period > 10000)
    {
        Trace::g_plog->STAMP(Trace::VERBOSE) << "Bad Poll Period of " << m_poll_period << " mSecs Overidden with " << DEFAULT_POLL_PERIOD << " mSecs" << Trace::EndLog();
        m_poll_period = DEFAULT_POLL_PERIOD;
    }
    else
    {
        // Convert to milliseconds
        m_poll_period /= 1000;
    }

    if (m_poll_retries < 2 || m_poll_retries > 20)
    {
        Trace::g_plog->STAMP(Trace::VERBOSE) << "Bad Poll Retries of " << m_poll_retries << " Overidden with " << DEFAULT_POLL_RETRIES << Trace::EndLog();
        m_poll_period = DEFAULT_POLL_RETRIES;
    }

    if (m_command_delay < 0 || m_command_delay > 5)
    {
        Trace::g_plog->STAMP(Trace::VERBOSE) << "Bad Command Delay of " << m_command_delay << " mSecs Overidden with " << DEFAULT_COMMAND_DELAY << " mSecs" << Trace::EndLog();
        m_command_delay = DEFAULT_COMMAND_DELAY;
    }

    // Start the thread 
    m_pcommandThread.reset(new OS::Thread(std::tr1::bind(&FlightSimHardware::CommandThread, this)));   
}

//  Function:       FlightSimHardware::SendCommand
//
//  Description:    Queues a command for sending
//
//  Parameters:
//      const std::vector<unsigned char> &command - command to send

void FlightSimHardware::SendCommand(const RawBufferType &command, bool log)
{
    if (log) Trace::g_plog->STAMP(Trace::VERBOSE) << "Command Buffer = " << hexdump(command) << Trace::EndLog();
   
    // Add to the queue and set the send event
    {
        const OS::MutexLock LOCK_SEND(m_mutex_other_command);
        m_command_queue.push(command);
    }
}

void FlightSimHardware::AddPolledCallback(int hardware_address, const PolledCallbackType &cb)
{
    const OS::MutexLock LOCK_SEND(m_mutex_polled_control);
    {
        if (!m_running)
        {
            m_callbacks[hardware_address] = cb.Clone();

            // Reset Loop Pointer
            m_current_device = m_callbacks.begin();
        }
        else
        {
             Trace::g_plog->STAMP(Trace::ERR) << "You may not Add Polled Callbacks once the Poll thread is running!" << Trace::EndLog();
        }
    }
    
}

void FlightSimHardware::RemovePolledCallback(const PolledCallbackType &cb)
{
    const OS::MutexLock LOCK_SEND(m_mutex_polled_control);
    {
        if (!m_running)
        {
            for(std::map<int, PolledCallbackType *>::iterator i = m_callbacks.begin(); i != m_callbacks.end(); ++i)
            {
                if(cb == *i->second)
                {
                    Trace::g_plog->STAMP(Trace::VERBOSE) << "Removing Callback for Device address " << i->first << Trace::EndLog();
       
                    delete i->second;
                    m_callbacks.erase(i);
                    
                    // Reset Loop Pointer
                    m_current_device = m_callbacks.begin();

                    break;
                }
            }
        }
        else
        {
             Trace::g_plog->STAMP(Trace::ERR) << "You may not Remove Polled Callbacks when the thread is running" << Trace::EndLog();
        }
    }
}

///
/// The Worker thread that sends commands to the hardware via the Com port
/// It also recieves Polled Status responses via the COM port.
///
OS::ThreadReturnType FlightSimHardware::CommandThread()
{

    Trace::g_plog->STAMP(Trace::INFO) << "FlightSimHardware : Port " << m_port << " Command thread started with Period " << m_poll_period*1000 << " mSecs, "
                                      << m_poll_retries << " Retries, " 
                                      << m_command_delay << " mSec/Byte Command Delay"
                                      << Trace::EndLog();

    // Create a timer, and set up the polling period
    OS::Timer  timer;
    {
        OS::OSTime period;
        period.seconds      = static_cast<int>(m_poll_period);
        period.nano_seconds = static_cast<int>((m_poll_period  - period.seconds) * 1000000000.0);

        // Start the timer
        timer.Set(period, true, period);
    }

    /// The Event Handles. 0 = Kill Event and 1 = the Polling Timer
    OS::OSHandle events[2] = { m_command_thread_kill_signal.GetEvent().handle,  // Index 0            
                               timer.handle };                                  // Index 1

    OS::OSCounter time_last_log = OS::GetCounter();
    m_time_last_send = OS::GetCounter();

#ifdef LOG_PROFILE
    static Sydac::Profiler prof;
    static int             cnt = 0;
    prof.Start();
#endif

    {
        // Disable registered Callback add or remove while we are looping through them
        const OS::MutexLock LOCK_SEND(m_mutex_polled_control);
        m_running = true;
    }

    // We no longer need to use the polled controlmutex once the thread is running. 
    // Clients are not able to register or deregister callbacks while m_running is true.
    m_current_device         = m_callbacks.begin();
    int current_poll_count   = 0;

    // Loop until a kill event is received
    while (true)
    {
        try
        {
 
            // Waiting for a Kill or a timer event.
            const int EVENT_INDEX = OS::WaitForMultipleObjects(2, events, OS::INFINITE);

            // Kill by breaking out of the loop
            if(EVENT_INDEX == 0)
                break;

#ifdef LOG_PROFILE
            // Get timing for Polling Loop excluding the Loop wait period.
            prof.BeginCycle();
#endif

            ///------------------------------------------------------------------------------
            /// Get the next Polled Hardware device and poll it
            ///------------------------------------------------------------------------------
            if (m_current_device != m_callbacks.end() && current_poll_count<=0)
            {

                current_poll_count = 1;

                // Setup the hardware address in the pre-populated status request command buffer
                m_poll_send_buffer[1] = m_current_device->first;

                /*
                Trace::g_plog->STAMP(Trace::VERBOSE) << "FlightSimHardware: Port " << m_port << " Poll Device " << m_current_device->first 
                << hexdump(m_poll_send_buffer)
                << Trace::EndLog();
                */

                DWORD bytes_written;
                WriteFile(m_hport, &m_poll_send_buffer[0], static_cast<DWORD>(m_poll_send_buffer.size()), &bytes_written, NULL);

                // Always delay here before sending other commands?
                if (1)
                {
                    // Delay 1ms before sending commands below
                    ::Sleep(static_cast<DWORD>(10));
                }

            }

            ///------------------------------------------------------------------------------
            /// Check if there are any other Commands Queued and send them
            /// These are commands that do not get a response - Not even an ACK
            ///------------------------------------------------------------------------------
            bool commands_to_process = false;
            std::vector<RawBufferType > message_queue;
            {
                // Lock the mutex just long enough to Swap queues.
                const OS::MutexLock LOCK_SEND(m_mutex_other_command);
                // Nasty Hack. If the command delay is 0 then only process 1 command per
                // poll period. 
                if (m_command_delay > 0)
                {
                    while(!m_command_queue.empty())
                    {
                        message_queue.push_back(m_command_queue.front());
                        m_command_queue.pop();
                    }
                }
                else
                {
                    if(!m_command_queue.empty())
                    {
                        message_queue.push_back(m_command_queue.front());
                        m_command_queue.pop();
                    }
                }
            }

            // Process the message_queue
            if (!message_queue.empty())
            {
                for(size_t i = 0; i < message_queue.size(); ++i)
                {
                    
                    const RawBufferType &command = message_queue[i];
                    
                    //Trace::g_plog->STAMP(Trace::VERBOSE) << "+++Out Buffer(" << command.size() << ") = " << hexdump(command) << Trace::EndLog();

                    DWORD bytes_written;
                    WriteFile(m_hport, &command[0], static_cast<DWORD>(command.size()), &bytes_written, NULL);

                    // The Event Recorder appears to have a buffering issue. As it has no Ack or
                    // handshaking, it has no way of telling us when its finished processing the 
                    // last command. Interrupted commands are abandoned.
                    //
                    // XTL2500 Radio - Writing text is an issue - Commands sent while another is
                    // busy are ignored (And sometimes corrupted - Font size can sometimes get messed
                    // up.
                    // 
                    // Configurable Delay per Byte of last message sent (To allow it to complete before the 
                    // next message is sent)
                    if (m_command_delay > 0 && i < message_queue.size())
                    {
                        // Loss of precision expected. Dont make the delay too small
                        DWORD delayms =static_cast<DWORD>(command.size()*m_command_delay);

                        //Trace::g_plog->STAMP(Trace::VERBOSE) << "+++Sleep " << delayms << Trace::EndLog();

                        ::Sleep(delayms);
                    }
                    
                }
            }

            ///------------------------------------------------------------------------------
            /// Receive any response bytes and process them.
            ///------------------------------------------------------------------------------
            if (m_current_device != m_callbacks.end() && current_poll_count > 0)
            {
                // Our buffers are 25 bytes so give a bit of extra room
                char buf[128];
                DWORD bytes_read;

                // Read data from the serial connection - this will timeout immediately if
                // there is no data to read.
                if(ReadFile(m_hport, buf, 128, &bytes_read, 0) == 0)
                {
                    // Unrecoverable error, just log for now
                    Trace::g_plog->STAMP(Trace::ERR) << "Port " << m_port << " ReadFile returned Error." << Trace::EndLog();
                }

                // If there were bytes read, store these in the buffer up to the limit
                if(bytes_read > 0)
                {
                    /*
                    Trace::g_plog->STAMP(Trace::VERBOSE) << "Response Device " << m_current_device->first 
                                                         << " Buffer = " << hexdump(FlightSimHardware::RawBufferType(&buf[0],&buf[bytes_read]))
                                                         << Trace::EndLog();
                                                         */

                    // Get whats there and process the message to see if the 
                    // full 25 bytes are there.
                    m_poll_receive_buffer.insert(m_poll_receive_buffer.end(), &buf[0], &buf[bytes_read]);

                    // Looking for a 25 byte buffer that looks like:
                    // 0x00 Address Type Model Version 18Bytes 0xAA 0xFF
                    
                    // Its possible the start of the buffer is corrupted -
                    // If the first byte is not the start byte, discard everything up to that byte.
                    if (m_poll_receive_buffer[0] != START_BYTE)
                    {
                        m_poll_receive_buffer.erase(m_poll_receive_buffer.begin(), find(m_poll_receive_buffer.begin(), m_poll_receive_buffer.end(), START_BYTE));
                    }

                    // Find the position of the end byte pair
                    RawBufferType::iterator iend = std::search(m_poll_receive_buffer.begin(), m_poll_receive_buffer.end(), END_BYTE_PAIR.begin(), END_BYTE_PAIR.end());
                    int len = std::distance(m_poll_receive_buffer.begin(), iend );
                    if(iend != m_poll_receive_buffer.end() && len == POLL_RESPONSE_SIZE-2)
                    {

                        // Extract the received Status data buffer
                        RawBufferType statusbuf;

                        std::move(m_poll_receive_buffer.begin(), iend+2, std::back_inserter(statusbuf));  // ##
                        m_poll_receive_buffer.erase(m_poll_receive_buffer.begin(), iend+2);

                        // Check that the Address in the Response matches the current device
                        if (statusbuf[1] == m_current_device->first)
                        {

                            // Callbacks need protection if the polling of other devices is to be maintained.
                            try
                            {
                                // Make the Callback.
                                (*m_current_device->second)(statusbuf);
                            }
                            catch(std::exception &e)
                            {
                                // OPTION - Build an Enabled flag into the Map so that Bad callbacks can be ignored?
                                //         OR
                                //          Remove this device here and re-enable the Iterator?
                                //         OR
                                //          Just let the Errors pile up and ignore it?
                                Trace::g_plog->STAMP(Trace::ERR) << "Port " << m_port <<  " Callback for device " << m_current_device->first 
                                    << " Threw Exception " << e.what() 
                                    << Trace::EndLog();
                            }
                        }
                        else
                        {
                            // Address Mismatch - Log it and dump the buffer ready for the next round
                            // This Error may indicate that a longer Poll period would be needed?
                            Trace::g_plog->STAMP(Trace::ERR) << "Port " << m_port << " Callback for device " << m_current_device->first 
                                                             << " had incorrect address of " <<  static_cast<int>(statusbuf[1])
                                                             << Trace::EndLog();

                            m_poll_receive_buffer.clear();
                        }

                        // Get the Next device in the list (Loop through the map)
                        if (++m_current_device == m_callbacks.end())
                        {
                            m_current_device = m_callbacks.begin();
                        }

                        current_poll_count = 0;
                    }
                }

                if (current_poll_count > 0)
                {
                    // Buffer not complete yet - Increment counter and wait till next loop
                    current_poll_count++;

                    // The main function of this part is to handle devices that are not plugged in to the
                    // correct COM port, or are switched off, or have failed. It should also detect and warn 
                    // about corrupted data packets that may be caused by USB or Bus cables that are to long
                    // or are being affected by noise sources.
                    // All the Polling thread knows about is the COM port. It has no way of knowing if anything 
                    // is actually plugged into the other end as the FlightSim Hardware does not use any of the
                    // industry standard handshaking mechanisms. It has no way of knowing if the received buffer is
                    // correct as there are no CRC or check bits in the messages.
                    if (current_poll_count > m_poll_retries)
                    {
                        Trace::g_plog->STAMP(Trace::ERR) << "Port " << m_port << " Poll Count exceeded " << m_poll_retries 
                            << " Loop iterations waiting for device address " << m_current_device->first 
                            << " to respond. Trying the next registered device "
                            << Trace::EndLog();

                        // Dump the current Buffer, ready for the next device
                        m_poll_receive_buffer.clear();

                        // Get the Next device in the list (Loop through the map)
                        if (++m_current_device == m_callbacks.end())
                        {
                            m_current_device = m_callbacks.begin();
                        }

                        current_poll_count = 0;
                    }
                }
                 
            }
#ifdef LOG_PROFILE
            prof.EndCycle();
            if(++cnt % 100 == 0)
                debug_log << prof.ToString() << std::endl;
#endif
        }
        catch(SydacException &e)
        {
            // We can't safely keep trying to use
            // the socket without reopening it...
            e.AddStackTrace(FLSTAMP, "In hardware thread.");
            Trace::g_plog->LogException(e);

        }
        catch(std::exception &e)
        {
            Trace::g_plog->STAMP(Trace::ERR) << "FlightSimHardware: Port " << m_port << " Unexpected Error " << e.what() << Trace::EndLog();
        } 

    } // End While

    // Get out and end the thread when the kill signal is received.
    Trace::g_plog->STAMP(Trace::INFO)<< "FlightSimHardware: Port " << m_port << " Worker thread killed" << Trace::EndLog();

    {
        // Disable registered Callback add or remove while we are looping through them
        const OS::MutexLock LOCK_SEND(m_mutex_polled_control);
        m_running = false;
    }

    return OS::CastToReturnType(0UL);
}


