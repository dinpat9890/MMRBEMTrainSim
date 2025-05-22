/// @file      RadioState.h
///            Capture the state of Radio subsystem.
///
/// @copyright (C) Copyright:  OKTAL SYDAC Pvt Ltd, 2022

#ifndef RADIO_STATE_H
#define RADIO_STATE_H

#include <vector>
#include <map>
#include <set>

struct EmergencySpecialMsgState
{
    int id = -1;
    std::string code;
    bool stop_status = true;
    int count = 1;
};

enum class CallState
{
    INACTIVE = 0,
    CALL_REQUEST = 1,
    CALL_CONNECTED = 2,
};
const int RADIO_CALL_INACTIVE = 0;

class RadioState
{
public:
    enum class State { unknown, inactive, powering_on, auto_announce, semi_auto_announce, manual_announce };

    State getState() const { return m_state; }

private:

    State m_state{ State::unknown };

   

public:
    
    int                           m_intercom_output{ 0 };
    int                           m_radio_intercom_state{ 0 };
    int                           m_radio_call_type{ 0 };

};

#endif