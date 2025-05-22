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

public enum HVACConstantsEnum
{
  UNIT_OFF(0, "Unit Off", ApplicationConstants.HVAC_MODE_OK_CSS), //$NON-NLS-1$
  PRE_HEATING(1, "Pre-Heating", ApplicationConstants.HVAC_MODE_OK_CSS), //$NON-NLS-1$
  PRE_COOLING(2, "Pre-Cooling", ApplicationConstants.HVAC_MODE_OK_CSS), //$NON-NLS-1$
  VENTILATION(3, "Ventilation", ApplicationConstants.HVAC_MODE_OK_CSS), //$NON-NLS-1$
  COOLING(4, "Cooling", ApplicationConstants.HVAC_MODE_OK_CSS), //$NON-NLS-1$
  HEATING(5, "Heating", ApplicationConstants.HVAC_MODE_OK_CSS), //$NON-NLS-1$
  EMERGENCY_VENT(6, "Emergency Vent", ApplicationConstants.HVAC_MODE_OK_CSS), //$NON-NLS-1$
  FAULT(7, "Fault", "hvac_faulty"), //$NON-NLS-1$ //$NON-NLS-2$
  ISOLATED(8, "Isolated", "hvac_isolated"), AUTO(9, "AUTO", ApplicationConstants.HVAC_CONTROL_MODE_AUTO_CSS), //$NON-NLS-3$ //$NON-NLS-2$
  DMAPER(10, "OPEN", ApplicationConstants.HVAC_DAMPER_CSS);//$NON-NLS-1$ //$NON-NLS-2$

  private final int value;

  private final String name;

  private final String state;

  public int getValue()
  {
    return value;
  }

  public String getState()
  {
    return state;
  }

  HVACConstantsEnum(int value, String name, String state)
  {
    this.value = value;
    this.state = state;
    this.name = name;
  }

  public static HVACConstantsEnum valueOf(int intValue)
  {
    for (HVACConstantsEnum i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Propulsion Enabled:" + intValue); //$NON-NLS-1$
  }

  public String getName()
  {
    return name;
  }
}
