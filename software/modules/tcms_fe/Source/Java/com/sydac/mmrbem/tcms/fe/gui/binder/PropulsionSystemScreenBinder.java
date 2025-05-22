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
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsPropulsionSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainTopViewComponentProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.PropulsionSystemScreenModel;

public class PropulsionSystemScreenBinder extends AbstractCommsListener
{

  private PropulsionSystemScreenModel propulsionSystemScreenModel;

  public PropulsionSystemScreenBinder(PropulsionSystemScreenModel propulsionSystemScreenModel)
  {
    super();
    this.propulsionSystemScreenModel = propulsionSystemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsPropulsionSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainTopViewComponentProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainTopViewComponentProperties.PROPULSION_STATUS.equals(key))
    {
      propulsionSystemScreenModel.setPropulsionState((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.PROPULSION_ENABLED_STATUS.equals(key))
    {
      propulsionSystemScreenModel.setPropulsionEnabledStatus((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.AK_CONTACTOR_STATUS.equals(key))
    {
      propulsionSystemScreenModel.setAkContactorStatusList((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.K_CONTACTOR_STATUS.equals(key))
    {
      propulsionSystemScreenModel.setKContactorStatusList((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.DYNAMIC_BRAKE_STATUS.equals(key))
    {
      propulsionSystemScreenModel.setDynamicBrakeStatusList((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.VCB_TRIP_COMMAND_STATUS.equals(key))
    {
      propulsionSystemScreenModel.setVcbTripCommandStatusList((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.FILTER_VOLTAGE_STATUS.equals(key))
    {
      propulsionSystemScreenModel.setFilterVoltageStatusList((byte[])newValue);
    }
    else if (IAppOutputsPropulsionSystemScreenProperties.TRACTIVE_EFFORT_STATUS.equals(key))
    {
      propulsionSystemScreenModel.setTractiveEffortStatusList((byte[])newValue);
    }
    else if (IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS.equals(key))
    {
      propulsionSystemScreenModel.setTotalColumn((Integer)newValue);
    }
  }

}
