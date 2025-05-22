/*
 * ==================================================================
 * 
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.state;

/**
 * This enum for CabDirection
 * 
 * @author mulukg
 *
 */
public enum DrivingDirectionStatus
{

  WHITE("button-driving-direction-left-white", 0), // $NON-NLS-1
  YELLOW("button-driving-direction-left-yellow", 1), // $NON-NLS-1
  RED("button-driving-direction-left-red", 2); // $NON-NLS-1

  private final int value;

  private final String text;

  private DrivingDirectionStatus(String text, int value)
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

  public static DrivingDirectionStatus valueOf(int intValue)
  {
    for (DrivingDirectionStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for BCUStatus:" + intValue); //$NON-NLS-1$
  }

}
