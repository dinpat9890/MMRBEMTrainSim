/**
 * ============================================================================
 * ======
 *
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ============================================================================
 * =======
 */
package com.sydac.simulatormanager.plugin.timetable.ui.controller;

import com.sydac.simulatormanager.legacy.Controller;
import com.sydac.simulatormanager.plugin.timetable.ui.model.AddStationTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.SelectStationTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.StationTableData;

/**
 * The <code>TimeTablePopupController</code> class controls the action to add or
 * delete Stations in TimeTable
 *
 * @author patanges
 *
 * @see Controller
 */
public class TimetablePopupController extends Controller
{
  public static final int ADD_LOCATION_AT_CURSOR = 0;

  public static final int ADD_LOCATION_FRONT = 1;

  public static final int ADD_LOCATION_REAR = 2;

  public static final int ADD_LOCATION_UNKNOWN = -1;

  private static TimetablePopupController instance = null;

  private AddStationTableEditModel addStationTableDataModel;

  private SelectStationTableEditModel selectStationTableDataModel;

  private TimetablePopupController()
  {
    super();
  } // TimeTablePopupController

  /**
   * Method: getInstance
   *
   * @return _instance the current instance of TimeTablePopupController
   */
  public static synchronized TimetablePopupController getInstance()
  {
    if (instance == null)
    {
      instance = new TimetablePopupController();
    } // if
    return instance;
  } // getInstance

  public void addStationAt(int row)
  {
    if (row >= 0)
    {
      StationTableData stationTableData = selectStationTableDataModel.getSelectStationTableDatas().get(row);
      addStationTableDataModel.addStation(stationTableData);
    } // else if
  } // addStationAt

  public void removeStationAt(int row)
  {
    addStationTableDataModel.removeStation(row);
  } // removeStationAt

  public void addAllStation()
  {
    addStationTableDataModel.addAllStation(selectStationTableDataModel.getSelectStationTableDatas());
  } // addAllStation

  public void setAddStationTableDataModel(AddStationTableEditModel addStationTableDataModel)
  {
    this.addStationTableDataModel = addStationTableDataModel;
  }

  public void setSelectStationTableDataModel(SelectStationTableEditModel selectStationTableDataModel)
  {
    this.selectStationTableDataModel = selectStationTableDataModel;
  }

} // class TimeTablePopupController

// -- EOF
