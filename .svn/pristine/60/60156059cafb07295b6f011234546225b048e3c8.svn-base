/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.mmrbem.cabscreens.fe.common.DateTimeModel;
import com.sydac.mmrbem.cabscreens.fe.utils.timer.CommsTimerManager;
import com.sydac.mmrbem.cabscreens.fe.utils.timer.IRunCycleBroadcaster;
import com.sydac.mmrbem.cabscreens.fe.utils.timer.IRunCycleListener;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.application.CommsConnectionInfo;
import com.sydac.simcomms.framework.UnitCreator;

import javafx.application.Platform;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleLongProperty;

/**
 * Saloon CCTV Frontend Application entry point.
 * 
 * @author johnsh
 *
 */
public abstract class AbstractFxFrontendModule extends FxFrontendModule implements IRunCycleBroadcaster
{

  private static final long MILLIS = 1000L;

  private LongProperty simulationDateAndTimeInMillis = new SimpleLongProperty();

  private long currentSimTimeInMillis;

  private final List<IRunCycleListener> runCycleListeners = new ArrayList<>();
  
  protected String applicationName;

  protected String frameTitle;

  /**
   * @param unitCreators unit creators
   * @param connectionInfo connection information
   */
  public AbstractFxFrontendModule(Collection<UnitCreator> unitCreators, CommsConnectionInfo connectionInfo)
  {
    super(unitCreators, connectionInfo);
  }

  /**
   * @param connectionInfo connection information
   */
  public AbstractFxFrontendModule(CommsConnectionInfo connectionInfo)
  {
    super(connectionInfo);
  }

  @Override
  protected String getApplicationName()
  {
    return applicationName;
  }

  @Override
  protected String getFrameTitle(int carIndex)
  {
    return frameTitle + carIndex;
  }

  @Override
  protected Collection<UnitCreator> doDefineSession(Gateway gateway, BaseScenarioData scenarioData, BaseSessionData sessionData)
  {
    initializeCommsTimerManager(gateway, sessionData);
    final long sessionStartTimeInMillis = sessionData.getStartDateTime() * MILLIS;
    simulationDateAndTimeInMillis.set(sessionStartTimeInMillis);
    DateTimeModel.bindSimTime(simulationDateAndTimeInMillis);

    gateway.scheduleTimerCallback(time ->
    {
      Platform.runLater(() ->

      simulationDateAndTimeInMillis.set(sessionStartTimeInMillis + (long)(time * MILLIS)));

      return time + (Math.signum(getGateway().getTiming().getRate()) * 0.1);
    }, 0d);

    return super.doDefineSession(gateway, scenarioData, sessionData);
  }

  @Override
  public void unloadScenario()
  {
    super.unloadScenario();

    runCycleListeners.clear();
    CommsTimerManager.stopTimerManager();
  }

  /**
   * 1. Initialize CommsTimerManager <br>
   * 2. Set the session start time <br>
   * 3. Attach a timer callback on the gateway to receive run-cycle callbacks.
   *
   * @param gateway      as {@link Gateway}
   * @param aSessionData as current session Data.{@link BaseSessionData}
   */
  private void initializeCommsTimerManager(Gateway gateway, BaseSessionData aSessionData)
  {
      CommsTimerManager.initializeTimerManager(this);
      final long sessionSimStartTimeUTCMillis = aSessionData.getStartDateTime() * 1000L;

      gateway.scheduleTimerCallback(elapsedTimeInMillis ->
      {
          currentSimTimeInMillis = sessionSimStartTimeUTCMillis + (long) (elapsedTimeInMillis * 1000L);
          for (IRunCycleListener runCycleListener : runCycleListeners)
          {
              runCycleListener.runCycle(currentSimTimeInMillis);
          }

          return elapsedTimeInMillis + (Math.signum(getGateway().getTiming().getRate()) * 0.1D);

      }, 0);
  }

  @Override
  public void join(IRunCycleListener runCycleListener)
  {
    runCycleListeners.add(runCycleListener);    
  }

  @Override
  public void release(IRunCycleListener runCycleListener)
  {
    runCycleListeners.remove(runCycleListener);
  }

  @Override
  public long getCurrentTimeInMillis()
  {
    return currentSimTimeInMillis;
  }

}
