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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AKContactorStatusList.AKContactorStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AKStatusList.AKStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSControlUnitStatusList.APSControlUnitStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CIStatusList.CIStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVSelectedCarIndexList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVSelectedCarIndexList.SelectedCarIndex;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.KContactorStatusList.KContactorStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.KStatusList.KStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PantographStatusList.Pantograph;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PantographStatusList.PantographStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBStatusList.VCBState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBStatusList.VCBStatus;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;

import javafx.beans.property.BooleanProperty;
import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.MapProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleBooleanProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleMapProperty;
import javafx.collections.FXCollections;

public class HighVoltageScreenModel extends AbstractScreenModel
{

  private ListProperty<CarComponentObjectProperty> pantographState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> vcbState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> akContactorState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> kContactorState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> akState1 = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> akState2 = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> kState1 = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> kState2 = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> apsState1 = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> apsState2 = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<CarComponentObjectProperty> ciState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private IntegerProperty reqCtrlVcbNsStatusProperty = new SimpleIntegerProperty();

  private IntegerProperty riseSelectedState = new SimpleIntegerProperty();

  private BooleanProperty openVcbState = new SimpleBooleanProperty();

  private BooleanProperty closeVcbState = new SimpleBooleanProperty();

  private IntegerProperty pantoLowAllCarProperty = new SimpleIntegerProperty();

  private IntegerProperty isolateCiFrontCarProperty = new SimpleIntegerProperty();

  private IntegerProperty isolateCiRearCarProperty = new SimpleIntegerProperty();

  private IntegerProperty isolateCiM1Property = new SimpleIntegerProperty();

  private IntegerProperty isolateCiM2Property = new SimpleIntegerProperty();

  private IntegerProperty isolateCiM3Property = new SimpleIntegerProperty();

  private MapProperty<Integer, Integer> hvSelectedIndexMap = new SimpleMapProperty<>(
      FXCollections.observableHashMap());

  private HVSelectedCarIndexList hVSelectedCarIndexList;

  public HighVoltageScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getRiseSelectedState()
  {
    return riseSelectedState;
  }

  public void setRiseSelectedState(Integer riseSelectedState)
  {
    this.riseSelectedState.set(riseSelectedState);
  }

  public BooleanProperty getOpenVcbState()
  {
    return openVcbState;
  }

  public void setOpenVcbState(Boolean openVcbState)
  {
    this.openVcbState.set(openVcbState);
  }

  public BooleanProperty getCloseVcbState()
  {
    return closeVcbState;
  }

