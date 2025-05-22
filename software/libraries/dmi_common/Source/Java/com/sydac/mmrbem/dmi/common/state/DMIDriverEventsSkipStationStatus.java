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

/**
 * This enum for DMI Driver Events Skip Station
 * 
 * @author joshian
 *
 */
public enum DMIDriverEventsSkipStationStatus
{
  UNKNOWN("driver-event-default", 0), //$NON-NLS-1$
  DRIVER_EVENT_CHANGE_ENDS("b4-skip-station", 1); //$NON-NLS-1$

  private final int value;

  private final String text;

  private DMIDriverEventsSkipStationStatus(String text, int value)
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

  public static DMIDriverEventsSkipStationStatus valueOf(int intValue)
  {
    for (DMIDriverEventsSkipStationStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIDriverEventsSkipStationStatus : " + intValue); //$NON-NLS-1$
  }

}
