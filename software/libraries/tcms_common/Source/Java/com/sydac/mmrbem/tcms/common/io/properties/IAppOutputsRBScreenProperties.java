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

public interface IAppOutputsRBScreenProperties
{
  @CommsBinding(property = VDUOutputs.RB_HVAC1_STATUS)
  PropertyKey<byte[]> RB_HVAC1_STATUS = create();

  @CommsBinding(property = VDUOutputs.RB_HVAC2_STATUS)
  PropertyKey<byte[]> RB_HVAC2_STATUS = create();

  @CommsBinding(property = VDUOutputs.RB_APSICB_STATUS)
  PropertyKey<byte[]> RB_APSICB_STATUS = create();

  @CommsBinding(property = VDUOutputs.RB_FDSCB_STATUS)
  PropertyKey<byte[]> RB_FDSCB_STATUS = create();

 
}
