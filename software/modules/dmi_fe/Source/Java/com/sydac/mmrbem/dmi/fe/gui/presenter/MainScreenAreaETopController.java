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

import com.sydac.mmrbem.dmi.common.state.DMIATCStatus;
import com.sydac.mmrbem.dmi.common.state.DMIATPZoneStatus;
import com.sydac.mmrbem.dmi.common.state.DMIDepotIndication;
import com.sydac.mmrbem.dmi.common.state.DMIRadioCommStatus;
import com.sydac.mmrbem.dmi.fe.gui.AbstractDMIController;
import com.sydac.mmrbem.dmi.fe.gui.binder.MainScreenAreaETopBinder;
import com.sydac.mmrbem.dmi.fe.gui.model.MainScreenAreaETopModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

/**
 * Provides common infrastructure like grid pane containers and labels for Main
 * Screen Area E Top.
 * 
 * @author mulukg
 */
public class MainScreenAreaETopController extends AbstractDMIController
{

  @FXML
  private GridPane mainGrid;

  @FXML
  private Label areaE6Label;
  
  @FXML
  private Label areaE7Label;
  
  @FXML
  private Label areaE8Label;

  @FXML
  private Label areaE10Label;

  MainScreenAreaETopModel mainScreenAreaETopModel;

  MainScreenAreaETopBinder binder;

  @Override
  public void initializeImpl()
  {

    AbstractDMIController.updateScaledPrefSize(mainGrid, mainGrid.getPrefWidth(), mainGrid.getPrefHeight());

    mainScreenAreaETopModel = new MainScreenAreaETopModel(scenarioCarIndex);
    dmiScreenBinders.add(new MainScreenAreaETopBinder(mainScreenAreaETopModel));

    initalizeRadioCommStatusListner();

    initalizeAtcCommStatusListner();
    
    initalizeAtpZoneStatusListner();
    
    initalizeDepotIndicationListner();

  }

  private ChangeListener<Number> radioCommsStatusListener = (observable, oldVal, newVal) -> {
    updateRadioCommStatus(mainScreenAreaETopModel.getRadioCommsStatus().get());
  };

  private void initalizeRadioCommStatusListner()
  {
    mainScreenAreaETopModel.getRadioCommsStatus().addListener(radioCommsStatusListener);
    updateRadioCommStatus(mainScreenAreaETopModel.getRadioCommsStatus().get());
  }

  private void updateRadioCommStatus(int radioStatusValue)
  {
    // remove all the CSS
    areaE6Label.getStyleClass().removeAll(Arrays.asList(DMIRadioCommStatus.values()).stream()
        .map(p -> p.getText()).collect(Collectors.toList()));
    areaE6Label.getStyleClass().add(DMIRadioCommStatus.valueOf(radioStatusValue).getText());
  }

  private ChangeListener<Number> atcStatusListener = (observable, oldVal, newVal) -> {
    updateAtcStatus(mainScreenAreaETopModel.getAtcStatus().get());
  };

  private void initalizeAtcCommStatusListner()
  {
    mainScreenAreaETopModel.getAtcStatus().addListener(atcStatusListener);
    updateAtcStatus(mainScreenAreaETopModel.getAtcStatus().get());
  }

  private void updateAtcStatus(int atcStatusValue)
  {
    // remove all the CSS
    areaE10Label.getStyleClass().removeAll(
        Arrays.asList(DMIATCStatus.values()).stream().map(p -> p.getText()).collect(Collectors.toList()));
    areaE10Label.getStyleClass().add(DMIATCStatus.valueOf(atcStatusValue).getText());
  }
  
  private ChangeListener<Number>atpZoneStatusListener = (observable, oldVal, newVal) -> 
  {
	updateATPZoneStatus(mainScreenAreaETopModel.getAtpZoneStatus().get());
  };

  private void initalizeAtpZoneStatusListner() 
  {
	mainScreenAreaETopModel.getAtpZoneStatus().addListener(atpZoneStatusListener);
	updateATPZoneStatus(mainScreenAreaETopModel.getAtpZoneStatus().get());
  }

  private void updateATPZoneStatus(int atpZoneValue) 
  {
    // remove all the CSS
    areaE7Label.getStyleClass().removeAll(
        Arrays.asList(DMIATPZoneStatus.values()).stream().map(p -> p.getText()).collect(Collectors.toList()));
    areaE7Label.getStyleClass().add(DMIATPZoneStatus.valueOf(atpZoneValue).getText());
  }
  
  private ChangeListener<Number>depotIndicationListener = (observable, oldVal, newVal) -> 
  {
    updateDepotIndication(mainScreenAreaETopModel.getDepotIndication().get());
  };

  private void initalizeDepotIndicationListner() 
  {
    mainScreenAreaETopModel.getDepotIndication().addListener(depotIndicationListener);
    updateDepotIndication(mainScreenAreaETopModel.getDepotIndication().get());
  }

  private void updateDepotIndication(int depotIndicationValue) 
  {
    // remove all the CSS
    areaE8Label.getStyleClass().removeAll(
        Arrays.asList(DMIDepotIndication.values()).stream().map(p -> p.getText()).collect(Collectors.toList()));
    areaE8Label.getStyleClass().add(DMIDepotIndication.valueOf(depotIndicationValue).getText());
  }

  @Override
  public void detachListeners()
  {
    mainScreenAreaETopModel.getRadioCommsStatus().removeListener(radioCommsStatusListener);
    mainScreenAreaETopModel.getAtcStatus().removeListener(atcStatusListener);
    mainScreenAreaETopModel.getAtpZoneStatus().removeListener(atpZoneStatusListener);
    mainScreenAreaETopModel.getDepotIndication().removeListener(depotIndicationListener);
  }
}
