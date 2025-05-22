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

/**
 * This interface defines {@link PropertyKey} instances for screen changes
 * ApplicaitonInputs.
 * 
 */
public interface IAppInputsScreenChangeProperties
{
  @CommsBinding(property = VDUInputs.TCMS_SCREEN_CHANGE_REQUEST)
  PropertyKey<Integer> TCMS_SCREEN_CHANGE_REQUEST = create();

  @CommsBinding(property = VDUInputs.TCMS_POPUP_CHANGE_REQUEST)
  PropertyKey<Integer> TCMS_POPUP_CHANGE_REQUEST = create();

  @CommsBinding(property = VDUInputs.CCTV_SCREEN_CHANGE_REQUEST)
  PropertyKey<Integer> CCTV_SCREEN_CHANGE_REQUEST = create();

  @CommsBinding(property = VDUInputs.CCTV_POPUP_CHANGE_REQUEST)
  PropertyKey<Integer> CCTV_POPUP_CHANGE_REQUEST = create();
}
