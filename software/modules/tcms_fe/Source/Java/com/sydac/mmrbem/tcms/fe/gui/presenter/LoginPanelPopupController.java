/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_0_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_1_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_2_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_3_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_4_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_5_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_6_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_7_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_8_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_9_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_CLEAR_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_DELETE_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.KEYPAD_ENTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGOUT_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.MAINTAINER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.OPERATOR_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.SETTING_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.KeyPadEnum;
import com.sydac.mmrbem.tcms.common.state.VDUModeEnum;
import com.sydac.mmrbem.tcms.fe.base.ServiceRequestHandler;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.HybridModeScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.LoginPanelPopupBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.VduSelectionPopupBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.HybridModeScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.LoginPanelPopupModel;
import com.sydac.mmrbem.tcms.fe.gui.model.VduSelectionPopupModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class LoginPanelPopupController extends AbstractTCMSController
{
  @FXML
  @CommsNumber(OPERATOR_BUTTON)
  private Button profileBtn;

  @FXML
  @CommsNumber(MAINTAINER_BUTTON)
  private Button maintainerBtn;

  @FXML
  @CommsNumber(SETTING_BUTTON)
  private Button settingBtn;

  @FXML
  @CommsNumber(LOGOUT_BUTTON)
  private Button logoutBtn;

  @FXML
  @CommsNumber(KEYPAD_2_BUTTON)
  private Button keyPadNum2;

  @FXML
  @CommsNumber(KEYPAD_3_BUTTON)
  private Button keyPadNum3;

  @FXML
  @CommsNumber(KEYPAD_5_BUTTON)
  private Button keyPadNum5;

  @FXML
  @CommsNumber(KEYPAD_4_BUTTON)
  private Button keyPadNum4;

  @FXML
  @CommsNumber(KEYPAD_9_BUTTON)
  private Button keyPadNum9;

  @FXML
  @CommsNumber(KEYPAD_6_BUTTON)
  private Button keyPadNum6;

  @FXML
  @CommsNumber(KEYPAD_7_BUTTON)
  private Button keyPadNum7;

  @FXML
  @CommsNumber(KEYPAD_8_BUTTON)
  private Button keyPadNum8;

  @FXML
  @CommsNumber(KEYPAD_1_BUTTON)
  private Button keyPadNum1;

  @FXML
  @CommsNumber(KEYPAD_0_BUTTON)
  private Button keyPadNum0;

  @FXML
  @CommsNumber(KEYPAD_CLEAR_BUTTON)
  private Button keyPadClear;

  @FXML
  @CommsNumber(KEYPAD_ENTER_BUTTON)
  private Button keyPadEnter;

  @FXML
  @CommsNumber(KEYPAD_DELETE_BUTTON)
  private Button keyPadDelete;

  @FXML
  private GridPane keypadGrid;

  @FXML
  private GridPane beforeLoginGrid;

  @FXML
  private GridPane afterLoginGrid;

  @FXML
  private GridPane hybridModeLeftPanelGrid;

  @FXML
  private GridPane hybridModeRightPanelGrid;

  @FXML
  private Label userLoginLbl;

  @FXML
  private Label userIdLbl;

  private ChangeListener<Boolean> operatorButtonListener;

  private ChangeListener<Boolean> loginListener;

  private NodePseudoClassProperty operatorButtonProperty;

  private ChangeListener<Number> hybridPanelSideListener;

  private ChangeListener<Number> vduModeListener;

  private ChangeListener<Number> cctvVduModeListener;

  private HybridModeScreenModel hybridModeScreenModel;

  private LoginPanelPopupModel loginPanelPopupModel;

  private VduSelectionPopupModel vduSelectionPopupModel;

  private ServiceRequestHandler serviceRequestHandler;

  @Override
  public void detachListeners()
  {
    loginPanelPopupModel.getKeypadPanelVisible().removeListener(operatorButtonListener);
    hybridModeScreenModel.getHybridPanelActiveSide().removeListener(hybridPanelSideListener);
    vduSelectionPopupModel.getVduSelected().removeListener(vduModeListener);
    loginPanelPopupModel.getLogoutPanelVisible().removeListener(loginListener);
    vduSelectionPopupModel.getCurrentCctvVduMode().removeListener(cctvVduModeListener);
  }

  @Override
  public void initializeImpl()
  {
    loginPanelPopupModel = new LoginPanelPopupModel(scenarioCarIndex);
    tcmsScreenBinders.add(new LoginPanelPopupBinder(loginPanelPopupModel));

    serviceRequestHandler = TCMSFactory.getServiceRequestHandler(scenarioCarIndex);

    operatorButtonProperty = new NodePseudoClassProperty(profileBtn);

    operatorButtonListener = (observable, oldVal, newVal) -> updateKeypadPanel(newVal);
    loginPanelPopupModel.getKeypadPanelVisible().addListener(operatorButtonListener);

    loginListener = (observable, oldVal, newVal) -> updateLoginLogoutGridActive(newVal);
    loginPanelPopupModel.getLogoutPanelVisible().addListener(loginListener);

    userIdLbl.setText(loginPanelPopupModel.getUserId().get());
    userIdLbl.textProperty().bind(loginPanelPopupModel.getUserId());

    updateKeypadPanel(loginPanelPopupModel.getKeypadPanelVisible().get());
    updateLoginLogoutGridActive(loginPanelPopupModel.getLogoutPanelVisible().get());

    hybridModeScreenModel = new HybridModeScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HybridModeScreenBinder(hybridModeScreenModel));

    hybridPanelSideListener = (observable, oldVal,
        newVal) -> updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());
    hybridModeScreenModel.getHybridPanelActiveSide().addListener(hybridPanelSideListener);

    updatePanelActiveSide(hybridModeScreenModel.getHybridPanelActiveSide().get());

    vduSelectionPopupModel = new VduSelectionPopupModel(scenarioCarIndex);
    tcmsScreenBinders.add(new VduSelectionPopupBinder(vduSelectionPopupModel, frontend));

    vduModeListener = ((observable, oldVal, newVal) -> updateHybridPanelVisibility());
    vduSelectionPopupModel.getVduSelected().addListener(vduModeListener);

    cctvVduModeListener = ((observable, oldVal, newVal) -> updateHybridPanelVisibility());
    vduSelectionPopupModel.getCurrentCctvVduMode().addListener(cctvVduModeListener);

    updateHybridPanelVisibility();
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

  private void updateHybridPanelVisibility()
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

  private void updateKeypadPanel(boolean visible)
  {
    if (visible)
    {
      keypadGrid.setVisible(true);
      userLoginLbl.setVisible(true);
      operatorButtonProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
    else
    {
      keypadGrid.setVisible(false);
      userLoginLbl.setVisible(false);
      operatorButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
  }

  private void updateLoginLogoutGridActive(boolean loggedIn)
  {

    beforeLoginGrid.setVisible(!loggedIn);
    afterLoginGrid.setVisible(loggedIn);
  }

  @FXML
  void onOpratorButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendButtonClickRequest(VDUInputs.OPERATOR_BUTTON_PRESSED);
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.CLEAR);
  }

  @FXML
  void onLogoutButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendVDUModeChangeRequest(VDUModeEnum.VDU_TCMS_MODE, frontend);
    serviceRequestHandler.sendButtonClickRequest(VDUInputs.LOGOUT_BUTTON_PRESSED);
  }

  @FXML
  void onKey0ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_0);
  }

  @FXML
  void onKey1ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_1);
  }

  @FXML
  void onKey2ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_2);
  }

  @FXML
  void onKey3ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_3);
  }

  @FXML
  void onKey4ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_4);
  }

  @FXML
  void onKey5ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_5);
  }

  @FXML
  void onKey6ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_6);
  }

  @FXML
  void onKey7ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_7);
  }

  @FXML
  void onKey8ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_8);
  }

  @FXML
  void onKey9ButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.NO_9);
  }

  @FXML
  void onKeyClearButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.CLEAR);
  }

  @FXML
  void onKeyDeleteButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.DELETE);
  }

  @FXML
  void onKeyEnterButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendKeyPadButtonRequest(KeyPadEnum.ENTER);
  }
}
