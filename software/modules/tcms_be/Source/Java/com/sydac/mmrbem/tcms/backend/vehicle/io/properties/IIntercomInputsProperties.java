/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.backend.vehicle.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.IntercomInputs;

/**
 * This interface defines {@link PropertyKey} instances for ApplicaitonOutputs.
 *
 */
public interface IIntercomInputsProperties
{
  @CommsBinding(property = IntercomInputs.CAB_INTERCOM_BUTTON)
  PropertyKey<Integer> CAB_INTERCOM_BUTTON = create();

  @CommsBinding(property = IntercomInputs.CAB_CANCEL_BUTTON)
  PropertyKey<Integer> CAB_CANCEL_BUTTON = create();
}
