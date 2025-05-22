/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.MANUAL_MODE_SCREEN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.NEXT_STATION_SCREEN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ROUTE_SCREEN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SKIP_STATION_SCREEN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.START_STATION_SCREEN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SYSTEM_SCREEN_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SYSTEM_SCREEN_OK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.TERMINAL_STATION_SCREEN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.TRAIN_ID_SCREEN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.VOLUME_SETTING_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.PapisModeEnum;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.SystemSettingsScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.SystemSettingsScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.input.TouchEvent;

public class SystemSettingsScreenController extends AbstractPAPISController
{

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label routeLbl;

  @FXML
  private Label startStationLbl;

  @FXML
  private Label terminalStationLbl;

  @FXML
  private Label nextStationLbl;

  @FXML
  private Label trainIdLbl;

  @FXML
  private Label autoModeIcon;

  @FXML
  private Label semiAutoModeIcon;

  @FXML
  private Label manualModeIcon;

  @FXML
  private Label selectedModeLbl;

  @FXML
  private Label skipLabel;

  @FXML
  private Label manualModeLabel;

  @FXML
  private Label okLabel;

  @FXML
  private Label lineLabel;

  @FXML
  private Label startStNameLabel;

  @FXML
  private Label terminalStNameLabel;

  @FXML
  private Label nextStNameLabel;

  @FXML
  @CommsNumber(TRAIN_ID_SCREEN_BUTTON)
  private Button idSettingScreenBtn;

  @FXML
  @CommsNumber(ROUTE_SCREEN_BUTTON)
  private Button routeSettingScreenBtn;

  @FXML
  @CommsNumber(START_STATION_SCREEN_BUTTON)
  private Button startStationSelectionScreenBtn;

  @FXML
  @CommsNumber(TERMINAL_STATION_SCREEN_BUTTON)
  private Button terminalStationSelectionScreenBtn;

  @FXML
  @CommsNumber(NEXT_STATION_SCREEN_BUTTON)
  private Button nextStationSelectionScreenBtn;

  @FXML
  @CommsNumber(SKIP_STATION_SCREEN_BUTTON)
  private Button skipSettingScreenBtn;

  @FXML
  @CommsNumber(MANUAL_MODE_SCREEN_BUTTON)
  private Button manualModeSettingScreenBtn;

  @FXML
  @CommsNumber(VOLUME_SETTING_BUTTON)
  private Button volumeBtn;

  @FXML
  @CommsNumber(SYSTEM_SCREEN_OK_BUTTON)
  private Button sysOkBtn;

  @FXML
  @CommsNumber(SYSTEM_SCREEN_BACK_BUTTON)
  private Button sysBackBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<Number> modeSelectionListener;

  private ChangeListener<String> routeSelectionListener;

  private ChangeListener<String> startStationListener;

  private ChangeListener<String> terminalStationListener;

  private ChangeListener<String> nextStationListener;

  private ChangeListener<String> trainIdListener;

  private SystemSettingsScreenModel systemSettingsScreenModel;

