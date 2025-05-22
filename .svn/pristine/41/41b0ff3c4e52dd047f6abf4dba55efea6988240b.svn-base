/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.fe.base.ServiceRequestHandler;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.LowVoltageSystemCommandScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.LowVoltageSystemCommandScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class LowVoltageSystemCommandScreenController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(VDUInputs.LV_COMMAND_BCG1_M1_BUTTON)
  private Button isolateBcg1M1Button;

  @FXML
  @CommsNumber(VDUInputs.LV_COMMAND_BCG1_M2_BUTTON)
  private Button isolateBcg1M2Button;

  @FXML
  @CommsNumber(VDUInputs.LV_COMMAND_BCG1_M3_BUTTON)
  private Button isolateBcg1M3Button;

  @FXML
  @CommsNumber(VDUInputs.LV_COMMAND_BCG2_M1_BUTTON)
  private Button isolateBcg2M1Button;

  @FXML
  @CommsNumber(VDUInputs.LV_COMMAND_BCG2_M2_BUTTON)
  private Button isolateBcg2M2Button;

  @FXML
  @CommsNumber(VDUInputs.LV_COMMAND_BCG2_M3_BUTTON)
  private Button isolateBcg2M3Button;

  @FXML
  @CommsNumber(VDUInputs.LV_COMMAND_POPB_BUTTON)
  private Button pobpButton;

  private ServiceRequestHandler serviceRequestHandler;

  @FXML
  private GridPane outerGrid;

  @FXML
  private GridPane eightCarGrid;

  private LowVoltageSystemCommandScreenModel lowVoltageSystemCommandScreenModel;

  private ChangeListener<Number> totalColumnListener;

  private ChangeListener<Number> isolateBcg1M1StatusListener;

  private ChangeListener<Number> isolateBcg1M2StatusListener;

  private ChangeListener<Number> isolateBcg1M3StatusListener;

  private ChangeListener<Number> isolateBcg2M1StatusListener;

  private ChangeListener<Number> isolateBcg2M2StatusListener;

  private ChangeListener<Number> isolateBcg2M3StatusListener;

  private NodePseudoClassProperty isolateBcg1M1ButtonProperty;

  private NodePseudoClassProperty isolateBcg1M2ButtonProperty;

  private NodePseudoClassProperty isolateBcg1M3ButtonProperty;

  private NodePseudoClassProperty isolateBcg2M1ButtonProperty;

  private NodePseudoClassProperty isolateBcg2M2ButtonProperty;

  private NodePseudoClassProperty isolateBcg2M3ButtonProperty;

  private static final String SIX_CAR_FXML_NAME = "LowVoltageSixCars.fxml"; //$NON-NLS-1$

  @Override
  public void detachListeners()
  {
    lowVoltageSystemCommandScreenModel.getTotalColumn().removeListener(totalColumnListener);
    lowVoltageSystemCommandScreenModel.getIsolateBcg1M1Status().removeListener(isolateBcg1M1StatusListener);
    lowVoltageSystemCommandScreenModel.getIsolateBcg1M2Status().removeListener(isolateBcg1M2StatusListener);
    lowVoltageSystemCommandScreenModel.getIsolateBcg1M3Status().removeListener(isolateBcg1M3StatusListener);

    lowVoltageSystemCommandScreenModel.getIsolateBcg2M1Status().removeListener(isolateBcg2M1StatusListener);
    lowVoltageSystemCommandScreenModel.getIsolateBcg2M2Status().removeListener(isolateBcg2M2StatusListener);
    lowVoltageSystemCommandScreenModel.getIsolateBcg2M3Status().removeListener(isolateBcg2M3StatusListener);

  }

  @Override
  public void initializeImpl()
  {
    lowVoltageSystemCommandScreenModel = new LowVoltageSystemCommandScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new LowVoltageSystemCommandScreenBinder(lowVoltageSystemCommandScreenModel));
    serviceRequestHandler = TCMSFactory.getServiceRequestHandler(scenarioCarIndex);

    isolateBcg1M1ButtonProperty = new NodePseudoClassProperty(isolateBcg1M1Button);
    isolateBcg1M2ButtonProperty = new NodePseudoClassProperty(isolateBcg1M2Button);
    isolateBcg1M3ButtonProperty = new NodePseudoClassProperty(isolateBcg1M3Button);

    isolateBcg2M1ButtonProperty = new NodePseudoClassProperty(isolateBcg2M1Button);
    isolateBcg2M2ButtonProperty = new NodePseudoClassProperty(isolateBcg2M2Button);
    isolateBcg2M3ButtonProperty = new NodePseudoClassProperty(isolateBcg2M3Button);

    updateCarConfig(lowVoltageSystemCommandScreenModel.getTotalColumn().get());

    initializeBCGButtons();

    totalColumnListener = (observable, oldVal, newVal) -> updateCarConfig((int)newVal);
    lowVoltageSystemCommandScreenModel.getTotalColumn().addListener(totalColumnListener);

    isolateBcg1M1StatusListener = (observable, oldVal,
        newVal) -> updateBCG1ButtonState(isolateBcg1M1ButtonProperty, isolateBcg1M1Button, (int)newVal);
    lowVoltageSystemCommandScreenModel.getIsolateBcg1M1Status().addListener(isolateBcg1M1StatusListener);

    isolateBcg1M2StatusListener = (observable, oldVal,
        newVal) -> updateBCG1ButtonState(isolateBcg1M2ButtonProperty, isolateBcg1M2Button, (int)newVal);
    lowVoltageSystemCommandScreenModel.getIsolateBcg1M2Status().addListener(isolateBcg1M2StatusListener);

    isolateBcg1M3StatusListener = (observable, oldVal,
        newVal) -> updateBCG1ButtonState(isolateBcg1M3ButtonProperty, isolateBcg1M3Button, (int)newVal);
    lowVoltageSystemCommandScreenModel.getIsolateBcg1M3Status().addListener(isolateBcg1M3StatusListener);

    isolateBcg2M1StatusListener = (observable, oldVal,
        newVal) -> updateBCG2ButtonState(isolateBcg2M1ButtonProperty, isolateBcg2M1Button, (int)newVal);
    lowVoltageSystemCommandScreenModel.getIsolateBcg2M1Status().addListener(isolateBcg2M1StatusListener);

    isolateBcg2M2StatusListener = (observable, oldVal,
        newVal) -> updateBCG2ButtonState(isolateBcg2M2ButtonProperty, isolateBcg2M2Button, (int)newVal);
    lowVoltageSystemCommandScreenModel.getIsolateBcg2M2Status().addListener(isolateBcg2M2StatusListener);

    isolateBcg2M3StatusListener = (observable, oldVal,
        newVal) -> updateBCG2ButtonState(isolateBcg2M3ButtonProperty, isolateBcg2M3Button, (int)newVal);
    lowVoltageSystemCommandScreenModel.getIsolateBcg2M3Status().addListener(isolateBcg2M3StatusListener);

  }

  /**
   * initialize buttons with default value.
   */
  private void initializeBCGButtons()
  {
    updateBCG1ButtonState(isolateBcg1M1ButtonProperty, isolateBcg1M1Button,
        lowVoltageSystemCommandScreenModel.getIsolateBcg1M1Status().get());

    updateBCG1ButtonState(isolateBcg1M2ButtonProperty, isolateBcg1M2Button,
        lowVoltageSystemCommandScreenModel.getIsolateBcg1M2Status().get());

    updateBCG1ButtonState(isolateBcg1M3ButtonProperty, isolateBcg1M3Button,
        lowVoltageSystemCommandScreenModel.getIsolateBcg1M3Status().get());

    updateBCG2ButtonState(isolateBcg2M1ButtonProperty, isolateBcg2M1Button,
        lowVoltageSystemCommandScreenModel.getIsolateBcg2M1Status().get());

    updateBCG2ButtonState(isolateBcg2M2ButtonProperty, isolateBcg2M2Button,
        lowVoltageSystemCommandScreenModel.getIsolateBcg2M2Status().get());

    updateBCG2ButtonState(isolateBcg2M3ButtonProperty, isolateBcg2M3Button,
        lowVoltageSystemCommandScreenModel.getIsolateBcg2M3Status().get());
  }

  /**
   * update the BCG1 Button State
   * 
   * @param nodePseudoClassProperty
   * @param button
   * @param newVal
   */
  private void updateBCG1ButtonState(NodePseudoClassProperty nodePseudoClassProperty, Button button,
      int newVal)
  {

    if (newVal == 1)
    {

      nodePseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS_LOW_VOLTAGE);
      button.setText(TCMSUIConstants.LOW_VOLTAGE_REINSERT_LABEL);

    }
    else
    {
      nodePseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS_LOW_VOATAGE);
      button.setText(TCMSUIConstants.LOW_VOLTAGE_BCG1_LABEL);
    }
  }

  /**
   * update the BCG2 Button State
   * 
   * @param nodePseudoClassProperty
   * @param button
   * @param newVal
   */
  private void updateBCG2ButtonState(NodePseudoClassProperty nodePseudoClassProperty, Button button,
      int newVal)
  {

    if (newVal == 1)
    {

      nodePseudoClassProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS_LOW_VOLTAGE);
      button.setText(TCMSUIConstants.LOW_VOLTAGE_REINSERT_LABEL);

    }
    else
    {
      nodePseudoClassProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS_LOW_VOATAGE);
      button.setText(TCMSUIConstants.LOW_VOLTAGE_BCG2_LABEL);
    }
  }

  private void updateCarConfig(int noOfCars)
  {
    if (noOfCars != TCMSUIConstants.NUMBER_OF_CARS_ZERO)
    {

      if (noOfCars == TCMSUIConstants.NUMBER_OF_CARS_SIX)
      {

        LowVoltageSystemCommandSixCarScreenController lowVoltageSystemCommandSixCar = new LowVoltageSystemCommandSixCarScreenController();
        outerGrid.getChildren().add(lowVoltageSystemCommandSixCar.createCar(SIX_CAR_FXML_NAME));

        eightCarGrid.setVisible(false);
      }
      else
      {

        eightCarGrid.setVisible(true);
      }

    }
  }

  @FXML
  void onIsolateBcg1M1ButtonAction(ActionEvent event)
  {
    sendRequest(lowVoltageSystemCommandScreenModel.getIsolateBcg1M1Status().get(),
        VDUInputs.LV_COMMAND_BCG1_M1);
  }

  @FXML
  void onIsolateBcg1M2ButtonAction(ActionEvent event)
  {
    sendRequest(lowVoltageSystemCommandScreenModel.getIsolateBcg1M2Status().get(),
        VDUInputs.LV_COMMAND_BCG1_M2);

  }

  @FXML
  void onIsolateBcg1M3ButtonAction(ActionEvent event)
  {

    sendRequest(lowVoltageSystemCommandScreenModel.getIsolateBcg1M3Status().get(),
        VDUInputs.LV_COMMAND_BCG1_M3);

  }

  @FXML
  void onIsolateBcg2M1ButtonAction(ActionEvent event)
  {
    sendRequest(lowVoltageSystemCommandScreenModel.getIsolateBcg2M1Status().get(),
        VDUInputs.LV_COMMAND_BCG2_M1);

  }

  @FXML
  void onIsolateBcg2M2ButtonAction(ActionEvent event)
  {
    sendRequest(lowVoltageSystemCommandScreenModel.getIsolateBcg2M2Status().get(),
        VDUInputs.LV_COMMAND_BCG2_M2);

  }

  @FXML
  void onIsolateBcg2M3ButtonAction(ActionEvent event)
  {
    sendRequest(lowVoltageSystemCommandScreenModel.getIsolateBcg2M3Status().get(),
        VDUInputs.LV_COMMAND_BCG2_M3);

  }

  @FXML
  void onPopbButtonAction(ActionEvent event)
  {
    serviceRequestHandler.sendButtonClickRequest(VDUInputs.LV_COMMAND_POPB);

  }

  /**
   * Send request to service handler
   * 
   * @param value
   * @param commsNumber
   */
  private void sendRequest(int value, String commsNumber)
  {
    if (value == 0)
    {
      serviceRequestHandler.sendIsolateButtonRequest(commsNumber, 1);
    }
    else
    {
      serviceRequestHandler.sendIsolateButtonRequest(commsNumber, 0);
    }
  }

}
