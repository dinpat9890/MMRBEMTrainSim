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

public interface IAppOutputsPropulsionSystemScreenProperties
{
  @CommsBinding(property = VDUOutputs.PROPULSION_ENABLED_STATUS)
  PropertyKey<byte[]> PROPULSION_ENABLED_STATUS = create();

  @CommsBinding(property = VDUOutputs.AK_CONTACTOR_STATUS)
  PropertyKey<byte[]> AK_CONTACTOR_STATUS = create();

  @CommsBinding(property = VDUOutputs.K_CONTACTOR_STATUS)
  PropertyKey<byte[]> K_CONTACTOR_STATUS = create();

  @CommsBinding(property = VDUOutputs.DYNAMIC_BRAKE_STATUS)
  PropertyKey<byte[]> DYNAMIC_BRAKE_STATUS = create();

  @CommsBinding(property = VDUOutputs.VCB_TRIP_COMMAND_STATUS)
  PropertyKey<byte[]> VCB_TRIP_COMMAND_STATUS = create();

  @CommsBinding(property = VDUOutputs.FILTER_VOLTAGE_STATUS)
  PropertyKey<byte[]> FILTER_VOLTAGE_STATUS = create();

  @CommsBinding(property = VDUOutputs.TRACTIVE_EFFORT_STATUS)
  PropertyKey<byte[]> TRACTIVE_EFFORT_STATUS = create();
}
