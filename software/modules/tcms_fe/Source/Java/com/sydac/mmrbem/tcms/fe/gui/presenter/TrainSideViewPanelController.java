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
import com.sydac.mmrbem.tcms.fe.gui.binder.TrainSideViewComponentStatusBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainSideViewComponentStatusModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class TrainSideViewPanelController extends AbstractTCMSController
{

  @FXML
  private HBox trainSideViewHBox;

  private static final String DM_FRONT_CAR_FXML_NAME = "TrainSideViewDMFrontCar.fxml"; //$NON-NLS-1$

  private static final String T_CAR_FXML_NAME = "TrainSideViewTCar.fxml"; //$NON-NLS-1$

  private static final String M_CAR_FXML_NAME = "TrainSideViewMCar.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "TrainSideViewDMRearCar.fxml"; //$NON-NLS-1$

  private TrainSideViewComponentStatusModel carComponentStatusModel;

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> currentScreenIdListener;

  @Override
  public void initializeImpl()
  {
    carComponentStatusModel = new TrainSideViewComponentStatusModel(scenarioCarIndex);
    tcmsScreenBinders.add(new TrainSideViewComponentStatusBinder(carComponentStatusModel));
    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    currentScreenIdListener = ((observable, oldVal, newVal) -> updatePanelSize(newVal.intValue()));
    footerPanelModel.getCurrentScreenId().addListener(currentScreenIdListener);
  }

  private void updatePanelSize(int screenId)
  {
    if (ScreenId.valueOf(screenId).getId() == (ScreenId.OPERATING_SCREEN).getId())
    {
      buildTrainConfig(TCMSUIConstants.OPERATING_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE);
    }
    else
    {
      buildTrainConfig(TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE);
    }

  }

  private void buildTrainConfig(int carPanelSize)
  {
    trainSideViewHBox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    trainSideViewHBox.setSpacing(5);

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
        TrainSideViewDMCarController driverCabController = new TrainSideViewDMCarController(carConfig,
            carComponentStatusModel);
        trainSideViewHBox.getChildren()
            .add(driverCabController.createCar(DM_FRONT_CAR_FXML_NAME, carPanelSize));
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        TrainSideViewDMCarController carController = new TrainSideViewDMCarController(carConfig,
            carComponentStatusModel);
        trainSideViewHBox.getChildren().add(carController.createCar(DM_REAR_CAR_FXML_NAME, carPanelSize));
      }
      else if (carType == CarType.M)
      {
        TrainSideViewMCarController carController = new TrainSideViewMCarController(carConfig,
            carComponentStatusModel);
        trainSideViewHBox.getChildren().add(carController.createCar(M_CAR_FXML_NAME, carPanelSize));
      }
      else if (carType == CarType.T)
      {
        TrainSideViewTCarController carController = new TrainSideViewTCarController(carConfig,
            carComponentStatusModel);
        trainSideViewHBox.getChildren().add(carController.createCar(T_CAR_FXML_NAME, carPanelSize));
      }
    }
  }

  @Override
  public void detachListeners()
  {
    // To detach listeners
  }
}
