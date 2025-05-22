/*
 * *****************************************************************************
 * * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.TCMSVehicleInputs;

public interface ITCMSVehicleInputsFireProperties
{

  @CommsBinding(property = TCMSVehicleInputs.TCMS_FDU_RESET_REQ)
  PropertyKey<Integer> TCMS_FDU_RESET_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.TCMS_FIRE_ALARM_RESET_REQ)
  PropertyKey<Integer> TCMS_FIRE_ALARM_RESET_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.HVAC_1_FIRE_DETECTOR_DISABLE_VDU_REQ)
  PropertyKey<Integer> HVAC_1_FIRE_DETECTOR_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.EDB_HEAT_ALARM_DISABLE_VDU_REQ)
  PropertyKey<Integer> EDB_HEAT_ALARM_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.CAB_SMOKE_DETECTOR_DISABLE_VDU_REQ)
  PropertyKey<Integer> CAB_SMOKE_DETECTOR_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.SHD_END_CUBICLE_REAR_RIGHT_1_DISABLE_VDU_REQ)
  PropertyKey<Integer> SHD_END_CUBICLE_REAR_RIGHT_1_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.SHD_END_CUBICLE_REAR_RIGHT_2_DISABLE_VDU_REQ)
  PropertyKey<Integer> SHD_END_CUBICLE_REAR_RIGHT_2_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.SHD_END_CUBICLE_REAR_LEFT_1_DISABLE_VDU_REQ)
  PropertyKey<Integer> SHD_END_CUBICLE_REAR_LEFT_1_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.SHD_END_CUBICLE_REAR_LEFT_2_DISABLE_VDU_REQ)
  PropertyKey<Integer> SHD_END_CUBICLE_REAR_LEFT_2_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.SALOON_R1_FIRE_DETECTOR_DISABLE_VDU_REQ)
  PropertyKey<Integer> SALOON_R1_FIRE_DETECTOR_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.SALOON_R2_FIRE_DETECTOR_DISABLE_VDU_REQ)
  PropertyKey<Integer> SALOON_R2_FIRE_DETECTOR_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.AUXILIARY_DESK_FIRE_DETECTOR_DISABLE_VDU_REQ)
  PropertyKey<Integer> AUXILIARY_DESK_FIRE_DETECTOR_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.LHD_DRIVER_DESK_DISABLE_VDU_REQ)
  PropertyKey<Integer> LHD_DRIVER_DESK_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.LHD_CI_DISABLE_VDU_REQ)
  PropertyKey<Integer> LHD_CI_DISABLE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.LHD_LTJB_DISABLE_VDU_REQ)
  PropertyKey<Integer> LHD_LTJB_DISABLE_VDU_REQ = create();
}
