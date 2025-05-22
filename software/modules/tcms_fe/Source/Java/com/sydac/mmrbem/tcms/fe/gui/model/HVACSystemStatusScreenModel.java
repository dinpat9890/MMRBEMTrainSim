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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVACControlModeStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVACControlModeStatusList.HVACControlStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVACOperationModeStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVACOperationModeStatusList.HVACOperatingStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVSelectedCarIndexList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HVSelectedCarIndexList.SelectedCarIndex;
import com.sydac.mmrbem.tcms.common.state.HVACConstantsEnum;
import com.sydac.mmrbem.tcms.common.state.HVACControlEnum;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.data.ITableRowProperty;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataProcesser;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.MapProperty;
import javafx.beans.property.ObjectProperty;
import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.beans.property.SimpleMapProperty;
import javafx.collections.FXCollections;

public class HVACSystemStatusScreenModel extends AbstractScreenModel
{

  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> hvacStatusOneTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> hvacStatusTwoTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser statusOneTableDataProcessor;

  private TableDataProcesser statusTwoTableDataProcessor;

  private HVACOperationModeStatusList hvacOperationModeStatusListOne = null;

  private HVACOperationModeStatusList hvacOperationModeStatusListTwo = null;

  private HVACControlModeStatusList hvacControlModeStatusListOne = null;

  private HVACControlModeStatusList hvacControlModeStatusListTwo = null;

  private IntegerProperty isolateHvac1 = new SimpleIntegerProperty();

  private IntegerProperty isolateHvac2 = new SimpleIntegerProperty();

 

  private ListProperty<CarComponentObjectProperty> hvac1IsolateState = new SimpleListProperty<>(
      FXCollections.observableArrayList());
  private ListProperty<CarComponentObjectProperty> hvac2IsolateState = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  public HVACSystemStatusScreenModel(int carIndex)
  {
    super(carIndex);
    statusOneTableDataProcessor = new TableDataProcesser(hvacStatusOneTableDataList);
    statusTwoTableDataProcessor = new TableDataProcesser(hvacStatusTwoTableDataList);

    initializeTableData();
  }

  private void initializeTableData()
  {
    statusOneTableDataProcessor.emptyData(RowProperty.HVAC_OPERATING_MODE_STATUS_1, totalColumn.get());
    statusOneTableDataProcessor.emptyData(RowProperty.BLANK_ROW_1, totalColumn.get());

    statusOneTableDataProcessor.emptyData(RowProperty.HVAC_CONTROL_MODE_STATUS_1, totalColumn.get());

    statusTwoTableDataProcessor.emptyData(RowProperty.HVAC_OPERATING_MODE_STATUS_2, totalColumn.get());
    statusTwoTableDataProcessor.emptyData(RowProperty.BLANK_ROW_2, totalColumn.get());
    statusTwoTableDataProcessor.emptyData(RowProperty.HVAC_CONTROL_MODE_STATUS_2, totalColumn.get());

    updateOperatingModeStatusOne();
    updateControlModeStatusOne();

    updateOperatingModeStatusTwo();
    updateControlModeStatusTwo();
  }

  private void updateOperatingModeStatusOne()
  {
    if (hvacOperationModeStatusListOne != null)
    {
      statusOneTableDataProcessor.emptyData(RowProperty.HVAC_OPERATING_MODE_STATUS_1, totalColumn.get());
      for (HVACOperatingStatus statusTableDO : hvacOperationModeStatusListOne.getHvacOperatingStatusList())
      {
        statusOneTableDataProcessor.updateData(RowProperty.HVAC_OPERATING_MODE_STATUS_1,
            statusTableDO.getCarIndex(), false,
            HVACConstantsEnum.valueOf(statusTableDO.getHvacOperatingState().getNumber()).getName(),
            HVACConstantsEnum.valueOf(statusTableDO.getHvacOperatingState().getNumber()).getState(),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);

        updateCarComponentStatus(statusTableDO.getHvacOperatingState().name(), statusTableDO.getCarIndex(),
            hvac1IsolateState);
      }
    }
  }

  private void updateControlModeStatusOne()
  {
    if (hvacControlModeStatusListOne != null)
    {
      statusOneTableDataProcessor.emptyData(RowProperty.HVAC_CONTROL_MODE_STATUS_1, totalColumn.get());
      for (HVACControlStatus statusTableDO : hvacControlModeStatusListOne.getHvacControlStatusList())
      {
        // Note ,as discuused keeping Control mode as static but proto and comms
        // varaible is ready
        statusOneTableDataProcessor.updateData(RowProperty.HVAC_CONTROL_MODE_STATUS_1,
            statusTableDO.getCarIndex(), false,
            HVACControlEnum.valueOf(statusTableDO.getHvacControlState().getNumber()).getName(),
            HVACControlEnum.valueOf(statusTableDO.getHvacControlState().getNumber()).getState(),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);

      }
    }
  }

