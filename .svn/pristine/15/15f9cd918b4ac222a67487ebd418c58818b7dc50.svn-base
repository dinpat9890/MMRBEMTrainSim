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
 * AutoRotationStatus represent the status of auto rotation
 * 
 * @author ext-vp
 *
 */
public enum AutoRotationStatus
{

  OFF(0, "pause"), //$NON-NLS-1$
  ON(1, "play"), //$NON-NLS-1$
  RESET(-1, "play"); //$NON-NLS-1$

  private int value;

  private String stringValue;

  private AutoRotationStatus(final int aValue, final String aStringValue)
  {
    value = aValue;
    stringValue = aStringValue;
  }

  public static AutoRotationStatus getStatusOf(int aValue)
  {
    for (AutoRotationStatus status : values())
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
