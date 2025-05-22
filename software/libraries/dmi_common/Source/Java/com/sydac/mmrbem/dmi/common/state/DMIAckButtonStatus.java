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

/**
 * This enum for high priority messages acknowledgement status
 * 
 * @author ext-savanjin
 *
 */

public enum DMIAckButtonStatus
{
  ACK_BUTTON_HIDE("button-ack-hide", 1), // $NON-NLS-1
  ACK_BUTTON_ENABLED("button-ack-enabled", 2), // $NON-NLS-1
  ACK_BUTTON_DISABLED("button-ack-disabled", 3); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMIAckButtonStatus(String text, int value)
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

  public static DMIAckButtonStatus valueOf(int intValue)
  {
    for (DMIAckButtonStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for ACK Button Status:" + intValue); //$NON-NLS-1$
  }

}
