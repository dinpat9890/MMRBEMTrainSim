/*
 * ================================================================== (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.model;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TimeZone;

import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

/**
 * A model to Main Screen
 * 
 * @author mulukg
 *
 */

public class MainScreenModel extends AbstractScreenModel
{
  private static final String UTC = "UTC"; //$NON-NLS-1$

  private StringProperty currentDateProperty = new SimpleStringProperty();

  private StringProperty currentHourAndMinProperty = new SimpleStringProperty();

  private SimpleDateFormat timeFormat = new SimpleDateFormat("HH:mm:ss"); //$NON-NLS-1$

  private SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy"); //$NON-NLS-1$

  private final IntegerProperty safteyBrakeStatus = new SimpleIntegerProperty();

  private final IntegerProperty advisorySpeed = new SimpleIntegerProperty();

  private IntegerProperty currentTrainSpeed = new SimpleIntegerProperty();

  private IntegerProperty currentDrivingMode = new SimpleIntegerProperty();

  private IntegerProperty lifeIndicatorStatus = new SimpleIntegerProperty();

  private StringProperty serviceNumber = new SimpleStringProperty();

  private StringProperty destinationId = new SimpleStringProperty();

  private BooleanProperty menuPanelStatus = new SimpleBooleanProperty();

  private final StringProperty crewNumber = new SimpleStringProperty();

  private final BooleanProperty crewIdPanelStatus = new SimpleBooleanProperty();

  private final IntegerProperty warningSpeed = new SimpleIntegerProperty();

  private final StringProperty areaD1Label = new SimpleStringProperty();

  private StringProperty destinationCode = new SimpleStringProperty();

  private IntegerProperty selectedSettingsPanelId = new SimpleIntegerProperty();

  private IntegerProperty selectedBrightnessValue = new SimpleIntegerProperty();

  private IntegerProperty selectedAudioValue = new SimpleIntegerProperty();

  public MainScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getSafteyBrakeStatus()
  {
    return safteyBrakeStatus;
  }

  public void setSafetyBrakeStatus(Integer safetyBrakeStatus)
  {
    this.safteyBrakeStatus.set(safetyBrakeStatus);
  }

  public StringProperty currentDateProperty()
  {
    return currentDateProperty;
  }

  public StringProperty currentHourAndMinProperty()
  {
    return currentHourAndMinProperty;
  }

  public void setAdvisorySpeed(Integer value)
  {
    advisorySpeed.set(value);
  }

  public IntegerProperty getAdvisorySpeed()
  {
    return advisorySpeed;
  }

  public void setCurrentDrivingMode(Integer value)
  {
    currentDrivingMode.set(value);
  }

  public void setCurrentTrainSpeed(Integer value)
  {
    currentTrainSpeed.setValue(value);
  }

  public IntegerProperty getCurrentTrainSpeed()
  {
    return currentTrainSpeed;
  }

  public IntegerProperty getCurrentDrivingMode()
  {
    return currentDrivingMode;
  }

  public void setLifeIndicatorStatus(Integer value)
  {
    lifeIndicatorStatus.set(value);
  }

  public void setServiceNumberValue(String value)
  {
    serviceNumber.set(value);
    updateAreaD1();
  }

  public StringProperty getServiceNumber()
  {
    return serviceNumber;
  }

  public IntegerProperty getLifeIndicatorStatus()
  {
    return lifeIndicatorStatus;
  }

  public void setMenuPanelStatus(Boolean menuStatus)
  {
    menuPanelStatus.set(menuStatus);
  }

  public BooleanProperty getMenuPanelStatus()
  {
    return menuPanelStatus;
  }

  public void setCurrentDateAndTime(Number dateTime)
  {
    Date date = new Date((long)dateTime.doubleValue());
    timeFormat.setTimeZone(TimeZone.getTimeZone(UTC));
    dateFormat.setTimeZone(TimeZone.getTimeZone(UTC));

    currentHourAndMinProperty.set(timeFormat.format(date));
    currentDateProperty.set(dateFormat.format(date));
  }

  public void setCrewNumber(String crewNum)
  {
    crewNumber.set(crewNum);
  }

  public void setCrewIdPanelStatus(boolean status)
  {
    crewIdPanelStatus.set(status);
  }

  /**
   * @return the crewNumber
   */
  public StringProperty getCrewNumber()
  {
    return crewNumber;
  }

  /**
   * @return the crewIdPanelStatus
   */
  public BooleanProperty getCrewIdPanelStatus()
  {
    return crewIdPanelStatus;
  }

  public void setWarningSpeed(Integer value)
  {
    warningSpeed.set(value);
  }

  public IntegerProperty getWarningSpeed()
  {
    return warningSpeed;
  }

  public void setAreaD1Label(String value)
  {
    areaD1Label.set(value);
  }

  public StringProperty getAreaD1Label()
  {
    return areaD1Label;
  }

  private void updateAreaD1()
  {
    if (getServiceNumber() != null)
    {
      if (getServiceNumber().get().length() == 1)
      {
        setAreaD1Label("0" + getServiceNumber().get()); //$NON-NLS-1$
      }
      else
      {
        setAreaD1Label(getServiceNumber().get());
      }
    }
  }

  public StringProperty getDestinationCode()
  {
    return destinationCode;
  }

  public void setDestinationCode(byte[] destinationCode)
  {
    this.destinationCode.set(new String(destinationCode));
  }

  public StringProperty getDestinationId()
  {
    return destinationId;
  }

  public void setDestinationId(Integer destinationId)
  {
    String destId = destinationId.toString();
    if (destinationId <= 0)
    {
      this.destinationId.set("00"); //$NON-NLS-1$
    }
    else
    {
      if (destId.length() == 1)
      {
        this.destinationId.set("0" + destId); //$NON-NLS-1$
      }
      else
      {
        this.destinationId.set(destId);
      }
    }
  }

  public IntegerProperty getSelectedSettingsPanelId()
  {
    return selectedSettingsPanelId;
  }

  public void setSelectedSettingsPanelId(Integer selectedSettingsPanelId)
  {
    this.selectedSettingsPanelId.set(selectedSettingsPanelId);
  }

  public IntegerProperty getSelectedBrightnessValue()
  {
    return selectedBrightnessValue;
  }

  public void setSelectedBrightnessValue(Integer selectedBrightnessValue)
  {
    this.selectedBrightnessValue.set(selectedBrightnessValue);
  }

  public IntegerProperty getSelectedAudioValue()
  {
    return selectedAudioValue;
  }

  public void setSelectedAudioValue(Integer selectedAudioValue)
  {
    this.selectedAudioValue.set(selectedAudioValue);
  }
}
