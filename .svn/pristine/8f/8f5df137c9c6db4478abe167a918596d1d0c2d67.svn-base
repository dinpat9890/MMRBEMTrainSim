package com.sydac.simulatormanager.plugin.timetable.ui.model;

import static com.sydac.simulatormanager.i18n.SimulatorManagerI18N.t;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

import javax.swing.table.AbstractTableModel;

import com.sydac.common.dataobjects.DBTrackNetwork;
import com.sydac.common.dataobjects.timetable.DBLine;
import com.sydac.common.dataobjects.timetable.DBLine.DBLineManager;
import com.sydac.common.dataobjects.timetable.DBLineStationAssoc;
import com.sydac.common.dataobjects.timetable.DBRoute;
import com.sydac.common.dataobjects.timetable.DBLineStationAssoc.DBLineStationAssocManagerByLine;
import com.sydac.common.dataobjects.timetable.DBRoute.DBRouteManager;
import com.sydac.common.dataobjects.timetable.DBRouteStationAssoc;
import com.sydac.common.dataobjects.timetable.DBRouteStationAssoc.DBRouteStationAssocManager;
import com.sydac.common.dataobjects.timetable.DBRunStationAssoc;
import com.sydac.common.dataobjects.timetable.DBRunStationAssoc.DBRunStationAssocManager;
import com.sydac.common.dataobjects.timetable.DBStation;
import com.sydac.common.dataobjects.timetable.DBStation.DBStationManager;
import com.sydac.simulatormanager.plugin.timetable.constants.TimetableConstants;
import com.sydac.simulatormanager.plugin.timetable.ui.controller.StationTableSequenceComparator;
import com.sydac.simulatormanager.scenariobuilder.model.manager.ScenarioManager;
import com.sydac.simulatormanager.scenariobuilder.model.valueobjects.ScenarioModel;

public class SelectStationTableEditModel extends AbstractTableModel
{
  private static final long serialVersionUID = 1L;

  private List<StationTableData> selectStationTableDatas;

  private Map<String, Integer> lineNameMap;

  private Map<String, Integer> lineRouteNameMap;

  private static final String[] columnNames = new String[] { t("Sequence"), //$NON-NLS-1$
      t("Station Name"), }; //$NON-NLS-1$

  public SelectStationTableEditModel(List<StationTableData> selectStationTableDatas)
  {
    this.selectStationTableDatas = selectStationTableDatas;
  }

  @Override
  public String getColumnName(int column)
  {
    return columnNames[column];
  }

  @Override
  public Object getValueAt(int row, int col)
  {
    StationTableData f = selectStationTableDatas.get(row);
    Object field = null;

    switch (col)
    {
    case 0:
      field = f.getSequence();
      break;
    case 1:
      field = f.getStationName();
      break;
    default:
      break;
    }

    return field;

  }

  public List<StationTableData> getSelectStationTableDatas()
  {
    return selectStationTableDatas;
  }

  public void setSelectStationTableDatas(List<StationTableData> selectStationTableDatas)
  {
    this.selectStationTableDatas = selectStationTableDatas;
    fireTableDataChanged();
  }

  public void onTrackNetworkChange()
  {
   // loadSelectStationTableDatasfromDB(TimetableConstants.UP_TACK);
  }

  /**
   * loadSelectStationTableDatasfromDB - Loads SelectStationTableData from
   * database on the basis of scenarioId and lineName;
   * 
   * @param lineName
   *          Line name
   */
  public void loadSelectStationTableDatasfromDB(String lineName)
  {
    ScenarioModel currentScenarioModel = ScenarioManager.getInstance().getCurrentScenarioModel();
    List<StationTableData> selectStationDatas = new ArrayList<>();
    if (null != currentScenarioModel)
    {
      DBTrackNetwork trackNetwork = currentScenarioModel.getTrackNetwork();
      if (null != trackNetwork)
      {
        int trackNetworkID = trackNetwork.getTrackNetworkId();
        DBLineManager dbLineManager = new DBLineManager();
        dbLineManager.load();
        if(getRouteLineData().isEmpty() && getRouteLineData()!=null) {
System.out.println("getRouteLineData().get(lineName) "+ getRouteLineData().get(lineName));}
        Optional<DBLine> dbLine = dbLineManager.parallelStream()
            .filter(p -> p.getValue(DBLine.LINE_LINE_ID).equals(getRouteLineData().get(lineName))
                && p.getValue(DBLine.TRNE_TRACKNETWORK_ID) == trackNetworkID)
            .findFirst();
        if (dbLine.isPresent())
        {

          DBRouteStationAssocManager routeStationAssocManager = new DBRouteStationAssocManager();
          routeStationAssocManager.load();
          List<DBRouteStationAssoc> dbRouteStationAssocs = routeStationAssocManager.stream()
              .filter(
                  h -> h.getValue(DBRouteStationAssoc.ROUT_ROUTE_ID) == getLineRouteMapData().get(lineName))
              .collect(Collectors.toList());
          DBRunStationAssocManager runStationAssocManager = new DBRunStationAssocManager();
          runStationAssocManager.load();
          DBLineStationAssocManagerByLine assocManagerByLine = new DBLineStationAssocManagerByLine(
              dbLine.get());
          assocManagerByLine.load();
          DBStationManager stationManager = new DBStationManager();
          stationManager.load();
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
                .filter(h -> h.getValue(DBRunStationAssoc.RSTA_ROUTE_STATION_ID) == routeStationid)
                .findFirst();

            if (dbRunStationAssoc.isPresent())
            {
              long arrivalTime = dbRunStationAssoc.get().getValue(DBRunStationAssoc.RUST_ARRIVAL_TIME);
              long departureTime = dbRunStationAssoc.get().getValue(DBRunStationAssoc.RUST_DEPARTURE_TIME);
              StationTableData stationTableData = new StationTableData(sequence, stationName, arrivalTime,
                  departureTime, dbRouteStationAssoc.getValue(DBRouteStationAssoc.RSTA_SEQUENCE));
              selectStationDatas.add(stationTableData);

            }

          }
          Collections.sort(selectStationDatas, new StationTableSequenceComparator());

        }
      }
    }
    setSelectStationTableDatas(selectStationDatas);
  }

  @Override
  public int getColumnCount()
  {
    return columnNames.length;
  }

  @Override
  public int getRowCount()
  {
    return selectStationTableDatas.size();
  }

  public void reset()
  {
    selectStationTableDatas.clear();
    setSelectStationTableDatas(new ArrayList<>());
  }

  public void seRouteLineData(Map<String, Integer> lineNameMap)
  {

    this.lineNameMap = lineNameMap;

  }

  public Map<String, Integer> getRouteLineData()
  {
    return lineNameMap;
  }

  public void setLineRouteMapData(Map<String, Integer> lineRouteNameMap)
  {
    this.lineRouteNameMap = lineRouteNameMap;

  }

  public Map<String, Integer> getLineRouteMapData()
  {
    return lineRouteNameMap;

  }
}
