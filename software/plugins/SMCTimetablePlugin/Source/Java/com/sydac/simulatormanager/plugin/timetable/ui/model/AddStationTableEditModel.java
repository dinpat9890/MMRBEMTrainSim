package com.sydac.simulatormanager.plugin.timetable.ui.model;

import static com.sydac.simulatormanager.i18n.SimulatorManagerI18N.t;

import java.util.Collections;
import java.util.List;
import java.util.Optional;

import javax.swing.table.AbstractTableModel;

import com.sydac.simulatormanager.plugin.timetable.ui.components.TimeField;
import com.sydac.simulatormanager.plugin.timetable.ui.controller.StationTableStationIdComparator;

public class AddStationTableEditModel extends AbstractTableModel
{

  private List<StationTableData> addStationTableDatas;

  private Integer sequence;

  private final String[] columnNames = new String[] { t("Sequence"), //$NON-NLS-1$
      t("Station Name"), //$NON-NLS-1$
      t("<html><center>Arrival Time<br>(D:HH:mm:ss)"), //$NON-NLS-1$
      t("<html><center>Departure Time<br>(D:HH:mm:ss)"),
      t("") }; //$NON-NLS-1$

  public AddStationTableEditModel(List<StationTableData> addStationTableDatas)
  {
    this.addStationTableDatas = addStationTableDatas;
    sequence = 1;
  }

  @Override
  public String getColumnName(int column)
  {
    return columnNames[column];
  }

  @Override
  public Object getValueAt(int row, int col)
  {

    StationTableData f = addStationTableDatas.get(row);
    Object field = null;
    switch (col)
    {
    case 0:
      field = f.getSequence();
      break;
    case 1:
      field = f.getStationName();
      break;
    case 2:
      field = f.getArrivalTime();
      break;
    case 3:
      field = f.getDepartureTime();
      break;
    case 4:
      field = f.getStationID();
      break;
    default:
      break;
    }
    return field;
  }

  @Override
  public void setValueAt(Object aValue, int rowIndex, int columnIndex)
  {
    if (columnIndex == 2)
    {
      addStationTableDatas.get(rowIndex).setArrivalTime((Long)aValue);
      fireTableCellUpdated(rowIndex, columnIndex);
    }
    else if (columnIndex == 3)
    {
      addStationTableDatas.get(rowIndex).setDepartureTime((Long)aValue);
      fireTableCellUpdated(rowIndex, columnIndex);
    }
  }

  @Override
  public boolean isCellEditable(int rowIndex, int columnIndex)
  {
    return (columnIndex == 2 || columnIndex == 3);
  }

  @Override
  public Class<?> getColumnClass(int columnIndex)
  {
    if (columnIndex == 2)
    {
      return TimeField.class;
    }
    else
    {
      return Object.class;
    }
  }

  @Override
  public int getColumnCount()
  {
    return columnNames.length;
  }

  @Override
  public int getRowCount()
  {
    return addStationTableDatas.size();
  }

  public List<StationTableData> getAddStationTableDatas()
  {
    return addStationTableDatas;
  }

  public void setAddStationTableDatas(List<StationTableData> addStationTableDatas)
  {
    this.addStationTableDatas = addStationTableDatas;
    fireTableDataChanged();
  }

  public void addStation(StationTableData station)
  {
    Optional<StationTableData> stationO = addStationTableDatas.stream()
        .filter(h -> h.getStationName().equals(station.getStationName())).findFirst();
    StationTableData selectedStation = new StationTableData(station.getSequence(), station.getStationName(),
        station.getArrivalTime(), station.getDepartureTime(), station.getStationID());
    if (!stationO.isPresent())
    {
      addStationTableDatas.add(selectedStation);
      Collections.sort(addStationTableDatas, new StationTableStationIdComparator());
      sequence = 1;
      for (StationTableData data : addStationTableDatas)
      {
        data.setSequence(sequence);
        sequence = sequence + 1;
      }
      fireTableDataChanged();
    }
  }

  public void removeStation(int row)
  {
    addStationTableDatas.remove(row);
    if (!addStationTableDatas.isEmpty())
    {
      int i = 0;
      for (StationTableData station : addStationTableDatas)
      {
        station.setSequence(++i);
      }
    }
    fireTableDataChanged();
  }

  public void addAllStation(List<StationTableData> stationTableDatas)
  {
    addStationTableDatas.clear();
    addStationTableDatas.addAll(stationTableDatas);
    fireTableDataChanged();
  }
}
