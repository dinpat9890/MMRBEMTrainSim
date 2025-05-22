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
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import com.sydac.mmrbem.cbtc.common.protos.CBTCProtos.AvailableModesList.DrivingMode;
import com.sydac.mmrbem.dmi.common.state.DMILocalisationStatus;
import com.sydac.mmrbem.dmi.common.state.DrivingModeStatus;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenAreaCRightBinder;
import com.sydac.mmrbem.dmi.fe.gui.data.AvailableDrivingModesDO;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaCRightModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.CurrentDrivingMode;
import com.sydac.project.runtimedata.ProjectObjectConstants.TypeValue.LocalisationStatus;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

/**
 * Provides common infrastructure like grid pane containers and labels for Main
 * Screen Area C Right.
 * 
 * @author mulukg
 */
public class MainScreenAreaCRightController extends AbstractDMIController
{

  private static final int FLASH_EXECUTION_INTERVAL = 1000;

  private static final int FLASH_PAUSE_INTERVAL = 500;

  @FXML
  private GridPane mainGrid;

  @FXML
  private Label areaCStopLabel;

  @FXML
  private Label areaC1Label;

  @FXML
  private Label areaC2Label;

  @FXML
  private Label areaC3Label;

  @FXML
  private Label areaC4Label;

  @FXML
  private Label areaC5Label;

  @FXML
  private Label areaC11Label;

  @FXML
  private Label areaC31Label;

  @FXML
  private Label areaC21Label;

  @FXML
  private Label areaC41Label;

  private MainScreenAreaCRightModel mainScreenAreaCRightModel;

  public static final String DRIVING_MODE_AVAILABLE = "driving-mode-available"; //$NON-NLS-1$

  private static final String DRIVING_MODE_NOT_AVAILABLE = "driving-mode-not-available"; //$NON-NLS-1$

  private List<Label> drivingModeAvailLabelList;

  private Map<DrivingModeStatus, Label> drivingModeLabelMap = new HashMap<>();

  private Boolean areaC5LabelFlashStatus = false;

