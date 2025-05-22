/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.papis.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.papis.backend.logic.SharedDataModel;
import com.sydac.mmrbem.papis.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsProperties;
import com.sydac.mmrbem.papis.backend.vehicle.io.properties.IPISBEOutputsStartupScreenProperties;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsCommonProperties;
import com.sydac.mmrbem.papis.common.io.properties.IVehicleProperties;

/**
 * This handler class is used for screen change handling. All screen change
 * logic
 * 
 * @author ext-vp
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class ScreenChangeHandler extends AbstractFunctionalLogic implements IScreenChangeHandler
{

  private final SharedDataModel shareDataModel;

  private IAppOutputsHandler appOutputsHandler;

  /**
   * The screen change listener map. Currently supports only on
   * {@link IScreenChangeListener} for one screen. If more than one listener
   * added for same screen, first listener will be removed.
   */
  private Map<ScreenId, IScreenChangeListener> screenChangeListenerMap = new HashMap<>();

  /** The current screen. */
  private ScreenId currentScreen = ScreenId.BLANK_SCREEN;

  private ScreenId currentPopup = ScreenId.BLANK_SCREEN;

  private static final int POWER_ON = 1;

  private boolean isPcuFailed = false;

  private int lastActiveScreen = ScreenId.MAIN_INTERFACE_SCREEN.getId();

  private static final int PCU_FAILURE = 1;

  private CommsBinding commsBinding;

  public ScreenChangeHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPISBEOutputsProperties.class, IVehicleProperties.class);

    this.commsBinding = commsBinding;

    shareDataModel = aShareDataModel;
   
  }

  @Override
  public <T> void trainComputerVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {

    if (getActiveVehicleIndex() == vehicleIndex)
    {}
  }

  @Override
  public <T> void pisBeOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (IPISBEOutputsStartupScreenProperties.POWER_STATE.equals(key))
    {
      if (((Integer)newValue) == (POWER_ON) && !isPcuFailed)
      {
        processScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN.getId());
        lastActiveScreen = ScreenId.MAIN_INTERFACE_SCREEN.getId();
      }
      else
      {
        processScreenChangeRequest(ScreenId.BLANK_SCREEN.getId());
      }
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

  void processScreenChangeRequest(int screenChangeRequest)
  {
    if (screenChangeRequest > -1)
    {
      ScreenId request = ScreenId.valueOf(screenChangeRequest);
      setCurrentScreen(request);
    }
  }

  void processPopupChangeRequest(int popupChangeRequest)
  {
    if (popupChangeRequest > 0)
    {
      ScreenId request = ScreenId.valueOf(popupChangeRequest);
      setCurrentPopup(request);
    }
  }

  protected void setCurrentScreen(ScreenId request)
  {

    ScreenId newScreen = request;

    notifyScreenChange(newScreen);

    initializeOutputHandler();

    updateCurrentScreen(currentScreen.getId());

    shareDataModel.setScreenId(currentScreen.getId());
  }

  protected void setCurrentPopup(ScreenId request)
  {
    ScreenId newPopup = request;

    notifyPopupChange(newPopup);

    initializeOutputHandler();

    updateCurrentPopup(currentPopup.getId());

    shareDataModel.setPopupId(currentPopup.getId());
  }

  private void updateCurrentScreen(int screenId)
  {
    if (appOutputsHandler != null)
    {
      appOutputsHandler.setCurrentScreenId(screenId);
    }
  }

  private void updateCurrentPopup(int popupId)
  {
    if (appOutputsHandler != null)
    {
      appOutputsHandler.setPopupScreenId(popupId);
    }
  }

  private void notifyScreenChange(ScreenId newScreen)
  {
    if (currentScreen != newScreen)
    {
      notifyLeaving(currentScreen);
      currentScreen = newScreen;
      notifyEntering(currentScreen);
    }
  }

  private void notifyPopupChange(ScreenId newPopup)
  {
    if (currentPopup != newPopup)
    {
      currentPopup = newPopup;
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      initializeOutputHandler();
      if (key.equals(IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST) && (Integer)newValue > -1
          && !isPcuFailed)
      {
        processScreenChangeRequest((Integer)newValue);
        lastActiveScreen = (Integer)newValue;
      }
    }
  }

  @Override
  public <T> void vehiclePropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, Integer vehicleIndex)
  {
    if (IVehicleProperties.FLT_PCU_FAILURE.equals(key) && getActiveVehicleIndex() == vehicleIndex)
    {
      isPcuFailed = ((Integer)newValue == PCU_FAILURE);
      if (isPcuFailed)
      {
        processScreenChangeRequest(ScreenId.BLANK_SCREEN.getId());
      }
      else
      {
        processScreenChangeRequest(lastActiveScreen);
      }
    }
  }

  @Override
  public void requestScreenChange(ScreenId newScreenId)
  {
    if (!isPcuFailed)
    {
      processScreenChangeRequest(newScreenId.getId());
      lastActiveScreen = newScreenId.getId();
    }
  }

  private void initializeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsHandler)commsBinding.getAppOutputsSetter();
    }
  }

}
