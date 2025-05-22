/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.fe.app;

import com.sydac.common.dataobjects.DBScenarioTrain;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.app.AbstractApplication;
import com.sydac.mmrbem.cabscreens.fe.base.ApplicationFactory;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendSceneManager;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.papis.fe.base.CommsListenerManager;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

/**
 * {@link Application} extension and entry point for TCMS application.
 * 
 */
public class PAPISApplication extends AbstractApplication
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
    PAPISApplication.xpos = xpos;
    PAPISApplication.ypos = ypos;
    PAPISApplication.width = width;
    PAPISApplication.height = height;
    PAPISApplication.sceneManager = sceneManager;

    if (!applicationInitiated.getAndSet(true))
    {
      Platform.setImplicitExit(false);
      Application.launch(PAPISApplication.class, new String[] {});
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
      sceneManager.setSize(PAPISApplication.width,PAPISApplication.height);
      applicationStage.setTitle(ApplicationConstants.APP_NAME); // $NON-NLS-1$
      applicationStage.getProperties().put(ApplicationFactory.SCENARIO_CAR_INDEX, carIndex);
      CONTROLLER_FACTORY.setScenarioCarIndex(carIndex);
      // TrainConfigurationController.getTrainConfigurationModelInstance(carIndex);
      applicationStage.show();
    });

    ScreenChangeListener screenChangeListener = new ScreenChangeListener(carIndex);
    screenChangeListener.attachToModel(PAPISFactory.getCommsBinding(carIndex));
    CommsListenerManager.addListener(carIndex, screenChangeListener);
  }

  @Override
  public void setApplicationTransparentStyle()
  {
    PAPISApplication.applicationStage.initStyle(StageStyle.TRANSPARENT);
  }

  static class ScreenChangeListener extends AbstractCommsListener
  {
    public ScreenChangeListener(int carIndex)
    {
      setScenarioCarIndex(carIndex);
      propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);

    }

    @Override
    protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
    {
      if (key == IAppOutputsScreenChangeProperties.CURRENT_SCREEN_ID)
      {
        int screenId = (Integer)newValue;
        String screenName = ScreenId.valueOf(screenId).getScreenName();

        Platform.runLater(() -> setScene(scenarioCarIndex, screenName));
        // Add timer logic to observe inactivity
      }

    }

  }
}