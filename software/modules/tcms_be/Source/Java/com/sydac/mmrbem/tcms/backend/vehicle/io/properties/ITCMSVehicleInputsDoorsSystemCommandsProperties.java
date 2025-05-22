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

public interface ITCMSVehicleInputsDoorsSystemCommandsProperties
{

  @CommsBinding(property = TCMSVehicleInputs.DOOR_A1_ISOLATE_VDU_REQ)
  PropertyKey<Integer> DOOR_A1_ISOLATE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.DOOR_A2_ISOLATE_VDU_REQ)
  PropertyKey<Integer> DOOR_A2_ISOLATE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.DOOR_A3_ISOLATE_VDU_REQ)
  PropertyKey<Integer> DOOR_A3_ISOLATE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.DOOR_A4_ISOLATE_VDU_REQ)
  PropertyKey<Integer> DOOR_A4_ISOLATE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.DOOR_B1_ISOLATE_VDU_REQ)
  PropertyKey<Integer> DOOR_B1_ISOLATE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.DOOR_B2_ISOLATE_VDU_REQ)
  PropertyKey<Integer> DOOR_B2_ISOLATE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.DOOR_B3_ISOLATE_VDU_REQ)
  PropertyKey<Integer> DOOR_B3_ISOLATE_VDU_REQ = create();

  @CommsBinding(property = TCMSVehicleInputs.DOOR_B4_ISOLATE_VDU_REQ)
  PropertyKey<Integer> DOOR_B4_ISOLATE_VDU_REQ = create();
}
