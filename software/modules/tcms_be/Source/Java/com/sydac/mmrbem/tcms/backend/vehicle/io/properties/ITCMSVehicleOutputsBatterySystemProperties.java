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

public interface ITCMSVehicleOutputsBatterySystemProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.BCG_1_STATUS)
  PropertyKey<Integer> BCG_1_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BCG_2_STATUS)
  PropertyKey<Integer> BCG_2_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BCG_1_FAULT)
  PropertyKey<Integer> BCG_1_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BCG_2_FAULT)
  PropertyKey<Integer> BCG_2_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BCG_1_ISOLATED)
  PropertyKey<Integer> BCG_1_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.BCG_2_ISOLATED)
  PropertyKey<Integer> BCG_2_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.BCG_OUTPUT_VOLTAGE)
  PropertyKey<Integer> BCG_OUTPUT_VOLTAGE = create();

  @CommsBinding(property = TCMSVehicleOutputs.BATTERY_VOLTAGE)
  PropertyKey<Integer> BATTERY_VOLTAGE = create();

  @CommsBinding(property = TCMSVehicleOutputs.TOTAL_OUTPUT_CURRENT)
  PropertyKey<Integer> TOTAL_OUTPUT_CURRENT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BCG_1_OUTPUT_CURRENT)
  PropertyKey<Integer> BCG_1_OUTPUT_CURRENT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BCG_2_OUTPUT_CURRENT)
  PropertyKey<Integer> BCG_2_OUTPUT_CURRENT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BATTERY_CURRENT)
  PropertyKey<Integer> BATTERY_CURRENT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BATTERY_TEMPERATURE)
  PropertyKey<Integer> BATTERY_TEMPERATURE = create();
}
