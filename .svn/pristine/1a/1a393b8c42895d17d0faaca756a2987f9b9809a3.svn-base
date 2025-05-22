/*
 * ==================================================================
 *
 * (C) Copyright 2010 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.replay;

import static com.sydac.gui.layout.Layout.DEFAULT_SPACING_STRING;
import static com.sydac.gui.layout.Layout.RIGHT;
import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Optional;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.stream.Collectors;

import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;
import javax.swing.ScrollPaneConstants;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.TableCellRenderer;

import com.sydac.common.dataobjects.DBPhysicalHub;
import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBSimInstructor;
import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.common.dataobjects.DBSimUser;
import com.sydac.contentutils.scenario.gui.formatter.DBSimUserFormatter;
import com.sydac.foundation.AsyncSwingModelListener;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.foundation.functional.Pair;
import com.sydac.gui.components.table.ConfigurableTableModel;
import com.sydac.gui.components.table.FilteredTableModel;
import com.sydac.gui.components.table.IColumnConfig;
import com.sydac.gui.components.table.SortedTable;
import com.sydac.gui.components.table.TableFilteringControl;
import com.sydac.gui.components.table.TableSorter;
import com.sydac.gui.components.table.Tables;
import com.sydac.gui.components.table.TextAreaCellRenderer;
import com.sydac.simulatorcontroller.model.SessionManager;
import com.sydac.utility.DateTimeUtils;

import net.miginfocom.layout.AC;
import net.miginfocom.layout.CC;
import net.miginfocom.layout.LC;
import net.miginfocom.swing.MigLayout;

/**
 * A panel that displays a configurable table containing replayable sessions.
 * The table will have a scroll bar for your convenience.
 *
 * @author Stanley Mladenov
 */
public class ReplaySessionSelectionTablePanel extends JPanel
{
  /**
   * Creates a column configuration which shows the Trainees' names against the
   * hub they used.
   */
  public static IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, String> createTraineesHubsColumnConfig()
  {
    return new TraineesColConfig();
  }

  /**
   * Creates a column configuration which shows the Instructor's name.
   */
  public static IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, String> createInstructorColumnConfig()
  {
    return new InstructorColConfig();
  }

  /**
   * Creates a column configuration which shows the name of the Scenario. Note
   * that this is called the "Description" in the database.
   */
  public static IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, String> createScenarioNameColumnConfig()
  {
    return new ScenarioColConfig();
  }

  /**
   * Creates a column configuration which shows the Session start time.
   */
  public static IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, FormattedDate> createSessionDateColumnConfig()
  {
    return new DateColConfig();
  }

  /**
   * Returns a default Session table configuration. Currently this has columns
   * for Trainee(s), Instructor, Scenario and (Session) Date.
   *
   * @return a default Scenario table configuration.
   */
  private static List<IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?>> createDefaultColumnConfig()
  {
    return Arrays.asList(createTraineesHubsColumnConfig(), createInstructorColumnConfig(), createScenarioNameColumnConfig(), createSessionDateColumnConfig());
  }

  private SessionManager sessionManager;

  private final ConfigurableTableModel<Pair<DBSimSession, Collection<DBSimSessionHub>>> savedSessionsTableModel;

  private final FilteredTableModel<ConfigurableTableModel<Pair<DBSimSession, Collection<DBSimSessionHub>>>> filteredTableModel;

  private final TableSorter sortedTableModel;

  private final JScrollPane savedSessionsScrollPane = new JScrollPane();

  private final SortedTable savedSessionsTable;

  private final TableFilteringControl textFilter;

  private CopyOnWriteArrayList<SessionSelectionListener> selectionListeners = new CopyOnWriteArrayList<>();

  /**
   * Constructs the table panel with default column settings.
   */
  public ReplaySessionSelectionTablePanel()
  {
    this(createDefaultColumnConfig());
  }

  /**
   * @deprecated Only here for backwards compatibility. Please use an
   *             alternative constructor.
   */
  @Deprecated
  public ReplaySessionSelectionTablePanel(IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?>[] columnConfigs)
  {
    this(Arrays.asList(columnConfigs));
  }

  /**
   * Constructs the table panel with customised column settings.
   */
  public ReplaySessionSelectionTablePanel(List<IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?>> columnConfigs)
  {
    savedSessionsTableModel = new ConfigurableTableModel<>(columnConfigs);
    filteredTableModel = new FilteredTableModel<>(savedSessionsTableModel);
    sortedTableModel = new TableSorter(filteredTableModel);
    savedSessionsTable = new SortedTable(sortedTableModel);
    textFilter = new TableFilteringControl(filteredTableModel);

    sessionManager = SessionManager.getInstance();

    try
    {
      jbInit();
    }
    catch (Exception ex)
    {
      ex.printStackTrace();
    }

    sessionManager.addModelListener(sessionsHandler, true);
  }

