/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.logic.handler;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.stream.Collectors;

import org.springframework.stereotype.Service;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.common.registry.Registry;
import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.CBTCTextMessages;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.CBTCTextMessages.CBTCTextMessage;
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.TextMessagePriority;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.dmi.backend.logic.DateTimeModel;
import com.sydac.mmrbem.dmi.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCOnboardInputsProperties;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.ICBTCOnboardOutputsProperties;
import com.sydac.mmrbem.dmi.common.data.TextMessageDO;
import com.sydac.mmrbem.dmi.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsProperties;
import com.sydac.mmrbem.dmi.common.protos.DMIProtos;
import com.sydac.mmrbem.dmi.common.protos.DMIProtos.TextMessages.AckState;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;

/**
 * This handler class is responsible for managing Text Message display.
 * 
 * @author Bigi P
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class TextMessageHandler extends AbstractFunctionalLogic
{
  private static final String ECTS_TEXT_MESSAGE_DOMAIN = "etcsmessage"; //$NON-NLS-1$

  private static final String SPLIT_BY_NEWLINE_REGEX = "\\r?\\n"; //$NON-NLS-1$

  private static final int MAX_NO_OF_TEXT_MESSAGE_LINES = 5;

  private long SECOND_TO_MILLIS_CONVERSION_FACTOR = 1000L;

  /**
   * New message indication time in milliseconds.
   */
  private long newMsgIndicationDuration = Registry.getInstance().getInteger(ApplicationConstants.DOMAIN_NAME,
      ApplicationConstants.NEW_MESSAGE_INDICATION_DURATION, 10) * 1000L;

  /**
   * Time for which Ack button has to be disabled in milliseconds.
   */
  private long ackDisableDuration = Registry.getInstance().getInteger(ApplicationConstants.DOMAIN_NAME,
      ApplicationConstants.ACK_DISABLE_DURATION, 1) * SECOND_TO_MILLIS_CONVERSION_FACTOR;

  /**
   * Time at which new message indication displayed.
   */
  private long newMsgIndicationDisplayedTime;

  /**
   * The text message list that has to be displayed. It can be either most
   * recent high priority message or the non acknowledgement message list.
   */
  private List<TextMessageDO> textMessageList = new CopyOnWriteArrayList<>();

  /**
   * The local text message list that will be save all the text messages
   * received from onboard unit and save messages to above list.
   */
  private List<TextMessageDO> localTextMessageList = new ArrayList<>();

  private int uniqueId;

  /**
   * Index of the first message displayed in the text message area.
   */
  private int activeMessageIndex;

  /**
   * Time of the most recent message.
   */
  private long mostRecentMessageTime;

  /**
   * The time at which Ack button disabled.
   */
  private long ackDisabledTime;

  public TextMessageHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class, ICBTCOnboardOutputsProperties.class);
  }

  /**
   * Processes the CBTC text message list and updates the displayed messages.
   */
  private void processCBTCTextMessageList(byte[] textMessageByteArray)
  {

    try
    {
      List<CBTCTextMessage> cbtcTextMessages = CBTCTextMessages.parseFrom(textMessageByteArray)
          .getCbtcTextMessageList();

      List<CBTCTextMessage> sortedList = sort(cbtcTextMessages);
      // Hope the returned list retains its sorting order.
      List<CBTCTextMessage> highPriorityMessages = sortedList.stream()
          .filter(cbtcTextMessage -> cbtcTextMessage.getType() == TextMessagePriority.HIGH)
          .collect(Collectors.toList());

      // If high priority messages exist, display the most recent one alone.
      // Otherwise display all the messages in chronological order.
      if (!highPriorityMessages.isEmpty())
      {
        updateTextMessage(Arrays.asList(highPriorityMessages.get(0)));
      }
      else
      {
        updateTextMessage(sortedList);
      }

      // As the incoming text message list is updated, text messages are
      // displayed from beginning.
      updateActiveMessageIndex(0);
      updateAckDisabledTime(0);
      publishTextMessages();

      TextMessageDO recentMessage = !textMessageList.isEmpty() ? textMessageList.get(0) : null;
      // Update new message indication
      boolean newMessageIndication;
      if (recentMessage != null && recentMessage.getTimeStamp() > mostRecentMessageTime)
      {
        mostRecentMessageTime = recentMessage.getTimeStamp();
        newMessageIndication = true;
      }
      else
      {
        newMessageIndication = false;
      }
      publishNewMessageIndication(newMessageIndication);
    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }
  }

  /**
   * Updates text message list. This includes updating the displayed list,
   * Up/Down button status.
   * 
   * @param cbtcTextMessageList
   *          the new text message list
   */
  private void updateTextMessage(List<CBTCTextMessage> cbtcTextMessageList)
  {
    List<TextMessageDO> textMessageDOList = new ArrayList<>();
    long sessionStartTimeMillis = DateTimeModel.getInstance().getSessionStartTime();

    int localListSize = localTextMessageList.size();

    uniqueId = (localListSize == 0) ? 0 : localTextMessageList.get(localListSize - 1).getUniqueId();
    for (CBTCTextMessage cbtcTextMessage : cbtcTextMessageList)
    {
      String messageText = getTextMessageString(cbtcTextMessage.getId().getNumber());
      String[] messageTexts = messageText.split(SPLIT_BY_NEWLINE_REGEX);

      // For each line of the text message area, a TextMessageDO object is
      // created.
      // Timestamp is required only for the first line of the message.

      TextMessageDO textMessageDO = new TextMessageDO();
      textMessageDO.setUniqueId((int)cbtcTextMessage.getUniqueId());
      textMessageDO.setDisplayText(messageTexts[0]);
      textMessageDO.setAckState(cbtcTextMessage.getAckRequired() ? AckState.ACK_ENABLED : AckState.NO_ACK);

      // Onboard sends elapsed time. Add session start time to elapsed time
      // to find timestamp of the message.
      textMessageDO.setTimeStamp((long)cbtcTextMessage.getElapsedTime() * SECOND_TO_MILLIS_CONVERSION_FACTOR
          + sessionStartTimeMillis);

      textMessageDO.setPriority(cbtcTextMessage.getType());
      textMessageDOList.add(textMessageDO);

      if (localTextMessageList.isEmpty())
      {
        localTextMessageList.addAll(textMessageDOList);
      }
      else if (textMessageDO.getUniqueId() > uniqueId)
      {
        localTextMessageList.add(textMessageDO);
        uniqueId = textMessageDO.getUniqueId();
      }
      else if (textMessageDO.getUniqueId() == uniqueId)
      {
        localTextMessageList.remove(uniqueId - 1);
        localTextMessageList.add(textMessageDO);
      }
    }

    textMessageList = new ArrayList<>(sortByUniqueIdDesc(localTextMessageList));
  }

  private List<TextMessageDO> sortByUniqueIdDesc(List<TextMessageDO> localTextMessageList2)
  {
    List<TextMessageDO> modifiableList = new ArrayList<>(localTextMessageList2);
    modifiableList.sort((textMesage1, textMessage2) -> {
      int uid1 = textMesage1.getUniqueId();
      int uid2 = textMessage2.getUniqueId();
      return (uid2 - uid1);
    });
    return modifiableList;
  }

  /**
   * When message acknowledgement request comes it sets state of the
   * corresponding text message to ACK_DISABLED and publishes the list.
   * 
   * @param value
   */
  private void processAckRequest()
  {
    if (!textMessageList.isEmpty())
    {
      TextMessageDO textMessage = textMessageList.get(0);
      textMessage.setAckState(AckState.ACK_DISABLED);
      updateAckDisabledTime(DateTimeModel.getInstance().getTime());
      publishTextMessages();
    }
  }

  /**
   * Updates active message index.
   * 
   * @param aActiveMessageIndex
   */
  private void updateActiveMessageIndex(int aActiveMessageIndex)
  {
    activeMessageIndex = aActiveMessageIndex;
  }

  /**
   * Updates Ack button disabled time.
   */
  private void updateAckDisabledTime(long ackDisabledTime)
  {
    this.ackDisabledTime = ackDisabledTime;
  }

  /**
   * Publishes text messages. This includes publishing text message list and
   * Up/Down button status.
   */
  private void publishTextMessages()
  {
    publishActiveTextMessages();
    publishUpButtonStatus();
    publishDownButtonStatus();
  }

  /**
   * Publishes Up button status. The button is enabled only if there is any
   * entry before the first active message.
   */
  private void publishUpButtonStatus()
  {
    getAppOutputHandler().setTextMessageUpButtonStatus(activeMessageIndex > 0);
  }

  /**
   * Publishes Down button status. The button is enabled only if there is any
   * entry after the last active message.
   */
  private void publishDownButtonStatus()
  {
    getAppOutputHandler().setTextMessageDownButtonStatus(
        activeMessageIndex + MAX_NO_OF_TEXT_MESSAGE_LINES < textMessageList.size());
  }

  /**
   * Publishes text messages that are to be displayed.
   */
  private void publishActiveTextMessages()
  {

    try
    {

      int endIndex = textMessageList.size() < activeMessageIndex + MAX_NO_OF_TEXT_MESSAGE_LINES
          ? textMessageList.size()
          : activeMessageIndex + MAX_NO_OF_TEXT_MESSAGE_LINES;
      List<TextMessageDO> activeTextMessageList = textMessageList.subList(activeMessageIndex, endIndex);

      getAppOutputHandler().setActiveTextMessages(getRawFor(activeTextMessageList));

    }
    catch (IndexOutOfBoundsException e)
    {
      Tracer.getInstance().error(e);
    }
  }

  /**
   * Publishes new message indications status.
   */
  private void publishNewMessageIndication(boolean status)
  {
    newMsgIndicationDisplayedTime = status ? DateTimeModel.getInstance().getTime() : 0;
    setApplicationOutputsProperty(IAppOutputsProperties.NEW_MESSGAE_INDICATION, status);
  }

  private byte[] getRawFor(List<TextMessageDO> textMessageList)
  {
    DMIProtos.TextMessages.Builder builder = DMIProtos.TextMessages.newBuilder();
    for (TextMessageDO textMessageDO : textMessageList)
    {
      DMIProtos.TextMessages.TextMessage.Builder stateBuilder = DMIProtos.TextMessages.TextMessage
          .newBuilder();
      stateBuilder.setUniqueId(textMessageDO.getUniqueId());
      stateBuilder.setDisplayText(textMessageDO.getDisplayText());
      stateBuilder.setTimeStamp(textMessageDO.getTimeStamp());
      stateBuilder.setAckState(textMessageDO.getAckState());
      stateBuilder.setPriority(textMessageDO.getPriority().getNumber());
      builder.addTextMessage(stateBuilder);
    }

    return builder.build().toByteArray();
  }

  /**
   * Sorts the specified list of text messages in chronological order.
   * 
   * @param messageList
   *          sorted message list.
   */
  private List<CBTCTextMessage> sort(List<CBTCTextMessage> messageList)
  {
    // As the unmodifiableList cannot be sorted, first create a modifiable list.
    List<CBTCTextMessage> modifiableList = new ArrayList<>(messageList);
    modifiableList.sort((textMessage1, textMessage2) -> {
      long time1 = (long)textMessage1.getElapsedTime();
      long time2 = (long)textMessage2.getElapsedTime();
      return (int)(time2 - time1);
    });

    return modifiableList;
  }

  /**
   * Gets the message to be displayed corresponding to the message id.
   * 
   * @param messageId
   *          The message id.
   * @return the display text
   */
  private String getTextMessageString(int messageId)
  {
    return Registry.getInstance().getString(ECTS_TEXT_MESSAGE_DOMAIN, String.valueOf(messageId));
  }

  /**
   * Handles Up button request. Can be processed directly as Up button is
   * enabled only if Up navigation is allowed.
   */
  private void handleUpButtonRequest(boolean requestStatus)
  {
    if (requestStatus)
    {
      activeMessageIndex--;
      publishTextMessages();
    }
  }

  /**
   * Handles Down button request. Can be processed directly as Down button is
   * enabled only if Down navigation is allowed.
   */
  private void handleDownButtonRequest(boolean requestStatus)
  {
    if (requestStatus)
    {
      activeMessageIndex++;
      publishTextMessages();
    }
  }

  @Override
  public void process(long aSimTime)
  {
    // If new message indication is displayed for the required duration stop the
    // display.
    if (newMsgIndicationDisplayedTime > 0 && (DateTimeModel.getInstance().getTime()
        - newMsgIndicationDisplayedTime) >= newMsgIndicationDuration)
    {
      publishNewMessageIndication(false);
    }

    // If Ack button is disabled for the required duration, send acknowledge
    // request to onboard.
    if (ackDisabledTime > 0
        && (DateTimeModel.getInstance().getTime() - ackDisabledTime) >= ackDisableDuration)
    {
      IPropertySetter onboardInputSetter = getCbtcOnboardInputsSetter(getActiveVehicleIndex());
      if (onboardInputSetter != null && !textMessageList.isEmpty())
      {
        sendPulseRequest(onboardInputSetter, ICBTCOnboardInputsProperties.CBTC_MESSAGE_ACKNOWLEDGE,
            textMessageList.get(0).getUniqueId(), 0);
      }
      updateAckDisabledTime(0);
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsProperties.TEXT_MESSAGE_UP_BUTTON_REQUEST))
      {
        handleUpButtonRequest((Boolean)newValue);
      }
      else if (key.equals(IAppInputsProperties.TEXT_MESSAGE_DOWN_BUTTON_REQUEST))
      {
        handleDownButtonRequest((Boolean)newValue);
      }
      else if (key.equals(IAppInputsProperties.TEXT_MESSAGE_ACKNOWLEDGE_REQUEST) && (Integer)newValue > 0)
      {
        processAckRequest();
      }
    }
  }

  @Override
  public <T> void cbtcOnboardOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(ICBTCOnboardOutputsProperties.CBTC_TEXT_MESSAGES))
      {
        processCBTCTextMessageList((byte[])newValue);
      }
    }
  }
}