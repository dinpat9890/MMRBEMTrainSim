/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.CC_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.CH_CHG_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.EMG_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.FAULT_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.LANG_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PC_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SPC_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.SYS_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.gui.control.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.DoorStatusEnum;
import com.sydac.mmrbem.papis.common.state.HeaderStatusLabelEnum;
import com.sydac.mmrbem.papis.common.state.PapisModeEnum;
import com.sydac.mmrbem.papis.common.utils.timer.AlarmFlashTimer;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.HeaderStatusBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.MainInterfaceScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.PassengerAlarmScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.MainInterfaceScreenModel;
import com.sydac.mmrbem.papis.fe.gui.model.PassengerAlarmScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.shape.Line;
import javafx.util.Duration;

public class MainInterfaceScreenController extends AbstractPAPISController
{
  private static final String BUTTON_SELECTED = "selected"; //$NON-NLS-1$

  private static final String BUTTON_UNSELECTED = "unselected"; //$NON-NLS-1$

  private static final String FLASH_OFF = "flash_off"; //$NON-NLS-1$

  private static final String FLASH_ON = "flash_on"; //$NON-NLS-1$

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label headerStatusLabel;

  @FXML
  private Label masterLbl;

  @FXML
  private Label connectionTypeLbl;

  @FXML
  private Label currentLineLbl;

  @FXML
  private Label currentModeLbl;

  @FXML
  private Label currentStationLbl;

  @FXML
  private Label terminalStationLbl;

  @FXML
  private Label nextStationLbl;

  @FXML
  private Label doorOpeningSideLbl;

  @FXML
  private Line line;

  @FXML
  private Label emptyLbl;

  @FXML
  private GridPane redLabelGrid;

  @FXML
  @CommsNumber(LANG_BUTTON)
  private Button langSettingBtn;

  @FXML
  @CommsNumber(SYS_BUTTON)
  private Button systemSettingBtn;

  @FXML
  @CommsNumber(SPC_BUTTON)
  private Button spcInfoBtn;

  @FXML
  @CommsNumber(EMG_BUTTON)
  private Button emgInfoBtn;

  @FXML
  @CommsNumber(FAULT_BUTTON)
  private Button faultBtn;

  @FXML
  @CommsNumber(CC_BUTTON)
  private Button ccBtn;

  @FXML
  @CommsNumber(CH_CHG_BUTTON)
  private Button chChgBtn;

  @FXML
  @CommsNumber(PC_BUTTON)
  private Button pcBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<Number> modeListener;

  private ChangeListener<String> currentStationListener;

  private ChangeListener<String> terminalStationListener;

  private ChangeListener<String> nextStationListener;

  private ChangeListener<String> doorOpeningSideListener;

  private ChangeListener<String> currentLineListener;

  private ChangeListener<String> currentConnectionListener;

  private ChangeListener<Number> ccButtonPropertyListener;

  private ChangeListener<Number> pcButtonPropertyListener;

  private ChangeListener<Number> doorModePropertyListener;

  private MainInterfaceScreenModel mainInterfaceScreenModel;

  private HeaderDateTimeModel headerDateTimeModel;

  private PassengerAlarmScreenModel passengerAlarmScreenModel;

  private ChangeListener<Number> alarmStatusListener;

  private ChangeListener<Number> intercomStatusListener;

  private ChangeListener<Number> buttonStatusListener;

  private ChangeListener<Number> headerStatusLabelListener;

  private AlarmFlashTimer passengerAlarmTimer;

  private AlarmFlashTimer cabToCabPassengerAlarmTimer;

  private Map<Integer, NodePseudoClassProperty> buttonLblMap = new HashMap<>();

  private NodePseudoClassProperty btn1NodePseudoClassProperty;

  private NodePseudoClassProperty btn2NodePseudoClassProperty;

  private NodePseudoClassProperty btn3NodePseudoClassProperty;

  private NodePseudoClassProperty btn4NodePseudoClassProperty;

  private NodePseudoClassProperty btn5NodePseudoClassProperty;

  private NodePseudoClassProperty btn6NodePseudoClassProperty;

  private NodePseudoClassProperty btn7NodePseudoClassProperty;

  private NodePseudoClassProperty btn8NodePseudoClassProperty;

