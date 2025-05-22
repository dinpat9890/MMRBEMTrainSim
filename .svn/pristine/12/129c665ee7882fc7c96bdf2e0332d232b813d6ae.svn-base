/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.BrakeSystemCommandsScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.TrainSideViewComponentStatusBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.BrakeSystemCommandsScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainSideViewComponentStatusModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableView;
import javafx.scene.layout.HBox;

public class BrakeSystemCommandsScreenController extends AbstractTCMSController
{

  @FXML
  private TableView<StatusTableDO> parkingbrakeStatusTable;

  @FXML
  private Button reqParkingBrakeAppliedBtn;

  @FXML
  private Button reqParkingBrakeRelease;

  @FXML
  private Button reqParkingBrakeBypass;

  @FXML
  private HBox isolatePanelHbox;

  public static final String BRAKE_ISOLATE_PANEL_FXML = "BrakeCommandsIsolatePanel.fxml"; //$NON-NLS-1$
  
  public static final String BRAKE_ISOLATE_PANEL_21_FXML = "BrakeCommandsIsolatePanel21_Orientation.fxml"; //$NON-NLS-1$

  private ChangeListener<Number> totalColumnListener;

  private ChangeListener<Number> screenChangeListener;

  private NodePseudoClassProperty parkBrakeAppliedButtonProperty;

  private NodePseudoClassProperty parkBrakeReleaseButtonProperty;

  private NodePseudoClassProperty parkBrakeBypassButtonProperty;

  private BrakeSystemCommandsScreenModel brakeSystemCommandsScreenModel;

  private TrainSideViewComponentStatusModel carComponentStatusModel;

  private FooterPanelModel footerPanelModel;

  private ScheduledExecutorService scheduledExecutorService = Executors.newSingleThreadScheduledExecutor();

  @Override
  public void initializeImpl()
  {
    brakeSystemCommandsScreenModel = new BrakeSystemCommandsScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new BrakeSystemCommandsScreenBinder(brakeSystemCommandsScreenModel));

    carComponentStatusModel = new TrainSideViewComponentStatusModel(scenarioCarIndex);
    tcmsScreenBinders.add(new TrainSideViewComponentStatusBinder(carComponentStatusModel));

    parkingbrakeStatusTable.setItems(brakeSystemCommandsScreenModel.getParkingBrakeStatusTableDataList());
    parkingbrakeStatusTable.setVisible(false);

    createTableRenderer(brakeSystemCommandsScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    brakeSystemCommandsScreenModel.getTotalColumn().addListener(totalColumnListener);

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);

    parkBrakeAppliedButtonProperty = new NodePseudoClassProperty(reqParkingBrakeAppliedBtn);
    parkBrakeReleaseButtonProperty = new NodePseudoClassProperty(reqParkingBrakeRelease);
    parkBrakeBypassButtonProperty = new NodePseudoClassProperty(reqParkingBrakeBypass);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(parkingbrakeStatusTable, noOfCars,
          TCMSUIConstants.BRAKE_COMMANDS_PRKG_BRK_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.BRAKE_SCREEN_TABEL_COLUMN_WIDTH);
      parkingbrakeStatusTable.setVisible(true);
    }
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.BRAKE_SYSTEM_COMMANDS_SCREEN.getId() == screenId)
    {
      buildTrainConfig();
    }
  }

  private void buildTrainConfig()
  {
    isolatePanelHbox.getChildren().clear();

    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    isolatePanelHbox.setSpacing(2);

    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      
      
      if (carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        BrakeSystemCommandsIsolatePanelController isolatePanelController = new BrakeSystemCommandsIsolatePanelController(
            carConfig, carComponentStatusModel);
        isolatePanelHbox.getChildren().add(isolatePanelController.createCar(BRAKE_ISOLATE_PANEL_FXML));
      }
      else if (carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        BrakeSystemCommandsIsolatePanelController2 isolatePanelController = new BrakeSystemCommandsIsolatePanelController2(
            carConfig, carComponentStatusModel);
        isolatePanelHbox.getChildren().add(isolatePanelController.createCar(BRAKE_ISOLATE_PANEL_21_FXML));
      }
    }
  }

  @Override
  public void detachListeners()
  {
    brakeSystemCommandsScreenModel.getTotalColumn().removeListener(totalColumnListener);
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }

  @FXML
  private void onParkingBrakeReqButtonAction(ActionEvent event)
  {
    if (event.getSource().equals(reqParkingBrakeAppliedBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(VDUInputs.PRKNG_BRAKE_APPLIED_REQ);
      parkBrakeAppliedButtonProperty.set(TCMSUIConstants.PARK_BRAKE_PRESSED_CSS);
      scheduledExecutorService.schedule(
          () -> parkBrakeAppliedButtonProperty.set(TCMSUIConstants.PARK_BRAKE_DEFAULT_CSS), 1000,
          TimeUnit.MILLISECONDS);
    }
    else if (event.getSource().equals(reqParkingBrakeRelease))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(VDUInputs.PRKNG_BRAKE_RELEASE_REQ);
      parkBrakeReleaseButtonProperty.set(TCMSUIConstants.PARK_BRAKE_PRESSED_CSS);
      scheduledExecutorService.schedule(
          () -> parkBrakeReleaseButtonProperty.set(TCMSUIConstants.PARK_BRAKE_DEFAULT_CSS), 1000,
          TimeUnit.MILLISECONDS);
    }
    else if (event.getSource().equals(reqParkingBrakeBypass))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(VDUInputs.PRKNG_BRAKE_BYPASS_REQ);
      parkBrakeBypassButtonProperty.set(TCMSUIConstants.PARK_BRAKE_PRESSED_CSS);
      scheduledExecutorService.schedule(
          () -> parkBrakeBypassButtonProperty.set(TCMSUIConstants.PARK_BRAKE_DEFAULT_CSS), 1000,
          TimeUnit.MILLISECONDS);
    }
  }
}