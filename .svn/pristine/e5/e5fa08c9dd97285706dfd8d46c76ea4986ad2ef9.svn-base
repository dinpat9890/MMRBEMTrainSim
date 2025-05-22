/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.papis.common.data.MultiplePecuCallModel;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.MultiplePecuCallList;
import com.sydac.mmrbem.papis.common.protos.PAPISProtos.MultiplePecuCallList.MultiplePecuCall;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class PassengerAlarmScreenModel extends AbstractScreenModel
{
  private IntegerProperty alarmStatus = new SimpleIntegerProperty();

  private IntegerProperty intercomStatus = new SimpleIntegerProperty();

  private IntegerProperty activeCallType = new SimpleIntegerProperty();

  private IntegerProperty pecuId = new SimpleIntegerProperty();

  private BooleanProperty upArrowPressed = new SimpleBooleanProperty();

  private BooleanProperty downArrowPressed = new SimpleBooleanProperty();

  private IntegerProperty selectedAlarm = new SimpleIntegerProperty();

  private IntegerProperty alarmState = new SimpleIntegerProperty();
  
  private IntegerProperty callCount = new SimpleIntegerProperty();

  private MultiplePecuCallList multiplePecuCallList;

  private ListProperty<MultiplePecuCallModel> pecuCallList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public PassengerAlarmScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getAlarmStatus()
  {
    return alarmStatus;
  }

  public void setAlarmStatus(Integer state)
  {
    alarmStatus.set(state);
  }

  public void setIntercomStatus(Integer newValue)
  {
    this.intercomStatus.set(newValue);
  }

  public IntegerProperty getIntercomStatus()
  {
    return intercomStatus;
  }

  public void setActiveCallType(Integer activeCallType)
  {
    this.activeCallType.set(activeCallType);

  }

  public IntegerProperty getActiveCallType()
  {
    return activeCallType;
  }

  public IntegerProperty getPecuId()
  {
    return pecuId;
  }

  public void setPecuId(Integer pecuId)
  {
    this.pecuId.set(pecuId);
  }

  public BooleanProperty getUpArrowPressed()
  {
    return upArrowPressed;
  }

  public void setUpArrowPressed(Integer upArrowPressed)
  {
    this.upArrowPressed.set(upArrowPressed == 1);
  }

  public BooleanProperty getDownArrowPressed()
  {
    return downArrowPressed;
  }

  public void setDownArrowPressed(Integer downArrowPressed)
  {
    this.downArrowPressed.set(downArrowPressed == 1);
  }

  public void setSelectedAlarm(Integer newValue)
  {
    this.selectedAlarm.set(newValue);

  }

  public IntegerProperty getSelectedAlarm()
  {
    return selectedAlarm;
  }

  public void setAlarmState(Integer newValue)
  {
    this.alarmState.set(newValue);

  }

  public IntegerProperty getAlarmState()
  {
    return alarmState;
  }

  public void setMultipleCallList(byte[] lineList)
  {

    if (lineList.length != 0)
    {
      try
      {
        this.multiplePecuCallList = PAPISProtos.MultiplePecuCallList.parseFrom(lineList);

        updateLineList();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public ListProperty<MultiplePecuCallModel> getMultipleCallList()
  {
    return pecuCallList;
  }

  private void updateLineList()
  {
    if (multiplePecuCallList != null)
    {
      pecuCallList.clear();
      for (MultiplePecuCall list : this.multiplePecuCallList.getMultiplePecuCallList())
      {
          pecuCallList.add(new MultiplePecuCallModel(list.getPecuId(), list.getPecuName()));
      }

    }

  }

  public void setCallCount(Integer newValue)
  {
    this.callCount.set(newValue);
    
  }

  public IntegerProperty getCallCount()
  {
    return callCount;
  }

}
