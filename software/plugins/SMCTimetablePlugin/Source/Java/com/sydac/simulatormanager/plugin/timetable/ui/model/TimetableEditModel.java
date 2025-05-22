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
import java.util.Comparator;
import java.util.List;
import java.util.Optional;

import com.sydac.common.dataobjects.timetable.DBRoute;
import com.sydac.common.dataobjects.timetable.DBRoute.DBRouteManager;
import com.sydac.foundation.Model;
import com.sydac.simulatormanager.plugin.timetable.constants.TimetableConstants;

/**
 * Model class for scenario timetables.
 *
 */
public class TimetableEditModel extends Model
{
  private List<StationTableData> stationTableData;

  private String timeTableName;

  private String lineName;

  private String routeCode;

  private TimetableData timeTableData;

  /**
   * change constants enumerated.
   */
  public enum Change
  {
    LINE_NAME_CHANGE,
    TABLE_NAME_CHANGE,
    STATION_DATA_CHANGE,
    ROUTE_CODE_CHANGE

  } // Change

  @Override
  protected void onCreate()
  {
    timeTableData = new TimetableData();
    stationTableData = new ArrayList<>();
    setStationTableData(new ArrayList<>());
    setTimeTableName(TimetableConstants.BLANK);
    setLineName(TimetableConstants.BLANK);
    setRouteCode(TimetableConstants.BLANK);
  }

  @Override
  protected void onDestroy()
  {
    stationTableData = null;
    this.timeTableData = null;
  }

  public List<StationTableData> getStationTableData()
  {
    return stationTableData;
  }

  public void setStationTableData(List<StationTableData> stationTableData)
  {
    this.stationTableData = stationTableData;
    timeTableData.setStationDataList(stationTableData);
    fireModelChangedEvent(Change.STATION_DATA_CHANGE);
  }

  public String getTimeTableName()
  {
    return timeTableName;
  }

  public void setTimeTableName(String timeTableName)
  {
    this.timeTableName = timeTableName;
    timeTableData.setName(timeTableName);
    fireModelChangedEvent(Change.TABLE_NAME_CHANGE);
  }

  public String getLineName()
  {
    return lineName;
  }

  public void setLineName(String lineName)
  {
    this.lineName = lineName;
    timeTableData.setLineName(lineName);
    fireModelChangedEvent(Change.LINE_NAME_CHANGE);
  }

  public TimetableData getTimeTableData()
  {
    if (!stationTableData.isEmpty())
    {
      StationTableData lastStationData = stationTableData.get(stationTableData.size() - 1);
      timeTableData.setEndStationName(lastStationData.getStationName());
      Optional<StationTableData> firstStationData = stationTableData.stream().findFirst();
      if (firstStationData.isPresent())
      {
        timeTableData.setStartStationName(firstStationData.get().getStationName());
        if (timeTableData.getRouteCode().isEmpty())
        {
          // Making a unique route code which is less than 20 chars.
          DBRouteManager routeManager = new DBRouteManager();
          routeManager.load();
          int nextId = 1;
          if (routeManager.getCount() > 0)
          {
            Comparator<DBRoute> byRouteId = Comparator.comparing(route -> route.getValue(DBRoute.ROUT_ROUTE_ID));
            Optional<DBRoute> max = routeManager.stream().max(byRouteId);
            if (max.isPresent())
            {
              nextId += max.get().getValue(DBRoute.ROUT_ROUTE_ID);
            }
          }
          StringBuilder routeCodeBuilder = new StringBuilder();
          if (timeTableData.getName() != null && timeTableData.getName().length() >= 10)
          {
            routeCodeBuilder.append(timeTableData.getName().substring(0, 10));
          }
          else
          {
            routeCodeBuilder.append(timeTableData.getName());
          }
          routeCodeBuilder.append("_"); //$NON-NLS-1$
          routeCodeBuilder.append(nextId);
          timeTableData.setRouteCode(routeCodeBuilder.toString());
        }
      }
      return timeTableData;
    }
    return null;
  }

  public void setTimeTableData(TimetableData timeTableData)
  {
    this.timeTableData = timeTableData;
  }

  public String getRouteCode()
  {
    return routeCode;
  }

  public void setRouteCode(String routeCode)
  {
    this.routeCode = routeCode;
  }

}
