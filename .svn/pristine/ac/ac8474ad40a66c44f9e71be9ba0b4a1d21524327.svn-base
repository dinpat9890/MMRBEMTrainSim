//******************************************************************************
//
//  File:           ArduinoHardware.cpp
//
//  Description:    Class for communicating with a Arduino LCD and 
//                  keypad
//                  
//  Reference:      First Great Western 0060J79A
//
//  Author:         James Errington, Peter Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2013
//
//******************************************************************************
#include "ArduinoHardware.h"
#include "common/StandardLogging.h"
#include "common/LexicalCast.h"

//#define GSMR_DEBUG

using namespace std;

namespace
{
    // Number of key presses that are buffered. After this they are dropped
    const int KEYPRESS_LIMIT = 10;

    const int MESSAGE_TYPE_UNSET   = -1;
    const int MESSAGE_TYPE_PRESS   =  2;
    const int MESSAGE_TYPE_RELEASE =  3;

    const int MODULE_VK_202_25  = 0x0E;
    const int MODULE_LK_404_55  = 0x0A;
    const int MODULE_LK_404_25  = 0x73;

    //  Function:       ConvertVersion
    //
    //  Description:    Converts a version from string format to Matrix Orbital 
    //                  format
    //
    //  Parameters:
    //      const std::string &version - version as A.B
    //
    //  Return value:
    //      int              - version in hex AB
    
    int ConvertVersion(const std::string &version)
    {
        int ret = 0;
        
        if(!version.empty())
        {
            double dversion = Common::LexicalCast<double>(version);

            // Version A.B is in hex AB
            ret = static_cast<int>(dversion * 10.0);
            ret = ((ret / 10) << 4) | (ret % 10);
        }

        return ret;
    }

    //  Function:       ConvertVersion
    //
    //  Description:    Converts a version from Matrix Orbital format to string
    //                  format
    //
    //  Parameters:
    //      int              - version in hex AB
    //
    //  Return value:
    //      std::string version - version as A.B

    std::string ConvertVersion(int version)
    {
        std::string ret;
        
        if(version != 0)
            ret = 
            Common::LexicalCast<std::string, int>(version >> 4) + "." + Common::LexicalCast<std::string, int>(version & 0x0F);

        return ret;
    }
}

//  Function:       ArduinoHardware::GetModuleTypeConfiguration
//
//  Description:    Obtains configuration for the specified module and version.
//
//  Parameters:
//      int module_type  - Module type as used by Matrix Orbital
//      int module_version - Version as used by Matrix Orbital
//
//  Return value:
//      ArduinoHardware::Configuration - parameters that vary this device 
//                          from others

ArduinoHardware::Configuration ArduinoHardware::GetModuleTypeConfiguration(int module_type, int module_version)
{
    Configuration config;
    config.module_type    = module_type;
    config.module_version = ConvertVersion(module_version);

    config.display_cols = 20; 
    config.display_rows = 4; 

    // Otherwise use defaults
    return config;
}

//  Function:       ArduinoHardware::GetModuleTypeConfiguration
//
//  Description:    Obtains configuration for the specified module and version.
//
//  Parameters:
//      const std::string &module_name - Module name as a string, eg VK202_25
//      const std::string &module_version - Version number as a string A.B
//
//  Return value:
//      ArduinoHardware::Configuration - parameters that vary this device 
//                          from others

ArduinoHardware::Configuration ArduinoHardware::GetModuleTypeConfiguration(const std::string &module_name, const std::string &module_version)
{
    int module_id         = 0;
    int module_version_id = ConvertVersion(module_version);

    if(module_name == "VK202_25")
        module_id = MODULE_VK_202_25;
    else if(module_name == "LK404_25")
        module_id = MODULE_LK_404_25;
    else if(module_name == "LK404_55")
        module_id = MODULE_LK_404_55;
    else if(module_name != "")
        throw CommonException("Invalid module name ") << module_name;

    return GetModuleTypeConfiguration(module_id, module_version_id);
}

//  Function:       ArduinoHardware::ArduinoHardware
//
//  Description:    Constructor. Initialises a communications port and then 
//                  creates the send and receive threads
//
//  Parameters:
//      const char *port - Communications port, eg COM1
//      int line_width   - Width of the LCD screen
//      int line_count   - How many lines the LCD screen has

