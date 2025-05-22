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
 * CallStatusConstant defines call status
 *
 * @author mulukg
 *
 */
public enum RadioCallStatus
{

  IN_ACTIVE("", 0), //$NON-NLS-1$
  CALL_REQUESTED("Radio Call Requested", 1), //$NON-NLS-1$
  CALL_CONNECTED("Radio Call Connected", 2), //$NON-NLS-1$
  ;

  private final String text;

  private final int value;

  private RadioCallStatus(String text, Integer value)
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

  public static RadioCallStatus valueOf(int intValue)
  {
    for (RadioCallStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for RadioCallStatus:" + intValue); //$NON-NLS-1$
  }

}
