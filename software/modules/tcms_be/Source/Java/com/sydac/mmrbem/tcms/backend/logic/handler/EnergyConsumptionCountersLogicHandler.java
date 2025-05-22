/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.List;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsEnergyConsumptionCounterScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsEnergyConsumpCountersScreenProperties;
import com.sydac.mmrbem.tcms.common.data.EnergyConsumptionScreenDetailModel;
import com.sydac.mmrbem.tcms.common.data.HVACTestScreenDetailModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EnergyConsumpCountersList;
import com.sydac.mmrbem.tcms.common.utils.XMLParser;

/**
 * This handler class is used for handling Energy Consumption Counters screen
 * data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class EnergyConsumptionCountersLogicHandler extends AbstractFunctionalLogic
{
  private EnergyConsumpCountersList.Builder builder;

  private IAppOutputsEnergyConsumptionCounterScreenHandler appOutputsEnergyConsumptionCounterScreenHandler;

  private CommsBinding commsBinding;

  private XMLParser xmlParser;

  protected EnergyConsumptionCountersLogicHandler(CommsBinding commsBinding)
  {
    super(commsBinding, ITCMSVehicleOutputsEnergyConsumpCountersScreenProperties.class);
    this.commsBinding = commsBinding;
    xmlParser = new XMLParser();
    initializeAppOutputHandler();
  }

  private byte[] updateEnergyConsumpCounterList()
  {
    byte[] energyCounters;
    builder = TCMSProto.EnergyConsumpCountersList.newBuilder();

    for (EnergyConsumptionScreenDetailModel spcInfo : getEnergyConsumptionList())
    {
      TCMSProto.EnergyConsumpCountersList.EnergyConsumpStatus.Builder countersBuilder = TCMSProto.EnergyConsumpCountersList.EnergyConsumpStatus
          .newBuilder();
      countersBuilder.setCounterName(spcInfo.getDescName()); // $NON-NLS-1$
      countersBuilder.setDescription(spcInfo.getCompName()); // $NON-NLS-1$
      countersBuilder.setCurrentValue(spcInfo.getEnergyValue());
      countersBuilder.setMeasurUnit("kWh"); //$NON-NLS-1$
      builder.addEnergyConsumpStatus(countersBuilder.build());
    }
    energyCounters = builder.build().toByteArray();

    return energyCounters;
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    initializeAppOutputHandler();
    appOutputsEnergyConsumptionCounterScreenHandler
        .setEnergyConsumptionCountersStatus(updateEnergyConsumpCounterList());
  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsEnergyConsumptionCounterScreenHandler == null)
    {
      appOutputsEnergyConsumptionCounterScreenHandler = (IAppOutputsEnergyConsumptionCounterScreenHandler)commsBinding
          .getAppOutputsSetter();
    }
  }

  private List<EnergyConsumptionScreenDetailModel> getEnergyConsumptionList()
  {
    return xmlParser.getEnergyConsumptionScreenDataList();
  }
}
