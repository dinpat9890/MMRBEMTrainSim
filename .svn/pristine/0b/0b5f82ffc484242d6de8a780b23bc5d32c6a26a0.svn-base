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
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTestSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.TestSystemScreenModel;

public class FireSystemTestScreenBinder extends AbstractCommsListener
{

  private TestSystemScreenModel testSystemScreenModel;

  public FireSystemTestScreenBinder(TestSystemScreenModel testSystemScreenModel)
  {
    super();
    this.testSystemScreenModel = testSystemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsTestSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsTestSystemScreenProperties.FIRE_SYSTEM_TEST_STATUS))
    {
      testSystemScreenModel.setActiveTestStatusList((byte[])newValue);
    }
    else if (key.equals(IAppOutputsTestSystemScreenProperties.FDS_TOTAL_PAGE))
    {
      testSystemScreenModel.setTotalPageNumber((Integer)newValue);
    }
    else if (key.equals(IAppOutputsTestSystemScreenProperties.FDS_CURRENT_PAGE))
    {
      testSystemScreenModel.setCurrentPageNumber((Integer)newValue);
    }
  }

}
