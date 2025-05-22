/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

/**
 * @author ext-tambet
 **/
package com.sydac.mmrbem.radio.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.ALARM_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.DEPOT_GROUP_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.LOG_ON_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.MAIN_GROUP_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.MSG_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.PA_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.RTT_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.SHUNT_GROUP_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.TRAIN_GROUP_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.TR_REAR_BTN_REQUEST;

import com.sydac.mmrbem.radio.fe.base.RadioFactory;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;

/**
 * Provides common infrastructure like grid pane containers and labels for Call
 * Request And Navigation Panel
 * 
 * @author ext-tambet
 */
public class CallRequestAndNavigationPanelController extends AbstractRadioController
{

  @FXML
  void onAlarmBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(ALARM_BTN_REQUEST);
  }

  @FXML
  void onDepotBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(DEPOT_GROUP_BTN_REQUEST);
  }

  @FXML
  void onLogonBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(LOG_ON_BTN_REQUEST);
  }

  @FXML
  void onMainBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(MAIN_GROUP_BTN_REQUEST);
  }

  @FXML
  void onMsgBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(MSG_BTN_REQUEST);
  }

  @FXML
  void onPaBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(PA_BTN_REQUEST);
  }

  @FXML
  void onRttBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(RTT_BTN_REQUEST);
  }

  @FXML
  void onShuntBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(SHUNT_GROUP_BTN_REQUEST);
  }

  @FXML
  void onTrainBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(TRAIN_GROUP_BTN_REQUEST);
  }

  @FXML
  void onTrRearBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(TR_REAR_BTN_REQUEST);
  }

  @Override
  public void detachListeners()
  {

  }

  @Override
  public void initializeImpl()
  {

  }

}
