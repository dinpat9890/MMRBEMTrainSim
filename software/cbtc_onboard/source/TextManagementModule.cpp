///
/// @file       TextManagementModule.cpp
///
///             Implements the Text Management Module class.
///             Design:
///             https://adl-atlassian.simulation.lan/confluence/display/NTATRL/Text+Management+Module+Design
///
/// @author     Adam Zielinski
///             Carmine Fantarella
///
/// @copyright  (C) Copyright:  SYDAC Pty Ltd, 2020-2021
///

#include "TextManagementModule.h"

#include "common/StandardLogging.h"

using namespace CBTC::Protos;
using namespace Project::CBTCOnBoard;
using namespace std;

namespace
{
    const int    MAX_NUM_TEXT_MESSAGES             = 32;
    const double EMERGENCY_BRAKE_REPORTING_TIMEOUT = 2; // seconds

    // make true when logging traces are required
    const bool DEBUG = false;
}

/// Constructor, which just initializes the members appropriately
///
/// @param init Initialisation data for the module
///
TextManagementModule::TextManagementModule(const Initialisation& init)
  : CBTCModule<TextManagementModule, TextManagementModuleIO>(init)
{
    // Initialise state data, if required
    X().session_start_time = K().session_start_time;
}

/// The Module function which, given the current inputs, adjusts the internal state and
/// populates the outputs.
///
/// @param new_time   The amount of time to since the scenario started running
///
void TextManagementModule::Step(double elapsed_time)
{

    if (U().cabin_activation == Project::TypeValue::CabinActivation::INACTIVE)
    {
        // When cab is not active, clear all existing text messages
        ManageClearAllMessages();

        // Report the empty text message list
        PopulateOutputMessageList();
    }
    else
    {
        // Process any text messages that have been acknowledged
        UpdateMessageListOnAckReceived();

        // Add any text messages whose reporting conditions have been met
        ProcessTextConditions(elapsed_time);

        // Clear any text messages whose reporting conditions are no longer being met
        ClearExpiredHighPriorityMessages(elapsed_time);

        // Report the list text messages whose conditions are being met
        PopulateOutputMessageList();
    }

    // Set the flag that triggers the playing of audio for high priority messages
    if (X().new_high_priority_msg_reported)
    {
        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::WARN)
              << "Report High Priority Text : " << X().new_high_priority_msg_reported << Trace::EndLog();
        Y().new_high_priority_msg_reported = true;
        X().new_high_priority_msg_reported = false;
    }
    else
        Y().new_high_priority_msg_reported = false;

    // Set the flag that triggers the playing of audio for ack messages
    if (X().new_acknowledge_msg_reported)
    {
        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::WARN) << "Report ACK Text : " << X().new_acknowledge_msg_reported << Trace::EndLog();
        Y().new_acknowledge_msg_reported = true;
        X().new_acknowledge_msg_reported = false;
    }
    else
        Y().new_acknowledge_msg_reported = false;

    X().emergency_brake_condition = U().emergency_brake_condition;
    X().safety_brake_state        = U().safety_brake_state;
    X().emergency_brake_ordered   = U().emergency_brake_ordered;
    X().selected_driving_mode     = U().selected_driving_mode;
}

