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
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.stream.Collectors;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.dmi.common.state.DrivingModeStatus;
import com.sydac.mmrbem.dmi.common.state.WarningStatus;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenAreaBLeftBinder;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenAreaDMiddleBinder;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaBLeftModel;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaDMiddleModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.CurrentDrivingMode;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Arc;
import javafx.scene.shape.Circle;

/**
 * Provides common infrastructure like grid pane containers and labels for Main
 * Screen Area B Left.
 * 
 * @author mulukg
 */
public class MainScreenAreaBLeftController extends AbstractDMIController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private Label areaB1Label;

  @FXML
  private Label areaB3Label;

  @FXML
  private Label areaB4Label;

  @FXML
  private Label areaB5Label;

  @FXML
  private AnchorPane needleBase;

  @FXML
  private AnchorPane anchorPane1;

  @FXML
  private Circle circle1;

  @FXML
  private Circle circle2;

  @FXML
  private Circle circle3;

  @FXML
  private AnchorPane anchorPane2;

  @FXML
  private AnchorPane anchorPane3;

  @FXML
  private AnchorPane anchorPane4;

  @FXML
  private AnchorPane anchorPane5;

  @FXML
  private AnchorPane anchorPane6;

  @FXML
  private ImageView needle;

  @FXML
  private ImageView speedDial;

  @FXML
  private Label speedLabel;

  @FXML
  private Arc targetSpeedArc;

  @FXML
  private Arc permittedSpeedArc;

  @FXML
  private AnchorPane speedIndicatorHookLabelBase;

  @FXML
  private Label speedIndicatorHookLabel;

  @FXML
  private AnchorPane advisoryArrowBase;

  @FXML
  private ImageView advisorySpeedArrow;

  @FXML
  private AnchorPane warningArrowBase;

  @FXML
  private ImageView warningSpeedArrow;

  private NodePseudoClassProperty areaB3LabelProperty;

  private NodePseudoClassProperty areaB4LabelProperty;

  private NodePseudoClassProperty areaB5LabelProperty;

  private MainScreenAreaBLeftModel mainScreenAreaBLeftModel;

  private MainScreenAreaDMiddleModel mainScreenAreaDMiddleModel;

  private Map<String, Boolean> bLabelsStatusMap = new LinkedHashMap<>();

  private Map<Integer, NodePseudoClassProperty> bLabelNodePsuedoPropertyMap = new LinkedHashMap<>();

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    double scale = 1.0;
    if (AbstractDMIController.HEIGHT_SCALE >= AbstractDMIController.WIDTH_SCALE)
    {
      scale = AbstractDMIController.HEIGHT_SCALE;
    }
    else
    {
      scale = AbstractDMIController.WIDTH_SCALE;
    }

    AbstractDMIController.updateScaledPrefSize(anchorPane1, anchorPane1.getPrefWidth(),
        anchorPane1.getPrefHeight());

    circle1.setRadius(circle1.getRadius() * scale);
    circle1.setLayoutX(circle1.getLayoutX() * AbstractDMIController.WIDTH_SCALE);
    circle1.setLayoutY(circle1.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    AbstractDMIController.updateScaledPrefSize(anchorPane2, anchorPane2.getPrefWidth(),
        anchorPane2.getPrefHeight());

    circle2.setRadius(circle2.getRadius() * scale);

    circle2.setLayoutX(circle2.getLayoutX() * AbstractDMIController.WIDTH_SCALE);

    circle2.setLayoutY(circle2.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    AbstractDMIController.updateScaledPrefSize(anchorPane3, anchorPane3.getPrefWidth(),
        anchorPane3.getPrefHeight());

    permittedSpeedArc.setLayoutX(permittedSpeedArc.getLayoutX() * AbstractDMIController.WIDTH_SCALE);
    permittedSpeedArc.setLayoutY(permittedSpeedArc.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    permittedSpeedArc.setRadiusX(permittedSpeedArc.getRadiusX() * AbstractDMIController.WIDTH_SCALE);
    permittedSpeedArc.setRadiusY(permittedSpeedArc.getRadiusY() * AbstractDMIController.HEIGHT_SCALE);

    AbstractDMIController.updateScaledPrefSize(anchorPane4, anchorPane4.getPrefWidth(),
        anchorPane4.getPrefHeight());

    targetSpeedArc.setLayoutX(targetSpeedArc.getLayoutX() * AbstractDMIController.WIDTH_SCALE);
    targetSpeedArc.setLayoutY(targetSpeedArc.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    targetSpeedArc.setRadiusX(targetSpeedArc.getRadiusX() * AbstractDMIController.WIDTH_SCALE);
    targetSpeedArc.setRadiusY(targetSpeedArc.getRadiusY() * AbstractDMIController.HEIGHT_SCALE);

    targetSpeedArc.setLength(targetSpeedArc.getLength() * AbstractDMIController.WIDTH_SCALE);

    AbstractDMIController.updateScaledPrefSize(anchorPane5, anchorPane5.getPrefWidth(),
        anchorPane5.getPrefHeight());

    circle3.setRadius(circle3.getRadius() * scale);

    circle3.setLayoutX(circle3.getLayoutX() * AbstractDMIController.WIDTH_SCALE);

    circle3.setLayoutY(circle3.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    AbstractDMIController.updateScaledPrefSize(anchorPane6, anchorPane6.getPrefWidth(),
        anchorPane6.getPrefHeight());

    speedDial.setFitHeight(speedDial.getFitHeight() * AbstractDMIController.HEIGHT_SCALE);
    speedDial.setFitWidth(speedDial.getFitWidth() * AbstractDMIController.WIDTH_SCALE);

    speedDial.setLayoutX(speedDial.getLayoutX() * AbstractDMIController.WIDTH_SCALE);
    speedDial.setLayoutY(speedDial.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    speedLabel.getStyleClass().removeAll("speedo-meter-speed-label", "speedo-meter-speed-label-small"); //$NON-NLS-1$ //$NON-NLS-2$

    if (AbstractDMIController.WIDTH_SCALE < 1.0 || AbstractDMIController.HEIGHT_SCALE < 1.0)
    {
      speedLabel.getStyleClass().add("speedo-meter-speed-label-small"); //$NON-NLS-1$
    }
    else
    {
      speedLabel.getStyleClass().add("speedo-meter-speed-label"); //$NON-NLS-1$
    }

    AbstractDMIController.updateScaledPrefSize(speedLabel, speedLabel.getPrefWidth(),
        speedLabel.getPrefHeight());
    speedLabel.setLayoutX(speedLabel.getLayoutX() * AbstractDMIController.WIDTH_SCALE);
    speedLabel.setLayoutY(speedLabel.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    AbstractDMIController.updateScaledPrefSize(needleBase, needleBase.getPrefWidth(),
        needleBase.getPrefHeight());

    needleBase.setLayoutX(needleBase.getLayoutX() * AbstractDMIController.WIDTH_SCALE);
    needleBase.setLayoutY(needleBase.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    needle.setFitHeight(needle.getFitHeight() * AbstractDMIController.HEIGHT_SCALE);
    needle.setFitWidth(needle.getFitWidth() * AbstractDMIController.WIDTH_SCALE);

    needle.setLayoutX(needle.getLayoutX() * AbstractDMIController.WIDTH_SCALE);
    needle.setLayoutY(needle.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    AbstractDMIController.updateScaledPrefSize(speedIndicatorHookLabelBase,
        speedIndicatorHookLabelBase.getPrefWidth(), speedIndicatorHookLabelBase.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(speedIndicatorHookLabel,
        speedIndicatorHookLabel.getPrefWidth(), speedIndicatorHookLabel.getPrefHeight());
    speedIndicatorHookLabel
        .setLayoutX(speedIndicatorHookLabel.getLayoutX() * AbstractDMIController.WIDTH_SCALE);
    speedIndicatorHookLabel
        .setLayoutY(speedIndicatorHookLabel.getLayoutY() * AbstractDMIController.HEIGHT_SCALE);

    mainScreenAreaBLeftModel = new MainScreenAreaBLeftModel(scenarioCarIndex);

    dmiScreenBinders.add(new MainScreenAreaBLeftBinder(mainScreenAreaBLeftModel));

    mainScreenAreaDMiddleModel = new MainScreenAreaDMiddleModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenAreaDMiddleBinder(mainScreenAreaDMiddleModel));

    areaB3LabelProperty = new NodePseudoClassProperty(areaB3Label);
    areaB4LabelProperty = new NodePseudoClassProperty(areaB4Label);
    areaB5LabelProperty = new NodePseudoClassProperty(areaB5Label);

    bLabelNodePsuedoPropertyMap.put(1, areaB3LabelProperty);
    bLabelNodePsuedoPropertyMap.put(2, areaB4LabelProperty);
    bLabelNodePsuedoPropertyMap.put(3, areaB5LabelProperty);

    bLabelsStatusMap.put("ChangeOfEnds", false); //$NON-NLS-1$
    bLabelsStatusMap.put("NeutralZone", false); //$NON-NLS-1$
    bLabelsStatusMap.put("SkipStation", false); //$NON-NLS-1$
    bLabelsStatusMap.put("WorkZone", false); //$NON-NLS-1$

    initalizeWarningStatusListner();

    initalizeDrivingModeStatusListener();

    initalizeCurrentTrainSpeedListener();

    initalizeCbtcTargetSpeedListener();

    initalizeCbtcPermittedSpeedListener();

    initializeDriverEventChangeEndsListener();

    initializeNeutralZoneListener();

    initializeDriverEventSkipStation();

    initializeDriverEventWorkZoneListener();

    initialiseAtcBypassState();

    initialiseAdvisorySpeedState();

    initialiseWarningSpeedState();

  }

  private void initialiseAtcBypassState()
  {

    ChangeListener<Boolean> atcBypassStatusListener = (observable, oldVal, newVal) -> {
      updateDrivingModeStatus(mainScreenAreaBLeftModel.getCurrentDrivingMode().get());
    };

    mainScreenAreaBLeftModel.getAtcBypassState().addListener(atcBypassStatusListener);

  }

  private void initializeDriverEventSkipStation()
  {
    ChangeListener<Boolean> driverEventSkipStationListener = (observable, oldVal, newVal) -> {
      updateDriverEventSkipStation(mainScreenAreaBLeftModel.getDriverEventSkipStation().get());
    };

    mainScreenAreaBLeftModel.getDriverEventSkipStation().addListener(driverEventSkipStationListener);
    updateDriverEventSkipStation(mainScreenAreaBLeftModel.getDriverEventSkipStation().get());
  }

  private void initializeDriverEventChangeEndsListener()
  {
    ChangeListener<Boolean> driverEventChangeEndListener = (observable, oldVal, newVal) -> {
      updateDriverEventChangeEnds(mainScreenAreaBLeftModel.getDriverEventChangeEnds().get());
    };

    mainScreenAreaBLeftModel.getDriverEventChangeEnds().addListener(driverEventChangeEndListener);
    updateDriverEventChangeEnds(mainScreenAreaBLeftModel.getDriverEventChangeEnds().get());
  }

  private void initializeNeutralZoneListener()
  {
    ChangeListener<Number> neutralZoneListener = (observable, oldValue, newValue) -> {
      updateNeutralZoneStatus(mainScreenAreaBLeftModel.getNeutralZoneStatus().get());
    };

    mainScreenAreaBLeftModel.getNeutralZoneStatus().addListener(neutralZoneListener);
    updateNeutralZoneStatus(mainScreenAreaBLeftModel.getNeutralZoneStatus().get());
  }

  private void initializeDriverEventWorkZoneListener()
  {
    ChangeListener<Boolean> driverEventWorkZoneListener = (observable, oldVal, newVal) -> {
      updateDriverEventWorkZone(mainScreenAreaBLeftModel.getDriverEventWorkZone().get());
    };

    mainScreenAreaBLeftModel.getDriverEventWorkZone().addListener(driverEventWorkZoneListener);
    updateDriverEventWorkZone(mainScreenAreaBLeftModel.getDriverEventWorkZone().get());
  }

  private void initalizeWarningStatusListner()
  {
    ChangeListener<Number> warningStatusListener = (observable, oldVal, newVal) -> {
      updateWarningStatus(mainScreenAreaBLeftModel.getWarningStatus().get());
    };
    mainScreenAreaBLeftModel.getWarningStatus().addListener(warningStatusListener);
    updateWarningStatus(mainScreenAreaBLeftModel.getWarningStatus().get());
  }

  private void initialiseAdvisorySpeedState()
  {

    ChangeListener<Number> advisorySpeedListener = (observable, oldVal, newVal) -> {
      updateSpeedStatus(mainScreenAreaBLeftModel.getAdvisorySpeed().get(), this.advisoryArrowBase,
          this.advisorySpeedArrow);
    };

    mainScreenAreaBLeftModel.getAdvisorySpeed().addListener(advisorySpeedListener);
    updateSpeedStatus(mainScreenAreaBLeftModel.getAdvisorySpeed().get(), this.advisoryArrowBase,
        this.advisorySpeedArrow);
  }

  private void initialiseWarningSpeedState()
  {

    ChangeListener<Number> warningSpeedListener = (observable, oldVal, newVal) -> {
      updateSpeedStatus(mainScreenAreaBLeftModel.getWarningSpeed().get(), this.warningArrowBase,
          this.warningSpeedArrow);
    };

    mainScreenAreaBLeftModel.getWarningSpeed().addListener(warningSpeedListener);
    updateSpeedStatus(mainScreenAreaBLeftModel.getWarningSpeed().get(), this.warningArrowBase,
        this.warningSpeedArrow);
  }

  private void updateDriverEventChangeEnds(boolean b)
  {
    bLabelsStatusMap.put("ChangeOfEnds", b); //$NON-NLS-1$
    updateBLabelPriorityList();
  }

  private void updateNeutralZoneStatus(int status)
  {
    bLabelsStatusMap.put("NeutralZone", //$NON-NLS-1$
        (status == 1 && (mainScreenAreaBLeftModel.getCurrentDrivingMode().get() == CurrentDrivingMode.ATP
            || mainScreenAreaBLeftModel.getCurrentDrivingMode().get() == CurrentDrivingMode.ATO
            || mainScreenAreaBLeftModel.getCurrentDrivingMode().get() == CurrentDrivingMode.ATB)));
    updateBLabelPriorityList();
  }

  private void updateDriverEventSkipStation(boolean b)
  {
    bLabelsStatusMap.put("SkipStation", b); //$NON-NLS-1$
    updateBLabelPriorityList();
  }

  private void updateDriverEventWorkZone(boolean b)
  {
    bLabelsStatusMap.put("WorkZone", b); //$NON-NLS-1$
    updateBLabelPriorityList();
  }

  private void updateBLabelPriorityList()
  {
    int index = 1;

    for (Entry<Integer, NodePseudoClassProperty> entry : bLabelNodePsuedoPropertyMap.entrySet())
    {
      entry.getValue().set("empty"); //$NON-NLS-1$
    }

    for (Entry<String, Boolean> entry : bLabelsStatusMap.entrySet())
    {
      if (entry.getValue().booleanValue() && index < 4)
      {
        bLabelNodePsuedoPropertyMap.get(index).set(entry.getKey());
        index++;
      }
    }
  }

  private void updateSpeedLabelAndIndicator()
  {
    boolean isValidPermittedTargetSpeed = true;

    if (mainScreenAreaBLeftModel.getCbtcPermittedSpeed().get() < 0
        || mainScreenAreaBLeftModel.getCbtcTargetSpeed().get() < 0)
    {
      isValidPermittedTargetSpeed = false;
    }

    double currentTrainSpeed = mainScreenAreaBLeftModel.getCurrentTrainSpeed().get();
    int cbtcPermittedSpeed = Math.abs(mainScreenAreaBLeftModel.getCbtcPermittedSpeed().get());
    int cbtcTargetSpeed = Math.abs(mainScreenAreaBLeftModel.getCbtcTargetSpeed().get());

    int angleAtMinSpeed = -140;
    int angleAtMaxSpeed = 140;
    double maxSpeed = 85.0;
    double angleToMove1Km;

    if (DrivingModeStatus.RMF_MODE.getValue() == mainScreenAreaBLeftModel.getCurrentDrivingMode().get()
        || DrivingModeStatus.ROS_MODE.getValue() == mainScreenAreaBLeftModel.getCurrentDrivingMode().get())
    {
      maxSpeed = 25.0;
      angleAtMaxSpeed = -53;
      angleToMove1Km = (Math.abs(angleAtMinSpeed) - Math.abs(angleAtMaxSpeed)) / maxSpeed;
    }
    else if (DrivingModeStatus.RMR_MODE.getValue() == mainScreenAreaBLeftModel.getCurrentDrivingMode().get())
    {
      maxSpeed = 10.0;
      angleAtMaxSpeed = -105;
      angleToMove1Km = (Math.abs(angleAtMinSpeed) - Math.abs(angleAtMaxSpeed)) / maxSpeed;
    }
    else
    {
      angleToMove1Km = (Math.abs(angleAtMinSpeed) + Math.abs(angleAtMaxSpeed)) / maxSpeed;
    }

    if (currentTrainSpeed > maxSpeed)
    {
      currentTrainSpeed = (int)maxSpeed;
    }

    double rotateAngle = (angleAtMinSpeed + (Math.abs(currentTrainSpeed) * angleToMove1Km));

    if (rotateAngle < angleAtMinSpeed)
    {
      rotateAngle = angleAtMinSpeed;
    }

    if (rotateAngle > angleAtMaxSpeed)
    {
      rotateAngle = angleAtMaxSpeed;
    }

    this.needleBase.setRotate(rotateAngle);

    speedLabel.setText(String.valueOf(((Double)Math.abs(currentTrainSpeed)).intValue()));

    if (isValidPermittedTargetSpeed && (DrivingModeStatus.ATP_MODE.getValue() == mainScreenAreaBLeftModel
        .getCurrentDrivingMode().get()
        || DrivingModeStatus.ATO_MODE.getValue() == mainScreenAreaBLeftModel.getCurrentDrivingMode().get()))
    {

      speedIndicatorHookLabel.setVisible(true);

      if (cbtcPermittedSpeed > maxSpeed)
      {
        cbtcPermittedSpeed = (int)maxSpeed;
      }

      if (cbtcTargetSpeed > maxSpeed)
      {
        cbtcTargetSpeed = (int)maxSpeed;
      }

      updateCbtcPermittedSpeed(angleToMove1Km, cbtcPermittedSpeed, cbtcTargetSpeed);
      updateCbtcTargetSpeed(angleToMove1Km, maxSpeed, cbtcPermittedSpeed, cbtcTargetSpeed);
      updatespeedIndicatorHookLabel(angleToMove1Km, Math.abs(currentTrainSpeed), cbtcPermittedSpeed,
          cbtcTargetSpeed);

    }
    else
    {
     
      // Hide speed indicator
      speedIndicatorHookLabel.setVisible(false);
      permittedSpeedArc.setLength(360);
      targetSpeedArc.setLength(0);
    }

  }

  private void updatespeedIndicatorHookLabel(double angleToMove1Km, double currentTrainSpeed,
      int cbtcPermittedSpeed, int cbtcTargetSpeed)
  {
    int angleAtMinSpeed = -125;

    double rotateAngle = angleAtMinSpeed;

    speedIndicatorHookLabel.setVisible(cbtcTargetSpeed >= 0);

    if (cbtcPermittedSpeed <= cbtcTargetSpeed)
    {
      if (DrivingModeStatus.ATO_MODE.getValue() == mainScreenAreaBLeftModel.getCurrentDrivingMode().get())
      {
        rotateAngle += ((cbtcTargetSpeed - currentTrainSpeed) * angleToMove1Km) + 0.1;
      }
      else
      {
        rotateAngle += ((cbtcPermittedSpeed - currentTrainSpeed) * angleToMove1Km) + 0.1;
      }

    }
    else if (currentTrainSpeed > cbtcTargetSpeed)
    {
      rotateAngle -= ((currentTrainSpeed - cbtcTargetSpeed) * angleToMove1Km) + 0.1;
    }
    else if (currentTrainSpeed < cbtcTargetSpeed)
    {
      rotateAngle += (cbtcTargetSpeed - currentTrainSpeed) * angleToMove1Km;
    }
  
    speedIndicatorHookLabelBase.setRotate(rotateAngle);

  }

  private void updateCbtcPermittedSpeed(double angleToMove1Km, int cbtcPermittedSpeed, int cbtcTargetSpeed)
  {

    double permittedSpeedArcLengthAtZeroSpeed = 360.0;

    double permittedSpeedArcStartAngleAtZeroSpeed = -130;

    double arcLengthWithUpdatedSpeeed = permittedSpeedArcLengthAtZeroSpeed
        - (cbtcPermittedSpeed * angleToMove1Km);

    double arcLengthWithUpdatedSpeeedTarget = permittedSpeedArcLengthAtZeroSpeed
        - (cbtcTargetSpeed * angleToMove1Km);

    if (DrivingModeStatus.ATO_MODE.getValue() == mainScreenAreaBLeftModel.getCurrentDrivingMode().get())
    {
    

      if (cbtcTargetSpeed > cbtcPermittedSpeed)
      {
        permittedSpeedArc.setLength(arcLengthWithUpdatedSpeeedTarget);
      }
      else
      {
        permittedSpeedArc.setLength(arcLengthWithUpdatedSpeeed);
      }
    }
    else
    {
      permittedSpeedArc.setLength(arcLengthWithUpdatedSpeeed);
    }

    permittedSpeedArc.setStartAngle(permittedSpeedArcStartAngleAtZeroSpeed);

  }

  private void updateCbtcTargetSpeed(double angleToMove1Km, double maxSpeed, int cbtcPermittedSpeed,
      int cbtcTargetSpeed)
  {
    if (DrivingModeStatus.ATO_MODE.getValue() == mainScreenAreaBLeftModel.getCurrentDrivingMode().get())
    {
      if (cbtcTargetSpeed > cbtcPermittedSpeed)
      {
        targetSpeedArc.setLength(0);
        // targetSpeedArc.setStartAngle(0);

      }
      else
      {
        calculateTargetSpeed(angleToMove1Km, maxSpeed, cbtcPermittedSpeed, cbtcTargetSpeed);
      }
    }
    else
    {
      calculateTargetSpeed(angleToMove1Km, maxSpeed, cbtcPermittedSpeed, cbtcTargetSpeed);
    }
  }

  private void calculateTargetSpeed(double angleToMove1Km, double maxSpeed, int cbtcPermittedSpeed,
      int cbtcTargetSpeed)
  {
    double startAngleAtMaxSpeed = -51.0;

    double targetSpeedArcLength = (cbtcPermittedSpeed - cbtcTargetSpeed) * angleToMove1Km;

    double targetSpeedArcStartAngle = startAngleAtMaxSpeed
        + ((maxSpeed - cbtcPermittedSpeed) * angleToMove1Km) + 0.5;

    targetSpeedArc.setLength(targetSpeedArcLength);

    targetSpeedArc.setStartAngle(targetSpeedArcStartAngle);
  }

  private void initalizeCbtcPermittedSpeedListener()
  {

    ChangeListener<Number> cbtcPermittedSpeedListener = (observable, oldVal, newVal) -> {
      updateSpeedLabelAndIndicator();
    };

    mainScreenAreaBLeftModel.getCbtcPermittedSpeed().addListener(cbtcPermittedSpeedListener);
    updateSpeedLabelAndIndicator();

  }

  private void initalizeCbtcTargetSpeedListener()
  {
    ChangeListener<Number> cbtcTargetSpeedListener = (observable, oldVal, newVal) -> {
      updateSpeedLabelAndIndicator();
    };

    mainScreenAreaBLeftModel.getCbtcTargetSpeed().addListener(cbtcTargetSpeedListener);
    updateSpeedLabelAndIndicator();

  }

  private void initalizeCurrentTrainSpeedListener()
  {
    ChangeListener<Number> currentTrainSpeedListener = (observable, oldVal, newVal) -> {
      updateSpeedLabelAndIndicator();
    };

    mainScreenAreaBLeftModel.getCurrentTrainSpeed().addListener(currentTrainSpeedListener);
    updateSpeedLabelAndIndicator();
  }

  private void initalizeDrivingModeStatusListener()
  {
    ChangeListener<Number> drivingModeStatusListener = (observable, oldVal, newVal) -> {
      updateDrivingModeStatus(mainScreenAreaBLeftModel.getCurrentDrivingMode().get());
    };

    mainScreenAreaBLeftModel.getCurrentDrivingMode().addListener(drivingModeStatusListener);
    updateDrivingModeStatus(mainScreenAreaBLeftModel.getCurrentDrivingMode().get());

    updateNeutralZoneStatus(mainScreenAreaBLeftModel.getNeutralZoneStatus().get());
  }

  private void updateDrivingModeStatus(int updatedDrivingMode)
  {

    if (!mainScreenAreaBLeftModel.getAtcBypassState().get())
    {
      speedDial.getStyleClass().removeAll(Arrays.asList(DrivingModeStatus.values()).stream()
          .map(DrivingModeStatus::getSpeedDialCss).collect(Collectors.toList()));

      speedDial.getStyleClass().add(DrivingModeStatus.valueOf(updatedDrivingMode).getSpeedDialCss());
    }

    updateSpeedLabelAndIndicator();

  }

  private void updateWarningStatus(int updatedWarningStatus)
  {
    // remove all the CSS
    needle.getStyleClass().removeAll(Arrays.asList(WarningStatus.values()).stream()
        .map(p -> p.getSpeedometerNeedleStatus()).collect(Collectors.toList()));

    needle.getStyleClass().add(WarningStatus.valueOf(updatedWarningStatus).getSpeedometerNeedleStatus());
  }

  private void updateSpeedStatus(double speed, AnchorPane arrowBase, ImageView speedrrow)
  {
    int angleAtMinSpeed = -140;
    int angleAtMaxSpeed = 140;
    double maxSpeed = 85.0;
    double angleToMove1Km;
    angleToMove1Km = (Math.abs(angleAtMinSpeed) + Math.abs(angleAtMaxSpeed)) / maxSpeed;
    double rotateAngle = (angleAtMinSpeed + (speed * angleToMove1Km));

    if (rotateAngle < angleAtMinSpeed)
    {
      rotateAngle = angleAtMinSpeed;
    }

    if (rotateAngle > angleAtMaxSpeed)
    {
      rotateAngle = angleAtMaxSpeed;
    }

    arrowBase.setRotate(rotateAngle);

    if (speedrrow.equals(this.advisorySpeedArrow))
    {
      speedrrow.setVisible(speed > 0.9);
    }
    else if (speedrrow.equals(this.warningSpeedArrow))
    {
      speedrrow.setVisible(speed > 3.9);
    }
  }

  @Override
  public void detachListeners()
  {

  }

}
