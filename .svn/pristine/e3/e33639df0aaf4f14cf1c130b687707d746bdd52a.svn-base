/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.HVAC_COMMAND_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.HVACSystemStatusScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.HVACSystemStatusScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableView;

public class HVACSystemStatusScreenController extends AbstractTCMSController
{

  @FXML
  private TableView<StatusTableDO> hvacSystemStatusTableOneTable;

  @FXML
  private TableView<StatusTableDO> hvacSystemStatusTableTwoTable;

  @FXML
  @CommsNumber(HVAC_COMMAND_BUTTON)
  private Button hvacSystemCommandButton;
  
  @FXML
  @CommsNumber(VDUInputs.HVAC_SYSTEM_TEMPRETURE_BUTTON)
  private Button hvacTempButton;

  private HVACSystemStatusScreenModel hvacSystemStatusScreenModel;

  private ChangeListener<Number> totalColumnListener;

  @Override
  public void initializeImpl()
  {

    hvacSystemStatusScreenModel = new HVACSystemStatusScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HVACSystemStatusScreenBinder(hvacSystemStatusScreenModel));

    hvacSystemStatusTableOneTable.setItems(hvacSystemStatusScreenModel.getHvacStatusOneTableDataList());
    hvacSystemStatusTableOneTable.setVisible(false);

    hvacSystemStatusTableTwoTable.setItems(hvacSystemStatusScreenModel.getHvacStatusTwoTableDataList());
    hvacSystemStatusTableTwoTable.setVisible(false);

    createTableRenderer(hvacSystemStatusScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    hvacSystemStatusScreenModel.getTotalColumn().addListener(totalColumnListener);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {

      new TableDataRenderer(hvacSystemStatusTableOneTable, noOfCars,
          TCMSUIConstants.HVAC_SYSTEM_SCREEN_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE, TCMSUIConstants.TABLE_COLUMN_WIDTH);
      hvacSystemStatusTableOneTable.setVisible(true);

      new TableDataRenderer(hvacSystemStatusTableTwoTable, noOfCars,
          TCMSUIConstants.HVAC_SYSTEM_SCREEN_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE, TCMSUIConstants.TABLE_COLUMN_WIDTH);
      hvacSystemStatusTableTwoTable.setVisible(true);

    }
  }

  @Override
  public void detachListeners()
  {
    hvacSystemStatusScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }

  
  @FXML
  void onCommandsButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.HVAC_COMMANDS_SCREEN, frontend);
  }
  
  @FXML
  void onTempretureButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.HVAC_TEMPRETURE_SCREEN, frontend);
  }
}
