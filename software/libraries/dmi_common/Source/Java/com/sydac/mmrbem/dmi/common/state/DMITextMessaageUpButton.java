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
 * This enum for low priority message up button status
 * 
 * @author ext-savanjin
 *
 */

public enum DMITextMessaageUpButton
{
  UP_BUTTON_DISABLED("button-up-disabled", 0), // $NON-NLS-1
  UP_BUTTON_ENABLED("button-up-enabled", 1); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMITextMessaageUpButton(String text, int value)
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

  public static DMITextMessaageUpButton valueOf(int intValue)
  {
    for (DMITextMessaageUpButton i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Up Text Messaage Button Status:" + intValue); //$NON-NLS-1$
  }
}
