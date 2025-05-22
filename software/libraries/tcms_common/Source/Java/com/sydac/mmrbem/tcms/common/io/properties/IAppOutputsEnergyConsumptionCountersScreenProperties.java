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

public interface IAppOutputsEnergyConsumptionCountersScreenProperties
{
  @CommsBinding(property = VDUOutputs.ENERGY_CONSUMPTION_COUNTERS_STATUS)
  PropertyKey<byte[]> ENERGY_CONSUMPTION_COUNTERS_STATUS = create();

  @CommsBinding(property = VDUOutputs.ENERGY_CONSUMP_COUNTER_TOTAL_PAGES)
  PropertyKey<Integer> ENERGY_CONSUMP_COUNTER_TOTAL_PAGES = create();

  @CommsBinding(property = VDUOutputs.ENERGY_CONSUMP_COUNTER_CURRENT_PAGE)
  PropertyKey<Integer> ENERGY_CONSUMP_COUNTER_CURRENT_PAGE = create();

  @CommsBinding(property = VDUOutputs.ENERGY_CONSUPTION_TOTAL_COUNTER)
  PropertyKey<Integer> ENERGY_CONSUPTION_TOTAL_COUNTER = create();
}