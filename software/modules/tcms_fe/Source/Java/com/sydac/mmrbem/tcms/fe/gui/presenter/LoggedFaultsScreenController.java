/*
 * ==================================================================
 * 
 * (C) Copyright 2023 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_ANY_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_ANY_PRIORITY_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_ANY_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_APS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_ATC_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_BCG_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_BRAKES_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_CCTV_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_DM1_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_DM6_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_DOORS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_FDS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_HVAC_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_HV_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_LIGHTS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_LV_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_M3_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_M4_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_MV_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PAGE_DOWN_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PAGE_UP_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PAPIS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PRIORITY_1_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PRIORITY_2_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PRIORITY_3_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PRIORITY_4_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PRIORITY_5_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PRIORITY_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_PROP_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_T2_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_T5_CAR_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_TCMS_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_TR_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_VEHICLE_SYSTEM_FILTER_BUTTON;
import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.LOGGED_FAULTS_WFL_SYSTEM_FILTER_BUTTON;

import com.sydac.gui.control.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsCarFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsPriorityFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ActiveFaultsSystemFilterEnum;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.LoggedFaultsScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.data.LoggedFaultsTableDO;
import com.sydac.mmrbem.tcms.fe.gui.model.LoggedFaultsScreenModel;

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

public class LoggedFaultsScreenController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(LOGGED_FAULTS_PAGE_UP_BUTTON)
  private Button pageUpBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PAGE_DOWN_BUTTON)
  private Button pageDownBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_FILTER_BUTTON)
  private Button filterLoggedFaultsBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_SYSTEM_FILTER_BUTTON)
  private Button filterSystemBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_CAR_FILTER_BUTTON)
  private Button filterCarBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PRIORITY_FILTER_BUTTON)
  private Button filterPriorityBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_ANY_SYSTEM_FILTER_BUTTON)
  private Button anySysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_ATC_SYSTEM_FILTER_BUTTON)
  private Button atcSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_VEHICLE_SYSTEM_FILTER_BUTTON)
  private Button vehicleSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PAPIS_SYSTEM_FILTER_BUTTON)
  private Button papisSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_HV_SYSTEM_FILTER_BUTTON)
  private Button hvSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_FDS_SYSTEM_FILTER_BUTTON)
  private Button fdsSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_MV_SYSTEM_FILTER_BUTTON)
  private Button mvSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_LV_SYSTEM_FILTER_BUTTON)
  private Button lvSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_CCTV_SYSTEM_FILTER_BUTTON)
  private Button cctvSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_TR_SYSTEM_FILTER_BUTTON)
  private Button trSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_TCMS_SYSTEM_FILTER_BUTTON)
  private Button tcmsSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_WFL_SYSTEM_FILTER_BUTTON)
  private Button wflSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_HVAC_SYSTEM_FILTER_BUTTON)
  private Button hvacSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_BCG_SYSTEM_FILTER_BUTTON)
  private Button bcgSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_BRAKES_SYSTEM_FILTER_BUTTON)
  private Button brakesSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_APS_SYSTEM_FILTER_BUTTON)
  private Button apsSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_DOORS_SYSTEM_FILTER_BUTTON)
  private Button doorsSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_LIGHTS_SYSTEM_FILTER_BUTTON)
  private Button lightsSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PROP_SYSTEM_FILTER_BUTTON)
  private Button propulsionSysFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_ANY_CAR_FILTER_BUTTON)
  private Button anyCarFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_DM1_CAR_FILTER_BUTTON)
  private Button dm1CarFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_T2_CAR_FILTER_BUTTON)
  private Button t2CarFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_M3_CAR_FILTER_BUTTON)
  private Button m3CarFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_M4_CAR_FILTER_BUTTON)
  private Button m4CarFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_T5_CAR_FILTER_BUTTON)
  private Button t5CarFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_DM6_CAR_FILTER_BUTTON)
  private Button dm6CarFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_ANY_PRIORITY_FILTER_BUTTON)
  private Button anyPriorityFilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PRIORITY_1_FILTER_BUTTON)
  private Button priority1FilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PRIORITY_2_FILTER_BUTTON)
  private Button priority2FilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PRIORITY_3_FILTER_BUTTON)
  private Button priority3FilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PRIORITY_4_FILTER_BUTTON)
  private Button priority4FilterBtn;

  @FXML
  @CommsNumber(LOGGED_FAULTS_PRIORITY_5_FILTER_BUTTON)
  private Button priority5FilterBtn;

  @FXML
  private TableView<LoggedFaultsTableDO> loggedFaultsTableView;

  @FXML
  private GridPane loggedFaultsMainGrid;

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

  private ChangeListener<? super ObservableList<LoggedFaultsTableDO>> faultsListListener;

  private ChangeListener<Number> pageUpBtnActiveListener;

  private ChangeListener<Number> pageDownBtnActiveListener;

  private ChangeListener<Number> systemFilterListener;

  private ChangeListener<Number> carFilterListener;

  private ChangeListener<Number> priorityFilterListener;

  private LoggedFaultsScreenModel loggedFaultsScreenModel;

  private NodePseudoClassProperty filterButtonProperty;

  private NodePseudoClassProperty systemFilterButtonProperty;

  private NodePseudoClassProperty carFilterButtonProperty;

  private NodePseudoClassProperty priorityFilterButtonProperty;

  private NodePseudoClassProperty pageUpButtonProperty;

  private NodePseudoClassProperty pageDownButtonProperty;

  private int systemFilterId = ActiveFaultsSystemFilterEnum.ANY.getSysFilterId();

  private int carFilterId = ActiveFaultsCarFilterEnum.ANY.getCarFilterId();

  private int priorityFilterId = ActiveFaultsPriorityFilterEnum.ANY.getPriorityFilterId();

  @Override
  public void detachListeners()
  {
    loggedFaultsScreenModel.getCurrentPageNumber().removeListener(currentPageListener);
    loggedFaultsScreenModel.getTotalPageNumber().removeListener(totalPagesListener);
    loggedFaultsScreenModel.getTotalActiveFaults().removeListener(totalActiveFaultsListener);
    loggedFaultsScreenModel.getFaultListUpdateAvailable().removeListener(faultListUpdateListener);
    loggedFaultsScreenModel.getLoggedFaultsList().removeListener(faultsListListener);
    loggedFaultsScreenModel.getPageUpActive().removeListener(pageUpBtnActiveListener);
    loggedFaultsScreenModel.getPageDownActive().removeListener(pageDownBtnActiveListener);
    loggedFaultsScreenModel.getAppliedSystemFilterId().removeListener(systemFilterListener);
    loggedFaultsScreenModel.getAppliedCarFilterId().removeListener(carFilterListener);
    loggedFaultsScreenModel.getAppliedPriorityFilterId().removeListener(priorityFilterListener);
  }

  @Override
  public void initializeImpl()
  {
    loggedFaultsScreenModel = new LoggedFaultsScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new LoggedFaultsScreenBinder(loggedFaultsScreenModel));

    loggedFaultsMainGrid.setVisible(true);
    filterOptionsGrid.setVisible(false);
    filterSystemSubGrid.setVisible(false);
    filterCarSubGrid.setVisible(false);
    filterPrioritySubGrid.setVisible(false);

    filterButtonProperty = new NodePseudoClassProperty(filterLoggedFaultsBtn);
    systemFilterButtonProperty = new NodePseudoClassProperty(filterSystemBtn);
    carFilterButtonProperty = new NodePseudoClassProperty(filterCarBtn);
    priorityFilterButtonProperty = new NodePseudoClassProperty(filterPriorityBtn);
    pageUpButtonProperty = new NodePseudoClassProperty(pageUpBtn);
    pageDownButtonProperty = new NodePseudoClassProperty(pageDownBtn);

    currentPageListener = (observable, oldVal, newVal) -> updateFaultCountsDisplayLabel();
    loggedFaultsScreenModel.getCurrentPageNumber().addListener(currentPageListener);

    totalPagesListener = (observable, oldVal, newVal) -> updateFaultCountsDisplayLabel();
    loggedFaultsScreenModel.getTotalPageNumber().addListener(totalPagesListener);

    pageUpBtnActiveListener = (observable, oldVal, newVal) -> updatePageUpBtnActive(newVal.intValue());
    loggedFaultsScreenModel.getPageUpActive().addListener(pageUpBtnActiveListener);

    pageDownBtnActiveListener = (observable, oldVal, newVal) -> updatePageDownBtnActive(newVal.intValue());
    loggedFaultsScreenModel.getPageDownActive().addListener(pageDownBtnActiveListener);

    systemFilterListener = (observable, oldVal, newVal) -> updateAppliedSystemFilterText(newVal.intValue());
    loggedFaultsScreenModel.getAppliedSystemFilterId().addListener(systemFilterListener);

    carFilterListener = (observable, oldVal, newVal) -> updateAppliedCarFilterText(newVal.intValue());
    loggedFaultsScreenModel.getAppliedCarFilterId().addListener(carFilterListener);

    priorityFilterListener = (observable, oldVal,
        newVal) -> updateAppliedPriorityFilterText(newVal.intValue());
    loggedFaultsScreenModel.getAppliedPriorityFilterId().addListener(priorityFilterListener);

    totalActiveFaultsListener = (observable, oldVal, newVal) -> updateFaultCountsDisplayLabel();
    loggedFaultsScreenModel.getTotalActiveFaults().addListener(totalActiveFaultsListener);

    faultsListListener = (observable, oldVal,
        newVal) -> setTableProperties(loggedFaultsScreenModel.getLoggedFaultsList());
    loggedFaultsScreenModel.getLoggedFaultsList().addListener(faultsListListener);

    updateFaultCountsDisplayLabel();
    updatePageUpBtnActive(loggedFaultsScreenModel.getPageUpActive().get());
    updatePageDownBtnActive(loggedFaultsScreenModel.getPageDownActive().get());
    updateAppliedSystemFilterText(systemFilterId);
    updateAppliedCarFilterText(carFilterId);
    updateAppliedPriorityFilterText(priorityFilterId);
    setTableProperties(loggedFaultsScreenModel.getLoggedFaultsList());
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

  private void setTableProperties(ListProperty<LoggedFaultsTableDO> eventList)
  {
    if (eventList != null && !eventList.isEmpty())
    {
      loggedFaultsTableView.setVisible(true);
      loggedFaultsTableView.setFixedCellSize(51 * 1.0);
      loggedFaultsTableView.getSelectionModel().setCellSelectionEnabled(false);
      loggedFaultsTableView.setPadding(new Insets(0, 0, 0, 0));

      loggedFaultsTableView.widthProperty().addListener((source, oldWidth, newWidth) -> {
        Pane header = (Pane)loggedFaultsTableView.lookup("TableHeaderRow"); //$NON-NLS-1$
        if (header.isVisible())
        {
          header.setPrefHeight(50);
          header.setVisible(true);
        }
      });

      loggedFaultsTableView.getColumns().add(getColumn("carCode", 100 * 1.0, "CAR")); //$NON-NLS-1$ //$NON-NLS-2$
      loggedFaultsTableView.getColumns().add(getColumn("faultCode", 100 * 1.0, "CODE")); //$NON-NLS-1$ //$NON-NLS-2$
      loggedFaultsTableView.getColumns().add(getColumn("faultOccuranceDateTime", 130 * 1.0, "TIME START")); //$NON-NLS-1$ //$NON-NLS-2$
      loggedFaultsTableView.getColumns().add(getColumn("faultClearanceDateTime", 130 * 1.0, "TIME END")); //$NON-NLS-1$ //$NON-NLS-2$
      loggedFaultsTableView.getColumns().add(getColumn("faultSystemName", 130 * 1.0, "SYSTEM")); //$NON-NLS-1$ //$NON-NLS-2$
      loggedFaultsTableView.getColumns().add(getColumn("faultDescription", 434 * 1.0, "DESCRIPTION")); //$NON-NLS-1$ //$NON-NLS-2$
      loggedFaultsTableView.getColumns().add(getColumn("faultLevel", 0 * 1.0, "PR")); //$NON-NLS-1$ //$NON-NLS-2$

      loggedFaultsTableView.setColumnResizePolicy(TableView.CONSTRAINED_RESIZE_POLICY);

      loggedFaultsTableView.setItems(eventList);

      loggedFaultsTableView.getSelectionModel().selectedIndexProperty()
          .addListener(new RowChangeHandler(loggedFaultsTableView, eventList));
    }
  }

  private class RowChangeHandler implements ChangeListener<Object>
  {
    private ListProperty<LoggedFaultsTableDO> eventList;

    private TableView<LoggedFaultsTableDO> currentEventTable;

    public RowChangeHandler(TableView<LoggedFaultsTableDO> eventTable,
        ListProperty<LoggedFaultsTableDO> eventList)
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
            .sendSelectedLoggedFaultRequest(Integer.valueOf(eventList.get(selectedRow).getFaultCode()));
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

  private TableColumn<LoggedFaultsTableDO, Object> getColumn(String columnName, double width,
      String headerName)
  {
    TableColumn<LoggedFaultsTableDO, Object> column = new TableColumn<>((headerName));
    column.setCellValueFactory(new PropertyValueFactory<>(columnName));

    column.setCellFactory(
        new Callback<TableColumn<LoggedFaultsTableDO, Object>, TableCell<LoggedFaultsTableDO, Object>>() {
          @Override
          public TableCell<LoggedFaultsTableDO, Object> call(TableColumn<LoggedFaultsTableDO, Object> param)
          {
            return new TableCell<LoggedFaultsTableDO, Object>() {
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
    faultCountDisplayLbl.setText("There are " + loggedFaultsScreenModel.getTotalActiveFaults().get() //$NON-NLS-1$
        + " logged faults. (Showing page " + loggedFaultsScreenModel.getCurrentPageNumber().get() + " of " //$NON-NLS-1$ //$NON-NLS-2$
        + loggedFaultsScreenModel.getTotalPageNumber().get() + ")"); //$NON-NLS-1$
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
  void onPageUpActiveFaultsButtonAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendLoggedFaultsPageUpButtonRequest(1);
  }

  @FXML
  void onPageDownActiveFaultsButtonAction()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendLoggedFaultsPageDownButtonRequest(1);
  }

  @FXML
  void onFilterLoggedFaultsButtonAction()
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
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.ANY);
    }
    else if (actionEvent.getSource().equals(vehicleSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.VEHICLE);
    }
    else if (actionEvent.getSource().equals(hvSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.HV);
    }
    else if (actionEvent.getSource().equals(mvSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.MV);
    }
    else if (actionEvent.getSource().equals(lvSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.LV);
    }
    else if (actionEvent.getSource().equals(tcmsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.TCMS);
    }
    else if (actionEvent.getSource().equals(hvacSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.HVAC);
    }
    else if (actionEvent.getSource().equals(brakesSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.BRAKES);
    }
    else if (actionEvent.getSource().equals(doorsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.DOORS);
    }
    else if (actionEvent.getSource().equals(lightsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.LIGHTS);
    }
    else if (actionEvent.getSource().equals(atcSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.ATC);
    }
    else if (actionEvent.getSource().equals(papisSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.PAPIS);
    }
    else if (actionEvent.getSource().equals(fdsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.FDS);
    }
    else if (actionEvent.getSource().equals(cctvSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.CCTV);
    }
    else if (actionEvent.getSource().equals(trSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.TR);
    }
    else if (actionEvent.getSource().equals(wflSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.WFL);
    }
    else if (actionEvent.getSource().equals(bcgSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.BCG);
    }
    else if (actionEvent.getSource().equals(apsSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.APS);
    }
    else if (actionEvent.getSource().equals(propulsionSysFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsSystemFilterRequest(ActiveFaultsSystemFilterEnum.PROPULSION);
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
          .sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.ANY);
    }
    else if (actionEvent.getSource().equals(dm1CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.DM1);
    }
    else if (actionEvent.getSource().equals(t2CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.T2);
    }
    else if (actionEvent.getSource().equals(m3CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.M3);
    }
    else if (actionEvent.getSource().equals(m4CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.M4);
    }
    else if (actionEvent.getSource().equals(t5CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.T5);
    }
    else if (actionEvent.getSource().equals(dm6CarFilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsCarFilterRequest(ActiveFaultsCarFilterEnum.DM6);
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
          .sendLoggedFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.ANY);
    }
    else if (actionEvent.getSource().equals(priority1FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_1);
    }
    else if (actionEvent.getSource().equals(priority2FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_2);
    }
    else if (actionEvent.getSource().equals(priority3FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_3);
    }
    else if (actionEvent.getSource().equals(priority4FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_4);
    }
    else if (actionEvent.getSource().equals(priority5FilterBtn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendLoggedFaultsPriorityFilterRequest(ActiveFaultsPriorityFilterEnum.PRIOPRITY_5);
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
