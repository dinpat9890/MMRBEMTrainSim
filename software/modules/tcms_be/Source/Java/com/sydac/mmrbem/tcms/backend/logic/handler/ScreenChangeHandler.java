/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.time.Duration;
import java.time.Instant;
import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.common.registry.Registry;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperationScreenProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IVehicleProperties;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsCCTVScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsDataLoadingProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHeaderPanelProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLoginPopupProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsVduSettingsPopupProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.HeaderPanelTitleEnum;
import com.sydac.mmrbem.tcms.common.state.VDUBrightnessModeEnum;
import com.sydac.mmrbem.tcms.common.state.VDUDataCatagory;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;
import com.sydac.mmrbem.tcms.common.utils.timer.CommsTimer;

/**
 * This handler class is used for screen change handling. All screen change
 * logic
 * 
 * @author potdars
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
  private ScreenId currentTcmsScreen = ScreenId.BLANK_SCREEN;

  private ScreenId currentTcmsPopup = ScreenId.BLANK_SCREEN;

  private ScreenId currentCctvScreen = ScreenId.BLANK_SCREEN;

  private ScreenId currentCctvPopup = ScreenId.BLANK_SCREEN;

  private CommsBinding commsBinding;

  private CommsTimer powerUpSplashScreenTimer;

  private CommsTimer powerUpBlueScreenTimer;

  private CommsTimer powerUpDataLoadingScreenTimer;

  private Instant lastActionTime;

  private boolean messageFlag = false;

  private int messageId = VDUDataCatagory.PROGRESS_1_MESSAGE.getValue();

  private int cctvDisplayHanged = 1;

  private int cctvDisplayNotHanged = 0;

  /** Runnable to perform actions of start up sequence */
  private Runnable powerUpSplashScreenRunnable = () -> {
    if (powerUpSplashScreenTimer != null)
    {
      powerUpSplashScreenTimer.safeCancel();

      // Display Blue screen and start its timer
      setTcmsCurrentScreen(ScreenId.BLANK_SCREEN);
      setCctvCurrentScreen(ScreenId.BLANK_SCREEN);
      if (!powerUpBlueScreenTimer.isRunning())
      {
        powerUpBlueScreenTimer.start();
      }
    }
  };

  /** Runnable to perform actions of start up sequence */
  private Runnable powerUpBlueScreenRunnable = () -> {
    if (powerUpBlueScreenTimer != null)
    {
      powerUpBlueScreenTimer.safeCancel();
      setTcmsCurrentScreen(ScreenId.STARTUP_SCREEN);
      setCctvCurrentScreen(ScreenId.STARTUP_SCREEN);
      if (!powerUpDataLoadingScreenTimer.isRunning())
      {
        powerUpDataLoadingScreenTimer.start();
      }
    }
  };

  private Runnable powerUpDataLoadingScreenRunnable = () -> {
    if (powerUpDataLoadingScreenTimer != null)
    {
      powerUpDataLoadingScreenTimer.safeCancel();
      setTcmsCurrentScreen(ScreenId.DATA_LOADING_SCREEN);
      setCctvCurrentScreen(ScreenId.DATA_LOADING_SCREEN);
      lastActionTime = Instant.now();
      messageFlag = true;
    }
  };

  public ScreenChangeHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsProperties.class,
        IVehicleProperties.class);

    this.commsBinding = commsBinding;
    shareDataModel = aShareDataModel;
    int splashScreenTime = Registry.getInstance().getInteger(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.SPLASH_SCREEN_TIME, 5000); // time in millisecond
    int blueScreenTime = Registry.getInstance().getInteger(ApplicationConstants.DOMAIN_NAME,
        ApplicationConstants.BLUE_SCREEN_TIME, 10000); // time in millisecond
    powerUpSplashScreenTimer = CommsTimer.newScheduledTimer(powerUpSplashScreenRunnable, splashScreenTime);
    powerUpBlueScreenTimer = CommsTimer.newScheduledTimer(powerUpBlueScreenRunnable, splashScreenTime);
    powerUpDataLoadingScreenTimer = CommsTimer.newScheduledTimer(powerUpDataLoadingScreenRunnable,
        blueScreenTime);

    this.lastActionTime = Instant.now();
    DateTimeModel.getInstance().addModelListener((oldValue, newValue) -> {
      updateDataLoadingMessageId();
    }, true);
  }

  private void updateDataLoadingMessageId()
  {
    Duration dur = Duration.between(lastActionTime, Instant.now());
    long seconds = dur.toMillis() / 1000L;

    if (seconds >= ApplicationConstants.TWO_SECOND && messageFlag)
    {
      if (messageId <= VDUDataCatagory.PROGRESS_7_MESSAGE.getValue())
      {
        setApplicationOutputsProperty(IAppOutputsDataLoadingProperties.DATA_LOADING_SEQUENCE,
            VDUDataCatagory.valueOf(messageId).getValue());
        lastActionTime = Instant.now();
        messageFlag = true;
        messageId++;
      }
      else
      {
        messageFlag = false;
        messageId = VDUDataCatagory.PROGRESS_1_MESSAGE.getValue();
        setTcmsCurrentScreen(ScreenId.LOGIN_PANEL);
        setCctvCurrentScreen(ScreenId.LOGIN_PANEL);
      }
    }
  }

  boolean isCCTVHanged = false;

  @Override
  public <T> void vehiclePropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, Integer vehicleIndex)
  {
    if (IVehicleProperties.FLT_CCTV_DISPLAY_HANGED.equals(key) && getActiveVehicleIndex() == vehicleIndex)
    {
      isCCTVHanged = ((Integer)newValue == cctvDisplayHanged);
      if (isCCTVHanged)
      {
        setApplicationOutputsProperty(IAppOutputsCCTVScreenProperties.CCTV_DISPLAY_HANGED_FAULT,
            cctvDisplayHanged);
      }
      else
      {
        setApplicationOutputsProperty(IAppOutputsCCTVScreenProperties.CCTV_DISPLAY_HANGED_FAULT,
            cctvDisplayNotHanged);
      }
    }
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (ITCMSVehicleOutputsProperties.HMI_POWER.equals(key))
    {
      setApplicationOutputsProperty(IAppOutputsVduSettingsPopupProperties.TCMS_BRIGHTNESS_BUTTON_SELECTED,
          VDUBrightnessModeEnum.BRIGHTNESS_AUTO.getId());
      setApplicationOutputsProperty(IAppOutputsVduSettingsPopupProperties.CCTV_BRIGHTNESS_BUTTON_SELECTED,
          VDUBrightnessModeEnum.BRIGHTNESS_AUTO.getId());
      if (Boolean.TRUE.equals(newValue))
      {
        if (!powerUpSplashScreenTimer.isRunning())
        {
          powerUpSplashScreenTimer.start();
        }
      }
      else
      {
        powerUpSplashScreenTimer.safeCancel();
        powerUpBlueScreenTimer.safeCancel();
        powerUpDataLoadingScreenTimer.safeCancel();
        setTcmsCurrentScreen(ScreenId.BLANK_SCREEN);
        setTcmsCurrentPopup(ScreenId.BLANK_SCREEN);
        setCctvCurrentScreen(ScreenId.BLANK_SCREEN);
        setCctvCurrentPopup(ScreenId.BLANK_SCREEN);
        setApplicationOutputsProperty(IAppOutputsDataLoadingProperties.DATA_LOADING_SEQUENCE,
            VDUDataCatagory.PROGRESS_1_MESSAGE.getValue());
        setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.LOGIN_INFO_TITLE,
            HeaderPanelTitleEnum.EMPTY.getValue());
        setApplicationOutputsProperty(IAppOutputsLoginPopupProperties.USER_LOGGED_IN, 0);
      }
    }
    else if (ITCMSVehicleOutputsOperationScreenProperties.CAB_ACTIVE.equals(key) && (Integer)newValue == 1)
    {
      shareDataModel.setCurrentActiveCabId(vehicleIndex);
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
    setTcmsCurrentScreen(ScreenId.BLANK_SCREEN);
    setCctvCurrentScreen(ScreenId.BLANK_SCREEN);
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

  void processTcmsScreenChangeRequest(int screenChangeRequest)
  {
    if (screenChangeRequest > 0)
    {
      ScreenId request = ScreenId.valueOf(screenChangeRequest);
      setTcmsCurrentScreen(request);
    }
  }

  void processCctvScreenChangeRequest(int screenChangeRequest)
  {
    if (screenChangeRequest > 0)
    {
      ScreenId request = ScreenId.valueOf(screenChangeRequest);
      setCctvCurrentScreen(request);
    }
  }

  void processTcmsPopupChangeRequest(int popupChangeRequest)
  {
    if (popupChangeRequest > -1)
    {
      ScreenId request = ScreenId.valueOf(popupChangeRequest);
      setTcmsCurrentPopup(request);
    }
  }

  void processCctvPopupChangeRequest(int popupChangeRequest)
  {
    if (popupChangeRequest > -1)
    {
      ScreenId request = ScreenId.valueOf(popupChangeRequest);
      setCctvCurrentPopup(request);
    }
  }

  protected void setTcmsCurrentScreen(ScreenId request)
  {
    ScreenId newScreen = request;

    notifyTcmsScreenChange(newScreen);

    initializeOutputHandler();

    updateTcmsCurrentScreen(currentTcmsScreen.getId());

    shareDataModel.setTcmsScreenId(currentTcmsScreen.getId());
  }

  protected void setCctvCurrentScreen(ScreenId request)
  {
    ScreenId newScreen = request;

    notifyCctvScreenChange(newScreen);

    initializeOutputHandler();

    updateCctvCurrentScreen(currentCctvScreen.getId());

    shareDataModel.setCctvScreenId(currentCctvScreen.getId());
  }

  protected void setTcmsCurrentPopup(ScreenId request)
  {
    ScreenId newPopup = request;

    notifyTcmsPopupChange(newPopup);

    initializeOutputHandler();

    updateTcmsCurrentPopup(currentTcmsPopup.getId());

    shareDataModel.setTcmsPopupId(currentTcmsPopup.getId());
  }

  protected void setCctvCurrentPopup(ScreenId request)
  {
    ScreenId newPopup = request;

    notifyCctvPopupChange(newPopup);

    initializeOutputHandler();

    updateCctvCurrentPopup(currentCctvPopup.getId());

    shareDataModel.setCctvPopupId(currentCctvPopup.getId());
  }

  private void updateTcmsCurrentScreen(int screenId)
  {
    if (appOutputsHandler != null)
    {
      appOutputsHandler.setTcmsCurrentScreenId(screenId);
    }
  }

  private void updateCctvCurrentScreen(int screenId)
  {
    if (appOutputsHandler != null)
    {
      appOutputsHandler.setCctvCurrentScreenId(screenId);
    }
  }

  private void updateTcmsCurrentPopup(int popupId)
  {
    if (appOutputsHandler != null)
    {
      appOutputsHandler.setTcmsPopupScreenId(popupId);
    }
  }

  private void updateCctvCurrentPopup(int popupId)
  {
    if (appOutputsHandler != null)
    {
      appOutputsHandler.setCctvPopupScreenId(popupId);
    }
  }

  private void notifyTcmsScreenChange(ScreenId newScreen)
  {
    if (currentTcmsScreen != newScreen)
    {
      notifyLeaving(currentTcmsScreen);
      currentTcmsScreen = newScreen;
      notifyEntering(currentTcmsScreen);
    }
  }

  private void notifyCctvScreenChange(ScreenId newScreen)
  {
    if (currentCctvScreen != newScreen)
    {
      notifyLeaving(currentCctvScreen);
      currentCctvScreen = newScreen;
      notifyEntering(currentCctvScreen);
    }
  }

  private void notifyTcmsPopupChange(ScreenId newPopup)
  {
    if (currentTcmsPopup != newPopup)
    {
      currentTcmsPopup = newPopup;
    }
  }

  private void notifyCctvPopupChange(ScreenId newPopup)
  {
    if (currentCctvPopup != newPopup)
    {
      currentCctvPopup = newPopup;
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      initializeOutputHandler();

      if (key.equals(IAppInputsScreenChangeProperties.TCMS_SCREEN_CHANGE_REQUEST) && (Integer)newValue > -1)
      {
        processTcmsScreenChangeRequest((Integer)newValue);
      }
      else if (key.equals(IAppInputsScreenChangeProperties.TCMS_POPUP_CHANGE_REQUEST)
          && (Integer)newValue > -1)
      {
        processTcmsPopupChangeRequest((Integer)newValue);
        if (shareDataModel.getVduSelectedMode() == VDUModeEnum.VDU_HYBRID_MODE.getId()
            && ScreenId.valueOf((Integer)newValue).equals(ScreenId.BLANK_SCREEN)
            && ScreenId.CCTV_HYBRID_MODE_COMMON_SCREEN.getId() != (Integer)newValue)
        {
          sendPulseRequest(appOutputsHandler, IAppOutputsScreenChangeProperties.TCMS_POPUP_SCREEN_ID, 0,
              ScreenId.CCTV_HYBRID_MODE_COMMON_SCREEN.getId());
        }
      }
      else if (key.equals(IAppInputsScreenChangeProperties.CCTV_SCREEN_CHANGE_REQUEST)
          && (Integer)newValue > -1 && !isCCTVHanged)
      {
        processCctvScreenChangeRequest((Integer)newValue);
      }
      else if (key.equals(IAppInputsScreenChangeProperties.CCTV_POPUP_CHANGE_REQUEST)
          && (Integer)newValue > -1 && !isCCTVHanged)
      {
        processCctvPopupChangeRequest((Integer)newValue);
        if (shareDataModel.getCctvVduSelectedMode() == VDUModeEnum.VDU_HYBRID_MODE.getId()
            && ScreenId.valueOf((Integer)newValue).equals(ScreenId.BLANK_SCREEN)
            && ScreenId.CCTV_HYBRID_MODE_COMMON_SCREEN.getId() != (Integer)newValue)
        {
          sendPulseRequest(appOutputsHandler, IAppOutputsScreenChangeProperties.CCTV_POPUP_SCREEN_ID, 0,
              ScreenId.CCTV_HYBRID_MODE_COMMON_SCREEN.getId());
        }
      }
    }
  }

  @Override
  public void requestScreenChange(ScreenId newScreenId)
  {
    processTcmsScreenChangeRequest(newScreenId.getId());
  }

  private void initializeOutputHandler()
  {
    if (appOutputsHandler == null)
    {
      appOutputsHandler = (IAppOutputsHandler)commsBinding.getAppOutputsSetter();
    }
  }
}