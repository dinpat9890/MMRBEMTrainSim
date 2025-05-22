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
import com.sydac.mmrbem.tcms.fe.gui.binder.HighVoltageScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;

public class HighVoltageSystemScreenController extends AbstractTCMSController
{

  @FXML
  private HBox hvHbox;

  @FXML
  private Button hvCommandsBtn;

  private static final String DM_FRONT_CAR_FXML_NAME = "HighVoltageDMFrontCar.fxml"; //$NON-NLS-1$

  private static final String T_CAR_FXML_NAME = "HighVoltageTCar.fxml"; //$NON-NLS-1$

  private static final String M_CAR_LEFT_FXML_NAME = "HighVoltageMLeftCar.fxml"; //$NON-NLS-1$

  private static final String M_CAR_RIGHT_FXML_NAME = "HighVoltageMRightCar.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "HighVoltageDMRearCar.fxml"; //$NON-NLS-1$

  private HighVoltageScreenModel highVoltageScreenModel;

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> screenChangeListener;

  @Override
  public void detachListeners()
  {
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }

  @Override
  public void initializeImpl()
  {
    highVoltageScreenModel = new HighVoltageScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HighVoltageScreenBinder(highVoltageScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.HIGH_VOLTAGE_SYSTEM_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    hvHbox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    hvHbox.setSpacing(0);

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
        HighVoltageDMCarController dmCarController = new HighVoltageDMCarController(carConfig,
            highVoltageScreenModel, carLblStr);
        hvHbox.getChildren().add(dmCarController.createCar(DM_FRONT_CAR_FXML_NAME));
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        HighVoltageDMCarController dmCarController = new HighVoltageDMCarController(carConfig,
            highVoltageScreenModel, carLblStr);
        hvHbox.getChildren().add(dmCarController.createCar(DM_REAR_CAR_FXML_NAME));
      }
      else if (carType == CarType.M
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        HighVoltageMCarController carController = new HighVoltageMCarController(carConfig,
            highVoltageScreenModel, carLblStr);
        hvHbox.getChildren().add(carController.createCar(M_CAR_LEFT_FXML_NAME));
      }
      else if (carType == CarType.M
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        HighVoltageMCarController carController = new HighVoltageMCarController(carConfig,
            highVoltageScreenModel, carLblStr);
        hvHbox.getChildren().add(carController.createCar(M_CAR_RIGHT_FXML_NAME));
      }
      else if (carType == CarType.T)
      {
        HighVoltageTCarController carController = new HighVoltageTCarController(carConfig,
            highVoltageScreenModel, carLblStr);
        hvHbox.getChildren().add(carController.createCar(T_CAR_FXML_NAME));
      }
    }
  }

  @FXML
  private void onHvCommandsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.HV_COMMANDS_SCREEN, frontend);
  }
}
