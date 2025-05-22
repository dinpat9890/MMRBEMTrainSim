/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.common.state;

public enum PropulsionEnabledEnum
{
  UNKNOWN(0, ""), ENABLED(1, "Prop Enabled"), NOT_ENABLED(2, "Prop Not \nEnabled"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$

  private final int value;

  private final String state;

  public int getValue()
  {
    return value;
  }

  public String getState()
  {
    return state;
  }

  PropulsionEnabledEnum(int value, String state)
  {
    this.value = value;
    this.state = state;
  }

  public static PropulsionEnabledEnum valueOf(int intValue)
  {
    for (PropulsionEnabledEnum i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Propulsion Enabled:" + intValue); //$NON-NLS-1$
  }
}
