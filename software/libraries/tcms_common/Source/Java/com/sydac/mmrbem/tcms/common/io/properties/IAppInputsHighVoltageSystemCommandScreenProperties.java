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

public interface IAppInputsHighVoltageSystemCommandScreenProperties
{

  @CommsBinding(property = VDUInputs.RISE_SELECTED_PANTO_REQ)
  PropertyKey<Integer> RISE_SELECTED_PANTO_REQ = create();

  @CommsBinding(property = VDUInputs.LOWER_ALL_PANTO_REQ)
  PropertyKey<Integer> LOWER_ALL_PANTO_REQ = create();

  @CommsBinding(property = VDUInputs.OPEN_VCB_REQ)
  PropertyKey<Integer> OPEN_VCB_REQ = create();

  @CommsBinding(property = VDUInputs.CLOSE_VCB_REQ)
  PropertyKey<Integer> CLOSE_VCB_REQ = create();

  @CommsBinding(property = VDUInputs.PANTO_SELECTED_REQ_CAR)
  PropertyKey<Integer> PANTO_SELECTED_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.PANTO_LOWER_REQ_CAR)
  PropertyKey<Integer> PANTO_LOWER_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.PANTO_RESET_REQ_CAR)
  PropertyKey<Integer> PANTO_RESET_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.VCB_RESET_REQ_CAR)
  PropertyKey<Integer> VCB_RESET_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.ISOLATE_CI_REQ_CAR)
  PropertyKey<Integer> ISOLATE_CI_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.ISOLATE_CI_REQ)
  PropertyKey<Integer> ISOLATE_CI_REQ = create();

  @CommsBinding(property = VDUInputs.ISOLATE_PANTO_REQ_CAR)
  PropertyKey<Integer> ISOLATE_PANTO_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.ISOLATE_PANTO_REQ)
  PropertyKey<Integer> ISOLATE_PANTO_REQ = create();

  @CommsBinding(property = VDUInputs.ISOLATE_VCB_REQ_CAR)
  PropertyKey<Integer> ISOLATE_VCB_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.ISOLATE_VCB_REQ)
  PropertyKey<Integer> ISOLATE_VCB_REQ = create();

  @CommsBinding(property = VDUInputs.ISOLATE_APS1_REQ_CAR)
  PropertyKey<Integer> ISOLATE_APS1_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.ISOLATE_APS1_REQ)
  PropertyKey<Integer> ISOLATE_APS1_REQ = create();

  @CommsBinding(property = VDUInputs.ISOLATE_APS2_REQ_CAR)
  PropertyKey<Integer> ISOLATE_APS2_REQ_CAR = create();

  @CommsBinding(property = VDUInputs.ISOLATE_APS2_REQ)
  PropertyKey<Integer> ISOLATE_APS2_REQ = create();

  @CommsBinding(property = VDUInputs.REQ_CTRL_VCB_NS)
  PropertyKey<Integer> REQ_CTRL_VCB_NS = create();

  @CommsBinding(property = VDUInputs.PANTO_BUTTON_STATE_REQ)
  PropertyKey<Integer> PANTO_BUTTON_STATE_REQ = create();

  @CommsBinding(property = VDUInputs.ISOLATE_CI_FRONT_CAR_REQ)
  PropertyKey<Integer> ISOLATE_CI_FRONT_CAR_REQ = create();
 
  @CommsBinding(property = VDUInputs.ISOLATE_CI_REAR_CAR_REQ)
  PropertyKey<Integer> ISOLATE_CI_REAR_CAR_REQ = create();
  
  @CommsBinding(property = VDUInputs.ISOLATE_CI_M1_REQ)
  PropertyKey<Integer> ISOLATE_CI_M1_REQ = create();
  
  @CommsBinding(property = VDUInputs.ISOLATE_CI_M2_REQ)
  PropertyKey<Integer> ISOLATE_CI_M2_REQ = create();
  
  @CommsBinding(property = VDUInputs.ISOLATE_CI_M3_REQ)
  PropertyKey<Integer> ISOLATE_CI_M3_REQ = create();
}
