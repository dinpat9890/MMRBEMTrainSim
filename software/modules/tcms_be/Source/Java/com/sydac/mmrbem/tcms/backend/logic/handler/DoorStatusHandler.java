/*
 * ================================================================== (C)
 * Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic.handler;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.function.Consumer;
import java.util.function.Function;

import org.springframework.stereotype.Service;

import com.sydac.common.log.Tracer;
import com.sydac.foundation.PropertyKey;
import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.AbstractFunctionalLogic;
import com.sydac.mmrbem.tcms.backend.logic.annotation.FunctionalLogicHandler;
import com.sydac.mmrbem.tcms.backend.vehicle.io.models.ITCMSVehicleOutputsDoorModel;
import com.sydac.mmrbem.tcms.backend.vehicle.io.properties.ITCMSVehicleOutputsDoorStatusProperties;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequest;
import com.sydac.mmrbem.tcms.backend.vehicle.request.handler.ITCMSVehicleOutputsRequestHandler;
import com.sydac.mmrbem.tcms.common.data.Entry;
import com.sydac.mmrbem.tcms.common.io.properties.IAppOutputsTrainTopViewComponentProperties;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VehicleDoorStatesList.DoorState;

/**
 * This handler class handle the Door status of vehicle and set to COMMS. Note
 * that car orientation is taken car by frontend
 * 
 */
@Service
@FunctionalLogicHandler(arguments = { CommsBinding.class })
public class DoorStatusHandler extends AbstractFunctionalLogic
{
  DoorStatusUpdateRequestHandler doorA1StateHandler = new DoorStatusUpdateRequestHandler(this::getDoorA1State,
      this::setAppOutputDoorA1Status);

  DoorStatusUpdateRequestHandler doorA2StateHandler = new DoorStatusUpdateRequestHandler(this::getDoorA2State,
      this::setAppOutputDoorA2Status);

  DoorStatusUpdateRequestHandler doorA3StateHandler = new DoorStatusUpdateRequestHandler(this::getDoorA3State,
      this::setAppOutputDoorA3Status);

  DoorStatusUpdateRequestHandler doorA4StateHandler = new DoorStatusUpdateRequestHandler(this::getDoorA4State,
      this::setAppOutputDoorA4Status);

  DoorStatusUpdateRequestHandler doorB1StateHandler = new DoorStatusUpdateRequestHandler(this::getDoorB1State,
      this::setAppOutputDoorB1Status);

  DoorStatusUpdateRequestHandler doorB2StateHandler = new DoorStatusUpdateRequestHandler(this::getDoorB2State,
      this::setAppOutputDoorB2Status);

  DoorStatusUpdateRequestHandler doorB3StateHandler = new DoorStatusUpdateRequestHandler(this::getDoorB3State,
      this::setAppOutputDoorB3Status);

  DoorStatusUpdateRequestHandler doorB4StateHandler = new DoorStatusUpdateRequestHandler(this::getDoorB4State,
      this::setAppOutputDoorB4Status);

  DoorStatusUpdateRequestHandler emergencyEscapeDoorStateHandler = new DoorStatusUpdateRequestHandler(
      this::getEmergencyEscapeDoorState, this::setAppOutputEmergencyEscapeDoorStatus);

  /**
   * This map holds request handles for Door Status related parameters.
   */
  private final Map<PropertyKey<? extends Number>, DoorStatusUpdateRequestHandler> handlerMap = new HashMap<>();

  public DoorStatusHandler(CommsBinding commsBinding)
  {
    super(commsBinding, ITCMSVehicleOutputsDoorStatusProperties.class);
    initializeMap();
  }

