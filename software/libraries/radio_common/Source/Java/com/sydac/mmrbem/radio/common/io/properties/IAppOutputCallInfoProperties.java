/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioOutputs;

public interface IAppOutputCallInfoProperties
{

  @CommsBinding(property = RadioOutputs.INPUT_SSI_ID)
  PropertyKey<Integer> INPUT_SSI_ID = create();

  @CommsBinding(property = RadioOutputs.CALL_GROUP_NAME)
  PropertyKey<byte[]> CALL_GROUP_NAME = create();

  @CommsBinding(property = RadioOutputs.CALL_SSI_ID)
  PropertyKey<Integer> CALL_SSI_ID = create();

  @CommsBinding(property = RadioOutputs.CALL_GROUP_STATUS)
  PropertyKey<Integer> CALL_GROUP_STATUS = create();

  @CommsBinding(property = RadioOutputs.INCOMING_CALL_NAME)
  PropertyKey<byte[]> INCOMING_CALL_NAME = create();
  
  @CommsBinding(property = RadioOutputs.INCOMING_CALL_TYPE)
  PropertyKey<Integer>  INCOMING_CALL_TYPE = create();

  @CommsBinding(property = RadioOutputs.DEPOT_INDICATION)
  PropertyKey<Integer> DEPOT_INDICATION = create();
}
