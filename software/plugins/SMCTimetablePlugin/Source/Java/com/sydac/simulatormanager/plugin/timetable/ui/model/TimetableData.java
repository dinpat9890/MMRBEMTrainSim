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

import java.util.ArrayList;
import java.util.List;

import com.sydac.simulatormanager.plugin.timetable.constants.TimetableConstants;
import com.sydac.simulatormanager.scenariobuilder.model.TableEditModel.TableData;

/**
 * Represents a Performance Parameter.
 * 
 * @author patanges
 *
 */
public class TimetableData extends TableData
{
  /* The Id field. Loaded from database */
  private Integer id;

  /* The Scenario Id field. Loaded from database */
  private Integer scenarioId;

  /* The Unit . Loaded from configuration file */
  private String name;

  /* The targeted value . User entered value */
  private String routeCode;

  /* Full penalty value. User entered value */
  private String lineName;

  /* Minimum penalty points. User entered value */
  private String startStationName;

  /* Maximum penalty applied . User entered value */
  private String endStationName;

  private List<StationTableData> stationDataList;

  public TimetableData()
  {
    this.id = null;
    this.scenarioId = null;
    this.name = TimetableConstants.BLANK;
    this.routeCode = TimetableConstants.BLANK;
    this.lineName = TimetableConstants.BLANK;
    this.startStationName = TimetableConstants.BLANK;
    this.endStationName = TimetableConstants.BLANK;
    this.setStationDataList(new ArrayList<>());
  }

  /**
   * @return the id
   */
  public Integer getId()
  {
    return id;
  }

  /**
   * @param id
   *          the id to set
   */
  public void setId(Integer id)
  {
    this.id = id;
  }

  /**
   * @return the scenarioId
   */
  public Integer getScenarioId()
  {
    return scenarioId;
  }

  /**
   * @param scenarioId
   *          the scenarioId to set
   */
  public void setScenarioId(Integer scenarioId)
  {
    this.scenarioId = scenarioId;
  }

  /**
   * @return the routeCode
   */
  public String getRouteCode()
  {
    return routeCode;
  }

  /**
   * @param routeCode
   *          the routeCode to set
   */
  public void setRouteCode(String routeCode)
  {
    this.routeCode = routeCode;
  }

  /**
   * @return the LineName
   */
  public String getLineName()
  {
    return lineName;
  }

  /**
   * @param lineName
   *          the lineName to set
   */
  public void setLineName(String lineName)
  {
    this.lineName = lineName;
  }

  /**
   * @return the unit
   */
  public String getName()
  {
    return name;
  }

  /**
   * @param name
   *          the Name to set
   */
  public void setName(String name)
  {
    this.name = name;
  }

  /**
   * @return the StartStationName
   */
  public String getStartStationName()
  {
    return startStationName;
  }

  /**
   * @param startStationName
   *          the StartStationName to set
   */
  public void setStartStationName(String startStationName)
  {
    this.startStationName = startStationName;
  }

  /**
   * @return the endStationName
   */
  public String getEndStationName()
  {
    return endStationName;
  }

  /**
   * @param endStationName
   *          the EndStationName to set
   */
  public void setEndStationName(String endStationName)
  {
    this.endStationName = endStationName;
  }

  /*
   * (non-Javadoc)
   * 
   * @see java.lang.Object#hashCode()
   */
  @Override
  public int hashCode()
  {
    final int prime = 31;
    int result = 1;
     result = prime * result + ((name == null) ? 0 : name.hashCode());
    return result;
  }

  /*
   * (non-Javadoc)
   * 
   * @see java.lang.Object#equals(java.lang.Object)
   */
  @Override
  public boolean equals(Object obj)
  {
    if (this == obj)
      return true;
    if (obj == null)
      return false;
    if (getClass() != obj.getClass())
      return false;

    TimetableData other = (TimetableData)obj;
    if (name == null)
    {
      if (other.name != null)
        return false;
    }
    else if (!name.equals(other.name))
      return false;

    return true;
  }

  public List<StationTableData> getStationDataList()
  {
    return stationDataList;
  }

  public void setStationDataList(List<StationTableData> stationDataList)
  {
    this.stationDataList = stationDataList;
  }

}
