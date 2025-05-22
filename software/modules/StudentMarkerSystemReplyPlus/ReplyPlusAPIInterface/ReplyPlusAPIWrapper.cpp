///******************************************************************************
///
/// @File: ReplyPlusAPIWrapper.cpp
///
/// @Description: This application exposes functions those are required to 
///               Communicate with Fleatwood Group (Reply Plus) device.
///               Base Communication and System Identification Methods
/// @Reference: WRS970_API_Programmers_Guide_3_2_3 and 
///             Reply Plus .Net API Programmers Guide 1_0_7
///
/// @Author: Deepankar Chakraborty
///          Pradeep Prajapati
///
/// @Copyright: SYDAC Pty Ltd, 2015
///
///******************************************************************************

#include "pch.h"
#include "ReplyPlusAPIWrapper.h"


using namespace System;
using namespace System::Runtime::InteropServices; // Marshal
using namespace ReplyPlusAPI;
using namespace SMS;


extern "C"
{
    __declspec(dllexport) SMS::Hardware* __cdecl MakeResponseHardware()
    {
        return new SMS::ReplyPlusHardware();
    }
}

/// Constructor

ReplyPlusHardware::ReplyPlusHardware()
{
    m_plus_base_api_wrapper = gcnew ReplyPlusAPIWrapper(*this);

    m_observers_mutex = gcnew Mutex();
}

void ReplyPlusHardware::AttachObserver(Observer *observer) 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_observers.push_back(observer);
}

void ReplyPlusHardware::DetachObserver(Observer *observer) 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_observers.erase(remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
}

/// An Event triggered to provide helpfull debug messages describing the details 
/// of processing of the API. The event is only triggered if the 
/// DebugEventsEnabled property set is true.
///
/// @param base_serial device serial code
/// @param message debug message

void ReplyPlusHardware::PlusBaseOnDebug( const char* base_serial, const char* message ) 
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnDebug(base_serial, message);
    }
}

/// An event triggered to provide errors that may occur in the API. 
/// The event is only triggered if ErrorEventsEnabled property is set to true.
///
/// @param base_serial device serial code
/// @param error error message

void ReplyPlusHardware::PlusBaseOnError( const char* base_serial, const char* error )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnError(base_serial, error);
    }
}

/// An event triggered when a keypad votes at tghe address or Keypad ID of the another keypad. 
/// This event occurs no matter which addressing mode is in use. This event not trigger when a
/// keypad serial number of zeroes is being added over a valid serial number of vice versa.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusHardware::PlusBaseOnDuplicateID( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnDuplicateID(base_serial, keypad_serial, keypad_id );
    }
}

/// An event is triggered when the alert key is pressed on the keypad. 
/// This event is only triggered if KeypadAlertEnabled property is set to true
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusHardware::PlusBaseOnKeypadAlert( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadAlert(base_serial, keypad_serial, keypad_id );
    }
}

/// An event triggered upon the response of the keypads where the ping Timer time has expired.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusHardware::PlusBaseOnKeypadPing( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadPing(base_serial, keypad_serial, keypad_id);
    }
}

/// An error triggered by a keypad with a low battery
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusHardware::PlusBaseOnLowBatteryWarning( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnLowBatteryWarning(base_serial, keypad_serial, keypad_id);
    }
}

/// An event triggered when a keypad has requested to login to the system.
/// Upon determining if the keypad data is valid, the KeypadLoginResult 
/// method should be called within this event. First, Login can be used 
/// globally such that each keypad connceting to the system must enter the 
/// same login value. An alternate option is to compare the serial number of 
/// the login data against a table of specific login values per keypad serial number.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param password password to login

void ReplyPlusHardware::PlusBaseOnKeypadLogin( const char* base_serial, const char* keypad_serial, const char* password )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadLogin(base_serial, keypad_serial, password);
    }
}

/// An event triggered when a keypad has not responded from SendMsgByID 
/// or SendMsgBySerial method calls within the timeout period.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusHardware::PlusBaseOnKeypadMsgTimeout( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadMsgTimeout(base_serial, keypad_serial, keypad_id);
    }
}

/// An event triggered when the system is a static system, authentication is true and 
/// a keypad outside of the keypad list attemts to vote.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code

void ReplyPlusHardware::PlusBaseOnKeypadNotAuthorized( const char* base_serial, const char* keypad_serial )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadNotAuthorized(base_serial, keypad_serial);
    }
}

