/**
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable.model;

import java.util.Date;

import com.sydac.common.dataobjects.DBScenario;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.simulatormanager.plugin.timetable.ui.model.SelectStationTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetablesTableEditModel;
import com.sydac.simulatormanager.scenariobuilder.model.manager.ScenarioManager;
import com.sydac.simulatormanager.scenariobuilder.model.valueobjects.ScenarioModel;

/**
 * This class listens to Scenario events by listening to ScenarioManager changes
 * and updates the model accordingly.
 *
 */
public class TimetableManager
{
  /* The caution order directory path from configuration */

  /* Training details model */
  private SelectStationTableEditModel selectStationTableDataModel;

  /* Performance Parameter model */
  private TimetablesTableEditModel trackTimeTableListTableEditModel;

  /**
   * Creates the ScenarioDetailsManger instance
   * 
   * @param trainingDetailsModel
   *          Training detail model
   * @param trackTimeTableListTableEditModel
   *          Track time table list edit model
   */
  public TimetableManager(SelectStationTableEditModel trainingDetailsModel,
      TimetablesTableEditModel trackTimeTableListTableEditModel)
  {
    this.selectStationTableDataModel = trainingDetailsModel;
    this.trackTimeTableListTableEditModel = trackTimeTableListTableEditModel;
  }

  /**
   * Registers model listeners
   */
  public void registerListeners()
  {
    ScenarioManager scenarioManager = ScenarioManager.getInstance();
    scenarioManager.addModelListener(scenarioListener, ScenarioManager.Change.SCENARIO_DELETED_OK, false);
    scenarioManager.addModelListener(scenarioListener, ScenarioManager.Change.CURRENT_SCENARIO_CHANGED,
        false);
    scenarioManager.addModelListener(scenarioListener, ScenarioManager.Change.SCENARIO_ACTION_CHANGED, false);
    scenarioManager.addModelListener(scenarioListener,
        ScenarioManager.Change.SCENARIO_TRACK_LOCKED_IN_CHANGED, false);
  }

  /**
   * Deletes associated data from database when a scenario is deleted.
   *
   * @param dbScenarioID
   *          Database ID of scenario being deleted from the database.
   * @return boolean indicating the status of delete operation.
   */
  public boolean deleteFromDatabase(int dbScenarioID)
  {
    DBScenario dbScenario = new DBScenario(dbScenarioID);
    return trackTimeTableListTableEditModel.deleteFromDatabase(dbScenario);
  }

  /**
   * Saves data to the database when the specified scenario is saved.
   *
   * @param dbScenarioID
   *          Database ID of scenario being saved to the database.
   * @param saveAsNew
   *          boolean indicating whether the scenario save is saving a new
   *          scenario or updating an existing scenario.
   * @return boolean indicating whether the plug-in was successful in saving or
   *         not.
   */
  public boolean saveToDatabase(int dbScenarioID, boolean saveAsNew)
  {
    ScenarioManager scenarioManager = ScenarioManager.getInstance();
    ScenarioModel scenarioModel = scenarioManager.getCurrentScenarioModel();
    int trackNwId = scenarioModel.getTrackNetwork().getTrackNetworkId();
    Date date = new Date(scenarioModel.getInitialDate().getTime());
    return trackTimeTableListTableEditModel.saveToDatabase(dbScenarioID, trackNwId, date, saveAsNew,selectStationTableDataModel.getRouteLineData());
  }

  /* Listens to changes. */
  private IModelListener scenarioListener = (Model model, Enum<?> whatChanged) -> {
    if (model instanceof ScenarioManager)
    {
      ScenarioManager scenarioManager = ScenarioManager.getInstance();
      ScenarioModel scenarioModel = scenarioManager.getCurrentScenarioModel();

      if (whatChanged == ScenarioManager.Change.CURRENT_SCENARIO_CHANGED)
      {
        int scenarioId = scenarioModel.getScenarioId();
        if (scenarioId > 0)
        {
          trackTimeTableListTableEditModel.onScenarioChange(scenarioId);
        }
      }
      else if (whatChanged == ScenarioManager.Change.SCENARIO_TRACK_LOCKED_IN_CHANGED)
      {
        selectStationTableDataModel.onTrackNetworkChange();
      }
      else if (whatChanged == ScenarioManager.Change.SCENARIO_ACTION_CHANGED)
      {
        trackTimeTableListTableEditModel.reset();
        selectStationTableDataModel.reset();
      }
    }
  };
}
