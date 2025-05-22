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
import com.sydac.project.runtimedata.ProjectObjectConstants.TCMSVehicleOutputs;

/**
 * This interface holds variable for TCMSVehicleOutputs.
 * 
 */
public interface ITCMSVehicleOutputsProperties
    extends ITCMSVehicleOutputsPropulsionSystemProperties, ITCMSVehicleOutputsDoorSystemProperties,
    ITCMSVehicleOutputsBatterySystemProperties, ITCMSVehicleOutputsAPSSystemProperties,
    ITCMSVehicleOutputsBrakeSystemProperties, ITCMSVehicleOutputsDoorStatusProperties,
    ITCMSVehicleOutputsOperationScreenProperties, ITCMSVehicleOutputsOperatingScreenProperties,
    ITCMSVehicleOutputsWFLSystemProperties, ITCMSVehicleOutputsActiveFaultsScreenProperties,
    ITCMSVehicleOutputsEnergyConsumpCountersScreenProperties, ITCMSVehicleOutputsLightSystemProperties,
    ITCMSVehicleOutputsHVACSystemScreenProperties, ITCMSVehicleOutputsLowVoltageSystemProperties,
    ITCMSVehicleOutputsECNScreenProperties, ITCMSVehicleOutputsFireDetectionSystemProperties,
    ITCMSVehicleOutputsMediumVoltageSystemProperties, ITCMSVehicleOutputsSpeedLimitInterlockScreenProperties,
    ITCMSVehicleOutputsPantographInterlockScreenProperties, ITCMSVehicleOutputsVCBInterlockScreenProperties,
    ITCMSVehicleOutputsEBLoopInterlockScreenProperties, ITCMSVehicleOutputsStatusScreenProperties,
    ITCMSVehicleOutputsSpecialModesProperties, ITCMSVehicleOutputsMisceProperties,
    ITCMSVehicleOutputsEnableToRunInterlockScreenProperties,
    ITCMSVehicleOutputsBrakeLoopInterlockScreenProperties
{
  @CommsBinding(property = TCMSVehicleOutputs.HMI_POWER)
  PropertyKey<Boolean> HMI_POWER = create();

  @CommsBinding(property = TCMSVehicleOutputs.DUMMY_FAULT_SIGNAL)
  PropertyKey<Integer> DUMMY_FAULT_SIGNAL = create();

  @CommsBinding(property = TCMSVehicleOutputs.POWER_OFF_PRESSED)
  PropertyKey<Boolean> POWER_OFF_PRESSED = create();

}
