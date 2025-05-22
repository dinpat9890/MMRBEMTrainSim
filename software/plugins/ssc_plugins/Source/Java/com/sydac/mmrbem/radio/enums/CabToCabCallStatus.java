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
public enum CabToCabCallStatus
{

  INACTIVE("", 0), //$NON-NLS-1$
  CALL_REQUESTED("Cab To Cab Call Requested", 1), //$NON-NLS-1$
  CALL_CONNECTED("Cab To Cab Call  Connected", 2), //$NON-NLS-1$
  ;

  private final String text;

  private final int value;

  private CabToCabCallStatus(String text, Integer value)
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

  public static CabToCabCallStatus valueOf(int intValue)
  {
    for (CabToCabCallStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for CabToCabCallStatus:" + intValue); //$NON-NLS-1$
  }

}
