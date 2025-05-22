package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsFireDetectionSystemScreenProperties
{
  @CommsBinding(property = VDUOutputs.FDU_SYSTEM_FAULT_STATUS)
  PropertyKey<byte[]> FDU_SYSTEM_FAULT_STATUS = create();

  @CommsBinding(property = VDUOutputs.FIRE_SENSOR_FAULT_STATUS)
  PropertyKey<byte[]> FIRE_SENSOR_FAULT_STATUS = create();

  @CommsBinding(property = VDUOutputs.FIRE_SENSOR_ALARM_STATUS)
  PropertyKey<byte[]> FIRE_SENSOR_ALARM_STATUS = create();

  @CommsBinding(property = VDUOutputs.FIRE_SENSOR_DISABLED_STATUS)
  PropertyKey<byte[]> FIRE_SENSOR_DISABLED_STATUS = create();

  @CommsBinding(property = VDUOutputs.FIRE_SYSTEM_INTERNAL_FIRE_STATUS)
  PropertyKey<byte[]> FIRE_SYSTEM_INTERNAL_FIRE_STATUS = create();

  @CommsBinding(property = VDUOutputs.FIRE_SYSTEM_EXTERNAL_SMOKE_STATUS)
  PropertyKey<byte[]> FIRE_SYSTEM_EXTERNAL_SMOKE_STATUS = create();

  @CommsBinding(property = VDUOutputs.FIRE_SYSTEM_UFAR_STATUS)
  PropertyKey<byte[]> FIRE_SYSTEM_UFAR_STATUS = create();

  @CommsBinding(property = VDUOutputs.FIRE_SYSTEM_SFAR_STATUS)
  PropertyKey<byte[]> FIRE_SYSTEM_SFAR_STATUS = create();

  @CommsBinding(property = VDUOutputs.FIRE_SYSTEM_UNDER_FRAME_FIRE_STATUS)
  PropertyKey<byte[]> FIRE_SYSTEM_UNDER_FRAME_FIRE_STATUS = create();
}
