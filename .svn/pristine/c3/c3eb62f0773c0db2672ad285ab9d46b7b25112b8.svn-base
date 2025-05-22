/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.gui.i18n.CommonStrings;
import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.VcbInterlockScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class VcbInterlockTCarController extends AbstractTCMSController
{
  @FXML
  private Label vcbLbl1;

  @FXML
  private Label vcbLbl2;

  @FXML
  private Label vcbLbl3;

  @FXML
  private Label vcbLbl4;

  @FXML
  private Label vcbLbl5;

  @FXML
  private Label vcbLbl6;

  @FXML
  private Label vcbLbl7;

  @FXML
  private Label vcbLbl8;

  @FXML
  private Label vcbLbl9;

  @FXML
  private Label vcb4DmLbl;

  @FXML
  private Label vcb4TCarLbl;

  @FXML
  private Label vcb5DmLbl;

  @FXML
  private Label vcb5TCarLbl;

  @FXML
  private Label vcb2TCarLbl;

  @FXML
  private Label vcb3TCarLbl;

  @FXML
  private Label vcb6TCarLbl;

  @FXML
  private Label vcb4DmCarLbl;

  @FXML
  private Label vcb5DmCarLbl;

  @FXML
  private Label carLbl;

  @FXML
  private GridPane vcbGrid3;

  private NodePseudoClassProperty vcb1StateProperty;

  private NodePseudoClassProperty vcb2StateProperty;

  private NodePseudoClassProperty vcb3StateProperty;

  private NodePseudoClassProperty vcb4StateProperty;

  private NodePseudoClassProperty vcb5StateProperty;

  private NodePseudoClassProperty vcb6StateProperty;

  private NodePseudoClassProperty vcb7StateProperty;

  private NodePseudoClassProperty vcb8StateProperty;

  private NodePseudoClassProperty vcb9StateProperty;

  private NodePseudoClassProperty vcb2TCarStateProperty;

  private NodePseudoClassProperty vcb3TCarStateProperty;

  private NodePseudoClassProperty vcb4TCarStateProperty;

  private NodePseudoClassProperty vcb5TCarStateProperty;

  private NodePseudoClassProperty vcb6TCarStateProperty;

  private NodePseudoClassProperty vcb4DmCarStateProperty;

  private NodePseudoClassProperty vcbLbl4StateProperty;

  private NodePseudoClassProperty vcb5DmCarStateProperty;

  private NodePseudoClassProperty vcbLbl5StateProperty;

  private ObjectPropertyBase<CarComponentStatesDO> vcb1State;

  private ObjectPropertyBase<CarComponentStatesDO> vcb2State;

  private ObjectPropertyBase<CarComponentStatesDO> vcb3State;

  private ObjectPropertyBase<CarComponentStatesDO> vcb4State;

  private ObjectPropertyBase<CarComponentStatesDO> vcb5State;

  private ObjectPropertyBase<CarComponentStatesDO> vcb6State;

  private ObjectPropertyBase<CarComponentStatesDO> vcb7State;

  private ObjectPropertyBase<CarComponentStatesDO> vcb8State;

  private ObjectPropertyBase<CarComponentStatesDO> vcb9State;

  private VcbInterlockScreenModel vcbInterlockScreenModel;

  private String headerLblString = ApplicationConstants.BLANK;

  private String dmCarLbl = ApplicationConstants.BLANK;

  private String mCarLbl = ApplicationConstants.BLANK;

  private String carLblStr = ApplicationConstants.BLANK;

  private int carIndex;

  public VcbInterlockTCarController(CarConfigurationModel carConfig,
      VcbInterlockScreenModel vcbInterlockScreenModel, String headerLabel, String dmCarLbl, String mCarLbl,
      String carLblStr)
  {
    this.vcbInterlockScreenModel = vcbInterlockScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
    this.headerLblString = headerLabel;
    this.dmCarLbl = dmCarLbl;
    this.mCarLbl = mCarLbl;
    this.carLblStr = carLblStr;

  }

  @Override
  public void detachListeners()
  {
    // To Detach Listeners
  }

  @Override
  public void initializeImpl()
  {

    vcb1StateProperty = new NodePseudoClassProperty(vcbLbl1);
    vcb2StateProperty = new NodePseudoClassProperty(vcbLbl2);
    vcb3StateProperty = new NodePseudoClassProperty(vcbLbl3);
    vcb4StateProperty = new NodePseudoClassProperty(vcbLbl4);
    vcb5StateProperty = new NodePseudoClassProperty(vcbLbl5);
    vcb6StateProperty = new NodePseudoClassProperty(vcbLbl6);
    vcb7StateProperty = new NodePseudoClassProperty(vcbLbl7);
    vcb8StateProperty = new NodePseudoClassProperty(vcbLbl8);
    vcb9StateProperty = new NodePseudoClassProperty(vcbLbl9);

    vcb2TCarStateProperty = new NodePseudoClassProperty(vcb2TCarLbl);
    vcb3TCarStateProperty = new NodePseudoClassProperty(vcb3TCarLbl);
    vcb4TCarStateProperty = new NodePseudoClassProperty(vcb4TCarLbl);
    vcb5TCarStateProperty = new NodePseudoClassProperty(vcb5TCarLbl);
    vcb6TCarStateProperty = new NodePseudoClassProperty(vcb6TCarLbl);

    vcb4DmCarStateProperty = new NodePseudoClassProperty(vcb4DmLbl);
    vcb5DmCarStateProperty = new NodePseudoClassProperty(vcb5DmLbl);

    vcbLbl4StateProperty = new NodePseudoClassProperty(vcb4DmCarLbl);
    vcbLbl5StateProperty = new NodePseudoClassProperty(vcb5DmCarLbl);

    vcb1State = vcbInterlockScreenModel.getVcbByTransformerState(carIndex);
    vcb1State.addListener(observable -> updateVcb1State());
    updateVcb1State();

    vcb2State = vcbInterlockScreenModel.getVcbByAcOverCurrentState(carIndex);
    vcb2State.addListener(observable -> updateVcb2State());
    updateVcb2State();

    vcb3State = vcbInterlockScreenModel.getVcbByMtrState(carIndex);
    vcb3State.addListener(observable -> updateVcb3State());
    updateVcb3State();

    vcb4State = vcbInterlockScreenModel.getVcbByIcDmState(carIndex);
    vcb4State.addListener(observable -> updateVcb4State());
    updateVcb4State();

    vcb5State = vcbInterlockScreenModel.getVcbByIcMState(carIndex);
    vcb5State.addListener(observable -> updateVcb5State());
    updateVcb5State();

    vcb6State = vcbInterlockScreenModel.getVcbByApsState(carIndex);
    vcb6State.addListener(observable -> updateVcb6State());
    updateVcb6State();

    vcb7State = vcbInterlockScreenModel.getVcbNoLineVoltageState(carIndex);
    vcb7State.addListener(observable -> updateVcb7State());
    updateVcb7State();

    vcb8State = vcbInterlockScreenModel.getVcbByApsAkState(carIndex);
    vcb8State.addListener(observable -> updateVcb8State());
    updateVcb8State();

    vcb9State = vcbInterlockScreenModel.getVcbByCiAkState(carIndex);
    vcb9State.addListener(observable -> updateVcb9State());
    updateVcb9State();

    updateCarLabel(headerLblString);
    updateCarNameLabel(dmCarLbl, mCarLbl, carLblStr);
  }

  private void updateVcb9State()
  {
    vcb9StateProperty.set(vcb9State.get().getComponentState().toLowerCase());
  }

  private void updateVcb8State()
  {
    vcb8StateProperty.set(vcb8State.get().getComponentState().toLowerCase());
  }

  private void updateVcb7State()
  {
    vcb7StateProperty.set(vcb7State.get().getComponentState().toLowerCase());
  }

  private void updateVcb6State()
  {
    vcb6StateProperty.set(vcb6State.get().getComponentState().toLowerCase());
    vcb6TCarStateProperty.set(vcb6State.get().getComponentState().toLowerCase());
  }

  private void updateVcb5State()
  {
    vcb5StateProperty.set(vcb5State.get().getComponentState().toLowerCase());
    vcb5TCarStateProperty.set(vcb5State.get().getComponentState().toLowerCase());
    vcb5DmCarStateProperty.set(vcb5State.get().getComponentState().toLowerCase());
    vcbLbl5StateProperty.set(vcb5State.get().getComponentState().toLowerCase());
  }

  private void updateVcb4State()
  {
    vcb4StateProperty.set(vcb4State.get().getComponentState().toLowerCase());
    vcb4TCarStateProperty.set(vcb4State.get().getComponentState().toLowerCase());
    vcb4DmCarStateProperty.set(vcb4State.get().getComponentState().toLowerCase());
    vcbLbl4StateProperty.set(vcb4State.get().getComponentState().toLowerCase());
  }

  private void updateVcb3State()
  {
    vcb3StateProperty.set(vcb3State.get().getComponentState().toLowerCase());
    vcb3TCarStateProperty.set(vcb3State.get().getComponentState().toLowerCase());
  }

  private void updateVcb2State()
  {
    vcb2StateProperty.set(vcb2State.get().getComponentState().toLowerCase());
    vcb2TCarStateProperty.set(vcb2State.get().getComponentState().toLowerCase());
  }

  private void updateVcb1State()
  {
    vcb1StateProperty.set(vcb1State.get().getComponentState().toLowerCase());
  }

  private void updateCarNameLabel(String dmCarLblString, String mCarLblString, String carLblStr)
  {
    if (mCarLblString.equals(CommonStrings.BLANK))
    {
      vcb5DmLbl.setText(CommonStrings.BLANK);
      vcb5DmCarLbl.setText(CommonStrings.BLANK);
      vcb5TCarLbl.setText(CommonStrings.BLANK);
      vcbLbl5.setText(CommonStrings.BLANK);
    }
    else
    {
      vcb5DmLbl.setText(mCarLblString);
      vcb5TCarLbl.setText(carLblStr);
    }
    vcb4DmLbl.setText(dmCarLblString);
    vcb2TCarLbl.setText(carLblStr);
    vcb2TCarLbl.setText(carLblStr);
    vcb3TCarLbl.setText(carLblStr);
    vcb4TCarLbl.setText(carLblStr);
    vcb6TCarLbl.setText(carLblStr);
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
