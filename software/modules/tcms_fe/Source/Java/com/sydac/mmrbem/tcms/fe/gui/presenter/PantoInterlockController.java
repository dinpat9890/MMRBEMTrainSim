/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.PantographInterlockScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.PantographInterlockScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;

public class PantoInterlockController extends AbstractTCMSController
{
  private static final String PANTO = "PANTO"; //$NON-NLS-1$

  @FXML
  private Label carLbl;

  private PantographInterlockScreenModel pantographInterlockScreenModel;

  @FXML
  private HBox lvHbox;

  private static final String T_CAR_FXML_NAME = "PantoInterlockTCar.fxml"; //$NON-NLS-1$

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
    pantographInterlockScreenModel = new PantographInterlockScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new PantographInterlockScreenBinder(pantographInterlockScreenModel));
    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.PANTO_INTERLOCK_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    lvHbox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);
    if (trainConfigurationModel.totalCarsProperty().get() == ApplicationConstants.SIX_CAR_CONFIG)
    {
      lvHbox.setSpacing(250);
    }
    else if (trainConfigurationModel.totalCarsProperty().get() == ApplicationConstants.EIGHT_CAR_CONFIG)
    {
      lvHbox.setSpacing(60);
    }
    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      CarType carType = CarType.valueByCarTypeCode(carConfig.carTypeProperty().get());
      Integer carIndex = carConfig.carIndexProperty().get() + 1;
      String carLblStr = PANTO + " " + carConfig.carTypeProperty().get().concat(carIndex.toString()); //$NON-NLS-1$

      if (carType == CarType.T)
      {
        PantoInterlockTCarController carController = new PantoInterlockTCarController(carConfig,
            pantographInterlockScreenModel, carLblStr);
        lvHbox.getChildren().add(carController.createCar(T_CAR_FXML_NAME));
      }
    }
  }

}
