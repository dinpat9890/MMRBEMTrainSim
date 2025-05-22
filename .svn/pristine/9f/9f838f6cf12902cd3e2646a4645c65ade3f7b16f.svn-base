/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.APSSystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.APSSystemScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;

public class APSSystemScreenController extends AbstractTCMSController
{

  @FXML
  private TableView<StatusTableDO> apsSystemStatusTable;

  private APSSystemScreenModel apsSystemScreenModel;

  private ChangeListener<Number> totalColumnListener;

  @Override
  public void detachListeners()
  {
    apsSystemScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }

  @Override
  public void initializeImpl()
  {
    apsSystemScreenModel = new APSSystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new APSSystemScreenBinder(apsSystemScreenModel));

    apsSystemStatusTable.setItems(apsSystemScreenModel.getStatusTableDataList());
    apsSystemStatusTable.setVisible(false);

    createTableRenderer(apsSystemScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    apsSystemScreenModel.getTotalColumn().addListener(totalColumnListener);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(apsSystemStatusTable, noOfCars, TCMSUIConstants.APS_SYSTEM_TABLE_CELL_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.TABLE_SCREEN_TOP_VIEW_CAR_PANEL_SIZE);
      apsSystemStatusTable.setVisible(true);
    }
  }

}
