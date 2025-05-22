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

public interface ITCMSVehicleOutputsBrakeSystemProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_SERVICE_BRAKE_STATUS)
  PropertyKey<Integer> BOGIE_1_SERVICE_BRAKE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_SERVICE_BRAKE_ISOLATED)
  PropertyKey<Integer> BOGIE_1_SERVICE_BRAKE_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_SERVICE_BRAKE_STATUS)
  PropertyKey<Integer> BOGIE_2_SERVICE_BRAKE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_SERVICE_BRAKE_ISOLATED)
  PropertyKey<Integer> BOGIE_2_SERVICE_BRAKE_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_PARKING_BRAKE_STATUS)
  PropertyKey<Integer> BOGIE_1_PARKING_BRAKE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_PARKING_BRAKE_STATUS)
  PropertyKey<Integer> BOGIE_2_PARKING_BRAKE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_PARKING_BRAKE_ISOLATED)
  PropertyKey<Integer> BOGIE_1_PARKING_BRAKE_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_PARKING_BRAKE_ISOLATED)
  PropertyKey<Integer> BOGIE_2_PARKING_BRAKE_ISOLATED = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_SERVICE_BRAKE_FAULT)
  PropertyKey<Integer> BOGIE_1_SERV_BRAKE_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_SERVICE_BRAKE_FAULT)
  PropertyKey<Integer> BOGIE_2_SERV_BRAKE_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_WSP_STATUS)
  PropertyKey<Integer> BOGIE_1_WSP_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_WSP_STATUS)
  PropertyKey<Integer> BOGIE_2_WSP_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_SUSP_STATUS)
  PropertyKey<Integer> BOGIE_1_SUSP_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_SUSP_STATUS)
  PropertyKey<Integer> BOGIE_2_SUSP_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BECU_STATUS)
  PropertyKey<Integer> BECU_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.BECU_MINOR_FAULT)
  PropertyKey<Integer> BECU_MINOR_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BECU_MAJOR_FAULT)
  PropertyKey<Integer> BECU_MAJOR_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BRAKE_TRAIN_LINE_STATUS)
  PropertyKey<Integer> BRAKE_TRAIN_LINE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.MOTOR_TRAIN_LINE_STATUS)
  PropertyKey<Integer> MOTOR_TRAIN_LINE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.FSB_1_LINE_STATUS)
  PropertyKey<Integer> FSB_1_LINE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.FSB_2_LINE_STATUS)
  PropertyKey<Integer> FSB_2_LINE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_1_LINE_STATUS)
  PropertyKey<Integer> EB_1_LINE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.EB_2_LINE_STATUS)
  PropertyKey<Integer> EB_2_LINE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.HOLDING_BRAKE_STATUS)
  PropertyKey<Integer> HOLDING_BRAKE_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.EPIC_ISOLATION_STATUS)
  PropertyKey<Integer> EPIC_ISOLATION_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.ED_CUTOUT_STATUS)
  PropertyKey<Integer> ED_CUTOUT_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.RPRESS_ISOLATION_STATUS)
  PropertyKey<Integer> RPRESS_ISOLATION_STATUS = create();

  @CommsBinding(property = TCMSVehicleOutputs.MAIN_PIPE_PRESSURE)
  PropertyKey<Integer> MAIN_PIPE_PRESSURE = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_BRAKE_CYLINDER_PRESSURE)
  PropertyKey<Integer> BOGIE_1_BRAKE_CYLINDER_PRESSURE = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_BRAKE_CYLINDER_PRESSURE)
  PropertyKey<Integer> BOGIE_2_BRAKE_CYLINDER_PRESSURE = create();

  @CommsBinding(property = TCMSVehicleOutputs.AIR_SUSPENSION_PRESSURE)
  PropertyKey<Integer> AIR_SUSPENSION_PRESSURE = create();

  @CommsBinding(property = TCMSVehicleOutputs.EP_BRAKE_DELIVERED)
  PropertyKey<Integer> EP_BRAKE_DELIVERED = create();

  @CommsBinding(property = TCMSVehicleOutputs.ED_BRAKE_REQUESTED)
  PropertyKey<Integer> ED_BRAKE_REQUESTED = create();

  @CommsBinding(property = TCMSVehicleOutputs.CAR_WEIGHT)
  PropertyKey<Integer> CAR_WEIGHT = create();
  
  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_2_SUSP_FAULT)
  PropertyKey<Integer> BOGIE_2_SUSP_FAULT = create();

  @CommsBinding(property = TCMSVehicleOutputs.BOGIE_1_SUSP_FAULT)
  PropertyKey<Integer> BOGIE_1_SUSP_FAULT = create();
  
  
}
