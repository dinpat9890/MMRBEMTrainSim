/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTCMSStatusScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.TCMSStatusScreenModel;

public class TCMSStatusScreenBinder extends AbstractCommsListener
{

  private TCMSStatusScreenModel tcmsStatusScreenModel;

  public TCMSStatusScreenBinder(TCMSStatusScreenModel tcmsStatusScreenModel)
  {
    this.tcmsStatusScreenModel = tcmsStatusScreenModel;
    propertyKeyDefinitions.add(IAppOutputsTCMSStatusScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTCMSStatusScreenProperties.CCU_STATUS.equals(key))
    {
      tcmsStatusScreenModel.setCCUState((byte[])newValue);
    }
     else if (IAppOutputsTCMSStatusScreenProperties.RIO_1_2_LINE_STATUS.equals(key))
    {
      tcmsStatusScreenModel.setRIO12LineState((byte[])newValue);
    }
    else if (IAppOutputsTCMSStatusScreenProperties.ER_STATUS.equals(key))
    {
      tcmsStatusScreenModel.setERState((byte[])newValue);
    }
    else if (IAppOutputsTCMSStatusScreenProperties.RIO1_STATUS.equals(key))
    {
      tcmsStatusScreenModel.setRIO1State((byte[])newValue);
    }
    else if (IAppOutputsTCMSStatusScreenProperties.RIO2_STATUS.equals(key))
    {
      tcmsStatusScreenModel.setRIO2State((byte[])newValue);
    }
   
  }
}
