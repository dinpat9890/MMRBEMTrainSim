/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.application;

/**
 * BaseApplication extensions that need to support informing clients on
 * runCycle() can implement this interface.<br>
 * <br>
 * Interested clients have to implement the {@link IRunCycleListener} interface.
 * 
 * @author Nazim Oliyath
 * 
 */
public interface IRunCycleBroadcaster
{

  /**
   * Join to listen for runCycle callbacks.
   * 
   * @param runCycleListener
   *          run cycle listener
   */
  void join(IRunCycleListener runCycleListener);

  /**
   * Release listeners from receiving runCycle callbacks.
   * 
   * @param runCycleListener
   *          run cycle listener
   */
  void release(IRunCycleListener runCycleListener);

  /**
   * Get current simulation time in milliseconds.
   * 
   * @return get current time in millisecond
   */
  long getCurrentTimeInMillis();

}
