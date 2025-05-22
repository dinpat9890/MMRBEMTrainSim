/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.BatterySystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.BatterySystemScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;

public class BatterySystemScreenController extends AbstractTCMSController
{

  @FXML
  private TableView<StatusTableDO> bcgStatusTable;

  @FXML
  private TableView<StatusTableDO> bcgOutputVoltageStatusTable;

  @FXML
  private TableView<StatusTableDO> batteryVoltageStatusTable;

  @FXML
  private TableView<StatusTableDO> outputCurrentStatusTable;

  @FXML
  private TableView<StatusTableDO> totalOutputCurrentStatusTable;

  @FXML
  private TableView<StatusTableDO> batteryCurrentStatusTable;

  @FXML
  private TableView<StatusTableDO> batteryTemperatureStatusTable;

  private BatterySystemScreenModel batterySystemScreenModel;

  private ChangeListener<Number> totalColumnListener;

  @Override
  public void detachListeners()
  {
    batterySystemScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }

  @Override
  public void initializeImpl()
  {
    batterySystemScreenModel = new BatterySystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new BatterySystemScreenBinder(batterySystemScreenModel));

    bcgStatusTable.setItems(batterySystemScreenModel.getBcgStatusTableDataList());
    bcgStatusTable.setVisible(false);

    bcgOutputVoltageStatusTable.setItems(batterySystemScreenModel.getBcgOutputVoltageStatusTableDataList());
    bcgOutputVoltageStatusTable.setVisible(false);

    batteryVoltageStatusTable.setItems(batterySystemScreenModel.getBatteryVoltageStatusTableDataList());
    batteryVoltageStatusTable.setVisible(false);

    outputCurrentStatusTable.setItems(batterySystemScreenModel.getOutputCurrentStatusTableDataList());
    outputCurrentStatusTable.setVisible(false);

    totalOutputCurrentStatusTable
        .setItems(batterySystemScreenModel.getTotalOutputCurrentStatusTableDataList());
    totalOutputCurrentStatusTable.setVisible(false);

    batteryCurrentStatusTable.setItems(batterySystemScreenModel.getBatteryCurrentStatusTableDataList());
    batteryCurrentStatusTable.setVisible(false);

    batteryTemperatureStatusTable
        .setItems(batterySystemScreenModel.getBatteryTemperatureStatusTableDataList());
    batteryTemperatureStatusTable.setVisible(false);

    createTableRenderer(batterySystemScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    batterySystemScreenModel.getTotalColumn().addListener(totalColumnListener);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(bcgStatusTable, noOfCars, TCMSUIConstants.BATTERY_SYSTEM_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE);
      bcgStatusTable.setVisible(true);

      new TableDataRenderer(bcgOutputVoltageStatusTable, noOfCars,
          TCMSUIConstants.BATTERY_SYSTEM_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
      bcgOutputVoltageStatusTable.setVisible(true);

      new TableDataRenderer(batteryVoltageStatusTable, noOfCars,
          TCMSUIConstants.BATTERY_SYSTEM_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
      batteryVoltageStatusTable.setVisible(true);

      new TableDataRenderer(outputCurrentStatusTable, noOfCars,
          TCMSUIConstants.BATTERY_SYSTEM_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
      outputCurrentStatusTable.setVisible(true);

      new TableDataRenderer(totalOutputCurrentStatusTable, noOfCars,
          TCMSUIConstants.BATTERY_SYSTEM_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
      totalOutputCurrentStatusTable.setVisible(true);

      new TableDataRenderer(batteryCurrentStatusTable, noOfCars,
          TCMSUIConstants.BATTERY_SYSTEM_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
      batteryCurrentStatusTable.setVisible(true);

      new TableDataRenderer(batteryTemperatureStatusTable, noOfCars,
          TCMSUIConstants.BATTERY_SYSTEM_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
      batteryTemperatureStatusTable.setVisible(true);
    }
  }
}