/// An event triggered when a keypad has shown its keypad specific message on the LCD. 
/// This event is triggered only on the call of the SendMsgByID or SendMsgBySerial methods 
/// and returs serial number anbd keypad ID of a responding keypad. 
/// The MessageAckEnabled property must be set to true to receive this event.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusHardware::PlusBaseOnMessageAck( const char* base_serial, const char* keypad_serial, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnMessageAck(base_serial, keypad_serial, keypad_id);
    }
}

/// An event triggered when a keypad sends its moment to moment data
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id
/// @param battery_level 
/// @param moment_data

void ReplyPlusHardware::PlusBaseOnMomentToMoment( const char* base_serial, const char* keypad_serial, int keypad_id, int battery_level, const char* moment_data )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnMomentToMoment(base_serial, keypad_serial, keypad_id, battery_level, moment_data);
    }
}

/// Property set to limit the time the keyopad is allowed to continue tp transmit 
/// up to 140 characters of a vote before triggering the OnSMSVoteTimeout event. 
/// The default is 40000 or 40 seconds.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param question_number question for which the timeout happened.
/// @param vote_data vote for the above param

void ReplyPlusHardware::PlusBaseOnSMSVoteTimeout( const char* base_serial, const char* keypad_serial, int question_number, const char* vote_data )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnSMSVoteTimeout(base_serial, keypad_serial, question_number, vote_data);
    }
}

/// An event is fired when a keypad requests to be trained.
/// The result of this methode is the TrainKeypad method.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param battery_level battery level in numbers.
/// @param version 
/// @param requested_base_id base id of the device for which request has be initiated
/// @param current_base_id current base device id
/// @param group
/// @param address

void ReplyPlusHardware::PlusBaseOnTrainingRequest(const char* base_serial, const char* keypad_serial, int battery_level, const char* version, int requested_base_id, int current_base_id, int group, int address)
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnTrainingRequest(base_serial, keypad_serial, battery_level, version, requested_base_id, current_base_id, group, address );
    }
}

/// An event fired when the trained keypad has acknowledged its training
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param battery_level battery level in numbers.
/// @param version 
/// @param base_id current base device id
/// @param keypad_id keypad id

void ReplyPlusHardware::PlusBaseOnTrainingAck( const char* base_serial, const char* keypad_serial, int battery_level, const char* version, int base_id, int keypad_id )
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnTrainingAck(base_serial, keypad_serial, battery_level, version, base_id, keypad_id );
    }
}

/// An event triggered when a new keypad has joined the keypad list
/// 
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code

void ReplyPlusHardware::PlusBaseOnKeypadConnect(const char* base_serial, const char* keypad_serial)
{
    for(auto observer : m_observers)
    {
        observer->PlusBaseOnKeypadConnect(base_serial, keypad_serial);
    }
}

/// A method used to add a keypad dynamiclly to the system. The KeypadID 
/// assigned to the keypad is determined by the system. Even though the API 
/// automatically assign an address to the keypad, it first searches the list 
/// for the keypads' serial number and verifies it is not already in the list. 
/// If it is in the list, the keypad receives the ID already assigned. This 
/// means that a keypad powered down unexpectedly, receives the same ID it had 
/// previously. If the leypad is not in the list, it receives the next available 
/// address.
///
/// @param serial_number serial number of the key you wish to add.

bool ReplyPlusHardware::AddKeypad(const char* serial_number)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->AddKeypad(gcnew System::String(serial_number));
}

/// A method used to format a question by just answer type.
/// Using the properties described in this section.
/// Availabled Types:
/// atSingleAlpha, atSingleDigit, atYesNo, atYesAbstainNo, atAgreeDisagree
/// atLowMedHigh, atTrueFalse, atMomentToMoment, atMultiAlphaNumeric, atNegativePlus
/// atCustomSoftKeys
/// @param question_number question number
/// @param answer_type type from available types

void ReplyPlusHardware::BeginQuestion(int question_number, AnswerType answer_type)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->BeginQuestion(question_number, (ReplyPlusAPIControl::AnswerType)answer_type);
}

/// A method used to clear the messages from the API data Buffer.

void ReplyPlusHardware::ClearDataBuffer()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->ClearDataBuffer();
}

/// A method used to clear the entire keypad list.

void ReplyPlusHardware::ClearKeypadList()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->ClearKeypadList();
}

