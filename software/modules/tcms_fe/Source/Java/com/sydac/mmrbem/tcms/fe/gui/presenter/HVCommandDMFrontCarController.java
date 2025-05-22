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

public class HVCommandDMFrontCarController extends AbstractTCMSController
{

  @FXML
  private Button isolateCiBtn;

  private ObjectPropertyBase<CarComponentStatesDO> ciState;

  private HighVoltageScreenModel highVoltageScreenModel;
  
  private NodePseudoClassProperty isolateCiButtonProperty;
  
  private ChangeListener<Number> islolateListener;

  private int carIndex;

  public HVCommandDMFrontCarController(CarConfigurationModel carConfig,
      HighVoltageScreenModel highVoltageScreenModel)
  {
    this.highVoltageScreenModel = highVoltageScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
  }

  @Override
  public void initializeImpl()
  {
    
    isolateCiButtonProperty = new NodePseudoClassProperty(isolateCiBtn);
    ciState = highVoltageScreenModel.ciStatusProperty(carIndex);
    ciState.addListener(observable -> ciIsolateStateUpdate());
    ciIsolateStateUpdate();
    
    islolateListener = (observable, oldVal,
        newVal) -> updateIsolateCi(newVal.intValue());
    highVoltageScreenModel.getIsolateCiFrontCarState().addListener(islolateListener);

  }

  
  private void updateIsolateCi(int isolateState)
  {
    if (isolateState==1)
    {
      isolateCiButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      isolateCiButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
  }
  
  private void ciIsolateStateUpdate()
  {
    
    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      isolateCiBtn.setText(TCMSUIConstants.DE_ISOLATE_CI_TXT);
    }
    else
    {
      isolateCiBtn.setText(TCMSUIConstants.ISOLATE_CI_TXT);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void isolateCiButtonAction(ActionEvent event)
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
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.ISOLATE_CI_FRONT_CAR_REQ);
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
