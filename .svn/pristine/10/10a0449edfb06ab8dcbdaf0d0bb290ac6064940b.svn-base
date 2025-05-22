/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.model;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.dmi.common.state.DMIDepartureInformation;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * A model to Main Screen Area D Middle
 * 
 * @author mulukg
 *
 */
public class MainScreenAreaDMiddleModel extends AbstractScreenModel
{
  private final IntegerProperty psdDoorStatus = new SimpleIntegerProperty();

  private final IntegerProperty trainDockingStatus = new SimpleIntegerProperty();

  private final StringProperty operationalServiceStoppingPointDistance = new SimpleStringProperty("");

  private final IntegerProperty departureOrder = new SimpleIntegerProperty();

  private final IntegerProperty departureInformation = new SimpleIntegerProperty(DMIDepartureInformation.NO_INDICATION.getValue());

  private final IntegerProperty trainDoorStatus = new SimpleIntegerProperty();

  private final StringProperty remainingDepartureTime = new SimpleStringProperty();

  private final BooleanProperty remainingTimeMinuteFlashStatus = new SimpleBooleanProperty();

  private final LongProperty flashTime = new SimpleLongProperty();
  
  private final IntegerProperty detrainmentDoorStatus = new SimpleIntegerProperty();
 
  public MainScreenAreaDMiddleModel(int carIndex)
  {
    super(carIndex);
  }

  public void setPsdDoorStatus(Integer value)
  {
    psdDoorStatus.set(value);
  }

  public IntegerProperty getPsdDoorStatus()
  {
    return psdDoorStatus;
  }

  public void setTrainDockingStatus(Integer dockingStatus)
  {
    trainDockingStatus.set(dockingStatus);
  }

  public void setOperationalServiceStoppingDistance(String stoppingDistance)
  {
    operationalServiceStoppingPointDistance.set(stoppingDistance);
  }

  public IntegerProperty getTrainDockingStatus()
  {
    return trainDockingStatus;
  }

  public StringProperty getOperationalServiceStoppingPointDistance()
  {
    return operationalServiceStoppingPointDistance;
  }

  public void setDepartureOrder(Integer value)
  {
    departureOrder.set(value);
  }

  public IntegerProperty getDepartureOrder()
  {
    return departureOrder;
  }

  public void setDepartureInformationStatus(Integer departureInformation)
  {
    this.departureInformation.set(departureInformation);
  }

  public IntegerProperty getDepartureInformation()
  {
    return departureInformation;
  }

  public void setTrainDoorStatus(Integer value)
  {
    trainDoorStatus.set(value);
  }

  public IntegerProperty getTrainDoorStatus()
  {
    return trainDoorStatus;
  }

  public void setRemainingTimeBeforeDeparture(String remainingTime)
  {
    remainingDepartureTime.set(remainingTime);
  }

  public void setRemainingTimeInMinuteStatus(Boolean minuteStatus)
  {
    remainingTimeMinuteFlashStatus.set(minuteStatus);
  }

  public StringProperty getRemainingDepartureTime()
  {
    return remainingDepartureTime;
  }

  public BooleanProperty getRemainingTimeMinuteFlashStatus()
  {
    return remainingTimeMinuteFlashStatus;
  }

  public void setFlashTime(Number dateTime)
  {
    flashTime.set((long)dateTime);
  }

  public LongProperty getFlashTime()
  {
    return flashTime;
  }
  
  public void setDetrainmentDoorStatus(Integer detrainmentDoorStatus) {
	this.detrainmentDoorStatus.set(detrainmentDoorStatus);;
  }

  public IntegerProperty getDetrainmentDoorStatus() {
	return detrainmentDoorStatus;
  }
  
}
