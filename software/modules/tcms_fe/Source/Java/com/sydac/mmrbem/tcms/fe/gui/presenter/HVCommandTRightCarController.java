/*
 * ==================================================================
 *
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;
import java.util.Objects;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSControlUnitStatusList.APSControlUnitState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PantographStatusList.Pantograph;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBStatusList.VCBState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageRightTCarScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class HVCommandTRightCarController extends AbstractTCMSController
{

  @FXML
  private GridPane reqVcbPopupGrid;

  @FXML
  private Button reqVcbConfirmBtn;

  @FXML
  private Button reqVcbDeclineBtn;

  @FXML
  private Button pantoSelectRightBtn;

  @FXML
  private Button pantoLowerBtn;

  @FXML
  private Button pantoResetBtn;

  @FXML
  private Button vcbResetBtn;

  @FXML
  private Button reqCtrlVcbNsBtn;

  @FXML
  private Button pantoIsolateBtn;

  @FXML
  private Button vcbIsolateBtn;

  @FXML
  private Button aps1IsolateBtn;

  @FXML
  private Button aps2IsolateBtn;

  private NodePseudoClassProperty pantoIsolateStateProperty;

  private NodePseudoClassProperty pantoSelectButtonProperty;

  private NodePseudoClassProperty pantoLowerButtonProperty;

  private NodePseudoClassProperty reqCtrlVcbNsButtonProperty;

  private NodePseudoClassProperty vcbResetButtonProperty;

  private NodePseudoClassProperty vcbIsolateButtonProperty;

  private NodePseudoClassProperty aps1ButtonProperty;

  private NodePseudoClassProperty aps2ButtonProperty;

  private ObjectPropertyBase<CarComponentStatesDO> apsState1;

  private ObjectPropertyBase<CarComponentStatesDO> apsState2;

  private ObjectPropertyBase<CarComponentStatesDO> pantoState;

  private ObjectPropertyBase<CarComponentStatesDO> vcbState;

  private ChangeListener<Number> reqCtrlVcbNsListener;

  private HighVoltageScreenModel highVoltageScreenModel;

  private ChangeListener<Number> rightPantoListener;

  private ChangeListener<Number> rightPantoLowListener;

  private HighVoltageRightTCarScreenModel highVoltageRightTCarScreenModel;

  private int carIndex;

  private NodePseudoClassProperty reqVcbConfirmButtonProperty;

  private NodePseudoClassProperty reqVcbDeclineButtonProperty;

  private boolean pantoSelected;

  private ChangeListener<Number> resetPantoListener;

  private NodePseudoClassProperty pantoResetButtonProperty;

  private ChangeListener<Number> resetVcbListener;

  private ChangeListener<Number> isolateVcbListener;

  private ChangeListener<Number> aps1Listener;

  private ChangeListener<Number> aps2Listener;

  private ChangeListener<Number> confirmListener;

  public HVCommandTRightCarController(CarConfigurationModel carConfig,
      HighVoltageScreenModel highVoltageScreenModel,
      HighVoltageRightTCarScreenModel highVoltageRightTCarScreenModel)
  {

    this.highVoltageScreenModel = highVoltageScreenModel;
    this.highVoltageRightTCarScreenModel = highVoltageRightTCarScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
    pantoSelected = false;
  }

  @Override
  public void initializeImpl()
  {
    pantoIsolateStateProperty = new NodePseudoClassProperty(pantoIsolateBtn);
    pantoSelectButtonProperty = new NodePseudoClassProperty(pantoSelectRightBtn);
    pantoLowerButtonProperty = new NodePseudoClassProperty(pantoLowerBtn);
    reqCtrlVcbNsButtonProperty = new NodePseudoClassProperty(reqCtrlVcbNsBtn);

    vcbResetButtonProperty = new NodePseudoClassProperty(vcbResetBtn);

    vcbIsolateButtonProperty = new NodePseudoClassProperty(vcbIsolateBtn);

    aps1ButtonProperty = new NodePseudoClassProperty(aps1IsolateBtn);

    aps2ButtonProperty = new NodePseudoClassProperty(aps2IsolateBtn);
    reqVcbConfirmButtonProperty = new NodePseudoClassProperty(reqVcbConfirmBtn);
    reqVcbDeclineButtonProperty = new NodePseudoClassProperty(reqVcbDeclineBtn);

    pantoResetButtonProperty = new NodePseudoClassProperty(pantoResetBtn);
    apsState1 = highVoltageScreenModel.apsStatus1Property(carIndex);
    apsState1.addListener(observable -> aps1IsolateStateUpdate());
    aps1IsolateStateUpdate();

    apsState2 = highVoltageScreenModel.apsStatus2Property(carIndex);
    apsState2.addListener(observable -> aps2IsolateStateUpdate());
    aps2IsolateStateUpdate();

    vcbState = highVoltageScreenModel.vcbStatusProperty(carIndex);
    vcbState.addListener(observable -> vcbIsolateStateUpdate());

    pantoState = highVoltageScreenModel.pantographStatusProperty(carIndex);
    pantoState.addListener(observable -> pantoIsolateStateUpdate());

    reqCtrlVcbNsListener = (observable, oldValue, newValue) -> updateReqCtrlVcbNs(newValue.intValue());
    highVoltageScreenModel.getReqCtrlVcbNsStatusProperty().addListener(reqCtrlVcbNsListener);

    rightPantoListener = (observable, oldValue, newValue) -> checkPantoSelected();
    highVoltageRightTCarScreenModel.getRightPantoState().addListener(rightPantoListener);

    rightPantoLowListener = (observable, oldValue, newValue) -> pantoLowerStateUpdate();
    highVoltageRightTCarScreenModel.getRightPantoLowState().addListener(rightPantoLowListener);

    resetPantoListener = (observable, oldValue, newValue) -> pantoResetUpdate(newValue.intValue());
    highVoltageRightTCarScreenModel.getRightResetPantoState().addListener(resetPantoListener);

    resetVcbListener = (observable, oldValue, newValue) -> vcbResetUpdate(newValue.intValue());
    highVoltageRightTCarScreenModel.getRightVcbResetState().addListener(resetVcbListener);

    isolateVcbListener = (observable, oldValue, newValue) -> vcbIsolateUpdate(newValue.intValue());
    highVoltageRightTCarScreenModel.getRightVcbIsolateState().addListener(isolateVcbListener);

    aps1Listener = (observable, oldValue, newValue) -> aps1Update(newValue.intValue());
    highVoltageRightTCarScreenModel.getAps5IsolateState().addListener(aps1Listener);

    aps2Listener = (observable, oldValue, newValue) -> aps2Update(newValue.intValue());
    highVoltageRightTCarScreenModel.getAps6IsolateState().addListener(aps2Listener);

    confirmListener = (observable, oldValue, newValue) -> updateGrid(newValue.intValue());
    highVoltageRightTCarScreenModel.getConfirmState().addListener(confirmListener);

    pantoIsolateStateUpdate();
    pantoSelectStateUpdate();
    vcbIsolateStateUpdate();
    updateGrid(highVoltageRightTCarScreenModel.getConfirmState().get());
    updateReqCtrlVcbNsButton();
  }

  private void updateGrid(int intValue)
  {
    if (intValue == 1)
    {
      reqVcbPopupGrid.setVisible(Boolean.TRUE);
    }
    else
    {
      reqVcbPopupGrid.setVisible(Boolean.FALSE);
    }
  }

  private void aps1Update(int reset)
  {

    if (reset == 1)
    {
      aps1ButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      aps1ButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }

  }

  private void aps2Update(int reset)
  {

    if (reset == 1)
    {
      aps2ButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      aps2ButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }

  }

  private void vcbIsolateUpdate(int reset)
  {

    if (reset == 1)
    {
      vcbIsolateButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      vcbIsolateButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }

  }

  private void vcbResetUpdate(int reset)
  {

    if (reset == 1)
    {
      vcbResetButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      vcbResetButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }

  }

  private void pantoResetUpdate(int reset)
  {
    if (reset == 1)
    {
      pantoResetButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      pantoResetButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
  }

  private void updateReqCtrlVcbNs(int state)
  {

    if (state == 0)
    {
      reqCtrlVcbNsButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else
    {
      reqCtrlVcbNsButtonProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
  }

  private void pantoIsolateStateUpdate()
  {
    if (Objects.equals(pantoState.get().getComponentState(), Pantograph.ISOLATED.toString().toLowerCase()))
    {
      pantoIsolateStateProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
      pantoIsolateBtn.setText(TCMSUIConstants.REINSERT_PANTO_TXT);
    }
    else if (Objects.equals(pantoState.get().getComponentState(),
        Pantograph.LOWERED.toString().toLowerCase()) || Objects.equals(pantoState.get().getComponentState(),
            Pantograph.LOWERED_FAULTY.toString().toLowerCase()))
    {
      pantoIsolateStateProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
      pantoIsolateBtn.setText(TCMSUIConstants.ISOLATE_PANTO_TXT);
      checkPantoSelected();
      pantoSelectStateUpdate();
    }
    else
    {
      pantoIsolateStateProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
      pantoIsolateBtn.setText(TCMSUIConstants.ISOLATE_PANTO_TXT);
      pantoSelectStateUpdate();
    }
    pantoLowerStateUpdate();
  }

  private void pantoSelectStateUpdate()
  {
   
    if (Objects.equals(pantoState.get().getComponentState(), Pantograph.RAISED.toString().toLowerCase()))
    {
      pantoSelectButtonProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
      pantoSelectRightBtn.setText(TCMSUIConstants.SELECT_TXT);
    }
//    else
//    {
//      checkPantoSelected();
//    }
  }

  private void checkPantoSelected()
  {
    if (highVoltageRightTCarScreenModel.getRightPantoState().get() == 1)
    {
      pantoSelectButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
      pantoSelectRightBtn.setText(TCMSUIConstants.DESELECT_TXT);
    }
    else
    {
      pantoSelectButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
      pantoSelectRightBtn.setText(TCMSUIConstants.SELECT_TXT);
    }
  }

  private void pantoLowerStateUpdate()
  {
    pantoLowerBtn.setText(TCMSUIConstants.LOWER_TXT);
    if (Objects.equals(pantoState.get().getComponentState(), Pantograph.RAISED.toString().toLowerCase())
        && Objects.equals(vcbState.get().getComponentState(), VCBState.OPEN.toString().toLowerCase()))
    {
      if (highVoltageRightTCarScreenModel.getRightPantoLowState().get() == 1)
      {
        pantoLowerButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
      }
      else
      {
        pantoLowerButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
      }
    }
    else
    {
      pantoLowerButtonProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
    }
  }

  private void vcbIsolateStateUpdate()
  {
    if (Objects.equals(vcbState.get().getComponentState(), VCBState.ISOLATED.toString().toLowerCase()))
    {
      vcbIsolateBtn.setText(TCMSUIConstants.DE_ISOLATE_VCB_TXT);
    }
    else
    {
      vcbIsolateBtn.setText(TCMSUIConstants.ISOLATE_VCB_TXT);
    }
    pantoLowerStateUpdate();
  }

  private void aps1IsolateStateUpdate()
  {
    if (Objects.equals(apsState1.get().getComponentState(),
        APSControlUnitState.APS_CU_ISOLATED.toString().toLowerCase()))
    {
      aps1IsolateBtn.setText(updateApsButtonDeIsolateText());
    }
    else
    {
      aps1IsolateBtn.setText(updateApsButtonIsolateText());
    }
  }

  private String updateApsButtonDeIsolateText()
  {
    String buttonText;
    if (carIndex == TCMSConstants.CAB_1)
    {
      buttonText = TCMSUIConstants.DE_ISOLATE_APS_1_TXT;
    }
    else if (carIndex == TCMSConstants.CAB_3 || carIndex == TCMSConstants.CAB_4)
    {
      buttonText = TCMSUIConstants.DE_ISOLATE_APS_3_TXT;
    }
    else
    {
      buttonText = TCMSUIConstants.DE_ISOLATE_APS_5_TXT;
    }
    return buttonText;
  }

  private String updateApsButtonIsolateText()
  {
    String buttonText;
    if (carIndex == TCMSConstants.CAB_1)
    {
      buttonText = TCMSUIConstants.ISOLATE_APS_1_TXT;
    }
    else if (carIndex == TCMSConstants.CAB_3 || carIndex == TCMSConstants.CAB_4)
    {
      buttonText = TCMSUIConstants.ISOLATE_APS_3_TXT;
    }
    else
    {
      buttonText = TCMSUIConstants.ISOLATE_APS_5_TXT;
    }
    return buttonText;
  }

  private void aps2IsolateStateUpdate()
  {
    if (Objects.equals(apsState2.get().getComponentState(),
        APSControlUnitState.APS_CU_ISOLATED.toString().toLowerCase()))
    {
      aps2IsolateBtn.setText(updateAps2ButtonDeIsolateText());
    }
    else
    {
      aps2IsolateBtn.setText(updateAps2ButtonIsolateText());
    }
  }

  private String updateAps2ButtonIsolateText()
  {
    String buttonText;
    if (carIndex == TCMSConstants.CAB_1)
    {
      buttonText = TCMSUIConstants.ISOLATE_APS_2_TXT;
    }
    else if (carIndex == TCMSConstants.CAB_3 || carIndex == TCMSConstants.CAB_4)
    {
      buttonText = TCMSUIConstants.ISOLATE_APS_4_TXT;
    }
    else
    {
      buttonText = TCMSUIConstants.ISOLATE_APS_6_TXT;
    }
    return buttonText;
  }

  private String updateAps2ButtonDeIsolateText()
  {
    String buttonText;
    if (carIndex == TCMSConstants.CAB_1)
    {
      buttonText = TCMSUIConstants.DE_ISOLATE_APS_2_TXT;
    }
    else if (carIndex == TCMSConstants.CAB_3 || carIndex == TCMSConstants.CAB_4)
    {
      buttonText = TCMSUIConstants.DE_ISOLATE_APS_4_TXT;
    }
    else
    {
      buttonText = TCMSUIConstants.DE_ISOLATE_APS_6_TXT;
    }
    return buttonText;
  }

  private void updateReqCtrlVcbNsButton()
  {
    reqVcbPopupGrid.setVisible(Boolean.FALSE);
    if (carIndex == TCMSConstants.CAB_6 || carIndex == TCMSConstants.CAB_4)
    {
      reqCtrlVcbNsBtn.setVisible(Boolean.TRUE);
    }
    else
    {
      reqCtrlVcbNsBtn.setVisible(Boolean.FALSE);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void pantoSelectButtonAction(ActionEvent event)
  {

    if (!Objects.equals(pantoState.get().getComponentState(), Pantograph.RAISED.toString().toLowerCase()))
    {
      // pantoSelected = !pantoSelected;
      // pantoSelectStateUpdate();
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendHVCommandReq(VDUInputs.PANTO_SELECTED_REQ_CAR, carIndex);

      if (highVoltageRightTCarScreenModel.getRightPantoState().get() == 1)
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.PANTO_BUTTON_RIGHT_REQ,
            0);
      }
      else
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.PANTO_BUTTON_RIGHT_REQ,
            1);
      }
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void pantoLowerButtonAction(ActionEvent event)
  {
    if (Objects.equals(pantoState.get().getComponentState(), Pantograph.RAISED.toString().toLowerCase())
        && Objects.equals(vcbState.get().getComponentState(), VCBState.OPEN.toString().toLowerCase()))
    {
      if (!pantoSelected)
      {
        pantoSelected = !pantoSelected;
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendHVCommandReq(VDUInputs.PANTO_SELECTED_REQ_CAR, carIndex);
      }
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.PANTO_LOWER_REQ_CAR,
          carIndex);
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(VDUInputs.PANTO_LOW_BUTTON_RIGHT_REQ);
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.PANTO_BUTTON_RIGHT_REQ, 0);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void pantoResetButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.PANTO_RESET_REQ_CAR,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.PANTO_RESET_BUTTON_RIGHT_REQ);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void vcbResetButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.VCB_RESET_REQ_CAR,
        carIndex);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.VCB_RESET_BUTTON_RIGHT_REQ);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void reqCtrlVcbNsButtonAction(ActionEvent event)
  {
    // reqVcbPopupGrid.setVisible(Boolean.TRUE);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.REQ_VCB_CONFIRM_BUTTON, 1);

    // TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.REQ_VCB_CONFIRM_BUTTON,
    // 0);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void pantoIsolateButtonAction(ActionEvent event)
  {
    if ((Objects.equals(pantoState.get().getComponentState(), Pantograph.ISOLATED.toString().toLowerCase()))
        || (Objects.equals(pantoState.get().getComponentState(),
            Pantograph.LOWERED.toString().toLowerCase())))
    {
      if (Objects.equals(pantoState.get().getComponentState(), Pantograph.ISOLATED.toString().toLowerCase()))
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_PANTO_REQ, 0);
      }
      else
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_PANTO_REQ, 1);
      }
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.ISOLATE_PANTO_REQ_CAR,
          carIndex);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void vcbIsolateButtonAction(ActionEvent event)
  {
    if (Objects.equals(vcbState.get().getComponentState(), VCBState.ISOLATED.toString().toLowerCase()))

    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_VCB_REQ, 0);
    }
    else if (Objects.equals(vcbState.get().getComponentState(), VCBState.OPEN.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_VCB_REQ, 1);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.ISOLATE_VCB_REQ_CAR,
        carIndex);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.ISOLATE_RIGHT_VCB_REQ);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void aps1IsolateButtonAction(ActionEvent event)
  {
    if (Objects.equals(apsState1.get().getComponentState(),
        APSControlUnitState.APS_CU_ISOLATED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_APS1_REQ, 0);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_APS1_REQ, 1);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.ISOLATE_APS1_REQ_CAR,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.ISOLATE_APS5_REQUEST);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void aps2IsolateButtonAction(ActionEvent event)
  {
    if (Objects.equals(apsState2.get().getComponentState(),
        APSControlUnitState.APS_CU_ISOLATED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_APS2_REQ, 0);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_APS2_REQ, 1);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.ISOLATE_APS2_REQ_CAR,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.ISOLATE_APS6_REQUEST);
  }

  @FXML
  private void onReqVcbConfirmButtonAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.REQ_CTRL_VCB_NS,
        highVoltageScreenModel.getReqCtrlVcbNsStatusProperty().get() == 0 ? 1 : 0);
    // reqVcbPopupGrid.setVisible(Boolean.FALSE);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.REQ_VCB_CONFIRM_BUTTON, 0);
  }

  @FXML
  private void onReqVcbDeclineButtonAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.REQ_VCB_CONFIRM_BUTTON, 0);
    // reqVcbPopupGrid.setVisible(Boolean.FALSE);
  }

  @Override
  public void detachListeners()
  {
    // To Detach Listeners
  }

  public GridPane createCar(String fxmlName)
  {

    GridPane gridPane;
    FXMLLoader fxmlLoader = new FXMLLoader(ViewPackage.class.getResource(fxmlName));
    fxmlLoader.setController(this);
    try
    {
      gridPane = fxmlLoader.load();
    }
    catch (IOException exception)
    {
      logger.error(exception);
      throw new LoadingException(exception);
    }
    return gridPane;
  }
}