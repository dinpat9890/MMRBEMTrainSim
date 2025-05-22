//******************************************************************************
//
//  File:           FlightSimGaugeHardware.cpp
//
//  Description:    Class for communication with Lynx Servo Drivers
//
//  Reference:      Lithuania Freight Simulator
//
//  Author:         Adrian James
//
//  (C) Copyright:  SYDAC Pty Ltd, 2011
//
//******************************************************************************
#include "FlightSimGaugeHardware.h"
#include "common/StandardLogging.h"

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

namespace
{
    // Control bytes
    const int START_BYTE       = 0x00;
    const int END_BYTE         = 0xFF;

    // standard data bytes
    const int LIGHT_MODE_OFF  = 0x00;
	const int LIGHT_MODE_ON   = 0x01;
	const int LIGHT_MODE_CTL  = 0x02;
	// Masks
    const int DISPLAY_ON_MASK = 0x80;
    const int LIGHTS_ON_MASK  = 0x40;
	const int UPDATE_BL_MASK  = 0x10;
	const int BL_INTENSITY    = 0x0F;

	const int RED_LIGHT_ON_BYTE = 0x02;

    const int ZERO_LOW_BYTE   = 0x01;
    const int ZERO_HIGH_BYTE  = 0x02;

    // Limitations
    const int MAX_GAUGE_ADDRESS = 255;
	const int MAX_LIGHT_INTENSITY = 100;

    // Commands
    const int NEW_POSITION_FIRST_GAUGE   = 0x50;
    const int NEW_POSITION_SECOND_GAUGE  = 0x60;
    const int SWITCH_LIGHTS_COMMAND      = 0x80;
	const int SWITCH_RED_LIGHTS_COMMAND  = 0xE8;

	// Bit 2 and 3 Always 1 - Bit 2 is The signbit which is only set for numbers > 32767 (&h7FFF); otherwise ignored so leave set to 1
    const int COMMAND_MASK               = 0x0C;

    // Clock Command Constants
    const int CLOCK_CHECK_BYTE = 0xAA;

    // Clock Commands
    const int CLOCK_CMD_CHECK            = 0xA0;
    const int CLOCK_DATA_CHECK           = 0x80;

    const int CLOCK_CMD_INITIALISE       = 0x01;
    const int CLOCK_CMD_SET_DIGITS       = 0x03;
    const int CLOCK_CMD_SET_INT_CLOCK    = 0x04;
    const int CLOCK_CMD_SET_DISPLAY_MODE = 0x06;
    const int CLOCK_CMD_GET_STATUS       = 0x07;
    const int CLOCK_CMD_SWITCH_INTENSITY = 0x08;
    const int CLOCK_CMD_SWITCH_ON_OFF    = 0x09;
    const int CLOCK_CMD_SET_INTENSITY    = 0x0A;

    // Clock Special Characters (0 to 9 are 0x00 to 0x09)
    const int CLOCK_DASH  = 0x0A;
    const int CLOCK_E     = 0x0B;
    const int CLOCK_H     = 0x0C;
    const int CLOCK_L     = 0x0D;
    const int CLOCK_P     = 0x0E;
    const int CLOCK_SPACE = 0x0F;

