/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.EmergencyBrakeInterlockScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.EmergencyBrakeInterlockScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class EmergencyBrakeInterlockScreenController extends AbstractTCMSController
{

  private EmergencyBrakeInterlockScreenModel emergencyBrakeInterlockScreenModel;

  @FXML
  private Label emergencyLbl1;

  @FXML
  private Label emergencyLbl2;

  @FXML
  private Label emergencyLbl3;

  @FXML
  private Label emergencyLbl4;

  @FXML
  private Label emergencyLbl5;

  @FXML
  private Label emergencyLbl6;

  @FXML
  private Label emergencyLbl7;

  @FXML
  private Label emergencyLbl8;

  @FXML
  private Label emergencyLbl9;

  @FXML
  private Label emergencyLbl10;

  @FXML
  private Label emergencyLbl11;

  @FXML
  private Label emergencyLbl3CarNo;

  @FXML
  private Label emergencyLbl5CarNo;

  private NodePseudoClassProperty emergency1StateProperty;

  private NodePseudoClassProperty emergency2StateProperty;

  private NodePseudoClassProperty emergency3StateProperty;

  private NodePseudoClassProperty emergency4StateProperty;

  private NodePseudoClassProperty emergency5StateProperty;

  private NodePseudoClassProperty emergency6StateProperty;

  private NodePseudoClassProperty emergency7StateProperty;

  private NodePseudoClassProperty emergency8StateProperty;

  private NodePseudoClassProperty emergency9StateProperty;

  private NodePseudoClassProperty emergency10StateProperty;

  private NodePseudoClassProperty emergency11StateProperty;

  private NodePseudoClassProperty emergencyCarNo3LblStateProperty;

  private NodePseudoClassProperty emergencyCarNo5LblStateProperty;

  private FooterPanelModel footerPanelModel;

  private ChangeListener<String> ebByCcListener;

  private ChangeListener<String> ebByPushButtonFirstCarListener;

  private ChangeListener<String> ebByPushButtonLastCarListener;

  private ChangeListener<String> ebByEbByDeadmanFirstCarListener;

  private ChangeListener<String> ebByEbByDeadmanLastCarListener;

  private ChangeListener<String> ebByNonCabEnabledListener;

  private ChangeListener<String> ebByNonDirectionSelectedListener;

  private ChangeListener<String> ebEbByMcListener;

  private ChangeListener<String> ebEbByBrakeLoopListener;

  private ChangeListener<String> ebEbByAtcZeroSpeedListener;

  private ChangeListener<Number> lastVehicleIdListener;

  private ChangeListener<String> masterControllerInFSBListener;

  @Override
  public void detachListeners()
  {}

  @Override
  public void initializeImpl()
  {
    emergencyBrakeInterlockScreenModel = new EmergencyBrakeInterlockScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new EmergencyBrakeInterlockScreenBinder(emergencyBrakeInterlockScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    emergency1StateProperty = new NodePseudoClassProperty(emergencyLbl1);
    emergency2StateProperty = new NodePseudoClassProperty(emergencyLbl2);
    emergency3StateProperty = new NodePseudoClassProperty(emergencyLbl3);
    emergency4StateProperty = new NodePseudoClassProperty(emergencyLbl4);
    emergency5StateProperty = new NodePseudoClassProperty(emergencyLbl5);
    emergency6StateProperty = new NodePseudoClassProperty(emergencyLbl6);
    emergency7StateProperty = new NodePseudoClassProperty(emergencyLbl7);
    emergency8StateProperty = new NodePseudoClassProperty(emergencyLbl8);
    emergency9StateProperty = new NodePseudoClassProperty(emergencyLbl9);
    emergency10StateProperty = new NodePseudoClassProperty(emergencyLbl10);
    emergencyCarNo3LblStateProperty = new NodePseudoClassProperty(emergencyLbl3CarNo);
    emergencyCarNo5LblStateProperty = new NodePseudoClassProperty(emergencyLbl5CarNo);
    emergency11StateProperty = new NodePseudoClassProperty(emergencyLbl11);

    ebByCcListener = (observable, oldVal,
        newVal) -> updatedEbByCcState(emergencyBrakeInterlockScreenModel.getEbByCcState().get());
    emergencyBrakeInterlockScreenModel.getEbByCcState().addListener(ebByCcListener);

    ebByPushButtonFirstCarListener = (observable, oldVal, newVal) -> updatedEbByPushButtonFirstCarState(
        emergencyBrakeInterlockScreenModel.getEbByPushButtonFirstState().get());
    emergencyBrakeInterlockScreenModel.getEbByPushButtonFirstState()
        .addListener(ebByPushButtonFirstCarListener);

    ebByPushButtonLastCarListener = (observable, oldVal, newVal) -> updatedEbByPushButtonLastCarState(
        emergencyBrakeInterlockScreenModel.getEbByPushButtonLastCarState().get());
    emergencyBrakeInterlockScreenModel.getEbByPushButtonLastCarState()
        .addListener(ebByPushButtonLastCarListener);

    ebByEbByDeadmanFirstCarListener = (observable, oldVal, newVal) -> updatedEbByDeadmanFirstCarState(
        emergencyBrakeInterlockScreenModel.getEbByEbByDeadmanFirstCarState().get());
    emergencyBrakeInterlockScreenModel.getEbByEbByDeadmanFirstCarState()
        .addListener(ebByEbByDeadmanFirstCarListener);

    ebByEbByDeadmanLastCarListener = (observable, oldVal, newVal) -> updatedEbByDeadmanLastCarState(
        emergencyBrakeInterlockScreenModel.getEbByEbByDeadmanLastCarState().get());
    emergencyBrakeInterlockScreenModel.getEbByEbByDeadmanLastCarState()
        .addListener(ebByEbByDeadmanLastCarListener);

    ebByNonCabEnabledListener = (observable, oldVal, newVal) -> updatedEbByNonCabEnabledState(
        emergencyBrakeInterlockScreenModel.getEbByNonCabEnabledState().get());
    emergencyBrakeInterlockScreenModel.getEbByNonCabEnabledState().addListener(ebByNonCabEnabledListener);

    ebByNonDirectionSelectedListener = (observable, oldVal, newVal) -> updatedEbByNonDirectionSelectedState(
        emergencyBrakeInterlockScreenModel.getEbByNonDirectionSelectedState().get());
    emergencyBrakeInterlockScreenModel.getEbByNonDirectionSelectedState()
        .addListener(ebByNonDirectionSelectedListener);

    ebEbByMcListener = (observable, oldVal,
        newVal) -> updatedEbByMcState(emergencyBrakeInterlockScreenModel.getEbByMcState().get());
    emergencyBrakeInterlockScreenModel.getEbByMcState().addListener(ebEbByMcListener);

    ebEbByBrakeLoopListener = (observable, oldVal, newVal) -> updatedEbByBrakeLoopSelectedState(
        emergencyBrakeInterlockScreenModel.getEbByBrakeLoopState().get());
    emergencyBrakeInterlockScreenModel.getEbByBrakeLoopState().addListener(ebEbByBrakeLoopListener);

    ebEbByAtcZeroSpeedListener = (observable, oldVal, newVal) -> updatedEbByAtcZeroSpeedState(
        emergencyBrakeInterlockScreenModel.getEbEbByAtcZeroSpeedState().get());
    emergencyBrakeInterlockScreenModel.getEbEbByAtcZeroSpeedState().addListener(ebEbByAtcZeroSpeedListener);

    lastVehicleIdListener = (observable, oldVal,
        newVal) -> updatedLastVehicleId(emergencyBrakeInterlockScreenModel.getLastVehicleId().get());
    emergencyBrakeInterlockScreenModel.getLastVehicleId().addListener(lastVehicleIdListener);

    masterControllerInFSBListener = (observable, oldValue, newValue) -> updateMasterControllerInFSBState(
        emergencyBrakeInterlockScreenModel.getMasterControllerInFSBPositionState().get());
    emergencyBrakeInterlockScreenModel.getMasterControllerInFSBPositionState()
        .addListener(masterControllerInFSBListener);

  }

  private void updateMasterControllerInFSBState(String string)
  {
    emergency11StateProperty.set(string);
  }

  private void updatedLastVehicleId(int vehicleId)
  {
    emergencyLbl5CarNo.setText(Integer.toString(vehicleId));
    emergencyLbl3CarNo.setText(Integer.toString(vehicleId));
  }

  private void updatedEbByAtcZeroSpeedState(String string)
  {
    emergency10StateProperty.set(string);
  }

  private void updatedEbByBrakeLoopSelectedState(String string)
  {
    emergency9StateProperty.set(string);
  }

  private void updatedEbByMcState(String string)
  {
    emergency8StateProperty.set(string);
  }

  private void updatedEbByNonDirectionSelectedState(String string)
  {
    emergency7StateProperty.set(string);
  }

  private void updatedEbByNonCabEnabledState(String string)
  {
    emergency6StateProperty.set(string);
  }

  private void updatedEbByDeadmanLastCarState(String string)
  {
    emergency5StateProperty.set(string);
    emergencyCarNo5LblStateProperty.set(string);
  }

  private void updatedEbByDeadmanFirstCarState(String string)
  {
    emergency4StateProperty.set(string);
  }

  private void updatedEbByPushButtonFirstCarState(String string)
  {
    emergency2StateProperty.set(string);
  }

  private void updatedEbByPushButtonLastCarState(String string)
  {
    emergency3StateProperty.set(string);
    emergencyCarNo3LblStateProperty.set(string);
  }

  private void updatedEbByCcState(String string)
  {
    emergency1StateProperty.set(string);
  }

}
