/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsEnableToRunScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.EnableToRunInterlockScreenModel;

public class EnableToRunInterlockScreenBinder extends AbstractCommsListener
{

  private EnableToRunInterlockScreenModel enableToRunInterlockScreenModel;

  public EnableToRunInterlockScreenBinder(EnableToRunInterlockScreenModel ebInterlockScreenModel)
  {
    super();
    this.enableToRunInterlockScreenModel = ebInterlockScreenModel;
    propertyKeyDefinitions.add(IAppOutputsEnableToRunScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsEnableToRunScreenProperties.ENABLE_RUN_INTERLOCK_STATUS.equals(key))
    {
      enableToRunInterlockScreenModel.setEnableRunInterlockState((byte[])newValue);
    }
  }

}
