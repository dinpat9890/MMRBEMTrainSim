/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.fe.gui.presenter;

import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.ScreenSaverBinder;
import com.sydac.mmrbem.dmi.fe.gui.model.ScreenSaverModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

/**
 * Provides common infrastructure like grid pane containers and labels for
 * Screen Saver Screen.
 * 
 * @author mulukg
 */
public class ScreenSaverController extends AbstractDMIController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private Label softwareVersion;

  private ScreenSaverModel screenSaverModel;

  private ChangeListener<String> progressBarValueListener;

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    screenSaverModel = new ScreenSaverModel(scenarioCarIndex);
    dmiScreenBinders.add(new ScreenSaverBinder(screenSaverModel));

    progressBarValueListener = (observable, oldVal, newVal) -> updateProgressValue(newVal);
    screenSaverModel.getSoftwateVersionText().addListener(progressBarValueListener);
  }

  private void updateProgressValue(String newVal)
  {
    softwareVersion.setText(" Software version :  " + newVal);
  }

  @Override
  public void detachListeners()
  {

  }

}