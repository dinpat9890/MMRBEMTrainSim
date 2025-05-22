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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBatterySystemTestScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.data.BatteryTestScreenDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TestSystemStatusList;
import com.sydac.mmrbem.tcms.common.utils.XMLParser;

/**
 * This handler class is used for handling Battery System Test Screen Data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class BatterySystemTestScreenLogicHandler extends AbstractFunctionalLogic
{
  private TestSystemStatusList.Builder builder;

  private IAppOutputsBatterySystemTestScreenHandler appOutputsBatterySystemTestScreenHandler;

  private CommsBinding commsBinding;

  private XMLParser xmlParser;

  protected BatterySystemTestScreenLogicHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class);
    this.commsBinding = commsBinding;
    xmlParser = new XMLParser();
    initializeAppOutputHandler();
  }

  private byte[] updateBatterySystemTestStatus()
  {
    byte[] brakeTestLists;
    builder = TCMSProto.TestSystemStatusList.newBuilder();

    for (BatteryTestScreenDetailModel spcInfo : getBatteryTestList())
    {
      TCMSProto.TestSystemStatusList.TestSystemStatus.Builder batteryTests = TCMSProto.TestSystemStatusList.TestSystemStatus
          .newBuilder();
      batteryTests.setId(spcInfo.getBatteryId());
      batteryTests.setCarIndex(spcInfo.getCarId());
      batteryTests.setComponenetName(spcInfo.getCompName());
      batteryTests.setTestStatus(spcInfo.getBatteryStatus());
      batteryTests.setLastUpdateDate(DateTimeModel.getInstance().getStartTime());
      batteryTests.setLastUpdateTime(DateTimeModel.getInstance().getStartTime());

      builder.addTestSystemStatus(batteryTests.build());
    }
    brakeTestLists = builder.build().toByteArray();

    return brakeTestLists;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    initializeAppOutputHandler();
    if (getBatteryTestList() != null && !getBatteryTestList().isEmpty())
    {
      appOutputsBatterySystemTestScreenHandler.setBatterySystemTestStatus(updateBatterySystemTestStatus());
    }
  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsBatterySystemTestScreenHandler == null)
    {
      appOutputsBatterySystemTestScreenHandler = (IAppOutputsBatterySystemTestScreenHandler)commsBinding
          .getAppOutputsSetter();
    }
  }

  private List<BatteryTestScreenDetailModel> getBatteryTestList()
  {
    return xmlParser.getBatteryTestScreenDataList();
  }

}
