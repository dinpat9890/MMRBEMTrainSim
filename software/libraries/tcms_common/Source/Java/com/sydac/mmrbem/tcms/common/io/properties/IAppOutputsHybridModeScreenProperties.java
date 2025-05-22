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

public interface IAppOutputsHybridModeScreenProperties
{

  @CommsBinding(property = VDUOutputs.ACTIVE_HYBRID_PANEL_SIDE)
  PropertyKey<Integer> ACTIVE_HYBRID_PANEL_SIDE = create();

  @CommsBinding(property = VDUOutputs.HYBRID_PANEL_DISPLAY_IMAGE_ID)
  PropertyKey<Integer> HYBRID_PANEL_DISPLAY_IMAGE_ID = create();
}
