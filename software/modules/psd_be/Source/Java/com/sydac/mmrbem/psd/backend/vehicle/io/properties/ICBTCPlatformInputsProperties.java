/*
 * *****************************************************************************
 * * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.psd.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.CBTCOnboardOutputs;
import com.sydac.project.runtimedata.ProjectObjectConstants.CBTCPlatformInputs;

/**
 * This interface holds variable for CBTCPlatformInputs
 * 
 */
public interface ICBTCPlatformInputsProperties
{

  @CommsBinding(property = CBTCPlatformInputs.PLATFORM_DOOR_CLOSE_REQUEST)
  PropertyKey<Integer> PLATFORM_DOOR_CLOSE_REQUEST = create();

  @CommsBinding(property = CBTCPlatformInputs.PLATFORM_DOOR_OPEN_REQUEST)
  PropertyKey<Integer> PLATFORM_DOOR_OPEN_REQUEST = create();

  @CommsBinding(property = CBTCPlatformInputs.PLATFORM_DOOR_INTERLOCK_OVERRIDE)
  PropertyKey<Integer> PLATFORM_DOOR_INTERLOCK_OVERRIDE = create();
}
