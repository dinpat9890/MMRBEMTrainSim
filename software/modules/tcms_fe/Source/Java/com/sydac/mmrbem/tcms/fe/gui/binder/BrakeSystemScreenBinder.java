/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsBrakeSystemScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainConfigurationProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.BrakeSystemScreenModel;

public class BrakeSystemScreenBinder extends AbstractCommsListener
{
  private BrakeSystemScreenModel brakeSystemScreenModel;

  public BrakeSystemScreenBinder(BrakeSystemScreenModel brakeSystemScreenModel)
  {
    super();
    this.brakeSystemScreenModel = brakeSystemScreenModel;
    propertyKeyDefinitions.add(IAppOutputsBrakeSystemScreenProperties.class);
    propertyKeyDefinitions.add(IAppOutputsTrainConfigurationProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (IAppOutputsTrainConfigurationProperties.NUMBER_OF_CARS.equals(key))
    {
      brakeSystemScreenModel.setTotalColumn((Integer)newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.SERVICE_BRK_STATUS.equals(key))
    {
      brakeSystemScreenModel.setServiceBrakeStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.PARKING_BRK_STATUS.equals(key))
    {
      brakeSystemScreenModel.setParkingBrakeStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.WSP_STATUS.equals(key))
    {
      brakeSystemScreenModel.setWspStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.SUSP_STATUS.equals(key))
    {
      brakeSystemScreenModel.setSuspStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.BRAKE_CONTROL_UNIT_STATUS.equals(key))
    {
      brakeSystemScreenModel.setBecuStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.TRAIN_LINE_STATUS.equals(key))
    {
      brakeSystemScreenModel.setTrainLineStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.FULL_SERVICE_BRAKE_LINE_STATUS.equals(key))
    {
      brakeSystemScreenModel.setFsbStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.EMERGENCY_BRAKE_LINE_STATUS.equals(key))
    {
      brakeSystemScreenModel.setEbStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.HOLDING_BRAKE_EPIC_ISOLATION_STATUS.equals(key))
    {
      brakeSystemScreenModel.setHoldEpicStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.ED_CUT_OUT_RPRESS_ISOLATION_STATUS.equals(key))
    {
      brakeSystemScreenModel.setEdCutRpresStatus((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.MAIN_PIPE_PRESSURE_STATUS.equals(key))
    {
      brakeSystemScreenModel.setMainPipePressureValue((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.BRAKE_CYLINDER_PRESSURE_STATUS.equals(key))
    {
      brakeSystemScreenModel.setBrakeCylinderPressureValue((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.AIR_SUSPENSION_PRESSURE_STATUS.equals(key))
    {
      brakeSystemScreenModel.setAirSuspensionPressureValue((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.EP_BRAKE_DELIVERED_STATUS.equals(key))
    {
      brakeSystemScreenModel.setEDBrakeDeliveredValue((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.ED_BRAKE_REQUESTED_STATUS.equals(key))
    {
      brakeSystemScreenModel.setEDBrakeRequestedValue((byte[])newValue);
    }
    else if (IAppOutputsBrakeSystemScreenProperties.CAR_WEIGHT_STATUS.equals(key))
    {
      brakeSystemScreenModel.setCarWeightValue((byte[])newValue);
    }
  }
}
