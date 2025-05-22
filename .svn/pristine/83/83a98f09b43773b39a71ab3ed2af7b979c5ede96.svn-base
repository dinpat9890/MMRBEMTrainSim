/*
 * ==================================================================
 * 
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.common.state;

import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.DepartureOrder;

/**
 * This enum for DMI Departure Order
 * 
 * @author joshian
 *
 */
public enum DMIDepartureOrderStatus
{
  NO_ORDER("departure-order-no-order", DepartureOrder.NO_ORDER), //$NON-NLS-1$
  START("departure-order-start", DepartureOrder.START_ORDER), //$NON-NLS-1$
  CLOSE_DOORS("departure-order-close-doors", DepartureOrder.CLOSE_DOORS_ORDER), //$NON-NLS-1$
  OPEN_DOORS("departure-order-open-doors", DepartureOrder.OPEN_DOORS_ORDER); //$NON-NLS-1$

  private final int value;

  private final String text;

  private DMIDepartureOrderStatus(String text, int value)
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

  public static DMIDepartureOrderStatus valueOf(int intValue)
  {
    for (DMIDepartureOrderStatus i : values())
    {
      if (i.getValue() == intValue)
      {
        return i;
      }
    }
    throw new IllegalArgumentException("Invalid value for DMIDepartureOrderStatus : " + intValue); //$NON-NLS-1$
  }

}
