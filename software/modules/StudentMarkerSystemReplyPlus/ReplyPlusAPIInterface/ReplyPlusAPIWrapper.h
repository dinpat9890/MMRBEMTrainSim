///******************************************************************************
///
/// @File: ReplyPlusAPIWrapper.h
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

#ifndef REPLY_PLUS_API_WRAPPER
#define REPLY_PLUS_API_WRAPPER

#include "ReplyPlusAPIInterface.h"
#include <msclr\auto_gcroot.h>


using namespace System;
using namespace System::Runtime::InteropServices; // Marshal
using namespace System::Threading;
using namespace ReplyPlusAPI;

ref class ReplyPlusAPIWrapper;

template <class T>
ref struct Lock
{
    inline Lock(T ^object) : m_object(object) { m_object->WaitOne(); }
    inline ~Lock() { m_object->ReleaseMutex(); }

private:
    T ^m_object;
};

namespace SMS 
{
    class ReplyPlusHardware : public Hardware
    {
    public:
        ReplyPlusHardware();

        void AttachObserver(Observer *observer);
        void DetachObserver(Observer *observer);

        void PlusBaseOnDebug( const char* base_serial, const char* message );
        void PlusBaseOnError( const char* base_serial, const char* error );
        void PlusBaseOnDuplicateID( const char* base_serial, const char* keypad_serial, int keypad_id );
        void PlusBaseOnKeypadAlert( const char* base_serial, const char* keypad_serial, int keypad_id );
        void PlusBaseOnKeypadPing( const char* base_serial, const char* keypad_serial, int keypad_id );
        void PlusBaseOnLowBatteryWarning( const char* base_serial, const char* keypad_serial, int keypad_id );
        void PlusBaseOnKeypadLogin( const char* base_serial, const char* keypad_serial, const char* password );
        void PlusBaseOnKeypadMsgTimeout( const char* base_serial, const char* keypad_serial, int keypad_id );
        void PlusBaseOnKeypadNotAuthorized( const char* base_serial, const char* keypad_serial );
        void PlusBaseOnMessageAck( const char* base_serial, const char* keypad_serial, int keypad_id );
        void PlusBaseOnMomentToMoment( const char* base_serial, const char* keypad_serial, int keypad_id, int battery_level, const char* moment_data );
        void PlusBaseOnSMSVoteTimeout( const char* base_serial, const char* keypad_serial, int question_number, const char* vote_data );
        void PlusBaseOnTrainingRequest(const char* base_serial, const char* keypad_serial, int battery_level, const char* version, int requested_base_id, int current_base_id, int group, int address);
        void PlusBaseOnTrainingAck( const char* base_serial, const char* keypad_serial, int battery_level, const char* version, int base_id, int keypad_id );
        void PlusBaseOnKeypadConnect(const char* base_serial, const char* keypad_serial);

        bool AddKeypad(const char* serial_number);
        void ClearDataBuffer();
        void ClearKeypadList();
        void BeginQuestion(int question_number, AnswerType answer_type);
        void ClearStoredMessageByID(int keypadID, int MessageIndex);
        void ClearStoredMessageBySerial(const char* serialNumber, int MessageIndex);
        bool Connect(const char* SerialNumber);
        bool Connect(const char* IPAddress, int Port);
        void Disconnect();
        const char* GetAvailableBases();
        const char* GetNextKeypadVote();
        bool IsKeypadInList(const char* SerialNumber);
        void KeypadLoginResult(const char* serialNumber, bool passed);
        void LockKeys(const char* keys);
        void LogoutAllKeypads();
        void LogoutKeypad(int address);
        void RemoveKeypad(int keypadID);
        void RemoveKeypad(const char* SerialNumber);
        bool RemoveKeypadByID(const char* keypads);
        void SendMsgByID(int keypadID, const char* keypadMessage);
        void SendMsgBySerial(const char* serialNumber, const char* keypadMessage);
        void SetSession(const char* sessionName, int sessionGroup);
        bool SetToTraining(TrainMode value, BasePowerLevel powerLevel);
        void StoreMessageByID(int keypadID, const char* keypadMessage, int MessageIndex, bool StoreMessage, bool RecallMessage);
        void StoreMessageBySerial(const char* serialNumber, const char* keypadMessage, int MessageIndex, bool StoreMessage, bool RecallMessage);
        bool TrainKeypad(const char* serialNumber, int keypadID, unsigned char baseID);
        void UnlockKeys(const char* Keys);

