/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.fe.base.impl;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import com.sydac.core.runtimedata.HubIO;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.state.DoorOpeningSideEnum;
import com.sydac.mmrbem.papis.common.state.KeyPadEnum;
import com.sydac.mmrbem.papis.common.state.ManualAnnouncementMessageType;
import com.sydac.mmrbem.papis.common.state.PapisModeEnum;
import com.sydac.mmrbem.papis.common.state.RouteDirectionEnum;
import com.sydac.mmrbem.papis.fe.base.ServiceRequestHandler;
import com.sydac.peer.application.SimplePropertySetter;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.framework.GatewayProvider;

public class ServiceRequestHandlerImpl implements ServiceRequestHandler
{

  private SimplePropertySetter propertySetter;

  private ScheduledExecutorService scheduledExecutorService = Executors.newSingleThreadScheduledExecutor();

  @Override
  public void setHubValuesObject(CObject hubValues, GatewayProvider gatewayProvider)
  {
    this.propertySetter = new SimplePropertySetter(gatewayProvider.getGateway(), hubValues);
  }

  /*
   * Sends pulse value for given comms number. Sets the number to 'set' value
   * and then to 'reset' value after 100ms.
   */
  private void sendPulseRequest(final String number, final double set, final double reset)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), set);
    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(
        () -> propertySetter.setNumber(HubIO.createIOPropertyName(number), reset), 100,
        TimeUnit.MILLISECONDS);

  }

  /*
   * Sends pulse (1, 0) value for given comms number.
   */
  private void sendPulseRequest(final String number)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), true);
    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(
        () -> propertySetter.setNumber(HubIO.createIOPropertyName(number), false), 100,
        TimeUnit.MILLISECONDS);

  }

  /*
   * Sets value for given comms number.
   */
  @Override
  public void sendRequest(final String number, Integer val)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), val);
  }

  @Override
  public void sendButtonClickRequest(String buttonName)
  {
    sendPulseRequest(buttonName);
  }

  @Override
  public void sendRequest(String number, Double val)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), val);
    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(
        () -> propertySetter.setNumber(HubIO.createIOPropertyName(number), false), 100,
        TimeUnit.MILLISECONDS);
  }

  @Override
  public void sendScreenChangeRequest(ScreenId screenId)
  {
    sendPulseRequest(PAPISInputs.SCREEN_CHANGE_REQUEST, screenId.getId(), -1);
  }

  @Override
  public void sendModeChangeRequest(PapisModeEnum modeId)
  {
    sendPulseRequest(PAPISInputs.MODE_SELECTION_REQUEST, modeId.getModeId(), -1);
  }

  @Override
  public void sendTrainIdKeypadButtonRequest(KeyPadEnum key)
  {
    sendPulseRequest(PAPISInputs.TRAIN_ID_KEYPAD_BUTTON_REQUEST, key.getValue(), -1);
  }

  @Override
  public void sendRouteDirectionRequest(RouteDirectionEnum direction)
  {
    sendPulseRequest(PAPISInputs.ROUTE_DIRECTION_REQUEST, direction.getDirectionId(), -1);
  }

  @Override
  public void sendRouteScreenUpButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.ROUTE_SCREEN_UP_PRESSED, val, -1);
  }

  @Override
  public void sendRouteScreenDownButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.ROUTE_SCREEN_DOWN_PRESSED, val, -1);
  }

  @Override
  public void sendLineIdSelected(Integer lineId)
  {
    sendPulseRequest(PAPISInputs.SELECTED_ROUTE_ID_REQUEST, lineId, -1);
  }

  @Override
  public void sendStartStationIdRequest(Integer stationId)
  {
    sendPulseRequest(PAPISInputs.SELECTED_START_ST_ID_REQUEST, stationId, -1);
  }

  @Override
  public void sendTerminalStationIdRequest(Integer stationId)
  {
    sendPulseRequest(PAPISInputs.SELECTED_TERMINAL_ST_ID_REQUEST, stationId, -1);
  }

  @Override
  public void sendNextStationIdRequest(Integer stationId)
  {
    sendPulseRequest(PAPISInputs.SELECTED_NEXT_ST_ID_REQUEST, stationId, -1);
  }

  @Override
  public void sendStationSelectionUpButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.STATION_SELECTION_SCREN_UP_PRESSED, val, -1);
  }

  @Override
  public void sendStationSelectionDownButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.STATION_SELECTION_SCREN_DOWN_PRESSED, val, -1);
  }

  @Override
  public void sendSkipScreenStationListUpButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.SKIP_SCREEN_STATION_LIST_UP_PRESSED, val, -1);
  }

  @Override
  public void sendSkipScreenStationListDownButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.SKIP_SCREEN_STATION_LIST_DOWN_PRESSED, val, -1);
  }

  @Override
  public void sendSkipStationListUpButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.SKIP_SCREEN_SKIP_LIST_UP_PRESSED, val, -1);
  }

  @Override
  public void sendSkipStationListDownButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.SKIP_SCREEN_SKIP_LIST_DOWN_PRESSED, val, -1);
  }

  @Override
  public void sendStationIdAddedToSkipList(Integer stationId)
  {
    sendPulseRequest(PAPISInputs.STATION_ID_ADDED_TO_SKIP_LIST, stationId, -1);
  }

  @Override
  public void sendStationIdRemovedFromSkipList(Integer stationId)
  {
    sendPulseRequest(PAPISInputs.STATION_ID_REMOVED_FROM_SKIP_LIST, stationId, -1);
  }

  @Override
  public void sendSkipScreenOkButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.SKIP_SCREEN_OK_BUTTON_PRESSED, val, -1);
  }

  @Override
  public void sendSkipScreenBackButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.SKIP_SCREEN_BACK_BUTTON_PRESSED, val, -1);
  }

  @Override
  public void sendManualModeScreenStationListUpPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.MANUAL_MODE_STATION_LIST_UP_PRESSED, val, -1);
  }

  @Override
  public void sendManualModeScreenStationListDownPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.MANUAL_MODE_STATION_LIST_DOWN_PRESSED, val, -1);
  }

  @Override
  public void sendManualModeScreenCurrentStationSelection(Integer stationId)
  {
    sendPulseRequest(PAPISInputs.MANUAL_MODE_SELECTED_CURRENT_STATION_ID, stationId, -1);
  }

  @Override
  public void sendManualModeScreenDoorOpeningSide(DoorOpeningSideEnum doorSide)
  {
    sendPulseRequest(PAPISInputs.MANUAL_MODE_SELECTED_DOOR_OPENING_SIDE, doorSide.getDoorOpenSideId(), -1);
  }

  @Override
  public void sendManualModeScreenMessageTypeRequest(ManualAnnouncementMessageType messageType)
  {
    sendPulseRequest(PAPISInputs.MANUAL_MODE_SELECTED_MESSAGE_TYPE, messageType.getMessageTypeId(), -1);
  }

  @Override
  public void sendSpcInfoSelectedId(Integer spcInfoId)
  {
    sendPulseRequest(PAPISInputs.SPC_INFO_ID_REQ, spcInfoId, -1);
  }

  @Override
  public void sendSpcInfoPlayCount(Integer count)
  {
    sendPulseRequest(PAPISInputs.SPC_INFO_NO_OF_TIMES, count, -1);
  }

  @Override
  public void sendSpcInfoListUpButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.SPC_INFO_SCREEN_UP_BUTTON_PRESSED, val, -1);
  }

  @Override
  public void sendSpcInfoListDownButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.SPC_INFO_SCREEN_DOWN_BUTTON_PRESSED, val, -1);
  }

  @Override
  public void sendSpcInfoStopAnnouncementRequest(Integer val)
  {
    sendPulseRequest(PAPISInputs.SPC_INFO_SCREEN_STOP_BUTTON_PRESSED, val, 0);
  }

  @Override
  public void sendEmgInfoSelectedId(Integer emgInfoId)
  {
    sendPulseRequest(PAPISInputs.EMG_INFO_ID_REQ, emgInfoId, -1);
  }

  @Override
  public void sendEmgInfoPlayCount(Integer count)
  {
    sendPulseRequest(PAPISInputs.EMG_INFO_NO_OF_TIMES, count, -1);
  }

  @Override
  public void sendEmgInfoListUpButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.EMG_INFO_SCREEN_UP_BUTTON_PRESSED, val, -1);
  }

  @Override
  public void sendEmgInfoListDownButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.EMG_INFO_SCREEN_DOWN_BUTTON_PRESSED, val, -1);
  }

  @Override
  public void sendEmgInfoStopAnnouncementRequest(Integer val)
  {
    sendPulseRequest(PAPISInputs.EMG_INFO_SCREEN_STOP_BUTTON_PRESSED, val, 0);
  }

  @Override
  public void sendPhysicalUpButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.UP_ARROW_BUTTON, val, -1);

  }

  @Override
  public void sendPhysicalDownButtonPressed(Integer val)
  {
    sendPulseRequest(PAPISInputs.DOWN_ARROW_BUTTON, val, -1);

  }

  @Override
  public void sendStartStaionSelected(int index)
  {
    sendPulseRequest(PAPISInputs.START_STATION_SELECTED, index, -1);
  }

  @Override
  public void sendSelectedEmgInfoIdRequest(int index)
  {
    sendPulseRequest(PAPISInputs.CURRENT_EMERGENCY_MESSAGE, index, -1);

  }

  @Override
  public void sendSelectedSpcInfoIdRequest(int index)
  {
    sendPulseRequest(PAPISInputs.CURRENT_SPECIAL_MESSAGE, index, -1);

  }

  @Override
  public void sendSelectedTerminalStationId(int index)
  {
    sendPulseRequest(PAPISInputs.TERMINAL_STATION_SELECTED, index, -1);

  }

  @Override
  public void sendSelectedNextStationId(int index)
  {
    sendPulseRequest(PAPISInputs.NEXT_STATION_SELECTED, index, -1);

  }

  @Override
  public void sendSpcInfoOkButtonPressedReq(Integer val)
  {
    sendPulseRequest(PAPISInputs.SPC_INFO_SCREEN_OK_BUTTON_PRESSED, val, -1);
  }

  @Override
  public void sendEmgInfoOkButtonPressedReq(Integer val)
  {
    sendPulseRequest(PAPISInputs.EMG_INFO_SCREEN_OK_BUTTON_PRESSED, val, -1);
  }

  @Override
  public void sendSelectedAlarmId(int index)
  {
    sendRequest(PAPISInputs.PASSENGER_ALARM_SELECTED_REQUEST, index);
    
  }

 
}