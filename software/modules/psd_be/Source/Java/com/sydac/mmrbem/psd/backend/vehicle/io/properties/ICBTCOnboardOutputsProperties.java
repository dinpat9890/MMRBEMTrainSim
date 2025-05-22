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

/**
 * This interface holds variable for CBTCOnboardOutputs.
 * 
 */
public interface ICBTCOnboardOutputsProperties
{

  @CommsBinding(property = CBTCOnboardOutputs.CURRENT_TRAIN_SPEED)
  PropertyKey<Double> CURRENT_TRAIN_SPEED = create();

}
