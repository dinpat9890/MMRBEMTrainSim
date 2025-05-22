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

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.ATCStatus;

/**
 * This enum for atc status
 * 
 * @author mulukg
 *
 */

public enum DMIATCStatus
{
  HEALTHY("atc-status-normal", ATCStatus.HEALTHY), // $NON-NLS-1
  WARNING("atc-status-yellow", ATCStatus.WARNING), // $NON-NLS-1
  DEGRADED("atc-status-red", ATCStatus.DEGRADED); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMIATCStatus(String text, int value)
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

  public static DMIATCStatus valueOf(int intValue)
  {
    for (DMIATCStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Atc Status:" + intValue); //$NON-NLS-1$
  }
}
