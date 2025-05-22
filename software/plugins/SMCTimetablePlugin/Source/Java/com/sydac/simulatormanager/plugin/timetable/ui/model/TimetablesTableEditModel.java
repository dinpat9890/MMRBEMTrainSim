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
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.timetable.DBCourse;
import com.sydac.common.dataobjects.timetable.DBCourse.DBCourseManager;
import com.sydac.common.dataobjects.timetable.DBLine;
import com.sydac.common.dataobjects.timetable.DBLine.DBLineManager;
import com.sydac.common.dataobjects.timetable.DBLineStationAssoc;
import com.sydac.common.dataobjects.timetable.DBLineStationAssoc.DBLineStationAssocManager;
import com.sydac.common.dataobjects.timetable.DBLineStationAssoc.DBLineStationAssocManagerByLine;
import com.sydac.common.dataobjects.timetable.DBRoute;
import com.sydac.common.dataobjects.timetable.DBRoute.DBRouteManager;
import com.sydac.common.dataobjects.timetable.DBRouteStationAssoc;
import com.sydac.common.dataobjects.timetable.DBRouteStationAssoc.DBRouteStationAssocManager;
import com.sydac.common.dataobjects.timetable.DBRouteStationAssoc.DBRouteStationAssocManagerByRoute;
import com.sydac.common.dataobjects.timetable.DBRun;
import com.sydac.common.dataobjects.timetable.DBRun.DBRunManager;
import com.sydac.common.dataobjects.timetable.DBRunStationAssoc;
import com.sydac.common.dataobjects.timetable.DBRunStationAssoc.DBRunStationAssocManager;
import com.sydac.common.dataobjects.timetable.DBScenarioTimetableAssoc;
import com.sydac.common.dataobjects.timetable.DBScenarioTimetableAssoc.DBScenarioTimetableAssocManager;
import com.sydac.common.dataobjects.timetable.DBStation;
import com.sydac.common.dataobjects.timetable.DBStation.DBStationManager;
import com.sydac.common.dataobjects.timetable.DBTimetable;
import com.sydac.common.dataobjects.timetable.DBTimetable.DBTimetableManager;
import com.sydac.common.dataobjects.timetable.DBTimetableCourseAssoc;
import com.sydac.common.dataobjects.timetable.DBTimetableCourseAssoc.DBTimetableCourseAssocManager;
import com.sydac.simulatormanager.plugin.timetable.ui.controller.StationTableSequenceComparator;
import com.sydac.simulatormanager.scenariobuilder.model.TableEditModel;
import com.sydac.simulatormanager.scenariobuilder.model.manager.ScenarioManager;
import com.sydac.simulatormanager.scenariobuilder.model.valueobjects.ScenarioModel;

/**
 * Model class for the list of {@link TimetableData} objects displayed on UI.
 * 
 * @author patanges
 */
public class TimetablesTableEditModel extends TableEditModel
{

  /* List of TimeTableData currently displayed in UI */
  private List<TimetableData> scenarioTimeTables = null;

  /* List of TimeTableData that are to be removed */
  private List<TimetableData> deletedscenarioTimeTables = null;

  private int scenarioId;

  /**
   * Creates an instance of <code>TimetablesTableEditModel</code>
   */
  public TimetablesTableEditModel()
  {
    super();
    create();
  }

  /**
   * To be called when scenario is changed.
   * 
   * @param scenarioId
   *          the scenario id
   */
  public void onScenarioChange(int scenarioId)
  {
    this.scenarioId = scenarioId;
    setScenarioId(scenarioId);
    DBScenario dbScenario = ScenarioManager.getInstance().getScenario(scenarioId);
    List<TimetableData> timeTables = loadScenarioTimeTables(dbScenario);
    setScenarioTimeTables(timeTables);
  }

  /**
   * Loads all the <code>DBScenarioTimetableAssoc</code> children of the
   * <code>DBScenario</code> passed. Converts each
   * <code>DBScenarioTimetableAssoc</code> object to <code>TimeTableData</code>
   * object and returns a list of converted objects.
   * 
   * @param dbScenario
   *          The <code>DBScenario</code> for which the timetable are to be
   *          loaded.
   * @return List of <code>TimeTableData</code> objects.
   */
  public List<TimetableData> loadScenarioTimeTables(DBScenario dbScenario)
  {
    int scenarioid = dbScenario.getScenarioId();
    List<TimetableData> timeTables = new ArrayList<>();
    DBScenarioTimetableAssocManager scenarioTimetableAssocManager = new DBScenarioTimetableAssocManager();
    scenarioTimetableAssocManager.load();
    List<DBScenarioTimetableAssoc> dbScenarioTimetableAssocs = scenarioTimetableAssocManager.stream()
        .filter(h -> h.getValue(DBScenarioTimetableAssoc.SCEN_SCENARIO_ID) == scenarioid)
        .collect(Collectors.toList());
    for (DBScenarioTimetableAssoc dbScenarioTimetableAssoc : dbScenarioTimetableAssocs)
    {
      int timeTableid = dbScenarioTimetableAssoc.getValue(DBScenarioTimetableAssoc.TITA_TIMETABLE_ID);
      TimetableData timeTableData = new TimetableData();
      DBTimetableManager timetableManager = new DBTimetableManager();
      timetableManager.load();
      Optional<DBTimetable> dbTimetable = timetableManager.stream()
          .filter(h -> h.getValue(DBTimetable.TITA_TIMETABLE_ID) == dbScenarioTimetableAssoc
              .getValue(DBScenarioTimetableAssoc.TITA_TIMETABLE_ID))
          .findFirst();
      if (dbTimetable.isPresent())
      {
        timeTableData.setName(dbTimetable.get().getValue(DBTimetable.TITA_NAME));
        timeTableData.setId(timeTableid);
      }
      DBTimetableCourseAssocManager timetableCourseAssocManager = new DBTimetableCourseAssocManager();
      timetableCourseAssocManager.load();
      Optional<DBTimetableCourseAssoc> dbTimetableCourseAssoc = timetableCourseAssocManager.stream()
          .filter(h -> h.getValue(DBTimetableCourseAssoc.TITA_TIMETABLE_ID) == timeTableid).findFirst();
      DBRunManager runManager = new DBRunManager();
      Optional<DBRun> dbRun = runManager.stream()
          .filter(h -> h.getValue(DBRun.COUR_COURSE_ID) == dbTimetableCourseAssoc.get()
              .getValue(DBTimetableCourseAssoc.COUR_COURSE_ID))
          .findFirst();
      if (dbRun.isPresent())
      {
        int routeId = dbRun.get().getValue(DBRun.ROUT_ROUTE_ID);
        DBRouteManager routeManager = new DBRouteManager();
        Optional<DBRoute> dbRoute = routeManager.stream()
            .filter(h -> h.getValue(DBRoute.ROUT_ROUTE_ID) == routeId).findFirst();
      
        DBLineManager lineManager = new DBLineManager();
        Optional<DBLine> dbLine = lineManager.stream()
            .filter(h -> h.getValue(DBLine.LINE_LINE_ID) == dbRoute.get().getValue(DBRoute.LINE_LINE_ID))
            .findFirst();
        DBRouteStationAssocManager routeStationAssocManager = new DBRouteStationAssocManager();
        routeStationAssocManager.load();
        List<DBRouteStationAssoc> dbRouteStationAssocs = routeStationAssocManager.stream()
            .filter(h -> h.getValue(DBRouteStationAssoc.ROUT_ROUTE_ID) == routeId)
            .collect(Collectors.toList());

        timeTableData.setRouteCode(dbRoute.get().getValue(DBRoute.ROUT_CODE));
        timeTableData.setLineName(dbRoute.get().getValue(DBRoute.ROUT_NAME));
        DBStationManager stationManager = new DBStationManager();
        stationManager.load();
        DBLineStationAssocManagerByLine assocManagerByLine = new DBLineStationAssocManagerByLine(
            dbLine.get());
        assocManagerByLine.load();
        List<StationTableData> stationTableDatas = getStationTableDatas(dbRouteStationAssocs, stationManager,
            assocManagerByLine);
        Collections.sort(stationTableDatas, new StationTableSequenceComparator());
        timeTableData.setEndStationName(stationTableDatas.get(stationTableDatas.size() - 1).getStationName());
        timeTableData.setStartStationName(stationTableDatas.get(0).getStationName());
        timeTableData.setStationDataList(stationTableDatas);
        timeTables.add(timeTableData);
      }
    }

    return timeTables;
  }

