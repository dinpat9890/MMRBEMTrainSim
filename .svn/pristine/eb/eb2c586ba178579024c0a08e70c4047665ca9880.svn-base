/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.EnumMap;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsOperatingScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsHeaderPanelProperties;
import com.sydac.mmrbem.tcms.common.state.DrivingModeEnum;
import com.sydac.mmrbem.tcms.common.utils.SpeedUnitConverter;

/**
 * This handler class is used for Header Panel change handling.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class HeaderPanelChangeHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private EnumMap<DrivingModeEnum, Integer> drivingModeMap = new EnumMap<>(DrivingModeEnum.class);

  private boolean checkForDrivingModeActive;

  private int drivingModeValue;

  private static final int PASSENGERS_PER_CAB_25_PERC = 88;

  private SpeedUnitConverter speedUnitConverter = new SpeedUnitConverter();

  public HeaderPanelChangeHandler(CommsBinding commsBinding, SharedDataModel sharedDataModel)
  {
    super(commsBinding, ITCMSVehicleOutputsOperatingScreenProperties.class);
    this.sharedModel = sharedDataModel;
    updatePassengerCount();
  }

  private void updatePassengerCount()
  {
    setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.PASSENGERS_COUNT,
        (PASSENGERS_PER_CAB_25_PERC * sharedModel.getTotalCar()));
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (sharedModel.getCurrentActiveCabId() == vehicleIndex)
    {
      if (ITCMSVehicleOutputsOperatingScreenProperties.UTO_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.UTO.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.RMR_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.RMR.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.RMF_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.RMF.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.ATP_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.ATP.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.ATO_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.ATO.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.ROS_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.ROS.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.ATB_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.ATB.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.ATC_BYPASS_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.ATC_BYPASS.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.STANDBY_MODE.equals(key))
      {
        updateDrivingMode(DrivingModeEnum.STANDBY.getValue(), (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.TRAIN_SPEED.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.TRAIN_CURRENT_SPEED,
            getSpeedInKMPHDouble((Double)newValue));
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.TCMS_SPEED_LIMIT.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.TRAIN_SPEED_LIMIT,
            getSpeedInKMPHDouble((Double)newValue));
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.OPERATIONAL_MODE.equals(key))
      {
        setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.OPERATING_MODE, (Integer)newValue);
      }
      else if (ITCMSVehicleOutputsOperatingScreenProperties.TOTAL_WEIGHT.equals(key))
      {
        updatePassengerCount();
      }
    }
  }

  public Double getSpeedInKMPHDouble(double newValue)
  {
    Double result = speedUnitConverter.convertTo(newValue);
    return result.doubleValue();
  }

  private void updateDrivingMode(int mode, Integer value)
  {
    checkForDrivingModeActive = Boolean.FALSE;
    drivingModeMap.put(DrivingModeEnum.valueOf(mode), value);
    drivingModeMap.forEach((drivingMode, active) -> {
      if (active == 1)
      {
        checkForDrivingModeActive = Boolean.TRUE;
        drivingModeValue = drivingMode.getValue();
      }
    });

    if (checkForDrivingModeActive)
    {
      setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.DRIVING_MODE, drivingModeValue);
    }
    else
    {
      setApplicationOutputsProperty(IAppOutputsHeaderPanelProperties.DRIVING_MODE, value);
    }
  }
}
