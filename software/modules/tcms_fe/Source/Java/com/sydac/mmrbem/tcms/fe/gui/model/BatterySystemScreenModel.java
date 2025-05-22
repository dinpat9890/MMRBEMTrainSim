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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BCGOutputVoltageStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BCGOutputVoltageStatusList.BCGOutputVoltage;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BCGStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BCGStatusList.BCGStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryCurrentStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryCurrentStatusList.BatteryCurrent;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryTemperatureStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryTemperatureStatusList.BatteryTemperature;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryVoltageStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BatteryVoltageStatusList.BatteryVoltage;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.OutputCurrentStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.OutputCurrentStatusList.OutputCurrent;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TotalOutputCurrentStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TotalOutputCurrentStatusList.TotalOutputCurrent;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
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

public class BatterySystemScreenModel extends AbstractScreenModel
{

  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> bcgStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> bcgOutputVoltageStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> batteryVoltageStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> outputCurrentStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> totalOutputCurrentStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> batteryCurrentStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> batteryTemperatureStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private IntegerProperty opScreenBatteryVoltage = new SimpleIntegerProperty();

  private TableDataProcesser bcgStatusTableDataProcessor;

  private TableDataProcesser bcgOutputVoltageStatusTableDataProcessor;

  private TableDataProcesser batteryVoltageStatusTableDataProcessor;

  private TableDataProcesser outputCurrentStatusTableDataProcessor;

  private TableDataProcesser totalOutputCurrentStatusTableDataProcessor;

  private TableDataProcesser batteryCurrentStatusTableDataProcessor;

  private TableDataProcesser batteryTemperatureStatusTableDataProcessor;

  private BCGStatusList bcgStatusList = null;

  private BCGOutputVoltageStatusList bcgOutputVoltageStatusList = null;

  private BatteryVoltageStatusList batteryVoltageStatusList = null;

  private OutputCurrentStatusList outputCurrentStatusList = null;

  private TotalOutputCurrentStatusList totalOutputCurrentStatusList = null;

  private BatteryCurrentStatusList batteryCurrentStatusList = null;

  private BatteryTemperatureStatusList batteryTemperatureStatusList = null;

  public BatterySystemScreenModel(int carIndex)
  {
    super(carIndex);
    bcgStatusTableDataProcessor = new TableDataProcesser(bcgStatusTableDataList);
    bcgOutputVoltageStatusTableDataProcessor = new TableDataProcesser(bcgOutputVoltageStatusTableDataList);
    batteryVoltageStatusTableDataProcessor = new TableDataProcesser(batteryVoltageStatusTableDataList);
    outputCurrentStatusTableDataProcessor = new TableDataProcesser(outputCurrentStatusTableDataList);
    totalOutputCurrentStatusTableDataProcessor = new TableDataProcesser(
        totalOutputCurrentStatusTableDataList);
    batteryCurrentStatusTableDataProcessor = new TableDataProcesser(batteryCurrentStatusTableDataList);
    batteryTemperatureStatusTableDataProcessor = new TableDataProcesser(
        batteryTemperatureStatusTableDataList);
    initializeTableData();
  }

  /**
   * Initialize table data by empty rows.
   */
  private void initializeTableData()
  {
    bcgStatusTableDataProcessor.emptyData(RowProperty.BCG_STATUS, totalColumn.get());
    bcgOutputVoltageStatusTableDataProcessor.emptyData(RowProperty.BCG_OUTPUT_VOLTAGE_STATUS,
        totalColumn.get());
    batteryVoltageStatusTableDataProcessor.emptyData(RowProperty.BATTERY_VOLTAGE_STATUS, totalColumn.get());
    outputCurrentStatusTableDataProcessor.emptyData(RowProperty.OUTPUT_CURRENT_STATUS, totalColumn.get());
    totalOutputCurrentStatusTableDataProcessor.emptyData(RowProperty.TOTAL_OUTPUT_CURRENT_STATUS,
        totalColumn.get());
    batteryCurrentStatusTableDataProcessor.emptyData(RowProperty.BATTERY_CURRENT_STATUS, totalColumn.get());
    batteryTemperatureStatusTableDataProcessor.emptyData(RowProperty.BATTERY_TEMPERATURE_STATUS,
        totalColumn.get());

    updateBcgStatus();
    updateBcgOutputVoltageStatus();
    updateBatteryVoltageStatus();
    updateOutputCurrentStatus();
    updateTotalOutputCurrentStatus();
    updateBatteryCurrentStatus();
    updateBatteryTemperatureStatus();
  }

  private void updateBcgStatus()
  {
    if (bcgStatusList != null)
    {
      bcgStatusTableDataProcessor.emptyData(RowProperty.BCG_STATUS, totalColumn.get());
      for (BCGStatus statusTableDO : bcgStatusList.getBcgStatusList())
      {
        bcgStatusTableDataProcessor.updateData(RowProperty.BCG_STATUS, statusTableDO.getCarIndex(), true,
            TCMSUIConstants.BCG_STATUS_LABEL_1, statusTableDO.getBcgState1().toString().toLowerCase(),
            TCMSUIConstants.BCG_STATUS_LABEL_2, statusTableDO.getBcgState2().toString().toLowerCase());
      }
    }
  }

