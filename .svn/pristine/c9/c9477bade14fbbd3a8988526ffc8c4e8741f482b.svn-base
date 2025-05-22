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

public class MediumVoltageSystemTCarController extends AbstractTCMSController
{

  @FXML
  private Label carLbl;

  @FXML
  private Label aps1Lbl;

  @FXML
  private Label aps2Lbl;

  @FXML
  private Label hvac1Lbl;

  @FXML
  private Label hvac2Lbl;

  @FXML
  private Label auxCompLbl;

  @FXML
  private Label pecLbl;

  @FXML
  private Label mtrBlowerLowLbl;

  @FXML
  private Label mtrBlowerHighLbl;

  @FXML
  private Label shoreSupplyLbl;

  private MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel;

  private int carIndex;

  private String carLblString = ApplicationConstants.BLANK;

  public MediumVoltageSystemTCarController(CarConfigurationModel carConfig,
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

    NodePseudoClassProperty aps1StateProperty = new NodePseudoClassProperty(aps1Lbl);
    NodePseudoClassProperty aps2StateProperty = new NodePseudoClassProperty(aps2Lbl);
    NodePseudoClassProperty auxCompStateProperty = new NodePseudoClassProperty(auxCompLbl);
    NodePseudoClassProperty hvac1StateProperty = new NodePseudoClassProperty(hvac1Lbl);
    NodePseudoClassProperty hvac2StateProperty = new NodePseudoClassProperty(hvac2Lbl);
    NodePseudoClassProperty pecStateProperty = new NodePseudoClassProperty(pecLbl);

    ObjectPropertyBase<CarComponentStatesDO> aps1State = mediumVoltageSystemScreenModel
        .apsStatus1Property(carIndex);
    aps1State
        .addListener(observable -> aps1StateProperty.set(aps1State.get().getComponentState().toLowerCase()));
    aps1StateProperty.set(aps1State.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> aps2State = mediumVoltageSystemScreenModel
        .apsStatus2Property(carIndex);
    aps2State
        .addListener(observable -> aps2StateProperty.set(aps2State.get().getComponentState().toLowerCase()));
    aps2StateProperty.set(aps2State.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> pecState = mediumVoltageSystemScreenModel
        .pecStatusProperty(carIndex);
    pecState
        .addListener(observable -> pecStateProperty.set(pecState.get().getComponentState().toLowerCase()));
    pecStateProperty.set(pecState.get().getComponentState().toLowerCase());

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

    ObjectPropertyBase<CarComponentStatesDO> auxCompState = mediumVoltageSystemScreenModel
        .auxCompStatusProperty(carIndex);
    auxCompState.addListener(
        observable -> auxCompStateProperty.set(auxCompState.get().getComponentState().toLowerCase()));
    auxCompStateProperty.set(auxCompState.get().getComponentState().toLowerCase());
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
