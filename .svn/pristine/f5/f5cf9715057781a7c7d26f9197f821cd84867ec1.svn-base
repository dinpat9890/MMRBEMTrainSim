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

public interface IAppOutputsLowVoltageSystemScreenProperties
{
  @CommsBinding(property = VDUOutputs.LV_BIC_SWITCH_STATUS_LIST)
  PropertyKey<byte[]> LV_BIC_SWITCH_STATUS_LIST = create();

  @CommsBinding(property = VDUOutputs.LV_TCC_SWITCH_STATUS_LIST)
  PropertyKey<byte[]> LV_TCC_SWITCH_STATUS_LIST = create();
}
