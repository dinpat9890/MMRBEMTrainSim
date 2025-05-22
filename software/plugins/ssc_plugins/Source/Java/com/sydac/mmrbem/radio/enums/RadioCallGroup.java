/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.enums;

public enum RadioCallGroup
{
  NO_GROUP_CALL(0, ""), //$NON-NLS-1$
  MAIN_GROUP_CALL(1, "Main Group Call"), //$NON-NLS-1$
  DEPOT_GROUP_CALL(2, "Depot Group Call"), //$NON-NLS-1$
  SHUNT_GROUP_CALL(3, "Shunt Group Call"), //$NON-NLS-1$
  TRAIN_GROUP_CALL(4, "Train Group Call"); //$NON-NLS-1$

  private final int value;

  private final String text;

  private RadioCallGroup(int value, String text)
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

  public static RadioCallGroup valueOf(int intValue)
  {
    for (RadioCallGroup i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}