  /**
   * Gives List<StationTableData>
   * 
   * @param dbRouteStationAssocs
   * @param stationManager
   * @param assocManagerByLine
   */
  private List<StationTableData> getStationTableDatas(List<DBRouteStationAssoc> dbRouteStationAssocs,
      DBStationManager stationManager, DBLineStationAssocManagerByLine assocManagerByLine)
  {
    List<StationTableData> stationTableDatas = new ArrayList<>();
    DBRunStationAssocManager runStationAssocManager = new DBRunStationAssocManager();
    runStationAssocManager.load();

    for (DBRouteStationAssoc dbRouteStationAssoc : dbRouteStationAssocs)
    {
      int sequence = dbRouteStationAssoc.getValue(DBRouteStationAssoc.RSTA_SEQUENCE);
      Optional<DBStation> dbStation = stationManager.stream()
          .filter(h -> h.getValue(DBStation.STAT_STATION_ID) == dbRouteStationAssoc
              .getValue(DBRouteStationAssoc.STAT_STATION_ID))
          .findFirst();
      String stationName = dbStation.get().getValue(DBStation.STAT_NAME);
      Optional<DBLineStationAssoc> dbLineStation = assocManagerByLine.stream()
          .filter(h -> h.getValue(DBLineStationAssoc.STAT_STATION_ID) == dbRouteStationAssoc
              .getValue(DBRouteStationAssoc.STAT_STATION_ID))
          .findFirst();
      int routeStationid = dbRouteStationAssoc.getValue(DBRouteStationAssoc.RSTA_ROUTE_STATION_ID);
      Optional<DBRunStationAssoc> dbRunStationAssoc = runStationAssocManager.stream()
          .filter(h -> h.getValue(DBRunStationAssoc.RSTA_ROUTE_STATION_ID) == routeStationid).findFirst();

      if (dbRunStationAssoc.isPresent())
      {
        long arrivalTime = dbRunStationAssoc.get().getValue(DBRunStationAssoc.RUST_ARRIVAL_TIME);
        long departureTime = dbRunStationAssoc.get().getValue(DBRunStationAssoc.RUST_DEPARTURE_TIME);
        StationTableData stationTableData = new StationTableData(sequence, stationName, arrivalTime,
            departureTime, dbRouteStationAssoc.getValue(DBRouteStationAssoc.RSTA_SEQUENCE));
        stationTableDatas.add(stationTableData);
      }
    }
    return stationTableDatas;
  }

  /**
   * Adds a {@link TimetableData} to the the table data list.
   * 
   * @param timeTableParameter
   *          The TimeTableData to add.
   */
  public void addTimeTableData(TimetableData timeTableParameter)
  {
    getScenarioTimeTables().add(timeTableParameter);
    fireModelChangedEvent(TableEditModel.Change.LIST_CHANGED);
  }

  /**
   * Updates the table data with UI changes.
   * 
   * @param updated
   *          The updated timeTableData.
   */
  public void updateTimeTableData(TimetableData updated)
  {
    String tableName = updated.getName();
    if (getScenarioTimeTables().stream().filter(h -> h.getName().equals(tableName)).findFirst().isPresent())
    {
      TimetableData timeTableData = getScenarioTimeTables().stream()
          .filter(h -> h.getName().equals(tableName)).findFirst().get();
      timeTableData.setLineName(updated.getLineName());
      timeTableData.setName(updated.getName());
      timeTableData.setScenarioId(scenarioId);
      timeTableData.setStartStationName(updated.getStartStationName());
      timeTableData.setEndStationName(updated.getEndStationName());
      fireModelChangedEvent(TableEditModel.Change.LIST_CHANGED);
    }
  }

  /**
   * Removed a {@link TimetableData} from the the table data list.
   * 
   * @param selectionIndex
   *          The index of the TimeTableData instance to be removed.
   */
  public void removeTimeTableData(int selectionIndex)
  {
    TimetableData timeTableData = getScenarioTimeTables().remove(selectionIndex);
    if (null != timeTableData.getId())
    {
      deletedscenarioTimeTables.add(timeTableData);
    }
    fireModelChangedEvent(TableEditModel.Change.LIST_CHANGED);
  }

  /**
   * @return the scenarioTimeTables
   */
  public List<TimetableData> getScenarioTimeTables()
  {
    return scenarioTimeTables;
  }

  /**
   * @param scenarioTimeTables
   *          the scenarioTimeTables to set
   */
  public void setScenarioTimeTables(List<TimetableData> scenarioTimeTables)
  {
    this.scenarioTimeTables = scenarioTimeTables;
    fireModelChangedEvent(TableEditModel.Change.LIST_CHANGED);
  }

