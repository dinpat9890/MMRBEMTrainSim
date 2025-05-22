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

public interface IAppInputsHVRightTCarCommandScreenProperties
{

  @CommsBinding(property = VDUInputs.PANTO_BUTTON_RIGHT_REQ)
  PropertyKey<Integer> PANTO_BUTTON_RIGHT_REQ = create();

  @CommsBinding(property = VDUInputs.PANTO_LOW_BUTTON_RIGHT_REQ)
  PropertyKey<Integer> PANTO_LOW_BUTTON_RIGHT_REQ = create();

  @CommsBinding(property = VDUInputs.PANTO_RESET_BUTTON_RIGHT_REQ)
  PropertyKey<Integer> PANTO_RESET_BUTTON_RIGHT_REQ = create();

  @CommsBinding(property = VDUInputs.VCB_RESET_BUTTON_RIGHT_REQ)
  PropertyKey<Integer> VCB_RESET_BUTTON_RIGHT_REQ = create();

  @CommsBinding(property = VDUInputs.REQ_VCB_CONFIRM_BUTTON)
  PropertyKey<Integer> REQ_VCB_CONFIRM_BUTTON = create();

  @CommsBinding(property = VDUInputs.REQ_VCB_DECLINE_BUTTON)
  PropertyKey<Integer> REQ_VCB_DECLINE_BUTTON = create();

 
  @CommsBinding(property = VDUInputs.ISOLATE_APS5_REQUEST)
  PropertyKey<Integer> ISOLATE_APS5_REQUEST = create();

  @CommsBinding(property = VDUInputs.ISOLATE_APS6_REQUEST)
  PropertyKey<Integer> ISOLATE_APS6_REQUEST = create();



  @CommsBinding(property = VDUInputs.ISOLATE_RIGHT_VCB_REQ)
  PropertyKey<Integer> ISOLATE_RIGHT_VCB_REQ = create();
}
