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

import java.util.Objects;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ALGStatusList.ALGStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ECNComponentSwitchStatusList.ECNComponentSwitchStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainBackboneNodeStatusList.TrainBackboneNodeStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainEthernetRepeaterStatusList.TrainEthernetRepeaterStatus;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class TCMSEthernetConsistNetworkScreenModel extends AbstractScreenModel
{

  private ListProperty<CarComponentObjectProperty> componentSwitchAState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> componentSwitchBState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> componentSwitchCState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> trainBackboneNodeState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> trainEthernetRepeaterState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> algState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public TCMSEthernetConsistNetworkScreenModel(int carIndex)
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
      if (!Objects.equals(componentList.get(indexOf).get().getComponentState(), statesDO.getComponentState()))
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
   * CS-A State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> componentSwitchAStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, componentSwitchAState);
  }

  /**
   * CS-B State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> componentSwitchBStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, componentSwitchBState);
  }

  /**
   * CS-C State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> componentSwitchCStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, componentSwitchCState);
  }

  /**
   * TBN State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> trainBackboneNodeStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, trainBackboneNodeState);
  }

  /**
   * TER State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> trainEthernetRepeaterStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, trainEthernetRepeaterState);
  }

  /**
   * ALG State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> algStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, algState);
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

  public void setComponentSwitchAState(byte[] componentSwitchStatusList)
  {
    if (componentSwitchStatusList.length != 0)
    {
      try
      {
        TCMSProto.ECNComponentSwitchStatusList status = TCMSProto.ECNComponentSwitchStatusList
            .parseFrom(componentSwitchStatusList);
        for (ECNComponentSwitchStatus vehicleState : status.getEcnComponentSwitchStatusList())
        {
          updateCarComponentStatus(vehicleState.getEcnComponentSwitchState().name().toLowerCase(),
              vehicleState.getCarIndex(), componentSwitchAState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setComponentSwitchBState(byte[] componentSwitchStatusList)
  {
    if (componentSwitchStatusList.length != 0)
    {
      try
      {
        TCMSProto.ECNComponentSwitchStatusList status = TCMSProto.ECNComponentSwitchStatusList
            .parseFrom(componentSwitchStatusList);
        for (ECNComponentSwitchStatus vehicleState : status.getEcnComponentSwitchStatusList())
        {
          updateCarComponentStatus(vehicleState.getEcnComponentSwitchState().name().toLowerCase(),
              vehicleState.getCarIndex(), componentSwitchBState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setComponentSwitchCState(byte[] componentSwitchStatusList)
  {
    if (componentSwitchStatusList.length != 0)
    {
      try
      {
        TCMSProto.ECNComponentSwitchStatusList status = TCMSProto.ECNComponentSwitchStatusList
            .parseFrom(componentSwitchStatusList);
        for (ECNComponentSwitchStatus vehicleState : status.getEcnComponentSwitchStatusList())
        {
          updateCarComponentStatus(vehicleState.getEcnComponentSwitchState().name().toLowerCase(),
              vehicleState.getCarIndex(), componentSwitchCState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setTrainBackboneNodeState(byte[] tbnStatusList)
  {
    if (tbnStatusList.length != 0)
    {
      try
      {
        TCMSProto.TrainBackboneNodeStatusList status = TCMSProto.TrainBackboneNodeStatusList
            .parseFrom(tbnStatusList);
        for (TrainBackboneNodeStatus vehicleState : status.getTrainBackboneNodeStatusList())
        {
          updateCarComponentStatus(vehicleState.getTrainBackboneNodeState().name().toLowerCase(),
              vehicleState.getCarIndex(), trainBackboneNodeState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setTrainEthernetRepeaterState(byte[] terStatusList)
  {
    if (terStatusList.length != 0)
    {
      try
      {
        TCMSProto.TrainEthernetRepeaterStatusList status = TCMSProto.TrainEthernetRepeaterStatusList
            .parseFrom(terStatusList);
        for (TrainEthernetRepeaterStatus vehicleState : status.getTrainEthernetRepeaterStatusList())
        {
          updateCarComponentStatus(vehicleState.getTrainEthernetRepeaterState().name().toLowerCase(),
              vehicleState.getCarIndex(), trainEthernetRepeaterState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setALGState(byte[] algStatusList)
  {
    if (algStatusList.length != 0)
    {
      try
      {
        TCMSProto.ALGStatusList status = TCMSProto.ALGStatusList.parseFrom(algStatusList);
        for (ALGStatus vehicleState : status.getAlgStatusList())
        {
          updateCarComponentStatus(vehicleState.getAlgState().name().toLowerCase(),
              vehicleState.getCarIndex(), algState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }
}
