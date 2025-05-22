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

import java.awt.Dimension;
import java.awt.Window;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.JTableHeader;
import javax.swing.table.TableColumn;
import javax.swing.table.TableColumnModel;

import com.sydac.common.dataobjects.DBTrackNetwork;
import com.sydac.common.dataobjects.timetable.DBLine;
import com.sydac.common.dataobjects.timetable.DBLine.DBLineManagerByTrackNetwork;
import com.sydac.common.dataobjects.timetable.DBRoute;
import com.sydac.common.dataobjects.timetable.DBRoute.DBRouteManager;
import com.sydac.eventscript.gui.IModelListenerHandler;
import com.sydac.foundation.IModelListener;
import com.sydac.foundation.Model;
import com.sydac.gui.container.Windows;
import com.sydac.simulatormanager.gui.model.EditState;
import com.sydac.simulatormanager.plugin.timetable.ui.components.TimeCellEditor;
import com.sydac.simulatormanager.plugin.timetable.ui.components.TimeCellRenderer;
import com.sydac.simulatormanager.plugin.timetable.ui.controller.TimetablePopupController;
import com.sydac.simulatormanager.plugin.timetable.ui.controller.TimetablesTableEditController;
import com.sydac.simulatormanager.plugin.timetable.ui.model.AddStationTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.SelectStationTableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.StationTableData;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetableEditModel;
import com.sydac.simulatormanager.plugin.timetable.ui.model.TimetablesTableRowEditControlModel;
import com.sydac.simulatormanager.scenariobuilder.gui.TableRowEditDialog;
import com.sydac.simulatormanager.scenariobuilder.model.manager.ScenarioManager;
import com.sydac.simulatormanager.scenariobuilder.model.valueobjects.ScenarioModel;

import net.miginfocom.swing.MigLayout;

/**
 * TrackTimeTableListTableRowEditDialog - this class gives dialog when user add
 * or edit Time Table entry
 * 
 * @author patanges
 *
 */
@SuppressWarnings("nls")
public class TimetableEditDialog extends TableRowEditDialog implements IModelListenerHandler
{
  private JComboBox<String> selectLineBox;

  private AddStationTableEditModel addStationTableDataModel;

  private SelectStationTableEditModel selectStationTableDataModel;

  private JTable addStationTable;

  private JTable selectstationTable;

  private TimetablePopupController popupController;

  private JButton addBtn;

  private JButton removeBtn;

  private TimetableEditModel timeTableEditModel;

  private JTextField timeTableNameTxt;

  private JButton addAllBtn;
  
  private ArrayList<Integer> linesAvalaible;
  private HashMap<String, Integer> lineNameMap;
  
  private  Map<String,Integer> lineRouteNameMap ;

  private ItemListener itemListener = (ItemEvent itemEvent) ->
  {
    if (itemEvent.getStateChange() == ItemEvent.SELECTED)
    {
      timeTableEditModel.setLineName((String)itemEvent.getItem());
     
      selectStationTableDataModel.loadSelectStationTableDatasfromDB((String)itemEvent.getItem());
      if (selectStationTableDataModel.getSelectStationTableDatas().isEmpty())
      {
        addAllBtn.setEnabled(false);
      }
      else
      {
        addAllBtn.setEnabled(true);
      }
    }
  };

  FocusAdapter focusAdapter = new FocusAdapter()
  {
    @Override
    public void focusLost(FocusEvent focusEvent)
    {
      if (focusEvent.getSource() == timeTableNameTxt)
      {
        timeTableEditModel.setTimeTableName(timeTableNameTxt.getText());
      }

    }
  };

  private IModelListener stationDataChangeListener = (Model model, Enum<?> whatChanged) ->
  {
    List<StationTableData> stationTableDatas = this.timeTableEditModel.getStationTableData();
    if (whatChanged == TimetableEditModel.Change.STATION_DATA_CHANGE)
    {
      addStationTableDataModel.setAddStationTableDatas(stationTableDatas);
      updateReceived();
    }
  };

