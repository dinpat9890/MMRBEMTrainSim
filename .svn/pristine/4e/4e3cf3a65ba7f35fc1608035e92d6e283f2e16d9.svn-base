/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.state;

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.TrainDoorStatus;

/**
 * This enum for train door status
 * 
 * @author ext-savanjin
 *
 */

public enum DMITrainDoorStatus
{
  UNKNOWN("train-door-status-unknown", TrainDoorStatus.UNKNOWN), // $NON-NLS-1
  DOOR_CLOSED("train-door-status-closed", TrainDoorStatus.DOOR_CLOSED), // $NON-NLS-1
  DOOR_OPENING("train-door-status-opening", TrainDoorStatus.DOOR_OPENING), // $NON-NLS-1
  DOOR_OPEN("train-door-status-open", TrainDoorStatus.DOOR_OPEN), // $NON-NLS-1
  DOOR_WARNING_OPEN("train-door-status-warning-open", TrainDoorStatus.DOOR_WARNING_OPEN), // $NON-NLS-1
  DOOR_WARNING_CLOSING("train-door-status-warning-closing", TrainDoorStatus.DOOR_WARNING_CLOSING); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMITrainDoorStatus(String text, int value)
  {
    this.text = text;
    this.value = value;
  }

  public int getValue()
  {
    return value;
  }

  /**
   * Get text to display
   * 
   * @return text
   */
  public String getText()
  {
    return text;
  }

  public static DMITrainDoorStatus valueOf(int intValue)
  {
    for (DMITrainDoorStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Train Door Status:" + intValue); //$NON-NLS-1$
  }
}
