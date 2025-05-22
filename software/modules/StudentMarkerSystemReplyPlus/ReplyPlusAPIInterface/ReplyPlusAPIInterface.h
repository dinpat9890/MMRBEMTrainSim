///******************************************************************************
///
/// @File: ReplyPlusAPIInterface.h
///
/// @Description: Observer and Hardware to register observers to use
///               API's available.
/// @Reference: WRS970_API_Programmers_Guide_3_2_3 and 
///             Reply Plus .Net API Programmers Guide 1_0_7
///
/// @Author: Deepankar Chakraborty
///
/// @Copyright: SYDAC Pty Ltd, 2015
///
///******************************************************************************
#ifndef REPLY_PLUS_API_INTERFACE
#define REPLY_PLUS_API_INTERFACE

#pragma once

#include <vector>
//#include <memory>


namespace SMS 
{
    enum class AddrMode
    {
        Dynamic = 0,
        Static = 1,
    };

    enum class AnswerType
    {
        SingleAlpha = 0,
        SingleDigit = 1,
        YesNo = 2,
        YesAbstainNo = 3,
        NegativePlus = 4,
        AgreeDisagree = 5,
        LowMedHigh = 6,
        TrueFalse = 7,
        MomentToMoment = 8,
        MultiAlphaNumeric = 9,
        CustomSoftKeys = 10,
    };

    enum class Band
    {
        None = 0,
        LowMid = 1,
        LowHigh = 2,
        MidHigh = 3,
        Low = 4,
        Mid = 5,
        High = 6,
        Auto = 7,
    };

    enum class BasePowerLevel
    {
        Low = 0,
        Mid = 1,
        High = 2,
        EuroMax = 3,
        USMax = 6,
    };

    enum class DAddressTimeout
    {
        Two = 0,
        Eight = 1,
        Twelve = 2,
        Off = 3,
    };

    enum class LineOnePrompt
    {
        Blank = 0,
        Welcome = 1,
        Hello = 2,
        PleaseVote = 3,
        VoteNow = 4,
        ChooseAgain = 5,
        VoteEnded = 6,
        TimeIsUp = 7,
        BreakTime = 8,
        Questions = 9,
        ManyThanks = 10,
        ThankYou = 11,
        SystemIdle = 12,
        QuestionNumber = 13,
        RespondNow = 14,
        ReturnKeypad = 15,
        CustomPrompt = 16,
    };

    enum class MnuAccess
    {
        Disabled = 0,
        mnuContrast = 1,
        mnuBaseAddress = 2,
        mnuBaseID = 3,
        mnuKeyBeep = 4,
        mnuOpMode = 5,
    };

    enum class OnTimer
    {
        TwoSeconds = 0,
        ThreeSeconds = 1,
        FourSeconds = 2,
        FiveSeconds = 3,
    };

    enum class OpMethod
    {
        Normal = 0,
        OnKeypress = 1,
        OnAcknowledged = 2,
    };

    enum class PngTimer
    {
        Off = 0,
        Five = 1,
        Ten = 2,
        Fifteen = 3,
    };

    enum class PowerTimer
    {
        Ten = 0,
        Twenty = 1,
        Thirty = 2,
        Forty = 3,
    };

    enum class Symbol
    {
        ssPeriod = 0,
        ssAsterisk = 1,
        ssQuestionMark = 2,
        ssExclamation = 3,
        ssAt = 4,
        ssUnderscore = 5,
        ssColon = 6,
        ssSemicolon = 7,
        ssComma = 8,
        ssApostrophe = 9,
        ssPercent = 10,
        ssPlus = 11,
        ssMinus = 12,
        ssForwardSlash = 13,
        ssLeftParentheses = 14,
        ssRightParentheses = 15,
        ssX = 16,
        ssY = 17,
        ssEqual = 18,
        ssPound = 19,
        ssDollar = 20,
        ssAmpersand = 21,
        ssLessThan = 22,
        ssGreaterThan = 23,
    };

    enum class TrainMode
    {
        tmNormal = 0,
        tmTrainingPending = 1,
        tmTraining = 2,
    };

    class Observer
    {
    public:
        virtual void PlusBaseOnDebug( const char* base_serial, const char* message ) {}
        virtual void PlusBaseOnError( const char* base_serial, const char* error ) {}
        virtual void PlusBaseOnDuplicateID( const char* base_serial, const char* keypad_serial, int keypad_id ) {}
        virtual void PlusBaseOnKeypadAlert( const char* base_serial, const char* keypad_serial, int keypad_id ) {}
        virtual void PlusBaseOnKeypadPing( const char* base_serial, const char* keypad_serial, int keypad_id ) {}
        virtual void PlusBaseOnLowBatteryWarning( const char* base_serial, const char* keypad_serial, int keypad_id ) {}
        virtual void PlusBaseOnKeypadLogin( const char* base_serial, const char* keypad_serial, const char* password ) {}
        virtual void PlusBaseOnKeypadMsgTimeout( const char* base_serial, const char* keypad_serial, int keypad_id ) {}
        virtual void PlusBaseOnKeypadNotAuthorized( const char* base_serial, const char* keypad_serial ) {}
        virtual void PlusBaseOnMessageAck( const char* base_serial, const char* keypad_serial, int keypad_id ) {}
        virtual void PlusBaseOnMomentToMoment( const char* base_serial, const char* keypad_serial, int keypad_id, int battery_level, const char* moment_data ) {}
        virtual void PlusBaseOnSMSVoteTimeout( const char* base_serial, const char* keypad_serial, int question_number, const char* vote_data ) {}
        virtual void PlusBaseOnTrainingRequest(const char* base_serial, const char* keypad_serial, int battery_level, const char* version, int requested_base_id, int current_base_id, int group, int address) {}
        virtual void PlusBaseOnTrainingAck( const char* base_serial, const char* keypad_serial, int battery_level, const char* version, int base_id, int keypad_id ) {}
        virtual void PlusBaseOnKeypadConnect(const char* base_serial, const char* keypad_serial) {}
    };

