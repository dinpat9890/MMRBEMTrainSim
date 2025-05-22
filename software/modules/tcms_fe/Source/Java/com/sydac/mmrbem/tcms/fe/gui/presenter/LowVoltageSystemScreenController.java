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

import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.LowVoltageSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.MediumVoltageSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.LowVoltageScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.MediumVoltageSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class LowVoltageSystemScreenController extends AbstractTCMSController
{

  @FXML
  private HBox lvHbox;

  private static final String DM_FRONT_CAR_FXML_NAME = "LowVoltageDMFrontCar.fxml"; //$NON-NLS-1$

  private static final String T_CAR_FXML_NAME = "LowVoltageTCar.fxml"; //$NON-NLS-1$

  private static final String M_CAR_FXML_NAME = "LowVoltageMCar.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "LowVoltageDMRearCar.fxml"; //$NON-NLS-1$

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> screenChangeListener;

  private LowVoltageScreenModel lowVoltageScreenModel;

  private MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel;

  @Override
  public void detachListeners()
  {
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }

  @Override
  public void initializeImpl()
  {
    mediumVoltageSystemScreenModel = new MediumVoltageSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new MediumVoltageSystemScreenBinder(mediumVoltageSystemScreenModel));

    lowVoltageScreenModel = new LowVoltageScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new LowVoltageSystemScreenBinder(lowVoltageScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.LOW_VOLTAGE_SYSTEM_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    lvHbox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    lvHbox.setSpacing(0);

    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      CarType carType = CarType.valueByCarTypeCode(carConfig.carTypeProperty().get());
      Integer carIndex = carConfig.carIndexProperty().get() + 1;
      String carLblStr = carConfig.carTypeProperty().get().concat(carIndex.toString());

      if ((carType == CarType.DM) && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        LowVoltageCommonCarController dmCarController = new LowVoltageCommonCarController(carLblStr);
        lvHbox.getChildren().add(dmCarController.createCar(DM_FRONT_CAR_FXML_NAME));
      }
      if ((carType == CarType.DM) && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        LowVoltageCommonCarController dmCarController = new LowVoltageCommonCarController(carLblStr);
        lvHbox.getChildren().add(dmCarController.createCar(DM_REAR_CAR_FXML_NAME));
      }
      else if (carType == CarType.M)
      {
        LowVoltageMCarController carController = new LowVoltageMCarController(lowVoltageScreenModel,
            carConfig, carLblStr);
        lvHbox.getChildren().add(carController.createCar(M_CAR_FXML_NAME));
      }
      else if (carType == CarType.T)
      {
        LowVoltageTCarController carController = new LowVoltageTCarController(carLblStr, carConfig,
            mediumVoltageSystemScreenModel);
        lvHbox.getChildren().add(carController.createCar(T_CAR_FXML_NAME));
      }
    }
  }

  @FXML
  private void onLVCommandsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.LOW_VOLTAGE_SYSTEM_COMMAND_SCREEN, frontend);
  }

  @FXML
  private void onRBCommandsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.REMOTE_CB_COMMANDS_SCREEN, frontend);
  }
}
