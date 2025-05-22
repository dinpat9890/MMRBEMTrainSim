/*******************************************************************************
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.CC_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.CH_CHG_BUTTON;

import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.state.ApplicationConstants;
import com.sydac.mmrbem.papis.common.state.HeaderStatusLabelEnum;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.HeaderStatusBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.PapisCommonPanelBinder;
import com.sydac.mmrbem.papis.fe.gui.binder.PassengerAlarmScreenBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;
import com.sydac.mmrbem.papis.fe.gui.model.PapisCommonPanelModel;
import com.sydac.mmrbem.papis.fe.gui.model.PassengerAlarmScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class PapisCommonPanelController extends AbstractPAPISController
{

  @FXML
  private Button chChgBtn;

  @FXML
  private Button upArrowBtn;

  @FXML
  private Button downArrowBtn;

  @FXML
  private Button leftArrowBtn;

  @FXML
  private Button rightArrowBtn;

  @FXML
  private Button pcBtn;

  @FXML
  private Button ccBtn;

  @FXML
  private Button muteBtn;

  @FXML
  private Button backBtn;

  @FXML
  private Button langBtn;

  private PapisCommonPanelModel papisCommonPanelModel;

  private PassengerAlarmScreenModel passengerAlarmScreenModel;

  private HeaderDateTimeModel headerStatusModel;

  @Override
  public void detachListeners()
  {}

  @Override
  public void initializeImpl()
  {
    papisCommonPanelModel = new PapisCommonPanelModel(scenarioCarIndex);
    papisScreenBinders.add(new PapisCommonPanelBinder(papisCommonPanelModel));

    passengerAlarmScreenModel = new PassengerAlarmScreenModel(scenarioCarIndex);
    papisScreenBinders.add(new PassengerAlarmScreenBinder(passengerAlarmScreenModel));

    headerStatusModel = new HeaderDateTimeModel(scenarioCarIndex);
    papisScreenBinders.add(new HeaderStatusBinder(headerStatusModel));
  }

  @FXML
  private void onPhysicalButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(chChgBtn))
    {
    //  PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(CH_CHG_BUTTON);
      //As per latest comment from client,commented code to disconnect call.And Navigate to Main Interface.    
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
      .sendScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN);
    }
    else if (event.getSource().equals(upArrowBtn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendPhysicalUpButtonPressed(1);
    }
    else if (event.getSource().equals(downArrowBtn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendPhysicalDownButtonPressed(1);
    }
    else if (event.getSource().equals(leftArrowBtn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendPhysicalUpButtonPressed(1);
    }
    else if (event.getSource().equals(rightArrowBtn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendPhysicalDownButtonPressed(1);
    }
    else if (event.getSource().equals(pcBtn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.PASSENGER_ALARM_SCREEN);
    }
    else if (event.getSource().equals(ccBtn))
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
    else if (event.getSource().equals(muteBtn))
    {
      if (headerStatusModel.getHeaderStatusLabelId().get() == HeaderStatusLabelEnum.EMPTY.getStatusTypeId())
      {
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(PAPISInputs.MUTE_BUTTON,
            HeaderStatusLabelEnum.MUTE.getStatusTypeId());
      }
      else if (headerStatusModel.getHeaderStatusLabelId().get() == HeaderStatusLabelEnum.MUTE
          .getStatusTypeId())
      {
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(PAPISInputs.MUTE_BUTTON,
            HeaderStatusLabelEnum.EMPTY.getStatusTypeId());
      }
    }
    else if (event.getSource().equals(backBtn))
    {
      int currentScreenId = papisCommonPanelModel.getCurrentScreenId().get();
      if (currentScreenId == ScreenId.TRAIN_ID_SETTING_SCREEN.getId()
          || currentScreenId == ScreenId.ROUTE_SETTINGS_SCREEN.getId()
          || currentScreenId == ScreenId.START_STATION_SELECTION_SCREEN.getId()
          || currentScreenId == ScreenId.TERMINAL_STATION_SELECTION_SCREEN.getId()
          || currentScreenId == ScreenId.NEXT_STATION_SELECTION_SCREEN.getId()
          || currentScreenId == ScreenId.MANUAL_MODE_SETTING_SCREEN.getId()
          || currentScreenId == ScreenId.SKIP_STATION_SETTING_SCREEN.getId()
          || currentScreenId == ScreenId.VOLUME_SETTING_SCREEN.getId()
          || currentScreenId == ScreenId.LANGUAGE_SETTING_SCREEN.getId())
      {
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendScreenChangeRequest(ScreenId.SYSTEM_SETTINGS_SCREEN);
      }
      else if (currentScreenId == ScreenId.SYSTEM_SETTINGS_SCREEN.getId()
          || currentScreenId == ScreenId.SPECIAL_INFORMATION_SCREEN.getId()
          || currentScreenId == ScreenId.EMERGENCY_INFORMATION_SCREEN.getId()
          || currentScreenId == ScreenId.PASSENGER_ALARM_SCREEN.getId()
          || currentScreenId == ScreenId.FAULT_SCREEN.getId())
      {
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendScreenChangeRequest(ScreenId.MAIN_INTERFACE_SCREEN);
      }
      else if (currentScreenId == ScreenId.PECU_ISOLATE_SCREEN.getId())
      {
        PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendScreenChangeRequest(ScreenId.PASSENGER_ALARM_SCREEN);
      }
    }
    else if (event.getSource().equals(langBtn))
    {
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendScreenChangeRequest(ScreenId.LANGUAGE_SETTING_SCREEN);
    }
  }
}
