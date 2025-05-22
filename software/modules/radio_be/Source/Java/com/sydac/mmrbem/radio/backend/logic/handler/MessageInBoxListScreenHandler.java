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
import com.sydac.radio.proto.RadioProtos.InBoxMessage;
import com.sydac.radio.proto.RadioProtos.MessageList;

/**
 * This handler class is used for Message Logic
 * 
 * @author ext-tambet
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class MessageInBoxListScreenHandler extends AbstractFunctionalLogic implements IScreenChangeListener
{

  private List<MessageDO> messageList = new ArrayList<>();

  private int selectedMsgId = 0;

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  @Autowired
  private SharedDataModel sharedDataModel;

  public MessageInBoxListScreenHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IRadioIntercomOutputProperties.class, IAppInputsMessageScreenProperties.class,
        IAppInputsKeyPadPanelProperties.class);

    initMessageList();

  }

  private void initMessageList()
  {

    messageList = RadioPropertiesReader.getInstance().getInboxMsgMap().entrySet().stream()
        .map(m -> new MessageDO(m.getValue().getMsgText(), m.getKey(), new Date().getTime()))
        .collect(Collectors.toList());

  }

  private void updateInboxMessageList()
  {
    MessageList.Builder msgList = MessageList.newBuilder();
    messageList.forEach(m -> {
      MessageList.Message.Builder message = MessageList.Message.newBuilder();

      message.setMessageId(m.getMsgId());
      message.setMessageText(m.getMsgText());
      message.setDateTime(m.getDateTime());

      msgList.addMessages(message);

    });
    setApplicationOutputsProperty(IAppOutputMessageScreenProperties.INBOX_MESSAGE_LIST,
        msgList.build().toByteArray());
    setApplicationOutputsProperty(IAppOutputsHeaderProperties.MESSAGE_COUNT,
        messageList.size());
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (IAppInputsMessageScreenProperties.INBOX_MSG_LIST_SELECTED_ID.equals(key) && (Integer)newValue > 0)
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
        && sharedDataModel.getScreenId() == ScreenId.MESSAGE_INBOX_LIST_SCREEN.getId())
    {

      MessageDO message = messageList.stream().filter(m -> m.getMsgId() == selectedMsgId).findFirst()
          .orElse(null);
      byte[] msg = new byte[0];
      if (message != null)
      {
        InBoxMessage.Builder inBoxMsg = InBoxMessage.newBuilder();

        inBoxMsg.setMessageId(message.getMsgId());
        inBoxMsg.setMessageText(message.getMsgText());

        msg = inBoxMsg.build().toByteArray();
      }
      setApplicationOutputsProperty(IAppOutputMessageScreenProperties.INBOX_MESSAGE, msg);
      screenChangeHandler.requestScreenChange(ScreenId.INBOX_MESSAGE_SCREEN);

    }
  }

  private void setMessageId(int msgId)
  {
    setApplicationOutputsProperty(IAppOutputMessageScreenProperties.INBOX_MSG_LIST_SELECTED_ID,
        msgId);
  }

  @Override
  public void onEnteringScreen(int screenId)
  {
    selectedMsgId = ApplicationConstants.RESET_VALUE;
    setMessageId(1);
    updateInboxMessageList();
  }

  @Override
  public void onLeavingScreen(int screenId)
  {
    // TODO Auto-generated method stub

  }
}
