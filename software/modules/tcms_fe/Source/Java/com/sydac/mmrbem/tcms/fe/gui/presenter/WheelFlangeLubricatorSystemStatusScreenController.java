/*******************************************************************************
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 *******************************************************************************/

package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.WheelFlangeLubricatorSystemStatusScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.StatusTableDO;
import com.sydac.mmrbem.tcms.fe.gui.data.TableDataRenderer;
import com.sydac.mmrbem.tcms.fe.gui.model.WheelFlangeLubricatorSystemStatusScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TableView;
import javafx.scene.layout.GridPane;

public class WheelFlangeLubricatorSystemStatusScreenController extends AbstractTCMSController
{
  @FXML
  private TableView<StatusTableDO> wflStatusListTable;

  @FXML
  private GridPane sixCarIsolateCommandGrid;

  @FXML
  private GridPane eightCarIsolateCommandGrid;

  @FXML
  private Button sixCarDm1IsolateWflBtn;

  @FXML
  private Button sixCarDm6IsolateWflBtn;

  @FXML
  private Button eightCarDm1lsolateWflBtn;

  @FXML
  private Button eightCarDm8lsolateWflBtn;

  private static final String ISOLATE_TEXT = "ISOLATE"; //$NON-NLS-1$

  private static final String DE_ISOLATE_TEXT = "DE-ISOLATE"; //$NON-NLS-1$

  private WheelFlangeLubricatorSystemStatusScreenModel wheelFlangeLubricatorSystemStatusScreenModel;

  private ChangeListener<Number> totalColumnListener;

  private ChangeListener<Number> frontCabWflIsolationListener;

  private ChangeListener<Number> rearCabWflIsolationListener;

  @Override
  public void initializeImpl()
  {

    wheelFlangeLubricatorSystemStatusScreenModel = new WheelFlangeLubricatorSystemStatusScreenModel(
        scenarioCarIndex);
    tcmsScreenBinders
        .add(new WheelFlangeLubricatorSystemStatusScreenBinder(wheelFlangeLubricatorSystemStatusScreenModel));

    wflStatusListTable.setItems(wheelFlangeLubricatorSystemStatusScreenModel.getWFLStatusTableDataList());
    wflStatusListTable.setVisible(false);

    totalColumnListener = (observable, oldVal, newVal) -> createTableRenderer((int)newVal);
    wheelFlangeLubricatorSystemStatusScreenModel.getTotalColumn().addListener(totalColumnListener);

    createTableRenderer(wheelFlangeLubricatorSystemStatusScreenModel.getTotalColumn().get());

    frontCabWflIsolationListener = (observable, oldVal,
        newVal) -> updateFrontCabButtonText(newVal.intValue());
    wheelFlangeLubricatorSystemStatusScreenModel.getFrontCarWflIsolatedStatus()
        .addListener(frontCabWflIsolationListener);

    rearCabWflIsolationListener = (observable, oldVal, newVal) -> updateRearCabButtonText(newVal.intValue());
    wheelFlangeLubricatorSystemStatusScreenModel.getRearCarWflIsolatedStatus()
        .addListener(rearCabWflIsolationListener);

  }

  private void updateFrontCabButtonText(int isolatedSatus)
  {
    if (isolatedSatus == TCMSUIConstants.WFL_DE_ISOLATED_VALUE)
    {
      sixCarDm1IsolateWflBtn.setText(ISOLATE_TEXT);
      eightCarDm1lsolateWflBtn.setText(ISOLATE_TEXT);
    }
    else
    {
      sixCarDm1IsolateWflBtn.setText(DE_ISOLATE_TEXT);
      eightCarDm1lsolateWflBtn.setText(DE_ISOLATE_TEXT);
    }
  }

