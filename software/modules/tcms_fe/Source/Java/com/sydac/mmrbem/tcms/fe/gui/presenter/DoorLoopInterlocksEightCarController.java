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
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
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

public class DoorLoopInterlocksEightCarController extends AbstractTCMSController
{
  @FXML
  private GridPane eightCarGrid;

  @FXML
  private Label detrainmentDoorDm1Lbl;

  @FXML
  private Label detrainmentDoorDm8Lbl;

  @FXML
  private Label leftDoorDm1Lbl;

  @FXML
  private Label leftDoorT2Lbl;

  @FXML
  private Label leftDoorM3Lbl;

  @FXML
  private Label leftDoorT4Lbl;

  @FXML
  private Label leftDoorM5Lbl;

  @FXML
  private Label leftDoorM6Lbl;

  @FXML
  private Label leftDoorT7Lbl;

  @FXML
  private Label leftDoorDm8Lbl;

  @FXML
  private Label rightDoorDm1Lbl;

  @FXML
  private Label rightDoorT2Lbl;

  @FXML
  private Label rightDoorM3Lbl;

  @FXML
  private Label rightDoorT4Lbl;

  @FXML
  private Label rightDoorM5Lbl;

  @FXML
  private Label rightDoorM6Lbl;

  @FXML
  private Label rightDoorT7Lbl;

  @FXML
  private Label rightDoorDm8Lbl;

  @FXML
  private Label pabrDm1Lbl;

  @FXML
  private Label pabrDm8Lbl;

  NodePseudoClassProperty leftDoorDm1Property;

  NodePseudoClassProperty leftDoorT2Property;

  NodePseudoClassProperty leftDoorM3Property;

  NodePseudoClassProperty leftDoorT4Property;

  NodePseudoClassProperty leftDoorM5Property;

  NodePseudoClassProperty leftDoorM6Property;

  NodePseudoClassProperty leftDoorT7Property;

  NodePseudoClassProperty leftDoorDm8Property;

  NodePseudoClassProperty rightDoorDm1Property;

  NodePseudoClassProperty rightDoorT2Property;

  NodePseudoClassProperty rightDoorM3Property;

  NodePseudoClassProperty rightDoorT4Property;

  NodePseudoClassProperty rightDoorM5Property;

  NodePseudoClassProperty rightDoorM6Property;

  NodePseudoClassProperty rightDoorT7Property;

  NodePseudoClassProperty rightDoorDm8Property;

  NodePseudoClassProperty detrainmentDoorDm1Property;

  NodePseudoClassProperty detrainmentDoorDm8Property;

  NodePseudoClassProperty pabrDm1NodePseudoClassProperty;

  NodePseudoClassProperty pabrDm8NodePseudoClassProperty;

  private ChangeListener<Number> totalCarsListener;

  private ChangeListener<Number> screenChangeListener;

  private ChangeListener<Number> pabrDm1StateChangeListener;

  private ChangeListener<Number> pabrDm8StateChangeListener;

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
    leftDoorT4Property = new NodePseudoClassProperty(leftDoorT4Lbl);
    leftDoorM5Property = new NodePseudoClassProperty(leftDoorM5Lbl);
    leftDoorM6Property = new NodePseudoClassProperty(leftDoorM6Lbl);
    leftDoorT7Property = new NodePseudoClassProperty(leftDoorT7Lbl);
    leftDoorDm8Property = new NodePseudoClassProperty(leftDoorDm8Lbl);

    rightDoorDm1Property = new NodePseudoClassProperty(rightDoorDm1Lbl);
    rightDoorT2Property = new NodePseudoClassProperty(rightDoorT2Lbl);
    rightDoorM3Property = new NodePseudoClassProperty(rightDoorM3Lbl);
    rightDoorT4Property = new NodePseudoClassProperty(rightDoorT4Lbl);
    rightDoorM5Property = new NodePseudoClassProperty(rightDoorM5Lbl);
    rightDoorM6Property = new NodePseudoClassProperty(rightDoorM6Lbl);
    rightDoorT7Property = new NodePseudoClassProperty(rightDoorT7Lbl);
    rightDoorDm8Property = new NodePseudoClassProperty(rightDoorDm8Lbl);

