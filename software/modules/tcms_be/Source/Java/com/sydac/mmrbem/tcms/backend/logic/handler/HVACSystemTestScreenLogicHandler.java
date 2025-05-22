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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsHVACSystemTestScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.data.HVACTestScreenDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TestSystemStatusList;
import com.sydac.mmrbem.tcms.common.utils.XMLParser;

/**
 * This handler class is used for handling Brake System Test Screen Data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class HVACSystemTestScreenLogicHandler extends AbstractFunctionalLogic
{
  private TestSystemStatusList.Builder builder;

  private IAppOutputsHVACSystemTestScreenHandler appOutputsHVACSystemTestScreenHandler;

  private CommsBinding commsBinding;

  private XMLParser xmlParser;

  protected HVACSystemTestScreenLogicHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class);
    this.commsBinding = commsBinding;
    xmlParser = new XMLParser();
    initializeAppOutputHandler();
  }

  private byte[] updateHVACSystemTestStatus()
  {
    byte[] brakeTestLists;
    builder = TCMSProto.TestSystemStatusList.newBuilder();

    for (HVACTestScreenDetailModel spcInfo : getHvacTestList())
    {
      TCMSProto.TestSystemStatusList.TestSystemStatus.Builder hvacTests = TCMSProto.TestSystemStatusList.TestSystemStatus
          .newBuilder();
      hvacTests.setId(spcInfo.getHvaCId());
      hvacTests.setCarIndex(spcInfo.getCarId());
      hvacTests.setComponenetName(spcInfo.getCompName());
      hvacTests.setTestStatus(spcInfo.getHvacStatus());
      hvacTests.setLastUpdateDate(DateTimeModel.getInstance().getStartTime());
      hvacTests.setLastUpdateTime(DateTimeModel.getInstance().getStartTime());

      builder.addTestSystemStatus(hvacTests.build());
    }
    brakeTestLists = builder.build().toByteArray();

    return brakeTestLists;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    initializeAppOutputHandler();

    if (getHvacTestList() != null && !getHvacTestList().isEmpty())
    {
      appOutputsHVACSystemTestScreenHandler.setHVACSystemTestStatus(updateHVACSystemTestStatus());
    }

  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsHVACSystemTestScreenHandler == null)
    {
      appOutputsHVACSystemTestScreenHandler = (IAppOutputsHVACSystemTestScreenHandler)commsBinding
          .getAppOutputsSetter();
    }
  }

  private List<HVACTestScreenDetailModel> getHvacTestList()
  {
    return xmlParser.getHVACTestScreenDataList();
  }

}
