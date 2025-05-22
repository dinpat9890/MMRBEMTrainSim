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

public interface IAppOutputsFaultDetailsScreenProperties
{
  @CommsBinding(property = VDUOutputs.FAULT_DETAILS_INFO)
  PropertyKey<byte[]> FAULT_DETAILS_INFO = create();

  @CommsBinding(property = VDUOutputs.PREVIOUS_SCREEN_ID_TO_FAULT_DETAILS)
  PropertyKey<Integer> PREVIOUS_SCREEN_ID_TO_FAULT_DETAILS = create();
}