/// Updates the text message list to include all text messages where the conditions required to display
/// a given text message have been met.
///
/// @param new_time   The amount of time to since the scenario started running
///
void TextManagementModule::ProcessTextConditions(double elapsed_time)
{
    struct TextMessageData
    {
        CBTC::Protos::TextId              msg_id;
        CBTC::Protos::TextMessagePriority priority;
        bool                              msg_ack;
    };
    vector<TextMessageData> text_messages;
    TextMessageData         msg_data;

    using namespace Project::CBTCOnBoard;

    // Processing for Text ID 100
    if (!IsMessageAlreadyInHighPriorityList(TextId::AM_MODE_IS_AVAILABLE) && U().transition_into_automatic &&
        (U().ato_is_available || U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATP) &&
        U().cbtc_current_mode != Project::TypeValue::CBTCMode::ATC_BYPASS &&
		U().current_train_speed <=0.0)
    {
        msg_data.msg_id   = TextId::AM_MODE_IS_AVAILABLE;
        msg_data.priority = CBTC::Protos::TextMessagePriority::HIGH;
        msg_data.msg_ack  = false;
        text_messages.push_back(msg_data);
    }
    if (U().safety_brake_state == Project::TypeValue::SafetyBrakeState::FSB_ACTIVE && 
		U().selected_driving_mode == Project::TypeValue::DriverModeSelection::ATP &&
        U().train_docking_status == Project::TypeValue::TrainDockingStatus::SHORT_STOP)
    {
        msg_data.msg_id   = TextId::FSB_WHILE_DOCKING;
        msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
        msg_data.msg_ack  = false;
        text_messages.push_back(msg_data);
    }
    // Processing for Text ID 200
    /*if (!IsMessageAlreadyInHighPriorityList(TextId::SWITCH_MODE_TO_CM) && U().transition_into_semi_automatic &&
        (U().cbtc_current_mode == Project::TypeValue::CBTCMode::AM || U().cbtc_current_mode ==
    Project::TypeValue::CBTCMode::ATO) && (X().last_reported_ack_message != TextId::SWITCH_MODE_TO_CM))
    {
        msg_data.msg_id   = TextId::SWITCH_MODE_TO_CM;
        msg_data.priority = CBTC::Protos::TextMessagePriority::HIGH;
        msg_data.msg_ack  = true;
        text_messages.push_back(msg_data);

        X().last_reported_ack_message = TextId::SWITCH_MODE_TO_CM;
    }*/

    // Processing for Text ID 203
    if (!IsMessageAlreadyInHighPriorityList(TextId::ATC_IS_BYPASSED) && U().cbtc_current_mode == Project::TypeValue::CBTCMode::ATC_BYPASS)
    {
        msg_data.msg_id   = TextId::ATC_IS_BYPASSED;
        msg_data.priority = CBTC::Protos::TextMessagePriority::HIGH;
        msg_data.msg_ack  = false;
        text_messages.push_back(msg_data);
    }

    // Report when an emergency brake starts to be applied
    if (X().emergency_brake_condition != U().emergency_brake_condition)
    {
        // Processing for text ID 110
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_TRAIN_DOOR_UNLOCKED)
        {
            msg_data.msg_id   = TextId::EB_TRAIN_DOORS_UNLOCKED;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Processing for Text ID 112
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_TRAIN_HOLD)
        {
            msg_data.msg_id   = TextId::EB_TRAIN_HOLD_APPLIED;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Trigger message for Text ID 113
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_OVERSPEED_INTERVENTION)
        {
            msg_data.msg_id   = TextId::EB_OVER_SPEED;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Trigger message for Text ID 123
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_TRAIN_DELOCALISED)
        {
            msg_data.msg_id   = TextId::EB_TRAIN_DELOCALISED;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Trigger message for Text ID 117
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_SIGNAL_OVERRUN)
        {
            msg_data.msg_id   = TextId::EB_SIGNAL_OVERRUN;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Processing for Text ID 118
        if (U().emergency_brake_condition == TypeValue::EmergencyBrakeTrigger::ROLLWAY ||
            U().emergency_brake_condition == TypeValue::EmergencyBrakeTrigger::MAX_REVERSE_EXCEEDED)
        {
            msg_data.msg_id   = TextId::EB_ROLLBACK;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Processing for text ID 111
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_PSD_UNLOCKED)
        {
            msg_data.msg_id   = TextId::EB_PSD_UNLOCKED;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Processing for text ID 114
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_FATAL_FAULT)
        {
            msg_data.msg_id   = TextId::EB_FATAL_FAULT;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Processing for text ID 116
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_NO_IMMOBILISATION)
        {
            msg_data.msg_id   = TextId::EB_SAFETY_IMMOBILIZATION_NOT_OBTAINED;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Processing for text ID 120
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_MODE_CHANGE_ON_RUN)
        {
            msg_data.msg_id   = TextId::EB_CHANGING_MODE_WHILE_RUNNING;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Processing for text ID 122
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_REQUESTED_BY_ATS)
        {
            msg_data.msg_id   = TextId::EB_REQUESTED_BY_ATS;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        // Processing for text ID 204
        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_COMMS_LOST)
        {
            msg_data.msg_id   = TextId::EB_RADIO_COMMUNICATION_LOST;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }

        if (U().emergency_brake_condition == Project::CBTCOnBoard::TypeValue::EmergencyBrakeTrigger::EB_PEC_REQUEST)
        {
            msg_data.msg_id   = TextId::EB_PEC_REQUEST;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }
    }

    // Processing for text ID 205
    {
        // If the safety brake state or the CBTC emergency brake order changes, we need to check
        // whether or not the rolling stock/driver EB text message is to be reported
        bool safety_brake_changed          = (U().safety_brake_state != X().safety_brake_state);
        bool emergency_brake_changed       = (U().emergency_brake_ordered != X().emergency_brake_ordered);
        bool selected_driving_mode_changed = (U().selected_driving_mode != X().selected_driving_mode);
        bool safety_brake_on               = (U().safety_brake_state == Project::TypeValue::SafetyBrakeState::ACTIVE);
        bool emergency_brake_on            = U().emergency_brake_ordered;

        if (emergency_brake_changed)
        {
            // If emergency brake just turned OFF && safety brake ON
            if (!emergency_brake_on && safety_brake_on)
            {
                // After the CBTC stops ordering the application of the safety brake their is a short delay before the
                // train model will actually release the safety brake.
                // - In order to give the train model time to release the brake we need to add a short delay before
                ///  checking whether or not the rolling stock/driver has applied the EB
                // - Without the delay we will get unexpected RS/Driver EB text messages after the EB order by the CBTC
                //   is released
                X().rs_eb_report_time = elapsed_time + EMERGENCY_BRAKE_REPORTING_TIMEOUT;
            }
            else
            {
                X().rs_eb_report_time = INVALID_TIME;
            }
        }
        else if (safety_brake_changed)
        {
            // If safety brake ON && emergency brake OFF
            if (safety_brake_on && !emergency_brake_on)
            {
                // NOTE:
                // Safety brake is applied by the train model (but not reported on DMI) when the selected driver mode is
                // Off. Need to delay the reporting of the safety brake state for at least a second after leaving the
                // off state.
                // - This is required since the train model has a delay between the time that the CBTC mode changes &
                // the
                //   actual time at which the brake is released.
                // - Without this the safety brake will flash on the DMI after leaving the off state
                bool selected_driving_mode_on = (U().selected_driving_mode != Project::TypeValue::DriverModeSelection::OFF);

                if (selected_driving_mode_on)
                {
                    if (selected_driving_mode_changed) // Selected driving mode just changed from OFF to ON
                    {
                        X().rs_eb_report_time = elapsed_time + EMERGENCY_BRAKE_REPORTING_TIMEOUT; // Place a timeout
                                                                                                  // before reporting,
                                                                                                  // because of delay on
                                                                                                  // train model
                    }
                    else if (X().rs_eb_report_time == INVALID_TIME) // If no report time delay currently active, then
                                                                    // immediately report
                    {
                        X().rs_eb_report_time = elapsed_time; // Report Safety Brake message immediately
                    }
                }
            }
            else
            {
                X().rs_eb_report_time = INVALID_TIME;
            }
        }

        // Add the text message a short delay after the rolling stock/driver EB is detected
        if ((X().rs_eb_report_time != INVALID_TIME) && (X().rs_eb_report_time <= elapsed_time))
        {
            X().rs_eb_report_time = INVALID_TIME;

            msg_data.msg_id   = TextId::EB_RS_DRIVER;
            msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
            msg_data.msg_ack  = false;
            text_messages.push_back(msg_data);
        }
    }

    // Processing for text ID 130
    // - Message is not yet in the list
    // - CBTC Startup test has been initiated or completed (completed case required to cover case where powerup is
    // skipped)
    // - message list is almost empty (ie cab has just been activated)
    if (!IsMessageAlreadyInList(TextId::ATC_INIT_TEST_IN_PROGRESS) &&
        ((U().start_up_test_stage == Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_STARTED) ||
         (U().start_up_test_stage == Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_SUCCESS)) &&
        (X().low_priority_message_list.size() <= 1))
    {
        msg_data.msg_id   = TextId::ATC_INIT_TEST_IN_PROGRESS;
        msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
        msg_data.msg_ack  = false;
        text_messages.push_back(msg_data);
    }

    // Processing for text ID 131
    // - Message is not yet in the list
    // - CBTC Startup test has been initiated
    // - message list is almost empty (ie cab has just been activated)
    if (!IsMessageAlreadyInList(TextId::ATC_INIT_TEST_OK) &&
        (U().start_up_test_stage == Project::CBTCOnBoard::TypeValue::StartupTestStage::INIT_TEST_SUCCESS) &&
        (X().low_priority_message_list.size() <= 1))
    {
        msg_data.msg_id   = TextId::ATC_INIT_TEST_OK;
        msg_data.priority = CBTC::Protos::TextMessagePriority::LOW;
        msg_data.msg_ack  = false;
        text_messages.push_back(msg_data);
    }

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::INFO) << "Active Text Message List (Id, Ack, Priority\n";

    // Adds text messages into the text message list
    for (auto text_message : text_messages)
    {
        AddTextMessage(elapsed_time, text_message.msg_id, text_message.msg_ack, text_message.priority);

        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::INFO)
              << text_message.msg_id << "   " << text_message.msg_ack << "   " << text_message.priority;
    }

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::INFO) << Trace::EndLog();
}

