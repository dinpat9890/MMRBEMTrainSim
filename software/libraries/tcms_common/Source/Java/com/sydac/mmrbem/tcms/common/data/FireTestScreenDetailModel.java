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

public class FireTestScreenDetailModel
{

  private String carId;
  
  

  private int fireId;

  private String fireStatus;

  private String compName;

  public FireTestScreenDetailModel()
  {
    super();
   
  }

  public int getFireId()
  {
    return fireId;
  }

  public void setFireId(int id)
  {
    this.fireId = id;
  }

  public String getFireStatus()
  {
    return fireStatus;
  }

  public void setFireStatus(String status)
  {
    this.fireStatus = status;
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
