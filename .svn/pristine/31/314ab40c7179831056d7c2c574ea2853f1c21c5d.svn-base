/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.common.application;

/**
 * Clients willing to listen on {@link IRunCycleBroadcaster} have to implement
 * this interface and join to the broadcaster.
 * 
 * @author Nazim Oliyath
 * 
 */
@FunctionalInterface
public interface IRunCycleListener
{

  /**
   * Run cycle callback with current simulation time in milliseconds.
   * 
   * @param simulationTimeInMillis
   *          simulator time in millisecond
   */
  void runCycle(long simulationTimeInMillis);

}
