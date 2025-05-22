/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.TCMSVehicleOutputs;

public interface ITCMSVehicleOutputsAPSSystemProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.APS_1_STATUS)
  PropertyKey<Integer> APS_1_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.APS_2_STATUS)
  PropertyKey<Integer> APS_2_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.APS_1_FAULT)
  PropertyKey<Integer> APS_1_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.APS_2_FAULT)
  PropertyKey<Integer> APS_2_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.APS_1_ISOLATED)
  PropertyKey<Integer> APS_1_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.APS_2_ISOLATED)
  PropertyKey<Integer> APS_2_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.AK_1_STATUS)
  PropertyKey<Integer> AK_1_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.AK_2_STATUS)
  PropertyKey<Integer> AK_2_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.K_1_STATUS)
  PropertyKey<Integer> K_1_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.K_2_STATUS)
  PropertyKey<Integer> K_2_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.APS_1_OUTPUT_VOLTAGE)
  PropertyKey<Integer> APS_1_OUTPUT_VOLTAGE = create();

  @CommsBinding(property = TCMSVehicleOutputs.APS_2_OUTPUT_VOLTAGE)
  PropertyKey<Integer> APS_2_OUTPUT_VOLTAGE = create();
}
