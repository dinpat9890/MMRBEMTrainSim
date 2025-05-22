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
import com.sydac.mmrbem.tcms.fe.gui.binder.TCMSStatusScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TCMSStatusScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class TCMSStatusScreenController extends AbstractTCMSController
{

  @FXML
  private HBox systemHbox;

  private static final String DM_FRONT_CAR_FXML_NAME = "SystemStatusDMFrontCar.fxml"; //$NON-NLS-1$

  private static final String MIDDLE_CAR_FXML_NAME = "SystemStatusMiddleCar.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "SystemStatusDMRearCar.fxml"; //$NON-NLS-1$

  private FooterPanelModel footerPanelModel;

  private TCMSStatusScreenModel tcmsStatusScreenModel;

  private ChangeListener<Number> screenChangeListener;

  @Override
  public void detachListeners()
  {
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }

  @Override
  public void initializeImpl()
  {
    tcmsStatusScreenModel = new TCMSStatusScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new TCMSStatusScreenBinder(tcmsStatusScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateSystemStatus(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateSystemStatus(int screenId)
  {
    if (ScreenId.SYSTEM_STATUS_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    systemHbox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    systemHbox.setSpacing(0);

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
        TCMSStatusDMCarController dmCarController = new TCMSStatusDMCarController(tcmsStatusScreenModel,
            carConfig, carLblStr);
        systemHbox.getChildren().add(dmCarController.createCar(DM_FRONT_CAR_FXML_NAME));
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        TCMSStatusDMCarController dmCarController = new TCMSStatusDMCarController(tcmsStatusScreenModel,
            carConfig, carLblStr);
        systemHbox.getChildren().add(dmCarController.createCar(DM_REAR_CAR_FXML_NAME));
      }
      else
      {
        TCMSStatusTCarMCarController carController = new TCMSStatusTCarMCarController(tcmsStatusScreenModel,
            carConfig, carLblStr);
        systemHbox.getChildren().add(carController.createCar(MIDDLE_CAR_FXML_NAME));
      }

    }
  }

}
