/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsEnergyConsumptionCountersScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.EnergyConsumptionCountersScreenModel;

public class EnergyConsumptionCountersScreenBinder extends AbstractCommsListener
{
  private EnergyConsumptionCountersScreenModel energyConsumptionCountersScreenModel;

  public EnergyConsumptionCountersScreenBinder(
      EnergyConsumptionCountersScreenModel energyConsumptionCountersScreenModel)
  {
    super();
    this.energyConsumptionCountersScreenModel = energyConsumptionCountersScreenModel;
    propertyKeyDefinitions.add(IAppOutputsEnergyConsumptionCountersScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsEnergyConsumptionCountersScreenProperties.ENERGY_CONSUPTION_TOTAL_COUNTER.equals(key))
    {
      energyConsumptionCountersScreenModel.setTotalEnergyConsumpCounters((Integer)newValue);
    }
    else if (IAppOutputsEnergyConsumptionCountersScreenProperties.ENERGY_CONSUMPTION_COUNTERS_STATUS
        .equals(key))
    {
      energyConsumptionCountersScreenModel.setEnergyConsumptionCounters((byte[])newValue);
    }
    else if (IAppOutputsEnergyConsumptionCountersScreenProperties.ENERGY_CONSUMP_COUNTER_CURRENT_PAGE
        .equals(key))
    {
      energyConsumptionCountersScreenModel.setCurrentPageNumber((Integer)newValue);
    }
    else if (IAppOutputsEnergyConsumptionCountersScreenProperties.ENERGY_CONSUMP_COUNTER_TOTAL_PAGES
        .equals(key))
    {
      energyConsumptionCountersScreenModel.setTotalPageNumber((Integer)newValue);
    }
  }

}