  public void setCloseVcbState(Boolean closeVcbState)
  {
    this.closeVcbState.set(closeVcbState);
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
   * Panto State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> pantographStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, pantographState);
  }

  /**
   * VCB State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> vcbStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, vcbState);
  }

  /**
   * Ak Contactor State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> akContactorStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, akContactorState);
  }

  /**
   * K Contactor State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> kContactorStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, kContactorState);
  }

  /**
   * Ak Status 1 State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> akStatus1Property(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, akState1);
  }

  /**
   * Ak Status 2 State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> akStatus2Property(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, akState2);
  }

  /**
   * K Status 1 State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> kStatus1Property(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, kState1);
  }

  /**
   * K Status 2 State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> kStatus2Property(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, kState2);
  }

  /**
   * APS Status 1 State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> apsStatus1Property(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, apsState1);
  }

  /**
   * APS Status 2 State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> apsStatus2Property(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, apsState2);
  }

  /**
   * CI State Property
   * 
   * @param carIndex
   *          the car index
   * @return the ObjectPropertyBase of {@link CarComponentStatesDO} type
   */
  public final ObjectPropertyBase<CarComponentStatesDO> ciStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, ciState);
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
        boolean atleastOnePantoNotRaised = false;
        boolean allPantoRaised = false;
        TCMSProto.PantographStatusList status = TCMSProto.PantographStatusList.parseFrom(pantographStateList);
        for (PantographStatus vehicleState : status.getPantographStatusList())
        {
          if ((status.getPantographStatusList().size() == TCMSConstants.CAB_6
              && (vehicleState.getCarIndex() == TCMSConstants.CAB_1
                  || vehicleState.getCarIndex() == TCMSConstants.CAB_4))
              || ((status.getPantographStatusList().size() == TCMSConstants.CAB_8)
                  && (vehicleState.getCarIndex() == TCMSConstants.CAB_1
                      || vehicleState.getCarIndex() == TCMSConstants.CAB_3
                      || vehicleState.getCarIndex() == TCMSConstants.CAB_6)))
          {
            if ((!Objects.equals(vehicleState.getPantograhState().name(), (Pantograph.RAISED.toString()))))
            {
              atleastOnePantoNotRaised = true;
            }
            if (Objects.equals(vehicleState.getPantograhState().name(), Pantograph.LOWERED.toString()))
            {
              allPantoRaised = false;
            }
          }

          updateCarComponentStatus(vehicleState.getPantograhState().name().toLowerCase(),
              vehicleState.getCarIndex(), pantographState);
        }
        int pantoRiseState = (allPantoRaised || !atleastOnePantoNotRaised) ? 0 : 1;
       setRiseSelectedState(pantoRiseState);
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
        boolean vcbOpened = false;
        boolean vcbClosed = false;
        TCMSProto.VCBStatusList status = TCMSProto.VCBStatusList.parseFrom(vcbStateList);
        for (VCBStatus vehicleState : status.getVcbStatusList())
        {
          if ((status.getVcbStatusList().size() == TCMSConstants.CAB_6
              && (vehicleState.getCarIndex() == TCMSConstants.CAB_1
                  || vehicleState.getCarIndex() == TCMSConstants.CAB_4))
              || ((status.getVcbStatusList().size() == TCMSConstants.CAB_8)
                  && (vehicleState.getCarIndex() == TCMSConstants.CAB_1
                      || vehicleState.getCarIndex() == TCMSConstants.CAB_3
                      || vehicleState.getCarIndex() == TCMSConstants.CAB_6)))
          {
            if (Objects.equals(vehicleState.getVcbState().name(), VCBState.OPEN.toString()))
            {
              vcbOpened = true;
            }
            if (Objects.equals(vehicleState.getVcbState().name(), VCBState.CLOSED.toString()))
            {
              vcbClosed = true;
            }
          }

          setOpenVcbState(vcbOpened);
          setCloseVcbState(vcbClosed);

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

  public void setAkContactorState(byte[] akContactorStateList)
  {
    if (akContactorStateList.length != 0)
    {
      try
      {
        TCMSProto.AKContactorStatusList status = TCMSProto.AKContactorStatusList
            .parseFrom(akContactorStateList);
        for (AKContactorStatus vehicleState : status.getAkContactorStatusList())
        {
          updateCarComponentStatus(vehicleState.getAkContactorState().name().toLowerCase(),
              vehicleState.getCarIndex(), akContactorState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setKContactorState(byte[] kContactorStateList)
  {
    if (kContactorStateList.length != 0)
    {
      try
      {
        TCMSProto.KContactorStatusList status = TCMSProto.KContactorStatusList.parseFrom(kContactorStateList);
        for (KContactorStatus vehicleState : status.getKContactorStatusList())
        {
          updateCarComponentStatus(vehicleState.getKContactorState().name().toLowerCase(),
              vehicleState.getCarIndex(), kContactorState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setAkState(byte[] akStateList)
  {
    if (akStateList.length != 0)
    {
      try
      {
        TCMSProto.AKStatusList status = TCMSProto.AKStatusList.parseFrom(akStateList);
        for (AKStatus vehicleState : status.getAkStatusList())
        {
          updateCarComponentStatus(vehicleState.getAkState1().name().toLowerCase(),
              vehicleState.getCarIndex(), akState1);
          updateCarComponentStatus(vehicleState.getAkState2().name().toLowerCase(),
              vehicleState.getCarIndex(), akState2);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setKState(byte[] kStateList)
  {
    if (kStateList.length != 0)
    {
      try
      {
        TCMSProto.KStatusList status = TCMSProto.KStatusList.parseFrom(kStateList);
        for (KStatus vehicleState : status.getKStatusList())
        {
          updateCarComponentStatus(vehicleState.getKState1().name().toLowerCase(), vehicleState.getCarIndex(),
              kState1);
          updateCarComponentStatus(vehicleState.getKState2().name().toLowerCase(), vehicleState.getCarIndex(),
              kState2);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setAPSState(byte[] apsStateList)
  {
    if (apsStateList.length != 0)
    {
      try
      {
        TCMSProto.APSControlUnitStatusList status = TCMSProto.APSControlUnitStatusList
            .parseFrom(apsStateList);
        for (APSControlUnitStatus vehicleState : status.getApsControlUnitStatusList())
        {
          updateCarComponentStatus(vehicleState.getApsControlUnitState1().name().toLowerCase(),
              vehicleState.getCarIndex(), apsState1);
          updateCarComponentStatus(vehicleState.getApsControlUnitState2().name().toLowerCase(),
              vehicleState.getCarIndex(), apsState2);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setCIState(byte[] ciStateList)
  {
    if (ciStateList.length != 0)
    {
      try
      {
        TCMSProto.CIStatusList status = TCMSProto.CIStatusList.parseFrom(ciStateList);
        for (CIStatus vehicleState : status.getCIStatusList())
        {
          updateCarComponentStatus(vehicleState.getCIState().name().toLowerCase(), vehicleState.getCarIndex(),
              ciState);
        }
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public IntegerProperty getReqCtrlVcbNsStatusProperty()
  {
    return reqCtrlVcbNsStatusProperty;
  }

  public void setReqCtrlVcbNsStatusProperty(Integer reqCtrlVcbNsStatusProperty)
  {
    this.reqCtrlVcbNsStatusProperty.set(reqCtrlVcbNsStatusProperty);
  }

  public void setPantoLowAllCarstate(Integer newValue)
  {
    this.pantoLowAllCarProperty.set(newValue);

  }

  public IntegerProperty getPantoLowAllCarstate()
  {
    return pantoLowAllCarProperty;
  }

  public IntegerProperty getIsolateCiFrontCarState()
  {
    return isolateCiFrontCarProperty;
  }

  public void setIsolateCiFrontCarState(Integer newValue)
  {
    this.isolateCiFrontCarProperty.set(newValue);

  }

  public IntegerProperty getIsolateCiRearCarState()
  {
    return isolateCiRearCarProperty;
  }

  public void setIsolateCiRearCarState(Integer newValue)
  {
    this.isolateCiRearCarProperty.set(newValue);

  }

  public IntegerProperty getIsolateM1State()
  {
    return isolateCiM1Property;
  }

  public void setIsolateM1State(Integer newValue)
  {
    this.isolateCiM1Property.set(newValue);

  }

  public IntegerProperty getIsolateM2State()
  {
    return isolateCiM2Property;
  }

  public void setIsolateM2State(Integer newValue)
  {
    this.isolateCiM2Property.set(newValue);

  }

  public void setIsolateM3State(Integer newValue)
  {
    this.isolateCiM3Property.set(newValue);

  }

  public IntegerProperty getIsolateM3State()
  {
    return isolateCiM3Property;
  }

  public void setHvSelectedCarIndexList(byte[] data)
  {
    try
    {
      hVSelectedCarIndexList = HVSelectedCarIndexList.parseFrom(data);
    }
    catch (InvalidProtocolBufferException e)
    {
      hVSelectedCarIndexList = null;
      e.printStackTrace();
    }
    updateMap();
  }

  private void updateMap()
  {
    hvSelectedIndexMap.clear();
    if (hVSelectedCarIndexList != null)
    {
      for (int carIndex = 0; carIndex < hVSelectedCarIndexList.getSelectedCarIndexList().size(); carIndex++)
      {

        SelectedCarIndex page400title = hVSelectedCarIndexList.getSelectedCarIndexList().get(carIndex);

        // System.out.println("HighVoltageScreenModel.updateMap()" +
        // page400title.getCarIndex() + " panto " +
        // page400title.getPantoButtonSelected());
        this.hvSelectedIndexMap.put(page400title.getCarIndex(), page400title.getPantoButtonSelected());

      }
    }
    // System.out.println("HighVoltageScreenModel.updateMap()" +
    // hvSelectedIndexMap.size());
  }

  public MapProperty<Integer, Integer> getHvSelectedCarIndexList()
  {

    return hvSelectedIndexMap;

  }
}
