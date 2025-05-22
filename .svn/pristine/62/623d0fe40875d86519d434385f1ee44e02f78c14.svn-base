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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FDUFaultStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FDUFaultStatusList.FDUFaultStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSensorAlarmStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSensorAlarmStatusList.FireSensorAlarmStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSensorDisabledStatusList.FireSensorDisabledState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSensorFaultStatusList.FireSensorFaultState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSystemWiredLineStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSystemWiredLineStatusList.FireSystemWireLineState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FireSystemWiredLineStatusList.FireSystemWiredLineStatus;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
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

public class FireDetectionSystemScreenModel extends AbstractScreenModel
{

  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> sensorStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> wiredStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> fduSystemFaultStatusDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser sensorStatusTableDataProcessor;

  private TableDataProcesser wiredStatusTableDataProcessor;

  private TableDataProcesser fduSystemTableDataProcessor;

  private FDUFaultStatusList fduFaultStatusList;

  private FireSensorAlarmStatusList fireSensorAlarmStatusList = null;

  private FireSystemWiredLineStatusList externalSmokeStatusList = null;

  private FireSystemWiredLineStatusList ufarStatusList = null;

  private FireSystemWiredLineStatusList internalFireStatusList = null;

  private FireSystemWiredLineStatusList sfarStatusList = null;

  public FireDetectionSystemScreenModel(int carIndex)
  {
    super(carIndex);
    sensorStatusTableDataProcessor = new TableDataProcesser(sensorStatusTableDataList);
    wiredStatusTableDataProcessor = new TableDataProcesser(wiredStatusTableDataList);
    fduSystemTableDataProcessor = new TableDataProcesser(fduSystemFaultStatusDataList);

    initializeTableData();
  }