    std::string hexdump(const std::vector<unsigned char> &command)
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

//  Function:       FlightSimGaugeHardware::FlightSimGaugeHardware
//
//  Description:    Constructor. Initialises a communications port and then 
//                  creates the send thread
//
//  Parameters:
//      const char *port - Communications port, eg COM1

FlightSimGaugeHardware::FlightSimGaugeHardware(const char *port, int baud_rate, int data_bits, int parity, int stop_bits)
    : m_kill_threads(false), m_pthread_send(0)
{
    // Open the serial port.
    m_hport = CreateFile (port,                          // Pointer to the name of the port
                          GENERIC_READ | GENERIC_WRITE,  // Access (read-write) mode
                          0,                             // Share mode
                          NULL,                          // Pointer to the security attribute
                          OPEN_EXISTING,                 // How to open the serial port
                          0,                             // Port attributes
                          NULL);                         // Handle to port with attribute

    if(m_hport == INVALID_HANDLE_VALUE)
        throw CommonException(FLSTAMP, "Could not open COM port");

    DCB PortDCB;

    // Initialize the DCBlength member. 
    PortDCB.DCBlength = sizeof (DCB); 

    // Get the default port setting information.
    GetCommState (m_hport, &PortDCB);

    // Change the DCB structure settings.
    
    PortDCB.fBinary           = TRUE;                // Binary mode; no EOF check 
    PortDCB.fParity           = FALSE;               // Enable parity checking 
    PortDCB.fOutxCtsFlow      = FALSE;               // No CTS output flow control 
    PortDCB.fOutxDsrFlow      = FALSE;               // No DSR output flow control 
    PortDCB.fDtrControl       = DTR_CONTROL_DISABLE; // DTR flow control type 
    PortDCB.fDsrSensitivity   = FALSE;               // DSR sensitivity 
    PortDCB.fTXContinueOnXoff = TRUE;                // XOFF continues Tx 
    PortDCB.fOutX             = FALSE;               // No XON/XOFF out flow control 
    PortDCB.fInX              = FALSE;               // No XON/XOFF in flow control 
    PortDCB.fErrorChar        = FALSE;               // Disable error replacement 
    PortDCB.fNull             = FALSE;               // Disable null stripping 
    PortDCB.fRtsControl       = RTS_CONTROL_DISABLE; // RTS flow control 
    PortDCB.fAbortOnError     = FALSE;               // Do not abort reads/writes on error

    // Configurable parameters
    PortDCB.BaudRate          = baud_rate;           // Current baud
    PortDCB.ByteSize          = data_bits;           // Number of bits/byte, 4-8 
    PortDCB.Parity            = parity;              // 0-4=no,odd,even,mark,space 
    PortDCB.StopBits          = stop_bits;           // 0,1,2 = 1, 1.5, 2 

    // Configure the port according to the specifications of the DCB 
    // structure.
    if (!SetCommState (m_hport, &PortDCB))
    {
        CloseHandle(m_hport);
        throw CommonException(FLSTAMP, "Could not set CommState");
    }

    // Spawn send thread
    m_pthread_send = new OS::Thread(MakeCallback(&FlightSimGaugeHardware::SendThread, this));
}

//  Function:       FlightSimGaugeHardware::~FlightSimGaugeHardware
//
//  Description:    Destructor. Closes the send thread, and then 
//                  the communications port

FlightSimGaugeHardware::~FlightSimGaugeHardware()
{
    // Signal threads to close
    m_kill_threads = true;
    m_event_send.Set();

    // Wait for threads to close, otherwise forcibly kill them
    m_pthread_send->Terminate(1000);

    // Delete the threads
    delete m_pthread_send;

    // Close the serial connection
    CloseHandle(m_hport);
}

//  Function:       FlightSimGaugeHardware::SetPosition
//
//  Description:    Sets the position of a servo. If in a command group, this is delayed until the
//                  group is ended.
//
//  Parameters:
//      int gauge_address - Address of flight sim gauge
//      int position      - position
//

void FlightSimGaugeHardware::SetPosition(int gauge_address, bool first_needle, double position, bool log)
{
    if (log) Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Gauge Set Position "
                                                  << " first_needle " << (first_needle?"True":"False")
                                                  << " Position " << position
                                                  << Trace::EndLog();

    assert(gauge_address > 0 && gauge_address <= MAX_GAUGE_ADDRESS);

    unsigned int position_int = static_cast<unsigned int>(position);

    unsigned int data_low = position_int & 0xFF;

    // this is the L bit for the command byte
    unsigned int data_low_bit = data_low & ZERO_LOW_BYTE;

    // zeros can not be sent in the message, so bit wise or with zero low bit
    data_low = data_low | ZERO_LOW_BYTE;

    unsigned int data_high = position_int & 0xFF00;
    data_high = data_high >>8;

    // this is the H bit for the command byte
    unsigned int data_high_bit = data_high & ZERO_HIGH_BYTE;

    // zeros can not be sent in the message, so bit wise or with zero high bit
    data_high = data_high |ZERO_HIGH_BYTE;

    unsigned int gauge_command = 0;

    if (first_needle)
        gauge_command = NEW_POSITION_FIRST_GAUGE;
    else
        gauge_command = NEW_POSITION_SECOND_GAUGE;

    gauge_command = gauge_command | COMMAND_MASK | data_high_bit | data_low_bit;

    std::vector<unsigned char> command;

    command.push_back(START_BYTE);
    command.push_back(gauge_address);
    command.push_back(gauge_command);
    command.push_back(data_low);
    command.push_back(data_high);
    command.push_back(END_BYTE);

    SendCommand(command, log);
}

//  Function:       FlightSimGaugeHardware::SetBackLights
//
//  Description:    Enable the Display and/or the Back lights of the Gauge.
//
//  Parameters:
//      int gauge_address - Address of flight sim gauge
//      bool display_on   - Turns on Display when true
//      bool backlight_on - Turn on backlights when true - When Off Overides Intensity Setting)
//      double intensity  - Backlight intensity (0 = Off, up to 100% is Brightest)
// V1
// 8=Switchlights:Lowbyte=DL00.0000;D=displayon/off,L=lighton/off
// V2 onwards
// 8= Switch lights: Low byte= DLSU.IIII; D=display on/off, L=light on/off, XXSU.IIII=Soft Backlight dimmer
//   '     SU.IIII: S=1:Save as default, U=1:Update Backlight Level, IIII= Backlight level(0-15)
//   '     High byte is Light mode command. 0=no action,1=set always on, 2= set On/Off by command
//
// Notes: This command appears to be valid for all Gauge types.

void FlightSimGaugeHardware::SetLights(int gauge_address, bool display_on, bool backlight_on, int intensity, bool log)
{
    assert(gauge_address >= 0 && gauge_address <= MAX_GAUGE_ADDRESS);

	// Idiot Proof Comms Number
	if (intensity < 0) 
		intensity = 0;
	else if (intensity > MAX_LIGHT_INTENSITY) 
		intensity = MAX_LIGHT_INTENSITY;

    Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Gauge Set Lights "
                                         << " display " << (display_on?"On":"Off")
                                         << " backlight " << (backlight_on?"On":"Off")
										 << " intensity " << intensity
                                         << Trace::EndLog();

	// Scale 0 to 100% to 0 to 15
	int command_byte = static_cast<int>(intensity*0.15) & 0x0f;

    if (display_on) 
        command_byte |= DISPLAY_ON_MASK;

    if (backlight_on)
	{
		// Its not clear if the Light On/Off command bit is required for Variable Backlights?
        command_byte |= LIGHTS_ON_MASK;
		command_byte |= UPDATE_BL_MASK;
	}

	unsigned int data_low =  command_byte & 0xFF;

    // this is the L bit for the command byte
    unsigned int data_low_bit = data_low & ZERO_LOW_BYTE;

    // zeros can not be sent in the message, so bit wise or with zero low bit
    data_low = data_low | ZERO_LOW_BYTE;

	// The Flight Illusion devices back lights are on at intensity 0.
	// When Intensity is 0, then we turn the Backlight off with a Flag.
	// When Intensity is 0.1 then the light is on at minimum intensity
	unsigned int data_high = (backlight_on?LIGHT_MODE_CTL:LIGHT_MODE_OFF);

    // this is the H bit for the command byte
    unsigned int data_high_bit = data_high & ZERO_HIGH_BYTE;

    // zeros can not be sent in the message, so bit wise or with zero high bit
    data_high = data_high |ZERO_HIGH_BYTE;

    unsigned int gauge_command = SWITCH_LIGHTS_COMMAND;

    gauge_command = gauge_command | COMMAND_MASK | data_high_bit | data_low_bit;

    std::vector<unsigned char> command;

    command.push_back(START_BYTE);
    command.push_back(gauge_address);
    command.push_back(gauge_command);
    command.push_back(data_low);
    command.push_back(data_high);
    command.push_back(END_BYTE);

    SendCommand(command, log);
}

//  Function:       FlightSimGaugeHardware::SetRedLight
//
//  Description:    Turn on or off the Red Light
//
//  Parameters:
//      int gauge_address - Address of flight sim gauge
//      bool red_light_on - Turn on red light when true
//
// Notes: This command appears to be valid for all Gauge types.

void FlightSimGaugeHardware::SetRedLight(int gauge_address, bool red_light_on, bool log)
{
    assert(gauge_address >= 0 && gauge_address <= MAX_GAUGE_ADDRESS);

    Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Gauge Set Lights "
                                         << " Red Light " << (red_light_on?"On":"Off")
                                         << Trace::EndLog();

    std::vector<unsigned char> command;

    command.push_back(START_BYTE);
    command.push_back(gauge_address);

    command.push_back(SWITCH_RED_LIGHTS_COMMAND);

    int command_byte = ZERO_LOW_BYTE;

    if (red_light_on)
        command_byte = RED_LIGHT_ON_BYTE;

    command.push_back(command_byte);

    command.push_back(ZERO_HIGH_BYTE);
    command.push_back(END_BYTE);

    SendCommand(command, log);
}

//  Function:       FlightSimGaugeHardware::ClockSetDigits
//
//  Description:    Sets the Digits on the Clock. Sets undefined digit positions to a space.
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      std::vector<int> digits1_7 - Array of Digit Values (Left to Right on Clock)
//
void FlightSimGaugeHardware::ClockSetDigits(int clock_address, const std::vector<int> digits1_7)
{
    std::vector<unsigned char> buffer;
    buffer.push_back(START_BYTE);
    buffer.push_back(clock_address);
    buffer.push_back(13);
    buffer.push_back(CLOCK_CMD_CHECK | CLOCK_CMD_SET_DIGITS);
    // Hard Coded 7 Digits on Clock. This is unlikely to change.
    // TODO - Is it worth checking the validity of the digits? Not in this hack.
    // Process Digits from Left to Right.
    size_t i=0;
    while (i<digits1_7.size())
    {
        buffer.push_back( CLOCK_DATA_CHECK | digits1_7[i++]);
    }
    // Set Remaining digits to Blank.
    while(i<7)
    {
        buffer.push_back( CLOCK_DATA_CHECK | CLOCK_SPACE);
        i++;
    }

    buffer.push_back(CLOCK_CHECK_BYTE);
    buffer.push_back(END_BYTE);

     SendCommand(buffer);
}

//  Function:       FlightSimGaugeHardware::ClockSetInternalClock
//
//  Description:    Sets the Internal Clock Time. No validation of input data is performed.
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      int hours - 0-23
//      int mins  - 0-59
//      int secs  - 0-59
//
void FlightSimGaugeHardware::ClockSetInternalClock(int clock_address, int hours, int mins, int secs)
{
    std::vector<unsigned char> buffer;
    buffer.push_back(START_BYTE);
    buffer.push_back(clock_address);
    buffer.push_back(9);
    buffer.push_back(CLOCK_CMD_CHECK | CLOCK_CMD_SET_INT_CLOCK);
    buffer.push_back( CLOCK_DATA_CHECK | hours);
    buffer.push_back( CLOCK_DATA_CHECK | mins);
    buffer.push_back( CLOCK_DATA_CHECK | secs);
    buffer.push_back(CLOCK_CHECK_BYTE);
    buffer.push_back(END_BYTE);
    SendCommand(buffer);
}

//  Function:       FlightSimGaugeHardware::ClockSetDisplayMode
//
//  Description:    Sets the Clock Mode.
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      bool internal_clock - If true the Clock displays its internal clock
//                            If False the Clock display is static until a new set of digits are received.
//
void FlightSimGaugeHardware::ClockSetDisplayMode(int clock_address, bool internal_clock)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Set Mode :" 
                                         << " Internal Clock " << (internal_clock?"On":"Off")
                                         << Trace::EndLog();

