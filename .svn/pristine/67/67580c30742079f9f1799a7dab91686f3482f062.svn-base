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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ExternalTemperatureStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ExternalTemperatureStatusList.ExternalTemperatureStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.InternalTemperatureStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.InternalTemperatureStatusList.InternalTemperatureStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.SetPointTemperatureStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.SetPointTemperatureStatusList.SetPointTemperatureStatus;
import com.sydac.mmrbem.tcms.common.state.HVACConstantsEnum;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.data.ITableRowProperty;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataProcesser;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.ListProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleListProperty;
import javafx.collections.FXCollections;

public class HVACTempretureScreenModel extends AbstractScreenModel
{

  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> hvacStatusOneTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> hvacStatusTwoTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser statusOneTableDataProcessor;

  private TableDataProcesser statusTwoTableDataProcessor;

  private SetPointTemperatureStatusList setPointTemperatureStatusListOne = null;

  private InternalTemperatureStatusList internalTemperatureStatusListOne = null;

  private ExternalTemperatureStatusList externalTemperatureStatusListOne = null;

  private SetPointTemperatureStatusList setPointTemperatureStatusListTwo = null;

  private InternalTemperatureStatusList internalTemperatureStatusListTwo = null;

  private ExternalTemperatureStatusList externalTemperatureStatusListTwo = null;

  public HVACTempretureScreenModel(int carIndex)
  {
    super(carIndex);
    statusOneTableDataProcessor = new TableDataProcesser(hvacStatusOneTableDataList);
    statusTwoTableDataProcessor = new TableDataProcesser(hvacStatusTwoTableDataList);

    initializeTableData();
  }

  private void initializeTableData()
  {
    statusOneTableDataProcessor.emptyData(RowProperty.RAD_STATUS_1, totalColumn.get());
    statusOneTableDataProcessor.emptyData(RowProperty.FAD_STATUS_1, totalColumn.get());
    statusOneTableDataProcessor.emptyData(RowProperty.SET_POINT_TEMPERATURE_STATUS_1, totalColumn.get());
    statusOneTableDataProcessor.emptyData(RowProperty.INTERNAL_TEMPERATURE_STATUS_1, totalColumn.get());
    statusOneTableDataProcessor.emptyData(RowProperty.EXTERNAL_TEMPERATURE_STATUS_1, totalColumn.get());

    statusTwoTableDataProcessor.emptyData(RowProperty.RAD_STATUS_2, totalColumn.get());
    statusTwoTableDataProcessor.emptyData(RowProperty.FAD_STATUS_2, totalColumn.get());
    statusTwoTableDataProcessor.emptyData(RowProperty.SET_POINT_TEMPERATURE_STATUS_2, totalColumn.get());
    statusTwoTableDataProcessor.emptyData(RowProperty.INTERNAL_TEMPERATURE_STATUS_2, totalColumn.get());
    statusTwoTableDataProcessor.emptyData(RowProperty.EXTERNAL_TEMPERATURE_STATUS_2, totalColumn.get());

    updatRadStatusOne();
    updatFadStatusOne();
    updateSetTempStatusOne();
    updateInternalTempStatusOne();
    updateExternalTempStatusOne();

    updatRadStatusTwo();
    updatFadStatusTwo();
    updateSetTempStatusTwo();
    updateInternalTempStatusTwo();
    updateExternalTempStatusTwo();

  }

