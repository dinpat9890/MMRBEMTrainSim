/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.radio.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs;

public interface IAppInputsKeyPadPanelProperties
{

  @CommsBinding(property = RadioInputs.BTN_0_REQUEST)
  PropertyKey<Integer> BTN_0_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_1_REQUEST)
  PropertyKey<Integer> BTN_1_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_2_ABC_REQUEST)
  PropertyKey<Integer> BTN_2_ABC_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_3_DEF_REQUEST)
  PropertyKey<Integer> BTN_3_DEF_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_4_GHI_REQUEST)
  PropertyKey<Integer> BTN_4_GHI_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_5_JKL_REQUEST)
  PropertyKey<Integer> BTN_5_JKL_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_6_MNO_REQUEST)
  PropertyKey<Integer> BTN_6_MNO_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_7_PQRS_REQUEST)
  PropertyKey<Integer> BTN_7_PQRS_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_8_TUV_REQUEST)
  PropertyKey<Integer> BTN_8_TUV_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_9_WXYZ_REQUEST)
  PropertyKey<Integer> BTN_9_WXYZ_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_HASH_REQUEST)
  PropertyKey<Integer> BTN_HASH_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_STAR_REQUEST)
  PropertyKey<Integer> BTN_STAR_REQUEST = create();

  @CommsBinding(property = RadioInputs.ENTER_START_CALL_BTN_REQUEST)
  PropertyKey<Integer> ENTER_START_CALL_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.END_CALL_BTN_REQUEST)
  PropertyKey<Integer> END_CALL_BTN_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_UP_ARROW_REQUEST)
  PropertyKey<Integer> BTN_UP_ARROW_REQUEST = create();

  @CommsBinding(property = RadioInputs.BTN_DOWN_ARROW_REQUEST)
  PropertyKey<Integer> BTN_DOWN_ARROW_REQUEST = create();

}
