/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsPantographInterlockScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.PantographInterlockScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.SpeedLimitInterlockScreenModel;

public class PantographInterlockScreenBinder extends AbstractCommsListener
{

  private PantographInterlockScreenModel pantographInterlockScreenModel;

  public PantographInterlockScreenBinder(PantographInterlockScreenModel pantographInterlockScreenModel)
  {
    super();
    this.pantographInterlockScreenModel = pantographInterlockScreenModel;
    propertyKeyDefinitions.add(IAppOutputsPantographInterlockScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsPantographInterlockScreenProperties.PANTO_STATUS.equals(key))
    {
      pantographInterlockScreenModel.setACPMState((byte[])newValue);
    }
  }

}
