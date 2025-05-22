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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CIStatusList.CIState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
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

public class HVCommandMCarController extends AbstractTCMSController
{

  @FXML
  private Button isolateCiBtnM1;

  @FXML
  private Button isolateCiBtnM2;

  @FXML
  private Button isolateCiBtnM3;

  private ObjectPropertyBase<CarComponentStatesDO> ciState;

  private HighVoltageScreenModel highVoltageScreenModel;
  
  private NodePseudoClassProperty isolateCiM1ButtonProperty;
  
  private NodePseudoClassProperty isolateCiM2ButtonProperty;
  
  private NodePseudoClassProperty isolateCiM3ButtonProperty;
  


  private int carIndex;

  public HVCommandMCarController(CarConfigurationModel carConfig,
      HighVoltageScreenModel highVoltageScreenModel)
  {
    this.highVoltageScreenModel = highVoltageScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
  }

  @Override
  public void initializeImpl()
  {
    isolateCiM1ButtonProperty = new NodePseudoClassProperty(isolateCiBtnM1);
    isolateCiM2ButtonProperty = new NodePseudoClassProperty(isolateCiBtnM2);
    isolateCiM3ButtonProperty = new NodePseudoClassProperty(isolateCiBtnM3);
    setButtonVisibility();

    ChangeListener<Number>    islolateM1Listener = (observable, oldVal,
        newVal) -> updateM1(newVal.intValue());
    highVoltageScreenModel.getIsolateM1State().addListener(islolateM1Listener);
    
    ChangeListener<Number>   islolateM2Listener = (observable, oldVal,
        newVal) -> updateM2(newVal.intValue());
    highVoltageScreenModel.getIsolateM2State().addListener(islolateM2Listener);
    
    ChangeListener<Number>   islolateM3Listener = (observable, oldVal,
        newVal) -> updateM3(newVal.intValue());
    highVoltageScreenModel.getIsolateM3State().addListener(islolateM3Listener);
    
    
    ciState = highVoltageScreenModel.ciStatusProperty(carIndex);

    ciState.addListener(observable -> {

      if (carIndex == TCMSConstants.CAB_2)
      {
        ciIsolateM1StateUpdate();

      }
      else if (carIndex == TCMSConstants.CAB_3 || carIndex == TCMSConstants.CAB_5)
      {
        ciIsolateM3StateUpdate();
      }
      else if (carIndex == TCMSConstants.CAB_4)
      {
        ciIsolateM2StateUpdate();

      }

    });
    ciIsolateM1StateUpdate();
    ciIsolateM2StateUpdate();
    ciIsolateM3StateUpdate();
  }

  private void updateM1(int isolateState)
  {

    if (isolateState==1)
    {
      isolateCiM1ButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      isolateCiM1ButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
  
  }
  
  private void updateM2(int isolateState)
  {

    if (isolateState==1)
    {
      isolateCiM2ButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      isolateCiM2ButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
  
  }
  
  private void updateM3(int isolateState)
  {

    if (isolateState==1)
    {
      isolateCiM3ButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      isolateCiM3ButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
  
  }

  private void setButtonVisibility()
  {
    if (carIndex == TCMSConstants.CAB_2)
    {
      isolateCiBtnM1.setVisible(true);
      isolateCiBtnM2.setVisible(false);
      isolateCiBtnM3.setVisible(false);
    }
    else if (carIndex == TCMSConstants.CAB_3 || carIndex == TCMSConstants.CAB_5)
    {
      isolateCiBtnM3.setVisible(true);
      isolateCiBtnM1.setVisible(false);
      isolateCiBtnM2.setVisible(false);
    }
    else if (carIndex == TCMSConstants.CAB_4)
    {
      isolateCiBtnM3.setVisible(false);
      isolateCiBtnM1.setVisible(false);
      isolateCiBtnM2.setVisible(true);
    }
  }

  private void ciIsolateM1StateUpdate()
  {
    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      isolateCiBtnM1.setText(TCMSUIConstants.DE_ISOLATE_CI_TXT);
    }
    else
    {
      isolateCiBtnM1.setText(TCMSUIConstants.ISOLATE_CI_TXT);
    }
  }

  private void ciIsolateM2StateUpdate()
  {
    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      isolateCiBtnM2.setText(TCMSUIConstants.DE_ISOLATE_CI_TXT);
    }
    else
    {
      isolateCiBtnM2.setText(TCMSUIConstants.ISOLATE_CI_TXT);
    }
  }

  private void ciIsolateM3StateUpdate()
  {
    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      isolateCiBtnM3.setText(TCMSUIConstants.DE_ISOLATE_CI_TXT);
    }
    else
    {
      isolateCiBtnM3.setText(TCMSUIConstants.ISOLATE_CI_TXT);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void isolateCiM1ButtonAction(ActionEvent event)
  {
    
    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_CI_REQ, 0);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_CI_REQ, 1);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.ISOLATE_CI_REQ_CAR,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.ISOLATE_CI_M1_REQ);
      
  }

  @FXML
  private void isolateCiM2ButtonAction(ActionEvent event)
  {
   

    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_CI_REQ, 0);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_CI_REQ, 1);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.ISOLATE_CI_REQ_CAR,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.ISOLATE_CI_M2_REQ);
  }

  @FXML
  private void isolateCiM3ButtonAction(ActionEvent event)
  {
  
    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_CI_REQ, 0);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_CI_REQ, 1);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.ISOLATE_CI_REQ_CAR,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.ISOLATE_CI_M3_REQ);
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
