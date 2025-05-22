/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.model;

import java.math.RoundingMode;
import java.text.DecimalFormat;

import com.google.protobuf.InvalidProtocolBufferException;
import com.sydac.common.log.Tracer;
import com.sydac.mmrbem.cabscreens.fe.gui.model.AbstractScreenModel;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AirSuspensionPressureStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.AirSuspensionPressureStatusList.AirSuspensionPressureStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BrakeControlUnitStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BrakeControlUnitStatusList.BrakeControlUnitStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BrakeCylinderPressureStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.BrakeCylinderPressureStatusList.BrakeCylinderPressureStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CarWeightStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CarWeightStatusList.CarWeightStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EDBrakeRequestedStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EDBrakeRequestedStatusList.EDBrakeRequestedStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EDCutOutRPRESSIsolationStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EDCutOutRPRESSIsolationStatusList.EDCutOutRpressIsolationStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EPBrakeDeliveredStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EPBrakeDeliveredStatusList.EPBrakeDeliveredStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EmergencyBrakeLineStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EmergencyBrakeLineStatusList.EmergencyBrakeLineStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FullServiceBrakeLineStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.FullServiceBrakeLineStatusList.FullServiceBrakeLineStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HoldingBrakeEpicIsolationStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.HoldingBrakeEpicIsolationStatusList.HoldingBrakeEpicIsolationStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MainPipePressureStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.MainPipePressureStatusList.MainPipePressureStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ParkingBrkStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ParkingBrkStatusList.ParkingBrkStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.SUSPStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.SUSPStatusList.SUSPStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ServiceBrkStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.ServiceBrkStatusList.ServiceBrkStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainLineStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.TrainLineStatusList.TrainLineStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WSPStatusList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.WSPStatusList.WSPStatus;
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

public class BrakeSystemScreenModel extends AbstractScreenModel
{
  DecimalFormat oneDecimalPointFormat = new DecimalFormat("###.#"); //$NON-NLS-1$

  private IntegerProperty totalColumn = new SimpleIntegerProperty();

  private ListProperty<StatusTableDO> brakeStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> wspSuspStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> brakeControlUnitStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> lineStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> holdEpicEdRpressStatusTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private ListProperty<StatusTableDO> brakeValueTableDataList = new SimpleListProperty<>(
      FXCollections.observableArrayList());

  private TableDataProcesser brakeStatusTableDataProcessor;

  private TableDataProcesser wspSuspStatusTableDataProcessor;

  private TableDataProcesser brakeControlUnitStatusTableDataProcessor;

  private TableDataProcesser lineStatusTableDataProcessor;

  private TableDataProcesser holdEpicEdRpressStatusTableDataProcessor;

  private TableDataProcesser brakeValueTableDataProcessor;

  private ServiceBrkStatusList serviceBrakeStatusList = null;

  private ParkingBrkStatusList parkingBrakeStatusList = null;

  private WSPStatusList wspStatusList = null;

  private SUSPStatusList suspStatusList = null;

  private BrakeControlUnitStatusList brakeControlUnitStatusList = null;

  private TrainLineStatusList trainLineStatusList = null;

  private FullServiceBrakeLineStatusList fullServiceBrakeLineStatusList = null;

  private EmergencyBrakeLineStatusList emergencyBrakeLineStatusList = null;

  private HoldingBrakeEpicIsolationStatusList holdingBrakeEpicIsolationStatusList = null;

  private EDCutOutRPRESSIsolationStatusList edCutOutRpressStatusList = null;

  private MainPipePressureStatusList mainPipePressureStatusList = null;

  private BrakeCylinderPressureStatusList brakeCylinderPressureStatusList = null;

  private AirSuspensionPressureStatusList airSuspensionPressureStatusList = null;

  private EPBrakeDeliveredStatusList epBrakeDeliveredStatusList = null;