    std::vector<unsigned char> buffer;
    buffer.push_back(START_BYTE);
    buffer.push_back(clock_address);
    buffer.push_back(7);
    buffer.push_back(CLOCK_CMD_CHECK | CLOCK_CMD_SET_DISPLAY_MODE);
    buffer.push_back( CLOCK_DATA_CHECK | (internal_clock?1:0));    
    buffer.push_back(CLOCK_CHECK_BYTE);
    buffer.push_back(END_BYTE);
    SendCommand(buffer);
}

//  Function:       FlightSimGaugeHardware::ClockSwitchIntensity
//
//  Description:    Sets the Clock Display intensity.
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      bool daytime - If true the Clock sets the daytime intensity
//                     If False the Clock sets the nighttime intensity.
//
// Note: Intensity Values are defined with the ClockSetDisplayIntensity command.
//
void FlightSimGaugeHardware::ClockSwitchIntensity(int clock_address, bool daytime)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Set Intensity :" 
                                         << " Daytime " << (daytime?"On":"Off")
                                         << Trace::EndLog();

    std::vector<unsigned char> buffer;
    buffer.push_back(START_BYTE);
    buffer.push_back(clock_address);
    buffer.push_back(7);
    buffer.push_back(CLOCK_CMD_CHECK | CLOCK_CMD_SWITCH_INTENSITY);
    buffer.push_back( CLOCK_DATA_CHECK | (daytime?0:1));    
    buffer.push_back(CLOCK_CHECK_BYTE);
    buffer.push_back(END_BYTE);
    SendCommand(buffer);
}

