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

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.DMIWarningStatus;

/**
 * This enum for DMI warning
 * 
 * @author mulukg
 *
 */
public enum WarningStatus
{

  NORMAL("a1-area-status-normal", "speedo-meter-needle-normal", DMIWarningStatus.NORMAL), // $NON-NLS-1
  WARNING("a1-area-status-warning", "speedo-meter-needle-warning", DMIWarningStatus.WARNING), // $NON-NLS-1
  INTERVENTION("a1-area-status-intervention", "speedo-meter-needle-intervention", DMIWarningStatus.INTERVENTION); // $NON-NLS-1

  private final int value;

  private final String areaA1LabelStatus;

  private final String speedometerNeedleStatus;

  private WarningStatus(String areaA1LabelStatus, String speedometerNeedleStatus, int value)
  {
    this.areaA1LabelStatus = areaA1LabelStatus;
    this.value = value;
    this.speedometerNeedleStatus = speedometerNeedleStatus;
  }

  public int getValue()
  {
    return value;
  }

  /**
   * Get text to display
   * 
   * @return areaA1LabelStatus
   */
  public String getAreaA1LabelStatus()
  {
    return areaA1LabelStatus;
  }

  public String getSpeedometerNeedleStatus()
  {
    return speedometerNeedleStatus;
  }

  public static WarningStatus valueOf(int intValue)
  {
    for (WarningStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for WarningStatus:" + intValue); //$NON-NLS-1$
  }

}
