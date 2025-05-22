/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.BrakeLoopInterlockScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.DoorLoopInterlocksScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.MiscellaniaScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.BrakeLoopInterlockScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.DoorLoopInterlocksScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.MiscellaniaScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.state.BrakeLoopStatus;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class BrakeLoopInterlockEightCarScreenController extends AbstractTCMSController
{

  private BrakeLoopInterlockScreenModel brakeLoopInterlockScreenModel;

  @FXML
  private Label dereailmentRightLbl1;

  @FXML
  private Label rightSideLbl1;

  @FXML
  private Label dereailmentRightLbl2;

  @FXML
  private Label rightSideLbl2;

  @FXML
  private Label dereailmentLeftLbl1;

  @FXML
  private Label leftSideLbl1;

  @FXML
  private Label dereailmentLeftLbl2;

  @FXML
  private Label leftSideLbl2;

  @FXML
  private Label brakeLoop1Lbl;

  @FXML
  private Label mLbl1;

  @FXML
  private Label brakeLoop1Lb2;

  @FXML
  private Label mLbl2;

  @FXML
  private Label obstacleLbl1;

  @FXML
  private Label detectedLbl1;

  @FXML
  private Label obstacleLbl2;

  @FXML
  private Label detectedLbl2;

  @FXML
  private Label detrainentLbl1;

  @FXML
  private Label doorLbl1;

  @FXML
  private Label detrainentLbl2;

  @FXML
  private Label doorLbl2;

  @FXML
  private Label mainReservLbl1;

  @FXML
  private Label mainReservCarLbl1;

  @FXML
  private Label mainReservLbl2;

  @FXML
  private Label mainReservCarLbl2;

  @FXML
  private Label mainReservLbl3;

  @FXML
  private Label mainReservCarLbl3;

  @FXML
  private Label mainReservLbl4;

  @FXML
  private Label mainReservCarLbl4;

  @FXML
  private Label automticLbl;

  @FXML
  private Label tCalLbl;

  @FXML
  private Label cbTripCarlbl1;

  @FXML
  private Label cbTripCarlbl2;

  @FXML
  private Label brakeLoop1Lb3;

  @FXML
  private Label mLbl3;

  @FXML
  private Label cbTripCarlbl3;

  @FXML
  private Label mainReservLbl5;

  @FXML
  private Label mainReservCarLbl5;

  @FXML
  private Label automticLbl1;

  @FXML
  private Label tCalLbl1;

  @FXML
  private Label automticLbl2;

  @FXML
  private Label tCalLbl2;

  private NodePseudoClassProperty dereailmentRightLbl1StateProperty;

  private NodePseudoClassProperty rightSideLbl1StateProperty;

  private NodePseudoClassProperty dereailmentRightLbl2StateProperty;

  private NodePseudoClassProperty rightSideLbl2StateProperty;

  private NodePseudoClassProperty dereailmentLeftLbl1StateProperty;

  private NodePseudoClassProperty leftSideLbl1StateProperty;

  private NodePseudoClassProperty dereailmentLeftLbl2StateProperty;

  private NodePseudoClassProperty leftSideLbl2StateProperty;

  private NodePseudoClassProperty brakeLoop1LblStateProperty;

  private NodePseudoClassProperty mLbl1StateProperty;

  private NodePseudoClassProperty brakeLoop2LblStateProperty;

  private NodePseudoClassProperty mLbl2StateProperty;

  private NodePseudoClassProperty obstacleLbl1LblStateProperty;

  private NodePseudoClassProperty detectedLbl1StateProperty;

  private NodePseudoClassProperty obstacleLbl2LblStateProperty;

  private NodePseudoClassProperty detectedLbl2StateProperty;

  NodePseudoClassProperty detrainentLbl1StateProperty;

  NodePseudoClassProperty doorLbl1StateProperty;

  private NodePseudoClassProperty detrainentLbl2StateProperty;

  private NodePseudoClassProperty doorLbl2StateProperty;

  private NodePseudoClassProperty mainReservLbl1StateProperty;

  private NodePseudoClassProperty mainReservCarLbl1StateProperty;

  private NodePseudoClassProperty mainReservLbl2StateProperty;

  private NodePseudoClassProperty mainReservCarLbl2StateProperty;

  private NodePseudoClassProperty mainReservLbl3StateProperty;

  private NodePseudoClassProperty mainReservCarLbl3StateProperty;

  private NodePseudoClassProperty mainReservLbl4StateProperty;

  private NodePseudoClassProperty mainReservCarLbl4StateProperty;

  private NodePseudoClassProperty automticLblStateProperty;

  private NodePseudoClassProperty tCalLblStateProperty;

  private FooterPanelModel footerPanelModel;

  private MiscellaniaScreenModel miscellaniaScreenModel;

  private ChangeListener<Number> derelamentLeftFirstCarListener;

  private ChangeListener<Number> derelamentLeftLastCarListener;

  private ChangeListener<Number> derelamentRightFirstCarListener;

  private ChangeListener<Number> derelamentRightLastCarListener;

  private ChangeListener<Number> obstrectionLeftFirstCarListener;

  private ChangeListener<Number> obstrectionLeftLastCarListener;

  private DoorLoopInterlocksScreenModel doorLoopInterlocksScreenModel;

  private ChangeListener<Number> detrainmentFirstCarListener;

  private ChangeListener<Number> detrainmentLastCarListener;

  private ChangeListener<Number> totalCarsListener;

  private ChangeListener<Number> screenChangeListener;

  private NodePseudoClassProperty cbTripCarlbl1Property;

  private NodePseudoClassProperty cbTripCarlbl2Property;

  private NodePseudoClassProperty mainReservLbl5StateProperty;

  private NodePseudoClassProperty mainReservCarLbl5StateProperty;

  private NodePseudoClassProperty automticLbl1StateProperty;

  private NodePseudoClassProperty tCalLbl1StateProperty;

  private NodePseudoClassProperty brakeLoop3LblStateProperty;

  private NodePseudoClassProperty mLbl3StateProperty;

  private NodePseudoClassProperty automticLbl2StateProperty;

  private NodePseudoClassProperty tCalLbl2StateProperty;

  private NodePseudoClassProperty cbTripCarlbl3Property;
  
  private ChangeListener<Number> obstrectionRightFirstCarListener;

  private ChangeListener<Number> obstrectionRightLastCarListener;

  @Override
  public void detachListeners()
  {}

  @Override
  public void initializeImpl()
  {

    brakeLoopInterlockScreenModel = new BrakeLoopInterlockScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new BrakeLoopInterlockScreenBinder(brakeLoopInterlockScreenModel));

    doorLoopInterlocksScreenModel = new DoorLoopInterlocksScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new DoorLoopInterlocksScreenBinder(doorLoopInterlocksScreenModel));

    miscellaniaScreenModel = new MiscellaniaScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new MiscellaniaScreenBinder(miscellaniaScreenModel));

    dereailmentRightLbl1StateProperty = new NodePseudoClassProperty(dereailmentRightLbl1);
    rightSideLbl1StateProperty = new NodePseudoClassProperty(rightSideLbl1);
    dereailmentRightLbl2StateProperty = new NodePseudoClassProperty(dereailmentRightLbl2);
    rightSideLbl2StateProperty = new NodePseudoClassProperty(rightSideLbl2);
    dereailmentLeftLbl1StateProperty = new NodePseudoClassProperty(dereailmentLeftLbl1);
    leftSideLbl1StateProperty = new NodePseudoClassProperty(leftSideLbl1);

    dereailmentLeftLbl2StateProperty = new NodePseudoClassProperty(dereailmentLeftLbl2);
    leftSideLbl2StateProperty = new NodePseudoClassProperty(leftSideLbl2);

    brakeLoop1LblStateProperty = new NodePseudoClassProperty(brakeLoop1Lbl);
    mLbl1StateProperty = new NodePseudoClassProperty(mLbl1);

    brakeLoop2LblStateProperty = new NodePseudoClassProperty(brakeLoop1Lb2);
    mLbl2StateProperty = new NodePseudoClassProperty(mLbl2);

    obstacleLbl1LblStateProperty = new NodePseudoClassProperty(obstacleLbl1);
    detectedLbl1StateProperty = new NodePseudoClassProperty(detectedLbl1);

    obstacleLbl2LblStateProperty = new NodePseudoClassProperty(obstacleLbl2);
    detectedLbl2StateProperty = new NodePseudoClassProperty(detectedLbl2);

    detrainentLbl1StateProperty = new NodePseudoClassProperty(detrainentLbl1);
    doorLbl1StateProperty = new NodePseudoClassProperty(doorLbl1);

    detrainentLbl2StateProperty = new NodePseudoClassProperty(detrainentLbl2);
    doorLbl2StateProperty = new NodePseudoClassProperty(doorLbl2);

    mainReservLbl1StateProperty = new NodePseudoClassProperty(mainReservLbl1);
    mainReservCarLbl1StateProperty = new NodePseudoClassProperty(mainReservCarLbl1);

    mainReservLbl2StateProperty = new NodePseudoClassProperty(mainReservLbl2);
    mainReservCarLbl2StateProperty = new NodePseudoClassProperty(mainReservCarLbl2);

    mainReservLbl3StateProperty = new NodePseudoClassProperty(mainReservLbl3);
    mainReservCarLbl3StateProperty = new NodePseudoClassProperty(mainReservCarLbl3);

    mainReservLbl4StateProperty = new NodePseudoClassProperty(mainReservLbl4);
    mainReservCarLbl4StateProperty = new NodePseudoClassProperty(mainReservCarLbl4);

    mainReservLbl5StateProperty = new NodePseudoClassProperty(mainReservLbl5);
    mainReservCarLbl5StateProperty = new NodePseudoClassProperty(mainReservCarLbl5);

    automticLblStateProperty = new NodePseudoClassProperty(automticLbl);
    tCalLblStateProperty = new NodePseudoClassProperty(tCalLbl);

    automticLbl1StateProperty = new NodePseudoClassProperty(automticLbl1);
    tCalLbl1StateProperty = new NodePseudoClassProperty(tCalLbl1);

    automticLbl2StateProperty = new NodePseudoClassProperty(automticLbl2);
    tCalLbl2StateProperty = new NodePseudoClassProperty(tCalLbl2);

    cbTripCarlbl1Property = new NodePseudoClassProperty(cbTripCarlbl1);
    cbTripCarlbl2Property = new NodePseudoClassProperty(cbTripCarlbl2);
    cbTripCarlbl3Property = new NodePseudoClassProperty(cbTripCarlbl3);

    brakeLoop3LblStateProperty = new NodePseudoClassProperty(brakeLoop1Lb3);
    mLbl3StateProperty = new NodePseudoClassProperty(mLbl3);

    derelamentLeftFirstCarListener = (observable, oldValue,
        newValue) -> updateDerailmentLeftFirstCar((Integer)newValue);

    miscellaniaScreenModel.getFirstCarDerailmentLeft().addListener(derelamentLeftFirstCarListener);
    updateDerailmentLeftFirstCar(miscellaniaScreenModel.getFirstCarDerailmentLeft().get());

    derelamentLeftLastCarListener = (observable, oldValue,
        newValue) -> updateDerailmentLeftLastCar((Integer)newValue);

    miscellaniaScreenModel.getLastCarDerailmentLeft().addListener(derelamentLeftLastCarListener);
    updateDerailmentLeftLastCar(miscellaniaScreenModel.getLastCarDerailmentLeft().get());

    derelamentRightFirstCarListener = (observable, oldValue,
        newValue) -> updateDerailmentRightFirstCar((Integer)newValue);

    miscellaniaScreenModel.getFirstCarDerailmentRight().addListener(derelamentRightFirstCarListener);
    updateDerailmentRightFirstCar(miscellaniaScreenModel.getFirstCarDerailmentRight().get());

    derelamentRightLastCarListener = (observable, oldValue,
        newValue) -> updateDerailmentRightLastCar((Integer)newValue);

    miscellaniaScreenModel.getLastCarDerailmentRight().addListener(derelamentRightLastCarListener);
    updateDerailmentRightLastCar(miscellaniaScreenModel.getLastCarDerailmentRight().get());

    obstrectionLeftFirstCarListener = (observable, oldValue,
        newValue) -> updateObstrectionFirstCar((Integer)newValue);

    miscellaniaScreenModel.getFirstCarObstrectionLeft().addListener(obstrectionLeftFirstCarListener);
    updateObstrectionFirstCar(miscellaniaScreenModel.getFirstCarObstrectionLeft().get());

    obstrectionLeftLastCarListener = (observable, oldValue,
        newValue) -> updateObstrectionLastCar((Integer)newValue);

    miscellaniaScreenModel.getLastCarObstrectionLeft().addListener(obstrectionLeftLastCarListener);
    updateObstrectionLastCar(miscellaniaScreenModel.getLastCarObstrectionLeft().get());

    totalCarsListener = (observable, oldVal, newVal) -> updateCars((int)newVal);
    doorLoopInterlocksScreenModel.getNumberOfCars().addListener(totalCarsListener);
    
    obstrectionRightFirstCarListener = (observable, oldValue,
        newValue) -> updateObstrectionFirstCar((Integer)newValue);

    miscellaniaScreenModel.getFirstCarObstrectionRight().addListener(obstrectionRightFirstCarListener);
    updateObstrectionFirstCar(miscellaniaScreenModel.getFirstCarObstrectionRight().get());

    obstrectionRightLastCarListener = (observable, oldValue,
        newValue) -> updateObstrectionLastCar((Integer)newValue);

    miscellaniaScreenModel.getLastCarObstrectionRight().addListener(obstrectionRightLastCarListener);
    updateObstrectionLastCar(miscellaniaScreenModel.getLastCarObstrectionRight().get());

  }

  private void updateDerailmentLeftFirstCar(int doorStateId)
  {

    dereailmentLeftLbl1StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());
    leftSideLbl1StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());
  }

  private void updateDerailmentLeftLastCar(int doorStateId)
  {

    dereailmentLeftLbl2StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());
    leftSideLbl2StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateDerailmentRightFirstCar(int doorStateId)
  {

    dereailmentRightLbl1StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());
    rightSideLbl1StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());
  }

  private void updateDerailmentRightLastCar(int doorStateId)
  {

    dereailmentRightLbl2StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());
    rightSideLbl2StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateObstrectionFirstCar(int doorStateId)
  {

    obstacleLbl1LblStateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());
    detectedLbl1StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateObstrectionLastCar(int doorStateId)
  {

    obstacleLbl2LblStateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());
    detectedLbl2StateProperty.set(BrakeLoopStatus.getStatusOf(doorStateId).getStyleClass());

  }

  private void updateCars(int noOfCars)
  {

    rightSideLbl2.setText(Integer.toString(noOfCars));
    leftSideLbl2.setText(Integer.toString(noOfCars));
    detectedLbl2.setText(Integer.toString(noOfCars));
    doorLbl2.setText(Integer.toString(noOfCars));
    mainReservCarLbl2.setText(Integer.toString(noOfCars));

    updateStatus();

  }

  private void updateStatus()
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

      ObjectPropertyBase<CarComponentStatesDO> detrainmentDoorState = doorLoopInterlocksScreenModel
          .detrainmentDoorOpenStatusProperty(carIndex);

      ObjectPropertyBase<CarComponentStatesDO> mainReserviorState = brakeLoopInterlockScreenModel
          .mainReserviorPressureProperty(carIndex);

      ObjectPropertyBase<CarComponentStatesDO> automaticState = brakeLoopInterlockScreenModel
          .automaticDropeProperty(carIndex);
      
      ObjectPropertyBase<CarComponentStatesDO> brakeLoopCbState = brakeLoopInterlockScreenModel
          .brakeLoopCbProperty(carIndex);

      if ((carType == CarType.DM) && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
      {

        mainReserviorState.addListener(observable -> {
          mainReservLbl1StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
          mainReservCarLbl1StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
        });
        mainReservLbl1StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
        mainReservCarLbl1StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());

        detrainmentDoorState.addListener(observable -> {
          detrainentLbl1StateProperty.set(detrainmentDoorState.get().getComponentState().toLowerCase());
          doorLbl1StateProperty.set(detrainmentDoorState.get().getComponentState().toLowerCase());
        });
        detrainentLbl1StateProperty.set(detrainmentDoorState.get().getComponentState().toLowerCase());
        doorLbl1StateProperty.set(detrainmentDoorState.get().getComponentState().toLowerCase());
      }
      else if ((carType == CarType.T || carType == CarType.M))
      {

        if (carIndex == TCMSUIConstants.T2_CAR)
        {
          automaticState.addListener(observable -> {
            automticLblStateProperty.set(automaticState.get().getComponentState().toLowerCase());
            tCalLblStateProperty.set(automaticState.get().getComponentState().toLowerCase());
          });
          automticLblStateProperty.set(automaticState.get().getComponentState().toLowerCase());
          tCalLblStateProperty.set(automaticState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.T4_CAR)
        {
          automaticState.addListener(observable -> {
            automticLbl1StateProperty.set(automaticState.get().getComponentState().toLowerCase());
            tCalLbl1StateProperty.set(automaticState.get().getComponentState().toLowerCase());
          });
          automticLbl1StateProperty.set(automaticState.get().getComponentState().toLowerCase());
          tCalLbl1StateProperty.set(automaticState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.T7_CAR)
        {
          automaticState.addListener(observable -> {
            automticLbl2StateProperty.set(automaticState.get().getComponentState().toLowerCase());
            tCalLbl2StateProperty.set(automaticState.get().getComponentState().toLowerCase());
          });
          automticLbl2StateProperty.set(automaticState.get().getComponentState().toLowerCase());
          tCalLbl2StateProperty.set(automaticState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.M3_CAR)
        {
          mainReserviorState.addListener(observable -> {
            mainReservLbl3StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
            mainReservCarLbl3StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
          });
          mainReservLbl3StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
          mainReservCarLbl3StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());

          // FIX mE with Brake llop CB triped
          brakeLoopCbState.addListener(observable -> {
            brakeLoop1LblStateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
            mLbl1StateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
            cbTripCarlbl1Property.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          });
          brakeLoop1LblStateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          mLbl1StateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          cbTripCarlbl1Property.set(brakeLoopCbState.get().getComponentState().toLowerCase());

        }
        else if (carIndex == TCMSUIConstants.M5_CAR)
        {
          mainReserviorState.addListener(observable -> {
            mainReservLbl4StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
            mainReservCarLbl4StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
          });
          mainReservLbl4StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
          mainReservCarLbl4StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());

          // FIX mE with Brake llop CB triped
          brakeLoopCbState.addListener(observable -> {
            brakeLoop2LblStateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
            mLbl2StateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
            cbTripCarlbl2Property.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          });
          brakeLoop2LblStateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          mLbl2StateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          cbTripCarlbl2Property.set(brakeLoopCbState.get().getComponentState().toLowerCase());
        }
        else if (carIndex == TCMSUIConstants.M6_CAR)
        {
          mainReserviorState.addListener(observable -> {
            mainReservLbl5StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
            mainReservCarLbl5StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
          });
          mainReservLbl5StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
          mainReservCarLbl5StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());

          // FIX mE with Brake llop CB triped
          brakeLoopCbState.addListener(observable -> {
            brakeLoop3LblStateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
            mLbl3StateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
            cbTripCarlbl3Property.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          });
          brakeLoop3LblStateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          mLbl3StateProperty.set(brakeLoopCbState.get().getComponentState().toLowerCase());
          cbTripCarlbl3Property.set(brakeLoopCbState.get().getComponentState().toLowerCase());

        }
      }

      else if ((carType == CarType.DM)
          && carConfig.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
      {

        mainReserviorState.addListener(observable -> {
          mainReservLbl2StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
          mainReservCarLbl2StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
        });
        mainReservLbl2StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());
        mainReservCarLbl2StateProperty.set(mainReserviorState.get().getComponentState().toLowerCase());

        detrainmentDoorState.addListener(observable -> {
          detrainentLbl2StateProperty.set(detrainmentDoorState.get().getComponentState().toLowerCase());
          doorLbl2StateProperty.set(detrainmentDoorState.get().getComponentState().toLowerCase());
        });
        detrainentLbl2StateProperty.set(detrainmentDoorState.get().getComponentState().toLowerCase());
        doorLbl2StateProperty.set(detrainmentDoorState.get().getComponentState().toLowerCase());
      }
    }
  }

  public GridPane createCar(String fxmlName)
  {
    GridPane gridPane;
    FXMLLoader fxmlLoader = new FXMLLoader(ViewPackage.class.getResource(fxmlName));
    fxmlLoader.setController(this);
    try
    {
      gridPane = fxmlLoader.load();
    }
    catch (IOException exception)
    {
      logger.error(exception);
      throw new LoadingException(exception);
    }
    return gridPane;
  }

}
