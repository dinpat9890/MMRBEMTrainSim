/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ROUTE_SCREEN_KEYPAD_0_BUTTON;

import java.util.Iterator;
import java.util.List;

import com.sydac.gui.control.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.app.button.ButtonBehavior;
import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.data.StationDetailModel;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.KeyPadEnum;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSModeEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.action.StationScreenCommandRequest;
import com.sydac.mmrbem.tcms.fe.gui.action.StationScreenCommandRequest.StationCommand;
import com.sydac.mmrbem.tcms.fe.gui.binder.RouteScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.RouteScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.WeakChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Toggle;
import javafx.scene.control.ToggleButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.GridPane;

public class RouteScreenController extends AbstractTCMSController
{
  @FXML
  private GridPane stationDetailGrid;

  @FXML
  private GridPane trainIdKeypadGrid;

  @FXML
  private GridPane stationGrid;

  @FXML
  private Label destPlatformLbl;

  @FXML
  private Label trainIdLbl;

  @FXML
  private Label stationNameLbl;

  @FXML
  private Label startStationLbl;

  @FXML
  private Label destinationStationLbl;

  @FXML
  private Label trainIdKeypadLbl;

  @FXML
  private Button autoModeBtn;

  @FXML
  private Button semiAutoModeBtn;

  @FXML
  private Button manualModeBtn;

  @FXML
  private Button trainIdSetBtn;

  @FXML
  private Button startStSetBtn;

  @FXML
  private Button destinationStSetBtn;

  @FXML
  private Button startPlatformDownBtn;

  @FXML
  private Button startPlatformUpBtn;

  @FXML
  private Button destPlatformDownBtn;

  @FXML
  private Button destPlatformUpBtn;

  @FXML
  private Button startServiceBtn;

  @FXML
  private Button skipSttaionBtn;

  @FXML
  @CommsNumber(VDUInputs.TRAIN_HOLD_BUTTON)
  private Button trainHoldsetBtn;

  @FXML
  @CommsNumber(VDUInputs.TRAIN_UNDER_EVAC_SET_BUTTON)
  private Button trainEvacBtn;

  @FXML
  @CommsNumber(VDUInputs.TRAIN_OUT_OF_SERVICE_SET_BUTTON)
  private Button trainOutOfServiceBtn;

  @FXML
  @CommsNumber(VDUInputs.DELAY_IN_SERVICE_BUTTON)
  private Button trainDelayBtn;