/// A method used to clear a message at a specific message index on a specific keypad,
/// defined by the keypad ID
///
/// @param keypad_id id of the keypad for which meesage needs to be cleared
/// @param message_index message index

void ReplyPlusHardware::ClearStoredMessageByID(int keypad_id, int message_index)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->ClearStoredMessageByID(keypad_id, message_index);
}

/// A method used to clear a message at a specific message index on a specific keypad.

void ReplyPlusHardware::ClearStoredMessageBySerial(const char* serial_number, int message_index)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->ClearStoredMessageBySerial(gcnew System::String(serial_number), message_index);
}

/// A method used to connect the PC to the based station via USB or TCP.
/// CommType must be set to desired connection before calling this method.
/// Method is called with a string identifying the TCP/IP address and an 
/// integer for port as parameters for a TCI/IP connection and a serial 
/// number for a USB connection. All products are shipped with a default
/// ID address of 200.0.078 and port 2101
///
/// @param serial_number base serial number or receiver serial code
///
/// @return true if connected otherwise false

bool ReplyPlusHardware::Connect(const char* serial_number)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->Connect(gcnew System::String(serial_number));
}

/// A method used to connect the PC to the based station via USB or TCP.
/// CommType must be set to desired connection before calling this method.
/// Method is called with a string identifying the TCP/IP address and an 
/// integer for port as parameters for a TCI/IP connection and a serial 
/// number for a USB connection. All products are shipped with a default
/// ID address of 200.0.078 and port 2101
///
/// @param ip_adress receiver system ip adress
/// @param Port port number
///
/// @return true if connected otherwise false

bool ReplyPlusHardware::Connect(const char* ip_address, int Port)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->Connect(gcnew System::String(ip_address), Port);
}

/// A method used to disconnect the PC from the base station. 
/// Calling this method does not lose the eypad list which is described later. 
/// As long as the instance of the API exists the keypad list will remain as is.

void ReplyPlusHardware::Disconnect()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->Disconnect();
}

/// GetAvailableBases - A method used to detect bases connected via USB.
/// A boolean parameter tells whether or not to include the name of the 
/// base along with the serial number. 
/// Results are comma "," delimited and the name is separated from the serial number with dash "-".
/// If not device is found the result is "No Device Found".

const char* ReplyPlusHardware::GetAvailableBases()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    String ^bases = m_plus_base_api_wrapper->m_plus_base->GetAvailableBases();

    return (const char*)Marshal::StringToHGlobalAnsi(bases).ToPointer();
}

/// A method to extract the next vote from the internal API buffer.
/// The vote infromation is delimited by the pipe symbol "|" and contains serial number,ID
/// Time, Version, Battery, Vote, KeypadType and Question Number. Once this is called 
/// Vote received is taken off of the internal API buffer.

const char* ReplyPlusHardware::GetNextKeypadVote()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    String ^next_keypad_vote = m_plus_base_api_wrapper->m_plus_base->GetNextKeypadVote();

    return (const char*)Marshal::StringToHGlobalAnsi(next_keypad_vote).ToPointer();
}

/// A method is used to determin if a keypad serial number is currently in the keypad list.

bool ReplyPlusHardware::IsKeypadInList(const char* serial_number)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->IsKeypadInList(gcnew System::String(serial_number));
}

/// A method used to verify the login data sent by a keypad.
/// This method is called after the OnKeypadLogin event.
/// @param serial_number keypad serial number 
/// @param passed result

void ReplyPlusHardware::KeypadLoginResult(const char* serial_number, bool passed)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->KeypadLoginResult(gcnew System::String(serial_number), passed);
}

/// A method used to lock out keys from the keypad. Parameter is a comma delimited 
/// string of the keys that are to be locked. The "soft keys" are denoted by 
/// "Left", "Niddle". and "Right" as depicted in the example. "SYM" is the symbol 
/// key and "Scan" and "Link" are for the "Search Available Bases" key. 
/// The "All" parameter locks all keys. This method is overridden with KeypadAlertEnabled 
/// flag for the alert key. However, it may still be locked when KeypadAlertEnabled is false.
///
/// @param keys read above description

void ReplyPlusHardware::LockKeys(const char* keys)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->LockKeys(gcnew System::String(keys));
}

/// Method is used to log out all keypads. A keypad must searches for the bases and 
/// select a base with which to connect. This method does not clear the keypad list.

void ReplyPlusHardware::LogoutAllKeypads()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->LogoutAllKeypads();
}