  @Override
  public List<TableData> getScenarioTableDataList()
  {
    return Collections.unmodifiableList(getScenarioTimeTables());
  }

  /**
   * Retrieves the TimeTableData element from the table data list at the
   * specified index and return it.
   * 
   * @param index
   *          The index of the object to be retrieved.
   * @return Returns the object retrieved from the data list. If no object is
   *         found at this index or if the index is out of bounds with the list
   *         <code>null</code> is returned.
   */
  public TimetableData getTimeTableDataAt(int index)
  {
    if (null != scenarioTimeTables && index >= 0 && index < scenarioTimeTables.size())
    {
      return scenarioTimeTables.get(index);
    }
    return null;
  }
 // getRouteLineData().get(lineName)
  /**
   * Saves the {@link DBScenarioTimetableAssoc} instances to database which are
   * associated with scenario with id <code>dbScenarioId</code>.
   * 
   * @param dbScenarioId
   *          Id of the scenario
   * @param trackNwId
   *          track new id
   * @param date
   *          date info
   * @param saveAsNew
   *          boolean indicating new scenario or update to existing scenario.
   * @return boolean indicating the status of save operation
   */
  public boolean saveToDatabase(int dbScenarioId, int trackNwId, Date date, boolean saveAsNew,Map<String, Integer> routeLineData)
  {
    boolean savedOk = true;
    List<TimetableData> timeTableDatas = getScenarioTimeTables();
    int trackNetworkId = trackNwId;
    Date scenarioStartTime = date;
    if (saveAsNew)
    {
      for (TimetableData tableData : timeTableDatas)
      {
        savedOk = addTimetableToDBScenario(dbScenarioId, savedOk, trackNetworkId, scenarioStartTime,
            tableData,routeLineData);
        if (!savedOk)
        {
          break;
        }

      }
    }
    else
    {
      savedOk &= updateTimeTableDataOfScenario(timeTableDatas, dbScenarioId, trackNwId, scenarioStartTime,
          savedOk,routeLineData);
    }

    return savedOk;
  }

  /**
   * Saves the {@link DBScenarioTimetableAssoc} instances to database which are
   * associated with scenario with id <code>dbScenarioId</code>.
   * 
   * @param dbScenarioId
   *          Id of the scenario
   * @param trackNwId
   * @param date
   * @return boolean indicating the status of save operation
   */
  private boolean addTimetableToDBScenario(int dbScenarioId, boolean asavedOk, int trackNetworkId,
      Date scenarioStartTime, TimetableData tableData,Map<String, Integer> routeLineData)
  {
    boolean savedOk = asavedOk;
    DBTimetableManager timetableManager = new DBTimetableManager();
    timetableManager.load();
    Optional<DBTimetable> timetableNew = timetableManager.stream()
        .filter(h -> h.getValue(DBTimetable.TITA_NAME).equals(tableData.getName())).findFirst();
    DBRouteManager routeMang = new DBRouteManager();
    routeMang.load();
    Optional<DBRoute> routeNew = routeMang.stream()
        .filter(h -> h.getValue(DBRoute.ROUT_CODE).equals(tableData.getRouteCode())).findFirst();
    if (timetableNew.isPresent()) // check if the new timetable name is already
                                  // present in DBTimetable
    {
      tableData.setName(getUniqueName(timetableManager));
      tableData.setRouteCode(getUniqueName(timetableManager));
    }
    else if (routeNew.isPresent()) // check if the new Route Code is already
                                   // present in DBRoute
    {
      tableData.setRouteCode(getUniqueName(timetableManager));
    }

    // create DBTimetable
    savedOk &= createDBTimetable(savedOk, trackNetworkId, tableData);
    if (!savedOk)
    {
      return false;
    }
    else // create DBScenarioTimetableAssoc
    {
      DBTimetableManager timetableManager1 = new DBTimetableManager();
      timetableManager1.load();
      Optional<DBTimetable> timetable = timetableManager1.stream()
          .filter(h -> h.getValue(DBTimetable.TITA_NAME).equals(tableData.getName())).findFirst();
      if (timetable.isPresent())
      {
        int timetableId = timetable.get().getValue(DBTimetable.TITA_TIMETABLE_ID);
        String timetableName = timetable.get().getValue(DBTimetable.TITA_NAME);
        savedOk &= createDBScenarioTimeTableAssoc(dbScenarioId, savedOk, trackNetworkId, scenarioStartTime,
            timetableId) && createDBCourse(trackNetworkId, timetableName);
        if (!savedOk)
        {
          return false;
        }
        else // create DBTimetableCourseAssoc
        {
          DBCourseManager courseManager = new DBCourseManager();
          courseManager.load();
          Optional<DBCourse> dbCourse = courseManager.stream()
              .filter(h -> h.getValue(DBCourse.COUR_CODE).equals(timetableName)).findFirst();
          if (dbCourse.isPresent())
          {
            int courseId = dbCourse.get().getValue(DBCourse.COUR_COURSE_ID);
            savedOk &= createDBTimetableCourseAssoc(savedOk, trackNetworkId, timetableId, courseId);
            if (!savedOk)
            {
              return false;
            }
            else // create DBRoute
            {
              DBLineManager lineManager = new DBLineManager();
              lineManager.load();
              Optional<DBLine> dbline = lineManager.stream()
                  .filter(h -> h.getValue(DBLine.LINE_LINE_ID).equals(routeLineData.get(tableData.getLineName()))).findFirst();
              if (dbline.isPresent())
              {
                int lineid = dbline.get().getValue(DBLine.LINE_LINE_ID);
                savedOk &= createDBRoute(savedOk, trackNetworkId, tableData, lineid);
                if (!savedOk)
                {
                  return false;
                }
                else // create DBRouteStationAssoc
                {
                  savedOk &= createDBRouteStationAssoc(savedOk, trackNetworkId, tableData, courseId, lineid);
                }
              }
            }
          }
        }
      }
    }
    return savedOk;
  }

