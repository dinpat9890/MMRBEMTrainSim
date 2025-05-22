/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.BatterySystemTestScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.TestScreenTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TextTableTextCellFactory;
import com.sydac.mmrbem.tcms.fe.gui.model.TestSystemScreenModel;

import javafx.application.Platform;
import javafx.beans.property.ListProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.fxml.FXML;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.Pane;

public class BatterySystemTestScreenController extends AbstractTCMSController
{

  @FXML
  private Button batteryTestUpButton;

  @FXML
  private Button batteryTestDownButtoon;

  @FXML
  private Button batteryTestStartButton;

  @FXML
  private Label batteryTestScreenLabel;

  @FXML
  private TableView<TestScreenTableDO> batteryTestScreenTable;

  private TestSystemScreenModel testSystemScreenModel;

  private ChangeListener<Number> currentPageListener;

  private ChangeListener<Number> totalPagesListener;

  private static final double CELL_HEIGHT = 52;

  private static final double CAR_WIDTH = 170;

  private static final double COMPONENT_WIDTH = 170;

  private static final double TEST_STATUS_WIDTH = 170;

  private static final double LAST_UPDATE_WIDTH = 514;

  @Override
  public void initializeImpl()
  {
    testSystemScreenModel = new TestSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new BatterySystemTestScreenBinder(testSystemScreenModel));

    currentPageListener = (observable, oldVal, newVal) -> updateBatterySystemTestScreenTable();
    testSystemScreenModel.getCurrentPageNumber().addListener(currentPageListener);

    totalPagesListener = (observable, oldVal, newVal) -> updateBatterySystemTestScreenTable();
    testSystemScreenModel.getTotalPageNumber().addListener(totalPagesListener);

    updateBatterySystemTestScreenTable();

    setTableProperties(testSystemScreenModel.getActiveTestStatusList());

  }

  @Override
  public void detachListeners()
  {

  }

  private void setTableProperties(ListProperty<TestScreenTableDO> eventList)
  {

    batteryTestScreenTable.setFixedCellSize(CELL_HEIGHT * 1.0);

    batteryTestScreenTable.getSelectionModel().setCellSelectionEnabled(false);
    batteryTestScreenTable.getSelectionModel().clearAndSelect(0);
    batteryTestScreenTable.setPadding(new Insets(0, 0, 0, 0));

    batteryTestScreenTable.widthProperty().addListener((source, oldWidth, newWidth) -> {
      Pane header = (Pane)batteryTestScreenTable.lookup("TableHeaderRow"); //$NON-NLS-1$
      if (header.isVisible())
      {
        header.setMaxHeight(64);
        header.setMinHeight(64);
        header.setPrefHeight(52);
        header.setVisible(true);
      }
    });

    batteryTestScreenTable.getColumns().add(getColumn("carCode", COMPONENT_WIDTH * 1.0, "CAR")); //$NON-NLS-1$ //$NON-NLS-2$
    batteryTestScreenTable.getColumns().add(getColumn("componentName", TEST_STATUS_WIDTH * 1.0, "COMPONENT")); //$NON-NLS-1$ //$NON-NLS-2$
    batteryTestScreenTable.getColumns().add(getColumn("testStatus", LAST_UPDATE_WIDTH * 1.0, "TEST STATUS")); //$NON-NLS-1$ //$NON-NLS-2$
    batteryTestScreenTable.getColumns()
        .add(getColumn("lastUpdateDate", LAST_UPDATE_WIDTH * 1.0, "LAST UPDATE")); //$NON-NLS-1$ //$NON-NLS-2$

    batteryTestScreenTable.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY);

    batteryTestScreenTable.setItems(eventList);

    batteryTestScreenTable.getSelectionModel().selectedIndexProperty()
        .addListener(new RowChangeHandler(batteryTestScreenTable, eventList));

  }

  private class RowChangeHandler implements ChangeListener<Object>
  {
    private ListProperty<TestScreenTableDO> eventList;

    private TableView<TestScreenTableDO> currentEventTable;

    public RowChangeHandler(TableView<TestScreenTableDO> eventTable,
        ListProperty<TestScreenTableDO> eventList)
    {
      this.currentEventTable = eventTable;
      this.eventList = eventList;
    }

    @Override
    public void changed(ObservableValue<?> ov, Object oldVal, Object newVal)
    {

      int selectedRow = currentEventTable.getSelectionModel().getSelectedIndex();

      if (selectedRow == -1)
      {
        return;
      }

      Platform.runLater(() -> {

        currentEventTable.requestFocus();
        currentEventTable.getSelectionModel().select(selectedRow);
        currentEventTable.getFocusModel().focus(selectedRow);

      });

    }

  }

  private void updateBatterySystemTestScreenTable()
  {
    batteryTestScreenLabel
    .setText("Showing page " + TCMSUIConstants.CURRENT_PAGE + " of " //$NON-NLS-1$ //$NON-NLS-2$
        + TCMSUIConstants.TOTAL_PAGE); /// $NON-NLS-1$
  }

  private TableColumn<TestScreenTableDO, Object> getColumn(String columnName, double width, String headerName)
  {
    TableColumn<TestScreenTableDO, Object> column = new TableColumn<>((headerName)); // $NON-NLS-1$
    column.setCellValueFactory(new PropertyValueFactory<>(columnName)); // $NON-NLS-1$
    column.setCellFactory(
        tableColumn -> new TextTableTextCellFactory<TestScreenTableDO, Object>(columnName, true));
    column.setPrefWidth(width);
    column.setMinWidth(width);
    column.setMaxWidth(width);
    column.setSortable(false);
    column.setResizable(false);
    return column;

  }

}