  private void updateOperatingModeStatusTwo()
  {

    if (hvacOperationModeStatusListTwo != null)
    {
      statusTwoTableDataProcessor.emptyData(RowProperty.HVAC_OPERATING_MODE_STATUS_2, totalColumn.get());
      for (HVACOperatingStatus statusTableDO : hvacOperationModeStatusListTwo.getHvacOperatingStatusList())
      {
        statusTwoTableDataProcessor.updateData(RowProperty.HVAC_OPERATING_MODE_STATUS_2,
            statusTableDO.getCarIndex(), false,
            HVACConstantsEnum.valueOf(statusTableDO.getHvacOperatingState().getNumber()).getName(),
            HVACConstantsEnum.valueOf(statusTableDO.getHvacOperatingState().getNumber()).getState(),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        
        updateCarComponentStatus(statusTableDO.getHvacOperatingState().name(), statusTableDO.getCarIndex(),
            hvac2IsolateState);
      }
    }
  }

  private void updateControlModeStatusTwo()
  {
    if (hvacControlModeStatusListTwo != null)
    {
      statusTwoTableDataProcessor.emptyData(RowProperty.HVAC_CONTROL_MODE_STATUS_2, totalColumn.get());
      for (HVACControlStatus statusTableDO : hvacControlModeStatusListTwo.getHvacControlStatusList())
      {
        // Note ,as discuused keeping Control mode as static but proto and comms
        // varaible is ready
        statusTwoTableDataProcessor.updateData(RowProperty.HVAC_CONTROL_MODE_STATUS_2,
            statusTableDO.getCarIndex(), false,
            HVACControlEnum.valueOf(statusTableDO.getHvacControlState().getNumber()).getName(),
            HVACControlEnum.valueOf(statusTableDO.getHvacControlState().getNumber()).getState(),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  /**
   * Getter and setter for total column in our screen
   * 
   * @return total column
   **/
  public IntegerProperty getTotalColumn()
  {
    return totalColumn;
  }

  public void setTotalColumn(Integer totalColumn)
  {
    this.totalColumn.set(totalColumn);
  }

  /***
   * Gets the sensor table data list.@return the status table data list
   * 
   * @return List HVAC Status list
   ***/
  public ListProperty<StatusTableDO> getHvacStatusOneTableDataList()
  {
    return hvacStatusOneTableDataList;
  }

  public ListProperty<StatusTableDO> getHvacStatusTwoTableDataList()
  {
    return hvacStatusTwoTableDataList;
  }

  /**
   * Enum to hold the rows for HVAC status table with its tempreature and cell
   * alignment.
   ***/
  private enum RowProperty implements ITableRowProperty
  {
    HVAC_OPERATING_MODE_STATUS_1(0, "", CENTER), //$NON-NLS-1$
    BLANK_ROW_1(1, " ", CENTER), // $NON-NLS-2$
    HVAC_CONTROL_MODE_STATUS_1(2, "", CENTER), //$NON-NLS-1$

    HVAC_OPERATING_MODE_STATUS_2(0, "", CENTER), //$NON-NLS-1$
    BLANK_ROW_2(1, " ", CENTER), //$NON-NLS-1$
    HVAC_CONTROL_MODE_STATUS_2(2, "", CENTER); //$NON-NLS-1$

    private int value;

    private String rowName;

    private String rowTextAlignment;

    /**
     * Instantiates a new row property.
     *
     * @param value
     *          the row index
     * @param name
     *          the row name
     * @param rowTextAlignment
     *          the row text alignment
     */
    private RowProperty(int value, String name, String rowTextAlignment)
    {
      this.value = value;
      this.rowName = name;
      this.rowTextAlignment = rowTextAlignment;
    }

    @Override
    public int getIndex()
    {
      return this.value;
    }

    @Override
    public String getRowName()
    {
      return this.rowName;
    }

    @Override
    public String getRowTextAlignment()
    {
      return this.rowTextAlignment;
    }
  }

  public void setHvacOperationModeStatusListOne(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        hvacOperationModeStatusListOne = TCMSProto.HVACOperationModeStatusList.parseFrom(newValue);
        updateOperatingModeStatusOne();

      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setHvacOperationModeStatusListTwo(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        hvacOperationModeStatusListTwo = TCMSProto.HVACOperationModeStatusList.parseFrom(newValue);
        updateOperatingModeStatusTwo();

      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setHvacControlModeStatusListOne(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        hvacControlModeStatusListOne = TCMSProto.HVACControlModeStatusList.parseFrom(newValue);
        updateControlModeStatusOne();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public void setHvacControlModeStatusListTwo(byte[] newValue)
  {

    if (newValue.length != 0)
    {
      try
      {
        hvacControlModeStatusListTwo = TCMSProto.HVACControlModeStatusList.parseFrom(newValue);
        updateControlModeStatusTwo();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }

  }

  public void setIsolateHvac1State(Integer newValue)
  {
    this.isolateHvac1.set(newValue);

  }

  public void setIsolateHvac2State(Integer newValue)
  {
    this.isolateHvac2.set(newValue);

  }

  public IntegerProperty getIsolateHvac1State()
  {
    return isolateHvac1;
  }

  public IntegerProperty getIsolateHvac2State()
  {
    return isolateHvac2;
  }

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

  public final ObjectPropertyBase<CarComponentStatesDO> hvac1IsolateStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, hvac1IsolateState);
  }
  
  public final ObjectPropertyBase<CarComponentStatesDO> hvac2IsolateStatusProperty(int carIndex)
  {
    return getCarComponentPropertyFor(carIndex, hvac2IsolateState);
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

 
  
  
  
}
