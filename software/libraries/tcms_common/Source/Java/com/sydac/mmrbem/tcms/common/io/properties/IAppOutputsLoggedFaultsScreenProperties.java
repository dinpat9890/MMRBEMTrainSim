/*******************************************************************************
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.common.io.properties;

import static com.sydac.foundation.PropertyKey.create;

import com.sydac.common.febe.binding.CommsBinding;
import com.sydac.foundation.PropertyKey;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUOutputs;

public interface IAppOutputsLoggedFaultsScreenProperties
{
  @CommsBinding(property = VDUOutputs.LOGGED_FAULTS_STATUS)
  PropertyKey<byte[]> LOGGED_FAULTS_STATUS = create();

  @CommsBinding(property = VDUOutputs.NO_OF_LOGGED_FAULTS)
  PropertyKey<Integer> NO_OF_LOGGED_FAULTS = create();

  @CommsBinding(property = VDUOutputs.NO_OF_LOGGED_FAULTS_PAGE)
  PropertyKey<Integer> NO_OF_LOGGED_FAULTS_PAGE = create();

  @CommsBinding(property = VDUOutputs.CURRENT_LOGGED_FAULTS_PAGE)
  PropertyKey<Integer> CURRENT_LOGGED_FAULTS_PAGE = create();

  @CommsBinding(property = VDUOutputs.LOGGED_FAULTS_TOTAL_LIST_COUNT)
  PropertyKey<Integer> LOGGED_FAULTS_TOTAL_LIST_COUNT = create();

  @CommsBinding(property = VDUOutputs.LOGGED_FAULT_SYS_FILTER_APPLIED)
  PropertyKey<Integer> LOGGED_FAULT_SYS_FILTER_APPLIED = create();

  @CommsBinding(property = VDUOutputs.LOGGED_FAULT_CAR_FILTER_APPLIED)
  PropertyKey<Integer> LOGGED_FAULT_CAR_FILTER_APPLIED = create();

  @CommsBinding(property = VDUOutputs.LOGGED_FAULT_PRIORITY_FILTER_APPLIED)
  PropertyKey<Integer> LOGGED_FAULT_PRIORITY_FILTER_APPLIED = create();

  @CommsBinding(property = VDUOutputs.LOGGED_FAULT_PAGE_UP_ACTIVE)
  PropertyKey<Integer> LOGGED_FAULT_PAGE_UP_ACTIVE = create();

  @CommsBinding(property = VDUOutputs.LOGGED_FAULT_PAGE_DOWN_ACTIVE)
  PropertyKey<Integer> LOGGED_FAULT_PAGE_DOWN_ACTIVE = create();
}
