/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.TCMSVehicleOutputs;

public interface ITCMSVehicleOutputsVCBInterlockScreenProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.TRANSFORMER_OIL_TEMPERATURE)
  PropertyKey<Integer> TRANSFORMER_OIL_TEMPERATURE = create();

  @CommsBinding(property = TCMSVehicleOutputs.VCB_OPENED_BY_AC_OVER_CURRENT)
  PropertyKey<Integer> VCB_OPENED_BY_AC_OVER_CURRENT = create();

  @CommsBinding(property = TCMSVehicleOutputs.VCB_OPENED_BY_MTR_PROTECTION)
  PropertyKey<Integer> VCB_OPENED_BY_MTR_PROTECTION = create();

  @CommsBinding(property = TCMSVehicleOutputs.VCB_OPENED_BY_IC_M)
  PropertyKey<Integer> VCB_OPENED_BY_IC_M = create();

  @CommsBinding(property = TCMSVehicleOutputs.VCB_OPENED_BY_IC_DM)
  PropertyKey<Integer> VCB_OPENED_BY_IC_DM = create();

  @CommsBinding(property = TCMSVehicleOutputs.VCB_OPENED_BY_APS)
  PropertyKey<Integer> VCB_OPENED_BY_APS = create();

  @CommsBinding(property = TCMSVehicleOutputs.NO_LINE_VOLTAGE)
  PropertyKey<Integer> NO_LINE_VOLTAGE = create();

  @CommsBinding(property = TCMSVehicleOutputs.APS_K_AK_CONTACTOR)
  PropertyKey<Integer> APS_K_AK_CONTACTOR = create();

  @CommsBinding(property = TCMSVehicleOutputs.CI_K_AK_CONTACTOR)
  PropertyKey<Integer> CI_K_AK_CONTACTOR = create();

}
