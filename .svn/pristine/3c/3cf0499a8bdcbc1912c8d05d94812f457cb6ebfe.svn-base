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

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.fe.base.ServiceRequestHandler;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.MediumVoltageSystemCommandScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.MediumVoltageSystemCommandScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class MediumVoltageCommandScreenSixCarController extends AbstractTCMSController
{

  private ServiceRequestHandler serviceRequestHandler;

  @FXML
  private Button dmFrontForceBtn;

  @FXML
  private Button dmRearForceBtn;

  @FXML
  private Button forceLowBtn1;

  @FXML
  private Button forceLowBtn3;

  @FXML
  private Button forceHighBtn1;

  @FXML
  private Button forceHighBtn3;

  @FXML
  private Button resetFrontBtn;

  @FXML
  private Button resetRearBtn;

  private NodePseudoClassProperty dmFrontForceBtnProperty;

  private NodePseudoClassProperty dmRearForceBtnProperty;

  private NodePseudoClassProperty forceLowBtn1Property;

  private NodePseudoClassProperty forceLowBtn3Property;

  private NodePseudoClassProperty forceHighBtn1Property;

  private NodePseudoClassProperty forceHighBtn3Property;

  private NodePseudoClassProperty resetFrontBtnProperty;

  private NodePseudoClassProperty resetRearBtnProperty;

  private ChangeListener<Number> dmFrontForceStatusListener;

  private ChangeListener<Number> dmRearForceStatusListener;

  private ChangeListener<Number> forceLowBtn1StatusListener;

  private ChangeListener<Number> forceLowBtn3StatusListener;

  private ChangeListener<Number> forceHighBtn1StatusListener;

  private ChangeListener<Number> forceHighBtn3StatusListener;

  private ChangeListener<Number> resetFrontBtnStatusListener;

  private ChangeListener<Number> resetRearBtnStatusListener;

  private MediumVoltageSystemCommandScreenModel mediumVoltageSystemCommandScreenModel;

  @Override
  public void detachListeners()
  {
    mediumVoltageSystemCommandScreenModel.getDmFrontCarForceStatus()
        .removeListener(dmFrontForceStatusListener);
    mediumVoltageSystemCommandScreenModel.getT1CarLowForceStatus().removeListener(forceLowBtn1StatusListener);
    mediumVoltageSystemCommandScreenModel.getT3CarLowForceStatus().removeListener(forceLowBtn3StatusListener);

    mediumVoltageSystemCommandScreenModel.getDmFrontCarResetStatus()
        .removeListener(resetFrontBtnStatusListener);
    mediumVoltageSystemCommandScreenModel.getDmRearCarResetStatus()
        .removeListener(resetRearBtnStatusListener);

    mediumVoltageSystemCommandScreenModel.getT3CarHighForceStatus()
        .removeListener(forceHighBtn3StatusListener);
    mediumVoltageSystemCommandScreenModel.getT1CarHighForceStatus()
        .removeListener(forceHighBtn1StatusListener);
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
    forceLowBtn3Property = new NodePseudoClassProperty(forceLowBtn3);

    forceHighBtn1Property = new NodePseudoClassProperty(forceHighBtn1);
    forceHighBtn3Property = new NodePseudoClassProperty(forceHighBtn3);

    resetFrontBtnProperty = new NodePseudoClassProperty(resetFrontBtn);
    resetRearBtnProperty = new NodePseudoClassProperty(resetRearBtn);
    
    dmFrontForceStatusListener = (observable, oldVal,
        newVal) -> updateCarForceState(dmFrontForceBtnProperty, dmFrontForceBtn, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getDmFrontCarForceStatus().addListener(dmFrontForceStatusListener);

    dmRearForceStatusListener = (observable, oldVal,
        newVal) -> updateCarForceState(dmRearForceBtnProperty, dmRearForceBtn, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getDmRearCarForceStatus().addListener(dmRearForceStatusListener);

    forceLowBtn1StatusListener = (observable, oldVal, newVal) -> updateForceLowState(forceLowBtn1Property,
        forceLowBtn1, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT1CarLowForceStatus().addListener(forceLowBtn1StatusListener);

   

    forceLowBtn3StatusListener = (observable, oldVal, newVal) -> updateForceLowState(forceLowBtn3Property,
        forceLowBtn3, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT3CarLowForceStatus().addListener(forceLowBtn3StatusListener);

    forceHighBtn1StatusListener = (observable, oldVal, newVal) -> updateForceHighState(forceHighBtn1Property,
        forceHighBtn1, (int)newVal);
    mediumVoltageSystemCommandScreenModel.getT1CarHighForceStatus().addListener(forceHighBtn1StatusListener);
    
 
    
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

  

    updateForceLowState(forceLowBtn3Property, forceLowBtn3,
        mediumVoltageSystemCommandScreenModel.getT3CarLowForceStatus().get());

    updateForceHighState(forceHighBtn1Property, forceHighBtn1,
        mediumVoltageSystemCommandScreenModel.getT1CarHighForceStatus().get());

  
    updateForceHighState(forceHighBtn3Property, forceHighBtn3,
        mediumVoltageSystemCommandScreenModel.getT3CarHighForceStatus().get());
    
    updateCarResetState(resetRearBtnProperty, resetRearBtn, mediumVoltageSystemCommandScreenModel.getDmRearCarResetStatus().get());
    
    updateCarResetState(resetFrontBtnProperty, resetFrontBtn, mediumVoltageSystemCommandScreenModel.getDmFrontCarResetStatus().get());

    
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
  void forceHighBtn3Action(ActionEvent event)
  {
    sendRequest(VDUInputs.MV_T3_FORCE_HIGH_CAR_REQ,
        mediumVoltageSystemCommandScreenModel.getT3CarHighForceStatus().get());
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

  private void updateCarForceState(NodePseudoClassProperty nodePseudoClassProperty, Button dmForceBtn,
      int newVal)
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

  private void updateCarResetState(NodePseudoClassProperty nodePseudoClassProperty, Button dmForceBtn,
      int newVal)
  {
    if (newVal == 1)
    {

      nodePseudoClassProperty.set(TCMSUIConstants.UNFORCE_PSEUDO_CLASS);
     // dmForceBtn.setText(TCMSUIConstants.MV_VOLTAGE_UNFORCE_LABEL);

    }
    else
    {
      nodePseudoClassProperty.set(TCMSUIConstants.FORCE_PSEUDO_CLASS);
     // dmForceBtn.setText(TCMSUIConstants.MV_VOLTAGE_FORCE_LABEL);
    }
  }
}
