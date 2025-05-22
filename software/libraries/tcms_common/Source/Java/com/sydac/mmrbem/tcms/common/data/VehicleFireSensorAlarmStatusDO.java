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
 * This class hold data for Fire System Screen - Fire Sensor Alarm Status. <br>
 * Note: Data can be hold as {@link Integer}
 */
public class VehicleFireSensorAlarmStatusDO
{

  private int fireSensorAlarmStatus;

  public int getFireSensorAlarmStatus()
  {
    return fireSensorAlarmStatus;
  }

  public void setFireSensorAlarmStatus(int fireSensorAlarmStatus)
  {
    this.fireSensorAlarmStatus = fireSensorAlarmStatus;
  }
}