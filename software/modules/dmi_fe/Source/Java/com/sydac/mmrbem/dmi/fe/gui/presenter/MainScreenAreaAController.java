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
import java.util.List;
import java.util.stream.Collectors;

import com.sydac.mmrbem.dmi.common.state.ApplicationConstants;
import com.sydac.mmrbem.dmi.common.state.WarningStatus;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenAreaABinder;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaAModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

/**
 * Provides common infrastructure like grid pane containers and labels for Main
 * Screen Area A.
 * 
 * @author mulukg
 */
public class MainScreenAreaAController extends AbstractDMIController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private Label areaA1Label;

  @FXML
  private Label areaA2Label;

  @FXML
  private Label targetDistBar;

  private MainScreenAreaAModel mainScreenModel;

  private List<Integer> targetDistanceList;

  private ChangeListener<Number> warningStatusListener;

  private ChangeListener<Number> targetDistanceListener;

  private ChangeListener<Boolean> targetDistanceBarGraphStatusListener;

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaA2Label, areaA2Label.getPrefWidth(),
        areaA2Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(targetDistBar, targetDistBar.getPrefWidth(),
        targetDistBar.getPrefHeight());

    targetDistBar.setLayoutX(ApplicationConstants.AREA_A_LAYOUT_X * AbstractDMIController.WIDTH_SCALE);

    targetDistBar.setLayoutY(ApplicationConstants.AREA_A_LAYOUT_Y * AbstractDMIController.HEIGHT_SCALE);

    targetDistanceList = Arrays.asList(0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000);

    mainScreenModel = new MainScreenAreaAModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenAreaABinder(mainScreenModel));

    warningStatusListener = (observable, oldVal,
        newVal) -> updateWarningStatus(mainScreenModel.getWarningStatus().get());

    targetDistanceListener = (observable, oldVal,
        newVal) -> updateTargetDistance(mainScreenModel.getTargetDistance().get());

    targetDistanceBarGraphStatusListener = (observable, oldVal, newVal) -> updateTargetDistanceBarGraphStatus(
        mainScreenModel.getTargetDistanceBarGraphStatus().get());

    initalizeWarningStatusListner();
    intializeTargetDistance();
    intializeTargetDistanceBarGraphStatus();
  }

  private void updateTargetDistanceBarGraphStatus(boolean isVisible)
  {
    targetDistBar.setVisible(isVisible);
    areaA2Label.getStyleClass().removeAll("a2-area-target-dist-bar", "a2-area-target-dist-bar-invisible");

    if (isVisible)
    {
      areaA2Label.getStyleClass().add("a2-area-target-dist-bar");
    }
    else
    {
      areaA2Label.getStyleClass().add("a2-area-target-dist-bar-invisible");
    }

  }

  private void intializeTargetDistanceBarGraphStatus()
  {
    mainScreenModel.getTargetDistanceBarGraphStatus().addListener(targetDistanceBarGraphStatusListener);
    updateTargetDistanceBarGraphStatus(mainScreenModel.getTargetDistanceBarGraphStatus().get());
  }

  private void intializeTargetDistance()
  {
    mainScreenModel.getTargetDistance().addListener(targetDistanceListener);
    updateTargetDistance(mainScreenModel.getTargetDistance().get());
  }

  private void initalizeWarningStatusListner()
  {
    mainScreenModel.getWarningStatus().addListener(warningStatusListener);
    updateWarningStatus(mainScreenModel.getWarningStatus().get());
  }

  private void updateWarningStatus(int warningStateValue)
  {
    // remove all the CSS
    areaA1Label.getStyleClass().removeAll(Arrays.asList(WarningStatus.values()).stream()
        .map(p -> p.getAreaA1LabelStatus()).collect(Collectors.toList()));
    areaA1Label.getStyleClass().add(WarningStatus.valueOf(warningStateValue).getAreaA1LabelStatus());
  }

  private void updateTargetDistance(int targetDistanceValue)
  {

    if (!targetDistanceList.isEmpty()
        && targetDistanceList.get(targetDistanceList.size() - 1) < targetDistanceValue)
    {
      targetDistanceValue = targetDistanceList.get(targetDistanceList.size() - 1);
    }

    int speedLevelIndex = getNearestSpeedLevelIndex(targetDistanceValue);

    if (speedLevelIndex > 0)
    {
      double heightOfSpeedLevel = targetDistBar.getPrefHeight() / 10;
      int currentLevelMaxSpeed = targetDistanceList.get(speedLevelIndex);
      int previousSpeedLevelndex = speedLevelIndex - 1;
      int previousLevelMaxSpeed = targetDistanceList.get(previousSpeedLevelndex);

      double heightFor1Km = heightOfSpeedLevel / (currentLevelMaxSpeed - previousLevelMaxSpeed);

      double targetDistanceBarHeight = (previousSpeedLevelndex * heightOfSpeedLevel)
          + ((targetDistanceValue - previousLevelMaxSpeed) * heightFor1Km);

      double insetTop = targetDistBar.getPrefHeight() - targetDistanceBarHeight;

      targetDistBar.setStyle("-fx-background-insets: " + (insetTop > 0 ? insetTop : 0) + " 0.0 0.0 0.0;");
    }
  }

  private int getNearestSpeedLevelIndex(int targetDistanceValue)
  {

    for (int i = 0; i < targetDistanceList.size(); i++)
    {
      if (targetDistanceValue == targetDistanceList.get(i))
      {
        return i;
      }
      else if (i + 1 != targetDistanceList.size() && targetDistanceValue <= targetDistanceList.get(i + 1))
      {
        return i + 1;
      }
    }
    return 0;
  }

  @Override
  public void detachListeners()
  {
    mainScreenModel.getWarningStatus().removeListener(warningStatusListener);
    mainScreenModel.getTargetDistance().removeListener(targetDistanceListener);
  }
}