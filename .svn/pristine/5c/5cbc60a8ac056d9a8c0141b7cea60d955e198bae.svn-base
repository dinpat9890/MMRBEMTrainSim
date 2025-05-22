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

import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.mmrbem.dmi.common.state.DMIConstants;
import com.sydac.mmrbem.dmi.fe.base.DMIFactory;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;

/**
 * A controller for menu popup dialog
 *
 * @author ext-savanjin
 *
 */

public class MainScreenMenuPopupController extends AbstractDMIController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private GridPane mainMenuPane;

  @FXML
  private Pane menuPane;

  @FXML
  private GridPane menuGridPane;

  @FXML
  private Label menuTitleLabel;

  @FXML
  private Button languageButton;

  @FXML
  private Button closeButton;

  @FXML
  private Label testLabel;

  @FXML
  private Label statusLabel;

  @FXML
  private Label setupLabel;

  @FXML
  private Label resetLabel;

  @FXML
  private GridPane languageMenuPane;

  @FXML
  private Button languageEnglishButton;

  @FXML
  private Button previousButton;

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(menuPane, menuPane.getPrefWidth(), menuPane.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(menuGridPane, menuGridPane.getPrefWidth(),
        menuGridPane.getPrefHeight());

    menuGridPane.setLayoutX(ApplicationConstants.MENU_GRID_LAYOUT_X * AbstractDMIController.WIDTH_SCALE);

    updateMainMenuPanel();
  }

  private void updateMainMenuPanel()
  {
    mainMenuPane.setVisible(true);
    languageMenuPane.setVisible(false);
    menuTitleLabel.setText(DMIConstants.MAIN_MENU_TITLE);
    languageButton.setText(DMIConstants.LANGUAGE_BUTTON_TEXT);
    statusLabel.setText(DMIConstants.STATUS_BUTTON_TEXT);
    setupLabel.setText(DMIConstants.SETUP_BUTTON_TEXT);
    testLabel.setText(DMIConstants.TEST_BUTTON_TEXT);
    resetLabel.setText(DMIConstants.RESET_BUTTON_TEXT);
    closeButton.setText(DMIConstants.CLOSE_BUTTON_TEXT);
  }

  @FXML
  void onCloseButtonAction(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(DMIInputs.MENU_CLOSE_BUTTON_PRESS_REQUEST);
  }

  @FXML
  void onLanguageButtonAction(ActionEvent event)
  {
    // FIXME The Front End should not be responsible for bringing up dialogs.
    // This approach breaks replay functionality.
    updateLanguageMenu();
  }

  private void updateLanguageMenu()
  {
    languageMenuPane.setVisible(true);
    mainMenuPane.setVisible(false);
    menuTitleLabel.setText(DMIConstants.LANGUAGE_MENU_TITLE);
    languageEnglishButton.setText(DMIConstants.ENGLISH_BUTTON_TEXT);
    previousButton.setText(DMIConstants.PREVIOUS_BUTTON_TEXT);
  }

  @FXML
  void onLanguageEnglishButtonAction(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(DMIInputs.ENGLISH_LANGUAGE_BUTTON_PRESS_REQUEST);
  }

  @FXML
  void onLanguagePreviousButtonAction(ActionEvent event)
  {
    // FIXME The Front End should not be responsible for closing dialogs. This
    // approach breaks replay functionality.
    updateMainMenuPanel();
  }

  @Override
  public void removeListeners()
  {
    // Listener is not used
  }

  @Override
  public void detachListeners()
  {
    // TODO Auto-generated method stub

  }

}
