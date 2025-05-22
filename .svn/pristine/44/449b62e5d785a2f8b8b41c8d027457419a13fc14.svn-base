/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ParkingBrakeStatusList.ParkingBrakeStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PropulsionStatusList.PropulsionStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ServiceBrakeStatusList.ServiceBrakeStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VehicleDoorStatesList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VehicleDoorStatesList.DoorState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VehicleDoorStatesList.VehicleDoorState;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.data.VehicleDoorStatesDO;

import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class TrainTopViewComponentStatusModel extends AbstractScreenModel
{
  private ListProperty<DoorObjectProperty> doorA1State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<DoorObjectProperty> doorA2State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<DoorObjectProperty> doorA3State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<DoorObjectProperty> doorA4State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<DoorObjectProperty> doorB1State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<DoorObjectProperty> doorB2State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<DoorObjectProperty> doorB3State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<DoorObjectProperty> doorB4State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<DoorObjectProperty> detrainmentDoorState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> parkingBrakeState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> serviceBrakeState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> propulsionState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public TrainTopViewComponentStatusModel(int carIndex)
  {
    super(carIndex);
  }

  /**
   * Update the car component state in ListProperty <CarComponentObjectProperty>
   * for the given car index.<br>
   * Note: component state only gets updated, if current and previous state are
   * different
   *
   * @param componentState
   *          CSS name for component
   * @param carIndex
   *          the car index
   * @param componentList
   *          list of {@link CarComponentObjectProperty} which need to update
   */
  private void updateCarComponentStatus(String componentState, int carIndex,
      ListProperty<CarComponentObjectProperty> componentList)
  {
    CarComponentStatesDO statesDO = new CarComponentStatesDO();
    statesDO.setComponentState(componentState);
    statesDO.setCarIndex(carIndex);
    int indexOf = indexOf(componentList, statesDO);
    if (indexOf != -1)
    {
      // data already exists for this car, check if state has changed
      if (componentList.get(indexOf).get().getComponentState() != statesDO.getComponentState())
      {
        componentList.get(indexOf).setComponentCSS(statesDO.getComponentState());
      }
      // else, there is no change in state. Do nothing
    }
    else
    {
      // data does not exist, so add to list
      componentList.add(new CarComponentObjectProperty(statesDO));
    }

  }

  /**
   * Return index of element in ListProperty<CarComponentObjectProperty> that
   * matches with incoming CarComponentStatesDO object
   *
   * @param componentStateList
   *          list of {@link CarComponentObjectProperty}
   * @param statesDO
   *          reference of {@link CarComponentStatesDO}
   * @return index of matched element, if not return -1
   */
  private int indexOf(ListProperty<CarComponentObjectProperty> componentStateList,
      CarComponentStatesDO statesDO)
  {
    for (int i = 0; i < componentStateList.size(); i++)
    {
      CarComponentObjectProperty objectProperty = componentStateList.get(i);
      if (objectProperty.get().getCarIndex() == statesDO.getCarIndex())
      {
        return i;
      }
    }
    return -1;
  }

  /**
   * Return index of element in ListProperty<DoorObjectProperty> that matches
   * with incoming VehicleDoorStatesDO object
   *
   * @param doorState
   *          list of {@link DoorObjectProperty}
   * @param statesDO
   *          reference of {@link VehicleDoorStatesDO}
   * @return index
   */
  private int indexOfDoor(ListProperty<DoorObjectProperty> doorState, VehicleDoorStatesDO statesDO)
  {
    for (int i = 0; i < doorState.size(); i++)
    {
      DoorObjectProperty objectProperty = doorState.get(i);
      if (objectProperty.get().getCarIndex() == statesDO.getCarIndex())
      {
        return i;
      }
    }
    return -1;
  }

  /**
   * Process the raw data for doors and then updates the door status properties
   * for each door.
   *
   * @param vehicleDoorStatesList
   *          as {@link VehicleDoorStatesList} the data
   * @param doorState
   *          the door status property
   */
  private void updateDoorStatus(VehicleDoorStatesList vehicleDoorStatesList,
      ListProperty<DoorObjectProperty> doorState)
  {
    if (vehicleDoorStatesList != null)
    {
      for (VehicleDoorState vehicleDoorState : vehicleDoorStatesList.getVehicleList())
      {
        VehicleDoorStatesDO statesDO = new VehicleDoorStatesDO();
        statesDO.setDoorState(vehicleDoorState.getDoorState());
        statesDO.setCarIndex(vehicleDoorState.getCarIndex());
        int indexOf = indexOfDoor(doorState, statesDO);
        if (indexOf != -1)
        {
          // data already exists for this car, check if state has changed
          if (doorState.get(indexOf).get().getDoorState() != statesDO.getDoorState())
          {
            doorState.get(indexOf).setState(statesDO.getDoorState());
          }
          // else, there is no change in state. Do nothing
        }
        else
        {
          // data does not exist, so add to list
          doorState.add(new DoorObjectProperty(statesDO));
        }
      }
    }
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> doorA1StatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, doorA1State);
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> doorA2StatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, doorA2State);
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> doorA3StatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, doorA3State);
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> doorA4StatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, doorA4State);
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> doorB1StatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, doorB1State);
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> doorB2StatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, doorB2State);
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> doorB3StatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, doorB3State);
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> doorB4StatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, doorB4State);
  }

  public final ObjectPropertyBase<VehicleDoorStatesDO> detrainmentDoorStatusProperty(int carIndex)
  {
    return getDoorPropertyFor(carIndex, detrainmentDoorState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> parkingBrakeStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, parkingBrakeState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> serviceBrakeStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, serviceBrakeState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> propulsionStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, propulsionState);
  }

  public void setDoorA1State(byte[] doorA1StateList)
  {
    if (doorA1StateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList.parseFrom(doorA1StateList);
        updateDoorStatus(status, doorA1State);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDoorA2State(byte[] doorA2StateList)
  {
    if (doorA2StateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList.parseFrom(doorA2StateList);
        updateDoorStatus(status, doorA2State);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDoorA3State(byte[] doorA3StateList)
  {
    if (doorA3StateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList.parseFrom(doorA3StateList);
        updateDoorStatus(status, doorA3State);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDoorA4State(byte[] doorA4StateList)
  {
    if (doorA4StateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList.parseFrom(doorA4StateList);
        updateDoorStatus(status, doorA4State);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDoorB1State(byte[] doorB1StateList)
  {
    if (doorB1StateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList.parseFrom(doorB1StateList);
        updateDoorStatus(status, doorB1State);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDoorB2State(byte[] doorB2StateList)
  {
    if (doorB2StateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList.parseFrom(doorB2StateList);
        updateDoorStatus(status, doorB2State);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDoorB3State(byte[] doorB3StateList)
  {
    if (doorB3StateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList.parseFrom(doorB3StateList);
        updateDoorStatus(status, doorB3State);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDoorB4State(byte[] doorB4StateList)
  {
    if (doorB4StateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList.parseFrom(doorB4StateList);
        updateDoorStatus(status, doorB4State);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDetrainmentDoorState(byte[] detrainmentDoorStateList)
  {
    if (detrainmentDoorStateList.length != 0)
    {
      try
      {
        TCMSProto.VehicleDoorStatesList status = TCMSProto.VehicleDoorStatesList
            .parseFrom(detrainmentDoorStateList);
        updateDoorStatus(status, detrainmentDoorState);
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setParkingBrakeState(byte[] parkingBrakeStateList)
  {
    if (parkingBrakeStateList.length != 0)
    {
      try
      {
        TCMSProto.ParkingBrakeStatusList status = TCMSProto.ParkingBrakeStatusList
            .parseFrom(parkingBrakeStateList);
        for (ParkingBrakeStatus vehicleState : status.getParkingBrakeStatusList())
        {
          updateCarComponentStatus(vehicleState.getParkingBrakeState().name().toLowerCase(),
              vehicleState.getCarIndex(), parkingBrakeState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setServiceBrakeState(byte[] serviceBrakeStateList)
  {
    if (serviceBrakeStateList.length != 0)
    {
      try
      {
        TCMSProto.ServiceBrakeStatusList status = TCMSProto.ServiceBrakeStatusList
            .parseFrom(serviceBrakeStateList);
        for (ServiceBrakeStatus vehicleState : status.getServiceBrakeStatusList())
        {
          updateCarComponentStatus(vehicleState.getServiceBrakeState().name().toLowerCase(),
              vehicleState.getCarIndex(), serviceBrakeState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setPropulsionState(byte[] propulsionStateList)
  {
    if (propulsionStateList.length != 0)
    {
      try
      {
        TCMSProto.PropulsionStatusList status = TCMSProto.PropulsionStatusList.parseFrom(propulsionStateList);
        for (PropulsionStatus vehicleState : status.getPropulsionStatusList())
        {
          updateCarComponentStatus(vehicleState.getPropulsionState().name().toLowerCase(),
              vehicleState.getCarIndex(), propulsionState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  /**
   * Helper method to iterate through the list of car component and find the
   * component state corresponding the carIndex
   *
   * @param carIndex
   *          the car index
   * @param carComponentList
   *          List of {@link CarComponentObjectProperty}
   * @return {@link CarComponentObjectProperty}
   */
  private CarComponentObjectProperty getCarComponentPropertyFor(int carIndex,
      ListProperty<CarComponentObjectProperty> carComponentList)
  {
    for (CarComponentObjectProperty property : carComponentList)
    {
      if (property.get().getCarIndex() == carIndex)
      {
        return property;
      }
    }
    return null;
  }

  /**
   * Helper method to iterate through the list of door states and find the door
   * state corresponding the carIndex
   *
   * @param carIndex
   *          the car index
   * @param doorStates
   *          List of {@link DoorObjectProperty}
   * @return {@link DoorObjectProperty}
   */
  private DoorObjectProperty getDoorPropertyFor(int carIndex, ListProperty<DoorObjectProperty> doorStates)
  {
    for (DoorObjectProperty property : doorStates)
    {
      if (property.get().getCarIndex() == carIndex)
        return property;
    }
    return null;
  }

  /**
   * {@link ObjectProperty} extension that is provided by the DoorStatusModel to
   * give information regarding the state of a door on a car / vehicle.
   *
   * @author Nazim Oliyath
   */
  public final class DoorObjectProperty extends ObjectPropertyBase<VehicleDoorStatesDO>
  {

    public DoorObjectProperty(VehicleDoorStatesDO initialValue)
    {
      super(initialValue);
    }

    public void setState(DoorState newDoorState)
    {
      get().setDoorState(newDoorState);
      invalidated();
      fireValueChangedEvent();
    }

    @Override
    public Object getBean()
    {
      return null;
    }

    @Override
    public String getName()
    {
      return null;
    }

    @Override
    public boolean equals(Object obj)
    {
      if (obj instanceof DoorObjectProperty)
      {
        return get().getCarIndex() == ((DoorObjectProperty)obj).get().getCarIndex();
      }
      return false;
    }

    @Override
    public int hashCode()
    {
      return get().getCarIndex() * 31;
    }
  }

  /**
   * {@link ObjectProperty} extension that is provided by the
   * CarComponentStatusModel to give information regarding the state of a
   * component on a car / vehicle.
   *
   */
  public final class CarComponentObjectProperty extends ObjectPropertyBase<CarComponentStatesDO>
  {

    public CarComponentObjectProperty(CarComponentStatesDO initialValue)
    {
      super(initialValue);
    }

    public void setComponentCSS(String componentCSS)
    {
      get().setComponentState(componentCSS);
      invalidated();
      fireValueChangedEvent();
    }

    @Override
    public Object getBean()
    {
      return null;
    }

    @Override
    public String getName()
    {
      return null;
    }

    @Override
    public boolean equals(Object obj)
    {
      if (obj instanceof CarComponentObjectProperty)
      {
        return get().getCarIndex() == ((CarComponentObjectProperty)obj).get().getCarIndex();
      }
      return false;
    }

    @Override
    public int hashCode()
    {
      return get().getCarIndex() * 31;
    }
  }

}
