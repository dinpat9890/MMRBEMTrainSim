/*
 * ======================================================================= (C)
 * Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.logic.handler;

import java.math.BigDecimal;
import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.common.registry.Registry;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.dmi.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.dmi.backend.logic.SharedDataModel;
import com.sydac.mmrbem.dmi.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.dmi.backend.vehicle.io.models.IDMIVehicleOutputsModel;
import com.sydac.mmrbem.dmi.backend.vehicle.io.properties.IDMIVehicleOutputsStartupScreenProperties;
import com.sydac.mmrbem.dmi.common.ScreenId;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsScreenSaverProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsStartupScreenProperties;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.mmrbem.dmi.common.state.DMIConstants;

/**
 * This handler class is used for screen change handling. All screen change
 * logic
 * 
 * @author joshian
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class ScreenChangeHandler extends AbstractFunctionalLogic
{
  private static final int EXECUTION_TIME_DIFFERENCE = 1000; // in millisecond

  private IAppOutputsHandler appOutputsHandler;

  private final SharedDataModel shareDataModel;

  private IDMIVehicleOutputsModel vOutputModel;

  private int lifeIndicatorCounter = 0;

  private int progressBarValueCounter = 0;

  private long previousLifeIndicatorTime = 0;

  private long previousProgressBarTime = 0;

  private long currentTime = 0;

  private boolean processBarState = true;

  /**
   * Progress bar counter states.
   */
  private double progressBarCounterStates = Registry.getInstance()
      .getInteger(ApplicationConstants.DOMAIN_NAME, ApplicationConstants.PROGRESS_BAR_COUNTER_STATES, 10);

  /**
   * The screen change listener map. Currently supports only on
   * {@link IScreenChangeListener} for one screen. If more than one listener
   * added for same screen, first listener will be removed.
   */
  private Map<ScreenId, IScreenChangeListener> screenChangeListenerMap = new HashMap<>();

  /** The current screen. */
  private ScreenId currentScreen = ScreenId.BLANK_SCREEN;

  private CommsBinding commsBinding;

  public ScreenChangeHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IDMIVehicleOutputsStartupScreenProperties.class);

    this.commsBinding = commsBinding;

    initalizeVOutputModel();

    shareDataModel = aShareDataModel;
  }

  private void initalizeVOutputModel()
  {
    if (this.vOutputModel == null)
    {
      this.vOutputModel = (IDMIVehicleOutputsModel)commsBinding.getDmivehicleoutputsmodels()
          .get(getActiveVehicleIndex());

    }
  }

  /**
   * Registering ScreenChangeListeners can be done from BusinessLogic.
   * 
   * @param screenId
   *          the screen id
   * @param screenChangeListener
   *          the screen change listener
   */
  public final void register(ScreenId screenId, IScreenChangeListener screenChangeListener)
  {
    screenChangeListenerMap.put(screenId, screenChangeListener);
  }

  @Override
  public void attachListeners()
  {
    super.attachListeners();
    initializeOutputHandler();
    setCurrentScreen(ScreenId.BLANK_SCREEN);
  }

  @Override
  public void detachListeners()
  {
    super.detachListeners();
    appOutputsHandler = null;
  }

  /**
   * Notify leaving.
   * 
   * @param screenId
   *          the screen id
   */
  private void notifyLeaving(ScreenId screenId)
  {
    if (screenChangeListenerMap.containsKey(screenId))
    {
      screenChangeListenerMap.get(screenId).onLeavingScreen(screenId.getId());
    }
  }

  /**
   * Notify entering.
   * 
   * @param screenId
   *          the screen id
   */
  private void notifyEntering(ScreenId screenId)
  {
    if (screenChangeListenerMap.containsKey(screenId))
    {
      screenChangeListenerMap.get(screenId).onEnteringScreen(screenId.getId());
    }
  }

  private void setCurrentScreen(ScreenId request)
  {
    ScreenId newScreen = request;
    if (currentScreen != newScreen)
    {
      notifyLeaving(currentScreen);
      currentScreen = newScreen;
      notifyEntering(currentScreen);
    }
    appOutputsHandler.setCurrentScreenId(currentScreen.getId());
    shareDataModel.setScreenId(currentScreen.getId());
  }

  @Override
  public void process(long aSimTime)
  {
    initializeOutputHandler();
    initalizeVOutputModel();
    this.currentTime = aSimTime;
    lifeIndicatorStatusUpdate();
    progressBarStatusUpdate();
    setDateTime(aSimTime);
  }

  private void setDateTime(Long aSimTime)
  {
    if (aSimTime != null)
    {
      setApplicationOutputsProperty(IAppOutputsMainScreenProperties.CURRENT_DATE_AND_TIME, aSimTime);
    }
  }

  @Override
  public <T> void dmiVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {

    initalizeVOutputModel();

    if (key.equals(IDMIVehicleOutputsStartupScreenProperties.POWER_ON)
        || key.equals(IDMIVehicleOutputsStartupScreenProperties.CAB_ACTIVE))
    {

      if (this.vOutputModel != null && getActiveVehicleIndex() == vehicleIndex)
      {
        initializeOutputHandler();

        if (this.vOutputModel.getPowerOn() == 0)
        {
          processScreenChangeRequest(ScreenId.BLANK_SCREEN.getId());
        }
        else
        {
          if ((this.vOutputModel.getCabActive() == 1) && this.vOutputModel.getPowerOn() == 1)
          {
            setServiceNumberValue();

            processBarState = true;
            progressBarValueCounter = 0;
            progressBarCounterStates = Registry.getInstance().getInteger(ApplicationConstants.DOMAIN_NAME,
                ApplicationConstants.PROGRESS_BAR_COUNTER_STATES, 10);

            progressBarStatusUpdate();
          }
          else if (this.vOutputModel.getCabActive() == 0 && this.vOutputModel.getPowerOn() == 1)
          {
            processScreenChangeRequest(ScreenId.SCREEN_SAVER_SCREEN.getId());
          }
        }
      }
    }
  }

  private void setServiceNumberValue()
  {
    // set service number value
    setApplicationOutputsProperty(IAppOutputsMainScreenProperties.SERVICE_NUMBER_VALUE,
        shareDataModel.getServiceNumber());
  }

  private void setSoftwareVersion()
  {
    // set service number value
    setApplicationOutputsProperty(IAppOutputsScreenSaverProperties.SOFTWARE_VERSION,
        shareDataModel.getSoftwareVersion().getBytes());
  }

  private void lifeIndicatorStatusUpdate()
  {
    if (currentTime - previousLifeIndicatorTime >= EXECUTION_TIME_DIFFERENCE)
    {

      previousLifeIndicatorTime = currentTime;
      if (lifeIndicatorCounter > DMIConstants.LIFE_INDICATOR_COUNTER_STATES)
      {
        lifeIndicatorCounter = DMIConstants.LIFE_INDICATOR_COUNTER_START_STATE;
      }
      setApplicationOutputsProperty(IAppOutputsMainScreenProperties.LIFE_INDICATOR_STATUS,
          lifeIndicatorCounter++);
    }
  }

  private void progressBarStatusUpdate()
  {

    if (this.vOutputModel != null && this.vOutputModel.getCabActive() > 0 && processBarState)
    {
      // set startup screen when counter is at 0 only
      if (progressBarValueCounter == 0)
      {
        processScreenChangeRequest(ScreenId.STARTUP_SCREEN.getId());
      }
      else if (isEqual(progressBarValueCounter, progressBarCounterStates))
      {
        // set main screen after loading
        processScreenChangeRequest(ScreenId.MAIN_SCREEN.getId());
      }

      // difference between current time and previous time is calculated and
      // checked if it is greater than or equals to 1 second(1000 millisecond)
      // to increase progress bar value after 1 second delay
      if (currentTime - previousProgressBarTime >= EXECUTION_TIME_DIFFERENCE)
      {
        previousProgressBarTime = currentTime;

        if (progressBarValueCounter >= progressBarCounterStates)
        {
          processBarState = false;
        }

        setApplicationOutputsProperty(IAppOutputsStartupScreenProperties.PROGRESS_BAR_VALUE,
            progressBarValueCounter / progressBarCounterStates);

        progressBarValueCounter++;
      }
    }
  }

  private boolean isEqual(double doubleValue, double doubleValue1)
  {
    BigDecimal a = BigDecimal.valueOf(doubleValue);
    BigDecimal b = BigDecimal.valueOf(doubleValue1);
    return a.compareTo(b) == 0;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      initializeOutputHandler();
    }
  }

  private void initializeOutputHandler()
  {
    if (appOutputsHandler == null)
      appOutputsHandler = (IAppOutputsHandler)commsBinding.getAppOutputsSetter();
    setSoftwareVersion();
  }

  private void processScreenChangeRequest(int screenChangeRequest)
  {
    ScreenId request = ScreenId.valueOf(screenChangeRequest);
    setCurrentScreen(request);
  }

}
