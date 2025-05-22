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
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.Frontend;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.HeaderPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HeaderPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainSideViewComponentStatusModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputsValues;

import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public abstract class AbstractTrainSideViewPanelController extends AbstractTCMSController
{

  @FXML
  protected GridPane mainGrid;

  @FXML
  protected Label carCaptionLbl;

  @FXML
  protected Label cabFaultStatusLbl;

  @FXML
  protected Label bogie1Lbl;

  @FXML
  protected Label bogie2Lbl;

  protected NodePseudoClassProperty bogie1PseudoClassProperty;

  protected NodePseudoClassProperty bogie2PseudoClassProperty;

  protected NodePseudoClassProperty cabFaultStatePseudoClassProperty;

  private ObjectPropertyBase<CarComponentStatesDO> bogie1State;

  private ObjectPropertyBase<CarComponentStatesDO> bogie2State;

  private ObjectPropertyBase<CarComponentStatesDO> cabFaultState;

  protected CarConfigurationModel carConfigModel;

  protected TrainSideViewComponentStatusModel carComponentStatusModel;

  private HeaderPanelModel headerPanelModel;

  private ChangeListener<Number> currentScreenIdListener;

  private int currentScreenId;

  protected int carIndex;

  private NodePseudoClassProperty propertyNode;

  protected AbstractTrainSideViewPanelController(CarConfigurationModel carConfigModel,
      TrainSideViewComponentStatusModel carComponentStatusModel)
  {
    this.carConfigModel = carConfigModel;
    this.carComponentStatusModel = carComponentStatusModel;
    this.carIndex = carConfigModel.carIndexProperty().get();
  }

  @Override
  public void initializeImpl()
  {
    headerPanelModel = new HeaderPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HeaderPanelBinder(headerPanelModel));

    propertyNode = new NodePseudoClassProperty(carCaptionLbl);

    currentScreenIdListener = (observable, oldVal, newVal) -> updateCurrentScreenId((int)newVal);
    headerPanelModel.getCurrentScreenId().addListener(currentScreenIdListener);

    carCaptionLbl.textProperty().bind(carConfigModel.carDisplayNameProperty());

    carCaptionLbl.setOnMouseClicked(event -> changeScreenToShowFireDetectionDetailsScreen());

    bogie1PseudoClassProperty = new NodePseudoClassProperty(bogie1Lbl);
    bogie2PseudoClassProperty = new NodePseudoClassProperty(bogie2Lbl);
    cabFaultStatePseudoClassProperty = new NodePseudoClassProperty(cabFaultStatusLbl);

    bogie1State = carComponentStatusModel.bogie1StatusProperty(carIndex);
    bogie2State = carComponentStatusModel.bogie2StatusProperty(carIndex);
    cabFaultState = carComponentStatusModel.cabFaultStatusProperty(carIndex);

    bogie1State.addListener(observable -> {
      updateOrientation();
    });

    bogie2State.addListener(observable -> {
      updateOrientation();
    });
    cabFaultState.addListener(
        observable -> cabFaultStatePseudoClassProperty.set(cabFaultState.get().getComponentState()));
  }

  private void updateCurrentScreenId(int newVal)
  {
    currentScreenId = newVal;
  }

  private void changeScreenToShowFireDetectionDetailsScreen()
  {
    int carIndex = carConfigModel.carIndexProperty().get();
    String carType = carConfigModel.carTypeProperty().get();

    if (currentScreenId == 15 || currentScreenId == 63 || currentScreenId == 64)
    {
      propertyNode.set(CarType.valueByCarTypeCode(carType) == CarType.DM ? "select" : "deselect");
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputsValues.FIRE_DETECTION_SELECTED_CAR_INDEX_REQ, carIndex);

      if (carIndex == 0)
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendScreenChangeRequest(ScreenId.FIRE_DECTECTION_SYSTEM_DETAILS_SCREEN, Frontend.TCMS);
      }
      else
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendScreenChangeRequest(ScreenId.FDS_DETAILS_SCREEN_OTHER_CARS, Frontend.TCMS);
      }

    }
  }

  protected void initUI()
  {
    bogie1PseudoClassProperty.set(bogie1State.get().getComponentState().toLowerCase());
    bogie2PseudoClassProperty.set(bogie2State.get().getComponentState().toLowerCase());
    cabFaultStatePseudoClassProperty.set(cabFaultState.get().getComponentState());
  }

  private void updateOrientation()
  {
    if (carConfigModel.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
    {
      bogie1PseudoClassProperty.set(bogie1State.get().getComponentState().toLowerCase());
      bogie2PseudoClassProperty.set(bogie2State.get().getComponentState().toLowerCase());
    }
    else if (carConfigModel.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
    {
      bogie1PseudoClassProperty.set(bogie2State.get().getComponentState().toLowerCase());
      bogie2PseudoClassProperty.set(bogie1State.get().getComponentState().toLowerCase());
    }
  }

  public GridPane createCar(String fxmlName, int carPanelSize)
  {
    GridPane gridPane;
    FXMLLoader fxmlLoader = new FXMLLoader(ViewPackage.class.getResource(fxmlName));
    fxmlLoader.setController(this);
    try
    {
      gridPane = fxmlLoader.load();
      gridPane.setPrefWidth(carPanelSize);
      gridPane.setPrefHeight(TCMSUIConstants.TRAIN_SIDE_VIEW_PANEL_HEIGHT);
    }
    catch (IOException exception)
    {
      logger.error(exception);
      throw new LoadingException(exception);
    }
    return gridPane;
  }

}
