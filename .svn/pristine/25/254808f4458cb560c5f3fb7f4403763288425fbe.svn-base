
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
 * {@link CabToCabCallType} defines call types
 *
 * @author mulukg
 *
 */
public enum CabToCabCallType
{

  NO_ACTIVE_CALL(0, ""), // $NON-NLS-1$
  CAB_TO_CAB_CALL(1, "Cab To Cab Call"), // $NON-NLS-1$
  ACTIVE_OHP_CALL(2, "PECU Call"),// $NON-NLS-1$
  SCC_TO_CAB_CALL(3, "Cab To Cab Call");// $NON-NLS-1$

  private final int value;

  private final String text;

  private CabToCabCallType(Integer value, String text)
  {
    this.value = value;
    this.text = text;
  }

  public int getValue()
  {
    return value;
  }

  public String getText()
  {
    return text;
  }

  public static CabToCabCallType valueOf(int intValue)
  {
    for (CabToCabCallType i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for CabToCabCallType:" + intValue); //$NON-NLS-1$
  }

}