  private void initializeTableData()
  {
    sensorStatusTableDataProcessor.emptyData(RowProperty.FIRE_DETECTION_SENSOR_FAULT_STATE,
        totalColumn.get());
    sensorStatusTableDataProcessor.emptyData(RowProperty.FIRE_DETECTION_SENSOR_ALARM, totalColumn.get());
    sensorStatusTableDataProcessor.emptyData(RowProperty.FIRE_DETECTION_SENSOR_DISABLED_STATE,
        totalColumn.get());

    wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_EXIT_SMOKE, totalColumn.get());
    wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_UNDER_FRAME_FIRE, totalColumn.get());
    wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_UFAR, totalColumn.get());
    wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_INTERNAL_FIRE, totalColumn.get());
    wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_SFAR, totalColumn.get());

    fduSystemTableDataProcessor.emptyData(RowProperty.FDU_SYSTEM_FAULT_STATUS, totalColumn.get());

    updateFDUSystemFaultStatus();
    updateFireSensorFaultStatus();
    updateFireSensorAlarmStatus();
    updateFireSensorDisabledStatus();

    updateWiredLineSFARStatusTable();
    updateWiredLineExtSmokeStatusTable();
    updateWiredLineInternalFireStatusTable();
    updateWiredLineUFARStatusTable();
    updateWiredLineUnderframeFireStatusTable();
  }

  private void updateFireSensorDisabledStatus()
  {
    if (totalColumn.get() != 0)
    {
      sensorStatusTableDataProcessor.emptyData(RowProperty.FIRE_DETECTION_SENSOR_DISABLED_STATE,
          totalColumn.get());

      for (int carIndex = 1; carIndex <= totalColumn.get(); carIndex++)
      {
        sensorStatusTableDataProcessor.updateData(RowProperty.FIRE_DETECTION_SENSOR_DISABLED_STATE, carIndex,
            false, RowProperty.FIRE_DETECTION_SENSOR_DISABLED_STATE.getRowName(),
            FireSensorDisabledState.FIRE_SENSOR_DISABLED_NOT_DISABLED.toString().toLowerCase(),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateFireSensorAlarmStatus()
  {
    if (fireSensorAlarmStatusList != null)
    {
      sensorStatusTableDataProcessor.emptyData(RowProperty.FIRE_DETECTION_SENSOR_ALARM, totalColumn.get());

      for (FireSensorAlarmStatus statusTableDO : fireSensorAlarmStatusList.getFireSensorAlarmStatusList())
      {
        sensorStatusTableDataProcessor.updateData(RowProperty.FIRE_DETECTION_SENSOR_ALARM,
            statusTableDO.getCarIndex(), false, RowProperty.FIRE_DETECTION_SENSOR_ALARM.getRowName(),
            statusTableDO.getFireSensorAlarmState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateFireSensorFaultStatus()
  {
    if (totalColumn.get() != 0)
    {
      sensorStatusTableDataProcessor.emptyData(RowProperty.FIRE_DETECTION_SENSOR_FAULT_STATE,
          totalColumn.get());

      for (int carIndex = 0; carIndex < totalColumn.get(); carIndex++)
      {
        sensorStatusTableDataProcessor.updateData(RowProperty.FIRE_DETECTION_SENSOR_FAULT_STATE, carIndex,
            false, RowProperty.FIRE_DETECTION_SENSOR_FAULT_STATE.getRowName(),
            FireSensorFaultState.FIRE_SENSOR_FAULT_NOT_FAULTY.toString().toLowerCase(),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateFDUSystemFaultStatus()
  {
    if (fduFaultStatusList != null)
    {
      fduSystemTableDataProcessor.emptyData(RowProperty.FDU_SYSTEM_FAULT_STATUS, totalColumn.get());

      for (FDUFaultStatus statusTableDO : fduFaultStatusList.getFduFaultStatusList())
      {
        fduSystemTableDataProcessor.updateData(RowProperty.FDU_SYSTEM_FAULT_STATUS,
            statusTableDO.getCarIndex(), false, RowProperty.FDU_SYSTEM_FAULT_STATUS.getRowName(),
            statusTableDO.getFduFaultState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateWiredLineSFARStatusTable()
  {
    if (sfarStatusList != null)
    {
      wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_SFAR, totalColumn.get());

      for (FireSystemWiredLineStatus statusTableDO : sfarStatusList.getFireSystemWiredLineStatusList())
      {
        wiredStatusTableDataProcessor.updateData(RowProperty.WIRED_SFAR, statusTableDO.getCarIndex(), false,
            RowProperty.WIRED_SFAR.getRowName(),
            statusTableDO.getFireSystemWireLineState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateWiredLineExtSmokeStatusTable()
  {
    if (externalSmokeStatusList != null)
    {
      wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_EXIT_SMOKE, totalColumn.get());

      for (FireSystemWiredLineStatus statusTableDO : externalSmokeStatusList
          .getFireSystemWiredLineStatusList())
      {
        wiredStatusTableDataProcessor.updateData(RowProperty.WIRED_EXIT_SMOKE, statusTableDO.getCarIndex(),
            false, RowProperty.WIRED_EXIT_SMOKE.getRowName(),
            statusTableDO.getFireSystemWireLineState().toString().toLowerCase()
                .concat(TCMSUIConstants.EXTERNAL_SMOKE_CSS),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateWiredLineUnderframeFireStatusTable()
  {
    if (totalColumn.get() != 0)
    {
      wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_UNDER_FRAME_FIRE, totalColumn.get());

      for (int carIndex = 1; carIndex <= totalColumn.get(); carIndex++)
      {
        if (((totalColumn.get() == TCMSConstants.SIX_CAR) && (carIndex == TCMSConstants.DM1))
            || ((totalColumn.get() == TCMSConstants.SIX_CAR) && (carIndex == TCMSConstants.DM6))
            || ((totalColumn.get() == TCMSConstants.EIGHT_CAR) && (carIndex == TCMSConstants.DM1))
            || ((totalColumn.get() == TCMSConstants.EIGHT_CAR) && (carIndex == TCMSConstants.DM8)))
        {
          wiredStatusTableDataProcessor.updateData(RowProperty.WIRED_UNDER_FRAME_FIRE, carIndex, false,
              RowProperty.WIRED_UNDER_FRAME_FIRE.getRowName(),
              FireSystemWireLineState.WIRED_LINE_HEALTHY.toString().toLowerCase()
                  .concat(TCMSUIConstants.UNDER_FRAME_FIRE_CSS),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          wiredStatusTableDataProcessor.updateData(RowProperty.WIRED_UNDER_FRAME_FIRE, carIndex, false,
              RowProperty.WIRED_UNDER_FRAME_FIRE.getRowName(),
              FireSystemWireLineState.WIRED_LINE_NOT_AVAILABLE.toString().toLowerCase()
                  .concat(TCMSUIConstants.UNDER_FRAME_FIRE_CSS),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateWiredLineUFARStatusTable()
  {
    if (ufarStatusList != null)
    {
      wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_UFAR, totalColumn.get());

      for (FireSystemWiredLineStatus statusTableDO : ufarStatusList.getFireSystemWiredLineStatusList())
      {
        wiredStatusTableDataProcessor.updateData(RowProperty.WIRED_UFAR, statusTableDO.getCarIndex(), false,
            RowProperty.WIRED_UFAR.getRowName(),
            statusTableDO.getFireSystemWireLineState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateWiredLineInternalFireStatusTable()
  {
    if (internalFireStatusList != null)
    {
      wiredStatusTableDataProcessor.emptyData(RowProperty.WIRED_INTERNAL_FIRE, totalColumn.get());

      for (FireSystemWiredLineStatus statusTableDO : internalFireStatusList
          .getFireSystemWiredLineStatusList())
      {
        wiredStatusTableDataProcessor.updateData(RowProperty.WIRED_INTERNAL_FIRE, statusTableDO.getCarIndex(),
            false, RowProperty.WIRED_INTERNAL_FIRE.getRowName(),
            statusTableDO.getFireSystemWireLineState().toString().toLowerCase()
                .concat(TCMSUIConstants.INTERNAL_FIRE_CSS),
            TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
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
    initializeTableData();
  }

  /**
   * Gets the sensor table data list.
   *
   * @return the sensor table data list
   */
  public ObservableList<StatusTableDO> getSensorStatusTableDataList()
  {
    return sensorStatusTableDataList;
  }

  public ObservableList<StatusTableDO> getWiredStatusTableDataList()
  {
    return wiredStatusTableDataList;
  }

  public ObservableList<StatusTableDO> getFduSystemFaultStatusDataList()
  {
    return fduSystemFaultStatusDataList;
  }

  /**
   * Enum to hold the rows for FIRE DETECTION status table with its name and
   * unit and cell alignment.
   */
  private enum RowProperty implements ITableRowProperty
  {
    FIRE_DETECTION_SENSOR_FAULT_STATE(0, "FAULT", CENTER), //$NON-NLS-1$
    FIRE_DETECTION_SENSOR_ALARM(1, "ALARM", CENTER), //$NON-NLS-1$
    FIRE_DETECTION_SENSOR_DISABLED_STATE(2, "DISABLED", CENTER), //$NON-NLS-1$
    WIRED_EXIT_SMOKE(0, "EXT SMOKE", CENTER), //$NON-NLS-1$
    WIRED_UNDER_FRAME_FIRE(1, "UNDER FRAME FIRE", CENTER), //$NON-NLS-1$
    WIRED_UFAR(2, "UFAR", CENTER), //$NON-NLS-1$
    WIRED_INTERNAL_FIRE(3, "INTERNAL FIRE", CENTER), //$NON-NLS-1$
    WIRED_SFAR(4, "SFAR", CENTER), //$NON-NLS-1$
    FDU_SYSTEM_FAULT_STATUS(0, "FDU", CENTER); //$NON-NLS-1$

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

  public void setFDUFaultStatusList(byte[] fduFaultList)
  {
    if (fduFaultList.length != 0)
    {
      try
      {
        fduFaultStatusList = TCMSProto.FDUFaultStatusList.parseFrom(fduFaultList);
        updateFDUSystemFaultStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setFireSensorFaultStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      updateFireSensorFaultStatus();
    }
  }

  public void setFireSensorAlarmStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        fireSensorAlarmStatusList = TCMSProto.FireSensorAlarmStatusList.parseFrom(newValue);
        updateFireSensorAlarmStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setFireSensorDisabledStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      updateFireSensorDisabledStatus();
    }
  }

  public void setExternalSmokeStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        externalSmokeStatusList = TCMSProto.FireSystemWiredLineStatusList.parseFrom(newValue);
        updateWiredLineExtSmokeStatusTable();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setUnderFrameFireStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      updateWiredLineUnderframeFireStatusTable();
    }
  }

  public void setUFARStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        ufarStatusList = TCMSProto.FireSystemWiredLineStatusList.parseFrom(newValue);
        updateWiredLineUFARStatusTable();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setInternalFireStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        internalFireStatusList = TCMSProto.FireSystemWiredLineStatusList.parseFrom(newValue);
        updateWiredLineInternalFireStatusTable();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setSFARStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        sfarStatusList = TCMSProto.FireSystemWiredLineStatusList.parseFrom(newValue);
        updateWiredLineSFARStatusTable();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

}