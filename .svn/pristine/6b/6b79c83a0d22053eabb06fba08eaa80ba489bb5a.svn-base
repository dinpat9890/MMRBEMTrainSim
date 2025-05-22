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
public enum CarTypeName
{
  SIX_CAR_T2("T2", "(DM1)", "(M3)"), //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
  SIX_CAR_T5("T5", "(M4)", "(DM6)"), //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
  EIGHT_CAR_T2("T2", "(DM1)", "(M3)"), //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
  EIGHT_CAR_T4("T4", "(M5)", ""), //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
  EIGHT_CAR_T7("T7", "(M6)", "(DM8)"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$

  private final String carTypeCode;

  private final String dmCarDisplayName;

  private final String mCarDisplayName;

  private CarTypeName(String aType, String dmCarName, String mCarName)
  {
    carTypeCode = aType;
    dmCarDisplayName = dmCarName;
    mCarDisplayName = mCarName;
  }

  public String getCarTypeCode()
  {
    return carTypeCode;
  }

  public String getDmCarDisplayName()
  {
    return dmCarDisplayName;
  }

  public String getMCarDisplayName()
  {
    return mCarDisplayName;
  }

  public static CarTypeName valueByCarTypeCode(String aCarTypeCode)
  {
    for (CarTypeName carType : CarTypeName.values())
    {
      if (carType.getCarTypeCode().equalsIgnoreCase(aCarTypeCode))
      {
        return carType;
      }
    }
    throw new IllegalArgumentException(aCarTypeCode);
  }

}
