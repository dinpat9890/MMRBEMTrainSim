/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.psd.fe.app;

import com.sydac.common.registry.Registry;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.app.AbstractApplication;
import com.sydac.mmrbem.cabscreens.fe.base.ApplicationFactory;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendSceneManager;
import com.sydac.mmrbem.psd.common.ScreenId;
import com.sydac.mmrbem.psd.common.data.ApplicationConstants;
import com.sydac.mmrbem.psd.common.data.PlatformSide;
import com.sydac.mmrbem.psd.common.io.properties.IAppOutputsPSDProperties;
import com.sydac.mmrbem.psd.common.io.properties.IAppOutputsScreenChangeProperties;
import com.sydac.mmrbem.psd.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.psd.fe.base.CommsListenerManager;
import com.sydac.mmrbem.psd.fe.base.PSDFactory;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

/**
 * {@link Application} extension and entry point for TCMS application.
 * 
 */
public class PSDApplication extends AbstractApplication
{
  private static final Registry INSTANCE = Registry.getInstance();

  private static final boolean IS_FSTDS_MODE = INSTANCE.getBoolean(ApplicationConstants.DOMAIN_NAME,
      "isfstdsmode", true);

  private static final int PLATFORM_SIDE = INSTANCE.getInteger(ApplicationConstants.DOMAIN_NAME,
      "platformside", 1);

  static int trainDocked = 0;

  static int platform = 0;
  private static final int rightXPos = INSTANCE.getInteger(ApplicationConstants.DOMAIN_NAME,
      "rightXPosition", 0);
  private static final int rightYPos = INSTANCE.getInteger(ApplicationConstants.DOMAIN_NAME,
      "rightYPosition", 0);
  private static final boolean ALWAYS_ON_TOP = Registry.getInstance().getBoolean("gui", "alwaysontop", false); //$NON-NLS-1$ //$NON-NLS-2$
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
    PSDApplication.xpos = xpos;
    PSDApplication.ypos = ypos;
    PSDApplication.width = width;
    PSDApplication.height = height;
    PSDApplication.sceneManager = sceneManager;

    // System.out.println("PSDApplication.startApplication()"+
    // PSDApplication.xpos);
    if (!applicationInitiated.getAndSet(true))
    {
      Platform.setImplicitExit(false);
      Application.launch(PSDApplication.class, new String[] {});
    }
  }

  /**
   * Show the TMS application
   * 
   * @param carIndex
   *          carIndex
   */
  public static final void showApplication(final int carIndex)
  {
    waitForInitialization();
    SCENE_MAP.clear();

    // Once initialization is complete, put the scenarioCarIndex property onto
    // the stage for later use and show the application.
    Platform.runLater(() -> {
      sceneManager.setSize(PSDApplication.width,PSDApplication.height);
      applicationStage.setTitle(ApplicationConstants.PSD_APP_NAME); // $NON-NLS-1$
      applicationStage.getProperties().put(ApplicationFactory.SCENARIO_CAR_INDEX, carIndex);
   
      CONTROLLER_FACTORY.setScenarioCarIndex(carIndex);
      // CONTROLLER_FACTORY.setFrontend(frontend);
      applicationStage.show();
    });
    brightness.brightnessProperty().bind(brightnessValue);
    ScreenChangeListener screenChangeListener = new ScreenChangeListener(carIndex);
    screenChangeListener.attachToModel(PSDFactory.getCommsBinding(carIndex));
    CommsListenerManager.addListener(carIndex, screenChangeListener);

    applicationStage.setAlwaysOnTop(ALWAYS_ON_TOP);
  }

  @Override
  public void setApplicationTransparentStyle()
  {
    PSDApplication.applicationStage.initStyle(StageStyle.TRANSPARENT);
  }

  static class ScreenChangeListener extends AbstractCommsListener
  {
    public ScreenChangeListener(int carIndex)
    {
      setScenarioCarIndex(carIndex);

      propertyKeyDefinitions.add(IAppOutputsScreenChangeProperties.class);
      propertyKeyDefinitions.add(IAppOutputsPSDProperties.class);

    }

    @Override
    protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
    {

      if (key == IAppOutputsScreenChangeProperties.PSD_SCREEN_ID)
      {
        int screenId = (Integer)newValue;
        String screenName = ScreenId.valueOf(screenId).getScreenName();

        Platform.runLater(() -> setScene(scenarioCarIndex, screenName));

      }
      else if (key == IAppOutputsPSDProperties.TRAIN_DOCKING_STATUS)
      {
        trainDocked = (Integer)newValue;

        Platform.runLater(() -> {
          if (trainDocked == ApplicationConstants.CORRECTLY_DOCKED) // CORRECTLY_DOCKED(1),
          {

            checkType();
            // applicationStage.show();
          }
          else
          {
            applicationStage.hide();
          }
        });
      }
      else if (key == IAppOutputsPSDProperties.PLATFORM_SIDE)
      {
        platform = (Integer)newValue;
        Platform.runLater(() -> {

          checkType();

        });
      }
    }

    private void checkType()
    {
      if (IS_FSTDS_MODE)
      {

        loadApplication(platform);
      }
      else
      {

        loadDswApplication(platform);
      }
    }

    private void loadApplication(int platformSide)
    {
      
      if (trainDocked == 1)
      {
        if (platformSide == PlatformSide.RIGHT.getValue())
        {
          PSDApplication.applicationStage.setX(rightXPos);
          PSDApplication.applicationStage.setY(rightYPos);
          
          // applicationStage.show();
        }
        else if (platformSide == PlatformSide.LEFT.getValue())
        {
          PSDApplication.applicationStage.setX(PSDApplication.xpos);
          // applicationStage.show();
        }
      
        applicationStage.show();
       
      }
    }

    private void loadDswApplication(int side)
    {
      if (trainDocked == 1)
      {
        if (side == PLATFORM_SIDE)
        {

          PSDApplication.applicationStage.setX(PSDApplication.xpos);
          applicationStage.show();
        }
        else
        {

          applicationStage.hide();
        }
        setNamesForDSW(side);
      }
    }

    private static void setNamesForDSW(int platformSide)
    {
      if (platformSide == PlatformSide.RIGHT.getValue())
      {
        applicationStage.setTitle(ApplicationConstants.RIGHT_PSD_APP_NAME); 
      }
      else if (platformSide == PlatformSide.LEFT.getValue())
      {    
        applicationStage.setTitle(ApplicationConstants.LEFT_PSD_APP_NAME); 
      }

    }  
    
  }

  
}