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
 * This enum for new message status 
 * @author ext-savanjin
 *
 */

public enum DMINewMessageStatus
{
  DOWN_BUTTON_DISABLED("label-new-message-hide", 0), // $NON-NLS-1
  DOWN_BUTTON_ENABLED("label-new-message-show", 1); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMINewMessageStatus(String text, int value)
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

  public static DMINewMessageStatus valueOf(int intValue)
  {
    for (DMINewMessageStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Down New Messaage Status:" + intValue); //$NON-NLS-1$
  }
}
