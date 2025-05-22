/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.app;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.app.AbstractApplication;
import com.sydac.mmrbem.cabscreens.fe.base.ApplicationFactory;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendSceneManager;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsVduSettingsPopupProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.base.CommsListenerManager;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.base.impl.FxFrontendSceneManagerImpl;
import com.sydac.mmrbem.tcms.fe.common.Frontend;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

/**
 * {@link Application} extension and entry point for TCMS application.
 * 
 */
public class TCMSApplication extends AbstractApplication
{

  /**
   * Start the TMS application by launching it and creating a {@link Stage}
   * 
   * @param xpos
   *          x position
   * @param ypos
   *          y position
   * @param width
   *          width
   * @param height
   *          height
   * @param sceneManager
   *          {@link IFxFrontendSceneManager}
   */
  public static final void startApplication(int xpos, int ypos, int width, int height,
      IFxFrontendSceneManager sceneManager)
  {
    TCMSApplication.xpos = xpos;
    TCMSApplication.ypos = ypos;
    TCMSApplication.width = width;
    TCMSApplication.height = height;
    TCMSApplication.sceneManager = sceneManager;

    if (!applicationInitiated.getAndSet(true))
    {
      Platform.setImplicitExit(false);
      Application.launch(TCMSApplication.class, new String[] {});
    }
  }

  /**
   * Show the TMS application
   * 
   * @param carIndex
   *          carIndex
   * @param frontend
   *          frontend
   */
  public static final void showApplication(final int carIndex, final Frontend frontend)
  {
    waitForInitialization();
    SCENE_MAP.clear();

    // Once initialization is complete, put the scenarioCarIndex property onto
    // the stage for later use and show the application.
    Platform.runLater(() -> {
      // TCMS Width and Height as given on TCMSFrontendApplicationManager
      sceneManager.setSize(TCMSApplication.width, TCMSApplication.height);
      applicationStage.setTitle(frontend.name()); // $NON-NLS-1$
      applicationStage.getProperties().put(ApplicationFactory.SCENARIO_CAR_INDEX, carIndex);
      CONTROLLER_FACTORY.setScenarioCarIndex(carIndex);
      CONTROLLER_FACTORY.setFrontend(frontend);
      applicationStage.show();
    });
    brightness.brightnessProperty().bind(brightnessValue);
    ScreenChangeListener screenChangeListener = new ScreenChangeListener(carIndex, frontend);
    screenChangeListener.attachToModel(TCMSFactory.getCommsBinding(carIndex));
    CommsListenerManager.addListener(carIndex, screenChangeListener);
  }

  @Override
  public void setApplicationTransparentStyle()
  {
    TCMSApplication.applicationStage.initStyle(StageStyle.TRANSPARENT);
  }

  static class ScreenChangeListener extends AbstractCommsListener
  {
    public ScreenChangeListener(int carIndex, Frontend frontend)
    {
      setScenarioCarIndex(carIndex);
      setFrontend(frontend);
      propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);
      propertyKeyDefinitions.add(IAppOutputsVduSettingsPopupProperties.class);
    }

    @Override
    protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
    {
      if (frontend == Frontend.TCMS)
      {

        if (key == IAppOutputsScreenChangeProperties.TCMS_CURRENT_SCREEN_ID)
        {
          int screenId = (Integer)newValue;
          String screenName = ScreenId.valueOf(screenId).getScreenName();

          Platform.runLater(() -> setScene(scenarioCarIndex, screenName));
          // Add timer logic to observe inactivity
        }
        else if (key == IAppOutputsScreenChangeProperties.TCMS_POPUP_SCREEN_ID)
        {
          Platform.runLater(() -> {
            int popUpScreenId = (Integer)newValue;
            if (popUpScreenId == 0)
            {
              popUpStage.hide();
            }
            else
            {
              String screenName = ScreenId.valueOf(popUpScreenId).getScreenName();
              setPopUpScene(scenarioCarIndex, screenName);
              popUpStage.show();
            }
          });

          // Add timer logic to observe inactivity
        }
        else if (key == IAppOutputsVduSettingsPopupProperties.TCMS_BRIGHTNESS_BUTTON_SELECTED)
        {
          brightnessValue.set(((Integer)newValue - (double)ApplicationConstants.BRIGHTNESS_MAX_VALUE) / 10);
          FxFrontendSceneManagerImpl.updateBrightness((Integer)newValue);
        }
      }
      else if (frontend == Frontend.CCTV)
      {
        if (key == IAppOutputsScreenChangeProperties.CCTV_CURRENT_SCREEN_ID)
        {
          int screenId = (Integer)newValue;
          String screenName = ScreenId.valueOf(screenId).getScreenName();

          Platform.runLater(() -> setScene(scenarioCarIndex, screenName));
          // Add timer logic to observe inactivity
        }
        else if (key == IAppOutputsScreenChangeProperties.CCTV_POPUP_SCREEN_ID)
        {
          Platform.runLater(() -> {
            int popUpScreenId = (Integer)newValue;
            if (popUpScreenId == 0)
            {
              popUpStage.hide();
            }
            else
            {
              String screenName = ScreenId.valueOf(popUpScreenId).getScreenName();
              setPopUpScene(scenarioCarIndex, screenName);
              popUpStage.show();
            }
          });

          // Add timer logic to observe inactivity
        }
        else if (key == IAppOutputsVduSettingsPopupProperties.CCTV_BRIGHTNESS_BUTTON_SELECTED)
        {
          brightnessValue.set(((Integer)newValue - (double)ApplicationConstants.BRIGHTNESS_MAX_VALUE) / 10);
          FxFrontendSceneManagerImpl.updateBrightness((Integer)newValue);
        }
      }
    }
  }
}