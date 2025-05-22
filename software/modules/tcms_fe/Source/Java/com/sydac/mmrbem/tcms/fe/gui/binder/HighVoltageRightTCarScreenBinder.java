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
import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageRightTCarScreenModel;

public class HighVoltageRightTCarScreenBinder extends AbstractCommsListener
{

  private HighVoltageRightTCarScreenModel highVoltageRightTCarScreenModel;

  public HighVoltageRightTCarScreenBinder(HighVoltageRightTCarScreenModel highVoltageScreenModel)
  {
    super();
    this.highVoltageRightTCarScreenModel = highVoltageScreenModel;

    propertyKeyDefinitions.add(IAppOutputsHighVolatageSystemCommandsScreenProperties.class);

  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_RIGHT_BUTTON_STATE.equals(key))
    {
      highVoltageRightTCarScreenModel.setRightPantoState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_LOW_RIGHT_BUTTON_STATE
        .equals(key))
    {
      highVoltageRightTCarScreenModel.setRightPantoLowState((Integer)newValue);
    }
    else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.HV_PANTO_RIGHT_RESET_BUTTON_STATE
        .equals(key))
    {
      highVoltageRightTCarScreenModel.setRightResetPantoState((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_RESET_BUTTON_RIGHT_STATE
        .equals(key))
    {
      highVoltageRightTCarScreenModel.setRightVcbResetState((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_RIGHT_VCB_STATE
        .equals(key))
    {
      highVoltageRightTCarScreenModel.setRightVcbIsolateState((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS5_STATE
        .equals(key))
    {
      highVoltageRightTCarScreenModel.setAps5IsolateState((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.ISOLATE_APS6_STATE
        .equals(key))
    {
      highVoltageRightTCarScreenModel.setAps6IsolateState((Integer)newValue);
    }else if (IAppOutputsHighVolatageSystemCommandsScreenProperties.VCB_CONFIRM_BUTTON_STATE
        .equals(key))
    {
      highVoltageRightTCarScreenModel.setConfirmState((Integer)newValue);
    }
  }

}
