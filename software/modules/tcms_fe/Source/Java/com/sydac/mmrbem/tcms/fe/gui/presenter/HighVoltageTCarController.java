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

public class HighVoltageTCarController extends AbstractTCMSController
{
  @FXML
  private Label carLbl;

  @FXML
  private Label pantoLbl;

  @FXML
  private Label vcbLbl;

  @FXML
  private Label egsLbl;

  @FXML
  private Label k1Lbl;

  @FXML
  private Label k2Lbl;

  @FXML
  private Label ak1Lbl;

  @FXML
  private Label ak2Lbl;

  @FXML
  private Label aps1Lbl;

  @FXML
  private Label aps2Lbl;

  private NodePseudoClassProperty pantoStateProperty;

  private NodePseudoClassProperty vcbStateProperty;

  private NodePseudoClassProperty akState1Property;

  private NodePseudoClassProperty akState2Property;

  private NodePseudoClassProperty kState1Property;

  private NodePseudoClassProperty kState2Property;

  private NodePseudoClassProperty apsState1Property;

  private NodePseudoClassProperty apsState2Property;

  private ObjectPropertyBase<CarComponentStatesDO> akState1;

  private ObjectPropertyBase<CarComponentStatesDO> akState2;

  private ObjectPropertyBase<CarComponentStatesDO> kState1;

  private ObjectPropertyBase<CarComponentStatesDO> kState2;

  private ObjectPropertyBase<CarComponentStatesDO> apsState1;

  private ObjectPropertyBase<CarComponentStatesDO> apsState2;

  private ObjectPropertyBase<CarComponentStatesDO> pantoState;

  private ObjectPropertyBase<CarComponentStatesDO> vcbState;

  private HighVoltageScreenModel highVoltageScreenModel;

  private int carIndex;

  private String carLblString = ApplicationConstants.BLANK;

  public HighVoltageTCarController(CarConfigurationModel carConfig,
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

    akState1Property = new NodePseudoClassProperty(ak1Lbl);
    akState2Property = new NodePseudoClassProperty(ak2Lbl);
    kState1Property = new NodePseudoClassProperty(k1Lbl);
    kState2Property = new NodePseudoClassProperty(k2Lbl);
    apsState1Property = new NodePseudoClassProperty(aps1Lbl);
    apsState2Property = new NodePseudoClassProperty(aps2Lbl);
    pantoStateProperty = new NodePseudoClassProperty(pantoLbl);
    vcbStateProperty = new NodePseudoClassProperty(vcbLbl);

    akState1 = highVoltageScreenModel.akStatus1Property(carIndex);
    akState1
        .addListener(observable -> akState1Property.set(akState1.get().getComponentState().toLowerCase()));
    akState1Property.set(akState1.get().getComponentState().toLowerCase());

    akState2 = highVoltageScreenModel.akStatus2Property(carIndex);
    akState2
        .addListener(observable -> akState2Property.set(akState2.get().getComponentState().toLowerCase()));
    akState2Property.set(akState2.get().getComponentState().toLowerCase());

    kState1 = highVoltageScreenModel.kStatus1Property(carIndex);
    kState1.addListener(observable -> kState1Property.set(kState1.get().getComponentState().toLowerCase()));
    kState1Property.set(kState1.get().getComponentState().toLowerCase());

    kState2 = highVoltageScreenModel.kStatus2Property(carIndex);
    kState2.addListener(observable -> kState2Property.set(kState2.get().getComponentState().toLowerCase()));
    kState2Property.set(kState2.get().getComponentState().toLowerCase());

    apsState1 = highVoltageScreenModel.apsStatus1Property(carIndex);
    apsState1
        .addListener(observable -> apsState1Property.set(apsState1.get().getComponentState().toLowerCase()));
    apsState1Property.set(apsState1.get().getComponentState().toLowerCase());

    apsState2 = highVoltageScreenModel.apsStatus2Property(carIndex);
    apsState2
        .addListener(observable -> apsState2Property.set(apsState2.get().getComponentState().toLowerCase()));
    apsState2Property.set(apsState2.get().getComponentState().toLowerCase());

    pantoState = highVoltageScreenModel.pantographStatusProperty(carIndex);
    pantoState.addListener(
        observable -> pantoStateProperty.set(pantoState.get().getComponentState().toLowerCase()));
    pantoStateProperty.set(pantoState.get().getComponentState().toLowerCase());

    vcbState = highVoltageScreenModel.vcbStatusProperty(carIndex);
    vcbState
        .addListener(observable -> vcbStateProperty.set(vcbState.get().getComponentState().toLowerCase()));
    vcbStateProperty.set(vcbState.get().getComponentState().toLowerCase());
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