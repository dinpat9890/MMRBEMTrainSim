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

public interface IAppOutputsLowVoltageSystemCommandScreenProperties
{
  @CommsBinding(property = VDUOutputs.ISOLATE_BCG1_M1_STATUS)
  PropertyKey<Integer> ISOLATE_BCG1_M1_STATUS = create();

  @CommsBinding(property = VDUOutputs.ISOLATE_BCG1_M2_STATUS)
  PropertyKey<Integer> ISOLATE_BCG1_M2_STATUS = create();

  @CommsBinding(property = VDUOutputs.ISOLATE_BCG1_M3_STATUS)
  PropertyKey<Integer> ISOLATE_BCG1_M3_STATUS = create();

  @CommsBinding(property = VDUOutputs.ISOLATE_BCG2_M1_STATUS)
  PropertyKey<Integer> ISOLATE_BCG2_M1_STATUS = create();

  @CommsBinding(property = VDUOutputs.ISOLATE_BCG2_M2_STATUS)
  PropertyKey<Integer> ISOLATE_BCG2_M2_STATUS = create();

  @CommsBinding(property = VDUOutputs.ISOLATE_BCG2_M3_STATUS)
  PropertyKey<Integer> ISOLATE_BCG2_M3_STATUS = create();

  @CommsBinding(property = VDUOutputs.LV_POPB_STATUS)
  PropertyKey<Integer> LV_POPB_STATUS = create();
}
