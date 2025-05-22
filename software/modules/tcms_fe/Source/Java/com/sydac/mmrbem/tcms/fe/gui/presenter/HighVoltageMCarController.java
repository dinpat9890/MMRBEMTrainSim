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
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class HighVoltageMCarController extends AbstractTCMSController
{
  @FXML
  private Label carLbl;

  @FXML
  private Label kContactorLbl;

  @FXML
  private Label akContactorLbl;

  @FXML
  private Label ciLbl;

  private NodePseudoClassProperty akContactorStateProperty;

  private NodePseudoClassProperty kContactorStateProperty;

  private NodePseudoClassProperty ciStateProperty;

  private ObjectPropertyBase<CarComponentStatesDO> akContactorState;

  private ObjectPropertyBase<CarComponentStatesDO> kContactorState;

  private ObjectPropertyBase<CarComponentStatesDO> ciState;

  private HighVoltageScreenModel highVoltageScreenModel;

  private String carLblString = ApplicationConstants.BLANK;

  private int carIndex;

  public HighVoltageMCarController(CarConfigurationModel carConfig,
      HighVoltageScreenModel highVoltageScreenModel, String carLbl)
  {
    this.highVoltageScreenModel = highVoltageScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
    this.carLblString = carLbl;
  }

  private void updateCarLabel(String carLabel)
  {
    carLbl.setText(carLabel);
  }

  @Override
  public void initializeImpl()
  {
    updateCarLabel(carLblString);

    akContactorStateProperty = new NodePseudoClassProperty(akContactorLbl);
    kContactorStateProperty = new NodePseudoClassProperty(kContactorLbl);
    ciStateProperty = new NodePseudoClassProperty(ciLbl);

    akContactorState = highVoltageScreenModel.akContactorStatusProperty(carIndex);
    akContactorState.addListener(
        observable -> akContactorStateProperty.set(akContactorState.get().getComponentState().toLowerCase()));
    akContactorStateProperty.set(akContactorState.get().getComponentState().toLowerCase());

    kContactorState = highVoltageScreenModel.kContactorStatusProperty(carIndex);
    kContactorState.addListener(
        observable -> kContactorStateProperty.set(kContactorState.get().getComponentState().toLowerCase()));
    kContactorStateProperty.set(kContactorState.get().getComponentState().toLowerCase());

    ciState = highVoltageScreenModel.ciStatusProperty(carIndex);
    ciState.addListener(observable -> ciStateProperty.set(ciState.get().getComponentState().toLowerCase()));
    ciStateProperty.set(ciState.get().getComponentState().toLowerCase());
  }

  @Override
  public void detachListeners()
  {
    // To Detach Listeners
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
