/*
 * ==================================================================
 * 
 * (C) Copyright 2020 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.logic;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

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

  private Set<Integer> f1F2CarSet = new HashSet<>();

  private Set<Integer> carType_MC1 = new HashSet<>();

  private Set<Integer> carType_MC1_TP_MSC1 = new HashSet<>();

  private int trainId;

  private Set<Integer> carType_MC1_MSC1 = new HashSet<>();

  private String serviceNumber;
  
  private String softwareVersion;

  public SharedDataModel()
  {
    // f1F2CarSet.add(1);
    // f1F2CarSet.add(3);
    // Not Required.
  }

  public int getTrainId()
  {
    return trainId;
  }

  public void setTrainId(int trainId)
  {
    this.trainId = trainId;
  }

  public Set<Integer> getF1F2CarSet()
  {
    return f1F2CarSet;
  }

  public Set<Integer> getMc1CarSet()
  {
    return carType_MC1;
  }

  public Set<Integer> getMc1_TP_MCS1CarSet()
  {
    return carType_MC1_TP_MSC1;
  }

  public Set<Integer> getMc1_MCS1CarSet()
  {
    return carType_MC1_MSC1;
  }

  public int getScreenId()
  {
    return screenId.getValue();
  }

  public void setScreenId(Integer screenId)
  {
    this.screenId.setValue(screenId);
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
    SCREEN_ID, TMS_STATE;
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

  public void setServiceNumber(String tripNumber)
  {
    serviceNumber = tripNumber;
  }

  public String getServiceNumber()
  {
    return serviceNumber;
  }

  /**
   * @return the softwareVersion
   */
  public String getSoftwareVersion()
  {
    return softwareVersion;
  }

  /**
   * @param softwareVersion the softwareVersion to set
   */
  public void setSoftwareVersion(String softwareVersion)
  {
    this.softwareVersion = softwareVersion;
  }
  
  

}
