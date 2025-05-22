/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsEBLoopInterlockScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.EmergencyBrakeInterlockScreenModel;

public class EmergencyBrakeInterlockScreenBinder extends AbstractCommsListener
{

  private EmergencyBrakeInterlockScreenModel ebInterlockScreenModel;

  public EmergencyBrakeInterlockScreenBinder(EmergencyBrakeInterlockScreenModel ebInterlockScreenModel)
  {
    super();
    this.ebInterlockScreenModel = ebInterlockScreenModel;
    propertyKeyDefinitions.add(IAppOutputsEBLoopInterlockScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsEBLoopInterlockScreenProperties.EB_INTERLOCK_STATUS.equals(key))
    {
      ebInterlockScreenModel.setEbInterlockState((byte[])newValue);
    }
  }

}
