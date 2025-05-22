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

public enum ActiveFaultsCarFilterEnum
{
  ANY(0, "any", "ANY CAR"), //$NON-NLS-1$ //$NON-NLS-2$
  DM1(1, "dm1", "CAR: DM1"), //$NON-NLS-1$ //$NON-NLS-2$
  T2(2, "t2", "CAR: T2"), //$NON-NLS-1$ //$NON-NLS-2$
  M3(3, "m3", "CAR: M3"), //$NON-NLS-1$ //$NON-NLS-2$
  M4(4, "m4", "CAR: M4"), //$NON-NLS-1$ //$NON-NLS-2$
  T5(5, "t5", "CAR: T5"), //$NON-NLS-1$ //$NON-NLS-2$
  DM6(6, "dm6", "CAR: DM6"); //$NON-NLS-1$ //$NON-NLS-2$

  private final int carFilterId;

  private final String carName;

  private final String appliedFilterString;

  ActiveFaultsCarFilterEnum(int carFilterId, String carName, String appliedFilterString)
  {
    this.carFilterId = carFilterId;
    this.carName = carName;
    this.appliedFilterString = appliedFilterString;
  }

  public int getCarFilterId()
  {
    return carFilterId;
  }

  public String getCarName()
  {
    return carName;
  }

  public String getAppliedFilterString()
  {
    return appliedFilterString;
  }

  public static ActiveFaultsCarFilterEnum valueOf(int intValue)
  {
    for (ActiveFaultsCarFilterEnum i : values())
    {
      if (i.getCarFilterId() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}
