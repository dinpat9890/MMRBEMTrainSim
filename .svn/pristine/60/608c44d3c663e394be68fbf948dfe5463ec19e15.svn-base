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
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.RbCommandScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.RbCommandScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class RemoteCBScreenController extends AbstractTCMSController
{

  @FXML
  private HBox remoteCbHBox;

  private static final String DM_CAR_FXML_NAME = "RBCommandDMCarPanel.fxml"; //$NON-NLS-1$

  private static final String T_CAR_FXML_NAME = "RBCommandTCarPanel.fxml"; //$NON-NLS-1$

  private static final String M_CAR_FXML_NAME = "RBCommandMCarPanel.fxml"; //$NON-NLS-1$

  private RbCommandScreenModel rbCommandScreenModel;

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
    rbCommandScreenModel = new RbCommandScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new RbCommandScreenBinder(rbCommandScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.REMOTE_CB_COMMANDS_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    remoteCbHBox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    remoteCbHBox.setSpacing(10);

    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      CarType carType = CarType.valueByCarTypeCode(carConfig.carTypeProperty().get());

      if ((carType == CarType.DM) && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        RBCommandDMCarController dmCarController = new RBCommandDMCarController(carConfig,
            rbCommandScreenModel);
        remoteCbHBox.getChildren().add(dmCarController.createCar(DM_CAR_FXML_NAME));
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        RBCommandDMCarController dmCarController = new RBCommandDMCarController(carConfig,
            rbCommandScreenModel);
        remoteCbHBox.getChildren().add(dmCarController.createCar(DM_CAR_FXML_NAME));
      }

      else if (carType == CarType.M
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        RBCommandMCarController mCarController = new RBCommandMCarController(carConfig, rbCommandScreenModel);
        remoteCbHBox.getChildren().add(mCarController.createCar(M_CAR_FXML_NAME));
      }
      else if (carType == CarType.M
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        
        RBCommandMCarController mCarController = new RBCommandMCarController(carConfig, rbCommandScreenModel);
        remoteCbHBox.getChildren().add(mCarController.createCar(M_CAR_FXML_NAME));
      }

      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        RBCommandTCarController dmCarController = new RBCommandTCarController(carConfig,
            rbCommandScreenModel);
        remoteCbHBox.getChildren().add(dmCarController.createCar(T_CAR_FXML_NAME));
      }

      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        RBCommandTCarController dmCarController = new RBCommandTCarController(carConfig,
            rbCommandScreenModel);
        remoteCbHBox.getChildren().add(dmCarController.createCar(T_CAR_FXML_NAME));
      }

    }
  }
}
