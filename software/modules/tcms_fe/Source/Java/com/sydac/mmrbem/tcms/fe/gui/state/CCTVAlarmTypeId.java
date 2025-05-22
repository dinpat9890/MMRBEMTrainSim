/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.state;

/**
 * CCTV AlarmId enum for Alarm Types
 * 
 * @author ext-vp
 *
 */
public enum CCTVAlarmTypeId
{
  ALARM_FIRE_1(1, "fire-smoke-alarm-new"), //$NON-NLS-1$
  ALARM_OBSTCL_SALOON_DR_2(2, "obstacle-saloon-door-alarm-new"), //$NON-NLS-1$
  ALARM_PECU_3(3, "pecu-alarm-new"), //$NON-NLS-1$
  ALARM_DR_UNLK_4(4, "door-unlocked-alarm-new"), //$NON-NLS-1$
  ALARM_EMRG_DR_OPN_5(5, "opening-of-emergency-door-alarm-new"), //$NON-NLS-1$
  ALARM_DRVR_DSK_6(6, "opening-of-driver-console-deck-alarm-new"), //$NON-NLS-1$
  ALARM_OBSTRUCTION_DEFLCT_7(7, "obstruction-deflection-device-alarm-new"), //$NON-NLS-1$
  ALARM_TRACK_EVENT_8(8, "track-related-events-alarm-new"), //$NON-NLS-1$
  ALARM_EMRG_CCTV_9(9, "cctv-emergency-button-alarm-new"), //$NON-NLS-1$
  ALARM_OHE_10(10, "ohe-event-alarm-new"), //$NON-NLS-1$
  ALARM_PANTO_11(11, "pantograph-event-alarm-new"); //$NON-NLS-1$

  private int alarmId;

  private String alarmName;

  CCTVAlarmTypeId(int alarmId, String name)
  {
    this.alarmId = alarmId;
    this.alarmName = name;
  }

  public static CCTVAlarmTypeId getAlarmIdof(int aValue)
  {
    for (CCTVAlarmTypeId status : values())
    {
      if (status.alarmId == aValue)
      {
        return status;
      }
    }
    return null;
  }

  public int getAlarmId()
  {
    return alarmId;
  }

  public String getAlarmName()
  {
    return alarmName;
  }
}
