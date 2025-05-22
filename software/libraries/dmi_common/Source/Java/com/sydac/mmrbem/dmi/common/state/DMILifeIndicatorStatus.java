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

/**
 * This enum for life indicator status
 * 
 * @author ext-savanjin
 *
 */

public enum DMILifeIndicatorStatus
{
  LIFE_INDICATOR_STATE_0("life-indicator-label-state-0", 0), // $NON-NLS-1
  LIFE_INDICATOR_STATE_1("life-indicator-label-state-1", 1), // $NON-NLS-1
  LIFE_INDICATOR_STATE_2("life-indicator-label-state-2", 2), // $NON-NLS-1
  LIFE_INDICATOR_STATE_3("life-indicator-label-state-3", 3), // $NON-NLS-1
  LIFE_INDICATOR_STATE_4("life-indicator-label-state-4", 4), // $NON-NLS-1
  LIFE_INDICATOR_STATE_5("life-indicator-label-state-5", 5), // $NON-NLS-1
  LIFE_INDICATOR_STATE_6("life-indicator-label-state-6", 6); // $NON-NLS-1

  private final int value;

  private final String text;

  private DMILifeIndicatorStatus(String text, int value)
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

  public static DMILifeIndicatorStatus valueOf(int intValue)
  {
    for (DMILifeIndicatorStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for Life Indicator Status:" + intValue); //$NON-NLS-1$
  }
}
