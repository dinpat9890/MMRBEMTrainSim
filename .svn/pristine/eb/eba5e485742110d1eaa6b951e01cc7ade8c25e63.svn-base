/*
 * ==================================================================
 * 
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.state;

/**
 * This enum for Days
 * 
 * @author ext-vp
 *
 */
public enum Days
{

  SUNDAY("Sunday", "Sun"), //$NON-NLS-1$ //$NON-NLS-2$
  MONDAY("Monday", "Mon"), //$NON-NLS-1$ //$NON-NLS-2$
  TUESDAY("Tuesday", "Tue"), //$NON-NLS-1$ //$NON-NLS-2$
  WEDNESDAY("Wednesday", "Wed"), //$NON-NLS-1$ //$NON-NLS-2$
  THURSDAY("Thursday", "Thu"), //$NON-NLS-1$ //$NON-NLS-2$
  FRIDAY("Friday", "Fri"), //$NON-NLS-1$ //$NON-NLS-2$
  SATURDAY("Saturday", "Sat"); //$NON-NLS-1$ //$NON-NLS-2$

  private final String day;

  private final String text;

  private Days(String day, String text)
  {
    this.text = text;
    this.day = day;
  }

  public String getDay()
  {
    return day;
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

  public static Days getDay(String day)
  {
    for (Days i : values())
    {
      if (i.getDay().equalsIgnoreCase(day))
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Days:" + day); //$NON-NLS-1$
  }

}