/// A method used to logout a specific keypad by its address. The address can be 
/// obtained by looking up the serial number in the keypad list. The keypad must be
/// on the system with login enabled. Calling this methode does not remove the 
/// keypad from the keypad list. Call the RemoveKeypad or RemoveStaticKeypad for this.
///
/// @param address keypad address

void ReplyPlusHardware::LogoutKeypad(int address)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->LogoutKeypad(address);
}

/// A method used to remove a keypad from the keypad list by serial number. 
/// The address of the serial number removed then becomes available to the 
/// next keypad requesting or added through the AddKeypad method.
///
/// @param keypad_id

void ReplyPlusHardware::RemoveKeypad(int keypad_id)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->RemoveKeypad(keypad_id);
}

/// A method used to remove a keypad from the keypad list by serial number. 
/// The address of the serial number removed then becomes available to the 
/// next keypad requesting or added through the AddKeypad method.
///
/// @param serial_number keypad serial number

void ReplyPlusHardware::RemoveKeypad(const char* serial_number)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->RemoveKeypad(gcnew System::String(serial_number));
}


bool ReplyPlusHardware::RemoveKeypadByID(const char* keypads)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->RemoveKeypadByID(gcnew System::String(keypads));
}

/// A method used to send a specific keypad, by keypad ID, a message. Note: See sendMsgBySerial
///
/// @param keypad_id id of the keypad
/// @param keypad_message

void ReplyPlusHardware::SendMsgByID(int keypad_id, const char* keypad_message)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->SendMsgByID(keypad_id, gcnew System::String(keypad_message));
}

/// A method used to send a specific keypad, by serial number, a message.
/// @param serial_number
/// @param keypad_message

void ReplyPlusHardware::SendMsgBySerial(const char* serial_number, const char* keypad_message)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->SendMsgBySerial(gcnew System::String(serial_number), gcnew System::String(keypad_message));
}

/// A method used to set the session name and group bases on a system.
/// 
/// @param session_name
/// @param session_group

void ReplyPlusHardware::SetSession(const char* session_name, int session_group)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->SetSession(gcnew System::String(session_name), session_group);
}

/// A method used to set the system into a training mode so that keypads can 
/// link to the system. Parameters include the power level and mode to put the system in.
///
/// @param value Available types are tmNormal, tmTrainingPending and tmTraining
/// @param power_level Available types are Low, Mid, High, EuroMax and USMax = 6

bool ReplyPlusHardware::SetToTraining(TrainMode value, BasePowerLevel power_level)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->SetToTraining((ReplyPlusAPIControl::TrainMode)value, (ReplyPlusAPIControl::BasePowerLevel)power_level);
}

/// A method used to clear a message at a specific message index on a 
/// specific keypad, defined by the keypad serial.
///
/// @param keypad_id
/// @param keypad_message
/// @param message_index
/// @param store_message
/// @param recall_message

void ReplyPlusHardware::StoreMessageByID(int keypad_id, const char* keypad_message, int message_index, bool store_message, bool recall_message)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->StoreMessageByID(keypad_id, gcnew System::String(keypad_message), message_index, store_message, recall_message);
}

/// A method is used to store and recall messages that were saved on a 
/// specific keypad, defined by the serial number. The range for a valid message index is 0-15
///
/// @param serial_number
/// @param keypad_message
/// @param message_index
/// @param store_message
/// @param recall_message

void ReplyPlusHardware::StoreMessageBySerial(const char* serial_number, const char* keypad_message, int message_index, bool store_message, bool recall_message)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->StoreMessageBySerial(gcnew System::String(serial_number), gcnew System::String(keypad_message), message_index, store_message, recall_message);
}

/// A method is used to train or deny a keypad onto the system.
/// 
/// @param serial_number
/// @param keypad_id
/// @param base_id
///
/// @return true or false

bool ReplyPlusHardware::TrainKeypad(const char* serial_number, int keypad_id, unsigned char base_id)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->TrainKeypad(gcnew System::String(serial_number), keypad_id, base_id);
}

/// A method used to unlock keys that were locked out via the LockKeys method.
/// @param keys Parameter is a comma delimited 
/// string of the keys that are to be locked. The "soft keys" are denoted by 
/// "Left", "Niddle". and "Right" as depicted in the example. "SYM" is the symbol 
/// key and "Scan" and "Link" are for the "Search Available Bases" key. 
/// The "All" parameter locks all keys. This method is overridden with KeypadAlertEnabled 
/// flag for the alert key. However, it may still be locked when KeypadAlertEnabled is false.

