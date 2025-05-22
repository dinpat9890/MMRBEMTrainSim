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
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.TrainTopViewComponentStatusBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainTopViewComponentStatusModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class TrainTopViewPanelController extends AbstractTCMSController
{

  @FXML
  private HBox trainTopViewHBox;

  private static final String DM_FRONT_CAR_FXML_NAME = "TrainTopViewDMFrontCar.fxml"; //$NON-NLS-1$

  private static final String T_CAR_FXML_NAME = "TrainTopViewTCar.fxml"; //$NON-NLS-1$

  private static final String M_CAR_FXML_NAME = "TrainTopViewMCar.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "TrainTopViewDMRearCar.fxml"; //$NON-NLS-1$

  private TrainTopViewComponentStatusModel carComponentStatusModel;

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> currentScreenIdListener;

  @Override
  public void detachListeners()
  {
    footerPanelModel.getCurrentScreenId().removeListener(currentScreenIdListener);
  }

  @Override
  public void initializeImpl()
  {
    carComponentStatusModel = new TrainTopViewComponentStatusModel(scenarioCarIndex);
    tcmsScreenBinders.add(new TrainTopViewComponentStatusBinder(carComponentStatusModel));
    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    currentScreenIdListener = ((observable, oldVal, newVal) -> updatePanelSize(newVal.intValue()));
    footerPanelModel.getCurrentScreenId().addListener(currentScreenIdListener);
  }

  private void updatePanelSize(int screenId)
  {
    if (ScreenId.valueOf(screenId).getId() == (ScreenId.OPERATING_SCREEN).getId())
    {
      buildTrainConfig(TCMSUIConstants.OPERATING_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
    }
    else
    {
      buildTrainConfig(TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
    }

  }

  private void buildTrainConfig(int carPanelSize)
  {
    trainTopViewHBox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    trainTopViewHBox.setSpacing(0);

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
        TrainTopViewDMCarController driverCabController = new TrainTopViewDMCarController(carConfig,
            carComponentStatusModel, footerPanelModel);
        trainTopViewHBox.getChildren()
            .add(driverCabController.createCar(DM_FRONT_CAR_FXML_NAME, carPanelSize));
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        TrainTopViewDMCarController carController = new TrainTopViewDMCarController(carConfig,
            carComponentStatusModel, footerPanelModel);
        trainTopViewHBox.getChildren().add(carController.createCar(DM_REAR_CAR_FXML_NAME, carPanelSize));
      }
      else if (carType == CarType.M)
      {
        TrainTopViewMCarController carController = new TrainTopViewMCarController(carConfig,
            carComponentStatusModel, footerPanelModel);
        trainTopViewHBox.getChildren().add(carController.createCar(M_CAR_FXML_NAME, carPanelSize));
      }
      else if (carType == CarType.T)
      {
        TrainTopViewTCarController carController = new TrainTopViewTCarController(carConfig,
            carComponentStatusModel, footerPanelModel);
        trainTopViewHBox.getChildren().add(carController.createCar(T_CAR_FXML_NAME, carPanelSize));
      }
    }
  }
}
