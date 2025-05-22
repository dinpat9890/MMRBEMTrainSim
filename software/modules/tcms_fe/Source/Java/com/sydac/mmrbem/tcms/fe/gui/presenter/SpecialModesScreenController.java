/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.OperatingScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.SpecialModesScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.OperatingScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.SpecialModesScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

public class SpecialModesScreenController extends AbstractTCMSController
{

  @FXML
  private Label hteModeStatusLbl;

  @FXML
  private Label washingModeStatusLbl;

  @FXML
  private Label rescueModeStatusLbl;

  @FXML
  private Label lowSpeedCutOutStatusLbl;

  @FXML
  private Label jogModeLbl;

  @FXML
  private Label scsStatusLbl;

  @FXML
  private Label hostlerModeLbl;

  @FXML
  private Button activateHteBtn;

  @FXML
  private Button activateWashingBtn;

  @FXML
  private Button washingSpeed3Btn;

  @FXML
  private Button washingSpeed4Btn;

  @FXML
  private Button washingSpeed5Btn;

  @FXML
  private Label shuntModeLbl;

  @FXML
  private Button activateShuntingBtn;

  @FXML
  private Button activateLowSpeedBtn;

  @FXML
  private Button shuntMinSpeedDecreaseBtn;

  @FXML
  private Button shuntMinSpeedIncreaseBtn;

  @FXML
  private Button shuntMaxSpeedDrceaseBtn;

  @FXML
  private Button shuntMaxSpeedIncreaseBtn;

  @FXML
  private Button setShuntSpeedBtn;

  @FXML
  private Button setAtpSpeedBtn;

  @FXML
  private Label shuntMinSpeedLbl;

  @FXML
  private Label shuntMaxSpeedLbl;

  @FXML
  private Label atpMaxSpeedLbl;

  private ChangeListener<String> rescueModeListener;

  private ChangeListener<String> jogModeListener;

  private ChangeListener<String> atcBypassListener;

  private ChangeListener<Number> hteStatusListener;

  private ChangeListener<Number> shuntMinSpeedListener;

  private ChangeListener<Number> shuntMaxSpeedListener;

  private ChangeListener<Number> atpMaxSpeedListener;

  private ChangeListener<Number> washingModeStatusListener;

  private ChangeListener<Number> shuntModeStatusListener;

  private ChangeListener<Number> atpLowModeStatusListener;

  private ChangeListener<Number> shuntModeSetButtonStatusListener;

  private ChangeListener<Number> atpSetButtonStatusListener;

  private NodePseudoClassProperty hteStatusProperty;

  private NodePseudoClassProperty activateHteBtnPseudoClassProperty;

  private NodePseudoClassProperty washingModeStatusProperty;

  private NodePseudoClassProperty shuntModeStatusProperty;

  private NodePseudoClassProperty shuntModeLabelProperty;

  private NodePseudoClassProperty shuntSpeedButtonLabelProperty;

  private NodePseudoClassProperty lowSpeedATPLabelProperty;

  private NodePseudoClassProperty atpModeStatusProperty;

  private NodePseudoClassProperty atpSetButtonStatusProperty;

  private NodePseudoClassProperty activateWashingBtnPseudoClassProperty;

  private NodePseudoClassProperty rescueModeProperty;

  private NodePseudoClassProperty jogModeProperty;

  private NodePseudoClassProperty atcBypassProperty;

  private NodePseudoClassProperty washingSpeed3Property;

  private NodePseudoClassProperty washingSpeed4Property;

  private NodePseudoClassProperty washingSpeed5Property;

  private OperatingScreenModel operatingScreenModel;

  private SpecialModesScreenModel specialModesScreenModel;

  private static final Integer INACTIVE_VALUE = 0;

  private static final Integer ACTIVE_VALUE = 1;

  private static final Integer HTE_INACTIVE_VALUE = 0;

  private static final Integer HTE_REQUIRED_VALUE = 1;

  private static final Integer HTE_ACTIVATED_VALUE = 2;

  private static int shuntModeStatus = 0;

  private static int atpModeStatus = 0;

  private static int washModeStatus = 0;

  @Override
  public void initializeImpl()
  {
    operatingScreenModel = new OperatingScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new OperatingScreenBinder(operatingScreenModel));

