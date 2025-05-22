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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FDUCBStatusList.FDUCBState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVAC1StatusList.HVAC1State;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVAC2StatusList.HVAC2State;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.RbCommandScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.property.ObjectPropertyBase;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class RBCommandDMCarController extends AbstractTCMSController
{

  private RbCommandScreenModel rbCommandScreenModel;

  private int carIndex;

  @FXML
  private GridPane frontFduGrid;

  @FXML
  private GridPane frontHvacGrid;

  @FXML
  private Button openBtnFduFront;

  @FXML
  private Button closeBtnFduFront;

  @FXML
  private Button openBtnHvac1Front;

  @FXML
  private Button closeBtnHvac1Front;

  @FXML
  private Button openBtnHvac2Front;

  @FXML
  private Button closeBtnHvac2Front;

  private NodePseudoClassProperty openBtnHvac1FrontProperty;

  private NodePseudoClassProperty closeBtnHvac1FrontProperty;

  private NodePseudoClassProperty openBtnHvac2FrontProperty;

  private NodePseudoClassProperty closeBtnHvac2FrontProperty;

  private NodePseudoClassProperty openBtnFducbFrontProperty;

  private NodePseudoClassProperty closeBtnFducbFrontProperty;

  ObjectPropertyBase<CarComponentStatesDO> hvac1State;

  ObjectPropertyBase<CarComponentStatesDO> hvac2State;

  ObjectPropertyBase<CarComponentStatesDO> fducbState;

  public RBCommandDMCarController(CarConfigurationModel carConfig, RbCommandScreenModel rbCommandScreenModel)
  {
    this.rbCommandScreenModel = rbCommandScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
  }

  @Override
  public void initializeImpl()
  {

    openBtnHvac1FrontProperty = new NodePseudoClassProperty(openBtnHvac1Front);
    closeBtnHvac1FrontProperty = new NodePseudoClassProperty(closeBtnHvac1Front);
    openBtnHvac2FrontProperty = new NodePseudoClassProperty(openBtnHvac2Front);
    closeBtnHvac2FrontProperty = new NodePseudoClassProperty(closeBtnHvac2Front);

    openBtnFducbFrontProperty = new NodePseudoClassProperty(openBtnFduFront);
    closeBtnFducbFrontProperty = new NodePseudoClassProperty(closeBtnFduFront);

    hvac1State = rbCommandScreenModel.hvac1StatusProperty(carIndex);
    hvac1State.addListener(observable -> hvac1StatusUpdated());
    hvac2State = rbCommandScreenModel.hvac2StatusProperty(carIndex);
    hvac2State.addListener(observable -> hvac2StatusUpdated());

    fducbState = rbCommandScreenModel.fdscbStatusProperty(carIndex);
    fducbState.addListener(observable -> fducbStatusUpdated());

    hvac1StatusUpdated();
    hvac2StatusUpdated();
    fducbStatusUpdated();
  }

  @FXML
  private void openBtnFduFrontAction(ActionEvent event)
  {
    if (Objects.equals(fducbState.get().getComponentState(), FDUCBState.OPEN.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_FDU_OPEN_REQ, 1);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_FDU_OPEN_REQ, 0);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.RB_FDU_OPEN_REQ_CAR,
        carIndex);

  }

 

  @FXML
  private void closeBtnFduFrontAction(ActionEvent event)
  {
    if (Objects.equals(fducbState.get().getComponentState(), FDUCBState.CLOSED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_FDU_COSE_REQ, 1);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_FDU_COSE_REQ, 0);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.RB_FDU_CLOSE_REQ_CAR,
        carIndex);
  }

 
  @FXML
  private void openBtnHvac1FrontAction(ActionEvent event)
  {
   

    if (Objects.equals(hvac1State.get().getComponentState(), HVAC1State.OPEN.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_HAVC1_OPEN_REQ, 1);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_HAVC1_OPEN_REQ, 0);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.RB_HAVC1_OPEN_REQ_CAR,
        carIndex);
  }

  @FXML
  private void closeBtnHvac1FrontAction(ActionEvent event)
  {

    if (Objects.equals(hvac1State.get().getComponentState(), HVAC1State.CLOSED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_HVAC1_CLOSE_REQ, 1);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_HVAC1_CLOSE_REQ, 0);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.RB_HAVC1_CLOSE_REQ_CAR,
        carIndex);
  }

  @FXML
  private void openBtnHvac2FrontAction(ActionEvent event)
  {
    if (Objects.equals(hvac2State.get().getComponentState(), HVAC2State.OPEN.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_HAVC2_OPEN_REQ, 1);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_HAVC2_OPEN_REQ, 0);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.RB_HAVC2_OPEN_REQ_CAR,
        carIndex);
  }

  @FXML
  private void closeBtnHvac2FrontAction(ActionEvent event)
  {
    if (Objects.equals(hvac2State.get().getComponentState(), HVAC2State.CLOSED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_HVAC2_CLOSE_REQ, 1);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RB_HVAC2_CLOSE_REQ, 0);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.RB_HAVC2_CLOSE_REQ_CAR,
        carIndex);
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

  private void hvac1StatusUpdated()
  {

    if (Objects.equals(rbCommandScreenModel.hvac1StatusProperty(carIndex).get().getComponentState(),
        HVAC1State.OPEN.toString().toLowerCase()))
    {
      openBtnHvac1FrontProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
      closeBtnHvac1FrontProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
    }
    else
    {
      openBtnHvac1FrontProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
      closeBtnHvac1FrontProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }

  }

  private void hvac2StatusUpdated()
  {
    if (Objects.equals(rbCommandScreenModel.hvac2StatusProperty(carIndex).get().getComponentState(),
        HVAC2State.OPEN.toString().toLowerCase()))
    {
      openBtnHvac2FrontProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
      closeBtnHvac2FrontProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
    }
    else
    {
      openBtnHvac2FrontProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
      closeBtnHvac2FrontProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }

  

  }

  private void fducbStatusUpdated()
  {

    if (Objects.equals(rbCommandScreenModel.fdscbStatusProperty(carIndex).get().getComponentState(),
        FDUCBState.OPEN.toString().toLowerCase()))
    {
      openBtnFducbFrontProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
      closeBtnFducbFrontProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
    }
    else
    {
      openBtnFducbFrontProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
      closeBtnFducbFrontProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }

  }

  
}
