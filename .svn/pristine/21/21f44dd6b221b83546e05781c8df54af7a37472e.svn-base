/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsBatterySystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLowVoltageSystemScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.LowVoltageScreenModel;

public class LowVoltageSystemScreenBinder extends AbstractCommsListener
{

  private LowVoltageScreenModel lowVoltageScreenModel;

  public LowVoltageSystemScreenBinder(LowVoltageScreenModel lowVoltageScreenModel)
  {
    this.lowVoltageScreenModel = lowVoltageScreenModel;
    propertyKeyDefinitions.add(IAppOutputsBatterySystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsLowVoltageSystemScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsBatterySystemScreenProperties.BCG_STATUS.equals(key))
    {
      lowVoltageScreenModel.setBCGState((byte[])newValue);
    }
    else if (IAppOutputsLowVoltageSystemScreenProperties.LV_BIC_SWITCH_STATUS_LIST.equals(key))
    {
      lowVoltageScreenModel.setBICState((byte[])newValue);
    }
    else if (IAppOutputsLowVoltageSystemScreenProperties.LV_TCC_SWITCH_STATUS_LIST.equals(key))
    {
      lowVoltageScreenModel.setTCCState((byte[])newValue);
    }
  }
}
