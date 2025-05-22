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
import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.DepartureInformation.DepartureStatus;
/**
 * This enum for departure information
 * @author ext-savanjin
 *
 */

public enum DMIDepartureInformation
{
  NO_INDICATION("departure-information-no-indication", DepartureStatus.NO_INDICATION.getNumber()), // $NON-NLS-1
  NO_DEPARTURE_INFO("departure-information-no-info", DepartureStatus.NO_DEPARTURE_INFO.getNumber()), // $NON-NLS-1
  TRAIN_HOLD("departure-information-train-hold", DepartureStatus.TRAIN_HOLD.getNumber()), // $NON-NLS-1
  REMAINING_TIME("departure-information-remaining-time", DepartureStatus.REMAINING_TIME.getNumber()); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMIDepartureInformation(String text, int value)
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

  public static DMIDepartureInformation valueOf(int intValue)
  {
    for (DMIDepartureInformation i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIDepartureInformation:" + intValue); //$NON-NLS-1$
  }
}
