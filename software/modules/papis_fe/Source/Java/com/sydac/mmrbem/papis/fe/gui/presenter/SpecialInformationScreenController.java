/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SPC_INFO_SCREEN_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SPC_INFO_SCREEN_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SPC_INFO_SCREEN_OK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SPC_INFO_SCREEN_STOP_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SPC_INFO_SCREEN_UP_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.SpecialInfoDetailModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.PapisCommonPanelBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.SpecialInformationScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.PapisCommonPanelModel;
import com.sydac.mmrbem.papis.fe.gui.model.SpecialInformationScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;
import javafx.scene.layout.GridPane;

public class SpecialInformationScreenController extends AbstractPAPISController
{

  @FXML
  private GridPane playCountOptionsGrid;

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label currentSpcInfoLbl;

  @FXML
  private Label noOfTimesLbl;

  @FXML
  private Label dropDownArrowLbl;

  @FXML
  private Label spcInfoOption1;

  @FXML
  private Label spcInfoOption2;

  @FXML
  private Label spcInfoOption3;

  @FXML
  private Label spcInfoOption4;

  @FXML
  private Label spcInfoOption5;

  @FXML
  private Label spcInfoOption6;

  @FXML
  private Label spcInfoOption7;

  @FXML
  private Label spcInfoOption8;

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
  @CommsNumber(SPC_INFO_SCREEN_OK_BUTTON)
  private Button spcInfoOkBtn;

  @FXML
  @CommsNumber(SPC_INFO_SCREEN_STOP_BUTTON)
  private Button spcInfoStopBtn;

  @FXML
  @CommsNumber(SPC_INFO_SCREEN_BACK_BUTTON)
  private Button spcInfoBackBtn;

  @FXML
  @CommsNumber(SPC_INFO_SCREEN_UP_BUTTON)
  private Button spcInfoListUpBtn;

  @FXML
  @CommsNumber(SPC_INFO_SCREEN_DOWN_BUTTON)
  private Button spcInfoListDownBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<? super ObservableList<SpecialInfoDetailModel>> spcInfoListListener;

  private Map<Integer, Label> spcInfoOptionsMap = new HashMap<>();

  private Map<Integer, Label> playCountOptionsMap = new HashMap<>();

  private SpecialInformationScreenModel specialInformationScreenModel;

  private HeaderDateTimeModel headerDateTimeModel;

  private Integer spcInfoId = 0;

  private boolean gridVisibleFlag = false;

  private Integer spcInfoOptId1 = 0;

  private Integer spcInfoOptId2 = 1;

  private Integer spcInfoOptId3 = 2;

  private Integer spcInfoOptId4 = 3;

  private Integer spcInfoOptId5 = 4;

  private Integer spcInfoOptId6 = 5;

  private Integer spcInfoOptId7 = 6;

  private Integer spcInfoOptId8 = 7;

  private Integer playCountOptId1 = 1;

  private Integer playCountOptId2 = 2;

  private Integer playCountOptId3 = 3;

  private Integer playCountOptId4 = 4;

  private Integer playCountOptId5 = 5;

  private Integer playCountOptId6 = 6;

  private Integer playCountOptId7 = 7;

  private Integer playCountOptId8 = 8;

  private Integer playCountOptId9 = 9;

  private Integer playCountOptId10 = 10;

  private NodePseudoClassProperty upButtonNodePseudoClassProperty;

  private NodePseudoClassProperty downButtonNodePseudoClassProperty;

  private PapisCommonPanelModel papisCommonPanelModel;

  private ChangeListener<Number> resetSelectedButtonListener;

  private ChangeListener<Number> specialMessageSelectedListener;

  private boolean initialLoadup;

  private int firstOptionIndex = 0;

