/*
 * ================================================================== (C)
 * Copyright 2017 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.cabscreens.fe.common;

import javafx.beans.property.LongProperty;
import javafx.beans.property.ReadOnlyLongProperty;
import javafx.beans.property.ReadOnlyLongWrapper;

/**
 * This class is used to set current simulated time
 * 
 */
public class DateTimeModel
{

  private static ReadOnlyLongWrapper simTimeInMillis = new ReadOnlyLongWrapper();

  private DateTimeModel()
  {}

  /**
   * API to bind simulator's date and time to this utility.
   * 
   * @param simTime
   *          simulator time
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

  public static long getTimeInSeconds()
  {
    return getSimTimeProperty().get() / 1000L;
  }

}
