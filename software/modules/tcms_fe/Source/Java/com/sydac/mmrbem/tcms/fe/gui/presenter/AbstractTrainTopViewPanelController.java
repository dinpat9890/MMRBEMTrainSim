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

import java.io.IOException;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.data.VehicleDoorStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainTopViewComponentStatusModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public abstract class AbstractTrainTopViewPanelController extends AbstractTCMSController
{
  @FXML
  protected Label doorA1Icon;

  @FXML
  protected Label doorA2Icon;

  @FXML
  protected Label doorA3Icon;

  @FXML
  protected Label doorA4Icon;

  @FXML
  protected Label doorB1Icon;

  @FXML
  protected Label doorB2Icon;

  @FXML
  protected Label doorB3Icon;

  @FXML
  protected Label doorB4Icon;

  @FXML
  private Label serviceBrakeIcon;

  @FXML
  private Label parkingBrakeIcon;

  protected NodePseudoClassProperty doorA1PseudoClassProperty;

  protected NodePseudoClassProperty doorA2PseudoClassProperty;

  protected NodePseudoClassProperty doorA3PseudoClassProperty;

  protected NodePseudoClassProperty doorA4PseudoClassProperty;

  protected NodePseudoClassProperty doorB1PseudoClassProperty;

  protected NodePseudoClassProperty doorB2PseudoClassProperty;

  protected NodePseudoClassProperty doorB3PseudoClassProperty;

  protected NodePseudoClassProperty doorB4PseudoClassProperty;

  private NodePseudoClassProperty parkingBrakePseudoClassProperty;

  private NodePseudoClassProperty serviceBrakePseudoClassProperty;

  protected ObjectPropertyBase<VehicleDoorStatesDO> doorA1State;

  protected ObjectPropertyBase<VehicleDoorStatesDO> doorA2State;

  protected ObjectPropertyBase<VehicleDoorStatesDO> doorA3State;

  protected ObjectPropertyBase<VehicleDoorStatesDO> doorA4State;

  protected ObjectPropertyBase<VehicleDoorStatesDO> doorB1State;

  protected ObjectPropertyBase<VehicleDoorStatesDO> doorB2State;

  protected ObjectPropertyBase<VehicleDoorStatesDO> doorB3State;

  protected ObjectPropertyBase<VehicleDoorStatesDO> doorB4State;

  private ObjectPropertyBase<CarComponentStatesDO> parkingBrakeState;

  private ObjectPropertyBase<CarComponentStatesDO> serviceBrakeState;

  protected CarConfigurationModel carConfigModel;

  protected TrainTopViewComponentStatusModel carComponentStatusModel;

  protected FooterPanelModel footerPanelModel;

  protected int carIndex;

  protected AbstractTrainTopViewPanelController(CarConfigurationModel carConfig,
      TrainTopViewComponentStatusModel carComponentStatusModel, FooterPanelModel footerPanelModel)
  {
    this.carConfigModel = carConfig;
    this.carComponentStatusModel = carComponentStatusModel;
    this.carIndex = carConfigModel.carIndexProperty().get();
    this.footerPanelModel = footerPanelModel;
  }

  @Override
  public void initializeImpl()
  {
    doorA1PseudoClassProperty = new NodePseudoClassProperty(doorA1Icon);
    doorA2PseudoClassProperty = new NodePseudoClassProperty(doorA2Icon);
    doorA3PseudoClassProperty = new NodePseudoClassProperty(doorA3Icon);
    doorA4PseudoClassProperty = new NodePseudoClassProperty(doorA4Icon);
    doorB1PseudoClassProperty = new NodePseudoClassProperty(doorB1Icon);
    doorB2PseudoClassProperty = new NodePseudoClassProperty(doorB2Icon);
    doorB3PseudoClassProperty = new NodePseudoClassProperty(doorB3Icon);
    doorB4PseudoClassProperty = new NodePseudoClassProperty(doorB4Icon);

    parkingBrakePseudoClassProperty = new NodePseudoClassProperty(parkingBrakeIcon);
    serviceBrakePseudoClassProperty = new NodePseudoClassProperty(serviceBrakeIcon);

    parkingBrakeState = carComponentStatusModel.parkingBrakeStatusProperty(carIndex);
    serviceBrakeState = carComponentStatusModel.serviceBrakeStatusProperty(carIndex);

    parkingBrakeState.addListener(observable -> parkingBrakePseudoClassProperty
        .set(parkingBrakeState.get().getComponentState().toLowerCase()));
    serviceBrakeState.addListener(observable -> serviceBrakePseudoClassProperty
        .set(serviceBrakeState.get().getComponentState().toLowerCase()));
  }

  protected void initUI()
  {
    if (footerPanelModel.getCurrentScreenId().get() == (ScreenId.DOOR_SYSTEM_SCREEN.getId())
        || footerPanelModel.getCurrentScreenId().get() == (ScreenId.DOORS_SYTEM_COMMANDS_SCREEN.getId()))
    {
      serviceBrakeIcon.setVisible(false);
      parkingBrakeIcon.setVisible(false);
    }
    else
    {
      serviceBrakeIcon.setVisible(true);
      parkingBrakeIcon.setVisible(true);
    }
    parkingBrakePseudoClassProperty.set(parkingBrakeState.get().getComponentState().toLowerCase());
    serviceBrakePseudoClassProperty.set(serviceBrakeState.get().getComponentState().toLowerCase());
  }

  /**
   * Creates the car by loading FXML file.
   * 
   * @param fxmlName
   *          fxml file name
   * @param carPanelSize
   *          car panel siize
   * @return the node
   */
  public GridPane createCar(String fxmlName, int carPanelSize)
  {
    GridPane gridPane;
    FXMLLoader fxmlLoader = new FXMLLoader(ViewPackage.class.getResource(fxmlName));
    fxmlLoader.setController(this);

    try
    {
      gridPane = fxmlLoader.load();
      gridPane.setPrefWidth(carPanelSize);
      gridPane.setPrefHeight(TCMSUIConstants.TRAIN_TOP_VIEW_PANEL_HEIGHT);

    }
    catch (IOException exception)
    {
      logger.error(exception);
      throw new LoadingException(exception);
    }
    return gridPane;
  }
}
