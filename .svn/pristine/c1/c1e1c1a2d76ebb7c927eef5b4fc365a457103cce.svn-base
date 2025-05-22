//******************************************************************************
//
//  File:           FlightSimGaugeHardware.h
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
#ifndef FLIGHTSIM_GAUGE_HARDWARE_H
#define FLIGHTSIM_GAUGE_HARDWARE_H

#include <common/OSThreadClasses.h>

#include <vector>
#include <queue>

//  Class:          FlightSimGaugeHardware
//
//  Description:    Communicates with Flight Sim Gauge Hardware

class FlightSimGaugeHardware
{
public:
    FlightSimGaugeHardware(const char *port, int baud_rate, int data_bits, int parity, int stop_bits);
    ~FlightSimGaugeHardware();

    // Positional Commands
    void SetPosition(int gauge_address, bool first_needle, double position, bool log=false);
    void SetLights(int gauge_address, bool display_on, bool backlight_on, int intensity=0, bool log=false);
	void SetRedLight(int gauge_address, bool red_light_on, bool log=false);

    // Clock Commands
    void ClockSetDigits(int clock_address, const std::vector<int> digits1_7);
    void ClockSetInternalClock(int clock_address, int hours, int mins, int secs);
    void ClockSetDisplayMode(int clock_address, bool internal_clock);
    void ClockSwitchIntensity(int clock_address, bool daytime);
    void ClockSwitchIndicatorsAndDisplay(int clock_address, bool speed_led_on, bool clock_led_on, bool display_on); 
    void ClockSetDisplayIntensity(int clock_address, bool day, int intensity, bool deflt);
    // Utility commands
    void ClockInit(int clock_address, int day_intensity=0, int night_intensity=0);
    void ClockSetTime(int clock_address, int hours, int mins, int secs);
    void ClockSetSpeed(int clock_address, int speed);

private:
    unsigned long SendThread();

    HANDLE m_hport;

    void SendCommand(const std::vector<unsigned char> &command, bool log = false);

    // Commands sent, including text, are done as commands, placed on a queue
    OS::Mutex m_mutex_send;
    OS::Event m_event_send;
    std::queue<std::vector<unsigned char> > m_custom_commands;


    // Dynamically created threads for the send and receive queues
    OS::Thread *m_pthread_send;

    bool m_kill_threads;

};

#endif // FLIGHTSIM_GAUGE_HARDWARE_H
