/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.app;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.app.AbstractApplication;
import com.sydac.mmrbem.cabscreens.fe.base.ApplicationFactory;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendSceneManager;
import com.sydac.mmrbem.dmi.common.ScreenId;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsMainScreenSettingsProperties;
import com.sydac.mmrbem.dmi.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.base.CommsListenerManager;
import com.sydac.mmrbem.dmi.fe.base.DMIFactory;
import com.sydac.mmrbem.dmi.fe.base.impl.FxFrontendSceneManagerImpl;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;

/**
 * {@link Application} extension and entry point for DMI application.
 * 
 */
public class DMIApplication extends AbstractApplication
{

  public static Double CURRENT_APP_WIDTH = 1024.0;// $NON-NLS-1$

  public static Double CURRENT_APP_HEIGHT = 768.0;// $NON-NLS-1$

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
  public static final void startApplication(int xpos, int ypos, Integer width, Integer height,
      IFxFrontendSceneManager sceneManager)
  {
    DMIApplication.xpos = xpos;
    DMIApplication.ypos = ypos;
    DMIApplication.width = width;
    DMIApplication.height = height;
    DMIApplication.sceneManager = sceneManager;

        
    DMIApplication.CURRENT_APP_HEIGHT = height.doubleValue();
    DMIApplication.CURRENT_APP_WIDTH = width.doubleValue();

    AbstractDMIController.calculateScaleFactor();

    if (!applicationInitiated.getAndSet(true))
    {
      Platform.setImplicitExit(false);
      Application.launch(DMIApplication.class, new String[] {});
    }
  }

  /**
   * Show the TMS application
   * 
   * @param carIndex
   *          carIndex
   * @param dbScenarioTrain
   *          dbScenarioTrain
   */
  public static final void showApplication(final int carIndex, DBScenarioTrain dbScenarioTrain)
  {
    waitForInitialization();
    SCENE_MAP.clear();

    // Once initialization is complete, put the scenarioCarIndex property onto
    // the stage for later use and show the application.
    Platform.runLater(() -> {
      sceneManager.setSize(DMIApplication.width,DMIApplication.height);
      applicationStage.setTitle(ApplicationConstants.APP_NAME); // $NON-NLS-1$
      applicationStage.getProperties().put(ApplicationFactory.SCENARIO_CAR_INDEX, carIndex);
      CONTROLLER_FACTORY.setScenarioCarIndex(carIndex);
      // TrainConfigurationController.getTrainConfigurationModelInstance(carIndex);
      applicationStage.show();
    });
    brightness.brightnessProperty().bind(brightnessValue);
    ScreenChangeListener screenChangeListener = new ScreenChangeListener(carIndex);
    screenChangeListener.attachToModel(DMIFactory.getCommsBinding(carIndex));
    CommsListenerManager.addListener(carIndex, screenChangeListener);
  }

  @Override
  public void setApplicationTransparentStyle()
  {
    // Do nothing
  }

  static class ScreenChangeListener extends AbstractCommsListener
  {
    public ScreenChangeListener(int carIndex)
    {
      setScenarioCarIndex(carIndex);
      propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);
      propertyKeyDefinitions.add(IAppOutputsMainScreenSettingsProperties.class);
    }

    @Override
    protected <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
    {
      if (key == IAppOutputsScreenChangeProperties.CURRENT_SCREEN_ID)
      {
        CONTROLLER_FACTORY.setIsTenCar(true);
        String screenName = ScreenId.valueOf((Integer)newValue).getScreenName();

        Platform.runLater(() -> setScene(scenarioCarIndex, screenName));
      }
      else if (key == IAppOutputsMainScreenSettingsProperties.SELECTED_BRIGHTNESS_VALUE)
      {
        brightnessValue.set(((Integer)newValue - (double)ApplicationConstants.BRIGHTNESS_MAX_VALUE) / 10);
        FxFrontendSceneManagerImpl.updateBrightness((Integer)newValue);
      }
    }
  }

}