  private EDBrakeRequestedStatusList edBrakeRequestedStatusList = null;

  private CarWeightStatusList carWeightStatusList = null;

  private final IntegerProperty emergencyBrakeState = new SimpleIntegerProperty(); // $NON-NLS-1$

  private final IntegerProperty fullBrakeState = new SimpleIntegerProperty(); // $NON-NLS-1$

  private final IntegerProperty brakeTlState = new SimpleIntegerProperty(); // $NON-NLS-1$

  public BrakeSystemScreenModel(int carIndex)
  {
    super(carIndex);
    brakeStatusTableDataProcessor = new TableDataProcesser(brakeStatusTableDataList);
    wspSuspStatusTableDataProcessor = new TableDataProcesser(wspSuspStatusTableDataList);
    brakeControlUnitStatusTableDataProcessor = new TableDataProcesser(brakeControlUnitStatusTableDataList);
    lineStatusTableDataProcessor = new TableDataProcesser(lineStatusTableDataList);
    holdEpicEdRpressStatusTableDataProcessor = new TableDataProcesser(holdEpicEdRpressStatusTableDataList);
    brakeValueTableDataProcessor = new TableDataProcesser(brakeValueTableDataList);
    initializeTableData();
  }

  /**
   * Initialize table data by empty rows.
   */
  private void initializeTableData()
  {
    brakeStatusTableDataProcessor.emptyData(RowProperty.SERVICE_BRAKE_STATUS, totalColumn.get());
    brakeStatusTableDataProcessor.emptyData(RowProperty.PARKING_BRAKE_STATUS, totalColumn.get());

    wspSuspStatusTableDataProcessor.emptyData(RowProperty.WSP_STATUS, totalColumn.get());
    wspSuspStatusTableDataProcessor.emptyData(RowProperty.SUSP_STATUS, totalColumn.get());

    brakeControlUnitStatusTableDataProcessor.emptyData(RowProperty.BRAKE_CONTROL_UNIT_STATUS,
        totalColumn.get());

    lineStatusTableDataProcessor.emptyData(RowProperty.TRAIN_LINE_STATUS, totalColumn.get());
    lineStatusTableDataProcessor.emptyData(RowProperty.FSB_STATUS, totalColumn.get());
    lineStatusTableDataProcessor.emptyData(RowProperty.EB_STATUS, totalColumn.get());

    holdEpicEdRpressStatusTableDataProcessor.emptyData(RowProperty.HOLD_EPIC_STATUS, totalColumn.get());
    holdEpicEdRpressStatusTableDataProcessor.emptyData(RowProperty.ED_CUT_RPRESS_STATUS, totalColumn.get());

    brakeValueTableDataProcessor.emptyData(RowProperty.AIR_PRESSURE_LABEL, totalColumn.get());
    brakeValueTableDataProcessor.emptyData(RowProperty.MAIN_PIPE_VALUE, totalColumn.get());
    brakeValueTableDataProcessor.emptyData(RowProperty.CYLINDERS_VALUE, totalColumn.get());
    brakeValueTableDataProcessor.emptyData(RowProperty.SUSPENS_VALUE, totalColumn.get());
    brakeValueTableDataProcessor.emptyData(RowProperty.EFFORTS_LABEL, totalColumn.get());
    brakeValueTableDataProcessor.emptyData(RowProperty.EP_BRK_DELIVERED_VALUE, totalColumn.get());
    brakeValueTableDataProcessor.emptyData(RowProperty.ED_BRK_REQ_VALUE, totalColumn.get());
    brakeValueTableDataProcessor.emptyData(RowProperty.CAR_WEIGHT_VALUE, totalColumn.get());

    updateServiceBrakeStatus();
    updateParkingBrakeStatus();
    updateWspStatus();
    updateSuspStatus();
    updateBecuStatus();
    updateTrainLineStatus();
    updateFsbStatus();
    updateEbStatus();
    updateHoldEpicStatus();
    updateEdCutRpressStatus();
    updateMainPipePressureStatus();
    updateBrakeCylinderPressureValue();
    updateAirSuspensionPressureValue();
    updateEpBrakeDeliveredValue();
    updateEdBrakeRequestedValue();
    updateCarWeightValue();
  }

