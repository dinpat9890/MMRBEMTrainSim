/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.base.impl;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import com.sydac.core.runtimedata.HubIO;
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
import com.sydac.mmrbem.tcms.fe.base.ServiceRequestHandler;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.gui.action.StationScreenCommandRequest.StationCommand;
import com.sydac.mmrbem.tcms.fe.gui.state.AutoRotationStatus;
import com.sydac.mmrbem.tcms.fe.gui.state.CameraButtonSelectionId;
import com.sydac.mmrbem.tcms.fe.gui.state.EventModeStatus;
import com.sydac.mmrbem.tcms.fe.gui.state.InternalExternalViewStatus;
import com.sydac.peer.application.SimplePropertySetter;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;
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
  public void sendPulseRequest(final String number, final double set, final double reset)
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
  public void sendRequestWithDelayedReset(String number, Integer val)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), val);
    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(
        () -> propertySetter.setNumber(HubIO.createIOPropertyName(number), false), 2000,
        TimeUnit.MILLISECONDS);
  }

  @Override
  public void sendScreenChangeRequest(ScreenId screenId, IFrontend frontend)
  {
    if (frontend == Frontend.TCMS)
    {
      sendPulseRequest(VDUInputs.TCMS_SCREEN_CHANGE_REQUEST, screenId.getId(), -1);
      sendPulseRequest(VDUInputs.TCMS_POPUP_CHANGE_REQUEST, ScreenId.BLANK_SCREEN.getId(), -1);
    }
    else if (frontend == Frontend.CCTV)
    {
      sendPulseRequest(VDUInputs.CCTV_SCREEN_CHANGE_REQUEST, screenId.getId(), -1);
      sendPulseRequest(VDUInputs.CCTV_POPUP_CHANGE_REQUEST, ScreenId.BLANK_SCREEN.getId(), -1);
    }

  }

  @Override
  public void sendPopupChangeRequest(ScreenId popupId, IFrontend frontend)
  {
    if (frontend == Frontend.TCMS)
    {
      sendPulseRequest(VDUInputs.TCMS_POPUP_CHANGE_REQUEST, popupId.getId(), -1);
    }
    else if (frontend == Frontend.CCTV)
    {
      sendPulseRequest(VDUInputs.CCTV_POPUP_CHANGE_REQUEST, popupId.getId(), -1);
    }
  }

  @Override
  public void sendVDUModeChangeRequest(VDUModeEnum vduModeId, IFrontend frontend)
  {
    if (frontend == Frontend.TCMS)
    {
      sendPulseRequest(VDUInputs.TCMS_VDU_BUTTON_REQUEST, vduModeId.getId(), -1);
    }
    else if (frontend == Frontend.CCTV)
    {
      sendPulseRequest(VDUInputs.CCTV_VDU_BUTTON_REQUEST, vduModeId.getId(), -1);
    }
  }

  @Override
  public void sendVDUBrightnessChangeRequest(VDUBrightnessModeEnum vduBrightness, IFrontend frontend)
  {
    if (frontend == Frontend.TCMS)
    {
      sendPulseRequest(VDUInputs.TCMS_BRIGHTNESS_BUTTON_REQUEST, vduBrightness.getId(), -1);
    }
    else if (frontend == Frontend.CCTV)
    {
      sendPulseRequest(VDUInputs.CCTV_BRIGHTNESS_BUTTON_REQUEST, vduBrightness.getId(), -1);
    }
  }

  @Override
  public void sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum footerSubmenu)
  {
    sendPulseRequest(VDUInputs.FOOTER_SUBMENU_CHANGE_REQUEST, footerSubmenu.getId(), -1);
  }

  @Override
  public void sendKeyPadButtonRequest(KeyPadEnum keyPadEnum)
  {
    sendPulseRequest(VDUInputs.KEYPAD_BUTTON_REQUEST, keyPadEnum.getValue(), -1);
  }

  @Override
  public void sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum enumId)
  {
    sendPulseRequest(VDUInputs.ACTIVE_FAULTS_SYSTEM_FILTER_BUTTON_REQUEST, enumId.getSysFilterId(), -1);
  }

  @Override
  public void sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum enumId)
  {
    sendPulseRequest(VDUInputs.ACTIVE_FAULTS_CAR_FILTER_BUTTON_REQUEST, enumId.getCarFilterId(), -1);
  }

  @Override
  public void sendActiveFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum enumId)
  {
    sendPulseRequest(VDUInputs.ACTIVE_FAULTS_PRIORITY_FILTER_BUTTON_REQUEST, enumId.getPriorityFilterId(),
        -1);
  }

  @Override
  public void sendActiveFaultsUpdateButtonRequest(Integer val)
  {
    sendPulseRequest(VDUInputs.ACTIVE_FAULTS_UPDATE_BUTTON_REQUEST, val, -1);
  }

  @Override
  public void sendSelectedActiveFaultRequest(Integer val)
  {
    sendPulseRequest(VDUInputs.ACTIVE_FAULT_LIST_SELECTED_INDEX, val, -1);
  }

  @Override
  public void sendEventAreaFaultDetailRequest(Integer faultId)
  {
    sendPulseRequest(VDUInputs.EVENT_AREA_FAULT_DETAIL_REQUEST, faultId, -1);
  }

  @Override
  public void sendActiveFaultsPageUpButtonRequest(Integer val)
  {
    sendPulseRequest(VDUInputs.ACTIVE_FAULTS_PAGE_UP_BUTTON_REQUEST, val, -1);
  }

  @Override
  public void sendActiveFaultsPageDownButtonRequest(Integer val)
  {
    sendPulseRequest(VDUInputs.ACTIVE_FAULTS_PAGE_DOWN_BUTTON_REQUEST, val, -1);
  }

  @Override
  public void sendEventIdAcknowledged(Integer eventId)
  {
    sendPulseRequest(VDUInputs.ACTIVE_FAULTS_ACKNOWLEDGE_BUTTON_REQUEST, eventId, 0);
  }

  @Override
  public void sendCCTVCameraVehicleIndexRequest(CameraButtonSelectionId id)
  {
    sendPulseRequest(VDUInputs.CURRENT_SELECTED_VEHICLE, id.getSelectionId(), -1);
  }

  @Override
  public void sendCCTVSelectedCameraIdRequest(Integer viewValue)
  {
    sendPulseRequest(VDUInputs.SELECTED_CAMERA_ID, viewValue, -1);
  }

  @Override
  public void sendCCTVExteriorCameraTypeRequest(CameraButtonSelectionId id)
  {
    sendPulseRequest(VDUInputs.EXT_CAMERA_TYPE_REQUEST, id.getSelectionId(), -1);
  }

  @Override
  public void sendCCTVInternalExternalSelectionRequest(InternalExternalViewStatus status)
  {
    sendPulseRequest(VDUInputs.INTERNAL_OR_EXTERNAL_SELECTION_REQUEST, status.getValue(), -1);
  }

  @Override
  public void sendCCTVAutoRotationRequest(AutoRotationStatus status)
  {
    sendPulseRequest(VDUInputs.AUTO_ROTATION_REQUEST, status.getValue(), -1);
  }

  @Override
  public void sendCCTVEventModeRequest(EventModeStatus status)
  {
    sendPulseRequest(VDUInputs.ALARM_MODE, status.getValue(), -1);
  }

  @Override
  public void sendCCTVEventTypeRequest(Integer type)
  {
    sendPulseRequest(VDUInputs.ALARM_TYPE, type, 0);
  }

  @Override
  public void sendCCTVPreviousVehicleRequest(Integer value)
  {
    sendPulseRequest(VDUInputs.PREVIOUS_ARROW_PRESSED_REQUEST, value, 0);
  }

  @Override
  public void sendCCtVNextVehicleRequest(Integer value)
  {
    sendPulseRequest(VDUInputs.NEXT_ARROW_PRESSED_REQUEST, value, 0);
  }

  @Override
  public void sendCCTVExternalCameraCarIndexRequest(Integer carId)
  {
    sendPulseRequest(VDUInputs.SELECTED_EXT_CAMTYP_VEHICLE_REQ, carId, 0);
  }

  @Override
  public void onDoubbleClickOnCameraFeed(Integer selectedCarId, Integer selectedCameraId, ScreenId cctvScreen,
      IFrontend frontend)
  {
    sendCCTVExternalCameraCarIndexRequest(selectedCarId);

    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(() -> sendCCTVSelectedCameraIdRequest(selectedCameraId), 50,
        TimeUnit.MILLISECONDS);

    sendScreenChangeRequest(cctvScreen, frontend);

  }

  @Override
  public void onDoubbleClickOnHybridCameraFeed(Integer selectedCarId, Integer selectedCameraId,
      IFrontend frontend)
  {
    sendCCTVExternalCameraCarIndexRequest(selectedCarId);

    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(() -> sendCCTVSelectedCameraIdRequest(selectedCameraId), 50,
        TimeUnit.MILLISECONDS);

  }

  @Override
  public void sendIsolateButtonRequest(String number, int val)
  {
    sendRequest(number, val);
  }

  @Override
  public void sendPBIsolateBogie1Req(Integer val)
  {
    sendPulseRequest(VDUInputs.PB_ISOLATE_BOGIE_1_REQ, val, -1);
  }

  @Override
  public void sendPBIsolateBogie2Req(Integer val)
  {
    sendPulseRequest(VDUInputs.PB_ISOLATE_BOGIE_2_REQ, val, -1);
  }

  @Override
  public void sendPBSelectedIsolateCar(Integer val)
  {
    sendPulseRequest(VDUInputs.SELECTED_PB_ISOLATE_CAR, val, -1);
  }

  @Override
  public void sendSelectedDoorIsolateCar(Integer val)
  {
    sendPulseRequest(VDUInputs.SELECTED_DOOR_ISO_REINS_CAR, val, -1);
  }

  @Override
  public void sendDoorIsolateReq(String input, Integer val)
  {
    sendPulseRequest(input, val, -1);
  }

  @Override
  public void sendActiveHybridPanelSideReq(Integer val)
  {
    sendRequest(VDUInputs.ACTIVE_HYBRID_PANEL_SIDE_REQ, val);
  }

  @Override
  public void sendHybridPanelNextImageReq(Integer val)
  {
    sendPulseRequest(VDUInputs.HYBRID_PANEL_NEXT_IMAGE_BUTTON, val, -1);
  }

  @Override
  public void sendHybridPanelPrevImageReq(Integer val)
  {
    sendPulseRequest(VDUInputs.HYBRID_PANEL_PREV_IMAGE_BUTTON, val, -1);
  }

  @Override
  public void sendFrontLowHornSoundReq(Integer val)
  {
    sendPulseRequest(VDUInputs.LOW_SOUND_HORN_FRONT_REQ, val, 0);
  }

  @Override
  public void sendRearLowHornSoundReq(Integer val)
  {
    sendPulseRequest(VDUInputs.LOW_SOUND_HORN_REAR_REQ, val, 0);
  }

  @Override
  public void sendFrontHighHornSoundReq(Integer val)
  {
    sendPulseRequest(VDUInputs.HIGH_SOUND_HORN_FRONT_REQ, val, 0);
  }

  @Override
  public void sendRearHighHornSoundReq(Integer val)
  {
    sendPulseRequest(VDUInputs.HIGH_SOUND_HORN_REAR_REQ, val, 0);
  }

  @Override
  public void sendFrontHornIsolateReinsertReq(Integer val)
  {
    sendRequest(VDUInputs.HORN_ISOLATE_RESINSERT_FRONT_REQ, val);
  }

  @Override
  public void sendRearHornIsolateReinsertReq(Integer val)
  {
    sendRequest(VDUInputs.HORN_ISOLATE_RESINSERT_REAR_REQ, val);
  }

  @Override
  public void sendHVCommandReq(String number, Integer val)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), val);
    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(() -> propertySetter.setNumber(HubIO.createIOPropertyName(number), -1),
        1000, TimeUnit.MILLISECONDS);
  }

  @Override
  public void sendSpecialModesActivateReq(String number, Integer val)
  {
    scheduledExecutorService.schedule(() -> propertySetter.setNumber(HubIO.createIOPropertyName(number), val),
        1000, TimeUnit.MILLISECONDS);
  }

  @Override
  public void sendWflIsolateReq(String number, Integer val)
  {
    scheduledExecutorService.schedule(() -> propertySetter.setNumber(HubIO.createIOPropertyName(number), val),
        500, TimeUnit.MILLISECONDS);
  }

  @Override
  public void sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum enumId)
  {
    sendPulseRequest(VDUInputs.LOGGED_FAULTS_SYSTEM_FILTER_BUTTON_REQUEST, enumId.getSysFilterId(), -1);
  }

  @Override
  public void sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum enumId)
  {
    sendPulseRequest(VDUInputs.LOGGED_FAULTS_CAR_FILTER_BUTTON_REQUEST, enumId.getCarFilterId(), -1);
  }

  @Override
  public void sendLoggedFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum enumId)
  {
    sendPulseRequest(VDUInputs.LOGGED_FAULTS_PRIORITY_FILTER_BUTTON_REQUEST, enumId.getPriorityFilterId(),
        -1);
  }

  @Override
  public void sendSelectedLoggedFaultRequest(Integer val)
  {
    sendPulseRequest(VDUInputs.LOGGED_FAULT_LIST_SELECTED_INDEX, val, -1);
  }

  @Override
  public void sendLoggedFaultsPageUpButtonRequest(Integer val)
  {
    sendPulseRequest(VDUInputs.LOGGED_FAULTS_PAGE_UP_BUTTON_REQUEST, val, -1);
  }

  @Override
  public void sendLoggedFaultsPageDownButtonRequest(Integer val)
  {
    sendPulseRequest(VDUInputs.LOGGED_FAULTS_PAGE_DOWN_BUTTON_REQUEST, val, -1);
  }

  @Override
  public void sendHVCommandDelayReq(String number, Integer val, Integer resetVal)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), val);
    scheduledExecutorService.schedule(
        () -> propertySetter.setNumber(HubIO.createIOPropertyName(number), resetVal), 300,
        TimeUnit.MILLISECONDS);

    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(() -> propertySetter.setNumber(HubIO.createIOPropertyName(number), -1),
        1200, TimeUnit.MILLISECONDS);

  }

  @Override
  public void sendModeChangeRequest(TCMSModeEnum modeId)
  {
    sendPulseRequest(VDUInputs.ROUTE_SCREEN_MODE_SELECTION_REQUEST, modeId.getModeId(), -1);
    
  }

  @Override
  public void sendRouteKeyPadButtonRequest(KeyPadEnum keyPadEnum)
  {
    sendPulseRequest(VDUInputs.ROUTE_SCREEN_KEYPAD_BUTTON_REQUEST, keyPadEnum.getValue(), -1);
  }
  
  
  public void sendStationRequest(StationCommand command, Integer val, Integer resetVal )
  {
    sendPulseRequest(command.getInputName(),val, resetVal);
  }
  
  
}