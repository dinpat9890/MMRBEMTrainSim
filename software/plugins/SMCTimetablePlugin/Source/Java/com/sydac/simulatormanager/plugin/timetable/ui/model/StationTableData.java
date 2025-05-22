/**
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable.ui.model;

import com.sydac.simulatormanager.scenariobuilder.model.TableEditModel.TableData;

public class StationTableData extends TableData
{
  private Integer sequence;

  private String stationName;

  private long arrivalTime;

  private long departureTime;
  
  private Integer stationID;

  public StationTableData(Integer sequence, String stationName, long arrivalTime, long departureTime,Integer stationID)
  {
    super();
    this.sequence = sequence;
    this.stationName = stationName;
    this.arrivalTime = arrivalTime;
    this.departureTime = departureTime;
    this.stationID = stationID;
  }

  public StationTableData()
  {    
  }

  public String getStationName()
  {
    return stationName;
  }

  public void setStationName(String stationName)
  {
    this.stationName = stationName;
  }

  public Integer getSequence()
  {
    return sequence;
  }

  public void setSequence(Integer sequence)
  {
    this.sequence = sequence;
  }

  public long getDepartureTime()
  {
    return departureTime;
  }

  public void setDepartureTime(long departureTime)
  {
    this.departureTime = departureTime;
  }

  public long getArrivalTime()
  {
    return arrivalTime;
  }

  public void setArrivalTime(long arrivalTime)
  {
    this.arrivalTime = arrivalTime;
  }

  public Integer getStationID()
  {
    return stationID;
  }

  public void setStationID(Integer stationID)
  {
    this.stationID = stationID;
  }

}
