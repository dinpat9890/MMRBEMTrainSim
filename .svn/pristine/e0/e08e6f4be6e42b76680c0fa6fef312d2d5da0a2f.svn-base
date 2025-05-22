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

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_ANY_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_ANY_PRIORITY_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_ANY_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_APS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_ATC_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_BCG_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_BRAKES_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_CCTV_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_DM1_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_DM6_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_DOORS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_FDS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_HVAC_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_HV_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_LIGHTS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_LV_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_M3_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_M4_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_MV_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PAGE_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PAGE_UP_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PAPIS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PRIORITY_1_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PRIORITY_2_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PRIORITY_3_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PRIORITY_4_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PRIORITY_5_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PRIORITY_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_PROP_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_T2_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_T5_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_TCMS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_TR_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_UPDATE_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_VEHICLE_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.ACTIVE_FAULTS_WFL_SYSTEM_FILTER_BUTTON;

import com.sydac.gui.control.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.cabscreens.fe.utils.timer.CommsTimer;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsCarFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsPriorityFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsSystemFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.ActiveFaultsScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.FaultsTableDO;
import com.sydac.mmrbem.tcms.fe.gui.model.ActiveFaultsScreenModel;

import javafx.application.Platform;
import javafx.beans.property.ListProperty;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.geometry.Insets;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableCell;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.util.Callback;

