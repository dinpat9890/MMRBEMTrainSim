/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.LightSystemStatusScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.LightSystemStatusScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.TableView;

public class LightSystemStatusScreenController extends AbstractTCMSController
{

  @FXML
  private TableView<StatusTableDO> saloonLightGroupTable1;

  @FXML
  private TableView<StatusTableDO> saloonLightGroupTable2;

  @FXML
  private TableView<StatusTableDO> flasherLightTable;

  private LightSystemStatusScreenModel lightSystemStatusScreenModel;

  private ChangeListener<Number> totalColumnListener;

  @Override
  public void initializeImpl()
  {
    lightSystemStatusScreenModel = new LightSystemStatusScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new LightSystemStatusScreenBinder(lightSystemStatusScreenModel));

    saloonLightGroupTable1.setItems(lightSystemStatusScreenModel.getSaloonLightTableDataList1());
    saloonLightGroupTable1.setVisible(false);

    saloonLightGroupTable2.setItems(lightSystemStatusScreenModel.getSaloonLightTableDataList2());
    saloonLightGroupTable2.setVisible(false);

    flasherLightTable.setItems(lightSystemStatusScreenModel.getFlasherLightTableDataList());
    flasherLightTable.setVisible(false);

    createTableRenderer(lightSystemStatusScreenModel.getTotalColumn().get());

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    lightSystemStatusScreenModel.getTotalColumn().addListener(totalColumnListener);
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(saloonLightGroupTable1, noOfCars,
          TCMSUIConstants.LIGHT_SYSTEM_STATUS_SCREEN_TABLE_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE, TCMSUIConstants.TABLE_COLUMN_WIDTH);
      saloonLightGroupTable1.setVisible(true);

      new TableDataRenderer(saloonLightGroupTable2, noOfCars,
          TCMSUIConstants.LIGHT_SYSTEM_STATUS_SCREEN_TABLE_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE, TCMSUIConstants.TABLE_COLUMN_WIDTH);
      saloonLightGroupTable2.setVisible(true);

      new TableDataRenderer(flasherLightTable, noOfCars,
          TCMSUIConstants.LIGHT_SYSTEM_STATUS_SCREEN_TABLE_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE, TCMSUIConstants.TABLE_COLUMN_WIDTH);
      flasherLightTable.setVisible(true);
    }
  }

  @Override
  public void detachListeners()
  {
    lightSystemStatusScreenModel.getTotalColumn().removeListener(totalColumnListener);
  }

}
