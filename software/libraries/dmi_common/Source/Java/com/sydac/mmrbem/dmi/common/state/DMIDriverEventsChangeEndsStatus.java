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
 * This enum for DMI Driver Events Change Ends
 * 
 * @author joshian
 *
 */
public enum DMIDriverEventsChangeEndsStatus
{
  UNKNOWN("driver-event-default", 0), // $NON-NLS-1
  DRIVER_EVENT_CHANGE_ENDS("b3-event-change-ends", 1); // $NON-NLS-1
  

  private final int value;

  private final String text;

  private DMIDriverEventsChangeEndsStatus(String text, int value)
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

  public static DMIDriverEventsChangeEndsStatus valueOf(int intValue)
  {
    for (DMIDriverEventsChangeEndsStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIDriverEventsChangeEndsStatus : " + intValue); //$NON-NLS-1$
  }

}
