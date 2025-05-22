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

import javafx.fxml.FXML;
import javafx.scene.layout.GridPane;

/**
 * Provides common infrastructure like grid pane containers and labels for
 * Trailing car, Panto car, Luggage Car (XC) and Motor car types.
 * 
 * @author rautprit
 */
public abstract class AbstractCommonCarPanelController extends AbstractDMIController
{
  @FXML
  private GridPane mainGrid;

  @Override
  public void initializeImpl()
  {
    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());
  }
}
