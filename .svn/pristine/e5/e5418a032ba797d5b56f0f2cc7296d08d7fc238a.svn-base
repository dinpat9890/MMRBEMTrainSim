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
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;

/**
 * A model to Main Screen Area A
 * 
 * @author mulukg
 *
 */
public class MainScreenAreaAModel extends AbstractScreenModel
{
  private final IntegerProperty warningStatus = new SimpleIntegerProperty();

  private final IntegerProperty targetDistance = new SimpleIntegerProperty();

  private final BooleanProperty targetDistanceBarGraphStatus = new SimpleBooleanProperty();

  public MainScreenAreaAModel(int carIndex)
  {
    super(carIndex);
  }

  public void setWarningStatus(Integer value)
  {
    warningStatus.set(value);
  }

  public IntegerProperty getWarningStatus()
  {
    return warningStatus;
  }

  public void setTargetDistance(Integer value)
  {
    targetDistance.set(value);
  }

  public IntegerProperty getTargetDistance()
  {
    return targetDistance;
  }

  public void setTargetDistanceBarGraphStatus(Boolean newValue)
  {
    targetDistanceBarGraphStatus.set(newValue);
  }

  /**
   * @return the targetDistanceBarGraphStatus
   */
  public BooleanProperty getTargetDistanceBarGraphStatus()
  {
    return targetDistanceBarGraphStatus;
  }

}