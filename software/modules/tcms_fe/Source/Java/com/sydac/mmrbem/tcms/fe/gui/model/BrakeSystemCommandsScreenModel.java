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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ParkingBrakeStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ParkingBrakeStatusList.ParkingBrakeStatus;
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

public class BrakeSystemCommandsScreenModel extends AbstractScreenModel
{
  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> parkingBrakeStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser parkingBrakeStatusTableDataProcessor;

  private ParkingBrakeStatusList parkingBrakeStatusList = null;

  public BrakeSystemCommandsScreenModel(int carIndex)
  {
    super(carIndex);
    parkingBrakeStatusTableDataProcessor = new TableDataProcesser(parkingBrakeStatusTableDataList);
    initializeTableData();
  }

  /**
   * Initialize table data by empty rows.
   */
  private void initializeTableData()
  {
    parkingBrakeStatusTableDataProcessor.emptyData(RowProperty.PARKING_BRAKE_STATUS, totalColumn.get());

    updateParkingBrakeStatusList();
  }

  private void updateParkingBrakeStatusList()
  {
    if (parkingBrakeStatusList != null)
    {
      parkingBrakeStatusTableDataProcessor.emptyData(RowProperty.PARKING_BRAKE_STATUS, totalColumn.get());
      for (ParkingBrakeStatus statusTableDO : parkingBrakeStatusList.getParkingBrakeStatusList())
      {
        parkingBrakeStatusTableDataProcessor.updateData(RowProperty.PARKING_BRAKE_STATUS,
            statusTableDO.getCarIndex(), false, TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.PARKING_BRAKE_ICON_CSS
                .concat(statusTableDO.getParkingBrakeState().toString().toLowerCase()),
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

  public ObservableList<StatusTableDO> getParkingBrakeStatusTableDataList()
  {
    return parkingBrakeStatusTableDataList;
  }

  /**
   * Enum to hold the rows for BRAKE status table with its name and unit and
   * cell alignment.
   */
  private enum RowProperty implements ITableRowProperty
  {
    PARKING_BRAKE_STATUS(0, "", CENTER); //$NON-NLS-1$

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

  public void setParkingBrakeState(byte[] parkingBrakeStateList)
  {
    if (parkingBrakeStateList.length != 0)
    {
      try
      {
        parkingBrakeStatusList = TCMSProto.ParkingBrakeStatusList.parseFrom(parkingBrakeStateList);
        updateParkingBrakeStatusList();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

}
