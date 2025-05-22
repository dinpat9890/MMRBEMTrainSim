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

public enum BrakeLoopStatus
{

  NOT_ACTIVE(0, "not_active"), //$NON-NLS-1$
  ACTIVE(1, "active"); //$NON-NLS-1$

  private int value;

  private String styleClass;

  private BrakeLoopStatus(final int aValue, final String aStyleClass)
  {
    value = aValue;
    styleClass = aStyleClass;
  }

  public static BrakeLoopStatus getStatusOf(int aValue)
  {
    for (BrakeLoopStatus status : values())
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
