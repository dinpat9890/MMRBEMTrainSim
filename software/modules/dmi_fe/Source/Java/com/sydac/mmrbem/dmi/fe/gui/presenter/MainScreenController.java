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

import static com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs.CREW_BUTTON_PRESS_REQUEST;

import java.util.Arrays;
import java.util.stream.Collectors;

import com.sydac.mmrbem.dmi.common.state.DMIConstants;
import com.sydac.mmrbem.dmi.common.state.DMILifeIndicatorStatus;
import com.sydac.mmrbem.dmi.common.state.DMISafetyBrakeStatus;
import com.sydac.mmrbem.dmi.fe.base.DMIFactory;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenBinder;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.DMIInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;

/**
 * Provides common infrastructure like grid pane containers and labels for Main
 * Screen.
 * 
 * @author mulukg
 */
public class MainScreenController extends AbstractDMIController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private GridPane settingsMainGrid;

  @FXML
  private GridPane audioGrid;

  @FXML
  private GridPane brightnessGrid;

  @FXML
  private Label areaLifeLabel;

  @FXML
  private Label areaDwLabel;

  @FXML
  private Label areaUpLabel;

  @FXML
  private Label areaMenuLabel;

  @FXML
  private Button audioBtn;

  @FXML
  private Button brightnessBtn;

  @FXML
  private Label areaE1923Label;

  @FXML
  private Label advisorySpeedLabel;

  @FXML
  private Label areaC8Label;

  @FXML
  private Label areaD8DateLabel;

  @FXML
  private Label areaD8TimeLabel;

  @FXML
  private Button crewIdButton;

  @FXML
  private Label serviceNumberLabel;

  @FXML
  private Label destinationCodeLbl;

  @FXML
  private Pane crewNumberDialogPopUpPane;

  @FXML
  private Pane mainScreenMenuPopupPane;

  @FXML
  private GridPane msgCrewGrid;

  @FXML
  private GridPane drivingModesGrid;

  @FXML
  private GridPane speedoGrid;

  @FXML
  private GridPane areaDMiddleGrid;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<Number> lifeIndicatorLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<String> serviceNuberLabelListener;

  private ChangeListener<String> destinationIdListener;

  private ChangeListener<Boolean> menuPanelStatusListener;

  private ChangeListener<String> areaD1LabelListener;

  private ChangeListener<String> destinationCodeListener;

  private ChangeListener<Number> activeSettingsPanelListener;

  private MainScreenModel mainScreenModel;

  private ChangeListener<Number> safetyBrakestatusListener = (observable, oldVal,
      newVal) -> updateSafetyBrakeStatus(mainScreenModel.getSafteyBrakeStatus().get());

  private ChangeListener<Boolean> crewIdPanelStatusListener = (observable, oldVal,
      newVal) -> updatCrewIdPanelStatus(mainScreenModel.getCrewIdPanelStatus().getValue());

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(mainScreenMenuPopupPane,
        mainScreenMenuPopupPane.getPrefWidth(), mainScreenMenuPopupPane.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(crewNumberDialogPopUpPane,
        crewNumberDialogPopUpPane.getPrefWidth(), crewNumberDialogPopUpPane.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(msgCrewGrid, msgCrewGrid.getPrefWidth(),
        msgCrewGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(drivingModesGrid, drivingModesGrid.getPrefWidth(),
        drivingModesGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(speedoGrid, speedoGrid.getPrefWidth(),
        speedoGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaC8Label, areaC8Label.getPrefWidth(),
        areaC8Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaDMiddleGrid, areaDMiddleGrid.getPrefWidth(),
        areaDMiddleGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(settingsMainGrid, settingsMainGrid.getPrefWidth(),
        settingsMainGrid.getPrefHeight());

    mainScreenModel = new MainScreenModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenBinder(mainScreenModel));

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    mainScreenModel.currentDateProperty().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    mainScreenModel.currentHourAndMinProperty().addListener(timeLabelListener);

    lifeIndicatorLabelListener = (observable, oldVal, newVal) -> updateLifeIndicatorLabel((int)newVal);
    mainScreenModel.getLifeIndicatorStatus().addListener(lifeIndicatorLabelListener);

    areaD1LabelListener = (observable, oldVal, newVal) -> updateAreaD1Label();
    mainScreenModel.getAreaD1Label().addListener(areaD1LabelListener);

    destinationIdListener = (observable, oldVal, newVal) -> updateAreaD1Label();
    mainScreenModel.getDestinationId().addListener(destinationIdListener);

    menuPanelStatusListener = (observable, oldVal, newVal) -> updateMenuPanelStatus(newVal);
    mainScreenModel.getMenuPanelStatus().addListener(menuPanelStatusListener);

    destinationCodeListener = (observable, oldVal,
        newVal) -> updateDestinationCode(mainScreenModel.getDestinationCode().get());
    mainScreenModel.getDestinationCode().addListener(destinationCodeListener);

    activeSettingsPanelListener = (observable, oldVal,
        newVal) -> updateActiveSettingPanelGrid(mainScreenModel.getSelectedSettingsPanelId().get());
    mainScreenModel.getSelectedSettingsPanelId().addListener(activeSettingsPanelListener);

    updateDateLabel(mainScreenModel.currentDateProperty().get());
    updateTimeLabel(mainScreenModel.currentHourAndMinProperty().get());
    updateLifeIndicatorLabel(mainScreenModel.getSafteyBrakeStatus().get());
    updateAreaD1Label();
    updateMenuPanelStatus(mainScreenModel.getMenuPanelStatus().getValue());
    updateDestinationCode(mainScreenModel.getDestinationCode().get());
    updateActiveSettingPanelGrid(mainScreenModel.getSelectedSettingsPanelId().get());

    initalizeSafetyBrakeStatusListner();
    initalizeAdvisorySpeed();
    initalizeDrivingModeStatusListener();
    initalizeCurrentTrainSpeedListener();

    initializeCrewIdPanelStatusListener();

  }

  private void updateActiveSettingPanelGrid(int activeGridId)
  {
    if (activeGridId == 0)
    {
      settingsMainGrid.setVisible(false);
      audioGrid.setVisible(false);
      brightnessGrid.setVisible(false);
    }
    else if (activeGridId == 1)
    {
      settingsMainGrid.setVisible(true);
      audioGrid.setVisible(true);
      brightnessGrid.setVisible(false);
    }
    else if (activeGridId == 2)
    {
      settingsMainGrid.setVisible(true);
      audioGrid.setVisible(false);
      brightnessGrid.setVisible(true);
    }
  }

  private void updateDestinationCode(String destCode)
  {
    if (destCode != null)
    {
      destinationCodeLbl.setText(destCode);
    }
    else
    {
      destinationCodeLbl.setText(DMIConstants.SERVICE_NUMBER_NOT_VALID);
    }
  }

  private void initalizeCurrentTrainSpeedListener()
  {
    ChangeListener<Number> currentTrainSpeedListener = (observable, oldVal, newVal) -> updateAdvisorySpeed();
    mainScreenModel.getCurrentTrainSpeed().addListener(currentTrainSpeedListener);
    updateAdvisorySpeed();
  }

  private void initalizeDrivingModeStatusListener()
  {
    ChangeListener<Number> drivingModeStatusListener = (observable, oldVal,
        newVal) -> updateDrivingModeStatus();

    mainScreenModel.getCurrentDrivingMode().addListener(drivingModeStatusListener);
    updateDrivingModeStatus();
  }

  private void updateDrivingModeStatus()
  {
    updateAdvisorySpeed();
  }

  private void initalizeAdvisorySpeed()
  {

    ChangeListener<Number> timeAdvisorySpeed = (observable, oldVal, newVal) -> updateAdvisorySpeed();
    mainScreenModel.getAdvisorySpeed().addListener(timeAdvisorySpeed);
    updateAdvisorySpeed();
  }

  private void updateAdvisorySpeed()
  {
    int advisorySpeed = mainScreenModel.getAdvisorySpeed().get();

    advisorySpeedLabel.setVisible(false);

    if (advisorySpeed > 0)
    {
      // advisorySpeedLabel.setText(String.valueOf(advisorySpeed));
    }
  }

  private void initalizeSafetyBrakeStatusListner()
  {
    mainScreenModel.getSafteyBrakeStatus().addListener(safetyBrakestatusListener);
    updateSafetyBrakeStatus(mainScreenModel.getSafteyBrakeStatus().get());
  }

  private void updateSafetyBrakeStatus(int brakeStateValue)
  {
    // remove all the CSS
    areaC8Label.getStyleClass().removeAll(Arrays.asList(DMISafetyBrakeStatus.values()).stream()
        .map(DMISafetyBrakeStatus::getText).collect(Collectors.toList()));
    areaC8Label.getStyleClass().add(DMISafetyBrakeStatus.valueOf(brakeStateValue).getText());
  }

  private void updateLifeIndicatorLabel(int value)
  {
    // remove all the CSS
    areaLifeLabel.getStyleClass().removeAll(Arrays.asList(DMILifeIndicatorStatus.values()).stream()
        .map(DMILifeIndicatorStatus::getText).collect(Collectors.toList()));

    areaLifeLabel.getStyleClass().add(DMILifeIndicatorStatus.valueOf(value).getText());
  }

  private void updateDateLabel(String newVal)
  {
    areaD8DateLabel.setText(newVal);
  }

  private void initializeCrewIdPanelStatusListener()
  {
    mainScreenModel.getCrewIdPanelStatus().addListener(crewIdPanelStatusListener);
    updatCrewIdPanelStatus(mainScreenModel.getCrewIdPanelStatus().get());
  }

  private void updatCrewIdPanelStatus(Boolean newVal)
  {
    crewNumberDialogPopUpPane.setVisible(newVal);
  }

  private void updateMenuPanelStatus(Boolean newVal)
  {
    mainScreenMenuPopupPane.setVisible(newVal);
  }

  private void updateAreaD1Label()
  {
    // With Recent comment from customer (DMI id should be same TCMS - Train
    // Number), commenting this implementation as confirmed from Yogesh
    // if (mainScreenModel.getAreaD1Label().get() != null &&
    // mainScreenModel.getDestinationId().get() != null)
    // {
    // serviceNumberLabel
    // .setText((mainScreenModel.getDestinationId().get()).concat(mainScreenModel.getAreaD1Label().get()));
    // }
    // else
    // {
    // serviceNumberLabel.setText(DMIConstants.SERVICE_NUMBER_NOT_VALID);
    // }

    serviceNumberLabel.setText(DMIConstants.TRAIN_ID);
  }

  private void updateTimeLabel(String newVal)
  {
    areaD8TimeLabel.setText(newVal);
  }

  @Override
  public void detachListeners()
  {
    mainScreenModel.currentDateProperty().removeListener(dateLabelListener);
    mainScreenModel.currentHourAndMinProperty().removeListener(timeLabelListener);
    mainScreenModel.getLifeIndicatorStatus().removeListener(lifeIndicatorLabelListener);
    mainScreenModel.getMenuPanelStatus().removeListener(menuPanelStatusListener);
    mainScreenModel.getServiceNumber().removeListener(serviceNuberLabelListener);
    mainScreenModel.getDestinationCode().removeListener(destinationCodeListener);
    mainScreenModel.getAreaD1Label().removeListener(areaD1LabelListener);
    mainScreenModel.getDestinationId().removeListener(destinationIdListener);
    mainScreenModel.getSelectedSettingsPanelId().removeListener(activeSettingsPanelListener);
  }

  @FXML
  void crewIdButtonClicked(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(CREW_BUTTON_PRESS_REQUEST);
  }

  @FXML
  void onMenuButtonAction(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(DMIInputs.MENU_BUTTON_PRESS_REQUEST);
  }

  @FXML
  void onBrightnessButtonAction(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(DMIInputs.BRIGHTNESS_BUTTON_PRESS_REQUEST);
  }

  @FXML
  void onAudioButtonAction(ActionEvent event)
  {
    DMIFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(DMIInputs.AUDIO_BUTTON_PRESS_REQUEST);
  }
}
