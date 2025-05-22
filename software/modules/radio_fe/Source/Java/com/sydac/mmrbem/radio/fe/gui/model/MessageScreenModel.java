/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.gui.model;

import java.util.stream.Collectors;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.gui.i18n.CommonStrings;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.radio.common.data.MessageTableDO;
import com.sydac.radio.proto.RadioProtos;
import com.sydac.radio.proto.RadioProtos.InBoxMessage;
import com.sydac.radio.proto.RadioProtos.OutBoxMessage;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;
import javafx.collections.FXCollections;

public class MessageScreenModel extends AbstractScreenModel
{

  private IntegerProperty selectedInBoxMessageId = new SimpleIntegerProperty();

  private IntegerProperty selectedOutBoxMessageId = new SimpleIntegerProperty();

  private IntegerProperty selectedInBoxOutBoxBtnId = new SimpleIntegerProperty();

  private ListProperty<MessageTableDO> inBoxMessageList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<MessageTableDO> outBoxMessageList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private IntegerProperty inBoxMessageId = new SimpleIntegerProperty();

  private StringProperty inBoxMessageText = new SimpleStringProperty();

  private IntegerProperty outBoxMessageId = new SimpleIntegerProperty();

  private StringProperty outBoxMessageText = new SimpleStringProperty();

  private StringProperty outBoxMessageCode = new SimpleStringProperty();

  public MessageScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public ListProperty<MessageTableDO> getInBoxMessageList()
  {
    return inBoxMessageList;
  }

  public ListProperty<MessageTableDO> getOutBoxMessageList()
  {
    return outBoxMessageList;
  }

  public void setSelectedInboxMessageId(Integer selectedMsgId)
  {
    this.selectedInBoxMessageId.set(selectedMsgId);
  }

  public IntegerProperty getSelectedInBoxMessageId()
  {
    return selectedInBoxMessageId;
  }

  public void setSelectedOutBoxMessageId(Integer outBoxMessageId)
  {
    this.selectedOutBoxMessageId.set(outBoxMessageId);
  }

  public IntegerProperty getSelectedOutBoxMessageId()
  {
    return selectedOutBoxMessageId;
  }

  public void setInBoxMessageList(byte[] msgList)
  {
    try
    {
      this.inBoxMessageList.clear();
      if (msgList.length != 0)
      {
        this.inBoxMessageList.addAll(RadioProtos.MessageList.parseFrom(msgList).getMessagesList().stream()
            .map(message -> new MessageTableDO(message.getMessageText(), message.getMessageId(),
                message.getDateTime()))
            .collect(Collectors.toList()));
      }
    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }

  }

  public void setOutBoxMessageList(byte[] msgList)
  {
    try
    {
      this.outBoxMessageList.clear();
      if (msgList.length != 0)
      {
        this.outBoxMessageList.addAll(RadioProtos.MessageList.parseFrom(msgList).getMessagesList().stream()
            .map(message -> new MessageTableDO(message.getMessageText(), message.getMessageId(),
                message.getDateTime()))
            .collect(Collectors.toList()));
      }
    }
    catch (InvalidProtocolBufferException e)
    {
      Tracer.getInstance().error(e);
    }

  }

  public void setSelectedInBoxOutBoxBtnId(Integer btnId)
  {
    selectedInBoxOutBoxBtnId.set(btnId);
  }

  public IntegerProperty getSelectedInBoxOutBoxBtnId()
  {
    return selectedInBoxOutBoxBtnId;
  }

  public void setInBoxMessage(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        InBoxMessage msg = InBoxMessage.parseFrom(newValue);

        inBoxMessageId.set(msg.getMessageId());
        inBoxMessageText.set(msg.getMessageText());
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      inBoxMessageId.set(0);
      inBoxMessageText.set(CommonStrings.BLANK);
    }

  }

  public IntegerProperty getInBoxMessageId()
  {
    return inBoxMessageId;
  }

  public StringProperty getInBoxMessageText()
  {
    return inBoxMessageText;
  }

  public void setOutBoxMessage(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        OutBoxMessage msg = OutBoxMessage.parseFrom(newValue);
        outBoxMessageId.set(msg.getMessageId());
        outBoxMessageText.set(msg.getMessageText());
        outBoxMessageCode.set(msg.getStatusCode());
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      outBoxMessageId.set(0);
      outBoxMessageText.set(CommonStrings.BLANK);
      outBoxMessageCode.set(CommonStrings.BLANK);
    }

  }

  public IntegerProperty getOutBoxMessageId()
  {
    return outBoxMessageId;
  }

  public StringProperty getOutBoxMessageText()
  {
    return outBoxMessageText;
  }

  public StringProperty getOutBoxMessageCode()
  {
    return outBoxMessageCode;
  }

}
