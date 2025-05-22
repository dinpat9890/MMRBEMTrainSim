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
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsAPSSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsBatterySystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHVACSystemStatusScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsMediumVoltageSystemScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.MediumVoltageSystemScreenModel;

public class MediumVoltageSystemScreenBinder extends AbstractCommsListener
{

  private MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel;

  public MediumVoltageSystemScreenBinder(MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel)
  {
    super();
    this.mediumVoltageSystemScreenModel = mediumVoltageSystemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsBatterySystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsHVACSystemStatusScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsAPSSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsMediumVoltageSystemScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsAPSSystemScreenProperties.APS_CONTROL_UNIT_STATUS.equals(key))
    {
      mediumVoltageSystemScreenModel.setAPSState((byte[])newValue);
    }
    else if (IAppOutputsBatterySystemScreenProperties.BCG_STATUS.equals(key))
    {
      mediumVoltageSystemScreenModel.setBCGState((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.HVAC_OPERATING_MODE_STATUS_1.equals(key))
    {
      mediumVoltageSystemScreenModel.setHVAC1State((byte[])newValue);
    }
    else if (IAppOutputsHVACSystemStatusScreenProperties.HVAC_OPERATING_MODE_STATUS_2.equals(key))
    {
      mediumVoltageSystemScreenModel.setHVAC2State((byte[])newValue);
    }
    else if (IAppOutputsMediumVoltageSystemScreenProperties.MV_PEC_SWITCH_STATUS_LIST.equals(key))
    {
      mediumVoltageSystemScreenModel.setPECState((byte[])newValue);
    }
    else if (IAppOutputsMediumVoltageSystemScreenProperties.MV_AUX_COMP_STATUS_LIST.equals(key))
    {
      mediumVoltageSystemScreenModel.setAuxCompState((byte[])newValue);
    }
    else if (IAppOutputsMediumVoltageSystemScreenProperties.MV_MAIN_COMP_STATUS_LIST.equals(key))
    {
      mediumVoltageSystemScreenModel.setMainCompState((byte[])newValue);
    }
  }
}
