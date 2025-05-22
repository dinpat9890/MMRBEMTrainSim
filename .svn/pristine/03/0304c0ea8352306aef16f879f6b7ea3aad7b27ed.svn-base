/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.backend.logic.handler;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.radio.backend.logic.SharedDataModel;
import com.sydac.mmrbem.radio.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.radio.backend.radiointercom.properties.IRadioIntercomOutputProperties;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.common.data.MessageDO;
import com.sydac.mmrbem.radio.common.io.RadioPropertiesReader;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsKeyPadPanelProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsMessageScreenProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputMessageScreenProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputsHeaderProperties;
import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.radio.proto.RadioProtos.MessageList;

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class MessageOutBoxListScreenHandler extends AbstractFunctionalLogic implements IScreenChangeListener
{

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  @Autowired
  private SharedDataModel sharedDataModel;

  @Autowired
  private KeyPadHandler keyPadHandler;

  private List<MessageDO> messageList = new ArrayList<>();

  private int selectedMsgId = 0;
  
  

  public MessageOutBoxListScreenHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IRadioIntercomOutputProperties.class, IAppInputsMessageScreenProperties.class,
        IAppInputsKeyPadPanelProperties.class);

    initMessageList();

  }

  private void initMessageList()
  {

    messageList = RadioPropertiesReader.getInstance().getOutboxMsgMap().entrySet().stream()
        .map(m -> new MessageDO(m.getValue().getMsgText(), m.getKey(), new Date().getTime()))
        .collect(Collectors.toList());
    
  
  }

  private void updateOutBoxMsgList()
  {
    MessageList.Builder msgList = MessageList.newBuilder();
    messageList.forEach(m -> {
      MessageList.Message.Builder message = MessageList.Message.newBuilder();

      message.setMessageId(m.getMsgId());
      message.setMessageText(m.getMsgText());
      message.setDateTime(m.getDateTime());

      msgList.addMessages(message);

    });
    setApplicationOutputsProperty(IAppOutputMessageScreenProperties.OUTBOX_MESSAGE_LIST,
        msgList.build().toByteArray());
    
    setApplicationOutputsProperty(IAppOutputsHeaderProperties.MESSAGE_COUNT,
        messageList.size()); //Fixed for MMRBEM-3084 ,as per the latest comment on task.Implemented only for Outbox.
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (IAppInputsMessageScreenProperties.OUTBOX_MSG_LIST_SELECTED_ID.equals(key) && selectedMsgId > 0)
    {
      selectedMsgId = (Integer)newValue;
      setMessageId(selectedMsgId);
    }
    else if (IAppInputsKeyPadPanelProperties.BTN_DOWN_ARROW_REQUEST.equals(key) && (Integer)newValue > 0)
    {
      MessageDO message = messageList.stream().filter(m -> m.getMsgId() == selectedMsgId).findFirst()
          .orElse(null);
      int index = 0;
      if (message != null)
      {
        index = messageList.indexOf(message);
      }
      int nextMsgIndex = index + 1;
      if (messageList.size() > nextMsgIndex)
      {
        selectedMsgId = messageList.get(nextMsgIndex).getMsgId();
        setMessageId(selectedMsgId);
      }
    }
    else if (IAppInputsKeyPadPanelProperties.BTN_UP_ARROW_REQUEST.equals(key) && (Integer)newValue > 0)
    {
      MessageDO message = messageList.stream().filter(m -> m.getMsgId() == selectedMsgId).findFirst()
          .orElse(null);
      int index = 0;
      if (message != null)
      {
        index = messageList.indexOf(message);
      }
      int nextMsgIndex = index - 1;
      if (nextMsgIndex != -1)
      {
        selectedMsgId = messageList.get(nextMsgIndex).getMsgId();
        setMessageId(selectedMsgId);
      }
    }
    else if (IAppInputsKeyPadPanelProperties.ENTER_START_CALL_BTN_REQUEST.equals(key) && (Integer)newValue > 0
        && sharedDataModel.getScreenId() == ScreenId.MESSAGE_OUTBOX_LIST_SCREEN.getId())
    {

      screenChangeHandler.requestScreenChange(ScreenId.OUTBOX_MESSAGE_SCREEN);
     
    }
  }

  private void setMessageId(int msgId)
  {
    setApplicationOutputsProperty(IAppOutputMessageScreenProperties.OUTBOX_MSG_LIST_SELECTED_ID,
        msgId);
  }

  public void addMessage(MessageDO messageDO)
  {
    messageList.add(messageDO);

    updateOutBoxMsgList();

    screenChangeHandler.requestScreenChange(ScreenId.MESSAGE_OUTBOX_LIST_SCREEN);

  }

  @Override
  public void onEnteringScreen(int screenId)
  {
    if (ScreenId.OUTBOX_MESSAGE_SCREEN.getId() == screenId)
    {
      keyPadHandler.clearOuBoxMsg();
    }
    else
    {
      selectedMsgId = ApplicationConstants.RESET_VALUE;
      setMessageId(1);
      updateOutBoxMsgList();
    }

  }

  @Override
  public void onLeavingScreen(int screenId)
  {

  }
}
