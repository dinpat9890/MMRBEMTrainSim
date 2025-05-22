/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsMediumVoltageSystemCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.MediumVoltageSystemCommandScreenModel;

public class MediumVoltageSystemCommandScreenBinder extends AbstractCommsListener
{
  private MediumVoltageSystemCommandScreenModel mediumVoltageSystemCommandScreenModel;

  public MediumVoltageSystemCommandScreenBinder(
      MediumVoltageSystemCommandScreenModel lowVoltageSystemCommandScreenModel)
  {
    super();
    this.mediumVoltageSystemCommandScreenModel = lowVoltageSystemCommandScreenModel;

    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
    propertyKeyDefinitions.add(IAppOutputsMediumVoltageSystemCommandScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS))
    {
      mediumVoltageSystemCommandScreenModel.setTotalColumn((Integer)newValue);
    }
    else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_FRONT_CAR_FORCE_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setDMFrontCarForceStatus((Integer)newValue);
    }
    else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_REAR_CAR_FORCE_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setDMRearCarForceStatus((Integer)newValue);
    }else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_FRONT_CAR_RESET_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setDMFrontCarResetStatus((Integer)newValue);
    }else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_REAR_CAR_RESET_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setDMRearCarResetStatus((Integer)newValue);
    }
    else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T1_CAR_LOW_FORCE_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setT1CarLowForceStatus((Integer)newValue);
    }else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T2_CAR_LOW_FORCE_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setT2CarLowForceStatus((Integer)newValue);
    }else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T3_CAR_LOW_FORCE_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setT3CarLowForceStatus((Integer)newValue);
    }else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T1_CAR_HIGH_FORCE_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setT1CarHighForceStatus((Integer)newValue);
    }else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T2_CAR_HIGH_FORCE_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setT2CarHighForceStatus((Integer)newValue);
    }else if (key.equals(IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T3_CAR_HIGH_FORCE_STATUS))
    {
      mediumVoltageSystemCommandScreenModel.setT3CarHIghForceStatus((Integer)newValue);
    }


  }
}
