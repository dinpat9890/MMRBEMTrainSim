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

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.DoorLoopInterlocksScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.FooterPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.DoorLoopInterlocksScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class DoorLoopInterlocksScreenController extends AbstractTCMSController
{
  @FXML
  private GridPane sixCarGrid;

  @FXML
  private Label detrainmentDoorDm1Lbl;

  @FXML
  private Label detrainmentDoorDm6Lbl;

  @FXML
  private Label leftDoorDm1Lbl;

  @FXML
  private Label leftDoorT2Lbl;

  @FXML
  private Label leftDoorM3Lbl;

  @FXML
  private Label leftDoorM4Lbl;

  @FXML
  private Label leftDoorT5Lbl;

  @FXML
  private Label leftDoorDm6Lbl;

  @FXML
  private Label rightDoorDm1Lbl;

  @FXML
  private Label rightDoorT2Lbl;

  @FXML
  private Label rightDoorM3Lbl;

  @FXML
  private Label rightDoorM4Lbl;

  @FXML
  private Label rightDoorT5Lbl;

  @FXML
  private Label rightDoorDm6Lbl;

  @FXML
  private Label pabrDm1Lbl;

  @FXML
  private Label pabrDm6Lbl;

  NodePseudoClassProperty leftDoorDm1Property;

  NodePseudoClassProperty leftDoorT2Property;

  NodePseudoClassProperty leftDoorM3Property;

  NodePseudoClassProperty leftDoorM4Property;

  NodePseudoClassProperty leftDoorT5Property;

  NodePseudoClassProperty leftDoorDm6Property;

  NodePseudoClassProperty rightDoorDm1Property;

  NodePseudoClassProperty rightDoorT2Property;

  NodePseudoClassProperty rightDoorM3Property;

  NodePseudoClassProperty rightDoorM4Property;

  NodePseudoClassProperty rightDoorT5Property;

  NodePseudoClassProperty rightDoorDm6Property;

  NodePseudoClassProperty detrainmentDoorDm1Property;

  NodePseudoClassProperty detrainmentDoorDm6Property;

  NodePseudoClassProperty pabrDm1NodePseudoClassProperty;

  NodePseudoClassProperty pabrDm6NodePseudoClassProperty;

  private ChangeListener<Number> totalCarsListener;

  private ChangeListener<Number> screenChangeListener;

  private ChangeListener<Number> pabrDm1StateChangeListener;

  private ChangeListener<Number> pabrDm6StateChangeListener;

  private DoorLoopInterlocksScreenModel doorLoopInterlocksScreenModel;

  private FooterPanelModel footerPanelModel;

  @Override
  public void initializeImpl()
  {
    doorLoopInterlocksScreenModel = new DoorLoopInterlocksScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new DoorLoopInterlocksScreenBinder(doorLoopInterlocksScreenModel));

    totalCarsListener = (observable, oldVal, newVal) -> updateSixOrEightCarGridActive((int)newVal);
    doorLoopInterlocksScreenModel.getNumberOfCars().addListener(totalCarsListener);

    leftDoorDm1Property = new NodePseudoClassProperty(leftDoorDm1Lbl);
    leftDoorT2Property = new NodePseudoClassProperty(leftDoorT2Lbl);
    leftDoorM3Property = new NodePseudoClassProperty(leftDoorM3Lbl);
    leftDoorM4Property = new NodePseudoClassProperty(leftDoorM4Lbl);
    leftDoorT5Property = new NodePseudoClassProperty(leftDoorT5Lbl);
    leftDoorDm6Property = new NodePseudoClassProperty(leftDoorDm6Lbl);

    rightDoorDm1Property = new NodePseudoClassProperty(rightDoorDm1Lbl);
    rightDoorT2Property = new NodePseudoClassProperty(rightDoorT2Lbl);
    rightDoorM3Property = new NodePseudoClassProperty(rightDoorM3Lbl);
    rightDoorM4Property = new NodePseudoClassProperty(rightDoorM4Lbl);
    rightDoorT5Property = new NodePseudoClassProperty(rightDoorT5Lbl);
    rightDoorDm6Property = new NodePseudoClassProperty(rightDoorDm6Lbl);

    detrainmentDoorDm1Property = new NodePseudoClassProperty(detrainmentDoorDm1Lbl);
    detrainmentDoorDm6Property = new NodePseudoClassProperty(detrainmentDoorDm6Lbl);

    pabrDm1NodePseudoClassProperty = new NodePseudoClassProperty(pabrDm1Lbl);
    pabrDm6NodePseudoClassProperty = new NodePseudoClassProperty(pabrDm6Lbl);

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);

    pabrDm1StateChangeListener = (observable, oldValue,
        newValue) -> updatePabrDm1State(doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm1().get());
    doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm1().addListener(pabrDm1StateChangeListener);

    updatePabrDm1State(doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm1().get());

    pabrDm6StateChangeListener = (observable, oldValue,
        newValue) -> updatePabrDm6State(doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm6().get());
    doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm6().addListener(pabrDm6StateChangeListener);

    updatePabrDm6State(doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm6().get());
  }

  private void updatePabrDm1State(int i)
  {
    if (i == 0)
    {
      pabrDm1NodePseudoClassProperty.set("closed"); //$NON-NLS-1$
    }
    else
    {
      pabrDm1NodePseudoClassProperty.set("open"); //$NON-NLS-1$
    }
  }

  private void updatePabrDm6State(int i)
  {
    if (i == 0)
    {
      pabrDm6NodePseudoClassProperty.set("closed"); //$NON-NLS-1$
    }
    else
    {
      pabrDm6NodePseudoClassProperty.set("open"); //$NON-NLS-1$
    }
  }

  private void updateConfig(int screenId)
  {
    if (ScreenId.DOOR_LOOP_INTERLOCKS_SCREEN.getId() == screenId)
    {
      updateDoorLoopOpenStatus();
    }
  }

  private void updateDoorLoopOpenStatus()
  {
    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    for (Integer vehicleIdentifier : trainConfigurationModel.getAllVehicleIdentifier())
    {
      CarConfigurationModel carConfig = trainConfigurationModel.getCarConfig(vehicleIdentifier);

      if (carConfig == null)
      {
        break;
      }

      CarType carType = CarType.valueByCarTypeCode(carConfig.carTypeProperty().get());
      Integer carIndex = carConfig.carIndexProperty().get();

      ObjectPropertyBase<CarComponentStatesDO> leftSideDoorsState = doorLoopInterlocksScreenModel
          .leftDoorOpenStatusProperty(carIndex);
      ObjectPropertyBase<CarComponentStatesDO> rightSideDoorsState = doorLoopInterlocksScreenModel
          .rightDoorOpenStatusProperty(carIndex);
      ObjectPropertyBase<CarComponentStatesDO> detrainmentDoorState = doorLoopInterlocksScreenModel
          .detrainmentDoorOpenStatusProperty(carIndex);

      if ((carType == CarType.DM) && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        leftSideDoorsState.addListener(observable -> leftDoorDm1Property
            .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
        leftDoorDm1Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());

        rightSideDoorsState.addListener(observable -> rightDoorDm1Property
            .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
        rightDoorDm1Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        detrainmentDoorState.addListener(observable -> detrainmentDoorDm1Property
            .set(detrainmentDoorState.get().getComponentState().toLowerCase()));
        detrainmentDoorDm1Property.set(detrainmentDoorState.get().getComponentState().toLowerCase());
      }
      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        leftSideDoorsState.addListener(
            observable -> leftDoorT2Property.set(leftSideDoorsState.get().getComponentState().toLowerCase()));
        leftDoorT2Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
        rightSideDoorsState.addListener(observable -> rightDoorT2Property
            .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
        rightDoorT2Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
      }
      else if ((carType == CarType.M)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {
        leftSideDoorsState.addListener(
            observable -> leftDoorM3Property.set(leftSideDoorsState.get().getComponentState().toLowerCase()));
        leftDoorM3Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
        rightSideDoorsState.addListener(observable -> rightDoorM3Property
            .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
        rightDoorM3Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
      }
      else if ((carType == CarType.M)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        leftSideDoorsState.addListener(
            observable -> leftDoorM4Property.set(leftSideDoorsState.get().getComponentState().toLowerCase()));
        leftDoorM4Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
        rightSideDoorsState.addListener(observable -> rightDoorM4Property
            .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
        rightDoorM4Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
      }
      else if ((carType == CarType.T)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        leftSideDoorsState.addListener(
            observable -> leftDoorT5Property.set(leftSideDoorsState.get().getComponentState().toLowerCase()));
        leftDoorT5Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
        rightSideDoorsState.addListener(observable -> rightDoorT5Property
            .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
        rightDoorT5Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        leftSideDoorsState.addListener(observable -> leftDoorDm6Property
            .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
        leftDoorDm6Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
        rightSideDoorsState.addListener(observable -> rightDoorDm6Property
            .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
        rightDoorDm6Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        detrainmentDoorState.addListener(observable -> detrainmentDoorDm6Property
            .set(detrainmentDoorState.get().getComponentState().toLowerCase()));
        detrainmentDoorDm6Property.set(detrainmentDoorState.get().getComponentState().toLowerCase());
      }
    }
  }

  private void updateSixOrEightCarGridActive(int noOfCars)
  {
    sixCarGrid.setVisible(noOfCars == ApplicationConstants.SIX_CAR_CONFIG);
  }

  @Override
  public void detachListeners()
  {
    doorLoopInterlocksScreenModel.getNumberOfCars().removeListener(totalCarsListener);
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }
}
