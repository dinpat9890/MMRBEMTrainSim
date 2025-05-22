/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.BRAKE_COMMANDS_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.BrakeSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.BrakeSystemScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableView;

public class BrakeSystemScreenController extends AbstractTCMSController
{
  @FXML
  @CommsNumber(BRAKE_COMMANDS_BUTTON)
  private Button brakeCommandsBtn;

  @FXML
  private TableView<StatusTableDO> brakeStatusTable;

  @FXML
  private TableView<StatusTableDO> wspSuspStatusTable;

  @FXML
  private TableView<StatusTableDO> brakeControlUnitStatusTable;

  @FXML
  private TableView<StatusTableDO> lineStatusTable;

  @FXML
  private TableView<StatusTableDO> holdEpicEdRpressStatusTable;

  @FXML
  private TableView<StatusTableDO> brakeValueTable;

  private ChangeListener<Number> totalColumnListener;

  private BrakeSystemScreenModel brakeSystemScreenModel;

  @Override
  public void detachListeners()
  {
    brakeSystemScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }

  @Override
  public void initializeImpl()
  {
    brakeSystemScreenModel = new BrakeSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new BrakeSystemScreenBinder(brakeSystemScreenModel));

    brakeStatusTable.setItems(brakeSystemScreenModel.getbrakeStatusTableDataList());
    brakeStatusTable.setVisible(false);
    brakeControlUnitStatusTable.setItems(brakeSystemScreenModel.getBrakeControlUnitStatusTableDataList());
    brakeControlUnitStatusTable.setVisible(false);
    wspSuspStatusTable.setItems(brakeSystemScreenModel.getWspSuspStatusTableDataList());
    wspSuspStatusTable.setVisible(false);
    lineStatusTable.setItems(brakeSystemScreenModel.getLineStatusTableDataList());
    lineStatusTable.setVisible(false);
    holdEpicEdRpressStatusTable.setItems(brakeSystemScreenModel.getHoldEpicEdRpressStatusTableDataList());
    holdEpicEdRpressStatusTable.setVisible(false);
    brakeValueTable.setItems(brakeSystemScreenModel.getBrakeValueTableDataList());
    brakeValueTable.setVisible(false);

    createTableRenderer(brakeSystemScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    brakeSystemScreenModel.getTotalColumn().addListener(totalColumnListener);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(brakeStatusTable, noOfCars, TCMSUIConstants.BRAKE_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.BRAKE_SCREEN_TABEL_COLUMN_WIDTH);
      brakeStatusTable.setVisible(true);

      new TableDataRenderer(wspSuspStatusTable, noOfCars, TCMSUIConstants.WSP_SUSP_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.BRAKE_SCREEN_TABEL_COLUMN_WIDTH);
      wspSuspStatusTable.setVisible(true);

      new TableDataRenderer(brakeControlUnitStatusTable, noOfCars,
          TCMSUIConstants.BCU_STATUS_TABLE_CELL_HEIGHT, TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.BRAKE_SCREEN_TABEL_COLUMN_WIDTH);
      brakeControlUnitStatusTable.setVisible(true);

      new TableDataRenderer(lineStatusTable, noOfCars, TCMSUIConstants.BRAKE_LINE_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.BRAKE_SCREEN_TABEL_COLUMN_WIDTH);
      lineStatusTable.setVisible(true);

      new TableDataRenderer(holdEpicEdRpressStatusTable, noOfCars,
          TCMSUIConstants.HOLD_EPIC_ED_RPRESS_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.BRAKE_SCREEN_TABEL_COLUMN_WIDTH);
      holdEpicEdRpressStatusTable.setVisible(true);

      new TableDataRenderer(brakeValueTable, noOfCars, TCMSUIConstants.BRAKE_VALUE_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.BRAKE_SCREEN_TABEL_COLUMN_WIDTH);
      brakeValueTable.setVisible(true);
    }
  }

  @FXML
  private void onBrakeCommandsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.BRAKE_SYSTEM_COMMANDS_SCREEN, frontend);
  }
}