  @FXML
  @CommsNumber(ROUTE_SCREEN_KEYPAD_0_BUTTON)
  private Button keypad0Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_1_BUTTON)
  private Button keypad1Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_2_BUTTON)
  private Button keypad2Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_3_BUTTON)
  private Button keypad3Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_4_BUTTON)
  private Button keypad4Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_5_BUTTON)
  private Button keypad5Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_6_BUTTON)
  private Button keypad6Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_7_BUTTON)
  private Button keypad7Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_8_BUTTON)
  private Button keypad8Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_9_BUTTON)
  private Button keypad9Btn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_BACKSPACE_BUTTON)
  private Button keypadBackspaceBtn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_CLEAR_BUTTON)
  private Button keypadClearBtn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_ENTER_BUTTON)
  private Button keypadEnterBtn;

  @FXML
  @CommsNumber(VDUInputs.ROUTE_SCREEN_KEYPAD_CLOSE_BUTTON)
  private Button trainIdkeypadCloseBtn;

  @FXML
  private Button stationEnterBtn;

  @FXML
  private Label trainHoldsetLbl;

  @FXML
  private Label trainEvacLbl;

  @FXML
  private Label trainOutOfServiceLbl;

  @FXML
  private Label trainDelayLbl;

  private ChangeListener<String> trainIdListener;

  private ChangeListener<String> semiAutoTrainIdListener;

  private ChangeListener<String> startStationListener;

  private ChangeListener<String> destinationStationListener;

  private ChangeListener<Number> tcmsPapisModeListener;

  private NodePseudoClassProperty autoButtonPseudoClassProperty;

  private NodePseudoClassProperty semiAutoButtonPseudoClassProperty;

  private NodePseudoClassProperty manualButtonPseudoClassProperty;

  private NodePseudoClassProperty trainUnderEvacSetBtnProperty;

  private NodePseudoClassProperty trainOutOfServSetBtnProperty;

  private NodePseudoClassProperty delayInServSetBtnProperty;

  private NodePseudoClassProperty trainHoldsetBtnProperty;

  private NodePseudoClassProperty destPlatformUpButtonProperty;

  private NodePseudoClassProperty destPlatformDownButtonProperty;

  private NodePseudoClassProperty startServiceBtnProperty;

  private ChangeListener<String> selectedStationName;

  private RouteScreenModel routeScreenModel;

  private static final int MAXROWS = 9;

  private static final int MAXCOLUMNS = 4;

  private static final double BUTTON_WIDTH = 100;

  private static final double BUTTON_HEIGHT = 40;

  private ToggleGroup stationListToggleGroup;

  private ChangeListener<Number> trainHoldListener;

  private ChangeListener<Number> trainEvacListener;

  private ChangeListener<Number> trainDelayListener;

  private ChangeListener<Number> trainOutOfServiceListener;

  private ChangeListener<Number> startServiceListener;

  private ChangeListener<? super Boolean> stationListChangedListener = (observer, oldValue,
      newVaule) -> buildStationListUI(routeScreenModel.getStationDetailList());

  private ChangeListener<? super Toggle> selectedToggleListener = (observable, oldValue, newValue) -> {
    if (newValue != null && newValue.isSelected())
    {
      ((StationScreenCommandRequest)newValue.getUserData()).sendToggleSelectedRequest();
      stationEnterBtn.setDisable(false);
    }

  };

  @Override
  public void initializeImpl()
  {
    routeScreenModel = new RouteScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new RouteScreenBinder(routeScreenModel));

    stationListToggleGroup = new ToggleGroup();
    trainIdKeypadGrid.setVisible(TCMSUIConstants.FALSE);

    autoButtonPseudoClassProperty = new NodePseudoClassProperty(autoModeBtn);
    semiAutoButtonPseudoClassProperty = new NodePseudoClassProperty(semiAutoModeBtn);
    manualButtonPseudoClassProperty = new NodePseudoClassProperty(manualModeBtn);

    trainUnderEvacSetBtnProperty = new NodePseudoClassProperty(trainEvacBtn);
    trainOutOfServSetBtnProperty = new NodePseudoClassProperty(trainOutOfServiceBtn);
    delayInServSetBtnProperty = new NodePseudoClassProperty(trainDelayBtn);
    trainHoldsetBtnProperty = new NodePseudoClassProperty(trainHoldsetBtn);

    startServiceBtnProperty = new NodePseudoClassProperty(startServiceBtn);

    trainIdListener = (observable, oldVal, newVal) -> updateTrainId(newVal);
    routeScreenModel.getTrainId().addListener(trainIdListener);

    semiAutoTrainIdListener = (observable, oldVal, newVal) -> updateKeypadTrainId(newVal);
    routeScreenModel.getSemiAutoTrainId().addListener(semiAutoTrainIdListener);

    startStationListener = (observable, oldVal, newVal) -> updateStartStationLabel(newVal);
    routeScreenModel.getStartStation().addListener(startStationListener);

    destinationStationListener = (observable, oldVal, newVal) -> updateDestinationStationLabel(newVal);
    routeScreenModel.getDestinationStation().addListener(destinationStationListener);

    tcmsPapisModeListener = (observable, oldVal, newVal) -> updateSelectedMode((Integer)newVal);
    routeScreenModel.getPapisSelectedMode().addListener(tcmsPapisModeListener);

    routeScreenModel.getStationListChangedProperty()
        .addListener(new WeakChangeListener<>(stationListChangedListener));

    updateSelectedMode(TCMSConstants.DEFAULT_PAPIS_MODE_SELECTED);
    updateTrainId(routeScreenModel.getTrainId().get());

    updateStartStationLabel(routeScreenModel.getStartStation().get());
    updateDestinationStationLabel(routeScreenModel.getDestinationStation().get());

    selectedStationName = (observable, oldVal, newVal) -> updateSelectedStationLabel(newVal);
    routeScreenModel.getSelectedStationName().addListener(selectedStationName);

    destPlatformDownButtonProperty = new NodePseudoClassProperty(destPlatformDownBtn);
    destPlatformUpButtonProperty = new NodePseudoClassProperty(destPlatformUpBtn);

    trainHoldListener = (observable, oldVal, newVal) -> updateTrainHold((Integer)newVal);
    routeScreenModel.getTrainHoldState().addListener(trainHoldListener);

    updateTrainHold(routeScreenModel.getTrainHoldState().get());

    trainEvacListener = (observable, oldVal, newVal) -> updateTrainEvac((Integer)newVal);
    routeScreenModel.getTrainEvac().addListener(trainEvacListener);

    updateTrainEvac(routeScreenModel.getTrainEvac().get());

    trainDelayListener = (observable, oldVal, newVal) -> updateTrainDelay((Integer)newVal);
    routeScreenModel.getTrainDelayState().addListener(trainDelayListener);

    updateTrainDelay(routeScreenModel.getTrainDelayState().get());

    trainOutOfServiceListener = (observable, oldVal, newVal) -> updateTrainService((Integer)newVal);
    routeScreenModel.getTrainOutOfService().addListener(trainOutOfServiceListener);

    updateTrainService(routeScreenModel.getTrainOutOfService().get());

    startServiceListener = (observable, oldVal, newVal) -> updateServiceState((Integer)newVal);
    routeScreenModel.getServiceState().addListener(startServiceListener);

    updateServiceState(routeScreenModel.getServiceState().get());
  }

  private void updateServiceState(Integer newVal)
  {

    if (newVal == 1)
    {

      startServiceBtnProperty.set(TCMSUIConstants.RESET_PSEUDO_CLASS);
      // trainIdSetBtn.setStyle("-fx-text-fill: white");
      trainIdSetBtn.setDisable(Boolean.TRUE);
      startStSetBtn.setDisable(Boolean.TRUE);
      destinationStSetBtn.setDisable(Boolean.TRUE);

    }
    else
    {
      startServiceBtnProperty.set(TCMSUIConstants.SET_PSEUDO_CLASS);
      trainIdSetBtn.setDisable(Boolean.FALSE);
      destinationStSetBtn.setDisable(Boolean.FALSE);
      startStSetBtn.setDisable(Boolean.FALSE);

      updateTrainService(0);
      updateTrainDelay(0);
      updateTrainEvac(0);

    }

  }

  private void updateTrainService(Integer newVal)
  {

    if (newVal == 1)
    {

      trainOutOfServSetBtnProperty.set(TCMSUIConstants.RESET_PSEUDO_CLASS);
      trainOutOfServiceBtn.setText(TCMSUIConstants.RESET_TXT);
      trainOutOfServiceLbl.setStyle(TCMSUIConstants.ROUTE_PRIORITY_RESET_CSS);

    }
    else
    {
      trainOutOfServSetBtnProperty.set(TCMSUIConstants.SET_PSEUDO_CLASS);
      trainOutOfServiceBtn.setText(TCMSUIConstants.SET_TEXT);
      trainOutOfServiceLbl.setStyle(TCMSUIConstants.ROUTE_PRIORITY_SET_CSS);
    }

  }

  private void updateTrainDelay(Integer delayVal)
  {

    if (delayVal == 1)
    {

      delayInServSetBtnProperty.set(TCMSUIConstants.RESET_PSEUDO_CLASS);
      trainDelayBtn.setText(TCMSUIConstants.RESET_TXT);
      trainDelayLbl.setStyle(TCMSUIConstants.ROUTE_PRIORITY_RESET_CSS);

    }
    else
    {
      delayInServSetBtnProperty.set(TCMSUIConstants.SET_PSEUDO_CLASS);
      trainDelayBtn.setText(TCMSUIConstants.SET_TEXT);
      trainDelayLbl.setStyle(TCMSUIConstants.ROUTE_PRIORITY_SET_CSS);
    }

  }

  private void updateTrainEvac(Integer trainEvacVal)
  {

    if (trainEvacVal == 1)
    {

      trainUnderEvacSetBtnProperty.set(TCMSUIConstants.RESET_PSEUDO_CLASS);
      trainEvacBtn.setText(TCMSUIConstants.RESET_TXT);
      trainEvacLbl.setStyle(TCMSUIConstants.ROUTE_PRIORITY_RESET_CSS);

    }
    else
    {
      trainUnderEvacSetBtnProperty.set(TCMSUIConstants.SET_PSEUDO_CLASS);
      trainEvacBtn.setText(TCMSUIConstants.SET_TEXT);
      trainEvacLbl.setStyle(TCMSUIConstants.ROUTE_PRIORITY_SET_CSS);
    }

  }

  private void updateTrainHold(Integer trainHoldVal)
  {

    if (trainHoldVal == 1)
    {

      trainHoldsetBtnProperty.set(TCMSUIConstants.RESET_PSEUDO_CLASS);
      trainHoldsetBtn.setText(TCMSUIConstants.RESET_TXT);
      trainHoldsetLbl.setStyle(TCMSUIConstants.ROUTE_PRIORITY_RESET_CSS);

    }
    else
    {
      trainHoldsetBtnProperty.set(TCMSUIConstants.SET_PSEUDO_CLASS);
      trainHoldsetBtn.setText(TCMSUIConstants.SET_TEXT);
      trainHoldsetLbl.setStyle(TCMSUIConstants.ROUTE_PRIORITY_SET_CSS);
    }

  }

  private void updateSelectedStationLabel(String stationName)
  {

    stationNameLbl.setText(stationName);

  }

  private void updateDestinationPlatformActive(Integer selectedPlatform)
  {
    if (selectedPlatform == TCMSUIConstants.PLATFORM_DOWN_SELECTED)
    {
      destPlatformDownButtonProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      destPlatformUpButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else if (selectedPlatform == TCMSUIConstants.PLATFORM_UP_SELECTED)
    {
      destPlatformDownButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
      destPlatformUpButtonProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
  }

  private void updateSelectedMode(Integer modeVal)
  {
    destPlatformDownBtn.setVisible(TCMSUIConstants.TRUE);
    destPlatformUpBtn.setVisible(TCMSUIConstants.TRUE);
    skipSttaionBtn.setVisible(TCMSUIConstants.TRUE);
    destPlatformLbl.setVisible(TCMSUIConstants.TRUE);
    trainHoldsetBtn.setVisible(TCMSUIConstants.TRUE);
    trainEvacBtn.setVisible(TCMSUIConstants.TRUE);
    trainOutOfServiceBtn.setVisible(TCMSUIConstants.TRUE);
    trainDelayBtn.setVisible(TCMSUIConstants.TRUE);

    stationGrid.setVisible(TCMSUIConstants.FALSE);
    startServiceBtn.setVisible(TCMSUIConstants.FALSE);
    destinationStSetBtn.setVisible(TCMSUIConstants.FALSE);
    autoButtonPseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    semiAutoButtonPseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    manualButtonPseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    startStSetBtn.setVisible(TCMSUIConstants.FALSE);
    trainIdSetBtn.setVisible(TCMSUIConstants.FALSE);
    if (TCMSModeEnum.valueOf(modeVal).equals(TCMSModeEnum.AUTO))
    {
      autoButtonPseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      // autoActiveGrid.setVisible(TCMSUIConstants.TRUE);
    }
    else if (TCMSModeEnum.valueOf(modeVal).equals(TCMSModeEnum.SEMI_AUTO))
    {
      destinationStSetBtn.setVisible(TCMSUIConstants.TRUE);
      startServiceBtn.setVisible(TCMSUIConstants.TRUE);
      semiAutoButtonPseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      startStSetBtn.setVisible(TCMSUIConstants.TRUE);
      trainIdSetBtn.setVisible(TCMSUIConstants.TRUE);
    }
    else if (TCMSModeEnum.valueOf(modeVal).equals(TCMSModeEnum.MANUAL))
    {
      destPlatformDownBtn.setVisible(TCMSUIConstants.FALSE);
      destPlatformUpBtn.setVisible(TCMSUIConstants.FALSE);
      skipSttaionBtn.setVisible(TCMSUIConstants.FALSE);
      destPlatformLbl.setVisible(TCMSUIConstants.FALSE);
      manualButtonPseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      trainHoldsetBtn.setVisible(TCMSUIConstants.FALSE);
      trainEvacBtn.setVisible(TCMSUIConstants.FALSE);
      trainOutOfServiceBtn.setVisible(TCMSUIConstants.FALSE);
      trainDelayBtn.setVisible(TCMSUIConstants.FALSE);

    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendModeChangeRequest(TCMSModeEnum.valueOf(modeVal));
  }

  private void updateDestinationStationLabel(String destinationStation)
  {
    if (destinationStation.equals(TCMSUIConstants.BLANK_STRING))
    {
      destinationStationLbl.setText(TCMSConstants.NO_STATION_SELECTED);

    }
    else
    {
      destinationStationLbl.setText(destinationStation);
      if (routeScreenModel.getPapisSelectedMode().get() > 0 && TCMSModeEnum
          .valueOf(routeScreenModel.getPapisSelectedMode().get()).equals(TCMSModeEnum.SEMI_AUTO))
      {
        setStationGrid(TCMSUIConstants.FALSE);
      }

    }
  }

  private void updateStartStationLabel(String startStation)
  {
    if (startStation.equals(TCMSUIConstants.BLANK_STRING))
    {
      startStationLbl.setText(TCMSConstants.NO_STATION_SELECTED);

    }
    else
    {
      startStationLbl.setText(startStation);
      if (routeScreenModel.getPapisSelectedMode().get() > 0 && TCMSModeEnum
          .valueOf(routeScreenModel.getPapisSelectedMode().get()).equals(TCMSModeEnum.SEMI_AUTO))
      {
        setStationGrid(TCMSUIConstants.FALSE);
      }
    }
  }

  private void updateTrainId(String trainId)
  {
    if (trainId.equals(TCMSUIConstants.BLANK_STRING))
    {
      trainIdLbl.setText(TCMSConstants.NO_TRAIN_ID_SELECTED);

    }
    else
    {
      trainIdLbl.setText(trainId);

    }
  }

  private void updateKeypadTrainId(String trainId)
  {
    if (trainId.equals(TCMSUIConstants.BLANK_STRING))
    {
      trainIdKeypadLbl.setText(TCMSConstants.NO_TRAIN_ID_SELECTED);

    }
    else
    {
      trainIdKeypadLbl.setText(trainId);

    }
  }

  @Override
  public void detachListeners()
  {
    routeScreenModel.getTrainId().removeListener(trainIdListener);
    routeScreenModel.getStartStation().removeListener(startStationListener);
    routeScreenModel.getDestinationStation().removeListener(destinationStationListener);
    routeScreenModel.getPapisSelectedMode().removeListener(tcmsPapisModeListener);
    routeScreenModel.getTrainOutOfService().removeListener(trainOutOfServiceListener);
    routeScreenModel.getTrainDelayState().removeListener(trainDelayListener);
    routeScreenModel.getTrainEvac().removeListener(trainEvacListener);
    routeScreenModel.getTrainHoldState().removeListener(trainHoldListener);
    routeScreenModel.getServiceState().removeListener(startServiceListener);
  }

  @FXML
  private void onModeButtonClickAction(ActionEvent event)
  {
    if (event.getSource().equals(autoModeBtn))
    {
      updateSelectedMode(TCMSModeEnum.AUTO.getModeId());
    }
    else if (event.getSource().equals(semiAutoModeBtn))
    {
      updateSelectedMode(TCMSModeEnum.SEMI_AUTO.getModeId());
    }
    else if (event.getSource().equals(manualModeBtn))
    {
      updateSelectedMode(TCMSModeEnum.MANUAL.getModeId());
    }

  }

  @FXML
  private void onSetButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(trainIdSetBtn))
    {
      setTrainIdKeypadGrid(TCMSUIConstants.TRUE);
    }
    else if (event.getSource().equals(startStSetBtn))
    {
      setStationGrid(TCMSUIConstants.TRUE);
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(VDUInputs.START_STATION_BUTTON_REQ);
    }
    else if (event.getSource().equals(destinationStSetBtn))
    {
      setStationGrid(TCMSUIConstants.TRUE);
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(VDUInputs.DEST_STATION_BUTTON_REQ);
    }

  }

  private void setTrainIdKeypadGrid(boolean keypadActive)
  {
    trainIdKeypadGrid.setVisible(keypadActive);
  }

  private void setStationGrid(boolean keypadActive)
  {
    stationGrid.setVisible(keypadActive);
  }

  @FXML
  private void onStationPopUpCloseBtnAction()
  {
    setStationGrid(TCMSUIConstants.FALSE);
  }

  @FXML
  private void onTrainIdKeypadButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(trainIdkeypadCloseBtn))
    {
      setTrainIdKeypadGrid(TCMSUIConstants.FALSE);
    }
    else if (event.getSource().equals(keypad0Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_0);
    }
    else if (event.getSource().equals(keypad1Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_1);
    }
    else if (event.getSource().equals(keypad2Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_2);
    }
    else if (event.getSource().equals(keypad3Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_3);
    }
    else if (event.getSource().equals(keypad4Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_4);
    }
    else if (event.getSource().equals(keypad5Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_5);
    }
    else if (event.getSource().equals(keypad6Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_6);
    }
    else if (event.getSource().equals(keypad7Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_7);
    }
    else if (event.getSource().equals(keypad8Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_8);
    }
    else if (event.getSource().equals(keypad9Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.NO_9);
    }
    else if (event.getSource().equals(keypadBackspaceBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.DELETE);
    }
    else if (event.getSource().equals(keypadClearBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.CLEAR);
    }
    else if (event.getSource().equals(keypadEnterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRouteKeyPadButtonRequest(KeyPadEnum.ENTER);
    }

  }

  @FXML
  private void onStartPlatformButtonAction(ActionEvent event)
  {
    // if (event.getSource().equals(startPlatformDownBtn))
    // {
    // updateStartPlatformActive(TCMSUIConstants.PLATFORM_DOWN_SELECTED);
    // }
    // else if (event.getSource().equals(startPlatformUpBtn))
    // {
    // updateStartPlatformActive(TCMSUIConstants.PLATFORM_UP_SELECTED);
    // }
  }

  @FXML
  private void onDestPlatformButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(destPlatformDownBtn))
    {
      updateDestinationPlatformActive(TCMSUIConstants.PLATFORM_DOWN_SELECTED);
    }
    else if (event.getSource().equals(destPlatformUpBtn))
    {
      updateDestinationPlatformActive(TCMSUIConstants.PLATFORM_UP_SELECTED);
    }
  }

  /**
   * Builds the station list UI with ToggleButtons to select station.
   * 
   * @param listMap
   *          the map of station id and station name
   */
  void buildStationListUI(List<StationDetailModel> listMap)
  {

    stationDetailGrid.getChildren().clear();
    stationListToggleGroup.getToggles().clear();
    stationListToggleGroup = new ToggleGroup();
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
          testButton.setText(station.getStationCode());
          testButton.setPrefWidth(BUTTON_WIDTH);
          testButton.setAlignment(Pos.CENTER_LEFT);
          testButton.setPrefHeight(BUTTON_HEIGHT);
          testButton.setUserData(new StationScreenCommandRequest(scenarioCarIndex,
              StationCommand.REQUEST_STATION_SELECTED, station.getStationId(), 0));

          testButton.setToggleGroup(stationListToggleGroup);

          stationDetailGrid.add(testButton, column, row);
        }

      }

    stationListToggleGroup.selectedToggleProperty()
        .addListener(new WeakChangeListener<>(selectedToggleListener));
    //
    // messageListScreenModel.getStationListSelectedStationProperty()
    // .addListener(new
    // WeakChangeListener<>(stationListSelectedStationListener));
  }

  @FXML
  private void onStationEnterBtn(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.STATION_ENTER_REQ);
  }

  @FXML
  private void trainHoldsetBtnAction(ActionEvent event)
  {
    if (routeScreenModel.getTrainHoldState().get() == ApplicationConstants.SET_VALUE)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.TRAIN_HOLD_BUTTON_REQ, 0);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.TRAIN_HOLD_BUTTON_REQ, 1);
    }
  }

  @FXML
  private void trainEvacBtnAction(ActionEvent event)
  {
    if (routeScreenModel.getPapisSelectedMode().get() > 0
        && TCMSModeEnum.valueOf(routeScreenModel.getPapisSelectedMode().get()).equals(TCMSModeEnum.AUTO))
    {

      setTrainEvac();
    }
    else if (routeScreenModel.getPapisSelectedMode().get() > 0
        && TCMSModeEnum.valueOf(routeScreenModel.getPapisSelectedMode().get()).equals(TCMSModeEnum.SEMI_AUTO)
        && (routeScreenModel.getServiceState().get() == ApplicationConstants.SET_VALUE))
    {

      setTrainEvac();
    }
  }

  private void setTrainEvac()
  {
    if (routeScreenModel.getTrainEvac().get() == ApplicationConstants.SET_VALUE)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.TRAIN_UNDER_EVAC_SET_BUTTON_REQ, 0);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.TRAIN_UNDER_EVAC_SET_BUTTON_REQ, 1);
    }
  }

  @FXML
  private void trainOutOfServiceBtnAction(ActionEvent event)
  {
    if (routeScreenModel.getPapisSelectedMode().get() > 0
        && TCMSModeEnum.valueOf(routeScreenModel.getPapisSelectedMode().get()).equals(TCMSModeEnum.AUTO))
    {

      setTrainOutOfService();
    }
    else if (routeScreenModel.getPapisSelectedMode().get() > 0
        && TCMSModeEnum.valueOf(routeScreenModel.getPapisSelectedMode().get()).equals(TCMSModeEnum.SEMI_AUTO)
        && (routeScreenModel.getServiceState().get() == ApplicationConstants.SET_VALUE))
    {

      setTrainOutOfService();
    }

  }

  private void setTrainOutOfService()
  {
    if (routeScreenModel.getTrainOutOfService().get() == ApplicationConstants.SET_VALUE)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.TRAIN_OUT_OF_SERVICE_SET_BUTTON_REQ, 0);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.TRAIN_OUT_OF_SERVICE_SET_BUTTON_REQ, 1);
    }
  }

  @FXML
  private void trainDelayBtnAction(ActionEvent event)
  {
    if (routeScreenModel.getPapisSelectedMode().get() > 0
        && TCMSModeEnum.valueOf(routeScreenModel.getPapisSelectedMode().get()).equals(TCMSModeEnum.AUTO))
    {

      setTrainDelay();
    }
    else if (routeScreenModel.getPapisSelectedMode().get() > 0
        && TCMSModeEnum.valueOf(routeScreenModel.getPapisSelectedMode().get()).equals(TCMSModeEnum.SEMI_AUTO)
        && (routeScreenModel.getServiceState().get() == ApplicationConstants.SET_VALUE))
    {

      setTrainDelay();
    }

  }

  private void setTrainDelay()
  {
    if (routeScreenModel.getTrainDelayState().get() == ApplicationConstants.SET_VALUE)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.DELAY_IN_SERVICE_BUTTON_REQ, 0);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.DELAY_IN_SERVICE_BUTTON_REQ, 1);
    }
  }

  @FXML
  private void skipSttaionBtnAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SKIP_STATION_SCREEN, frontend);
  }

  @FXML
  private void startServiceBtnAction(ActionEvent event)
  {
    if (routeScreenModel.getServiceState().get() == ApplicationConstants.SET_VALUE)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.START_SERVICE_BUTTON_REQ,
          0);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.START_SERVICE_BUTTON_REQ,
          1);
    }

  }

}
