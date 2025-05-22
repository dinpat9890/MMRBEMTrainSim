/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.PropulsionSystemTemperaturesScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.PropulsionSystemTemperaturesScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;

public class PropulsionSystemTemperaturesScreenController extends AbstractTCMSController
{

  @FXML
  private TableView<StatusTableDO> tempMotor1Table;

  @FXML
  private TableView<StatusTableDO> tempMotor2Table;

  @FXML
  private TableView<StatusTableDO> tempMotor3Table;

  @FXML
  private TableView<StatusTableDO> tempMotor4Table;

  @FXML
  private TableView<StatusTableDO> mainTransformferTempTable;

  private PropulsionSystemTemperaturesScreenModel propulsionSystemTemperaturesScreenModel;

  private ChangeListener<Number> totalColumnListener;

  @Override
  public void initializeImpl()
  {
    propulsionSystemTemperaturesScreenModel = new PropulsionSystemTemperaturesScreenModel(scenarioCarIndex);
    tcmsScreenBinders
        .add(new PropulsionSystemTemperaturesScreenBinder(propulsionSystemTemperaturesScreenModel));

    tempMotor1Table.setItems(propulsionSystemTemperaturesScreenModel.getMotor1TempTableDataList());
    tempMotor1Table.setVisible(false);

    tempMotor2Table.setItems(propulsionSystemTemperaturesScreenModel.getMotor2TempTableDataList());
    tempMotor2Table.setVisible(false);

    tempMotor3Table.setItems(propulsionSystemTemperaturesScreenModel.getMotor3TempTableDataList());
    tempMotor3Table.setVisible(false);

    tempMotor4Table.setItems(propulsionSystemTemperaturesScreenModel.getMotor4TempTableDataList());
    tempMotor4Table.setVisible(false);

    mainTransformferTempTable
        .setItems(propulsionSystemTemperaturesScreenModel.getMainTransformerTempTableDataList());
    mainTransformferTempTable.setVisible(false);

    createTableRenderer(propulsionSystemTemperaturesScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    propulsionSystemTemperaturesScreenModel.getTotalColumn().addListener(totalColumnListener);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(tempMotor1Table, noOfCars, TCMSUIConstants.TEMPERATURES_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE);
      tempMotor1Table.setVisible(true);

      new TableDataRenderer(tempMotor2Table, noOfCars, TCMSUIConstants.TEMPERATURES_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE);
      tempMotor2Table.setVisible(true);

      new TableDataRenderer(tempMotor3Table, noOfCars, TCMSUIConstants.TEMPERATURES_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE);
      tempMotor3Table.setVisible(true);

      new TableDataRenderer(tempMotor4Table, noOfCars, TCMSUIConstants.TEMPERATURES_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE);
      tempMotor4Table.setVisible(true);

      new TableDataRenderer(mainTransformferTempTable, noOfCars,
          TCMSUIConstants.TEMPERATURES_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE);
      mainTransformferTempTable.setVisible(true);
    }
  }

  @Override
  public void detachListeners()
  {
    propulsionSystemTemperaturesScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }
}