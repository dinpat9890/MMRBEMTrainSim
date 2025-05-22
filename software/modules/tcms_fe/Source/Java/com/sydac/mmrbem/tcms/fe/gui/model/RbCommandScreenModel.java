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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSCIBStatusList.APSCIBStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FDUCBStatusList.FDUCBStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVAC1StatusList.HVAC1Status;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVAC2StatusList.HVAC2Status;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class RbCommandScreenModel extends AbstractScreenModel
{

  private ListProperty<CarComponentObjectProperty> hvac1State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> hvac2State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> fdscbState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> apscibState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public RbCommandScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public void setHvac1Status(byte[] hvac1List)
  {
    if (hvac1List.length != 0)
    {
      try
      {

        TCMSProto.HVAC1StatusList status = TCMSProto.HVAC1StatusList.parseFrom(hvac1List);
        for (HVAC1Status vehicleState : status.getHvac1StatusList())
        {

          updateCarComponentStatus(vehicleState.getHavac1State().name().toLowerCase(),
              vehicleState.getCarIndex(), hvac1State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public final ObjectPropertyBase<CarComponentStatesDO> hvac1StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, hvac1State);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> hvac2StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, hvac2State);
  }

  public void setHvac2Status(byte[] hvac2List)
  {
    if (hvac2List.length != 0)
    {
      try
      {

        TCMSProto.HVAC2StatusList status = TCMSProto.HVAC2StatusList.parseFrom(hvac2List);
        for (HVAC2Status vehicleState : status.getHvac2StatusList())
        {

          updateCarComponentStatus(vehicleState.getHavac2State().name().toLowerCase(),
              vehicleState.getCarIndex(), hvac2State);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
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

  public void setFdscbStatus(byte[] fdscbList)
  {

    if (fdscbList.length != 0)
    {
      try
      {

        TCMSProto.FDUCBStatusList status = TCMSProto.FDUCBStatusList.parseFrom(fdscbList);
        for (FDUCBStatus vehicleState : status.getFducbStatusList())
        {

          updateCarComponentStatus(vehicleState.getFducbState().name().toLowerCase(),
              vehicleState.getCarIndex(), fdscbState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public final ObjectPropertyBase<CarComponentStatesDO> fdscbStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, fdscbState);
  }

  public void setApsicbStatus(byte[] apsList)
  {

    if (apsList.length != 0)
    {
      try
      {

        TCMSProto.APSCIBStatusList status = TCMSProto.APSCIBStatusList.parseFrom(apsList);
        for (APSCIBStatus vehicleState : status.getApscibStatusList())
        {

          updateCarComponentStatus(vehicleState.getApscibState().name().toLowerCase(),
              vehicleState.getCarIndex(), apscibState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public final ObjectPropertyBase<CarComponentStatesDO> apsicStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, apscibState);
  }
}
