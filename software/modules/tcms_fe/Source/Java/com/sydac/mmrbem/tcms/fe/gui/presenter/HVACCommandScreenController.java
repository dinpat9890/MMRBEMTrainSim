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
import com.sydac.mmrbem.tcms.fe.gui.binder.HVACSystemStatusScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.PISSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HVACSystemStatusScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.PISSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.collections.ObservableMap;
import javafx.fxml.FXML;
import javafx.scene.layout.HBox;

public class HVACCommandScreenController extends AbstractTCMSController
{

  @FXML
  private HBox hvCommandsHBox;

  // private static final String CAR_FXML_NAME = "HVACCommandCar.fxml";
  // //$NON-NLS-1$

  private static final String DM_FRONT_CAR_FXML_NAME = "HVACCommandDMCar.fxml"; //$NON-NLS-1$



  private static final String M_LEFT_CAR_FXML_NAME = "HVACCommandMLeftCarPanelCar.fxml"; //$NON-NLS-1$

  private static final String M_RIGHT_CAR_FXML_NAME = "HVACCommandMRightCarPanel.fxml"; //$NON-NLS-1$

  private static final String M_MIDDLE_CAR_FXML_NAME = "HVACCommandMMiddleCarPanel.fxml"; //$NON-NLS-1$

  private static final String DM_REAR_CAR_FXML_NAME = "HVACCommandDmRearCarPanel.fxml"; //$NON-NLS-1$

  private static final String T_LEFT_CAR_FXML_NAME = "HVACCommandTLeftCarPanel.fxml"; //$NON-NLS-1$

  private static final String T_RIGHT_CAR_FXML_NAME = "HVACCommandTRightCarPanel.fxml"; //$NON-NLS-1$

  private static final String T_MIDDLE_CAR_FXML_NAME = "HVACCommandTMiddleCarPanel.fxml"; //$NON-NLS-1$

  private HVACSystemStatusScreenModel hvacSystemStatusScreenModel;

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
    hvacSystemStatusScreenModel = new HVACSystemStatusScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HVACSystemStatusScreenBinder(hvacSystemStatusScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.HVAC_COMMANDS_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    hvCommandsHBox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    hvCommandsHBox.setSpacing(5);

    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      Integer carIndex = carConfig.carIndexProperty().get();
      String carLblStr = carConfig.carTypeProperty().get().concat(carIndex.toString());
      CarType carType = CarType.valueByCarTypeCode(carConfig.carTypeProperty().get());

      if ((carType == CarType.DM) && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
      
        HVACCommandDMFrontCarController dmCarController = new HVACCommandDMFrontCarController(carConfig,
            hvacSystemStatusScreenModel, carLblStr, carIndex);
        hvCommandsHBox.getChildren().add(dmCarController.createCar(DM_FRONT_CAR_FXML_NAME));
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
     
        HVACCommandDMRearCarController dmCarController = new HVACCommandDMRearCarController(carConfig,
            hvacSystemStatusScreenModel, carLblStr, carIndex);
        hvCommandsHBox.getChildren().add(dmCarController.createCar(DM_REAR_CAR_FXML_NAME));
      }
      else if ((carType == CarType.M)
          && (carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
          && carConfig.carIndexProperty().get() == TCMSConstants.CAB_2)
      {
       
        HVACCommandMMiddleCarController carController = new HVACCommandMMiddleCarController(carConfig,
            hvacSystemStatusScreenModel, carLblStr, carIndex);
        hvCommandsHBox.getChildren().add(carController.createCar(M_MIDDLE_CAR_FXML_NAME));

      }
      else if ((carType == CarType.M)
          && (carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2)))
      {
     
        HVACCommandMLeftCarController carController = new HVACCommandMLeftCarController(carConfig,
            hvacSystemStatusScreenModel, carLblStr, carIndex);
        hvCommandsHBox.getChildren().add(carController.createCar(M_LEFT_CAR_FXML_NAME));

      }

      else if ((carType == CarType.M)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
     
        HVACCommandMRightCarController carController = new HVACCommandMRightCarController(carConfig,
            hvacSystemStatusScreenModel, carLblStr, carIndex);
        hvCommandsHBox.getChildren().add(carController.createCar(M_RIGHT_CAR_FXML_NAME));
      }
      else if ((carType == CarType.T)
          && (carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
          && carConfig.carIndexProperty().get() == TCMSConstants.CAB_3)
      {
       
        HVACCommandTMiddleCarController carController = new HVACCommandTMiddleCarController(carConfig,
            hvacSystemStatusScreenModel, carLblStr, carIndex);
        hvCommandsHBox.getChildren().add(carController.createCar(T_MIDDLE_CAR_FXML_NAME));
      }
      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
       
        HVACCommandTLeftCarController carController = new HVACCommandTLeftCarController(carConfig,
            hvacSystemStatusScreenModel, carLblStr, carIndex);
        hvCommandsHBox.getChildren().add(carController.createCar(T_LEFT_CAR_FXML_NAME));
      }

      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
       
        HVACCommandTRightCarController carController = new HVACCommandTRightCarController(carConfig,
            hvacSystemStatusScreenModel, carLblStr, carIndex);
        hvCommandsHBox.getChildren().add(carController.createCar(T_RIGHT_CAR_FXML_NAME));
      }

    }
  }

}
