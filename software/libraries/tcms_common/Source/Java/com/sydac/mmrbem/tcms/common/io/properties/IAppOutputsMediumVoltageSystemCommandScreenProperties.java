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

public interface IAppOutputsMediumVoltageSystemCommandScreenProperties
{
  @CommsBinding(property = VDUOutputs.MV_DM_FRONT_CAR_FORCE_STATUS)
  PropertyKey<Integer> MV_DM_FRONT_CAR_FORCE_STATUS = create();

  @CommsBinding(property = VDUOutputs.MV_DM_REAR_CAR_FORCE_STATUS)
  PropertyKey<Integer> MV_DM_REAR_CAR_FORCE_STATUS = create();

  @CommsBinding(property = VDUOutputs.MV_DM_FRONT_CAR_RESET_STATUS)
  PropertyKey<Integer> MV_DM_FRONT_CAR_RESET_STATUS = create();

  @CommsBinding(property = VDUOutputs.MV_DM_REAR_CAR_RESET_STATUS)
  PropertyKey<Integer> MV_DM_REAR_CAR_RESET_STATUS = create();

  @CommsBinding(property = VDUOutputs.MV_T1_CAR_LOW_FORCE_STATUS)
  PropertyKey<Integer> MV_T1_CAR_LOW_FORCE_STATUS = create();

  @CommsBinding(property = VDUOutputs.MV_T2_CAR_LOW_FORCE_STATUS)
  PropertyKey<Integer> MV_T2_CAR_LOW_FORCE_STATUS = create();

  @CommsBinding(property = VDUOutputs.MV_T3_CAR_LOW_FORCE_STATUS)
  PropertyKey<Integer> MV_T3_CAR_LOW_FORCE_STATUS = create();
  
  
  @CommsBinding(property = VDUOutputs.MV_T1_CAR_HIGH_FORCE_STATUS)
  PropertyKey<Integer> MV_T1_CAR_HIGH_FORCE_STATUS = create();

  @CommsBinding(property = VDUOutputs.MV_T2_CAR_HIGH_FORCE_STATUS)
  PropertyKey<Integer> MV_T2_CAR_HIGH_FORCE_STATUS = create();

  @CommsBinding(property = VDUOutputs.MV_T3_CAR_HIGH_FORCE_STATUS)
  PropertyKey<Integer> MV_T3_CAR_HIGH_FORCE_STATUS = create();
}
