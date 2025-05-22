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

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.RadioCallType;

/**
 * <p>
 * {@link RadioCallTypeState} defines radio call types
 *
 * @author mulukg
 *
 */
public enum RadioCallTypeState
{

  NONE("", 0), //$NON-NLS-1$
  HALF_DUPLEX("Radio Call Type: Half Duplex Call", RadioCallType.RADIO_HALF_DUPLEX), //$NON-NLS-1$
  FULL_DUPLEX("Radio Call Type: Full Duplex Call", RadioCallType.RADIO_FULL_DUPLEX), //$NON-NLS-1$
  EMERGENCY("Radio Call Type: Emergency Call", RadioCallType.RADIO_EMERGNECY), //$NON-NLS-1$
  GROUP("Radio Call Type: Group Call", RadioCallType.RADIO_GROUP); //$NON-NLS-1$

  private final String text;

  private final int value;

  private RadioCallTypeState(String text, Integer value)
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

  public static RadioCallTypeState valueOf(int intValue)
  {
    for (RadioCallTypeState i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for RadioCallTypeState:" + intValue); //$NON-NLS-1$
  }

}
