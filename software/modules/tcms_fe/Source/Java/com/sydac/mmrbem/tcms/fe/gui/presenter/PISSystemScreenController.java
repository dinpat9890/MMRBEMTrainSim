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

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.PISSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.PISSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;

public class PISSystemScreenController extends AbstractTCMSController
{

  @FXML
  private HBox hvCommandsHBox;
  
  @FXML
  @CommsNumber(VDUInputs.PABR_BYPASS_BUTTON)
  private Button bypassBtn;

  private static final String CAR_FXML_NAME1 = "PisSystemCar.fxml"; //$NON-NLS-1$
  


  private PISSystemScreenModel pisSystemScreenModel;

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
    pisSystemScreenModel = new PISSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new PISSystemScreenBinder(pisSystemScreenModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.PIS_SYSTEM_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
   
    hvCommandsHBox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    hvCommandsHBox.setSpacing(20);

    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      
      Integer carIndex = carConfig.carIndexProperty().get() +1;
      String carLblStr = carConfig.carTypeProperty().get().concat(carIndex.toString());
      CarType carType = CarType.valueByCarTypeCode(carConfig.carTypeProperty().get());
      
      PISSystemCarController carController = new PISSystemCarController(carConfig, pisSystemScreenModel,
          carLblStr, carIndex);
      hvCommandsHBox.getChildren().add(carController.createCar(CAR_FXML_NAME1)); 
      


    }
  }
  
  @FXML
  public void onBypassBtnAction(ActionEvent event)
  {
  
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.PABR_BYPASS_REQ_BUTTON);
   
  }

}
