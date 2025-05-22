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
 * This enum for DMI Driver Events Work Zone
 * 
 * @author joshian
 *
 */
public enum DMIDriverEventsWorkZoneStatus
{
  UNKNOWN("driver-event-default", 0), // $NON-NLS-1
  DRIVER_EVENT_CHANGE_ENDS("b5-work-zone", 1); // $NON-NLS-1
  

  private final int value;

  private final String text;

  private DMIDriverEventsWorkZoneStatus(String text, int value)
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

  public static DMIDriverEventsWorkZoneStatus valueOf(int intValue)
  {
    for (DMIDriverEventsWorkZoneStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIDriverEventsWorkZoneStatus : " + intValue); //$NON-NLS-1$
  }

}
