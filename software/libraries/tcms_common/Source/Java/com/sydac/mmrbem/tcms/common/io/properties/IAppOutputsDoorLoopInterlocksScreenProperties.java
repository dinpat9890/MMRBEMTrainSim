package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsDoorLoopInterlocksScreenProperties
{
  @CommsBinding(property = VDUOutputs.LEFT_DOOR_OPEN_STATUS)
  PropertyKey<byte[]> LEFT_DOOR_OPEN_STATUS = create();

  @CommsBinding(property = VDUOutputs.RIGHT_DOOR_OPEN_STATUS)
  PropertyKey<byte[]> RIGHT_DOOR_OPEN_STATUS = create();

  @CommsBinding(property = VDUOutputs.EMG_DOOR_OPEN_STATUS)
  PropertyKey<byte[]> EMG_DOOR_OPEN_STATUS = create();

  @CommsBinding(property = VDUOutputs.PABR_DE_ENERGIZED_IN_DM1)
  PropertyKey<Integer> PABR_DE_ENERGIZED_IN_DM1 = create();

  @CommsBinding(property = VDUOutputs.PABR_DE_ENERGIZED_IN_DM6)
  PropertyKey<Integer> PABR_DE_ENERGIZED_IN_DM6 = create();

  @CommsBinding(property = VDUOutputs.PABR_DE_ENERGIZED_IN_DM8)
  PropertyKey<Integer> PABR_DE_ENERGIZED_IN_DM8 = create();
}
