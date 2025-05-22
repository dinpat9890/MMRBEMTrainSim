/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.logic;

import com.sydac.foundation.Model;

public class DateTimeModel extends Model
{

  /** The date time model. */
  private static DateTimeModel dateTimeModel;

  /** The time. */
  private long time;

  /** The time. */
  private long startTime;

  /**
   * private constructor of class to avoid instantiation.
   */
  private DateTimeModel()
  {}

  /* Static 'instance' method */
  /**
   * Gets the single instance of DateTimeModel.
   * 
   * @return single instance of DateTimeModel
   */
  public static DateTimeModel getInstance()
  {
    if (dateTimeModel == null)
    {
      dateTimeModel = new DateTimeModel();
    }
    return dateTimeModel;
  }

  /**
   * The Enum DateTimeChange.
   */
  public enum DateTimeChange
  {
    TIME_CHANGE
  }

  /**
   * Sets time when runCyle in TCMSFrontendModule updated and fires
   * TIME_CHANGE event.
   *
   * @param aTime
   *          the new time
   */
  public void setTime(long aTime)
  {
    if (aTime != time)
    {
      time = aTime;
      fireModelChangedEvent(DateTimeChange.TIME_CHANGE);
    }
  }

  /**
   * Gets the time in milliseconds
   *
   * @return the time
   */
  public long getTime()
  {
    return time;
  }

  /**
   * Gets the time in seconds
   *
   * @return the time
   */
  public long getTimeInSeconds()
  {
    return time / 1000L;
  }

  /*
   * (non-Javadoc)
   * 
   * @see com.sydac.foundation.Model#onCreate()
   */
  @Override
  protected void onCreate()
  {
    // NO-OP

  }

  /*
   * (non-Javadoc)
   * 
   * @see com.sydac.foundation.Model#onDestroy()
   */
  @Override
  protected void onDestroy()
  {
    // NO-OP

  }

  public long getStartTime()
  {
    return startTime;
  }

  public void setStartTime(long startTime)
  {
    this.startTime = startTime;
  }

}