    class Hardware
    {
    public:
        virtual void AttachObserver(Observer *observer) = 0;
        virtual void DetachObserver(Observer *observer) = 0;

        virtual bool AddKeypad(const char* serial_number) = 0;
        virtual void ClearDataBuffer() = 0;
        virtual void ClearKeypadList() = 0;
        virtual void BeginQuestion(int question_number, AnswerType answer_type) = 0;
        virtual void ClearStoredMessageByID(int keypadID, int MessageIndex) = 0;
        virtual void ClearStoredMessageBySerial(const char* serialNumber, int MessageIndex) = 0;
        virtual bool Connect(const char* SerialNumber) = 0;
        virtual bool Connect(const char* IPAddress, int Port) = 0;
        virtual void Disconnect() = 0;
        virtual const char* GetAvailableBases() = 0;
        virtual const char* GetNextKeypadVote() = 0;
        virtual bool IsKeypadInList(const char* SerialNumber) = 0;
        virtual void KeypadLoginResult(const char* serialNumber, bool passed) = 0;
        virtual void LockKeys(const char* keys) = 0;
        virtual void LogoutAllKeypads() = 0;
        virtual void LogoutKeypad(int address) = 0;
        virtual void RemoveKeypad(int keypadID) = 0;
        virtual void RemoveKeypad(const char* SerialNumber) = 0;
        virtual bool RemoveKeypadByID(const char* keypads) = 0;
        virtual void SendMsgByID(int keypadID, const char* keypadMessage) = 0;
        virtual void SendMsgBySerial(const char* serialNumber, const char* keypadMessage) = 0;
        virtual void SetSession(const char* sessionName, int sessionGroup) = 0;
        virtual bool SetToTraining(TrainMode value, BasePowerLevel powerLevel) = 0;
        virtual void StoreMessageByID(int keypadID, const char* keypadMessage, int MessageIndex, bool StoreMessage, bool RecallMessage) = 0;
        virtual void StoreMessageBySerial(const char* serialNumber, const char* keypadMessage, int MessageIndex, bool StoreMessage, bool RecallMessage) = 0;
        virtual bool TrainKeypad(const char* serialNumber, int keypadID, unsigned char baseID) = 0;
        virtual void UnlockKeys(const char* Keys) = 0;

        virtual AddrMode AddressMode() = 0;
        virtual bool Authentication() = 0;
        virtual bool AutoConnect() = 0;
        virtual bool AutomateQuestionNumber() = 0;
        virtual Band AvoidWifi() = 0;
        virtual int BaseChannel() = 0;
        virtual const char* BaseName() = 0;
        virtual const char* BaseSerial() = 0; 
        virtual const char* BaseVersion() = 0;
        virtual bool BeepKeypads() = 0; 
        virtual int CommunicationTimeout() = 0;
        virtual bool Connected() = 0;
        virtual const char* ControlVersion() = 0;
        virtual const char* CustomMessage() = 0; 
        virtual const char* CustomSoftKeys() = 0; 
        virtual bool DebugEnabled() = 0; 
        virtual DAddressTimeout DynamicAddressTimeout() = 0;
        virtual bool ErrorsEnabled() = 0; 
        virtual bool ExceptionsEnabled() = 0; 
        virtual bool ForceMenu() = 0; 
        virtual bool HideAntennaIcon() = 0;
        virtual bool HideBatteryIcon() = 0;
        virtual bool KeyLockFeedback() = 0; 
        virtual bool KeypadAlertEnabled() = 0;
        virtual bool KeypadBacklight() = 0; 
        virtual OnTimer KeypadBacklightOnTimer() = 0; 
        virtual OpMethod KeypadBacklightOpMethod() = 0;
        virtual bool KeypadHideVote() = 0;
        virtual const char* KeypadList() = 0;
        virtual int KeypadListCount() = 0;
        virtual bool KeypadLoginEnabled() = 0; 
        virtual bool KeypadLowBatteryNotification() = 0; 
        virtual PowerTimer KeypadPowerTimer() = 0; 
        virtual bool KeypadsOutOfRange() = 0; 
        virtual bool KeypadsPowerDown() = 0;
        virtual int MaxKeypadsAllowed() = 0; 
        virtual MnuAccess MenuAccess() = 0;
        virtual const char* Model() = 0;
        virtual bool MsgAckEnabled() = 0;
        virtual int NumberOfKeypadVotes() = 0;
        virtual PngTimer PingTimer() = 0;
        virtual bool PowerKeyDisabled() = 0;
        virtual BasePowerLevel PowerLevel() = 0;
        virtual int ProductID() = 0;
        virtual bool ReceiveArrowOnAnyBase() = 0;
        virtual bool ScrollFaster() = 0;
        virtual bool SecureLogin() = 0;
        virtual int SeqLinkPackets() = 0;
        virtual const char* SessionName() = 0; 
        virtual bool ShowAnswer() = 0; 
        virtual bool ShowReceived() = 0; 
        virtual bool ShowSending() = 0; 
        virtual bool SMSEntry() = 0; 
        virtual int SMSVoteTimeout() = 0;
        virtual Symbol StartSymbol() = 0;
        virtual bool TCPKeepAliveEnabled() = 0;
        virtual int TCPKeepAliveTimeout() = 0;
        virtual TrainMode TrainingMode() = 0;
    };

    typedef Hardware *(* FACTORY_PROC)(void);
}

#endif //REPLY_PLUS_API_INTERFACE