/// Updates the text message list based on the Ack message Id that is received
///
void TextManagementModule::UpdateMessageListOnAckReceived()
{
    // If a text message ack has been received then remove the acknowledged message from the text message list
    if (U().ack_text_message_id != UNDEFINED_TEXT_ID)
    {
        X().high_priority_message_list.remove_if(
          [this](std::pair<double, CBTCTextMessages_CBTCTextMessage> msg)
          {
              if ((msg.second.ackrequired() == true) && ((msg.second.uniqueid() == U().ack_text_message_id)))
                  return true;
              else
                  return false;
          });

        X().low_priority_message_list.remove_if(
          [this](std::pair<double, CBTCTextMessages_CBTCTextMessage> msg)
          {
              if ((msg.second.ackrequired() == true) && ((msg.second.uniqueid() == U().ack_text_message_id)))
                  return true;
              else
                  return false;
          });

        if (DEBUG)
            Trace::GetLogger().STAMP(Trace::INFO)
              << "Text Management  Ack Message ID: " << U().ack_text_message_id << Trace::EndLog();
    }
}

/// Adds a text message into the list of text messages that are to be reported
///
/// @param new_time   The amount of time to since the scenario started running
/// @param id         Text ID
/// @param msg_ack    Identifies msg_ack information
/// @param type       Message type whether Important or Auxiliary
///
void TextManagementModule::AddTextMessage(double elapsed_time, CBTC::Protos::TextId id, bool msg_ack, CBTC::Protos::TextMessagePriority priority)
{
    CBTC::Protos::CBTCTextMessages_CBTCTextMessage new_message;
    // Prepare message
    // index would be assigned after store list check
    new_message.set_id(id);
    new_message.set_uniqueid(GenerateUniqueMessageId());
    new_message.set_ackrequired(msg_ack);

    // NOTE
    // Due to a bug where the date_time value found in sessionData is not being correctly reported to
    // the seesion start time (refer CORETRAIN-) the onboard system reports the elapsed time rather
    // than the sessionTime. Same bug does not occur in the Java code and so now the DMI is required
    // to add the session start time to the elapsed time in order to determine the sesssion
    // time at which the message was logged
    // new_message.set_timestamp(X().session_start_time + elapsed_time);
    new_message.set_elapsedtime(elapsed_time);

    // Need to flag when a new ack message is being added into the text message list
    if (msg_ack)
        X().new_acknowledge_msg_reported = true;

    // Set message priority based on priority type and report when a high priority message has been added
    if (priority == CBTC::Protos::TextMessagePriority::HIGH)
    {
        new_message.set_type(CBTC::Protos::TextMessagePriority::HIGH);

        // Push it at the front of the list since newer messages should appear on top of any previously
        // reported high priority text message
        X().high_priority_message_list.push_front(std::pair<double, CBTCTextMessages_CBTCTextMessage>(elapsed_time, new_message));

        // Need to flag when a new high priority text message is being added into the text message list
        X().new_high_priority_msg_reported = true;
    }
    else
    {
        new_message.set_type(CBTC::Protos::TextMessagePriority::LOW);

        // Push it at the front of the list since newer messages should appear at the start of the text message list
        //X().low_priority_message_list.push_front(std::pair<double, CBTCTextMessages_CBTCTextMessage>(elapsed_time, new_message));

        if (!X().low_priority_message_list.empty())
        {
            std::pair < double, CBTCTextMessages_CBTCTextMessage> firstValue = X().low_priority_message_list.front();
            CBTCTextMessages_CBTCTextMessage                    first_message = firstValue.second;
            
            // Push the FSB_WHILE_DOCKING if it is not already push 
            if (first_message.id() != CBTC::Protos::TextId::FSB_WHILE_DOCKING)
            {
                X().low_priority_message_list.push_front(std::pair<double, CBTCTextMessages_CBTCTextMessage>(elapsed_time, new_message));
            }
        }
        else
        {
            X().low_priority_message_list.push_front(std::pair<double, CBTCTextMessages_CBTCTextMessage>(elapsed_time, new_message));
        }

    }

    if (DEBUG)
        Trace::GetLogger().STAMP(Trace::INFO) << "AddTextMessage (id, ack_data) : " << id << ", " << msg_ack << Trace::EndLog();
}

