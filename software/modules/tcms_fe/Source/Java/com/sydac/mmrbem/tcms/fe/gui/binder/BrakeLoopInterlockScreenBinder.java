/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsEnableToRunScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.BrakeLoopInterlockScreenModel;

public class BrakeLoopInterlockScreenBinder extends AbstractCommsListener
{

  private BrakeLoopInterlockScreenModel brakeLoopInterlockScreenModel;

  public BrakeLoopInterlockScreenBinder(BrakeLoopInterlockScreenModel abbrakeLoopInterlockScreenModel)
  {
    super();
    this.brakeLoopInterlockScreenModel = abbrakeLoopInterlockScreenModel;
    propertyKeyDefinitions.add(IAppOutputsEnableToRunScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {

    if (IAppOutputsEnableToRunScreenProperties.MAIN_RESERVOIR_PRESSURE_LOW_STATUS.equals(key))
    {
      brakeLoopInterlockScreenModel.setMainReserviorPressureState((byte[])newValue);
    }else if (IAppOutputsEnableToRunScreenProperties.ADD_INTERVENTION_STATUS.equals(key))
    {
      brakeLoopInterlockScreenModel.setAutomaticDropState((byte[])newValue);
    }else if (IAppOutputsEnableToRunScreenProperties.BRAKE_LOOP_CB_TRIPED_STATUS.equals(key))
    {
      brakeLoopInterlockScreenModel.setBrakeLoopCbState((byte[])newValue);
    }
  }

}
