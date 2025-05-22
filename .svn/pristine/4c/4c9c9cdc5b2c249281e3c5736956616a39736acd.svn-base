package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsRBScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.RbCommandScreenModel;

public class RbCommandScreenBinder extends AbstractCommsListener
{
  private RbCommandScreenModel rbCommandScreenModel;

  public RbCommandScreenBinder(RbCommandScreenModel bCommandScreenModel)
  {
    super();
    this.rbCommandScreenModel = bCommandScreenModel;
    propertyKeyDefinitions.add(IAppOutputsRBScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsRBScreenProperties.RB_HVAC1_STATUS.equals(key))
    {
      rbCommandScreenModel.setHvac1Status((byte[])newValue);
    }else if (IAppOutputsRBScreenProperties.RB_HVAC2_STATUS.equals(key))
    {
      rbCommandScreenModel.setHvac2Status((byte[])newValue);
    }
    else if (IAppOutputsRBScreenProperties.RB_FDSCB_STATUS.equals(key))
    {
      rbCommandScreenModel.setFdscbStatus((byte[])newValue);
    }
    else if (IAppOutputsRBScreenProperties.RB_APSICB_STATUS.equals(key))
    {
      rbCommandScreenModel.setApsicbStatus((byte[])newValue);
    }
    
  }

}
