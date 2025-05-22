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

public interface IAppOutputsActiveFaultsScreenProperties
{
  @CommsBinding(property = VDUOutputs.ACTIVE_FAULTS_STATUS)
  PropertyKey<byte[]> ACTIVE_FAULTS_STATUS = create();

  @CommsBinding(property = VDUOutputs.NO_OF_ACTIVE_FAULTS)
  PropertyKey<Integer> NO_OF_ACTIVE_FAULTS = create();

  @CommsBinding(property = VDUOutputs.NO_OF_ACTIVE_FAULTS_PAGE)
  PropertyKey<Integer> NO_OF_ACTIVE_FAULTS_PAGE = create();

  @CommsBinding(property = VDUOutputs.CURRENT_ACTIVE_FAULTS_PAGE)
  PropertyKey<Integer> CURRENT_ACTIVE_FAULTS_PAGE = create();

  @CommsBinding(property = VDUOutputs.ACTIVE_FAULT_LIST_UPDATED)
  PropertyKey<Integer> ACTIVE_FAULT_LIST_UPDATED = create();

  @CommsBinding(property = VDUOutputs.FAULTS_BUTTON_PRIORITY_STATE)
  PropertyKey<Integer> FAULTS_BUTTON_PRIORITY_STATE = create();

  @CommsBinding(property = VDUOutputs.ACTIVE_FAULTS_TOTAL_LIST_COUNT)
  PropertyKey<Integer> ACTIVE_FAULTS_TOTAL_LIST_COUNT = create();

  @CommsBinding(property = VDUOutputs.ACTIVE_FAULT_SYS_FILTER_APPLIED)
  PropertyKey<Integer> ACTIVE_FAULT_SYS_FILTER_APPLIED = create();

  @CommsBinding(property = VDUOutputs.ACTIVE_FAULT_CAR_FILTER_APPLIED)
  PropertyKey<Integer> ACTIVE_FAULT_CAR_FILTER_APPLIED = create();

  @CommsBinding(property = VDUOutputs.ACTIVE_FAULT_PRIORITY_FILTER_APPLIED)
  PropertyKey<Integer> ACTIVE_FAULT_PRIORITY_FILTER_APPLIED = create();

  @CommsBinding(property = VDUOutputs.ACTIVE_FAULT_PAGE_UP_ACTIVE)
  PropertyKey<Integer> ACTIVE_FAULT_PAGE_UP_ACTIVE = create();

  @CommsBinding(property = VDUOutputs.ACTIVE_FAULT_PAGE_DOWN_ACTIVE)
  PropertyKey<Integer> ACTIVE_FAULT_PAGE_DOWN_ACTIVE = create();
}
