/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.HVAC_TEMPRETURE_COMMANDS_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.HVAC_TEMPRETURE_STATUS_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.HVACTempretureScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.HVACTempretureScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableView;

public class HVACSystemTempretureScreenController extends AbstractTCMSController
{

  @FXML
  private TableView<StatusTableDO> hvacSystemStatusTableOneTable;

  @FXML
  private TableView<StatusTableDO> hvacSystemStatusTableTwoTable;

  @FXML
  @CommsNumber(HVAC_TEMPRETURE_COMMANDS_BUTTON)
  private Button hvacSystemCommandButton;
  
  @FXML
  @CommsNumber(HVAC_TEMPRETURE_STATUS_BUTTON)
  private Button hvacTempStatusButton;

  private HVACTempretureScreenModel hvacTempretureScreenModel;

  private ChangeListener<Number> totalColumnListener;

  @Override
  public void initializeImpl()
  {

    hvacTempretureScreenModel = new HVACTempretureScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HVACTempretureScreenBinder(hvacTempretureScreenModel));

    hvacSystemStatusTableOneTable.setItems(hvacTempretureScreenModel.getHvacStatusOneTableDataList());
    hvacSystemStatusTableOneTable.setVisible(false);

    hvacSystemStatusTableTwoTable.setItems(hvacTempretureScreenModel.getHvacStatusTwoTableDataList());
    hvacSystemStatusTableTwoTable.setVisible(false);

    createTableRenderer(hvacTempretureScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    hvacTempretureScreenModel.getTotalColumn().addListener(totalColumnListener);
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
    hvacTempretureScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }

  @FXML
  void onCommandsButtonAction(ActionEvent event)
  {
   // THis will go to command screen
  }
  
  @FXML
  void onStatusButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendScreenChangeRequest(ScreenId.HVAC_SYSTEM_STATUS_SCREEN, frontend);
  }
  
}
