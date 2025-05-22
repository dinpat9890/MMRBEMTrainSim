/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.fe.base;

import java.awt.event.ActionEvent;
import java.io.IOException;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Properties;

import javax.swing.Timer;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.common.febe.HubUtils;
import com.sydac.common.febe.frontend.IHubObjectCallback;
import com.sydac.common.febe.frontend.IODataObjectCreator;
import com.sydac.common.febe.frontend.IODataObjectMonitor;
import com.sydac.common.log.Tracer;
import com.sydac.common.registry.Registry;
import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.base.AbstractFrontendPanelManager;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendSceneManager;
import com.sydac.mmrbem.psd.common.ScreenId;
import com.sydac.mmrbem.psd.common.data.ApplicationConstants;
import com.sydac.mmrbem.psd.common.io.properties.IAppOutputsScreenChangeProperties;

import com.sydac.mmrbem.psd.fe.app.PSDApplication;
import com.sydac.mmrbem.psd.fe.base.impl.FxFrontendSceneManagerImpl;
import com.sydac.mmrbem.psd.fe.base.utils.TimeUtil;
import com.sydac.mmrbem.psd.fe.common.Frontend;
import com.sydac.mmrbem.psd.fe.comms.CommsBinding;
import com.sydac.mmrbem.psd.fe.comms.CommsBindingImpl;
import com.sydac.peer.application.PeerApplication;
import com.sydac.project.runtimedata.ProjectObjectConstants;
import com.sydac.project.runtimedata.ProjectObjectDefinition;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.Gateway;
import com.sydac.simcomms.TimingStatus;

import javafx.application.Platform;
import javafx.beans.property.LongProperty;
import javafx.beans.property.SimpleLongProperty;
import javafx.scene.Cursor;
import javafx.scene.Scene;

/**
 * Frontend Panel Manager that bridges the simulator session with the JavaFx
 * application's creation and presentation
 *
 * @author Nazim Oliyath
 */
public class FrontendPanelManager extends AbstractFrontendPanelManager
{

  // These objects have an application-long lifetime.
  private final PeerApplication baseApplication;

  private long sessionSimStartTimeUTCMillis;

  private LongProperty simulationDateAndTimeInMillis = new SimpleLongProperty();

  private static final long MILLIS = 1000L;

  private Timer timer = new Timer(100, (ActionEvent e) -> setCurrentTime());

  private final Object lock = new Object();

  private DBScenarioTrain dbScenarioTrain;

  private static final Tracer logger = Tracer.getInstance();

  public FrontendPanelManager(PeerApplication baseApplication)
  {
    this.baseApplication = baseApplication;

  }

  @Override
  public void prepareFrontend(Gateway aGateway, BaseScenarioData aScenarioData, BaseSessionData aSessionData,
      int carIndex)
  {
    // Ideally following two lines of code not required when FeBe helper is
    // used.
    // Still retains as we have not fully implemented FeBe Helper.
    prepareFrontend(carIndex);
    PSDFactory.register(carIndex, hubObjectProvider);
    PSDFactory.register(carIndex, new CommsBindingImpl(aGateway, carIndex));
  }