  private void updateBcgOutputVoltageStatus()
  {
    if (bcgOutputVoltageStatusList != null)
    {
      bcgOutputVoltageStatusTableDataProcessor.emptyData(RowProperty.BCG_OUTPUT_VOLTAGE_STATUS,
          totalColumn.get());
      for (BCGOutputVoltage statusTableDO : bcgOutputVoltageStatusList.getBcgOutputVoltageList())
      {
        if (statusTableDO.getBcgOutputVoltage() != ApplicationConstants.VALUE_NOT_APPLICABLE)
        {
          bcgOutputVoltageStatusTableDataProcessor.updateData(RowProperty.BCG_OUTPUT_VOLTAGE_STATUS,
              statusTableDO.getCarIndex(), false,
              String.valueOf(statusTableDO.getBcgOutputVoltage()).concat(" V"), //$NON-NLS-1$
              TCMSUIConstants.BATTERY_SCREEN_LABEL_1_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          bcgOutputVoltageStatusTableDataProcessor.updateData(RowProperty.BCG_OUTPUT_VOLTAGE_STATUS,
              statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateBatteryVoltageStatus()
  {
    if (batteryVoltageStatusList != null)
    {
      batteryVoltageStatusTableDataProcessor.emptyData(RowProperty.BATTERY_VOLTAGE_STATUS, totalColumn.get());
      for (BatteryVoltage statusTableDO : batteryVoltageStatusList.getBatteryVoltageList())
      {
        batteryVoltageStatusTableDataProcessor.updateData(RowProperty.BATTERY_VOLTAGE_STATUS,
            statusTableDO.getCarIndex(), false,
            String.valueOf(statusTableDO.getBatteryVoltage()).concat(" V"), //$NON-NLS-1$
            TCMSUIConstants.BATTERY_SCREEN_LABEL_2_CSS, TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);

        if (statusTableDO.getCarIndex() == 2)
        {
          setOpScreenBatteryVoltage(statusTableDO.getBatteryVoltage());
        }
      }
    }
  }

  private void updateOutputCurrentStatus()
  {
    if (outputCurrentStatusList != null)
    {
      outputCurrentStatusTableDataProcessor.emptyData(RowProperty.OUTPUT_CURRENT_STATUS, totalColumn.get());
      for (OutputCurrent statusTableDO : outputCurrentStatusList.getOutputCurrentList())
      {
        if (statusTableDO.getOutputCurrent1() != ApplicationConstants.VALUE_NOT_APPLICABLE
            && statusTableDO.getOutputCurrent2() != ApplicationConstants.VALUE_NOT_APPLICABLE)
        {
          outputCurrentStatusTableDataProcessor.updateData(RowProperty.OUTPUT_CURRENT_STATUS,
              statusTableDO.getCarIndex(), true,
              String.valueOf(statusTableDO.getOutputCurrent1()).concat(" A"), //$NON-NLS-1$
              TCMSUIConstants.BATTERY_SCREEN_LABEL_3_CSS,
              String.valueOf(statusTableDO.getOutputCurrent2()).concat(" A"), //$NON-NLS-1$
              TCMSUIConstants.BATTERY_SCREEN_LABEL_3_CSS);
        }
        else
        {
          outputCurrentStatusTableDataProcessor.updateData(RowProperty.OUTPUT_CURRENT_STATUS,
              statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateTotalOutputCurrentStatus()
  {
    if (totalOutputCurrentStatusList != null)
    {
      totalOutputCurrentStatusTableDataProcessor.emptyData(RowProperty.TOTAL_OUTPUT_CURRENT_STATUS,
          totalColumn.get());
      for (TotalOutputCurrent statusTableDO : totalOutputCurrentStatusList.getTotalOutputCurrentList())
      {
        if (statusTableDO.getTotalOutputCurrent() != ApplicationConstants.VALUE_NOT_APPLICABLE)
        {
          totalOutputCurrentStatusTableDataProcessor.updateData(RowProperty.TOTAL_OUTPUT_CURRENT_STATUS,
              statusTableDO.getCarIndex(), false,
              String.valueOf(statusTableDO.getTotalOutputCurrent()).concat("A"), //$NON-NLS-1$
              TCMSUIConstants.BATTERY_SCREEN_LABEL_2_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          totalOutputCurrentStatusTableDataProcessor.updateData(RowProperty.TOTAL_OUTPUT_CURRENT_STATUS,
              statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateBatteryCurrentStatus()
  {
    if (batteryCurrentStatusList != null)
    {
      batteryCurrentStatusTableDataProcessor.emptyData(RowProperty.BATTERY_CURRENT_STATUS, totalColumn.get());
      for (BatteryCurrent statusTableDO : batteryCurrentStatusList.getBatteryCurrentList())
      {
        if (statusTableDO.getBatteryCurrent() != ApplicationConstants.VALUE_NOT_APPLICABLE)
        {
          batteryCurrentStatusTableDataProcessor.updateData(RowProperty.BATTERY_CURRENT_STATUS,
              statusTableDO.getCarIndex(), false,
              String.valueOf(statusTableDO.getBatteryCurrent()).concat(" A"), //$NON-NLS-1$
              TCMSUIConstants.BATTERY_SCREEN_LABEL_4_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          batteryCurrentStatusTableDataProcessor.updateData(RowProperty.BATTERY_CURRENT_STATUS,
              statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateBatteryTemperatureStatus()
  {
    if (batteryTemperatureStatusList != null)
    {
      batteryTemperatureStatusTableDataProcessor.emptyData(RowProperty.BATTERY_TEMPERATURE_STATUS,
          totalColumn.get());
      for (BatteryTemperature statusTableDO : batteryTemperatureStatusList.getBatteryTemperatureList())
      {
        if (statusTableDO.getBatteryTemperature() != ApplicationConstants.VALUE_NOT_APPLICABLE)
        {
          batteryTemperatureStatusTableDataProcessor.updateData(RowProperty.BATTERY_TEMPERATURE_STATUS,
              statusTableDO.getCarIndex(), false,
              String.valueOf(statusTableDO.getBatteryTemperature()).concat("\u00B0" + "C"), //$NON-NLS-1$//$NON-NLS-2$
              TCMSUIConstants.BATTERY_SCREEN_LABEL_4_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          batteryTemperatureStatusTableDataProcessor.updateData(RowProperty.BATTERY_TEMPERATURE_STATUS,
              statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  public IntegerProperty getTotalColumn()
  {
    return totalColumn;
  }

  public void setTotalColumn(Integer totalColumn)
  {
    this.totalColumn.set(totalColumn);
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getBcgStatusTableDataList()
  {
    return bcgStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getBcgOutputVoltageStatusTableDataList()
  {
    return bcgOutputVoltageStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getBatteryVoltageStatusTableDataList()
  {
    return batteryVoltageStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getOutputCurrentStatusTableDataList()
  {
    return outputCurrentStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getTotalOutputCurrentStatusTableDataList()
  {
    return totalOutputCurrentStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getBatteryCurrentStatusTableDataList()
  {
    return batteryCurrentStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getBatteryTemperatureStatusTableDataList()
  {
    return batteryTemperatureStatusTableDataList;
  }

  public void setBcgStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        bcgStatusList = TCMSProto.BCGStatusList.parseFrom(newValue);
        updateBcgStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setBcgOutputVoltageStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        bcgOutputVoltageStatusList = TCMSProto.BCGOutputVoltageStatusList.parseFrom(newValue);
        updateBcgOutputVoltageStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setOutputCurrentStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        outputCurrentStatusList = TCMSProto.OutputCurrentStatusList.parseFrom(newValue);
        updateOutputCurrentStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setTotalOutputCurrentStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        totalOutputCurrentStatusList = TCMSProto.TotalOutputCurrentStatusList.parseFrom(newValue);
        updateTotalOutputCurrentStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setBatteryCurrentStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        batteryCurrentStatusList = TCMSProto.BatteryCurrentStatusList.parseFrom(newValue);
        updateBatteryCurrentStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setBatteryTemperatureStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        batteryTemperatureStatusList = TCMSProto.BatteryTemperatureStatusList.parseFrom(newValue);
        updateBatteryTemperatureStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setBatteryVoltageStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        batteryVoltageStatusList = TCMSProto.BatteryVoltageStatusList.parseFrom(newValue);
        updateBatteryVoltageStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public IntegerProperty getOpScreenBatteryVoltage()
  {
    return opScreenBatteryVoltage;
  }

  public void setOpScreenBatteryVoltage(Integer opScreenBatteryVoltage)
  {
    this.opScreenBatteryVoltage.set(opScreenBatteryVoltage);
  }

  /**
   * Enum to hold the rows for Battery status table with its name and unit and
   * cell alignment.
   */
  private enum RowProperty implements ITableRowProperty
  {
    BCG_STATUS(0, "", CENTER), //$NON-NLS-1$
    BCG_OUTPUT_VOLTAGE_STATUS(0, "", CENTER), //$NON-NLS-1$
    BATTERY_VOLTAGE_STATUS(0, "", CENTER), //$NON-NLS-1$
    OUTPUT_CURRENT_STATUS(0, "", CENTER), //$NON-NLS-1$
    TOTAL_OUTPUT_CURRENT_STATUS(0, "", CENTER), //$NON-NLS-1$
    BATTERY_CURRENT_STATUS(0, "", CENTER), //$NON-NLS-1$
    BATTERY_TEMPERATURE_STATUS(0, "", CENTER); //$NON-NLS-1$

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

}