/// Clears the messages from the list of high priority text messages if end condition is met and places the text message
/// into the low priority list
///
/// @param elapsed_time   current simulator time
///
void TextManagementModule::ClearExpiredHighPriorityMessages(double elapsed_time)
{
    // Create a list of text messages that are to be cleared out of the high priority text message list
    vector<CBTC::Protos::TextId> clear_ids;

    // Check if reported high priority text message needs to be moved to low priority text message list - Text ID 100
    if (IsMessageAlreadyInHighPriorityList(TextId::AM_MODE_IS_AVAILABLE) &&
        (!U().transition_into_automatic || 
		(!U().ato_is_available && U().selected_driving_mode != Project::TypeValue::DriverModeSelection::ATP) ||
			U().current_train_speed > 0.0))
    {
        clear_ids.push_back(TextId::AM_MODE_IS_AVAILABLE);
    }

    // Check if reported high priority text message needs to be moved to low priority text message list - Text ID 200
    /*if (IsMessageAlreadyInHighPriorityList(TextId::SWITCH_MODE_TO_CM) &&
        (!U().transition_into_semi_automatic || (U().cbtc_current_mode != Project::TypeValue::CBTCMode::AM
    ||U().cbtc_current_mode != Project::TypeValue::CBTCMode::ATO)))
    {
        clear_ids.push_back(TextId::SWITCH_MODE_TO_CM);

        if (X().last_reported_ack_message == TextId::SWITCH_MODE_TO_CM)
            X().last_reported_ack_message = UNDEFINED_TEXT_ID;
    }*/

    // Check if reported high priority text message needs to be moved to low priority text message list - Text ID 203
    if (IsMessageAlreadyInHighPriorityList(TextId::ATC_IS_BYPASSED) &&
        (U().cbtc_current_mode != Project::TypeValue::CBTCMode::ATC_BYPASS))
    {
        clear_ids.push_back(TextId::ATC_IS_BYPASSED);
    }

    // Move the High priority text message whose display conditions are no longer being met into the
    // low priority text message list
    for (auto& id : clear_ids)
    {
        auto high_priority_list_itr = std::find_if(X().high_priority_message_list.begin(),
                                                   X().high_priority_message_list.end(),
                                                   [id](const std::pair<double, CBTCTextMessages_CBTCTextMessage>& item)
                                                   { return (item.second.id() == id); });

        high_priority_list_itr->second.set_type(CBTC::Protos::TextMessagePriority::LOW);
        X().low_priority_message_list.push_front(
          std::pair<double, CBTCTextMessages_CBTCTextMessage>(elapsed_time, high_priority_list_itr->second));

        X().high_priority_message_list.remove_if([id](std::pair<double, CBTCTextMessages_CBTCTextMessage> msg)
                                                 { return (msg.second.id() == id); });
    }
}

