/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import org.springframework.stereotype.Service;

import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsLVCommandHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputLowVoltageSystemCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsLowVoltageSystemCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for Low Voltage Command screen handling.
 * 
 */

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class LowVoltageCommandScreenHandler extends AbstractFunctionalLogic
{
  private final SharedDataModel shareDataModel;

  private ITCMSVehicleInputsLVCommandHandler vehicleInputsHandler;

  protected LowVoltageCommandScreenHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
  {
    super(commsBinding, IAppInputsProperties.class, ITCMSVehicleOutputsProperties.class);
    shareDataModel = aShareDataModel;

    initalizeVehicleInputHandler();
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (ITCMSVehicleOutputsProperties.POWER_OFF_PRESSED.equals(key) && Boolean.TRUE.equals(newValue))
    {
      resetInputCommands();
    }
  }

  private void resetInputCommands()
  {
    for (int carIndex = 0; carIndex < shareDataModel.getTotalCar(); carIndex++)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsLVCommandHandler)getTCMSVehicleInputsSetter(carIndex);

      vehicleInputsHandler.setLvIsolateBcg1(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setLvIsolateBcg2(ApplicationConstants.RESET_VALUE);

      setApplicationOutputsProperty(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M1_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M2_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M3_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M1_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M2_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M3_STATUS,
          ApplicationConstants.RESET_VALUE);

    }

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (getActiveVehicleIndex() == vehicleIndex)
    {

      if (key.equals(IAppInputLowVoltageSystemCommandScreenProperties.LV_COMMAND_BCG1_M1)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M1_STATUS, (Integer)newValue);
        updateBcg1(newValue, TCMSConstants.CAB_2);

      }
      else if (key.equals(IAppInputLowVoltageSystemCommandScreenProperties.LV_COMMAND_BCG1_M2)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M2_STATUS, (Integer)newValue);
        updateBcg1(newValue, TCMSConstants.CAB_4);
      }
      else if (key.equals(IAppInputLowVoltageSystemCommandScreenProperties.LV_COMMAND_BCG1_M3)
          && (Integer)newValue > -1)
      {

        setApplicationOutputsProperty(
            IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG1_M3_STATUS, (Integer)newValue);
        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          updateBcg1(newValue, TCMSConstants.CAB_3);
        }
        else
        {
          updateBcg1(newValue, TCMSConstants.CAB_5);
        }

      }
      else if (key.equals(IAppInputLowVoltageSystemCommandScreenProperties.LV_COMMAND_BCG2_M1)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M1_STATUS, (Integer)newValue);

        updateBcg2(newValue, TCMSConstants.CAB_2);
      }
      else if (key.equals(IAppInputLowVoltageSystemCommandScreenProperties.LV_COMMAND_BCG2_M2)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M2_STATUS, (Integer)newValue);
        updateBcg2(newValue, TCMSConstants.CAB_4);
      }
      else if (key.equals(IAppInputLowVoltageSystemCommandScreenProperties.LV_COMMAND_BCG2_M3)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsLowVoltageSystemCommandScreenProperties.ISOLATE_BCG2_M3_STATUS, (Integer)newValue);
        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          updateBcg2(newValue, TCMSConstants.CAB_3);
        }
        else
        {
          updateBcg2(newValue, TCMSConstants.CAB_5);
        }
      }
      else if (key.equals(IAppInputLowVoltageSystemCommandScreenProperties.LV_COMMAND_POPB)
          && (Integer)newValue > -1)
      {
        updatePopb(newValue);
      }

    }

  }

  private <T> void updatePopb(T newValue)
  {
    setApplicationOutputsProperty(IAppOutputsLowVoltageSystemCommandScreenProperties.LV_POPB_STATUS,
        (Integer)newValue);

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler.setLvCommandPopb((Integer)newValue);
    }
  }

  private <T> void updateBcg2(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsLVCommandHandler)getTCMSVehicleInputsSetter(vehicleIndex);
      vehicleInputsHandler.setLvIsolateBcg2((Integer)newValue);
    }
  }

  private <T> void updateBcg1(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsLVCommandHandler)getTCMSVehicleInputsSetter(vehicleIndex);

      vehicleInputsHandler.setLvIsolateBcg1((Integer)newValue);
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsLVCommandHandler)getTCMSVehicleInputsSetter(
          getActiveVehicleIndex());
    }
  }

  @Override
  public void attachListeners()
  {
    super.attachListeners();

    initalizeVehicleInputHandler();
  }

}
