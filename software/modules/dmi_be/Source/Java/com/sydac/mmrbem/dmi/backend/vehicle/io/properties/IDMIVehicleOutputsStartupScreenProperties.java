package com.sydac.mmrbem.dmi.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.DMIVehicleOutputs;

public interface IDMIVehicleOutputsStartupScreenProperties
{
  @CommsBinding(property = DMIVehicleOutputs.CAB_ACTIVE)
  PropertyKey<Integer> CAB_ACTIVE = create();

  @CommsBinding(property = DMIVehicleOutputs.POWER_ON)
  PropertyKey<Integer> POWER_ON = create();

  @CommsBinding(property = DMIVehicleOutputs.NEUTRAL_SECTION)
  PropertyKey<Integer> NEUTRAL_SECTION = create();
}
