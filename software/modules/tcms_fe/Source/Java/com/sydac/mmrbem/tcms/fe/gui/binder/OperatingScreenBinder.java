/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.binder;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.fe.base.AbstractCommsListener;
import com.sydac.mmrbem.tcms.fe.gui.model.OperatingScreenModel;

public class OperatingScreenBinder extends AbstractCommsListener
{

  OperatingScreenModel operatingScreenModel;

  public OperatingScreenBinder(OperatingScreenModel operatingScreenModel)
  {
    super();
    this.operatingScreenModel = operatingScreenModel;
    propertyKeyDefinitions.add(IAppOutputsOperatingScreenProperties.class);
  }

  @Override
  protected <T> void appOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue)
  {
    if (key.equals(IAppOutputsOperatingScreenProperties.TRAIN_NUMBER))
    {
      operatingScreenModel.setTrainNumber((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.LINE_VOLTAGE))
    {
      operatingScreenModel.setLineVoltage((Double)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.BATTERY_VOLTAGE))
    {
      operatingScreenModel.setBatteryVoltage((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.ODOMETER))
    {
      operatingScreenModel.setOdometerValue((Double)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.TOTAL_WEIGHT))
    {
      operatingScreenModel.setTotalTrainWeight((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.START_STATION))
    {
      operatingScreenModel.setStartStation((byte[])newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.CURRENT_STATION))
    {
      operatingScreenModel.setCurrentStation((byte[])newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.DESTINATION_STATION))
    {
      operatingScreenModel.setDestinationStation((byte[])newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.NEXT_STATION))
    {
      operatingScreenModel.setNextStation((byte[])newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.DOOR_OPEN_SIDE))
    {
      operatingScreenModel.setDoorOpeningNextStation((byte[])newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.RESCUE_MODE))
    {
      operatingScreenModel.setRescueMode((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.JOG_MODE))
    {
      operatingScreenModel.setJogMode((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.ENABLE_TO_RUN))
    {
      operatingScreenModel.setEnableToRun((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.ATC_BYPASS))
    {
      operatingScreenModel.setAtcBypass((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.SHORE_SUPPLY))
    {
      operatingScreenModel.setShoreSupply((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.COUPLED))
    {
      operatingScreenModel.setCoupled((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.NOTCH_VALUE))
    {
      operatingScreenModel.setNotchValue((Integer)newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.TCMS_MODE))
    {
      operatingScreenModel.setTcmsMode((byte[])newValue);
    }
    else if (key.equals(IAppOutputsOperatingScreenProperties.TCMS_TBC_FEEDBACK))
    {
      operatingScreenModel.setTcmsTbcFeedBackValue((Integer)newValue);
    }
  }
}
