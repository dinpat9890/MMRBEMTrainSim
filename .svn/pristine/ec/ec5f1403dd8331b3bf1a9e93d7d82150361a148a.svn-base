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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AKContactorStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AKContactorStatusList.AKContactorStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DynamicBrakeStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.DynamicBrakeStatusList.DynamicBrakeStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FilterVoltageStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FilterVoltageStatusList.FilterVoltage;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.KContactorStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.KContactorStatusList.KContactorStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PropulsionEnabledStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PropulsionEnabledStatusList.PropulsionEnabledStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PropulsionStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PropulsionStatusList.PropulsionStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TractiveEffortStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TractiveEffortStatusList.TractiveEffort;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBTripCommandStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.VCBTripCommandStatusList.VCBTripCommandStatus;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.PropulsionEnabledEnum;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.data.ITableRowProperty;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataProcesser;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

public class PropulsionSystemScreenModel extends AbstractScreenModel
{
  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> statusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> valueTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser statusTableDataProcessor;

  private TableDataProcesser valueTableDataProcessor;

  private PropulsionStatusList propulsionStatusList = null;

  private PropulsionEnabledStatusList propulsionEnabledStatusList = null;

  private AKContactorStatusList akContactorStatusList = null;

  private KContactorStatusList kContactorStatusList = null;

  private DynamicBrakeStatusList dynamicBrakeStatusList = null;

  private VCBTripCommandStatusList vcbTripCommandStatusList = null;

  private FilterVoltageStatusList filterVoltageStatusList = null;

  private TractiveEffortStatusList tractiveEffortStatusList = null;

  public PropulsionSystemScreenModel(int carIndex)
  {
    super(carIndex);
    statusTableDataProcessor = new TableDataProcesser(statusTableDataList);
    valueTableDataProcessor = new TableDataProcesser(valueTableDataList);
    initializeTableData();
  }

  /**
   * Initialize table data by empty rows.
   */
  private void initializeTableData()
  {
    statusTableDataProcessor.emptyData(RowProperty.PCU_STATE, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.PROPULSION_ENABLED_STATE, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.AK_CONTACTOR_STATE, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.K_CONTACTOR_STATE, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.DYNAMIC_BRAKE_STATE, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.VCB_TRIP_COMMAND_STATE, totalColumn.get());

    valueTableDataProcessor.emptyData(RowProperty.FILTER_VOLTAGE_LABEL, totalColumn.get());
    valueTableDataProcessor.emptyData(RowProperty.FILTER_VOLTAGE_VALUE, totalColumn.get());
    valueTableDataProcessor.emptyData(RowProperty.TRACTIVE_EFFORT_LABEL, totalColumn.get());
    valueTableDataProcessor.emptyData(RowProperty.TRACTIVE_EFFORT_VALUE, totalColumn.get());

    updatePcuStatus();
    updatePropEnabledStatus();
    updateAkContactorStatus();
    updateKContactorStatus();
    updateDynamicBrakeStatus();
    updateVcbTripCommandStatus();
    updateFilterVoltageValue();
    updateTractiveEffortValue();
  }

