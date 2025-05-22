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

public interface IAppInputsHVLeftTCarCommandScreenProperties
{

   @CommsBinding(property = VDUInputs.PANTO_BUTTON_LEFT_REQ)
   PropertyKey<Integer> PANTO_BUTTON_LEFT_REQ = create();

  @CommsBinding(property = VDUInputs.PANTO_LOW_BUTTON_LEFT_REQ)
  PropertyKey<Integer> PANTO_LOW_BUTTON_LEFT_REQ = create();

  @CommsBinding(property = VDUInputs.PANTO_RESET_BUTTON_LEFT_REQ)
  PropertyKey<Integer> PANTO_RESET_BUTTON_LEFT_REQ = create();

  @CommsBinding(property = VDUInputs.VCB_RESET_BUTTON_LEFT_REQ)
  PropertyKey<Integer> VCB_RESET_BUTTON_LEFT_REQ = create();

  @CommsBinding(property = VDUInputs.ISOLATE_APS1_REQUEST)
  PropertyKey<Integer> ISOLATE_APS1_REQUEST = create();

  @CommsBinding(property = VDUInputs.ISOLATE_APS2_REQUEST)
  PropertyKey<Integer> ISOLATE_APS2_REQUEST = create();

  @CommsBinding(property = VDUInputs.ISOLATE_LEFT_VCB_REQ)
  PropertyKey<Integer> ISOLATE_LEFT_VCB_REQ = create();

}
