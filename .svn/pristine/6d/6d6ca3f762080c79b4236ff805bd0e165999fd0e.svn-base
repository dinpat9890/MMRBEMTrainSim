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

import java.util.Arrays;
import java.util.stream.Collectors;

import com.sydac.mmrbem.dmi.common.state.DMIDepartureInformation;
import com.sydac.mmrbem.dmi.common.state.DMIDepartureOrderStatus;
import com.sydac.mmrbem.dmi.common.state.DMIDetrainmentDoorStatus;
import com.sydac.mmrbem.dmi.common.state.DMIPSDDoorStatus;
import com.sydac.mmrbem.dmi.common.state.DMITrainDockingStatus;
import com.sydac.mmrbem.dmi.common.state.DMITrainDoorStatus;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenAreaDMiddleBinder;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaDMiddleModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

/**
 * Provides common infrastructure like grid pane containers and labels for Main
 * Screen Area D Middle.
 * 
 * @author mulukg
 */
public class MainScreenAreaDMiddleController extends AbstractDMIController
{

  private static final int FLASH_EXECUTION_INTERVAL = 1000;

  private static final int FLASH_PAUSE_INTERVAL = 500;

  @FXML
  private GridPane mainGrid;

  @FXML
  private Label areaD2Label;

  @FXML
  private Label areaD3Label;

  @FXML
  private Label areaD4Label;

  @FXML
  private Label areaD5Label;

  @FXML
  private Label areaD5FlashLabel;

  @FXML
  private Label areaD6FlashLabel;

  @FXML
  private Label areaD6Label;

  @FXML
  private Label areaD7Label;

  @FXML
  private Label remTimeLabel;

  private ChangeListener<Number> areaD6LabelListener;

  private ChangeListener<Number> areaD2LabelListener;

  private ChangeListener<Number> areaD5LabelListener;

  private ChangeListener<Boolean> departureTimeMinuteStatusListener;

  private ChangeListener<String> remainingTimeListener;

  private MainScreenAreaDMiddleModel mainScreenAreaDMiddleModel;

  private Boolean remainingTimeLabelFlashStatus = false;

  private Boolean areaD5LabelFlashStatus = false;

  private Boolean areaD6LabelFlashStatus = false;

  private long previousFlashTime;

  private ChangeListener<Number> areaD7LabelListener;

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaD2Label, areaD2Label.getPrefWidth(),
        areaD2Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaD3Label, areaD3Label.getPrefWidth(),
        areaD3Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaD4Label, areaD4Label.getPrefWidth(),
        areaD4Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaD5Label, areaD5Label.getPrefWidth(),
        areaD5Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaD5FlashLabel, areaD5FlashLabel.getPrefWidth(),
        areaD5FlashLabel.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaD6Label, areaD6Label.getPrefWidth(),
        areaD6Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaD6FlashLabel, areaD6FlashLabel.getPrefWidth(),
        areaD6FlashLabel.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(remTimeLabel, remTimeLabel.getPrefWidth(),
        remTimeLabel.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaD7Label, areaD7Label.getPrefWidth(),
        areaD7Label.getPrefHeight());

