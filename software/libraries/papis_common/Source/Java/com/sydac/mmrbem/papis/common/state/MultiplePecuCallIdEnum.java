/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.state;

public enum MultiplePecuCallIdEnum
{
  PECU_1("PECU10", 1), //$NON-NLS-1$
  PECU_2("PECU12", 2), //$NON-NLS-1$
  PECU_3("PECU17", 3), //$NON-NLS-1$
  PECU_4("PECU21", 4); //$NON-NLS-1$

  private final String pecuName;

  private final int id;

  private MultiplePecuCallIdEnum(String pecuName, int id)
  {
    this.pecuName = pecuName;
    this.id = id;
  }

  public String getPecuName()
  {
    return pecuName;
  }

  public int getId()
  {
    return id;
  }

  public static MultiplePecuCallIdEnum valueOf(int intValue)
  {
    for (MultiplePecuCallIdEnum i : values())
    {
      if (i.getId() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}
