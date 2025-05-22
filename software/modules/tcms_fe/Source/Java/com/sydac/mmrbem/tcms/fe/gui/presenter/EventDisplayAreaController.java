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

import static com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs.EVENT_ACKNOWLEDGE_BUTTON;

import com.sydac.mmrbem.cabscreens.fe.base.CommsNumber;
import com.sydac.mmrbem.tcms.common.ScreenId;
import com.sydac.mmrbem.tcms.common.state.FaultsPriorityEnum;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.EventDisplayAreaPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.EventDisplayAreaModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.GridPane;

public class EventDisplayAreaController extends AbstractTCMSController
{

  @FXML
  @CommsNumber(EVENT_ACKNOWLEDGE_BUTTON)
  private Button ackBtn;

  @FXML
  private GridPane eventDisplayAreaGrid;

  @FXML
  private Label carCodeLbl;

  @FXML
  private Label faultCodeLbl;

  @FXML
  private Label faultSystemLbl;

  @FXML
  private Label faultDescriptionLbl;

  private EventDisplayAreaModel eventDisplayAreaModel;

  private ChangeListener<Number> priorityListener;

  private ChangeListener<Boolean> eventAvailableListener;

  private static final String PRIORITY_CSS = "event-display-area-label-"; //$NON-NLS-1$

  @Override
  public void detachListeners()
  {
    eventDisplayAreaModel.getFaultPriority().removeListener(priorityListener);
    eventDisplayAreaModel.getFirstFaultInfo().removeListener(eventAvailableListener);
  }

  @Override
  public void initializeImpl()
  {
    eventDisplayAreaModel = new EventDisplayAreaModel(scenarioCarIndex);
    tcmsScreenBinders.add(new EventDisplayAreaPanelBinder(eventDisplayAreaModel));

    setEventDisplayAreaGridVisile();

    carCodeLbl.textProperty().bind(eventDisplayAreaModel.getFaultCar());
    faultCodeLbl.textProperty().bind(eventDisplayAreaModel.getFaultCode());
    faultSystemLbl.textProperty().bind(eventDisplayAreaModel.getFaultSystem());
    faultDescriptionLbl.textProperty().bind(eventDisplayAreaModel.getFaultDescription());

    priorityListener = (observable, oldVal,
        newVal) -> updatePriorityCss(eventDisplayAreaModel.getFaultPriority().getValue());
    eventDisplayAreaModel.getFaultPriority().addListener(priorityListener);

    eventAvailableListener = (observable, oldVal, newVal) -> setEventDisplayAreaGridVisile();
    eventDisplayAreaModel.getFirstFaultInfo().addListener(eventAvailableListener);

    updatePriorityCss(eventDisplayAreaModel.getFaultPriority().get());
  }

  private void setEventDisplayAreaGridVisile()
  {
    eventDisplayAreaGrid.setVisible(eventDisplayAreaModel.getFirstFaultInfo().get());
  }

  private void updatePriorityCss(int priorityId)
  {
    carCodeLbl.getStyleClass().clear();
    faultCodeLbl.getStyleClass().clear();
    faultSystemLbl.getStyleClass().clear();
    faultDescriptionLbl.getStyleClass().clear();
    if (priorityId != 0 && priorityId <= 2)
    {
      carCodeLbl.getStyleClass()
          .add(PRIORITY_CSS + FaultsPriorityEnum.valueOf(priorityId).getPriorityCssName());
      faultCodeLbl.getStyleClass()
          .add(PRIORITY_CSS + FaultsPriorityEnum.valueOf(priorityId).getPriorityCssName());
      faultSystemLbl.getStyleClass()
          .add(PRIORITY_CSS + FaultsPriorityEnum.valueOf(priorityId).getPriorityCssName());
      faultDescriptionLbl.getStyleClass()
          .add(PRIORITY_CSS + FaultsPriorityEnum.valueOf(priorityId).getPriorityCssName());
    }
    else if (priorityId == 3)
    {
      carCodeLbl.getStyleClass().add(PRIORITY_CSS + FaultsPriorityEnum.ANY_PRIORITY.getPriorityCssName());
      faultCodeLbl.getStyleClass().add(PRIORITY_CSS + FaultsPriorityEnum.ANY_PRIORITY.getPriorityCssName());
      faultSystemLbl.getStyleClass().add(PRIORITY_CSS + FaultsPriorityEnum.ANY_PRIORITY.getPriorityCssName());
      faultDescriptionLbl.getStyleClass()
          .add(PRIORITY_CSS + FaultsPriorityEnum.ANY_PRIORITY.getPriorityCssName());
    }
  }

  @FXML
  void onAckButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendEventIdAcknowledged(
        Integer.valueOf(eventDisplayAreaModel.getIncomingFaultsList().get(0).getFaultCode().get()));
  }

  @FXML
  private void onEventDisplayAreaMouseClicked(MouseEvent event)
  {
    sendFaultDetailReq();
  }

  @FXML
  private void onEventDisplayAreaTouchPressed(MouseEvent event)
  {
    sendFaultDetailReq();
  }

  public void sendFaultDetailReq()
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendScreenChangeRequest(ScreenId.FAULT_DETAILS_SCREEN, frontend);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendEventAreaFaultDetailRequest(
        Integer.valueOf(eventDisplayAreaModel.getIncomingFaultsList().get(0).getFaultCode().get()));
  }
}
