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

public enum MiscellaniaStatus
{

  NOT_ACTIVE(0, "misc_not_active"), //$NON-NLS-1$
  ACTIVE(1, "misc_active"); //$NON-NLS-1$

  private int value;

  private String styleClass;

  private MiscellaniaStatus(final int aValue, final String aStyleClass)
  {
    value = aValue;
    styleClass = aStyleClass;
  }

  public static MiscellaniaStatus getStatusOf(int aValue)
  {
    for (MiscellaniaStatus status : values())
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

  public String getStyleClass()
  {
    return styleClass;
  }
}
