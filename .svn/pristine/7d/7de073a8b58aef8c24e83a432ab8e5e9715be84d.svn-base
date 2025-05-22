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

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainSideViewComponentStatusModel;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class TrainSideViewDMCarController extends AbstractTrainSideViewPanelController
{

  @FXML
  private Label dmDrivingCabLbl;

  @FXML
  private Label dmDirectionLbl;

  @FXML
  private Label carCaptionLbl;

  private NodePseudoClassProperty cabActiveStateProperty;

  private NodePseudoClassProperty cabDirectionStateProperty;

  private ObjectPropertyBase<CarComponentStatesDO> activeDrivingCabState;

  private ObjectPropertyBase<CarComponentStatesDO> cabDirectionState;

  public TrainSideViewDMCarController(CarConfigurationModel carConfig,
      TrainSideViewComponentStatusModel carComponentStatusModel)
  {
    super(carConfig, carComponentStatusModel);
  }

  @Override
  public void detachListeners()
  {}

  @Override
  public void initializeImpl()
  {
    super.initializeImpl();

    cabActiveStateProperty = new NodePseudoClassProperty(dmDrivingCabLbl);
    cabDirectionStateProperty = new NodePseudoClassProperty(dmDirectionLbl);

    activeDrivingCabState = carComponentStatusModel.cabActiveStatusProperty(carIndex);
    activeDrivingCabState.addListener(observable -> cabActiveStateProperty
        .set(activeDrivingCabState.get().getComponentState().toLowerCase()));
    cabActiveStateProperty.set(activeDrivingCabState.get().getComponentState().toLowerCase());

    cabDirectionState = carComponentStatusModel.cabDirectionStatusProperty(carIndex);
    cabDirectionState.addListener(observable -> cabDirectionStateProperty
        .set(cabDirectionState.get().getComponentState().toLowerCase()));
    cabDirectionStateProperty.set(cabDirectionState.get().getComponentState().toLowerCase());

    initUI();
  }

}
