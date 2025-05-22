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
 * This class hold data for WFL Screen - WFL Status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleWFLStatusDO
{

  private int wflStatus;

  private int wflFault;

  public int getWflStatus()
  {
    return wflStatus;
  }

  public void setWflStatus(int wflStatus)
  {
    this.wflStatus = wflStatus;
  }

  public int getWflFault()
  {
    return wflFault;
  }

  public void setWflFault(int wflFault)
  {
    this.wflFault = wflFault;
  }
}