  private void jbInit() throws Exception
  {
    setBorder(BorderFactory.createTitledBorder(t("Saved Sessions"))); //$NON-NLS-1$

    savedSessionsScrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
    savedSessionsScrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);

    savedSessionsTable.getTableHeader().setReorderingAllowed(true);
    savedSessionsTable.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
    savedSessionsTable.getSelectionModel().addListSelectionListener(new ListSelectionListener()
    {
      @Override
      public void valueChanged(ListSelectionEvent e)
      {
        if (e.getValueIsAdjusting() == false)
        {
          if (savedSessionsTable.getSelectedRowCount() == 0)
          {
            notifySessionDeselected();
          }
          else
          {
            Optional<Pair<DBSimSession, Collection<DBSimSessionHub>>> row = savedSessionsTableModel
                .getRow(Tables.findRootTableModelRow(sortedTableModel, filteredTableModel, savedSessionsTable.getSelectedRow()));

            if (row.isPresent())
            {
              notifySessionSelected(row.get());
            }
            else
            {
              notifySessionDeselected();
            }
          }
        }
      }
    });

    savedSessionsTable.addMouseListener(new MouseAdapter()
    {
      @Override
      public void mouseClicked(MouseEvent e)
      {
        if (e.getClickCount() == 2)
        {
          savedSessionsTableModel.getRow(Tables.findRootTableModelRow(sortedTableModel, filteredTableModel, savedSessionsTable.getSelectedRow())).ifPresent(r -> notifySessionDoubleClicked(r));
        }
      }
    });

    savedSessionsTableModel.applyColumnStyles(savedSessionsTable);
    savedSessionsTable.setSortedColumn(3, false);
    savedSessionsScrollPane.getViewport().add(savedSessionsTable);

    setLayout(new MigLayout(new LC().insets(DEFAULT_SPACING_STRING).gridGap(DEFAULT_SPACING_STRING, DEFAULT_SPACING_STRING), new AC().grow(100, 0), new AC().grow(100, 1).grow(0, 0)));

