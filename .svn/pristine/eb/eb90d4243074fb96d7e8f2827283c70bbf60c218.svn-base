/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.logic;

import java.util.Objects;

import org.springframework.stereotype.Service;

import com.sydac.foundation.Model;


/**
 * The Class SharedDataModel is observable data model, used to share data
 * between the logic functionality.
 */
@Service
public class SharedDataModel extends Model
{
  private Property<Integer> screenId = new Property<>(Change.SCREEN_ID, 0);

  private Property<Integer> popupId = new Property<>(Change.POPUP_ID, 0);

  private Property<String> trainId = new Property<>(Change.TRAIN_ID, "0"); //$NON-NLS-1$

  private Property<Integer> startStationId = new Property<>(Change.START_STATION_ID, 0);

  private Property<Integer> nextStationId = new Property<>(Change.NEXT_STATION_ID, 0);

  private Property<Integer> terminalStationId = new Property<>(Change.TERMINAL_STATION_ID, 0);

  private Property<Integer> currentStationId = new Property<>(Change.CURRENT_STATION_ID, 0);

  private Property<Integer> routeId = new Property<>(Change.ROUTE_ID, -1);
  
  private Property<Integer> totalCar = new Property<>(Change.SCREEN_ID, -1);

  public SharedDataModel()
  {

  }

  public int getScreenId()
  {
    return screenId.getValue();
  }

  public void setScreenId(Integer screenId)
  {
    this.screenId.setValue(screenId);
  }

  public int getPopupId()
  {
    return popupId.getValue();
  }

  public void setPopupId(Integer popupId)
  {
    this.popupId.setValue(popupId);
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
  public void setTotalCar(int totalCar)
  {
    this.totalCar.setValue(totalCar);
  }

  public enum Change
  {
    SCREEN_ID, POPUP_ID, TRAIN_ID, ROUTE_ID, START_STATION_ID, NEXT_STATION_ID, TERMINAL_STATION_ID, CURRENT_STATION_ID;
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

}
