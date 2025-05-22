/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.common.state.CarTypeName;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.VcbInterlockScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.VcbInterlockScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;

public class VcbInterlockController extends AbstractTCMSController
{
  private static final String VCB = "VCB"; //$NON-NLS-1$

  @FXML
  private Label carLbl;

  private VcbInterlockScreenModel vcbInterlockScreenModel;

  @FXML
  private HBox lvHbox;

  private static final String T_CAR_FXML_NAME = "VcbInterlockTCar.fxml"; //$NON-NLS-1$

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> screenChangeListener;

  private String dmCarLbl = ApplicationConstants.BLANK;

  private String mCarLbl = ApplicationConstants.BLANK;

  @Override
  public void detachListeners()
  {
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }

  @Override
  public void initializeImpl()
  {
    vcbInterlockScreenModel = new VcbInterlockScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new VcbInterlockScreenBinder(vcbInterlockScreenModel));
    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.VCB_INTERLOCK_SCREEN.getId() == screenId)
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
      lvHbox.setSpacing(30);
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
      String carLblStr = carConfig.carTypeProperty().get().concat(carIndex.toString());
      String headerLblStr = VCB + " " + carLblStr; //$NON-NLS-1$

      if (trainConfigurationModel.totalCarsProperty().get() == ApplicationConstants.SIX_CAR_CONFIG)
      {
        sixCarData(carLblStr);
      }
      else
      {
        eightCarData(carLblStr);
      }
      if (carType == CarType.T)
      {
        VcbInterlockTCarController carController = new VcbInterlockTCarController(carConfig,
            vcbInterlockScreenModel, headerLblStr, dmCarLbl, mCarLbl, carLblStr);
        lvHbox.getChildren().add(carController.createCar(T_CAR_FXML_NAME));
      }
    }
  }

  private void eightCarData(String carLblStr)
  {
    if (carLblStr.equals(CarTypeName.EIGHT_CAR_T2.getCarTypeCode()))
    {
      dmCarLbl = CarTypeName.EIGHT_CAR_T2.getDmCarDisplayName();
      mCarLbl = CarTypeName.EIGHT_CAR_T2.getMCarDisplayName();

    }
    else if (carLblStr.equals(CarTypeName.EIGHT_CAR_T4.getCarTypeCode()))
    {
      dmCarLbl = CarTypeName.EIGHT_CAR_T4.getDmCarDisplayName();
      mCarLbl = CarTypeName.EIGHT_CAR_T4.getMCarDisplayName();

    }
    else if (carLblStr.equals(CarTypeName.EIGHT_CAR_T7.getCarTypeCode()))
    {
      dmCarLbl = CarTypeName.EIGHT_CAR_T7.getDmCarDisplayName();
      mCarLbl = CarTypeName.EIGHT_CAR_T7.getMCarDisplayName();

    }
  }

  private void sixCarData(String carLblStr)
  {
    if (carLblStr.equals(CarTypeName.SIX_CAR_T2.getCarTypeCode()))
    {
      dmCarLbl = CarTypeName.SIX_CAR_T2.getDmCarDisplayName();
      mCarLbl = CarTypeName.SIX_CAR_T2.getMCarDisplayName();
    }
    else if (carLblStr.equals(CarTypeName.SIX_CAR_T5.getCarTypeCode()))
    {
      dmCarLbl = CarTypeName.SIX_CAR_T5.getDmCarDisplayName();
      mCarLbl = CarTypeName.SIX_CAR_T5.getMCarDisplayName();
    }
  }

}
