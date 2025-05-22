/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.TCMSVehicleOutputs;

/**
 * This interface holds variable for WFL system of TCMSVehicleOutputs variables.
 */
public interface ITCMSVehicleOutputsWFLSystemProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.WFL_ISOLATED)
  PropertyKey<Integer> WFL_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.WFL_STATUS)
  PropertyKey<Integer> WFL_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.WFL_FAULT)
  PropertyKey<Integer> WFL_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.WFL_OIL_LEVEL_STATUS)
  PropertyKey<Integer> WFL_OIL_LEVEL_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.WFL_PUMP_1)
  PropertyKey<Integer> WFL_PUMP_1 = create();

  @CommsBinding(property = TCMSVehicleOutputs.WFL_PUMP_2)
  PropertyKey<Integer> WFL_PUMP_2 = create();
}
