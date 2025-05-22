/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.tcms.common.data;

/**
 * This class hold data for Fire System Screen - Saloon Fire Alarm Status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleSFARStatusDO
{

  private int sfarStatus;

  private int sfarFaultStatus;

  public int getSfarStatus()
  {
    return sfarStatus;
  }

  public void setSfarStatus(int sfarStatus)
  {
    this.sfarStatus = sfarStatus;
  }

  public int getSfarFaultStatus()
  {
    return sfarFaultStatus;
  }

  public void setSfarFaultStatus(int sfarFaultStatus)
  {
    this.sfarFaultStatus = sfarFaultStatus;
  }
}