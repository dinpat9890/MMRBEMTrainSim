/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsAPSSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.APSSystemScreenModel;

public class APSSystemScreenBinder extends AbstractCommsListener
{
  private APSSystemScreenModel apsSystemScreenModel;

  public APSSystemScreenBinder(APSSystemScreenModel apsSystemScreenModel)
  {
    super();
    this.apsSystemScreenModel = apsSystemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsAPSSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsAPSSystemScreenProperties.APS_CONTROL_UNIT_STATUS.equals(key))
    {
      apsSystemScreenModel.setApsControlUnitStatusList((byte[])newValue);
    }
    else if (IAppOutputsAPSSystemScreenProperties.AK_STATUS.equals(key))
    {
      apsSystemScreenModel.setAkStatusList((byte[])newValue);
    }
    else if (IAppOutputsAPSSystemScreenProperties.K_STATUS.equals(key))
    {
      apsSystemScreenModel.setkStatusList((byte[])newValue);
    }
    else if (IAppOutputsAPSSystemScreenProperties.APS_OUTPUT_VOLTAGE_STATUS.equals(key))
    {
      apsSystemScreenModel.setApsOutputVoltageStatusList((byte[])newValue);
    }
    else if (IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS.equals(key))
    {
      apsSystemScreenModel.setTotalColumn((Integer)newValue);
    }
  }

}