  public String getUniqueName(DBTimetableManager timetableManager)
  {
    int nextId = 1;
    if (timetableManager.getCount() > 0)
    {
      Comparator<DBTimetable> bytableId = Comparator
          .comparing(table -> table.getValue(DBTimetable.TITA_TIMETABLE_ID));
      Optional<DBTimetable> max = timetableManager.stream().max(bytableId);
      if (max.isPresent())
      {
        nextId += max.get().getValue(DBTimetable.TITA_TIMETABLE_ID);
      }
    }
    StringBuilder timetableNameBuilder = new StringBuilder();
    ScenarioModel scenarioModel = ScenarioManager.getInstance().getCurrentScenarioModel();
    if (scenarioModel.getScenarioName() != null && scenarioModel.getScenarioName().length() >= 10)
    {
      timetableNameBuilder.append(scenarioModel.getScenarioName().substring(0, 10));
    }
    else
    {
      timetableNameBuilder.append(scenarioModel.getScenarioName());
    }
    timetableNameBuilder.append("_tt_"); //$NON-NLS-1$
    timetableNameBuilder.append(nextId);
    return timetableNameBuilder.toString();
  }

  /**
   * Updates the {@link DBTimetable} instances from database which are
   * associated with scenario with id <code>dbScenarioId</code>.
   * 
   * @param dbScenarioId
   *          Id of the scenario
   * @param timeTableDatas
   * @param trackNwId
   * @param scenarioStartTime
   * @param asavedOk
   * @return boolean indicating the status of save operation
   */
  private Boolean updateTimeTableDataOfScenario(List<TimetableData> timeTableDatas, int dbScenarioId,
      int trackNwId, Date scenarioStartTime, boolean asavedOk,Map<String, Integer> routeLineData)
  {
    boolean savedOk = asavedOk;
    for (TimetableData tableData : timeTableDatas)
    {
      DBTimetableManager timetableManager = new DBTimetableManager();
      timetableManager.load();
      Optional<DBTimetable> dbTimeTableO = timetableManager.stream()
          .filter(h -> h.getValue(DBTimetable.TITA_TIMETABLE_ID) == tableData.getId()).findFirst();
      if (dbTimeTableO.isPresent())
      {
        dbTimeTableO.get().setValue(DBTimetable.TITA_NAME, tableData.getName());
        savedOk &= dbTimeTableO.get().save();
        if (!savedOk)
        {
          break;
        }
        else
        {
          DBLineManager lineManager = new DBLineManager();
          lineManager.load();
          Optional<DBLine> dbLineO = lineManager.stream()
              .filter(h -> h.getValue(DBLine.LINE_LINE_ID).equals(routeLineData.get(tableData.getLineName()))).findFirst();
          int lineId = dbLineO.get().getValue(DBLine.LINE_LINE_ID);

          DBTimetableCourseAssocManager courseAssocManager = new DBTimetableCourseAssocManager();
          courseAssocManager.load();
          Optional<DBTimetableCourseAssoc> dbTimeTableCourseAssocO = courseAssocManager.stream()
              .filter(h -> h.getValue(DBTimetableCourseAssoc.TITA_TIMETABLE_ID) == tableData.getId())
              .findFirst();
          int courseId = dbTimeTableCourseAssocO.get().getValue(DBTimetableCourseAssoc.COUR_COURSE_ID);

          DBRunManager runManager = new DBRunManager();
          runManager.load();
          Optional<DBRun> dbRunO = runManager.stream()
              .filter(h -> h.getValue(DBRun.COUR_COURSE_ID) == courseId).findFirst();
          int routeId = dbRunO.get().getValue(DBRun.ROUT_ROUTE_ID);

          DBRouteManager routeManager = new DBRouteManager();
          routeManager.load();
          Optional<DBRoute> dbRouteO = routeManager.stream().filter(
              h -> h.getValue(DBRoute.ROUT_ROUTE_ID) == routeId && h.getValue(DBRoute.LINE_LINE_ID) == lineId)
              .findFirst();
          if (!dbRouteO.isPresent())
          {
            DBRunManager runManagers = new DBRunManager();
            runManagers.load();
            Optional<DBRun> dbRunOb = runManager.stream()
                .filter(h -> h.getValue(DBRun.COUR_COURSE_ID) == courseId).findFirst();
            if (dbRunOb.isPresent()) // delete DBRunStationAssoc and DBRun
            {
              int runID = dbRunO.get().getValue(DBRun.RUN_RUN_ID);
              DBRunStationAssocManager runStationAssocManager = new DBRunStationAssocManager();
              runStationAssocManager.load();
              List<DBRunStationAssoc> dbRunStationAssocs = runStationAssocManager.stream()
                  .filter(h -> h.getValue(DBRunStationAssoc.ROUT_ROUTE_ID) == routeId
                      && h.getValue(DBRunStationAssoc.RUN_RUN_ID) == runID)
                  .collect(Collectors.toList());
              for (DBRunStationAssoc dbRunStationAssoc : dbRunStationAssocs)
              {
                dbRunStationAssoc.markForDelete();
                savedOk &= dbRunStationAssoc.save();
                if (!savedOk)
                {
                  return false;
                }
              }
              dbRunO.get().markForDelete();
              savedOk &= dbRunO.get().save();
              if (!savedOk)
              {
                return false;
              }
              else // delete DBRouteStationAssoc
              {
                DBRouteStationAssocManager routeStationAssocManager = new DBRouteStationAssocManager();
                routeStationAssocManager.load();
                List<DBRouteStationAssoc> dbRouteStationAssocs = routeStationAssocManager.stream()
                    .filter(h -> h.getValue(DBRouteStationAssoc.ROUT_ROUTE_ID) == routeId)
                    .collect(Collectors.toList());
                for (DBRouteStationAssoc dbRouteStationAssoc : dbRouteStationAssocs)
                {
                  dbRouteStationAssoc.markForDelete();
                  savedOk &= dbRouteStationAssoc.save();
                  if (!savedOk)
                  {
                    return false;
                  }
                }
                if (!savedOk)
                {
                  return false;
                }
                else // create DBRouteStationAssoc
                {
                  dbRouteO = routeManager.stream().filter(h -> h.getValue(DBRoute.ROUT_ROUTE_ID) == routeId)
                      .findFirst();
                  dbRouteO.get().setValue(DBRoute.LINE_LINE_ID, lineId);
                  dbRouteO.get().setValue(DBRoute.ROUT_CODE, tableData.getRouteCode());
                  dbRouteO.get().setValue(DBRoute.ROUT_NAME, tableData.getRouteCode());
                  savedOk &= dbRouteO.get().save();
                  if (!savedOk)
                  {
                    break;
                  }
                  savedOk &= createDBRouteStationAssoc(savedOk, trackNwId, tableData, courseId, lineId);
                }
              }
            }
          }
          else
          {
            dbRouteO.get().setValue(DBRoute.ROUT_CODE, tableData.getRouteCode());
            dbRouteO.get().setValue(DBRoute.ROUT_NAME, tableData.getRouteCode());
            savedOk &= dbRouteO.get().save();
            if (!savedOk)
            {
              break;
            }
            else
            {
              DBRouteStationAssocManagerByRoute assocManagerByRoute = new DBRouteStationAssocManagerByRoute(
                  dbRouteO.get());
              assocManagerByRoute.load();
              List<StationTableData> stationTableDatas = tableData.getStationDataList();
              List<Integer> removedStationIds = new ArrayList<>();
              for (DBRouteStationAssoc dbRouteStationAssoc : assocManagerByRoute)
              {
                DBStationManager stationManager = new DBStationManager();
                stationManager.load();
                Optional<DBStation> dbStationO = stationManager.stream()
                    .filter(h -> h.getValue(DBStation.STAT_STATION_ID) == dbRouteStationAssoc
                        .getValue(DBRouteStationAssoc.STAT_STATION_ID))
                    .findFirst();
                Optional<StationTableData> astationTableData = stationTableDatas.stream()
                    .filter(h -> h.getStationName().equals(dbStationO.get().getValue(DBStation.STAT_NAME)))
                    .findFirst();
                if (!astationTableData.isPresent())
                {
                  removedStationIds
                      .add(dbRouteStationAssoc.getValue(DBRouteStationAssoc.RSTA_ROUTE_STATION_ID));
                }
              }

              for (StationTableData stationTableData : stationTableDatas)
              {
                DBStationManager stationManager = new DBStationManager();
                stationManager.load();
                Optional<DBStation> dbStationO = stationManager.stream()
                    .filter(h -> h.getValue(DBStation.STAT_NAME).equals(stationTableData.getStationName()))
                    .findFirst();
                int stationID = dbStationO.get().getValue(DBStation.STAT_STATION_ID);
                Optional<DBRouteStationAssoc> dbRouteStationAssoc = assocManagerByRoute.stream()
                    .filter(h -> h.getValue(DBRouteStationAssoc.STAT_STATION_ID) == stationID).findFirst();
                if (dbRouteStationAssoc.isPresent()) // to update existing
                                                     // stations
                {
                  dbRouteStationAssoc.get().setValue(DBRouteStationAssoc.RSTA_SEQUENCE,
                      stationTableData.getSequence());
                  dbRouteStationAssoc.get().setValue(DBRouteStationAssoc.LINE_LINE_ID, lineId);
                  savedOk &= dbRouteStationAssoc.get().save();
                  if (!savedOk)
                  {
                    break;
                  }
                  else
                  {
                    DBRunStationAssocManager runStationAssocManager = new DBRunStationAssocManager();
                    runStationAssocManager.load();
                    int routeStationId = dbRouteStationAssoc.get()
                        .getValue(DBRouteStationAssoc.RSTA_ROUTE_STATION_ID);
                    Optional<DBRunStationAssoc> dbRunStationAssocO = runStationAssocManager.stream()
                        .filter(h -> h.getValue(DBRunStationAssoc.RSTA_ROUTE_STATION_ID) == routeStationId)
                        .findFirst();
                    dbRunStationAssocO.get().setValue(DBRunStationAssoc.RUST_ARRIVAL_TIME,
                        stationTableData.getArrivalTime());
                    dbRunStationAssocO.get().setValue(DBRunStationAssoc.RUST_DEPARTURE_TIME,
                        stationTableData.getDepartureTime());
                    savedOk &= dbRunStationAssocO.get().save();
                    if (!savedOk)
                    {
                      break;
                    }
                  }
                }
                else // to add new station
                {
                  DBRouteStationAssoc dbRouteStationAssocn = new DBRouteStationAssoc();
                  dbRouteStationAssocn.setNew();
                  dbRouteStationAssocn.setValue(DBRouteStationAssoc.LINE_LINE_ID, lineId);
                  dbRouteStationAssocn.setValue(DBRouteStationAssoc.ROUT_ROUTE_ID, routeId);
                  dbRouteStationAssocn.setValue(DBRouteStationAssoc.STAT_STATION_ID, stationID);
                  dbRouteStationAssocn.setValue(DBRouteStationAssoc.RSTA_SEQUENCE,
                      stationTableData.getSequence());
                  dbRouteStationAssocn.setValue(DBRouteStationAssoc.RSTA_LOCATION, 0);
                  savedOk &= dbRouteStationAssocn.save();
                  if (!savedOk)
                  {
                    break;
                  }
                  else
                  {
                    DBRunStationAssoc dbRunStationAssoc = new DBRunStationAssoc();
                    dbRunStationAssoc.setNew();
                    dbRunStationAssoc.setValue(DBRunStationAssoc.ROUT_ROUTE_ID, routeId);
                    dbRunStationAssoc.setValue(DBRunStationAssoc.RUN_RUN_ID,
                        dbRunO.get().getValue(DBRun.RUN_RUN_ID));
                    dbRunStationAssoc.setValue(DBRunStationAssoc.RSTA_ROUTE_STATION_ID,
                        dbRouteStationAssocn.getValue(DBRouteStationAssoc.RSTA_ROUTE_STATION_ID));
                    dbRunStationAssoc.setValue(DBRunStationAssoc.RUST_ARRIVAL_TIME,
                        stationTableData.getArrivalTime());
                    dbRunStationAssoc.setValue(DBRunStationAssoc.RUST_DEPARTURE_TIME,
                        stationTableData.getDepartureTime());
                    savedOk &= dbRunStationAssoc.save();
                    if (!savedOk)
                    {
                      break;
                    }
                  }
                }

              }
              if (savedOk) // to remove deleted stations
              {
                for (Integer rstaRouteStId : removedStationIds)
                {

                  DBRouteStationAssocManager routeStationAssocManager = new DBRouteStationAssocManager();
                  routeStationAssocManager.load();
                  Optional<DBRouteStationAssoc> dbRouteStationAssoc = routeStationAssocManager.stream()
                      .filter(
                          h -> (int)h.getValue(DBRouteStationAssoc.RSTA_ROUTE_STATION_ID) == rstaRouteStId)
                      .findFirst();

                  DBRunStationAssocManager runStationAssocManager = new DBRunStationAssocManager();
                  runStationAssocManager.load();

                  Optional<DBRunStationAssoc> dbRunStationAssoc = runStationAssocManager.stream()
                      .filter(h -> (int)h.getValue(DBRunStationAssoc.RSTA_ROUTE_STATION_ID) == rstaRouteStId)
                      .findFirst();

                  dbRunStationAssoc.get().markForDelete();
                  savedOk &= dbRunStationAssoc.get().save();
                  if (!savedOk)
                  {
                    break;
                  }
                  else
                  {
                    dbRouteStationAssoc.get().markForDelete();
                    savedOk &= dbRouteStationAssoc.get().save();
                    if (!savedOk)
                    {
                      break;
                    }
                  }

                }
              }

            }
          }
        }
      }
      else
      {
        // save new timetabledata to saved scenario
        savedOk &= addTimetableToDBScenario(dbScenarioId, savedOk, trackNwId, scenarioStartTime, tableData,routeLineData);
      }

    }
    if (savedOk) // to remove deleted timetables from scenario
    {
      for (TimetableData tableData : deletedscenarioTimeTables)
      {
        savedOk &= deleteTimetableFromScenario(dbScenarioId, savedOk, tableData.getId());
        if (!savedOk)
        {
          break;
        }

      }
    }
    return savedOk;

  }

