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

public enum EventModeStatus
{

  NORMAL(0, "normal"), //$NON-NLS-1$
  EVENT(1, "event"); //$NON-NLS-1$

  private int value;

  private String stringValue;

  private EventModeStatus(final int aValue, final String aStringValue)
  {
    value = aValue;
    stringValue = aStringValue;
  }

  public static EventModeStatus getStatusOf(int aValue)
  {
    for (EventModeStatus status : values())
    {
      if (status.value == aValue)
      {
        return status;
      }
    }
    return null;
  }

  public int getValue()
  {
    return value;
  }

  public String getStringValue()
  {
    return stringValue;
  }
}
