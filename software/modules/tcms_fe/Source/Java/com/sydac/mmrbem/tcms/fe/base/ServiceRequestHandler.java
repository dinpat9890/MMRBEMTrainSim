/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.base;

import com.sydac.mmrbem.cabscreens.fe.common.IFrontend;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsCarFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsPriorityFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsSystemFilterEnum;
import com.sydac.mmrbem.tcms.common.state.FooterSubmenuPopupEnum;
import com.sydac.mmrbem.tcms.common.state.KeyPadEnum;
import com.sydac.mmrbem.tcms.common.state.TCMSModeEnum;
import com.sydac.mmrbem.tcms.common.state.VDUBrightnessModeEnum;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;
import com.sydac.mmrbem.tcms.fe.gui.action.StationScreenCommandRequest.StationCommand;
import com.sydac.mmrbem.tcms.fe.gui.state.AutoRotationStatus;
import com.sydac.mmrbem.tcms.fe.gui.state.CameraButtonSelectionId;
import com.sydac.mmrbem.tcms.fe.gui.state.EventModeStatus;
import com.sydac.mmrbem.tcms.fe.gui.state.InternalExternalViewStatus;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.framework.GatewayProvider;

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

  public void sendRequestWithDelayedReset(final String number, Integer val);

  public void sendButtonClickRequest(String buttonName);

  public void sendScreenChangeRequest(ScreenId screenId, IFrontend frontend);

  public void sendPopupChangeRequest(ScreenId popupId, IFrontend frontend);

  public void sendVDUModeChangeRequest(VDUModeEnum vduModeId, IFrontend frontend);

  public void sendVDUBrightnessChangeRequest(VDUBrightnessModeEnum vduBrightness, IFrontend frontend);

  public void sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum footerSubmenu);

  public void sendKeyPadButtonRequest(KeyPadEnum key);

  public void sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum enumId);

  public void sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum enumId);

  public void sendActiveFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum enumId);

  public void sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId buttonId);

  public void sendCCTVSelectedCameraIdRequest(Integer viewValue);

  public void sendCCTVExteriorCameraTypeRequest(CameraButtonSelectionId buttonId);

  public void sendCCTVInternalExternalSelectionRequest(InternalExternalViewStatus status);

  public void sendCCTVAutoRotationRequest(AutoRotationStatus status);

  public void sendCCTVEventModeRequest(EventModeStatus status);

  public void sendCCTVEventTypeRequest(Integer type);

  public void sendCCTVPreviousVehicleRequest(Integer value);

  public void sendCCtVNextVehicleRequest(Integer value);

  public void sendCCTVExternalCameraCarIndexRequest(Integer carId);

  public void sendActiveFaultsUpdateButtonRequest(Integer val);

  public void sendActiveFaultsPageUpButtonRequest(Integer val);

  public void sendActiveFaultsPageDownButtonRequest(Integer val);

  public void sendSelectedActiveFaultRequest(Integer val);

  public void sendEventAreaFaultDetailRequest(Integer faultId);

  public void sendEventIdAcknowledged(Integer valueOf);

  public void onDoubbleClickOnCameraFeed(Integer selectedCarId, Integer selectedCameraId,
      ScreenId cctvSingleFeedScreen, IFrontend frontend);

  public void sendIsolateButtonRequest(String number, int val);

  public void onDoubbleClickOnHybridCameraFeed(Integer firstFeedSelectedCarId,
      Integer firstFeedSelectedCameraId, IFrontend frontend);

  public void sendPBIsolateBogie1Req(Integer val);

  public void sendPBIsolateBogie2Req(Integer val);

  public void sendPBSelectedIsolateCar(Integer val);

  public void sendDoorIsolateReq(String input, Integer val);

  public void sendSelectedDoorIsolateCar(Integer val);

  public void sendActiveHybridPanelSideReq(Integer val);

  public void sendHybridPanelNextImageReq(Integer val);

  public void sendHybridPanelPrevImageReq(Integer val);

  public void sendFrontLowHornSoundReq(Integer val);

  public void sendRearLowHornSoundReq(Integer val);

  public void sendFrontHighHornSoundReq(Integer val);

  public void sendRearHighHornSoundReq(Integer val);

  public void sendFrontHornIsolateReinsertReq(Integer val);

  public void sendRearHornIsolateReinsertReq(Integer val);

  public void sendHVCommandReq(final String number, Integer val);

  public void sendSpecialModesActivateReq(final String number, Integer val);

  public void sendWflIsolateReq(String number, Integer val);

  public void sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum enumId);

  public void sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum enumId);

  public void sendLoggedFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum enumId);

  public void sendLoggedFaultsPageUpButtonRequest(Integer val);

  public void sendLoggedFaultsPageDownButtonRequest(Integer val);

  public void sendSelectedLoggedFaultRequest(Integer val);

  public void sendHVCommandDelayReq(String number, Integer val, Integer resetVal);
  
  public void sendModeChangeRequest(TCMSModeEnum modeId);
  public void sendRouteKeyPadButtonRequest(KeyPadEnum key);
  
  public void sendStationRequest(StationCommand command, Integer val, Integer resetVal);

}