public class ActiveFaultsScreenController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(ACTIVE_FAULTS_UPDATE_BUTTON)
  private Button updateActiveFaultsBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PAGE_UP_BUTTON)
  private Button pageUpBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PAGE_DOWN_BUTTON)
  private Button pageDownBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_FILTER_BUTTON)
  private Button filterActiveFaultsBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_SYSTEM_FILTER_BUTTON)
  private Button filterSystemBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_CAR_FILTER_BUTTON)
  private Button filterCarBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PRIORITY_FILTER_BUTTON)
  private Button filterPriorityBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_ANY_SYSTEM_FILTER_BUTTON)
  private Button anySysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_ATC_SYSTEM_FILTER_BUTTON)
  private Button atcSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_VEHICLE_SYSTEM_FILTER_BUTTON)
  private Button vehicleSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PAPIS_SYSTEM_FILTER_BUTTON)
  private Button papisSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_HV_SYSTEM_FILTER_BUTTON)
  private Button hvSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_FDS_SYSTEM_FILTER_BUTTON)
  private Button fdsSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_MV_SYSTEM_FILTER_BUTTON)
  private Button mvSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_LV_SYSTEM_FILTER_BUTTON)
  private Button lvSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_CCTV_SYSTEM_FILTER_BUTTON)
  private Button cctvSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_TR_SYSTEM_FILTER_BUTTON)
  private Button trSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_TCMS_SYSTEM_FILTER_BUTTON)
  private Button tcmsSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_WFL_SYSTEM_FILTER_BUTTON)
  private Button wflSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_HVAC_SYSTEM_FILTER_BUTTON)
  private Button hvacSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_BCG_SYSTEM_FILTER_BUTTON)
  private Button bcgSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_BRAKES_SYSTEM_FILTER_BUTTON)
  private Button brakesSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_APS_SYSTEM_FILTER_BUTTON)
  private Button apsSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_DOORS_SYSTEM_FILTER_BUTTON)
  private Button doorsSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_LIGHTS_SYSTEM_FILTER_BUTTON)
  private Button lightsSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PROP_SYSTEM_FILTER_BUTTON)
  private Button propulsionSysFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_ANY_CAR_FILTER_BUTTON)
  private Button anyCarFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_DM1_CAR_FILTER_BUTTON)
  private Button dm1CarFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_T2_CAR_FILTER_BUTTON)
  private Button t2CarFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_M3_CAR_FILTER_BUTTON)
  private Button m3CarFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_M4_CAR_FILTER_BUTTON)
  private Button m4CarFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_T5_CAR_FILTER_BUTTON)
  private Button t5CarFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_DM6_CAR_FILTER_BUTTON)
  private Button dm6CarFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_ANY_PRIORITY_FILTER_BUTTON)
  private Button anyPriorityFilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PRIORITY_1_FILTER_BUTTON)
  private Button priority1FilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PRIORITY_2_FILTER_BUTTON)
  private Button priority2FilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PRIORITY_3_FILTER_BUTTON)
  private Button priority3FilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PRIORITY_4_FILTER_BUTTON)
  private Button priority4FilterBtn;

  @FXML
  @CommsNumber(ACTIVE_FAULTS_PRIORITY_5_FILTER_BUTTON)
  private Button priority5FilterBtn;

  @FXML
  private TableView<FaultsTableDO> activeFaultsTableView;

  @FXML
  private GridPane activeFaultsMainGrid;

  @FXML
  private GridPane filterOptionsGrid;

  @FXML
  private GridPane filterSystemSubGrid;

  @FXML
  private GridPane filterCarSubGrid;

  @FXML
  private GridPane filterPrioritySubGrid;

  @FXML
  private Label faultCountDisplayLbl;

  private ChangeListener<Number> currentPageListener;

  private ChangeListener<Number> totalPagesListener;

  private ChangeListener<Number> totalActiveFaultsListener;

  private ChangeListener<Number> faultListUpdateListener;

  private ChangeListener<? super ObservableList<FaultsTableDO>> faultsListListener;

  private ChangeListener<Number> pageUpBtnActiveListener;

  private ChangeListener<Number> pageDownBtnActiveListener;

  private ChangeListener<Number> systemFilterListener;

  private ChangeListener<Number> carFilterListener;

  private ChangeListener<Number> priorityFilterListener;

  private ActiveFaultsScreenModel activeFaultsScreenModel;

  private NodePseudoClassProperty updateButtonProperty;

  private NodePseudoClassProperty filterButtonProperty;

  private NodePseudoClassProperty systemFilterButtonProperty;

  private NodePseudoClassProperty carFilterButtonProperty;

  private NodePseudoClassProperty priorityFilterButtonProperty;

  private NodePseudoClassProperty pageUpButtonProperty;

  private NodePseudoClassProperty pageDownButtonProperty;

  private int systemFilterId = ActiveFaultsSystemFilterEnum.ANY.getSysFilterId();

  private int carFilterId = ActiveFaultsCarFilterEnum.ANY.getCarFilterId();

  private int priorityFilterId = ActiveFaultsPriorityFilterEnum.ANY.getPriorityFilterId();

  private CommsTimer updateButtonTimer;

  private boolean toggleFlag1 = false;

  private int updateFashCount = 0;

  private Runnable updateRunnable = () -> {
    if (updateFashCount < 4)
    {
      toggleFlag1 = !toggleFlag1;
      updateButtonProperty
          .set(toggleFlag1 ? TCMSUIConstants.SELECTED_PSEUDO_CLASS : TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
      updateFashCount++;
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendActiveFaultsUpdateButtonRequest(1);
    }
  };

  @Override
  public void detachListeners()
  {
    activeFaultsScreenModel.getCurrentPageNumber().removeListener(currentPageListener);
    activeFaultsScreenModel.getTotalPageNumber().removeListener(totalPagesListener);
    activeFaultsScreenModel.getTotalActiveFaults().removeListener(totalActiveFaultsListener);
    activeFaultsScreenModel.getFaultListUpdateAvailable().removeListener(faultListUpdateListener);
    activeFaultsScreenModel.getActiveFaultsList().removeListener(faultsListListener);
    activeFaultsScreenModel.getPageUpActive().removeListener(pageUpBtnActiveListener);
    activeFaultsScreenModel.getPageDownActive().removeListener(pageDownBtnActiveListener);
    activeFaultsScreenModel.getAppliedSystemFilterId().removeListener(systemFilterListener);
    activeFaultsScreenModel.getAppliedCarFilterId().removeListener(carFilterListener);
    activeFaultsScreenModel.getAppliedPriorityFilterId().removeListener(priorityFilterListener);
  }

  @Override
  public void initializeImpl()
  {
    activeFaultsScreenModel = new ActiveFaultsScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new ActiveFaultsScreenBinder(activeFaultsScreenModel));

    activeFaultsMainGrid.setVisible(true);
    filterOptionsGrid.setVisible(false);
    filterSystemSubGrid.setVisible(false);
    filterCarSubGrid.setVisible(false);
    filterPrioritySubGrid.setVisible(false);

    filterButtonProperty = new NodePseudoClassProperty(filterActiveFaultsBtn);
    systemFilterButtonProperty = new NodePseudoClassProperty(filterSystemBtn);
    carFilterButtonProperty = new NodePseudoClassProperty(filterCarBtn);
    priorityFilterButtonProperty = new NodePseudoClassProperty(filterPriorityBtn);
    pageUpButtonProperty = new NodePseudoClassProperty(pageUpBtn);
    pageDownButtonProperty = new NodePseudoClassProperty(pageDownBtn);

    currentPageListener = (observable, oldVal, newVal) -> updateFaultCountsDisplayLabel();
    activeFaultsScreenModel.getCurrentPageNumber().addListener(currentPageListener);

    totalPagesListener = (observable, oldVal, newVal) -> updateFaultCountsDisplayLabel();
    activeFaultsScreenModel.getTotalPageNumber().addListener(totalPagesListener);

    pageUpBtnActiveListener = (observable, oldVal, newVal) -> updatePageUpBtnActive(newVal.intValue());
    activeFaultsScreenModel.getPageUpActive().addListener(pageUpBtnActiveListener);

    pageDownBtnActiveListener = (observable, oldVal, newVal) -> updatePageDownBtnActive(newVal.intValue());
    activeFaultsScreenModel.getPageDownActive().addListener(pageDownBtnActiveListener);

    systemFilterListener = (observable, oldVal, newVal) -> updateAppliedSystemFilterText(newVal.intValue());
    activeFaultsScreenModel.getAppliedSystemFilterId().addListener(systemFilterListener);

    carFilterListener = (observable, oldVal, newVal) -> updateAppliedCarFilterText(newVal.intValue());
    activeFaultsScreenModel.getAppliedCarFilterId().addListener(carFilterListener);

    priorityFilterListener = (observable, oldVal,
        newVal) -> updateAppliedPriorityFilterText(newVal.intValue());
    activeFaultsScreenModel.getAppliedPriorityFilterId().addListener(priorityFilterListener);

    updateButtonTimer = CommsTimer.newRepeatTimer(updateRunnable, 0, 500);

    totalActiveFaultsListener = (observable, oldVal, newVal) -> updateFaultCountsDisplayLabel();
    activeFaultsScreenModel.getTotalActiveFaults().addListener(totalActiveFaultsListener);

    faultListUpdateListener = (observable, oldVal, newVal) -> updateUpdateButtonCss((Integer)newVal);
    activeFaultsScreenModel.getFaultListUpdateAvailable().addListener(faultListUpdateListener);

    faultsListListener = (observable, oldVal,
        newVal) -> setTableProperties(activeFaultsScreenModel.getActiveFaultsList());
    activeFaultsScreenModel.getActiveFaultsList().addListener(faultsListListener);

    updateButtonProperty = new NodePseudoClassProperty(updateActiveFaultsBtn);

    updateFaultCountsDisplayLabel();
    updatePageUpBtnActive(activeFaultsScreenModel.getPageUpActive().get());
    updatePageDownBtnActive(activeFaultsScreenModel.getPageDownActive().get());
    updateAppliedSystemFilterText(systemFilterId);
    updateAppliedCarFilterText(carFilterId);
    updateAppliedPriorityFilterText(priorityFilterId);
    setTableProperties(activeFaultsScreenModel.getActiveFaultsList());
  }

  private void updatePageDownBtnActive(int active)
  {
    pageDownButtonProperty.set(active == TCMSConstants.ACTIVE ? TCMSUIConstants.ACTIVE_PSEUDO_CLASS
        : TCMSUIConstants.NOT_ACTIVE_PSEUDO_CLASS);
  }

  private void updatePageUpBtnActive(Integer active)
  {
    pageUpButtonProperty.set(active == TCMSConstants.ACTIVE ? TCMSUIConstants.ACTIVE_PSEUDO_CLASS
        : TCMSUIConstants.NOT_ACTIVE_PSEUDO_CLASS);
  }

  private void updateUpdateButtonCss(Integer update)
  {
    if (update == TCMSConstants.ACTIVE)
    {
      updateFashCount = 0;
      updateButtonTimer.start();
    }
    else
    {
      if (updateButtonTimer.isRunning())
      {
        updateButtonTimer.safeCancel();
      }
      updateButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
  }

  private void setTableProperties(ListProperty<FaultsTableDO> eventList)
  {
    if (eventList != null && !eventList.isEmpty())
    {
      activeFaultsTableView.setVisible(true);
      activeFaultsTableView.setFixedCellSize(63 * 1.0);
      activeFaultsTableView.getSelectionModel().setCellSelectionEnabled(false);
      activeFaultsTableView.setPadding(new Insets(0, 0, 0, 0));

      activeFaultsTableView.widthProperty().addListener((source, oldWidth, newWidth) -> {
        Pane header = (Pane)activeFaultsTableView.lookup("TableHeaderRow"); //$NON-NLS-1$
        if (header.isVisible())
        {
          header.setPrefHeight(56);
          header.setVisible(true);
        }
      });

      activeFaultsTableView.getColumns().add(getColumn("carCode", 100 * 1.0, "CAR")); //$NON-NLS-1$ //$NON-NLS-2$
      activeFaultsTableView.getColumns().add(getColumn("faultCode", 100 * 1.0, "CODE")); //$NON-NLS-1$ //$NON-NLS-2$
      activeFaultsTableView.getColumns().add(getColumn("faultOccuranceDateTime", 130 * 1.0, "DATE/TIME")); //$NON-NLS-1$ //$NON-NLS-2$
      activeFaultsTableView.getColumns().add(getColumn("faultSystemName", 120 * 1.0, "SYSTEM")); //$NON-NLS-1$ //$NON-NLS-2$
      activeFaultsTableView.getColumns().add(getColumn("faultDescription", 574 * 1.0, "DESCRIPTION")); //$NON-NLS-1$ //$NON-NLS-2$
      activeFaultsTableView.getColumns().add(getColumn("faultLevel", 0 * 1.0, "PR")); //$NON-NLS-1$ //$NON-NLS-2$

      activeFaultsTableView.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY);

      activeFaultsTableView.setItems(eventList);

      activeFaultsTableView.getSelectionModel().selectedIndexProperty()
          .addListener(new RowChangeHandler(activeFaultsTableView, eventList));
    }
  }

  private class RowChangeHandler implements ChangeListener<Object>
  {
    private ListProperty<FaultsTableDO> eventList;

    private TableView<FaultsTableDO> currentEventTable;

    public RowChangeHandler(TableView<FaultsTableDO> eventTable, ListProperty<FaultsTableDO> eventList)
    {
      this.currentEventTable = eventTable;
      this.eventList = eventList;
    }

    @Override
    public void changed(ObservableValue<?> ov, Object oldVal, Object newVal)
    {

      int selectedRow = currentEventTable.getSelectionModel().getSelectedIndex();

      if (selectedRow == -1)
      {
        return;
      }
      else
      {
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendSelectedActiveFaultRequest(Integer.valueOf(eventList.get(selectedRow).getFaultCode()));
        TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
            .sendScreenChangeRequest(ScreenId.FAULT_DETAILS_SCREEN, frontend);
      }

      Platform.runLater(() -> {
        currentEventTable.requestFocus();
        currentEventTable.getSelectionModel().select(selectedRow);
        currentEventTable.getFocusModel().focus(selectedRow);
      });
    }
  }

  private TableColumn<FaultsTableDO, Object> getColumn(String columnName, double width, String headerName)
  {
    TableColumn<FaultsTableDO, Object> column = new TableColumn<>((headerName));
    column.setCellValueFactory(new PropertyValueFactory<>(columnName));

    column
        .setCellFactory(new Callback<TableColumn<FaultsTableDO, Object>, TableCell<FaultsTableDO, Object>>() {
          @Override
          public TableCell<FaultsTableDO, Object> call(TableColumn<FaultsTableDO, Object> param)
          {
            return new TableCell<FaultsTableDO, Object>() {
              @Override
              protected void updateItem(Object item, boolean empty)
              {
                if (!empty)
                {
                  int currentIndex = indexProperty().getValue() < 0 ? 0 : indexProperty().getValue();
                  Integer clmStatus = param.getTableView().getItems().get(currentIndex).getFaultLevel();
                  if (clmStatus == (TCMSConstants.FAULT_PRIORITY_1))
                  {
                    setStyle(TCMSUIConstants.FAULTS_TABLE_PRIORITY_1_CSS);
                    setText(item.toString());
                  }
                  else if (clmStatus == (TCMSConstants.FAULT_PRIORITY_2))
                  {
                    setStyle(TCMSUIConstants.FAULTS_TABLE_PRIORITY_2_CSS);
                    setText(item.toString());
                  }
                  else
                  {
                    setStyle(TCMSUIConstants.FAULTS_TABLE_LOW_PRIORITY_CSS);
                    setText(item.toString());
                  }
                }
                else
                {
                  setStyle(TCMSUIConstants.FAULTS_TABLE_LOW_PRIORITY_CSS);
                  setText(ApplicationConstants.BLANK);
                }
              }
            };
          }
        });
    column.setPrefWidth(width);
    column.setMinWidth(width);
    column.setMaxWidth(width);
    column.setSortable(false);
    column.setResizable(false);
    return column;
  }

  private void updateFaultCountsDisplayLabel()
  {
    faultCountDisplayLbl.setText("There are " + activeFaultsScreenModel.getTotalActiveFaults().get() //$NON-NLS-1$
        + " active faults. (Showing page " + activeFaultsScreenModel.getCurrentPageNumber().get() + " of " //$NON-NLS-1$ //$NON-NLS-2$
        + activeFaultsScreenModel.getTotalPageNumber().get() + ")"); //$NON-NLS-1$
  }

  private void updateFilterButtonProperty()
  {
    if (systemFilterId != ActiveFaultsSystemFilterEnum.ANY.getSysFilterId()
        || carFilterId != ActiveFaultsCarFilterEnum.ANY.getCarFilterId()
        || priorityFilterId != ActiveFaultsPriorityFilterEnum.ANY.getPriorityFilterId())
    {
      filterButtonProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
    else
    {
      filterButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
  }

  @FXML
  void onUpdateActiveFaultsButtonAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendActiveFaultsUpdateButtonRequest(1);
  }

  @FXML
  void onPageUpActiveFaultsButtonAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendActiveFaultsPageUpButtonRequest(1);
  }

  @FXML
  void onPageDownActiveFaultsButtonAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendActiveFaultsPageDownButtonRequest(1);
  }

  @FXML
  void onFilterActiveFaultsButtonAction()
  {
    filterOptionsGrid.setVisible(!filterOptionsGrid.isVisible());
    filterSystemSubGrid.setVisible(false);
    filterCarSubGrid.setVisible(false);
    filterPrioritySubGrid.setVisible(false);
  }

  @FXML
  void onFilterSystemButtonAction()
  {
    filterSystemSubGrid.setVisible(true);
    filterCarSubGrid.setVisible(false);
    filterPrioritySubGrid.setVisible(false);
  }

  @FXML
  void onFilterCarButtonAction()
  {
    filterSystemSubGrid.setVisible(false);
    filterCarSubGrid.setVisible(true);
    filterPrioritySubGrid.setVisible(false);
  }

  @FXML
  void onFilterPriorityButtonAction()
  {
    filterSystemSubGrid.setVisible(false);
    filterCarSubGrid.setVisible(false);
    filterPrioritySubGrid.setVisible(true);
  }

  @FXML
  void onFilterSystemSubOptionsButtonAction(ActionEvent actionEvent)
  {
    if (actionEvent.getSource().equals(anySysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.ANY);
    }
    else if (actionEvent.getSource().equals(vehicleSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.VEHICLE);
    }
    else if (actionEvent.getSource().equals(hvSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.HV);
    }
    else if (actionEvent.getSource().equals(mvSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.MV);
    }
    else if (actionEvent.getSource().equals(lvSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.LV);
    }
    else if (actionEvent.getSource().equals(tcmsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.TCMS);
    }
    else if (actionEvent.getSource().equals(hvacSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.HVAC);
    }
    else if (actionEvent.getSource().equals(brakesSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.BRAKES);
    }
    else if (actionEvent.getSource().equals(doorsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.DOORS);
    }
    else if (actionEvent.getSource().equals(lightsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.LIGHTS);
    }
    else if (actionEvent.getSource().equals(atcSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.ATC);
    }
    else if (actionEvent.getSource().equals(papisSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.PAPIS);
    }
    else if (actionEvent.getSource().equals(fdsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.FDS);
    }
    else if (actionEvent.getSource().equals(cctvSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.CCTV);
    }
    else if (actionEvent.getSource().equals(trSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.TR);
    }
    else if (actionEvent.getSource().equals(wflSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.WFL);
    }
    else if (actionEvent.getSource().equals(bcgSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.BCG);
    }
    else if (actionEvent.getSource().equals(apsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.APS);
    }
    else if (actionEvent.getSource().equals(propulsionSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.PROPULSION);
    }
    filterSystemSubGrid.setVisible(false);
  }

  private void updateAppliedSystemFilterText(int systemId)
  {
    filterSystemBtn.setText(ActiveFaultsSystemFilterEnum.valueOf(systemId).getAppliedFilterString());
    if (systemId == ActiveFaultsSystemFilterEnum.ANY.getSysFilterId())
    {
      systemFilterButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else
    {
      systemFilterButtonProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
    this.systemFilterId = systemId;
    updateFilterButtonProperty();
  }

  @FXML
  void onFilterCarSubOptionsButtonAction(ActionEvent actionEvent)
  {
    if (actionEvent.getSource().equals(anyCarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.ANY);
    }
    else if (actionEvent.getSource().equals(dm1CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.DM1);
    }
    else if (actionEvent.getSource().equals(t2CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.T2);
    }
    else if (actionEvent.getSource().equals(m3CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.M3);
    }
    else if (actionEvent.getSource().equals(m4CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.M4);
    }
    else if (actionEvent.getSource().equals(t5CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.T5);
    }
    else if (actionEvent.getSource().equals(dm6CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.DM6);
    }
    filterCarSubGrid.setVisible(false);
  }

  private void updateAppliedCarFilterText(int carFilterId)
  {
    filterCarBtn.setText(ActiveFaultsCarFilterEnum.valueOf(carFilterId).getAppliedFilterString());
    if (carFilterId == ActiveFaultsCarFilterEnum.ANY.getCarFilterId())
    {
      carFilterButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else
    {
      carFilterButtonProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);

    }
    this.carFilterId = carFilterId;
    updateFilterButtonProperty();
  }

  @FXML
  void onFilterPrioritySubOptionsButtonAction(ActionEvent actionEvent)
  {
    if (actionEvent.getSource().equals(anyPriorityFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.ANY);
    }
    else if (actionEvent.getSource().equals(priority1FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_1);
    }
    else if (actionEvent.getSource().equals(priority2FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_2);
    }
    else if (actionEvent.getSource().equals(priority3FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_3);
    }
    else if (actionEvent.getSource().equals(priority4FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_4);
    }
    else if (actionEvent.getSource().equals(priority5FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendActiveFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_5);
    }
    filterPrioritySubGrid.setVisible(false);
  }

  private void updateAppliedPriorityFilterText(int priorityFilterId)
  {
    filterPriorityBtn
        .setText(ActiveFaultsPriorityFilterEnum.valueOf(priorityFilterId).getAppliedFilterString());
    if (priorityFilterId == ActiveFaultsPriorityFilterEnum.ANY.getPriorityFilterId())
    {
      priorityFilterButtonProperty.set(TCMSUIConstants.UNSELECTED_PSEUDO_CLASS);
    }
    else
    {
      priorityFilterButtonProperty.set(TCMSUIConstants.SELECTED_PSEUDO_CLASS);
    }
    this.priorityFilterId = priorityFilterId;
    updateFilterButtonProperty();
  }
}
