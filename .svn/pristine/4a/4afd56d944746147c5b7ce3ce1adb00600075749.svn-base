///                                                                                                        UpdateFlightSimGaugePositions
/// @file       FlightSimHardwareV2.h
///
///             Declares the FlightSimHardwareV2 class. 
///
/// @ingroup    MTM Train Sim
///
/// @author     Andy Cooper
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2013
///

#ifndef FLIGHTSIM_HARDWARE_V2_WRAPPER
#define FLIGHTSIM_HARDWARE_V2_WRAPPER

#include <windows.h>
#include <vector>
#include <map>
#include <queue>

#include "common/StandardLogging.h"
#include "common/Utilities.h"
#include "common/OSThreadClasses.h"
#include "common/OSClasses.h"

namespace FlightSim
{
   
}

/// Encapsulates the FlightSim Hardware as an object.
///
/// Design Notes (Mostly explaining why the interface is not very Client friendly, because it was the quickest way to
///               develop it as there was no time to make it nice).
///
/// 1 - Client Units that require Polled Command replies must register a callback for the raw data.
/// 2 - No Data processing is performed in this Class - Its up to the Client to copy the data in the callback
///     and return as fast as possible - Delays in the callback WILL stuff up all the other hardware waiting to Poll.
/// 3 - No callback registration/deregistration after thread started - This means that the Parent Unit creates this class
///     Passes a reference to Client units that register for Keypress polling as required. Parent unit then starts and 
///     ultimately stops the thread before destructing the Client Units, which may then Deregister.

class FlightSimHardwareV2 : private Common::Unique
{
public:
    /// The type of callback that will be called when a feature passes an object of interest
    typedef std::vector<unsigned char>      RawBufferType;
    typedef Callback<void, RawBufferType &> PolledCallbackType;

// Member functions
public:
    // Constructor and deconstructor
    FlightSimHardwareV2(const std::string &port, int baud_rate, int data_bits, int parity, int stop_bits, double poll_period, int poll_retries, double cmd_delay=0);
    ~FlightSimHardwareV2();

    void SendCommand(const RawBufferType &command, bool log = false);

    void AddPolledCallback(int hardware_address, const PolledCallbackType &cb);
    void RemovePolledCallback(const PolledCallbackType &cb);

    // Thread Control Functions. 
    void Startup();
    void Shutdown();
    bool IsRunning();

	void PackV2CommandBuffer(RawBufferType &buffer, unsigned int address, unsigned int command, unsigned int data_low, unsigned int data_high);

private:
    // Thread functions.
    OS::ThreadReturnType CommandThread();

// Variables
private:

    bool        m_running;

    std::string m_port;
    HANDLE      m_hport;

    double      m_poll_period;
    int         m_poll_retries;
    double      m_command_delay;

    // Counters for use in the thread
    OS::OSCounter m_time_last_send;
 
    // Variables associated with the thread
    std::unique_ptr<OS::Thread> m_pcommandThread;

    OS::Signaller m_command_thread_kill_signal;

    OS::Mutex m_mutex_other_command;
    std::queue<RawBufferType > m_command_queue;

    // Mutex to protect the list of pointers to polled hardware.
    OS::Mutex m_mutex_thread_control;

    OS::Mutex m_mutex_polled_control;
    std::map<int, PolledCallbackType *>::iterator m_current_device;
    std::map<int, PolledCallbackType *> m_callbacks;

    RawBufferType m_poll_send_buffer;
    RawBufferType m_poll_receive_buffer;
};

#endif FLIGHTSIM_HARDWARE_V2_WRAPPER
