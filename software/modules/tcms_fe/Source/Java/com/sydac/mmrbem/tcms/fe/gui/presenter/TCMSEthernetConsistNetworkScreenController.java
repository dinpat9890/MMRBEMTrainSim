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
import com.sydac.mmrbem.tcms.fe.gui.binder.TCMSEthernetConsistNetworkScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TCMSEthernetConsistNetworkScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class TCMSEthernetConsistNetworkScreenController extends AbstractTCMSController
{

  @FXML
  private HBox ecnHBox;

  private static final String DM_FRONT_CAR_FXML_NAME = "EthernetConsistNetworkDMFrontCar.fxml"; //$NON-NLS-1$

  private static final String T_CAR_M_CAR_FXML_NAME = "EthernetConsistNetworkTCarMCar.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "EthernetConsistNetworkDMRearCar.fxml"; //$NON-NLS-1$

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> screenChangeListener;

  private TCMSEthernetConsistNetworkScreenModel tcmsEthernetConsistNetworkScreenModel;

  @Override
  public void detachListeners()
  {
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }

  @Override
  public void initializeImpl()
  {
    tcmsEthernetConsistNetworkScreenModel = new TCMSEthernetConsistNetworkScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new TCMSEthernetConsistNetworkScreenBinder(tcmsEthernetConsistNetworkScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.TCMS_ECN_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    ecnHBox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    ecnHBox.setSpacing(0);

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
        TCMSEthernetConsistNetworkDMCarController dmCarController = new TCMSEthernetConsistNetworkDMCarController(
            tcmsEthernetConsistNetworkScreenModel, carConfig, carLblStr);
        ecnHBox.getChildren().add(dmCarController.createCar(DM_FRONT_CAR_FXML_NAME));
      }
      if ((carType == CarType.DM) && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        TCMSEthernetConsistNetworkDMCarController dmCarController = new TCMSEthernetConsistNetworkDMCarController(
            tcmsEthernetConsistNetworkScreenModel, carConfig, carLblStr);
        ecnHBox.getChildren().add(dmCarController.createCar(DM_REAR_CAR_FXML_NAME));
      }
      else if (carType == CarType.M || carType == CarType.T)
      {
        TCMSEthernetConsistNetworkTCarMCarController carController = new TCMSEthernetConsistNetworkTCarMCarController(
            tcmsEthernetConsistNetworkScreenModel, carConfig, carLblStr);
        ecnHBox.getChildren().add(carController.createCar(T_CAR_M_CAR_FXML_NAME));
      }
    }
  }
}
