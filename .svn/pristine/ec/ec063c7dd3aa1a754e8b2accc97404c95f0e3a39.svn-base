/* ==================================================================
 *
 *  (C) Copyright 2002 Sydac Pty Ltd., all rights reserved.
 *  This is unpublished proprietary source code of Sydac.
 *  The copyright notice above does not evidence any actual
 *  or intended publication of such source code.
 *
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.replay;

import static com.sydac.simulatorcontroller.i18n.SimulatorControllerI18N.t;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Collection;
import java.util.Date;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

import com.sydac.common.dataobjects.DBSimSession;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.foundation.functional.Pair;
import com.sydac.gui.components.NonEditableTextField;
import com.sydac.gui.components.SizedButton;
import com.sydac.mmrbem.scc.plugin.sessionsetup.replay.ReplaySessionSelectionTablePanel.SessionSelectionListener;
import com.sydac.simulatorcontroller.gui.common.TooltipManager;
import com.sydac.simulatorcontroller.gui.icon.SessionIcons;
import com.sydac.utility.DateTimeUtils;

/**
 * This class is a panel for setting up a replay session to run.
 * <p>
 * Projects may use this panel with the {@link ReplaySessionController} and {@link ReplaySessionModel}
 * classes.
 * <p>
 * This screen gives you a single selection: which session to run. The session
 * will replay as it was recorded (ie on the same Hubs). If the customer needs
 * to send replays to different hubs, or replay only a subset of what was
 * recorded, you probably want the {@link ReplaySessionHubMappingView}.
 *
 * @see ReplaySessionController
 * @see ReplaySessionModel
 * @see ReplaySessionHubMappingView
 */
