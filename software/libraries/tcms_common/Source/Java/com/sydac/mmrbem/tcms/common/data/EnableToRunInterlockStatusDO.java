/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.common.data;

public class EnableToRunInterlockStatusDO
{
  private int carIndex;

  private int erHighVolatgeMissingState;

  private int erCabNotEnabledState;

  private int erDrivingModeNotOkState;

  private int erTrainDirectionMissingState;

  private int erAtcStatusState;

  private int erTrainReadyState;

  private int erManyRPressureState;

  private int erManyEpicCutoutState;

  private int erManyBogieIsolatedState;
  
  private int erMotoringTlState;
  
  private int erBrakeLoopTlState;
  
  private int erParkingBrakeTlState;
  
  private int erDoorLoopOpenTlState;
  
  private int erZvrdState;

 
  /**
   * @return the erHighVolatgeMissingState
   */
  public int getErHighVolatgeMissingState()
  {
    return erHighVolatgeMissingState;
  }

  /**
   * @param erHighVolatgeMissingState the erHighVolatgeMissingState to set
   */
  public void setErHighVolatgeMissingState(int erHighVolatgeMissingState)
  {
    this.erHighVolatgeMissingState = erHighVolatgeMissingState;
  }

  /**
   * @return the erCabNotEnabledState
   */
  public int getErCabNotEnabledState()
  {
    return erCabNotEnabledState;
  }

  /**
   * @param erCabNotEnabledState the erCabNotEnabledState to set
   */
  public void setErCabNotEnabledState(int erCabNotEnabledState)
  {
    this.erCabNotEnabledState = erCabNotEnabledState;
  }

  /**
   * @return the erDrivingModeNotOkState
   */
  public int getErDrivingModeNotOkState()
  {
    return erDrivingModeNotOkState;
  }

  /**
   * @param erDrivingModeNotOkState the erDrivingModeNotOkState to set
   */
  public void setErDrivingModeNotOkState(int erDrivingModeNotOkState)
  {
    this.erDrivingModeNotOkState = erDrivingModeNotOkState;
  }

  /**
   * @return the erTrainDirectionMissingState
   */
  public int getErTrainDirectionMissingState()
  {
    return erTrainDirectionMissingState;
  }

  /**
   * @param erTrainDirectionMissingState the erTrainDirectionMissingState to set
   */
  public void setErTrainDirectionMissingState(int erTrainDirectionMissingState)
  {
    this.erTrainDirectionMissingState = erTrainDirectionMissingState;
  }

  /**
   * @return the erAtcStatusState
   */
  public int getErAtcStatusState()
  {
    return erAtcStatusState;
  }

  /**
   * @param erAtcStatusState the erAtcStatusState to set
   */
  public void setErAtcStatusState(int erAtcStatusState)
  {
    this.erAtcStatusState = erAtcStatusState;
  }

  /**
   * @return the erTrainReadyState
   */
  public int getErTrainReadyState()
  {
    return erTrainReadyState;
  }

  /**
   * @param erTrainReadyState the erTrainReadyState to set
   */
  public void setErTrainReadyState(int erTrainReadyState)
  {
    this.erTrainReadyState = erTrainReadyState;
  }

  /**
   * @return the erManyRPressureState
   */
  public int getErManyRPressureState()
  {
    return erManyRPressureState;
  }

  /**
   * @param erManyRPressureState the erManyRPressureState to set
   */
  public void setErManyRPressureState(int erManyRPressureState)
  {
    this.erManyRPressureState = erManyRPressureState;
  }

  /**
   * @return the erManyEpicCutoutState
   */
  public int getErManyEpicCutoutState()
  {
    return erManyEpicCutoutState;
  }

  /**
   * @param erManyEpicCutoutState the erManyEpicCutoutState to set
   */
  public void setErManyEpicCutoutState(int erManyEpicCutoutState)
  {
    this.erManyEpicCutoutState = erManyEpicCutoutState;
  }

  /**
   * @return the erManyBogieIsolatedState
   */
  public int getErManyBogieIsolatedState()
  {
    return erManyBogieIsolatedState;
  }

  /**
   * @param erManyBogieIsolatedState the erManyBogieIsolatedState to set
   */
  public void setErManyBogieIsolatedState(int erManyBogieIsolatedState)
  {
    this.erManyBogieIsolatedState = erManyBogieIsolatedState;
  }

  /**
   * @return the erMotoringTlState
   */
  public int getErMotoringTlState()
  {
    return erMotoringTlState;
  }

  /**
   * @param erMotoringTlState the erMotoringTlState to set
   */
  public void setErMotoringTlState(int erMotoringTlState)
  {
    this.erMotoringTlState = erMotoringTlState;
  }

  /**
   * @return the erBrakeLoopTlState
   */
  public int getErBrakeLoopTlState()
  {
    return erBrakeLoopTlState;
  }

  /**
   * @param erBrakeLoopTlState the erBrakeLoopTlState to set
   */
  public void setErBrakeLoopTlState(int erBrakeLoopTlState)
  {
    this.erBrakeLoopTlState = erBrakeLoopTlState;
  }

  /**
   * @return the erParkingBrakeTlState
   */
  public int getErParkingBrakeTlState()
  {
    return erParkingBrakeTlState;
  }

  /**
   * @param erParkingBrakeTlState the erParkingBrakeTlState to set
   */
  public void setErParkingBrakeTlState(int erParkingBrakeTlState)
  {
    this.erParkingBrakeTlState = erParkingBrakeTlState;
  }

  /**
   * @return the erDoorLoopOpenTlState
   */
  public int getErDoorLoopOpenTlState()
  {
    return erDoorLoopOpenTlState;
  }

  /**
   * @param erDoorLoopOpenTlState the erDoorLoopOpenTlState to set
   */
  public void setErDoorLoopOpenTlState(int erDoorLoopOpenTlState)
  {
    this.erDoorLoopOpenTlState = erDoorLoopOpenTlState;
  }

  public int getCarIndex()
  {
    return carIndex;
  }

  public void setCarIndex(int carIndex)
  {
    this.carIndex = carIndex;
  }

  public int getErZvrdState()
  {
    return erZvrdState;
  }

  public void setErZvrdState(int erZvrdState)
  {
    this.erZvrdState = erZvrdState;
  }

 

}