//  Function:       FlightSimGaugeHardware::ClockSwitchIndicatorsAndDisplay
//
//  Description:    Turns the Clock LEDs and display on or off
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      bool speed_led_on - If true the Clock turns on the Speed Led
//      bool clock_led_on - If true the Clock turns on the Clock Led
//      bool display_on   - If true the Clock turns the main display on
//
void FlightSimGaugeHardware::ClockSwitchIndicatorsAndDisplay(int clock_address, bool speed_led_on, bool clock_led_on, bool display_on)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Indicate:" 
                                         << " Speed " << (speed_led_on?"On":"Off")
                                         << " Clock " << (clock_led_on?"On":"Off")
                                         << " Display " << (clock_led_on?"On":"Off")
                                         << Trace::EndLog();

    std::vector<unsigned char> buffer;
    buffer.push_back(START_BYTE);
    buffer.push_back(clock_address);
    buffer.push_back(9);
    buffer.push_back(CLOCK_CMD_CHECK | CLOCK_CMD_SWITCH_ON_OFF);
    buffer.push_back( CLOCK_DATA_CHECK | (clock_led_on?1:0));
    buffer.push_back( CLOCK_DATA_CHECK | (speed_led_on?1:0));
    buffer.push_back( CLOCK_DATA_CHECK | (display_on?1:0));
    buffer.push_back(CLOCK_CHECK_BYTE);
    buffer.push_back(END_BYTE);
    SendCommand(buffer);
}

