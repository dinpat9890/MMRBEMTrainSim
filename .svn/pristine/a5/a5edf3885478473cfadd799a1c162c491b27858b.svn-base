/* ==================================================================
 *
 *  (C) Copyright 2015 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.replay;

import static com.sydac.gui.layout.Layout.CENTER;
import static com.sydac.gui.layout.Layout.DEFAULT_SPACING_STRING;
import static com.sydac.gui.layout.Layout.ZERO;
import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.MessageFormat;
import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.Optional;
import java.util.function.Function;
import java.util.stream.Collectors;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JEditorPane;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.TableCellRenderer;

import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.contentutils.scenario.gui.formatter.DBSimUserFormatter;
import com.sydac.contentutils.scenario.gui.formatter.IScenarioDetailsFormatter;
import com.sydac.contentutils.session.gui.formatter.DBSimSessionFormatter;
import com.sydac.foundation.functional.Pair;
import com.sydac.gui.components.Buttons;
import com.sydac.gui.components.TextFields;
import com.sydac.gui.components.table.IColumnConfig;
import com.sydac.mmrbem.scc.plugin.sessionsetup.replay.ReplaySessionSelectionTablePanel.AbstractSavedSessionsTableColConfig;
import com.sydac.mmrbem.scc.plugin.sessionsetup.replay.ReplaySessionSelectionTablePanel.SessionSelectionListener;
import com.sydac.simulatorcontroller.model.IDefineSessionListener;
import com.sydac.simulatorcontroller.model.LocalStateModel;
import com.sydac.utility.HTMLBuilder;

import net.miginfocom.layout.AC;
import net.miginfocom.layout.CC;
import net.miginfocom.layout.LC;
import net.miginfocom.swing.MigLayout;

/**
 * A dialog to let a user select a session for replay.
 *
 * @author Stanley Mladenov
 */
