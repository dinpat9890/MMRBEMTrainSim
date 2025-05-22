/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.radio.enums;

/**
 * <p>
 * {@link CallDirection} defines call direction
 *
 * @author mulukg
 *
 */
public enum CallDirection
{

  NONE("", 0), //$NON-NLS-1$
  INCOMING("Incoming", 1), //$NON-NLS-1$
  OUTGOING("Outgoing", 2);//$NON-NLS-1$

  private final String text;

  private final int value;

  private CallDirection(String text, Integer value)
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

  public static CallDirection valueOf(int intValue)
  {
    for (CallDirection i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for CallDirection:" + intValue); //$NON-NLS-1$
  }

}