  private void updateServiceBrakeStatus()
  {
    if (serviceBrakeStatusList != null)
    {
      brakeStatusTableDataProcessor.emptyData(RowProperty.SERVICE_BRAKE_STATUS, totalColumn.get());
      for (ServiceBrkStatus statusTableDO : serviceBrakeStatusList.getServiceBrkStatusList())
      {
        brakeStatusTableDataProcessor.updateData(RowProperty.SERVICE_BRAKE_STATUS,
            statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
            statusTableDO.getServiceBrkState1().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            statusTableDO.getServiceBrkState2().toString().toLowerCase());
        
        
      }
    }
  }

  private void updateParkingBrakeStatus()
  {
    if (parkingBrakeStatusList != null)
    {
      brakeStatusTableDataProcessor.emptyData(RowProperty.PARKING_BRAKE_STATUS, totalColumn.get());
      for (ParkingBrkStatus statusTableDO : parkingBrakeStatusList.getParkingBrkStatusList())
      {
        brakeStatusTableDataProcessor.updateData(RowProperty.PARKING_BRAKE_STATUS,
            statusTableDO.getCarIndex(), true, TCMSUIConstants.BLANK_STRING,
            statusTableDO.getParkingBrkState1().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            statusTableDO.getParkingBrkState2().toString().toLowerCase());
      }
    }
  }

  private void updateWspStatus()
  {
    if (wspStatusList != null)
    {
      wspSuspStatusTableDataProcessor.emptyData(RowProperty.WSP_STATUS, totalColumn.get());
      for (WSPStatus statusTableDO : wspStatusList.getWspStatusList())
      {
        wspSuspStatusTableDataProcessor.updateData(RowProperty.WSP_STATUS, statusTableDO.getCarIndex(), true,
            RowProperty.WSP_STATUS.getRowName(), statusTableDO.getWspState1().toString().toLowerCase(),
            RowProperty.WSP_STATUS.getRowName(), statusTableDO.getWspState2().toString().toLowerCase());
      }
    }
  }

  private void updateSuspStatus()
  {
    if (suspStatusList != null)
    {
      wspSuspStatusTableDataProcessor.emptyData(RowProperty.SUSP_STATUS, totalColumn.get());
      for (SUSPStatus statusTableDO : suspStatusList.getSuspStatusList())
      {
        wspSuspStatusTableDataProcessor.updateData(RowProperty.SUSP_STATUS, statusTableDO.getCarIndex(), true,
            RowProperty.SUSP_STATUS.getRowName(), statusTableDO.getSuspState1().toString().toLowerCase(),
            RowProperty.SUSP_STATUS.getRowName(), statusTableDO.getSuspState2().toString().toLowerCase());
      }
    }
  }

  private void updateBecuStatus()
  {
    if (brakeControlUnitStatusList != null)
    {
      brakeControlUnitStatusTableDataProcessor.emptyData(RowProperty.BRAKE_CONTROL_UNIT_STATUS,
          totalColumn.get());
      for (BrakeControlUnitStatus statusTableDO : brakeControlUnitStatusList.getBrakeControlUnitStatusList())
      {
        brakeControlUnitStatusTableDataProcessor.updateData(RowProperty.BRAKE_CONTROL_UNIT_STATUS,
            statusTableDO.getCarIndex(), false, TCMSUIConstants.BLANK_STRING,
            statusTableDO.getBrakeControlUnitState().toString().toLowerCase(), TCMSUIConstants.BLANK_STRING,
            TCMSUIConstants.NOT_APPLICABLE_CSS);
        
        
      }
    }
  }

 

