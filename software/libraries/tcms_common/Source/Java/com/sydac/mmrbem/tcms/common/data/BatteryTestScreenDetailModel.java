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

public class BatteryTestScreenDetailModel
{

  private String carId;

  private int batteryId;

  private String batteryStatus;

  private String compName;

  public BatteryTestScreenDetailModel()
  {
    super();

  }

  public int getBatteryId()
  {
    return batteryId;
  }

  public void setBatteryId(int id)
  {
    this.batteryId = id;
  }

  public String getBatteryStatus()
  {
    return batteryStatus;
  }

  public void setBatteryStatus(String status)
  {
    this.batteryStatus = status;
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
