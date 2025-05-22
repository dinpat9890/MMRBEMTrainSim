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
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageMiddleTCarScreenModel;

public class HighVoltageMiddleTCarScreenBinder extends AbstractCommsListener
{

  private HighVoltageMiddleTCarScreenModel highVoltageMiddleTCarScreenModel;

  public HighVoltageMiddleTCarScreenBinder(HighVoltageMiddleTCarScreenModel highVoltageScreenModel)
  {
    super();
    this.highVoltageMiddleTCarScreenModel = highVoltageScreenModel;

    propertyKeyDefinitions.add(IAppOutputsHighVolatageSystemCommandsScreenProperties.class);

  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_MIDDLE_BUTTON_STATE.equals(key))
    {
      highVoltageMiddleTCarScreenModel.setMiddlePantoState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LOW_MIDDLE_BUTTON_STATE
        .equals(key))
    {
      highVoltageMiddleTCarScreenModel.setMiddlePantoLowState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_MIDDLE_RESET_BUTTON_STATE
        .equals(key))
    {
      highVoltageMiddleTCarScreenModel.setMidResetPantoState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_RESET_BUTTON_MIDDLE_STATE.equals(key))
    {
      highVoltageMiddleTCarScreenModel.setMidVcbResetState((Integer)newValue);

    }
  
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_MIDDLE_VCB_STATE.equals(key))
    {
      highVoltageMiddleTCarScreenModel.setMidVcbIsolateState((Integer)newValue);

    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS3_STATE.equals(key))
    {
      highVoltageMiddleTCarScreenModel.setAps3IsolateState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS4_STATE.equals(key))
    {
      highVoltageMiddleTCarScreenModel.setAps4IsolateState((Integer)newValue);
    }
  }

}
