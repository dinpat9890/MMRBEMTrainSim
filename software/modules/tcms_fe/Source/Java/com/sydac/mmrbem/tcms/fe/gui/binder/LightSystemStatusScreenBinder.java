/******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLightSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.LightSystemStatusScreenModel;

public class LightSystemStatusScreenBinder extends AbstractCommsListener
{
  private LightSystemStatusScreenModel lightSystemStatusScreenModel;

  public LightSystemStatusScreenBinder(LightSystemStatusScreenModel lightSystemStatusScreenModel)
  {
    super();
    this.lightSystemStatusScreenModel = lightSystemStatusScreenModel;
    propertyKeyDefinitions.add(IAppOutputsLightSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsLightSystemScreenProperties.SALOON_LIGHT_GROUP_STATUS_1))
    {
      lightSystemStatusScreenModel.setSaloonLightStatusList1((byte[])newValue);
    }
    else if (key.equals(IAppOutputsLightSystemScreenProperties.SALOON_LIGHT_GROUP_STATUS_2))
    {
      lightSystemStatusScreenModel.setSaloonLightStatusList2((byte[])newValue);
    }
    else if (key.equals(IAppOutputsLightSystemScreenProperties.FLASHER_LIGHT_STATUS))
    {
      lightSystemStatusScreenModel.setFlasherLightStatusList((byte[])newValue);
    }
    else if (key.equals(IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS))
    {
      lightSystemStatusScreenModel.setTotalColumn((Integer)newValue);
    }
  }

}
