/*
 * ==================================================================
 * 
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 * 
 */
package com.sydac.mmrbem.tcms.fe.base.impl;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.sydac.common.log.Tracer;
import com.sydac.gui.Backgrounds;
import com.sydac.mmrbem.cabscreens.fe.app.ApplicationControllerFactory;
import com.sydac.mmrbem.cabscreens.fe.base.ApplicationFactory;
import com.sydac.mmrbem.cabscreens.fe.base.IFxFrontendSceneManager;
import com.sydac.mmrbem.cabscreens.fe.gui.AbstractController;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.DoubleProperty;
import javafx.beans.property.SimpleDoubleProperty;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.effect.ColorAdjust;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.Region;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;

/**
 * Implementation of {@link FxFrontendSceneManagerImpl} Sets up the scene
 * correctly for TCMS
 *
 * @author ext-vp
 */
public class FxFrontendSceneManagerImpl implements IFxFrontendSceneManager
{
  private static final String FXML_EXT = ".fxml"; //$NON-NLS-1$

  private static final String OUTER_PANEL_XML = "CommonScreen.fxml"; //$NON-NLS-1$

  private Map<Integer, List<AbstractController>> controllerMap = new HashMap<>();

  private static ColorAdjust brightness = new ColorAdjust();

  private static DoubleProperty brightnessValue = new SimpleDoubleProperty();

  // Default TCMS Height
  private int orignalHeight = 768;

  // Default TCMS Width
  private int orignalWidth = 1024;

  // TCMS Width as on Properties file
  private double appWidth;

  // TCMS Height as on Properties file
  private double appHeight;

  /**
   * Creates Scene for the Application
   *
   * The screen is made resize able by adding the existing Grid Pane/Pane/Parent
   * by adding them into a proper Region (StackPane). The Stack Pane will hold
   * all the fxml's and will be set with updated pref width and height. The
   * Scaling logic is also included in setScale method.
   *
   */
  @Override
  public Scene createScene(String screenName, int carIndex, ApplicationControllerFactory controllerFactory)
  {
    Scene scene = null;
    try
    {
      // Create pane from the FXML
      FXMLLoader loader;
      Parent parent;

      if (!ScreenId.isFullScreen(screenName))
      {
        Pane pane = FXMLLoader.load(ViewPackage.class.getResource(screenName + FXML_EXT), null, null,
            controllerFactory);
        URL url = ViewPackage.class.getResource(OUTER_PANEL_XML);
        loader = new FXMLLoader(getClass().getResource(OUTER_PANEL_XML), null, null, controllerFactory);
        loader.setLocation(url);
        GridPane outerPanelGridPane = (GridPane)loader.load();
        outerPanelGridPane.add(pane, 0, 1);
        pane.setEffect(brightness);
        outerPanelGridPane.setEffect(brightness);
        StackPane rootPane = createRootStackPane();
        rootPane.getChildren().add(outerPanelGridPane);
        setScale(orignalWidth, orignalHeight, rootPane);
        rootPane.setEffect(brightness);
        scene = new Scene(rootPane);
      }
      else
      {
        loader = new FXMLLoader(ViewPackage.class.getResource(screenName + FXML_EXT), null, null,
            controllerFactory);
        parent = loader.load();
        parent.setEffect(brightness);
        StackPane fullScreenRootPane = createRootStackPane();
        fullScreenRootPane.setStyle("-fx-background-color: Transparent"); //$NON-NLS-1$
        fullScreenRootPane.getChildren().add(parent);
        setScale(orignalWidth, orignalHeight, fullScreenRootPane);
        scene = new Scene(fullScreenRootPane, Color.TRANSPARENT);
      }

      brightness.brightnessProperty().bind(brightnessValue);

      // Fetch the 'scenarioCarIndex' from stage and put onto the scene
      scene.getProperties().put(ApplicationFactory.SCENARIO_CAR_INDEX, carIndex);

      // Adding the controllers based on car index.
      List<AbstractController> controllers = controllerMap.computeIfAbsent(carIndex, k -> new ArrayList<>());
      controllers.add(loader.getController());
    }
    catch (IOException e)
    {
      Tracer.getInstance().error(e);
    }

    return scene;
  }

  /**
   * Update brightness of application.
   *
   * @param value
   *          the value
   */
  public static void updateBrightness(int value)
  {
    brightnessValue.set((value - (double)ApplicationConstants.BRIGHTNESS_MAX_VALUE) / 10);
  }

  @Override
  public void reset(int carIndex)
  {
    controllerMap.computeIfPresent(carIndex, (k, v) -> {
      v.forEach(aController -> {
        if (null != aController)
        {
          aController.removeListeners();
        }
      });
      return null;
    });
  }

  /**
   * This method is responsible for setting the StackPane properties which
   * mainly depends on the TCMS width and height given in properties file.
   */
  private StackPane createRootStackPane()
  {
    StackPane pane = new StackPane();

    pane.setMinSize(Region.USE_PREF_SIZE, Region.USE_PREF_SIZE);
    pane.setMaxSize(Region.USE_PREF_SIZE, Region.USE_PREF_SIZE);
    pane.setPrefWidth(appWidth);
    pane.setPrefHeight(appHeight);
    pane.setBackground(Backgrounds.BLACK_BACKGROUND);

    return pane;
  }

  /**
   * Calculates the scale properties for the resizing of the screens
   * 
   */
  public void setScale(double originalWidth, double originalHeight, StackPane resizePane)
  {
    double scaleX = appWidth / originalWidth;
    double scaleY = appHeight / originalHeight;

    if (Double.compare(scaleY, scaleX) < 0)
    {
      scaleX = scaleY;
    }

    setScale(scaleX, resizePane);
  }

  /**
   * Set the scale of the Stack Pane
   *
   * @param scale
   *          The scale value, between 0.0 and 1.0
   */
  public void setScale(double scale, StackPane resizePane)
  {
    resizePane.setScaleX(scale);
    resizePane.setScaleY(scale);
  }

  @Override
  public void setSize(double appWidth, double appHeight)
  {
    this.appWidth = appWidth;
    this.appHeight = appHeight;
  }
}