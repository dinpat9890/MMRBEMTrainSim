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

import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainSideViewComponentStatusModel;

public class TrainSideViewMCarController extends AbstractTrainSideViewPanelController
{

  public TrainSideViewMCarController(CarConfigurationModel carConfig,
      TrainSideViewComponentStatusModel carComponentStatusModel)
  {
    super(carConfig, carComponentStatusModel);
  }

  @Override
  public void initializeImpl()
  {
    super.initializeImpl();
    initUI();
  }

  @Override
  public void detachListeners()
  {}

}
