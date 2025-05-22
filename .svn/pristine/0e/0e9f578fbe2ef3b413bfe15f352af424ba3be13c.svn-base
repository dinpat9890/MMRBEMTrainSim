/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.common.state;

public enum CallInfoStatus
{
  NONE(0, "none", ""), //$NON-NLS-1$ //$NON-NLS-2$
  CALL_REQUEST(1, "active", " Requested"), //$NON-NLS-1$ //$NON-NLS-2$
  CALL_CONNECTED(2, "active", " Connected"), //$NON-NLS-1$ //$NON-NLS-2$
  CALL_TALKING(3, "active", " Talking"), //$NON-NLS-1$ //$NON-NLS-2$
  CALL_DISCONNECTED(4, "active", "Disconnected"), //$NON-NLS-1$ //$NON-NLS-2$
  ;

  private final int value;

  private final String text;

  private final String css;

  private CallInfoStatus(int value, String css, String text)
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

  public static CallInfoStatus valueOf(int intValue)
  {
    for (CallInfoStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    return null;
  }
}