    specialModesScreenModel = new SpecialModesScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new SpecialModesScreenBinder(specialModesScreenModel));

    hteStatusProperty = new NodePseudoClassProperty(hteModeStatusLbl);
    washingModeStatusProperty = new NodePseudoClassProperty(washingModeStatusLbl);
    rescueModeProperty = new NodePseudoClassProperty(rescueModeStatusLbl);
    jogModeProperty = new NodePseudoClassProperty(jogModeLbl);
    atcBypassProperty = new NodePseudoClassProperty(scsStatusLbl);
    washingSpeed3Property = new NodePseudoClassProperty(washingSpeed3Btn);
    washingSpeed4Property = new NodePseudoClassProperty(washingSpeed4Btn);
    washingSpeed5Property = new NodePseudoClassProperty(washingSpeed5Btn);
    shuntModeStatusProperty = new NodePseudoClassProperty(activateShuntingBtn);
    atpModeStatusProperty = new NodePseudoClassProperty(activateLowSpeedBtn);
    shuntModeLabelProperty = new NodePseudoClassProperty(shuntModeLbl);
    lowSpeedATPLabelProperty = new NodePseudoClassProperty(lowSpeedCutOutStatusLbl);
    shuntSpeedButtonLabelProperty = new NodePseudoClassProperty(setShuntSpeedBtn);
    atpSetButtonStatusProperty = new NodePseudoClassProperty(setAtpSpeedBtn);

    activateHteBtnPseudoClassProperty = new NodePseudoClassProperty(activateHteBtn);
    activateWashingBtnPseudoClassProperty = new NodePseudoClassProperty(activateWashingBtn);

    hteStatusListener = (observable, oldVal,
        newVal) -> updateHteStatus(specialModesScreenModel.getHteStatusProperty().get());
    specialModesScreenModel.getHteStatusProperty().addListener(hteStatusListener);

    washingModeStatusListener = (observable, oldVal,
        newVal) -> updateWashingModeStatus(specialModesScreenModel.getWashingStatusProperty().get());
    specialModesScreenModel.getWashingStatusProperty().addListener(washingModeStatusListener);

    rescueModeListener = (observable, oldVal,
        newVal) -> updateRescueModeStatus(operatingScreenModel.getRescueMode().get());
    operatingScreenModel.getRescueMode().addListener(rescueModeListener);

    jogModeListener = (observable, oldVal,
        newVal) -> updateJogModeStatus(operatingScreenModel.getJogMode().get());
    operatingScreenModel.getJogMode().addListener(jogModeListener);

    atcBypassListener = (observable, oldVal,
        newVal) -> updateAtcBypassStatus(operatingScreenModel.getAtcBypass().get());
    operatingScreenModel.getAtcBypass().addListener(atcBypassListener);

    shuntMinSpeedListener = (observable, oldVal,
        newVal) -> updateShuntMinSpeed(specialModesScreenModel.getShuntMinSpeedProperty().get());
    specialModesScreenModel.getShuntMinSpeedProperty().addListener(shuntMinSpeedListener);

    shuntMaxSpeedListener = (observable, oldVal,
        newVal) -> updateShuntMaxSpeed(specialModesScreenModel.getShuntMaxSpeedProperty().get());
    specialModesScreenModel.getShuntMaxSpeedProperty().addListener(shuntMaxSpeedListener);

    atpMaxSpeedListener = (observable, oldVal,
        newVal) -> updateAtpMaxSpeed(specialModesScreenModel.getAtpMaxSpeedProperty().get());
    specialModesScreenModel.getAtpMaxSpeedProperty().addListener(atpMaxSpeedListener);

    shuntModeStatusListener = (observable, oldVal,
        newVal) -> updateShuntModeStatus(specialModesScreenModel.getShuntModeStatusProperty().get());
    specialModesScreenModel.getShuntModeStatusProperty().addListener(shuntModeStatusListener);

    atpLowModeStatusListener = (observable, oldVal,
        newVal) -> updateAtpLowModeStatus(specialModesScreenModel.getAtpLowSpeedStatusProperty().get());
    specialModesScreenModel.getAtpLowSpeedStatusProperty().addListener(atpLowModeStatusListener);

    shuntModeSetButtonStatusListener = (observable, oldVal,
        newVal) -> updateShuntModeSetButton(specialModesScreenModel.getShuntModeButtonStatusProperty().get());
    specialModesScreenModel.getShuntModeButtonStatusProperty().addListener(shuntModeSetButtonStatusListener);

    atpSetButtonStatusListener = (observable, oldVal,
        newVal) -> updateAtpSetButton(specialModesScreenModel.getAtpModeSetButtonStatusProperty().get());
    specialModesScreenModel.getAtpModeSetButtonStatusProperty().addListener(atpSetButtonStatusListener);

    updateSelectedWashingModeSpeed(TCMSUIConstants.WASHING_SPEED_3);
    updateHteStatus(specialModesScreenModel.getHteStatusProperty().get());
    updateWashingModeStatus(specialModesScreenModel.getWashingStatusProperty().get());

    updateShuntMinSpeed(specialModesScreenModel.getShuntMinSpeedProperty().get());
    updateShuntMaxSpeed(specialModesScreenModel.getShuntMaxSpeedProperty().get());
    updateAtpMaxSpeed(specialModesScreenModel.getAtpMaxSpeedProperty().get());
    updateShuntModeSetButton(specialModesScreenModel.getShuntModeButtonStatusProperty().get());
    updateAtpSetButton(specialModesScreenModel.getAtpModeSetButtonStatusProperty().get());
    updateAtpLowModeStatus(specialModesScreenModel.getAtpLowSpeedStatusProperty().get());
    updateShuntModeStatus(specialModesScreenModel.getShuntModeStatusProperty().get());
  }

  private void updateAtpSetButton(int buttonStatus)
  {
    if (buttonStatus == INACTIVE_VALUE)
    {
      atpSetButtonStatusProperty.set(TCMSUIConstants.BUTTON_AVAILABLE_CSS);
    }
    else if (buttonStatus == ACTIVE_VALUE)
    {
      atpSetButtonStatusProperty.set(TCMSUIConstants.BUTTON_ACTIVATED_CSS);
    }
  }

  private void updateShuntModeSetButton(int buttonStatus)
  {
    if (buttonStatus == INACTIVE_VALUE)
    {
      shuntSpeedButtonLabelProperty.set(TCMSUIConstants.BUTTON_AVAILABLE_CSS);
    }
    else if (buttonStatus == ACTIVE_VALUE)
    {
      shuntSpeedButtonLabelProperty.set(TCMSUIConstants.BUTTON_ACTIVATED_CSS);
    }
  }

  private void updateAtpLowModeStatus(int atpStatus)
  {
    atpModeStatus = atpStatus;
    if (atpStatus == INACTIVE_VALUE)
    {
      atpModeStatusProperty.set(TCMSUIConstants.BUTTON_AVAILABLE_CSS);
      lowSpeedATPLabelProperty.set(TCMSUIConstants.STATUS_INACTIVE_CSS);
    }
    else if (atpStatus == ACTIVE_VALUE)
    {
      atpModeStatusProperty.set(TCMSUIConstants.BUTTON_ACTIVATED_CSS);
      lowSpeedATPLabelProperty.set(TCMSUIConstants.STATUS_ACTIVE_CSS);
    }
  }

  private void updateShuntModeStatus(int shuntStatus)
  {
    shuntModeStatus = shuntStatus;
    if (shuntStatus == INACTIVE_VALUE)
    {
      shuntModeStatusProperty.set(TCMSUIConstants.BUTTON_AVAILABLE_CSS);
      shuntModeLabelProperty.set(TCMSUIConstants.STATUS_INACTIVE_CSS);
    }
    else if (shuntStatus == ACTIVE_VALUE)
    {
      shuntModeStatusProperty.set(TCMSUIConstants.BUTTON_ACTIVATED_CSS);
      shuntModeLabelProperty.set(TCMSUIConstants.STATUS_ACTIVE_CSS);
    }
  }

  private void updateShuntMinSpeed(int speed)
  {
    if (speed > 0)
    {
      shuntMinSpeedLbl.setText(Integer.toString(speed));
    }
    else
    {
      shuntMinSpeedLbl.setText(Integer.toString(TCMSConstants.SHUNTING_MIN_SPEED_MAXLEVEL));
    }
  }

  private void updateShuntMaxSpeed(int shuntMaxSpeed)
  {
    if (shuntMaxSpeed > 0)
    {
      shuntMaxSpeedLbl.setText(Integer.toString(shuntMaxSpeed));
    }
    else
    {
      shuntMaxSpeedLbl.setText(Integer.toString(TCMSConstants.SHUNTING_MAX_SPEED));
    }
  }

  private void updateAtpMaxSpeed(int atpMaxSpeed)
  {
    if (atpMaxSpeed > 0)
    {

      atpMaxSpeedLbl.setText(Integer.toString(atpMaxSpeed));
    }
    else
    {
      atpMaxSpeedLbl.setText(Integer.toString(TCMSConstants.ATP_MAX_SPEED));
    }
  }

  private void updateHteStatus(int status)
  {
    if (status == HTE_INACTIVE_VALUE)
    {
      hteStatusProperty.set(TCMSUIConstants.STATUS_INACTIVE_CSS);
      activateHteBtnPseudoClassProperty.set(TCMSUIConstants.BUTTON_UNAVAILABLE_CSS);
    }
    else if (status == HTE_REQUIRED_VALUE)
    {
      hteStatusProperty.set(TCMSUIConstants.STATUS_INACTIVE_CSS);
      activateHteBtnPseudoClassProperty.set(TCMSUIConstants.BUTTON_AVAILABLE_CSS);
    }
    else if (status == HTE_ACTIVATED_VALUE)
    {
      hteStatusProperty.set(TCMSUIConstants.STATUS_ACTIVE_CSS);
      activateHteBtnPseudoClassProperty.set(TCMSUIConstants.BUTTON_ACTIVATED_CSS);
    }
  }

  private void updateWashingModeStatus(int status)
  {
    washModeStatus = status;
    if (status == INACTIVE_VALUE)
    {
      washingModeStatusProperty.set(TCMSUIConstants.STATUS_INACTIVE_CSS);
      activateWashingBtnPseudoClassProperty.set(TCMSUIConstants.BUTTON_AVAILABLE_CSS);
    }
    else if (status == ACTIVE_VALUE)
    {
      washingModeStatusProperty.set(TCMSUIConstants.STATUS_ACTIVE_CSS);
      activateWashingBtnPseudoClassProperty.set(TCMSUIConstants.BUTTON_ACTIVATED_CSS);
    }
  }

  private void updateAtcBypassStatus(String cssClass)
  {
    atcBypassProperty.set(cssClass);
  }

  private void updateJogModeStatus(String cssClass)
  {
    jogModeProperty.set(cssClass);
  }

  private void updateRescueModeStatus(String cssClass)
  {
    rescueModeProperty.set(cssClass);
  }

  @Override
  public void detachListeners()
  {
    operatingScreenModel.getRescueMode().removeListener(rescueModeListener);
    operatingScreenModel.getJogMode().removeListener(jogModeListener);
    operatingScreenModel.getAtcBypass().removeListener(atcBypassListener);
    specialModesScreenModel.getHteStatusProperty().removeListener(hteStatusListener);
    specialModesScreenModel.getWashingStatusProperty().removeListener(washingModeStatusListener);

    specialModesScreenModel.getAtpMaxSpeedProperty().removeListener(atpMaxSpeedListener);
    specialModesScreenModel.getShuntMaxSpeedProperty().removeListener(shuntMaxSpeedListener);
    specialModesScreenModel.getShuntMinSpeedProperty().removeListener(shuntMinSpeedListener);
  }

  @FXML
  private void onWashingSpeedButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(washingSpeed3Btn))
    {
      updateSelectedWashingModeSpeed(TCMSUIConstants.WASHING_SPEED_3);
    }
    else if (event.getSource().equals(washingSpeed4Btn))
    {
      updateSelectedWashingModeSpeed(TCMSUIConstants.WASHING_SPEED_4);
    }
    else if (event.getSource().equals(washingSpeed5Btn))
    {
      updateSelectedWashingModeSpeed(TCMSUIConstants.WASHING_SPEED_5);
    }
  }

  @SuppressWarnings("unused")
  @FXML
  private void onActivateHteButtonAction(ActionEvent event)
  {
    if (specialModesScreenModel.getHteStatusProperty().get() == HTE_REQUIRED_VALUE)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendSpecialModesActivateReq(VDUInputs.ACTIVATE_HTE_REQ, HTE_REQUIRED_VALUE);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendSpecialModesActivateReq(VDUInputs.ACTIVATE_HTE_REQ, HTE_INACTIVE_VALUE);
    }
  }

  private void updateSelectedWashingModeSpeed(int selectedSpeed)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSpecialModesActivateReq(VDUInputs.ACTIVATE_WASHING_REQ, INACTIVE_VALUE);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendSpecialModesActivateReq(VDUInputs.SELECTED_WASHING_MODE_SPEED, selectedSpeed);

    if (selectedSpeed == TCMSUIConstants.WASHING_SPEED_3)
    {
      washingSpeed3Property.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      washingSpeed4Property.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
      washingSpeed5Property.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else if (selectedSpeed == TCMSUIConstants.WASHING_SPEED_4)
    {
      washingSpeed3Property.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
      washingSpeed4Property.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      washingSpeed5Property.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else if (selectedSpeed == TCMSUIConstants.WASHING_SPEED_5)
    {
      washingSpeed3Property.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
      washingSpeed4Property.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
      washingSpeed5Property.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
  }

  @FXML
  private void onActivateWashingButtonAction(ActionEvent event)
  {
    if (specialModesScreenModel.getWashingStatusProperty().get() == INACTIVE_VALUE && shuntModeStatus == 0
        && atpModeStatus == 0)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendSpecialModesActivateReq(VDUInputs.ACTIVATE_WASHING_REQ, ACTIVE_VALUE);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendSpecialModesActivateReq(VDUInputs.ACTIVATE_WASHING_REQ, INACTIVE_VALUE);
    }
  }

  @FXML
  private void onActivateAtpLowButtonAction(ActionEvent event)
  {
    if (specialModesScreenModel.getAtpLowSpeedStatusProperty().get() == INACTIVE_VALUE && shuntModeStatus == 0
        && washModeStatus == 0)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendSpecialModesActivateReq(VDUInputs.SPECIAL_MODE_ACTIVATE_ATP_LOW_BUTTON_REQUEST, ACTIVE_VALUE);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendSpecialModesActivateReq(
          VDUInputs.SPECIAL_MODE_ACTIVATE_ATP_LOW_BUTTON_REQUEST, INACTIVE_VALUE);
    }
  }

  @FXML
  private void onActivateShuntingButtonAction(ActionEvent event)
  {
    if (specialModesScreenModel.getShuntModeStatusProperty().get() == INACTIVE_VALUE && atpModeStatus == 0
        && washModeStatus == 0)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendSpecialModesActivateReq(VDUInputs.SPECIAL_MODE_ACTIVATE_SHUNTING_BUTTON_REQUEST, ACTIVE_VALUE);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendSpecialModesActivateReq(
          VDUInputs.SPECIAL_MODE_ACTIVATE_SHUNTING_BUTTON_REQUEST, INACTIVE_VALUE);
    }
  }

  @FXML
  private void onShuntMinSpeedDrceaseButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.SPECIAL_MODE_SHUNT_MIN_SPEED_DECREASE_REQUEST);
  }

  @FXML
  private void onShuntMinSpeedIncreaseButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.SPECIAL_MODE_SHUNT_MIN_SPEED_INCREASE_REQUEST);
  }

  @FXML
  private void onShuntMaxSpeedDrceaseButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.SPECIAL_MODE_SHUNT_MAX_SPEED_DECREASE_REQUEST);
  }

  @FXML
  private void onShuntMaxSpeedIncreaseButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.SPECIAL_MODE_SHUNT_MAX_SPEED_INCREASE_REQUEST);
  }

  @FXML
  private void onSetShuntButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.SPECIAL_MODE_SHUNT_SET_BUTTON_REQUEST);

  }

  @FXML
  private void onAtpMaxSpeedDrceaseButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.SPECIAL_MODE_ATP_MAX_SPEED_DECREASE_REQUEST);
  }

  @FXML
  private void onAtpMaxSpeedIncreaseButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.SPECIAL_MODE_ATP_MAX_SPEED_INCREASE_REQUEST);

  }

  @FXML
  private void onSetAtpButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.SPECIAL_MODE_ATP_SET_BUTTON_REQUEST);

  }
}