  private void updateTrainLineStatus()
  {
    if (trainLineStatusList != null)
    {
      lineStatusTableDataProcessor.emptyData(RowProperty.TRAIN_LINE_STATUS, totalColumn.get());
      for (TrainLineStatus statusTableDO : trainLineStatusList.getTrainLineStatusList())
      {
        lineStatusTableDataProcessor.updateData(RowProperty.TRAIN_LINE_STATUS, statusTableDO.getCarIndex(),
            true, TCMSUIConstants.BRAKE_TRAIN_LINE_STATUS_LABEL,
            statusTableDO.getBrakeTrainLineState().toString().toLowerCase(),
            TCMSUIConstants.MOT_TRAIN_LINE_STATUS_LABEL,
            statusTableDO.getMotorTrainLineState().toString().toLowerCase());
        
        if (statusTableDO.getCarIndex() == 0)
        {
          if (statusTableDO.getBrakeTrainLineState().getNumber() == 2)
          {
            setBrakeTlBrake(1);
          }
          else
          {
            setBrakeTlBrake(0);
          }

        }
      }
    }
  }

  private void updateFsbStatus()
  {
    if (fullServiceBrakeLineStatusList != null)
    {
      lineStatusTableDataProcessor.emptyData(RowProperty.FSB_STATUS, totalColumn.get());
      for (FullServiceBrakeLineStatus statusTableDO : fullServiceBrakeLineStatusList
          .getFullServiceBrakeLineStatusList())
      {
        lineStatusTableDataProcessor.updateData(RowProperty.FSB_STATUS, statusTableDO.getCarIndex(), true,
            TCMSUIConstants.BRAKE_FSB_1_STATUS_LABEL,
            statusTableDO.getFullServiceBrakeLineState1().toString().toLowerCase(),
            TCMSUIConstants.BRAKE_FSB_2_STATUS_LABEL,
            statusTableDO.getFullServiceBrakeLineState2().toString().toLowerCase());
        
        if (statusTableDO.getCarIndex() == 0)
        {
          if (statusTableDO.getFullServiceBrakeLineState1().getNumber() == 2 || statusTableDO.getFullServiceBrakeLineState2().getNumber() == 2 )
          {
            setServiceBrake(1);
          }
          else
          {
            setServiceBrake(0);
          }

        }
      }
    }
  }

  private void updateEbStatus()
  {
    if (emergencyBrakeLineStatusList != null)
    {
      lineStatusTableDataProcessor.emptyData(RowProperty.EB_STATUS, totalColumn.get());
      for (EmergencyBrakeLineStatus statusTableDO : emergencyBrakeLineStatusList
          .getEmergencyBrakeLineStatusList())
      {
        lineStatusTableDataProcessor.updateData(RowProperty.EB_STATUS, statusTableDO.getCarIndex(), true,
            TCMSUIConstants.BRAKE_EB_1_STATUS_LABEL,
            statusTableDO.getEmergencyBrakeLineState1().toString().toLowerCase(),
            TCMSUIConstants.BRAKE_EB_2_STATUS_LABEL,
            statusTableDO.getEmergencyBrakeLineState2().toString().toLowerCase());

        if (statusTableDO.getCarIndex() == 0)
        {
          if (statusTableDO.getEmergencyBrakeLineState1().getNumber() == 2 || statusTableDO.getEmergencyBrakeLineState2().getNumber() == 2)
          {
            setEmergencyBrake(1);
          }
          else
          {
            setEmergencyBrake(0);
          }

        }
      }
    }
  }

  private void setEmergencyBrake(int ebValue)
  {
    //using EB 1 Line status
    this.emergencyBrakeState.set(ebValue);

  }
  
  private void setServiceBrake(int ebValue)
  {
  //using  BOGIE_1_SERVICE_BRAKE_STATUS
    this.fullBrakeState.set(ebValue);

  }

  public IntegerProperty getEmergencyBrake()
  {
    return emergencyBrakeState;
  }
  
  public IntegerProperty getServiceBrake()
  {
    return fullBrakeState;
  }
  
