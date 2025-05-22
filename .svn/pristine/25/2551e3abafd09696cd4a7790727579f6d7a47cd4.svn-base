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
import com.sydac.mmrbem.tcms.fe.gui.binder.HighVoltageLeftTCarScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.HighVoltageMiddleTCarScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.HighVoltageRightTCarScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.HighVoltageScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageLeftTCarScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageMiddleTCarScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageRightTCarScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class HVSystemCommandScreenController extends AbstractTCMSController
{

  @FXML
  private HBox hvCommandsHBox;

  private static final String DM_FRONT_CAR_FXML_NAME = "HVCommandDmFrontCarPanel.fxml"; //$NON-NLS-1$

  private static final String T_CAR_FXML_NAME = "HVCommandTCarPanel.fxml"; //$NON-NLS-1$

  private static final String M_CAR_FXML_NAME = "HVCommandMCarPanel.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "HVCommandDmRearCarPanel.fxml"; //$NON-NLS-1$

  private static final String T_LEFT_CAR_FXML_NAME = "HVCommandTLeftCarPanel.fxml"; //$NON-NLS-1$

  private static final String T_RIGHT_CAR_FXML_NAME = "HVCommandTRightCarPanel.fxml"; //$NON-NLS-1$

  private static final String T_MIDDLE_CAR_FXML_NAME = "HVCommandTMiddleCarPanel.fxml"; //$NON-NLS-1$

  private HighVoltageScreenModel highVoltageScreenModel;

  private FooterPanelModel footerPanelModel;

  private ChangeListener<Number> screenChangeListener;
  
  private HighVoltageLeftTCarScreenModel highVoltageLeftTCarScreenModel;
  
  private  HighVoltageRightTCarScreenModel highVoltageRightTCarScreenModel;
  
  private  HighVoltageMiddleTCarScreenModel highVoltageMiddleTCarScreenModel;

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
    
    highVoltageLeftTCarScreenModel = new HighVoltageLeftTCarScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HighVoltageLeftTCarScreenBinder(highVoltageLeftTCarScreenModel));
    
    highVoltageRightTCarScreenModel = new HighVoltageRightTCarScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HighVoltageRightTCarScreenBinder(highVoltageRightTCarScreenModel));
    
    highVoltageMiddleTCarScreenModel = new HighVoltageMiddleTCarScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HighVoltageMiddleTCarScreenBinder(highVoltageMiddleTCarScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.HV_COMMANDS_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    hvCommandsHBox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    hvCommandsHBox.setSpacing(4);

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
        HVCommandDMFrontCarController dmCarController = new HVCommandDMFrontCarController(carConfig,
            highVoltageScreenModel);
        hvCommandsHBox.getChildren().add(dmCarController.createCar(DM_FRONT_CAR_FXML_NAME));
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        HVCommandDMRearCarController dmCarController = new HVCommandDMRearCarController(carConfig,
            highVoltageScreenModel);
        hvCommandsHBox.getChildren().add(dmCarController.createCar(DM_REAR_CAR_FXML_NAME));
      }
      else if (carType == CarType.M)
      {
        HVCommandMCarController carController = new HVCommandMCarController(carConfig,
            highVoltageScreenModel);
        hvCommandsHBox.getChildren().add(carController.createCar(M_CAR_FXML_NAME));
      }
      else if ((carType == CarType.T)
          && (carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
          && carConfig.carIndexProperty().get() == TCMSConstants.CAB_3)
      {

        HVCommandTMiddleCarController carController = new HVCommandTMiddleCarController(carConfig,
            highVoltageScreenModel, highVoltageMiddleTCarScreenModel);
        hvCommandsHBox.getChildren().add(carController.createCar(T_MIDDLE_CAR_FXML_NAME));
      }
      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        HVCommandTLeftCarController carController = new HVCommandTLeftCarController(carConfig,
            highVoltageScreenModel, highVoltageLeftTCarScreenModel);
        hvCommandsHBox.getChildren().add(carController.createCar(T_LEFT_CAR_FXML_NAME));
      }

      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        HVCommandTRightCarController carController = new HVCommandTRightCarController(carConfig,
            highVoltageScreenModel,highVoltageRightTCarScreenModel);
        hvCommandsHBox.getChildren().add(carController.createCar(T_RIGHT_CAR_FXML_NAME));
      }

    }
  }
}
