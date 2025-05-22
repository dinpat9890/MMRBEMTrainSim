/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SKIP_LIST_ADD_STATION_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SKIP_LIST_REMOVE_STATION_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SKIP_STATION_SCREEN_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SKIP_STATION_SCREEN_OK_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.StationDetailModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.SkipStationSettingScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.SkipStationSettingScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class SkipStationSettingScreenController extends AbstractPAPISController
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
  private Label skipListUpLbl;

  @FXML
  private Label skipListDownLbl;

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
  private Label skipOption1;

  @FXML
  private Label skipOption2;

  @FXML
  private Label skipOption3;

  @FXML
  private Label skipOption4;

  @FXML
  private Label skipOption5;

  @FXML
  private Label skipOption6;

  @FXML
  @CommsNumber(SKIP_LIST_ADD_STATION_BUTTON)
  private Button addToSkipListBtn;

  @FXML
  @CommsNumber(SKIP_LIST_REMOVE_STATION_BUTTON)
  private Button removeFromSkipListBtn;

  @FXML
  @CommsNumber(SKIP_STATION_SCREEN_OK_BUTTON)
  private Button skipSettingScreenOkBtn;

  @FXML
  @CommsNumber(SKIP_STATION_SCREEN_BACK_BUTTON)
  private Button skipSettingScreenBackBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<? super ObservableList<StationDetailModel>> stationListListener;

  private ChangeListener<? super ObservableList<StationDetailModel>> skipStationListListener;

  private Map<Integer, Label> stationOptionsMap = new HashMap<>();

  private Map<Integer, Label> skipStationOptionsMap = new HashMap<>();

  private HeaderDateTimeModel headerDateTimeModel;

  private Integer stationId = 0;

  private Integer skipStationId = 0;

  private Integer stationOptId1 = 0;

  private Integer stationOptId2 = 1;

  private Integer stationOptId3 = 2;

  private Integer stationOptId4 = 3;

  private Integer stationOptId5 = 4;

  private Integer stationOptId6 = 5;

  private Integer skipOptId1 = 0;

  private Integer skipOptId2 = 1;

  private Integer skipOptId3 = 2;

  private Integer skipOptId4 = 3;

  private Integer skipOptId5 = 4;

  private Integer skipOptId6 = 5;

  private SkipStationSettingScreenModel skipStationSettingScreenModel;

  
  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    skipStationSettingScreenModel.getStationDetailList().removeListener(stationListListener);
    skipStationSettingScreenModel.getSkipStationDetailList().removeListener(skipStationListListener);
  }

  @Override
  public void initializeImpl()
  {
    skipStationSettingScreenModel = new SkipStationSettingScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new SkipStationSettingScreenBinder(skipStationSettingScreenModel));

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

    skipStationOptionsMap.put(skipOptId1, skipOption1);
    skipStationOptionsMap.put(skipOptId2, skipOption2);
    skipStationOptionsMap.put(skipOptId3, skipOption3);
    skipStationOptionsMap.put(skipOptId4, skipOption4);
    skipStationOptionsMap.put(skipOptId5, skipOption5);
    skipStationOptionsMap.put(skipOptId6, skipOption6);

    stationListListener = (observable, oldVal, newVal) -> updateStationOptions();
    skipStationSettingScreenModel.getStationDetailList().addListener(stationListListener);

    skipStationListListener = (observable, oldVal, newVal) -> updateSkipStationOptions();
    skipStationSettingScreenModel.getSkipStationDetailList().addListener(skipStationListListener);

  
    updateStationOptions();
    updateSkipStationOptions();
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

    for (int optionsCounter = 0; optionsCounter < skipStationSettingScreenModel.getStationDetailList()
        .size(); optionsCounter++)
    {
      String station = skipStationSettingScreenModel.getStationDetailList().get(optionsCounter)
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

  private void updateSkipStationOptions()
  {
    for (int optionsCounter = 0; optionsCounter < skipStationOptionsMap.size(); optionsCounter++)
    {
      skipStationOptionsMap.get(optionsCounter).setText(ApplicationConstants.BLANK);
      skipStationOptionsMap.get(optionsCounter).getStyleClass().clear();
      skipStationOptionsMap.get(optionsCounter).setVisible(false);
    }

    for (int optionsCounter = 0; optionsCounter < skipStationSettingScreenModel.getSkipStationDetailList()
        .size(); optionsCounter++)
    {
      String station = skipStationSettingScreenModel.getSkipStationDetailList().get(optionsCounter)
          .getStationName();

      if (station != null)
      {
        skipStationOptionsMap.get(optionsCounter).setText(station);
        skipStationOptionsMap.get(optionsCounter).getStyleClass()
            .add(ApplicationConstants.STATION_LIST_OPTIONS_UNSELECTED_CSS);
        skipStationOptionsMap.get(optionsCounter).setVisible(true);
      }
    }
  }

  private void updateSelectedStationId(Integer index)
  {
    updateStationOptions();
    stationId = skipStationSettingScreenModel.getStationDetailList().get(index).getStationId();
    stationOptionsMap.get(index).getStyleClass().add(ApplicationConstants.STATION_LIST_OPTIONS_SELECTED_CSS);
  }

  private void updateSelectedSkipStationId(Integer index)
  {
    updateSkipStationOptions();
    skipStationId = skipStationSettingScreenModel.getSkipStationDetailList().get(index).getStationId();
    skipStationOptionsMap.get(index).getStyleClass()
        .add(ApplicationConstants.STATION_LIST_OPTIONS_SELECTED_CSS);
  }

  @FXML
  private void onStOptionMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(stationOptionsMap.get(stationOptId1)))
    {
      updateSelectedStationId(stationOptId1);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId2)))
    {
      updateSelectedStationId(stationOptId2);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId3)))
    {
      updateSelectedStationId(stationOptId3);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId4)))
    {
      updateSelectedStationId(stationOptId4);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId5)))
    {
      updateSelectedStationId(stationOptId5);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId6)))
    {
      updateSelectedStationId(stationOptId6);
    }
  }

  @FXML
  private void onStOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(stationOptionsMap.get(stationOptId1)))
    {
      updateSelectedStationId(stationOptId1);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId2)))
    {
      updateSelectedStationId(stationOptId2);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId3)))
    {
      updateSelectedStationId(stationOptId3);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId4)))
    {
      updateSelectedStationId(stationOptId4);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId5)))
    {
      updateSelectedStationId(stationOptId5);
    }
    else if (event.getSource().equals(stationOptionsMap.get(stationOptId6)))
    {
      updateSelectedStationId(stationOptId6);
    }
  }

  @FXML
  private void onSkipOptionMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(skipStationOptionsMap.get(skipOptId1)))
    {
      updateSelectedSkipStationId(skipOptId1);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId2)))
    {
      updateSelectedSkipStationId(skipOptId2);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId3)))
    {
      updateSelectedSkipStationId(skipOptId3);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId4)))
    {
      updateSelectedSkipStationId(skipOptId4);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId5)))
    {
      updateSelectedSkipStationId(skipOptId5);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId6)))
    {
      updateSelectedSkipStationId(skipOptId6);
    }
  }

  @FXML
  private void onSkipOptionTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(skipStationOptionsMap.get(skipOptId1)))
    {
      updateSelectedSkipStationId(skipOptId1);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId2)))
    {
      updateSelectedSkipStationId(skipOptId2);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId3)))
    {
      updateSelectedSkipStationId(skipOptId3);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId4)))
    {
      updateSelectedSkipStationId(skipOptId4);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId5)))
    {
      updateSelectedSkipStationId(skipOptId5);
    }
    else if (event.getSource().equals(skipStationOptionsMap.get(skipOptId6)))
    {
      updateSelectedSkipStationId(skipOptId6);
    }
  }

  @FXML
  private void onStationListUpMouseClicked(MouseEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipScreenStationListUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onStationListUpTouchPressed(TouchEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipScreenStationListUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onStationListDownMouseClicked(MouseEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipScreenStationListDownButtonPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onStationListDownTouchPressed(TouchEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipScreenStationListDownButtonPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onSkipListUpMouseClicked(MouseEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipStationListUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onSkipListUpTouchPressed(TouchEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipStationListUpButtonPressed(ApplicationConstants.UP_PRESSED);
  }

  @FXML
  private void onSkipListDownMouseClicked(MouseEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipStationListDownButtonPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onSkipListDownTouchPressed(TouchEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipStationListDownButtonPressed(ApplicationConstants.DOWN_PRESSED);
  }

  @FXML
  private void onAddToSkipListButtonAction(ActionEvent event)
  {
    for (int optionsCounter = 0; optionsCounter < skipStationSettingScreenModel.getStationDetailList()
        .size(); optionsCounter++)
    {
      if (stationId == skipStationSettingScreenModel.getStationDetailList().get(optionsCounter)
          .getStationId())
      {
        setAddToSkipListButtonStatus();
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendStationIdAddedToSkipList(stationId);
      }
    }
  }

  private void resetReomoveFromAndAddToListButton()
  {
    addToSkipListBtn.getStyleClass().clear();
    removeFromSkipListBtn.getStyleClass().clear();
    addToSkipListBtn.getStyleClass().add(ApplicationConstants.RIGHT_ARROW_UNSELECTED_CSS);
    removeFromSkipListBtn.getStyleClass().add(ApplicationConstants.LEFT_ARROW_UNSELECTED_CSS);

  }

  private void setAddToSkipListButtonStatus()
  {
    addToSkipListBtn.getStyleClass().clear();
    removeFromSkipListBtn.getStyleClass().clear();
    addToSkipListBtn.getStyleClass().add(ApplicationConstants.RIGHT_ARROW_SELECTED_CSS);
    removeFromSkipListBtn.getStyleClass().add(ApplicationConstants.LEFT_ARROW_UNSELECTED_CSS);
  }

  private void setReomoveFromSkipListButtonStatus()
  {
    addToSkipListBtn.getStyleClass().clear();
    removeFromSkipListBtn.getStyleClass().clear();
    addToSkipListBtn.getStyleClass().add(ApplicationConstants.RIGHT_ARROW_UNSELECTED_CSS);
    removeFromSkipListBtn.getStyleClass().add(ApplicationConstants.LEFT_ARROW_SELECTED_CSS);
  }

  @FXML
  private void onRemoveFromSkipListButtonAction(ActionEvent event)
  {
    for (int optionsCounter = 0; optionsCounter < skipStationSettingScreenModel.getSkipStationDetailList()
        .size(); optionsCounter++)
    {
      if (skipStationId == skipStationSettingScreenModel.getSkipStationDetailList().get(optionsCounter)
          .getStationId())
      {
        setReomoveFromSkipListButtonStatus();
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendStationIdRemovedFromSkipList(skipStationId);
      }
    }
  }

  @FXML
  private void onSkipSettingsOkButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipScreenOkButtonPressed(ApplicationConstants.OK_PRESSED);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);

  }

  @FXML
  private void onSkipSettingBackButtonAction(ActionEvent event)
  {
    resetReomoveFromAndAddToListButton();
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSkipScreenBackButtonPressed(ApplicationConstants.BACK_PRESSED);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
  }

}
