/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.psd.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.psd.backend.comms.CommsBinding;
import com.sydac.mmrbem.psd.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.psd.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.psd.common.ScreenId;
import com.sydac.mmrbem.psd.common.io.properties.IAppInputsProperties;


/**
 * This handler class is used for screen change handling. All screen change
 * logic
 * 
 * @author jadhalp
 *
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class ScreenChangeHandler extends AbstractFunctionalLogic implements IScreenChangeHandler
{

 
  private IAppOutputsHandler appOutputsHandler;

  /**
   * The screen change listener map. Currently supports only on
   * {@link IScreenChangeListener} for one screen. If more than one listener
   * added for same screen, first listener will be removed.
   */
  private Map<ScreenId, IScreenChangeListener> screenChangeListenerMap = new HashMap<>();

  /** The current screen. */
  private ScreenId currentPsdScreen = ScreenId.BLANK_SCREEN;

  private CommsBinding commsBinding;


  public ScreenChangeHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class);

    this.commsBinding = commsBinding;
   
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
    if (screenChangeRequest > 0)
    {
      ScreenId request = ScreenId.valueOf(screenChangeRequest);
      setCurrentScreen(request);
    }
  }


  protected void setCurrentScreen(ScreenId request)
  {
    ScreenId newScreen = request;

    notifyScreenChange(newScreen);

    initializeOutputHandler();

    updateCurrentScreen(currentPsdScreen.getId());

    
  }

  


  private void updateCurrentScreen(int screenId)
  {
    if (appOutputsHandler != null)
    {
      appOutputsHandler.setPsdScreenId(screenId);
    }
  }

 

  private void notifyScreenChange(ScreenId newScreen)
  {
    if (currentPsdScreen != newScreen)
    {
      notifyLeaving(currentPsdScreen);
      currentPsdScreen = newScreen;
      notifyEntering(currentPsdScreen);
    }
  }



  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      initializeOutputHandler();

     
    }
  }

  @Override
  public void requestScreenChange(ScreenId newScreenId)
  {
    processScreenChangeRequest(newScreenId.getId());
  }

  private void initializeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsHandler)commsBinding.getAppOutputsSetter();
    }
  }
}
