#include "pch.h"
//#include "ReplyPlusAPIInterface.h"
#include "ReplyPlusAPIWrapper.h"
#include <algorithm>

using namespace SMS;


void Hardware::AttachObserver(Observer *observer) 
{
    m_observers.push_back(observer);
}

void Hardware::DetachObserver(Observer *observer) 
{
    m_observers.erase(remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
}

void Hardware::PlusBaseOnDebug( const char* base_serial, const char* message ) 
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnDebug(base_serial, message);
    }
}

void Hardware::PlusBaseOnError( const char* base_serial, const char* error )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnError(base_serial, error);
    }
}

void Hardware::PlusBaseOnDuplicateID( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnDuplicateID(base_serial, keypad_serial, keypad_id );
    }
}

void Hardware::PlusBaseOnKeypadAlert( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadAlert(base_serial, keypad_serial, keypad_id );
    }
}

void Hardware::PlusBaseOnKeypadPing( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadPing(base_serial, keypad_serial, keypad_id);
    }
}
void Hardware::PlusBaseOnLowBatteryWarning( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnLowBatteryWarning(base_serial, keypad_serial, keypad_id);
    }
}

void Hardware::PlusBaseOnKeypadLogin( const char* base_serial, const char* keypad_serial, const char* password )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadLogin(base_serial, keypad_serial, password);
    }
}

void Hardware::PlusBaseOnKeypadMsgTimeout( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadMsgTimeout(base_serial, keypad_serial, keypad_id);
    }
}

void Hardware::PlusBaseOnKeypadNotAuthorized( const char* base_serial, const char* keypad_serial )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadNotAuthorized(base_serial, keypad_serial);
    }
}

void Hardware::PlusBaseOnMessageAck( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnMessageAck(base_serial, keypad_serial, keypad_id);
    }
}

void Hardware::PlusBaseOnMomentToMoment( const char* base_serial, const char* keypad_serial, int keypad_id, int battery_level, const char* moment_data )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnMomentToMoment(base_serial, keypad_serial, keypad_id, battery_level, moment_data);
    }
}

void Hardware::PlusBaseOnSMSVoteTimeout( const char* base_serial, const char* keypad_serial, int question_number, const char* vote_data )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnSMSVoteTimeout(base_serial, keypad_serial, question_number, vote_data);
    }
}

void Hardware::PlusBaseOnTrainingRequest(const char* base_serial, const char* keypad_serial, int battery_level, const char* version, int requested_base_id, int current_base_id, int group, int address)
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnTrainingRequest(base_serial, keypad_serial, battery_level, version, requested_base_id, current_base_id, group, address );
    }
}

void Hardware::PlusBaseOnTrainingAck( const char* base_serial, const char* keypad_serial, int battery_level, const char* version, int base_id, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnTrainingAck(base_serial, keypad_serial, battery_level, version, base_id, keypad_id );
    }
}

void Hardware::PlusBaseOnKeypadConnect(const char* base_serial, const char* keypad_serial)
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadConnect(base_serial, keypad_serial);
    }
}

