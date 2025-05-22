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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsFireSystemTestScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;

import com.sydac.mmrbem.tcms.common.data.FireTestScreenDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TestSystemStatusList;
import com.sydac.mmrbem.tcms.common.utils.XMLParser;

/**
 * This handler class is used for handling Fire System Test Screen Data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class FireSystemTestScreenLogiHandler extends AbstractFunctionalLogic
{
  private TestSystemStatusList.Builder builder;

  private IAppOutputsFireSystemTestScreenHandler appOutputsFireSystemTestScreenHandler;

  private CommsBinding commsBinding;
  private XMLParser xmlParser;
  protected FireSystemTestScreenLogiHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class);
    this.commsBinding = commsBinding;
    xmlParser = new XMLParser();  
    initializeAppOutputHandler();
  }

  private byte[] updateFireSystemTestStatus()
  {
    byte[] fireTestsLists;
    builder = TCMSProto.TestSystemStatusList.newBuilder();

    for (FireTestScreenDetailModel spcInfo : getFireTestList())
    {
      TCMSProto.TestSystemStatusList.TestSystemStatus.Builder fireTests = TCMSProto.TestSystemStatusList.TestSystemStatus
          .newBuilder();
      fireTests.setId(spcInfo.getFireId());
      fireTests.setCarIndex(spcInfo.getCarId());
      fireTests.setComponenetName(spcInfo.getCompName());
      fireTests.setTestStatus(spcInfo.getFireStatus());
      fireTests.setLastUpdateDate(DateTimeModel.getInstance().getStartTime());
      fireTests.setLastUpdateTime(DateTimeModel.getInstance().getStartTime());

      builder.addTestSystemStatus(fireTests.build());
    }
    fireTestsLists = builder.build().toByteArray();

    return fireTestsLists;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    initializeAppOutputHandler();
    if(getFireTestList() !=null && !getFireTestList().isEmpty())
    {
    appOutputsFireSystemTestScreenHandler.setFireSystemTestStatus(updateFireSystemTestStatus());
    }
  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsFireSystemTestScreenHandler == null)
    {
      appOutputsFireSystemTestScreenHandler = (IAppOutputsFireSystemTestScreenHandler)commsBinding
          .getAppOutputsSetter();
    }
  }
  
  private List<FireTestScreenDetailModel> getFireTestList()
  {
    return xmlParser.getFireTestScreenDataList();
  }
  
}