ArduinoHardware::ArduinoHardware(const char *port, const std::string &module_type, const std::string &module_version)
: m_config(GetModuleTypeConfiguration(module_type, module_version)), m_kill_threads(false), m_pthread_send(0), m_pthread_recv(0)
{
    // Open the serial port.
    m_hport = CreateFile (port, // Pointer to the name of the port
                      GENERIC_READ | GENERIC_WRITE,
                                    // Access (read-write) mode
                      0,            // Share mode
                      NULL,         // Pointer to the security attribute
                      OPEN_EXISTING,// How to open the serial port
                      0,            // Port attributes
                      NULL);        // Handle to port with attribute

    if(m_hport == INVALID_HANDLE_VALUE)
        throw CommonException(FLSTAMP, "Could not open COM port");

    DCB PortDCB;

    // Initialize the DCBlength member. 
    PortDCB.DCBlength = sizeof (DCB); 

    // Get the default port setting information.
    GetCommState (m_hport, &PortDCB);

    // Change the DCB structure settings.
    PortDCB.BaudRate = CBR_9600;          // Current baud
    PortDCB.fBinary = TRUE;               // Binary mode; no EOF check 
    PortDCB.fParity = FALSE;              // Enable parity checking 
    PortDCB.fOutxCtsFlow = FALSE;         // No CTS output flow control 
    PortDCB.fOutxDsrFlow = FALSE;         // No DSR output flow control 
    PortDCB.fDtrControl = DTR_CONTROL_DISABLE;//ENABLE; 
                                          // DTR flow control type 
    PortDCB.fDsrSensitivity = FALSE;      // DSR sensitivity 
    PortDCB.fTXContinueOnXoff = TRUE;     // XOFF continues Tx 
    PortDCB.fOutX = FALSE;                // No XON/XOFF out flow control 
    PortDCB.fInX = FALSE;                 // No XON/XOFF in flow control 
    PortDCB.fErrorChar = FALSE;           // Disable error replacement
    PortDCB.fNull = FALSE;                // Disable null stripping 
    PortDCB.fRtsControl = RTS_CONTROL_DISABLE;//ENABLE; 
                                          // RTS flow control 
    PortDCB.fAbortOnError = FALSE;        // Do not abort reads/writes on 
                                          // error
    PortDCB.ByteSize = 8;                 // Number of bits/byte, 4-8 
    PortDCB.Parity = NOPARITY;            // 0-4=no,odd,even,mark,space 
    PortDCB.StopBits = ONESTOPBIT;        // 0,1,2 = 1, 1.5, 2 

    // Configure the port according to the specifications of the DCB 
    // structure.
    if (!SetCommState (m_hport, &PortDCB))
    {
        CloseHandle(m_hport);
        throw CommonException(FLSTAMP, "Could not set CommState");
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
        throw CommonException(FLSTAMP, "Could not set CommTimeouts");
    }

    // Spawn send and receive threads
    m_pthread_send = new OS::Thread(MemberCallback<unsigned long, ArduinoHardware>(this, &ArduinoHardware::SendThread));
    m_pthread_recv = new OS::Thread(MemberCallback<unsigned long, ArduinoHardware>(this, &ArduinoHardware::RecvThread));
}

//  Function:       ArduinoHardware::~ArduinoHardware
//
//  Description:    Destructor. Closes the send and receive threads, and then 
//                  the communications port

ArduinoHardware::~ArduinoHardware()
{
    // Signal threads to close
    m_kill_threads = true;
    m_event_send.Set();

    // Wait for threads to close
    m_event_send_closed.Wait();
    m_event_recv_closed.Wait();

    // Delete the threads
    delete m_pthread_send;
    delete m_pthread_recv;

    // Close the serial connection
    CloseHandle(m_hport);
}

//  Function:       ArduinoHardware::SetText
//
//  Description:    Sets the text seen on the screen
//
//  Parameters:
//      const vector<string> &lines - Text to be shown, line by line

