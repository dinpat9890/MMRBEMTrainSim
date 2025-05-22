//******************************************************************************
//
//  File:           ArduinoHardware.h
//
//  Description:    Class for communicating with an Arduino LCD and 
//                  keypad
//
//  Reference:      Chiltern, AC05 - 003
//
//  Author:         James Errington, Peter Cooper
//
//  (C) Copyright:  SYDAC Pty Ltd, 2012
//
//******************************************************************************
#ifndef ARDUINO_HARDWARE_H
#define ARDUINO_HARDWARE_H

#include <common/OSThreadClasses.h>

#include <string>
#include <vector>
#include <queue>

//  Class:          ArduinoHardware
//
//  Description:    Communicates with Arduino devices

class ArduinoHardware
{
public:
    //  Class:          KeypadPinOrder
    //
    //  Description:    Order of the pins connecting to the keypad membrane.
    
    enum KeypadPinOrder
    {
        COLUMNROW, //eg C1C2C3C4C5R1R2R3R4R5
        ROWCOLUMN  //eg R1R2R3R4R5C1C2C3C4C5
    };

    //  Structure:      Configuration
    //
    //  Description:    Configuration of an Arduino device, allowing the 
    //                  hardware to work with variants.
    
    struct Configuration
    {
        int         module_type;     // Identifier of the module

        std::string module_name;     // Module name, eg VK202_25
        std::string module_version;  // Version,     eg 5.8

        bool multi_port;             // If true, the multi-port syntax is used

        KeypadPinOrder keypad_pin_order; // Order of the pins

        int  keypad_rows;            // Number of row pins for the keypad
        int  keypad_cols;            // Number of column pins for the keypad
        int  keypad_base_value;      // Base value, from which keypress values begin
        int  keypad_key_up_modifier; // Modifier added to a keypress to indicate a key released.

        int  display_rows; // Number of rows on the display
        int  display_cols; // Number of columns on the display

        Configuration()
            : multi_port(false), keypad_pin_order(ROWCOLUMN), keypad_base_value(0x08), keypad_rows(5), keypad_cols(11), keypad_key_up_modifier(0x40), display_rows(4), display_cols(20)
        {
        }
    };

public:
    ArduinoHardware(const char *port, const std::string &module_type = "", const std::string &module_version = "");
    ~ArduinoHardware();

    void SetText(const std::vector<std::string> &display_lines);
    bool GetNextKeyAction(int &key, bool &press);

    void SetOutput(int port, bool state);
    void SetButtonLight(bool state, int id);

    void SetStartUpScreen(const std::vector<std::string> &display_lines);

    static Configuration GetModuleTypeConfiguration(const std::string &module_name, const std::string &module_version);
    static Configuration GetModuleTypeConfiguration(int module_type, int module_version = 0);

private:
    void SetKeyUpMode(bool auto_repeat);

    Configuration m_config;

    unsigned long SendThread();
    unsigned long RecvThread();

    HANDLE m_hport;

    // Commands sent, including text, are done as commands, placed on a queue
    OS::Mutex m_mutex_send;
    OS::Event m_event_send;
    std::queue<std::vector<unsigned char> > m_custom_commands;

    OS::Mutex m_mutex_recv;

    // each action is a Key ID and a bool indicating if the button have been pressed
    typedef std::pair<int, bool> KeyAction;
    std::vector<KeyAction> m_key_actions;

    // Dynamically created threads for the send and receive queues
    OS::Thread *m_pthread_send;
    OS::Thread *m_pthread_recv;

    bool m_kill_threads;
    OS::Event m_event_send_closed;
    OS::Event m_event_recv_closed;
};

#endif // MATRIX_ORBITAL_HARDWARE_H
