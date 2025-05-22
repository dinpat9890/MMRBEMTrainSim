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

public interface IAppInputsHVMiddleTCarCommandScreenProperties
{



  @CommsBinding(property = VDUInputs.ISOLATE_MIDDLE_VCB_REQ)
  PropertyKey<Integer> ISOLATE_MIDDLE_VCB_REQ = create();
  
  @CommsBinding(property = VDUInputs.ISOLATE_APS3_REQUEST)
  PropertyKey<Integer> ISOLATE_APS3_REQUEST = create();

  @CommsBinding(property = VDUInputs.ISOLATE_APS4_REQUEST)
  PropertyKey<Integer> ISOLATE_APS4_REQUEST = create();
  
  @CommsBinding(property = VDUInputs.VCB_RESET_BUTTON_MIDDLE_REQ)
  PropertyKey<Integer> VCB_RESET_BUTTON_MIDDLE_REQ = create();

  
  @CommsBinding(property = VDUInputs.PANTO_RESET_BUTTON_MIDDLE_REQ)
  PropertyKey<Integer> PANTO_RESET_BUTTON_MIDDLE_REQ = create();
  
  @CommsBinding(property = VDUInputs.PANTO_LOW_BUTTON_MIDDLE_REQ)
  PropertyKey<Integer> PANTO_LOW_BUTTON_MIDDLE_REQ = create();
  
  @CommsBinding(property = VDUInputs.PANTO_BUTTON_MIDDLE_REQ)
  PropertyKey<Integer> PANTO_BUTTON_MIDDLE_REQ = create();
}
