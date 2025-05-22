/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.DOOR_COMMANDS_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.DoorSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.DoorSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;

public class DoorSystemScreenController extends AbstractTCMSController
{
  private static final String CAR_DCU_STATUS_FXML = "CarDCUStatus.fxml"; //$NON-NLS-1$

  @FXML
  @CommsNumber(DOOR_COMMANDS_BUTTON)
  private Button doorCommandsBtn;

  @FXML
  private HBox carDcuStatusHBox;

  private DoorSystemScreenModel doorSystemScreenModel;

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
    doorSystemScreenModel = new DoorSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new DoorSystemScreenBinder(doorSystemScreenModel));
    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    currentScreenIdListener = ((observable, oldVal, newVal) -> {
      if (ScreenId.valueOf(newVal.intValue()).getId() == (ScreenId.DOOR_SYSTEM_SCREEN).getId())
      {
        buildCarDCUStatus();
      }
    });
    footerPanelModel.getCurrentScreenId().addListener(currentScreenIdListener);
  }

  private void buildCarDCUStatus()
  {
    carDcuStatusHBox.getChildren().clear();
    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    carDcuStatusHBox.setSpacing(0);

    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      CarDCUStatusController carDcuStatusController = new CarDCUStatusController(carConfig,
          doorSystemScreenModel);
      carDcuStatusHBox.getChildren().add(carDcuStatusController.createCar(CAR_DCU_STATUS_FXML));
    }
  }

  @FXML
  private void onDoorSystemCommandsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.DOORS_SYTEM_COMMANDS_SCREEN, frontend);
  }
}
