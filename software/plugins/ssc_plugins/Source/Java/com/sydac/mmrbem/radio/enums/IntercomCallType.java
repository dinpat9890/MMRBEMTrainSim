
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
 * {@link IntercomCallType} defines call types
 *
 * @author mulukg
 *
 */
public enum IntercomCallType
{

  NO_CALL(0, ""), //$NON-NLS-1$
  RADIO_CALL(1, "Radio Call"), //$NON-NLS-1$
  CAB_TO_CAB_CALL(2, "Cab To Cab Call"), //$NON-NLS-1$
  ACTIVE_OHP_CALL(3, "PECU Call"), //$NON-NLS-1$
  SCC_TO_CAB_CALL(4, "Cab To Cab Call"); //$NON-NLS-1$

  private final int value;

  private final String text;

  private IntercomCallType(Integer value, String text)
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

  public static IntercomCallType valueOf(int intValue)
  {
    for (IntercomCallType i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for IntercomCallType:" + intValue); //$NON-NLS-1$
  }

}
