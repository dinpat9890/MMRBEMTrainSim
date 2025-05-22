/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import com.sydac.mmrbem.cabscreens.fe.common.DateTimeModel;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsScreenChangeProperties;

import javafx.beans.property.DoubleProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class HeaderPanelModel extends AbstractScreenModel implements IAppOutputsScreenChangeProperties
{

  private IntegerProperty currentScreenId = new SimpleIntegerProperty();

  private IntegerProperty currentCctvScreenId = new SimpleIntegerProperty();

  private DoubleProperty trainSpeed = new SimpleDoubleProperty();

  private DoubleProperty speedLimit = new SimpleDoubleProperty();

  private StringProperty currentTime = new SimpleStringProperty();

  private StringProperty currentDate = new SimpleStringProperty();

  private IntegerProperty operatingMode = new SimpleIntegerProperty();

  private IntegerProperty drivingMode = new SimpleIntegerProperty();

  private IntegerProperty passengerCount = new SimpleIntegerProperty();

  private IntegerProperty loginTitleInfo = new SimpleIntegerProperty();

  private static final String UTC = "UTC"; //$NON-NLS-1$

  private SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm:ss"); //$NON-NLS-1$

  private SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy"); //$NON-NLS-1$

  public HeaderPanelModel(int scenarioCarIndex)
  {
    super(scenarioCarIndex);
    processDateAndTime();
  }

  /**
   * Process date and time fetched from {@link DateTimeModel} and formats it to
   * required format for header panel.
   */
  private void processDateAndTime()
  {
    DateTimeModel.getSimTimeProperty().addListener((observable, oldValue, newValue) -> {
      Date date = new Date((long)newValue.doubleValue());
      timeFormat.setTimeZone(TimeZone.getTimeZone(UTC));
      dateFormat.setTimeZone(TimeZone.getTimeZone(UTC));

      currentTime.set(timeFormat.format(date));
      currentDate.set(dateFormat.format(date));
    });
  }

  public IntegerProperty getCurrentScreenId()
  {
    return currentScreenId;
  }

  public void setCurrentScreenId(int currentScreenId)
  {
    this.currentScreenId.set(currentScreenId);
  }

  public DoubleProperty getTrainSpeed()
  {
    return trainSpeed;
  }

  public void setTrainSpeed(double currentSpeed)
  {
    this.trainSpeed.set(currentSpeed);
  }

  public StringProperty getCurrentTime()
  {
    return currentTime;
  }

  public void setCurrentTime(String currentTime)
  {
    this.currentTime.set(currentTime);
  }

  public StringProperty getCurrentDate()
  {
    return currentDate;
  }

  public void setCurrentDate(String currentDate)
  {
    this.currentDate.set(currentDate);
  }

  public IntegerProperty getOperatingMode()
  {
    return operatingMode;
  }

  public void setOperatingMode(int operatingMode)
  {
    this.operatingMode.set(operatingMode);
  }

  public IntegerProperty getDrivingMode()
  {
    return drivingMode;
  }

  public void setDrivingMode(int drivingMode)
  {
    this.drivingMode.set(drivingMode);
  }

  public IntegerProperty getPassengerCount()
  {
    return passengerCount;
  }

  public void setPassengerCount(int passengerCount)
  {
    this.passengerCount.set(passengerCount);
  }

  public DoubleProperty getSpeedLimit()
  {
    return speedLimit;
  }

  public void setSpeedLimit(double speedLimit)
  {
    this.speedLimit.set(speedLimit);
  }

  public IntegerProperty getLoginTitleInfo()
  {
    return loginTitleInfo;
  }

  public void setLoginTitleInfo(int loginTitleInfo)
  {
    this.loginTitleInfo.set(loginTitleInfo);
  }

  public IntegerProperty getCurrentCctvScreenId()
  {
    return currentCctvScreenId;
  }

  public void setCurrentCctvScreenId(Integer currentCctvScreenId)
  {
    this.currentCctvScreenId.set(currentCctvScreenId);
  }

}
