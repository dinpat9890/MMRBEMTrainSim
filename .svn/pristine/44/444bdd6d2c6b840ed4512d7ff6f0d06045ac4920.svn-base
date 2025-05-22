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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MainTransformerTemperaturesList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MainTransformerTemperaturesList.MainTransformerTemperatures;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MotorTemperaturesList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MotorTemperaturesList.MotorTemperature;
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

public class PropulsionSystemTemperaturesScreenModel extends AbstractScreenModel
{
  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> motor1TempTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> motor2TempTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> motor3TempTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> motor4TempTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> mainTransformerTempTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser motor1TempTableDataProcessor;

  private TableDataProcesser motor2TempTableDataProcessor;

  private TableDataProcesser motor3TempTableDataProcessor;

  private TableDataProcesser motor4TempTableDataProcessor;

  private TableDataProcesser mainTransformerTempTableDataProcessor;

  private MotorTemperaturesList motor1TemperaturesList = null;

  private MotorTemperaturesList motor2TemperaturesList = null;

  private MotorTemperaturesList motor3TemperaturesList = null;

  private MotorTemperaturesList motor4TemperaturesList = null;

  private MainTransformerTemperaturesList mainTransformerTemperaturesList = null;

  public PropulsionSystemTemperaturesScreenModel(int carIndex)
  {
    super(carIndex);
    motor1TempTableDataProcessor = new TableDataProcesser(motor1TempTableDataList);
    motor2TempTableDataProcessor = new TableDataProcesser(motor2TempTableDataList);
    motor3TempTableDataProcessor = new TableDataProcesser(motor3TempTableDataList);
    motor4TempTableDataProcessor = new TableDataProcesser(motor4TempTableDataList);
    mainTransformerTempTableDataProcessor = new TableDataProcesser(mainTransformerTempTableDataList);
    initializeTableData();
  }

  /**
   * Initialize table data by empty rows.
   */
  private void initializeTableData()
  {
    motor1TempTableDataProcessor.emptyData(RowProperty.MOTOR_1_TEMPERATURE, totalColumn.get());
    motor2TempTableDataProcessor.emptyData(RowProperty.MOTOR_2_TEMPERATURE, totalColumn.get());
    motor3TempTableDataProcessor.emptyData(RowProperty.MOTOR_3_TEMPERATURE, totalColumn.get());
    motor4TempTableDataProcessor.emptyData(RowProperty.MOTOR_4_TEMPERATURE, totalColumn.get());
    mainTransformerTempTableDataProcessor.emptyData(RowProperty.MAIN_TRANSFORMER_TEMPERATURE,
        totalColumn.get());

    updateMotor1Temperature();
    updateMotor2Temperature();
    updateMotor3Temperature();
    updateMotor4Temperature();
    updateMainTransformerTemperature();
  }

