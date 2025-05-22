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

public enum ActiveFaultsSystemFilterEnum
{
  ANY(0, "any", "ANY SYSTEM"), //$NON-NLS-1$ //$NON-NLS-2$
  VEHICLE(1, "vehicle", "SYS: VEHICLE"), //$NON-NLS-1$ //$NON-NLS-2$
  HV(2, "hv", "SYS: HV"), //$NON-NLS-1$ //$NON-NLS-2$
  MV(3, "mv", "SYS: MV"), //$NON-NLS-1$ //$NON-NLS-2$
  LV(4, "lv", "SYS: LV"), //$NON-NLS-1$ //$NON-NLS-2$
  TCMS(5, "tcms", "SYS: TCMS"), //$NON-NLS-1$ //$NON-NLS-2$
  HVAC(6, "hvac", "SYS: HVAC"), //$NON-NLS-1$ //$NON-NLS-2$
  BRAKES(7, "brakes", "SYS: BRAKES"), //$NON-NLS-1$ //$NON-NLS-2$
  DOORS(8, "doors", "SYS: DOORS"), //$NON-NLS-1$ //$NON-NLS-2$
  LIGHTS(9, "lights", "SYS: LIGHTS"), //$NON-NLS-1$ //$NON-NLS-2$
  ATC(10, "atc", "SYS: ATC"), //$NON-NLS-1$ //$NON-NLS-2$
  PAPIS(11, "papis", "SYS: PAPIS"), //$NON-NLS-1$ //$NON-NLS-2$
  FDS(12, "fds", "SYS: FDS"), //$NON-NLS-1$ //$NON-NLS-2$
  CCTV(13, "cctv", "SYS: CCTV"), //$NON-NLS-1$ //$NON-NLS-2$
  TR(14, "tr", "SYS:TR"), //$NON-NLS-1$ //$NON-NLS-2$
  WFL(15, "wfl", "SYS: WFL"), //$NON-NLS-1$ //$NON-NLS-2$
  BCG(16, "bcg", "SYS: BCG"), //$NON-NLS-1$ //$NON-NLS-2$
  APS(17, "aps", "SYS: APS"), //$NON-NLS-1$ //$NON-NLS-2$
  PROPULSION(18, "propulsion", "SYS: PROP"); //$NON-NLS-1$ //$NON-NLS-2$

  private final int sysFilterId;

  private final String sysName;

  private final String appliedFilterString;

  ActiveFaultsSystemFilterEnum(int sysFilterId, String sysName, String appliedFilterString)
  {
    this.sysFilterId = sysFilterId;
    this.sysName = sysName;
    this.appliedFilterString = appliedFilterString;
  }

  public int getSysFilterId()
  {
    return sysFilterId;
  }

  public String getSysName()
  {
    return sysName;
  }

  public String getAppliedFilterString()
  {
    return appliedFilterString;
  }

  public static ActiveFaultsSystemFilterEnum valueOf(int intValue)
  {
    for (ActiveFaultsSystemFilterEnum i : values())
    {
      if (i.getSysFilterId() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}
