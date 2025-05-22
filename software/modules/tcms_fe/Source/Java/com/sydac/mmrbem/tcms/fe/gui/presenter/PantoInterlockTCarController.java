/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.PantographInterlockScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class PantoInterlockTCarController extends AbstractTCMSController
{
  @FXML
  private Label pantoLbl1;

  @FXML
  private Label pantoLbl2;

  @FXML
  private Label carLbl;

  private NodePseudoClassProperty panto1StateProperty;

  private NodePseudoClassProperty panto2StateProperty;

  private ObjectPropertyBase<CarComponentStatesDO> panto1State;

  private ObjectPropertyBase<CarComponentStatesDO> panto2State;

  private PantographInterlockScreenModel pantographInterlockScreenModel;

  private String carLblString = ApplicationConstants.BLANK;

  private int carIndex;

  public PantoInterlockTCarController(CarConfigurationModel carConfig,
      PantographInterlockScreenModel pantographInterlockScreenModel, String carLabel)
  {
    this.pantographInterlockScreenModel = pantographInterlockScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
    this.carLblString = carLabel;
  }

  @Override
  public void detachListeners()
  {
    // To Detach Listeners
  }

  @Override
  public void initializeImpl()
  {

    panto1StateProperty = new NodePseudoClassProperty(pantoLbl1);
    panto2StateProperty = new NodePseudoClassProperty(pantoLbl2);

    panto1State = pantographInterlockScreenModel.acpmStatusProperty(carIndex);
    panto1State.addListener(
        observable -> panto1StateProperty.set(panto1State.get().getComponentState().toLowerCase()));
    panto1StateProperty.set(panto1State.get().getComponentState().toLowerCase());

    panto2State = pantographInterlockScreenModel.ocpmStatusProperty(carIndex);
    panto2State.addListener(
        observable -> panto2StateProperty.set(panto2State.get().getComponentState().toLowerCase()));
    panto2StateProperty.set(panto1State.get().getComponentState().toLowerCase());
    updateCarLabel(carLblString);
  }

  private void updateCarLabel(String carLblString)
  {
    carLbl.setText(carLblString);
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