/// Checks if a text message, with the given Text Id, already appears in the list of high priority text messages
///
/// @param id   Text ID Identifies the message being looked for
///
/// @returns true if text message appears in the list of text messages, otherwise false
///
bool TextManagementModule::IsMessageAlreadyInList(int id)
{
    bool ret = false;

    // Check for the text ID in the high priority message list
    auto high_priority_list_itr = std::find_if(X().high_priority_message_list.begin(),
                                               X().high_priority_message_list.end(),
                                               [id](const std::pair<double, CBTCTextMessages_CBTCTextMessage>& item)
                                               { return (item.second.id() == id); });

    // Check for the text ID in the low priority message list
    auto low_priority_list_itr = std::find_if(X().low_priority_message_list.begin(),
                                              X().low_priority_message_list.end(),
                                              [id](const std::pair<double, CBTCTextMessages_CBTCTextMessage>& item)
                                              { return (item.second.id() == id); });

    // Return true of we found the text Id being looked for
    if (low_priority_list_itr != X().low_priority_message_list.end() ||
        high_priority_list_itr != X().high_priority_message_list.end())
    {
        ret = true;
    }

    return ret;
}

/// Checks if a text message, with the given Text Id, already appears in the list of text messages
///
/// @param id   Text ID Identifies the message being looked for
///
/// @returns true if text message appears in the list of high priority text messages, otherwise false
///
bool TextManagementModule::IsMessageAlreadyInHighPriorityList(int id)
{
    // Check for the text ID in the high priority message list
    auto high_priority_list_itr = std::find_if(X().high_priority_message_list.begin(),
                                               X().high_priority_message_list.end(),
                                               [id](const std::pair<double, CBTCTextMessages_CBTCTextMessage>& item)
                                               { return (item.second.id() == id); });

    // Return true of we found the text Id in the high priority text message list
    if (high_priority_list_itr != X().high_priority_message_list.end())
        return true;

    return false;
}