  private void updateMotor1Temperature()
  {
    if (motor1TemperaturesList != null)
    {
      motor1TempTableDataProcessor.emptyData(RowProperty.MOTOR_1_TEMPERATURE, totalColumn.get());
      for (MotorTemperature statusTableDO : motor1TemperaturesList.getMotorTemperatureList())
      {
        if (statusTableDO.getBogie1MotorTemperature() != TCMSConstants.VALUE_NOT_APPLICABLE)
        {
          motor1TempTableDataProcessor.updateData(RowProperty.MOTOR_1_TEMPERATURE,
              statusTableDO.getCarIndex(), true,
              String.valueOf(statusTableDO.getBogie1MotorTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS,
              String.valueOf(statusTableDO.getBogie2MotorTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
        else
        {
          motor1TempTableDataProcessor.updateData(RowProperty.MOTOR_1_TEMPERATURE,
              statusTableDO.getCarIndex(), false, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
      }
    }
  }

  private void updateMotor2Temperature()
  {
    if (motor2TemperaturesList != null)
    {
      motor2TempTableDataProcessor.emptyData(RowProperty.MOTOR_2_TEMPERATURE, totalColumn.get());
      for (MotorTemperature statusTableDO : motor2TemperaturesList.getMotorTemperatureList())
      {
        if (statusTableDO.getBogie1MotorTemperature() != TCMSConstants.VALUE_NOT_APPLICABLE)
        {
          motor2TempTableDataProcessor.updateData(RowProperty.MOTOR_2_TEMPERATURE,
              statusTableDO.getCarIndex(), true,
              String.valueOf(statusTableDO.getBogie1MotorTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS,
              String.valueOf(statusTableDO.getBogie2MotorTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
        else
        {
          motor2TempTableDataProcessor.updateData(RowProperty.MOTOR_2_TEMPERATURE,
              statusTableDO.getCarIndex(), false, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
      }
    }
  }

  private void updateMotor3Temperature()
  {
    if (motor3TemperaturesList != null)
    {
      motor3TempTableDataProcessor.emptyData(RowProperty.MOTOR_3_TEMPERATURE, totalColumn.get());
      for (MotorTemperature statusTableDO : motor3TemperaturesList.getMotorTemperatureList())
      {
        if (statusTableDO.getBogie1MotorTemperature() != TCMSConstants.VALUE_NOT_APPLICABLE)
        {
          motor3TempTableDataProcessor.updateData(RowProperty.MOTOR_3_TEMPERATURE,
              statusTableDO.getCarIndex(), true,
              String.valueOf(statusTableDO.getBogie1MotorTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS,
              String.valueOf(statusTableDO.getBogie2MotorTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
        else
        {
          motor3TempTableDataProcessor.updateData(RowProperty.MOTOR_3_TEMPERATURE,
              statusTableDO.getCarIndex(), false, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
      }
    }
  }

  private void updateMotor4Temperature()
  {
    if (motor4TemperaturesList != null)
    {
      motor4TempTableDataProcessor.emptyData(RowProperty.MOTOR_4_TEMPERATURE, totalColumn.get());
      for (MotorTemperature statusTableDO : motor4TemperaturesList.getMotorTemperatureList())
      {
        if (statusTableDO.getBogie1MotorTemperature() != TCMSConstants.VALUE_NOT_APPLICABLE)
        {
          motor4TempTableDataProcessor.updateData(RowProperty.MOTOR_4_TEMPERATURE,
              statusTableDO.getCarIndex(), true,
              String.valueOf(statusTableDO.getBogie1MotorTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS,
              String.valueOf(statusTableDO.getBogie2MotorTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
        else
        {
          motor4TempTableDataProcessor.updateData(RowProperty.MOTOR_4_TEMPERATURE,
              statusTableDO.getCarIndex(), false, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
      }
    }
  }

  private void updateMainTransformerTemperature()
  {
    if (mainTransformerTemperaturesList != null)
    {
      mainTransformerTempTableDataProcessor.emptyData(RowProperty.MAIN_TRANSFORMER_TEMPERATURE,
          totalColumn.get());
      for (MainTransformerTemperatures statusTableDO : mainTransformerTemperaturesList
          .getMainTransformerTemperaturesList())
      {
        if (statusTableDO.getMainTransformerTemperature() != TCMSConstants.VALUE_NOT_APPLICABLE)
        {
          mainTransformerTempTableDataProcessor.updateData(RowProperty.MAIN_TRANSFORMER_TEMPERATURE,
              statusTableDO.getCarIndex(), false,
              String.valueOf(statusTableDO.getMainTransformerTemperature())
                  .concat(TCMSUIConstants.DEGREE_CELCIUS_LABEL),
              TCMSUIConstants.TEMPERATURES_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          mainTransformerTempTableDataProcessor.updateData(RowProperty.MAIN_TRANSFORMER_TEMPERATURE,
              statusTableDO.getCarIndex(), false, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.TEMPERATURES_LABEL_CSS);
        }
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

  public ObservableList<StatusTableDO> getMotor1TempTableDataList()
  {
    return motor1TempTableDataList;
  }

  public ObservableList<StatusTableDO> getMotor2TempTableDataList()
  {
    return motor2TempTableDataList;
  }

  public ObservableList<StatusTableDO> getMotor3TempTableDataList()
  {
    return motor3TempTableDataList;
  }

  public ObservableList<StatusTableDO> getMotor4TempTableDataList()
  {
    return motor4TempTableDataList;
  }

  public ObservableList<StatusTableDO> getMainTransformerTempTableDataList()
  {
    return mainTransformerTempTableDataList;
  }

  /**
   * Enum to hold the rows for BRAKE status table with its name and unit and
   * cell alignment.
   */
  private enum RowProperty implements ITableRowProperty
  {
    MOTOR_1_TEMPERATURE(0, "", CENTER), //$NON-NLS-1$
    MOTOR_2_TEMPERATURE(0, "", CENTER), //$NON-NLS-1$
    MOTOR_3_TEMPERATURE(0, "", CENTER), //$NON-NLS-1$
    MOTOR_4_TEMPERATURE(0, "", CENTER), //$NON-NLS-1$
    MAIN_TRANSFORMER_TEMPERATURE(0, "", CENTER); //$NON-NLS-1$

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

  public void setMotor1TemperatureList(byte[] motorTemperatureList)
  {
    if (motorTemperatureList.length != 0)
    {
      try
      {
        this.motor1TemperaturesList = TCMSProto.MotorTemperaturesList.parseFrom(motorTemperatureList);
        updateMotor1Temperature();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setMotor2TemperatureList(byte[] motorTemperatureList)
  {
    if (motorTemperatureList.length != 0)
    {
      try
      {
        this.motor2TemperaturesList = TCMSProto.MotorTemperaturesList.parseFrom(motorTemperatureList);
        updateMotor2Temperature();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setMotor3TemperatureList(byte[] motorTemperatureList)
  {
    if (motorTemperatureList.length != 0)
    {
      try
      {
        this.motor3TemperaturesList = TCMSProto.MotorTemperaturesList.parseFrom(motorTemperatureList);
        updateMotor3Temperature();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setMotor4TemperatureList(byte[] motorTemperatureList)
  {
    if (motorTemperatureList.length != 0)
    {
      try
      {
        this.motor4TemperaturesList = TCMSProto.MotorTemperaturesList.parseFrom(motorTemperatureList);
        updateMotor4Temperature();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setMainTransformerTemperatureList(byte[] mainTransformerTemperatureList)
  {
    if (mainTransformerTemperatureList.length != 0)
    {
      try
      {
        this.mainTransformerTemperaturesList = TCMSProto.MainTransformerTemperaturesList
            .parseFrom(mainTransformerTemperatureList);
        updateMainTransformerTemperature();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }
}
