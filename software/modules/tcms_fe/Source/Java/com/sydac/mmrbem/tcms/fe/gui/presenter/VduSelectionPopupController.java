/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_CCTV_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_HYBRID_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_TCMS_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.HybridModeScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.VduSelectionPopupBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.HybridModeScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.VduSelectionPopupModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class VduSelectionPopupController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(VDU_TCMS_BUTTON)
  private Button tcmsBtn;

  @FXML
  @CommsNumber(VDU_HYBRID_BUTTON)
  private Button hybridBtn;

  @FXML
  @CommsNumber(VDU_CCTV_BUTTON)
  private Button cctvBtn;

  @FXML
  private GridPane hybridModeLeftPanelGrid;

  @FXML
  private GridPane hybridModeRightPanelGrid;

  private NodePseudoClassProperty tcmsButtonProperty;

  private NodePseudoClassProperty hybridButtonProperty;

  private NodePseudoClassProperty cctvButtonProperty;

  private ChangeListener<Number> vduModeListener;

  private ChangeListener<Number> cctvVduModeListener;

  private ChangeListener<Number> hybridPanelSideListener;

  private HybridModeScreenModel hybridModeScreenModel;

  private Map<Integer, NodePseudoClassProperty> navigationButtonMap = new HashMap<>();

  private VduSelectionPopupModel vduSelectionPopupModel;

  @Override
  public void detachListeners()
  {
    vduSelectionPopupModel.getVduSelected().removeListener(vduModeListener);
    hybridModeScreenModel.getHybridPanelActiveSide().removeListener(hybridPanelSideListener);
    vduSelectionPopupModel.getCurrentCctvVduMode().removeListener(cctvVduModeListener);
  }

  @Override
  public void initializeImpl()
  {
    vduSelectionPopupModel = new VduSelectionPopupModel(scenarioCarIndex);
    tcmsScreenBinders.add(new VduSelectionPopupBinder(vduSelectionPopupModel, frontend));

    hybridModeScreenModel = new HybridModeScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HybridModeScreenBinder(hybridModeScreenModel));

    hybridPanelSideListener = (observable, oldVal,
        newVal) -> updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
    hybridModeScreenModel.getHybridPanelActiveSide().addListener(hybridPanelSideListener);

    tcmsButtonProperty = new NodePseudoClassProperty(tcmsBtn);
    hybridButtonProperty = new NodePseudoClassProperty(hybridBtn);
    cctvButtonProperty = new NodePseudoClassProperty(cctvBtn);

    initializeButtonStateList();

    vduModeListener = ((observable, oldVal, newVal) -> updateCurrentVduButtonState());
    vduSelectionPopupModel.getVduSelected().addListener(vduModeListener);

    cctvVduModeListener = ((observable, oldVal, newVal) -> updateCurrentVduButtonState());
    vduSelectionPopupModel.getCurrentCctvVduMode().addListener(cctvVduModeListener);

    updateCurrentVduButtonState();
    updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
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

  private void updateHybridPanelVisibility(int currentVduMode)
  {
    if (VDUModeEnum.VDU_HYBRID_MODE.getId() == currentVduMode)
    {
      hybridModeLeftPanelGrid.setVisible(true);
      hybridModeRightPanelGrid.setVisible(true);
    }
    else
    {
      hybridModeLeftPanelGrid.setVisible(false);
      hybridModeRightPanelGrid.setVisible(false);
    }
  }

  private void initializeButtonStateList()
  {
    navigationButtonMap.put(VDUModeEnum.VDU_TCMS_MODE.getId(), tcmsButtonProperty);
    navigationButtonMap.put(VDUModeEnum.VDU_HYBRID_MODE.getId(), hybridButtonProperty);
    navigationButtonMap.put(VDUModeEnum.VDU_CCTV_MODE.getId(), cctvButtonProperty);

    if (frontend.equals(Frontend.TCMS))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendVDUModeChangeRequest(VDUModeEnum.VDU_TCMS_MODE, frontend);
    }
    else if (frontend.equals(Frontend.CCTV))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendVDUModeChangeRequest(VDUModeEnum.VDU_CCTV_MODE, frontend);
    }
  }

  private void updateCurrentVduButtonState()
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
    updateHybridPanelVisibility(currentVduMode);
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
      if (key == currentVduMode)
      {
        navigationButtonMap.get(key).set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      }
    }
  }

  /**
   * @param event unused 
   */
  @FXML
  void onTcmsButtonAction(ActionEvent event)
  {
    sendTCMSModeChangeReq();
  }

  private void sendTCMSModeChangeReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendVDUModeChangeRequest(VDUModeEnum.VDU_TCMS_MODE,
        frontend);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPopupChangeRequest(ScreenId.BLANK_SCREEN,
        frontend);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.OPERATING_SCREEN,
        frontend);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendActiveHybridPanelSideReq(TCMSUIConstants.NO_HYBRID_PANEL_SIDE_ACTIVE);
  }

  /**
   * @param event unused 
   */
  @FXML
  void onHybridButtonAction(ActionEvent event)
  {
    if (vduSelectionPopupModel.getVduSelected().get() == VDUModeEnum.VDU_CCTV_MODE.getId()
        || vduSelectionPopupModel.getCurrentCctvVduMode().get() == VDUModeEnum.VDU_CCTV_MODE.getId())
    {
      sendTCMSModeChangeReq();
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPopupChangeRequest(ScreenId.BLANK_SCREEN,
        frontend);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendVDUModeChangeRequest(VDUModeEnum.VDU_HYBRID_MODE, frontend);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendPopupChangeRequest(ScreenId.CCTV_HYBRID_MODE_COMMON_SCREEN, frontend);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendActiveHybridPanelSideReq(TCMSUIConstants.LEFT_PANEL_ACTIVE);
  }

  /**
   * @param event unused 
   */
  @FXML
  void onCctvButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendVDUModeChangeRequest(VDUModeEnum.VDU_TCMS_MODE,
        frontend);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendActiveHybridPanelSideReq(TCMSUIConstants.LEFT_PANEL_ACTIVE);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendVDUModeChangeRequest(VDUModeEnum.VDU_CCTV_MODE,
        frontend);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.CCTV_FOUR_FEED_SCREEN, frontend);
  }
}
