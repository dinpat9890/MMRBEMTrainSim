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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BCGStatusList.BCGStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LVBatteryIsolationContactorStatusList.LVBatteryIsolationContactorStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LVTrainControlContactorStatusList.LVTrainControlContactorStatus;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class LowVoltageScreenModel extends AbstractScreenModel
{

  private ListProperty<CarComponentObjectProperty> bcg1State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> bcg2State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> bicSwitchState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> tccSwitchState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public LowVoltageScreenModel(int carIndex)
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
   * BCG 1 State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> bcg1StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, bcg1State);
  }

  /**
   * BCG 2 State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> bcg2StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, bcg2State);
  }

  /**
   * BIC State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> bicStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, bicSwitchState);
  }

  /**
   * TCC State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> tccStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, tccSwitchState);
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

  public void setBCGState(byte[] bcgStateList)
  {
    if (bcgStateList.length != 0)
    {
      try
      {
        TCMSProto.BCGStatusList status = TCMSProto.BCGStatusList.parseFrom(bcgStateList);
        for (BCGStatus vehicleState : status.getBcgStatusList())
        {
          updateCarComponentStatus(vehicleState.getBcgState1().name().toLowerCase(),
              vehicleState.getCarIndex(), bcg1State);
          updateCarComponentStatus(vehicleState.getBcgState2().name().toLowerCase(),
              vehicleState.getCarIndex(), bcg2State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setBICState(byte[] bicStateList)
  {
    if (bicStateList.length != 0)
    {
      try
      {
        TCMSProto.LVBatteryIsolationContactorStatusList status = TCMSProto.LVBatteryIsolationContactorStatusList
            .parseFrom(bicStateList);
        for (LVBatteryIsolationContactorStatus vehicleState : status
            .getLvBatteryIsolationContactorStatusList())
        {
          updateCarComponentStatus(vehicleState.getLvBatteryIsolationContactorState().name().toLowerCase(),
              vehicleState.getCarIndex(), bicSwitchState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setTCCState(byte[] tccStateList)
  {
    if (tccStateList.length != 0)
    {
      try
      {
        TCMSProto.LVTrainControlContactorStatusList status = TCMSProto.LVTrainControlContactorStatusList
            .parseFrom(tccStateList);
        for (LVTrainControlContactorStatus vehicleState : status.getLvTrainControlContactorStatusList())
        {
          updateCarComponentStatus(vehicleState.getLvTrainControlContactorState().name().toLowerCase(),
              vehicleState.getCarIndex(), tccSwitchState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }
}
