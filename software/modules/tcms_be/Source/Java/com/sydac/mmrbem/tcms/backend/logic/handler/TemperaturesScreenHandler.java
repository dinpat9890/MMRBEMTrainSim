/*
 * ==================================================================
 * (C)Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.List;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IModelListener;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTemperaturesScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MainTransformerTemperaturesList.MainTransformerTemperatures;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MotorTemperaturesList.MotorTemperature;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;

/**
 * This handler class is used for handling Propulsion System Tempertures screen
 * data
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class, SharedDataModel.class })
public class TemperaturesScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  private List<VehicleDetailModel> vehicleDetailModelList;

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> {
    vehicleDetailModelList = sharedModel.getVehicleDetailModelList();
    // Write the initial state of propulsion status
    if (!vehicleDetailModelList.isEmpty())
    {
      updateMotor1TemperatureList();
      updateMotor2TemperatureList();
      updateMotor3TemperatureList();
      updateMotor4TemperatureList();
      updateMainTransformerTemperatureList();
    }
  };

  public TemperaturesScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding);
    sharedModel = aSharedModel;
  }

  /**
   * Attach listeners.
   */
  @Override
  public void attachListeners()
  {
    super.attachListeners();
    sharedModel.addModelListener(trainConfigListener, Change.TRAIN_CONFIGURED, true);
  }

  /**
   * Detach listeners.
   */
  @Override
  public void detachListeners()
  {
    super.detachListeners();
    sharedModel.removeModelListener(trainConfigListener, Change.TRAIN_CONFIGURED);
  }

  private void updateMotor1TemperatureList()
  {

    TCMSProto.MotorTemperaturesList.Builder builder = TCMSProto.MotorTemperaturesList.newBuilder();
    MotorTemperature.Builder vehicleBuilder = MotorTemperature.newBuilder();
    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setBogie1MotorTemperature(TCMSConstants.TEMP_VALUE_2);
        vehicleBuilder.setBogie2MotorTemperature(TCMSConstants.TEMP_VALUE_3);
      }
      else
      {
        vehicleBuilder.setBogie1MotorTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
        vehicleBuilder.setBogie2MotorTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
      }
      builder.addMotorTemperature(vehicleBuilder.build());
    }
    setApplicationOutputsProperty(IAppOutputsTemperaturesScreenProperties.MOTOR_1_TEMPERATURE_LIST,
        builder.build().toByteArray());
  }

  private void updateMotor2TemperatureList()
  {

    TCMSProto.MotorTemperaturesList.Builder builder = TCMSProto.MotorTemperaturesList.newBuilder();
    MotorTemperature.Builder vehicleBuilder = MotorTemperature.newBuilder();
    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setBogie1MotorTemperature(TCMSConstants.TEMP_VALUE_1);
        vehicleBuilder.setBogie2MotorTemperature(TCMSConstants.TEMP_VALUE_2);
      }
      else
      {
        vehicleBuilder.setBogie1MotorTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
        vehicleBuilder.setBogie2MotorTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
      }
      builder.addMotorTemperature(vehicleBuilder.build());
    }
    setApplicationOutputsProperty(IAppOutputsTemperaturesScreenProperties.MOTOR_2_TEMPERATURE_LIST,
        builder.build().toByteArray());
  }

  private void updateMotor3TemperatureList()
  {

    TCMSProto.MotorTemperaturesList.Builder builder = TCMSProto.MotorTemperaturesList.newBuilder();
    MotorTemperature.Builder vehicleBuilder = MotorTemperature.newBuilder();
    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setBogie1MotorTemperature(TCMSConstants.TEMP_VALUE_4);
        vehicleBuilder.setBogie2MotorTemperature(TCMSConstants.TEMP_VALUE_3);
      }
      else
      {
        vehicleBuilder.setBogie1MotorTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
        vehicleBuilder.setBogie2MotorTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
      }
      builder.addMotorTemperature(vehicleBuilder.build());
    }
    setApplicationOutputsProperty(IAppOutputsTemperaturesScreenProperties.MOTOR_3_TEMPERATURE_LIST,
        builder.build().toByteArray());
  }

  private void updateMotor4TemperatureList()
  {

    TCMSProto.MotorTemperaturesList.Builder builder = TCMSProto.MotorTemperaturesList.newBuilder();
    MotorTemperature.Builder vehicleBuilder = MotorTemperature.newBuilder();
    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.DM_CAR.equals(carClassCode) || TCMSConstants.M_CAR.equals(carClassCode))
      {
        vehicleBuilder.setBogie1MotorTemperature(TCMSConstants.TEMP_VALUE_2);
        vehicleBuilder.setBogie2MotorTemperature(TCMSConstants.TEMP_VALUE_4);
      }
      else
      {
        vehicleBuilder.setBogie1MotorTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
        vehicleBuilder.setBogie2MotorTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
      }
      builder.addMotorTemperature(vehicleBuilder.build());
    }
    setApplicationOutputsProperty(IAppOutputsTemperaturesScreenProperties.MOTOR_4_TEMPERATURE_LIST,
        builder.build().toByteArray());
  }

  private void updateMainTransformerTemperatureList()
  {

    TCMSProto.MainTransformerTemperaturesList.Builder builder = TCMSProto.MainTransformerTemperaturesList
        .newBuilder();
    MainTransformerTemperatures.Builder vehicleBuilder = MainTransformerTemperatures.newBuilder();
    for (int carIndex = 0; carIndex < sharedModel.getTotalCar(); carIndex++)
    {
      vehicleBuilder.setCarIndex(carIndex);
      String carClassCode = vehicleDetailModelList != null
          ? vehicleDetailModelList.get(carIndex).getCarClassCode()
          : ApplicationConstants.BLANK;
      if (TCMSConstants.T_CAR.equals(carClassCode))
      {
        vehicleBuilder.setMainTransformerTemperature(TCMSConstants.TEMP_VALUE_5);
      }
      else
      {
        vehicleBuilder.setMainTransformerTemperature(TCMSConstants.VALUE_NOT_APPLICABLE);
      }
      builder.addMainTransformerTemperatures(vehicleBuilder.build());
    }
    setApplicationOutputsProperty(IAppOutputsTemperaturesScreenProperties.MAIN_TRANSFORMER_TEMPERATURE_LIST,
        builder.build().toByteArray());
  }

}
