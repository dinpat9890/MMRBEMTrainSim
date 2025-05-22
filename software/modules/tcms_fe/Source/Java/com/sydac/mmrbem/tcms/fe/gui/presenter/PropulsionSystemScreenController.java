/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.PROPULSION_SPECIAL_MODES_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.PROPULSION_TEMPERATURES_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.PropulsionSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.PropulsionSystemScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableView;

public class PropulsionSystemScreenController extends AbstractTCMSController
{
  @FXML
  @CommsNumber(PROPULSION_SPECIAL_MODES_BUTTON)
  private Button propulsionSpecialModesBtn;

  @FXML
  @CommsNumber(PROPULSION_TEMPERATURES_BUTTON)
  private Button propulsionTemperaturesBtn;

  @FXML
  private TableView<StatusTableDO> propulsionSystemStatusTable;

  @FXML
  private TableView<StatusTableDO> propulsionSystemValueTable;

  private PropulsionSystemScreenModel propulsionSystemScreenModel;

  private ChangeListener<Number> totalColumnListener;

  @Override
  public void initializeImpl()
  {
    propulsionSystemScreenModel = new PropulsionSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new PropulsionSystemScreenBinder(propulsionSystemScreenModel));

    propulsionSystemStatusTable.setItems(propulsionSystemScreenModel.getStatusTableDataList());
    propulsionSystemStatusTable.setVisible(false);

    propulsionSystemValueTable.setItems(propulsionSystemScreenModel.getValueTableDataList());
    propulsionSystemValueTable.setVisible(false);

    createTableRenderer(propulsionSystemScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    propulsionSystemScreenModel.getTotalColumn().addListener(totalColumnListener);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(propulsionSystemStatusTable, noOfCars,
          TCMSUIConstants.PROPULSION_SCREEN_STATUS_TABLE_COLUMN_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.PROPULSION_SCREEN_TABLE_COLUMN_WIDTH);
      propulsionSystemStatusTable.setVisible(true);

      new TableDataRenderer(propulsionSystemValueTable, noOfCars,
          TCMSUIConstants.PROPULSION_SCREEN_VALUE_TABLE_COLUMN_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.PROPULSION_SCREEN_TABLE_COLUMN_WIDTH);
      propulsionSystemValueTable.setVisible(true);
    }
  }

  @Override
  public void detachListeners()
  {
    propulsionSystemScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }

  @FXML
  private void onTemperaturesButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.PROPULSION_TEMPERATURES_SCREEN, frontend);
  }

  @FXML
  private void onSpecialModesButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.SPECIAL_MODES_SCREEN, frontend);
  }
}