  /**
   * Deletes the {@link DBTimetable} instances from database which are
   * associated with scenario with id <code>dbScenarioId</code>.
   * 
   * @param dbScenarioId
   *          Id of the scenario
   * @param asavedOk
   * @param timetableID
   * @return boolean indicating the status of save operation
   */
  private boolean deleteTimetableFromScenario(int dbScenarioId, boolean asavedOk, int timetableID)
  {
    boolean savedOk = asavedOk;
    DBTimetableCourseAssocManager courseAssocManager = new DBTimetableCourseAssocManager();
    courseAssocManager.load();
    Optional<DBTimetableCourseAssoc> dbTimeTableCourseAssocO = courseAssocManager.stream()
        .filter(h -> h.getValue(DBTimetableCourseAssoc.TITA_TIMETABLE_ID) == timetableID).findFirst();
    int courseId = dbTimeTableCourseAssocO.get().getValue(DBTimetableCourseAssoc.COUR_COURSE_ID);

    DBRunManager runManager = new DBRunManager();
    runManager.load();
    Optional<DBRun> dbRunO = runManager.stream().filter(h -> h.getValue(DBRun.COUR_COURSE_ID) == courseId)
        .findFirst();
    if (dbRunO.isPresent())
    {
      int routeId = dbRunO.get().getValue(DBRun.ROUT_ROUTE_ID);
      int runID = dbRunO.get().getValue(DBRun.RUN_RUN_ID);
      DBRunStationAssocManager runStationAssocManager = new DBRunStationAssocManager();
      runStationAssocManager.load();
      List<DBRunStationAssoc> dbRunStationAssocs = runStationAssocManager.stream()
          .filter(h -> h.getValue(DBRunStationAssoc.ROUT_ROUTE_ID) == routeId
              && h.getValue(DBRunStationAssoc.RUN_RUN_ID) == runID)
          .collect(Collectors.toList());
      for (DBRunStationAssoc dbRunStationAssoc : dbRunStationAssocs)
      {
        dbRunStationAssoc.markForDelete();
        savedOk &= dbRunStationAssoc.save();
        if (!savedOk)
        {
          return false;
        }
      }
      dbRunO.get().markForDelete();
      savedOk &= dbRunO.get().save();
      if (!savedOk)
      {
        return false;
      }
      else
      {
        DBRouteStationAssocManager routeStationAssocManager = new DBRouteStationAssocManager();
        routeStationAssocManager.load();
        List<DBRouteStationAssoc> dbRouteStationAssocs = routeStationAssocManager.stream()
            .filter(h -> h.getValue(DBRouteStationAssoc.ROUT_ROUTE_ID) == routeId)
            .collect(Collectors.toList());
        for (DBRouteStationAssoc dbRouteStationAssoc : dbRouteStationAssocs)
        {
          dbRouteStationAssoc.markForDelete();
          savedOk &= dbRouteStationAssoc.save();
          if (!savedOk)
          {
            return false;
          }
        }
        DBRouteManager routeManager = new DBRouteManager();
        Optional<DBRoute> dbRouteO = routeManager.stream()
            .filter(h -> h.getValue(DBRoute.ROUT_ROUTE_ID) == routeId).findFirst();
        dbRouteO.get().markForDelete();
        savedOk &= dbRouteO.get().save();
        if (!savedOk)
        {
          return false;
        }
        else
        {
          dbTimeTableCourseAssocO.get().markForDelete();
          savedOk &= dbTimeTableCourseAssocO.get().save();
          if (!savedOk)
          {
            return false;
          }
          else
          {
            DBCourseManager courseManager = new DBCourseManager();
            courseManager.load();
            Optional<DBCourse> dbCoursO = courseManager.stream()
                .filter(h -> h.getValue(DBCourse.COUR_COURSE_ID) == courseId).findFirst();
            dbCoursO.get().markForDelete();
            savedOk &= dbCoursO.get().save();
            if (!savedOk)
            {
              return false;
            }
            else
            {
              DBScenarioTimetableAssocManager scenarioTimetableAssocManager = new DBScenarioTimetableAssocManager();
              scenarioTimetableAssocManager.load();
              Optional<DBScenarioTimetableAssoc> dbScenarioTimetableAssocO = scenarioTimetableAssocManager
                  .stream().filter(h -> h.getValue(DBScenarioTimetableAssoc.SCEN_SCENARIO_ID) == dbScenarioId
                      && h.getValue(DBScenarioTimetableAssoc.TITA_TIMETABLE_ID) == timetableID)
                  .findFirst();
              dbScenarioTimetableAssocO.get().markForDelete();
              savedOk &= dbScenarioTimetableAssocO.get().save();
              if (!savedOk)
              {
                return false;
              }
              else
              {
                DBTimetableManager timetableManager = new DBTimetableManager();
                timetableManager.load();
                Optional<DBTimetable> dbTimetableO = timetableManager.stream()
                    .filter(h -> h.getValue(DBTimetable.TITA_TIMETABLE_ID) == timetableID).findFirst();
                dbTimetableO.get().markForDelete();
                savedOk &= dbTimetableO.get().save();
                if (!savedOk)
                {
                  return false;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      return false;
    }
    return savedOk;
  }

  /**
   * createDBCourse - create {@link DBCourse} table for a table data
   * 
   * @param trackNetworkId
   * @param timetableName
   * @return boolean indicating the status of table save operation
   */
  private boolean createDBCourse(int trackNetworkId, String timetableName)
  {
    DBCourse dbCourse = new DBCourse();
    dbCourse.setNew();
    dbCourse.setValue(DBCourse.TRNE_TRACKNETWORK_ID, trackNetworkId);
    dbCourse.setValue(DBCourse.COUR_CODE, timetableName);
    dbCourse.setValue(DBCourse.COUR_NAME, timetableName);
    return dbCourse.save();
  }

  /**
   * createDBTimetable - create {@link DBTimetable} table for a tabledata
   * 
   * @param asavedOk
   * @param trackNetworkId
   * @param tableData
   * @return boolean indicating the status of table save operation
   */
  private boolean createDBTimetable(boolean asavedOk, int trackNetworkId, TimetableData tableData)
  {
    boolean savedOk = asavedOk;
    DBTimetable dbTimetable = new DBTimetable();
    dbTimetable.setNew();
    dbTimetable.setValue(DBTimetable.TRNE_TRACKNETWORK_ID, trackNetworkId);
    dbTimetable.setValue(DBTimetable.TITA_NAME, tableData.getName());
    savedOk &= dbTimetable.save();
    return savedOk;
  }

  /**
   * createDBScenarioTimeTableAssoc - create {@link DBScenarioTimeTableAssoc}
   * table for a timetable associated with dbScenarioId
   * 
   * @param dbScenarioId
   * @param trackNetworkId
   * @param asavedOk
   * @param scenarioStartTime
   * @param timetableId
   * @return boolean indicating the status of table save operation
   */
  private boolean createDBScenarioTimeTableAssoc(int dbScenarioId, boolean asavedOk, int trackNetworkId,
      Date scenarioStartTime, int timetableId)
  {
    boolean savedOk = asavedOk;
    DBScenarioTimetableAssoc dbScenarioTimetableAssoc = new DBScenarioTimetableAssoc();
    dbScenarioTimetableAssoc.setNew();
    dbScenarioTimetableAssoc.setValue(DBScenarioTimetableAssoc.SCEN_SCENARIO_ID, dbScenarioId);
    dbScenarioTimetableAssoc.setValue(DBScenarioTimetableAssoc.TITA_TIMETABLE_ID, timetableId);
    dbScenarioTimetableAssoc.setValue(DBScenarioTimetableAssoc.TRNE_TRACKNETWORK_ID, trackNetworkId);
    dbScenarioTimetableAssoc.setValue(DBScenarioTimetableAssoc.SCTT_STARTDATETIME, scenarioStartTime);
    savedOk &= dbScenarioTimetableAssoc.save();
    return savedOk;
  }

  /**
   * createDBTimetableCourseAssoc - create {@link DBTimetableCourseAssoc} table
   * for a timetable associated with courseId
   * 
   * @param trackNetworkId
   * @param asavedOk
   * @param courseId
   * @param timetableId
   * @return boolean indicating the status of table save operation
   */
  private boolean createDBTimetableCourseAssoc(boolean asavedOk, int trackNetworkId, int timetableId,
      int courseId)
  {
    boolean savedOk = asavedOk;
    DBTimetableCourseAssoc courseAssoc = new DBTimetableCourseAssoc();
    courseAssoc.setNew();
    courseAssoc.setValue(DBTimetableCourseAssoc.TITA_TIMETABLE_ID, timetableId);
    courseAssoc.setValue(DBTimetableCourseAssoc.TRNE_TRACKNETWORK_ID, trackNetworkId);
    courseAssoc.setValue(DBTimetableCourseAssoc.COUR_COURSE_ID, courseId);
    savedOk &= courseAssoc.save();
    return savedOk;
  }

  /**
   * createDBRoute - create {@link DBRoute} table for a timetabledata
   * 
   * @param trackNetworkId
   * @param asavedOk
   * @param tableData
   * @param lineid
   * @return boolean indicating the status of table save operation
   */
  private boolean createDBRoute(boolean asavedOk, int trackNetworkId, TimetableData tableData, int lineid)
  {
    boolean savedOk = asavedOk;
    DBRoute dbRoute = new DBRoute();
    dbRoute.setNew();
    dbRoute.setValue(DBRoute.ROUT_CODE, tableData.getRouteCode());
    dbRoute.setValue(DBRoute.ROUT_NAME, tableData.getRouteCode());
    dbRoute.setValue(DBRoute.LINE_LINE_ID, lineid);
    dbRoute.setValue(DBRoute.TRNE_TRACKNETWORK_ID, trackNetworkId);
    dbRoute.setValue(DBRoute.DEST_DESTINATION_ID, null);// temp
    savedOk &= dbRoute.save();
    return savedOk;
  }

  /**
   * createDBRouteStationAssoc - create {@link DBRouteStationAssoc} table for a
   * timetable data associated with {@link DBRoute}
   * 
   * @param trackNetworkId
   * @param asavedOk
   * @param tableData
   * @param lineid
   * @param courseId
   * @return boolean indicating the status of table save operation
   */
  private boolean createDBRouteStationAssoc(boolean asavedOk, int trackNetworkId, TimetableData tableData,
      int courseId, int lineid)
  {
    boolean savedOk = asavedOk;
    DBRouteManager routeManager = new DBRouteManager();
    routeManager.load();
    Optional<DBRoute> dbRouteO = routeManager.stream()
        .filter(h -> h.getValue(DBRoute.ROUT_CODE).equals(tableData.getRouteCode())
            && h.getValue(DBRoute.LINE_LINE_ID) == lineid
            && h.getValue(DBRoute.TRNE_TRACKNETWORK_ID) == trackNetworkId)
        .findFirst();
    if (dbRouteO.isPresent())
    {
      int routeId = dbRouteO.get().getValue(DBRoute.ROUT_ROUTE_ID);
      DBLineStationAssocManager lineStationAssocManager = new DBLineStationAssocManager();
      lineStationAssocManager.load();

      for (StationTableData stationTableData : tableData.getStationDataList())
      {
        DBStationManager stationManager = new DBStationManager();
        stationManager.load();
        Optional<DBStation> dbStationO = stationManager.stream()
            .filter(h -> h.getValue(DBStation.STAT_NAME).equals(stationTableData.getStationName()))
            .findFirst();
        if (dbStationO.isPresent())
        {
          int staionId = dbStationO.get().getValue(DBStation.STAT_STATION_ID);
          DBRouteStationAssoc dbRouteStationAssoc = new DBRouteStationAssoc();
          dbRouteStationAssoc.setNew();
          dbRouteStationAssoc.setValue(DBRouteStationAssoc.LINE_LINE_ID, lineid);
          dbRouteStationAssoc.setValue(DBRouteStationAssoc.ROUT_ROUTE_ID, routeId);
          dbRouteStationAssoc.setValue(DBRouteStationAssoc.STAT_STATION_ID, staionId);
          dbRouteStationAssoc.setValue(DBRouteStationAssoc.RSTA_SEQUENCE, stationTableData.getSequence());
          dbRouteStationAssoc.setValue(DBRouteStationAssoc.RSTA_LOCATION, 0);
          savedOk &= dbRouteStationAssoc.save();
        }
        if (!savedOk)
        {
          break;
        }
      }

      if (savedOk) // create DBRun
      {
        savedOk = createDBRun(savedOk, trackNetworkId, courseId, routeId);
        if (savedOk) // create DBRunStationAssoc
        {
          savedOk = createDBRunStationAssoc(savedOk, trackNetworkId, tableData, lineid, routeId);
        }
      }
    }
    return savedOk;
  }

  /**
   * createDBRun - create {@link DBRun} table for a courseId and routeId
   * 
   * @param trackNetworkId
   * @param asavedOk
   * @param routeId
   * @param courseId
   * @return boolean indicating the status of table save operation
   */
  private boolean createDBRun(boolean asavedOk, int trackNetworkId, int courseId, int routeId)
  {
    boolean savedOk = asavedOk;
    DBRun dbRun = new DBRun();
    long i = 0;
    dbRun.setNew();
    dbRun.setValue(DBRun.ROUT_ROUTE_ID, routeId);
    dbRun.setValue(DBRun.TRNE_TRACKNETWORK_ID, trackNetworkId);
    dbRun.setValue(DBRun.COUR_COURSE_ID, courseId);
    dbRun.setValue(DBRun.RUN_START_TIME, i); // temp
    savedOk &= dbRun.save();
    return savedOk;
  }

  /**
   * createDBRunStationAssoc - create {@link DBRunStationAssoc} table for a
   * timetabledata with given courseId and routeId
   * 
   * @param trackNetworkId
   * @param asavedOk
   * @param routeId
   * @param tableData
   * @param lineid
   * @return boolean indicating the status of table save operation
   */
  private boolean createDBRunStationAssoc(boolean asavedOk, int trackNetworkId, TimetableData tableData,
      int lineid, int routeId)
  {
    boolean savedOk = asavedOk;
    DBRouteStationAssocManager routeStationAssocManager = new DBRouteStationAssocManager();
    routeStationAssocManager.load();
    List<DBRouteStationAssoc> dbRouteStationAssocs = routeStationAssocManager.stream()
        .filter(h -> h.getValue(DBRouteStationAssoc.ROUT_ROUTE_ID) == routeId
            && h.getValue(DBRouteStationAssoc.LINE_LINE_ID) == lineid)
        .collect(Collectors.toList());
    DBRunManager runManager = new DBRunManager();
    runManager.load();
    Optional<DBRun> dbRunO = runManager.stream().filter(h -> h.getValue(DBRun.ROUT_ROUTE_ID) == routeId
        && h.getValue(DBRun.TRNE_TRACKNETWORK_ID) == trackNetworkId).findFirst();
    for (DBRouteStationAssoc routeStationAssoc : dbRouteStationAssocs)
    {
      DBRunStationAssoc dbRunStationAssoc = new DBRunStationAssoc();
      dbRunStationAssoc.setNew();
      dbRunStationAssoc.setValue(DBRunStationAssoc.ROUT_ROUTE_ID, routeId);
      dbRunStationAssoc.setValue(DBRunStationAssoc.RUN_RUN_ID, dbRunO.get().getValue(DBRun.RUN_RUN_ID));
      dbRunStationAssoc.setValue(DBRunStationAssoc.RSTA_ROUTE_STATION_ID,
          routeStationAssoc.getValue(DBRouteStationAssoc.RSTA_ROUTE_STATION_ID));
      StationTableData data = tableData.getStationDataList().stream()
          .filter(h -> h.getSequence().equals(routeStationAssoc.getValue(DBRouteStationAssoc.RSTA_SEQUENCE)))
          .findFirst().get();
      dbRunStationAssoc.setValue(DBRunStationAssoc.RUST_ARRIVAL_TIME, data.getArrivalTime());
      dbRunStationAssoc.setValue(DBRunStationAssoc.RUST_DEPARTURE_TIME, data.getDepartureTime());
      savedOk &= dbRunStationAssoc.save();
      if (!savedOk)
      {
        break;
      }
    }
    return savedOk;
  }

  /**
   * Deletes all the {@link DBScenarioTimetableAssoc} instances from database
   * which are associated with <code>dbScenario</code>.
   * 
   * @param dbScenario
   *          Instance of {@link DBScenario} for which all the instances of
   *          {@link DBScenarioTimetableAssoc} are to be deleted.
   * @return Returns true if deletion is successful.
   */
  public boolean deleteFromDatabase(DBScenario dbScenario)
  {
    boolean deletedOk = true;
    DBScenarioTimetableAssocManager scenarioTimetableAssocManager = new DBScenarioTimetableAssocManager();
    scenarioTimetableAssocManager.load();
    List<DBScenarioTimetableAssoc> dbScenarioTimetableAssocs = scenarioTimetableAssocManager.stream()
        .filter(h -> h.getValue(DBScenarioTimetableAssoc.SCEN_SCENARIO_ID) == dbScenario.getScenarioId())
        .collect(Collectors.toList());

    for (DBScenarioTimetableAssoc dbScenarioTimetableAssoc : dbScenarioTimetableAssocs)
    {
      deletedOk &= deleteTimetableFromScenario(dbScenario.getScenarioId(), deletedOk,
          dbScenarioTimetableAssoc.getValue(DBScenarioTimetableAssoc.TITA_TIMETABLE_ID));
      if (!deletedOk)
      {
        break;
      }
    }
    return deletedOk;
  }

  @Override
  protected void onCreate()
  {
    scenarioTimeTables = new ArrayList<>();
    deletedscenarioTimeTables = new ArrayList<>();
  }

  @Override
  protected void onDestroy()
  {
    // not required here
  }

  public void reset()
  {
    onCreate();
    fireModelChangedEvent(TableEditModel.Change.LIST_CHANGED);
  }

  /**
   * Enable the add button on the plugin panel. There is no direct way of doing
   * this.
   */
  public void triggerButtonEnabling()
  {
    fireModelChangedEvent(TableEditModel.Change.LIST_CHANGED);
  }

  public int getScenarioId()
  {
    return scenarioId;
  }

  public void setScenarioId(int scenarioId)
  {
    this.scenarioId = scenarioId;
  }
}
