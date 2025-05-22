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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsBrakeSystemTestScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.data.BrakeTestScreenDetailModel;
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
public class BrakeSystemTestScreenLogicHandler extends AbstractFunctionalLogic
{
  private TestSystemStatusList.Builder builder;

  private IAppOutputsBrakeSystemTestScreenHandler appOutputsBrakeSystemTestScreenHandler;

  private CommsBinding commsBinding;
  private XMLParser xmlParser;
  protected BrakeSystemTestScreenLogicHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class);
    this.commsBinding = commsBinding;
    xmlParser = new XMLParser();  
    initializeAppOutputHandler();
  }

  private byte[] updateBrakeSystemTestStatus()
  {
    byte[] brakeTestLists;
    builder = TCMSProto.TestSystemStatusList.newBuilder();

    for (BrakeTestScreenDetailModel spcInfo : getBrakeTestList())
    {
      TCMSProto.TestSystemStatusList.TestSystemStatus.Builder brakeTests = TCMSProto.TestSystemStatusList.TestSystemStatus
          .newBuilder();
      brakeTests.setId(spcInfo.getBrakeId());
      brakeTests.setCarIndex(spcInfo.getCarId());
      brakeTests.setComponenetName(spcInfo.getCompName());
      brakeTests.setTestStatus(spcInfo.getSystemStatus());
      brakeTests.setLastUpdateDate(DateTimeModel.getInstance().getStartTime());
      brakeTests.setLastUpdateTime(DateTimeModel.getInstance().getStartTime());

      builder.addTestSystemStatus(brakeTests.build());
    }
    brakeTestLists = builder.build().toByteArray();

    return brakeTestLists;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
    initializeAppOutputHandler();
    if(getBrakeTestList() !=null && !getBrakeTestList().isEmpty())
    {
    appOutputsBrakeSystemTestScreenHandler.setBrakeSystemTestStatus(updateBrakeSystemTestStatus());
    }
    }
  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsBrakeSystemTestScreenHandler == null)
    {
      appOutputsBrakeSystemTestScreenHandler = (IAppOutputsBrakeSystemTestScreenHandler)commsBinding
          .getAppOutputsSetter();
    }
  }
  
  private List<BrakeTestScreenDetailModel> getBrakeTestList()
  {
    return xmlParser.getBrakeTestScreenDataList();
  }
  
  
 
}
