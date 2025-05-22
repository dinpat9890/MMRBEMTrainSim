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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLOilLevelStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLOilLevelStatusList.WFLOilLevelStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLPumpStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLPumpStatusList.WFLPumpStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLStatusList.WFLState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WFLStatusList.WFLStatus;
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

public class WheelFlangeLubricatorSystemStatusScreenModel extends AbstractScreenModel
{

  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private IntegerProperty frontCarWflIsolatedStatus = new SimpleIntegerProperty();

  private IntegerProperty rearCarWflIsolatedStatus = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> wflStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser wflStatusTableDataProcessor;

  private WFLStatusList wflStatusList;

  private WFLOilLevelStatusList wflOilLevelStatusList;

  private WFLPumpStatusList wflPumpStatusList1;

  private WFLPumpStatusList wflPumpStatusList2;

  public WheelFlangeLubricatorSystemStatusScreenModel(int carIndex)
  {
    super(carIndex);
    wflStatusTableDataProcessor = new TableDataProcesser(wflStatusTableDataList);
    initializeTableData();
  }

  private void initializeTableData()
  {
    wflStatusTableDataProcessor.emptyData(RowProperty.WFL_STATUS_TABLE, totalColumn.get());
    wflStatusTableDataProcessor.emptyData(RowProperty.WFL_OIL_LEVEL_STATUS, totalColumn.get());
    wflStatusTableDataProcessor.emptyData(RowProperty.WFL_PUMP_STATION_1, totalColumn.get());
    wflStatusTableDataProcessor.emptyData(RowProperty.WFL_PUMP_STATION_2, totalColumn.get());

    updateStatusRow();
    updateOilLevelRow();
    updatePumpStationFirstRow();
    updatePumpStationSecondRow();
  }

  private void updatePumpStationSecondRow()
  {
    if (wflPumpStatusList2 != null)
    {
      wflStatusTableDataProcessor.emptyData(RowProperty.WFL_PUMP_STATION_2, totalColumn.get());
      for (WFLPumpStatus statusTableDO : wflPumpStatusList2.getWflPumpStatusList())
      {
        wflStatusTableDataProcessor.updateData(RowProperty.WFL_PUMP_STATION_2, statusTableDO.getCarIndex(),
            false, RowProperty.WFL_PUMP_STATION_2.getRowName(),
            statusTableDO.getWflPumpState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updatePumpStationFirstRow()
  {
    if (wflPumpStatusList1 != null)
    {
      wflStatusTableDataProcessor.emptyData(RowProperty.WFL_PUMP_STATION_1, totalColumn.get());
      for (WFLPumpStatus statusTableDO : wflPumpStatusList1.getWflPumpStatusList())
      {
        wflStatusTableDataProcessor.updateData(RowProperty.WFL_PUMP_STATION_1, statusTableDO.getCarIndex(),
            false, RowProperty.WFL_PUMP_STATION_1.getRowName(),
            statusTableDO.getWflPumpState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }

  }

  private void updateOilLevelRow()
  {
    if (wflOilLevelStatusList != null)
    {
      wflStatusTableDataProcessor.emptyData(RowProperty.WFL_OIL_LEVEL_STATUS, totalColumn.get());
      for (WFLOilLevelStatus statusTableDO : wflOilLevelStatusList.getWflOilLevelStatusList())
      {
        wflStatusTableDataProcessor.updateData(RowProperty.WFL_OIL_LEVEL_STATUS, statusTableDO.getCarIndex(),
            false, RowProperty.WFL_OIL_LEVEL_STATUS.getRowName(),
            statusTableDO.getWflOilState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateStatusRow()
  {
    if (wflStatusList != null)
    {
      wflStatusTableDataProcessor.emptyData(RowProperty.WFL_STATUS_TABLE, totalColumn.get());

      for (WFLStatus statusTableDO : wflStatusList.getWflStatusList())
      {
        String wflStatusCss = statusTableDO.getWflState().toString().toLowerCase();
        if ((frontCarWflIsolatedStatus.get() == TCMSUIConstants.WFL_ISOLATED_VALUE
            && statusTableDO.getCarIndex() == TCMSConstants.DM1_CAR)
            || ((rearCarWflIsolatedStatus.get() == TCMSUIConstants.WFL_ISOLATED_VALUE)
                && (totalColumn.get() == TCMSConstants.CAB_8
                    && statusTableDO.getCarIndex() == TCMSConstants.DM8_CAR)
                || (rearCarWflIsolatedStatus.get() == TCMSUIConstants.WFL_ISOLATED_VALUE)
                    && (totalColumn.get() == TCMSConstants.CAB_6
                        && statusTableDO.getCarIndex() == TCMSConstants.DM6_CAR)))
        {
          wflStatusCss = WFLState.WFL_STATUS_ISOLATED.toString().toLowerCase();
        }
        wflStatusTableDataProcessor.updateData(RowProperty.WFL_STATUS_TABLE, statusTableDO.getCarIndex(),
            false, RowProperty.WFL_STATUS_TABLE.getRowName(), wflStatusCss, TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  /**
   * Getter and setter for total column in our screen
   * 
   * @return Integer total column
   **/
  public IntegerProperty getTotalColumn()
  {
    return totalColumn;
  }

  public void setTotalColumn(Integer totalColumn)
  {
    this.totalColumn.set(totalColumn);
  }

  public IntegerProperty getFrontCarWflIsolatedStatus()
  {
    return frontCarWflIsolatedStatus;
  }

  public void setFrontCarWflIsolatedStatus(Integer frontCarWflIsolatedStatus)
  {
    this.frontCarWflIsolatedStatus.set(frontCarWflIsolatedStatus);
    updateStatusRow();
  }

  public IntegerProperty getRearCarWflIsolatedStatus()
  {
    return rearCarWflIsolatedStatus;
  }

  public void setRearCarWflIsolatedStatus(Integer rearCarWflIsolatedStatus)
  {
    this.rearCarWflIsolatedStatus.set(rearCarWflIsolatedStatus);
    updateStatusRow();
  }

  /***
   * Gets the sensor table data list.@return the status table data list
   * 
   * @return {@link ListProperty}
   ***/
  public ListProperty<StatusTableDO> getWFLStatusTableDataList()
  {
    return wflStatusTableDataList;
  }

  /**
   * Enum to hold the rows for HVAC status table with its tempreature and cell
   * alignment.
   ***/
  private enum RowProperty implements ITableRowProperty
  {
    WFL_STATUS_TABLE(0, "WFL", CENTER), //$NON-NLS-1$
    WFL_OIL_LEVEL_STATUS(1, "OIL LEVEL", CENTER), //$NON-NLS-1$
    WFL_PUMP_STATION_1(2, "PUMP 1", CENTER), //$NON-NLS-1$
    WFL_PUMP_STATION_2(3, "PUMP 2", CENTER); //$NON-NLS-1$

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

  public void setWflStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        wflStatusList = TCMSProto.WFLStatusList.parseFrom(newValue);
        updateStatusRow();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setWflOilLevelStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        wflOilLevelStatusList = TCMSProto.WFLOilLevelStatusList.parseFrom(newValue);
        updateOilLevelRow();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setWflPumpStatusListOne(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        wflPumpStatusList1 = TCMSProto.WFLPumpStatusList.parseFrom(newValue);
        updatePumpStationFirstRow();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setWflPumpStatusListTwo(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        wflPumpStatusList2 = TCMSProto.WFLPumpStatusList.parseFrom(newValue);
        updatePumpStationSecondRow();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

}
