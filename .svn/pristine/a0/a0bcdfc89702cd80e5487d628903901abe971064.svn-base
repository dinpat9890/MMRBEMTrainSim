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
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EnableToRunList;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EnableToRunList.ERState;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EnableToRunList.EnableToRunStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EbInterlockData.EbInterlockStatus;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.EbInterlockData.EbState;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class EnableToRunInterlockScreenModel extends AbstractScreenModel
{
  private EnableToRunList erInterlockData;

  private final StringProperty erHighVolatgeMissingState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erCabNotEnabledState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erDrivingModeNotOkState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erTrainDirectionMissingState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erAtcStatusState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erTrainReadyState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erManyRPressureState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erManyEpicCutoutState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erManyBogieIsolatedState = new SimpleStringProperty(); // $NON-NLS-1$

  private final StringProperty erMotoringTlState = new SimpleStringProperty(); // $NON-NLS-1$

  private final IntegerProperty lastVehicleId = new SimpleIntegerProperty(); // $NON-NLS-1$

  private final StringProperty erBrakeLoopTlState = new SimpleStringProperty();

  private final StringProperty erParkingBrakeTlState = new SimpleStringProperty();

  private final StringProperty erDoorLoopOpenTlState = new SimpleStringProperty();

  private final StringProperty erZvrdFirstCarState = new SimpleStringProperty();

  private final StringProperty erZvrdLastCarState = new SimpleStringProperty();

  public EnableToRunInterlockScreenModel(int carIndex)
  {
    super(carIndex);
  }

  public IntegerProperty getLastVehicleId()
  {
    return lastVehicleId;
  }

  public void setEnableRunInterlockState(byte[] enableToRunList)
  {
    if (enableToRunList.length != 0)
    {
      try
      {
        erInterlockData = TCMSProto.EnableToRunList.parseFrom(enableToRunList);
        updateEnableRunState();
      }
      catch (InvalidProtocolBufferException e)
      {
        Tracer.getInstance().error(e);
      }
    }
  }

  /**
   * @return the erInterlockData
   */
  public EnableToRunList getErInterlockData()
  {
    return erInterlockData;
  }

  /**
   * @param erInterlockData
   *          the erInterlockData to set
   */
  public void setErInterlockData(EnableToRunList erInterlockData)
  {
    this.erInterlockData = erInterlockData;
  }

  /**
   * @return the erHighVolatgeMissingState
   */
  public StringProperty getErHighVolatgeMissingState()
  {
    return erHighVolatgeMissingState;
  }

  /**
   * @return the erCabNotEnabledState
   */
  public StringProperty getErCabNotEnabledState()
  {
    return erCabNotEnabledState;
  }

  /**
   * @return the erDrivingModeNotOkState
   */
  public StringProperty getErDrivingModeNotOkState()
  {
    return erDrivingModeNotOkState;
  }

  /**
   * @return the erTrainDirectionMissingState
   */
  public StringProperty getErTrainDirectionMissingState()
  {
    return erTrainDirectionMissingState;
  }

  /**
   * @return the erAtcStatusState
   */
  public StringProperty getErAtcStatusState()
  {
    return erAtcStatusState;
  }

  /**
   * @return the erTrainReadyState
   */
  public StringProperty getErTrainReadyState()
  {
    return erTrainReadyState;
  }

  /**
   * @return the erManyRPressureState
   */
  public StringProperty getErManyRPressureState()
  {
    return erManyRPressureState;
  }

  /**
   * @return the erManyEpicCutoutState
   */
  public StringProperty getErManyEpicCutoutState()
  {
    return erManyEpicCutoutState;
  }

  /**
   * @return the erManyBogieIsolatedState
   */
  public StringProperty getErManyBogieIsolatedState()
  {
    return erManyBogieIsolatedState;
  }

  /**
   * @return the erMotoringTlState
   */
  public StringProperty getErMotoringTlState()
  {
    return erMotoringTlState;
  }

  /**
   * @return the erBrakeLoopTlState
   */
  public StringProperty getErBrakeLoopTlState()
  {
    return erBrakeLoopTlState;
  }

  /**
   * @return the erParkingBrakeTlState
   */
  public StringProperty getErParkingBrakeTlState()
  {
    return erParkingBrakeTlState;
  }

  /**
   * @return the erDoorLoopOpenTlState
   */
  public StringProperty getErDoorLoopOpenTlState()
  {
    return erDoorLoopOpenTlState;
  }

  /**
   * @return the erZvrdFirstState
   */
  public StringProperty getErZvrdFirstCarState()
  {
    return erZvrdFirstCarState;
  }

  /**
   * @return the erZvrdLastState
   */
  public StringProperty getErZvrdLastCarState()
  {
    return erZvrdLastCarState;
  }

  private void updateEnableRunState()
  {
    if (erInterlockData != null)
    {
      boolean isErHighVolatgeMissingState = false;
      boolean isErCabNotEnabledState = false;
      boolean isErDrivingModeNotOkState = false;
      boolean isErTrainDirectionMissingState = false;
      boolean isErAtcStatusState = false;
      boolean isErTrainReadyState = false;
      boolean isErManyRPressureState = false;
      boolean isErManyEpicCutoutState = false;
      boolean isErManyBogieIsolatedState = false;
      boolean isErMotoringTlState = false;
      boolean isErBrakeLoopTlState = false;
      boolean isErParkingBrakeTlState = false;
      boolean isErDoorLoopOpenTlState = false;
      boolean isErZvrdFirstCarState = false;
      boolean isErZvrdLastCarState = false;
      for (EnableToRunStatus status : erInterlockData.getEnableToRunStatusList())
      {

        if ((status.getCarIndex() == 0))
        {
          if (ERState.ACTIVE.equals(status.getErHighVolatgeMissing()))
          {
            isErHighVolatgeMissingState = true;
          }
          if (ERState.ACTIVE.equals(status.getErCabNotEnabled()))
          {
            isErCabNotEnabledState = true;
          }
          if (ERState.ACTIVE.equals(status.getErDrivingModeNotOk()))
          {
            isErDrivingModeNotOkState = true;
          }
          if (ERState.ACTIVE.equals(status.getErTrainDirectionMissing()))
          {
            isErTrainDirectionMissingState = true;
          }
          if (ERState.ACTIVE.equals(status.getErAtcStatus()))
          {
            isErAtcStatusState = true;
          }
          if (ERState.ACTIVE.equals(status.getErTrainReady()))
          {
            isErTrainReadyState = true;
          }
          if (ERState.ACTIVE.equals(status.getErManyRPressure()))
          {
            isErManyRPressureState = true;
          }
          if (ERState.ACTIVE.equals(status.getErManyEpicCutout()))
          {
            isErManyEpicCutoutState = true;
          }
          if (ERState.ACTIVE.equals(status.getErManyBogieIsolated()))
          {
            isErManyBogieIsolatedState = true;
          }
          if (ERState.ACTIVE.equals(status.getErMotoringTl()))
          {
            isErMotoringTlState = true;
          }
          if (ERState.ACTIVE.equals(status.getErBrakeLoopTl()))
          {
            isErBrakeLoopTlState = true;
          }
          if (ERState.ACTIVE.equals(status.getErParkingBrakeTl()))
          {
            isErParkingBrakeTlState = true;
          }
          if (ERState.ACTIVE.equals(status.getErDoorLoopOpenTl()))
          {
            isErDoorLoopOpenTlState = true;
          }
        }

        if ((status.getCarIndex() == 0) && (ERState.ACTIVE.equals(status.getErZvrdNotActive())))
        {
          isErZvrdFirstCarState = true;
        }

        else if ((status.getCarIndex() == erInterlockData.getEnableToRunStatusList().size() - 1)
            && (ERState.ACTIVE.equals(status.getErZvrdNotActive())))
        {

          isErZvrdLastCarState = true;
        }

      }
      lastVehicleId.setValue(erInterlockData.getEnableToRunStatusList().size());

      updatedHighVolatgeMissing(isErHighVolatgeMissingState);
      updatedCabNotEnabled(isErCabNotEnabledState);
      updatedDrivingMode(isErDrivingModeNotOkState);
      updatedTrainDirectionMissing(isErTrainDirectionMissingState);
      updatedAtcStatus(isErAtcStatusState);
      updatedTrainReady(isErTrainReadyState);
      updatedManyRPressure(isErManyRPressureState);
      updatedEpicCutout(isErManyEpicCutoutState);
      updatedBogieIsolated(isErManyBogieIsolatedState);
      updatedMotoringTl(isErMotoringTlState);
      updatedBrakeLoopTl(isErBrakeLoopTlState);
      updatedParkingBrakeTl(isErParkingBrakeTlState);
      updatedDoorLoopOpenTl(isErDoorLoopOpenTlState);
      updatedZvrdFirstCarState(isErZvrdFirstCarState);
      updatedZvrdLastCarState(isErZvrdLastCarState);
    }
  }

  private void updatedHighVolatgeMissing(boolean isHighVolatgeMissing)
  {
    if (isHighVolatgeMissing)
    {
      erHighVolatgeMissingState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erHighVolatgeMissingState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedCabNotEnabled(boolean isCabNotEnabled)
  {
    if (isCabNotEnabled)
    {
      erCabNotEnabledState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erCabNotEnabledState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedDrivingMode(boolean isDrivingMode)
  {
    if (isDrivingMode)
    {
      erDrivingModeNotOkState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erDrivingModeNotOkState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedTrainDirectionMissing(boolean isTrainDirectionMissing)
  {
    if (isTrainDirectionMissing)
    {
      erTrainDirectionMissingState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erTrainDirectionMissingState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedAtcStatus(boolean isAtcStatus)
  {
    if (isAtcStatus)
    {
      erAtcStatusState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erAtcStatusState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedTrainReady(boolean isTrainReady)
  {
    if (isTrainReady)
    {
      erTrainReadyState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erTrainReadyState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedManyRPressure(boolean isManyRPressure)
  {
    if (isManyRPressure)
    {
      erManyRPressureState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erManyRPressureState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedEpicCutout(boolean isEpicCutout)
  {
    if (isEpicCutout)
    {
      erManyEpicCutoutState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erManyEpicCutoutState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedBogieIsolated(boolean isBogieIsolated)
  {
    if (isBogieIsolated)
    {
      erManyBogieIsolatedState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erManyBogieIsolatedState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedMotoringTl(boolean isMotoringTl)
  {
    if (isMotoringTl)
    {
      erMotoringTlState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erMotoringTlState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedBrakeLoopTl(boolean isBrakeLoopTl)
  {
    if (isBrakeLoopTl)
    {
      erBrakeLoopTlState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erBrakeLoopTlState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedParkingBrakeTl(boolean isParkingBrakeTl)
  {
    if (isParkingBrakeTl)
    {
      erParkingBrakeTlState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erParkingBrakeTlState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedDoorLoopOpenTl(boolean isDoorLoopOpenTl)
  {
    if (isDoorLoopOpenTl)
    {
      erDoorLoopOpenTlState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erDoorLoopOpenTlState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedZvrdFirstCarState(boolean isZvrdFirstCarState)
  {
    if (isZvrdFirstCarState)
    {
      erZvrdFirstCarState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erZvrdFirstCarState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }
  }

  private void updatedZvrdLastCarState(boolean isErZvrdLastCarState)
  {

    if (isErZvrdLastCarState)
    {
      erZvrdLastCarState.setValue(ERState.ACTIVE.toString().toLowerCase());
    }
    else
    {
      erZvrdLastCarState.setValue(ERState.NOT_ACTIVE.toString().toLowerCase());
    }

  }

}
