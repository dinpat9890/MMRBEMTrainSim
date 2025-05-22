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

public interface IAppOutputsTrainSideViewComponentProperties
{
  @CommsBinding(property = VDUOutputs.TRAIN_SIDE_VIEW_STATUS)
  PropertyKey<byte[]> TRAIN_SIDE_VIEW_STATUS = create();

  @CommsBinding(property = VDUOutputs.PANTOGRAPH_STATUS)
  PropertyKey<byte[]> PANTOGRAPH_STATUS = create();

  @CommsBinding(property = VDUOutputs.VCB_STATUS)
  PropertyKey<byte[]> VCB_STATUS = create();

  @CommsBinding(property = VDUOutputs.DRIVER_CAB_DIRECTION)
  PropertyKey<byte[]> DRIVER_CAB_DIRECTION = create();

  @CommsBinding(property = VDUOutputs.CAB_FAULT_STATE)
  PropertyKey<byte[]> CAB_FAULT_STATE = create();
  

  @CommsBinding(property = VDUOutputs.CI_STATUS)
  PropertyKey<byte[]> CI_STATUS = create();
}
