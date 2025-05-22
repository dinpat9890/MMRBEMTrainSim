/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.APS_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.BATTERY_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.BATTERY_TESTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.BRAKE_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.BRAKE_TESTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.DOORS_LOOP_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.DOOR_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.DOOR_TESTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.EB_LOOP_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ECN_NETWORK_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ENERGY_COUNTERS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.EVENT_RECORDERS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FIRE_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.FIRE_TESTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.HVAC_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.HVAC_TESTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.HV_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.IC_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LIGHTS_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LV_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.MAINT_TESTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.MISC_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.MV_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ODOMETER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.PANTO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.PERFORMANCE_COUNTERS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.PIS_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.PIS_TESTS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.PROPULSION_SYSTEM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.REMOTE_IO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.RUN_STATISTICS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.SPEED_LIM_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.SW_VERSIONS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.SYS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.TCMS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.TCMS_STATUS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.TIMER_COUNTERS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VCB_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.WFL_SYSTEM_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.FooterSubmenuPopupEnum;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterSubmenuPopupBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.HybridModeScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.VduSelectionPopupBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterSubmenuPopupModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HybridModeScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.VduSelectionPopupModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class FooterSubmenuPopupController extends AbstractTCMSController
{

  @FXML
  private GridPane submenuMainGrid;

  @FXML
  private GridPane subsystemsGrid;

  @FXML
  private GridPane interlocksGrid;

  @FXML
  private GridPane faultsGrid;

  @FXML
  private GridPane testsGrid;

  @FXML
  private GridPane countersGrid;

  @FXML
  private GridPane tcmsSubmenuGrid;

  @FXML
  private GridPane performanceSubmenuGrid;

  @FXML
  private GridPane hybridModeLeftPanelGrid;

  @FXML
  private GridPane hybridModeRightPanelGrid;

  @FXML
  @CommsNumber(PROPULSION_SYSTEM_BUTTON)
  private Button propulsionBtn;

  @FXML
  @CommsNumber(BRAKE_SYSTEM_BUTTON)
  private Button brakeBtn;

  @FXML
  @CommsNumber(DOOR_SYSTEM_BUTTON)
  private Button doorBtn;

  @FXML
  @CommsNumber(APS_SYSTEM_BUTTON)
  private Button apsbtn;

  @FXML
  @CommsNumber(TCMS_BUTTON)
  private Button tcmsBtn;

  @FXML
  @CommsNumber(FIRE_SYSTEM_BUTTON)
  private Button fireBtn;

  @FXML
  @CommsNumber(BATTERY_SYSTEM_BUTTON)
  private Button batteryBtn;

  @FXML
  @CommsNumber(HVAC_SYSTEM_BUTTON)
  private Button hvacBtn;

  @FXML
  @CommsNumber(HV_SYSTEM_BUTTON)
  private Button hvBtn;

  @FXML
  @CommsNumber(MV_SYSTEM_BUTTON)
  private Button mvBtn;

  @FXML
  @CommsNumber(LV_SYSTEM_BUTTON)
  private Button lvBtn;

  @FXML
  @CommsNumber(WFL_SYSTEM_BUTTON)
  private Button wflBtn;

  @FXML
  @CommsNumber(LIGHTS_SYSTEM_BUTTON)
  private Button lightsBtn;

  @FXML
  @CommsNumber(PIS_SYSTEM_BUTTON)
  private Button pisBtn;

  @FXML
  @CommsNumber(IC_BUTTON)
  private Button icBtn;

  @FXML
  @CommsNumber(MISC_BUTTON)
  private Button miscBtn;

  @FXML
  @CommsNumber(EB_LOOP_BUTTON)
  private Button ebLoopIntBtn;

  @FXML
  @CommsNumber(DOORS_LOOP_BUTTON)
  private Button doorsLoopBtn;

  @FXML
  @CommsNumber(VCB_BUTTON)
  private Button vcbIntBtn;

  @FXML
  @CommsNumber(PANTO_BUTTON)
  private Button pantoIntBtn;

  @FXML
  @CommsNumber(SPEED_LIM_BUTTON)
  private Button speedLimIntBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_BUTTON)
  private Button activeFaultsBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_BUTTON)
  private Button loggedFaultsBtn;

  @FXML
  @CommsNumber(SYS_BUTTON)
  private Button sysTestsBtn;

  @FXML
  @CommsNumber(BRAKE_TESTS_BUTTON)
  private Button brakeTestsBtn;

  @FXML
  @CommsNumber(DOOR_TESTS_BUTTON)
  private Button doorTestsBtn;

  @FXML
  @CommsNumber(FIRE_TESTS_BUTTON)
  private Button fireTestsBtn;

  @FXML
  @CommsNumber(BATTERY_TESTS_BUTTON)
  private Button batteryTestsBtn;

  @FXML
  @CommsNumber(HVAC_TESTS_BUTTON)
  private Button hvacTestsBtn;

  @FXML
  @CommsNumber(PIS_TESTS_BUTTON)
  private Button pisTestsBtn;

  @FXML
  @CommsNumber(MAINT_TESTS_BUTTON)
  private Button maintBtn;

  @FXML
  @CommsNumber(TIMER_COUNTERS_BUTTON)
  private Button timerBtn;

  @FXML
  @CommsNumber(ENERGY_COUNTERS_BUTTON)
  private Button energyBtn;

  @FXML
  @CommsNumber(PERFORMANCE_COUNTERS_BUTTON)
  private Button performanceBtn;

  @FXML
  @CommsNumber(TCMS_STATUS_BUTTON)
  private Button tcmsStatusBtn;

  @FXML
  @CommsNumber(ECN_NETWORK_BUTTON)
  private Button ecnNetworkBtn;

  @FXML
  @CommsNumber(REMOTE_IO_BUTTON)
  private Button remoteIOBtn;

  @FXML
  @CommsNumber(EVENT_RECORDERS_BUTTON)
  private Button eventRecordersBtn;

  @FXML
  @CommsNumber(SW_VERSIONS_BUTTON)
  private Button swVersionsBtn;

  @FXML
  @CommsNumber(RUN_STATISTICS_BUTTON)
  private Button runStatisticsBtn;

  @FXML
  @CommsNumber(ODOMETER_BUTTON)
  private Button odometerBtn;

  @FXML
  @CommsNumber(VDUInputs.ENABLE_RUN_BUTTON)
  private Button enableRunLoopIntBtn;

  @FXML
  @CommsNumber(VDUInputs.BRAKE_LOOP_BUTTON)
  private Button brakeLoopBtn;

  @FXML
  private GridPane leftSideGrid;

  @FXML
  private GridPane rightSideGrid;

  @FXML
  private GridPane testSubmenuGrid;

  private ChangeListener<Number> hybridPanelSideListener;

  private HybridModeScreenModel hybridModeScreenModel;

  private ChangeListener<Number> footerSubmenuPopupIdListener;

  private ChangeListener<Number> vduModeListener;

  private ChangeListener<Number> cctvVduModeListener;

  private NodePseudoClassProperty propulsionBtnProperty;

  private NodePseudoClassProperty brakeBtnProperty;

  private NodePseudoClassProperty doorBtnProperty;

  private NodePseudoClassProperty apsBtnProperty;

  private NodePseudoClassProperty fdsBtnProperty;

  private NodePseudoClassProperty batteryBtnProperty;

  private NodePseudoClassProperty hvacBtnProperty;

  private NodePseudoClassProperty wflBtnProperty;
  
  private NodePseudoClassProperty pisBtnProperty;

  private NodePseudoClassProperty activeFaultsBtnProperty;

  private Map<Integer, GridPane> footerSubmenuLevelPopupGridMap = new HashMap<>();

  private Map<Integer, NodePseudoClassProperty> navigationButtonMap = new HashMap<>();

  private FooterSubmenuPopupModel footerSubmenuPopupModel;

  private VduSelectionPopupModel vduSelectionPopupModel;

  @Override
  public void detachListeners()
  {
    footerSubmenuPopupModel.getFooterSubmenuPopupId().removeListener(footerSubmenuPopupIdListener);
    vduSelectionPopupModel.getVduSelected().removeListener(vduModeListener);
    hybridModeScreenModel.getHybridPanelActiveSide().removeListener(hybridPanelSideListener);
    vduSelectionPopupModel.getCurrentCctvVduMode().removeListener(cctvVduModeListener);
  }

  @Override
  public void initializeImpl()
  {
    footerSubmenuPopupModel = new FooterSubmenuPopupModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterSubmenuPopupBinder(footerSubmenuPopupModel));

    vduSelectionPopupModel = new VduSelectionPopupModel(scenarioCarIndex);
    tcmsScreenBinders.add(new VduSelectionPopupBinder(vduSelectionPopupModel, frontend));

    hybridModeScreenModel = new HybridModeScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HybridModeScreenBinder(hybridModeScreenModel));

    hybridPanelSideListener = (observable, oldVal,
        newVal) -> updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
    hybridModeScreenModel.getHybridPanelActiveSide().addListener(hybridPanelSideListener);

    propulsionBtnProperty = new NodePseudoClassProperty(propulsionBtn);
    brakeBtnProperty = new NodePseudoClassProperty(brakeBtn);
    doorBtnProperty = new NodePseudoClassProperty(doorBtn);
    apsBtnProperty = new NodePseudoClassProperty(apsbtn);
    fdsBtnProperty = new NodePseudoClassProperty(fireBtn);
    batteryBtnProperty = new NodePseudoClassProperty(batteryBtn);
    hvacBtnProperty = new NodePseudoClassProperty(hvacBtn);
    wflBtnProperty = new NodePseudoClassProperty(wflBtn);
    pisBtnProperty = new NodePseudoClassProperty(pisBtn);
    activeFaultsBtnProperty = new NodePseudoClassProperty(activeFaultsBtn);

    initializeFooterSubmenuPopupMap();
    initializeButtonScreenStateList();

    footerSubmenuPopupIdListener = ((observable, oldVal,
        newVal) -> updateFooterSubmenuPopupActiveGrid(newVal.intValue()));
    footerSubmenuPopupModel.getFooterSubmenuPopupId().addListener(footerSubmenuPopupIdListener);

    updateFooterSubmenuPopupActiveGrid(footerSubmenuPopupModel.getFooterSubmenuPopupId().get());

    vduModeListener = ((observable, oldVal, newVal) -> updateHybridPanelActive());
    vduSelectionPopupModel.getVduSelected().addListener(vduModeListener);

    cctvVduModeListener = ((observable, oldVal, newVal) -> updateHybridPanelActive());
    vduSelectionPopupModel.getCurrentCctvVduMode().addListener(cctvVduModeListener);

    updateHybridPanelActive();
  }

  private void updatePanelActiveSide(int panelActiveVal)
  {

    hybridModeLeftPanelGrid.setVisible(panelActiveVal == TCMSUIConstants.LEFT_PANEL_ACTIVE);
    hybridModeRightPanelGrid.setVisible(panelActiveVal == TCMSUIConstants.RIGHT_PANEL_ACTIVE);
    hybridModeLeftPanelGrid.getStyleClass().clear();
    hybridModeRightPanelGrid.getStyleClass().clear();
    if (panelActiveVal == TCMSUIConstants.LEFT_PANEL_ACTIVE)
    {
      hybridModeRightPanelGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_TRANSPARANT_CSS);
      hybridModeLeftPanelGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_DEFAULT_CSS);
    }
    else if (panelActiveVal == TCMSUIConstants.RIGHT_PANEL_ACTIVE)
    {
      hybridModeRightPanelGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_DEFAULT_CSS);
      hybridModeLeftPanelGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_TRANSPARANT_CSS);
    }
    else
    {
      hybridModeRightPanelGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_TRANSPARANT_CSS);
      hybridModeLeftPanelGrid.getStyleClass().add(TCMSUIConstants.HYBRID_GRID_TRANSPARANT_CSS);
    }
  }

  private void updateHybridPanelActive()
  {
    int currentVduMode = 0;
    if (Frontend.TCMS.equals(frontend))
    {
      currentVduMode = vduSelectionPopupModel.getVduSelected().get();
    }
    else if (Frontend.CCTV.equals(frontend))
    {
      currentVduMode = vduSelectionPopupModel.getCurrentCctvVduMode().get();
    }
    if (VDUModeEnum.VDU_HYBRID_MODE.getId() == currentVduMode)
    {
      hybridModeLeftPanelGrid.setVisible(true);
      hybridModeRightPanelGrid.setVisible(true);
      updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
    }
    else
    {
      hybridModeLeftPanelGrid.setVisible(false);
      hybridModeRightPanelGrid.setVisible(false);
    }
  }

  private void initializeFooterSubmenuPopupMap()
  {
    footerSubmenuLevelPopupGridMap.put(FooterSubmenuPopupEnum.SYSTEMS_BUTTON_POPUP.getId(), subsystemsGrid);
    footerSubmenuLevelPopupGridMap.put(FooterSubmenuPopupEnum.INTERLOCKS_BUTTON_POPUP.getId(),
        interlocksGrid);
    footerSubmenuLevelPopupGridMap.put(FooterSubmenuPopupEnum.FAULTS_BUTTON_POPUP.getId(), faultsGrid);
    footerSubmenuLevelPopupGridMap.put(FooterSubmenuPopupEnum.TESTS_BUTTON_POPUP.getId(), testsGrid);
    footerSubmenuLevelPopupGridMap.put(FooterSubmenuPopupEnum.COUNTERS_BUTTON_POPUP.getId(), countersGrid);
    footerSubmenuLevelPopupGridMap.put(FooterSubmenuPopupEnum.TCMS_BUTTON_POPUP.getId(), tcmsSubmenuGrid);
    footerSubmenuLevelPopupGridMap.put(FooterSubmenuPopupEnum.PERFORMANE_BUTTON_POPUP.getId(),
        performanceSubmenuGrid);
    footerSubmenuLevelPopupGridMap.put(FooterSubmenuPopupEnum.MAINTAINCE_BUTTON_POPUP.getId(),
        testSubmenuGrid);
  }

  private void initializeButtonScreenStateList()
  {
    navigationButtonMap.put(ScreenId.PROPULSION_SYSTEM_SCREEN.getId(), propulsionBtnProperty);
    navigationButtonMap.put(ScreenId.BRAKE_SYSTEM_SCREEN.getId(), brakeBtnProperty);
    navigationButtonMap.put(ScreenId.DOOR_SYSTEM_SCREEN.getId(), doorBtnProperty);
    navigationButtonMap.put(ScreenId.APS_SYSTEM_SCREEN.getId(), apsBtnProperty);
    navigationButtonMap.put(ScreenId.FIRE_DETECTION_SYSTEM_STATUS_SCREEN.getId(), fdsBtnProperty);
    navigationButtonMap.put(ScreenId.BATTERY_SYSTEM_SCREEN.getId(), batteryBtnProperty);
    navigationButtonMap.put(ScreenId.HVAC_SYSTEM_STATUS_SCREEN.getId(), hvacBtnProperty);
    navigationButtonMap.put(ScreenId.WHEEL_FLANG_LUBRICATOR_SYSTEM_STATUS_SCREEN.getId(), wflBtnProperty);
    navigationButtonMap.put(ScreenId.ACTIVE_FAULTS_SCREEN.getId(), activeFaultsBtnProperty);
    navigationButtonMap.put(ScreenId.PIS_SYSTEM_SCREEN.getId(), pisBtnProperty);
  }

  private void updateFooterSubmenuPopupActiveGrid(Integer submenuPopupId)
  {
    // Apply selected submenu grid
    if (FooterSubmenuPopupEnum.valueOfLevel(submenuPopupId).equals(TCMSUIConstants.FOOTER_SUBMENU_LEVEL_1))
    {
      for (Map.Entry<Integer, GridPane> entry : footerSubmenuLevelPopupGridMap.entrySet())
      {
        Integer key = entry.getKey();
        if (key.equals(submenuPopupId))
        {
          footerSubmenuLevelPopupGridMap.get(key).setVisible(TCMSUIConstants.TRUE);
        }
        else
        {
          footerSubmenuLevelPopupGridMap.get(key).setVisible(TCMSUIConstants.FALSE);
        }
      }
    }
    else if (FooterSubmenuPopupEnum.valueOfLevel(submenuPopupId)
        .equals(TCMSUIConstants.FOOTER_SUBMENU_LEVEL_2))
    {
      for (Map.Entry<Integer, GridPane> entry : footerSubmenuLevelPopupGridMap.entrySet())
      {
        Integer key = entry.getKey();
        if (key.equals(submenuPopupId) && submenuPopupId == FooterSubmenuPopupEnum.TCMS_BUTTON_POPUP.getId())
        {
          subsystemsGrid.setVisible(TCMSUIConstants.TRUE);
          tcmsSubmenuGrid.setVisible(TCMSUIConstants.TRUE);
        }
        else if (key.equals(submenuPopupId)
            && submenuPopupId == FooterSubmenuPopupEnum.PERFORMANE_BUTTON_POPUP.getId())
        {
          countersGrid.setVisible(TCMSUIConstants.TRUE);
          performanceSubmenuGrid.setVisible(TCMSUIConstants.TRUE);
        }
        else if (key.equals(submenuPopupId)
            && submenuPopupId == FooterSubmenuPopupEnum.MAINTAINCE_BUTTON_POPUP.getId())
        {
          testsGrid.setVisible(TCMSUIConstants.TRUE);
          testSubmenuGrid.setVisible(TCMSUIConstants.TRUE);
        }
        else
        {
          footerSubmenuLevelPopupGridMap.get(key).setVisible(TCMSUIConstants.FALSE);
        }
      }
    }
    else
    {
      submenuMainGrid.setVisible(false);
    }
    updateCurrentScreenButtonState(submenuPopupId);
  }

  private void updateCurrentScreenButtonState(Integer screenId)
  {
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
      if (key.equals(screenId))
      {
        navigationButtonMap.get(key).set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      }
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onTCMSButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum.TCMS_BUTTON_POPUP);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onPerformanceButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum.PERFORMANE_BUTTON_POPUP);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onPropulsionSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.PROPULSION_SYSTEM_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onDoorSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.DOOR_SYSTEM_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onApsSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.APS_SYSTEM_SCREEN,
        frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onBatterySystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.BATTERY_SYSTEM_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onBrakeSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.BRAKE_SYSTEM_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onFireDetectionSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.FIRE_DETECTION_SYSTEM_STATUS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onWflSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.WHEEL_FLANG_LUBRICATOR_SYSTEM_STATUS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onHvacSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.HVAC_SYSTEM_STATUS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onLightSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.LIGHT_SYSTEM_STATUS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onActiveFaultsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.ACTIVE_FAULTS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onLoggedFaultsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.LOGGED_FAULTS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onEnergyCountersButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.ENERGY_CONSUMPTION_COUNTERS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onOdometerButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.ODOMETER_SCREEN,
        frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onHVButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.HIGH_VOLTAGE_SYSTEM_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onLVButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.LOW_VOLTAGE_SYSTEM_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onECNButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.TCMS_ECN_SCREEN,
        frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onRemoteIOButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.REMOTE_IO_SCREEN,
        frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onEventRecordersButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.EVENT_RECORDERS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onSwVesrionButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SOFTWARE_VERSION_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onSystemStatusButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_STATUS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onSystemTestButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SYSTEM_TEST_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onMVButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.MEDIUM_VOLTAGE_SYSTEM_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onBrakeSystemTestButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.BRAKE_SYSTEM_TEST_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onDoorSystemTestButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.DOOR_SYSTEM_TEST_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onFireSystemTestButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.FIRE_SYSTEM_TEST_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onBatterySystemTestButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.BATTERY_SYSTEM_TEST_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onHvacSystemTestButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.HVAC_SYSTEM_TEST_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onPisSystemTestButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.PIS_SYSTEM_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onSpeedLimitButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SPEED_LIMIT_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onPantoButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.PANTO_INTERLOCK_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onEbLoopInterlockButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.EB_INTERLOCK_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onVcbInterlockButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.VCB_INTERLOCK_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onDoorsLoopButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.DOOR_LOOP_INTERLOCKS_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onMiscButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.MISCELLANIA_SCREEN, frontend);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  void onbrakeLoopInterlockButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.BRAKE_LOOP_INTERLOCKS_SCREEN, frontend);
  }

  @FXML
  void onMainBtnAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendFooterSubmenuChangeRequest(FooterSubmenuPopupEnum.MAINTAINCE_BUTTON_POPUP);
  }

  @FXML
  void enableRunLoopIntBtnAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.ENABLERUN_INTERLOCK_SCREEN, frontend);
  }
  
  @FXML
  void onPISSystemButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
    .sendScreenChangeRequest(ScreenId.PIS_SYSTEM_SCREEN,frontend);
  }
  

}