void ArduinoHardware::SetText(const vector<string> &lines)
{
    // Compose the command(s)
    vector<unsigned char> display_text_string;

    // if there is nothing in the vector, or there are no strings that are non-empty, just use the 'clear screen' command.
    // This is just a small optimisation.
    if (lines.empty() || std::find_if(lines.begin(), lines.end(), [](const auto& line) { return line != ""; }) == lines.end())
    {
        //display_text_string.push_back(0x15);      // Display Clear
        //display_text_string.push_back(0x16);      // Cursor Home
    }
    else
    {
    
        // send the struct_screen_data message type
        display_text_string.push_back(0x04); 

        // set the start index
        display_text_string.push_back(0x00); // Doesn't look like this is used.  

        // set the length
        display_text_string.push_back(0x50); // decimal 80. We write every digit even if the message is less than 80 digits. 

        vector<unsigned char> buf(80, ' ');

        copy(lines[0].begin(), lines[0].begin() + min(static_cast<size_t>(80), lines[0].size()), buf.begin());
 
        // FIXME
        // Horrible hack to convert chracters into what we want on the target display.
        // This probably belongs in the Arduino code.
        replace(buf.begin(), buf.end(), unsigned char(0x00), unsigned char(' '));
        replace(buf.begin(), buf.end(), unsigned char(0x88), unsigned char(0xEF));

        display_text_string.insert(display_text_string.end(), buf.begin(), buf.end());
    }

    const OS::MutexLock LOCK_SEND(m_mutex_send);
    m_custom_commands.push(display_text_string);
    m_event_send.Set();
}

//  Function:       ArduinoHardware::SetStartUpScreen
//
//  Description:    Sets the startup scren to the specified text. This the 
//                  screen shown when the display is turned on, but no messages 
//                  have been sent to it
//
//  Parameters:
//      const std::vector<std::string> &lines - Startup text
//
//  Notes:          Not used in simulation

void ArduinoHardware::SetStartUpScreen(const std::vector<std::string> &lines)
{
    // Compose the command(s)
    vector<unsigned char> display_text_string;

    display_text_string.push_back(0x04);
    display_text_string.push_back(0x00);
    display_text_string.push_back(0x1B);
    display_text_string.push_back('h');
    display_text_string.push_back('e');
    display_text_string.push_back('l');
    display_text_string.push_back('l');
    display_text_string.push_back('o');
    display_text_string.push_back('t');
    display_text_string.push_back('h');
    display_text_string.push_back('e');
    display_text_string.push_back('r');
    display_text_string.push_back('e');
    display_text_string.push_back('h');
    display_text_string.push_back('o');
    display_text_string.push_back('w');
    display_text_string.push_back('a');
    display_text_string.push_back('r');
    display_text_string.push_back('e');
    display_text_string.push_back('y');
    display_text_string.push_back('o');
    display_text_string.push_back('u');
    display_text_string.push_back('i');
    display_text_string.push_back('t');
    display_text_string.push_back('i');
    display_text_string.push_back('s');
    display_text_string.push_back('v');
    display_text_string.push_back('e');
    display_text_string.push_back('r');
    display_text_string.push_back('y');

    const OS::MutexLock LOCK_SEND(m_mutex_send);
    m_custom_commands.push(display_text_string);
    m_event_send.Set();
}

//  Function:       ArduinoHardware::GetNextKeyAction
//
//  Description:    Retrieves the next key action received if there is one in the
//                  buffer
//
//  Parameters:
//      int &key         - Key received
//      bool &pressed    - True if pressed
//
//  Return value:
//      bool             - True if there was a key in the buffer
//
//  Notes:          Key presses and releases are recorded. Add KEY_UP to the key
//                  to get the value that corresponds to a key up

bool ArduinoHardware::GetNextKeyAction(int &key, bool &pressed)
{
    const OS::MutexLock LOCK_RECV(m_mutex_recv);

    bool ret = !m_key_actions.empty();

    if(ret)
    {
        key = m_key_actions.front().first;
        pressed = m_key_actions.front().second;
        m_key_actions.erase(m_key_actions.begin());
    }

    return ret;
}

//  Function:       ArduinoHardware::SetOutput
//
//  Description:    Sets the output state of the specified port
//
//  Parameters:
//      int port         - Port number
//      bool state       - true if turning the output on

void ArduinoHardware::SetOutput(int port, bool state)
{
    vector<unsigned char> set_output_string;

    if(!m_config.multi_port)
    {
        // Compose the command (note 0x57 is on for port != 0,
        // not 0x56 as in documentation)
        set_output_string.push_back(0xFE);
        set_output_string.push_back((state ^ (port != 0)) ? 0x56 : 0x57);

        if(port != 0)
            set_output_string.push_back(port);
    }
    else
    {
        set_output_string.push_back(0xFE);
        set_output_string.push_back(state ? 0x57 : 0x56);
        set_output_string.push_back(port);
    }

    // Add to the queue and set the send event
    const OS::MutexLock LOCK_SEND(m_mutex_send);
    m_custom_commands.push(set_output_string);
    m_event_send.Set();
}

