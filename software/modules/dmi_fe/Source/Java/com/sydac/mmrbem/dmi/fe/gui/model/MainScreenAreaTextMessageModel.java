package com.sydac.mmrbem.dmi.fe.gui.model;

import java.util.stream.Collectors;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.dmi.common.protos.DMIProtos;
import com.sydac.mmrbem.dmi.fe.gui.data.TextMsgInfoDO;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class MainScreenAreaTextMessageModel extends AbstractScreenModel
{
  private ListProperty<TextMsgInfoDO> textMessageList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private BooleanProperty upButtonStatus = new SimpleBooleanProperty();

  private BooleanProperty downButtonStatus = new SimpleBooleanProperty();

  private BooleanProperty newMessageIndicaton = new SimpleBooleanProperty();

  public MainScreenAreaTextMessageModel(int carIndex)
  {
    super(carIndex);
  }

  public void setActiveTextMessages(byte[] messagesList)
  {
    if (messagesList.length != 0)
    {
      try
      {
        DMIProtos.TextMessages messages = DMIProtos.TextMessages.parseFrom(messagesList);

        textMessageList.clear();
        textMessageList.addAll(FXCollections.observableArrayList(messages.getTextMessageList().stream()
            .map(message -> new TextMsgInfoDO(message.getUniqueId(), message.getDisplayText(),
                message.getTimeStamp(), message.getAckState(), message.getPriority()))
            .collect(Collectors.toList())));
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setTextMessageUpButtonStatus(Boolean value)
  {
    upButtonStatus.set(value);
  }

  public void setTextMessageDownButtonStatus(Boolean value)
  {
    downButtonStatus.set(value);
  }

  public BooleanProperty getUpButtonStatus()
  {
    return upButtonStatus;
  }

  public BooleanProperty getDownButtonStatus()
  {
    return downButtonStatus;
  }

  public void setNewMessageIndication(Boolean value)
  {
    newMessageIndicaton.set(value);
  }

  public BooleanProperty getNewMessageIndicaton()
  {
    return newMessageIndicaton;
  }

  public ListProperty<TextMsgInfoDO> getTextMessageList()
  {
    return textMessageList;
  }

}