/// Populates the CBTC text message list that is to be sent to the DMI
///
void TextManagementModule::PopulateOutputMessageList()
{
    size_t index = 0;
    Y().cbtc_text_messages.Clear();

    // Limit the number of text messages to a maximum size
    for (int excess_msgs = (X().low_priority_message_list.size() - MAX_NUM_TEXT_MESSAGES); excess_msgs > 0; excess_msgs--)
    {
        X().low_priority_message_list.pop_back();
    }

    // First populate the high priority messages into the list
    for (const auto& text_message : X().high_priority_message_list)
    {
        auto new_message = Y().cbtc_text_messages.add_cbtctextmessage();
        new_message->CopyFrom(text_message.second);
        new_message->set_index(index);
        index++;

        if (DEBUG)
        {
            Trace::GetLogger().STAMP(Trace::WARN)
              << "TextManagementModule - Messages :"
              << "ID" << new_message->id() << "\n Unique ID: " << new_message->uniqueid() << Trace::EndLog();
        }
    }

    // Now populate the low priority messages into the list
    for (const auto& text_message : X().low_priority_message_list)
    {
        auto new_message = Y().cbtc_text_messages.add_cbtctextmessage();
        new_message->CopyFrom(text_message.second);
        new_message->set_index(index);
        index++;

        if (DEBUG)
        {
            Trace::GetLogger().STAMP(Trace::WARN)
              << "TextManagementModule - Messages :"
              << "ID" << new_message->id() << "\n Unique ID: " << new_message->uniqueid() << Trace::EndLog();
        }
    }
}

/// Manages the clearing of all text messages as required
///
void TextManagementModule::ManageClearAllMessages()
{
    X().high_priority_message_list.clear();
    X().low_priority_message_list.clear();
    X().new_high_priority_msg_reported = false;
    X().new_acknowledge_msg_reported   = false;
    X().unique_message_id              = 0;
}

/// Calculates and return unique ID each time it gets called.
///
/// @returns First time it will return 1, and incrementing by 1 thereafter
///
int TextManagementModule::GenerateUniqueMessageId()
{
    return (++X().unique_message_id);
}
