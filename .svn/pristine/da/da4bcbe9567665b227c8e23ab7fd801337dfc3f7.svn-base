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

public interface IAppOutputsWheelFlangeLubricatorScreenProperties
{
  @CommsBinding(property = VDUOutputs.WFL_STATUS)
  PropertyKey<byte[]> WFL_STATUS = create();

  @CommsBinding(property = VDUOutputs.WFL_OIL_LEVEL_STATUS)
  PropertyKey<byte[]> WFL_OIL_LEVEL_STATUS = create();

  @CommsBinding(property = VDUOutputs.WFL_PUMP_STATUS_1)
  PropertyKey<byte[]> WFL_PUMP_STATUS_1 = create();

  @CommsBinding(property = VDUOutputs.WFL_PUMP_STATUS_2)
  PropertyKey<byte[]> WFL_PUMP_STATUS_2 = create();

  @CommsBinding(property = VDUOutputs.WFL_ISOLATED_STATUS_FRONT_CAR)
  PropertyKey<Integer> WFL_ISOLATED_STATUS_FRONT_CAR = create();

  @CommsBinding(property = VDUOutputs.WFL_ISOLATED_STATUS_REAR_CAR)
  PropertyKey<Integer> WFL_ISOLATED_STATUS_REAR_CAR = create();
}
