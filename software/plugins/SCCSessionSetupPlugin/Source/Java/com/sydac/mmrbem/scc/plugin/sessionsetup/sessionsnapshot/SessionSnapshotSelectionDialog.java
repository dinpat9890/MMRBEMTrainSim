/*
 * ==================================================================
 * 
 * (C) Copyright 2015 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.scc.plugin.sessionsetup.sessionsnapshot;

import static com.sydac.contentutils.i18n.ContentUtilsI18N.t;

import java.awt.Container;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Collection;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JEditorPane;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.table.AbstractTableModel;

import net.miginfocom.layout.AC;
import net.miginfocom.layout.CC;
import net.miginfocom.layout.LC;
import net.miginfocom.swing.MigLayout;

import com.sydac.common.dataobjects.DBScenario;
import com.sydac.common.dataobjects.DBSessionSnapshot;
import com.sydac.common.dataobjects.DBSimSessionHub;
import com.sydac.contentutils.session.gui.formatter.DBSimSessionFormatter;
import com.sydac.contentutils.session.gui.select.DBSessionSnapshotSelectionDialog.IDBSnapshotCache;
import com.sydac.gui.components.Buttons;
import com.sydac.gui.components.table.SortedTable;
import com.sydac.gui.components.table.TableSorter;
import com.sydac.gui.components.table.Tables;
import com.sydac.gui.container.Windows;
import com.sydac.gui.font.FontUtils;
import com.sydac.gui.font.FontUtils.UIFontType;
import com.sydac.utility.DateTimeUtils;

/**
 * This class allows the user to select a snapshot from a dialog box.
 * <p>
 * Based on code which was based on legacy code in the SCC :(
 * <p>
 * Note that passing around {@link DBSessionSnapshot} is less than ideal, as
 * they are not document classes. Once the document classes are fleshed out, a
 * new version of this dialog will be made to handle documents (I hope).
 */
public final class SessionSnapshotSelectionDialog extends JDialog
{
  /** The custom table model for the JTable */
  private SnapshotTableModel tableModel = new SnapshotTableModel();

  private TableSorter tableSorter = new TableSorter(tableModel);

  private JPanel dialogPanel = new JPanel();

  private SortedTable snapshotTable;

  private JScrollPane scrollPane = new JScrollPane();

  private final CofmowIDBSnapshotCache snapshots;

  /** The snapshot selected from the list of available snapshots. */
  private DBSessionSnapshot highlightedSnapshot;

  /**
   * The selection to return. This will be {@link #highlightedSnapshot} if the
   * user presses Ok.
   */
  private DBSessionSnapshot selection;

  private JEditorPane selectedSessionDetails = new JEditorPane();

  private JButton okButton = Buttons.createOkButton();

  private JButton cancelButton = Buttons.createCancelButton();

  private JCheckBox runWithoutSnapshotCheckBox = new JCheckBox(t("Run without a Snapshot"), false); //$NON-NLS-1$

