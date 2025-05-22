/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ROUTE_SCREEN_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ROUTE_SCREEN_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ROUTE_SCREEN_OK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ROUTE_SCREEN_UP_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.LineDetailModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.RouteDirectionEnum;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.RouteSettingScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.RouteSettingScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class RouteSettingScreenController extends AbstractPAPISController
{

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label lineNameLbl;

  @FXML
  private Label trainDirectionUpIcon;

  @FXML
  private Label trainDirectionDownIcon;

  @FXML
  private Label lineOption1;

  @FXML
  private Label lineOption2;

  @FXML
  private Label lineOption3;

  @FXML
  private Label lineOption4;

  @FXML
  @CommsNumber(ROUTE_SCREEN_UP_BUTTON)
  private Button lineInputUpBtn;

  @FXML
  @CommsNumber(ROUTE_SCREEN_DOWN_BUTTON)
  private Button lineInputDownBtn;

  @FXML
  @CommsNumber(ROUTE_SCREEN_OK_BUTTON)
  private Button routeSettingOkBtn;

  @FXML
  @CommsNumber(ROUTE_SCREEN_BACK_BUTTON)
  private Button routeSettingBackBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<? super ObservableList<LineDetailModel>> lineListListener;

  private ChangeListener<String> lineSelectionListener;

  private Map<Integer, Label> lineMap = new HashMap<>();

  private RouteSettingScreenModel routeSettingScreenModel;

  private HeaderDateTimeModel headerDateTimeModel;

  private Integer lineId = 0;

  private Integer lineOptId1 = 0;

  private Integer lineOptId2 = 1;

  private Integer lineOptId3 = 2;

  private Integer lineOptId4 = 3;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    routeSettingScreenModel.getLineDetailList().removeListener(lineListListener);
    routeSettingScreenModel.getLineNameProperty().removeListener(lineSelectionListener);
  }

  @Override
  public void initializeImpl()
  {
    routeSettingScreenModel = new RouteSettingScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new RouteSettingScreenBinder(routeSettingScreenModel));

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());

    lineMap.put(lineOptId1, lineOption1);
    lineMap.put(lineOptId2, lineOption2);
    lineMap.put(lineOptId3, lineOption3);
    lineMap.put(lineOptId4, lineOption4);

    lineListListener = (observable, oldVal, newVal) -> updateLineOptions();
    routeSettingScreenModel.getLineDetailList().addListener(lineListListener);

    lineSelectionListener = (observable, oldVal, newVal) -> updateLineNameLabel(newVal);
    routeSettingScreenModel.getLineNameProperty().addListener(lineSelectionListener);

    updateLineOptions();
    updateUpDirectionSelection();
  }

  private void updateUpDirectionSelection()
  {
    trainDirectionUpIcon.getStyleClass().clear();
    trainDirectionDownIcon.getStyleClass().clear();
    trainDirectionUpIcon.getStyleClass().add(ApplicationConstants.DIRECTION_SELECTED);
    trainDirectionDownIcon.getStyleClass().add(ApplicationConstants.DIRECTION_UNSELECTED);
  }

  private void updateDownDirectionSelection()
  {
    trainDirectionUpIcon.getStyleClass().clear();
    trainDirectionDownIcon.getStyleClass().clear();
    trainDirectionUpIcon.getStyleClass().add(ApplicationConstants.DIRECTION_UNSELECTED);
    trainDirectionDownIcon.getStyleClass().add(ApplicationConstants.DIRECTION_SELECTED);
  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void updateLineOptions()
  {
    for (int optionsCounter = 0; optionsCounter < lineMap.size(); optionsCounter++)
    {
      lineMap.get(optionsCounter).setText(""); //$NON-NLS-1$
      lineMap.get(optionsCounter).getStyleClass().clear();
      lineMap.get(optionsCounter).setVisible(false);
    }

    for (int optionsCounter = 0; optionsCounter < routeSettingScreenModel.getLineDetailList()
        .size(); optionsCounter++)
    {
      String line = routeSettingScreenModel.getLineDetailList().get(optionsCounter).getLineName();

      if (line != null)
      {
        lineMap.get(optionsCounter).setText(line);
        lineMap.get(optionsCounter).getStyleClass().add(ApplicationConstants.LINE_OPTIONS_UNSELECTED_CSS);
        lineMap.get(optionsCounter).setVisible(true);
      }
    }
  }

  private void updateLineNameLabel(String lineName)
  {
    lineNameLbl.setText(lineName);
  }

  private void updateLineId(int index)
  {
    lineId = routeSettingScreenModel.getLineDetailList().get(index).getLineId();
    for (int i = 0; i < lineMap.size(); i++)
    {
      lineMap.get(i).getStyleClass().clear();
      lineMap.get(i).getStyleClass().add(ApplicationConstants.LINE_OPTIONS_UNSELECTED_CSS);
    }
    lineMap.get(index).getStyleClass().add(ApplicationConstants.LINE_OPTIONS_SELECTED_CSS);
    updateLineNameLabel(routeSettingScreenModel.getLineDetailList().get(index).getLineName());
  }

  @FXML
  private void onLineOptionsMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(lineMap.get(lineOptId1)))
    {
      updateLineId(lineOptId1);
    }
    else if (event.getSource().equals(lineMap.get(lineOptId2)))
    {
      updateLineId(lineOptId2);
    }
    else if (event.getSource().equals(lineMap.get(lineOptId3)))
    {
      updateLineId(lineOptId3);
    }
    else if (event.getSource().equals(lineMap.get(lineOptId4)))
    {
      updateLineId(lineOptId4);
    }
  }

  @FXML
  private void onLineOptionsTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(lineMap.get(lineOptId1)))
    {
      updateLineId(lineOptId1);
    }
    else if (event.getSource().equals(lineMap.get(lineOptId2)))
    {
      updateLineId(lineOptId2);
    }
    else if (event.getSource().equals(lineMap.get(lineOptId3)))
    {
      updateLineId(lineOptId3);
    }
    else if (event.getSource().equals(lineMap.get(lineOptId4)))
    {
      updateLineId(lineOptId4);
    }
  }

  @FXML
  private void onTrainDirectionUpIconMouseClicked(MouseEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteDirectionRequest(RouteDirectionEnum.UP);
    updateUpDirectionSelection();
  }

  @FXML
  private void onTrainDirectionUpIconTouchPressed(TouchEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteDirectionRequest(RouteDirectionEnum.UP);
    updateUpDirectionSelection();
  }

  @FXML
  private void onTrainDirectionDownIconMouseClicked(MouseEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendRouteDirectionRequest(RouteDirectionEnum.DOWN);
    updateDownDirectionSelection();
  }

  @FXML
  private void onTrainDirectionDownIconTouchPressed(TouchEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendRouteDirectionRequest(RouteDirectionEnum.DOWN);
    updateDownDirectionSelection();
  }

  @FXML
  private void onLineInputUpButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendRouteScreenUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onLineInputDownButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendRouteScreenDownButtonPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onRouteSettingOkButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendLineIdSelected(lineId);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
    updateLineOptions();
  }

  @FXML
  private void onRouteSettingBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
    updateLineOptions();
  }
}
