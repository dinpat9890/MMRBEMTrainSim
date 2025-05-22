/*******************************************************************************
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.dmi.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.DMIOutputs;

/**
 * This interface defines {@link PropertyKey} instances for Main Screen Area C
 * Right Application Outputs.
 *
 */
public interface IAppOutputsMainScreenAreaCRightProperties
{

  @CommsBinding(property = DMIOutputs.LOCALISATION_STATUS)
  PropertyKey<Integer> LOCALISATION_STATUS = create();

  @CommsBinding(property = DMIOutputs.AVAILABLE_MODES)
  PropertyKey<byte[]> AVAILABLE_MODES = create();
}
