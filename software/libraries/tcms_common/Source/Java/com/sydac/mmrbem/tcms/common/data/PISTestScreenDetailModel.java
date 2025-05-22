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

public class PISTestScreenDetailModel
{

  private String carId;
  
  

  private int pisId;

  private String pisStatus;

  private String compName;

  public PISTestScreenDetailModel()
  {
    super();
   
  }

  public int getPisId()
  {
    return pisId;
  }

  public void setPisId(int id)
  {
    this.pisId = id;
  }

  public String getPISStatus()
  {
    return pisStatus;
  }

  public void setPISStatus(String status)
  {
    this.pisStatus = status;
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
