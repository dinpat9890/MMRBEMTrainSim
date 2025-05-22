package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHVACSystemStatusScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHighVolatageSystemCommandsScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.HVACSystemStatusScreenModel;

public class HVACSystemStatusScreenBinder extends AbstractCommsListener
{
  private HVACSystemStatusScreenModel hvacSystemStatusScreenModel;

  public HVACSystemStatusScreenBinder(HVACSystemStatusScreenModel hvacSystemStatusScreenModel)
  {
    super();
    this.hvacSystemStatusScreenModel = hvacSystemStatusScreenModel;
    propertyKeyDefinitions.add(IAppOutputsHVACSystemStatusScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
   propertyKeyDefinitions.add(IAppOutputsHighVolatageSystemCommandsScreenProperties.class);
    
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsHVACSystemStatusScreenProperties.HVAC_OPERATING_MODE_STATUS_1.equals(key))
    {
      hvacSystemStatusScreenModel.setHvacOperationModeStatusListOne((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.HVAC_OPERATING_MODE_STATUS_2.equals(key))
    {
      hvacSystemStatusScreenModel.setHvacOperationModeStatusListTwo((byte[])newValue);
    }
    else if (key.equals(IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS))
    {
      hvacSystemStatusScreenModel.setTotalColumn((Integer)newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.HVAC_CONTROL_MODE_STATUS_1.equals(key))
    {
      hvacSystemStatusScreenModel.setHvacControlModeStatusListOne((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.HVAC_CONTROL_MODE_STATUS_2.equals(key))
    {
      hvacSystemStatusScreenModel.setHvacControlModeStatusListTwo((byte[])newValue);
    }
  }
  
  

}
