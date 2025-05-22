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

import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FooterPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainTopViewComponentStatusModel;

public class TrainTopViewTCarController extends AbstractTrainTopViewPanelController
{

  private String carOrientation;

  protected TrainTopViewTCarController(CarConfigurationModel carConfig,
      TrainTopViewComponentStatusModel carComponentStatusModel, FooterPanelModel footerPanelModel)
  {
    super(carConfig, carComponentStatusModel, footerPanelModel);
    carOrientation = carConfig.getCarOrientation();
  }

  @Override
  public void detachListeners()
  {
    // TODO Auto-generated method stub
  }

  @Override
  public void initializeImpl()
  {
    super.initializeImpl();
    initUI();

    if (carOrientation.equals(TCMSConstants.CAR_ORIENTATION_1_2))
    {
      doorA1State = carComponentStatusModel.doorA1StatusProperty(carIndex);
      doorA2State = carComponentStatusModel.doorA2StatusProperty(carIndex);
      doorA3State = carComponentStatusModel.doorA3StatusProperty(carIndex);
      doorA4State = carComponentStatusModel.doorA4StatusProperty(carIndex);
      doorB1State = carComponentStatusModel.doorB1StatusProperty(carIndex);
      doorB2State = carComponentStatusModel.doorB2StatusProperty(carIndex);
      doorB3State = carComponentStatusModel.doorB3StatusProperty(carIndex);
      doorB4State = carComponentStatusModel.doorB4StatusProperty(carIndex);
    }
    else if (carOrientation.equals(TCMSConstants.CAR_ORIENTATION_2_1))
    {
      doorA1State = carComponentStatusModel.doorA4StatusProperty(carIndex);
      doorA2State = carComponentStatusModel.doorA3StatusProperty(carIndex);
      doorA3State = carComponentStatusModel.doorA2StatusProperty(carIndex);
      doorA4State = carComponentStatusModel.doorA1StatusProperty(carIndex);
      doorB1State = carComponentStatusModel.doorB4StatusProperty(carIndex);
      doorB2State = carComponentStatusModel.doorB3StatusProperty(carIndex);
      doorB3State = carComponentStatusModel.doorB2StatusProperty(carIndex);
      doorB4State = carComponentStatusModel.doorB1StatusProperty(carIndex);
    }

    doorA1State.addListener(observable -> doorA1PseudoClassProperty
        .set(doorA1State.get().getDoorState().toString().toLowerCase()));
    doorA2State.addListener(observable -> doorA2PseudoClassProperty
        .set(doorA2State.get().getDoorState().toString().toLowerCase()));
    doorA3State.addListener(observable -> doorA3PseudoClassProperty
        .set(doorA3State.get().getDoorState().toString().toLowerCase()));
    doorA4State.addListener(observable -> doorA4PseudoClassProperty
        .set(doorA4State.get().getDoorState().toString().toLowerCase()));
    doorB1State.addListener(observable -> doorB1PseudoClassProperty
        .set(doorB1State.get().getDoorState().toString().toLowerCase()));
    doorB2State.addListener(observable -> doorB2PseudoClassProperty
        .set(doorB2State.get().getDoorState().toString().toLowerCase()));
    doorB3State.addListener(observable -> doorB3PseudoClassProperty
        .set(doorB3State.get().getDoorState().toString().toLowerCase()));
    doorB4State.addListener(observable -> doorB4PseudoClassProperty
        .set(doorB4State.get().getDoorState().toString().toLowerCase()));

    doorA1PseudoClassProperty.set(doorA1State.get().getDoorState().toString().toLowerCase());
    doorA2PseudoClassProperty.set(doorA2State.get().getDoorState().toString().toLowerCase());
    doorA3PseudoClassProperty.set(doorA3State.get().getDoorState().toString().toLowerCase());
    doorA4PseudoClassProperty.set(doorA4State.get().getDoorState().toString().toLowerCase());
    doorB1PseudoClassProperty.set(doorB1State.get().getDoorState().toString().toLowerCase());
    doorB2PseudoClassProperty.set(doorB2State.get().getDoorState().toString().toLowerCase());
    doorB3PseudoClassProperty.set(doorB3State.get().getDoorState().toString().toLowerCase());
    doorB4PseudoClassProperty.set(doorB4State.get().getDoorState().toString().toLowerCase());
  }

}
