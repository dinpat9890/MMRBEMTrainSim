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
public enum OHPCallStatus
{

  NORMAL("PECU Call Status: Normal", 0), //$NON-NLS-1$
  FAULT("PECU Call Status: Fault", 1), //$NON-NLS-1$
  CALLING("PECU Call Status: Calling", 2), //$NON-NLS-1$
  TALKING("PECU Call Status: Talking", 3), //$NON-NLS-1$
  MUTIPLE_OHP_CALLS("Multiple PECU Call Requested", 5) //$NON-NLS-1$
  ;

  private final String text;

  private final int value;

  private OHPCallStatus(String text, Integer value)
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

  public static OHPCallStatus valueOf(int intValue)
  {
    for (OHPCallStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for OHPCallStatus:" + intValue); //$NON-NLS-1$
  }

}
