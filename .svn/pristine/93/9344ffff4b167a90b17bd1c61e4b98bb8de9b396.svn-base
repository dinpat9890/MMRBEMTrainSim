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

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.beans.property.SimpleIntegerProperty;

/**
 * A model to Main Screen Area B Left
 * 
 * @author mulukg
 *
 */
public class MainScreenAreaBLeftModel extends AbstractScreenModel
{

  private DoubleProperty currentTrainSpeed = new SimpleDoubleProperty();

  private IntegerProperty cbtcTargetSpeed = new SimpleIntegerProperty();

  private IntegerProperty cbtcPermittedSpeed = new SimpleIntegerProperty();

  private IntegerProperty currentDrivingMode = new SimpleIntegerProperty();

  private IntegerProperty warningStatus = new SimpleIntegerProperty();

  private BooleanProperty driverEventChangeEnds = new SimpleBooleanProperty();

  private BooleanProperty driverEventSkipStation = new SimpleBooleanProperty();

  private BooleanProperty driverEventWorkZone = new SimpleBooleanProperty();

  private BooleanProperty atcBypassState = new SimpleBooleanProperty();

  private final DoubleProperty advisorySpeed = new SimpleDoubleProperty();

  private final DoubleProperty warningSpeed = new SimpleDoubleProperty();

  private IntegerProperty neutralZoneStatus = new SimpleIntegerProperty();

  public MainScreenAreaBLeftModel(int carIndex)
  {
    super(carIndex);
  }

  public void setCurrentTrainSpeed(Double value)
  {
    currentTrainSpeed.setValue(value);
  }

  public void setCbtcTargetSpeed(Integer value)
  {
    cbtcTargetSpeed.set(value);
  }

  public void setCbtcPermittedSpeed(Integer value)
  {
    cbtcPermittedSpeed.set(value);
  }

  public void setCurrentDrivingMode(Integer value)
  {
    currentDrivingMode.set(value);
  }

  public void setWarningStatus(Integer value)
  {
    warningStatus.set(value);
  }

  public DoubleProperty getCurrentTrainSpeed()
  {
    return currentTrainSpeed;
  }

  public IntegerProperty getCbtcTargetSpeed()
  {
    return cbtcTargetSpeed;
  }

  public IntegerProperty getCbtcPermittedSpeed()
  {
    return cbtcPermittedSpeed;
  }

  public IntegerProperty getCurrentDrivingMode()
  {
    return currentDrivingMode;
  }

  public IntegerProperty getWarningStatus()
  {
    return warningStatus;
  }

  public void setDriverEventChangeEnds(Boolean value)
  {
    driverEventChangeEnds.set(value);
  }

  public void setDriverEventSkipStation(Boolean value)
  {
    driverEventSkipStation.set(value);
  }

  public void setDriverEventWorkZone(Boolean value)
  {
    driverEventWorkZone.set(value);
  }

  public BooleanProperty getDriverEventChangeEnds()
  {
    return driverEventChangeEnds;
  }

  public BooleanProperty getDriverEventSkipStation()
  {
    return driverEventSkipStation;
  }

  public BooleanProperty getDriverEventWorkZone()
  {
    return driverEventWorkZone;
  }

  /**
   * @return the atcBypassState
   */
  public BooleanProperty getAtcBypassState()
  {
    return atcBypassState;
  }

  /**
   * @param atcBypassState
   *          the atcBypassState to set
   */
  public void setAtcBypassState(Boolean atcBypassState)
  {
    this.atcBypassState.set(atcBypassState);
  }

  public void setAdvisorySpeed(Double value)
  {
    advisorySpeed.set(value);
  }

  public DoubleProperty getAdvisorySpeed()
  {
    return advisorySpeed;
  }

  public void setWarningSpeed(Double value)
  {
    warningSpeed.set(value);
  }

  public DoubleProperty getWarningSpeed()
  {
    return warningSpeed;
  }

  public IntegerProperty getNeutralZoneStatus()
  {
    return neutralZoneStatus;
  }

  public void setNeutralZoneStatus(Integer neutralZoneStatus)
  {
    this.neutralZoneStatus.set(neutralZoneStatus);
  }

}