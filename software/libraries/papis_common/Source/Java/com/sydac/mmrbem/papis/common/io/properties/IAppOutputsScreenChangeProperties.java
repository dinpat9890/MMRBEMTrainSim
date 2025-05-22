/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.papis.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PAPISOutputs;;

public interface IAppOutputsScreenChangeProperties
{
  @CommsBinding(property = PAPISOutputs.CURRENT_SCREEN_ID)
  PropertyKey<Integer> CURRENT_SCREEN_ID = create();

  @CommsBinding(property = PAPISOutputs.HEADER_PANEL_STATUS_LABEL_ID)
  PropertyKey<Integer> HEADER_PANEL_STATUS_LABEL_ID = create();
}
