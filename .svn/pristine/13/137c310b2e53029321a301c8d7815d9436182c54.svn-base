/**
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable.ui.controller;

import static com.sydac.simulatormanager.i18n.SimulatorManagerI18N.t;

import java.util.List;
import java.util.Optional;

import javax.swing.JOptionPane;

import com.sydac.common.dataobjects.timetable.DBCourse;
import com.sydac.common.dataobjects.timetable.DBCourse.DBCourseManager;
import com.sydac.common.dataobjects.timetable.DBTimetable;
import com.sydac.common.dataobjects.timetable.DBTimetable.DBTimetableManager;
import com.sydac.common.log.Tracer;
import com.sydac.simulatormanager.common.SimulatorManagerFrame;
import com.sydac.simulatormanager.gui.model.EditMode;
import com.sydac.simulatormanager.gui.model.EditState;
import com.sydac.simulatormanager.lang.InvalidNameException;
import com.sydac.simulatormanager.plugin.timetable.constants.TimetableConstants;
import com.sydac.simulatormanager.plugin.timetable.ui.TimetableEditDialog;
import com.sydac.simulatormanager.plugin.timetable.ui.model.SelectStationTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.StationTableData;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetableData;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetablesTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetablesTableRowEditControlModel;
import com.sydac.simulatormanager.scenariobuilder.controller.TableEditController;
import com.sydac.simulatormanager.scenariobuilder.model.TableEditModel;
import com.sydac.simulatormanager.scenariobuilder.model.TableRowEditControlModel;

public class TimetablesTableEditController extends TableEditController
{

  /* Reference to TableRowEditControlModel */
  private TimetablesTableRowEditControlModel tableRowEditControlModel;

  /* Reference to TableEditModel */
  private TimetablesTableEditModel tableEditModel;

  /* The dialog for editing Time Table Stations */
  private TimetableEditDialog detailsDialog;

  private SelectStationTableEditModel stationTableDataModel;

  private TimetableEditModel timeTableEditModel;

  /**
   * Constructs a TrackTimeTableListTableEditController with instance of
   * {@link TableEditModel} and {@link TableRowEditControlModel}
   * 
   * @param selectStationTableDataModel
   *          station table data
   * @param tableEditModel
   *          table edit model
   * @param tableRowEditControlModel
   *          table row edit control model.
   */
  public TimetablesTableEditController(SelectStationTableEditModel selectStationTableDataModel,
      TimetablesTableEditModel tableEditModel, TimetablesTableRowEditControlModel tableRowEditControlModel)
  {
    this.tableEditModel = tableEditModel;
    this.tableRowEditControlModel = tableRowEditControlModel;
    this.stationTableDataModel = selectStationTableDataModel;
  }

  @Override
  public void addRequest()
  {
     
    if (timeTableEditModel != null)
    {
      timeTableEditModel.destroy();
    }
    timeTableEditModel = new TimetableEditModel();
    timeTableEditModel.create();
    tableRowEditControlModel.setEditMode(EditMode.DEFINING);
    tableRowEditControlModel.setEditState(EditState.UNMODIFIED);
    detailsDialog = new TimetableEditDialog(SimulatorManagerFrame.getInstance(), stationTableDataModel,
        timeTableEditModel, this, tableRowEditControlModel);
    detailsDialog.attachListeners();
    detailsDialog.updateLineNameCombo();
    if(!tableEditModel.getScenarioTimeTables().isEmpty())
    {
      JOptionPane.showMessageDialog(detailsDialog, t("Timetable is already exists for this Scenario."), //$NON-NLS-1$
          t("Information"), //$NON-NLS-1$
          JOptionPane.WARNING_MESSAGE);
    }else
    {
      detailsDialog.setVisible(true);
    }
    
  
    detailsDialog.detachListeners();
    
    
  }

  @Override
  public void editRequest()
  {
    if (timeTableEditModel != null)
    {
      timeTableEditModel.destroy();
    }
    timeTableEditModel = new TimetableEditModel();
    timeTableEditModel.create();
    tableRowEditControlModel.setEditMode(EditMode.EDITING);
    tableRowEditControlModel.setEditState(EditState.UNMODIFIED);
    detailsDialog = new TimetableEditDialog(SimulatorManagerFrame.getInstance(), stationTableDataModel,
        timeTableEditModel, this, tableRowEditControlModel);
    TimetableData timetableData = tableEditModel.getTimeTableDataAt(tableEditModel.getChangeIndex());
    timetableData.getId();
    detailsDialog.updateLineNameCombo(); // To update select line and
                                         // selectStationTableData
    detailsDialog.updateSelectLine(timetableData.getLineName());
    detailsDialog.setTableName(timetableData.getName()); // To update TableName
    timeTableEditModel.setTimeTableData(timetableData);
    timeTableEditModel.setStationTableData(timetableData.getStationDataList()); // To
                                                                                // update
                                                                                // addStationTableData
    detailsDialog.attachListeners();
    detailsDialog.setVisible(true);
    detailsDialog.detachListeners();
  }
 

    @Override
  public void onDeleteRequest()
  {
    tableEditModel.removeTimeTableData(tableEditModel.getChangeIndex());
  }

  @Override
  public boolean onSaveRequest()
  {
    try
    {
      TimetableData timeTableData = timeTableEditModel.getTimeTableData();

      if (null != timeTableData)
      {
        if (TimetableConstants.BLANK.equals(timeTableData.getName()))
        {
          throw new InvalidNameException();
        }
        else if (!isValidTimesequence(timeTableData.getStationDataList())
            || isTimetableAlreadyExist(timeTableData))
        {
          return false;
        }
        else
        {
          if (EditMode.DEFINING == tableRowEditControlModel.getEditMode())
          {
            tableEditModel.addTimeTableData(timeTableData);
          }
          else if (EditMode.EDITING == tableRowEditControlModel.getEditMode())
          {
            tableEditModel.updateTimeTableData(timeTableData);
          }
        }

      }
    }
    catch (InvalidNameException e)
    {
      Tracer.getInstance().error(e);
      JOptionPane.showMessageDialog(detailsDialog, t("Please add Timetable Name"), //$NON-NLS-1$
          t("Save Error"), //$NON-NLS-1$
          JOptionPane.ERROR_MESSAGE);
      return false;
    }
    return true;
  }

  private boolean isTimetableAlreadyExist(TimetableData timeTableData)
  {
    DBTimetableManager timetableManager = new DBTimetableManager();
    timetableManager.load();
    Optional<DBTimetable> dbTimeTableO = timetableManager.stream()
        .filter(h -> h.getValue(DBTimetable.TITA_NAME).equals(timeTableData.getName())).findFirst();
    DBCourseManager courseManager = new DBCourseManager();
    courseManager.load();
    Optional<DBCourse> dbCourse = courseManager.stream()
        .filter(h -> h.getValue(DBCourse.COUR_CODE).equals(timeTableData.getName())).findFirst();
    if (dbTimeTableO.isPresent() || dbCourse.isPresent())
    {
      JOptionPane.showMessageDialog(detailsDialog, t("Timetable with this name is already exist in Database"),
          t("Save Error"), //$NON-NLS-1$
          JOptionPane.ERROR_MESSAGE);
      return true;
    }
    return false;
  }

  private boolean isValidTimesequence(List<StationTableData> stationDataList)
  {
    for (StationTableData stationTableData : stationDataList)
    {
      if (stationTableData.getSequence() == 1)
      {
        if (stationTableData.getDepartureTime() - stationTableData.getArrivalTime() < 0)
        {
          JOptionPane.showMessageDialog(detailsDialog,
              t(stationTableData.getStationName()
                  + " Arrival Time Should not be grater than Departure Time "), //$NON-NLS-1$
              t("Save Error"), //$NON-NLS-1$
              JOptionPane.ERROR_MESSAGE);
          return false;
        }
      }
      else
      {
        StationTableData prevStationData = stationDataList.get(stationTableData.getSequence() - 2);
        if (stationTableData.getArrivalTime() - prevStationData.getDepartureTime() == 0)
        {
          JOptionPane.showMessageDialog(detailsDialog,
              t(stationTableData.getStationName() + " Arrival Time Should not be equal to Departure Time of " //$NON-NLS-1$
                  + prevStationData.getStationName()),
              t("Save Error"), //$NON-NLS-1$
              JOptionPane.ERROR_MESSAGE);
          return false;
        }
        else if (stationTableData.getArrivalTime() - prevStationData.getDepartureTime() < 0)
        {
          JOptionPane.showMessageDialog(detailsDialog,
              t(stationTableData.getStationName() + " Arrival Time Should not be less than Departure Time of " //$NON-NLS-1$
                  + prevStationData.getStationName()),
              t("Save Error"), //$NON-NLS-1$
              JOptionPane.ERROR_MESSAGE);
          return false;
        }
        else if (stationTableData.getDepartureTime() - stationTableData.getArrivalTime() < 0)
        {
          JOptionPane.showMessageDialog(detailsDialog,
              t(stationTableData.getStationName()
                  + " Arrival Time Should not be grater than Departure Time "), //$NON-NLS-1$
              t("Save Error"), //$NON-NLS-1$
              JOptionPane.ERROR_MESSAGE);
          return false;
        }
      }
    }
    return true;
  }

  @Override
  public void setSelectedIndex(int index)
  {
    tableEditModel.setChangeIndex(index);
  }

  @Override
  public void cancelRequest()
  {
    // not required here
  }

  @Override
  public void clearRequest()
  {
    // not required here
  }

}