  private int defaultPlayCountOption = 1;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    specialInformationScreenModel.getSpcInfoDetailList().removeListener(spcInfoListListener);
    papisCommonPanelModel.getCurrentScreenId().removeListener(resetSelectedButtonListener);
    specialInformationScreenModel.getSpecialMessageSelected().removeListener(specialMessageSelectedListener);
  }

  @Override
  public void initializeImpl()
  {
    specialInformationScreenModel = new SpecialInformationScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new SpecialInformationScreenBinder(specialInformationScreenModel));

    papisCommonPanelModel = new PapisCommonPanelModel(scenarioCarIndex);
    papisScreenBinders.add(new PapisCommonPanelBinder(papisCommonPanelModel));

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());

    spcInfoOptionsMap.put(spcInfoOptId1, spcInfoOption1);
    spcInfoOptionsMap.put(spcInfoOptId2, spcInfoOption2);
    spcInfoOptionsMap.put(spcInfoOptId3, spcInfoOption3);
    spcInfoOptionsMap.put(spcInfoOptId4, spcInfoOption4);
    spcInfoOptionsMap.put(spcInfoOptId5, spcInfoOption5);
    spcInfoOptionsMap.put(spcInfoOptId6, spcInfoOption6);
    spcInfoOptionsMap.put(spcInfoOptId7, spcInfoOption7);
    spcInfoOptionsMap.put(spcInfoOptId8, spcInfoOption8);

    playCountOptionsMap.put(playCountOptId1, playCountOption1);
    playCountOptionsMap.put(playCountOptId2, playCountOption2);
    playCountOptionsMap.put(playCountOptId3, playCountOption3);
    playCountOptionsMap.put(playCountOptId4, playCountOption4);
    playCountOptionsMap.put(playCountOptId5, playCountOption5);
    playCountOptionsMap.put(playCountOptId6, playCountOption6);
    playCountOptionsMap.put(playCountOptId7, playCountOption7);
    playCountOptionsMap.put(playCountOptId8, playCountOption8);
    playCountOptionsMap.put(playCountOptId9, playCountOption9);
    playCountOptionsMap.put(playCountOptId10, playCountOption10);

    spcInfoListListener = (observable, oldVal, newVal) -> updateSpcInfoOptions();
    specialInformationScreenModel.getSpcInfoDetailList().addListener(spcInfoListListener);

    resetSelectedButtonListener = (observable, oldVal, newVal) -> resetUpAndDownButton();
    papisCommonPanelModel.getCurrentScreenId().addListener(resetSelectedButtonListener);

    specialMessageSelectedListener = (observable, oldVal,
        newVal) -> updateSelectedSpcInfoId(specialInformationScreenModel.getSpecialMessageSelected().get());
    specialInformationScreenModel.getSpecialMessageSelected().addListener(specialMessageSelectedListener);

    upButtonNodePseudoClassProperty = new NodePseudoClassProperty(spcInfoListUpBtn);
    downButtonNodePseudoClassProperty = new NodePseudoClassProperty(spcInfoListDownBtn);

    initialLoadup = true;
    updateSpcInfoOptions();
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

  private void updateSpcInfoOptions()
  {
    for (int optionsCounter = 0; optionsCounter < spcInfoOptionsMap.size(); optionsCounter++)
    {
      spcInfoOptionsMap.get(optionsCounter).setText(ApplicationConstants.BLANK);
      spcInfoOptionsMap.get(optionsCounter).getStyleClass().clear();
      spcInfoOptionsMap.get(optionsCounter).setVisible(false);
    }

    for (int optionsCounter = 0; optionsCounter < specialInformationScreenModel.getSpcInfoDetailList()
        .size(); optionsCounter++)
    {
      String spcInfo = specialInformationScreenModel.getSpcInfoDetailList().get(optionsCounter)
          .getSpecialInfoCode();

      if (spcInfo != null)
      {
        spcInfoOptionsMap.get(optionsCounter).setText(spcInfo);
        spcInfoOptionsMap.get(optionsCounter).getStyleClass()
            .add(ApplicationConstants.OPTIONS_UNSELECTED_CSS);
        spcInfoOptionsMap.get(optionsCounter).setVisible(true);
        if (spcInfoId != firstOptionIndex && specialInformationScreenModel.getSpcInfoDetailList()
            .get(optionsCounter).getSpecialInfoId() == spcInfoId)
        {
          spcInfoOptionsMap.get(optionsCounter).getStyleClass().clear();
          spcInfoOptionsMap.get(optionsCounter).getStyleClass()
              .add(ApplicationConstants.OPTIONS_SELECTED_CSS);
        }
        else if (initialLoadup && !specialInformationScreenModel.getSpcInfoDetailList().isEmpty())
        {
          PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
              .sendSelectedSpcInfoIdRequest(firstOptionIndex);
          spcInfoId = specialInformationScreenModel.getSpcInfoDetailList().get(firstOptionIndex)
              .getSpecialInfoId();
          spcInfoOptionsMap.get(firstOptionIndex).getStyleClass().clear();
          spcInfoOptionsMap.get(firstOptionIndex).getStyleClass()
              .add(ApplicationConstants.OPTIONS_SELECTED_CSS);
          updateSpcInfoNameLabel(specialInformationScreenModel.getSpcInfoDetailList().get(firstOptionIndex)
              .getSpecialInfoCode());

          PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSpcInfoSelectedId(spcInfoId);
          initialLoadup = false;
        }
      }
    }
  }

  private void updateSpcInfoNameLabel(String spcInfoName)
  {
    currentSpcInfoLbl.setText(spcInfoName);
  }

  private void updateSelectedSpcInfoId(int index)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedSpcInfoIdRequest(index);
    spcInfoId = firstOptionIndex;
    updateSpcInfoOptions();
    spcInfoId = specialInformationScreenModel.getSpcInfoDetailList().get(index).getSpecialInfoId();
    spcInfoOptionsMap.get(index).getStyleClass().clear();
    spcInfoOptionsMap.get(index).getStyleClass().add(ApplicationConstants.OPTIONS_SELECTED_CSS);
    updateSpcInfoNameLabel(
        specialInformationScreenModel.getSpcInfoDetailList().get(index).getSpecialInfoCode());

    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSpcInfoSelectedId(spcInfoId);
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
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSpcInfoPlayCount(index);
    updateCountOptionsGrid();
  }

  @FXML
  private void onSpcInfoOptionMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId1)))
    {
      updateSelectedSpcInfoId(spcInfoOptId1);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId2)))
    {
      updateSelectedSpcInfoId(spcInfoOptId2);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId3)))
    {
      updateSelectedSpcInfoId(spcInfoOptId3);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId4)))
    {
      updateSelectedSpcInfoId(spcInfoOptId4);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId5)))
    {
      updateSelectedSpcInfoId(spcInfoOptId5);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId6)))
    {
      updateSelectedSpcInfoId(spcInfoOptId6);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId7)))
    {
      updateSelectedSpcInfoId(spcInfoOptId7);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId8)))
    {
      updateSelectedSpcInfoId(spcInfoOptId8);
    }
  }

  @FXML
  private void onSpcInfoOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId1)))
    {
      updateSelectedSpcInfoId(spcInfoOptId1);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId2)))
    {
      updateSelectedSpcInfoId(spcInfoOptId2);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId3)))
    {
      updateSelectedSpcInfoId(spcInfoOptId3);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId4)))
    {
      updateSelectedSpcInfoId(spcInfoOptId4);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId5)))
    {
      updateSelectedSpcInfoId(spcInfoOptId5);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId6)))
    {
      updateSelectedSpcInfoId(spcInfoOptId6);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId7)))
    {
      updateSelectedSpcInfoId(spcInfoOptId7);
    }
    else if (event.getSource().equals(spcInfoOptionsMap.get(spcInfoOptId8)))
    {
      updateSelectedSpcInfoId(spcInfoOptId8);
    }
  }

  @FXML
  private void onPlayCountOptionMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(playCountOptionsMap.get(playCountOptId1)))
    {
      updateSelectedPlayCount(playCountOptId1);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId2)))
    {
      updateSelectedPlayCount(playCountOptId2);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId3)))
    {
      updateSelectedPlayCount(playCountOptId3);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId4)))
    {
      updateSelectedPlayCount(playCountOptId4);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId5)))
    {
      updateSelectedPlayCount(playCountOptId5);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId6)))
    {
      updateSelectedPlayCount(playCountOptId6);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId7)))
    {
      updateSelectedPlayCount(playCountOptId7);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId8)))
    {
      updateSelectedPlayCount(playCountOptId8);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId9)))
    {
      updateSelectedPlayCount(playCountOptId9);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId10)))
    {
      updateSelectedPlayCount(playCountOptId10);
    }
  }

  @FXML
  private void onPlayCountOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(playCountOptionsMap.get(playCountOptId1)))
    {
      updateSelectedPlayCount(playCountOptId1);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId2)))
    {
      updateSelectedPlayCount(playCountOptId2);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId3)))
    {
      updateSelectedPlayCount(playCountOptId3);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId4)))
    {
      updateSelectedPlayCount(playCountOptId4);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId5)))
    {
      updateSelectedPlayCount(playCountOptId5);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId6)))
    {
      updateSelectedPlayCount(playCountOptId6);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId7)))
    {
      updateSelectedPlayCount(playCountOptId7);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId8)))
    {
      updateSelectedPlayCount(playCountOptId8);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId9)))
    {
      updateSelectedPlayCount(playCountOptId9);
    }
    else if (event.getSource().equals(playCountOptionsMap.get(playCountOptId10)))
    {
      updateSelectedPlayCount(playCountOptId10);
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

  private void resetUpAndDownButton()
  {
    downButtonNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);
    upButtonNodePseudoClassProperty.set(ApplicationConstants.UNSELECTED_CSS);

  }

  @FXML
  private void onSpcInfoListUpButtonAction(ActionEvent event)
  {
    updateUpButtonSelectionStatus();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSpcInfoListUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onSpcInfoListDownButtonAction(ActionEvent event)
  {
    updateDownButtonSelectionStatus();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSpcInfoListDownButtonPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onSpcInfoOkButtonAction(ActionEvent event)
  {
    resetUpAndDownButton();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSpcInfoOkButtonPressedReq(ApplicationConstants.OK_PRESSED);
  }

  @FXML
  private void onSpcInfoStopButtonAction(ActionEvent event)
  {
    resetUpAndDownButton();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSpcInfoStopAnnouncementRequest(ApplicationConstants.STOP_ANNOUNCEMENT);
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
  private void onSpcInfoBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN);
    resetUpAndDownButton();
  }
}