  private void updatRadStatusOne()
  {
    if (totalColumn.get() != 0)
    {
      statusOneTableDataProcessor.emptyData(RowProperty.RAD_STATUS_1, totalColumn.get());

      for (int carIndex = 1; carIndex <= totalColumn.get(); carIndex++)
      {
        if (carIndex == 1)
        {
          statusOneTableDataProcessor.updateData(RowProperty.RAD_STATUS_1, carIndex, false,
              RowProperty.RAD_STATUS_1.getRowName().concat(HVACConstantsEnum.DMAPER.getName()),
              HVACConstantsEnum.valueOf(HVACConstantsEnum.DMAPER.getValue()).getState(),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusOneTableDataProcessor.updateData(RowProperty.RAD_STATUS_1, carIndex, false,
              HVACConstantsEnum.DMAPER.getName(),
              HVACConstantsEnum.valueOf(HVACConstantsEnum.DMAPER.getValue()).getState(),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }
  
  
  private void updatRadStatusTwo()
  {
    if (totalColumn.get() != 0)
    {
      statusTwoTableDataProcessor.emptyData(RowProperty.RAD_STATUS_2, totalColumn.get());

      for (int carIndex = 1; carIndex <= totalColumn.get(); carIndex++)
      {
        if (carIndex == 1)
        {
          statusTwoTableDataProcessor.updateData(RowProperty.RAD_STATUS_2, carIndex, false,
              RowProperty.RAD_STATUS_2.getRowName().concat(HVACConstantsEnum.DMAPER.getName()),
              HVACConstantsEnum.valueOf(HVACConstantsEnum.DMAPER.getValue()).getState(),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusTwoTableDataProcessor.updateData(RowProperty.RAD_STATUS_2, carIndex, false,
              HVACConstantsEnum.DMAPER.getName(),
              HVACConstantsEnum.valueOf(HVACConstantsEnum.DMAPER.getValue()).getState(),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }
  

  private void updatFadStatusOne()
  {
    if (totalColumn.get() != 0)
    {
      statusOneTableDataProcessor.emptyData(RowProperty.FAD_STATUS_1, totalColumn.get());

      for (int carIndex = 1; carIndex <= totalColumn.get(); carIndex++)
      {
        if (carIndex == 1)
        {
          statusOneTableDataProcessor.updateData(RowProperty.FAD_STATUS_1, carIndex, false,
              RowProperty.FAD_STATUS_1.getRowName().concat(HVACConstantsEnum.DMAPER.getName()),
              HVACConstantsEnum.valueOf(HVACConstantsEnum.DMAPER.getValue()).getState(),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusOneTableDataProcessor.updateData(RowProperty.FAD_STATUS_1, carIndex, false,
              HVACConstantsEnum.DMAPER.getName(),
              HVACConstantsEnum.valueOf(HVACConstantsEnum.DMAPER.getValue()).getState(),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }
  
  
  private void updatFadStatusTwo()
  {
    if (totalColumn.get() != 0)
    {
      statusTwoTableDataProcessor.emptyData(RowProperty.FAD_STATUS_2, totalColumn.get());

      for (int carIndex = 1; carIndex <= totalColumn.get(); carIndex++)
      {
        if (carIndex == 1)
        {
          statusTwoTableDataProcessor.updateData(RowProperty.FAD_STATUS_2, carIndex, false,
              RowProperty.FAD_STATUS_2.getRowName().concat(HVACConstantsEnum.DMAPER.getName()),
              HVACConstantsEnum.valueOf(HVACConstantsEnum.DMAPER.getValue()).getState(),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusTwoTableDataProcessor.updateData(RowProperty.FAD_STATUS_2, carIndex, false,
              HVACConstantsEnum.DMAPER.getName(),
              HVACConstantsEnum.valueOf(HVACConstantsEnum.DMAPER.getValue()).getState(),
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateSetTempStatusOne()
  {

    if (setPointTemperatureStatusListOne != null)
    {
      statusOneTableDataProcessor.emptyData(RowProperty.SET_POINT_TEMPERATURE_STATUS_1, totalColumn.get());
      for (SetPointTemperatureStatus statusTableDO : setPointTemperatureStatusListOne
          .getSetPointTemperatureStatusList())
      {
        String setPointTemp = statusTableDO.getSetPointTemperature() == TCMSUIConstants.UNKNOWN_TEMP_VALUE
            ? TCMSUIConstants.NO_VALUE
            : Float.toString(statusTableDO.getSetPointTemperature());

        if (statusTableDO.getCarIndex() == 0)
        {
          statusOneTableDataProcessor.updateData(RowProperty.SET_POINT_TEMPERATURE_STATUS_1,
              statusTableDO.getCarIndex(), false,
              RowProperty.SET_POINT_TEMPERATURE_STATUS_1.getRowName().concat(setPointTemp)
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusOneTableDataProcessor.updateData(RowProperty.SET_POINT_TEMPERATURE_STATUS_1,
              statusTableDO.getCarIndex(), false, setPointTemp.concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }

  }

  private void updateInternalTempStatusOne()
  {
    if (internalTemperatureStatusListOne != null)
    {
      statusOneTableDataProcessor.emptyData(RowProperty.INTERNAL_TEMPERATURE_STATUS_1, totalColumn.get());
      for (InternalTemperatureStatus statusTableDO : internalTemperatureStatusListOne
          .getInternalTemperatureStatusList())
      {
        String internalTemp = statusTableDO.getInternalTemperature() == TCMSUIConstants.UNKNOWN_TEMP_VALUE
            ? TCMSUIConstants.NO_VALUE
            : Float.toString(statusTableDO.getInternalTemperature());

        if (statusTableDO.getCarIndex() == 0)
        {
          statusOneTableDataProcessor.updateData(RowProperty.INTERNAL_TEMPERATURE_STATUS_1,
              statusTableDO.getCarIndex(), false,
              RowProperty.INTERNAL_TEMPERATURE_STATUS_1.getRowName().concat(internalTemp)
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusOneTableDataProcessor.updateData(RowProperty.INTERNAL_TEMPERATURE_STATUS_1,
              statusTableDO.getCarIndex(), false, internalTemp.concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateExternalTempStatusOne()
  {
    if (externalTemperatureStatusListOne != null)
    {
      statusOneTableDataProcessor.emptyData(RowProperty.EXTERNAL_TEMPERATURE_STATUS_1, totalColumn.get());

      for (ExternalTemperatureStatus statusTableDO : externalTemperatureStatusListOne
          .getExternalTemperatureStatusList())
      {
        String externalTemp = statusTableDO.getExternalTemperature() == TCMSUIConstants.UNKNOWN_TEMP_VALUE
            ? TCMSUIConstants.NO_VALUE
            : Float.toString(statusTableDO.getExternalTemperature());

        if (statusTableDO.getCarIndex() == 0)
        {
          statusOneTableDataProcessor.updateData(RowProperty.EXTERNAL_TEMPERATURE_STATUS_1,
              statusTableDO.getCarIndex(), false,
              RowProperty.EXTERNAL_TEMPERATURE_STATUS_1.getRowName().concat(externalTemp)
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusOneTableDataProcessor.updateData(RowProperty.EXTERNAL_TEMPERATURE_STATUS_1,
              statusTableDO.getCarIndex(), false, externalTemp.concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }

  }

  private void updateSetTempStatusTwo()
  {
    if (setPointTemperatureStatusListTwo != null)
    {
      statusTwoTableDataProcessor.emptyData(RowProperty.SET_POINT_TEMPERATURE_STATUS_2, totalColumn.get());

      for (SetPointTemperatureStatus statusTableDO : setPointTemperatureStatusListTwo
          .getSetPointTemperatureStatusList())
      {
        String setPointTemp = statusTableDO.getSetPointTemperature() == TCMSUIConstants.UNKNOWN_TEMP_VALUE
            ? TCMSUIConstants.NO_VALUE
            : Float.toString(statusTableDO.getSetPointTemperature());

        if (statusTableDO.getCarIndex() == 0)
        {
          statusTwoTableDataProcessor.updateData(RowProperty.SET_POINT_TEMPERATURE_STATUS_2,
              statusTableDO.getCarIndex(), false,
              RowProperty.SET_POINT_TEMPERATURE_STATUS_2.getRowName().concat(setPointTemp)
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusTwoTableDataProcessor.updateData(RowProperty.SET_POINT_TEMPERATURE_STATUS_2,
              statusTableDO.getCarIndex(), false, setPointTemp.concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }

      }
    }
  }

  private void updateInternalTempStatusTwo()
  {
    if (internalTemperatureStatusListTwo != null)
    {
      statusTwoTableDataProcessor.emptyData(RowProperty.INTERNAL_TEMPERATURE_STATUS_2, totalColumn.get());

      for (InternalTemperatureStatus statusTableDO : internalTemperatureStatusListTwo
          .getInternalTemperatureStatusList())
      {
        String internalTemp = statusTableDO.getInternalTemperature() == TCMSUIConstants.UNKNOWN_TEMP_VALUE
            ? TCMSUIConstants.NO_VALUE
            : Float.toString(statusTableDO.getInternalTemperature());

        if (statusTableDO.getCarIndex() == 0)
        {
          statusTwoTableDataProcessor.updateData(RowProperty.INTERNAL_TEMPERATURE_STATUS_2,
              statusTableDO.getCarIndex(), false,
              RowProperty.INTERNAL_TEMPERATURE_STATUS_2.getRowName().concat(internalTemp)
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusTwoTableDataProcessor.updateData(RowProperty.INTERNAL_TEMPERATURE_STATUS_2,
              statusTableDO.getCarIndex(), false, internalTemp.concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateExternalTempStatusTwo()
  {

    if (externalTemperatureStatusListTwo != null)
    {
      statusTwoTableDataProcessor.emptyData(RowProperty.EXTERNAL_TEMPERATURE_STATUS_2, totalColumn.get());

      for (ExternalTemperatureStatus statusTableDO : externalTemperatureStatusListTwo
          .getExternalTemperatureStatusList())
      {
        String externalTemp = statusTableDO.getExternalTemperature() == TCMSUIConstants.UNKNOWN_TEMP_VALUE
            ? TCMSUIConstants.NO_VALUE
            : Float.toString(statusTableDO.getExternalTemperature());

        if (statusTableDO.getCarIndex() == 0)
        {
          statusTwoTableDataProcessor.updateData(RowProperty.EXTERNAL_TEMPERATURE_STATUS_2,
              statusTableDO.getCarIndex(), false,
              RowProperty.EXTERNAL_TEMPERATURE_STATUS_2.getRowName().concat(externalTemp)
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          statusTwoTableDataProcessor.updateData(RowProperty.EXTERNAL_TEMPERATURE_STATUS_2,
              statusTableDO.getCarIndex(), false, externalTemp.concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.HVAC_TEMPERATURE_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
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
    initializeTableData();
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
    RAD_STATUS_1(0, "RAD ", CENTER), //$NON-NLS-1$
    FAD_STATUS_1(1, "FAD ", CENTER), //$NON-NLS-1$
    SET_POINT_TEMPERATURE_STATUS_1(2, "Set ", CENTER), // $NON-NLS-2$ //$NON-NLS-1$
    INTERNAL_TEMPERATURE_STATUS_1(3, "Int. ", CENTER), //$NON-NLS-1$
    EXTERNAL_TEMPERATURE_STATUS_1(4, "Ext. ", CENTER), //$NON-NLS-1$
    RAD_STATUS_2(0, "RAD ", CENTER), //$NON-NLS-1$
    FAD_STATUS_2(1, "FAD ", CENTER), //$NON-NLS-1$
    SET_POINT_TEMPERATURE_STATUS_2(2, "Set ", CENTER), //$NON-NLS-1$
    INTERNAL_TEMPERATURE_STATUS_2(3, "Int. ", CENTER), //$NON-NLS-1$
    EXTERNAL_TEMPERATURE_STATUS_2(4, "Ext. ", CENTER); //$NON-NLS-1$

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

  public void setSetPointTemperatureStatusListOne(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        setPointTemperatureStatusListOne = TCMSProto.SetPointTemperatureStatusList.parseFrom(newValue);
        updateSetTempStatusOne();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setInternalTemperatureStatusListOne(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        internalTemperatureStatusListOne = TCMSProto.InternalTemperatureStatusList.parseFrom(newValue);
        updateInternalTempStatusOne();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setExternalTemperatureStatusListOne(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        externalTemperatureStatusListOne = TCMSProto.ExternalTemperatureStatusList.parseFrom(newValue);
        updateExternalTempStatusOne();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setSetPointTemperatureStatusListTwo(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        setPointTemperatureStatusListTwo = TCMSProto.SetPointTemperatureStatusList.parseFrom(newValue);
        updateSetTempStatusTwo();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setInternalTemperatureStatusListTwo(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        internalTemperatureStatusListTwo = TCMSProto.InternalTemperatureStatusList.parseFrom(newValue);
        updateInternalTempStatusTwo();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setExternalTemperatureStatusListTwo(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        externalTemperatureStatusListTwo = TCMSProto.ExternalTemperatureStatusList.parseFrom(newValue);
        updateExternalTempStatusTwo();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

}
