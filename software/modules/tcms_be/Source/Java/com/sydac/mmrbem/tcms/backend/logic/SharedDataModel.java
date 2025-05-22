/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

import org.springframework.stereotype.Service;

import com.sydac.foundation.Model;
import com.sydac.mmrbem.tcms.common.data.VehicleDetailModel;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.utils.SpeedUnitConverter;

/**
 * The Class SharedDataModel is observable data model, used to share data
 * between the logic functionality.
 */
@Service
public class SharedDataModel extends Model
{
  private Property<Integer> tcmsScreenId = new Property<>(Change.TCMS_SCREEN_ID, 0);

  private Property<Integer> totalCar = new Property<>(Change.TCMS_SCREEN_ID, -1);

  private Property<Integer> tcmsPopupId = new Property<>(Change.TCMS_POPUP_ID, 0);

  private Property<Integer> cctvScreenId = new Property<>(Change.CCTV_SCREEN_ID, 0);

  private Property<Integer> cctvPopupId = new Property<>(Change.CCTV_POPUP_ID, 0);

  private Property<String> trainId = new Property<>(Change.TRAIN_ID, "0"); //$NON-NLS-1$

  private Property<Integer> startStationId = new Property<>(Change.START_STATION_ID, 0);

  private Property<Integer> nextStationId = new Property<>(Change.NEXT_STATION_ID, 0);

  private Property<Integer> terminalStationId = new Property<>(Change.TERMINAL_STATION_ID, 0);

  private Property<Integer> currentStationId = new Property<>(Change.CURRENT_STATION_ID, 0);

  private Property<Integer> routeId = new Property<>(Change.ROUTE_ID, -1);

  private Property<Integer> vduSelectedMode = new Property<>(Change.VDU_SELECTED_MODE_ID, -1);

  private Property<Integer> cctvVduSelectedMode = new Property<>(Change.VDU_SELECTED_MODE_ID, -1);

  private String userId = ApplicationConstants.BLANK;
  
  private String routeTrainId = ApplicationConstants.BLANK;

  private String trainName;

  private int totalVehicles;

  private int standByScreenTime;

  private int currentActiveCabId = 0;

  /** Vehicle detail model list. */
  private Property<List<VehicleDetailModel>> vehicleDetailModelList = new Property<>(Change.TRAIN_CONFIGURED,
      new ArrayList<>());

  private SpeedUnitConverter speedUnitConverter = new SpeedUnitConverter();

  public int getTcmsScreenId()
  {
    return tcmsScreenId.getValue();
  }

  public void setTcmsScreenId(Integer screenId)
  {
    this.tcmsScreenId.setValue(screenId);
  }

  public int getTcmsPopupId()
  {
    return tcmsPopupId.getValue();
  }

  public void setTcmsPopupId(Integer popupId)
  {
    this.tcmsPopupId.setValue(popupId);
  }

  public int getCctvScreenId()
  {
    return cctvScreenId.getValue();
  }

  public void setCctvScreenId(Integer screenId)
  {
    this.cctvScreenId.setValue(screenId);
  }

  public int getCctvPopupId()
  {
    return cctvPopupId.getValue();
  }

  public void setCctvPopupId(Integer popupId)
  {
    this.cctvPopupId.setValue(popupId);
  }

  public String getUserId()
  {
    return userId;
  }

  public void setUserId(String userId)
  {
    this.userId = userId;
  }

  public void setCurrentActiveCabId(Integer activeCabId)
  {
    this.currentActiveCabId = activeCabId;
  }

  public int getCurrentActiveCabId()
  {
    return currentActiveCabId;
  }

  /**
   * Get total car there in current scenario
   * 
   * @return total car
   */
  public int getTotalCar()
  {
    return totalCar.getValue();
  }

  /**
   * Set total car there in current scenario
   * 
   * @param totalCar
   *          total car
   */
  public void setTotalCar(Integer totalCar)
  {
    this.totalCar.setValue(totalCar);
  }

  public String getTrainId()
  {
    return trainId.getValue();
  }

  public void setTrainId(String trainId)
  {
    this.trainId.setValue(trainId);
  }

  public int getStartStationId()
  {
    return startStationId.getValue();
  }

