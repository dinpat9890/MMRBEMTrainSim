/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.TERMINAL_STATION_SCREEN_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.TERMINAL_STATION_SCREEN_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.TERMINAL_STATION_SCREEN_OK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.TERMINAL_STATION_SCREEN_UP_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.PapisCommonPanelBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.TerminalStationSelectionScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.PapisCommonPanelModel;
import com.sydac.mmrbem.papis.fe.gui.model.TerminalStationSelectionScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class TerminalStationSelectionScreenController extends AbstractPAPISController
{

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label terminalStationLbl;

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
  @CommsNumber(TERMINAL_STATION_SCREEN_UP_BUTTON)
  private Button terminalStListUpBtn;

  @FXML
  @CommsNumber(TERMINAL_STATION_SCREEN_DOWN_BUTTON)
  private Button terminalStationListDownBtn;

  @FXML
  @CommsNumber(TERMINAL_STATION_SCREEN_OK_BUTTON)
  private Button terminalStScreenOkBtn;

  @FXML
  @CommsNumber(TERMINAL_STATION_SCREEN_BACK_BUTTON)
  private Button terminalStScreenBackBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<? super ObservableList<StationDetailModel>> stationListListener;

  private ChangeListener<String> stationSelectionListener;

  private Map<Integer, Label> stationOptionsMap = new HashMap<>();

  private TerminalStationSelectionScreenModel terminalStationSelectionScreenModel;

  private HeaderDateTimeModel headerDateTimeModel;

  private Integer stationId = 0;

  private Integer stationOptMapId1 = 0;

  private Integer stationOptMapId2 = 1;

  private Integer stationOptMapId3 = 2;

  private Integer stationOptMapId4 = 3;

  private Integer stationOptMapId5 = 4;

  private Integer stationOptMapId6 = 5;

  private Integer stationOptMapId7 = 6;

  private Integer stationOptMapId8 = 7;

  private NodePseudoClassProperty upButtonNodePseudoClassProperty;

  private NodePseudoClassProperty downButtonNodePseudoClassProperty;

  private PapisCommonPanelModel papisCommonPanelModel;

  private ChangeListener<Number> resetSelectedButtonListener;

  private ChangeListener<Number> terminalStationUpDownButtonListener;

  private int resetSelectedIndex = 0;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    terminalStationSelectionScreenModel.getStationDetailList().removeListener(stationListListener);
    terminalStationSelectionScreenModel.getTerminalStationNameProperty()
        .removeListener(stationSelectionListener);
    papisCommonPanelModel.getCurrentScreenId().removeListener(resetSelectedButtonListener);
    terminalStationSelectionScreenModel.getTerminalStationSelected()
        .removeListener(terminalStationUpDownButtonListener);
  }

  @Override
  public void initializeImpl()
  {
    terminalStationSelectionScreenModel = new TerminalStationSelectionScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new TerminalStationSelectionScreenBinder(terminalStationSelectionScreenModel));

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
    stationOptionsMap.put(stationOptMapId7, stOption7);
    stationOptionsMap.put(stationOptMapId8, stOption8);

    stationListListener = (observable, oldVal, newVal) -> updateStationOptions();
    terminalStationSelectionScreenModel.getStationDetailList().addListener(stationListListener);

    stationSelectionListener = (observable, oldVal, newVal) -> updateTerminalStationNameLabel(newVal);
    terminalStationSelectionScreenModel.getTerminalStationNameProperty()
        .addListener(stationSelectionListener);
    upButtonNodePseudoClassProperty = new NodePseudoClassProperty(terminalStListUpBtn);
    downButtonNodePseudoClassProperty = new NodePseudoClassProperty(terminalStationListDownBtn);

    resetSelectedButtonListener = (observable, oldVal, newVal) -> resetUpAndDownButton();
    papisCommonPanelModel.getCurrentScreenId().addListener(resetSelectedButtonListener);

    terminalStationUpDownButtonListener = (observable, oldVal, newVal) -> updateTerminalStationId(
        terminalStationSelectionScreenModel.getTerminalStationSelected().get());
    terminalStationSelectionScreenModel.getTerminalStationSelected()
        .addListener(terminalStationUpDownButtonListener);

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
      stationOptionsMap.get(optionsCounter).setText(""); //$NON-NLS-1$
      stationOptionsMap.get(optionsCounter).getStyleClass().clear();
      stationOptionsMap.get(optionsCounter).setVisible(false);
    }

    for (int optionsCounter = 0; optionsCounter < terminalStationSelectionScreenModel.getStationDetailList()
        .size(); optionsCounter++)
    {
      String station = terminalStationSelectionScreenModel.getStationDetailList().get(optionsCounter)
          .getStationName();

      if (station != null)
      {
        stationOptionsMap.get(optionsCounter).setText(station);
        stationOptionsMap.get(optionsCounter).getStyleClass()
            .add(ApplicationConstants.OPTIONS_UNSELECTED_CSS);
        stationOptionsMap.get(optionsCounter).setVisible(true);
      }
    }
    if (!terminalStationSelectionScreenModel.getStationDetailList().isEmpty())
    {
      updateTerminalStationId(resetSelectedIndex);
    }
  }

  private void updateTerminalStationNameLabel(String stationName)
  {
    terminalStationLbl.setText(stationName);
  }

  private void updateTerminalStationId(int index)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedTerminalStationId(index);

    stationId = terminalStationSelectionScreenModel.getStationDetailList().get(index).getStationId();
    for (int i = 0; i < stationOptionsMap.size(); i++)
    {
      stationOptionsMap.get(i).getStyleClass().clear();
      stationOptionsMap.get(i).getStyleClass().add(ApplicationConstants.OPTIONS_UNSELECTED_CSS);
    }
    stationOptionsMap.get(index).getStyleClass().add(ApplicationConstants.OPTIONS_SELECTED_CSS);
    updateTerminalStationNameLabel(
        terminalStationSelectionScreenModel.getStationDetailList().get(index).getStationName());
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
    if (event.getSource().equals(stationOptionsMap.get(stationOptMapId1)))
    {
      updateTerminalStationId(stationOptMapId1);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId2)))
    {
      updateTerminalStationId(stationOptMapId2);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId3)))
    {
      updateTerminalStationId(stationOptMapId3);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId4)))
    {
      updateTerminalStationId(stationOptMapId4);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId5)))
    {
      updateTerminalStationId(stationOptMapId5);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId6)))
    {
      updateTerminalStationId(stationOptMapId6);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId7)))
    {
      updateTerminalStationId(stationOptMapId7);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId8)))
    {
      updateTerminalStationId(stationOptMapId8);
    }
  }

  @FXML
  private void onStOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(stationOptionsMap.get(stationOptMapId1)))
    {
      updateTerminalStationId(stationOptMapId1);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId2)))
    {
      updateTerminalStationId(stationOptMapId2);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId3)))
    {
      updateTerminalStationId(stationOptMapId3);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId4)))
    {
      updateTerminalStationId(stationOptMapId4);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId5)))
    {
      updateTerminalStationId(stationOptMapId5);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId6)))
    {
      updateTerminalStationId(stationOptMapId6);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId7)))
    {
      updateTerminalStationId(stationOptMapId7);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptMapId8)))
    {
      updateTerminalStationId(stationOptMapId8);
    }
  }

  @FXML
  private void terminalStListUpButtonAction(ActionEvent event)
  {
    updateUpButtonSelectionStatus();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendStationSelectionUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onTerminalStationListDownButtonAction(ActionEvent event)
  {
    updateDownButtonSelectionStatus();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendStationSelectionDownButtonPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onTerminalStScreenOkButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendTerminalStationIdRequest(stationId);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
    updateStationOptions();
    resetUpAndDownButton();
  }

  @FXML
  private void onTerminalStScreenBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
    updateStationOptions();
    resetUpAndDownButton();
  }
}
