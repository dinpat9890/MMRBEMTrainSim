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
 * FireTestScreenDetailModel acts as a buffer to store the data read from the
 * XML files,
 */

public class HVACTestScreenDetailModel
{

  private String carId;
  
  

  private int hvacId;

  private String hvacStatus;

  private String compName;

  public HVACTestScreenDetailModel()
  {
    super();
   
  }

  public int getHvaCId()
  {
    return hvacId;
  }
  

  public void setHvacId(int id)
  {
    this.hvacId = id;
  }

  public String getHvacStatus()
  {
    return hvacStatus;
  }

  public void setHvacStatus(String status)
  {
    this.hvacStatus = status;
  }

  public String getCompName()
  {
    return compName;
  }

  public void setCompName(String systemName)
  {
    this.compName = systemName;
  }
  
  public String getCarId()
  {
    return carId;
  }



  public void setCarId(String carId)
  {
    this.carId = carId;
  }
}
