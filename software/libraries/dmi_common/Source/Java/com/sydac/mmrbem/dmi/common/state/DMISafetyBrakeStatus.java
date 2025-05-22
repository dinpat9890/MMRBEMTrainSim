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
import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.SafetyBrakeState;
/**
 * This enum for DMI warning
 * 
 * @author mulukg
 *
 */
public enum DMISafetyBrakeStatus
{

  RELEASE("safetyBrake-status-release", SafetyBrakeState.INACTIVE), // $NON-NLS-1
  APPLIED("safetyBrake-status-applied",SafetyBrakeState.ACTIVE),
  FSB_APPLIED("fullServiceBrake-status-applied",SafetyBrakeState.FSB_ACTIVE);

  private final int value;

  private final String text;

  private DMISafetyBrakeStatus(String text, int value)
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

  public static DMISafetyBrakeStatus valueOf(int intValue)
  {
    for (DMISafetyBrakeStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMISafetyBrakesStatus : "  + intValue); //$NON-NLS-1$
  }

}
