/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.fe.base;

import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.common.state.DoorOpeningSideEnum;
import com.sydac.mmrbem.papis.common.state.KeyPadEnum;
import com.sydac.mmrbem.papis.common.state.ManualAnnouncementMessageType;
import com.sydac.mmrbem.papis.common.state.PapisModeEnum;
import com.sydac.mmrbem.papis.common.state.RouteDirectionEnum;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.framework.GatewayProvider;

/**
 * The Interface ServiceRequestHandler.
 *
 * @author Nazim Oliyath
 */
public interface ServiceRequestHandler
{

  /**
   * Sets the hub values object.
   *
   * @param hubValues
   *          the hub values
   * @param gatewayProvider
   *          the gateway
   */
  public void setHubValuesObject(CObject hubValues, GatewayProvider gatewayProvider);

  public void sendRequest(final String number, Integer val);

  public void sendRequest(final String number, Double val);

  public void sendButtonClickRequest(String buttonName);

  public void sendScreenChangeRequest(ScreenId screenId);

  public void sendModeChangeRequest(PapisModeEnum modeId);

  public void sendTrainIdKeypadButtonRequest(KeyPadEnum key);

  public void sendRouteDirectionRequest(RouteDirectionEnum direction);

  public void sendRouteScreenUpButtonPressed(Integer val);

  public void sendRouteScreenDownButtonPressed(Integer val);

  public void sendLineIdSelected(Integer lineId);

  public void sendStartStationIdRequest(Integer stationId);

  public void sendTerminalStationIdRequest(Integer stationId);

  public void sendNextStationIdRequest(Integer stationId);

  public void sendStationSelectionUpButtonPressed(Integer val);

  public void sendStationSelectionDownButtonPressed(Integer val);

  public void sendSkipScreenStationListUpButtonPressed(Integer val);

  public void sendSkipScreenStationListDownButtonPressed(Integer val);

  public void sendSkipStationListUpButtonPressed(Integer val);

  public void sendSkipStationListDownButtonPressed(Integer val);

  public void sendStationIdAddedToSkipList(Integer stationId);

  public void sendStationIdRemovedFromSkipList(Integer stationId);

  public void sendSkipScreenOkButtonPressed(Integer val);

  public void sendSkipScreenBackButtonPressed(Integer val);

  public void sendManualModeScreenStationListUpPressed(Integer val);

  public void sendManualModeScreenStationListDownPressed(Integer val);

  public void sendManualModeScreenCurrentStationSelection(Integer stationId);

  public void sendManualModeScreenDoorOpeningSide(DoorOpeningSideEnum doorSide);

  public void sendManualModeScreenMessageTypeRequest(ManualAnnouncementMessageType messageType);

  public void sendSpcInfoSelectedId(Integer spcInfoId);

  public void sendSpcInfoPlayCount(Integer count);

  public void sendSpcInfoListUpButtonPressed(Integer val);

  public void sendSpcInfoListDownButtonPressed(Integer val);

  public void sendSpcInfoStopAnnouncementRequest(Integer val);

  public void sendEmgInfoSelectedId(Integer emgInfoId);

  public void sendEmgInfoPlayCount(Integer count);

  public void sendEmgInfoListUpButtonPressed(Integer val);

  public void sendEmgInfoListDownButtonPressed(Integer val);

  public void sendEmgInfoStopAnnouncementRequest(Integer val);

  public void sendPhysicalUpButtonPressed(Integer val);

  public void sendPhysicalDownButtonPressed(Integer val);

  public void sendStartStaionSelected(int index);

  public void sendSelectedEmgInfoIdRequest(int index);

  public void sendSelectedSpcInfoIdRequest(int index);

  public void sendSpcInfoOkButtonPressedReq(Integer val);

  public void sendEmgInfoOkButtonPressedReq(Integer val);

  public void sendSelectedTerminalStationId(int index);

  public void sendSelectedNextStationId(int index);
  
  public void sendSelectedAlarmId(int index);
  
 

}