    add(textFilter, new CC().cell(0, 0, 2, 1).alignX(RIGHT));
    add(savedSessionsScrollPane, new CC().cell(0, 1, 2, 1).minWidth(Integer.toString(300)).grow());
  }

  /**
   * Adds a listener to the table.
   *
   * @param listener
   */
  public void addSessionSelectionListener(SessionSelectionListener listener)
  {
    selectionListeners.add(listener);
  }

  private void notifySessionDeselected()
  {
    for (SessionSelectionListener listener : selectionListeners)
    {
      listener.selectionCleared();
    }
  }

  private void notifySessionSelected(Pair<DBSimSession, Collection<DBSimSessionHub>> selectedSession)
  {
    for (SessionSelectionListener listener : selectionListeners)
    {
      listener.sessionRowSelected(selectedSession);
    }
  }

  private void notifySessionDoubleClicked(Pair<DBSimSession, Collection<DBSimSessionHub>> selectedSession)
  {
    for (SessionSelectionListener listener : selectionListeners)
    {
      listener.sessionRowDoubleClicked(selectedSession);
    }
  }

  @Override
  public void setEnabled(boolean enabled)
  {
    savedSessionsTable.setEnabled(enabled);
  }

  public void clearSelection()
  {
    savedSessionsTable.clearSelection();
  }

  public void refreshData()
  {
    sessionManager.refreshData();
  }

  /**
   * Handles changes to the sessions.
   */
  private IModelListener sessionsHandler = new AsyncSwingModelListener(new IModelListener()
  {
    @Override
    public void update(Model model, Enum<?> whatChanged)
    {
      Map<Integer, Collection<DBSimSessionHub>> sessionMap = sessionManager.getSessionHubs();
      List<Pair<DBSimSession, Collection<DBSimSessionHub>>> sessionData = new ArrayList<>();

      for (Integer key : sessionMap.keySet())
      {
        DBSimSession savedSession = sessionManager.getSavedSession(key);

        if (savedSession != null /* && !isIdealRunSession(savedSession) */)
        {
          sessionData.add(new Pair<>(savedSession, sessionMap.get(key)));
        }
      }

      savedSessionsTableModel.setData(sessionData);
    }

    
  });

  /**
   * @deprecated Only here for backwards compatibility. Please use
   *             {@link IColumnConfig} instead.
   */
  @Deprecated
  public static interface TableColConfig<T> extends IColumnConfig<T, Object>
  {}

  /**
   * Helper class for implementing {@link TableColConfig}.
   */
  public static abstract class AbstractSavedSessionsTableColConfig<R> implements IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, R>
  {
    String columnName;

    int preferredWidth;

    protected AbstractSavedSessionsTableColConfig(String colName, int prefWidth)
    {
      columnName = colName;
      preferredWidth = prefWidth;
    }

    public final void setColumnName(String colName)
    {
      columnName = colName;
    }

    @Override
    public final String getColumnName()
    {
      return columnName;
    }

    public final void setPreferredWidth(int prefWidth)
    {
      preferredWidth = prefWidth;
    }

    @Override
    public final int getPreferredWidth()
    {
      return preferredWidth;
    }

    /**
     * @return a new {@link TextAreaCellRenderer}.
     */
    @Override
    public TableCellRenderer getCellRenderer()
    {
      return new TextAreaCellRenderer();
    }
  }

  /**
   * A default class for adding a Trainee(s) column to the Saved Sessions Table.
   *
   * @deprecated Use {@link #createTraineesHubsColumnConfig()} instead.
   */
  @Deprecated
  public static final class TraineesColConfig extends AbstractSavedSessionsTableColConfig<String>
  {
    public TraineesColConfig()
    {
      super(t("Trainee(s)"), 450); //$NON-NLS-1$
    }

    @Override
    public Class<String> getColumnClass()
    {
      return String.class;
    }

    @Override
    public String cellValue(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
    {
      return simSession.getSecond().stream().filter(ss -> Objects.nonNull(ss.getDriver())).map(ss -> traineeHubInfoToString(ss)).collect(Collectors.joining("\n")); //$NON-NLS-1$
    }

    private String traineeHubInfoToString(DBSimSessionHub session)
    {
      DBPhysicalHub hub = session.getPhysicalHub();
      DBSimUser traineeUser = session.getDriver().getUser();
      return MessageFormat.format(t("{0} {1} on {2}, {3}"), //$NON-NLS-1$
          traineeUser.getFirstName(), traineeUser.getLastName(), hub.getPhysicalHubName(), hub.getSimulator().getSimulatorName());
    }
  }

  /**
   * A default class for adding an Instructor column to the Saved Sessions
   * Table.
   *
   * @deprecated Use {@link #createInstructorColumnConfig()} instead.
   */
  @Deprecated
  public static final class InstructorColConfig extends AbstractSavedSessionsTableColConfig<String>
  {
    public InstructorColConfig()
    {
      super(t("Instructor"), 200); //$NON-NLS-1$
    }

    @Override
    public Class<String> getColumnClass()
    {
      return String.class;
    }

    @Override
    public String cellValue(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
    {
      // same instructor for all hubs
      DBSimInstructor instructor = simSession.getFirst().getInstructor();
      DBSimUser instructorUser = instructor.getUser();
      return DBSimUserFormatter.getDisplayName(instructorUser);
    }

  }

  /**
   * A default class for adding a Scenario column to the Saved Sessions Table.
   *
   * @deprecated Use {@link #createScenarioNameColumnConfig()} instead.
   */
  @Deprecated
  public static final class ScenarioColConfig extends AbstractSavedSessionsTableColConfig<String>
  {
    public ScenarioColConfig()
    {
      super(t("Scenario"), 550); //$NON-NLS-1$
    }

    @Override
    public Class<String> getColumnClass()
    {
      return String.class;
    }

    @Override
    public String cellValue(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
    {
      // same scenario for all hubs
      DBScenario scenario = simSession.getFirst().getScenario();

      return (scenario != null ? scenario.getDescription() : t("Invalid scenario")); //$NON-NLS-1$
    }

  }

  /**
   * A default class for adding a Date column to the Saved Sessions Table.
   *
   * @deprecated Use {@link #createSessionDateColumnConfig()} instead.
   */
  @Deprecated
  public static final class DateColConfig extends AbstractSavedSessionsTableColConfig<FormattedDate>
  {
    public DateColConfig()
    {
      super(t("Date"), 200); //$NON-NLS-1$
    }

    @Override
    public Class<FormattedDate> getColumnClass()
    {
      return FormattedDate.class;
    }

    @Override
    public FormattedDate cellValue(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
    {
      // same for all hubs
      return new FormattedDate(simSession.getFirst().getStartDateUTC());
    }
  }

  /**
   * Wrapper for a {@link Date} object, applies some formatting to it.
   * Immutable.
   */
  private static class FormattedDate implements Comparable<FormattedDate>
  {
    Date date;

    String string;

    FormattedDate(Date d)
    {
      date = d;
      string = DateTimeUtils.getShortDateLongTimeString(date);
    }

    @Override
    public String toString()
    {
      return string;
    }

    @Override
    public int compareTo(FormattedDate o)
    {
      return date.compareTo(o.date);
    }
  }

  /**
   * Interface for classes to receive notifications on user interaction with the
   * table.
   */
  public interface SessionSelectionListener
  {
    /**
     * Called when a selection is cleared.
     */
    public void selectionCleared();

    /**
     * Called when a row is selected (by single click or keyboard navigation).
     *
     * @param simSession
     *          a session ID - list of session hubs pair.
     */
    public void sessionRowSelected(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession);

    /**
     * Called specifically when a row is double-clicked.
     *
     * @param simSession
     *          a session ID - list of session hubs pair.
     */
    public void sessionRowDoubleClicked(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession);

  }

}
