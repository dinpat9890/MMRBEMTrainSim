/**
 * ==================================================================
 * 
 * (C) Copyright 2018 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.simulatormanager.plugin.timetable.ui;

import static com.sydac.simulatormanager.i18n.SimulatorManagerI18N.t;

import javax.swing.table.TableColumnModel;

import com.sydac.simulatormanager.plugin.timetable.ui.controller.TimetablesTableEditController;
import com.sydac.simulatormanager.plugin.timetable.ui.model.SelectStationTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetableData;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetablesTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetablesTableRowEditControlModel;
import com.sydac.simulatormanager.scenariobuilder.gui.TableEditPanel;
import com.sydac.simulatormanager.scenariobuilder.model.TableEditModel.TableModel;
import com.sydac.simulatormanager.scenariobuilder.model.manager.ScenarioManager;
import com.sydac.simulatormanager.scenariobuilder.model.manager.ScenarioManager.ScenarioAction;
import com.sydac.simulatormanager.scenariobuilder.model.valueobjects.ScenarioModel;

public class TimetablePluginPanel extends TableEditPanel
{

  private TimetablesTableEditModel timetablesTableEditModel;

  /**
   * 
   * @param selectStationTableDataModel
   *          Station table data
   * @param trackTimeTableListTableEditModel
   *          time table list
   */
  public TimetablePluginPanel(SelectStationTableEditModel selectStationTableDataModel,
      TimetablesTableEditModel trackTimeTableListTableEditModel)
  {
    this.timetablesTableEditModel = trackTimeTableListTableEditModel;
    TimetablesTableEditController controller = new TimetablesTableEditController(selectStationTableDataModel,
        trackTimeTableListTableEditModel, TimetablesTableRowEditControlModel.getInstance());
    initialise(controller, trackTimeTableListTableEditModel, new TimeTablesTableModel());

    TableColumnModel columnModel = table.getColumnModel();
    // use large numbers so that they scale down in proportion
    // small numbers scale up in such a way that trends to equal widths
    columnModel.getColumn(0).setPreferredWidth(1000);
    columnModel.getColumn(1).setPreferredWidth(1000);
    columnModel.getColumn(2).setPreferredWidth(1000);
    columnModel.getColumn(3).setPreferredWidth(1000);
    columnModel.getColumn(4).setPreferredWidth(1000);
    columnModel.getColumn(5).setMinWidth(0);
    columnModel.getColumn(5).setMaxWidth(0);

  }

  /**
   * @return The string to display in the title of a Delete dialog.
   */
  @Override
  protected String confirmDeletedDialogTitle()
  {
    return t("Delete TimeTable"); //$NON-NLS-1$
  }

  /**
   * Returns the string to display in the body of a Delete dialog; something of
   * the form "Are you sure you want to delete this item?"
   *
   * @return The string to display in the body of a Delete dialog.
   */
  @Override
  protected String confirmDeletedDialogMessage()
  {
    return t("Are you sure you want to delete this TimeTable?"); //$NON-NLS-1$
  }

  @Override
  public void setEnabled(boolean enabled)
  {
    super.setEnabled(enabled);
    if (enabled)
    {
      timetablesTableEditModel.triggerButtonEnabling();
    }
  }

  @Override
  public boolean isEnabled()
  {
    return super.isEnabled() && isEditing();
  }

  private boolean isEditing()
  {
    ScenarioManager scenarioManager = ScenarioManager.getInstance();
    ScenarioModel scenarioModel = scenarioManager.getCurrentScenarioModel();
    ScenarioAction scenarioAction = scenarioManager.getScenarioAction();
    return scenarioAction == ScenarioAction.NEW
        || (scenarioAction == ScenarioAction.MODIFY && scenarioModel.getScenarioId() != 0);
  }

  static final class TimeTablesTableModel extends TableModel
  {
    public TimeTablesTableModel()
    {
      super(new String[] { t("Name"), //$NON-NLS-1$
          t("Route Code"), //$NON-NLS-1$
          t("Line Name"), //$NON-NLS-1$
          t("Start Station"), //$NON-NLS-1$
          t("End Station"), //$NON-NLS-1$
          t("Station Data List"), //$NON-NLS-1$
      });
    }

    @Override
    public Object getValueAt(int row, int col)
    {
      TimetableData f = (TimetableData)rowData.get(row);
      Object field = null;
      switch (col)
      {
      case 0:
        field = f.getName();
        break;
      case 1:
        field = f.getRouteCode();
        break;
      case 2:
        field = f.getLineName();
        break;
      case 3:
        field = f.getStartStationName();
        break;
      case 4:
        field = f.getEndStationName();
        break;
      case 5:
        field = f.getStationDataList();
        break;
      default:
        break;
      }
      return field;
    }
  }
}
