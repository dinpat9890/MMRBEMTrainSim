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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CabFaultStatusList.CabFaultSate;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CabFaultStatusList.CabFaultStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DriverCabDirectionList.DriverCabDirection;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PantographStatusList.PantographStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainSideViewStatusList.TrainSideViewStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBStatusList.VCBStatus;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class TrainSideViewComponentStatusModel extends AbstractScreenModel
{

  private ListProperty<CarComponentObjectProperty> pantographState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> cabDirectionState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> cabActiveState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> bogie1State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> bogie2State = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> cabFaultState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private int totalCab;

  public TrainSideViewComponentStatusModel(int carIndex)
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
   * Cab Direction status property.
   *
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> cabDirectionStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, cabDirectionState);
  }

  /**
   * 
   * @param carIndex
   *          car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> pantographStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, pantographState);
  }

  /**
   * 
   * @param carIndex
   *          car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> vcbStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbState);
  }

  /**
   * 
   * @param carIndex
   *          car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> bogie1StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, bogie1State);
  }

  /**
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> bogie2StatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, bogie2State);
  }

  /**
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> cabActiveStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, cabActiveState);
  }

  /**
   * 
   * @param carIndex
   *          car index the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> cabFaultStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, cabFaultState);
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

  public void setPantographState(byte[] pantographStateList)
  {
    if (pantographStateList.length != 0)
    {
      try
      {
        TCMSProto.PantographStatusList status = TCMSProto.PantographStatusList.parseFrom(pantographStateList);
        for (PantographStatus vehicleState : status.getPantographStatusList())
        {
          updateCarComponentStatus(vehicleState.getPantograhState().name().toLowerCase(),
              vehicleState.getCarIndex(), pantographState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setVcbState(byte[] vcbStateList)
  {
    if (vcbStateList.length != 0)
    {
      try
      {
        TCMSProto.VCBStatusList status = TCMSProto.VCBStatusList.parseFrom(vcbStateList);
        for (VCBStatus vehicleState : status.getVcbStatusList())
        {
          updateCarComponentStatus(vehicleState.getVcbState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setCabDirectionState(byte[] cabDirectionStateList)
  {
    if (cabDirectionStateList.length != 0)
    {
      try
      {
        TCMSProto.DriverCabDirectionList status = TCMSProto.DriverCabDirectionList
            .parseFrom(cabDirectionStateList);
        for (DriverCabDirection vehicleState : status.getDriverCabDirectionList())
        {
          updateCarComponentStatus(vehicleState.getDirectionState().name().toLowerCase(),
              vehicleState.getCarIndex(), cabDirectionState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setTrainSideViewState(byte[] trainSideViewState)
  {
    if (trainSideViewState.length != 0)
    {
      try
      {
        TCMSProto.TrainSideViewStatusList status = TCMSProto.TrainSideViewStatusList
            .parseFrom(trainSideViewState);
        totalCab = 0;
        for (TrainSideViewStatus vehicleState : status.getTrainSideViewStatusList())
        {
          updateCarComponentStatus(vehicleState.getBoogie1IsolationState().name().toLowerCase(),
              vehicleState.getCarIndex(), bogie1State);
          updateCarComponentStatus(vehicleState.getBoogie2IsolationState().name().toLowerCase(),
              vehicleState.getCarIndex(), bogie2State);
          updateCarComponentStatus(vehicleState.getActiveCabState().name().toLowerCase(),
              vehicleState.getCarIndex(), cabActiveState);
          totalCab++;
        }
        if (cabFaultState.isEmpty())
        {
          for (int cabIndex = 0; cabIndex < totalCab; cabIndex++)
          {
            updateCarComponentStatus(CabFaultSate.NO_ACTIVE_FAULT.toString().toLowerCase(), cabIndex,
                cabFaultState);
          }
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setCabFaultState(byte[] cabFaultStatus)
  {
    if (cabFaultStatus.length != 0)
    {
      try
      {
        TCMSProto.CabFaultStatusList status = TCMSProto.CabFaultStatusList.parseFrom(cabFaultStatus);
        for (CabFaultStatus vehicleState : status.getCabFaultStatusList())
        {
          updateCarComponentStatus(vehicleState.getCabFaultSate().name().toLowerCase(),
              vehicleState.getCarIndex(), cabFaultState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
    else
    {
      for (int cabIndex = 0; cabIndex < totalCab; cabIndex++)
      {
        updateCarComponentStatus(CabFaultSate.NO_ACTIVE_FAULT.toString().toLowerCase(), cabIndex,
            cabFaultState);
      }
    }
  }
}
