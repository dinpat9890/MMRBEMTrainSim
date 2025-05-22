/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.TrainTopViewComponentStatusBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainTopViewComponentStatusModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;

public class DoorsSystemCommandsScreenController extends AbstractTCMSController
{

  @FXML
  private Button openDoorsBtn;

  @FXML
  private HBox isolatePanelHbox;

  public static final String DOORS_ISOLATE_PANEL_FXML = "DoorsIsolateCommandsPanel.fxml"; //$NON-NLS-1$

  private ChangeListener<Number> screenChangeListener;

  private FooterPanelModel footerPanelModel;

  private TrainTopViewComponentStatusModel carComponentStatusModel;

  @Override
  public void initializeImpl()
  {
    carComponentStatusModel = new TrainTopViewComponentStatusModel(scenarioCarIndex);
    tcmsScreenBinders.add(new TrainTopViewComponentStatusBinder(carComponentStatusModel));

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.DOORS_SYTEM_COMMANDS_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    isolatePanelHbox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    isolatePanelHbox.setSpacing(0);

    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      if (carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        DoorsIsolateCommandsPanelController isolatePanelController = new DoorsIsolateCommandsPanelController(
            carConfig, carComponentStatusModel);
        isolatePanelHbox.getChildren().add(isolatePanelController.createCar(DOORS_ISOLATE_PANEL_FXML));
      }
      else if (carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        DoorsIsolateCommandsPanelController2 isolatePanelController = new DoorsIsolateCommandsPanelController2(
            carConfig, carComponentStatusModel);
        isolatePanelHbox.getChildren().add(isolatePanelController.createCar(DOORS_ISOLATE_PANEL_FXML));
      }
    }
  }

  @Override
  public void detachListeners()
  {
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }
}