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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CCUStatusList.CCUStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ERStatusList.ERStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.RIO12LineStatusList.RIO12LineStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.RIO1FaultStatusList.RIO1FaultStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.RIO1StatusList.RIO1Status;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.RIO2StatusList.RIO2Status;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class TCMSStatusScreenModel extends AbstractScreenModel
{

  private ListProperty<CarComponentObjectProperty> ccuState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> rio12LineState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> erState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> rio1State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> rio2State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public TCMSStatusScreenModel(int carIndex)
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
   * CCU State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> ccuStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, ccuState);
  }

  /**
   * RIO 1 RIO 2 Communication State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> rio12LineStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, rio12LineState);
  }

  /**
   * ER State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> erStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, erState);
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

  public void setCCUState(byte[] ccuStatusList)
  {
    if (ccuStatusList.length != 0)
    {
      try
      {
        TCMSProto.CCUStatusList status = TCMSProto.CCUStatusList.parseFrom(ccuStatusList);
        for (CCUStatus vehicleState : status.getCcuStatusList())
        {
          updateCarComponentStatus(vehicleState.getCcuState().name().toLowerCase(),
              vehicleState.getCarIndex(), ccuState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setRIO12LineState(byte[] rio12LineStatusList)
  {
    if (rio12LineStatusList.length != 0)
    {
      try
      {
        TCMSProto.RIO12LineStatusList status = TCMSProto.RIO12LineStatusList.parseFrom(rio12LineStatusList);
        for (RIO12LineStatus vehicleState : status.getRio12LineStatusList())
        {
          updateCarComponentStatus(vehicleState.getRio12LineState().name().toLowerCase(),
              vehicleState.getCarIndex(), rio12LineState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setERState(byte[] erStatusList)
  {
    if (erStatusList.length != 0)
    {
      try
      {
        TCMSProto.ERStatusList status = TCMSProto.ERStatusList.parseFrom(erStatusList);
        for (ERStatus vehicleState : status.getErStatusList())
        {
          updateCarComponentStatus(vehicleState.getErState().name().toLowerCase(), vehicleState.getCarIndex(),
              erState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setRIO1State(byte[] rio1StatusList)
  {

    if (rio1StatusList.length != 0)
    {
      try
      {
        TCMSProto.RIO1StatusList status = TCMSProto.RIO1StatusList.parseFrom(rio1StatusList);
        for (RIO1Status vehicleState : status.getRio1StatusList())
        {
          updateCarComponentStatus(vehicleState.getRio1State().name().toLowerCase(),
              vehicleState.getCarIndex(), rio1State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public void setRIO2State(byte[] rio2StatusList)
  {

    if (rio2StatusList.length != 0)
    {
      try
      {
        TCMSProto.RIO2StatusList status = TCMSProto.RIO2StatusList.parseFrom(rio2StatusList);
        for (RIO2Status vehicleState : status.getRio2StatusList())
        {
          updateCarComponentStatus(vehicleState.getRio2State().name().toLowerCase(),
              vehicleState.getCarIndex(), rio2State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public final ObjectPropertyBase<CarComponentStatesDO> rio1StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, rio1State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> rio2StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, rio2State);
  }

}
