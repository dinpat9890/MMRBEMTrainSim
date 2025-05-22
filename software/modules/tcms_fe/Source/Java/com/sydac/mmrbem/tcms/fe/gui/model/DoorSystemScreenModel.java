/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DCUStatusList.DCUStatus;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class DoorSystemScreenModel extends AbstractScreenModel
{

  private ListProperty<CarComponentObjectProperty> dcu1State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> dcu2State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> dcu3State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> dcu4State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> dcu5State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> dcu6State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> dcu7State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> dcu8State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public DoorSystemScreenModel(int carIndex)
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

  public final ObjectPropertyBase<CarComponentStatesDO> dcu1StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, dcu1State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> dcu2StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, dcu2State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> dcu3StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, dcu3State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> dcu4StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, dcu4State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> dcu5StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, dcu5State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> dcu6StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, dcu6State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> dcu7StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, dcu7State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> dcu8StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, dcu8State);
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

  public void setDcu1State(byte[] dcuStateList)
  {
    if (dcuStateList.length != 0)
    {
      try
      {
        TCMSProto.DCUStatusList status = TCMSProto.DCUStatusList.parseFrom(dcuStateList);
        for (DCUStatus vehicleState : status.getDcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getDcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), dcu1State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDcu2State(byte[] dcuStateList)
  {
    if (dcuStateList.length != 0)
    {
      try
      {
        TCMSProto.DCUStatusList status = TCMSProto.DCUStatusList.parseFrom(dcuStateList);
        for (DCUStatus vehicleState : status.getDcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getDcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), dcu2State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDcu3State(byte[] dcuStateList)
  {
    if (dcuStateList.length != 0)
    {
      try
      {
        TCMSProto.DCUStatusList status = TCMSProto.DCUStatusList.parseFrom(dcuStateList);
        for (DCUStatus vehicleState : status.getDcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getDcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), dcu3State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDcu4State(byte[] dcuStateList)
  {
    if (dcuStateList.length != 0)
    {
      try
      {
        TCMSProto.DCUStatusList status = TCMSProto.DCUStatusList.parseFrom(dcuStateList);
        for (DCUStatus vehicleState : status.getDcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getDcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), dcu4State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDcu5State(byte[] dcuStateList)
  {
    if (dcuStateList.length != 0)
    {
      try
      {
        TCMSProto.DCUStatusList status = TCMSProto.DCUStatusList.parseFrom(dcuStateList);
        for (DCUStatus vehicleState : status.getDcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getDcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), dcu5State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDcu6State(byte[] dcuStateList)
  {
    if (dcuStateList.length != 0)
    {
      try
      {
        TCMSProto.DCUStatusList status = TCMSProto.DCUStatusList.parseFrom(dcuStateList);
        for (DCUStatus vehicleState : status.getDcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getDcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), dcu6State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDcu7State(byte[] dcuStateList)
  {
    if (dcuStateList.length != 0)
    {
      try
      {
        TCMSProto.DCUStatusList status = TCMSProto.DCUStatusList.parseFrom(dcuStateList);
        for (DCUStatus vehicleState : status.getDcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getDcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), dcu7State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDcu8State(byte[] dcuStateList)
  {
    if (dcuStateList.length != 0)
    {
      try
      {
        TCMSProto.DCUStatusList status = TCMSProto.DCUStatusList.parseFrom(dcuStateList);
        for (DCUStatus vehicleState : status.getDcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getDcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), dcu8State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

}