void ReplyPlusHardware::UnlockKeys(const char* keys)
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    m_plus_base_api_wrapper->m_plus_base->UnlockKeys(gcnew System::String(keys));
}

/// A property managing the type, dynamic or static of the WRS970.
/// @return AddrMode Dynamic = 0 or Static = 1.

AddrMode ReplyPlusHardware::AddressMode()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (AddrMode)m_plus_base_api_wrapper->m_plus_base->AddressMode;
}

/// A property managin the another level of security 
/// for access to the WRS970 system.
/// @return bool

bool ReplyPlusHardware::Authentication()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->Authentication;
}

/// Automatically connects a keypad to a base when there is only one base found.
/// @return True if auto connect successfull otherwise false

bool ReplyPlusHardware::AutoConnect()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->AutoConnect;
}

/// A property that will automatically increment the question number 
/// on each beginQuestion.
///
/// @return true or false.

bool ReplyPlusHardware::AutomateQuestionNumber()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->AutomateQuestionNumber;
}

/// A property managing the RF frequency ranges used by the WRS970 sytem. 
/// This property can be used to increase system efficiency by 
/// avoiding a high noise level used by WiFi access points.
///
/// @return Band

Band ReplyPlusHardware::AvoidWifi()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (Band)m_plus_base_api_wrapper->m_plus_base->AvoidWifi;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::BaseChannel()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->BaseChannel;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::BaseName()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->BaseName).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::BaseSerial() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->BaseSerial).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::BaseVersion()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->BaseVersion).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::BeepKeypads() 
{
    return m_plus_base_api_wrapper->m_plus_base->BeepKeypads;
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::CommunicationTimeout()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->CommunicationTimeout;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::Connected()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->Connected;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::ControlVersion()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->ControlVersion).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::CustomMessage() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->CustomMessage).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::CustomSoftKeys() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->CustomSoftKeys).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::DebugEnabled() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->DebugEnabled;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

DAddressTimeout ReplyPlusHardware::DynamicAddressTimeout()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (DAddressTimeout)m_plus_base_api_wrapper->m_plus_base->DynamicAddressTimeout;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::ErrorsEnabled() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ErrorsEnabled;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::ExceptionsEnabled() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ExceptionsEnabled;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::ForceMenu() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ForceMenu;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::HideAntennaIcon()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->HideAntennaIcon;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::HideBatteryIcon()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->HideBatteryIcon;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::KeyLockFeedback() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeyLockFeedback;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::KeypadAlertEnabled()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeypadAlertEnabled;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::KeypadBacklight() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeypadBacklight;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

OnTimer ReplyPlusHardware::KeypadBacklightOnTimer() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (OnTimer)m_plus_base_api_wrapper->m_plus_base->KeypadBacklightOnTimer;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

OpMethod ReplyPlusHardware::KeypadBacklightOpMethod()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (OpMethod)m_plus_base_api_wrapper->m_plus_base->KeypadBacklightOpMethod;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::KeypadHideVote()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeypadHideVote;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::KeypadList()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->KeypadList).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::KeypadListCount()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeypadListCount;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::KeypadLoginEnabled() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeypadLoginEnabled;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::KeypadLowBatteryNotification() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeypadLowBatteryNotification;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

PowerTimer ReplyPlusHardware::KeypadPowerTimer() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (PowerTimer)m_plus_base_api_wrapper->m_plus_base->KeypadPowerTimer;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::KeypadsOutOfRange() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeypadsOutOfRange;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::KeypadsPowerDown()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->KeypadsPowerDown;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::MaxKeypadsAllowed() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->MaxKeypadsAllowed;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

MnuAccess ReplyPlusHardware::MenuAccess()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (MnuAccess)m_plus_base_api_wrapper->m_plus_base->MenuAccess;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::Model()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->Model).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::MsgAckEnabled()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->MsgAckEnabled;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::NumberOfKeypadVotes()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->NumberOfKeypadVotes;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

PngTimer ReplyPlusHardware::PingTimer()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (PngTimer)m_plus_base_api_wrapper->m_plus_base->PingTimer;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::PowerKeyDisabled()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->PowerKeyDisabled;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

