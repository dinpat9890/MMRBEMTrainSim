/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.PSDOutputs;

/**
 * This interface defines {@link PropertyKey} instances for Main Screen Area A
 * Application Outputs.
 *
 */
public interface IAppOutputsScreenChangeProperties
{
  @CommsBinding(property = PSDOutputs.PSD_SCREEN_ID)
  PropertyKey<Integer> PSD_SCREEN_ID = create();
  
 
}
