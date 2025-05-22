/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.state;

public enum CallType
{
  NO_CALL(0, "", ""), //$NON-NLS-1$ //$NON-NLS-2$
  RADIO_HALF_DUPLEX(1, "active", "Radio Half Duplex Call"), //$NON-NLS-1$ //$NON-NLS-2$
  RADIO_FULL_DUPLEX(2, "active", "Radio Full Duplex Call"), //$NON-NLS-1$ //$NON-NLS-2$
  RADIO_GROUP(3, "active", "Radio Group Call"), //$NON-NLS-1$ //$NON-NLS-2$
  RADIO_EMERGNECY(4, "active", "Radio Emergency Call") //$NON-NLS-1$ //$NON-NLS-2$
  ;

  private final int value;

  private final String text;

  private final String css;

  private CallType(int value, String css, String text)
  {
    this.css = css;
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

  public String getCss()
  {
    return css;
  }

  public static CallType valueOf(int intValue)
  {
    for (CallType i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}
