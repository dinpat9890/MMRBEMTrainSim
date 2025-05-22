/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.base.utils;

import javafx.beans.property.LongProperty;
import javafx.beans.property.ReadOnlyLongProperty;
import javafx.beans.property.ReadOnlyLongWrapper;

/**
 * Utility class that provides simulation date and time values
 * 
 * @author Nazim Oliyath
 *
 */
public class TimeUtil
{
  private static ReadOnlyLongWrapper simTimeInMillis = new ReadOnlyLongWrapper();

  private TimeUtil()
  {}

  /**
   * API to bind simulator's date and time to this utility.
   * 
   * @param simTime
   *          simTime
   */
  public static final void bindSimTime(LongProperty simTime)
  {
    simTimeInMillis.bind(simTime);
  }

  /**
   * Utility API for clients to get the simulator time (read-only) property.<br>
   * The property provides the date and time value in milliseconds.
   * 
   * @return {@link LongProperty}, date and time in milliseconds
   */
  public static final ReadOnlyLongProperty getSimTimeProperty()
  {
    return simTimeInMillis.getReadOnlyProperty();
  }

}
