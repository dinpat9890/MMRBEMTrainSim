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
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainTopViewComponentProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.BrakeSystemCommandsScreenModel;

public class BrakeSystemCommandsScreenBinder extends AbstractCommsListener
{

  private BrakeSystemCommandsScreenModel brakeSystemCommandsScreenModel;

  public BrakeSystemCommandsScreenBinder(BrakeSystemCommandsScreenModel brakeSystemCommandsScreenModel)
  {
    super();
    this.brakeSystemCommandsScreenModel = brakeSystemCommandsScreenModel;
    propertyKeyDefinitions.add(IAppOutputsTrainTopViewComponentProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS.equals(key))
    {
      brakeSystemCommandsScreenModel.setTotalColumn((Integer)newValue);
    }
    else if (IAppOutputsTrainTopViewComponentProperties.PARKING_BRAKE_STATUS.equals(key))
    {
      brakeSystemCommandsScreenModel.setParkingBrakeState((byte[])newValue);
    }
  }
}
