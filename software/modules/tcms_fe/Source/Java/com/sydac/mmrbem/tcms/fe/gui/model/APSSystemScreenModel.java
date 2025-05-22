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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AKStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AKStatusList.AKStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSControlUnitStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSControlUnitStatusList.APSControlUnitState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSControlUnitStatusList.APSControlUnitStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSOutputVoltageStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.APSOutputVoltageStatusList.APSOutputVoltageStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.KStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.KStatusList.KStatus;
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

public class APSSystemScreenModel extends AbstractScreenModel
{
  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> statusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser statusTableDataProcessor;

  private APSControlUnitStatusList apsControlUnitStatusList = null;

  private AKStatusList akStatusList = null;

  private KStatusList kStatusList = null;

  private APSOutputVoltageStatusList apsOutputVoltageStatusList = null;

  public APSSystemScreenModel(int carIndex)
  {
    super(carIndex);
    statusTableDataProcessor = new TableDataProcesser(statusTableDataList);
    initializeTableData();
  }

  /**
   * Initialize table data by empty rows.
   */
  private void initializeTableData()
  {
    statusTableDataProcessor.emptyData(RowProperty.GROUP_LABEL, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.APS_CONTROL_UNIT_STATUS, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.AK_STATUS, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.K_STATUS, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.APS_OUTPUT_VOLTAGE_LABEL, totalColumn.get());
    statusTableDataProcessor.emptyData(RowProperty.APS_OUTPUT_VOLTAGE_STATUS, totalColumn.get());

    updateApsControlUnitStatus();
    updateAkStatus();
    updateKStatus();
    UpdateApsOutputVoltageStatus();
  }

  private void updateApsControlUnitStatus()
  {
    if (apsControlUnitStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.GROUP_LABEL, totalColumn.get());
      statusTableDataProcessor.emptyData(RowProperty.APS_CONTROL_UNIT_STATUS, totalColumn.get());
      for (APSControlUnitStatus statusTableDO : apsControlUnitStatusList.getApsControlUnitStatusList())
      {
        if (statusTableDO.getApsControlUnitState1().equals(APSControlUnitState.APS_CU_BLANK))
        {
          statusTableDataProcessor.updateData(RowProperty.GROUP_LABEL, statusTableDO.getCarIndex(), true,
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
          statusTableDataProcessor.updateData(RowProperty.APS_CONTROL_UNIT_STATUS,
              statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusTableDataProcessor.updateData(RowProperty.GROUP_LABEL, statusTableDO.getCarIndex(), true,
              TCMSUIConstants.APS_GROUP_1_LABEL, TCMSUIConstants.APS_SCREEN_GROUP_LABEL_CSS,
              TCMSUIConstants.APS_GROUP_2_LABEL, TCMSUIConstants.APS_SCREEN_GROUP_LABEL_CSS);
          statusTableDataProcessor.updateData(RowProperty.APS_CONTROL_UNIT_STATUS,
              statusTableDO.getCarIndex(), true, RowProperty.APS_CONTROL_UNIT_STATUS.getRowName(),
              statusTableDO.getApsControlUnitState1().toString().toLowerCase(),
              RowProperty.APS_CONTROL_UNIT_STATUS.getRowName(),
              statusTableDO.getApsControlUnitState2().toString().toLowerCase());
        }
      }
    }
  }

  private void updateAkStatus()
  {
    if (akStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.AK_STATUS, totalColumn.get());
      for (AKStatus statusTableDO : akStatusList.getAkStatusList())
      {
        statusTableDataProcessor.updateData(RowProperty.AK_STATUS, statusTableDO.getCarIndex(), true,
            RowProperty.AK_STATUS.getRowName(), statusTableDO.getAkState1().toString().toLowerCase(),
            RowProperty.AK_STATUS.getRowName(), statusTableDO.getAkState2().toString().toLowerCase());
      }
    }
  }