  public TimetableEditDialog(Window parent, SelectStationTableEditModel stationTableDataModel, TimetableEditModel timeTableEditModel, TimetablesTableEditController aController,
      TimetablesTableRowEditControlModel editModel)
  {
    super(parent, aController, editModel, "Scenario Timetable");
    addStationTableDataModel = new AddStationTableEditModel(new ArrayList<>());
    selectStationTableDataModel = stationTableDataModel;
    this.timeTableEditModel = timeTableEditModel;
    popupController = TimetablePopupController.getInstance();
    popupController.setAddStationTableDataModel(addStationTableDataModel);
    popupController.setSelectStationTableDataModel(selectStationTableDataModel);
    layOutDialog();
    setSize(new Dimension(1200, 800));
    setLocationRelativeTo(parent);
    Windows.setFocusEmphasisGlassPane(this);
    linesAvalaible = new ArrayList<>();
    lineNameMap = new HashMap<>();
    lineRouteNameMap = new HashMap<>();
  }

  private void layOutDialog()
  {
    setLayout(new MigLayout("insets 0 0 0 0", "[]", "[][]"));
    add(createTimeTablePopupDialogPanel(), "wrap,width 100%,height 90%");
    add(createSaveCancelPanel(), "width 100%,height 10%");
  }

  public void updateLineNameCombo()
  {
    ScenarioManager scenarioManager = ScenarioManager.getInstance();
    ScenarioModel scenarioModel = scenarioManager.getCurrentScenarioModel();
    DBTrackNetwork trackNw = scenarioModel.getTrackNetwork();
    DBLineManagerByTrackNetwork dbLines = new DBLineManagerByTrackNetwork(trackNw);
    dbLines.load();
    for (DBLine line : dbLines)
    {
      if (linesAvalaible != null)
      {
        linesAvalaible.add(line.getValue(DBLine.LINE_LINE_ID));
      }

    }

    DBRouteManager routeMang = new DBRouteManager();
    routeMang.load();

    for (DBRoute dbRoute : routeMang)
    {
      if (linesAvalaible.contains(dbRoute.getValue(DBRoute.LINE_LINE_ID)))
      {
    
        lineNameMap.put(dbRoute.getValue(DBRoute.ROUT_NAME), dbRoute.getValue(DBRoute.LINE_LINE_ID));
        
        lineRouteNameMap.put(dbRoute.getValue(DBRoute.ROUT_NAME), dbRoute.getValue(DBRoute.ROUT_ROUTE_ID));
       
        selectStationTableDataModel.seRouteLineData(lineNameMap);
        selectStationTableDataModel.setLineRouteMapData(lineRouteNameMap);
        selectLineBox.addItem(dbRoute.getValue(DBRoute.ROUT_NAME));

      }
    }

    
  }

  public void updateSelectLine(String linename)
  {
    selectLineBox.setSelectedItem(linename);
    selectStationTableDataModel.loadSelectStationTableDatasfromDB(linename);
    if (selectStationTableDataModel.getSelectStationTableDatas().isEmpty())
    {
      addAllBtn.setEnabled(false);
    }
    else
    {
      addAllBtn.setEnabled(true);
    }
  }

  public void setTableName(String tableName)
  {
    timeTableNameTxt.setText(tableName);
  }

