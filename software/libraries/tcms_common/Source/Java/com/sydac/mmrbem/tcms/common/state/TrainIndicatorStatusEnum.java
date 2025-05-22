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

public enum TrainIndicatorStatusEnum
{
  INACTIVE(0, "inactive"), //$NON-NLS-1$
  ACTIVE(1, "active"); //$NON-NLS-1$

  private final int statusId;

  private final String status;

  TrainIndicatorStatusEnum(int statusId, String status)
  {
    this.statusId = statusId;
    this.status = status;
  }

  public int getStatusId()
  {
    return statusId;
  }

  public String getStatus()
  {
    return status;
  }

  public static TrainIndicatorStatusEnum valueOf(int intValue)
  {
    for (TrainIndicatorStatusEnum i : values())
    {
      if (i.getStatusId() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Train Indicator Status:" + intValue); //$NON-NLS-1$
  }
}
