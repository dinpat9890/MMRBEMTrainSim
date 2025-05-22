/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EnableToRunList.ERState;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.BrakeSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.EnableToRunInterlockScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.BrakeSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.EnableToRunInterlockScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class EnableToRunInterlockScreenController extends AbstractTCMSController
{

  @FXML
  private Label enableLbl1;

  @FXML
  private Label enableLbl2;

  @FXML
  private Label enableLbl3;

  @FXML
  private Label enableLbl4;

  @FXML
  private Label enableLbl5;

  @FXML
  private Label enableLbl6;

  @FXML
  private Label enableLbl7;

  @FXML
  private Label enableLbl8;

  @FXML
  private Label enableLbl9;

  @FXML
  private Label enableLbl10;

  @FXML
  private Label enableLbl11;

  @FXML
  private Label enableLbl3CarNo;

  @FXML
  private Label enableLbl5CarNo;

  @FXML
  private Label enableLbl12;

  @FXML
  private Label enableLbl13;

  @FXML
  private Label enableLbl14;

  @FXML
  private Label enableLbl15;

  @FXML
  private Label enableLbl16;

  @FXML
  private Label enableLbl17;

  @FXML
  private Label enableLbl18;

  @FXML
  private Label enableLbl101;

  @FXML
  private Label enableLbl181;

  private NodePseudoClassProperty enable1StateProperty;

  private NodePseudoClassProperty enable2StateProperty;

  private NodePseudoClassProperty enable3StateProperty;

  private NodePseudoClassProperty enable4StateProperty;

  private NodePseudoClassProperty enable5StateProperty;

  private NodePseudoClassProperty enable6StateProperty;

  private NodePseudoClassProperty enable7StateProperty;

  private NodePseudoClassProperty enable8StateProperty;

  private NodePseudoClassProperty enable9StateProperty;

  private NodePseudoClassProperty enable10StateProperty;

  private NodePseudoClassProperty enable11StateProperty;

  private NodePseudoClassProperty enableCarNo3LblStateProperty;

  private NodePseudoClassProperty enableCarNo5LblStateProperty;

  private FooterPanelModel footerPanelModel;

  private NodePseudoClassProperty enable12StateProperty;

  private NodePseudoClassProperty enable13StateProperty;

  private NodePseudoClassProperty enable14StateProperty;

  private NodePseudoClassProperty enable15StateProperty;

  private NodePseudoClassProperty enable16StateProperty;

  private NodePseudoClassProperty enable17StateProperty;

  private NodePseudoClassProperty enableLbl18StateProperty;

  private NodePseudoClassProperty enableLbl101StateProperty;

  private NodePseudoClassProperty enableLbl181StateProperty;

  private EnableToRunInterlockScreenModel enableToRunInterlockScreenModel;

  private ChangeListener<Number> lastVehicleIdListener;

  private BrakeSystemScreenModel brakeSystemScreenModel;

  @Override
  public void detachListeners()
  {}

  @Override
  public void initializeImpl()
  {

    enableToRunInterlockScreenModel = new EnableToRunInterlockScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new EnableToRunInterlockScreenBinder(enableToRunInterlockScreenModel));

    brakeSystemScreenModel = new BrakeSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new BrakeSystemScreenBinder(brakeSystemScreenModel));

    lastVehicleIdListener = (observable, oldVal,
        newVal) -> updatedLastVehicleId(enableToRunInterlockScreenModel.getLastVehicleId().get());
    enableToRunInterlockScreenModel.getLastVehicleId().addListener(lastVehicleIdListener);

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    enable1StateProperty = new NodePseudoClassProperty(enableLbl1);
    enable2StateProperty = new NodePseudoClassProperty(enableLbl2);
    enable3StateProperty = new NodePseudoClassProperty(enableLbl3);
    enable4StateProperty = new NodePseudoClassProperty(enableLbl4);
    enable5StateProperty = new NodePseudoClassProperty(enableLbl5);
    enable6StateProperty = new NodePseudoClassProperty(enableLbl6);
    enable7StateProperty = new NodePseudoClassProperty(enableLbl7);
    enable8StateProperty = new NodePseudoClassProperty(enableLbl8);
    enable9StateProperty = new NodePseudoClassProperty(enableLbl9);
    enable10StateProperty = new NodePseudoClassProperty(enableLbl10);
    enableCarNo3LblStateProperty = new NodePseudoClassProperty(enableLbl3CarNo);
    enableCarNo5LblStateProperty = new NodePseudoClassProperty(enableLbl5CarNo);
    enable11StateProperty = new NodePseudoClassProperty(enableLbl11);

    enable12StateProperty = new NodePseudoClassProperty(enableLbl12);
    enable13StateProperty = new NodePseudoClassProperty(enableLbl13);
    enable14StateProperty = new NodePseudoClassProperty(enableLbl14);
    enable15StateProperty = new NodePseudoClassProperty(enableLbl15);
    enable16StateProperty = new NodePseudoClassProperty(enableLbl16);
    enable17StateProperty = new NodePseudoClassProperty(enableLbl17);
    enableLbl18StateProperty = new NodePseudoClassProperty(enableLbl18);

    enableLbl101StateProperty = new NodePseudoClassProperty(enableLbl101);
    enableLbl181StateProperty = new NodePseudoClassProperty(enableLbl181);

    updatedLastVehicleId(enableToRunInterlockScreenModel.getLastVehicleId().get());

    ChangeListener<String> eb1Listener = (observable, oldVal, newVal) -> updatedHighVolatgeMissing(
        enableToRunInterlockScreenModel.getErHighVolatgeMissingState().get());
    enableToRunInterlockScreenModel.getErHighVolatgeMissingState().addListener(eb1Listener);

    updatedHighVolatgeMissing(enableToRunInterlockScreenModel.getErHighVolatgeMissingState().get());

    ChangeListener<String> eb2Listener = (observable, oldVal,
        newVal) -> updatedCabNotEnabled(enableToRunInterlockScreenModel.getErCabNotEnabledState().get());
    enableToRunInterlockScreenModel.getErCabNotEnabledState().addListener(eb2Listener);

    updatedCabNotEnabled(enableToRunInterlockScreenModel.getErCabNotEnabledState().get());

    ChangeListener<String> eb3Listener = (observable, oldVal,
        newVal) -> updatedDrivingMode(enableToRunInterlockScreenModel.getErDrivingModeNotOkState().get());
    enableToRunInterlockScreenModel.getErDrivingModeNotOkState().addListener(eb3Listener);

    updatedDrivingMode(enableToRunInterlockScreenModel.getErDrivingModeNotOkState().get());

    ChangeListener<String> eb4Listener = (observable, oldVal, newVal) -> updatedTrainDirectionMissing(
        enableToRunInterlockScreenModel.getErTrainDirectionMissingState().get());
    enableToRunInterlockScreenModel.getErTrainDirectionMissingState().addListener(eb4Listener);

    updatedTrainDirectionMissing(enableToRunInterlockScreenModel.getErTrainDirectionMissingState().get());

    ChangeListener<String> eb5Listener = (observable, oldVal,
        newVal) -> updatedAtcStatus(enableToRunInterlockScreenModel.getErAtcStatusState().get());
    enableToRunInterlockScreenModel.getErAtcStatusState().addListener(eb5Listener);

    updatedAtcStatus(enableToRunInterlockScreenModel.getErAtcStatusState().get());

    ChangeListener<String> eb6Listener = (observable, oldVal,
        newVal) -> updatedTrainReady(enableToRunInterlockScreenModel.getErTrainReadyState().get());
    enableToRunInterlockScreenModel.getErTrainReadyState().addListener(eb6Listener);

    updatedTrainReady(enableToRunInterlockScreenModel.getErTrainReadyState().get());

    ChangeListener<String> eb7Listener = (observable, oldVal,
        newVal) -> updatedManyRPressure(enableToRunInterlockScreenModel.getErManyRPressureState().get());
    enableToRunInterlockScreenModel.getErManyRPressureState().addListener(eb7Listener);

    updatedManyRPressure(enableToRunInterlockScreenModel.getErManyRPressureState().get());

    ChangeListener<String> eb8Listener = (observable, oldVal,
        newVal) -> updatedEpicCutout(enableToRunInterlockScreenModel.getErManyEpicCutoutState().get());
    enableToRunInterlockScreenModel.getErManyEpicCutoutState().addListener(eb8Listener);

    updatedEpicCutout(enableToRunInterlockScreenModel.getErManyEpicCutoutState().get());

    ChangeListener<String> eb9Listener = (observable, oldVal,
        newVal) -> updatedBogieIsolated(enableToRunInterlockScreenModel.getErManyBogieIsolatedState().get());
    enableToRunInterlockScreenModel.getErManyBogieIsolatedState().addListener(eb9Listener);

    updatedBogieIsolated(enableToRunInterlockScreenModel.getErManyBogieIsolatedState().get());

    ChangeListener<String> eb10Listener = (observable, oldVal,
        newVal) -> updatedMotoringTl(enableToRunInterlockScreenModel.getErMotoringTlState().get());
    enableToRunInterlockScreenModel.getErMotoringTlState().addListener(eb10Listener);

    updatedMotoringTl(enableToRunInterlockScreenModel.getErMotoringTlState().get());

    ChangeListener<String> eb11Listener = (observable, oldVal,
        newVal) -> updatedBrakeLoopTl(enableToRunInterlockScreenModel.getErBrakeLoopTlState().get());
    enableToRunInterlockScreenModel.getErBrakeLoopTlState().addListener(eb11Listener);

    updatedBrakeLoopTl(enableToRunInterlockScreenModel.getErBrakeLoopTlState().get());

    ChangeListener<String> eb12Listener = (observable, oldVal,
        newVal) -> updatedParkingBrakeTl(enableToRunInterlockScreenModel.getErParkingBrakeTlState().get());
    enableToRunInterlockScreenModel.getErParkingBrakeTlState().addListener(eb12Listener);

    updatedParkingBrakeTl(enableToRunInterlockScreenModel.getErParkingBrakeTlState().get());

    ChangeListener<String> eb13Listener = (observable, oldVal,
        newVal) -> updatedDoorLoopOpenTl(enableToRunInterlockScreenModel.getErDoorLoopOpenTlState().get());
    enableToRunInterlockScreenModel.getErDoorLoopOpenTlState().addListener(eb13Listener);

    updatedDoorLoopOpenTl(enableToRunInterlockScreenModel.getErDoorLoopOpenTlState().get());

    ChangeListener<String> eb14Listener = (observable, oldVal,
        newVal) -> updatedZvrdFirstCarState(enableToRunInterlockScreenModel.getErZvrdFirstCarState().get());
    enableToRunInterlockScreenModel.getErZvrdFirstCarState().addListener(eb14Listener);

    updatedZvrdFirstCarState(enableToRunInterlockScreenModel.getErZvrdFirstCarState().get());

    ChangeListener<String> eb15Listener = (observable, oldVal,
        newVal) -> updatedZvrdLastCarState(enableToRunInterlockScreenModel.getErZvrdLastCarState().get());
    enableToRunInterlockScreenModel.getErZvrdLastCarState().addListener(eb15Listener);

    updatedZvrdLastCarState(enableToRunInterlockScreenModel.getErZvrdLastCarState().get());

    ChangeListener<Number> eb16Listener = (observable, oldVal,
        newVal) -> updatedEmergencyBrake(brakeSystemScreenModel.getEmergencyBrake().get());
    brakeSystemScreenModel.getEmergencyBrake().addListener(eb16Listener);

    updatedEmergencyBrake(brakeSystemScreenModel.getEmergencyBrake().get());
    
    ChangeListener<Number> eb17Listener = (observable, oldVal,
        newVal) -> updateServiceBrake(brakeSystemScreenModel.getServiceBrake().get());
    brakeSystemScreenModel.getServiceBrake().addListener(eb17Listener);

    updateServiceBrake(brakeSystemScreenModel.getServiceBrake().get());
    
    
    ChangeListener<Number> eb18Listener = (observable, oldVal,
        newVal) -> updateBrakeTl(brakeSystemScreenModel.getBrakeTlState().get());
    brakeSystemScreenModel.getBrakeTlState().addListener(eb18Listener);

    updateBrakeTl(brakeSystemScreenModel.getBrakeTlState().get());
  }

  private void updateBrakeTl(int brakeTlvalue)
  {


    if (brakeTlvalue == ERState.ACTIVE.getNumber())
    {

      enable14StateProperty.set(ERState.ACTIVE.name().toLowerCase());
    }
    else
    {
      enable14StateProperty.set(ERState.NOT_ACTIVE.name().toLowerCase());
    }

  
  
    
  }

  private void updateServiceBrake(int ebValue)
  {

    if (ebValue == ERState.ACTIVE.getNumber())
    {

      enable13StateProperty.set(ERState.ACTIVE.name().toLowerCase());
    }
    else
    {
      enable13StateProperty.set(ERState.NOT_ACTIVE.name().toLowerCase());
    }

  
  }

  private void updatedEmergencyBrake(int ebValue)
  {
    if (ebValue == ERState.ACTIVE.getNumber())
    {

      enable12StateProperty.set(ERState.ACTIVE.name().toLowerCase());
    }
    else
    {
      enable12StateProperty.set(ERState.NOT_ACTIVE.name().toLowerCase());
    }

  }

  private void updatedLastVehicleId(int vehicleId)
  {
    enableLbl5CarNo.setText(Integer.toString(vehicleId));
    // enableLbl3CarNo.setText(Integer.toString(vehicleId));
  }

  private void updatedHighVolatgeMissing(String string)
  {
    enable1StateProperty.set(string);
  }

  private void updatedCabNotEnabled(String string)
  {
    enable2StateProperty.set(string);
  }

  private void updatedDrivingMode(String string)
  {
    enable3StateProperty.set(string);
  }

  private void updatedTrainDirectionMissing(String string)
  {
    enable4StateProperty.set(string);
  }

  private void updatedAtcStatus(String string)
  {
    enable5StateProperty.set(string);
  }

  private void updatedTrainReady(String string)
  {
    enable6StateProperty.set(string);
  }

  private void updatedManyRPressure(String string)
  {
    enable7StateProperty.set(string);
  }

  private void updatedEpicCutout(String string)
  {
    enable8StateProperty.set(string);
  }

  private void updatedBogieIsolated(String string)
  {
    enable9StateProperty.set(string);
  }

  private void updatedMotoringTl(String string)
  {
    enable11StateProperty.set(string);
  }

  private void updatedBrakeLoopTl(String string)
  {
    enable15StateProperty.set(string);
  }

  private void updatedParkingBrakeTl(String string)
  {
    enable16StateProperty.set(string);
  }

  private void updatedDoorLoopOpenTl(String string)
  {
    enable17StateProperty.set(string);
  }

  private void updatedZvrdFirstCarState(String string)
  {
    enable10StateProperty.set(string);
    enableCarNo3LblStateProperty.set(string);
    enableLbl101StateProperty.set(string);
  }

  private void updatedZvrdLastCarState(String string)
  {

    enableLbl18StateProperty.set(string);
    enableCarNo5LblStateProperty.set(string);
    enableLbl181StateProperty.set(string);
  }

}