  private void updateTractiveEffortValue()
  {
    if (tractiveEffortStatusList != null)
    {
      valueTableDataProcessor.emptyData(RowProperty.TRACTIVE_EFFORT_LABEL, totalColumn.get());
      valueTableDataProcessor.emptyData(RowProperty.TRACTIVE_EFFORT_VALUE, totalColumn.get());
      for (TractiveEffort statusTableDO : tractiveEffortStatusList.getTractiveEffortList())
      {
        int tractiveEffortValue = statusTableDO.getTractiveEffort();

        valueTableDataProcessor.updateData(RowProperty.TRACTIVE_EFFORT_LABEL, statusTableDO.getCarIndex(),
            false,
            tractiveEffortValue == ApplicationConstants.VALUE_NOT_APPLICABLE ? TCMSUIConstants.BLANK_STRING
                : RowProperty.TRACTIVE_EFFORT_LABEL.getRowName(),
            TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
        valueTableDataProcessor.updateData(RowProperty.TRACTIVE_EFFORT_VALUE, statusTableDO.getCarIndex(),
            false,
            tractiveEffortValue == ApplicationConstants.VALUE_NOT_APPLICABLE ? TCMSUIConstants.BLANK_STRING
                : String.valueOf(tractiveEffortValue),
            TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateFilterVoltageValue()
  {
    if (filterVoltageStatusList != null)
    {
      valueTableDataProcessor.emptyData(RowProperty.FILTER_VOLTAGE_LABEL, totalColumn.get());
      valueTableDataProcessor.emptyData(RowProperty.FILTER_VOLTAGE_VALUE, totalColumn.get());
      for (FilterVoltage statusTableDO : filterVoltageStatusList.getFilterVoltageList())
      {
        int filterVoltValue = statusTableDO.getFilterVoltage();

        valueTableDataProcessor.updateData(RowProperty.FILTER_VOLTAGE_LABEL, statusTableDO.getCarIndex(),
            false,
            filterVoltValue == ApplicationConstants.VALUE_NOT_APPLICABLE ? TCMSUIConstants.BLANK_STRING
                : RowProperty.FILTER_VOLTAGE_LABEL.getRowName(),
            TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
        valueTableDataProcessor.updateData(RowProperty.FILTER_VOLTAGE_VALUE, statusTableDO.getCarIndex(),
            false,
            filterVoltValue == ApplicationConstants.VALUE_NOT_APPLICABLE ? TCMSUIConstants.BLANK_STRING
                : String.valueOf(filterVoltValue),
            TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }

  }

  private void updateVcbTripCommandStatus()
  {
    if (vcbTripCommandStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.VCB_TRIP_COMMAND_STATE, totalColumn.get());
      for (VCBTripCommandStatus statusTableDO : vcbTripCommandStatusList.getVcbTripCommandStatusList())
      {
        statusTableDataProcessor.updateData(RowProperty.VCB_TRIP_COMMAND_STATE, statusTableDO.getCarIndex(),
            false, RowProperty.VCB_TRIP_COMMAND_STATE.getRowName(),
            statusTableDO.getVcbTripCommandState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateDynamicBrakeStatus()
  {
    if (dynamicBrakeStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.DYNAMIC_BRAKE_STATE, totalColumn.get());
      for (DynamicBrakeStatus statusTableDO : dynamicBrakeStatusList.getDynamicBrakeStatusList())
      {
        statusTableDataProcessor.updateData(RowProperty.DYNAMIC_BRAKE_STATE, statusTableDO.getCarIndex(),
            false, RowProperty.DYNAMIC_BRAKE_STATE.getRowName(),
            statusTableDO.getDynamicBrakeState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateKContactorStatus()
  {
    if (kContactorStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.K_CONTACTOR_STATE, totalColumn.get());
      for (KContactorStatus statusTableDO : kContactorStatusList.getKContactorStatusList())
      {
        statusTableDataProcessor.updateData(RowProperty.K_CONTACTOR_STATE, statusTableDO.getCarIndex(), false,
            RowProperty.K_CONTACTOR_STATE.getRowName(),
            statusTableDO.getKContactorState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateAkContactorStatus()
  {
    if (akContactorStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.AK_CONTACTOR_STATE, totalColumn.get());
      for (AKContactorStatus statusTableDO : akContactorStatusList.getAkContactorStatusList())
      {
        statusTableDataProcessor.updateData(RowProperty.AK_CONTACTOR_STATE, statusTableDO.getCarIndex(),
            false, RowProperty.AK_CONTACTOR_STATE.getRowName(),
            statusTableDO.getAkContactorState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updatePropEnabledStatus()
  {
    if (propulsionEnabledStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.PROPULSION_ENABLED_STATE, totalColumn.get());
      for (PropulsionEnabledStatus statusTableDO : propulsionEnabledStatusList
          .getPropulsionEnabledStatusList())
      {
        PropulsionEnabledEnum propulsionEnabledEnum = PropulsionEnabledEnum
            .valueOf(statusTableDO.getPropulsionEnabledState().getNumber());
        statusTableDataProcessor.updateData(RowProperty.PROPULSION_ENABLED_STATE, statusTableDO.getCarIndex(),
            false, propulsionEnabledEnum.getState(), propulsionEnabledEnum.name().toLowerCase(),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updatePcuStatus()
  {
    if (propulsionStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.PCU_STATE, totalColumn.get());
      for (PropulsionStatus statusTableDO : propulsionStatusList.getPropulsionStatusList())
      {
        statusTableDataProcessor.updateData(RowProperty.PCU_STATE, statusTableDO.getCarIndex(), false,
            TCMSUIConstants.BLANK_STRING, statusTableDO.getPropulsionState().name().toLowerCase(),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  public IntegerProperty getTotalColumn()
  {
    return totalColumn;
  }

  public void setTotalColumn(int totalColumn)
  {
    this.totalColumn.set(totalColumn);
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getStatusTableDataList()
  {
    return statusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getValueTableDataList()
  {
    return valueTableDataList;
  }

  /**
   * Enum to hold the rows for BRAKE status table with its name and unit and
   * cell alignment.
   */
  private enum RowProperty implements ITableRowProperty
  {
    PCU_STATE(0, "", LEFT), PROPULSION_ENABLED_STATE(1, "Prop Enabled", CENTER), AK_CONTACTOR_STATE(2, //$NON-NLS-1$ //$NON-NLS-2$
        "AK ON", CENTER), K_CONTACTOR_STATE(3, "K ON", CENTER), DYNAMIC_BRAKE_STATE(4, "ED Brake", //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
            CENTER), VCB_TRIP_COMMAND_STATE(5, "VCB trip", CENTER), FILTER_VOLTAGE_LABEL(0, "Filter volt", //$NON-NLS-1$ //$NON-NLS-2$
                CENTER), FILTER_VOLTAGE_VALUE(1, "Filter volt", CENTER), TRACTIVE_EFFORT_LABEL(2, //$NON-NLS-1$
                    "Tractive Effort", CENTER), TRACTIVE_EFFORT_VALUE(3, "Tractive Effort", CENTER); //$NON-NLS-1$ //$NON-NLS-2$

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

  public void setPropulsionState(byte[] propulsionStateList)
  {
    if (propulsionStateList.length != 0)
    {
      try
      {
        propulsionStatusList = TCMSProto.PropulsionStatusList.parseFrom(propulsionStateList);
        updatePcuStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setPropulsionEnabledStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        propulsionEnabledStatusList = TCMSProto.PropulsionEnabledStatusList.parseFrom(newValue);
        updatePropEnabledStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setAkContactorStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        akContactorStatusList = TCMSProto.AKContactorStatusList.parseFrom(newValue);
        updateAkContactorStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setKContactorStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        kContactorStatusList = TCMSProto.KContactorStatusList.parseFrom(newValue);
        updateKContactorStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setVcbTripCommandStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        vcbTripCommandStatusList = TCMSProto.VCBTripCommandStatusList.parseFrom(newValue);
        updateVcbTripCommandStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setDynamicBrakeStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        dynamicBrakeStatusList = TCMSProto.DynamicBrakeStatusList.parseFrom(newValue);
        updateDynamicBrakeStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setFilterVoltageStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        filterVoltageStatusList = TCMSProto.FilterVoltageStatusList.parseFrom(newValue);
        updateFilterVoltageValue();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setTractiveEffortStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        tractiveEffortStatusList = TCMSProto.TractiveEffortStatusList.parseFrom(newValue);
        updateTractiveEffortValue();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }
}
