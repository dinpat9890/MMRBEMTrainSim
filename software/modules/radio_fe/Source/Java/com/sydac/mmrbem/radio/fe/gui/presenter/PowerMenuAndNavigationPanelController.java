/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

/**
 * @author ext-naikp
 **/

package com.sydac.mmrbem.radio.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.POWER_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.EMERGENCY_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.START_MSG_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.MENU_BTN_REQUEST;
import static com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs.CONTACT_BTN_REQUEST;

import com.sydac.mmrbem.radio.common.state.ApplicationConstants;
import com.sydac.mmrbem.radio.fe.base.RadioFactory;
import com.sydac.mmrbem.radio.fe.gui.AbstractRadioController;
import com.sydac.mmrbem.radio.fe.gui.binder.PowerMenuAndNavPanelBinder;
import com.sydac.mmrbem.radio.fe.gui.model.PowerMenuAndNavPanelModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs;

import javafx.animation.RotateTransition;
import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

/**
 * Provides common infrastructure like grid pane containers and labels for Power
 * Menu and Navigation Panel
 * 
 * @author ext-naikp
 */
public class PowerMenuAndNavigationPanelController extends AbstractRadioController
{

  @FXML
  private Button contactNavigationBtn;
  
  @FXML
  private Button upButton;
  
  @FXML
  private Button downButton;

  private PowerMenuAndNavPanelModel powerMenuAndNavPanelModel;

  private ChangeListener<Number> selectedBtnIdListener;

  @Override
  public void initializeImpl()
  {
    powerMenuAndNavPanelModel = new PowerMenuAndNavPanelModel(scenarioCarIndex);
    radioScreenBinders.add(new PowerMenuAndNavPanelBinder(powerMenuAndNavPanelModel));

    selectedBtnIdListener = ((observable, oldVal, newVal) -> updateContactBtnStatus());
    powerMenuAndNavPanelModel.getContactNavBtnStatus().addListener(selectedBtnIdListener);
    
   
    updateContactBtnStatus();

  }

  private void updateContactBtnStatus()
  {
    if (ApplicationConstants.DIAGNOSTIC_BTN == powerMenuAndNavPanelModel.getContactNavBtnStatus().get())
    {
      contactNavigationBtn.setRotate(30);
    }
    
    else if (ApplicationConstants.CONTACT_BTN == powerMenuAndNavPanelModel.getContactNavBtnStatus().get())
    {
      contactNavigationBtn.setRotate(60);
    }
    else if (ApplicationConstants.CALLHISTORY_BTN == powerMenuAndNavPanelModel.getContactNavBtnStatus().get())
    {
      contactNavigationBtn.setRotate(90);
    }
    else if (ApplicationConstants.BITE_BTN == powerMenuAndNavPanelModel.getContactNavBtnStatus().get())
    {
      contactNavigationBtn.setRotate(120);
    }
    else if (ApplicationConstants.GROUP_BTN == powerMenuAndNavPanelModel.getContactNavBtnStatus().get())
    {
      contactNavigationBtn.setRotate(150);
    }
    else if (ApplicationConstants.MODES_BTN == powerMenuAndNavPanelModel.getContactNavBtnStatus().get())
    {
      contactNavigationBtn.setRotate(180);
    }
    else
    {
      contactNavigationBtn.setRotate(0);
    }

  }

  @Override
  public void detachListeners()
  {
    powerMenuAndNavPanelModel.getContactNavBtnStatus().removeListener(selectedBtnIdListener);
  }

  @FXML
  void onEmergencyBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(EMERGENCY_BTN_REQUEST);
  }

  @FXML
  void onMenuBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(MENU_BTN_REQUEST);
  }

  @FXML
  void onStartMsgBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(START_MSG_BTN_REQUEST);
  }

  @FXML
  void onContactNavigationBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(CONTACT_BTN_REQUEST);
  }

  @FXML
  void onPowerBtnClickAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(POWER_BTN_REQUEST);
  }

  @FXML
  void onDownButtonAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(RadioInputs.NAVIGATION_DOWN_ARROW_REQUEST);
  }
  
  @FXML
  void OnUpButtonAction(ActionEvent event)
  {
    RadioFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(RadioInputs.NAVIGATION_UP_ARROW_REQUEST);
  }
}
