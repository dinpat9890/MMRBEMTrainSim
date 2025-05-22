/*
 * ==================================================================
 *
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.cabscreens.fe.base;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.app.ApplicationControllerFactory;

import javafx.embed.swing.JFXPanel;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.input.InputEvent;

/**
 * extension of {@link JFXPanel} This handles the changing of the scene on the
 * Panel, creating it if necessary
 *
 * @author John Bailey
 */
@SuppressWarnings("serial")
public class FrontendJFXPanel extends JFXPanel
{
  private final transient Map<String, Scene> sceneMap = new HashMap<>();

  private static EventHandler<InputEvent> inputEventConsumer = InputEvent::consume;

  private transient IFxFrontendSceneManager sceneManager;

  private final transient ApplicationControllerFactory controllerFactory = new ApplicationControllerFactory();

  public FrontendJFXPanel()
  {
    // Empty Constructor
  }

  /**
   * Changes the scene on the panel, it stores a copy of each scene as they are
   * created, and references these, rather than recreating a scene we are
   * revisiting
   *
   * @param screenName
   *          The name of the screen we are wanting to load
   * @param carIndex
   *          The car that we are interested in.
   * @param sceneManager
   *          The concrete implementation of the sceneManager
   * @return {@link Scene} The new scene
   */
  public Scene changeScene(String screenName, int carIndex, IFxFrontendSceneManager sceneManager)
  {
    this.sceneManager = sceneManager;
    controllerFactory.setScenarioCarIndex(carIndex);
    Scene scene;

    if (sceneMap.containsKey(screenName))
    {
      // re-use already created scene
      scene = sceneMap.get(screenName);
    }
    else
    {
      scene = sceneManager.createScene(screenName, carIndex, controllerFactory);

      // Hold on to it for reuse on next request
      sceneMap.put(screenName, scene);
    }

    setScene(scene);

    return scene;
  }

  public final void clearScenes()
  {
    sceneMap.clear();
  }

  public void pause(boolean pause)
  {
    if (getScene() != null)
    {
      if (pause)
      {
        getScene().addEventFilter(InputEvent.ANY, inputEventConsumer);
      }
      else
      {
        getScene().removeEventFilter(InputEvent.ANY, inputEventConsumer);
      }
    }
  }

  public void reset(int carIndex)
  {
    if (null != sceneManager)
    {
      sceneManager.reset(carIndex);
    }
  }
  
}
