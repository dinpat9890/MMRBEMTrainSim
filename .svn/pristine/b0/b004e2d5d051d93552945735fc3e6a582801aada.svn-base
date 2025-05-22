/*******************************************************************************
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_1_CAR_1_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_1_CAR_2_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_1_CAR_3_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_1_CAR_4_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_1_CAR_5_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_1_CAR_6_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_2_CAR_1_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_2_CAR_2_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_2_CAR_3_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_2_CAR_4_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_2_CAR_5_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_2_CAR_6_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_3_CAR_1_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_3_CAR_2_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_3_CAR_3_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_3_CAR_4_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_3_CAR_5_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_3_CAR_6_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_4_CAR_1_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_4_CAR_2_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_4_CAR_3_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_4_CAR_4_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_4_CAR_5_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_4_CAR_6_ISO_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs.PECU_ISOLATE_SCREEN_BACK_BUTTON;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.papis.common.ScreenId;
import com.sydac.mmrbem.papis.fe.base.PAPISFactory;
import com.sydac.mmrbem.papis.fe.gui.AbstractPAPISController;
import com.sydac.mmrbem.papis.fe.gui.binder.HeaderStatusBinder;
import com.sydac.mmrbem.papis.fe.gui.model.HeaderDateTimeModel;

import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class PecuIsolateScreenController extends AbstractPAPISController
{

  @FXML
  private Label timeLbl;

  @FXML
  private Label dateLbl;

  @FXML
  private GridPane sixCarGrid;

  @FXML
  private GridPane outerGrid;

  @FXML
  @CommsNumber(PECU_1_CAR_1_ISO_BUTTON)
  private Button car1Pecu1Btn;

  @FXML
  @CommsNumber(PECU_2_CAR_1_ISO_BUTTON)
  private Button car1Pecu2Btn;

  @FXML
  @CommsNumber(PECU_3_CAR_1_ISO_BUTTON)
  private Button car1Pecu3Btn;

  @FXML
  @CommsNumber(PECU_4_CAR_1_ISO_BUTTON)
  private Button car1Pecu4Btn;

  @FXML
  @CommsNumber(PECU_1_CAR_2_ISO_BUTTON)
  private Button car2Pecu1Btn;

  @FXML
  @CommsNumber(PECU_2_CAR_2_ISO_BUTTON)
  private Button car2Pecu2Btn;

  @FXML
  @CommsNumber(PECU_3_CAR_2_ISO_BUTTON)
  private Button car2Pecu3Btn;

  @FXML
  @CommsNumber(PECU_4_CAR_2_ISO_BUTTON)
  private Button car2Pecu4Btn;

  @FXML
  @CommsNumber(PECU_1_CAR_3_ISO_BUTTON)
  private Button car3Pecu1Btn;

  @FXML
  @CommsNumber(PECU_2_CAR_3_ISO_BUTTON)
  private Button car3Pecu2Btn;

  @FXML
  @CommsNumber(PECU_3_CAR_3_ISO_BUTTON)
  private Button car3Pecu3Btn;

  @FXML
  @CommsNumber(PECU_4_CAR_3_ISO_BUTTON)
  private Button car3Pecu4Btn;

  @FXML
  @CommsNumber(PECU_1_CAR_4_ISO_BUTTON)
  private Button car4Pecu1Btn;

  @FXML
  @CommsNumber(PECU_2_CAR_4_ISO_BUTTON)
  private Button car4Pecu2Btn;

  @FXML
  @CommsNumber(PECU_3_CAR_4_ISO_BUTTON)
  private Button car4Pecu3Btn;

  @FXML
  @CommsNumber(PECU_4_CAR_4_ISO_BUTTON)
  private Button car4Pecu4Btn;

  @FXML
  @CommsNumber(PECU_1_CAR_5_ISO_BUTTON)
  private Button car5Pecu1Btn;

  @FXML
  @CommsNumber(PECU_2_CAR_5_ISO_BUTTON)
  private Button car5Pecu2Btn;

  @FXML
  @CommsNumber(PECU_3_CAR_5_ISO_BUTTON)
  private Button car5Pecu3Btn;

  @FXML
  @CommsNumber(PECU_4_CAR_5_ISO_BUTTON)
  private Button car5Pecu4Btn;

  @FXML
  @CommsNumber(PECU_1_CAR_6_ISO_BUTTON)
  private Button car6Pecu1Btn;

  @FXML
  @CommsNumber(PECU_2_CAR_6_ISO_BUTTON)
  private Button car6Pecu2Btn;

  @FXML
  @CommsNumber(PECU_3_CAR_6_ISO_BUTTON)
  private Button car6Pecu3Btn;

  @FXML
  @CommsNumber(PECU_4_CAR_6_ISO_BUTTON)
  private Button car6Pecu4Btn;

 

  @FXML
  @CommsNumber(PECU_ISOLATE_SCREEN_BACK_BUTTON)
  private Button backBtn;

  private ChangeListener<String> dateLabelListener;

  private ChangeListener<String> timeLabelListener;

  private HeaderDateTimeModel headerDateTimeModel;

  private NodePseudoClassProperty car1Pecu1BtnProperty;

  private NodePseudoClassProperty car1Pecu2BtnProperty;

  private NodePseudoClassProperty car1Pecu3BtnProperty;

  private NodePseudoClassProperty car1Pecu4BtnProperty;

  private NodePseudoClassProperty car2Pecu1BtnProperty;

  private NodePseudoClassProperty car2Pecu2BtnProperty;

  private NodePseudoClassProperty car2Pecu3BtnProperty;

  private NodePseudoClassProperty car2Pecu4BtnProperty;

  private NodePseudoClassProperty car3Pecu1BtnProperty;

  private NodePseudoClassProperty car3Pecu2BtnProperty;

  private NodePseudoClassProperty car3Pecu3BtnProperty;

  private NodePseudoClassProperty car3Pecu4BtnProperty;

  private NodePseudoClassProperty car4Pecu1BtnProperty;

  private NodePseudoClassProperty car4Pecu2BtnProperty;

  private NodePseudoClassProperty car4Pecu3BtnProperty;

  private NodePseudoClassProperty car4Pecu4BtnProperty;

  private NodePseudoClassProperty car5Pecu1BtnProperty;

  private NodePseudoClassProperty car5Pecu2BtnProperty;

  private NodePseudoClassProperty car5Pecu3BtnProperty;

  private NodePseudoClassProperty car5Pecu4BtnProperty;

  private NodePseudoClassProperty car6Pecu1BtnProperty;

  private NodePseudoClassProperty car6Pecu2BtnProperty;

  private NodePseudoClassProperty car6Pecu3BtnProperty;

  private NodePseudoClassProperty car6Pecu4BtnProperty;

 

  private Map<Button, NodePseudoClassProperty> propertyMap = new HashMap<>();

  private Map<Button, Integer> pecuIdMap = new HashMap<>();

  private ChangeListener<Number> totalCarListener;

  public static final int NUMBER_OF_CARS_EIGHT = 8;

  public static final int NUMBER_OF_CARS_ZERO = 0;

  private static final String EIGHT_CAR_FXML_NAME = "PecuIsolateScreenEightCar.fxml"; //$NON-NLS-1$

  @Override
  public void detachListeners()
  {
    headerDateTimeModel.getCurrentDate().removeListener(dateLabelListener);
    headerDateTimeModel.getCurrentTime().removeListener(timeLabelListener);
    headerDateTimeModel.getTotalCar().removeListener(totalCarListener);
  }

  @Override
  public void initializeImpl()
  {
    // sixCarGrid.setVisible(true);

    headerDateTimeModel = new HeaderDateTimeModel(scenarioCarIndex);
    papisScreenBinders.add(new HeaderStatusBinder(headerDateTimeModel));

    dateLabelListener = (observable, oldVal, newVal) -> updateDateLabel(newVal);
    this.headerDateTimeModel.getCurrentDate().addListener(dateLabelListener);

    timeLabelListener = (observable, oldVal, newVal) -> updateTimeLabel(newVal);
    this.headerDateTimeModel.getCurrentTime().addListener(timeLabelListener);

    updateDateLabel(this.headerDateTimeModel.getCurrentDate().get());
    updateTimeLabel(this.headerDateTimeModel.getCurrentTime().get());
    totalCarListener = (observable, oldVal, newVal) -> updateCarConfig((int)newVal);
    headerDateTimeModel.getTotalCar().addListener(totalCarListener);

    updateCarConfig(headerDateTimeModel.getTotalCar().get());

    car1Pecu1BtnProperty = new NodePseudoClassProperty(car1Pecu1Btn);
    car1Pecu2BtnProperty = new NodePseudoClassProperty(car1Pecu2Btn);
    car1Pecu3BtnProperty = new NodePseudoClassProperty(car1Pecu3Btn);
    car1Pecu4BtnProperty = new NodePseudoClassProperty(car1Pecu4Btn);
    car2Pecu1BtnProperty = new NodePseudoClassProperty(car2Pecu1Btn);
    car2Pecu2BtnProperty = new NodePseudoClassProperty(car2Pecu2Btn);
    car2Pecu3BtnProperty = new NodePseudoClassProperty(car2Pecu3Btn);
    car2Pecu4BtnProperty = new NodePseudoClassProperty(car2Pecu4Btn);
    car3Pecu1BtnProperty = new NodePseudoClassProperty(car3Pecu1Btn);
    car3Pecu2BtnProperty = new NodePseudoClassProperty(car3Pecu2Btn);
    car3Pecu3BtnProperty = new NodePseudoClassProperty(car3Pecu3Btn);
    car3Pecu4BtnProperty = new NodePseudoClassProperty(car3Pecu4Btn);
    car4Pecu1BtnProperty = new NodePseudoClassProperty(car4Pecu1Btn);
    car4Pecu2BtnProperty = new NodePseudoClassProperty(car4Pecu2Btn);
    car4Pecu3BtnProperty = new NodePseudoClassProperty(car4Pecu3Btn);
    car4Pecu4BtnProperty = new NodePseudoClassProperty(car4Pecu4Btn);
    car5Pecu1BtnProperty = new NodePseudoClassProperty(car5Pecu1Btn);
    car5Pecu2BtnProperty = new NodePseudoClassProperty(car5Pecu2Btn);
    car5Pecu3BtnProperty = new NodePseudoClassProperty(car5Pecu3Btn);
    car5Pecu4BtnProperty = new NodePseudoClassProperty(car5Pecu4Btn);
    car6Pecu1BtnProperty = new NodePseudoClassProperty(car6Pecu1Btn);
    car6Pecu2BtnProperty = new NodePseudoClassProperty(car6Pecu2Btn);
    car6Pecu3BtnProperty = new NodePseudoClassProperty(car6Pecu3Btn);
    car6Pecu4BtnProperty = new NodePseudoClassProperty(car6Pecu4Btn);

   

    propertyMap.put(car1Pecu1Btn, car1Pecu1BtnProperty);
    propertyMap.put(car1Pecu2Btn, car1Pecu2BtnProperty);
    propertyMap.put(car1Pecu3Btn, car1Pecu3BtnProperty);
    propertyMap.put(car1Pecu4Btn, car1Pecu4BtnProperty);
    propertyMap.put(car2Pecu1Btn, car2Pecu1BtnProperty);
    propertyMap.put(car2Pecu2Btn, car2Pecu2BtnProperty);
    propertyMap.put(car2Pecu3Btn, car2Pecu3BtnProperty);
    propertyMap.put(car2Pecu4Btn, car2Pecu4BtnProperty);
    propertyMap.put(car3Pecu1Btn, car3Pecu1BtnProperty);
    propertyMap.put(car3Pecu2Btn, car3Pecu2BtnProperty);
    propertyMap.put(car3Pecu3Btn, car3Pecu3BtnProperty);
    propertyMap.put(car3Pecu4Btn, car3Pecu4BtnProperty);
    propertyMap.put(car4Pecu1Btn, car4Pecu1BtnProperty);
    propertyMap.put(car4Pecu2Btn, car4Pecu2BtnProperty);
    propertyMap.put(car4Pecu3Btn, car4Pecu3BtnProperty);
    propertyMap.put(car4Pecu4Btn, car4Pecu4BtnProperty);
    propertyMap.put(car5Pecu1Btn, car5Pecu1BtnProperty);
    propertyMap.put(car5Pecu2Btn, car5Pecu2BtnProperty);
    propertyMap.put(car5Pecu3Btn, car5Pecu3BtnProperty);
    propertyMap.put(car5Pecu4Btn, car5Pecu4BtnProperty);
    propertyMap.put(car6Pecu1Btn, car6Pecu1BtnProperty);
    propertyMap.put(car6Pecu2Btn, car6Pecu2BtnProperty);
    propertyMap.put(car6Pecu3Btn, car6Pecu3BtnProperty);
    propertyMap.put(car6Pecu4Btn, car6Pecu4BtnProperty);

    

    pecuIdMap.put(car1Pecu1Btn, 1);
    pecuIdMap.put(car1Pecu2Btn, 2);
    pecuIdMap.put(car1Pecu3Btn, 3);
    pecuIdMap.put(car1Pecu4Btn, 4);
    pecuIdMap.put(car2Pecu1Btn, 5);
    pecuIdMap.put(car2Pecu2Btn, 6);
    pecuIdMap.put(car2Pecu3Btn, 7);
    pecuIdMap.put(car2Pecu4Btn, 8);
    pecuIdMap.put(car3Pecu1Btn, 9);
    pecuIdMap.put(car3Pecu2Btn, 10);
    pecuIdMap.put(car3Pecu3Btn, 11);
    pecuIdMap.put(car3Pecu4Btn, 12);
    pecuIdMap.put(car4Pecu1Btn, 13);
    pecuIdMap.put(car4Pecu2Btn, 14);
    pecuIdMap.put(car4Pecu3Btn, 15);
    pecuIdMap.put(car4Pecu4Btn, 16);
    pecuIdMap.put(car5Pecu1Btn, 17);
    pecuIdMap.put(car5Pecu2Btn, 18);
    pecuIdMap.put(car5Pecu3Btn, 19);
    pecuIdMap.put(car5Pecu4Btn, 20);
    pecuIdMap.put(car6Pecu1Btn, 21);
    pecuIdMap.put(car6Pecu2Btn, 22);
    pecuIdMap.put(car6Pecu3Btn, 23);
    pecuIdMap.put(car6Pecu4Btn, 24);

   

    for (Entry<Button, NodePseudoClassProperty> entry : propertyMap.entrySet())
    {
      entry.getValue().set("unselected"); //$NON-NLS-1$
    }

  }

  private void updateDateLabel(String newVal)
  {
    this.dateLbl.setText(newVal);
  }

  private void updateTimeLabel(String newVal)
  {
    this.timeLbl.setText(newVal);
  }

  private void sendIsolateDeIsolateReq(Button button)
  {
    if (propertyMap.get(button).get().equals("unselected")) //$NON-NLS-1$
    {
      propertyMap.get(button).set("selected"); //$NON-NLS-1$
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(PAPISInputs.PECU_ISOLATE_ID_REQ,
          pecuIdMap.get(button));
    }
    else
    {
      propertyMap.get(button).set("unselected"); //$NON-NLS-1$
      PAPISFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(PAPISInputs.PECU_DEISOLATE_ID_REQ,
          pecuIdMap.get(button));
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onPecuIsolateButtonAction(ActionEvent event)
  {
    sendIsolateDeIsolateReq((Button)event.getSource());
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onBackButtonAction(ActionEvent event)
  {
    PAPISFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.PASSENGER_ALARM_SCREEN);
  }

  private void updateCarConfig(int noOfCars)
  {
   
    if (noOfCars != NUMBER_OF_CARS_ZERO)
    {

      if (noOfCars == NUMBER_OF_CARS_EIGHT)
      {
      

        PecuIsolateScreenEightCarController systemCommandEightCar = new PecuIsolateScreenEightCarController();
        outerGrid.getChildren().add(systemCommandEightCar.createCar(EIGHT_CAR_FXML_NAME));

        sixCarGrid.setVisible(false);
      }
      else
      {
       
        sixCarGrid.setVisible(true);

      }

    }
  }
}
