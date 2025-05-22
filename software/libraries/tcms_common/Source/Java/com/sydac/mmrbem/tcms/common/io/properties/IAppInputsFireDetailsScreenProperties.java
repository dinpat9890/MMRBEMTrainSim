/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

public interface IAppInputsFireDetailsScreenProperties
{

  @CommsBinding(property = VDUInputs.FIRE_DETECTION_SELECTED_CAR_INDEX_REQ)
  PropertyKey<Integer> FIRE_DETECTION_SELECTED_CAR_INDEX_REQ = create(); 
  
  @CommsBinding(property = VDUInputs.HVAC_1_FIRE_DETECTOR_DISABLE_VDU_REQ)
  PropertyKey<Integer> HVAC_1_FIRE_DETECTOR_DISABLE_VDU_REQ = create(); 
  
  @CommsBinding(property = VDUInputs.EDB_HEAT_ALARM_DISABLE_VDU_REQ)
  PropertyKey<Integer> EDB_HEAT_ALARM_DISABLE_VDU_REQ = create(); 
  
  @CommsBinding(property = VDUInputs.CAB_SMOKE_DETECTOR_DISABLE_VDU_REQ)
  PropertyKey<Integer> CAB_SMOKE_DETECTOR_DISABLE_VDU_REQ = create(); 
  
  @CommsBinding(property = VDUInputs.SHD_SALOON_L1_BUTTON_REQ)
  PropertyKey<Integer> SHD_SALOON_L1_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.SHD_SALOON_L2_BUTTON_REQ)
  PropertyKey<Integer> SHD_SALOON_L2_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.SHD_SALOON_L3_BUTTON_REQ)
  PropertyKey<Integer> SHD_SALOON_L3_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.SHD_SALOON_R1_BUTTON_REQ)
  PropertyKey<Integer> SHD_SALOON_R1_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.SHD_SALOON_R2_BUTTON_REQ)
  PropertyKey<Integer> SHD_SALOON_R2_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.SHD_SALOON_R3_BUTTON_REQ)
  PropertyKey<Integer> SHD_SALOON_R3_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.HD_HVAC_2_BUTTON_REQ)
  PropertyKey<Integer> HD_HVAC_2_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.AUXILLARY_DESK_BUTTON_REQ)
  PropertyKey<Integer> AUXILLARY_DESK_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.END_CUBICLE_RR1_BUTTON_REQ)
  PropertyKey<Integer> END_CUBICLE_RR1_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.END_CUBICLE_RR2_BUTTON_REQ)
  PropertyKey<Integer> END_CUBICLE_RR2_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.END_CUBICLE_RL1_BUTTON_REQ)
  PropertyKey<Integer> END_CUBICLE_RL1_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.END_CUBICLE_RL2_BUTTON_REQ)
  PropertyKey<Integer> END_CUBICLE_RL2_BUTTON_REQ = create();
  
  @CommsBinding(property = VDUInputs.LHD_CI_DISABLE_VDU_REQ)
  PropertyKey<Integer> LHD_CI_DISABLE_VDU_REQ = create();
  
  @CommsBinding(property = VDUInputs.LHD_DRIVER_DESK_DISABLE_VDU_REQ)
  PropertyKey<Integer> LHD_DRIVER_DESK_DISABLE_VDU_REQ = create();
  
  @CommsBinding(property = VDUInputs.LHD_LTJB_DISABLE_VDU_REQ)
  PropertyKey<Integer> LHD_LTJB_DISABLE_VDU_REQ = create();
}
