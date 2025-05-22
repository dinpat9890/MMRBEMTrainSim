/* ==================================================================
 *
 *  (C) Copyright 2010 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.replay;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.MessageFormat;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.border.TitledBorder;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.TableColumnModel;

import com.sydac.common.dataobjects.DBHubModeTypeAssoc;
import com.sydac.common.dataobjects.DBPhysicalHub;
import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.common.dataobjects.DBSimUser;
import com.sydac.common.dataobjects.DBSimulator;
import com.sydac.common.dataobjects.DBSimulatorManager;
import com.sydac.contentutils.scenario.gui.formatter.DBSimUserFormatter;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.gui.components.MessagePanel;
import com.sydac.gui.components.MessagePanel.IconType;
import com.sydac.gui.components.NonEditableTextField;
import com.sydac.gui.components.SizedButton;
import com.sydac.gui.components.table.SortedTable;
import com.sydac.gui.components.table.TableSorter;
import com.sydac.gui.icon.EditingIcons;
import com.sydac.simulatorcontroller.gui.common.TooltipManager;
import com.sydac.simulatorcontroller.gui.icon.SessionIcons;
import com.sydac.simulatorcontroller.model.ConstantsModel;
import com.sydac.simulatorcontroller.session.setup.gui.table.RowEnablingSortedTable;
import com.sydac.simulatorcontroller.session.setup.gui.table.SelectedItemsSummaryTable;
import com.sydac.simulatorcontroller.session.setup.gui.table.model.GenericTableModel;
import com.sydac.simulatorcontroller.session.setup.gui.table.model.HubTableModel;
import com.sydac.simulatorcontroller.session.setup.gui.table.model.RowEnablingTableModel;
import com.sydac.utility.DateTimeUtils;

import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

/**
 * This class is a panel for setting up a replay session to run.
 * <p>
 * Projects may use this panel with the {@link ReplaySessionController} and {@link ReplaySessionModel}
 * classes.
 * <p>
 * This screen allows you to select a session and which hubs to play the
 * recorded hubs on. If the customer needs only a simple interface that replays
 * exactly what was recorded, you probably want the {@link ReplaySessionView}.
 * <p>
 * Note that this screen was based on {@link com.sydac.simulatorcontroller.session.setup.plugin.multihub.simulatedsession.preview.PreviewSessionView}.
 *
 * @author Stanley Mladenov
 *
 * @see ReplaySessionController
 * @see ReplaySessionModel
 * @see ReplaySessionView
 */
