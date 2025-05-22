/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.util.Iterator;
import java.util.List;

import com.sydac.mmrbem.cabscreens.fe.app.button.ButtonBehavior;
import com.sydac.mmrbem.tcms.common.data.StationDetailModel;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.action.StationScreenCommandRequest;
import com.sydac.mmrbem.tcms.fe.gui.action.StationScreenCommandRequest.StationCommand;
import com.sydac.mmrbem.tcms.fe.gui.binder.RouteScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.RouteScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.WeakChangeListener;
import javafx.fxml.FXML;
import javafx.geometry.Pos;
import javafx.scene.control.Toggle;
import javafx.scene.control.ToggleButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.GridPane;

public class SkipStationScreenController extends AbstractTCMSController
{

  private RouteScreenModel routeScreenModel; 
  
  @FXML
  private GridPane grid1;

  @FXML  
  private GridPane grid2;
  
  private static final int MAXROWS = 9;

  private static final int MAXCOLUMNS = 4;

  private static final double BUTTON_WIDTH = 170;

  private static final double BUTTON_HEIGHT = 100;

  private ToggleGroup stationListToggleGroup;
  
  private ChangeListener<? super Boolean> line2StationListChangedListener = (observer, oldValue,
      newVaule) -> buildLine2StationListUI(routeScreenModel.getLine2StationDetailList());
      
      
      private ChangeListener<? super Boolean> line7StationListChangedListener = (observer, oldValue,
          newVaule) -> buildLine7StationListUI(routeScreenModel.getLine7StationDetailList());
      
      private ChangeListener<? super Toggle> selectedToggleListener = (observable, oldValue, newValue) -> {
        if (newValue != null && newValue.isSelected())
        {
          ((StationScreenCommandRequest)newValue.getUserData()).sendToggleSelectedRequest();
          
        }

      };
  
  @Override
  public void detachListeners()
  {
   

  }

  @Override
  public void initializeImpl()
  {
    
    routeScreenModel = new RouteScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new RouteScreenBinder(routeScreenModel));
    
    routeScreenModel.getLine2StationListChangedProperty()
    .addListener(new WeakChangeListener<>(line2StationListChangedListener));
    
    routeScreenModel.getLine7StationListChangedProperty()
    .addListener(new WeakChangeListener<>(line7StationListChangedListener));
  }
  
  void buildLine7StationListUI(List<StationDetailModel> listMap)
  {

    grid1.getChildren().clear();
  
    stationListToggleGroup = new ToggleGroup();
    stationListToggleGroup.getToggles().clear();
    Iterator<StationDetailModel> keyIterator = listMap.iterator();
    int blankIndex = 1000;
    for (int column = 0; column < MAXCOLUMNS; column++)
      for (int row = 0; row < MAXROWS; row++)
      {
        if (keyIterator.hasNext())
        {
          StationDetailModel station = keyIterator.next();
          final ToggleButton testButton = new ToggleButton();
          testButton.getProperties().put(AbstractTCMSController.COMMS_NUMBER_KEY, VDUInputs.DUMMY_BUTTON);
          testButton.getProperties().put(ButtonBehavior.KEY_PRESS_VALUE_KEY,
              String.valueOf(station.getStationCode()) );
          testButton.getStyleClass().add("toggle-button"); //$NON-NLS-1$
          testButton.setText(station.getStationCode()+" SKIP");
          testButton.setPrefWidth(BUTTON_WIDTH);
          testButton.setAlignment(Pos.CENTER_LEFT);
          testButton.setPrefHeight(BUTTON_HEIGHT);
          testButton.setUserData(new StationScreenCommandRequest(scenarioCarIndex,
              StationCommand.SKIP_STATION_SELECTED, station.getStationId(), 0));

          testButton.setToggleGroup(stationListToggleGroup);

          grid1.add(testButton, column, row);
        }

      }

    stationListToggleGroup.selectedToggleProperty()
        .addListener(new WeakChangeListener<>(selectedToggleListener));
    //
    // messageListScreenModel.getStationListSelectedStationProperty()
    // .addListener(new
    // WeakChangeListener<>(stationListSelectedStationListener));
  }
  
  
  void buildLine2StationListUI(List<StationDetailModel> listMap)
  {

    grid2.getChildren().clear();
  
    stationListToggleGroup = new ToggleGroup();
    stationListToggleGroup.getToggles().clear();
    Iterator<StationDetailModel> keyIterator = listMap.iterator();
    int blankIndex = 1000;
    for (int column = 0; column < MAXCOLUMNS; column++)
      for (int row = 0; row < MAXROWS; row++)
      {
        if (keyIterator.hasNext())
        {
          StationDetailModel station = keyIterator.next();
          final ToggleButton testButton = new ToggleButton();
          testButton.getProperties().put(AbstractTCMSController.COMMS_NUMBER_KEY, VDUInputs.DUMMY_BUTTON);
          testButton.getProperties().put(ButtonBehavior.KEY_PRESS_VALUE_KEY,
              String.valueOf(station.getStationCode()));
          testButton.getStyleClass().add("toggle-button"); //$NON-NLS-1$
          testButton.setText(station.getStationCode()+" SKIP");
          testButton.setPrefWidth(BUTTON_WIDTH);
          testButton.setAlignment(Pos.CENTER_LEFT);
          testButton.setPrefHeight(BUTTON_HEIGHT);
          testButton.setUserData(new StationScreenCommandRequest(scenarioCarIndex,
              StationCommand.SKIP_STATION_SELECTED, station.getStationId(), 0));

          testButton.setToggleGroup(stationListToggleGroup);

          grid2.add(testButton, column, row);
        }

      }

    stationListToggleGroup.selectedToggleProperty()
        .addListener(new WeakChangeListener<>(selectedToggleListener));
    //
    // messageListScreenModel.getStationListSelectedStationProperty()
    // .addListener(new
    // WeakChangeListener<>(stationListSelectedStationListener));
  }


}