  /**
   * Creates a dialog for snapshot selection.
   *
   * @param aParent
   *          The parent window.
   * @param aSnapshotCache
   *          A cache from which to fetch snapshots.
   */
  public SessionSnapshotSelectionDialog(Window aParent, CofmowIDBSnapshotCache aSnapshotCache)
  {
    super(aParent, t("Select Snapshot"), ModalityType.APPLICATION_MODAL); //$NON-NLS-1$

    snapshots = aSnapshotCache;

    Container contentPane = this.getContentPane();

    snapshotTable = new SortedTable(tableSorter);

    Tables.setSingleRowSelection(snapshotTable);
    Tables.addDoubleClickCallback(snapshotTable, this::okButtonPressed);
    Tables.addRowSelectionCallback(snapshotTable, this::updateSelectedSnapshotDetails);
    Tables.setPreferredColumnWidths(snapshotTable, 225, 225, 150, 200);

    snapshotTable.getTableHeader().setReorderingAllowed(true);

    scrollPane.getViewport().add(snapshotTable);

    selectedSessionDetails.setEditable(false);
    selectedSessionDetails.setContentType("text/html"); //$NON-NLS-1$
    selectedSessionDetails.putClientProperty(JEditorPane.HONOR_DISPLAY_PROPERTIES, Boolean.TRUE);
    selectedSessionDetails.setFont(FontUtils.findUIFont(UIFontType.TEXT_AREA));

    updateSelectedSnapshotDetails();
    JScrollPane detailsScroller = new JScrollPane(selectedSessionDetails, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);

    okButton.setEnabled(false);
    okButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        okButtonPressed();
      }
    });

    cancelButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        cancelButtonPressed();
      }
    });

    runWithoutSnapshotCheckBox.addActionListener((ActionEvent e) -> {
      if (runWithoutSnapshotCheckBox.isSelected())
      {
        highlightedSnapshot = null;
        snapshotTable.getSelectionModel().clearSelection();
        okButton.setEnabled(true);
      }else{
        if(snapshotTable.getSelectedRowCount() == 0){
          okButton.setEnabled(false);
        }
      }
    });

    // defined here to make layout code neater
    JLabel snapshots = new JLabel(t("Available Snapshots")); //$NON-NLS-1$
    JLabel details = new JLabel(t("Session Details")); //$NON-NLS-1$
    JSeparator vertBar = new JSeparator(JSeparator.VERTICAL);
    JSeparator horizBar = new JSeparator(JSeparator.HORIZONTAL);

    JPanel runWithoutSnapshotPanel = new JPanel(new MigLayout(new LC().insets("0"))); //$NON-NLS-1$
    runWithoutSnapshotPanel.add(runWithoutSnapshotCheckBox);

    // Do the layout
    JPanel okCancelPanel = new JPanel(new MigLayout(new LC().insets("0"))); //$NON-NLS-1$    
    okCancelPanel.add(okButton);
    okCancelPanel.add(cancelButton);

    dialogPanel.setLayout(new MigLayout(new LC().insets("10") //$NON-NLS-1$
        .gridGap("10", "10"), //$NON-NLS-1$ //$NON-NLS-2$
        new AC().grow(100, 1, 3, 4).grow(0, 0, 2), new AC().grow(100, 1).grow(0, 0, 2, 3, 4, 5)));

    dialogPanel.add(snapshots, new CC().cell(0, 0));
    dialogPanel.add(scrollPane, new CC().cell(0, 1, 2, 1).width(":600:").grow()); //$NON-NLS-1$
    dialogPanel.add(vertBar, new CC().cell(2, 0, 1, 3).growY());
    dialogPanel.add(details, new CC().cell(3, 0));
    dialogPanel.add(detailsScroller, new CC().cell(3, 1, 2, 1).width(":300:").grow()); //$NON-NLS-1$
    dialogPanel.add(horizBar, new CC().cell(0, 3, 5, 1).growX());
    dialogPanel.add(runWithoutSnapshotPanel, new CC().cell(0, 4, 3, 1).alignX("left")); //$NON-NLS-1$
    dialogPanel.add(okCancelPanel, new CC().cell(4, 4, 3, 1).alignX("right")); //$NON-NLS-1$

    contentPane.add(dialogPanel);

    applyComponentOrientation(aParent.getComponentOrientation());
    Windows.setFocusEmphasisGlassPane(this);
    pack();
  }

  private void updateSelectedSnapshotDetails()
  {
    boolean selected = snapshotTable.getSelectedRowCount() > 0;

    okButton.setEnabled(selected);
    runWithoutSnapshotCheckBox.setSelected(!selected);

    highlightedSnapshot = tableModel.getDataAtRow(tableSorter.getModelIndex(snapshotTable.getSelectedRow()));

    if (highlightedSnapshot == null)
    {
      selectedSessionDetails.setText(t("Please Select a Snapshot.")); //$NON-NLS-1$
    }
    else
    {
      selectedSessionDetails.setText(new DBSimSessionFormatter(snapshots.getSession(highlightedSnapshot), snapshots.getScenario(highlightedSnapshot)).getHTMLSummary());
      // make sure we're at the top of the scroll pane (not doing this will have
      // it auto scroll to the bottom)
      selectedSessionDetails.setCaretPosition(0);
    }
  }

  /**
   * Called when the cancel button is pressed.
   */
  private void cancelButtonPressed()
  {
    selection = highlightedSnapshot;
    dispose();
  }

  /**
   * Called when the Ok button is pressed.
   */
  private void okButtonPressed()
  {
    selection = highlightedSnapshot;
    dispose();
  }

  /**
   * Returns the selected snapshot if Ok was pressed, or null if Cancel was
   * pressed.
   */
  public DBSessionSnapshot getSelectedSnapshot()
  {
    return selection;
  }
  /**
   * Sets selected snapshot
   * @param snapshot
   */
  public void setSelectedSnapshot(DBSessionSnapshot snapshot)
  {
    highlightedSnapshot = snapshot;    
  }

  @Override
  public void setVisible(boolean visible)
  {
    if (visible)
    {
      setLocationRelativeTo(getParent());
      // Clears the selection whenever this becomes visible.
      selection = null;
      runWithoutSnapshotCheckBox.setSelected(false);
      okButton.setEnabled(false);
    }
    super.setVisible(visible);
  }

  /**
   * Updates the displayed data, depending on the selected filter.
   */
  public void updateData(DBScenario scenario)
  {
    Collection<DBSessionSnapshot> data = snapshots.getSnapshots(scenario);
    tableModel.setData(data.toArray(new DBSessionSnapshot[data.size()]));
  }

  /**
   * This class is a table model for the snapshot information displayed in the
   * dialog.
   */
  private class SnapshotTableModel extends AbstractTableModel
  {

    private String[] columnNames = { t("Driver"), //$NON-NLS-1$
        t("Instructor"), t("Session Start Time"), //$NON-NLS-1$ //$NON-NLS-2$
        t("Snapshot Point") }; //$NON-NLS-1$

    /** The data to display */
    private DBSessionSnapshot[] data;

    public SnapshotTableModel()
    {
      // No operation
    }

    public void setData(DBSessionSnapshot[] aSnapshots)
    {
      data = aSnapshots;

      fireTableDataChanged();
    }

    public DBSessionSnapshot getDataAtRow(int aRow)
    {
      DBSessionSnapshot result = null;

      if (data != null)
      {
        if ((aRow >= 0) && (aRow < data.length))
        {
          result = data[aRow];
        }
      }

      return result;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public int getColumnCount()
    {
      return columnNames.length;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public int getRowCount()
    {
      int result = 0;

      if (data != null)
      {
        result = data.length;
      }

      return result;
    }

    @Override
    public String getColumnName(int col)
    {
      return columnNames[col];
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Object getValueAt(int row, int col)
    {
      String result = null;

      if (data != null)
      {
        DBSessionSnapshot snapshot = data[row];

        switch (col)
        {
        case 0:
          result = snapshots.getSessionHub(snapshot).getDriver().getUser().getDisplayString();
          break;
        case 1:
          result = snapshots.getSessionHub(snapshot).getInstructor().getUser().getDisplayString();
          break;
        case 2:
          result = DateTimeUtils.getShortDateShortTimeString(snapshots.getSession(snapshot).getStartDateUTC());
          break;
        case 3:
          result = DateTimeUtils.getElapsedTimeDescription(snapshot.getValue(DBSessionSnapshot.SESN_ELAPSED_TIME).longValue());
          break;
        }
      }

      return result;
    }
  }

  /**
   * This interface assumes that implementing classes are smart enough to figure
   * out when they need to update their data. If a call to {@code refresh()} or
   * similar is required, it must be done before
   * {@link SessionSnapshotSelectionDialog#setVisible(boolean)} is called.
   */
  public interface CofmowIDBSnapshotCache extends IDBSnapshotCache
  {
    /**
     * Returns a list sessions snapshots associated with a scenario.
     * 
     * @param scenario
     *          An instance of {@link DBScenario}
     * @return List of session snapshots associated with this
     *         <code>scenario</code>
     */
    Collection<DBSessionSnapshot> getSnapshots(DBScenario scenario);

    /**
     * 
     * The session associated with the given snapshot.
     *
     * @param snapshot
     *          An instance of {@link DBSessionSnapshot}
     * @return Session details associated with this <code>snapshot</code>
     */
    public DBSimSessionHub getSessionHub(DBSessionSnapshot snapshot);

  }

  
}
