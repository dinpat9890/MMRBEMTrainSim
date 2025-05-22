/******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.tcms.fe.gui.model;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LightStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LightStatusList.LightState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.LightStatusList.LightStatus;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.data.ITableRowProperty;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataProcesser;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class LightSystemStatusScreenModel extends AbstractScreenModel
{

  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> saloonLightTableDataList1 = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> saloonLightTableDataList2 = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> flasherLightTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser saloonLightTableDataProcessor1;

  private TableDataProcesser saloonLightTableDataProcessor2;

  private TableDataProcesser flasherLightTableDataProcessor;

  private LightStatusList saloonLightStatusList1;

  private LightStatusList saloonLightStatusList2;

  private LightStatusList flasherLightStatusList;

  public LightSystemStatusScreenModel(int carIndex)
  {
    super(carIndex);

    saloonLightTableDataProcessor1 = new TableDataProcesser(saloonLightTableDataList1);
    saloonLightTableDataProcessor2 = new TableDataProcesser(saloonLightTableDataList2);
    flasherLightTableDataProcessor = new TableDataProcesser(flasherLightTableDataList);
    initializeTableData();
  }

  private void initializeTableData()
  {
    saloonLightTableDataProcessor1.emptyData(RowProperty.SALOON_LIGHT_GROUP_STATUS_1, totalColumn.get());
    saloonLightTableDataProcessor2.emptyData(RowProperty.SALOON_LIGHT_GROUP_STATUS_2, totalColumn.get());
    flasherLightTableDataProcessor.emptyData(RowProperty.FLASHER_LIGHT_STATUS, totalColumn.get());

    updateSaloonLightTable1();
    updateSaloonLightTable2();
    updateFlasherLightTable();

  }

  private void updateSaloonLightTable2()
  {
    saloonLightTableDataProcessor2.emptyData(RowProperty.SALOON_LIGHT_GROUP_STATUS_2, totalColumn.get());
    if (saloonLightStatusList2 != null)
    {
      for (LightStatus statusTableDO : saloonLightStatusList2.getLightStatusList())
      {
        saloonLightTableDataProcessor2.updateData(RowProperty.SALOON_LIGHT_GROUP_STATUS_2,
            statusTableDO.getCarIndex(), false,
            statusTableDO.getLightState() == LightState.LIGHT_SYSTEM_OFF ? TCMSUIConstants.LIGHTS_OFF_LABEL
                : RowProperty.FLASHER_LIGHT_STATUS.getRowName(),
            statusTableDO.getLightState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateFlasherLightTable()
  {
    flasherLightTableDataProcessor.emptyData(RowProperty.FLASHER_LIGHT_STATUS, totalColumn.get());
    if (flasherLightStatusList != null)
    {
      for (LightStatus statusTableDO : flasherLightStatusList.getLightStatusList())
      {
        flasherLightTableDataProcessor.updateData(RowProperty.FLASHER_LIGHT_STATUS,
            statusTableDO.getCarIndex(), false,
            statusTableDO.getLightState() == LightState.LIGHT_SYSTEM_OFF ? TCMSUIConstants.LIGHTS_OFF_LABEL
                : RowProperty.FLASHER_LIGHT_STATUS.getRowName(),
            statusTableDO.getLightState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  private void updateSaloonLightTable1()
  {
    saloonLightTableDataProcessor1.emptyData(RowProperty.SALOON_LIGHT_GROUP_STATUS_1, totalColumn.get());
    if (saloonLightStatusList1 != null)
    {
      for (LightStatus statusTableDO : saloonLightStatusList1.getLightStatusList())
      {
        saloonLightTableDataProcessor1.updateData(RowProperty.SALOON_LIGHT_GROUP_STATUS_1,
            statusTableDO.getCarIndex(), false,
            statusTableDO.getLightState() == LightState.LIGHT_SYSTEM_OFF ? TCMSUIConstants.LIGHTS_OFF_LABEL
                : RowProperty.FLASHER_LIGHT_STATUS.getRowName(),
            statusTableDO.getLightState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
      }
    }
  }

  /** Getter and setter for total column in our screen 
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

  /***
   * Gets the sensor table data list.@return the status table data list
   * 
   * @return List saloon Light table list
   ***/
  public ListProperty<StatusTableDO> getSaloonLightTableDataList1()
  {
    return saloonLightTableDataList1;
  }

  public ListProperty<StatusTableDO> getSaloonLightTableDataList2()
  {
    return saloonLightTableDataList2;
  }

  public ListProperty<StatusTableDO> getFlasherLightTableDataList()
  {
    return flasherLightTableDataList;
  }

  /**
   * Enum to hold the rows for HVAC status table with its tempreature and cell
   * alignment.
   ***/
  private enum RowProperty implements ITableRowProperty
  {
    SALOON_LIGHT_GROUP_STATUS_1(0, "ON", CENTER), //$NON-NLS-1$
    SALOON_LIGHT_GROUP_STATUS_2(0, "ON", CENTER), //$NON-NLS-1$
    FLASHER_LIGHT_STATUS(0, "ON", CENTER); //$NON-NLS-1$

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

  public void setSaloonLightStatusList1(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        saloonLightStatusList1 = TCMSProto.LightStatusList.parseFrom(newValue);
        updateSaloonLightTable1();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setSaloonLightStatusList2(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        saloonLightStatusList2 = TCMSProto.LightStatusList.parseFrom(newValue);
        updateSaloonLightTable2();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setFlasherLightStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        flasherLightStatusList = TCMSProto.LightStatusList.parseFrom(newValue);
        updateFlasherLightTable();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

}
