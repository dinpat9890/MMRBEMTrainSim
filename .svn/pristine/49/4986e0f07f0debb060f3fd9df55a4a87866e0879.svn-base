/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsOdometerScreenProperties;

/**
 * This handler class is used for Odometer Screen change handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class OdometerScreenChangeHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  public OdometerScreenChangeHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsOperatingScreenProperties.class);
    this.sharedModel = aSharedModel;
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if ((sharedModel.getCurrentActiveCabId() == vehicleIndex)
        && ITCMSVehicleOutputsOperatingScreenProperties.ODOMETER.equals(key))
    {
      Integer odometerValue = (int)Math.ceil((Double)newValue);
      setApplicationOutputsProperty(IAppOutputsOdometerScreenProperties.ODOMETER_VALUE, odometerValue);
    }
  }
}