  private void updateKStatus()
  {
    if (kStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.K_STATUS, totalColumn.get());
      for (KStatus statusTableDO : kStatusList.getKStatusList())
      {
        statusTableDataProcessor.updateData(RowProperty.K_STATUS, statusTableDO.getCarIndex(), true,
            RowProperty.K_STATUS.getRowName(), statusTableDO.getKState1().toString().toLowerCase(),
            RowProperty.K_STATUS.getRowName(), statusTableDO.getKState2().toString().toLowerCase());
      }
    }
  }

  private void UpdateApsOutputVoltageStatus()
  {
    if (apsOutputVoltageStatusList != null)
    {
      statusTableDataProcessor.emptyData(RowProperty.APS_OUTPUT_VOLTAGE_LABEL, totalColumn.get());
      statusTableDataProcessor.emptyData(RowProperty.APS_OUTPUT_VOLTAGE_STATUS, totalColumn.get());
      for (APSOutputVoltageStatus statusTableDO : apsOutputVoltageStatusList.getApsOutputVoltageStatusList())
      {
        if (statusTableDO.getApsOutputVoltage1() != ApplicationConstants.VALUE_NOT_APPLICABLE
            && statusTableDO.getApsOutputVoltage2() != ApplicationConstants.VALUE_NOT_APPLICABLE)
        {
          statusTableDataProcessor.updateData(RowProperty.APS_OUTPUT_VOLTAGE_LABEL,
              statusTableDO.getCarIndex(), true, RowProperty.APS_OUTPUT_VOLTAGE_LABEL.getRowName(),
              TCMSUIConstants.APS_SCREEN_OUT_VOLT_LABEL_CSS,
              RowProperty.APS_OUTPUT_VOLTAGE_LABEL.getRowName(),
              TCMSUIConstants.APS_SCREEN_OUT_VOLT_LABEL_CSS);
          statusTableDataProcessor.updateData(RowProperty.APS_OUTPUT_VOLTAGE_STATUS,
              statusTableDO.getCarIndex(), true, String.valueOf(statusTableDO.getApsOutputVoltage1()),
              TCMSUIConstants.APS_SCREEN_OUT_VOLT_LABEL_CSS,
              String.valueOf(statusTableDO.getApsOutputVoltage2()),
              TCMSUIConstants.APS_SCREEN_OUT_VOLT_LABEL_CSS);
        }
        else
        {
          statusTableDataProcessor.updateData(RowProperty.APS_OUTPUT_VOLTAGE_LABEL,
              statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
          statusTableDataProcessor.updateData(RowProperty.APS_OUTPUT_VOLTAGE_STATUS,
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
  public ObservableList<StatusTableDO> getStatusTableDataList()
  {
    return statusTableDataList;
  }

  public void setApsControlUnitStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        apsControlUnitStatusList = TCMSProto.APSControlUnitStatusList.parseFrom(newValue);
        updateApsControlUnitStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setAkStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        akStatusList = TCMSProto.AKStatusList.parseFrom(newValue);
        updateAkStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setkStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        kStatusList = TCMSProto.KStatusList.parseFrom(newValue);
        updateKStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setApsOutputVoltageStatusList(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        apsOutputVoltageStatusList = TCMSProto.APSOutputVoltageStatusList.parseFrom(newValue);
        UpdateApsOutputVoltageStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  /**
   * Enum to hold the rows for APS status table with its name and unit and cell
   * alignment.
   */
  private enum RowProperty implements ITableRowProperty
  {
    GROUP_LABEL(0, "", "top_center"), //$NON-NLS-1$ //$NON-NLS-2$
    APS_CONTROL_UNIT_STATUS(1, "APS Sts", CENTER), //$NON-NLS-1$
    AK_STATUS(2, "AK ON", CENTER), //$NON-NLS-1$
    K_STATUS(3, "K ON", CENTER), //$NON-NLS-1$
    APS_OUTPUT_VOLTAGE_LABEL(4, "Out Volt", CENTER), //$NON-NLS-1$
    APS_OUTPUT_VOLTAGE_STATUS(5, "", CENTER); //$NON-NLS-1$

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
