/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import java.util.Objects;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AutomaticDropList.AutomaticDropStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BrakeLoopCbTripedList.BrakeLoopCbTripedStatus;

import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MainReserviorPressureLowList.MainReserviorStatus;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class BrakeLoopInterlockScreenModel extends AbstractScreenModel
{
  private IntegerProperty numberOfCars = new SimpleIntegerProperty();

  private ListProperty<CarComponentObjectProperty> mainRePressureState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> automaticDropState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> brakeLoopCbState = new SimpleListProperty<>(
      FXCollections.observableArrayList());
  

  private ListProperty<CarComponentObjectProperty> brakeLoopObState  = new SimpleListProperty<>(
      FXCollections.observableArrayList());
  public BrakeLoopInterlockScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getNumberOfCars()
  {
    return numberOfCars;
  }

  public void setNumberOfCars(Integer numberOfCars)
  {
    this.numberOfCars.set(numberOfCars);
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
  
  public final ObjectPropertyBase<CarComponentStatesDO> mainReserviorPressureProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, mainRePressureState);
  }

  public void setMainReserviorPressureState(byte[] mainPressureList)
  {

    if (mainPressureList.length != 0)
    {
      try
      {
        TCMSProto.MainReserviorPressureLowList status = TCMSProto.MainReserviorPressureLowList
            .parseFrom(mainPressureList);
        for (MainReserviorStatus vehicleState : status.getMainReserviorStatusList())
        {
          updateCarComponentStatus(vehicleState.getMainReseerviorState().name().toLowerCase(),
              vehicleState.getCarIndex(), mainRePressureState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public final ObjectPropertyBase<CarComponentStatesDO> automaticDropeProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, automaticDropState);
  }
  
  public void setAutomaticDropState(byte[] automaticDropList)
  {

    if (automaticDropList.length != 0)
    {
      try
      {
        TCMSProto.AutomaticDropList status = TCMSProto.AutomaticDropList.parseFrom(automaticDropList);
        for (AutomaticDropStatus vehicleState : status.getAutomaticDropStatusList())
        {
          updateCarComponentStatus(vehicleState.getAutomaticDropState().name().toLowerCase(),
              vehicleState.getCarIndex(), automaticDropState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public final ObjectPropertyBase<CarComponentStatesDO> brakeLoopCbProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, brakeLoopCbState);
  }
  
  public void setBrakeLoopCbState(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        TCMSProto.BrakeLoopCbTripedList status = TCMSProto.BrakeLoopCbTripedList.parseFrom(newValue);
        for (BrakeLoopCbTripedStatus vehicleState : status.getBrakeLoopCbTripedStatusList())
        {
          updateCarComponentStatus(vehicleState.getBrakeLoopCbTripedState().name().toLowerCase(),
              vehicleState.getCarIndex(), brakeLoopCbState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

 

}
