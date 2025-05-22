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

public enum InternalExternalViewStatus
{

  EXTERNAL_CAMERA_SELECTION(0, "external"), //$NON-NLS-1$
  INTERNAL_CAMERA_SELECTION(1, "internal"), //$NON-NLS-1$
  CAMERA_SELECTION_RESET(-1, "internal"); //$NON-NLS-1$

  private int value;

  private String stringValue;

  private InternalExternalViewStatus(final int aValue, final String aStringValue)
  {
    value = aValue;
    stringValue = aStringValue;
  }

  public static InternalExternalViewStatus getStatusOf(int aValue)
  {
    for (InternalExternalViewStatus status : values())
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
