/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLowVoltageSystemCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.LowVoltageSystemCommandScreenModel;

public class LowVoltageSystemCommandScreenBinder extends AbstractCommsListener
{
  private LowVoltageSystemCommandScreenModel lowVoltageSystemCommandScreenModel;

  public LowVoltageSystemCommandScreenBinder(
      LowVoltageSystemCommandScreenModel lowVoltageSystemCommandScreenModel)
  {
    super();
    this.lowVoltageSystemCommandScreenModel = lowVoltageSystemCommandScreenModel;
    propertyKeyDefinitions.add(IAppOutputsLowVoltageSystemCommandScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS))
    {
      lowVoltageSystemCommandScreenModel.setTotalColumn((Integer)newValue);
    }
    else if (key.equals(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M1_STATUS))
    {
      lowVoltageSystemCommandScreenModel.setIsolateBcg1M1Status((Integer)newValue);
    }else if (key.equals(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M2_STATUS))
    {
      lowVoltageSystemCommandScreenModel.setIsolateBcg1M2Status((Integer)newValue);
    }else if (key.equals(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M3_STATUS))
    {
      lowVoltageSystemCommandScreenModel.setIsolateBcg1M3Status((Integer)newValue);
    }else if (key.equals(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M1_STATUS))
    {
      lowVoltageSystemCommandScreenModel.setIsolateBcg2M1Status((Integer)newValue);
    }else if (key.equals(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M2_STATUS))
    {
      lowVoltageSystemCommandScreenModel.setIsolateBcg2M2Status((Integer)newValue); 
    }else if (key.equals(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M3_STATUS))
    {
      lowVoltageSystemCommandScreenModel.setIsolateBcg2M3Status((Integer)newValue);
    }else if (key.equals(IAppOutputsLowVoltageSystemCommandScreenProperties.LV_POPB_STATUS))
    {
      lowVoltageSystemCommandScreenModel.setPOPBStatus((Integer)newValue);
    }

  }
}