  public void setStartStationId(Integer startStationId)
  {
    this.startStationId.setValue(startStationId);
  }

  public int getNextStationId()
  {
    return nextStationId.getValue();
  }

  public void setNextStationId(Integer nextStationId)
  {
    this.nextStationId.setValue(nextStationId);
  }

  public int getTerminalStationId()
  {
    return terminalStationId.getValue();
  }

  public void setTerminalStationId(Integer terminalStationId)
  {
    this.terminalStationId.setValue(terminalStationId);
  }

  public int getRouteId()
  {
    return routeId.getValue();
  }

  public void setRouteId(Integer routeId)
  {
    this.routeId.setValue(routeId);
  }

  public int getCurrentStationId()
  {
    return currentStationId.getValue();
  }

  public void setCurrentStationId(Integer currentStationId)
  {
    this.currentStationId.setValue(currentStationId);
  }

  public String getTrainName()
  {
    return trainName;
  }

  public void setTrainName(String trainName)
  {
    this.trainName = trainName;
  }

  public int getTotalVehicles()
  {
    return totalVehicles;
  }

  public void setTotalVehicles(int totalVehicles)
  {
    this.totalVehicles = totalVehicles;
  }

  public int getStandByScreenTime()
  {
    return standByScreenTime;
  }

  public void setStandByScreenTime(int standByScreenTime)
  {
    this.standByScreenTime = standByScreenTime;
  }

  @Override
  protected void onCreate()
  {
    // No action necessary
  }

  @Override
  protected void onDestroy()
  {
    // No action necessary
  }

  public enum Change
  {
    TCMS_SCREEN_ID, TCMS_POPUP_ID, TRAIN_CONFIGURED, CCTV_SCREEN_ID, CCTV_POPUP_ID, TRAIN_ID, ROUTE_ID, START_STATION_ID, NEXT_STATION_ID, TERMINAL_STATION_ID, CURRENT_STATION_ID, VDU_SELECTED_MODE_ID;
  }

  public class Property<T>
  {
    private final Enum<?> change;

    private T value;

    public Property(Enum<?> aChange, T aInitial)
    {
      change = aChange;
      value = aInitial;
    }

    public Property(Enum<?> aChange)
    {
      change = aChange;
    }

    public void setValue(T newValue)
    {
      if (!Objects.equals(value, newValue))
      {
        value = newValue;
        fireModelChangedEvent(change);
      }
    }

    public T getValue()
    {
      return value;
    }
  }

  /**
   * Returns vehicle detail model list.
   * 
   * @return list of {@link VehicleDetailModel}
   */
  public List<VehicleDetailModel> getVehicleDetailModelList()
  {
    return vehicleDetailModelList.getValue();
  }

  /**
   * Sets vehicle detail model list.
   * 
   * @param vehicleDetailModelList
   *          list of {@link VehicleDetailModel}
   */
  public void setVehicleDetailModelList(List<VehicleDetailModel> vehicleDetailModelList)
  {
    this.vehicleDetailModelList.setValue(vehicleDetailModelList);
  }

  public int getSpeedInKMPH(double newValue)
  {
    return Integer.parseInt(speedUnitConverter.convertToFormatted(newValue));
  }

  public Double getOdometerInKm(double newValue)
  {
    return newValue / 1000;
  }

  public int getWeightInTon(int newValue)
  {
    return newValue / 1000;
  }

  public Double getVoltagetInKV(double newValue)
  {
    return newValue / 1000;
  }

  public Integer getVduSelectedMode()
  {
    return vduSelectedMode.getValue();
  }

  public void setVduSelectedMode(Integer vduSelectedMode)
  {
    this.vduSelectedMode.setValue(vduSelectedMode);
  }

  public Integer getCctvVduSelectedMode()
  {
    return cctvVduSelectedMode.getValue();
  }

  public void setCctvVduSelectedMode(Integer cctvVduSelectedMode)
  {
    this.cctvVduSelectedMode.setValue(cctvVduSelectedMode);
  }
  
  public String getRouteTrainId()
  {
    return routeTrainId;
  }

  public void setRouteTrainId(String id)
  {
    this.routeTrainId = id;
  }

}
