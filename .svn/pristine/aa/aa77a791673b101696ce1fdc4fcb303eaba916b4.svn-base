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
import com.sydac.mmrbem.tcms.fe.gui.model.MediumVoltageSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class MediumVoltageSystemDMCarController extends AbstractTCMSController
{

  @FXML
  private Label carLbl;

  @FXML
  private Label mainCompLbl;

  @FXML
  private Label hvac1Lbl;

  @FXML
  private Label hvac2Lbl;

  private MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel;

  private int carIndex;

  private String carLblString = ApplicationConstants.BLANK;

  public MediumVoltageSystemDMCarController(CarConfigurationModel carConfig,
      MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel, String carLabel)
  {
    this.mediumVoltageSystemScreenModel = mediumVoltageSystemScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
    this.carLblString = carLabel;
  }

  private void updateCarLabel(String carLabel)
  {
    carLbl.setText(carLabel);
  }

  @Override
  public void initializeImpl()
  {
    updateCarLabel(carLblString);

    NodePseudoClassProperty mainCompStateProperty = new NodePseudoClassProperty(mainCompLbl);
    NodePseudoClassProperty hvac1StateProperty = new NodePseudoClassProperty(hvac1Lbl);
    NodePseudoClassProperty hvac2StateProperty = new NodePseudoClassProperty(hvac2Lbl);

    ObjectPropertyBase<CarComponentStatesDO> mainCompState = mediumVoltageSystemScreenModel
        .mainCompStatusProperty(carIndex);
    mainCompState.addListener(
        observable -> mainCompStateProperty.set(mainCompState.get().getComponentState().toLowerCase()));
    mainCompStateProperty.set(mainCompState.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> hvac1State = mediumVoltageSystemScreenModel
        .hvac1StatusProperty(carIndex);
    hvac1State.addListener(
        observable -> hvac1StateProperty.set(hvac1State.get().getComponentState().toLowerCase()));
    hvac1StateProperty.set(hvac1State.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> hvac2State = mediumVoltageSystemScreenModel
        .hvac2StatusProperty(carIndex);
    hvac2State.addListener(
        observable -> hvac2StateProperty.set(hvac2State.get().getComponentState().toLowerCase()));
    hvac2StateProperty.set(hvac2State.get().getComponentState().toLowerCase());
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
