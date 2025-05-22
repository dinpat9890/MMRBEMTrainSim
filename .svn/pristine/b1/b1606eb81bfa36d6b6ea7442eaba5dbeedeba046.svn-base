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

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVACOperationModeStatusList.HVACOperatingState;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HVACSystemStatusScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.property.ObjectPropertyBase;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class HVACCommandMLeftCarController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(VDUInputs.RESET_HVAC1_BUTTON)
  private Button resetHvac1Btn;

  @FXML
  @CommsNumber(VDUInputs.RESET_HVAC2_BUTTON)
  private Button resetHvac2Btn;

  @FXML
  @CommsNumber(VDUInputs.ISOLATE_HVAC1_BUTTON)
  private Button isolateHvac1Btn;

  @FXML
  @CommsNumber(VDUInputs.ISOLATE_HVAC2_BUTTON)
  private Button isolateHvac2Btn;

  @FXML
  @CommsNumber(VDUInputs.RESET_SMOKE_BUTTON)
  private Button resetSmokeBtn;

  private int carIndex = 0;

  private CarConfigurationModel carConfig;

  private HVACSystemStatusScreenModel hvacSystemStatusScreenModel;

  private static final String ISOLATE_TEXT = "ISOLATE"; //$NON-NLS-1$

  private static final String DE_ISOLATE_TEXT = "DE-ISOLATE"; //$NON-NLS-1$

  private ObjectPropertyBase<CarComponentStatesDO> havac1State;

  private ObjectPropertyBase<CarComponentStatesDO> havac2State;

  public HVACCommandMLeftCarController(CarConfigurationModel carConfig,
      HVACSystemStatusScreenModel hvacSystemStatusScreenModel, String carLabel, int index)
  {
    this.hvacSystemStatusScreenModel = hvacSystemStatusScreenModel;
    this.carIndex = index;
    this.carConfig = carConfig;
  }

  @Override
  public void initializeImpl()
  {

    havac1State = hvacSystemStatusScreenModel.hvac1IsolateStatusProperty(carIndex);
    havac1State.addListener(observable -> updateIsolateHvac1ButtonText());

    updateIsolateHvac1ButtonText();

    havac2State = hvacSystemStatusScreenModel.hvac2IsolateStatusProperty(carIndex);
    havac2State.addListener(observable -> updateIsolateHvac2ButtonText());

    updateIsolateHvac2ButtonText();
  }

  @Override
  public void detachListeners()
  {

  }

  @FXML
  void resetHvac1BtnAction(ActionEvent event)
  {

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RESET_HVAC1_CAR_REQ,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.RESET_HVAC1_REQ);

  }

  @FXML
  void resetHvac2BtnAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RESET_HVAC2_CAR_REQ,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.RESET_HVAC2_REQ);

  }

  @FXML
  void isolateHvac1BtnAction(ActionEvent event)
  {

    if (Objects.equals(havac1State.get().getComponentState(),
        HVACOperatingState.HVAC_OPERATING_ISOLATED.toString()))
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_HVAC1_CAR4_REQ,
          TCMSUIConstants.REINSERT_VALUE);
    }
    else
    {

      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_HVAC1_CAR4_REQ,
          TCMSUIConstants.ISOLATE_VALUE);
    }

  }

  @FXML
  void isolateHvac2BtnAction(ActionEvent event)
  {

    if (Objects.equals(havac2State.get().getComponentState(),
        HVACOperatingState.HVAC_OPERATING_ISOLATED.toString()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_HVAC2_CAR4_REQ,
          TCMSUIConstants.REINSERT_VALUE);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_HVAC2_CAR4_REQ,
          TCMSUIConstants.ISOLATE_VALUE);
    }

  }

  @FXML
  void resetSmokeBtnAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.RESET_SMOKE_CAR_REQ,
        carIndex);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.RESET_SMOKE_REQ);
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

  private void updateIsolateHvac1ButtonText()
  {

    if (Objects.equals(havac1State.get().getComponentState(),
        HVACOperatingState.HVAC_OPERATING_ISOLATED.toString()))
    {
      isolateHvac1Btn.setText(DE_ISOLATE_TEXT);

    }
    else
    {
      isolateHvac1Btn.setText(ISOLATE_TEXT);
    }

  }

  private void updateIsolateHvac2ButtonText()
  {

    if (Objects.equals(havac2State.get().getComponentState(),
        HVACOperatingState.HVAC_OPERATING_ISOLATED.toString()))
    {
      isolateHvac2Btn.setText(DE_ISOLATE_TEXT);

    }
    else
    {
      isolateHvac2Btn.setText(ISOLATE_TEXT);
    }

  }

}
