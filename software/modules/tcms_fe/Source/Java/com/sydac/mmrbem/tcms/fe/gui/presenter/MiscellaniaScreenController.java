/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.MiscellaniaScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.MiscellaniaScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.state.MiscellaniaStatus;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class MiscellaniaScreenController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(VDUInputs.LOW_SOUND_HORN_FRONT_BUTTON)
  private Button lowSoundFrontBtn;

  @FXML
  @CommsNumber(VDUInputs.LOW_SOUND_HORN_REAR_BUTTON)
  private Button lowSoundRearBtn;

  @FXML
  @CommsNumber(VDUInputs.HIGH_SOUND_HORN_FRONT_BUTTON)
  private Button highSoundFrontBtn;

  @FXML
  @CommsNumber(VDUInputs.HIGH_SOUND_HORN_REAR_BUTTON)
  private Button highSoundRearBtn;

  @FXML
  @CommsNumber(VDUInputs.HORN_ISOLATE_RESINSERT_FRONT_BUTTON)
  private Button isolateHornFrontBtn;

  @FXML
  @CommsNumber(VDUInputs.HORN_ISOLATE_RESINSERT_REAR_BUTTON)
  private Button isolateHornRearBtn;

  private ChangeListener<Number> frontHornIsolateResinsertStateListener;

  private ChangeListener<Number> rearHornIsolateResinsertStateListener;

  private NodePseudoClassProperty frontHornIsolateButtonProperty;

  private NodePseudoClassProperty rearHornIsolateButtonProperty;

  private MiscellaniaScreenModel miscellaniaScreenModel;

  @FXML
  private Label odlLbl1;

  @FXML
  private Label odlLbl2;

  private NodePseudoClassProperty odlLbl1Property;

  private NodePseudoClassProperty odlLbl2Property;

  @FXML
  private Label odrLbl1;

  @FXML
  private Label odrLbl2;

  private NodePseudoClassProperty odrLbl1Property;

  private NodePseudoClassProperty odrLbl2Property;

  @FXML
  private Label ddlLbl1;

  @FXML
  private Label ddlLbl2;

  private NodePseudoClassProperty ddlLbl1Property;

  private NodePseudoClassProperty ddlLbl2Property;

  @FXML
  private Label ddrlbl1;

  @FXML
  private Label ddrlbl2;

  private NodePseudoClassProperty ddrlbl1Property;

  private NodePseudoClassProperty ddrlbl2Property;

  private ChangeListener<Number> derelamentLeftFirstCarListener;

  private ChangeListener<Number> derelamentLeftLastCarListener;

  private ChangeListener<Number> derelamentRightFirstCarListener;

  private ChangeListener<Number> derelamentRightLastCarListener;

  private ChangeListener<Number> obstrectionLeftFirstCarListener;

  private ChangeListener<Number> obstrectionLeftLastCarListener;

  private ChangeListener<Number> obstrectionRightFirstCarListener;

  private ChangeListener<Number> obstrectionRightLastCarListener;

  @Override
  public void detachListeners()
  {
    miscellaniaScreenModel.getHornIsolateReinsertFrontStatus()
        .removeListener(frontHornIsolateResinsertStateListener);
    miscellaniaScreenModel.getHornIsolateReinsertRearStatus()
        .removeListener(rearHornIsolateResinsertStateListener);
  }

  @Override
  public void initializeImpl()
  {
    miscellaniaScreenModel = new MiscellaniaScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new MiscellaniaScreenBinder(miscellaniaScreenModel));

    frontHornIsolateButtonProperty = new NodePseudoClassProperty(isolateHornFrontBtn);
    rearHornIsolateButtonProperty = new NodePseudoClassProperty(isolateHornRearBtn);

    odlLbl1Property = new NodePseudoClassProperty(odlLbl1);
    odlLbl2Property = new NodePseudoClassProperty(odlLbl2);

    odrLbl1Property = new NodePseudoClassProperty(odrLbl1);
    odrLbl2Property = new NodePseudoClassProperty(odrLbl2);

    ddlLbl1Property = new NodePseudoClassProperty(ddlLbl1);
    ddlLbl2Property = new NodePseudoClassProperty(ddlLbl2);

    ddrlbl1Property = new NodePseudoClassProperty(ddrlbl1);
    ddrlbl2Property = new NodePseudoClassProperty(ddrlbl2);

    frontHornIsolateResinsertStateListener = (observable, oldVal,
        newVal) -> updateFrontHornIsolateButtonState();
    miscellaniaScreenModel.getHornIsolateReinsertFrontStatus()
        .addListener(frontHornIsolateResinsertStateListener);

    rearHornIsolateResinsertStateListener = (observable, oldVal,
        newVal) -> updateRearHornIsolateButtonState();
    miscellaniaScreenModel.getHornIsolateReinsertRearStatus()
        .addListener(rearHornIsolateResinsertStateListener);

    derelamentLeftFirstCarListener = (observable, oldValue,
        newValue) -> updateDerailmentLeftFirstCar((Integer)newValue);

    miscellaniaScreenModel.getFirstCarDerailmentLeft().addListener(derelamentLeftFirstCarListener);
    updateDerailmentLeftFirstCar(miscellaniaScreenModel.getFirstCarDerailmentLeft().get());

    derelamentLeftLastCarListener = (observable, oldValue,
        newValue) -> updateDerailmentLeftLastCar((Integer)newValue);

    miscellaniaScreenModel.getLastCarDerailmentLeft().addListener(derelamentLeftLastCarListener);
    updateDerailmentLeftLastCar(miscellaniaScreenModel.getLastCarDerailmentLeft().get());

    derelamentRightFirstCarListener = (observable, oldValue,
        newValue) -> updateDerailmentRightFirstCar((Integer)newValue);

    miscellaniaScreenModel.getFirstCarDerailmentRight().addListener(derelamentRightFirstCarListener);
    updateDerailmentRightFirstCar(miscellaniaScreenModel.getFirstCarDerailmentRight().get());

    derelamentRightLastCarListener = (observable, oldValue,
        newValue) -> updateDerailmentRightLastCar((Integer)newValue);

    miscellaniaScreenModel.getLastCarDerailmentRight().addListener(derelamentRightLastCarListener);
    updateDerailmentRightLastCar(miscellaniaScreenModel.getLastCarDerailmentRight().get());

    obstrectionRightFirstCarListener = (observable, oldValue,
        newValue) -> updateObstrectionRightFirstCar((Integer)newValue);

    miscellaniaScreenModel.getFirstCarObstrectionRight().addListener(obstrectionRightFirstCarListener);
    updateObstrectionRightFirstCar(miscellaniaScreenModel.getFirstCarObstrectionRight().get());

    obstrectionRightLastCarListener = (observable, oldValue,
        newValue) -> updateObstrectionRightLastCar((Integer)newValue);

    miscellaniaScreenModel.getLastCarObstrectionRight().addListener(obstrectionRightLastCarListener);
    updateObstrectionRightLastCar(miscellaniaScreenModel.getLastCarObstrectionRight().get());

    obstrectionLeftFirstCarListener = (observable, oldValue,
        newValue) -> updateObstrectionLeftFirstCar((Integer)newValue);

    miscellaniaScreenModel.getFirstCarObstrectionLeft().addListener(obstrectionLeftFirstCarListener);
    updateObstrectionLeftFirstCar(miscellaniaScreenModel.getFirstCarObstrectionLeft().get());

    obstrectionLeftLastCarListener = (observable, oldValue,
        newValue) -> updateObstrectionLeftLastCar((Integer)newValue);

    miscellaniaScreenModel.getLastCarObstrectionLeft().addListener(obstrectionLeftLastCarListener);
    updateObstrectionLeftLastCar(miscellaniaScreenModel.getLastCarObstrectionLeft().get());

  }

  private void updateDerailmentLeftFirstCar(int doorStateId)
  {

    ddlLbl1Property.set(MiscellaniaStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateDerailmentLeftLastCar(int doorStateId)
  {

    ddlLbl2Property.set(MiscellaniaStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateDerailmentRightFirstCar(int doorStateId)
  {

    ddrlbl1Property.set(MiscellaniaStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateDerailmentRightLastCar(int doorStateId)
  {

    ddrlbl2Property.set(MiscellaniaStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateObstrectionRightFirstCar(int doorStateId)
  {

    odrLbl1Property.set(MiscellaniaStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateObstrectionRightLastCar(int doorStateId)
  {

    odrLbl2Property.set(MiscellaniaStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateObstrectionLeftFirstCar(int doorStateId)
  {

    odlLbl1Property.set(MiscellaniaStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateObstrectionLeftLastCar(int doorStateId)
  {

    odlLbl2Property.set(MiscellaniaStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateFrontHornIsolateButtonState()
  {
    if (miscellaniaScreenModel.getHornIsolateReinsertFrontStatus().get() == TCMSUIConstants.HORN_ISOLATED)
    {
      frontHornIsolateButtonProperty.set(TCMSUIConstants.HORN_ISOLATED_CSS);
      isolateHornFrontBtn.setText(TCMSUIConstants.HORN_RESET_ISOLATE_LABEL);
    }
    else
    {
      frontHornIsolateButtonProperty.set(TCMSUIConstants.HORN_REINSERTED_CSS);
      isolateHornFrontBtn.setText(TCMSUIConstants.HORN_ISOLATE_LABEL);
    }
  }

  private void updateRearHornIsolateButtonState()
  {
    if (miscellaniaScreenModel.getHornIsolateReinsertRearStatus().get() == TCMSUIConstants.HORN_ISOLATED)
    {
      rearHornIsolateButtonProperty.set(TCMSUIConstants.HORN_ISOLATED_CSS);
      isolateHornRearBtn.setText(TCMSUIConstants.HORN_RESET_ISOLATE_LABEL);
    }
    else
    {
      rearHornIsolateButtonProperty.set(TCMSUIConstants.HORN_REINSERTED_CSS);
      isolateHornRearBtn.setText(TCMSUIConstants.HORN_ISOLATE_LABEL);
    }
  }

  @FXML
  public void lowSoundButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(lowSoundFrontBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendFrontLowHornSoundReq(TCMSUIConstants.PULSE_VALUE);
    }
    else if (event.getSource().equals(lowSoundRearBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRearLowHornSoundReq(TCMSUIConstants.PULSE_VALUE);
    }
  }

  @FXML
  private void highSoundButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(highSoundFrontBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendFrontHighHornSoundReq(TCMSUIConstants.PULSE_VALUE);
    }
    else if (event.getSource().equals(highSoundRearBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRearHighHornSoundReq(TCMSUIConstants.PULSE_VALUE);
    }
  }

  @FXML
  private void isolateReinsertHornBtnAction(ActionEvent event)
  {
    if (event.getSource().equals(isolateHornFrontBtn))
    {
      setFrontHornIsolateReinsertValue();
    }
    else if (event.getSource().equals(isolateHornRearBtn))
    {
      setRearHornIsolateReinsertValue();
    }
  }

  private void setFrontHornIsolateReinsertValue()
  {
    if (miscellaniaScreenModel.getHornIsolateReinsertFrontStatus().get() == TCMSUIConstants.HORN_ISOLATED)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendFrontHornIsolateReinsertReq(TCMSUIConstants.HORN_REINSERTED);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendFrontHornIsolateReinsertReq(TCMSUIConstants.HORN_ISOLATED);
    }
  }

  private void setRearHornIsolateReinsertValue()
  {
    if (miscellaniaScreenModel.getHornIsolateReinsertRearStatus().get() == TCMSUIConstants.HORN_ISOLATED)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRearHornIsolateReinsertReq(TCMSUIConstants.HORN_REINSERTED);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRearHornIsolateReinsertReq(TCMSUIConstants.HORN_ISOLATED);
    }
  }

}
