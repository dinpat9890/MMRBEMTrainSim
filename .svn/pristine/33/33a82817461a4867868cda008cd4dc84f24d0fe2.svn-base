/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.common.state;

public enum CabSignalState
{
  INACTIVE(0, "in-active"), //$NON-NLS-1$
  ACTIVE(1, "active"), //$NON-NLS-1$
  
  ;

  private final int value;

  private final String cabSignalCss;

  private CabSignalState(int value, String cabSignalCss)
  {
    this.cabSignalCss = cabSignalCss;
    this.value = value;
  }

  public int getValue()
  {
    return value;
  }

  public String getCabSignalCss()
  {
    return cabSignalCss;
  }

  public static CabSignalState valueOf(int intValue)
  {
    for (CabSignalState i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}