  private void updateRearCabButtonText(int isolatedSatus)
  {
    if (isolatedSatus == TCMSUIConstants.WFL_DE_ISOLATED_VALUE)
    {
      sixCarDm6IsolateWflBtn.setText(ISOLATE_TEXT);
      eightCarDm8lsolateWflBtn.setText(ISOLATE_TEXT);
    }
    else
    {
      sixCarDm6IsolateWflBtn.setText(DE_ISOLATE_TEXT);
      eightCarDm8lsolateWflBtn.setText(DE_ISOLATE_TEXT);
    }
  }

  private void createTableRenderer(int noOfCars)
  {
    if (noOfCars != 0)
    {
      new TableDataRenderer(wflStatusListTable, noOfCars,
          TCMSUIConstants.WFL_SYSTEM_STATUS_SCREEN_TABLE_HEIGHT,
          TCMSUIConstants.TABLE_SCREEN_SIDE_VIEW_CAR_PANEL_SIZE,
          TCMSUIConstants.PROPULSION_SCREEN_TABLE_COLUMN_WIDTH);
      wflStatusListTable.setVisible(true);

      updateIsolateCommandGridActive(noOfCars);
    }
  }

  private void updateIsolateCommandGridActive(int totalCar)
  {
    if (totalCar == TCMSConstants.SIX_CAR)
    {
      sixCarIsolateCommandGrid.setVisible(true);
      eightCarIsolateCommandGrid.setVisible(false);
    }
    else if (totalCar == TCMSConstants.EIGHT_CAR)
    {
      sixCarIsolateCommandGrid.setVisible(false);
      eightCarIsolateCommandGrid.setVisible(true);
    }
  }

  @Override
  public void detachListeners()
  {
    wheelFlangeLubricatorSystemStatusScreenModel.getTotalColumn().removeListener(totalColumnListener);
    wheelFlangeLubricatorSystemStatusScreenModel.getFrontCarWflIsolatedStatus()
        .removeListener(frontCabWflIsolationListener);
    wheelFlangeLubricatorSystemStatusScreenModel.getRearCarWflIsolatedStatus()
        .removeListener(rearCabWflIsolationListener);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void sixCarDm1IsolateWflButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendWflIsolateReq(
        VDUInputs.WFL_ISOLATED_REQ_FRONT_CAR,
        wheelFlangeLubricatorSystemStatusScreenModel.getFrontCarWflIsolatedStatus()
            .get() == TCMSUIConstants.WFL_DE_ISOLATED_VALUE ? TCMSUIConstants.WFL_ISOLATED_VALUE
                : TCMSUIConstants.WFL_DE_ISOLATED_VALUE);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void sixCarDm6IsolateWflButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendWflIsolateReq(
        VDUInputs.WFL_ISOLATED_REQ_REAR_CAR,
        wheelFlangeLubricatorSystemStatusScreenModel.getRearCarWflIsolatedStatus()
            .get() == TCMSUIConstants.WFL_DE_ISOLATED_VALUE ? TCMSUIConstants.WFL_ISOLATED_VALUE
                : TCMSUIConstants.WFL_DE_ISOLATED_VALUE);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onEightCarDm1IsolateWflButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendWflIsolateReq(
        VDUInputs.WFL_ISOLATED_REQ_FRONT_CAR,
        wheelFlangeLubricatorSystemStatusScreenModel.getFrontCarWflIsolatedStatus()
            .get() == TCMSUIConstants.WFL_DE_ISOLATED_VALUE ? TCMSUIConstants.WFL_ISOLATED_VALUE
                : TCMSUIConstants.WFL_DE_ISOLATED_VALUE);
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void onEightCarDm8IsolateWflButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendWflIsolateReq(
        VDUInputs.WFL_ISOLATED_REQ_REAR_CAR,
        wheelFlangeLubricatorSystemStatusScreenModel.getRearCarWflIsolatedStatus()
            .get() == TCMSUIConstants.WFL_DE_ISOLATED_VALUE ? TCMSUIConstants.WFL_ISOLATED_VALUE
                : TCMSUIConstants.WFL_DE_ISOLATED_VALUE);
  }
}
