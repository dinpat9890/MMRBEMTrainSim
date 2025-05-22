/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.EMG_INFO_SCREEN_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.EMG_INFO_SCREEN_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.EMG_INFO_SCREEN_OK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.EMG_INFO_SCREEN_STOP_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.EMG_INFO_SCREEN_UP_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.EmergencyInfoDetailModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.EmergencyInformationScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.PapisCommonPanelBinder;
import com.sydac.mmrbem.papis.fe.gui.model.EmergencyInformationScreenModel;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.PapisCommonPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;
import javafx.scene.layout.GridPane;

public class EmergencyInformationScreenController extends AbstractPAPISController
{

  @FXML
  private GridPane playCountOptionsGrid;

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label currentEmgInfoLbl;

  @FXML
  private Label noOfTimesLbl;

  @FXML
  private Label dropDownArrowLbl;

  @FXML
  private Label emgInfoOption1;

  @FXML
  private Label emgInfoOption2;

  @FXML
  private Label emgInfoOption3;

  @FXML
  private Label emgInfoOption4;

  @FXML
  private Label emgInfoOption5;

  @FXML
  private Label emgInfoOption6;

  @FXML
  private Label emgInfoOption7;

  @FXML
  private Label emgInfoOption8;

  @FXML
  private Label playCountOption1;

  @FXML
  private Label playCountOption2;

  @FXML
  private Label playCountOption3;

  @FXML
  private Label playCountOption4;

  @FXML
  private Label playCountOption5;

  @FXML
  private Label playCountOption6;

  @FXML
  private Label playCountOption7;

  @FXML
  private Label playCountOption8;

  @FXML
  private Label playCountOption9;

  @FXML
  private Label playCountOption10;

  @FXML
  @CommsNumber(EMG_INFO_SCREEN_OK_BUTTON)
  private Button emgInfoOkBtn;

  @FXML
  @CommsNumber(EMG_INFO_SCREEN_STOP_BUTTON)
  private Button emgInfoStopBtn;

  @FXML
  @CommsNumber(EMG_INFO_SCREEN_BACK_BUTTON)
  private Button emgInfoBackBtn;

  @FXML
  @CommsNumber(EMG_INFO_SCREEN_UP_BUTTON)
  private Button emgInfoListUpBtn;

  @FXML
  @CommsNumber(EMG_INFO_SCREEN_DOWN_BUTTON)
  private Button emgInfoListDownBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<? super ObservableList<EmergencyInfoDetailModel>> emgInfoListListener;

  private Map<Integer, Label> emgInfoOptionsMap = new HashMap<>();

  private Map<Integer, Label> playCountOptionsMap = new HashMap<>();

  private HeaderDateTimeModel headerDateTimeModel;

  private Integer emgInfoId = 0;

  private boolean gridVisibleFlag = false;

  private static final Integer EMG_MAP_ID_1 = 0;

  private static final Integer EMG_MAP_ID_2 = 1;

  private static final Integer EMG_MAP_ID_3 = 2;

  private static final Integer EMG_MAP_ID_4 = 3;

  private static final Integer EMG_MAP_ID_5 = 4;

  private static final Integer EMG_MAP_ID_6 = 5;

  private static final Integer EMG_MAP_ID_7 = 6;

  private static final Integer EMG_MAP_ID_8 = 7;

  private static final Integer PLAY_COUNT_MAP_ID_1 = 1;

  private static final Integer PLAY_COUNT_MAP_ID_2 = 2;

  private static final Integer PLAY_COUNT_MAP_ID_3 = 3;

  private static final Integer PLAY_COUNT_MAP_ID_4 = 4;

  private static final Integer PLAY_COUNT_MAP_ID_5 = 5;

  private static final Integer PLAY_COUNT_MAP_ID_6 = 6;

  private static final Integer PLAY_COUNT_MAP_ID_7 = 7;

  private static final Integer PLAY_COUNT_MAP_ID_8 = 8;

  private static final Integer PLAY_COUNT_MAP_ID_9 = 9;

  private static final Integer PLAY_COUNT_MAP_ID_10 = 10;

  private EmergencyInformationScreenModel emergencyInformationScreenModel;

  private NodePseudoClassProperty upButtonNodePseudoClassProperty;

  private NodePseudoClassProperty downButtonNodePseudoClassProperty;

  private PapisCommonPanelModel papisCommonPanelModel;

  private ChangeListener<Number> resetSelectedButtonListener;

  private ChangeListener<Number> emergencyInformationListener;

  private boolean initialLoadup;

  private int firstOptionIndex = 0;