//  Function:       FlightSimGaugeHardware::ClockSetDisplayIntensity
//
//  Description:    Defines the Day or Night Intensity Levels
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      bool day          - If true the daytime intensity is being set
//      int intensity     - Intensity - Value between 0 and 15
//      bool deflt        - If true the intensity is saved in EEPROM and remembered.
//
void FlightSimGaugeHardware::ClockSetDisplayIntensity(int clock_address, bool day, int intensity, bool deflt)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Set Intensity :" 
                                         << " Speed " << (day?"Day":"Night")
                                         << " Intensity " << intensity
                                         << " Default " << (deflt?"On":"Off")
                                         << Trace::EndLog();

    std::vector<unsigned char> buffer;
    buffer.push_back(START_BYTE);
    buffer.push_back(clock_address);
    buffer.push_back(9);
    buffer.push_back(CLOCK_CMD_CHECK | CLOCK_CMD_SET_INTENSITY);
    buffer.push_back( CLOCK_DATA_CHECK | (day?0:1));
    buffer.push_back( CLOCK_DATA_CHECK | intensity);
    buffer.push_back( CLOCK_DATA_CHECK | (deflt?1:0));
    buffer.push_back(CLOCK_CHECK_BYTE);
    buffer.push_back(END_BYTE);
    SendCommand(buffer);
}

//  Function:       FlightSimGaugeHardware::ClockSetTime
//
//  Description:    Sets the Time in the last 6 digits. (The first digit is blank)
//                  Values are 0 padded.
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      int hours - 0-23
//      int mins  - 0-59
//      int secs  - 0-59
//
void FlightSimGaugeHardware::ClockSetTime(int clock_address, int hours, int mins, int secs)
{
    //Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Setting Time " << hours << ":" << mins << ":" << secs << Trace::EndLog();

    std::vector<int> time_buffer;
    time_buffer.push_back( CLOCK_DATA_CHECK | CLOCK_SPACE); // First Digit = Blank
    time_buffer.push_back( CLOCK_DATA_CHECK | hours/10);
    time_buffer.push_back( CLOCK_DATA_CHECK | hours%10);
    time_buffer.push_back( CLOCK_DATA_CHECK | mins/10);
    time_buffer.push_back( CLOCK_DATA_CHECK | mins%10);
    time_buffer.push_back( CLOCK_DATA_CHECK | secs/10);
    time_buffer.push_back( CLOCK_DATA_CHECK | secs%10);

    ClockSetDigits(clock_address, time_buffer);
}

