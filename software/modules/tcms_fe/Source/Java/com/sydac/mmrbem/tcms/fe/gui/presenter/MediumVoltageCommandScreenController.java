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

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.fe.base.ServiceRequestHandler;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.MediumVoltageSystemCommandScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.MediumVoltageSystemCommandScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class MediumVoltageCommandScreenController extends AbstractTCMSController
{

  @FXML
  private Button dmFrontForceBtn;

  @FXML
  private Button dmRearForceBtn;

  @FXML
  private Button forceLowBtn1;

  @FXML
  private Button forceLowBtn2;

  @FXML
  private Button forceLowBtn3;

  @FXML
  private Button forceHighBtn1;

  @FXML
  private Button forceHighBtn2;

  @FXML
  private Button forceHighBtn3;

  @FXML
  private Button resetFrontBtn;

  @FXML
  private Button resetRearBtn;

  @FXML
  private GridPane eightCarGrid;

  @FXML
  private GridPane resetGrid;

  @FXML
  private GridPane outerGrid;

  private ServiceRequestHandler serviceRequestHandler;

  private ChangeListener<Number> totalColumnListener;

  private NodePseudoClassProperty dmFrontForceBtnProperty;

  private NodePseudoClassProperty dmRearForceBtnProperty;

  private NodePseudoClassProperty forceLowBtn1Property;

  private NodePseudoClassProperty forceLowBtn2Property;

  private NodePseudoClassProperty forceLowBtn3Property;

  private NodePseudoClassProperty forceHighBtn1Property;

  private NodePseudoClassProperty forceHighBtn2Property;

  private NodePseudoClassProperty forceHighBtn3Property;

  private NodePseudoClassProperty resetFrontBtnProperty;

  private NodePseudoClassProperty resetRearBtnProperty;

  private MediumVoltageSystemCommandScreenModel mediumVoltageSystemCommandScreenModel;

  private ChangeListener<Number> dmFrontForceStatusListener;

  private ChangeListener<Number> dmRearForceStatusListener;

  private ChangeListener<Number> forceLowBtn1StatusListener;

  private ChangeListener<Number> forceLowBtn2StatusListener;

  private ChangeListener<Number> forceLowBtn3StatusListener;

  private ChangeListener<Number> forceHighBtn1StatusListener;

  private ChangeListener<Number> forceHighBtn2StatusListener;

  private ChangeListener<Number> forceHighBtn3StatusListener;

  private ChangeListener<Number> resetFrontBtnStatusListener;

  private ChangeListener<Number> resetRearBtnStatusListener;

  private static final String SIX_CAR_FXML_NAME = "MediumVoltageSystemCommandSixCarScreen.fxml"; //$NON-NLS-1$

  @Override
  public void detachListeners()
  {
    mediumVoltageSystemCommandScreenModel.getTotalColumn().removeListener(totalColumnListener);
    mediumVoltageSystemCommandScreenModel.getDmFrontCarForceStatus()
        .removeListener(dmFrontForceStatusListener);
    mediumVoltageSystemCommandScreenModel.getT1CarLowForceStatus().removeListener(forceLowBtn1StatusListener);
    mediumVoltageSystemCommandScreenModel.getT2CarLowForceStatus().removeListener(forceLowBtn2StatusListener);
    mediumVoltageSystemCommandScreenModel.getT3CarLowForceStatus().removeListener(forceLowBtn3StatusListener);
    
    mediumVoltageSystemCommandScreenModel.getDmFrontCarResetStatus().removeListener(resetFrontBtnStatusListener);
    mediumVoltageSystemCommandScreenModel.getDmRearCarResetStatus().removeListener(resetRearBtnStatusListener);
    
    mediumVoltageSystemCommandScreenModel.getT3CarHighForceStatus().removeListener(forceHighBtn3StatusListener);
    mediumVoltageSystemCommandScreenModel.getT2CarHighForceStatus().removeListener(forceHighBtn2StatusListener);
    mediumVoltageSystemCommandScreenModel.getT1CarHighForceStatus().removeListener(forceHighBtn1StatusListener);
  }

  @Override
  public void initializeImpl()
  {

    mediumVoltageSystemCommandScreenModel = new MediumVoltageSystemCommandScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new MediumVoltageSystemCommandScreenBinder(mediumVoltageSystemCommandScreenModel));
    serviceRequestHandler = TCMSFactory.getServiceRequestHandler(scenarioCarIndex);

    dmFrontForceBtnProperty = new NodePseudoClassProperty(dmFrontForceBtn);
    dmRearForceBtnProperty = new NodePseudoClassProperty(dmRearForceBtn);

    forceLowBtn1Property = new NodePseudoClassProperty(forceLowBtn1);
    forceLowBtn2Property = new NodePseudoClassProperty(forceLowBtn2);
    forceLowBtn3Property = new NodePseudoClassProperty(forceLowBtn3);

    forceHighBtn1Property = new NodePseudoClassProperty(forceHighBtn1);
    forceHighBtn2Property = new NodePseudoClassProperty(forceHighBtn2);
    forceHighBtn3Property = new NodePseudoClassProperty(forceHighBtn3);

    resetFrontBtnProperty = new NodePseudoClassProperty(resetFrontBtn);
    resetRearBtnProperty = new NodePseudoClassProperty(resetRearBtn);

    totalColumnListener = (observable, oldVal, newVal) -> updateCarConfig((int)newVal);
    mediumVoltageSystemCommandScreenModel.getTotalColumn().addListener(totalColumnListener);

    dmFrontForceStatusListener = (observable, oldVal,
        newVal) -> updateCarForceState(dmFrontForceBtnProperty, dmFrontForceBtn, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getDmFrontCarForceStatus().addListener(dmFrontForceStatusListener);

    dmRearForceStatusListener = (observable, oldVal,
        newVal) -> updateCarForceState(dmRearForceBtnProperty, dmRearForceBtn, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getDmRearCarForceStatus().addListener(dmRearForceStatusListener);

    forceLowBtn1StatusListener = (observable, oldVal, newVal) -> updateForceLowState(forceLowBtn1Property,
        forceLowBtn1, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT1CarLowForceStatus().addListener(forceLowBtn1StatusListener);

    forceLowBtn2StatusListener = (observable, oldVal, newVal) -> updateForceLowState(forceLowBtn2Property,
        forceLowBtn2, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT2CarLowForceStatus().addListener(forceLowBtn2StatusListener);

    forceLowBtn3StatusListener = (observable, oldVal, newVal) -> updateForceLowState(forceLowBtn3Property,
        forceLowBtn3, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT3CarLowForceStatus().addListener(forceLowBtn3StatusListener);

    forceHighBtn1StatusListener = (observable, oldVal, newVal) -> updateForceHighState(forceHighBtn1Property,
        forceHighBtn1, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT1CarHighForceStatus().addListener(forceHighBtn1StatusListener);
    
    forceHighBtn2StatusListener = (observable, oldVal, newVal) -> updateForceHighState(forceHighBtn2Property,
        forceHighBtn2, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT2CarHighForceStatus().addListener(forceHighBtn2StatusListener);
    
    forceHighBtn3StatusListener = (observable, oldVal, newVal) -> updateForceHighState(forceHighBtn3Property,
        forceHighBtn3, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT3CarHighForceStatus().addListener(forceHighBtn3StatusListener);
    
    
    resetFrontBtnStatusListener = (observable, oldVal,
        newVal) -> updateCarResetState(resetFrontBtnProperty, resetFrontBtn, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getDmFrontCarResetStatus().addListener(resetFrontBtnStatusListener);
    
    resetRearBtnStatusListener = (observable, oldVal,
        newVal) -> updateCarResetState(resetRearBtnProperty, resetRearBtn, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getDmRearCarResetStatus().addListener(resetRearBtnStatusListener);

    initializeButtons();
  }

  private void initializeButtons()
  {
    updateCarForceState(dmFrontForceBtnProperty, dmFrontForceBtn,
        mediumVoltageSystemCommandScreenModel.getDmFrontCarForceStatus().get());

    updateCarForceState(dmRearForceBtnProperty, dmRearForceBtn,
        mediumVoltageSystemCommandScreenModel.getDmRearCarForceStatus().get());

    updateForceLowState(forceLowBtn1Property, forceLowBtn1,
        mediumVoltageSystemCommandScreenModel.getT1CarLowForceStatus().get());

    updateForceLowState(forceLowBtn2Property, forceLowBtn2,
        mediumVoltageSystemCommandScreenModel.getT2CarLowForceStatus().get());

    updateForceLowState(forceLowBtn3Property, forceLowBtn3,
        mediumVoltageSystemCommandScreenModel.getT3CarLowForceStatus().get());

    updateForceHighState(forceHighBtn1Property, forceHighBtn1,
        mediumVoltageSystemCommandScreenModel.getT1CarHighForceStatus().get());

    updateForceHighState(forceHighBtn2Property, forceHighBtn2,
        mediumVoltageSystemCommandScreenModel.getT2CarHighForceStatus().get());
    updateForceHighState(forceHighBtn3Property, forceHighBtn3,
        mediumVoltageSystemCommandScreenModel.getT3CarHighForceStatus().get());
    
    updateCarResetState(resetRearBtnProperty, resetRearBtn, mediumVoltageSystemCommandScreenModel.getDmRearCarResetStatus().get());
    
    updateCarResetState(resetFrontBtnProperty, resetFrontBtn, mediumVoltageSystemCommandScreenModel.getDmFrontCarResetStatus().get());

    updateCarConfig(mediumVoltageSystemCommandScreenModel.getTotalColumn().get());
  }

  private void updateCarForceState(NodePseudoClassProperty nodePseudoClassProperty,
      Button dmForceBtn, int newVal)
  {
    if (newVal == 1)
    {

      nodePseudoClassProperty.set(TCMSUIConstants.UNFORCE_PSEUDO_CLASS);
      dmForceBtn.setText(TCMSUIConstants.MV_VOLTAGE_UNFORCE_LABEL);

    }
    else
    {
      nodePseudoClassProperty.set(TCMSUIConstants.FORCE_PSEUDO_CLASS);
      dmForceBtn.setText(TCMSUIConstants.MV_VOLTAGE_FORCE_LABEL);
    }
  }

 

  private void updateForceLowState(NodePseudoClassProperty nodePseudoClassProperty, Button forceBtn,
      int newVal)
  {
    if (newVal == 1)
    {

      nodePseudoClassProperty.set(TCMSUIConstants.UNFORCE_PSEUDO_CLASS);
      forceBtn.setText(TCMSUIConstants.MV_VOLTAGE_RELEASE_LOW_LABEL);

    }
    else
    {
      nodePseudoClassProperty.set(TCMSUIConstants.FORCE_PSEUDO_CLASS);
      forceBtn.setText(TCMSUIConstants.MV_VOLTAGE_FORCE_LOW_LABEL);
    }
  }

  private void updateForceHighState(NodePseudoClassProperty nodePseudoClassProperty, Button forceBtn,
      int newVal)
  {
    if (newVal == 1)
    {

      nodePseudoClassProperty.set(TCMSUIConstants.UNFORCE_PSEUDO_CLASS);
      forceBtn.setText(TCMSUIConstants.MV_VOLTAGE_RELEASE_HIGH_LABEL);

    }
    else
    {
      nodePseudoClassProperty.set(TCMSUIConstants.FORCE_PSEUDO_CLASS);
      forceBtn.setText(TCMSUIConstants.MV_VOLTAGE_FORCE_HIGH_LABEL);
    }
  }

  
  private void updateCarResetState(NodePseudoClassProperty nodePseudoClassProperty,
      Button dmForceBtn, int newVal)
  {
    if (newVal == 1)
    {

      nodePseudoClassProperty.set(TCMSUIConstants.UNFORCE_PSEUDO_CLASS);
     // dmForceBtn.setText(TCMSUIConstants.MV_VOLTAGE_UNFORCE_LABEL);

    }
    else
    {
      nodePseudoClassProperty.set(TCMSUIConstants.FORCE_PSEUDO_CLASS);
    //  dmForceBtn.setText(TCMSUIConstants.MV_VOLTAGE_FORCE_LABEL);
    }
  }
  
  @FXML
  void dmFrontForceBtnAction(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_DM_FRONT_FORCE_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getDmFrontCarForceStatus().get());

  }

  @FXML
  void dmRearForceBtnAction(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_DM_REAR_FORCE_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getDmRearCarForceStatus().get());

  }

  @FXML
  void dmResetFrontBtnAction(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_DM_FRONT_RESET_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getDmFrontCarResetStatus().get());

  }

  @FXML
  void dmResetRearBtnAction(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_DM_REAR_RESET_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getDmRearCarResetStatus().get());

  }

  @FXML
  void forceLowBtn1Action(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_T1_FORCE_LOW_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getT1CarLowForceStatus().get());
  }

  @FXML
  void forceLowBtn2Action(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_T2_FORCE_LOW_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getT2CarLowForceStatus().get());

  }

  @FXML
  void forceLowBtn3Action(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_T3_FORCE_LOW_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getT3CarLowForceStatus().get());
  }

  @FXML
  void forceHighBtn1Action(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_T1_FORCE_HIGH_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getT1CarHighForceStatus().get());

  }

  @FXML
  void forceHighBtn2Action(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_T2_FORCE_HIGH_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getT2CarHighForceStatus().get());
  }

  @FXML
  void forceHighBtn3Action(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_T3_FORCE_HIGH_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getT3CarHighForceStatus().get());
  }

  private void updateCarConfig(int noOfCars)
  {
    if (noOfCars != TCMSUIConstants.NUMBER_OF_CARS_ZERO)
    {

      if (noOfCars == TCMSUIConstants.NUMBER_OF_CARS_SIX)
      {

        MediumVoltageCommandScreenSixCarController systemCommandSixCar = new MediumVoltageCommandScreenSixCarController();
        outerGrid.getChildren().add(systemCommandSixCar.createCar(SIX_CAR_FXML_NAME));

        eightCarGrid.setVisible(false);
        resetGrid.setVisible(false);
      }
      else
      {

        eightCarGrid.setVisible(true);
        resetGrid.setVisible(true);
      }

    }
  }

  /**
   * Send request to service handler
   * 
   * @param value
   * @param commsNumber
   */
  private void sendRequest(String commsNumber, int value)
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
