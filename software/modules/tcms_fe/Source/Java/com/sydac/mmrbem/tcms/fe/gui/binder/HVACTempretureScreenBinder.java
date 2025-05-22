package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHVACSystemStatusScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.HVACTempretureScreenModel;

public class HVACTempretureScreenBinder extends AbstractCommsListener
{
  private HVACTempretureScreenModel hvacTempScreenModel;

  public HVACTempretureScreenBinder(HVACTempretureScreenModel hvacSystemStatusScreenModel)
  {
    super();
    this.hvacTempScreenModel = hvacSystemStatusScreenModel;
    propertyKeyDefinitions.add(IAppOutputsHVACSystemStatusScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
     if (IAppOutputsHVACSystemStatusScreenProperties.SET_POINT_TEMPERATURE_STATUS_1.equals(key))
    {
      hvacTempScreenModel.setSetPointTemperatureStatusListOne((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.SET_POINT_TEMPERATURE_STATUS_2.equals(key))
    {
      hvacTempScreenModel.setSetPointTemperatureStatusListTwo((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.INTERNAL_TEMPERATURE_STATUS_1.equals(key))
    {
      hvacTempScreenModel.setInternalTemperatureStatusListOne((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.INTERNAL_TEMPERATURE_STATUS_2.equals(key))
    {
      hvacTempScreenModel.setInternalTemperatureStatusListTwo((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.EXTERNAL_TEMPERATURE_STATUS_1.equals(key))
    {
      hvacTempScreenModel.setExternalTemperatureStatusListOne((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.EXTERNAL_TEMPERATURE_STATUS_2.equals(key))
    {
      hvacTempScreenModel.setExternalTemperatureStatusListTwo((byte[])newValue);
    }
    else if (key.equals(IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS))
    {
      hvacTempScreenModel.setTotalColumn((Integer)newValue);
    }
  }

}
