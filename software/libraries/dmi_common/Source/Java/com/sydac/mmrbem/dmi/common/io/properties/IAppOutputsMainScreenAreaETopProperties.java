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
 * This interface defines {@link PropertyKey} instances for Main Screen Area
 * ETop Application Outputs.
 *
 */
public interface IAppOutputsMainScreenAreaETopProperties
{

  @CommsBinding(property = DMIOutputs.RADIO_COMMUNICATION_STATUS)
  PropertyKey<Integer> RADIO_COMMUNICATION_STATUS = create();

  @CommsBinding(property = DMIOutputs.ATC_STATUS)
  PropertyKey<Integer> ATC_STATUS = create();
  
  @CommsBinding(property = DMIOutputs.ATP_ZONE_STATUS)
  PropertyKey<Integer> ATP_ZONE_STATUS = create();
  
  @CommsBinding(property = DMIOutputs.DEPOT_INDICATION)
  PropertyKey<Integer> DEPOT_INDICATION = create();

}