  private JPanel createTimeTablePopupDialogPanel()
  {
    JPanel mainPanel = new JPanel();
    mainPanel.setLayout(new MigLayout("", "[][]", "[]"));

    JPanel selectStationPanel = new JPanel();
    selectStationPanel.setBorder(new TitledBorder(""));
    selectStationPanel.setLayout(new MigLayout("", "[][][]", "4%[]6%[]"));

    JLabel selectLineLbl = new JLabel("Select Line");
    selectLineBox = new JComboBox<>();
    selectstationTable = new JTable(selectStationTableDataModel);
    selectstationTable.setVisible(true);
    selectstationTable.setAutoCreateRowSorter(true);
    selectstationTable.setTableHeader(new JTableHeader(selectstationTable.getColumnModel())
    {
      @Override
      public Dimension getPreferredSize()
      {
        Dimension d = super.getPreferredSize();
        d.height = 32;
        return d;
      }
    });
    selectstationTable.addMouseListener(new java.awt.event.MouseAdapter()
    {
      @Override
      public void mouseReleased(MouseEvent e)
      {
        selectStationTableMouseReleased();
      }

      @Override
      public void mouseClicked(MouseEvent e)
      {
        selectStationTableMouseClicked(e);
      }
    });
    JScrollPane selectstationTableScrollPane = new JScrollPane(selectstationTable);
    TableColumnModel columnModel = selectstationTable.getColumnModel();
    columnModel.getColumn(0).setPreferredWidth(1000);
    columnModel.getColumn(1).setPreferredWidth(2000);
    TableColumn col = selectstationTable.getColumnModel().getColumn(0);
    DefaultTableCellRenderer dtcr = new DefaultTableCellRenderer();
    dtcr.setHorizontalAlignment(SwingConstants.LEFT);
    col.setCellRenderer(dtcr);

    JPanel buttonPanel = new JPanel(new MigLayout("", "[]", "34%[][][][][]38%"));
    addBtn = new JButton("Add >");
    addBtn.setEnabled(false);
    addBtn.addActionListener(e -> addButtonActionPerformed());

    addAllBtn = new JButton("Add All >>");
    addAllBtn.addActionListener(e -> addAllButtonActionPerformed());

    JPanel addStationPanel = new JPanel();
    addStationPanel.setBorder(new TitledBorder(""));
    addStationPanel.setLayout(new MigLayout("", "[][]", "4%[]6%[]"));
    JLabel timeTableNameLbl = new JLabel("Timetable name");
    timeTableNameTxt = new JTextField();
    addStationTable = new JTable();
    addStationTable.setModel(addStationTableDataModel);
    addStationTable.setTableHeader(new JTableHeader(addStationTable.getColumnModel())
    {
      @Override
      public Dimension getPreferredSize()
      {
        addStationTable.getColumnModel().getColumn(4).setMinWidth(0);
        addStationTable.getColumnModel().getColumn(4).setMaxWidth(0);
        addStationTable.getColumnModel().getColumn(4).setWidth(0);
        Dimension d = super.getPreferredSize();
        d.height = 32;
        return d;
      }
    });
    addStationTable.addMouseListener(new java.awt.event.MouseAdapter()
    {
      @Override
      public void mouseReleased(MouseEvent e)
      {
        addStationTableMouseReleased();
      }
    });
    addStationTable.setRowHeight(30);
    TableColumnModel addStationTableColumnModel = addStationTable.getColumnModel();
    addStationTableColumnModel.getColumn(0).setPreferredWidth(400);
    addStationTableColumnModel.getColumn(1).setPreferredWidth(1000);
    TableColumn arrivalTimeColumn = addStationTableColumnModel.getColumn(2);
    TableColumn departureTimeColumn = addStationTable.getColumnModel().getColumn(3);
    arrivalTimeColumn.setPreferredWidth(1500);
    departureTimeColumn.setPreferredWidth(1500);
    addStationTable.doLayout();

    arrivalTimeColumn.setCellRenderer(new TimeCellRenderer());
    arrivalTimeColumn.setCellEditor(new TimeCellEditor());

    departureTimeColumn.setCellRenderer(new TimeCellRenderer());
    departureTimeColumn.setCellEditor(new TimeCellEditor());

    JScrollPane addStationTableScrollPane = new JScrollPane(addStationTable);

    removeBtn = new JButton("Remove");
    removeBtn.setEnabled(false);
    removeBtn.addActionListener(e -> removeButtonActionPerformed());

    selectStationPanel.add(selectLineLbl, "cell 0 0,width 20%,height 5%");
    selectStationPanel.add(selectLineBox, "cell 1 0,width 60%,height 5%");
    selectStationPanel.add(selectstationTableScrollPane, "cell 0 1 2 1,width 80%,height 84%");
    buttonPanel.add(addBtn, "cell 0 0,width 100%,height 5.5%");
    buttonPanel.add(addAllBtn, "cell 0 1,width 100%,height 5.5%");
    selectStationPanel.add(buttonPanel, "cell 2 1,width 20%,height 80%");
    mainPanel.add(selectStationPanel, "width 35%,height 100%");

    JPanel namePanel = new JPanel();
    namePanel.setLayout(new MigLayout("", "[][]", "4%[]6%[]"));
    namePanel.add(timeTableNameLbl, "cell 0 0,width 20%,height 100%");
    namePanel.add(timeTableNameTxt, "cell 1 0,width 70%,height 100%");
    addStationPanel.add(namePanel, "cell 0 0,width 90%, height 6%");
    addStationPanel.add(addStationTableScrollPane, "cell 0 1,width 90%,height 84%");
    addStationPanel.add(removeBtn, "cell 2 0 1 2,width 10%,height 4.5%");
    mainPanel.add(addStationPanel, "width 65%,height 100%");
    return mainPanel;
  }

