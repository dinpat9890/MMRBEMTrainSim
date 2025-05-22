/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsDoorLoopInterlocksScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.DoorLoopInterlocksScreenModel;

public class DoorLoopInterlocksScreenBinder extends AbstractCommsListener
{

  private DoorLoopInterlocksScreenModel doorLoopInterlocksScreenModel;

  public DoorLoopInterlocksScreenBinder(DoorLoopInterlocksScreenModel doorLoopInterlocksScreenModel)
  {
    super();
    this.doorLoopInterlocksScreenModel = doorLoopInterlocksScreenModel;
    propertyKeyDefinitions.add(IAppOutputsDoorLoopInterlocksScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsDoorLoopInterlocksScreenProperties.LEFT_DOOR_OPEN_STATUS.equals(key))
    {
      doorLoopInterlocksScreenModel.setLeftDoorOpenStatusList((byte[])newValue);
    }
    else if (IAppOutputsDoorLoopInterlocksScreenProperties.RIGHT_DOOR_OPEN_STATUS.equals(key))
    {
      doorLoopInterlocksScreenModel.setRightDoorOpenStatusList((byte[])newValue);
    }
    else if (IAppOutputsDoorLoopInterlocksScreenProperties.EMG_DOOR_OPEN_STATUS.equals(key))
    {
      doorLoopInterlocksScreenModel.setEmgDoorOpenStatusList((byte[])newValue);
    }
    else if (IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS.equals(key))
    {
      doorLoopInterlocksScreenModel.setNumberOfCars((Integer)newValue);
    }
    else if (IAppOutputsDoorLoopInterlocksScreenProperties.PABR_DE_ENERGIZED_IN_DM1.equals(key))
    {
      doorLoopInterlocksScreenModel.setPabrDeEnergizedInDm1((Integer)newValue);
    }
    else if (IAppOutputsDoorLoopInterlocksScreenProperties.PABR_DE_ENERGIZED_IN_DM6.equals(key))
    {
      doorLoopInterlocksScreenModel.setPabrDeEnergizedInDm6((Integer)newValue);
    }
    else if (IAppOutputsDoorLoopInterlocksScreenProperties.PABR_DE_ENERGIZED_IN_DM8.equals(key))
    {
      doorLoopInterlocksScreenModel.setPabrDeEnergizedInDm8((Integer)newValue);
    }
  }
}
