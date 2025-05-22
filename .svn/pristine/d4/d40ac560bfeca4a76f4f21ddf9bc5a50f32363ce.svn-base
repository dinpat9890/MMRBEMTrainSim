/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsHVACCommandHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsHVACCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVSelectedCarIndexList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVSelectedCarIndexList.SelectedCarIndex;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling HVAC System Status screen data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class HVACCommandScreenHandler extends AbstractFunctionalLogic
{
  private static final Tracer LOGGER = Tracer.getInstance();

  private CommsBinding commsBinding;

  private SharedDataModel sharedModel;

  private ITCMSVehicleInputsHVACCommandHandler vehicleInputsHandler;

  private int hvac1CarIndex = 0;

  private int hvac2CarIndex = 0;

  private int resetSmokeCarIndex = 0;

  protected HVACCommandScreenHandler(CommsBinding commsBinding, SharedDataModel sharedModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsProperties.class);
    this.commsBinding = commsBinding;
    this.sharedModel = sharedModel;
    initalizeVehicleInputHandler();

  }

  private void resetInputCommands()
  {
    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsHvac1ResetReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsHvac2ResetReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsHvac1IsolateReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsHvac2IsolateReq(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setTcmsHvacSmokeResetReq(ApplicationConstants.RESET_VALUE);
    }
  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {
    if (getActiveVehicleIndex() == vehicleIndex)
    {
      if (key.equals(IAppInputsHVACCommandScreenProperties.RESET_HVAC1_CAR_REQ) && (Integer)newValue > -1)
      {
        hvac1CarIndex = (Integer)newValue;
      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.RESET_HVAC1_REQ) && (Integer)newValue > -1)
      {

        resetHvac1Req((Integer)newValue);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.RESET_HVAC2_CAR_REQ)
          && (Integer)newValue > -1)
      {
        hvac2CarIndex = (Integer)newValue;

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.RESET_HVAC2_REQ) && (Integer)newValue > -1)
      {

        resetHvac2Req((Integer)newValue);
      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC1_CAR0_REQ))
      {
        isolateHVac1((Integer)newValue, 0);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC1_CAR1_REQ))
      {
        isolateHVac1((Integer)newValue, 1);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC1_CAR2_REQ))
      {
        isolateHVac1((Integer)newValue, 2);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC1_CAR3_REQ))
      {
        isolateHVac1((Integer)newValue, 3);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC1_CAR4_REQ))
      {
        isolateHVac1((Integer)newValue, 4);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC1_CAR5_REQ))
      {
        if (sharedModel.getTotalCar() == TCMSConstants.CAB_8)
        {
          isolateHVac1((Integer)newValue, 5);
        }
        else
        {
          isolateHVac1((Integer)newValue, 3);
        }

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC1_CAR6_REQ))
      {
        if (sharedModel.getTotalCar() == TCMSConstants.CAB_8)
        {
          isolateHVac1((Integer)newValue, 6);
        }
        else
        {
          isolateHVac1((Integer)newValue, 4);
        }

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC1_CAR7_REQ))
      {
        if (sharedModel.getTotalCar() == TCMSConstants.CAB_8)
        {
          isolateHVac1((Integer)newValue, TCMSConstants.DM8_CAR);
        }
        else
        {
          isolateHVac1((Integer)newValue, TCMSConstants.DM6_CAR);
        }

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.RESET_SMOKE_REQ) && (Integer)newValue > -1)
      {
        resetSmokeReq((Integer)newValue);
      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.RESET_SMOKE_CAR_REQ)
          && (Integer)newValue > -1)
      {
        resetSmokeCarIndex = (Integer)newValue;
      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC2_CAR0_REQ))
      {
        isolateHVac2((Integer)newValue, 0);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC2_CAR1_REQ))
      {
        isolateHVac2((Integer)newValue, 1);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC2_CAR2_REQ))
      {
        isolateHVac2((Integer)newValue, 2);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC2_CAR3_REQ))
      {
        isolateHVac2((Integer)newValue, 3);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC2_CAR4_REQ))
      {
        isolateHVac2((Integer)newValue, 4);

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC2_CAR5_REQ))
      {
        if (sharedModel.getTotalCar() == TCMSConstants.CAB_8)
        {
          isolateHVac2((Integer)newValue, 5);
        }
        else
        {
          isolateHVac2((Integer)newValue, 3);
        }

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC2_CAR6_REQ))
      {
        if (sharedModel.getTotalCar() == TCMSConstants.CAB_8)
        {
          isolateHVac2((Integer)newValue, 6);
        }
        else
        {
          isolateHVac2((Integer)newValue, 4);
        }

      }
      else if (key.equals(IAppInputsHVACCommandScreenProperties.ISOLATE_HVAC2_CAR7_REQ))
      {
        if (sharedModel.getTotalCar() == TCMSConstants.CAB_8)
        {
          isolateHVac2((Integer)newValue, 7);
        }
        else
        {
          isolateHVac2((Integer)newValue, 5);

        }
      }

    }

  }

  private void resetHvac1Req(int hvac)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(hvac1CarIndex);
      vehicleInputsHandler.setTcmsHvac1ResetReq(hvac);
    }
  }

  private void resetHvac2Req(int hvac)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(hvac2CarIndex);
      vehicleInputsHandler.setTcmsHvac2ResetReq(hvac);
    }
  }

  private void isolateHVac1(int val, int carIndex)
  {

    if (vehicleInputsHandler != null)
    {

      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsHvac1IsolateReq(val);

    }
  }

  private void isolateHVac2(int val, int carIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(carIndex);
      vehicleInputsHandler.setTcmsHvac2IsolateReq(val);
    }
  }

  /**
   * Attach listeners.
   */
  @Override
  public void attachListeners()
  {
    super.attachListeners();
    initalizeVehicleInputHandler();
  }

  /**
   * Detach listeners.
   */
  @Override
  public void detachListeners()
  {
    super.detachListeners();

  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (key.equals(ITCMSVehicleOutputsProperties.HMI_POWER) && Boolean.TRUE.equals(newValue))
    {
      // do something when power is ON
    }
    else if (ITCMSVehicleOutputsProperties.POWER_OFF_PRESSED.equals(key) && Boolean.TRUE.equals(newValue))
    {
      resetInputCommands();
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
    }
  }

  private void resetSmokeReq(int resetSmoke)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsHVACCommandHandler)getTCMSVehicleInputsSetter(
          resetSmokeCarIndex);
      vehicleInputsHandler.setTcmsHvacSmokeResetReq(resetSmoke);
    }
  }

}
