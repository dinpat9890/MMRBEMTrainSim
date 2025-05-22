/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ALARM_BUTTON_1;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ALARM_BUTTON_2;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ALARM_BUTTON_3;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ALARM_BUTTON_4;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ALARM_BUTTON_5;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.ALARM_BUTTON_6;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.NUMBER_OF_PECU_CALLS;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PASSENGER_ALARM_CLEAR_ALL_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PASSENGER_ALARM_CONNECT_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PASSENGER_ALARM_DISCONNECT_REQUEST;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.stream.Collectors;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.data.MultiplePecuCallModel;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.MultiplePecuCallIdEnum;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.PassengerAlarmScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.PassengerAlarmScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class PassengerAlarmScreenController extends AbstractPAPISController
{

  @FXML
  private Label currentAlarmLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private Label timeLbl;

  @FXML
  @CommsNumber(ALARM_BUTTON_1)
  private Button alarmButton1;

  @FXML
  @CommsNumber(ALARM_BUTTON_2)
  private Button alarmButton2;

  @FXML
  @CommsNumber(ALARM_BUTTON_3)
  private Button alarmButton3;

  @FXML
  @CommsNumber(ALARM_BUTTON_4)
  private Button alarmButton4;

  @FXML
  @CommsNumber(ALARM_BUTTON_5)
  private Button alarmButton5;

  @FXML
  @CommsNumber(ALARM_BUTTON_6)
  private Button alarmButton6;

  @FXML
  private Button connectBtn;

  @FXML
  private Button disconnectBtn;

  @FXML
  private Button resetBtn;

  @FXML
  private Button isolateBtn;

  @FXML
  private Button clearAllBtn;

  @FXML
  private Button alarmScreenBackBtn;

  @FXML
  private Button alarmListUpBtn;

  @FXML
  private Button alarmListDownBtn;

  private PassengerAlarmScreenModel passengerAlarmScreenModel;

  private HeaderDateTimeModel headerDateTimeModel;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private ChangeListener<Number> currentPecuIdListener;

  private ChangeListener<Number> callConnectionListener;

  private ChangeListener<Boolean> upArrowListener;

  private ChangeListener<Boolean> downArrowListener;

  private NodePseudoClassProperty connectButtonProperty;

  private NodePseudoClassProperty alarmBtn1Property;

  private NodePseudoClassProperty alarmBtn2Property;

  private NodePseudoClassProperty alarmBtn3Property;

  private NodePseudoClassProperty alarmBtn4Property;

  private NodePseudoClassProperty alarmBtn5Property;

  private NodePseudoClassProperty alarmBtn6Property;

  private int selectedPecuId;

  private int noOfAlarms;

  private int pecuId;

  private Map<Integer, String> multiAlarmMap = new HashMap<>();

  private Map<String, Integer> alarmNamesMap = new HashMap<>();

  private Map<Integer, Button> alarmButtonMap = new HashMap<>();

  private Map<Integer, NodePseudoClassProperty> alarmGridMap = new HashMap<>();

  private ChangeListener<Number> selectedAlarmListener;

  private ChangeListener<Number> alarmConnectedListener;

  private ChangeListener<Number> callCountListener;

  private ChangeListener<? super ObservableList<MultiplePecuCallModel>> lineListListener;

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    passengerAlarmScreenModel.getAlarmStatus().removeListener(callConnectionListener);
    passengerAlarmScreenModel.getPecuId().removeListener(currentPecuIdListener);
    passengerAlarmScreenModel.getUpArrowPressed().removeListener(upArrowListener);
    passengerAlarmScreenModel.getDownArrowPressed().removeListener(downArrowListener);
    passengerAlarmScreenModel.getSelectedAlarm().removeListener(selectedAlarmListener);
    passengerAlarmScreenModel.getAlarmState().removeListener(alarmConnectedListener);
    passengerAlarmScreenModel.getMultipleCallList().removeListener(lineListListener);
  }

  @Override
  public void initializeImpl()
  {

    passengerAlarmScreenModel = new PassengerAlarmScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new PassengerAlarmScreenBinder(passengerAlarmScreenModel));

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    selectedAlarmListener = (observable, oldVal, newVal) -> updateCurrentAlarmSelection(newVal.intValue());
    passengerAlarmScreenModel.getSelectedAlarm().addListener(selectedAlarmListener);

    lineListListener = (observable, oldVal, newVal) -> updateLineOptions();
    passengerAlarmScreenModel.getMultipleCallList().addListener(lineListListener);

    callCountListener = (observable, oldVal, newVal) -> updateNoOfCalls();
    passengerAlarmScreenModel.getCallCount().addListener(callCountListener);

    connectButtonProperty = new NodePseudoClassProperty(connectBtn);
    alarmBtn1Property = new NodePseudoClassProperty(alarmButton1);
    alarmBtn2Property = new NodePseudoClassProperty(alarmButton2);
    alarmBtn3Property = new NodePseudoClassProperty(alarmButton3);
    alarmBtn4Property = new NodePseudoClassProperty(alarmButton4);
    alarmBtn5Property = new NodePseudoClassProperty(alarmButton5);
    alarmBtn6Property = new NodePseudoClassProperty(alarmButton6);

    initializeAlarmSelectionState();
    initialileAlarmLabelMap();
    initializeNameMap();
    updateLineOptions();

    updateCurrentAlarmSelection(passengerAlarmScreenModel.getSelectedAlarm().get());

    currentPecuIdListener = (observable, oldVal, newVal) -> updateNoOfAlarms(newVal.intValue());
    passengerAlarmScreenModel.getPecuId().addListener(currentPecuIdListener);

    updateNoOfAlarms(passengerAlarmScreenModel.getPecuId().get());

    callConnectionListener = (observable, oldVal, newVal) -> updateConnectionState(newVal.intValue());
    passengerAlarmScreenModel.getAlarmStatus().addListener(callConnectionListener);

    updateConnectionState(passengerAlarmScreenModel.getAlarmStatus().get());

    upArrowListener = (observable, oldValue, newValue) -> upArrowPressed(newValue.booleanValue());
    passengerAlarmScreenModel.getUpArrowPressed().addListener(upArrowListener);

    upArrowPressed(passengerAlarmScreenModel.getUpArrowPressed().get());

    downArrowListener = (observable, oldValue, newValue) -> downArrowPressed(newValue.booleanValue());
    passengerAlarmScreenModel.getDownArrowPressed().addListener(downArrowListener);

    // downArrowPressed(passengerAlarmScreenModel.getDownArrowPressed().get());

    alarmConnectedListener = (observable, oldVal, newVal) -> updateAlarmState();
    passengerAlarmScreenModel.getAlarmState().addListener(alarmConnectedListener);

    updateAlarmState();

  }

  private void updateNoOfCalls()
  {
    noOfAlarms = passengerAlarmScreenModel.getCallCount().get();
    updateDefaultAlarmLabelState();
  }

  private void updateLineOptions()
  {

    multiAlarmMap.clear();
    for (int optionsCounter = 0; optionsCounter < passengerAlarmScreenModel.getMultipleCallList()
        .size(); optionsCounter++)
    {
      multiAlarmMap.put(passengerAlarmScreenModel.getMultipleCallList().get(optionsCounter).getPecuId(),
          passengerAlarmScreenModel.getMultipleCallList().get(optionsCounter).getPecuName());
    }
    resetAlarmList();
  }

  private void updateAlarmState()
  {

    if (passengerAlarmScreenModel.getPecuId().get() == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
    {

      updateCurrentAlarmLabel(passengerAlarmScreenModel.getSelectedAlarm().get());
      updateDefaultAlarmLabelState();

    }
    else
    {
      updateCurrentAlarmLabel(passengerAlarmScreenModel.getSelectedAlarm().get());
      noOfAlarms = noOfAlarms - 1;
      updateDefaultAlarmLabelState();
    }

  }

  private void downArrowPressed(boolean isButtonPressed)
  {
    if (isButtonPressed)
    {
      if (selectedPecuId != 0 && selectedPecuId != noOfAlarms)
      {
        updateCurrentAlarmSelection(selectedPecuId + 1);
      }
      else
      {
        updateCurrentAlarmSelection(1);
      }
    }
  }

  private void upArrowPressed(boolean isButtonPressed)
  {
    if (isButtonPressed)
    {
      if (selectedPecuId > 1)
      {
        updateCurrentAlarmSelection(selectedPecuId - 1);
      }
      else
      {
        updateCurrentAlarmSelection(noOfAlarms);
      }
    }
  }

  private void initializeAlarmSelectionState()
  {
    alarmGridMap.put(1, alarmBtn1Property);
    alarmGridMap.put(2, alarmBtn2Property);
    alarmGridMap.put(3, alarmBtn3Property);
    alarmGridMap.put(4, alarmBtn4Property);
    alarmGridMap.put(5, alarmBtn5Property);
    alarmGridMap.put(6, alarmBtn6Property);
  }

  private void initialileAlarmLabelMap()
  {
    alarmButtonMap.put(1, alarmButton1);
    alarmButtonMap.put(2, alarmButton2);
    alarmButtonMap.put(3, alarmButton3);
    alarmButtonMap.put(4, alarmButton4);
    alarmButtonMap.put(5, alarmButton5);
    alarmButtonMap.put(6, alarmButton6);
  }

  private void updateConnectionState(int connectionState)
  {
    if (connectionState == ApplicationConstants.PECU_CALL_CONNECTED
        && (passengerAlarmScreenModel.getActiveCallType().get() == ApplicationConstants.CALL_TYPE_OHP
            || passengerAlarmScreenModel.getPecuId().get() == ApplicationConstants.MULTIPLE_PECU_CALL_ID))
    {
      connectButtonProperty.set(ApplicationConstants.PECU_CONNECTED_CSS);
    }
    else
    {
      connectButtonProperty.set(ApplicationConstants.PECU_DISCONNECTED_CSS);
      currentAlarmLbl.setText(""); //$NON-NLS-1$
    }

    if (connectionState == 0)
    {
      alarmButtonMap.get(1).setText(""); //$NON-NLS-1$
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(0);
      updateDefaultAlarmLabelState();
    }

  }

  private void updateNoOfAlarms(int pecuId)
  {
    this.pecuId = pecuId;
    initializeAlarmSelectionState();
    initialileAlarmLabelMap();

    updateDefaultAlarmLabelState();
    if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
    {

      noOfAlarms = 4;

    }
    else if (pecuId != ApplicationConstants.NO_PECU_ID_SELECTED)
    {
      noOfAlarms = 1;
    }
    else
    {
      noOfAlarms = 0;
      for (Entry<Integer, Button> entry : alarmButtonMap.entrySet())
      {
        alarmButtonMap.get(entry.getKey()).setText(""); //$NON-NLS-1$
      }
      updateDefaultAlarmLabelState();
    }
    if (noOfAlarms > 0)
    {
      updateAlarmList(pecuId);
    }
  }

  private void updateAlarmList(Integer pecuId)
  {
    updateDefaultAlarmLabelState();
    if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
    {

      for (int i = 1; i <= multiAlarmMap.size(); i++)
      {
        alarmButtonMap.get(i).setText(multiAlarmMap.get(i));
      }
    }
    else
    {
      alarmButtonMap.get(1).setText("PECU" + pecuId); //$NON-NLS-1$
    }
  }

  private void updateCurrentAlarmSelection(Integer selectedAlarm)
  {

    if (passengerAlarmScreenModel.getAlarmStatus().get() == ApplicationConstants.PASSENGER_CALLING)
    {
      selectedPecuId = selectedAlarm;
      updateDefaultAlarmLabelState();

      if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
      {
        int index = 0;
        for (int i = 1; i <= alarmButtonMap.size(); i++)
        {
          String buttonText = alarmButtonMap.get(i).getText();

          String mapText = getKeyFromValue(alarmNamesMap, selectedPecuId);
          if (buttonText.equalsIgnoreCase(mapText))
          {
            index = i;
          }
        }

        alarmGridMap.get(index).set(ApplicationConstants.PECU_ALARM_SELECTED_CSS);
      }
      else
      {
        alarmGridMap.get(selectedAlarm).set(ApplicationConstants.PECU_ALARM_SELECTED_CSS);
      }
    }
  }

  private void updateDefaultAlarmLabelState()
  {
    // Un-select all alarm labels first
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : alarmGridMap.entrySet())
    {
      Integer key = entry.getKey();

      if (noOfAlarms >= key)
      {

        alarmGridMap.get(key).set(ApplicationConstants.PECU_ALARM_UNSELECTED_CSS);
        alarmButtonMap.get(key).setVisible(true);
      }
      else
      {
        alarmGridMap.get(key).set(ApplicationConstants.PECU_ALARM_DEFAULT_CSS);
        alarmButtonMap.get(key).setVisible(false);
      }
    }
  }

  private void updateCurrentAlarmLabel(int selectedLabelId)
  {

    int pecuId = passengerAlarmScreenModel.getPecuId().get();
    if (selectedLabelId == ApplicationConstants.NO_PECU_ID_SELECTED
        || pecuId == ApplicationConstants.NO_PECU_ID_SELECTED)
    {
      currentAlarmLbl.setText(""); //$NON-NLS-1$
    }
    else if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
    {

      currentAlarmLbl.setText(MultiplePecuCallIdEnum.valueOf(selectedPecuId).getPecuName());
    }
    else
    {
      currentAlarmLbl.setText("PECU" + pecuId); //$NON-NLS-1$
    }
  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void resetAlarmList()
  {
    List<String> multiPecuNameList = multiAlarmMap.values().stream().collect(Collectors.toList());

    multiAlarmMap.clear();

    for (int i = 1; i <= multiPecuNameList.size(); i++)
    {
      multiAlarmMap.put(i, multiPecuNameList.get(i - 1));
    }

    alarmButtonMap.forEach((key, label) -> {
      if (multiPecuNameList.size() < key)
      {
        alarmButtonMap.get(key).setText(""); //$NON-NLS-1$
      }
      else
      {
        alarmButtonMap.get(key).setText(multiAlarmMap.get(key));
      }
    });
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onConnectButtonAction(ActionEvent event)
  {
    if (selectedPecuId > 0
        && passengerAlarmScreenModel.getAlarmStatus().get() == ApplicationConstants.PASSENGER_CALLING)
    {

      updateCurrentAlarmLabel(selectedPecuId);

      noOfAlarms = noOfAlarms - 1;

      updateDefaultAlarmLabelState();
      resetAlarmList();
      if ((passengerAlarmScreenModel.getActiveCallType().get() == ApplicationConstants.CALL_TYPE_OHP
          || passengerAlarmScreenModel.getPecuId().get() == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
          && passengerAlarmScreenModel.getAlarmStatus().get() == ApplicationConstants.PASSENGER_CALLING)
      {
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendButtonClickRequest(PASSENGER_ALARM_CONNECT_REQUEST);

        if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
       {
          PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(NUMBER_OF_PECU_CALLS,
              multiAlarmMap.size());        }
      }
    }
    // selectedPecuId = 0;
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onDisconnectButtonAction(ActionEvent event)
  {
    if (!currentAlarmLbl.getText().isEmpty())
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(PASSENGER_ALARM_DISCONNECT_REQUEST);
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(0);
      updateCurrentAlarmLabel(ApplicationConstants.NO_PECU_ID_SELECTED);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onResetButtonAction(ActionEvent event)
  {
    if (!currentAlarmLbl.getText().isEmpty())
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(PASSENGER_ALARM_DISCONNECT_REQUEST);
      updateCurrentAlarmLabel(ApplicationConstants.NO_PECU_ID_SELECTED);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onClearAllButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(PASSENGER_ALARM_CLEAR_ALL_REQUEST);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onAlarmScreenBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onIsolateButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.PECU_ISOLATE_SCREEN);
  }

  @FXML
  private void onAlarmButton1Action(ActionEvent event)
  {
    if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
    {
      int id = alarmNamesMap.get(alarmButton1.getText());
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(id);
    }
    else
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(1);
    }

  }

  @FXML
  private void onAlarmButton2Action(ActionEvent event)
  {
    if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
    {

      int id = alarmNamesMap.get(alarmButton2.getText());

      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(id);
    }
    else
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(2);
    }

  }

  @FXML
  private void onAlarmButton3Action(ActionEvent event)
  {
    if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
    {

      int id = alarmNamesMap.get(alarmButton3.getText());
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(id);
    }
    else
    {

      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(3);
    }

  }

  @FXML
  private void onAlarmButton4Action(ActionEvent event)
  {
    if (pecuId == ApplicationConstants.MULTIPLE_PECU_CALL_ID)
    {
      int id = alarmNamesMap.get(alarmButton4.getText());
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(id);
    }
    else
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(4);
    }
  }

  @FXML
  private void onAlarmButton5Action(ActionEvent event)
  {

    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(5);

  }

  @FXML
  private void onAlarmButton6Action(ActionEvent event)
  {

    PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendSelectedAlarmId(6);

  }

  private void initializeNameMap()
  {
    alarmNamesMap.put("PECU10", 1);
    alarmNamesMap.put("PECU12", 2);
    alarmNamesMap.put("PECU17", 3);
    alarmNamesMap.put("PECU21", 4);
  }

  private static <K, V> K getKeyFromValue(Map<K, V> map, Object value)
  {

    // get all map keys using keySet method
    Set<K> keys = map.keySet();

    // iterate all keys
    for (K key : keys)
    {

      // if maps value for the current key matches, return the key
      if (map.get(key).equals(value))
      {
        return key;
      }
    }

    // if no values matches, return null
    return null;
  }
}
