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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VcbInterlockData.VcbInterlockStatus;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.ListProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class VcbInterlockScreenModel extends AbstractScreenModel
{
  private ListProperty<CarComponentObjectProperty> vcbByTransformerState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbByAcOverCurrentState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbByMtrState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbByIcMState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbByIcDmState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbByApsState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbNoLineVoltageState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbByApsAkState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbByCiAkState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public VcbInterlockScreenModel(int carIndex)
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

  public void setVcbInterlockState(byte[] acpmStateList)
  {
    if (acpmStateList.length != 0)
    {
      try
      {
        TCMSProto.VcbInterlockData status = TCMSProto.VcbInterlockData.parseFrom(acpmStateList);
        for (VcbInterlockStatus vehicleState : status.getVcbInterlockStatusList())
        {
          updateCarComponentStatus(vehicleState.getVcbTransformerTempState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbByTransformerState);

          updateCarComponentStatus(vehicleState.getVcbByAcState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbByAcOverCurrentState);

          updateCarComponentStatus(vehicleState.getVcbByMtrState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbByMtrState);

          updateCarComponentStatus(vehicleState.getVcbByIcDmState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbByIcDmState);

          updateCarComponentStatus(vehicleState.getVcbByIcMState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbByIcMState);

          updateCarComponentStatus(vehicleState.getVcbByApsState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbByApsState);

          updateCarComponentStatus(vehicleState.getVcbNoLineVoltageState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbNoLineVoltageState);

          updateCarComponentStatus(vehicleState.getVcbByApsAkState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbByApsAkState);

          updateCarComponentStatus(vehicleState.getVcbByCiAkState().name().toLowerCase(),
              vehicleState.getCarIndex(), vcbByCiAkState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbByTransformerState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbByTransformerState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbByAcOverCurrentState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbByAcOverCurrentState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbByMtrState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbByMtrState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbByIcMState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbByIcMState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbByIcDmState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbByIcDmState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbByApsState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbByApsState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbNoLineVoltageState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbNoLineVoltageState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbByApsAkState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbByApsAkState);
  }

  public final ObjectPropertyBase<CarComponentStatesDO> getVcbByCiAkState(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbByCiAkState);
  }

}
