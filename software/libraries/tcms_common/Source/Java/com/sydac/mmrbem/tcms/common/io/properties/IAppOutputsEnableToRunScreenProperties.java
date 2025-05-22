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

public interface IAppOutputsEnableToRunScreenProperties
{
  @CommsBinding(property = VDUOutputs.ENABLE_RUN_INTERLOCK_STATUS)
  PropertyKey<byte[]> ENABLE_RUN_INTERLOCK_STATUS = create();
  
  @CommsBinding(property = VDUOutputs.MAIN_RESERVOIR_PRESSURE_LOW_STATUS)
  PropertyKey<byte[]> MAIN_RESERVOIR_PRESSURE_LOW_STATUS = create();
  
  @CommsBinding(property = VDUOutputs.ADD_INTERVENTION_STATUS)
  PropertyKey<byte[]> ADD_INTERVENTION_STATUS = create();
  
  @CommsBinding(property = VDUOutputs.BRAKE_LOOP_CB_TRIPED_STATUS)
  PropertyKey<byte[]> BRAKE_LOOP_CB_TRIPED_STATUS = create();
}
