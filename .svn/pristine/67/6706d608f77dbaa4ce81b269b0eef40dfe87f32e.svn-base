/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainSideViewComponentProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainSideViewComponentStatusModel;

public class TrainSideViewComponentStatusBinder extends AbstractCommsListener
{

  private TrainSideViewComponentStatusModel trainSideViewComponentStatusModel;

  public TrainSideViewComponentStatusBinder(TrainSideViewComponentStatusModel carComponentStatusModel)
  {
    super();
    this.trainSideViewComponentStatusModel = carComponentStatusModel;
    propertyKeyDefinitions.add(IAppOutputsTrainSideViewComponentProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainSideViewComponentProperties.PANTOGRAPH_STATUS.equals(key))
    {
      trainSideViewComponentStatusModel.setPantographState((byte[])newValue);
    }
    else if (IAppOutputsTrainSideViewComponentProperties.VCB_STATUS.equals(key))
    {
      trainSideViewComponentStatusModel.setVcbState((byte[])newValue);
    }
    else if (IAppOutputsTrainSideViewComponentProperties.TRAIN_SIDE_VIEW_STATUS.equals(key))
    {
      trainSideViewComponentStatusModel.setTrainSideViewState((byte[])newValue);
    }
    else if (IAppOutputsTrainSideViewComponentProperties.DRIVER_CAB_DIRECTION.equals(key))
    {
      trainSideViewComponentStatusModel.setCabDirectionState((byte[])newValue);
    }
    else if (IAppOutputsTrainSideViewComponentProperties.CAB_FAULT_STATE.equals(key))
    {
      trainSideViewComponentStatusModel.setCabFaultState((byte[])newValue);
    }
  }

}