    mainScreenAreaDMiddleModel = new MainScreenAreaDMiddleModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenAreaDMiddleBinder(mainScreenAreaDMiddleModel));

    areaD6LabelListener = (observable, oldVal, newVal) -> updatePSDDoorStatusLabel((int)newVal);
    mainScreenAreaDMiddleModel.getPsdDoorStatus().addListener(areaD6LabelListener);

    areaD2LabelListener = (observable, oldVal, newVal) -> updateDepartureInfoStatusLabel((int)newVal);
    mainScreenAreaDMiddleModel.getDepartureInformation().addListener(areaD2LabelListener);

    remainingTimeListener = (observable, oldVal, newVal) -> updateRemainingTimeLabel(newVal);
    mainScreenAreaDMiddleModel.getRemainingDepartureTime().addListener(remainingTimeListener);

    ChangeListener<Number> areaD4LabelListener = (observable, oldVal, newVal) -> updateDockingStatusLabel();
    mainScreenAreaDMiddleModel.getTrainDockingStatus().addListener(areaD4LabelListener);

    ChangeListener<String> areaD4OperationalDistanceListener = (observable, oldVal,
        newVal) -> updateDockingStatusLabel();
    mainScreenAreaDMiddleModel.getOperationalServiceStoppingPointDistance()
        .addListener(areaD4OperationalDistanceListener);

    ChangeListener<Number> areaD3LabelListener = (observable, oldVal,
        newVal) -> updateDepartureOrders((int)newVal);
    mainScreenAreaDMiddleModel.getDepartureOrder().addListener(areaD3LabelListener);

    areaD5LabelListener = (observable, oldVal, newVal) -> updateTrainDoorStatus((int)newVal);
    mainScreenAreaDMiddleModel.getTrainDoorStatus().addListener(areaD5LabelListener);

    departureTimeMinuteStatusListener = (observable, oldVal,
        newVal) -> updateDepartureTimeMinuteStatus(newVal);
    mainScreenAreaDMiddleModel.getRemainingTimeMinuteFlashStatus()
        .addListener(departureTimeMinuteStatusListener);

    ChangeListener<Number> flashLabelListener = (observable, oldVal,
        newVal) -> updateFlashLabel((long)newVal);
    mainScreenAreaDMiddleModel.getFlashTime().addListener(flashLabelListener);

    areaD7LabelListener = (observable, oldVal, newVal) -> updateDetrainmentDoorStatus((int)newVal);
    mainScreenAreaDMiddleModel.getDetrainmentDoorStatus().addListener(areaD7LabelListener);

    updatePSDDoorStatusLabel(mainScreenAreaDMiddleModel.getPsdDoorStatus().get());
    updateDockingStatusLabel();
    updateRemainingTimeLabel(mainScreenAreaDMiddleModel.getRemainingDepartureTime().get());
    updateDepartureInfoStatusLabel(mainScreenAreaDMiddleModel.getDepartureInformation().get());
    updateDepartureOrders(mainScreenAreaDMiddleModel.getDepartureOrder().get());
    updateTrainDoorStatus(mainScreenAreaDMiddleModel.getTrainDoorStatus().get());
    updateDepartureTimeMinuteStatus(mainScreenAreaDMiddleModel.getRemainingTimeMinuteFlashStatus().get());
    updateDetrainmentDoorStatus(mainScreenAreaDMiddleModel.getDetrainmentDoorStatus().get());
  }

  private void updateFlashLabel(long flashTime)
  {
    if (flashTime - previousFlashTime > FLASH_EXECUTION_INTERVAL)
    {
      previousFlashTime = flashTime;
      if (Boolean.TRUE.equals(areaD5LabelFlashStatus))
      {
        areaD5FlashLabel.setVisible(true);
      }
      if (Boolean.TRUE.equals(areaD6LabelFlashStatus))
      {
        areaD6FlashLabel.setVisible(true);
      }
      if (Boolean.TRUE.equals(remainingTimeLabelFlashStatus))
      {
        remTimeLabel.setVisible(true);
      }
    }
    else if (flashTime - previousFlashTime > FLASH_PAUSE_INTERVAL)
    {
      areaD5FlashLabel.setVisible(false);
      areaD6FlashLabel.setVisible(false);
      if (Boolean.TRUE.equals(remainingTimeLabelFlashStatus))
      {
        remTimeLabel.setVisible(false);
      }
    }
  }

  private void updateDepartureOrders(int newVal)
  {
    // remove all the CSS
    areaD3Label.getStyleClass().removeAll(Arrays.asList(DMIDepartureOrderStatus.values()).stream()
        .map(DMIDepartureOrderStatus::getText).collect(Collectors.toList()));

    areaD3Label.getStyleClass().add(DMIDepartureOrderStatus.valueOf(newVal).getText());
  }

  private void updateTrainDoorStatus(int newVal)
  {
    // remove all the CSS
    areaD5Label.getStyleClass().removeAll(Arrays.asList(DMITrainDoorStatus.values()).stream()
        .map(DMITrainDoorStatus::getText).collect(Collectors.toList()));

    if (newVal == DMITrainDoorStatus.DOOR_WARNING_CLOSING.getValue()
        || newVal == DMITrainDoorStatus.DOOR_WARNING_OPEN.getValue()
        || newVal == DMITrainDoorStatus.DOOR_OPENING.getValue()
        || newVal == DMITrainDoorStatus.DOOR_OPEN.getValue())
    {
      areaD5LabelFlashStatus = true;
    }
    else
    {
      areaD5LabelFlashStatus = false;
      areaD5FlashLabel.setVisible(false);
    }

    areaD5Label.getStyleClass().add(DMITrainDoorStatus.valueOf(newVal).getText());
  }

  private void updateDockingStatusLabel()
  {
    int dockingStatus = mainScreenAreaDMiddleModel.getTrainDockingStatus().get();
    // remove all the CSS
    areaD4Label.getStyleClass().removeAll(Arrays.asList(DMITrainDockingStatus.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));

    if (DMITrainDockingStatus.OPERATIONAL_SERVICE_STOPPING_DISTANCE.getValue() == mainScreenAreaDMiddleModel
        .getTrainDockingStatus().get())
    {
      areaD4Label.getStyleClass().add(DMITrainDockingStatus.valueOf(dockingStatus).getText());
      areaD4Label.setText(
          String.valueOf(mainScreenAreaDMiddleModel.getOperationalServiceStoppingPointDistance().get()));
    }
    else
    {
      areaD4Label.getStyleClass().add(DMITrainDockingStatus.valueOf(dockingStatus).getText());
    }
  }

  private void updatePSDDoorStatusLabel(int newVal)
  {
    // // remove all the CSS
    areaD6Label.getStyleClass().removeAll(
        Arrays.asList(DMIPSDDoorStatus.values()).stream().map(p -> p.getText()).collect(Collectors.toList()));

    if (newVal == DMIPSDDoorStatus.PSD_CLOSING_FAILURE.getValue())
    {
      areaD6LabelFlashStatus = true;
    }
    else
    {
      areaD6LabelFlashStatus = false;
      areaD6FlashLabel.setVisible(false);
    }

    areaD6Label.getStyleClass().add(DMIPSDDoorStatus.valueOf(newVal).getText());
  }

  private void updateDepartureInfoStatusLabel(int depInfo)
  {
    // remove all the CSS
    areaD2Label.getStyleClass().removeAll(Arrays.asList(DMIDepartureInformation.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));

    // selected state CSS
    areaD2Label.getStyleClass().add(DMIDepartureInformation.valueOf(depInfo).getText());
  }

  private void updateRemainingTimeLabel(String remTime)
  {
    remTimeLabel.setText(remTime);
  }

  private void updateDepartureTimeMinuteStatus(Boolean newVal)
  {
    if (newVal)
    {
      remainingTimeLabelFlashStatus = true;
    }
    else
    {
      remainingTimeLabelFlashStatus = false;
      remTimeLabel.setVisible(true);
    }
  }

  private void updateDetrainmentDoorStatus(int newVal)
  {
    // remove all the CSS
    areaD7Label.getStyleClass().removeAll(Arrays.asList(DMIDetrainmentDoorStatus.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));

    // selected state CSS
    areaD7Label.getStyleClass().add(DMIDetrainmentDoorStatus.valueOf(newVal).getText());
  }

  @Override
  public void detachListeners()
  {
    mainScreenAreaDMiddleModel.getPsdDoorStatus().removeListener(areaD6LabelListener);
    mainScreenAreaDMiddleModel.getPsdDoorStatus().removeListener(areaD2LabelListener);
    mainScreenAreaDMiddleModel.getRemainingDepartureTime().removeListener(remainingTimeListener);
    mainScreenAreaDMiddleModel.getTrainDoorStatus().removeListener(areaD5LabelListener);
    mainScreenAreaDMiddleModel.getRemainingTimeMinuteFlashStatus()
        .removeListener(departureTimeMinuteStatusListener);
    mainScreenAreaDMiddleModel.getDetrainmentDoorStatus().removeListener(areaD7LabelListener);
  }
}
