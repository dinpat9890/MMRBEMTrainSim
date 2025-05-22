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
import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.RadioCommsStatus;
/**
 * This enum for DMI Driver Events Skip Station
 * 
 * @author joshian
 *
 */
public enum DMIRadioCommStatus
{
  FAULTY("radio-comm-status-fault", RadioCommsStatus.COMMS_NOT_ESTABLISHED), // $NON-NLS-1
  NORMAL("radio-comm-status-normal", RadioCommsStatus.COMMS_ESTABLISHED); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMIRadioCommStatus(String text, int value)
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

  public static DMIRadioCommStatus valueOf(int intValue)
  {
    for (DMIRadioCommStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIRadioCommStatus : " + intValue); //$NON-NLS-1$
  }

}
