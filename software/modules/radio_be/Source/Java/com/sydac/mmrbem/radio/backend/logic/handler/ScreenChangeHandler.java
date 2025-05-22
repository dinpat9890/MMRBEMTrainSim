/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.radio.backend.logic.SharedDataModel;
import com.sydac.mmrbem.radio.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.radio.backend.vehicle.io.models.properties.IPAPISVehicleOutputsProperties;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.radio.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.radio.common.io.properties.IVehicleProperties;

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

  /**
   * The screen change listener map. Currently supports only on
   * {@link IScreenChangeListener} for one screen. If more than one listener
   * added for same screen, first listener will be removed.
   */
  private Map<ScreenId, IScreenChangeListener> screenChangeListenerMap = new HashMap<>();

  /** The current screen. */
  private ScreenId currentScreen = ScreenId.BLANK_SCREEN;

  private boolean isTrainRadioFailed = false;

  private static final int TRAIN_RADIO_FAILURE = 1;

  private int lastActiveScreen = ScreenId.BLANK_SCREEN.getId();

  public ScreenChangeHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, IPAPISVehicleOutputsProperties.class,
        IVehicleProperties.class);

    shareDataModel = aShareDataModel;

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
    setCurrentScreen(ScreenId.BLANK_SCREEN);
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

  private void processScreenChangeRequest(int screenChangeRequest)
  {
    ScreenId request = ScreenId.valueOf(screenChangeRequest);
    setCurrentScreen(request);
  }

  protected void setCurrentScreen(ScreenId request)
  {

    ScreenId newScreen = request;

    notifyScreenChange(newScreen);

    updateCurrentScreen(currentScreen.getId());

    shareDataModel.setScreenId(currentScreen.getId());
  }

  private void updateCurrentScreen(int screenId)
  {
    setApplicationOutputsProperty(IAppOutputsScreenChangeProperties.CURRENT_SCREEN_ID, screenId);
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

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex
        && key.equals(IAppInputsScreenChangeProperties.SCREEN_CHANGE_REQUEST) && (Integer)newValue > -1
        && !isTrainRadioFailed)
    {
      processScreenChangeRequest((Integer)newValue);
      lastActiveScreen = (Integer)newValue;
    }
  }

  @Override
  public void requestScreenChange(ScreenId newScreenId)
  {
    if (!isTrainRadioFailed)
    {
      processScreenChangeRequest(newScreenId.getId());
      lastActiveScreen = newScreenId.getId();
    }
  }

  @Override
  public <T> void vehiclePropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, Integer vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex && IVehicleProperties.FLT_TRAIN_RADIO_FAILURE.equals(key))
    {
      isTrainRadioFailed = ((Integer)newValue == TRAIN_RADIO_FAILURE);

      if (isTrainRadioFailed)
      {
        processScreenChangeRequest(ScreenId.BLANK_SCREEN.getId());
      }
      else
      {
        processScreenChangeRequest(lastActiveScreen);
      }
    }
  }
}