BasePowerLevel ReplyPlusHardware::PowerLevel()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (BasePowerLevel)m_plus_base_api_wrapper->m_plus_base->PowerLevel;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::ProductID()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ProductID;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::ReceiveArrowOnAnyBase()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ReceiveArrowOnAnyBase;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::ScrollFaster()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ScrollFaster;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::SecureLogin()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->SecureLogin;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::SeqLinkPackets()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->SeqLinkPackets;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

const char* ReplyPlusHardware::SessionName() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (const char*)Marshal::StringToHGlobalAnsi(m_plus_base_api_wrapper->m_plus_base->SessionName).ToPointer();
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::ShowAnswer() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ShowAnswer;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::ShowReceived() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ShowReceived;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::ShowSending() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->ShowSending;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::SMSEntry() 
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->SMSEntry;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::SMSVoteTimeout()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->SMSVoteTimeout;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

Symbol ReplyPlusHardware::StartSymbol()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (Symbol)m_plus_base_api_wrapper->m_plus_base->StartSymbol;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

bool ReplyPlusHardware::TCPKeepAliveEnabled()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->TCPKeepAliveEnabled;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

int ReplyPlusHardware::TCPKeepAliveTimeout()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return m_plus_base_api_wrapper->m_plus_base->TCPKeepAliveTimeout;
}

/// reference Reply Plus .Net API Programmers Guide 1_0_7.pdf

TrainMode ReplyPlusHardware::TrainingMode()
{
    Lock<Mutex> ObserversLock(m_observers_mutex.get());
    return (TrainMode)m_plus_base_api_wrapper->m_plus_base->TrainingMode;
}

/// Constructor 
/// Registers reply plus driver callbacks once the device is connected.
/// @param reply_plus_hardware Reply Plus Hardware on which observer will get the response.

ReplyPlusAPIWrapper::ReplyPlusAPIWrapper(ReplyPlusHardware &reply_plus_hardware) : m_reply_plus_hardware(reply_plus_hardware)
{
    m_plus_base = gcnew ReplyPlusAPIControl();
    
    array<unsigned char> ^userLicenseBytes = {0x27, 0xFB, 0xF8, 0xE7, 0xBE, 0x12, 0x7D, 0x5F, 0x44, 0xCD, 0x93, 0x13, 0x1E, 0x2E, 0xA4, 0xDC, 0xBD, 0x19, 0x39, 0xC3, 0x60, 0xD0, 0x35, 0x9B, 0x47, 0x15, 0x98, 0x83, 0x34, 0xC0, 0x4E, 0xD5};
    m_plus_base->ValidateAPI(userLicenseBytes);

    m_plus_base->OnDebug += gcnew ReplyPlusAPIControl::TDebugMessage( this, &ReplyPlusAPIWrapper::PlusBaseOnDebug );
    m_plus_base->OnDebug += gcnew ReplyPlusAPIControl::TDebugMessage( this, &ReplyPlusAPIWrapper::PlusBaseOnDebug );
    m_plus_base->OnError += gcnew ReplyPlusAPIControl::TErrorMessage( this, &ReplyPlusAPIWrapper::PlusBaseOnError );
    m_plus_base->OnDuplicateID += gcnew ReplyPlusAPIControl::TDuplicateID( this, &ReplyPlusAPIWrapper::PlusBaseOnDuplicateID );
    m_plus_base->OnKeypadAlert += gcnew ReplyPlusAPIControl::TOnKeypadAlert( this, &ReplyPlusAPIWrapper::PlusBaseOnKeypadAlert );
    m_plus_base->OnKeypadPing += gcnew ReplyPlusAPIControl::TOnKeypadPing( this, &ReplyPlusAPIWrapper::PlusBaseOnKeypadPing );
    m_plus_base->OnLowBatteryWarning += gcnew ReplyPlusAPIControl::TLowBatteryWarning( this, &ReplyPlusAPIWrapper::PlusBaseOnLowBatteryWarning );
    m_plus_base->OnKeypadLogin += gcnew ReplyPlusAPIControl::TOnKeypadLogin( this, &ReplyPlusAPIWrapper::PlusBaseOnKeypadLogin );
    m_plus_base->OnKeypadMsgTimeout += gcnew ReplyPlusAPIControl::TKeypadMsgTimeout( this, &ReplyPlusAPIWrapper::PlusBaseOnKeypadMsgTimeout );
    m_plus_base->OnKeypadNotAuthorized += gcnew ReplyPlusAPIControl::TOnKeypadNotAuthorized( this, &ReplyPlusAPIWrapper::PlusBaseOnKeypadNotAuthorized );
    m_plus_base->OnMessageAck += gcnew ReplyPlusAPIControl::TOnMessageAck( this, &ReplyPlusAPIWrapper::PlusBaseOnMessageAck );
    m_plus_base->OnMomentToMoment += gcnew ReplyPlusAPIControl::TOnMomentToMoment( this, &ReplyPlusAPIWrapper::PlusBaseOnMomentToMoment );
    m_plus_base->OnSMSVoteTimeout += gcnew ReplyPlusAPIControl::TOnSMSVoteTimeout( this, &ReplyPlusAPIWrapper::PlusBaseOnSMSVoteTimeout );
    m_plus_base->OnTrainingRequest += gcnew ReplyPlusAPIControl::TOnTrainingRequest( this, &ReplyPlusAPIWrapper::PlusBaseOnTrainingRequest);
    m_plus_base->OnTrainingAck += gcnew ReplyPlusAPIControl::TOnTrainingAck( this, &ReplyPlusAPIWrapper::PlusBaseOnTrainingAck );
    m_plus_base->OnKeypadConnect += gcnew ReplyPlusAPIControl::TOnKeypadConnect( this, &ReplyPlusAPIWrapper::PlusBaseOnKeypadConnect );
    m_plus_base->ErrorsEnabled = true;
}

