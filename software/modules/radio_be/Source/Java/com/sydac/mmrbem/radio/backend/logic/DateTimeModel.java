/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.radio.backend.logic;

import com.sydac.foundation.Model;

/**
 * This class is used to set current simulated time
 * 
 */
public class DateTimeModel extends Model
{

  /** The date time model. */
  private static DateTimeModel dateTimeModel;

  /** The time. */
  private long time;

  /** The session start time. */
  private long sessionStartTime;

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
   * Sets time when runCyle in RadioBackendModule updated and fires TIME_CHANGE
   * event.
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
   * Sets session start time.
   * 
   * @param sessionStartTime
   *          session start time
   */
  public void setSessionStartTime(final long sessionStartTime)
  {
    this.sessionStartTime = sessionStartTime;
  }

  /**
   * Gets session start time(in milliseconds).
   * 
   * @return session start time
   */
  public long getSessionStartTime()
  {
    return sessionStartTime;
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

}
