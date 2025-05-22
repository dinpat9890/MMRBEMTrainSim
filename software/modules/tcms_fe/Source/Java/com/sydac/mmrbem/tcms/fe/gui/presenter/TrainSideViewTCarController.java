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

public class TrainSideViewTCarController extends AbstractTrainSideViewPanelController
{

  @FXML
  private Label pantoLbl;

  @FXML
  private Label vcbLbl;

  public TrainSideViewTCarController(CarConfigurationModel carConfig,
      TrainSideViewComponentStatusModel carComponentStatusModel)
  {
    super(carConfig, carComponentStatusModel);
  }

  @Override
  public void detachListeners()
  {
    // No Listeners Attached
  }

  @Override
  public void initializeImpl()
  {
    super.initializeImpl();

    NodePseudoClassProperty pantoStateProperty = new NodePseudoClassProperty(pantoLbl);
    NodePseudoClassProperty vcbStateProperty = new NodePseudoClassProperty(vcbLbl);

    ObjectPropertyBase<CarComponentStatesDO> pantoState = carComponentStatusModel
        .pantographStatusProperty(carIndex);
    pantoState.addListener(
        observable -> pantoStateProperty.set(pantoState.get().getComponentState().toLowerCase()));
    pantoStateProperty.set(pantoState.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> vcbState = carComponentStatusModel.vcbStatusProperty(carIndex);
    vcbState
        .addListener(observable -> vcbStateProperty.set(vcbState.get().getComponentState().toLowerCase()));
    vcbStateProperty.set(vcbState.get().getComponentState().toLowerCase());

    initUI();
  }
}