ReplyPlusAPIWrapper::~ReplyPlusAPIWrapper()
{
    delete m_plus_base;
}

/// An Event triggered to provide helpfull debug messages describing the details 
/// of processing of the API. The event is only triggered if the 
/// DebugEventsEnabled property set is true.
///
/// @param base_serial device serial code
/// @param message debug message

void ReplyPlusAPIWrapper::PlusBaseOnDebug( String ^base_serial, String ^message )
{
    m_reply_plus_hardware.PlusBaseOnDebug((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(message).ToPointer());
}


/// An event triggered to provide errors that may occur in the API. 
/// The event is only triggered if ErrorEventsEnabled property is set to true.
///
/// @param base_serial device serial code
/// @param error error message

void ReplyPlusAPIWrapper::PlusBaseOnError( String ^base_serial, String ^error )
{
    m_reply_plus_hardware.PlusBaseOnError((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(error).ToPointer());
}

/// An event triggered when a keypad votes at tghe address or Keypad ID of the another keypad. 
/// This event occurs no matter which addressing mode is in use. This event not trigger when a
/// keypad serial number of zeroes is being added over a valid serial number of vice versa.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusAPIWrapper::PlusBaseOnDuplicateID( String ^base_serial, String ^keypad_serial, int keypad_id )
{
    m_reply_plus_hardware.PlusBaseOnDuplicateID((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(), keypad_id);
}

/// An event is triggered when the alert key is pressed on the keypad. 
/// This event is only triggered if KeypadAlertEnabled property is set to true
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusAPIWrapper::PlusBaseOnKeypadAlert( String ^base_serial, String ^keypad_serial, int keypad_id )
{
    m_reply_plus_hardware.PlusBaseOnKeypadAlert((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(), keypad_id);
}

/// An event triggered upon the response of the keypads where the ping Timer time has expired.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusAPIWrapper::PlusBaseOnKeypadPing( String ^base_serial, String ^keypad_serial, int keypad_id )
{
    m_reply_plus_hardware.PlusBaseOnKeypadPing((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(), keypad_id);
}

/// An error triggered by a keypad with a low battery
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusAPIWrapper::PlusBaseOnLowBatteryWarning( String ^base_serial, String ^keypad_serial, int keypad_id )
{
    m_reply_plus_hardware.PlusBaseOnLowBatteryWarning((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(), keypad_id);
}
 
/// An event triggered when a keypad has requested to login to the system.
/// Upon determining if the keypad data is valid, the KeypadLoginResult 
/// method should be called within this event. First, Login can be used 
/// globally such that each keypad connceting to the system must enter the 
/// same login value. An alternate option is to compare the serial number of 
/// the login data against a table of specific login values per keypad serial number.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param password password to login

void ReplyPlusAPIWrapper::PlusBaseOnKeypadLogin( String ^base_serial, String ^keypad_serial, String ^password )
{
    m_reply_plus_hardware.PlusBaseOnKeypadLogin((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(),
        (const char*)Marshal::StringToHGlobalAnsi(password).ToPointer());
}

/// An event triggered when a keypad has not responded from SendMsgByID 
/// or SendMsgBySerial method calls within the timeout period.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusAPIWrapper::PlusBaseOnKeypadMsgTimeout( String ^base_serial, String ^keypad_serial, int keypad_id )
{
    m_reply_plus_hardware.PlusBaseOnKeypadMsgTimeout((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(), keypad_id);
}

/// An event triggered when the system is a static system, authentication is true and 
/// a keypad outside of the keypad list attemts to vote.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code

void ReplyPlusAPIWrapper::PlusBaseOnKeypadNotAuthorized( String ^base_serial, String ^keypad_serial )
{
    m_reply_plus_hardware.PlusBaseOnKeypadNotAuthorized((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer());
}

/// An event triggered when a keypad has shown its keypad specific message on the LCD. 
/// This event is triggered only on the call of the SendMsgByID or SendMsgBySerial methods 
/// and returs serial number anbd keypad ID of a responding keypad. 
/// The MessageAckEnabled property must be set to true to receive this event.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id

void ReplyPlusAPIWrapper::PlusBaseOnMessageAck( String ^base_serial, String ^keypad_serial, int keypad_id )
{
    m_reply_plus_hardware.PlusBaseOnMessageAck((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(), keypad_id);
}

/// An event triggered when a keypad sends its moment to moment data
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param keypad_id keypad id
/// @param battery_level 
/// @param moment_data

void ReplyPlusAPIWrapper::PlusBaseOnMomentToMoment( String ^base_serial, String ^keypad_serial, int keypad_id, int battery_level, String ^moment_data )
{
    m_reply_plus_hardware.PlusBaseOnMomentToMoment((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(),
        keypad_id, battery_level, (const char*)Marshal::StringToHGlobalAnsi(moment_data).ToPointer());
}

/// Property set to limit the time the keyopad is allowed to continue tp transmit 
/// up to 140 characters of a vote before triggering the OnSMSVoteTimeout event. 
/// The default is 40000 or 40 seconds.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param question_number question for which the timeout happened.
/// @param vote_data vote for the above param

void ReplyPlusAPIWrapper::PlusBaseOnSMSVoteTimeout( String ^base_serial, String ^keypad_serial, int question_number, String ^vote_data )
{
    m_reply_plus_hardware.PlusBaseOnSMSVoteTimeout((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(),
        question_number, (const char*)Marshal::StringToHGlobalAnsi(vote_data).ToPointer());
}

/// An event is fired when a keypad requests to be trained.
/// The result of this methode is the TrainKeypad method.
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param battery_level battery level in numbers.
/// @param version 
/// @param requested_base_id base id of the device for which request has be initiated
/// @param current_base_id current base device id
/// @param group
/// @param address

void ReplyPlusAPIWrapper::PlusBaseOnTrainingRequest(String ^base_serial, String ^keypad_serial, int battery_level, String ^version, int requested_base_id, int current_base_id, int group, int address)
{
    m_reply_plus_hardware.PlusBaseOnTrainingRequest((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(),
        battery_level, (const char*)Marshal::StringToHGlobalAnsi(version).ToPointer(), requested_base_id, current_base_id, group, address);
}

/// An event fired when the trained keypad has acknowledged its training
///
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code
/// @param battery_level battery level in numbers.
/// @param version 
/// @param base_id current base device id
/// @param keypad_id keypad id

void ReplyPlusAPIWrapper::PlusBaseOnTrainingAck( String ^base_serial, String ^keypad_serial, int battery_level, String ^version, int base_id, int keypad_id )
{
    m_reply_plus_hardware.PlusBaseOnTrainingAck((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer(), 
        battery_level, (const char*)Marshal::StringToHGlobalAnsi(version).ToPointer(), base_id, keypad_id);
}

/// An event triggered when a new keypad has joined the keypad list
/// 
/// @param base_serial connected device serial code
/// @param keypad_serial keypad device serial code

void ReplyPlusAPIWrapper::PlusBaseOnKeypadConnect(String ^base_serial, String ^keypad_serial)
{
    m_reply_plus_hardware.PlusBaseOnKeypadConnect((const char*)Marshal::StringToHGlobalAnsi(base_serial).ToPointer(), (const char*)Marshal::StringToHGlobalAnsi(keypad_serial).ToPointer());
}

