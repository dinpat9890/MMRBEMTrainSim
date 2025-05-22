/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.backend.app;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.febe.HubUtils;
import com.sydac.common.febe.backend.BackendModule;
import com.sydac.common.febe.backend.IVehicleBackend;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.AcceptCache;
import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.mmrbem.dmi.backend.logic.DateTimeModel;
import com.sydac.mmrbem.dmi.common.application.IRunCycleBroadcaster;
import com.sydac.mmrbem.dmi.common.application.IRunCycleListener;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.mmrbem.dmi.common.utils.timer.CommsTimerManager;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.application.CommsConnectionInfo;
import com.sydac.simcomms.framework.UnitCreator;
import com.sydac.simcomms.system.CSystem;
import com.sydac.simulatorcontroller.types.SimulatorType;

/**
 * Entry point for running the DMI Backend as a Comms Module.
 *
 */
public class DMIBackendModule extends BackendModule implements IRunCycleBroadcaster
{

  public static final int SESSION_PAUSED = 3;

  public static final int SESSION_RUNNING = 4;

  private long sessionSimStartTimeUTCMillis;

  private long currentSimTimeInMillis;

  private AcceptCache acceptCache;

  private Map<Integer, ApplicationContext> applicationContextMap;

  private final List<IRunCycleListener> runCycleListeners = new ArrayList<>();

  private int scenarioVehicleIndex = 0;

  /**
   * Instantiates a new DMI backend module.
   *
   * @param connectionInfo
   *          Connection information to connect to Comms
   */
  public DMIBackendModule(CommsConnectionInfo connectionInfo)
  {
    super(connectionInfo);
  }

  @Override
  public void initialise(final int xPosition, final int yPosition, final int screenWidth,
      final int screenHeight)
  {
    SimulatorType simulatorType = SimulatorType.valueOf(Registry.getInstance()
        .getString(ApplicationConstants.HUB_DOMAIN, ApplicationConstants.SIM_NAME_PROPERTY));
    // Prepare the acceptCache with either hub or simulator ID.

    acceptCache = new AcceptCache(simulatorType.getId());
  }

  @Override
  protected IVehicleBackend createVehicleBackend(DBScenarioTrain aTrain, int aCarIndex)
  {

    applicationContextMap = new HashMap<>();
    // Ideally this would be a bit smarter and use the car type here

    if (aCarIndex == scenarioVehicleIndex)
    {
      ApplicationContext applicationContext = new ApplicationContext();
      applicationContext.loadContext(getGateway(), aTrain, aCarIndex, this);

      applicationContextMap.put(aCarIndex, applicationContext);
      return applicationContext.getVehicleDMI();
    }
    return null;
  }

  @Override
  protected boolean doAcceptScenario(CSystem system, BaseScenarioData scenarioData)
  {
    try {
		scenarioVehicleIndex = HubUtils.findVehicleIndex(scenarioData,
		    HubUtils.findLogicalHubId(scenarioData, Registry.getInstance()));
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
    return acceptCache.acceptScenario(scenarioData);
  }

  @Override
  protected Collection<UnitCreator> doDefineSession(Gateway gateway, BaseScenarioData aScenarioData,
      BaseSessionData aSessionData)
  {
    initializeCommsTimerManager(gateway, aSessionData);
    applicationContextMap = new HashMap<>();
    DateTimeModel.getInstance().setTime(sessionSimStartTimeUTCMillis);
    DateTimeModel.getInstance().setSessionStartTime(sessionSimStartTimeUTCMillis);

    return Collections.emptyList();
  }

  @Override
  protected void doResetSession()
  {
    CommsTimerManager.stopTimerManager();
    currentSimTimeInMillis = 0;
    runCycleListeners.clear();
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

  /**
   * 1. Initialize CommsTimerManager <br>
   * 2. Set the session start time <br>
   * 3. Attach a timer callback on the gateway to receive run-cycle callbacks.
   *
   * @param gateway
   *          as {@link Gateway}
   * @param aSessionData
   *          as current session Data.{@link BaseSessionData}
   */
  private void initializeCommsTimerManager(Gateway gateway, BaseSessionData aSessionData)
  {
    CommsTimerManager.initializeTimerManager(this);
    sessionSimStartTimeUTCMillis = aSessionData.getStartDateTime() * 1000L;

    gateway.scheduleTimerCallback(elapsedTimeInMillis -> {
      currentSimTimeInMillis = sessionSimStartTimeUTCMillis + (long)(elapsedTimeInMillis * 1000L);
      for (IRunCycleListener runCycleListener : runCycleListeners)
      {
        runCycleListener.runCycle(currentSimTimeInMillis);
      }

      return elapsedTimeInMillis
          + (Math.signum(getGateway().getTiming().getRate()) * getThisCyclePeriod(elapsedTimeInMillis));

    }, 0);
  }

  @Override
  public long getCurrentTimeInMillis()
  {
    return 0;
  }

}