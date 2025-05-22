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

/**
 * 
 * Defines Car Type with Car type code and display name.
 */
public enum CarType
{
  DM("DM", "D"), //$NON-NLS-1$ //$NON-NLS-2$
  T("T", "T"), //$NON-NLS-1$ //$NON-NLS-2$
  M("M", "M"); //$NON-NLS-1$ //$NON-NLS-2$

  private final String carTypeCode;

  private final String displayCode;

  private CarType(String aType, String aDisplayName)
  {
    carTypeCode = aType;
    displayCode = aDisplayName;
  }

  public String getCarTypeCode()
  {
    return carTypeCode;
  }

  public String getDisplayCode()
  {
    return displayCode;
  }

  public static CarType valueByCarTypeCode(String aCarTypeCode)
  {
    for (CarType carType : CarType.values())
    {
      if (carType.getCarTypeCode().equalsIgnoreCase(aCarTypeCode))
      {
        return carType;
      }
    }
    throw new IllegalArgumentException(aCarTypeCode);
  }

}