  private double gridPrefWidth;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    mainInterfaceScreenModel.getActiveMode().removeListener(modeListener);
    mainInterfaceScreenModel.getCurrentStation().removeListener(currentStationListener);
    mainInterfaceScreenModel.getTerminalStation().removeListener(terminalStationListener);
    mainInterfaceScreenModel.getNextStation().removeListener(nextStationListener);
    mainInterfaceScreenModel.getDoorOpenSide().removeListener(doorOpeningSideListener);
    mainInterfaceScreenModel.getCurrentLine().removeListener(currentLineListener);
    mainInterfaceScreenModel.getCurrentConnection().removeListener(currentConnectionListener);
    mainInterfaceScreenModel.getCcButtonProperty().removeListener(ccButtonPropertyListener);
    mainInterfaceScreenModel.getPcButtonProperty().removeListener(pcButtonPropertyListener);
    mainInterfaceScreenModel.getDoorStatus().removeListener(doorModePropertyListener);
    passengerAlarmScreenModel.getAlarmStatus().removeListener(alarmStatusListener);
    passengerAlarmScreenModel.getIntercomStatus().removeListener(intercomStatusListener);
    mainInterfaceScreenModel.getSelectedButton().removeListener(buttonStatusListener);

  }

  @Override
  public void initializeImpl()
  {
    btn1NodePseudoClassProperty = new NodePseudoClassProperty(langSettingBtn);
    btn2NodePseudoClassProperty = new NodePseudoClassProperty(systemSettingBtn);
    btn3NodePseudoClassProperty = new NodePseudoClassProperty(spcInfoBtn);
    btn4NodePseudoClassProperty = new NodePseudoClassProperty(emgInfoBtn);
    btn5NodePseudoClassProperty = new NodePseudoClassProperty(faultBtn);
    btn6NodePseudoClassProperty = new NodePseudoClassProperty(ccBtn);
    btn7NodePseudoClassProperty = new NodePseudoClassProperty(chChgBtn);
    btn8NodePseudoClassProperty = new NodePseudoClassProperty(pcBtn);

    mainInterfaceScreenModel = new MainInterfaceScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new MainInterfaceScreenBinder(mainInterfaceScreenModel));

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);
    papisScreenBinders.add(new HeaderStatusBinder(headerDateTimeModel));
    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());

    headerStatusLabelListener = (observable, oldValue,
        newValue) -> updateHeaderStatusLabel(newValue.intValue());
    headerDateTimeModel.getHeaderStatusLabelId().addListener(headerStatusLabelListener);

    buttonLblMap.put(0, btn1NodePseudoClassProperty);
    buttonLblMap.put(1, btn2NodePseudoClassProperty);
    buttonLblMap.put(2, btn3NodePseudoClassProperty);
    buttonLblMap.put(3, btn4NodePseudoClassProperty);
    buttonLblMap.put(4, btn5NodePseudoClassProperty);
    buttonLblMap.put(5, btn6NodePseudoClassProperty);
    buttonLblMap.put(6, btn7NodePseudoClassProperty);
    buttonLblMap.put(7, btn8NodePseudoClassProperty);

    initializeFlashTimer();
    modeListener = (observable, oldVal, newVal) -> updateModeLabel((Integer)newVal);
    mainInterfaceScreenModel.getActiveMode().addListener(modeListener);

    currentStationListener = (observable, oldVal, newVal) -> updateCurrentStation(newVal);
    mainInterfaceScreenModel.getCurrentStation().addListener(currentStationListener);

    terminalStationListener = (observable, oldVal, newVal) -> updateTerminalStation(newVal);
    mainInterfaceScreenModel.getTerminalStation().addListener(terminalStationListener);

    nextStationListener = (observable, oldVal, newVal) -> updateNextStation(newVal);
    mainInterfaceScreenModel.getNextStation().addListener(nextStationListener);

    doorOpeningSideListener = (observable, oldVal, newVal) -> updateDoorOpeningSide(newVal);
    mainInterfaceScreenModel.getDoorOpenSide().addListener(doorOpeningSideListener);

    currentLineListener = (observable, oldVal, newVal) -> updateLine(newVal);
    mainInterfaceScreenModel.getCurrentLine().addListener(currentLineListener);

    currentConnectionListener = (observable, oldVal, newVal) -> updateConnectionType(newVal);
    mainInterfaceScreenModel.getCurrentConnection().addListener(currentConnectionListener);

    doorModePropertyListener = (observable, oldVal,
        newVal) -> updateDoorStatus(mainInterfaceScreenModel.getDoorStatus().get());
    mainInterfaceScreenModel.getDoorStatus().addListener(doorModePropertyListener);

    passengerAlarmScreenModel = new PassengerAlarmScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new PassengerAlarmScreenBinder(passengerAlarmScreenModel));

    alarmStatusListener = (observable, oldvalue,
        newvalue) -> updatePassengerAlarmStatus(passengerAlarmScreenModel.getAlarmStatus().get());
    passengerAlarmScreenModel.getAlarmStatus().addListener(alarmStatusListener);

    intercomStatusListener = (observable, oldvalue,
        newvalue) -> updateCabToCabAlarmStatus(passengerAlarmScreenModel.getIntercomStatus().get());
    passengerAlarmScreenModel.getIntercomStatus().addListener(intercomStatusListener);

    buttonStatusListener = (observable, oldvalue,
        newvalue) -> updateButtonSate(mainInterfaceScreenModel.getSelectedButton().get());
    mainInterfaceScreenModel.getSelectedButton().addListener(buttonStatusListener);

    updateButtonSate(mainInterfaceScreenModel.getSelectedButton().get());

    gridPrefWidth = redLabelGrid.getPrefWidth() / 4;

    Timeline timeline = new Timeline(new KeyFrame(Duration.ZERO, e -> {
      gridPrefWidth = gridPrefWidth - 3;
      connectionTypeLbl.setTranslateX(gridPrefWidth);
      if (gridPrefWidth <= -(redLabelGrid.getPrefWidth() / 4))
      {
        gridPrefWidth = redLabelGrid.getPrefWidth() / 4;
        connectionTypeLbl.setTranslateX(gridPrefWidth);
      }
    }), new KeyFrame(Duration.millis(140)));

    timeline.setCycleCount(Animation.INDEFINITE);
    timeline.play();
  }

  private void updateHeaderStatusLabel(int statusId)
  {
    headerStatusLabel.setText(HeaderStatusLabelEnum.valueOf(statusId).getStatusText());
  }

  private void updateButtonSate(int value)
  {
    for (int btnCntr = 0; btnCntr < buttonLblMap.size(); btnCntr++)
    {
      buttonLblMap.get(btnCntr).set(BUTTON_UNSELECTED);
    }
    buttonLblMap.get(value).set(BUTTON_SELECTED);

  }

  private void initializeFlashTimer()
  {
    passengerAlarmTimer = new AlarmFlashTimer(btn8NodePseudoClassProperty, FLASH_OFF, FLASH_ON);
    cabToCabPassengerAlarmTimer = new AlarmFlashTimer(btn6NodePseudoClassProperty, FLASH_OFF, FLASH_ON);
  }

  private void updateCabToCabAlarmStatus(int status)
  {
    if (status == ApplicationConstants.CALL_REQUEST
        && passengerAlarmScreenModel.getActiveCallType().get() == ApplicationConstants.CALL_TYPE_CTC)
    {
      cabToCabPassengerAlarmTimer.play();
    }
    else if (status == ApplicationConstants.CALL_CONNECTED
        && (passengerAlarmScreenModel.getActiveCallType().get() == ApplicationConstants.CALL_TYPE_CTC
            || passengerAlarmScreenModel.getActiveCallType().get() == ApplicationConstants.CALL_REQUEST))
    {
      cabToCabPassengerAlarmTimer.stop();
      btn6NodePseudoClassProperty.set(FLASH_ON);
    }
    else if (status == ApplicationConstants.RESET_VALUE)
    {
      cabToCabPassengerAlarmTimer.stop();
      btn6NodePseudoClassProperty.set(FLASH_OFF);
    }
  }

  private void updatePassengerAlarmStatus(int alarmStatus)
  {
    if (alarmStatus == ApplicationConstants.PASSENGER_CALLING
        && (passengerAlarmScreenModel.getActiveCallType().get() == ApplicationConstants.CALL_TYPE_OHP
            || passengerAlarmScreenModel.getPecuId().get() == ApplicationConstants.MULTIPLE_PECU_CALL_ID))
    {
      passengerAlarmTimer.play();
    }
    else
    {
      stopAlarmFlash(btn8NodePseudoClassProperty, passengerAlarmTimer);
    }
  }

  private void stopAlarmFlash(NodePseudoClassProperty btnName, AlarmFlashTimer timerType)
  {
    timerType.stop();
    btnName.set(FLASH_OFF);
  }

  private void updateDoorStatus(int state)
  {
    doorOpeningSideLbl.setText(DoorStatusEnum.valueOf(state).getDoorOpenSide());
  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void updateModeLabel(Integer newVal)
  {
    currentModeLbl.setText(PapisModeEnum.valueOf(newVal).getModeName());
  }

  private void updateCurrentStation(String currentStation)
  {
    currentStationLbl.setText(currentStation);
  }

  private void updateTerminalStation(String terminalStation)
  {
    terminalStationLbl.setText(terminalStation);
  }

  private void updateNextStation(String nextStation)
  {
    nextStationLbl.setText(nextStation);
  }

  private void updateDoorOpeningSide(String doorOpenSide)
  {
    doorOpeningSideLbl.setText(doorOpenSide);
  }

  private void updateLine(String line)
  {
    currentLineLbl.setText(line);
  }

  /**
   * @param connectionType
   *          unused This method can be used in case if full functionality is
   *          required
   */
  private void updateConnectionType(String connectionType)
  {}

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onLangSettingsButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.LANGUAGE_SETTING_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSysButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onSpcButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SPECIAL_INFORMATION_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onEmgButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.EMERGENCY_INFORMATION_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onCCButtonAction(ActionEvent event)
  {
    if (passengerAlarmScreenModel.getIntercomStatus().get() == ApplicationConstants.CALL_CONNECTED
        || passengerAlarmScreenModel.getIntercomStatus().get() == ApplicationConstants.CALL_REQUEST)
    {
      if (passengerAlarmScreenModel.getActiveCallType().get() == 1)
      {
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(PAPISInputs.CAB_TO_CAB_CAll_DISCONNECT_REQUEST);
      }
      else if (passengerAlarmScreenModel.getActiveCallType().get() == 3)
      {
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(CC_BUTTON);
      }
    }
    else
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(CC_BUTTON);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onChChgButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(CH_CHG_BUTTON);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onPCButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.PASSENGER_ALARM_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onFaultButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.FAULT_SCREEN);
  }

}
