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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsDoorSystemTestScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.data.DoorTestScreenDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TestSystemStatusList;
import com.sydac.mmrbem.tcms.common.utils.XMLParser;

/**
 * This handler class is used for handling Door System Test Screen Data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class DoorSystemTestScreenLogicHandler extends AbstractFunctionalLogic
{
  private TestSystemStatusList.Builder builder;

  private IAppOutputsDoorSystemTestScreenHandler appOutputsDoorSystemTestScreenHandler;

  private CommsBinding commsBinding;

  private XMLParser xmlParser;

  protected DoorSystemTestScreenLogicHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class);
    this.commsBinding = commsBinding;
    xmlParser = new XMLParser();
    initializeAppOutputHandler();

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      initializeAppOutputHandler();

      if (getDoorTestList() != null && !getDoorTestList().isEmpty())
      {
        appOutputsDoorSystemTestScreenHandler.setDoorSystemTestStatus(updateDoorSystemTestStatus());

      }
    }
  }

  private byte[] updateDoorSystemTestStatus()
  {
    byte[] brakeTestLists;
    builder = TCMSProto.TestSystemStatusList.newBuilder();

    for (DoorTestScreenDetailModel spcInfo : getDoorTestList())
    {
      TCMSProto.TestSystemStatusList.TestSystemStatus.Builder doorTests = TCMSProto.TestSystemStatusList.TestSystemStatus
          .newBuilder();
      doorTests.setId(spcInfo.getDoorId());
      doorTests.setCarIndex(spcInfo.getCarId());
      doorTests.setComponenetName(spcInfo.getCompName());
      doorTests.setTestStatus(spcInfo.getDoorStatus());
      doorTests.setLastUpdateDate(DateTimeModel.getInstance().getStartTime());
      doorTests.setLastUpdateTime(DateTimeModel.getInstance().getStartTime());

      builder.addTestSystemStatus(doorTests.build());
    }
    brakeTestLists = builder.build().toByteArray();

    return brakeTestLists;
  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsDoorSystemTestScreenHandler == null)
    {
      appOutputsDoorSystemTestScreenHandler = (IAppOutputsDoorSystemTestScreenHandler)commsBinding
          .getAppOutputsSetter();
    }
  }

  private List<DoorTestScreenDetailModel> getDoorTestList()
  {
    return xmlParser.getDoorTestScreenDataList();
  }

}
