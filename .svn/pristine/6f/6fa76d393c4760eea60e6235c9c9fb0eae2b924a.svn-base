/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui;

import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

import com.sydac.foundation.IPropertySetter;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.cabscreens.fe.gui.AbstractController;
import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.mmrbem.dmi.fe.app.DMIApplication;
import com.sydac.mmrbem.dmi.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.dmi.fe.base.DMIFactory;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableCell;
import javafx.scene.control.TextArea;
import javafx.scene.layout.Region;
import javafx.scene.text.FontWeight;

/**
 * Abstract class for all FXML Controller classes in the TMS application.
 * 
 */
public abstract class AbstractDMIController extends AbstractController
{
  private static final int RESET_VALUE = 0;

  protected ArrayList<AbstractCommsListener> dmiScreenBinders = new ArrayList<>();

  protected IPropertySetter appInputsSetter;

  protected static Double WIDTH_SCALE = 1.0;// $NON-NLS-1$

  protected static Double HEIGHT_SCALE = 1.0;// $NON-NLS-1$

  /**
   * Method that is called by the FMXL Loader during initialization of the FXML.
   */
  @FXML
  @Override
  public final void initialize()
  {
    /* Assign COMMS number to any @CommsNumber annotated JavaFx Controls */
    assignCommsNumberToFxControl();

    /* Initialize the controller */
    initializeImpl();

    dmiScreenBinders.forEach(b -> b.attachToModel(DMIFactory.getCommsBinding(scenarioCarIndex)));

    appInputsSetter = DMIFactory.getCommsBinding(scenarioCarIndex).getHubInputsValuesSetter();
  }

  public static void calculateScaleFactor()
  {
    //WIDTH_SCALE = DMIApplication.CURRENT_APP_WIDTH / ApplicationConstants.DEFAULT_APP_WIDTH;
    //HEIGHT_SCALE = DMIApplication.CURRENT_APP_HEIGHT / ApplicationConstants.DEFAULT_APP_HEIGHT;
  }

  public static void updatePrefSize(Region region, Double width, Double height)
  {
//    if (width < 0.0 && height > 0.0)
//    {
//      region.setPrefHeight(height);
//    }
//    else if (width > 0.0 && height < 0.0)
//    {
//      region.setPrefWidth(width);
//    }
//    else if (width > 0.0 && height > 0.0)
//    {
//      region.setPrefSize(width, height);
//    }
  }

  public static void updateScaledPrefSize(Region region, Double defaultWidth, Double defaultHeight)
  {
//    if (WIDTH_SCALE != 1.0 || HEIGHT_SCALE != 1.0)
//    {
//      updatePrefSize(region, defaultWidth * WIDTH_SCALE, defaultHeight * HEIGHT_SCALE);
//    }
//    else
//    {
//      updatePrefSize(region, defaultWidth, defaultHeight);
//    }
  }

  public static void updateFont(Region region, String fontFamily, FontWeight fontWeight, Double fontSize)
  {

//    if (WIDTH_SCALE < HEIGHT_SCALE)
//    {
//      fontSize = fontSize * HEIGHT_SCALE;
//    }
//    else
//    {
//      fontSize = fontSize * WIDTH_SCALE;
//    }
//
//    if (region instanceof Label)
//    {
//
//      ((Label)region).setStyle(((Label)region).getStyle() + " ; " + "-fx-font-size: " + fontSize
//          + "px; -fx-font-family: " + fontFamily + "; -fx-font-weight: " + fontWeight + ";");
//    }
//    else if (region instanceof Button)
//    {
//      ((Button)region).setStyle(((Button)region).getStyle() + " ; " + "-fx-font-size: " + fontSize
//          + "px; -fx-font-family: " + fontFamily + "; -fx-font-weight: " + fontWeight + ";");
//    }
//    else if (region instanceof TextArea)
//    {
//      ((TextArea)region).setStyle(((TextArea)region).getStyle() + " ; " + "-fx-font-size: " + fontSize
//          + "px; -fx-font-family: " + fontFamily + "; -fx-font-weight: " + fontWeight + ";");
//    }
//    else if (region instanceof TableCell)
//    {
//      ((TableCell)region).setStyle(((TableCell)region).getStyle() + " ; " + "-fx-font-size: " + fontSize
//          + "px; -fx-font-family: " + fontFamily + "; -fx-font-weight: " + fontWeight + ";");
//    }

  }

  protected void sendButtonRequest(final PropertyKey<Integer> propKey, int value)
  {
    appInputsSetter.setProperty(propKey, value);
    AbstractCommsListener.EXECUTOR.schedule(() -> appInputsSetter.setProperty(propKey, RESET_VALUE), 100,
        TimeUnit.MILLISECONDS);
  }

  @Override
  public void removeListeners()
  {
    dmiScreenBinders.forEach(AbstractCommsListener::detachFromModel);
    detachListeners();
  }

  public abstract void detachListeners();

}