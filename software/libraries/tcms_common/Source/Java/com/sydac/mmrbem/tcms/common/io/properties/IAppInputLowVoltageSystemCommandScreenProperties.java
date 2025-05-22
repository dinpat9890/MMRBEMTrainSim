/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

public interface IAppInputLowVoltageSystemCommandScreenProperties
{
  @CommsBinding(property = VDUInputs.LV_COMMAND_BCG1_M1)
  PropertyKey<Integer> LV_COMMAND_BCG1_M1 = create();

  @CommsBinding(property = VDUInputs.LV_COMMAND_BCG1_M2)
  PropertyKey<Integer> LV_COMMAND_BCG1_M2 = create();

  @CommsBinding(property = VDUInputs.LV_COMMAND_BCG1_M3)
  PropertyKey<Integer> LV_COMMAND_BCG1_M3 = create();

  @CommsBinding(property = VDUInputs.LV_COMMAND_BCG2_M1)
  PropertyKey<Integer> LV_COMMAND_BCG2_M1 = create();

  @CommsBinding(property = VDUInputs.LV_COMMAND_BCG2_M2)
  PropertyKey<Integer> LV_COMMAND_BCG2_M2 = create();

  @CommsBinding(property = VDUInputs.LV_COMMAND_BCG2_M3)
  PropertyKey<Integer> LV_COMMAND_BCG2_M3 = create();

  @CommsBinding(property = VDUInputs.LV_COMMAND_POPB)
  PropertyKey<Integer> LV_COMMAND_POPB = create();

}