  private int defaultPlayCountOption = 1;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    emergencyInformationScreenModel.getEmgInfoDetailList().removeListener(emgInfoListListener);
    papisCommonPanelModel.getCurrentScreenId().removeListener(resetSelectedButtonListener);
    emergencyInformationScreenModel.getEmergencyInfromationSelected()
        .removeListener(emergencyInformationListener);
  }

  @Override
  public void initializeImpl()
  {
    emergencyInformationScreenModel = new EmergencyInformationScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new EmergencyInformationScreenBinder(emergencyInformationScreenModel));

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    papisCommonPanelModel = new PapisCommonPanelModel(scenarioCarIndex);
    papisScreenBinders.add(new PapisCommonPanelBinder(papisCommonPanelModel));

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());

    emgInfoOptionsMap.put(EMG_MAP_ID_1, emgInfoOption1);
    emgInfoOptionsMap.put(EMG_MAP_ID_2, emgInfoOption2);
    emgInfoOptionsMap.put(EMG_MAP_ID_3, emgInfoOption3);
    emgInfoOptionsMap.put(EMG_MAP_ID_4, emgInfoOption4);
    emgInfoOptionsMap.put(EMG_MAP_ID_5, emgInfoOption5);
    emgInfoOptionsMap.put(EMG_MAP_ID_6, emgInfoOption6);
    emgInfoOptionsMap.put(EMG_MAP_ID_7, emgInfoOption7);
    emgInfoOptionsMap.put(EMG_MAP_ID_8, emgInfoOption8);

    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_1, playCountOption1);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_2, playCountOption2);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_3, playCountOption3);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_4, playCountOption4);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_5, playCountOption5);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_6, playCountOption6);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_7, playCountOption7);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_8, playCountOption8);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_9, playCountOption9);
    playCountOptionsMap.put(PLAY_COUNT_MAP_ID_10, playCountOption10);

    emgInfoListListener = (observable, oldVal, newVal) -> updateEmgInfoOptions();
    emergencyInformationScreenModel.getEmgInfoDetailList().addListener(emgInfoListListener);

    emergencyInformationListener = (observable, oldVal, newVal) -> updateSelectedEmgInfoId(
        emergencyInformationScreenModel.getEmergencyInfromationSelected().get());
    emergencyInformationScreenModel.getEmergencyInfromationSelected()
        .addListener(emergencyInformationListener);

    upButtonNodePseudoClassProperty = new NodePseudoClassProperty(emgInfoListUpBtn);
    downButtonNodePseudoClassProperty = new NodePseudoClassProperty(emgInfoListDownBtn);

    resetSelectedButtonListener = (observable, oldVal, newVal) -> resetUpAndDownButton();
    papisCommonPanelModel.getCurrentScreenId().addListener(resetSelectedButtonListener);

    initialLoadup = true;
    updateEmgInfoOptions();
    updateSelectedPlayCount(defaultPlayCountOption);
    updateCountOptionsGrid();
  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void updateEmgInfoOptions()
  {
    for (int optionsCounter = 0; optionsCounter < emgInfoOptionsMap.size(); optionsCounter++)
    {
      emgInfoOptionsMap.get(optionsCounter).setText(""); //$NON-NLS-1$
      emgInfoOptionsMap.get(optionsCounter).getStyleClass().clear();
      emgInfoOptionsMap.get(optionsCounter).setVisible(false);
    }

    for (int optionsCounter = 0; optionsCounter < emergencyInformationScreenModel.getEmgInfoDetailList()
        .size(); optionsCounter++)
    {
      String emgInfo = emergencyInformationScreenModel.getEmgInfoDetailList().get(optionsCounter)
          .getEmgInfoCode();

      if (emgInfo != null)
      {
        emgInfoOptionsMap.get(optionsCounter).setText(emgInfo);
        emgInfoOptionsMap.get(optionsCounter).getStyleClass()
            .add(ApplicationConstants.OPTIONS_UNSELECTED_CSS);
        emgInfoOptionsMap.get(optionsCounter).setVisible(true);

        if (emgInfoId != firstOptionIndex && emergencyInformationScreenModel.getEmgInfoDetailList()
            .get(optionsCounter).getEmgInfoId() == emgInfoId)
        {
          emgInfoOptionsMap.get(optionsCounter).getStyleClass().clear();
          emgInfoOptionsMap.get(optionsCounter).getStyleClass()
              .add(ApplicationConstants.OPTIONS_SELECTED_CSS);
        }
        else if (initialLoadup && !emergencyInformationScreenModel.getEmgInfoDetailList().isEmpty())
        {
          PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
              .sendSelectedEmgInfoIdRequest(firstOptionIndex);
          emgInfoId = emergencyInformationScreenModel.getEmgInfoDetailList().get(firstOptionIndex)
              .getEmgInfoId();
          emgInfoOptionsMap.get(firstOptionIndex).getStyleClass().clear();
          emgInfoOptionsMap.get(firstOptionIndex).getStyleClass()
              .add(ApplicationConstants.OPTIONS_SELECTED_CSS);
          updateEmgInfoNameLabel(
              emergencyInformationScreenModel.getEmgInfoDetailList().get(firstOptionIndex).getEmgInfoCode());

          PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendEmgInfoSelectedId(emgInfoId);
          initialLoadup = false;
        }
      }
    }
  }

  private void updateEmgInfoNameLabel(String emgInfoName)
  {
    currentEmgInfoLbl.setText(emgInfoName);
  }

  private void updateSelectedEmgInfoId(int index)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedEmgInfoIdRequest(index);
    emgInfoId = firstOptionIndex;
    updateEmgInfoOptions();
    emgInfoId = emergencyInformationScreenModel.getEmgInfoDetailList().get(index).getEmgInfoId();
    emgInfoOptionsMap.get(index).getStyleClass().clear();
    emgInfoOptionsMap.get(index).getStyleClass().add(ApplicationConstants.OPTIONS_UNSELECTED_CSS);
    emgInfoOptionsMap.get(index).getStyleClass().add(ApplicationConstants.OPTIONS_SELECTED_CSS);

    updateEmgInfoNameLabel(
        emergencyInformationScreenModel.getEmgInfoDetailList().get(index).getEmgInfoCode());

    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendEmgInfoSelectedId(emgInfoId);
  }

  private void updateCountOptionsGrid()
  {
    gridVisibleFlag = !gridVisibleFlag;
    playCountOptionsGrid.setVisible(gridVisibleFlag);
  }

  private void updateNoOfTimesLabel(String count)
  {
    noOfTimesLbl.setText(count);
  }

  private void updateSelectedPlayCount(int index)
  {
    updateNoOfTimesLabel(String.valueOf(index));
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendEmgInfoPlayCount(index);
    updateCountOptionsGrid();
  }

  @FXML
  private void onEmgInfoOptionMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_1)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_1);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_2)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_2);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_3)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_3);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_4)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_4);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_5)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_5);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_6)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_6);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_7)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_7);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_8)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_8);
    }
  }

  @FXML
  private void onEmgInfoOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_1)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_1);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_2)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_2);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_3)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_3);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_4)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_4);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_5)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_5);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_6)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_6);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_7)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_7);
    }
    else if (event.getSource().equals(emgInfoOptionsMap.get(EMG_MAP_ID_8)))
    {
      updateSelectedEmgInfoId(EMG_MAP_ID_8);
    }
  }

  @FXML
  private void onPlayCountOptionMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_1)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_1);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_2)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_2);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_3)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_3);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_4)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_4);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_5)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_5);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_6)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_6);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_7)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_7);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_8)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_8);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_9)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_9);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_10)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_10);
    }
  }

  @FXML
  private void onPlayCountOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_1)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_1);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_2)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_2);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_3)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_3);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_4)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_4);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_5)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_5);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_6)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_6);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_7)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_7);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_8)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_8);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_9)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_9);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(PLAY_COUNT_MAP_ID_10)))
    {
      updateSelectedPlayCount(PLAY_COUNT_MAP_ID_10);
    }
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

  @FXML
  private void onDropDownArrowMouseClicked(MouseEvent event)
  {
    updateCountOptionsGrid();
  }

  @FXML
  private void onDropDownArrowTouchPressed(TouchEvent event)
  {
    // updateCountOptionsGrid();
  }

  @FXML
  private void onEmgInfoListUpButtonAction(ActionEvent event)
  {
    updateUpButtonSelectionStatus();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendEmgInfoListUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onEmgInfoListDownButtonAction(ActionEvent event)
  {
    updateDownButtonSelectionStatus();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendEmgInfoListDownButtonPressed(ApplicationConstants.DOWN_PRESSED);

  }

  @FXML
  private void onEmgInfoOkButtonAction(ActionEvent event)
  {
    resetUpAndDownButton();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendEmgInfoOkButtonPressedReq(ApplicationConstants.OK_PRESSED);
  }

  private void resetUpAndDownButton()
  {
    downButtonNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
    upButtonNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);

  }

  @FXML
  private void onEmgInfoStopButtonAction(ActionEvent event)
  {
    resetUpAndDownButton();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendEmgInfoStopAnnouncementRequest(ApplicationConstants.STOP_ANNOUNCEMENT);
  }

  @FXML
  private void onEmgInfoBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN);
    resetUpAndDownButton();
  }
}
