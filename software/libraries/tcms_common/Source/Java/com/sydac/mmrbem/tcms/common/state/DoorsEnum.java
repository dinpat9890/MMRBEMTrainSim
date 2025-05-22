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

/**
 * 
 * Defines Doors name.
 */
public enum DoorsEnum
{
  DOOR_A1(1, "ISOLATE A1", "RESET ISO A1"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_A2(2, "ISOLATE A2", "RESET ISO A2"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_A3(3, "ISOLATE A3", "RESET ISO A3"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_A4(4, "ISOLATE A4", "RESET ISO A4"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_B1(5, "ISOLATE B1", "RESET ISO B1"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_B2(6, "ISOLATE B2", "RESET ISO B2"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_B3(7, "ISOLATE B3", "RESET ISO B3"), //$NON-NLS-1$ //$NON-NLS-2$
  DOOR_B4(8, "ISOLATE B4", "RESET ISO B4"); //$NON-NLS-1$ //$NON-NLS-2$

  private final int doorId;

  private final String isolateButtonText;

  private final String resetButtonText;

  private DoorsEnum(Integer doorId, String isolateButtonText, String resetButtonText)
  {
    this.doorId = doorId;
    this.isolateButtonText = isolateButtonText;
    this.resetButtonText = resetButtonText;
  }

  public int getDoorId()
  {
    return doorId;
  }

  public String getIsolateButtonText()
  {
    return isolateButtonText;
  }

  public String getResetButtonText()
  {
    return resetButtonText;
  }
}
