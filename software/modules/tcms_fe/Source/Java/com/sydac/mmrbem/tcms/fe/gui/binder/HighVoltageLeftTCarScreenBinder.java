/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHighVolatageSystemCommandsScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageLeftTCarScreenModel;

public class HighVoltageLeftTCarScreenBinder extends AbstractCommsListener
{

  private HighVoltageLeftTCarScreenModel highVoltageLeftTCarScreenModel;

  public HighVoltageLeftTCarScreenBinder(HighVoltageLeftTCarScreenModel highVoltageScreenModel)
  {
    super();
    this.highVoltageLeftTCarScreenModel = highVoltageScreenModel;

    propertyKeyDefinitions.add(IAppOutputsHighVolatageSystemCommandsScreenProperties.class);

  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LEFT_BUTTON_STATE.equals(key))
    {
      highVoltageLeftTCarScreenModel.setLeftPantoState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LOW_LEFT_BUTTON_STATE.equals(key))
    {
      highVoltageLeftTCarScreenModel.setLeftPantoLowState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LEFT_RESET_BUTTON_STATE
        .equals(key))
    {
      highVoltageLeftTCarScreenModel.setLeftResetPantoState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_RESET_BUTTON_LEFT_STATE.equals(key))
    {
      highVoltageLeftTCarScreenModel.setLeftVcbResetState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_LEFT_VCB_STATE.equals(key))
    {
      highVoltageLeftTCarScreenModel.setLeftVcbIsolateState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS1_STATE.equals(key))
    {
      highVoltageLeftTCarScreenModel.setAps1IsolateState((Integer)newValue);

    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS2_STATE.equals(key))
    {
      highVoltageLeftTCarScreenModel.setAps2IsolateState((Integer)newValue);
    }
  }

}