  protected void addStationTableMouseReleased()
  {
    removeBtn.setEnabled(addStationTable.getSelectedRowCount() > 0);
  }

  protected void selectStationTableMouseClicked(MouseEvent e)
  {
    if (e.getClickCount() >= 2 && selectstationTable.getRowCount() > 0 && selectstationTable.getSelectedRow() >= 0)
    {
      setSelectStationControlsEnabled(true);
      int row = selectstationTable.getSelectedRow();
      popupController.addStationAt(row);
    }

  }

  protected void selectStationTableMouseReleased()
  {
    if (selectstationTable.getSelectedRowCount() > 0)
    {
      setSelectStationControlsEnabled(true);
    }
    else
    {
      setSelectStationControlsEnabled(false);
    }
  }

  private void setSelectStationControlsEnabled(boolean flag)
  {
    addBtn.setEnabled(flag);
  }

  @Override
  public void attachListeners()
  {
    timeTableNameTxt.addFocusListener(focusAdapter);
    selectLineBox.addItemListener(itemListener);
    timeTableEditModel.addModelListener(stationDataChangeListener, TimetableEditModel.Change.STATION_DATA_CHANGE, true);
  }

  @Override
  public void detachListeners()
  {
    timeTableNameTxt.removeFocusListener(focusAdapter);
    timeTableEditModel.removeModelListener(stationDataChangeListener, TimetableEditModel.Change.STATION_DATA_CHANGE);
    selectLineBox.removeItemListener(itemListener);
  }

  private void updateReceived()
  {
    getTableRowEditControlModel().setEditState(EditState.MODIFIED);
  }

  @Override
  protected boolean validateEntry()
  {
    boolean validated = true;
    return validated;
  }

  private void addButtonActionPerformed()
  {
    int row = selectstationTable.getSelectedRow();
    popupController.addStationAt(row);
    timeTableEditModel.setStationTableData(addStationTableDataModel.getAddStationTableDatas());
  }

  private void removeButtonActionPerformed()
  {
    int row = addStationTable.getSelectedRow();
    popupController.removeStationAt(row);
    timeTableEditModel.setStationTableData(addStationTableDataModel.getAddStationTableDatas());
  }

  private void addAllButtonActionPerformed()
  {
    popupController.addAllStation();
    timeTableEditModel.setStationTableData(addStationTableDataModel.getAddStationTableDatas());
  }

}
