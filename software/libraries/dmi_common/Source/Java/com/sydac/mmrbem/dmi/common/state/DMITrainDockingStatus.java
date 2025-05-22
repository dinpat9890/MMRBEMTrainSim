/*
 * ==================================================================
 * 
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.state;
import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.TrainDockingStatus;
/**
 * This enum for DMI Train Docking
 * 
 * @author joshian
 *
 */
public enum DMITrainDockingStatus
{
  UNKNOWN("docking-status-unknown", TrainDockingStatus.UNKNOWN), // $NON-NLS-1
  CORRECTLY_DOCKED("docking-status-correctly-docked", TrainDockingStatus.CORRECTLY_DOCKED), // $NON-NLS-1
  SHORT_STOP("docking-status-short-stop", TrainDockingStatus.SHORT_STOP), // $NON-NLS-1
  LONG_STOP("docking-status-long-stop", TrainDockingStatus.LONG_STOP), // $NON-NLS-1
  TOO_LONG_STOP("docking-status-too-long-stop", TrainDockingStatus.TOO_LONG_STOP), // $NON-NLS-1
  OPERATIONAL_SERVICE_STOPPING_DISTANCE("operational-service-stopping-distance", TrainDockingStatus.OPERATIONAL_STOP_DISTANCE); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMITrainDockingStatus(String text, int value)
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

  public static DMITrainDockingStatus valueOf(int intValue)
  {
    for (DMITrainDockingStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMITrainDockingStatus : " + intValue); //$NON-NLS-1$
  }

}
