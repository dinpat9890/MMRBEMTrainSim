/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.RESET_FDU_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.RESET_FIRE_ALARM_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FireDetectionSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.FireDetectionSystemScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableView;
import javafx.scene.input.MouseEvent;

public class FireDetectionSystemScreenController extends AbstractTCMSController
{

  @FXML
  private TableView<StatusTableDO> fireDetectionSensorStatusTabel;

  @FXML
  private TableView<StatusTableDO> fireDetectionWiredStatusTable;

  @FXML
  private TableView<StatusTableDO> fduSystemFaultStatusTable;

  @FXML
  @CommsNumber(RESET_FDU_BUTTON)
  private Button fireDetectionRestFduButton;

  @FXML
  @CommsNumber(RESET_FIRE_ALARM_BUTTON)
  private Button fireDetectionRestFireAlarmButton;

  private FireDetectionSystemScreenModel fireDetectionSystemScreenModel;

  private ChangeListener<Number> totalColumnListener;

  @Override
  public void initializeImpl()
  {
    fireDetectionSystemScreenModel = new FireDetectionSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FireDetectionSystemScreenBinder(fireDetectionSystemScreenModel));

    fireDetectionSensorStatusTabel.setItems(fireDetectionSystemScreenModel.getSensorStatusTableDataList());
    fireDetectionSensorStatusTabel.setVisible(false);

    fireDetectionWiredStatusTable.setItems(fireDetectionSystemScreenModel.getWiredStatusTableDataList());
    fireDetectionWiredStatusTable.setVisible(false);

    fduSystemFaultStatusTable.setItems(fireDetectionSystemScreenModel.getFduSystemFaultStatusDataList());
    fduSystemFaultStatusTable.setVisible(false);

    createTableRenderer(fireDetectionSystemScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    fireDetectionSystemScreenModel.getTotalColumn().addListener(totalColumnListener);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(fireDetectionSensorStatusTabel, noOfCars,
          TCMSUIConstants.FIRE_DETECTION_SCREEN_SENSOR_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE, TCMSUIConstants.TABLE_COLUMN_WIDTH);
      fireDetectionSensorStatusTabel.setVisible(true);

      new TableDataRenderer(fireDetectionWiredStatusTable, noOfCars,
          TCMSUIConstants.FIRE_DETECTION_SCREEN_WIRED_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE, TCMSUIConstants.TABLE_COLUMN_WIDTH);
      fireDetectionWiredStatusTable.setVisible(true);

      new TableDataRenderer(fduSystemFaultStatusTable, noOfCars,
          TCMSUIConstants.FIRE_DETECTION_SCREEN_FDU_STATUS_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE, TCMSUIConstants.TABLE_COLUMN_WIDTH);
      fduSystemFaultStatusTable.setVisible(true);
    }
  }

  @Override
  public void detachListeners()
  {
    fireDetectionSystemScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }
  
  @FXML
  private void onResetFirAlarmAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
    .sendButtonClickRequest(VDUInputs.RESET_FIRE_ALARM_REQ);
  }

  @FXML
  private void onResetFduAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
    .sendButtonClickRequest(VDUInputs.RESET_FDU_REQ);
  }
}