//  Function:       ArduinoHardware::SetButtonLight
//
//  Description:    Turns button backlight on or off
//
//  Parameters:
//      bool state       - true if on
//      int id           - id of the light to switch on/off

void ArduinoHardware::SetButtonLight(bool state, int id)
{
    // Compose the command
    vector<unsigned char> set_backlight_string;
    set_backlight_string.push_back(state ? 0x05 : 0x06);
    set_backlight_string.push_back(id);

    // Add to the queue and set the send event
    const OS::MutexLock LOCK_SEND(m_mutex_send);
    m_custom_commands.push(set_backlight_string);
    m_event_send.Set();
}

//  Function:       ArduinoHardware::SendThread
//
//  Description:    The send thread. Initialises the screen and writes to it on
//                  request
//
//  Notes:          Any failure to write is ignored

unsigned long ArduinoHardware::SendThread()
{

    while(m_event_send.Wait(), !m_kill_threads)
    {
        while(true)
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

            // FIXME this block looks unused (everything falls through to the else statement)
            // Special case for setting the startup screen
            // Requires a 10ms delay per character
            if(command.size() >= 2 && command[0] == 0x15 && command[1] == 0x16)
            {
                for(size_t i = 0; i < command.size(); ++i)
                {
                    WriteFile(m_hport, &command[i], static_cast<DWORD>(1), &bytes_written, NULL);
                    Sleep(10);
                }
            }
            else
                WriteFile(m_hport, &command[0], static_cast<DWORD>(command.size()), &bytes_written, NULL);

#ifdef GSMR_DEBUG
            Trace::g_plog->STAMP(Trace::INFO);
            for(size_t i = 0; i < command.size(); ++i)
            {
                char thechar[3];
                sprintf(thechar, "%02X", command[i]);
                *Trace::g_plog << "W: " << thechar << " ";
            }
            *Trace::g_plog << Trace::EndLog();
#endif
        }
    }

    m_event_send_closed.Set();

    return 0;
}



//  Function:       ArduinoHardware::RecvThread
//
//  Description:    Receive thread. Any data received is assumed to be a 
//                  keypress and placed in a buffer.
//
//  Notes:          If a failure to read occurs, the thread is exited

unsigned long ArduinoHardware::RecvThread()
{
    // the current action type being processed
    // it's possible to get partial messages over serial,
    // so we need to save whatever we read between read cycles.
    // Possibly a better way to do this is to queue up unprocessed bytes 
    // until we have a whole message.
    // Given that messages are 2 bytes long, that doesn't seem worth the extra effort.
    int message_type = MESSAGE_TYPE_UNSET;

    while(!m_kill_threads)
    {
        char buf[1024];
        DWORD bytes_read;

        ::Sleep(5);

        // Read data from the serial connection.
        if(ReadFile(m_hport, buf, 1024, &bytes_read, NULL) == 0)
        {
            // Unrecoverable error, terminate now
          //  Trace::g_plog->STAMP(Trace::ERROR) << "Received thread failed." << Trace::EndLog();
            break;
        }

        // If there were bytes read, store these in the buffer up to the limit
        if(bytes_read != 0)
        {
            const OS::MutexLock LOCK_RECV(m_mutex_recv);

            for(size_t i = 0; i < bytes_read; ++i)
            {
                if(m_key_actions.size() < KEYPRESS_LIMIT)
                {
#ifdef GSMR_DEBUG
                    Trace::g_plog->STAMP(Trace::INFO) << "Reading byte '" << static_cast<int>(buf[i]) << "' from serial port." << Trace::EndLog();
#endif

                    if (message_type == MESSAGE_TYPE_UNSET)
                    {
                      message_type = buf[i];
                    }
                    else
                    {
                        if (message_type == MESSAGE_TYPE_PRESS)
                        {
                            m_key_actions.push_back(KeyAction(buf[i], true));
                        }
                        else if (message_type == MESSAGE_TYPE_RELEASE)
                        {
                            m_key_actions.push_back(KeyAction(buf[i], false)); 
                        }
                        else
                        {
                            Trace::g_plog->STAMP(Trace::INFO) << "Unknown message type '" << static_cast<int>(buf[i]) << "' recieved from serial port." << Trace::EndLog();
                        }

                        message_type = MESSAGE_TYPE_UNSET;
                    }
                }
            }
        }

        // Conserve CPU
        ::Sleep(10);
    }

    m_event_recv_closed.Set();

    return 0;
}
