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
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.DoorSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class CarDCUStatusController extends AbstractTCMSController
{
  @FXML
  protected GridPane mainGrid;

  @FXML
  private Label dcu1Lbl;

  @FXML
  private Label dcu2Lbl;

  @FXML
  private Label dcu3Lbl;

  @FXML
  private Label dcu4Lbl;

  @FXML
  private Label dcu5Lbl;

  @FXML
  private Label dcu6Lbl;

  @FXML
  private Label dcu7Lbl;

  @FXML
  private Label dcu8Lbl;

  private ObjectPropertyBase<CarComponentStatesDO> dcu1State;

  private ObjectPropertyBase<CarComponentStatesDO> dcu2State;

  private ObjectPropertyBase<CarComponentStatesDO> dcu3State;

  private ObjectPropertyBase<CarComponentStatesDO> dcu4State;

  private ObjectPropertyBase<CarComponentStatesDO> dcu5State;

  private ObjectPropertyBase<CarComponentStatesDO> dcu6State;

  private ObjectPropertyBase<CarComponentStatesDO> dcu7State;

  private ObjectPropertyBase<CarComponentStatesDO> dcu8State;

  private DoorSystemScreenModel doorSystemScreenModel;

  private CarConfigurationModel carConfigurationModel;

  private int carIndex;

  public CarDCUStatusController(CarConfigurationModel carConfigurationModel,
      DoorSystemScreenModel doorSystemScreenModel)
  {
    this.doorSystemScreenModel = doorSystemScreenModel;
    this.carConfigurationModel = carConfigurationModel;
    this.carIndex = carConfigurationModel.carIndexProperty().get();
  }

  @Override
  public void detachListeners()
  {
    // No Listeners Attached.
  }

  @Override
  public void initializeImpl()
  {
    NodePseudoClassProperty dcu1NodePseudoClassProperty = new NodePseudoClassProperty(dcu1Lbl);
    NodePseudoClassProperty dcu2NodePseudoClassProperty = new NodePseudoClassProperty(dcu2Lbl);
    NodePseudoClassProperty dcu3NodePseudoClassProperty = new NodePseudoClassProperty(dcu3Lbl);
    NodePseudoClassProperty dcu4NodePseudoClassProperty = new NodePseudoClassProperty(dcu4Lbl);
    NodePseudoClassProperty dcu5NodePseudoClassProperty = new NodePseudoClassProperty(dcu5Lbl);
    NodePseudoClassProperty dcu6NodePseudoClassProperty = new NodePseudoClassProperty(dcu6Lbl);
    NodePseudoClassProperty dcu7NodePseudoClassProperty = new NodePseudoClassProperty(dcu7Lbl);
    NodePseudoClassProperty dcu8NodePseudoClassProperty = new NodePseudoClassProperty(dcu8Lbl);

    if (carConfigurationModel.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_1_2))
    {
      dcu1State = doorSystemScreenModel.dcu1StatusProperty(carIndex);
      dcu2State = doorSystemScreenModel.dcu2StatusProperty(carIndex);
      dcu3State = doorSystemScreenModel.dcu3StatusProperty(carIndex);
      dcu4State = doorSystemScreenModel.dcu4StatusProperty(carIndex);
      dcu5State = doorSystemScreenModel.dcu5StatusProperty(carIndex);
      dcu6State = doorSystemScreenModel.dcu6StatusProperty(carIndex);
      dcu7State = doorSystemScreenModel.dcu7StatusProperty(carIndex);
      dcu8State = doorSystemScreenModel.dcu8StatusProperty(carIndex);
    }
    else if (carConfigurationModel.getCarOrientation().equals(TCMSConstants.CAR_ORIENTATION_2_1))
    {
      dcu1State = doorSystemScreenModel.dcu4StatusProperty(carIndex);
      dcu2State = doorSystemScreenModel.dcu3StatusProperty(carIndex);
      dcu3State = doorSystemScreenModel.dcu2StatusProperty(carIndex);
      dcu4State = doorSystemScreenModel.dcu1StatusProperty(carIndex);
      dcu5State = doorSystemScreenModel.dcu8StatusProperty(carIndex);
      dcu6State = doorSystemScreenModel.dcu7StatusProperty(carIndex);
      dcu7State = doorSystemScreenModel.dcu6StatusProperty(carIndex);
      dcu8State = doorSystemScreenModel.dcu5StatusProperty(carIndex);
    }

    dcu1State.addListener(
        observable -> dcu1NodePseudoClassProperty.set(dcu1State.get().getComponentState().toLowerCase()));
    dcu2State.addListener(
        observable -> dcu2NodePseudoClassProperty.set(dcu2State.get().getComponentState().toLowerCase()));
    dcu3State.addListener(
        observable -> dcu3NodePseudoClassProperty.set(dcu3State.get().getComponentState().toLowerCase()));
    dcu4State.addListener(
        observable -> dcu4NodePseudoClassProperty.set(dcu4State.get().getComponentState().toLowerCase()));
    dcu5State.addListener(
        observable -> dcu5NodePseudoClassProperty.set(dcu5State.get().getComponentState().toLowerCase()));
    dcu6State.addListener(
        observable -> dcu6NodePseudoClassProperty.set(dcu6State.get().getComponentState().toLowerCase()));
    dcu7State.addListener(
        observable -> dcu7NodePseudoClassProperty.set(dcu7State.get().getComponentState().toLowerCase()));
    dcu8State.addListener(
        observable -> dcu8NodePseudoClassProperty.set(dcu8State.get().getComponentState().toLowerCase()));

    dcu1NodePseudoClassProperty.set(dcu1State.get().getComponentState().toLowerCase());
    dcu2NodePseudoClassProperty.set(dcu2State.get().getComponentState().toLowerCase());
    dcu3NodePseudoClassProperty.set(dcu3State.get().getComponentState().toLowerCase());
    dcu4NodePseudoClassProperty.set(dcu4State.get().getComponentState().toLowerCase());
    dcu5NodePseudoClassProperty.set(dcu5State.get().getComponentState().toLowerCase());
    dcu6NodePseudoClassProperty.set(dcu6State.get().getComponentState().toLowerCase());
    dcu7NodePseudoClassProperty.set(dcu7State.get().getComponentState().toLowerCase());
    dcu8NodePseudoClassProperty.set(dcu8State.get().getComponentState().toLowerCase());

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