  private void setBrakeTlBrake(int brakeValue)
  {
    //using   BECU_STATUS
    brakeTlState.set(brakeValue);
    
  }
  
  public IntegerProperty getBrakeTlState()
  {
    return brakeTlState;
  }

  private void updateHoldEpicStatus()
  {
    if (holdingBrakeEpicIsolationStatusList != null)
    {
      holdEpicEdRpressStatusTableDataProcessor.emptyData(RowProperty.HOLD_EPIC_STATUS, totalColumn.get());
      for (HoldingBrakeEpicIsolationStatus statusTableDO : holdingBrakeEpicIsolationStatusList
          .getHoldingBrakeEpicIsolationStatusList())
      {
        holdEpicEdRpressStatusTableDataProcessor.updateData(RowProperty.HOLD_EPIC_STATUS,
            statusTableDO.getCarIndex(), true, TCMSUIConstants.HOLDING_BRAKE_STATUS_LABEL,
            statusTableDO.getHoldingBrakeState().toString().toLowerCase(), TCMSUIConstants.EPIC_STATUS_LABEL,
            statusTableDO.getEpicIsolationState().toString().toLowerCase());
      }
    }
  }

  private void updateEdCutRpressStatus()
  {
    if (edCutOutRpressStatusList != null)
    {
      holdEpicEdRpressStatusTableDataProcessor.emptyData(RowProperty.ED_CUT_RPRESS_STATUS, totalColumn.get());
      for (EDCutOutRpressIsolationStatus statusTableDO : edCutOutRpressStatusList
          .getEdCutOutRpressIsolationStatusList())
      {
        holdEpicEdRpressStatusTableDataProcessor.updateData(RowProperty.ED_CUT_RPRESS_STATUS,
            statusTableDO.getCarIndex(), true, TCMSUIConstants.ED_CUT_STATUS_LABEL,
            statusTableDO.getEdCutOutState().toString().toLowerCase(), TCMSUIConstants.RPRESS_STATUS_LABEL,
            statusTableDO.getRpressIsolationState().toString().toLowerCase());
      }
    }
  }

