/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsBatterySystemScreenProperties
{
  @CommsBinding(property = VDUOutputs.BCG_STATUS)
  PropertyKey<byte[]> BCG_STATUS = create();

  @CommsBinding(property = VDUOutputs.BCG_OUTPUT_VOLTAGE_STATUS)
  PropertyKey<byte[]> BCG_OUTPUT_VOLTAGE_STATUS = create();

  @CommsBinding(property = VDUOutputs.BATTERY_VOLTAGE_STATUS)
  PropertyKey<byte[]> BATTERY_VOLTAGE_STATUS = create();

  @CommsBinding(property = VDUOutputs.OUTPUT_CURRENT_STATUS)
  PropertyKey<byte[]> OUTPUT_CURRENT_STATUS = create();

  @CommsBinding(property = VDUOutputs.TOTAL_OUTPUT_CURRENT_STATUS)
  PropertyKey<byte[]> TOTAL_OUTPUT_CURRENT_STATUS = create();

  @CommsBinding(property = VDUOutputs.BATTERY_CURRENT_STATUS)
  PropertyKey<byte[]> BATTERY_CURRENT_STATUS = create();

  @CommsBinding(property = VDUOutputs.BATTERY_TEMPERATURE_STATUS)
  PropertyKey<byte[]> BATTERY_TEMPERATURE_STATUS = create();
}
