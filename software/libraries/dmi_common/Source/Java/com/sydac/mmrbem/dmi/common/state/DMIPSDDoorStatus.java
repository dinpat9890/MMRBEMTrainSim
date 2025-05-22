/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.state;

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.PSDDoorStatus;

/**
 * This enum for Platform Screen Doors Status
 * 
 * @author ext-savanjin
 *
 */
public enum DMIPSDDoorStatus
{
  NOT_AVAILABLE("psddoor-status-not-available", PSDDoorStatus.UNAVAILABLE), // $NON-NLS-1
  UNKNOWN("psddoor-status-unknown", PSDDoorStatus.UNKNOWN), // $NON-NLS-1
  PSD_CLOSED("psddoor-status-closed", PSDDoorStatus.PSD_CLOSED), // $NON-NLS-1
  PSD_OPENING("psddoor-status-opening", PSDDoorStatus.PSD_OPENING), // $NON-NLS-1
  PSD_OPENED("psddoor-status-opened", PSDDoorStatus.PSD_OPENED), // $NON-NLS-1
  PSD_CLOSING("psddoor-status-closing", PSDDoorStatus.PSD_CLOSING), // $NON-NLS-1
  PSD_CLOSING_FAILURE("psddoor-status-closing-failure", PSDDoorStatus.PSD_CLOSING_FAILURE); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMIPSDDoorStatus(String text, int value)
  {
    this.text = text;
    this.value = value;
  }

  public int getValue()
  {
    return value;
  }

  /**
   * Get text to display
   * 
   * @return text
   */
  public String getText()
  {
    return text;
  }

  public static DMIPSDDoorStatus valueOf(int intValue)
  {
    for (DMIPSDDoorStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIPSDDoorStatus:" + intValue); //$NON-NLS-1$
  }
}
