/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.NEXT_STATION_SCREEN_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.NEXT_STATION_SCREEN_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.NEXT_STATION_SCREEN_OK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.NEXT_STATION_SCREEN_UP_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.NextStationSelectionScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.PapisCommonPanelBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.NextStationSelectionScreenModel;
import com.sydac.mmrbem.papis.fe.gui.model.PapisCommonPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class NextStationSelectionScreenController extends AbstractPAPISController
{

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

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
  private Label stOption7;

  @FXML
  private Label stOption8;

  @FXML
  @CommsNumber(NEXT_STATION_SCREEN_UP_BUTTON)
  private Button nextStationListUpBtn;

  @FXML
  @CommsNumber(NEXT_STATION_SCREEN_DOWN_BUTTON)
  private Button nextStationListDownBtn;

  @FXML
  @CommsNumber(NEXT_STATION_SCREEN_OK_BUTTON)
  private Button nextStScreenOkBtn;

  @FXML
  @CommsNumber(NEXT_STATION_SCREEN_BACK_BUTTON)
  private Button nextStScreenBackBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<? super ObservableList<StationDetailModel>> stationListListener;

  private ChangeListener<String> stationSelectionListener;

  private Map<Integer, Label> stationOptionsMap = new HashMap<>();

  private NextStationSelectionScreenModel nextStationSelectionScreenModel;

  private HeaderDateTimeModel headerDateTimeModel;

  private Integer stationId = 0;

  private Integer stationOptId1 = 0;

  private Integer stationOptId2 = 1;

  private Integer stationOptId3 = 2;

  private Integer stationOptId4 = 3;

  private Integer stationOptId5 = 4;

  private Integer stationOptId6 = 5;

  private Integer stationOptId7 = 6;

  private Integer stationOptId8 = 7;

  private NodePseudoClassProperty upButtonNodePseudoClassProperty;

  private NodePseudoClassProperty downButtonNodePseudoClassProperty;

  private PapisCommonPanelModel papisCommonPanelModel;

  private ChangeListener<Number> resetSelectedButtonListener;

  private ChangeListener<Number> nextStationUpDownButtonListener;

  private int resetSelectedIndex = 0;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    nextStationSelectionScreenModel.getStationDetailList().removeListener(stationListListener);
    nextStationSelectionScreenModel.getNextStationNameProperty().removeListener(stationSelectionListener);
    papisCommonPanelModel.getCurrentScreenId().removeListener(resetSelectedButtonListener);
    nextStationSelectionScreenModel.getNextStationSelected().removeListener(nextStationUpDownButtonListener);

  }

  @Override
  public void initializeImpl()
  {
    nextStationSelectionScreenModel = new NextStationSelectionScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new NextStationSelectionScreenBinder(nextStationSelectionScreenModel));

    papisCommonPanelModel = new PapisCommonPanelModel(scenarioCarIndex);
    papisScreenBinders.add(new PapisCommonPanelBinder(papisCommonPanelModel));

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());

    stationOptionsMap.put(stationOptId1, stOption1);
    stationOptionsMap.put(stationOptId2, stOption2);
    stationOptionsMap.put(stationOptId3, stOption3);
    stationOptionsMap.put(stationOptId4, stOption4);
    stationOptionsMap.put(stationOptId5, stOption5);
    stationOptionsMap.put(stationOptId6, stOption6);
    stationOptionsMap.put(stationOptId7, stOption7);
    stationOptionsMap.put(stationOptId8, stOption8);

    stationListListener = (observable, oldVal, newVal) -> updateStationOptions();
    nextStationSelectionScreenModel.getStationDetailList().addListener(stationListListener);

    stationSelectionListener = (observable, oldVal, newVal) -> updateNextStationNameLabel(newVal);
    nextStationSelectionScreenModel.getNextStationNameProperty().addListener(stationSelectionListener);

    resetSelectedButtonListener = (observable, oldVal, newVal) -> resetUpAndDownButton();
    papisCommonPanelModel.getCurrentScreenId().addListener(resetSelectedButtonListener);

    upButtonNodePseudoClassProperty = new NodePseudoClassProperty(nextStationListUpBtn);
    downButtonNodePseudoClassProperty = new NodePseudoClassProperty(nextStationListDownBtn);

    nextStationUpDownButtonListener = (observable, oldVal,
        newVal) -> updateNextStationId(nextStationSelectionScreenModel.getNextStationSelected().get());
    nextStationSelectionScreenModel.getNextStationSelected().addListener(nextStationUpDownButtonListener);

    updateStationOptions();
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
    for (int optionsCounter = 0; optionsCounter < stationOptionsMap.size(); optionsCounter++)
    {
      stationOptionsMap.get(optionsCounter).setText(ApplicationConstants.BLANK);
      stationOptionsMap.get(optionsCounter).getStyleClass().clear();
      stationOptionsMap.get(optionsCounter).setVisible(false);
    }

    for (int optionsCounter = 0; optionsCounter < nextStationSelectionScreenModel.getStationDetailList()
        .size(); optionsCounter++)
    {
      String station = nextStationSelectionScreenModel.getStationDetailList().get(optionsCounter)
          .getStationName();

      if (station != null)
      {
        stationOptionsMap.get(optionsCounter).setText(station);
        stationOptionsMap.get(optionsCounter).getStyleClass()
            .add(ApplicationConstants.OPTIONS_UNSELECTED_CSS);
        stationOptionsMap.get(optionsCounter).setVisible(true);
      }
    }
    if (!nextStationSelectionScreenModel.getStationDetailList().isEmpty())
    {
      updateNextStationId(resetSelectedIndex);
    }
  }

  private void updateNextStationNameLabel(String stationName)
  {
    nextStationLbl.setText(stationName);
  }

  private void updateNextStationId(int index)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedNextStationId(index);

    stationId = nextStationSelectionScreenModel.getStationDetailList().get(index).getStationId();
    for (int i = 0; i < stationOptionsMap.size(); i++)
    {
      stationOptionsMap.get(i).getStyleClass().clear();
      stationOptionsMap.get(i).getStyleClass().add(ApplicationConstants.OPTIONS_UNSELECTED_CSS);
    }
    stationOptionsMap.get(index).getStyleClass().add(ApplicationConstants.OPTIONS_SELECTED_CSS);
    updateNextStationNameLabel(
        nextStationSelectionScreenModel.getStationDetailList().get(index).getStationName());
  }

  private void updateDownButtonSelectionStatus()
  {
    upButtonNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
    downButtonNodePseudoClassProperty.set(ApplicationConstants.SELECTED_CSS);
  }

  private void updateUpButtonSelectionStatus()
  {
    downButtonNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
    upButtonNodePseudoClassProperty.set(ApplicationConstants.SELECTED_CSS);
  }

  private void resetUpAndDownButton()
  {
    downButtonNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
    upButtonNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
  }

  @FXML
  private void onStOptionMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(stationOptionsMap.get(stationOptId1)))
    {
      updateNextStationId(stationOptId1);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId2)))
    {
      updateNextStationId(stationOptId2);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId3)))
    {
      updateNextStationId(stationOptId3);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId4)))
    {
      updateNextStationId(stationOptId4);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId5)))
    {
      updateNextStationId(stationOptId5);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId6)))
    {
      updateNextStationId(stationOptId6);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId7)))
    {
      updateNextStationId(stationOptId7);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId8)))
    {
      updateNextStationId(stationOptId8);
    }
  }

  @FXML
  private void onStOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(stationOptionsMap.get(stationOptId1)))
    {
      updateNextStationId(stationOptId1);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId2)))
    {
      updateNextStationId(stationOptId2);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId3)))
    {
      updateNextStationId(stationOptId3);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId4)))
    {
      updateNextStationId(stationOptId4);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId5)))
    {
      updateNextStationId(stationOptId5);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId6)))
    {
      updateNextStationId(stationOptId6);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId7)))
    {
      updateNextStationId(stationOptId7);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId8)))
    {
      updateNextStationId(stationOptId8);
    }
  }

  @FXML
  private void onNextStationListUpButtonAction(ActionEvent event)
  {
    updateUpButtonSelectionStatus();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendStationSelectionUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onNextStationListDownButtonAction(ActionEvent event)
  {
    updateDownButtonSelectionStatus();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendStationSelectionDownButtonPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onNextStScreenOkButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendNextStationIdRequest(stationId);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
    updateStationOptions();
    resetUpAndDownButton();
  }

  @FXML
  private void onNextStScreenBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
    updateStationOptions();
    resetUpAndDownButton();
  }
}