  private void updateMainPipePressureStatus()
  {
    if (mainPipePressureStatusList != null)
    {
      brakeValueTableDataProcessor.emptyData(RowProperty.AIR_PRESSURE_LABEL, totalColumn.get());
      brakeValueTableDataProcessor.emptyData(RowProperty.MAIN_PIPE_VALUE, totalColumn.get());
      for (MainPipePressureStatus statusTableDO : mainPipePressureStatusList.getMainPipePressureStatusList())
      {
        if ((statusTableDO.getCarIndex()) == 0)
        {
          brakeValueTableDataProcessor.updateData(RowProperty.AIR_PRESSURE_LABEL, statusTableDO.getCarIndex(),
              false, RowProperty.AIR_PRESSURE_LABEL.getRowName(),
              TCMSUIConstants.BRAKE_SCREEN_LABEL_HEADER_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
          brakeValueTableDataProcessor.updateData(RowProperty.MAIN_PIPE_VALUE, statusTableDO.getCarIndex(),
              true, RowProperty.MAIN_PIPE_VALUE.getRowName(), TCMSUIConstants.BRAKE_SCREEN_LABEL_1_CSS,
              String.valueOf(oneDecimalPointFormat.format(statusTableDO.getMainPipePressure())),
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          brakeValueTableDataProcessor.updateData(RowProperty.MAIN_PIPE_VALUE, statusTableDO.getCarIndex(),
              false, String.valueOf(oneDecimalPointFormat.format(statusTableDO.getMainPipePressure())),
              TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateBrakeCylinderPressureValue()
  {
    if (brakeCylinderPressureStatusList != null)
    {
      brakeValueTableDataProcessor.emptyData(RowProperty.CYLINDERS_VALUE, totalColumn.get());
      for (BrakeCylinderPressureStatus statusTableDO : brakeCylinderPressureStatusList
          .getBrakeCylinderPressureStatusList())
      {
        oneDecimalPointFormat.setRoundingMode(RoundingMode.DOWN);
        if ((statusTableDO.getCarIndex()) == 0)
        {
          brakeValueTableDataProcessor.updateData(RowProperty.CYLINDERS_VALUE, statusTableDO.getCarIndex(),
              true, RowProperty.CYLINDERS_VALUE.getRowName(), TCMSUIConstants.BRAKE_SCREEN_LABEL_1_CSS,
              String.valueOf(oneDecimalPointFormat.format(statusTableDO.getBogie1BrakeCylinderPressure()))
                  + "  " + //$NON-NLS-1$
                  (oneDecimalPointFormat.format(statusTableDO.getBogie2BrakeCylinderPressure())),
              TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS);
        }
        else
        {
          brakeValueTableDataProcessor.updateData(RowProperty.CYLINDERS_VALUE, statusTableDO.getCarIndex(),
              true,
              String.valueOf(oneDecimalPointFormat.format(statusTableDO.getBogie1BrakeCylinderPressure())),
              TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS,
              String.valueOf(oneDecimalPointFormat.format(statusTableDO.getBogie2BrakeCylinderPressure())),
              TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS);
        }
      }
    }
  }

  private void updateAirSuspensionPressureValue()
  {
    if (airSuspensionPressureStatusList != null)
    {
      brakeValueTableDataProcessor.emptyData(RowProperty.SUSPENS_VALUE, totalColumn.get());
      for (AirSuspensionPressureStatus statusTableDO : airSuspensionPressureStatusList
          .getAirSuspensionPressureStatusList())
      {
        if ((statusTableDO.getCarIndex()) == 0)
        {
          brakeValueTableDataProcessor.updateData(RowProperty.SUSPENS_VALUE, statusTableDO.getCarIndex(),
              true, RowProperty.SUSPENS_VALUE.getRowName(), TCMSUIConstants.BRAKE_SCREEN_LABEL_1_CSS,
              String.valueOf(oneDecimalPointFormat.format(statusTableDO.getAirSuspensionPressure())),
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          brakeValueTableDataProcessor.updateData(RowProperty.SUSPENS_VALUE, statusTableDO.getCarIndex(),
              false, String.valueOf(oneDecimalPointFormat.format(statusTableDO.getAirSuspensionPressure())),
              TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateEpBrakeDeliveredValue()
  {
    if (epBrakeDeliveredStatusList != null)
    {
      brakeValueTableDataProcessor.emptyData(RowProperty.EFFORTS_LABEL, totalColumn.get());
      brakeValueTableDataProcessor.emptyData(RowProperty.EP_BRK_DELIVERED_VALUE, totalColumn.get());
      for (EPBrakeDeliveredStatus statusTableDO : epBrakeDeliveredStatusList.getEpBrakeDeliveredStatusList())
      {
        if ((statusTableDO.getCarIndex()) == 0)
        {
          brakeValueTableDataProcessor.updateData(RowProperty.EFFORTS_LABEL, statusTableDO.getCarIndex(),
              false, RowProperty.EFFORTS_LABEL.getRowName(), TCMSUIConstants.BRAKE_SCREEN_LABEL_HEADER_CSS,
              TCMSUIConstants.BLANK_STRING, TCMSUIConstants.NOT_APPLICABLE_CSS);
          brakeValueTableDataProcessor.updateData(RowProperty.EP_BRK_DELIVERED_VALUE,
              statusTableDO.getCarIndex(), true, RowProperty.EP_BRK_DELIVERED_VALUE.getRowName(),
              TCMSUIConstants.BRAKE_SCREEN_LABEL_2_CSS,
              String.valueOf(statusTableDO.getEpBrakeDeliveredEffort()), TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          brakeValueTableDataProcessor.updateData(RowProperty.EP_BRK_DELIVERED_VALUE,
              statusTableDO.getCarIndex(), false, String.valueOf(statusTableDO.getEpBrakeDeliveredEffort()),
              TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateEdBrakeRequestedValue()
  {
    if (edBrakeRequestedStatusList != null)
    {
      brakeValueTableDataProcessor.emptyData(RowProperty.ED_BRK_REQ_VALUE, totalColumn.get());
      for (EDBrakeRequestedStatus statusTableDO : edBrakeRequestedStatusList.getEdBrakeRequestedStatusList())
      {
        if ((statusTableDO.getCarIndex()) == 0)
        {
          brakeValueTableDataProcessor.updateData(RowProperty.ED_BRK_REQ_VALUE, statusTableDO.getCarIndex(),
              true, RowProperty.ED_BRK_REQ_VALUE.getRowName(), TCMSUIConstants.BRAKE_SCREEN_LABEL_2_CSS,
              String.valueOf(statusTableDO.getEdBrakeRequestedEffort()), TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          brakeValueTableDataProcessor.updateData(RowProperty.ED_BRK_REQ_VALUE, statusTableDO.getCarIndex(),
              false, String.valueOf(statusTableDO.getEdBrakeRequestedEffort()),
              TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  private void updateCarWeightValue()
  {
    if (carWeightStatusList != null)
    {
      brakeValueTableDataProcessor.emptyData(RowProperty.CAR_WEIGHT_VALUE, totalColumn.get());
      for (CarWeightStatus statusTableDO : carWeightStatusList.getCarWeightStatusList())
      {
        if ((statusTableDO.getCarIndex()) == 0)
        {
          brakeValueTableDataProcessor.updateData(RowProperty.CAR_WEIGHT_VALUE, statusTableDO.getCarIndex(),
              true, RowProperty.CAR_WEIGHT_VALUE.getRowName(), TCMSUIConstants.BRAKE_SCREEN_LABEL_1_CSS,
              String.valueOf(oneDecimalPointFormat.format((statusTableDO.getCarWeight()))),
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
        else
        {
          brakeValueTableDataProcessor.updateData(RowProperty.CAR_WEIGHT_VALUE, statusTableDO.getCarIndex(),
              false, String.valueOf(oneDecimalPointFormat.format((statusTableDO.getCarWeight()))),
              TCMSUIConstants.TABLE_LABEL_NO_BORDER_CSS, TCMSUIConstants.BLANK_STRING,
              TCMSUIConstants.NOT_APPLICABLE_CSS);
        }
      }
    }
  }

  public void setServiceBrakeStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        serviceBrakeStatusList = TCMSProto.ServiceBrkStatusList.parseFrom(newValue);
        updateServiceBrakeStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setParkingBrakeStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        parkingBrakeStatusList = TCMSProto.ParkingBrkStatusList.parseFrom(newValue);
        updateParkingBrakeStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setWspStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        wspStatusList = TCMSProto.WSPStatusList.parseFrom(newValue);
        updateWspStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setSuspStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        suspStatusList = TCMSProto.SUSPStatusList.parseFrom(newValue);
        updateSuspStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setBecuStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        brakeControlUnitStatusList = TCMSProto.BrakeControlUnitStatusList.parseFrom(newValue);
        updateBecuStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setTrainLineStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        trainLineStatusList = TCMSProto.TrainLineStatusList.parseFrom(newValue);
        updateTrainLineStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setFsbStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        fullServiceBrakeLineStatusList = TCMSProto.FullServiceBrakeLineStatusList.parseFrom(newValue);
        updateFsbStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setEbStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        emergencyBrakeLineStatusList = TCMSProto.EmergencyBrakeLineStatusList.parseFrom(newValue);
        updateEbStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setHoldEpicStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        holdingBrakeEpicIsolationStatusList = TCMSProto.HoldingBrakeEpicIsolationStatusList
            .parseFrom(newValue);
        updateHoldEpicStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setEdCutRpresStatus(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        edCutOutRpressStatusList = TCMSProto.EDCutOutRPRESSIsolationStatusList.parseFrom(newValue);
        updateEdCutRpressStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setMainPipePressureValue(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        mainPipePressureStatusList = TCMSProto.MainPipePressureStatusList.parseFrom(newValue);
        updateMainPipePressureStatus();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setBrakeCylinderPressureValue(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        brakeCylinderPressureStatusList = TCMSProto.BrakeCylinderPressureStatusList.parseFrom(newValue);
        updateBrakeCylinderPressureValue();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setAirSuspensionPressureValue(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        airSuspensionPressureStatusList = TCMSProto.AirSuspensionPressureStatusList.parseFrom(newValue);
        updateAirSuspensionPressureValue();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setEDBrakeDeliveredValue(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        epBrakeDeliveredStatusList = TCMSProto.EPBrakeDeliveredStatusList.parseFrom(newValue);
        updateEpBrakeDeliveredValue();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setEDBrakeRequestedValue(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        edBrakeRequestedStatusList = TCMSProto.EDBrakeRequestedStatusList.parseFrom(newValue);
        updateEdBrakeRequestedValue();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  public void setCarWeightValue(byte[] newValue)
  {
    if (newValue.length != 0)
    {
      try
      {
        carWeightStatusList = TCMSProto.CarWeightStatusList.parseFrom(newValue);
        updateCarWeightValue();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
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
  public ObservableList<StatusTableDO> getbrakeStatusTableDataList()
  {
    return brakeStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getWspSuspStatusTableDataList()
  {
    return wspSuspStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getBrakeControlUnitStatusTableDataList()
  {
    return brakeControlUnitStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getLineStatusTableDataList()
  {
    return lineStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getHoldEpicEdRpressStatusTableDataList()
  {
    return holdEpicEdRpressStatusTableDataList;
  }

  /**
   * Gets the table data list.
   *
   * @return the table data list
   */
  public ObservableList<StatusTableDO> getBrakeValueTableDataList()
  {
    return brakeValueTableDataList;
  }

  /**
   * Enum to hold the rows for BRAKE status table with its name and unit and
   * cell alignment.
   */
  private enum RowProperty implements ITableRowProperty
  {
    SERVICE_BRAKE_STATUS(0, "", LEFT), //$NON-NLS-1$
    PARKING_BRAKE_STATUS(1, "", LEFT), //$NON-NLS-1$
    WSP_STATUS(0, "WSP", LEFT), //$NON-NLS-1$
    SUSP_STATUS(1, "SUSP", LEFT), //$NON-NLS-1$
    BRAKE_CONTROL_UNIT_STATUS(0, "", LEFT), //$NON-NLS-1$
    TRAIN_LINE_STATUS(0, "", LEFT), //$NON-NLS-1$
    FSB_STATUS(1, "", LEFT), //$NON-NLS-1$
    EB_STATUS(2, "", LEFT), //$NON-NLS-1$
    HOLD_EPIC_STATUS(0, "", LEFT), //$NON-NLS-1$
    ED_CUT_RPRESS_STATUS(1, "", LEFT), //$NON-NLS-1$
    AIR_PRESSURE_LABEL(0, "AIR PRESSURES [bar]", LEFT), //$NON-NLS-1$
    MAIN_PIPE_VALUE(1, "MAIN PIPE", LEFT), //$NON-NLS-1$
    CYLINDERS_VALUE(2, "CYLINDERS", LEFT), //$NON-NLS-1$
    SUSPENS_VALUE(3, "SUSPENS.", LEFT), //$NON-NLS-1$
    EFFORTS_LABEL(4, "EFFORTS [kN]", LEFT), //$NON-NLS-1$
    EP_BRK_DELIVERED_VALUE(5, "EP BRK DELIV", LEFT), //$NON-NLS-1$
    ED_BRK_REQ_VALUE(6, "ED BRK REQ", LEFT), //$NON-NLS-1$
    CAR_WEIGHT_VALUE(7, "WEIGHT [t]", LEFT); //$NON-NLS-1$

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