public final class ReplaySessionView
  extends JPanel
{
  private static final String EMPTY_STRING = ""; //$NON-NLS-1$
  private ReplaySessionController replaySessionController = null;
  private ReplaySessionModel replaySessionModel = null;

  private ReplaySessionSelectionTablePanel savedSessionsTable;

  private JLabel dateLabel = new JLabel(t("Simulated Start Date")); //$NON-NLS-1$
  private NonEditableTextField dateField = new NonEditableTextField();
  private JLabel timeLabel = new JLabel(t("Simulated Start Time")); //$NON-NLS-1$
  private NonEditableTextField timeField = new NonEditableTextField();

  private JLabel durationLabel = new JLabel(t("Session Duration")); //$NON-NLS-1$
  private NonEditableTextField durationField = new NonEditableTextField();

  private JLabel courseIdLabel = new JLabel(t("Course ID")); //$NON-NLS-1$
  private NonEditableTextField courseIdField = new NonEditableTextField();
  private JLabel sessionCodeLabel = new JLabel(t("Session Code")); //$NON-NLS-1$
  private NonEditableTextField sessionCodeField = new NonEditableTextField();

  private JButton loadButton;


  /**
   * Default constructor.
   */
  public ReplaySessionView(ReplaySessionController controller, ReplaySessionModel aModel)
  {
    replaySessionController = controller;

    replaySessionModel = aModel;

    try
    {
      jbInit();
    } // try
    catch ( Exception ex )
    {
      ex.printStackTrace();
    } // catch

    // FIXME: Don't pass partially constructed objects around, see #REVIEW 3061
    replaySessionModel.addModelListener( selectionHandler, ReplaySessionModel.Change.SELECTED_SESSION_CHANGED, true );
  } // ReplaySessionView


  /**
   * JBuilder GUI method.
   *
   * @exception Exception if an exception occurs
   */
  private void jbInit() throws Exception
  {
    setLayout(new GridBagLayout());

    savedSessionsTable = new ReplaySessionSelectionTablePanel();
    savedSessionsTable.addSessionSelectionListener(new SessionSelectionListener()
    {
      @Override
      public void selectionCleared()
      {
        replaySessionController.clearSelectedSession();
      } // sessionDeselected

      @Override
      public void sessionRowSelected(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
      {
        replaySessionController.setSelectedSession(simSession);
      } // sessionRowSelected

      @Override
      public void sessionRowDoubleClicked(Pair<DBSimSession, Collection<DBSimSessionHub>> simSession)
      {
        // Not interested
      } // sessionRowDoubleClicked
    });

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

    /* FIXME Commented out ON PURPOSE.  SEE BUGZILLA #5733
     * Also removed imports, so this will not compile if you just uncomment it!
    // Add in viewpoint selection for each display channel for this sim
    DBDisplayChannelManager dchMgr = new DBDisplayChannelManager();
    dchMgr.load();
    List<DBDisplayChannel> displayChannels = new ArrayList<DBDisplayChannel>(dchMgr);
    Collections.sort(displayChannels, new Comparator<DBDisplayChannel>() {
      public int compare(DBDisplayChannel ch1, DBDisplayChannel ch2)
      {
        return ch1.getDisplayChannelId() - ch2.getDisplayChannelId();
      } // compare
    });

    int simulatorId = ConstantsModel.getInstance().getSimulatorType().getId();
    int xpos = 500;
    for (DBDisplayChannel displayChannel : displayChannels)
    {
      if (displayChannel.getSimulatorId() == simulatorId)
      {
        JPanel rvev = new ReplayVisionEngineController(displayChannel.getDisplayChannelName(), displayChannel.getChannelLocation()).getViewPanel();
        rvev.setBounds(xpos, 270, 400, 270);
        this.add( rvev );
        xpos += 220;
      } // if
    } // for
    */

    Insets defaultInsets = new Insets(5, 5, 5, 5);

    add(savedSessionsTable, new GridBagConstraints(0, 0, 6, 1, 1.0, 1.0, GridBagConstraints.NORTH, GridBagConstraints.BOTH, defaultInsets, 0, 0));

    add(dateLabel, new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(dateField, new GridBagConstraints(1, 1, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(timeLabel, new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(timeField, new GridBagConstraints(1, 2, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    add(courseIdLabel,    new GridBagConstraints(2, 1, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(courseIdField,    new GridBagConstraints(3, 1, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(sessionCodeLabel, new GridBagConstraints(2, 2, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(sessionCodeField, new GridBagConstraints(3, 2, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    add(durationLabel, new GridBagConstraints(4, 1, 1, 1, 0.0, 0.0, GridBagConstraints.EAST, GridBagConstraints.NONE, defaultInsets, 0, 0));
    add(durationField, new GridBagConstraints(5, 1, 1, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    add(loadButton, new GridBagConstraints(0, 3, 6, 1, 0.0, 0.0, GridBagConstraints.WEST, GridBagConstraints.NONE, defaultInsets, 0, 0));

    // Add the tooltips to the controls
    TooltipManager.addToolTipText( loadButton, t("Start a replay using the selected session")); //$NON-NLS-1$
  } // jbInit

  // -----------------------
  // Overridden Methods
  // -----------------------

  /**
   * @see javax.swing.JPanel
   */
  @Override
  public void setEnabled( boolean enabled )
  {
    savedSessionsTable.setEnabled( enabled );

    if ( ( enabled == true ) && ( replaySessionModel.getSelectedSessionHubs() != null ) )
    {
      loadButton.setEnabled( true );
    } // if
    else
    {
      loadButton.setEnabled( false );
    } // else

    super.setEnabled( enabled );
  } // setEnabled

  // -----------------------
  // Model Listeners
  // -----------------------

  /**
   * Handles a change to the selected session.
   */
  private IModelListener selectionHandler = new IModelListener() {
    @Override
    public void update( Model model, Enum<?> whatChanged )
    {
      DBSimSession selectedSession = replaySessionModel.getSelectedSession();

      if ( selectedSession == null )
      {
        dateField.setText( EMPTY_STRING );
        timeField.setText( EMPTY_STRING );

        durationField.setText( EMPTY_STRING );

        courseIdField.setText( EMPTY_STRING );
        sessionCodeField.setText( EMPTY_STRING );

        loadButton.setEnabled( false );
      } // if
      else
      {
        Date startDate = selectedSession.getSimStartDateUTC();
        dateField.setText( DateTimeUtils.getShortDateString( startDate ) );
        timeField.setText( DateTimeUtils.getShortTimeString( startDate ) );

        Date duration = new Date( (long)(selectedSession.getDuration() * 1000.0) );
        durationField.setText( DateTimeUtils.getShortTimeString( duration ) );

        courseIdField.setText( selectedSession.getCourseId() );
        sessionCodeField.setText( selectedSession.getSessionCode() );

        loadButton.setEnabled( isEnabled() );
      } // else
    } // update
  };

  // -----------------------
  // Inner Classes
  // -----------------------

} // class ReplaySessionView

// --EOF
