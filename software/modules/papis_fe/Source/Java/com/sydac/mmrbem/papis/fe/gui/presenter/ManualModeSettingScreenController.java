/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.MANUAL_MODE_ARRIVAL_MESSAGE_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.MANUAL_MODE_DEPARTURE_MESSAGE_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.MANUAL_MODE_DOOR_OPEN_LEFT_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.MANUAL_MODE_DOOR_OPEN_RIGHT_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.MANUAL_MODE_SCREEN_BACK_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.DoorOpeningSideEnum;
import com.sydac.mmrbem.papis.common.state.ManualAnnouncementMessageType;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.ManualModeSettingScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.PapisCommonPanelBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.ManualModeSettingScreenModel;
import com.sydac.mmrbem.papis.fe.gui.model.PapisCommonPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class ManualModeSettingScreenController extends AbstractPAPISController
{

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label stationListUpLbl;

  @FXML
  private Label stationListDownLbl;

  @FXML
  private Label currentStationLbl;

  @FXML
  private Label nextStationLbl;

  @FXML
  private Label stOption1;

  @FXML
  private Label stOption2;

  @FXML
  private Label stOption3;

  @FXML
  private Label stOption4;

  @FXML
  private Label stOption5;

  @FXML
  private Label stOption6;

  @FXML
  @CommsNumber(MANUAL_MODE_DOOR_OPEN_LEFT_BUTTON)
  private Button doorOpenLeftSideBtn;

  @FXML
  @CommsNumber(MANUAL_MODE_DOOR_OPEN_RIGHT_BUTTON)
  private Button doorOpenRightSideBtn;

  @FXML
  @CommsNumber(MANUAL_MODE_ARRIVAL_MESSAGE_BUTTON)
  private Button arrivalMessageBtn;

  @FXML
  @CommsNumber(MANUAL_MODE_DEPARTURE_MESSAGE_BUTTON)
  private Button departureMessageBtn;

  @FXML
  @CommsNumber(MANUAL_MODE_SCREEN_BACK_BUTTON)
  private Button manualModeScreenBackBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<Number> resetSelectedButtonListener;

  private ChangeListener<? super ObservableList<StationDetailModel>> stationListListener;

  private NodePseudoClassProperty arrivalNodePseudoClassProperty;

  private NodePseudoClassProperty departureNodePseudoClassProperty;

  private Map<Integer, Label> stationOptionsMap = new HashMap<>();

  private HeaderDateTimeModel headerDateTimeModel;

  private Integer stationId = 0;

  private Integer stationOptMapId1 = 0;

  private Integer stationOptMapId2 = 1;

  private Integer stationOptMapId3 = 2;

  private Integer stationOptMapId4 = 3;

  private Integer stationOptMapId5 = 4;

  private Integer stationOptMapId6 = 5;

  private ManualModeSettingScreenModel manualModeSettingScreenModel;

  private PapisCommonPanelModel papisCommonPanelModel;

  private NodePseudoClassProperty leftSideNodePseudoClassProperty;

  private NodePseudoClassProperty rightSideNodePseudoClassProperty;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    manualModeSettingScreenModel.getStationDetailList().removeListener(stationListListener);
    papisCommonPanelModel.getCurrentScreenId().removeListener(resetSelectedButtonListener);
  }

  @Override
  public void initializeImpl()
  {
    manualModeSettingScreenModel = new ManualModeSettingScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new ManualModeSettingScreenBinder(manualModeSettingScreenModel));

    papisCommonPanelModel = new PapisCommonPanelModel(scenarioCarIndex);
    papisScreenBinders.add(new PapisCommonPanelBinder(papisCommonPanelModel));

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());

    stationOptionsMap.put(stationOptMapId1, stOption1);
    stationOptionsMap.put(stationOptMapId2, stOption2);
    stationOptionsMap.put(stationOptMapId3, stOption3);
    stationOptionsMap.put(stationOptMapId4, stOption4);
    stationOptionsMap.put(stationOptMapId5, stOption5);
    stationOptionsMap.put(stationOptMapId6, stOption6);

    stationListListener = (observable, oldVal, newVal) -> updateStationOptions();
    manualModeSettingScreenModel.getStationDetailList().addListener(stationListListener);

    resetSelectedButtonListener = (observable, oldVal, newVal) -> resetDoorTypeSelection();
    papisCommonPanelModel.getCurrentScreenId().addListener(resetSelectedButtonListener);

    updateStationOptions();

    arrivalNodePseudoClassProperty = new NodePseudoClassProperty(arrivalMessageBtn);
    departureNodePseudoClassProperty = new NodePseudoClassProperty(departureMessageBtn);

    leftSideNodePseudoClassProperty = new NodePseudoClassProperty(doorOpenLeftSideBtn);
    rightSideNodePseudoClassProperty = new NodePseudoClassProperty(doorOpenRightSideBtn);

  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void updateStationOptions()
  {
    if (stationId <= 0)
    {
      currentStationLbl.setText(ApplicationConstants.BLANK);
      nextStationLbl.setText(ApplicationConstants.BLANK);
    }
    for (int optionsCounter = 0; optionsCounter < stationOptionsMap.size(); optionsCounter++)
    {
      stationOptionsMap.get(optionsCounter).setText(ApplicationConstants.BLANK);
      stationOptionsMap.get(optionsCounter).getStyleClass().clear();
      stationOptionsMap.get(optionsCounter).setVisible(false);
    }

    for (int optionsCounter = 0; optionsCounter < manualModeSettingScreenModel.getStationDetailList()
        .size(); optionsCounter++)
    {
      String station = manualModeSettingScreenModel.getStationDetailList().get(optionsCounter)
          .getStationName();

      if (station != null)
      {
        stationOptionsMap.get(optionsCounter).setText(station);
        stationOptionsMap.get(optionsCounter).getStyleClass()
            .add(ApplicationConstants.STATION_LIST_OPTIONS_UNSELECTED_CSS);
        stationOptionsMap.get(optionsCounter).setVisible(true);
      }
    }
  }

  private void updateSelectedStationId(Integer index)
  {
    resetDoorTypeSelection();
    updateStationOptions();
    stationId = manualModeSettingScreenModel.getStationDetailList().get(index).getStationId();
    stationOptionsMap.get(index).getStyleClass().add(ApplicationConstants.STATION_LIST_OPTIONS_SELECTED_CSS);
    updateCurrentStationLabel(stationId);
    if (manualModeSettingScreenModel.getLastStationId().get() == stationId)
    {
      updateNextStationLabel(stationId);
    }
    else
    {
      if (manualModeSettingScreenModel.getStationDetailList().get(index)
          .getStationId() < manualModeSettingScreenModel.getLastStationId().get())
      {
        updateNextStationLabel(stationId + 1);
      }
      else
      {
        updateNextStationLabel(stationId - 1);
      }
    }
  }

  private void resetDoorTypeSelection()
  {
    leftSideNodePseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    rightSideNodePseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    arrivalNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
    departureNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
  }

  private void updateCurrentStationLabel(int stationId)
  {
    currentStationLbl.setText(manualModeSettingScreenModel.getStationName(stationId));
  }

  private void updateNextStationLabel(int stationId)
  {
    nextStationLbl.setText(manualModeSettingScreenModel.getStationName(stationId));
  }

  private void updateSelectedMessageTypeButton(ManualAnnouncementMessageType messageType)
  {
    arrivalNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
    departureNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
    if (messageType.equals(ManualAnnouncementMessageType.ARRIVAL))
    {
      arrivalNodePseudoClassProperty.set(ApplicationConstants.SELECTED_CSS);
    }
    else if (messageType.equals(ManualAnnouncementMessageType.DEPARTURE))
    {
      departureNodePseudoClassProperty.set(ApplicationConstants.SELECTED_CSS);
    }
  }

  @FXML
  private void onStOptionMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(stationOptionsMap.get(stationOptMapId1)))
    {
      updateSelectedStationId(stationOptMapId1);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId2)))
    {
      updateSelectedStationId(stationOptMapId2);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId3)))
    {
      updateSelectedStationId(stationOptMapId3);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId4)))
    {
      updateSelectedStationId(stationOptMapId4);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId5)))
    {
      updateSelectedStationId(stationOptMapId5);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId6)))
    {
      updateSelectedStationId(stationOptMapId6);
    }
  }

  @FXML
  private void onStOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(stationOptionsMap.get(stationOptMapId1)))
    {
      updateSelectedStationId(stationOptMapId1);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId2)))
    {
      updateSelectedStationId(stationOptMapId2);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId3)))
    {
      updateSelectedStationId(stationOptMapId3);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId4)))
    {
      updateSelectedStationId(stationOptMapId4);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId5)))
    {
      updateSelectedStationId(stationOptMapId5);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId6)))
    {
      updateSelectedStationId(stationOptMapId6);
    }
  }

  @FXML
  private void onStationListUpMouseClicked(MouseEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenStationListUpPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onStationListUpTouchPressed(TouchEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenStationListUpPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onStationListDownMouseClicked(MouseEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenStationListDownPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onStationListDownTouchPressed(TouchEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenStationListDownPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onDoorOpenLeftSideButtonAction(ActionEvent event)
  {
    doorStatusButtonSelected(DoorOpeningSideEnum.LEFT);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenDoorOpeningSide(DoorOpeningSideEnum.LEFT);
  }

  private void doorStatusButtonSelected(DoorOpeningSideEnum selectedSide)
  {
    if (selectedSide.equals(DoorOpeningSideEnum.LEFT))
    {
      leftSideNodePseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      rightSideNodePseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else if (selectedSide.equals(DoorOpeningSideEnum.RIGHT))
    {
      leftSideNodePseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
      rightSideNodePseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
  }

  @FXML
  private void onDoorOpenRightSideButtonAction(ActionEvent event)
  {
    doorStatusButtonSelected(DoorOpeningSideEnum.RIGHT);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenDoorOpeningSide(DoorOpeningSideEnum.RIGHT);
  }

  @FXML
  private void onArrivalMessageButtonAction(ActionEvent event)
  {
    messageSelectedStatus(ManualAnnouncementMessageType.ARRIVAL);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenCurrentStationSelection(stationId);
    updateSelectedMessageTypeButton(ManualAnnouncementMessageType.ARRIVAL);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenMessageTypeRequest(ManualAnnouncementMessageType.ARRIVAL);
  }

  private void messageSelectedStatus(ManualAnnouncementMessageType messageState)
  {
    if (messageState.equals(ManualAnnouncementMessageType.ARRIVAL))
    {
      arrivalNodePseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      departureNodePseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else if (messageState.equals(ManualAnnouncementMessageType.DEPARTURE))
    {
      arrivalNodePseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
      departureNodePseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
  }

  @FXML
  private void onDepartureMessageButtonAction(ActionEvent event)
  {
    messageSelectedStatus(ManualAnnouncementMessageType.DEPARTURE);

    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenCurrentStationSelection(stationId);
    updateSelectedMessageTypeButton(ManualAnnouncementMessageType.DEPARTURE);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendManualModeScreenMessageTypeRequest(ManualAnnouncementMessageType.DEPARTURE);
  }

  @FXML
  private void onManualModeBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
    stationId = 0;
    updateStationOptions();
    resetDoorTypeSelection();
  }
}
