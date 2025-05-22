/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.state;

public enum CallGroup
{
  NO_GROUP_CALL(0, ""), //$NON-NLS-1$
  MAIN_GROUP_CALL(1, "Main"), //$NON-NLS-1$
  DEPOT_GROUP_CALL(2, "Depot"), //$NON-NLS-1$
  SHUNT_GROUP_CALL(3, "Shunt"), //$NON-NLS-1$
  TRAIN_GROUP_CALL(4, "Train"); //$NON-NLS-1$

  private final int value;

  private final String text;

  private CallGroup(int value, String text)
  {
    this.value = value;
    this.text = text;
  }

  public int getValue()
  {
    return value;
  }

  public String getText()
  {
    return text;
  }

  public static CallGroup valueOf(int intValue)
  {
    for (CallGroup i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}
