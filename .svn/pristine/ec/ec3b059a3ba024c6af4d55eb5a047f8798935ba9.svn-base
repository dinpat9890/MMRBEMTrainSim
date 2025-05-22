/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_AUDIO_20_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_AUDIO_40_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_AUDIO_60_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_AUDIO_80_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_BRIGHTNESS_100_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_BRIGHTNESS_20_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_BRIGHTNESS_40_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_BRIGHTNESS_60_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_BRIGHTNESS_80_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.VDU_BRIGHTNESS_AUTO_BUTTON;

import java.util.HashMap;
import java.util.Map;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.VDUBrightnessModeEnum;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.HybridModeScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.VduSelectionPopupBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.VduSettingsPopupBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.HybridModeScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.VduSelectionPopupModel;
import com.sydac.mmrbem.tcms.fe.gui.model.VduSettingsPopupModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class VduSettingsPopupController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(VDU_BRIGHTNESS_AUTO_BUTTON)
  private Button brightnessAutoBtn;

  @FXML
  @CommsNumber(VDU_BRIGHTNESS_20_BUTTON)
  private Button brightness20Btn;

  @FXML
  @CommsNumber(VDU_BRIGHTNESS_40_BUTTON)
  private Button brightness40Btn;

  @FXML
  @CommsNumber(VDU_BRIGHTNESS_60_BUTTON)
  private Button brightness60Btn;

  @FXML
  @CommsNumber(VDU_BRIGHTNESS_80_BUTTON)
  private Button brightness80Btn;

  @FXML
  @CommsNumber(VDU_BRIGHTNESS_100_BUTTON)
  private Button brightness100Btn;

  @FXML
  @CommsNumber(VDU_AUDIO_20_BUTTON)
  private Button audio20Btn;

  @FXML
  @CommsNumber(VDU_AUDIO_40_BUTTON)
  private Button audio40Btn;

  @FXML
  @CommsNumber(VDU_AUDIO_60_BUTTON)
  private Button audio60Btn;

  @FXML
  @CommsNumber(VDU_AUDIO_80_BUTTON)
  private Button audio80Btn;

  @FXML
  @CommsNumber(VDU_AUDIO_40_BUTTON)
  private Button audio100Btn;

  @FXML
  private GridPane hybridModeLeftPanelGrid;

  @FXML
  private GridPane hybridModeRightPanelGrid;

  private NodePseudoClassProperty brightnessAutoButtonProperty;

  private NodePseudoClassProperty brightness20ButtonProperty;

  private NodePseudoClassProperty brightness40ButtonProperty;

  private NodePseudoClassProperty brightness60ButtonProperty;

  private NodePseudoClassProperty brightness80ButtonProperty;

  private NodePseudoClassProperty brightness100ButtonProperty;

  private ChangeListener<Number> brightnessModeListener;

  private ChangeListener<Number> hybridPanelSideListener;

  private ChangeListener<Number> vduModeListener;

  private ChangeListener<Number> cctvVduModeListener;

  private HybridModeScreenModel hybridModeScreenModel;

  private Map<Integer, NodePseudoClassProperty> navigationButtonMap = new HashMap<>();

  private VduSettingsPopupModel vduSettingsPopupModel;

  private VduSelectionPopupModel vduSelectionPopupModel;

  @Override
  public void detachListeners()
  {
    vduSettingsPopupModel.getCurrentBrightnessSetting().removeListener(brightnessModeListener);
    hybridModeScreenModel.getHybridPanelActiveSide().removeListener(hybridPanelSideListener);
    vduSelectionPopupModel.getVduSelected().removeListener(vduModeListener);
    vduSelectionPopupModel.getCurrentCctvVduMode().removeListener(cctvVduModeListener);
  }

  @Override
  public void initializeImpl()
  {
    vduSettingsPopupModel = new VduSettingsPopupModel(scenarioCarIndex);
    tcmsScreenBinders.add(new VduSettingsPopupBinder(vduSettingsPopupModel, frontend));

    vduSelectionPopupModel = new VduSelectionPopupModel(scenarioCarIndex);
    tcmsScreenBinders.add(new VduSelectionPopupBinder(vduSelectionPopupModel, frontend));

    hybridModeScreenModel = new HybridModeScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HybridModeScreenBinder(hybridModeScreenModel));

    hybridPanelSideListener = (observable, oldVal,
        newVal) -> updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
    hybridModeScreenModel.getHybridPanelActiveSide().addListener(hybridPanelSideListener);

    brightnessAutoButtonProperty = new NodePseudoClassProperty(brightnessAutoBtn);
    brightness20ButtonProperty = new NodePseudoClassProperty(brightness20Btn);
    brightness40ButtonProperty = new NodePseudoClassProperty(brightness40Btn);
    brightness60ButtonProperty = new NodePseudoClassProperty(brightness60Btn);
    brightness80ButtonProperty = new NodePseudoClassProperty(brightness80Btn);
    brightness100ButtonProperty = new NodePseudoClassProperty(brightness100Btn);

    initializeButtonStateList();

    brightnessModeListener = ((observable, oldVal,
        newVal) -> updateCurrentBrightnessButtonState(newVal.intValue()));
    vduSettingsPopupModel.getCurrentBrightnessSetting().addListener(brightnessModeListener);

    vduModeListener = ((observable, oldVal, newVal) -> updateHybridPanelActive());
    vduSelectionPopupModel.getVduSelected().addListener(vduModeListener);

    cctvVduModeListener = ((observable, oldVal, newVal) -> updateHybridPanelActive());
    vduSelectionPopupModel.getCurrentCctvVduMode().addListener(cctvVduModeListener);

    updateHybridPanelActive();

    updateCurrentBrightnessButtonState(vduSettingsPopupModel.getCurrentBrightnessSetting().get());
    updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
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
    }
    else
    {
      hybridModeLeftPanelGrid.setVisible(false);
      hybridModeRightPanelGrid.setVisible(false);
    }
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

  private void initializeButtonStateList()
  {
    navigationButtonMap.put(VDUBrightnessModeEnum.BRIGHTNESS_AUTO.getId(), brightnessAutoButtonProperty);
    navigationButtonMap.put(VDUBrightnessModeEnum.BRIGHTNESS_20.getId(), brightness20ButtonProperty);
    navigationButtonMap.put(VDUBrightnessModeEnum.BRIGHTNESS_40.getId(), brightness40ButtonProperty);
    navigationButtonMap.put(VDUBrightnessModeEnum.BRIGHTNESS_60.getId(), brightness60ButtonProperty);
    navigationButtonMap.put(VDUBrightnessModeEnum.BRIGHTNESS_80.getId(), brightness80ButtonProperty);
    navigationButtonMap.put(VDUBrightnessModeEnum.BRIGHTNESS_100.getId(), brightness100ButtonProperty);

  }

  private void updateCurrentBrightnessButtonState(int currentBrightness)
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
      if (key == currentBrightness)
      {
        navigationButtonMap.get(key).set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
      }
    }
  }

  @FXML
  void onBrightness20ButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendVDUBrightnessChangeRequest(VDUBrightnessModeEnum.BRIGHTNESS_20, frontend);
  }

  @FXML
  void onBrightness40ButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendVDUBrightnessChangeRequest(VDUBrightnessModeEnum.BRIGHTNESS_40, frontend);
  }

  @FXML
  void onBrightness60ButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendVDUBrightnessChangeRequest(VDUBrightnessModeEnum.BRIGHTNESS_60, frontend);
  }

  @FXML
  void onBrightness80ButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendVDUBrightnessChangeRequest(VDUBrightnessModeEnum.BRIGHTNESS_80, frontend);
  }

  @FXML
  void onBrightness100ButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendVDUBrightnessChangeRequest(VDUBrightnessModeEnum.BRIGHTNESS_100, frontend);
  }

  @FXML
  void onBrightnessAutoButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendVDUBrightnessChangeRequest(VDUBrightnessModeEnum.BRIGHTNESS_AUTO, frontend);
  }
}
