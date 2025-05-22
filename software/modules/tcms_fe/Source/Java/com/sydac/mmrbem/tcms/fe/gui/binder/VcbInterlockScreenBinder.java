/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsVCBInterlockScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.VcbInterlockScreenModel;

public class VcbInterlockScreenBinder extends AbstractCommsListener
{

  private VcbInterlockScreenModel vcbInterlockScreenModel;

  public VcbInterlockScreenBinder(VcbInterlockScreenModel vcbInterlockScreenModel)
  {
    super();
    this.vcbInterlockScreenModel = vcbInterlockScreenModel;
    propertyKeyDefinitions.add(IAppOutputsVCBInterlockScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsVCBInterlockScreenProperties.VCB_INTERLOCK_STATUS.equals(key))
    {
      vcbInterlockScreenModel.setVcbInterlockState((byte[])newValue);
    }
  }

}
