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
import com.sydac.mmrbem.tcms.fe.gui.binder.MediumVoltageSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.MediumVoltageSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class MediumVoltageSystemScreenController extends AbstractTCMSController
{

  @FXML
  private HBox mvHbox;

  private static final String DM_FRONT_CAR_FXML_NAME = "MediumVoltageSystemDMFront.fxml"; //$NON-NLS-1$

  private static final String T_FRONT_CAR_FXML_NAME = "MediumVoltageSystemTFront.fxml"; //$NON-NLS-1$

  private static final String T_REAR_CAR_FXML_NAME = "MediumVoltageSystemTRear.fxml"; //$NON-NLS-1$

  private static final String M_FRONT_CAR_FXML_NAME = "MediumVoltageSystemMFront.fxml"; //$NON-NLS-1$

  private static final String M_REAR_CAR_FXML_NAME = "MediumVoltageSystemMRear.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "MediumVoltageSystemDMRear.fxml"; //$NON-NLS-1$

  private MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel;

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
    mediumVoltageSystemScreenModel = new MediumVoltageSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new MediumVoltageSystemScreenBinder(mediumVoltageSystemScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.MEDIUM_VOLTAGE_SYSTEM_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    mvHbox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    mvHbox.setSpacing(0);

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
        MediumVoltageSystemDMCarController dmCarController = new MediumVoltageSystemDMCarController(carConfig,
            mediumVoltageSystemScreenModel, carLblStr);
        mvHbox.getChildren().add(dmCarController.createCar(DM_FRONT_CAR_FXML_NAME));
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        MediumVoltageSystemDMCarController dmCarController = new MediumVoltageSystemDMCarController(carConfig,
            mediumVoltageSystemScreenModel, carLblStr);
        mvHbox.getChildren().add(dmCarController.createCar(DM_REAR_CAR_FXML_NAME));
      }
      else if (carType == CarType.M
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        MediumVoltageSystemMCarController carController = new MediumVoltageSystemMCarController(carConfig,
            mediumVoltageSystemScreenModel, carLblStr);
        mvHbox.getChildren().add(carController.createCar(M_FRONT_CAR_FXML_NAME));
      }
      else if (carType == CarType.M
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        MediumVoltageSystemMCarController carController = new MediumVoltageSystemMCarController(carConfig,
            mediumVoltageSystemScreenModel, carLblStr);
        mvHbox.getChildren().add(carController.createCar(M_REAR_CAR_FXML_NAME));
      }
      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        MediumVoltageSystemTCarController carController = new MediumVoltageSystemTCarController(carConfig,
            mediumVoltageSystemScreenModel, carLblStr);
        mvHbox.getChildren().add(carController.createCar(T_FRONT_CAR_FXML_NAME));
      }
      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        MediumVoltageSystemTCarController carController = new MediumVoltageSystemTCarController(carConfig,
            mediumVoltageSystemScreenModel, carLblStr);
        mvHbox.getChildren().add(carController.createCar(T_REAR_CAR_FXML_NAME));
      }
    }
  }

  @FXML
  void onCmdBtnAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.MEDIUM_VOLTAGE_COMMANDS_SCREEN, frontend);
  }
}