  private long previousFlashTime;

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaC11Label, areaC11Label.getPrefWidth(),
        areaC11Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaC21Label, areaC21Label.getPrefWidth(),
        areaC21Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaC31Label, areaC31Label.getPrefWidth(),
        areaC31Label.getPrefHeight());

    AbstractDMIController.updateScaledPrefSize(areaC41Label, areaC41Label.getPrefWidth(),
        areaC41Label.getPrefHeight());

    mainScreenAreaCRightModel = new MainScreenAreaCRightModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenAreaCRightBinder(mainScreenAreaCRightModel));

    drivingModeAvailLabelList = Arrays.asList(areaC11Label, areaC21Label, areaC31Label, areaC41Label);

    initialiseDrivingModes();
    initialiseLocalisation();
    initialiseAtcBypassState();

    ChangeListener<Number> flashLabelListener = (observable, oldVal,
        newVal) -> updateFlashLabel((long)newVal);
    mainScreenAreaCRightModel.getFlashTime().addListener(flashLabelListener);

  }

  private void initialiseAtcBypassState()
  {

    ChangeListener<Boolean> atcBypassStatusListener = (observable, oldVal, newVal) -> {
      updateDrivingModeStatus();
    };

    mainScreenAreaCRightModel.getAtcBypassState().addListener(atcBypassStatusListener);

  }

  private void updateFlashLabel(long flashTime)
  {
    if (flashTime - previousFlashTime > FLASH_EXECUTION_INTERVAL && areaC5LabelFlashStatus)
    {
      previousFlashTime = flashTime;
      areaC5Label.setVisible(true);
    }
    else if (flashTime - previousFlashTime > FLASH_PAUSE_INTERVAL && areaC5LabelFlashStatus)
    {
      areaC5Label.setVisible(false);
    }
  }

  private ChangeListener<Number> drivingModeStatusListener = (observable, oldVal, newVal) -> {
    updateDrivingModeStatus();
    updateAvailableModeLabels();
  };

  private ChangeListener<Number> localisationListener = (observable, oldVal, newVal) -> {
    updateLocalisationStatus(mainScreenAreaCRightModel.getLocalisationStatus().get());
    updateDrivingModeStatus();
    updateAvailableModeLabels();
  };

  private ChangeListener<Number> drivingModeListener = (observable, oldVal, newVal) -> {
    updateLocalisationStatus(mainScreenAreaCRightModel.getLocalisationStatus().get());
  };

  private void initialiseDrivingModes()
  {
    mainScreenAreaCRightModel.getCurrentDrivingMode().addListener(drivingModeStatusListener);
    updateDrivingModeStatus();

    ChangeListener<? super ObservableList<AvailableDrivingModesDO>> availableDrivingModeStatusListener = ((
        observable, oldVal, newVal) -> updateAvailableModeLabels());
    mainScreenAreaCRightModel.getAvailableModesDOList().addListener(availableDrivingModeStatusListener);

  }

  private void initialiseLocalisation()
  {
    mainScreenAreaCRightModel.getLocalisationStatus().addListener(localisationListener);
    mainScreenAreaCRightModel.getCurrentDrivingMode().addListener(drivingModeListener);
    updateLocalisationStatus(mainScreenAreaCRightModel.getLocalisationStatus().get());
  }

  private void updateDrivingModeStatus()
  {

    int updatedDrivingMode = mainScreenAreaCRightModel.getCurrentDrivingMode().get();
    areaCStopLabel.getStyleClass().clear();
    areaC1Label.getStyleClass().clear();
    areaC2Label.getStyleClass().clear();
    areaC3Label.getStyleClass().clear();
    areaC4Label.getStyleClass().clear();

    if (CurrentDrivingMode.NO_MODE == updatedDrivingMode)
    {
      areaCStopLabel.getStyleClass().add("driving-no-mode-default"); //$NON-NLS-1$
      areaCStopLabel.setVisible(true);
      areaC1Label.setVisible(false);
      areaC2Label.setVisible(false);
      areaC3Label.setVisible(false);
      areaC4Label.setVisible(false);
    }
    if (CurrentDrivingMode.ATP == updatedDrivingMode)
    {
      areaC2Label.getStyleClass().add("driving-mode-atp-available"); //$NON-NLS-1$
      areaC1Label.setVisible(false);
      areaC2Label.setVisible(true);
      areaC3Label.setVisible(false);
      areaC4Label.setVisible(false);
      areaCStopLabel.setVisible(false);
    }
    if (CurrentDrivingMode.RMF == updatedDrivingMode || CurrentDrivingMode.RMR == updatedDrivingMode)
    {
      areaC1Label.getStyleClass().add("driving-mode-rm-available"); //$NON-NLS-1$
      areaC1Label.setVisible(true);
      areaC2Label.setVisible(false);
      areaC3Label.setVisible(false);
      areaC4Label.setVisible(false);
      areaCStopLabel.setVisible(false);
    }
    if (CurrentDrivingMode.ROS == updatedDrivingMode)
    {
      areaC1Label.getStyleClass().add("driving-mode-ros-available"); //$NON-NLS-1$
      areaC1Label.setVisible(true);
      areaC2Label.setVisible(false);
      areaC3Label.setVisible(false);
      areaC4Label.setVisible(false);
      areaCStopLabel.setVisible(false);
    }
    if (CurrentDrivingMode.ATO == updatedDrivingMode)
    {
      areaC3Label.getStyleClass().add("driving-mode-ato-available"); //$NON-NLS-1$
      areaC1Label.setVisible(false);
      areaC2Label.setVisible(false);
      areaC3Label.setVisible(true);
      areaC4Label.setVisible(false);
      areaCStopLabel.setVisible(false);
    }
    if (CurrentDrivingMode.UTO == updatedDrivingMode)
    {
      areaC3Label.getStyleClass().add("driving-mode-uto-available"); //$NON-NLS-1$
      areaC1Label.setVisible(false);
      areaC2Label.setVisible(false);
      areaC3Label.setVisible(true);
      areaC4Label.setVisible(false);
      areaCStopLabel.setVisible(false);
    }
    if (CurrentDrivingMode.ATB == updatedDrivingMode)
    {
      areaC4Label.getStyleClass().add("driving-mode-atb-available"); //$NON-NLS-1$
      areaC1Label.setVisible(false);
      areaC2Label.setVisible(false);
      areaC3Label.setVisible(false);
      areaC4Label.setVisible(true);
      areaCStopLabel.setVisible(false);
    }
  }

  private void updateAvailableModeLabels()
  {
    drivingModeAvailLabelList.forEach(label -> {
      label.getStyleClass().removeAll(DRIVING_MODE_AVAILABLE, DRIVING_MODE_NOT_AVAILABLE);
    });

    int updatedDrivingMode = mainScreenAreaCRightModel.getCurrentDrivingMode().get();
    List<DrivingMode> availableModes = mainScreenAreaCRightModel.getAvailableModes();

    String areaC11LabelCss = DRIVING_MODE_NOT_AVAILABLE;
    String areaC21LabelCss = DRIVING_MODE_NOT_AVAILABLE;
    String areaC31LabelCss = DRIVING_MODE_NOT_AVAILABLE;
    String areaC41LabelCss = DRIVING_MODE_NOT_AVAILABLE;

    if (!availableModes.isEmpty())
    {
      if (CurrentDrivingMode.NO_MODE == updatedDrivingMode)
      {
        if (availableModes.contains(DrivingMode.RMF_MODE) || availableModes.contains(DrivingMode.RMR_MODE))
        {
          areaC11LabelCss = DRIVING_MODE_AVAILABLE;
        }
        if (availableModes.contains(DrivingMode.ROS_MODE) || availableModes.contains(DrivingMode.ATP_MODE))
        {
          areaC21LabelCss = DRIVING_MODE_AVAILABLE;
        }
        if (availableModes.contains(DrivingMode.ATO_MODE) || availableModes.contains(DrivingMode.UTO_MODE))
        {
          areaC31LabelCss = DRIVING_MODE_AVAILABLE;
        }
        if (availableModes.contains(DrivingMode.ATB_MODE))
        {
          areaC41LabelCss = DRIVING_MODE_AVAILABLE;
        }
      }
      if (CurrentDrivingMode.RMF == updatedDrivingMode || CurrentDrivingMode.RMR == updatedDrivingMode)
      {
        areaC11LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.RMF == updatedDrivingMode
          || CurrentDrivingMode.RMR == updatedDrivingMode && !availableModes.contains(DrivingMode.ATP_MODE))
      {
        areaC21LabelCss = DRIVING_MODE_NOT_AVAILABLE;
      }
      if (CurrentDrivingMode.RMF == updatedDrivingMode
          || CurrentDrivingMode.RMR == updatedDrivingMode && availableModes.contains(DrivingMode.ATP_MODE))
      {
        areaC21LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.ROS == updatedDrivingMode)
      {
        areaC11LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.ATP == updatedDrivingMode)
      {
        if (mainScreenAreaCRightModel.getLocalisationStatus().get() == LocalisationStatus.NOT_LOCALISED
            || mainScreenAreaCRightModel.getLocalisationStatus().get() == LocalisationStatus.UNAVAILABLE)
        {
          areaC21LabelCss = DRIVING_MODE_NOT_AVAILABLE;
        }
        else
        {
          areaC21LabelCss = DRIVING_MODE_AVAILABLE;
        }
      }
      if (CurrentDrivingMode.ATP == updatedDrivingMode
          && (availableModes.contains(DrivingMode.RMF_MODE) || availableModes.contains(DrivingMode.RMR_MODE)))
      {
        areaC11LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.ATP == updatedDrivingMode && (availableModes.contains(DrivingMode.RMF_MODE)
          && availableModes.contains(DrivingMode.RMR_MODE) && availableModes.contains(DrivingMode.ATO_MODE)
          && availableModes.contains(DrivingMode.UTO_MODE)))
      {
        areaC31LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.ATO == updatedDrivingMode)
      {
        areaC11LabelCss = DRIVING_MODE_AVAILABLE;
        areaC21LabelCss = DRIVING_MODE_AVAILABLE;
        areaC31LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.ATO == updatedDrivingMode && (availableModes.contains(DrivingMode.RMF_MODE)
          && availableModes.contains(DrivingMode.RMR_MODE) && availableModes.contains(DrivingMode.ATP_MODE)
          && availableModes.contains(DrivingMode.UTO_MODE) && availableModes.contains(DrivingMode.ATB_MODE)))
      {
        areaC11LabelCss = DRIVING_MODE_AVAILABLE;
        areaC21LabelCss = DRIVING_MODE_AVAILABLE;
        areaC31LabelCss = DRIVING_MODE_AVAILABLE;
        areaC41LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.UTO == updatedDrivingMode && (availableModes.contains(DrivingMode.RMF_MODE)
          && availableModes.contains(DrivingMode.RMR_MODE) && availableModes.contains(DrivingMode.ATP_MODE)
          && availableModes.contains(DrivingMode.ATO_MODE)))
      {
        areaC11LabelCss = DRIVING_MODE_AVAILABLE;
        areaC21LabelCss = DRIVING_MODE_AVAILABLE;
        areaC31LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.UTO == updatedDrivingMode && (availableModes.contains(DrivingMode.RMF_MODE)
          && availableModes.contains(DrivingMode.RMR_MODE) && availableModes.contains(DrivingMode.ATP_MODE)
          && availableModes.contains(DrivingMode.ATO_MODE) && availableModes.contains(DrivingMode.ATB_MODE)))
      {
        areaC11LabelCss = DRIVING_MODE_AVAILABLE;
        areaC21LabelCss = DRIVING_MODE_AVAILABLE;
        areaC31LabelCss = DRIVING_MODE_AVAILABLE;
        areaC41LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if (CurrentDrivingMode.ATB == updatedDrivingMode
          && (availableModes.contains(DrivingMode.RMF_MODE) && availableModes.contains(DrivingMode.RMR_MODE)))
      {
        areaC11LabelCss = DRIVING_MODE_AVAILABLE;
        areaC41LabelCss = DRIVING_MODE_AVAILABLE;
      }
      if ((CurrentDrivingMode.RMF == updatedDrivingMode || CurrentDrivingMode.RMR == updatedDrivingMode)
          && (availableModes.contains(DrivingMode.UTO_MODE) || availableModes.contains(DrivingMode.ATO_MODE)))
      {
        areaC31LabelCss = DRIVING_MODE_AVAILABLE;
      }
    }

    if (mainScreenAreaCRightModel.getLocalisationStatus().get() == DMILocalisationStatus.ATC_NOT_LOCALIZED
        .getValue()
        || mainScreenAreaCRightModel.getLocalisationStatus().get() == DMILocalisationStatus.UNAVAILABLE
            .getValue())
    {
      areaC21LabelCss = DRIVING_MODE_NOT_AVAILABLE; // ATO Mode
      areaC31LabelCss = DRIVING_MODE_NOT_AVAILABLE; // ATP Mode
    }

    areaC11Label.getStyleClass().add(areaC11LabelCss);
    areaC21Label.getStyleClass().add(areaC21LabelCss);
    areaC31Label.getStyleClass().add(areaC31LabelCss);
    areaC41Label.getStyleClass().add(areaC41LabelCss);
  }

  private void updateLocalisationStatus(int value)
  {
    areaC5Label.getStyleClass().removeAll(Arrays.asList(DMILocalisationStatus.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));
    if (value == DMILocalisationStatus.ATC_LOCALIZED.getValue()
        && (mainScreenAreaCRightModel.getCurrentDrivingMode().get() == CurrentDrivingMode.ATP
            || mainScreenAreaCRightModel.getCurrentDrivingMode().get() == CurrentDrivingMode.ATO))
    {
      areaC5LabelFlashStatus = false;
      areaC5Label.setVisible(false);
    }
    else if (value == DMILocalisationStatus.ATC_MEMORISED_LOCALISATION.getValue())
    {
      areaC5LabelFlashStatus = true;
    }
    else
    {
      areaC5LabelFlashStatus = false;
      areaC5Label.setVisible(true);
      updateAvailableModeLabels();
    }

    areaC5Label.getStyleClass().add(DMILocalisationStatus.valueOf(value).getText());
  }

  @Override
  public void detachListeners()
  {}
}