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
import com.sydac.mmrbem.tcms.backend.app.io.handlers.IAppOutputsPISSystemTestScreenHandler;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.DateTimeModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.data.PISTestScreenDetailModel;
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
public class PISSystemTestScreenLogicHandler extends AbstractFunctionalLogic
{
  private TestSystemStatusList.Builder builder;

  private IAppOutputsPISSystemTestScreenHandler appOutputsPISSystemTestScreenHandler;

  private CommsBinding commsBinding;

  private XMLParser xmlParser;

  protected PISSystemTestScreenLogicHandler(CommsBinding commsBinding)
  {
    super(commsBinding, IAppInputsProperties.class);
    this.commsBinding = commsBinding;
    xmlParser = new XMLParser();
    initializeAppOutputHandler();
  }

  private byte[] updatePISSystemTestStatus()
  {
    byte[] brakeTestLists;
    builder = TCMSProto.TestSystemStatusList.newBuilder();

    for (PISTestScreenDetailModel spcInfo : getPisTestList())
    {
      TCMSProto.TestSystemStatusList.TestSystemStatus.Builder pisTests = TCMSProto.TestSystemStatusList.TestSystemStatus
          .newBuilder();
      pisTests.setId(spcInfo.getPisId());
      pisTests.setCarIndex(spcInfo.getCarId());
      pisTests.setComponenetName(spcInfo.getCompName());
      pisTests.setTestStatus(spcInfo.getPISStatus());
      pisTests.setLastUpdateDate(DateTimeModel.getInstance().getStartTime());
      pisTests.setLastUpdateTime(DateTimeModel.getInstance().getStartTime());

      builder.addTestSystemStatus(pisTests.build());
    }
    brakeTestLists = builder.build().toByteArray();

    return brakeTestLists;
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    initializeAppOutputHandler();

    if (getPisTestList() != null && !getPisTestList().isEmpty())
    {
      appOutputsPISSystemTestScreenHandler.setPisTestStatus(updatePISSystemTestStatus());
    }

  }

  private void initializeAppOutputHandler()
  {
    if (appOutputsPISSystemTestScreenHandler == null)
    {
      appOutputsPISSystemTestScreenHandler = (IAppOutputsPISSystemTestScreenHandler)commsBinding
          .getAppOutputsSetter();
    }
  }

  private List<PISTestScreenDetailModel> getPisTestList()
  {
    return xmlParser.getPISTestScreenDataList();
  }
}