  private void initializeMap()
  {
    // Door x Open
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A1_OPEN, doorA1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A2_OPEN, doorA2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A3_OPEN, doorA3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A4_OPEN, doorA4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B1_OPEN, doorB1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B2_OPEN, doorB2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B3_OPEN, doorB3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B4_OPEN, doorB4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.EMERGENCY_ESCAPE_DOOR_OPEN,
        emergencyEscapeDoorStateHandler);
    // Door x Isolated
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A1_ISOLATED, doorA1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A2_ISOLATED, doorA2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A3_ISOLATED, doorA3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A4_ISOLATED, doorA4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B1_ISOLATED, doorB1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B2_ISOLATED, doorB2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B3_ISOLATED, doorB3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B4_ISOLATED, doorB4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.EMERGENCY_ESCAPE_DOOR_ISOLATED,
        emergencyEscapeDoorStateHandler);
    // Door x Fault
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A1_FAULT, doorA1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A2_FAULT, doorA2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A3_FAULT, doorA3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A4_FAULT, doorA4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B1_FAULT, doorB1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B2_FAULT, doorB2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B3_FAULT, doorB3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B4_FAULT, doorB4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.EMERGENCY_ESCAPE_DOOR_FAULT,
        emergencyEscapeDoorStateHandler);
    // Door x Emergency Released
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A1_EMERGENCY_RELEASED, doorA1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A2_EMERGENCY_RELEASED, doorA2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A3_EMERGENCY_RELEASED, doorA3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A4_EMERGENCY_RELEASED, doorA4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B1_EMERGENCY_RELEASED, doorB1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B2_EMERGENCY_RELEASED, doorB2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B3_EMERGENCY_RELEASED, doorB3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B4_EMERGENCY_RELEASED, doorB4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.EMERGENCY_ESCAPE_DOOR_RELEASED,
        emergencyEscapeDoorStateHandler);
    // Door x Locked
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A1_LOCKED, doorA1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A2_LOCKED, doorA2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A3_LOCKED, doorA3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_A4_LOCKED, doorA4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B1_LOCKED, doorB1StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B2_LOCKED, doorB2StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B3_LOCKED, doorB3StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.DOOR_B4_LOCKED, doorB4StateHandler);
    handlerMap.put(ITCMSVehicleOutputsDoorStatusProperties.EMERGENCY_ESCAPE_DOOR_LOCKED,
        emergencyEscapeDoorStateHandler);
  }

  class DoorStatusUpdateRequestHandler implements ITCMSVehicleOutputsRequestHandler<DoorStatusRequest>
  {

    private final List<Entry<DoorState>> doorStatusList = new ArrayList<>();

    private final Function<ITCMSVehicleOutputsDoorModel, DoorState> doorModelFunction;

    private final Consumer<TCMSProto.VehicleDoorStatesList.Builder> applicationConsumer;

    DoorStatusUpdateRequestHandler(
        Function<ITCMSVehicleOutputsDoorModel, DoorState> doorStatusSupplierFunction,
        Consumer<TCMSProto.VehicleDoorStatesList.Builder> consumer)
    {
      doorModelFunction = doorStatusSupplierFunction;
      applicationConsumer = consumer;
    }

    @Override
    public void handleRequest(DoorStatusRequest request)
    {
      ITCMSVehicleOutputsDoorModel model = (ITCMSVehicleOutputsDoorModel)getTCMSVehicleOutputsModels()
          .get(request.getCarIndex());
      DoorState state = doorModelFunction.apply(model);
      setDoorStatus(doorStatusList, state, request.getCarIndex());
      applicationConsumer.accept(getVehicleDoorStatusBuilder());
    }

    private void setDoorStatus(List<Entry<DoorState>> doorState, DoorState state, int index)
    {
      synchronized (doorStatusList)
      {
        if (doorState.stream().anyMatch(entry -> entry.getIndex() == index))
        {
          doorState.stream().filter(entry -> entry.getIndex() == index)
              .forEach(entry -> entry.setData(state));
        }
        else
        {
          doorState.add(new Entry<>(index, state));
          Collections.sort(doorState);
        }
      }
    }

    private TCMSProto.VehicleDoorStatesList.Builder getVehicleDoorStatusBuilder()
    {
      TCMSProto.VehicleDoorStatesList.Builder builder = TCMSProto.VehicleDoorStatesList.newBuilder();
      synchronized (doorStatusList)
      {
        for (Entry<DoorState> entry : doorStatusList)
        {
          TCMSProto.VehicleDoorStatesList.VehicleDoorState.Builder doorBuilder = TCMSProto.VehicleDoorStatesList.VehicleDoorState
              .newBuilder();
          doorBuilder.setCarIndex(entry.getIndex());
          doorBuilder.setDoorState(entry.getData());
          builder.addVehicle(doorBuilder.build());
        }
      }
      return builder;
    }
  }

  private void setAppOutputDoorA1Status(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_A1,
        builder.build().toByteArray());
  }

  private void setAppOutputDoorA2Status(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_A2,
        builder.build().toByteArray());
  }

  private void setAppOutputDoorA3Status(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_A3,
        builder.build().toByteArray());
  }

  private void setAppOutputDoorA4Status(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_A4,
        builder.build().toByteArray());
  }

  private void setAppOutputDoorB1Status(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_B1,
        builder.build().toByteArray());
  }

  private void setAppOutputDoorB2Status(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_B2,
        builder.build().toByteArray());
  }

  private void setAppOutputDoorB3Status(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_B3,
        builder.build().toByteArray());
  }

  private void setAppOutputDoorB4Status(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_B4,
        builder.build().toByteArray());
  }

  private void setAppOutputEmergencyEscapeDoorStatus(TCMSProto.VehicleDoorStatesList.Builder builder)
  {
    setApplicationOutputsProperty(IAppOutputsTrainTopViewComponentProperties.DOOR_STATUS_DETRAINMENT,
        builder.build().toByteArray());
  }

  public DoorState getDoorA1State(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getDoorA1Open(), model.getDoorA1Isolated(), model.getDoorA1Fault(),
        model.getDoorA1EmergencyReleased(), model.getDoorA1Locked());
  }

  public DoorState getDoorA2State(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getDoorA2Open(), model.getDoorA2Isolated(), model.getDoorA2Fault(),
        model.getDoorA2EmergencyReleased(), model.getDoorA2Locked());
  }

  public DoorState getDoorA3State(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getDoorA3Open(), model.getDoorA3Isolated(), model.getDoorA3Fault(),
        model.getDoorA3EmergencyReleased(), model.getDoorA3Locked());
  }

  public DoorState getDoorA4State(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getDoorA4Open(), model.getDoorA4Isolated(), model.getDoorA4Fault(),
        model.getDoorA4EmergencyReleased(), model.getDoorA4Locked());
  }

  public DoorState getDoorB1State(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getDoorB1Open(), model.getDoorB1Isolated(), model.getDoorB1Fault(),
        model.getDoorB1EmergencyReleased(), model.getDoorB1Locked());
  }

  public DoorState getDoorB2State(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getDoorB2Open(), model.getDoorB2Isolated(), model.getDoorB2Fault(),
        model.getDoorB2EmergencyReleased(), model.getDoorB2Locked());
  }

  public DoorState getDoorB3State(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getDoorB3Open(), model.getDoorB3Isolated(), model.getDoorB3Fault(),
        model.getDoorB3EmergencyReleased(), model.getDoorB3Locked());
  }

  public DoorState getDoorB4State(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getDoorB4Open(), model.getDoorB4Isolated(), model.getDoorB4Fault(),
        model.getDoorB4EmergencyReleased(), model.getDoorB4Locked());
  }

  public DoorState getEmergencyEscapeDoorState(ITCMSVehicleOutputsDoorModel model)
  {
    return getDoorState(model.getEmergencyEscapeDoorOpen(), model.getEmergencyEscapeDoorIsolated(),
        model.getEmergencyEscapeDoorFault(), model.getEmergencyEscapeDoorReleased(),
        model.getEmergencyEscapeDoorLocked());
  }

  private DoorState getDoorState(int doorOpen, int doorIsolated, int doorFault, int doorEmergencyReleased,
      int doorLocked)
  {
    DoorState doorStatus;
    if (doorIsolated == 1)
    {
      doorStatus = DoorState.ISOLATED;
    }
    else if (doorOpen == 1 && doorFault == 1)
    {
      doorStatus = DoorState.OPEN_AND_FAULTY;
    }
    else if (doorFault == 1 && doorLocked == 0 && doorOpen == 0)
    {
      doorStatus = DoorState.OPEN_AND_FAULTY;
    }
    else if (doorOpen == 0 && doorFault == 1)
    {
      doorStatus = DoorState.CLOSE_AND_FAULTY;
    }

    else if (doorEmergencyReleased == 1)
    {
      doorStatus = DoorState.EMERGENCY;
    }
    else if (doorOpen == 0 && doorLocked == 1)
    {
      doorStatus = DoorState.CLOSED_AND_LOCKED;
    }
    else if (doorOpen == 0 && doorLocked == 0)
    {
      doorStatus = DoorState.CLOSED_BUT_NOT_LOCKED;
    }
    else if (doorOpen == 1)
    {
      doorStatus = DoorState.OPEN;
    }
    else
    {
      doorStatus = DoorState.UNKNOWN;
    }
    return doorStatus;
  }

  @Override
  public <T> void tcmsVehicleOutputsPropertyUpdated(PropertyKey<T> key, T oldValue, T newValue,
      int vehicleIndex)
  {
    DoorStatusUpdateRequestHandler handler = handlerMap.get(key);
    if (handler != null)
    {
      handler.handleRequest(new DoorStatusRequest(vehicleIndex));
    }
    else
    {
      Tracer.getInstance()
          .debug(String.format("Cannot update, request Handler for key %S is not found", key.toString())); //$NON-NLS-1$
    }
  }

  class DoorStatusRequest implements ITCMSVehicleOutputsRequest<Integer>
  {
    private final int carIndex;

    DoorStatusRequest(int aCarIndex)
    {
      carIndex = aCarIndex;
    }

    @Override
    public PropertyKey<Integer> getPropertyKey()
    {
      throw new UnsupportedOperationException();
    }

    @Override
    public Integer getOldValue()
    {
      throw new UnsupportedOperationException();
    }

    @Override
    public Integer getNewValue()
    {
      throw new UnsupportedOperationException();
    }

    @Override
    public int getCarIndex()
    {
      return carIndex;
    }
  }
}
