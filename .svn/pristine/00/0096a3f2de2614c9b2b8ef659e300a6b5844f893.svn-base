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
import com.sydac.project.runtimedata.ProjectObjectConstants.CBTCPlatformOutputs;

/**
 * This interface holds variable for CBTCOnboardOutputs.
 * 
 */
public interface ICBTCPlatformOutputsProperties
{
  
  @CommsBinding(property = CBTCPlatformOutputs.PSD_DOOR_STATUS)
  PropertyKey<Integer> PSD_DOOR_STATUS = create();
  
  @CommsBinding(property = CBTCPlatformOutputs.TRAIN_DOCKING_INFO)
  PropertyKey<byte[]> TRAIN_DOCKING_INFO = create();
  

  @CommsBinding(property = CBTCPlatformOutputs.PSD_INTERLOCK_OVERRIDE_STATUS)
  PropertyKey<Integer> PSD_INTERLOCK_OVERRIDE_STATUS = create();
}
