/*
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import com.sydac.simulatormanager.plugin.IScenarioBuilderPlugin;
import com.sydac.simulatormanager.plugin.timetable.model.TimetableManager;
import com.sydac.simulatormanager.plugin.timetable.ui.TimetablePluginPanel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.SelectStationTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetablesTableEditModel;
import com.sydac.simulatormanager.scenariobuilder.ScenarioBuilderTool;

/**
 * TimeTablePlugin provides UI for adding more time tables to scenario. User can
 * add, edit and delete TimeTables associated with Scenario
 * 
 */
public final class TimetablePlugin implements IScenarioBuilderPlugin
{

  private TimetableManager timeTablesManager;

  /**
   * Allow plug-ins to add GUI components to the
   * <code>ScenarioBuilderPanel</code>.
   *
   * @return list ScenarioBuilderTool
   */

  @Override
  public List<ScenarioBuilderTool> getTools()
  {
    SelectStationTableEditModel selectStationTableDataModel = new SelectStationTableEditModel(
        new ArrayList<>());
    TimetablesTableEditModel trackTimeTableListTableEditModel = new TimetablesTableEditModel();
    timeTablesManager = new TimetableManager(selectStationTableDataModel, trackTimeTableListTableEditModel);
    timeTablesManager.registerListeners();
    TimetablePluginPanel tablepanel = new TimetablePluginPanel(selectStationTableDataModel,
        trackTimeTableListTableEditModel);

    tablepanel.setName("Timetable");
    ScenarioBuilderTool d = new ScenarioBuilderTool(tablepanel.getName(), null, tablepanel);

    return new ArrayList<ScenarioBuilderTool>(Arrays.asList(d));
  }

  /**
   * Allow plug-ins to delete data from the database when the specified scenario
   * is deleted.
   *
   * @param dbScenarioID
   *          Database ID of scenario being deleted from the database.
   * @return Flag indicating whether the plug-in was successful in deleting data
   *         or not.
   */
  @Override
  public boolean deleteFromDatabase(int dbScenarioID)
  {
    return timeTablesManager.deleteFromDatabase(dbScenarioID);
  }

  /**
   * Allow plug-ins to save data to the database when the specified scenario is
   * saved.
   *
   * @param dbScenarioID
   *          Database ID of scenario being saved to the database.
   * @param saveAsNew
   *          Flag indicating whether the scenario save is saving a new scenario
   *          or updating an existing scenario.
   * @return Flag indicating whether the plug-in was successful in saving or
   *         not.
   */
  @Override
  public boolean saveToDatabase(int dbScenarioID, boolean saveAsNew)
  {
    return timeTablesManager.saveToDatabase(dbScenarioID, saveAsNew);
  }
}
