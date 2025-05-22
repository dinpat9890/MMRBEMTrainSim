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

public enum HVACControlEnum
{
  AUTO(0, "AUTO", ApplicationConstants.HVAC_CONTROL_MODE_AUTO_CSS), //$NON-NLS-3$ //$NON-NLS-2$
  REDUCED(1, "REDUCED", ApplicationConstants.HVAC_CONTROL_MODE_AUTO_CSS); //$NON-NLS-1$
  

  private final int value;

  private final String name;

  private final String state;

  public int getValue()
  {
    return value;
  }

  public String getState()
  {
    return state;
  }

  HVACControlEnum(int value, String name, String state)
  {
    this.value = value;
    this.state = state;
    this.name = name;
  }

  public static HVACControlEnum valueOf(int intValue)
  {
    for (HVACControlEnum i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Propulsion Enabled:" + intValue); //$NON-NLS-1$
  }

  public String getName()
  {
    return name;
  }
}
