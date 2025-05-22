package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsFireDetailsScreenProperties
{
  @CommsBinding(property = VDUOutputs.FIRE_DETECTION_SELECTED_CAR_INDEX)
  PropertyKey<Integer> FIRE_DETECTION_SELECTED_CAR_INDEX = create();

  @CommsBinding(property = VDUOutputs.HVAC_1_FIRE_SMOKE_ACTIVE_STATUS)
  PropertyKey<Integer> HVAC_1_FIRE_SMOKE_ACTIVE_STATUS = create();

  @CommsBinding(property = VDUOutputs.EDB_HEAT_ALARM_ACTIVE_STATUS)
  PropertyKey<Integer> EDB_HEAT_ALARM_ACTIVE_STATUS = create();

  @CommsBinding(property = VDUOutputs.CAB_SMOKE_ALARM_ACTIVE_STATUS)
  PropertyKey<Integer> CAB_SMOKE_ALARM_ACTIVE_STATUS = create();

  @CommsBinding(property = VDUOutputs.HVAC_1_BUTTON_STATUS)
  PropertyKey<Integer> HVAC_1_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.EDB_HEAT_BUTTON_STATUS)
  PropertyKey<Integer> EDB_HEAT_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.CAB_SMOKE_BUTTON_STATUS)
  PropertyKey<Integer> CAB_SMOKE_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.SHD_SALOON_L1_BUTTON_STATUS)
  PropertyKey<Integer> SHD_SALOON_L1_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.SHD_SALOON_L2_BUTTON_STATUS)
  PropertyKey<Integer> SHD_SALOON_L2_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.SHD_SALOON_L3_BUTTON_STATUS)
  PropertyKey<Integer> SHD_SALOON_L3_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.SHD_SALOON_R1_BUTTON_STATUS)
  PropertyKey<Integer> SHD_SALOON_R1_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.SHD_SALOON_R2_BUTTON_STATUS)
  PropertyKey<Integer> SHD_SALOON_R2_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.SHD_SALOON_R3_BUTTON_STATUS)
  PropertyKey<Integer> SHD_SALOON_R3_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.HD_HVAC_2_BUTTON_STATUS)
  PropertyKey<Integer> HD_HVAC_2_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.AUXILLARY_DESK_BUTTON_STATUS)
  PropertyKey<Integer> AUXILLARY_DESK_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.END_CUBICLE_RL1_BUTTON_STATUS)
  PropertyKey<Integer> END_CUBICLE_RL1_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.END_CUBICLE_RL2_BUTTON_STATUS)
  PropertyKey<Integer> END_CUBICLE_RL2_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.END_CUBICLE_RR1_BUTTON_STATUS)
  PropertyKey<Integer> END_CUBICLE_RR1_BUTTON_STATUS = create();

  @CommsBinding(property = VDUOutputs.END_CUBICLE_RR2_BUTTON_STATUS)
  PropertyKey<Integer> END_CUBICLE_RR2_BUTTON_STATUS = create();
  
  @CommsBinding(property = VDUOutputs.LHD_CI_DISABLE_STATUS)
  PropertyKey<Integer> LHD_CI_DISABLE_STATUS = create();

  @CommsBinding(property = VDUOutputs.LHD_DRIVER_DESK_DISABLE_STATUS)
  PropertyKey<Integer> LHD_DRIVER_DESK_DISABLE_STATUS = create();

  @CommsBinding(property = VDUOutputs.LHD_LTJB_DISABLE_STATUS)
  PropertyKey<Integer> LHD_LTJB_DISABLE_STATUS = create();
}
