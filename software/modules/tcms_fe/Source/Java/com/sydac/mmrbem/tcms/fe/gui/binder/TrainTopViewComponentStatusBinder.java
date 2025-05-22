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
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainTopViewComponentProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainTopViewComponentStatusModel;

public class TrainTopViewComponentStatusBinder extends AbstractCommsListener
{

  private TrainTopViewComponentStatusModel trainTopViewComponentStatusModel;

  public TrainTopViewComponentStatusBinder(TrainTopViewComponentStatusModel trainTopViewComponentStatusModel)
  {
    super();
    this.trainTopViewComponentStatusModel = trainTopViewComponentStatusModel;
    propertyKeyDefinitions.add(IAppOutputsTrainTopViewComponentProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_A1.equals(key))
    {
      trainTopViewComponentStatusModel.setDoorA1State((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_A2.equals(key))
    {
      trainTopViewComponentStatusModel.setDoorA2State((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_A3.equals(key))
    {
      trainTopViewComponentStatusModel.setDoorA3State((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_A4.equals(key))
    {
      trainTopViewComponentStatusModel.setDoorA4State((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_B1.equals(key))
    {
      trainTopViewComponentStatusModel.setDoorB1State((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_B2.equals(key))
    {
      trainTopViewComponentStatusModel.setDoorB2State((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_B3.equals(key))
    {
      trainTopViewComponentStatusModel.setDoorB3State((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_B4.equals(key))
    {
      trainTopViewComponentStatusModel.setDoorB4State((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_DETRAINMENT.equals(key))
    {
      trainTopViewComponentStatusModel.setDetrainmentDoorState((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.PARKING_BRAKE_STATUS.equals(key))
    {
      trainTopViewComponentStatusModel.setParkingBrakeState((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.SERVICE_BRAKE_STATUS.equals(key))
    {
      trainTopViewComponentStatusModel.setServiceBrakeState((byte[])newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.PROPULSION_STATUS.equals(key))
    {
      trainTopViewComponentStatusModel.setPropulsionState((byte[])newValue);
    }
  }

}