    pabrDm1NodePseudoClassProperty = new NodePseudoClassProperty(pabrDm1Lbl);
    pabrDm8NodePseudoClassProperty = new NodePseudoClassProperty(pabrDm8Lbl);

    detrainmentDoorDm1Property = new NodePseudoClassProperty(detrainmentDoorDm1Lbl);
    detrainmentDoorDm8Property = new NodePseudoClassProperty(detrainmentDoorDm8Lbl);

    footerPanelModel = new FooterPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FooterPanelBinder(footerPanelModel, frontend));

    screenChangeListener = (observable, oldVal, newVal) -> updateConfig(newVal.intValue());
    footerPanelModel.getCurrentScreenId().addListener(screenChangeListener);

    pabrDm1StateChangeListener = (observable, oldValue,
        newValue) -> updatePabrDm1State(doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm1().get());
    doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm1().addListener(pabrDm1StateChangeListener);

    updatePabrDm1State(doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm1().get());

    pabrDm8StateChangeListener = (observable, oldValue,
        newValue) -> updatePabrDm8State(doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm8().get());
    doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm8().addListener(pabrDm8StateChangeListener);

    updatePabrDm8State(doorLoopInterlocksScreenModel.getPabrDeEnergizedInDm8().get());
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

  private void updatePabrDm8State(int i)
  {
    if (i == 0)
    {
      pabrDm8NodePseudoClassProperty.set("closed"); //$NON-NLS-1$
    }
    else
    {
      pabrDm8NodePseudoClassProperty.set("open"); //$NON-NLS-1$
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
      else if (carType == CarType.T || carType == CarType.M)
      {
        if (carIndex == TCMSUIConstants.T2_CAR)
        {
          leftSideDoorsState.addListener(observable -> leftDoorT2Property
              .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
          leftDoorT2Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
          rightSideDoorsState.addListener(observable -> rightDoorT2Property
              .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
          rightDoorT2Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.T4_CAR)
        {
          leftSideDoorsState.addListener(observable -> leftDoorT4Property
              .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
          leftDoorT4Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
          rightSideDoorsState.addListener(observable -> rightDoorT4Property
              .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
          rightDoorT4Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.T7_CAR)
        {
          leftSideDoorsState.addListener(observable -> leftDoorT7Property
              .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
          leftDoorT7Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
          rightSideDoorsState.addListener(observable -> rightDoorT7Property
              .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
          rightDoorT7Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.M3_CAR)
        {
          leftSideDoorsState.addListener(observable -> leftDoorM3Property
              .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
          leftDoorM3Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
          rightSideDoorsState.addListener(observable -> rightDoorM3Property
              .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
          rightDoorM3Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.M5_CAR)
        {
          leftSideDoorsState.addListener(observable -> leftDoorM5Property
              .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
          leftDoorM5Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
          rightSideDoorsState.addListener(observable -> rightDoorM5Property
              .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
          rightDoorM5Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.M6_CAR)
        {
          leftSideDoorsState.addListener(observable -> leftDoorM6Property
              .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
          leftDoorM6Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
          rightSideDoorsState.addListener(observable -> rightDoorM6Property
              .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
          rightDoorM6Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        }
      }
      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {
        leftSideDoorsState.addListener(observable -> leftDoorDm8Property
            .set(leftSideDoorsState.get().getComponentState().toLowerCase()));
        leftDoorDm8Property.set(leftSideDoorsState.get().getComponentState().toLowerCase());
        rightSideDoorsState.addListener(observable -> rightDoorDm8Property
            .set(rightSideDoorsState.get().getComponentState().toLowerCase()));
        rightDoorDm8Property.set(rightSideDoorsState.get().getComponentState().toLowerCase());
        detrainmentDoorState.addListener(observable -> detrainmentDoorDm8Property
            .set(detrainmentDoorState.get().getComponentState().toLowerCase()));
        detrainmentDoorDm8Property.set(detrainmentDoorState.get().getComponentState().toLowerCase());
      }
    }
  }

  private void updateSixOrEightCarGridActive(int noOfCars)
  {
    eightCarGrid.setVisible(noOfCars == ApplicationConstants.EIGHT_CAR_CONFIG);
  }

  @Override
  public void detachListeners()
  {
    doorLoopInterlocksScreenModel.getNumberOfCars().removeListener(totalCarsListener);
    footerPanelModel.getCurrentScreenId().removeListener(screenChangeListener);
  }
}
