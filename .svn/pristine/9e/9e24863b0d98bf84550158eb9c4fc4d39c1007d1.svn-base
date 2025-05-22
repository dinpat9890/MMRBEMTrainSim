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
import com.sydac.mmrbem.tcms.backend.vehicle.io.handlers.ITCMSVehicleInputsMVCommandHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputMediumVoltageSystemCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppInputsProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsMediumVoltageSystemCommandScreenProperties;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for Low Voltage Command screen handling.
 * 
 */

@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class MediumVoltageCommandScreenHandler extends AbstractFunctionalLogic
{
  private final SharedDataModel shareDataModel;

  private ITCMSVehicleInputsMVCommandHandler vehicleInputsHandler;

  protected MediumVoltageCommandScreenHandler(CommsBinding commsBinding, SharedDataModel aShareDataModel)
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
      vehicleInputsHandler = (ITCMSVehicleInputsMVCommandHandler)getTCMSVehicleInputsSetter(carIndex);

      vehicleInputsHandler.setMvCompHoursReset(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setMvMainCompForcing(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setMvMtrBlowersForcingHigh(ApplicationConstants.RESET_VALUE);
      vehicleInputsHandler.setMvMtrBlowersForcingLow(ApplicationConstants.RESET_VALUE);

      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_FRONT_CAR_FORCE_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_REAR_CAR_FORCE_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_FRONT_CAR_RESET_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_REAR_CAR_RESET_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T1_CAR_LOW_FORCE_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T2_CAR_LOW_FORCE_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T3_CAR_LOW_FORCE_STATUS,
          ApplicationConstants.RESET_VALUE);

      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T1_CAR_HIGH_FORCE_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T2_CAR_HIGH_FORCE_STATUS,
          ApplicationConstants.RESET_VALUE);
      setApplicationOutputsProperty(
          IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T3_CAR_HIGH_FORCE_STATUS,
          ApplicationConstants.RESET_VALUE);

    }

  }

  @Override
  public <T> void appInputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue, int vehicleIndex)
  {

    if (getActiveVehicleIndex() == vehicleIndex)
    {

      if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_DM_FRONT_FORCE_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_FRONT_CAR_FORCE_STATUS,
            (Integer)newValue);
        updateMvMainCompForcing(newValue, TCMSConstants.DM1_CAR);

      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_DM_REAR_FORCE_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_REAR_CAR_FORCE_STATUS,
            (Integer)newValue);
        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          updateMvMainCompForcing(newValue, TCMSConstants.DM6_CAR);
        }
        else
        {
          updateMvMainCompForcing(newValue, TCMSConstants.DM8_CAR);
        }
      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_DM_FRONT_RESET_CAR_REQ)
          && (Integer)newValue > -1)
      {

        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_FRONT_CAR_RESET_STATUS,
            (Integer)newValue);
        updateMvCompHoursReset(newValue, TCMSConstants.DM1_CAR);

      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_DM_REAR_RESET_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_DM_REAR_CAR_RESET_STATUS,
            (Integer)newValue);

        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          updateMvCompHoursReset(newValue, TCMSConstants.DM6_CAR);
        }
        else
        {
          updateMvCompHoursReset(newValue, TCMSConstants.DM8_CAR);
        }
      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_T1_FORCE_LOW_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T1_CAR_LOW_FORCE_STATUS,
            (Integer)newValue);
        updateMvMtrBlowersForcingLow(newValue, TCMSConstants.T2_CAR);
      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_T2_FORCE_LOW_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T2_CAR_LOW_FORCE_STATUS,
            (Integer)newValue);
        updateMvMtrBlowersForcingLow(newValue, TCMSConstants.T4_CAR);
      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_T3_FORCE_LOW_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T3_CAR_LOW_FORCE_STATUS,
            (Integer)newValue);
        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          updateMvMtrBlowersForcingLow(newValue, TCMSConstants.T5_CAR);
        }
        else
        {
          updateMvMtrBlowersForcingLow(newValue, TCMSConstants.T7_CAR);
        }

      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_T1_FORCE_HIGH_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T1_CAR_HIGH_FORCE_STATUS,
            (Integer)newValue);
        updateMvMtrBlowersForcingHigh(newValue, TCMSConstants.CAB_2);
      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_T2_FORCE_HIGH_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T2_CAR_HIGH_FORCE_STATUS,
            (Integer)newValue);
        updateMvMtrBlowersForcingHigh(newValue, TCMSConstants.T4_CAR);
      }
      else if (key.equals(IAppInputMediumVoltageSystemCommandScreenProperties.MV_T3_FORCE_HIGH_CAR_REQ)
          && (Integer)newValue > -1)
      {
        setApplicationOutputsProperty(
            IAppOutputsMediumVoltageSystemCommandScreenProperties.MV_T3_CAR_HIGH_FORCE_STATUS,
            (Integer)newValue);
        if (shareDataModel.getTotalCar() == TCMSConstants.CAB_6)
        {
          updateMvMtrBlowersForcingHigh(newValue, TCMSConstants.T5_CAR);
        }
        else
        {
          updateMvMtrBlowersForcingHigh(newValue, TCMSConstants.T7_CAR);
        }

      }

    }

  }

  private <T> void updateMvCompHoursReset(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMVCommandHandler)getTCMSVehicleInputsSetter(vehicleIndex);
      vehicleInputsHandler.setMvCompHoursReset((Integer)newValue);
    }
  }

  private <T> void updateMvMainCompForcing(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMVCommandHandler)getTCMSVehicleInputsSetter(vehicleIndex);

      vehicleInputsHandler.setMvMainCompForcing((Integer)newValue);
    }
  }

  private <T> void updateMvMtrBlowersForcingHigh(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMVCommandHandler)getTCMSVehicleInputsSetter(vehicleIndex);

      vehicleInputsHandler.setMvMtrBlowersForcingHigh((Integer)newValue);
    }
  }

  private <T> void updateMvMtrBlowersForcingLow(T newValue, int vehicleIndex)
  {

    if (vehicleInputsHandler != null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMVCommandHandler)getTCMSVehicleInputsSetter(vehicleIndex);

      vehicleInputsHandler.setMvMtrBlowersForcingLow((Integer)newValue);
    }
  }

  private void initalizeVehicleInputHandler()
  {
    if (vehicleInputsHandler == null)
    {
      vehicleInputsHandler = (ITCMSVehicleInputsMVCommandHandler)getTCMSVehicleInputsSetter(
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
