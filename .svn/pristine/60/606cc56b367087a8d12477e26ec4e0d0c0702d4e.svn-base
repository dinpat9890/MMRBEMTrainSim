/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_BACK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_COUNTERS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_FAULTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_HELP_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_INTERLOCKS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_OPERATING_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_ROUTE_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_SYSTEMS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FOOTER_TESTS_BUTTON;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.BackNavigationScreenEnum;
import com.sydac.mmrbem.tcms.common.state.FooterSubmenuPopupEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

public class FooterPanelController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(FOOTER_OPERATING_BUTTON)
  private Button operatingBtn;

  @FXML
  @CommsNumber(FOOTER_SYSTEMS_BUTTON)
  private Button systemsBtn;

  @FXML
  @CommsNumber(FOOTER_INTERLOCKS_BUTTON)
  private Button interlocksBtn;

  @FXML
  @CommsNumber(FOOTER_ROUTE_BUTTON)
  private Button routeBtn;

  @FXML
  @CommsNumber(FOOTER_FAULTS_BUTTON)
  private Button faultsBtn;

  @FXML
  @CommsNumber(FOOTER_TESTS_BUTTON)
  private Button testsBtn;

  @FXML
  @CommsNumber(FOOTER_COUNTERS_BUTTON)
  private Button countersBtn;

  @FXML
  @CommsNumber(FOOTER_HELP_BUTTON)
  private Button helpBtn;

  @FXML
  @CommsNumber(FOOTER_BACK_BUTTON)
  private Button backBtn;

  private NodePseudoClassProperty operatingBtnProperty;

  private NodePseudoClassProperty systemsBtnProperty;

  private NodePseudoClassProperty interlocksBtnProperty;

  private NodePseudoClassProperty routeBtnProperty;

  private NodePseudoClassProperty faultsBtnProperty;

  private NodePseudoClassProperty testsBtnProperty;

  private NodePseudoClassProperty countersBtnProperty;

  private NodePseudoClassProperty helpBtnProperty;

  private ChangeListener<Number> screenIdListener;

  private ChangeListener<Number> noOfFaultsListener;

  private ChangeListener<Number> faultsPriorityListener;

  /**
   * This map contain button PseudoClass against its screen Id
   */
  private Map<Integer, NodePseudoClassProperty> navigationButtonMap = new HashMap<>();

  private Map<Integer, ScreenId> helpScreenMap = new HashMap<>();

  private FooterPanelModel footerPanelModel;

  @Override
  public void initializeImpl()
  {
    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    operatingBtnProperty = new NodePseudoClassProperty(operatingBtn);
    systemsBtnProperty = new NodePseudoClassProperty(systemsBtn);
    interlocksBtnProperty = new NodePseudoClassProperty(interlocksBtn);
    routeBtnProperty = new NodePseudoClassProperty(routeBtn);
    faultsBtnProperty = new NodePseudoClassProperty(faultsBtn);
    testsBtnProperty = new NodePseudoClassProperty(testsBtn);
    countersBtnProperty = new NodePseudoClassProperty(countersBtn);
    helpBtnProperty = new NodePseudoClassProperty(helpBtn);

    initializeButtonScreenStateList();
    initializeHelpScreenMap();

    screenIdListener = ((observable, oldVal, newVal) -> updateCurrentScreenButtonState(newVal.intValue()));
    footerPanelModel.getCurrentScreenId().addListener(screenIdListener);

    noOfFaultsListener = (observable, oldVal, newVal) -> updateFaultsCount((Integer)newVal);
    footerPanelModel.getNoOfFaults().addListener(noOfFaultsListener);

    faultsPriorityListener = (observable, oldVal, newVal) -> updateFaultsPriority((Integer)newVal);
    footerPanelModel.getFaultPriorityState().addListener(faultsPriorityListener);

    updateCurrentScreenButtonState(footerPanelModel.getCurrentScreenId().get());
    updateFaultsCount(footerPanelModel.getNoOfFaults().get());
    updateFaultsPriority(footerPanelModel.getFaultPriorityState().get());
  }

  private void updateFaultsPriority(Integer faultsPriority)
  {
    if (faultsPriority == 1)
    {
      faultsBtnProperty.set(TCMSUIConstants.FAULTS_PRIORITY_1_PSEUDO_CLASS);
    }
    else if (faultsPriority == 2)
    {
      faultsBtnProperty.set(TCMSUIConstants.FAULTS_PRIORITY_2_PSEUDO_CLASS);
    }
    else
    {
      faultsBtnProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
  }

  private void updateFaultsCount(Integer noOfFaults)
  {
    if (noOfFaults > 0)
    {
      faultsBtn.setText("FAULTS(" + noOfFaults + ")"); //$NON-NLS-1$ //$NON-NLS-2$
    }
    else
    {
      faultsBtn.setText("FAULTS"); //$NON-NLS-1$
    }
  }

  @Override
  public void detachListeners()
  {
    footerPanelModel.getCurrentScreenId().removeListener(screenIdListener);
    footerPanelModel.getNoOfFaults().removeListener(noOfFaultsListener);
    footerPanelModel.getFaultPriorityState().removeListener(faultsPriorityListener);
  }

  private void initializeButtonScreenStateList()
  {
    navigationButtonMap.put(ScreenId.OPERATING_SCREEN.getId(), operatingBtnProperty);
    navigationButtonMap.put(ScreenId.FOOTER_SUBMENU_POPUP.getId(), systemsBtnProperty);
    navigationButtonMap.put(ScreenId.FOOTER_SUBMENU_POPUP.getId(), interlocksBtnProperty);
    navigationButtonMap.put(ScreenId.ROUTE_SCREEN.getId(), routeBtnProperty);
    navigationButtonMap.put(ScreenId.FOOTER_SUBMENU_POPUP.getId(), faultsBtnProperty);
    navigationButtonMap.put(ScreenId.FOOTER_SUBMENU_POPUP.getId(), testsBtnProperty);
    navigationButtonMap.put(ScreenId.FOOTER_SUBMENU_POPUP.getId(), countersBtnProperty);
    navigationButtonMap.put(ScreenId.OPERATING_HELP_SCREEN.getId(), operatingBtnProperty);
  }

  private void initializeHelpScreenMap()
  {
    helpScreenMap.put(ScreenId.OPERATING_SCREEN.getId(), ScreenId.OPERATING_HELP_SCREEN);
  }

  private void updateCurrentScreenButtonState(Integer screenId)
  {
    updateHelpScreenButton(screenId);
    // Un-select all button first
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : navigationButtonMap.entrySet())
    {
      Integer key = entry.getKey();
      navigationButtonMap.get(key).set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }

    // Apply selected pseudo class to select button
    for (Map.Entry<Integer, NodePseudoClassProperty> entry : navigationButtonMap.entrySet())
    {
      Integer key = entry.getKey();
      if (Objects.equals(key, screenId) && entry.getValue() != faultsBtnProperty)
      {
        navigationButtonMap.get(key).set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      }
    }
  }

  private void updateHelpScreenButton(Integer screenId)
  {
    if (helpScreenMap.containsKey(screenId))
    {
      helpBtn.setText(TCMSUIConstants.HELP_BUTTON);
    }
    else
    {
      helpBtn.setText(TCMSUIConstants.BLANK_STRING);
    }
  }

  @FXML
  void onOperatingButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.OPERATING_SCREEN,
        frontend);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPopupChangeRequest(ScreenId.BLANK_SCREEN,
        frontend);
  }

  @FXML
  void onSystemsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendPopupChangeRequest(ScreenId.FOOTER_SUBMENU_POPUP, frontend);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum.SYSTEMS_BUTTON_POPUP);
  }

  @FXML
  void onInterlocksButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendPopupChangeRequest(ScreenId.FOOTER_SUBMENU_POPUP, frontend);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum.INTERLOCKS_BUTTON_POPUP);
  }

  @FXML
  void onRouteButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.ROUTE_SCREEN,
        frontend);
  }

  @FXML
  void onFaultsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendPopupChangeRequest(ScreenId.FOOTER_SUBMENU_POPUP, frontend);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum.FAULTS_BUTTON_POPUP);
  }

  @FXML
  void onTestsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendPopupChangeRequest(ScreenId.FOOTER_SUBMENU_POPUP, frontend);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum.TESTS_BUTTON_POPUP);
  }

  @FXML
  void onCountersButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendPopupChangeRequest(ScreenId.FOOTER_SUBMENU_POPUP, frontend);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum.COUNTERS_BUTTON_POPUP);
  }

  @FXML
  void onHelpButtonAction(ActionEvent event)
  {
    if (helpScreenMap.containsKey(footerPanelModel.getCurrentScreenId().get()))
    {
      ScreenId screenId = helpScreenMap.get(footerPanelModel.getCurrentScreenId().get());
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(screenId, frontend);
    }
  }

  @FXML
  void onBackButtonAction(ActionEvent event)
  {
    int popupScreenId = footerPanelModel.getCurrentPopupId().get();
    if (popupScreenId > ScreenId.BLANK_SCREEN.getId()
        && popupScreenId != ScreenId.CCTV_HYBRID_MODE_COMMON_SCREEN.getId())
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPopupChangeRequest(ScreenId.BLANK_SCREEN,
          frontend);
    }
    else
    {
      ScreenId screenId = ScreenId
          .valueOf(BackNavigationScreenEnum.backToScreenId(footerPanelModel.getCurrentScreenId().get()));
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(screenId, frontend);
    }
  }
}