  private HeaderDateTimeModel headerDateTimeModel;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    systemSettingsScreenModel.getTrainIdproperty().removeListener(trainIdListener);
    systemSettingsScreenModel.getRouteProperty().removeListener(routeSelectionListener);
    systemSettingsScreenModel.getModeSelectionProperty().removeListener(modeSelectionListener);
    systemSettingsScreenModel.getStartStationProperty().removeListener(startStationListener);
    systemSettingsScreenModel.getTerminalStationProperty().removeListener(terminalStationListener);
    systemSettingsScreenModel.getNextStationProperty().removeListener(nextStationListener);
  }

  @Override
  public void initializeImpl()
  {
    systemSettingsScreenModel = new SystemSettingsScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new SystemSettingsScreenBinder(systemSettingsScreenModel));

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());

    trainIdListener = (observable, oldVal, newVal) -> updateTrainId(newVal);
    systemSettingsScreenModel.getTrainIdproperty().addListener(trainIdListener);

    startStationListener = (observable, oldVal, newVal) -> updateStartStation(newVal);
    systemSettingsScreenModel.getStartStationProperty().addListener(startStationListener);

    terminalStationListener = (observable, oldVal, newVal) -> updateTerminalStation(newVal);
    systemSettingsScreenModel.getTerminalStationProperty().addListener(terminalStationListener);

    nextStationListener = (observable, oldVal, newVal) -> updateNextStation(newVal);
    systemSettingsScreenModel.getNextStationProperty().addListener(nextStationListener);

    routeSelectionListener = (observable, oldVal, newVal) -> updateRoute(newVal);
    systemSettingsScreenModel.getRouteProperty().addListener(routeSelectionListener);

    modeSelectionListener = (observable, oldVal, newVal) -> updateModeSelection((int)newVal);
    systemSettingsScreenModel.getModeSelectionProperty().addListener(modeSelectionListener);

  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void updateTrainId(String trainId)
  {
    trainIdLbl.setText(trainId);
  }

  private void updateStartStation(String startStation)
  {
    startStationLbl.setText(startStation);
  }

  private void updateTerminalStation(String terminalStation)
  {
    terminalStationLbl.setText(terminalStation);
  }

  private void updateNextStation(String nextStation)
  {
    nextStationLbl.setText(nextStation);
  }

  private void updateRoute(String route)
  {
    routeLbl.setText(route);
  }

  private void updateModeSelection(int modeId)
  {
    autoModeIcon.getStyleClass().clear();
    semiAutoModeIcon.getStyleClass().clear();
    manualModeIcon.getStyleClass().clear();

    skipLabel.setVisible(modeId == PapisModeEnum.AUTO.getModeId());
    manualModeLabel.setVisible(modeId != PapisModeEnum.MANUAL.getModeId());
    okLabel.setVisible(modeId == PapisModeEnum.AUTO.getModeId());

    lineLabel.setVisible(modeId == PapisModeEnum.AUTO.getModeId());
    startStNameLabel.setVisible(modeId == PapisModeEnum.AUTO.getModeId());
    terminalStNameLabel.setVisible(modeId == PapisModeEnum.AUTO.getModeId());
    nextStNameLabel.setVisible(modeId == PapisModeEnum.AUTO.getModeId());

    if (modeId == PapisModeEnum.AUTO.getModeId())
    {
      autoModeIcon.getStyleClass().add(PapisModeEnum.AUTO.getModeCssClass());
      semiAutoModeIcon.getStyleClass().add(ApplicationConstants.MODE_UNSELECTED);
      manualModeIcon.getStyleClass().add(ApplicationConstants.MODE_UNSELECTED);
      selectedModeLbl.setText(PapisModeEnum.AUTO.getModeName());

      skipLabel.setVisible(true);
    }
    else if (modeId == PapisModeEnum.SEMI_AUTO.getModeId())
    {
      semiAutoModeIcon.getStyleClass().add(PapisModeEnum.SEMI_AUTO.getModeCssClass());
      autoModeIcon.getStyleClass().add(ApplicationConstants.MODE_UNSELECTED);
      manualModeIcon.getStyleClass().add(ApplicationConstants.MODE_UNSELECTED);
      selectedModeLbl.setText(PapisModeEnum.SEMI_AUTO.getModeName());
    }
    else if (modeId == PapisModeEnum.MANUAL.getModeId())
    {
      manualModeIcon.getStyleClass().add(PapisModeEnum.MANUAL.getModeCssClass());
      autoModeIcon.getStyleClass().add(ApplicationConstants.MODE_UNSELECTED);
      semiAutoModeIcon.getStyleClass().add(ApplicationConstants.MODE_UNSELECTED);
      selectedModeLbl.setText(PapisModeEnum.MANUAL.getModeName());
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onTrainIdSettingScreenButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.TRAIN_ID_SETTING_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onRouteSettingScreenButtonAction(ActionEvent event)
  {
    if (systemSettingsScreenModel.getModeSelectionProperty().get() == PapisModeEnum.MANUAL.getModeId())
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.ROUTE_SETTINGS_SCREEN);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onStartStatonSelectionScreenButtonAction(ActionEvent event)
  {
    if (systemSettingsScreenModel.getModeSelectionProperty().get() != PapisModeEnum.AUTO.getModeId())
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.START_STATION_SELECTION_SCREEN);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onTerminalStationSelectionScreenButtonAction(ActionEvent event)
  {
    if (systemSettingsScreenModel.getModeSelectionProperty().get() != PapisModeEnum.AUTO.getModeId())
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.TERMINAL_STATION_SELECTION_SCREEN);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onNextStationSelectionScreenButtonAction(ActionEvent event)
  {
    if (systemSettingsScreenModel.getModeSelectionProperty().get() != PapisModeEnum.AUTO.getModeId())
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.NEXT_STATION_SELECTION_SCREEN);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSkipSettingScreenButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SKIP_STATION_SETTING_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onManualModeSettingScreenButtonAction(ActionEvent event)
  {
    if (systemSettingsScreenModel.getModeSelectionProperty().get() == PapisModeEnum.MANUAL.getModeId())
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.MANUAL_MODE_SETTING_SCREEN);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSysOkButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(PAPISInputs.SYSTEM_SCREEN_OK_BUTTON_REQ);
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSysBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onVolumeButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.VOLUME_SETTING_SCREEN);
  }

  @FXML
  private void onModeRadioMouseClicked(MouseEvent event)
  {
    if (event.getSource().equals(autoModeIcon))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendModeChangeRequest(PapisModeEnum.AUTO);
    }
    else if (event.getSource().equals(semiAutoModeIcon))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendModeChangeRequest(PapisModeEnum.SEMI_AUTO);
    }
    else if (event.getSource().equals(manualModeIcon))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendModeChangeRequest(PapisModeEnum.MANUAL);
    }
  }

  @FXML
  private void onModeRadioTouchPressed(TouchEvent event)
  {
    if (event.getSource().equals(autoModeIcon))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendModeChangeRequest(PapisModeEnum.AUTO);
    }
    else if (event.getSource().equals(semiAutoModeIcon))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendModeChangeRequest(PapisModeEnum.SEMI_AUTO);
    }
    else if (event.getSource().equals(manualModeIcon))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendModeChangeRequest(PapisModeEnum.MANUAL);
    }
  }
}