  @Override
  public void startFrontends(String aApplicationName, Gateway aGateway, BaseScenarioData aScenarioData,
      BaseSessionData aSessionData, boolean aIsSimulation, IHubObjectCallback aCallback)
  {
    sessionSimStartTimeUTCMillis = aSessionData.getStartDateTime() * MILLIS;
    simulationDateAndTimeInMillis.set(sessionSimStartTimeUTCMillis);
    TimeUtil.bindSimTime(simulationDateAndTimeInMillis);

    int logicalHubId = 0;
    try
    {
      logicalHubId = HubUtils.findLogicalHubId(aScenarioData, Registry.getInstance());
    }
    catch (IOException e)
    {
      logger.error(e);
    }
    final int creatorId = Registry.getInstance().getInteger(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.CREATOR_ID_KEY); // $NON-NLS-1$
    final int scenarioTrainId = HubUtils.findScenarioTrainId(aScenarioData, logicalHubId);
    Map<Integer, IHubObjectCallback> callbacks = new LinkedHashMap<>();

    dbScenarioTrain = new DBScenarioTrain(aScenarioData.getScenarioId(), scenarioTrainId);

    Map<Integer, CommsBinding> commsBindingMap = PSDFactory.getCommsBinding();
    if (aCallback == null) // GMI Plugin execution path
    {
      for (Entry<Integer, CommsBinding> commsBindingEntry : commsBindingMap.entrySet())
      {
        int carIndex = commsBindingEntry.getKey();
        callbacks.put(carIndex, new FxHubObjectCallback(carIndex, commsBindingEntry.getValue()));
        ScreenChangeListener screenChangeListener = new ScreenChangeListener(carIndex);
        screenChangeListener.attachToModel(PSDFactory.getCommsBinding(carIndex));
        CommsListenerManager.addListener(carIndex, screenChangeListener);
      }
    }
    else
    // FrontendModule execution path
    {
      for (Entry<Integer, CommsBinding> commsBindingEntry : commsBindingMap.entrySet())
      {
        int carIndex = commsBindingEntry.getKey();
        callbacks.put(carIndex, new TCMSCompositeHubObjectCallback(carIndex, commsBindingEntry.getValue(),
            aCallback, hubObjectCallbacks.get(carIndex), timer));
      }
    }

    if (aIsSimulation)
    {
      monitor = new IODataObjectCreator(aGateway, aApplicationName, logicalHubId, creatorId,
          ProjectObjectConstants.ClassId.PSD, scenarioTrainId, callbacks,
          ProjectObjectDefinition.getObjectDefinition(ProjectObjectConstants.ClassId.PSD_INPUTS),
          ProjectObjectDefinition.getObjectDefinition(ProjectObjectConstants.ClassId.PSD_OUTPUTS),
          ProjectObjectDefinition.getObjectDefinition(ProjectObjectConstants.ClassId.PSD_INPUTS_VALUES));

    }
    else
    {
      monitor = new IODataObjectMonitor(aGateway, logicalHubId, creatorId, ProjectObjectConstants.ClassId.PSD,
          scenarioTrainId, callbacks);
    }

    monitor.startSession();
    timer.start();
  }

  @Override
  public void flush()
  {
    CommsListenerManager.clear();
    PSDFactory.flush();
    timer.stop();
  }

  @Override
  public void createFxApplication(int carIndex, Properties properties)
  {
    int xpos = (int)properties.get(XPOS_KEY);
    int ypos = (int)properties.get(YPOS_KEY);
    int width = (int)properties.get(APP_WIDTH_KEY);
    int height = (int)properties.get(APP_HEIGHT_KEY);

    PSDApplication.startApplication(xpos, ypos, width, height, sceneManager);
  }

  @Override
  public void showFxApplication(final int carIndex, final boolean show)
  {
    if (show)
    {
      PSDApplication.showApplication(carIndex);
    }
    else
    {
      PSDApplication.hideApplication();
    }
  }

  /*
   * (non-Javadoc)
   *
   * @see com.sydac.fgwiep.fe.base.IFxFrontendPanelManager#pauseFxApplication(
   * boolean)
   */
  @Override
  public void pauseFxApplication(boolean pause)
  {
    PSDApplication.pauseApplication(pause);
  }

  @Override
  protected IFxFrontendSceneManager createSceneManager()
  {
    return new FxFrontendSceneManagerImpl();
  }

  private void setCurrentTime()
  {
    Platform.runLater(() -> {
      TimingStatus timingStatus = baseApplication.getGateway().getTiming();
      timingStatus.acquire();

      try
      {
        synchronized (lock)
        {
          simulationDateAndTimeInMillis
              .set(sessionSimStartTimeUTCMillis + (long)(timingStatus.getCurrentSysTime() * 1000));
        }
      }
      finally
      {
        timingStatus.release();
      }
    });
  }

  class ScreenChangeListener extends AbstractCommsListener
  {

    public ScreenChangeListener(int carIndex)
    {
      setScenarioCarIndex(carIndex);

      propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);
    }

    @Override
    protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
    {
      if (key == IAppOutputsScreenChangeProperties.PSD_SCREEN_ID)
      {
        // Need to change getFiveCarScreenName to correct screen mapping
        // according to number of cars
        String screenName;
        screenName = getScreenName((Integer)newValue);
        if (fxPanels.containsKey(scenarioCarIndex))
        {
          Scene scene = fxPanels.get(scenarioCarIndex).changeScene(screenName, scenarioCarIndex,
              sceneManager);
          if (hideMouse)
          {
            scene.setCursor(Cursor.NONE);
          }
        }
      }
    }