//  Function:       FlightSimGaugeHardware::ClockSetSpeed
//
//  Description:    Sets the Speed in the first 3 digits. (The other digits are blank)
//                  Value is 0 padded.
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      int speed - 0-999
//
void FlightSimGaugeHardware::ClockSetSpeed(int clock_address, int speed)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Setting Speed " << speed << Trace::EndLog();

    std::vector<int> speed_buffer;

    // Speed is limited to 0 to 999 km/h
    if (speed > 999) speed = 999;
    if (speed < 0) speed = 0;
    
    // For now 0 pad the speed
    speed_buffer.push_back( CLOCK_DATA_CHECK | (speed/100)%10);
    speed_buffer.push_back( CLOCK_DATA_CHECK | (speed/10)%10);
    speed_buffer.push_back( CLOCK_DATA_CHECK | speed%10);
    speed_buffer.push_back( CLOCK_DATA_CHECK | CLOCK_SPACE);
    speed_buffer.push_back( CLOCK_DATA_CHECK | CLOCK_SPACE);
    speed_buffer.push_back( CLOCK_DATA_CHECK | CLOCK_SPACE);
    speed_buffer.push_back( CLOCK_DATA_CHECK | CLOCK_SPACE);

    ClockSetDigits(clock_address, speed_buffer);
}

//  Function:       FlightSimGaugeHardware::ClockInit
//
//  Description:    Initialise the clock
//
//  Parameters:
//      int clock_address - Address of flight sim gauge
//      int speed - 0-999
//
void FlightSimGaugeHardware::ClockInit(int clock_address, int day_intensity, int night_intensity)
{
    Trace::g_plog->STAMP(Trace::VERBOSE) << "Command: Clock Init " << Trace::EndLog();

    // Display Time hard coded to Simulator time.
    ClockSetDisplayMode(clock_address,false);
    
    // Turn off Clock Led and Disable Display
    ClockSwitchIndicatorsAndDisplay(clock_address, false, false, false);

    // Define Default Day and Night Intensities.
    // TODO - Create Properties for these if required to Tune them
    ClockSetDisplayIntensity(clock_address, true, 5, true);
    ClockSetDisplayIntensity(clock_address, false, 13, true);

    // Choose the Day intensity as default
    ClockSwitchIntensity(clock_address,true);

}

//  Function:       FlightSimGaugeHardware::SendCommand
//
//  Description:    Queues a command for sending
//
//  Parameters:
//      const std::vector<unsigned char> &command - command to send

void FlightSimGaugeHardware::SendCommand(const std::vector<unsigned char> &command, bool log)
{

    if (log) Trace::g_plog->STAMP(Trace::VERBOSE) << "Command Buffer = " << hexdump(command) << Trace::EndLog();
   
    // Add to the queue and set the send event
    const OS::MutexLock LOCK_SEND(m_mutex_send);

    m_custom_commands.push(command);
    m_event_send.Set();
}

//  Function:       LynxServoHardware::SendThread
//
//  Description:    The send thread. Sends commands on request
//
//  Notes:          Any failure to write is ignored

unsigned long FlightSimGaugeHardware::SendThread()
{
    while(m_event_send.Wait(), !m_kill_threads)
    {
        while(!m_kill_threads)
        {
            bool no_more_commands = false;
            vector<unsigned char> command;

            {
                const OS::MutexLock LOCK_SEND(m_mutex_send);
                no_more_commands = m_custom_commands.empty();

                if(!no_more_commands)
                {
                    command = m_custom_commands.front();
                    m_custom_commands.pop();
                }
            }

            if(no_more_commands)
                break;

            DWORD bytes_written;
            WriteFile(m_hport, &command[0], static_cast<DWORD>(command.size()), &bytes_written, NULL);
        }
    }

    return 0;
}