public class SessionSelectionDialog
  extends JDialog
{
  // The following are thin wrappers to ReplaySessionSelectionTablePanel's helpers.
  // These are provided to make the interface similar to the scenario and session selection dialogs.

  /**
   * Creates a column configuration which shows the Instructor's name.
   */
  public static IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, String> createInstructorColumnConfig()
  {
    return ReplaySessionSelectionTablePanel.createInstructorColumnConfig();
  }

  /**
   * Creates a column configuration which shows the name of the Scenario.
   * Note that this is called the "Description" in the database.
   */
  private static IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, String> createScenarioNameColumnConfig()
  {
    return ReplaySessionSelectionTablePanel.createScenarioNameColumnConfig();
  }

  /**
   * Creates a column configuration which shows the Session start time.
   */
  private static IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?> createSessionDateColumnConfig()
  {
    return ReplaySessionSelectionTablePanel.createSessionDateColumnConfig();
  }

  // End of thin wrappers.

  /**
   * Creates a column configuration which shows the Trainees' names.
   * Only one name is shown in the cell, others are revealed in the tool tip on mouse over.
   */
  public static IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?> createTraineesColumnConfig()
  {
    return new TraineesColConfig();
  }

  /**
   * Returns a default Session table configuration.
   * Currently this has columns for Trainee (as described in {@link #createTraineesColumnConfig()}),
   * Instructor, Scenario and (Session) Date.
   *
   * @return a default Scenario table configuration.
   */
  public static List<IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?>> createDefaultColumnConfigs()
  {
    return Arrays.asList(
        createTraineesColumnConfig(),
        createInstructorColumnConfig(),
        createScenarioNameColumnConfig(),
        createSessionDateColumnConfig());
  }

  private final Function<DBScenario, IScenarioDetailsFormatter> detailsFormatterSupplier;

  private JSplitPane splitPane;

  private final JPanel dialogPanel = new JPanel();
  private final JEditorPane selectedSessionDetails = new JEditorPane();

  private final JButton okButton     = Buttons.createOkButton();
  private final JButton cancelButton = Buttons.createCancelButton();

  private final ReplaySessionSelectionTablePanel sessionTable;

  /** Whether a valid selection was made */
  private boolean validSelection = false;
  /** The session that was selected by the user */
  private Pair<DBSimSession, Collection<DBSimSessionHub>> selectedSession;

  /**
   * Constructs a new <code>SessionSelectionDialog</code>.
   *
   * @param parent the parent window.
   * @param modal <code>true</code> if the dialog should be modal to the parent frame
   */
  public SessionSelectionDialog(Window parent, boolean modal)
  {
    this(parent, modal ? ModalityType.APPLICATION_MODAL : ModalityType.MODELESS, Optional.empty(), Optional.empty());
  }

  /**
   * Constructs a new <code>SessionSelectionDialog</code>.
   *
   * @param parent the parent window.
   * @param modality the modality type.
   * @param optionalDetailsFormatterSupplier An optional supplier of {@link IScenarioDetailsFormatter}s
   *   for project-specific scenario details.
   * @param optionalTableColumnConfigs Optional settings for the selection table columns.
   *   See the various factory methods in this class and in {@link ReplaySessionSelectionTablePanel}
   *   for possible inclusions (or roll your own).
   */
  public SessionSelectionDialog(Window parent, ModalityType modality,
      Optional<Function<DBScenario, IScenarioDetailsFormatter>> optionalDetailsFormatterSupplier,
      Optional<List<IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?>>> optionalTableColumnConfigs)
  {
    this(parent, modality,
      optionalDetailsFormatterSupplier.orElse(s -> new IScenarioDetailsFormatter(){}),
      optionalTableColumnConfigs.orElseGet(() -> createDefaultColumnConfigs()));
  }

  /**
   * Constructs a new <code>SessionSelectionDialog</code>.
   *
   * @param parent the parent window.
   * @param modality the modality type.
   * @param aDetailsFormatterSupplier A supplier of {@link IScenarioDetailsFormatter}s
   *   for project-specific scenario details.
   * @param aTableColumnConfigs Optional settings for the selection table columns.
   *   See the various factory methods in this class and in {@link ReplaySessionSelectionTablePanel}
   *   for possible inclusions (or roll your own).
   */
  public SessionSelectionDialog(Window parent, ModalityType modality,
      Function<DBScenario, IScenarioDetailsFormatter> aDetailsFormatterSupplier,
      List<IColumnConfig<Pair<DBSimSession, Collection<DBSimSessionHub>>, ?>> aTableColumnConfigs)
  {
    super(parent, t("Select Session"), modality); //$NON-NLS-1$
    detailsFormatterSupplier = aDetailsFormatterSupplier;

    sessionTable = new ReplaySessionSelectionTablePanel(aTableColumnConfigs);

    // The table panel always adds a border which we don't want here.
    sessionTable.setBorder(null);

    try
    {
      jbInit();
      pack();
      splitPane.setDividerLocation(splitPane.getMaximumDividerLocation());

      Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
      Dimension windowSize = this.getPreferredSize();
      setLocation((screenSize.width  - windowSize.width) /2,
                  (screenSize.height - windowSize.height)/2);
    }
    catch (Exception ex)
    {
      ex.printStackTrace();
    }

    // short circuit.
    LocalStateModel.getInstance().addDefineSessionListener(new IDefineSessionListener()
    {
      @Override
      public void defineSession()
      {
        setVisible(false);
      }
    });
  }

  /**
   * Lays out the dialog contents.
   */
  private void jbInit()
  {
    Container contentPane = this.getContentPane();

    sessionTable.addSessionSelectionListener(new SessionSelectionListener()
    {
      @Override
      public void selectionCleared()
      {
        updateSelectedScenarioDetails(null);
      }

      @Override
      public void sessionRowSelected(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
      {
        updateSelectedScenarioDetails(simSession);
      }

      @Override
      public void sessionRowDoubleClicked(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
      {
        updateSelectedScenarioDetails(simSession);
        okButtonPressed();
      }
    });

    selectedSessionDetails.setEditable(false);
    selectedSessionDetails.setContentType(TextFields.CONTENT_TYPE_TEXT_HTML);
    TextFields.setLookAndFeel(selectedSessionDetails);

    updateSelectedScenarioDetails(null);
    JScrollPane detailsScroller =
      new JScrollPane(selectedSessionDetails, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);

    okButton.setEnabled( false );
    okButton.addActionListener( new ActionListener()
    {
      @Override
      public void actionPerformed( ActionEvent e )
      {
        okButtonPressed();
      }
    });

    cancelButton.addActionListener( new ActionListener()
    {
      @Override
      public void actionPerformed( ActionEvent e )
      {
        cancelButtonPressed();
      }
    });

    // defined here to make layout code neater
    JLabel sessions = new JLabel(t("Available Sessions")); //$NON-NLS-1$
    JLabel details = new JLabel(t("Session Details")); //$NON-NLS-1$

    // Do the layout
    JPanel okCancelPanel = new JPanel(new MigLayout(new LC().insets(ZERO)));
    okCancelPanel.add(okButton,     new CC().width("80!").height("25!")); //$NON-NLS-1$ //$NON-NLS-2$
    okCancelPanel.add(cancelButton, new CC().width("90!").height("25!")); //$NON-NLS-1$ //$NON-NLS-2$

    String minWidth = Integer.toString(300);

    JPanel selectionPanel = new JPanel(
        new MigLayout(new LC().insets(DEFAULT_SPACING_STRING)
                              .gridGap(DEFAULT_SPACING_STRING, DEFAULT_SPACING_STRING),
                      new AC().grow(100, 0),
                      new AC().grow(100, 1).grow(0, 0)));

    selectionPanel.add(sessions,     new CC().cell(0, 0));
    selectionPanel.add(sessionTable, new CC().cell(0, 1).minWidth(minWidth).grow());

    JPanel detailsPanel = new JPanel(
        new MigLayout(new LC().insets(DEFAULT_SPACING_STRING)
                              .gridGap(DEFAULT_SPACING_STRING, DEFAULT_SPACING_STRING),
                      new AC().grow(100),
                      new AC().grow(100, 1).grow(0, 0)));

    detailsPanel.add(details,         new CC().cell(0, 0));
    detailsPanel.add(detailsScroller, new CC().cell(0, 1).minWidth(minWidth).grow());

    splitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, selectionPanel, detailsPanel);
    splitPane.setResizeWeight(0.8);

    dialogPanel.setLayout(
        new MigLayout(new LC().insets(DEFAULT_SPACING_STRING)
                              .gridGap(DEFAULT_SPACING_STRING, DEFAULT_SPACING_STRING),
                      new AC().grow(100, 0),
                      new AC().grow(100, 0).grow(0, 1)));

    dialogPanel.add(splitPane,     new CC().cell(0, 0).grow());
    dialogPanel.add(okCancelPanel, new CC().cell(0, 1).alignX(CENTER));

    contentPane.add(dialogPanel);
  }

  private void updateSelectedScenarioDetails(Pair<DBSimSession, Collection<DBSimSessionHub>> aSelectedSession)
  {
    boolean selected = aSelectedSession != null;

    selectedSession = aSelectedSession;

    okButton.setEnabled(selected);

    if (!selected)
    {
      selectedSessionDetails.setText(t("Please Select a Session.")); //$NON-NLS-1$
    }
    else
    {
      DBSimSession simSession = selectedSession.getFirst();
      DBScenario scenario = new DBScenario(simSession.getScenarioId());

      selectedSessionDetails.setText(
          new DBSimSessionFormatter(simSession, scenario,
                                    detailsFormatterSupplier.apply(scenario)).getHTMLSummary());
      // make sure we're at the top of the scroll pane (not doing this will have it auto scroll to the bottom)
      selectedSessionDetails.setCaretPosition(0);
    }
  }

  /**
   * Called when the cancel button is pressed.
   */
  private void cancelButtonPressed()
  {
    selectedSession = null;
    dispose();
  }

  /**
   * Called when the Ok button is pressed.
   */
  private void okButtonPressed()
  {
    validSelection = true;
    dispose();
  }

  /**
   * Returns whether a valid selection was made.  If so, {@link #getSelectedSession()} will return the actual
   * selection.
   *
   * @return <code>true</code> if a valid selection was made, <code>false</code> otherwise
   */
  public boolean isValidSelection()
  {
    return validSelection;
  }

  /**
   * Returns the selected session and all of its hub data.
   */
  public Pair<DBSimSession, Collection<DBSimSessionHub>> getSelectedSession()
  {
    return selectedSession;
  }

  // -----------------------
  // Overridden Methods
  // -----------------------

  @Override
  public void setVisible(boolean visible)
  {
    if (visible)
    {
      // refresh the data
      sessionTable.clearSelection();
      validSelection = false;
      sessionTable.refreshData();
    }

    super.setVisible(visible);
  }


  // -----------------------
  // Inner Classes
  // -----------------------

  /**
   * A specific formatting of the trainee's column for this version of the session table.
   */
  private static final class TraineesColConfig
    extends AbstractSavedSessionsTableColConfig<CellValue>
  {
    public TraineesColConfig()
    {
      super(t("Trainee(s)"), 200); //$NON-NLS-1$
    }

    @Override
    public Class<CellValue> getColumnClass()
    {
      return CellValue.class;
    }

    @Override
    public TableCellRenderer getCellRenderer()
    {
      return new DefaultTableCellRenderer()
      {
        @Override
        public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected,
            boolean hasFocus, int row, int column)
        {
          DefaultTableCellRenderer renderer =
            (DefaultTableCellRenderer) super.getTableCellRendererComponent(table, value, isSelected, hasFocus, row, column);
          renderer.setToolTipText(((CellValue) value).toolTipText);
          return renderer;
        }
      };
    }

    @Override
    public CellValue cellValue(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
    {
      // Exclude instructor hubs.
      return new CellValue(simSession.getSecond().stream().filter((i)->{return i.getDriverId() != null;}).collect(Collectors.toList()));
    }
  }

  /**
   * Helper class for creating cell and tool tip text for the trainees in a session.
   */
  private static class CellValue
  {
    private String cellText;
    private String toolTipText;


    private CellValue(Collection<DBSimSessionHub> simSessions)
    {
      // Use HTML in the tool tip text so we can do multiple lines
      HTMLBuilder toolTipSB = new HTMLBuilder();
      Iterator<DBSimSessionHub> simSessionHubs = simSessions.iterator();

      if (simSessionHubs.hasNext())
      {
        String firstTrainee = DBSimUserFormatter.getDisplayName(simSessionHubs.next().getDriver().getUser());

        int otherCount = simSessions.size()-1;

        if (otherCount == 0)
        {
          cellText = firstTrainee;
        }
        else
        {
          // \u2026 is an ellipsis
          cellText = MessageFormat.format(t("{0}\u2026"), firstTrainee, otherCount); //$NON-NLS-1$
        }

        toolTipSB.startHTML().addText(firstTrainee);

        while (simSessionHubs.hasNext())
        {
          toolTipSB.br().addText(DBSimUserFormatter.getDisplayName(simSessionHubs.next().getDriver().getUser()));
        }

        toolTipSB.endHTML();
      }

      toolTipText = toolTipSB.toString();
    }


    @Override
    public String toString()
    {
      return cellText;
    }

  }
}
