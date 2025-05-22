/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.common.utils.timer;

/**
 * CommsTimer allows Comms applications to have a timer that is based on
 * runCycle(). The execution of the timers are controlled by
 * {@link CommsTimerManager}<br>
 * <br>
 * Two types of timers are currently supported<br>
 * - Repeat Timers with/without initial delay<br>
 * - One time timers
 * 
 * @author Nazim Oliyath
 * 
 */
public class CommsTimer
{

  private static int timerCounter = 0;

  private enum State
  {
    INIT, STARTED, CANCELLED
  }

  private int sequenceNumber;

  private Runnable action;

  private boolean isRepeated;

  private long initialDelay;

  private long period;

  private State state;

  /**
   * Private constructor
   */
  private CommsTimer(int sequenceNumber, Runnable action, boolean isRepeated, long initialDelay, long period)
  {
    this.sequenceNumber = sequenceNumber;
    this.action = action;
    this.isRepeated = isRepeated;
    this.initialDelay = initialDelay;
    this.period = period;
    this.state = State.INIT;
  }

  /**
   * Provides a repeat timer with specified initial delay and repeat period
   * 
   * @param action
   *          {@link Runnable}
   * @param initialDelay
   *          in milliseconds
   * @param period
   *          in milliseconds
   * @return CommsTimer
   */
  public static final CommsTimer newRepeatTimer(Runnable action, long initialDelay, long period)
  {
    if (action == null)
    {
      throw new IllegalArgumentException("Action to execute cannot be null"); //$NON-NLS-1$
    }
    if (period <= 0 || initialDelay < 0)
    {
      throw new IllegalArgumentException(
          "Repeated timer cannot have zero period & initial delay cannot be negative"); //$NON-NLS-1$
    }

    return new CommsTimer(++timerCounter, action, true, initialDelay, period);
  }

  /**
   * Provides a one-time timer that executes after the specified delay
   * 
   * @param action
   *          {@link Runnable}
   * @param delay
   *          in milliseconds
   * @return CommsTimer
   */
  public static final CommsTimer newScheduledTimer(Runnable action, long delay)
  {
    if (delay < 0)
    {
      throw new IllegalArgumentException("Delay cannot be negative"); //$NON-NLS-1$
    }
    return new CommsTimer(++timerCounter, action, false, delay, 0L);
  }

  /**
   * sequenceNumber
   * 
   * @return int
   */
  int getSequenceNumber()
  {
    return this.sequenceNumber;
  }

  /**
   * Runnable action
   * 
   * @return Runnable
   */
  Runnable getAction()
  {
    return this.action;
  }

  /**
   * Is repeat timer?
   * 
   * @return boolean
   */
  boolean isRepeated()
  {
    return this.isRepeated;
  }

  /**
   * initialDelay
   * 
   * @return long
   */
  long getInitialDelay()
  {
    return this.initialDelay;
  }

  /**
   * Repeat period
   * 
   * @return long
   */
  long getPeriod()
  {
    return this.period;
  }

  /**
   * Start the timer
   */
  public final void start()
  {
    if (this.state == State.STARTED)
    {
      throw new IllegalStateException("Timer already started !!"); //$NON-NLS-1$
    }
    CommsTimerManager.scheduleTimer(this);
    this.state = State.STARTED;
  }

  /**
   * Cancel the timer
   */
  public final void cancel()
  {
    if (this.state == State.CANCELLED)
    {
      throw new IllegalStateException("Timer already cancelled !!"); //$NON-NLS-1$
    }
    CommsTimerManager.cancelTimer(this);
    this.state = State.CANCELLED;
  }

  /**
   * Cancel the timer without throwing already cancel exception. If already
   * canceled then do noting.
   */
  public final void safeCancel()
  {
    if (this.state != State.CANCELLED)
    {
      CommsTimerManager.cancelTimer(this);
      this.state = State.CANCELLED;
    }
  }

  /**
   * Returns true if the Timer is already started (or running)
   * 
   * @return running status
   */
  public final boolean isRunning()
  {
    return this.state == State.STARTED;
  }

}
