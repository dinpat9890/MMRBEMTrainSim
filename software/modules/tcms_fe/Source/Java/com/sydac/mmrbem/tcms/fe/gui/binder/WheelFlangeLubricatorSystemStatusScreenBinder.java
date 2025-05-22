/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsWheelFlangeLubricatorScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.WheelFlangeLubricatorSystemStatusScreenModel;

public class WheelFlangeLubricatorSystemStatusScreenBinder extends AbstractCommsListener
{
  private WheelFlangeLubricatorSystemStatusScreenModel wheelFlangeLubricatorSystemStatusScreenModel;

  public WheelFlangeLubricatorSystemStatusScreenBinder(
      WheelFlangeLubricatorSystemStatusScreenModel wheelFlangeLubricatorSystemStatusScreenModel)
  {
    super();
    this.wheelFlangeLubricatorSystemStatusScreenModel = wheelFlangeLubricatorSystemStatusScreenModel;
    propertyKeyDefinitions.add(IAppOutputsWheelFlangeLubricatorScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsWheelFlangeLubricatorScreenProperties.WFL_STATUS))
    {
      wheelFlangeLubricatorSystemStatusScreenModel.setWflStatusList((byte[])newValue);
    }
    else if (key.equals(IAppOutputsWheelFlangeLubricatorScreenProperties.WFL_OIL_LEVEL_STATUS))
    {
      wheelFlangeLubricatorSystemStatusScreenModel.setWflOilLevelStatusList((byte[])newValue);
    }
    else if (key.equals(IAppOutputsWheelFlangeLubricatorScreenProperties.WFL_PUMP_STATUS_1))
    {
      wheelFlangeLubricatorSystemStatusScreenModel.setWflPumpStatusListOne((byte[])newValue);
    }
    else if (key.equals(IAppOutputsWheelFlangeLubricatorScreenProperties.WFL_PUMP_STATUS_2))
    {
      wheelFlangeLubricatorSystemStatusScreenModel.setWflPumpStatusListTwo((byte[])newValue);
    }
    else if (key.equals(IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS))
    {
      wheelFlangeLubricatorSystemStatusScreenModel.setTotalColumn((Integer)newValue);
    }
    else if (key.equals(IAppOutputsWheelFlangeLubricatorScreenProperties.WFL_ISOLATED_STATUS_FRONT_CAR))
    {
      wheelFlangeLubricatorSystemStatusScreenModel.setFrontCarWflIsolatedStatus((Integer)newValue);
    }
    else if (key.equals(IAppOutputsWheelFlangeLubricatorScreenProperties.WFL_ISOLATED_STATUS_REAR_CAR))
    {
      wheelFlangeLubricatorSystemStatusScreenModel.setRearCarWflIsolatedStatus((Integer)newValue);
    }
  }

}