        AddrMode AddressMode();
        bool Authentication();
        bool AutoConnect();
        bool AutomateQuestionNumber();
        Band AvoidWifi();
        int BaseChannel();
        const char* BaseName();
        const char* BaseSerial(); 
        const char* BaseVersion();
        bool BeepKeypads(); 
        int CommunicationTimeout();
        bool Connected();
        const char* ControlVersion();
        const char* CustomMessage(); 
        const char* CustomSoftKeys(); 
        bool DebugEnabled(); 
        DAddressTimeout DynamicAddressTimeout();
        bool ErrorsEnabled(); 
        bool ExceptionsEnabled(); 
        bool ForceMenu(); 
        bool HideAntennaIcon();
        bool HideBatteryIcon();
        bool KeyLockFeedback(); 
        bool KeypadAlertEnabled();
        bool KeypadBacklight(); 
        OnTimer KeypadBacklightOnTimer(); 
        OpMethod KeypadBacklightOpMethod();
        bool KeypadHideVote();
        const char* KeypadList();
        int KeypadListCount();
        bool KeypadLoginEnabled(); 
        bool KeypadLowBatteryNotification(); 
        PowerTimer KeypadPowerTimer(); 
        bool KeypadsOutOfRange(); 
        bool KeypadsPowerDown();
        int MaxKeypadsAllowed(); 
        MnuAccess MenuAccess();
        const char* Model();
        bool MsgAckEnabled();
        int NumberOfKeypadVotes();
        PngTimer PingTimer();
        bool PowerKeyDisabled();
        BasePowerLevel PowerLevel();
        int ProductID();
        bool ReceiveArrowOnAnyBase();
        bool ScrollFaster();
        bool SecureLogin();
        int SeqLinkPackets();
        const char* SessionName(); 
        bool ShowAnswer(); 
        bool ShowReceived(); 
        bool ShowSending(); 
        bool SMSEntry(); 
        int SMSVoteTimeout();
        Symbol StartSymbol();
        bool TCPKeepAliveEnabled();
        int TCPKeepAliveTimeout();
        TrainMode TrainingMode();

    private:
        msclr::auto_gcroot<ReplyPlusAPIWrapper^> m_plus_base_api_wrapper;
        msclr::auto_gcroot<Mutex^> m_observers_mutex;
        std::vector<Observer *> m_observers;
    };
}

ref class ReplyPlusAPIWrapper
{
    public: 
        ReplyPlusAPIWrapper(SMS::ReplyPlusHardware &reply_plus_hardware);
        ~ReplyPlusAPIWrapper();

        void PlusBaseOnDebug( String ^base_serial, String ^message );
        void PlusBaseOnError( String ^base_serial, String ^error );
        void PlusBaseOnDuplicateID( String ^base_serial, String ^keypad_serial, int keypad_id );
        void PlusBaseOnKeypadAlert( String ^base_serial, String ^keypad_serial, int keypad_id );
        void PlusBaseOnKeypadPing( String ^base_serial, String ^keypad_serial, int keypad_id );
        void PlusBaseOnLowBatteryWarning( String ^base_serial, String ^keypad_serial, int keypad_id );
        void PlusBaseOnKeypadLogin( String ^base_serial, String ^keypad_serial, String ^password );
        void PlusBaseOnKeypadMsgTimeout( String ^base_serial, String ^keypad_serial, int keypad_id );
        void PlusBaseOnKeypadNotAuthorized( String ^base_serial, String ^keypad_serial );
        void PlusBaseOnMessageAck( String ^base_serial, String ^keypad_serial, int keypad_id );
        void PlusBaseOnMomentToMoment( String ^base_serial, String ^keypad_serial, int keypad_id, int battery_level, String ^moment_data );
        void PlusBaseOnSMSVoteTimeout( String ^base_serial, String ^keypad_serial, int question_number, String ^vote_data );
        void PlusBaseOnTrainingRequest(String ^base_serial, String ^keypad_serial, int battery_level, String ^version, int requested_base_id, int current_base_id, int group, int address);
        void PlusBaseOnTrainingAck( String ^base_serial, String ^keypad_serial, int battery_level, String ^version, int base_id, int keypad_id );
        void PlusBaseOnKeypadConnect(String ^base_serial, String ^keypad_serial);

        ReplyPlusAPIControl ^m_plus_base;
    private:
        SMS::ReplyPlusHardware &m_reply_plus_hardware;
};

#endif //REPLY_PLUS_API_WRAPPER