    private String getScreenName(int id)
    {
      return ScreenId.valueOf(id).getScreenName();
    }
  }

  /**
   * Utility class using "Composition Pattern" which can be used to compose two
   * or more {@link IHubObjectCallback}
   *
   * @author Nazim Oliyath
   */
  public static final class TCMSCompositeHubObjectCallback implements IHubObjectCallback
  {
    private final int carIndex;

    private final IHubObjectCallback hubObjectCallback;

    private final IHubObjectCallback hubObjectCallback2;

    private final IHubObjectCallback hubObjectCallback3;

    private Timer timer;

    public TCMSCompositeHubObjectCallback(int carIndex, IHubObjectCallback hubObjectCallback,
        IHubObjectCallback hubObjectCallback2, IHubObjectCallback hubObjectCallback3, Timer timer)
    {
      this.carIndex = carIndex;
      this.hubObjectCallback = hubObjectCallback;
      this.hubObjectCallback2 = hubObjectCallback2;
      this.hubObjectCallback3 = hubObjectCallback3;
      this.timer = timer;
    }

    /*
     * (non-Javadoc)
     *
     * @see com.sydac.febe.comms.frontend.IHubObjectCallback#onHubInputCreation(
     * com .sydac.simcomms.CObject)
     */
    @Override
    public void onHubInputCreation(CObject hubInput)
    {
      hubObjectCallback.onHubInputCreation(hubInput);
      hubObjectCallback2.onHubInputCreation(hubInput);
      hubObjectCallback3.onHubInputCreation(hubInput);
    }

    /*
     * (non-Javadoc)
     *
     * @see
     * com.sydac.febe.comms.frontend.IHubObjectCallback#onHubOutputCreation(
     * com.sydac.simcomms.CObject)
     */
    @Override
    public void onHubOutputCreation(CObject hubOutput)
    {
      hubObjectCallback.onHubOutputCreation(hubOutput);
      hubObjectCallback2.onHubOutputCreation(hubOutput);
      hubObjectCallback3.onHubOutputCreation(hubOutput);
    }

    /*
     * (non-Javadoc)
     *
     * @see
     * com.sydac.febe.comms.frontend.IHubObjectCallback#onHubValuesCreation(
     * com.sydac.simcomms.CObject)
     */
    @Override
    public void onHubValuesCreation(CObject hubValues)
    {
      hubObjectCallback.onHubValuesCreation(hubValues);
      hubObjectCallback2.onHubValuesCreation(hubValues);
      hubObjectCallback3.onHubValuesCreation(hubValues);
      timer.start();
    }

    /*
     * (non-Javadoc)
     *
     * @see com.sydac.febe.comms.frontend.IHubObjectCallback#
     * onHubObjectDestruction()
     */
    @Override
    public void onHubObjectDestruction()
    {
      hubObjectCallback.onHubObjectDestruction();
      hubObjectCallback2.onHubObjectDestruction();
      hubObjectCallback3.onHubObjectDestruction();
      timer.stop();
      CommsListenerManager.detachFromModel(carIndex);
    }

  }

  protected static final class FxHubObjectCallback implements IHubObjectCallback
  {
    private final int carIndex;

    private final IHubObjectCallback hubObjectCallback;

    public FxHubObjectCallback(int aCarIndex, IHubObjectCallback hubObjectCallback)
    {
      this.carIndex = aCarIndex;
      this.hubObjectCallback = hubObjectCallback;
    }

    /*
     * (non-Javadoc)
     *
     * @see
     * com.sydac.febe.comms.frontend.IHubObjectCallback#onHubInputCreation(com
     * .sydac.simcomms.CObject)
     */
    @Override
    public void onHubInputCreation(CObject hubInput)
    {
      hubObjectCallback.onHubInputCreation(hubInput);
      CommsListenerManager.attachToModel(carIndex, PSDFactory.getCommsBinding(carIndex));
    }

    /*
     * (non-Javadoc)
     *
     * @see
     * com.sydac.febe.comms.frontend.IHubObjectCallback#onHubOutputCreation(
     * com.sydac.simcomms.CObject)
     */
    @Override
    public void onHubOutputCreation(CObject hubOutput)
    {
      hubObjectCallback.onHubOutputCreation(hubOutput);
    }

    /*
     * (non-Javadoc)
     *
     * @see
     * com.sydac.febe.comms.frontend.IHubObjectCallback#onHubValuesCreation(
     * com.sydac.simcomms.CObject)
     */
    @Override
    public void onHubValuesCreation(CObject hubValues)
    {
      hubObjectCallback.onHubValuesCreation(hubValues);
    }

    /*
     * (non-Javadoc)
     *
     * @see
     * com.sydac.febe.comms.frontend.IHubObjectCallback#onHubObjectDestruction()
     */
    @Override
    public void onHubObjectDestruction()
    {
      hubObjectCallback.onHubObjectDestruction();
      CommsListenerManager.detachFromModel(carIndex);
    }
  }
}
