/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsMiscellaniaScreenProperties
{
  @CommsBinding(property = VDUOutputs.LOW_SOUND_HORN_FRONT_STATUS)
  PropertyKey<Integer> LOW_SOUND_HORN_FRONT_STATUS = create();

  @CommsBinding(property = VDUOutputs.LOW_SOUND_HORN_REAR_STATUS)
  PropertyKey<Integer> LOW_SOUND_HORN_REAR_STATUS = create();

  @CommsBinding(property = VDUOutputs.HIGH_SOUND_HORN_FRONT_STATUS)
  PropertyKey<Integer> HIGH_SOUND_HORN_FRONT_STATUS = create();

  @CommsBinding(property = VDUOutputs.HIGH_SOUND_HORN_REAR_STATUS)
  PropertyKey<Integer> HIGH_SOUND_HORN_REAR_STATUS = create();

  @CommsBinding(property = VDUOutputs.HORN_ISOLATE_RESINSERT_FRONT_STATUS)
  PropertyKey<Integer> HORN_ISOLATE_RESINSERT_FRONT_STATUS = create();

  @CommsBinding(property = VDUOutputs.HORN_ISOLATE_RESINSERT_REAR_STATUS)
  PropertyKey<Integer> HORN_ISOLATE_RESINSERT_REAR_STATUS = create();
  
  @CommsBinding(property = VDUOutputs.MISC_OBSTRUCTION_DETECTED_LEFT)
  PropertyKey<byte[]> MISC_OBSTRUCTION_DETECTED_LEFT = create();
  
  @CommsBinding(property = VDUOutputs.MISC_OBSTRUCTION_DETECTED_RIGHT)
  PropertyKey<byte[]> MISC_OBSTRUCTION_DETECTED_RIGHT = create();
  
  @CommsBinding(property = VDUOutputs.MISC_DERAILMENT_DETECTED_LEFT)
  PropertyKey<byte[]> MISC_DERAILMENT_DETECTED_LEFT = create();
  
  @CommsBinding(property = VDUOutputs.MISC_DERAILMENT_DETECTED_RIGHT)
  PropertyKey<byte[]> MISC_DERAILMENT_DETECTED_RIGHT = create();
  
  
}
