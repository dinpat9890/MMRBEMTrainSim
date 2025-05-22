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
import com.sydac.mmrbem.dmi.fe.gui.binder.StartupScreenBinder;
import com.sydac.mmrbem.dmi.fe.gui.model.StartupScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.ProgressBar;
import javafx.scene.layout.GridPane;

/**
 * Controller to Startup Screen
 * 
 * @author ext-savanjin
 *
 */

public class StartupScreenController extends AbstractDMIController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private ProgressBar progressBar;

  private ChangeListener<Number> progressBarValueListener;

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    StartupScreenModel startupScreenModel = new StartupScreenModel(scenarioCarIndex);
    dmiScreenBinders.add(new StartupScreenBinder(startupScreenModel));

    progressBarValueListener = (observable, oldVal, newVal) -> updateProgressValue(newVal);
    startupScreenModel.getProgressBarValue().addListener(progressBarValueListener);
  }

  private void updateProgressValue(Number newVal)
  {
    progressBar.setProgress((double)newVal);
  }

  @Override
  public void detachListeners()
  {

  }
}