public final class ReplaySessionHubMappingView
  extends JPanel
{
  private static final String EMPTY_STRING = ""; //$NON-NLS-1$

  private final boolean sccSimRequired;

  private ReplaySessionController replaySessionController = null;
  private ReplaySessionModel replaySessionModel = null;

  private JTextField sessionField = new NonEditableTextField(new Dimension(500, 0));
  private JButton sessionButton = new JButton(t("Select Session...")); //$NON-NLS-1$

  private SourceHubTableModel sourceHubTableModel = new SourceHubTableModel();
  private TableSorter sourceHubTableSorter        = new TableSorter(sourceHubTableModel);
  private RowEnablingSortedTable sourceHubTable   = new RowEnablingSortedTable(sourceHubTableSorter);

  private HubTableModel destHubTableModel     = new HubTableModel();
  private TableSorter destHubTableSorter      = new TableSorter(destHubTableModel);
  private RowEnablingSortedTable destHubTable = new RowEnablingSortedTable(destHubTableSorter);

  private DBSimSessionHub selectedSourceHub;
  private DBPhysicalHub selectedDestHub;

  private JButton clearSelectionButton = new JButton(t("Clear Selections"), EditingIcons.CLEAR); //$NON-NLS-1$
  private JButton addSimConfigButton = new JButton(t("Add Playback Configuration"), EditingIcons.ADD); //$NON-NLS-1$

  private PlaybackSetupTable.PlaybackSetupTableModel playbackSetupTableModel;
  private TableSorter playbackSetupTableSorter;
  private SortedTable playbackSetupTable;

  private PlaybackSetupTable.PlaybackSetupTableModelData selectedPlaybackSetup;
  private JButton deletePlaybackSetupButton = new JButton(t("Delete"), EditingIcons.DELETE); //$NON-NLS-1$
  private JButton deleteAllPlaybackSetupButton = new JButton(t("Delete All"), EditingIcons.DELETE_ALL); //$NON-NLS-1$
  private JButton restorePlaybackSetupButton = new JButton(t("Restore Default Configuration"), EditingIcons.RESET); //$NON-NLS-1$

  private JLabel instructorLabel = new JLabel(t("Session Instructor")); //$NON-NLS-1$
  private JTextField instructorField = new NonEditableTextField(new Dimension(500, 0));

  private JLabel dateLabel = new JLabel(t("Simulated Start Date")); //$NON-NLS-1$
  private JTextField dateField = new NonEditableTextField();
  private JLabel timeLabel = new JLabel(t("Simulated Start Time")); //$NON-NLS-1$
  private JTextField timeField = new NonEditableTextField();

  private JLabel durationLabel = new JLabel(t("Duration")); //$NON-NLS-1$
  private JTextField durationField = new NonEditableTextField();

  private JLabel courseIdLabel = new JLabel(t("Course ID")); //$NON-NLS-1$
  private JTextField courseIdField = new NonEditableTextField();
  private JLabel sessionCodeLabel = new JLabel(t("Session Code")); //$NON-NLS-1$
  private JTextField sessionCodeField = new NonEditableTextField();

  private MessagePanel messagePanel = new MessagePanel();
  private JButton loadButton;
  private JButton clearButton;

  private Insets defaultInsets = new Insets(5, 5, 5, 5);


  public ReplaySessionHubMappingView(ReplaySessionController aController, ReplaySessionModel aModel)
  {
    this(aController, aModel, true);
  } // ReplaySessionHubMappingView


  public ReplaySessionHubMappingView(ReplaySessionController aController, ReplaySessionModel aModel, boolean aSCCSimRequired)
  {
    sccSimRequired = aSCCSimRequired;

    replaySessionController = aController;
    replaySessionModel = aModel;

    try
    {
      layoutScreen();
    } // try
    catch (Exception ex)
    {
      ex.printStackTrace();
    } // catch

    // FIXME: Don't pass partially constructed objects around, see #REVIEW 3061
    replaySessionModel.addModelListener( selectionHandler, ReplaySessionModel.Change.SELECTED_SESSION_CHANGED, true );
    replaySessionModel.addModelListener( hubMappingHandler, ReplaySessionModel.Change.HUB_MAPPING_CHANGED, true );
  } // ReplaySessionHubMappingView


  /**
   * Lays out the screen
   */
  private void layoutScreen()
  {
    setLayout( new GridBagLayout() );

    sessionButton.addActionListener( new ActionListener()
    {
      @Override
      public void actionPerformed( ActionEvent e )
      {
        replaySessionController.selectSession();
      } // actionPerformed
    });

    add(sessionButton,   new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(sessionField,    new GridBagConstraints(1, 1, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(instructorLabel, new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(instructorField, new GridBagConstraints(1, 2, 3, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    add(dateLabel,       new GridBagConstraints(0, 3, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(dateField,       new GridBagConstraints(1, 3, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(timeLabel,       new GridBagConstraints(0, 4, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(timeField,       new GridBagConstraints(1, 4, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(durationLabel,   new GridBagConstraints(0, 5, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(durationField,   new GridBagConstraints(1, 5, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(courseIdLabel,   new GridBagConstraints(2, 4, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(courseIdField,   new GridBagConstraints(3, 4, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(sessionCodeLabel,new GridBagConstraints(2, 5, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(sessionCodeField,new GridBagConstraints(3, 5, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    //
    // SETUP PANEL
    //

    Dimension preferredSelectionPanelSize = new Dimension(100, 50);

    //
    // SOURCE HUB PANEL
    //

    sourceHubTable.getSelectionModel().addListSelectionListener( new ListSelectionListener()
    {
      @Override
      public void valueChanged( ListSelectionEvent e )
      {
        if (!e.getValueIsAdjusting())
        {
          DBSimSessionHub prevSelection = selectedSourceHub;

          if ( sourceHubTable.getSelectedRowCount() == 0 )
          {
            selectedSourceHub = null;
          } //if
          else
          {
            // sanity check - shouldn't ever be false
            if (sourceHubTableModel.isRowEnabled(sourceHubTableSorter.getModelIndex(sourceHubTable.getSelectedRow())))
            {
              selectedSourceHub = sourceHubTableModel.getDataAtRow(sourceHubTableSorter.getModelIndex(sourceHubTable.getSelectedRow()));
            } // if
            else
            {
              // let's hope this doesn't happen
              throw new IllegalStateException("Resolving of sorted table to backing table has failed."); //$NON-NLS-1$
            } // else
          } // else

          // only do this if it's an update
          if (prevSelection != selectedSourceHub)
          {
            enableDestHubs();
            refreshControlEnabling();
          } // if
        } // if
      } // valueChanged

      private void enableDestHubs()
      {
        for (int i = 0; i < destHubTableModel.getRowCount(); i++)
        {
          if (selectedSourceHub != null)
          {
            DBPhysicalHub hub = destHubTableModel.getDataAtRow(i);

            boolean enabled = false;

            for (DBHubModeTypeAssoc hubModeTypeAssoc : hub.getHubType().getHubModeTypeAssocs())
            {
              enabled = hubModeTypeAssoc.getHubModeId() == selectedSourceHub.getHubModeId();

              if (enabled) break;
            } // for

            destHubTableModel.setRowEnabled(i, enabled);
          } // if
          else
          {
            destHubTableModel.setRowEnabled(i, true);
          } // else
        } // for
      } // enableDestHubs
    });

    JScrollPane sourceHubsScrollPanel = new JScrollPane();
    sourceHubsScrollPanel.getViewport().add(sourceHubTable);
    sourceHubsScrollPanel.setPreferredSize(sourceHubTable.getPreferredScrollableViewportSize());

    JPanel sourceHubsPanel = new JPanel();
    sourceHubsPanel.setLayout(new GridBagLayout());
    sourceHubsPanel.setBorder(new TitledBorder(t("Recorded Simulator Stations"))); //$NON-NLS-1$
    sourceHubsPanel.setPreferredSize(preferredSelectionPanelSize);

    sourceHubsPanel.add(sourceHubsScrollPanel, new GridBagConstraints(0, 0, 2, 1, 1.0, 1.0, GridBagConstraints.WEST, GridBagConstraints.BOTH,     defaultInsets, 0, 0));

    //
    // DESTINATION HUB PANEL
    //

    destHubTable.getSelectionModel().addListSelectionListener( new ListSelectionListener()
    {
      @Override
      public void valueChanged( ListSelectionEvent e )
      {
        if (!e.getValueIsAdjusting())
        {
          DBPhysicalHub prevSelection = selectedDestHub;

          if ( destHubTable.getSelectedRowCount() == 0 )
          {
            selectedDestHub = null;
          } //if
          else
          {
            // sanity check - shouldn't ever be false
            if (destHubTableModel.isRowEnabled(destHubTableSorter.getModelIndex(destHubTable.getSelectedRow())))
            {
              selectedDestHub = destHubTableModel.getDataAtRow(destHubTableSorter.getModelIndex(destHubTable.getSelectedRow()));
            } // if
            else
            {
              // let's hope this doesn't happen
              throw new IllegalStateException("Resolving of sorted table to backing table has failed."); //$NON-NLS-1$
            } // else
          } // else

          // only do this if it's an update
          if (prevSelection != selectedDestHub)
          {
            enableSourceHubs();
            refreshControlEnabling();
          } // if
        } // if
      } // valueChanged

      private void enableSourceHubs()
      {
        for (int i = 0; i < sourceHubTableModel.getRowCount(); i++)
        {
          if (selectedDestHub != null)
          {
            DBSimSessionHub hub = sourceHubTableModel.getDataAtRow(i);

            boolean enabled = false;

            for (DBHubModeTypeAssoc hubModeTypeAssoc : selectedDestHub.getHubType().getHubModeTypeAssocs())
            {
              enabled = hubModeTypeAssoc.getHubModeId() == hub.getHubModeId();

              if (enabled) break;
            } // for

            sourceHubTableModel.setRowEnabled(i, enabled);
          } // if
          else
          {
            sourceHubTableModel.setRowEnabled(i, true);
          } // else
        } // for
      } // enableSourceHubs
    });

    JScrollPane destHubsScrollPanel = new JScrollPane();
    destHubsScrollPanel.getViewport().add(destHubTable);
    destHubsScrollPanel.setPreferredSize(destHubTable.getPreferredScrollableViewportSize());


    JPanel destHubsPanel = new JPanel();
    destHubsPanel.setLayout(new GridBagLayout());
    destHubsPanel.setBorder(new TitledBorder(t("Simulator Stations"))); //$NON-NLS-1$
    destHubsPanel.setPreferredSize(preferredSelectionPanelSize);

    destHubsPanel.add(destHubsScrollPanel, new GridBagConstraints(0, 0, 2, 1, 1.0, 1.0, GridBagConstraints.WEST, GridBagConstraints.BOTH,     defaultInsets, 0, 0));

    clearSelectionButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        sourceHubTable.clearSelection();
        destHubTable.clearSelection();
      } // actionPerformed
    });

    addSimConfigButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        if (selectedDestHub   != null
        &&  selectedSourceHub != null)
        {
          replaySessionController.addHubMapping(selectedSourceHub.getHubId(), selectedDestHub.getPhysicalHubId());

          sourceHubTable.clearSelection();
          destHubTable.clearSelection();
        } // if
        else
        {
          throw new IllegalStateException("The GUI is in an inconsistant state!"); //$NON-NLS-1$
        } // else
      } // actionPerformed
    });

    //
    // PLAYBACK SETUP TABLE
    //

    playbackSetupTableModel  = new PlaybackSetupTable.PlaybackSetupTableModel();
    playbackSetupTableSorter = new TableSorter(playbackSetupTableModel);
    playbackSetupTable       = new PlaybackSetupTable(playbackSetupTableSorter);

    JScrollPane playbackSetupScrollPanel = new JScrollPane();
    playbackSetupScrollPanel.getViewport().add(playbackSetupTable);
    playbackSetupScrollPanel.setPreferredSize(playbackSetupTable.getPreferredScrollableViewportSize());

    playbackSetupTable.getSelectionModel().addListSelectionListener( new ListSelectionListener()
    {
      @Override
      public void valueChanged( ListSelectionEvent e )
      {
        if (!e.getValueIsAdjusting())
        {
          if ( playbackSetupTable.getSelectedRowCount() == 0 )
          {
            selectedPlaybackSetup = null;
          } //if
          else
          {
            selectedPlaybackSetup = playbackSetupTableModel.getDataAtRow(playbackSetupTableSorter.getModelIndex(playbackSetupTable.getSelectedRow()));
          } // else

          refreshControlEnabling();
        } // if
      } // valueChanged
    });

    deletePlaybackSetupButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        replaySessionController.removeHubMappingByDest(selectedPlaybackSetup.getPlaybackHub().getPhysicalHubId());
        selectedPlaybackSetup = null;
      } // actionPerformed
    });

    deleteAllPlaybackSetupButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        replaySessionController.removeAllHubMappings();
        selectedPlaybackSetup = null;
      } // actionPerformed
    });

    restorePlaybackSetupButton.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        replaySessionController.restoreDefaultHubMappings();
        selectedPlaybackSetup = null;
      } // actionPerformed
    });

    //
    // SELECTED SETUPS PANEL
    //

    JPanel playbackSetupPanel = new JPanel();
    playbackSetupPanel.setLayout(new GridBagLayout());
    playbackSetupPanel.setBorder(new TitledBorder(t("Playback Configurations"))); //$NON-NLS-1$

    playbackSetupPanel.add(playbackSetupScrollPanel,      new GridBagConstraints(0, 0, 3, 1, 1.0, 1.0, GridBagConstraints.WEST,   GridBagConstraints.BOTH,     defaultInsets, 0, 0));
    playbackSetupPanel.add(deletePlaybackSetupButton,     new GridBagConstraints(0, 1, 1, 1, 1.0, 0.0, GridBagConstraints.EAST,   GridBagConstraints.NONE,     defaultInsets, 0, 0));
    playbackSetupPanel.add(deleteAllPlaybackSetupButton,  new GridBagConstraints(1, 1, 1, 1, 0.0, 0.0, GridBagConstraints.CENTER, GridBagConstraints.NONE,     defaultInsets, 0, 0));
    playbackSetupPanel.add(restorePlaybackSetupButton,    new GridBagConstraints(2, 1, 1, 1, 1.0, 0.0, GridBagConstraints.WEST,   GridBagConstraints.NONE,     defaultInsets, 0, 0));

    //
    // LAYOUT
    //

    JPanel selectionPanel = new JPanel();
    selectionPanel.setLayout(new BoxLayout(selectionPanel, BoxLayout.X_AXIS));

    selectionPanel.add(sourceHubsPanel);
    selectionPanel.add(Box.createRigidArea(new Dimension(10, 1)));
    selectionPanel.add(destHubsPanel);

    // ensure the panels resize properly
    // there was a problem with the selectionPanel suddenly shrinking when the SCC was increased to larger sizes
    // (over about 1030 pixels tall)
    Dimension size = new Dimension(100, 100);
    selectionPanel.setPreferredSize(size);
    playbackSetupPanel. setPreferredSize(size);

    JPanel setupPanel = new JPanel(new GridBagLayout());
    setupPanel.setBorder(new TitledBorder(t("Replay Setup"))); //$NON-NLS-1$

    setupPanel.add(selectionPanel,       new GridBagConstraints(0, 0, 2, 1, 1.0, 0.6, GridBagConstraints.CENTER, GridBagConstraints.BOTH, defaultInsets, 0, 0));
    setupPanel.add(addSimConfigButton,   new GridBagConstraints(0, 1, 1, 1, 1.0, 0.0, GridBagConstraints.EAST,   GridBagConstraints.NONE, defaultInsets, 0, 0));
    setupPanel.add(clearSelectionButton, new GridBagConstraints(1, 1, 1, 1, 1.0, 0.0, GridBagConstraints.WEST,   GridBagConstraints.NONE, defaultInsets, 0, 0));
    setupPanel.add(playbackSetupPanel,   new GridBagConstraints(0, 2, 2, 1, 1.0, 0.4, GridBagConstraints.CENTER, GridBagConstraints.BOTH, defaultInsets, 0, 0));


    add(setupPanel, new GridBagConstraints(0, 6, 4, 1, 1.0, 1.0, GridBagConstraints.WEST, GridBagConstraints.BOTH, defaultInsets, 0, 0));

    final Dimension MAIN_BUTTON_SIZE = new Dimension(100, 35);

    loadButton = new SizedButton(t("Start Replay"), SessionIcons.REPLAY, MAIN_BUTTON_SIZE); //$NON-NLS-1$
    loadButton.addActionListener( new ActionListener()
    {
      @Override
      public void actionPerformed( ActionEvent e )
      {
        replaySessionController.loadReplay();
      } // actionPerformed
    });

    final JPanel thisPanel = this;

    clearButton = new SizedButton(t("Clear All"), EditingIcons.CLEAR, MAIN_BUTTON_SIZE); //$NON-NLS-1$
    clearButton.addActionListener( new ActionListener()
    {
      @Override
      public void actionPerformed( ActionEvent e )
      {
        if (JOptionPane.showConfirmDialog(thisPanel, t("Are you sure you want to clear all setup data?"),  //$NON-NLS-1$
            t("Confirm Clear All"), JOptionPane.YES_NO_OPTION) //$NON-NLS-1$
            == JOptionPane.YES_OPTION)
        {
          replaySessionController.clear();
        } // if
      } // actionPerformed
    });

    add(messagePanel, new GridBagConstraints(0, 7, 4, 1, 1.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.HORIZONTAL, defaultInsets, 0, 0));
    add(loadButton,   new GridBagConstraints(0, 8, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(clearButton,  new GridBagConstraints(3, 8, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    // Add the tooltips to the controls
    TooltipManager.addToolTipText(sessionButton, t("Select the session to replay")); //$NON-NLS-1$
    TooltipManager.addToolTipText(loadButton,    t("Start a replay using the selected session")); //$NON-NLS-1$
    TooltipManager.addToolTipText(clearButton,   t("Clear all fields on this page")); //$NON-NLS-1$
  } // layoutScreen

  // -----------------------
  // Interface Methods
  // -----------------------

  /**
   * Handles a change to the selected session.
   */
  private IModelListener selectionHandler = new IModelListener()
  {
    @Override
    public void update(Model model, Enum<?> whatChanged)
    {
      DBSimSession selectedSession = replaySessionModel.getSelectedSession();

      if (selectedSession == null)
      {
        sessionField.setText(EMPTY_STRING);
        instructorField.setText(EMPTY_STRING);

        dateField.setText(EMPTY_STRING);
        timeField.setText(EMPTY_STRING);
        durationField.setText(EMPTY_STRING);

        courseIdField.setText(EMPTY_STRING);
        sessionCodeField.setText(EMPTY_STRING);

        loadButton.setEnabled(false);

        populateSourceHubsTable();
        populateDestHubsTable();
      } // if
      else
      {
        sessionField.setText(MessageFormat.format(t("Scenario \"{0}\" recorded on {1}"),  //$NON-NLS-1$
            selectedSession.getScenario().getDescription(),
            DateTimeUtils.getShortDateString(selectedSession.getStartDateUTC())));

        instructorField.setText(DBSimUserFormatter.getDisplayName(selectedSession.getInstructor().getUser()));

        Date startDate = selectedSession.getSimStartDateUTC();
        dateField.setText( DateTimeUtils.getShortDateString( startDate ) );
        timeField.setText( DateTimeUtils.getShortTimeString( startDate ) );

        Date duration = new Date( (long)(selectedSession.getDuration() * 1000.0) );
        durationField.setText( DateTimeUtils.getShortTimeString( duration ) );

        courseIdField.setText( selectedSession.getCourseId() );
        sessionCodeField.setText( selectedSession.getSessionCode() );

        loadButton.setEnabled( isEnabled() );

        populateSourceHubsTable();
        populateDestHubsTable();
      } // else

      flagSelections();
      refreshControlEnabling();
    } // update
  };

  private IModelListener hubMappingHandler = new IModelListener()
  {
    @Override
    public void update(Model model, Enum<?> whatChanged)
    {
      populatePlaybackSetupTable();
      flagSelections();
      refreshControlEnabling();
    } // update
  };

  private void populateSourceHubsTable()
  {
    Collection<DBSimSessionHub> sessionHubs = replaySessionModel.getSelectedSessionHubs();

    if (sessionHubs != null)
    {
      List<DBSimSessionHub> filteredSessionHubs = new ArrayList<>();

      for (DBSimSessionHub sessionHub : sessionHubs)
      {
        if (!replaySessionModel.getInstructorHubIds().contains(sessionHub.getHubId()))
        {
          filteredSessionHubs.add(sessionHub);
        } // if
      } // for

      // FIXME surely we can do this array stuff better?
      sourceHubTableModel.setData(filteredSessionHubs.toArray(new DBSimSessionHub[]{}));
    } // if
    else
    {
      sourceHubTableModel.setData(new DBSimSessionHub[]{});
    } // else
  } // populateHubsTable

  private void populateDestHubsTable()
  {
    List<DBPhysicalHub> suitableHubs = new ArrayList<>();

    if (replaySessionModel.getSelectedSessionHubs() != null)
    {
      Set<Integer> hubModeIds = new TreeSet<>();

      for (DBSimSessionHub sessionHub : replaySessionModel.getSelectedSessionHubs())
      {
        hubModeIds.add(sessionHub.getHubModeId());
      } // for

      DBSimulatorManager simManager = new DBSimulatorManager();
      simManager.load();

      Set<String> supportedSimulators = ConstantsModel.getInstance().getSupportedSimulators();

      for (DBSimulator sim : simManager)
      {
        if (supportedSimulators.contains(sim.getSimulatorName()))
        {
          hubTestLoop:
          for (DBPhysicalHub hub : sim.getPhysicalHubs())
          {
            if (!replaySessionModel.getInstructorHubIds().contains(hub.getPhysicalHubId()))
            {
              for (DBHubModeTypeAssoc hubModeTypeAssoc : hub.getHubType().getHubModeTypeAssocs())
              {
                if (hubModeIds.contains(hubModeTypeAssoc.getHubModeId()))
                {
                  suitableHubs.add(hub);
                  continue hubTestLoop;
                } // if
              } // for
            } // if
          } // for
        } // if
      } // for
    } // if

    // FIXME surely we can do this array stuff better?
    destHubTableModel.setData(suitableHubs.toArray(new DBPhysicalHub[]{}));
  } // populateHubsTable

  private void populatePlaybackSetupTable()
  {
    Map<Integer, Integer> hubMappings = replaySessionModel.getHubMappings();

    PlaybackSetupTable.PlaybackSetupTableModelData[] data = new PlaybackSetupTable.PlaybackSetupTableModelData[hubMappings.size()];
    int index = 0;

    for (int sourceHubId : hubMappings.keySet())
    {
      DBSimSessionHub sourceHub = null;

      for (DBSimSessionHub sessionHub : replaySessionModel.getSelectedSessionHubs())
      {
        if (sessionHub.getHubId() == sourceHubId)
        {
          sourceHub = sessionHub;
          break;
        } // if
      } // for

      // Sanity check; this should never fire
      assert sourceHub != null;

      DBPhysicalHub destHub = new DBPhysicalHub(hubMappings.get(sourceHubId));

      data[index++] = new PlaybackSetupTable.PlaybackSetupTableModelData(sourceHub, destHub);
    } // for

    // Sanity check; this should never fire
    assert index == hubMappings.size();

    playbackSetupTableModel.setData(data);
  } // populateSimSetupTable

  private void flagSelections()
  {
    Collection<Integer> usedSourceHubs = replaySessionModel.getHubMappings().keySet();

    for (int row = 0; row < sourceHubTableModel.getRowCount(); row++)
    {
      sourceHubTableModel.setRowFlagged(row, usedSourceHubs.contains(sourceHubTableModel.getDataAtRow(row).getHubId()));
    } // for

    Collection<Integer> usedDestHubs = replaySessionModel.getHubMappings().values();

    for (int row = 0; row < destHubTableModel.getRowCount(); row++)
    {
      destHubTableModel.setRowFlagged(row, usedDestHubs.contains(destHubTableModel.getDataAtRow(row).getPhysicalHubId()));
    } // for
  } // flagSelections

  private void refreshControlEnabling()
  {
    setEnabled(isEnabled());
  } // refreshControlEnabling

  /**
   * @see javax.swing.JPanel
   */
  @Override
  public void setEnabled( boolean enabled )
  {
    super.setEnabled( enabled );

    sessionButton.setEnabled( enabled );
    sessionField.setEnabled( enabled );

    boolean sessionSelected = replaySessionModel.getSelectedSessionId() != null;
    boolean hubsConfigured = replaySessionModel.getHubMappings().size() > 0;

    sessionField.   setEnabled(enabled && sessionSelected);
    instructorLabel.setEnabled(enabled && sessionSelected);
    instructorField.setEnabled(enabled && sessionSelected);
    dateLabel.setEnabled(enabled && sessionSelected);
    dateField.setEnabled(enabled && sessionSelected);
    timeLabel.setEnabled(enabled && sessionSelected);
    timeField.setEnabled(enabled && sessionSelected);
    durationLabel.setEnabled(enabled && sessionSelected);
    durationField.setEnabled(enabled && sessionSelected);
    courseIdLabel.setEnabled(enabled && sessionSelected);
    courseIdField.setEnabled(enabled && sessionSelected);
    sessionCodeLabel.setEnabled(enabled && sessionSelected);
    sessionCodeField.setEnabled(enabled && sessionSelected);

    sourceHubTable.setEnabled(enabled && sessionSelected);
    destHubTable.setEnabled(enabled && sessionSelected);

    clearSelectionButton.setEnabled( enabled
                                  && ( selectedSourceHub != null
                                    || selectedDestHub   != null));
    addSimConfigButton.setEnabled( enabled
                                && selectedSourceHub != null
                                && selectedDestHub   != null);

    playbackSetupTable.setEnabled(enabled && sessionSelected);
    deletePlaybackSetupButton.setEnabled(enabled && selectedPlaybackSetup != null);
    deleteAllPlaybackSetupButton.setEnabled(enabled && hubsConfigured);
    restorePlaybackSetupButton.setEnabled(enabled && sessionSelected);

    loadButton.setEnabled( enabled && sessionSelected && hubsConfigured
                        && (!sccSimRequired || replaySessionModel.hubMappingsUseSimulator(ConstantsModel.getInstance().getSimulatorType().getId())));
    clearButton.setEnabled( enabled );

    messagePanel.setEnabled(enabled);
    updateHelpMessage();
  } // setEnabled

  private void updateHelpMessage()
  {
    if (replaySessionModel.getSelectedSessionId() == null)
    {
      messagePanel.setMessage(t("Please select a Session.")); //$NON-NLS-1$
    } // else if
    else if (replaySessionModel.getHubMappings().size() == 0)
    {
      if (selectedSourceHub == null)
      {
        messagePanel.setMessage(t("Please select a Recorded Simulator Station.")); //$NON-NLS-1$
      } // else if
      else if (selectedDestHub == null)
      {
        DBPhysicalHub sourceHub = selectedSourceHub.getPhysicalHub();

        messagePanel.setMessage( MessageFormat.format(
                t("Please select a Simulated Station to Replay Trainee {0} {1} on \"{2}\" Simulator''s \"{3}\" Station."), //$NON-NLS-1$
                selectedSourceHub.getDriver().getUser().getFirstName(), selectedSourceHub.getDriver().getUser().getLastName(),
                sourceHub.getSimulator().getSimulatorName(), selectedSourceHub.getPhysicalHub().getPhysicalHubName()));
      } // else if
      else
      {
        messagePanel.setMessage(t("Please add or edit this Simulator Configuration."), IconType.INFO); //$NON-NLS-1$
      } // else if
    } // else if
    // FIXME don't use is flagged to test, use the model
    else if (selectedSourceHub != null && sourceHubTableModel.isRowFlagged(sourceHubTableSorter.getModelIndex(sourceHubTable.getSelectedRow())))
    {
      messagePanel.setMessage(MessageFormat.format(
          t("You have already assigned a Playback Simulator Station for \"{0}\" Simulator''s \"{1}\" Station."), //$NON-NLS-1$
          selectedSourceHub.getPhysicalHub().getSimulator().getSimulatorName(), selectedSourceHub.getPhysicalHub().getPhysicalHubName()), IconType.WARNING);
    } // else if
    else if (selectedDestHub != null && destHubTableModel.isRowFlagged(destHubTableSorter.getModelIndex(destHubTable.getSelectedRow())))
    {
      messagePanel.setMessage(MessageFormat.format(
          t("You have already assigned a Recorded Simulator Station for \"{0}\" Simulator''s \"{1}\" Station."), //$NON-NLS-1$
          selectedDestHub.getSimulator().getSimulatorName(), selectedDestHub.getPhysicalHubName()), IconType.WARNING);
    } // else if
    else if (!replaySessionModel.hubMappingsUseSimulator(ConstantsModel.getInstance().getSimulatorType().getId()))
    {
      if (sccSimRequired)
      {
        messagePanel.setMessage(MessageFormat.format(t("You must use the Simulator \"{0}\" in this session."),  //$NON-NLS-1$
            ConstantsModel.getInstance().getSimulatorType().getName()), IconType.WARNING);
      } // if
      else
      {
        messagePanel.setMessage(MessageFormat.format(
            t("The Simulator \"{0}\" will be used in this session, but has nothing assigned to it."),  //$NON-NLS-1$
            ConstantsModel.getInstance().getSimulatorType().getName()), IconType.WARNING);
      } // else
    } // else if
    else if (isEnabled())
    {
      messagePanel.setMessage(t("Select Start Replay to begin the replay session."), IconType.OK); //$NON-NLS-1$
    } // else if
    else
    {
      messagePanel.removeMessage();
    } // else if
  } // updateHelpMessage

  public class SourceHubTableModel
    extends RowEnablingTableModel<DBSimSessionHub>
  {
    /**
     * Default constructor.
     */
    public SourceHubTableModel()
    {
      super(new String[]{t("Simulator"),  //$NON-NLS-1$
                         t("Station"),  //$NON-NLS-1$
                         t("Type"),  //$NON-NLS-1$
                         t("Trainee Last Name"),  //$NON-NLS-1$
                         t("Trainee First Name")}); //$NON-NLS-1$
    } // SourceHubTableModel


    /**
     * @see javax.swing.table.TableModel
     */
    @Override
    public Object getValueAt(int row, int col)
    {
      String result = null;
      DBSimSessionHub sessionHub = getDataAtRow(row);

      if (col < 3)
      {
        DBPhysicalHub hub = sessionHub.getPhysicalHub();

        switch (col)
        {
        case 0:
          result = hub.getSimulator().getSimulatorName();
          break;
        case 1:
          result = hub.getPhysicalHubName();
          break;
        case 2:
          result = hub.getHubType().getHubTypeName();
          break;
        } // switch
      } // if
      else
      {
        DBSimUser trainee = sessionHub.getDriver().getUser();

        switch (col)
        {
        case 3:
          result = trainee.getLastName();
          break;
        case 4:
          result = trainee.getFirstName();
          break;
        } // switch
      } // else

      return result;
    } // getValueAt

  } // class SourceHubTableModel

  private static class PlaybackSetupTable
    extends SelectedItemsSummaryTable
  {

    public PlaybackSetupTable(TableSorter aTableSorter)
    {
      super(aTableSorter);

      TableColumnModel columnModel = getColumnModel();
      columnModel.getColumn(0).setPreferredWidth(1300);
      columnModel.getColumn(1).setPreferredWidth(1000);
      columnModel.getColumn(2).setPreferredWidth(1000);
      columnModel.getColumn(3).setPreferredWidth(1000);
      columnModel.getColumn(4).setPreferredWidth(1300);
      columnModel.getColumn(5).setPreferredWidth(1000);
    } // SimulatorSetupTable

    static class PlaybackSetupTableModelData
    {
      private DBSimSessionHub recordedHub;
      private DBPhysicalHub playbackHub;

      public PlaybackSetupTableModelData(DBSimSessionHub sourceHub, DBPhysicalHub destHub)
      {
        recordedHub = sourceHub;
        playbackHub = destHub;
      } // PlaybackSetupTableModelData


      public DBSimSessionHub getRecordedHub()
      {
        return recordedHub;
      } // getRecordedHub

      public DBPhysicalHub getPlaybackHub()
      {
        return playbackHub;
      } // getPlaybackHub

    } // PlaybackSetupTableModelData


    static class PlaybackSetupTableModel
      extends GenericTableModel<PlaybackSetupTableModelData>
    {

      /**
       * Default constructor.
       */
      public PlaybackSetupTableModel()
      {
        super(new String[]{t("Recorded Simulator"),  //$NON-NLS-1$
            t("Recorded Station"),  //$NON-NLS-1$
            t("Trainee Last Name"),  //$NON-NLS-1$
            t("Trainee First Name"),  //$NON-NLS-1$
            t("Playback Simulator"),  //$NON-NLS-1$
            t("Playback Station")}); //$NON-NLS-1$
      } // SimulatorSetupTableModel


      /**
       * @see javax.swing.table.TableModel
       */
      @Override
      public Object getValueAt( int row, int col )
      {
        String result = null;
        PlaybackSetupTableModelData config = getDataAtRow(row);

        String ERROR_MSG = t("ERROR!"); //$NON-NLS-1$

        if (col < 4)
        {
          DBSimSessionHub sourceHub = config.getRecordedHub();

          switch(col)
          {
          case 0:
            result = sourceHub.getPhysicalHub().getSimulator().getSimulatorName();
            break;
          case 1:
            result = sourceHub.getPhysicalHub().getPhysicalHubName();
            break;
          case 2:
            result = sourceHub.getDriver().getUser().getLastName();
            break;
          case 3:
            result = sourceHub.getDriver().getUser().getFirstName();
            break;
          default:
            result = ERROR_MSG;
          } // switch
        } // if
        else
        {
          DBPhysicalHub destHub = config.getPlaybackHub();

          switch(col)
          {
          case 4:
            result = destHub.getSimulator().getSimulatorName();
            break;
          case 5:
            result = destHub.getPhysicalHubName();
            break;
          default:
            result = ERROR_MSG;
          } // switch
        } // else

        return result;
      } // getValueAt

    } // class PlaybackSetupTableModel

  } // class PlaybackSetupTable

} // class ReplaySessionHubMappingView

// -- EOF
