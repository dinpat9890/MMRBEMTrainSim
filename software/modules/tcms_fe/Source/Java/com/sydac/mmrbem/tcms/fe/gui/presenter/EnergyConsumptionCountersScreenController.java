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

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ENERGY_CONSUMP_PAGE_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ENERGY_CONSUMP_PAGE_UP_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.EnergyConsumptionCountersScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.EnergyConsumpCountersTableDO;
import com.sydac.mmrbem.tcms.fe.gui.model.EnergyConsumptionCountersScreenModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.Pane;

public class EnergyConsumptionCountersScreenController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(ENERGY_CONSUMP_PAGE_UP_BUTTON)
  private Button counterPageUpBtn;

  @FXML
  @CommsNumber(ENERGY_CONSUMP_PAGE_DOWN_BUTTON)
  private Button countersPageDownBtn;

  @FXML
  private Label counterDisplayLbl;

  @FXML
  private TableView<EnergyConsumpCountersTableDO> energyCountersTable;

  private ChangeListener<Number> currentPageListener;

  private ChangeListener<Number> totalPagesListener;

  private ChangeListener<Number> totalEnergyCountersListener;

  private EnergyConsumptionCountersScreenModel energyConsumptionCountersScreenModel;

  @Override
  public void detachListeners()
  {
    energyConsumptionCountersScreenModel.getCurrentPageNumber().removeListener(currentPageListener);
    energyConsumptionCountersScreenModel.getTotalEnergyConsumpCounters()
        .removeListener(totalEnergyCountersListener);
    energyConsumptionCountersScreenModel.getTotalPageNumber().removeListener(totalPagesListener);
  }

  @Override
  public void initializeImpl()
  {
    energyConsumptionCountersScreenModel = new EnergyConsumptionCountersScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new EnergyConsumptionCountersScreenBinder(energyConsumptionCountersScreenModel));

    currentPageListener = (observable, oldVal, newVal) -> updateCountsDisplayLabel();
    energyConsumptionCountersScreenModel.getCurrentPageNumber().addListener(currentPageListener);

    totalPagesListener = (observable, oldVal, newVal) -> updateCountsDisplayLabel();
    energyConsumptionCountersScreenModel.getTotalPageNumber().addListener(totalPagesListener);

    totalEnergyCountersListener = (observable, oldVal, newVal) -> updateCountsDisplayLabel();
    energyConsumptionCountersScreenModel.getTotalEnergyConsumpCounters()
        .addListener(totalEnergyCountersListener);

    updateCountsDisplayLabel();

    energyCountersTable.setFixedCellSize(51);

    energyCountersTable.widthProperty().addListener((source, oldWidth, newWidth) -> {
      Pane header = (Pane)energyCountersTable.lookup("TableHeaderRow"); //$NON-NLS-1$
      if (header.isVisible())
      {
        header.setMaxHeight(0);
        header.setMinHeight(0);
        header.setPrefHeight(0);
        header.setVisible(false);
      }
    });

    TableColumn<EnergyConsumpCountersTableDO, String> countersNameColumn = new TableColumn<>();
    countersNameColumn.setCellValueFactory(new PropertyValueFactory<>("counterName")); //$NON-NLS-1$
    countersNameColumn.setPrefWidth(396);
    countersNameColumn.setSortable(false);
    countersNameColumn.setResizable(false);

    energyCountersTable.getColumns().add(countersNameColumn);

    TableColumn<EnergyConsumpCountersTableDO, String> counterDescriptionColumn = new TableColumn<>();
    counterDescriptionColumn.setCellValueFactory(new PropertyValueFactory<>("counterDescription")); //$NON-NLS-1$
    counterDescriptionColumn.setPrefWidth(380);
    counterDescriptionColumn.setSortable(false);
    counterDescriptionColumn.setResizable(false);

    energyCountersTable.getColumns().add(counterDescriptionColumn);

    TableColumn<EnergyConsumpCountersTableDO, String> counterCurrentValueColumn = new TableColumn<>();
    counterCurrentValueColumn.setCellValueFactory(new PropertyValueFactory<>("currentValue")); //$NON-NLS-1$
    counterCurrentValueColumn.setPrefWidth(140);
    counterCurrentValueColumn.setSortable(false);
    counterCurrentValueColumn.setResizable(false);

    energyCountersTable.getColumns().add(counterCurrentValueColumn);

    TableColumn<EnergyConsumpCountersTableDO, String> counterMeasureUnitColumn = new TableColumn<>();
    counterMeasureUnitColumn.setCellValueFactory(new PropertyValueFactory<>("measureUnit")); //$NON-NLS-1$
    counterMeasureUnitColumn.setPrefWidth(100);
    counterMeasureUnitColumn.setSortable(false);
    counterMeasureUnitColumn.setResizable(false);

    energyCountersTable.getColumns().add(counterMeasureUnitColumn);

    energyCountersTable.setItems(energyConsumptionCountersScreenModel.getEnergyConsumptionCounterList());

  }

  private void updateCountsDisplayLabel()
  {
    counterDisplayLbl.setText(TCMSUIConstants.CURRENT_COUNTER + " counter. (Showing page " //$NON-NLS-1$
        + TCMSUIConstants.CURRENT_PAGE + " of " //$NON-NLS-1$
        + TCMSUIConstants.TOTAL_PAGE + ")"); //$NON-NLS-1$
  }

  @FXML
  private void onCountersPageUpBtnAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.ENERGY_CONSUMP_PAGE_UP_BUTTON_REQUEST);
  }

  @FXML
  private void onCountersPageDownBtnAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.ENERGY_CONSUMP_PAGE_DOWN_BUTTON_REQUEST);
  }

}
