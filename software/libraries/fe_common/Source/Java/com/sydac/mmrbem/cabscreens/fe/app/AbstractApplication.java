/*
 * ==================================================================
 *
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.app;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.atomic.AtomicBoolean;

import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendSceneManager;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.event.EventHandler;
import javafx.scene.Cursor;
import javafx.scene.Scene;
import javafx.scene.effect.ColorAdjust;
import javafx.scene.input.InputEvent;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

/**
 * {@link Application} extension and entry point for the application.
 *
 * @author ext-vp
 */
public abstract class AbstractApplication extends Application
{
  private static final CountDownLatch latch = new CountDownLatch(1);

  protected static final ApplicationControllerFactory CONTROLLER_FACTORY = new ApplicationControllerFactory();

  protected static final AtomicBoolean applicationInitiated = new AtomicBoolean(false);

  protected static final AtomicBoolean popUpInitiated = new AtomicBoolean(false);

  protected static final Map<String, Scene> SCENE_MAP = new HashMap<>();

  protected static final Map<String, Scene> POPUP_SCENE_MAP = new HashMap<>();

  private static String currentScreenName = null;

  private static String currentPopUpScreenName = null;

  private static EventHandler<InputEvent> inputEventConsumer = AbstractApplication::consumeEvent;

  private static boolean hideMouse = false;

  protected static Stage applicationStage;

  protected static Stage popUpStage;

  protected static ColorAdjust brightness = new ColorAdjust();

  protected static DoubleProperty brightnessValue = new SimpleDoubleProperty();

  protected static IFxFrontendSceneManager sceneManager;

  public static int xpos;

  public static int ypos;

  protected static int width;

  protected static int height;

  public static final void pauseApplication(boolean pause)
  {
    waitForInitialization();

    if (applicationStage != null)
    {
      if (pause && !applicationInitiated.getAndSet(true))
      {
        applicationStage.addEventFilter(InputEvent.ANY, inputEventConsumer);
      }
      else
      {
        applicationStage.removeEventFilter(InputEvent.ANY, inputEventConsumer);
        applicationInitiated.set(false);
      }
    }

    if (popUpStage != null)
    {
      if (pause && !popUpInitiated.getAndSet(true))
      {
        popUpStage.addEventFilter(InputEvent.ANY, inputEventConsumer);
      }
      else
      {
        popUpStage.removeEventFilter(InputEvent.ANY, inputEventConsumer);
        popUpInitiated.set(false);
      }
    }
  }

  protected static void setScene(int carIndex, String screenName)
  {
    if (!screenName.equals(currentScreenName))
    {
      currentScreenName = screenName;

      // Set the scene onto the stage
      Scene scene;

      if (SCENE_MAP.containsKey(screenName))
      {
        // re-use already created scene
        scene = SCENE_MAP.get(screenName);
      }
      else
      {
        scene = sceneManager.createScene(screenName, carIndex, CONTROLLER_FACTORY);
        SCENE_MAP.put(screenName, scene);
      }

      if (scene != null && scene.getRoot().getEffect() != brightness)
      {
        scene.getRoot().setEffect(brightness);

        if (hideMouse)
        {
          scene.setCursor(Cursor.NONE);
        }
      }

      AbstractApplication.applicationStage.setScene(scene);
    }
  }

  protected static void setPopUpScene(int carIndex, String screenName)
  {
    if (!screenName.equals(currentPopUpScreenName))
    {
      currentPopUpScreenName = screenName;

      // Set the scene onto the stage
      Scene popUpScene;

      if (POPUP_SCENE_MAP.containsKey(screenName))
      {
        // re-use already created scene
        popUpScene = POPUP_SCENE_MAP.get(screenName);
      }
      else
      {
        popUpScene = sceneManager.createScene(screenName, carIndex, CONTROLLER_FACTORY);
        POPUP_SCENE_MAP.put(screenName, popUpScene);
      }

      if (popUpScene != null && popUpScene.getRoot().getEffect() != brightness)
      {
        popUpScene.getRoot().setEffect(brightness);

        if (hideMouse)
        {
          popUpScene.setCursor(Cursor.NONE);
        }
      }

      AbstractApplication.popUpStage.setScene(popUpScene);
    }
  }

  /*
   * Wait till initialization is complete
   */
  public static void waitForInitialization()
  {
    try
    {
      latch.await();
    }
    catch (InterruptedException e)
    {
      Thread.currentThread().interrupt();
    }
  }

  /**
   * Hide the application
   *
   */
  public static final void hideApplication()
  {
    Platform.runLater(() -> {
      SCENE_MAP.clear();
      POPUP_SCENE_MAP.clear();
      currentScreenName = null;
      currentPopUpScreenName = null;
      applicationStage.setScene(null);
      popUpStage.setScene(null);
      applicationStage.hide();
      popUpStage.hide();
    });
    applicationInitiated.set(false);
    popUpInitiated.set(false);
  }

  /*
   * (non-Javadoc)
   *
   * @see javafx.application.Application#start(javafx.stage.Stage)
   */
  @Override
  public void start(Stage primaryStage) throws Exception
  {
    prepApplicationStage(primaryStage);
    setApplicationTransparentStyle();
    latch.countDown();
  }

  /*
   * Prepare the javafx.stage.Stage for the application
   *
   * @param stage
   */
  private static final void prepApplicationStage(Stage stage)
  {
    applicationStage = stage;
    applicationStage.setX(xpos);
    applicationStage.setY(ypos);
    applicationStage.setHeight(height);
    applicationStage.setWidth(width);
    applicationStage.initStyle(StageStyle.UNDECORATED);

    popUpStage = new Stage();
    popUpStage.setX(xpos);
    popUpStage.setY(ypos);
    popUpStage.initStyle(StageStyle.TRANSPARENT);
    popUpStage.initOwner(applicationStage);

  }

  /**
   * Set application state {@link StageStyle#TRANSPARENT} if application
   * background need to be transparent
   */
  public abstract void setApplicationTransparentStyle();

  public static void setHideMouse(boolean aHideMouse)
  {
    hideMouse = aHideMouse;
  }

  static final void consumeEvent(InputEvent event)
  {
    event.consume();
  }
}