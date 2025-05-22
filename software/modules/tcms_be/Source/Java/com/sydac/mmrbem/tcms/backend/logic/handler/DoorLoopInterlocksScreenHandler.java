/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Service;

import com.sydac.foundation.IModelListener;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel;
import com.sydac.mmrbem.tcms.backend.logic.SharedDataModel.Change;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.models.ITCMSVehicleOutputsDoorModel;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.IPAPISVehicleOutputsProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsDoorStatusProperties;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsDoorLoopInterlocksScreenProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DoorLoopInterlockData;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DoorLoopInterlockData.DoorLoopInterlockState;

/**
 * This handler class handle the Doorloop intrlocks status of vehicle and set to
 * COMMS.
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class DoorLoopInterlocksScreenHandler extends AbstractFunctionalLogic
{
  private SharedDataModel sharedModel;

  ITCMSVehicleOutputsDoorModel doorModel;

  private Map<Integer, DoorLoopInterlockState> leftDoorOpenStatusMap = new HashMap<>();

  private Map<Integer, DoorLoopInterlockState> rightDoorOpenStatusMap = new HashMap<>();

  private Map<Integer, DoorLoopInterlockState> emgDoorOpenStatusMap = new HashMap<>();

  /**
   * Listener to update vehicleDetailModelList
   */
  IModelListener trainConfigListener = (arg0, arg1) -> sharedModel.getVehicleDetailModelList();

  public DoorLoopInterlocksScreenHandler(CommsBinding commsBinding, SharedDataModel aSharedModel)
  {
    super(commsBinding, ITCMSVehicleOutputsDoorStatusProperties.class, IPAPISVehicleOutputsProperties.class);
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

  @Override
  public <T> void papisVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    if (IPAPISVehicleOutputsProperties.PECU_ALARM_ACTIVE.equals(key))
    {
      if (vehicleIndex == 0)
      {
        setApplicationOutputsProperty(IAppOutputsDoorLoopInterlocksScreenProperties.PABR_DE_ENERGIZED_IN_DM1,
            (Integer)newValue);
      }
      else if (vehicleIndex == 5)
      {
        setApplicationOutputsProperty(IAppOutputsDoorLoopInterlocksScreenProperties.PABR_DE_ENERGIZED_IN_DM6,
            (Integer)newValue);
      }
      else if (vehicleIndex == 7)
      {
        setApplicationOutputsProperty(IAppOutputsDoorLoopInterlocksScreenProperties.PABR_DE_ENERGIZED_IN_DM8,
            (Integer)newValue);
      }
    }
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    doorModel = (ITCMSVehicleOutputsDoorModel)getTCMSVehicleOutputsModels().get(vehicleIndex);
    if (key.equals(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A1_LOCKED)
        || key.equals(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A2_LOCKED)
        || key.equals(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A3_LOCKED)
        || key.equals(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A4_LOCKED))
    {
      getLeftDoorOpenStatus(vehicleIndex);
      setApplicationOutputsProperty(IAppOutputsDoorLoopInterlocksScreenProperties.LEFT_DOOR_OPEN_STATUS,
          updateLeftDoorLoopOpenStatus().build().toByteArray());

    }
    if (key.equals(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B1_LOCKED)
        || key.equals(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B2_LOCKED)
        || key.equals(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B3_LOCKED)
        || key.equals(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B4_LOCKED))
    {
      getRightDoorOpenStatus(vehicleIndex);
      setApplicationOutputsProperty(IAppOutputsDoorLoopInterlocksScreenProperties.RIGHT_DOOR_OPEN_STATUS,
          updateRightDoorLoopOpenStatus().build().toByteArray());
    }
    else if (key.equals(ITCMSVehicleOutputsDoorStatusProperties.EMERGENCY_ESCAPE_DOOR_LOCKED))
    {
      getEmergencyDoorOpenStatus(doorModel.getEmergencyEscapeDoorLocked(), vehicleIndex);
      setApplicationOutputsProperty(IAppOutputsDoorLoopInterlocksScreenProperties.EMG_DOOR_OPEN_STATUS,
          updateEmergencyDoorLoopOpenStatus().build().toByteArray());
    }
  }

  private DoorLoopInterlockData.Builder updateLeftDoorLoopOpenStatus()
  {
    DoorLoopInterlockData.Builder builder = DoorLoopInterlockData.newBuilder();
    synchronized (leftDoorOpenStatusMap)
    {
      leftDoorOpenStatusMap.forEach((vehicleIndex, doorOpenState) -> {
        DoorLoopInterlockData.DoorLoopInterlockStatus.Builder statusbuilder = DoorLoopInterlockData.DoorLoopInterlockStatus
            .newBuilder();
        statusbuilder.setCarIndex(vehicleIndex);
        statusbuilder.setDoorLoopInterlockState(doorOpenState);
        builder.addDoorLoopInterlockStatus(statusbuilder.build());
      });
    }
    return builder;
  }

  private DoorLoopInterlockData.Builder updateRightDoorLoopOpenStatus()
  {
    DoorLoopInterlockData.Builder builder = DoorLoopInterlockData.newBuilder();
    synchronized (rightDoorOpenStatusMap)
    {
      rightDoorOpenStatusMap.forEach((vehicleIndex, doorOpenState) -> {
        DoorLoopInterlockData.DoorLoopInterlockStatus.Builder statusbuilder = DoorLoopInterlockData.DoorLoopInterlockStatus
            .newBuilder();
        statusbuilder.setCarIndex(vehicleIndex);
        statusbuilder.setDoorLoopInterlockState(doorOpenState);
        builder.addDoorLoopInterlockStatus(statusbuilder.build());
      });
    }
    return builder;
  }

  private DoorLoopInterlockData.Builder updateEmergencyDoorLoopOpenStatus()
  {
    DoorLoopInterlockData.Builder builder = DoorLoopInterlockData.newBuilder();
    synchronized (emgDoorOpenStatusMap)
    {
      emgDoorOpenStatusMap.forEach((vehicleIndex, doorOpenState) -> {
        DoorLoopInterlockData.DoorLoopInterlockStatus.Builder statusbuilder = DoorLoopInterlockData.DoorLoopInterlockStatus
            .newBuilder();
        statusbuilder.setCarIndex(vehicleIndex);
        statusbuilder.setDoorLoopInterlockState(doorOpenState);
        builder.addDoorLoopInterlockStatus(statusbuilder.build());
      });
    }
    return builder;
  }

  private void getLeftDoorOpenStatus(Integer vehicleIndex)
  {
    if (doorModel.getDoorA1Locked() == DoorLoopInterlockState.OPEN_VALUE
        || doorModel.getDoorA2Locked() == DoorLoopInterlockState.OPEN_VALUE
        || doorModel.getDoorA3Locked() == DoorLoopInterlockState.OPEN_VALUE
        || doorModel.getDoorA4Locked() == DoorLoopInterlockState.OPEN_VALUE)
    {
      leftDoorOpenStatusMap.put(vehicleIndex, DoorLoopInterlockState.OPEN);
    }
    else
    {
      leftDoorOpenStatusMap.put(vehicleIndex, DoorLoopInterlockState.CLOSED);
    }
  }

  private void getRightDoorOpenStatus(Integer vehicleIndex)
  {
    if (doorModel.getDoorB1Locked() == DoorLoopInterlockState.OPEN_VALUE
        || doorModel.getDoorB2Locked() == DoorLoopInterlockState.OPEN_VALUE
        || doorModel.getDoorB3Locked() == DoorLoopInterlockState.OPEN_VALUE
        || doorModel.getDoorB4Locked() == DoorLoopInterlockState.OPEN_VALUE)
    {
      rightDoorOpenStatusMap.put(vehicleIndex, DoorLoopInterlockState.OPEN);
    }
    else
    {
      rightDoorOpenStatusMap.put(vehicleIndex, DoorLoopInterlockState.CLOSED);
    }
  }

  private void getEmergencyDoorOpenStatus(Integer doorOpen, Integer vehicleIndex)
  {
    if (doorOpen == DoorLoopInterlockState.OPEN_VALUE)
    {
      emgDoorOpenStatusMap.put(vehicleIndex, DoorLoopInterlockState.OPEN);
    }
    else
    {
      emgDoorOpenStatusMap.put(vehicleIndex, DoorLoopInterlockState.CLOSED);
    }
  }
}
