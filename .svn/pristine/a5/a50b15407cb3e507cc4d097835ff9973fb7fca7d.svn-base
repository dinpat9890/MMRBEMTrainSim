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

import java.io.IOException;
import java.util.Objects;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.PantographStatusList.Pantograph;
import com.sydac.mmrbem.tcms.common.proto.TCMSProto.CIStatusList.CIState;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;

import com.sydac.mmrbem.tcms.fe.gui.model.HighVoltageScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.property.ObjectPropertyBase;
import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class HVCommandDMRearCarController extends AbstractTCMSController
{

  @FXML
  private Button riseSelectedBtn;

  @FXML
  private Button pantoLowerAllBtn;

  @FXML
  private Button openVcbBtn;

  @FXML
  private Button closeVcbBtn;

  @FXML
  private Button isolateCiBtn;

  private NodePseudoClassProperty openVcbButtonProperty;

  private NodePseudoClassProperty closeVcbButtonProperty;

  private NodePseudoClassProperty riseSelectedButtonProperty;

  private NodePseudoClassProperty pantoLowerAllButtonProperty;

  private NodePseudoClassProperty isolateCiButtonProperty;

  private ObjectPropertyBase<CarComponentStatesDO> ciState;

  private ChangeListener<Boolean> openVcbButtonStateListener;

  private ChangeListener<Boolean> closeVcbButtonStateListener;

  private ChangeListener<Number> riseSelectedButtonStateListener;

  private ChangeListener<Number> pantoLowButtonStateListener;

  private ChangeListener<Number> islolateListener;

  private HighVoltageScreenModel highVoltageScreenModel;



  private int carIndex;

  private boolean pantoSelected;

  public HVCommandDMRearCarController(CarConfigurationModel carConfig,
      HighVoltageScreenModel highVoltageScreenModel
     
      )
  {
    this.highVoltageScreenModel = highVoltageScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
   
    pantoSelected = false;
  }

  @Override
  public void initializeImpl()
  {
    ciState = highVoltageScreenModel.ciStatusProperty(carIndex);
    ciState.addListener(observable -> ciIsolateStateUpdate());
    ciIsolateStateUpdate();

    openVcbButtonProperty = new NodePseudoClassProperty(openVcbBtn);
    closeVcbButtonProperty = new NodePseudoClassProperty(closeVcbBtn);
    riseSelectedButtonProperty = new NodePseudoClassProperty(riseSelectedBtn);
    pantoLowerAllButtonProperty = new NodePseudoClassProperty(pantoLowerAllBtn);
    isolateCiButtonProperty = new NodePseudoClassProperty(isolateCiBtn);
    openVcbButtonStateListener = (observable, oldVal,
        newVal) -> openVcbButtonStateUpdate(newVal.booleanValue());
    highVoltageScreenModel.getOpenVcbState().addListener(openVcbButtonStateListener);

    closeVcbButtonStateListener = (observable, oldVal,
        newVal) -> closeVcbButtonStateUpdate(newVal.booleanValue());
    highVoltageScreenModel.getCloseVcbState().addListener(closeVcbButtonStateListener);

    pantoLowButtonStateListener = (observable, oldVal, newVal) -> updatePantoLowAllCar(newVal.intValue());
    highVoltageScreenModel.getPantoLowAllCarstate().addListener(pantoLowButtonStateListener);

    riseSelectedButtonStateListener = (observable, oldVal,
        newVal) -> riseSelectedButtonStateUpdate(newVal.intValue());
    highVoltageScreenModel.getRiseSelectedState().addListener(riseSelectedButtonStateListener);

    islolateListener = (observable, oldVal, newVal) -> updateIsolateCi(newVal.intValue());
    highVoltageScreenModel.getIsolateCiRearCarState().addListener(islolateListener);

    openVcbButtonStateUpdate(highVoltageScreenModel.getOpenVcbState().get());
    closeVcbButtonStateUpdate(highVoltageScreenModel.getCloseVcbState().get());
    riseSelectedButtonStateUpdate(highVoltageScreenModel.getRiseSelectedState().get());
    // updatePantoLowAllCar(highVoltageScreenModel.getPantoLowAllCarstate().get());

    if (carIndex == TCMSConstants.CAB_7)
    {
      ObjectPropertyBase<CarComponentStatesDO> pantoState1 = highVoltageScreenModel
          .pantographStatusProperty(TCMSConstants.CAB_1);
      pantoState1.addListener(observable -> pantoRaisedStateUpdate(pantoState1));
      ObjectPropertyBase<CarComponentStatesDO> pantoState2 = highVoltageScreenModel
          .pantographStatusProperty(TCMSConstants.CAB_3);
      pantoState2.addListener(observable -> pantoRaisedStateUpdate(pantoState2));
      ObjectPropertyBase<CarComponentStatesDO> pantoState3 = highVoltageScreenModel
          .pantographStatusProperty(TCMSConstants.CAB_6);
      pantoState3.addListener(observable -> pantoRaisedStateUpdate(pantoState3));
    }
    else
    {

      ObjectPropertyBase<CarComponentStatesDO> pantoState4 = highVoltageScreenModel
          .pantographStatusProperty(TCMSConstants.CAB_1);
      pantoState4.addListener(observable -> pantoRaisedStateUpdate(pantoState4));

      ObjectPropertyBase<CarComponentStatesDO> pantoState5 = highVoltageScreenModel
          .pantographStatusProperty(TCMSConstants.CAB_4);
      pantoState5.addListener(observable -> pantoRaisedStateUpdate(pantoState5));
    }

    if (carIndex == TCMSConstants.CAB_5)
    {
      ObjectPropertyBase<CarComponentStatesDO> vcbState = highVoltageScreenModel
          .vcbStatusProperty(TCMSConstants.CAB_3);
      vcbState.addListener(observable -> vcbStatusUpdated());
    }
    else
    {
      ObjectPropertyBase<CarComponentStatesDO> vcbState2 = highVoltageScreenModel
          .vcbStatusProperty(TCMSConstants.CAB_6);
      vcbState2.addListener(observable -> vcbStatusUpdated());
    }
  }

  private void updateIsolateCi(int isolateState)
  {
    if (isolateState == 1)
    {
      isolateCiButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      isolateCiButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
  }

  private void updatePantoLowAllCar(int pantoState)
  {
    if (pantoState == 1)
    {
      pantoLowerAllButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      pantoLowerAllButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
  }

  private void vcbStatusUpdated()
  {
    openVcbButtonStateUpdate(highVoltageScreenModel.getOpenVcbState().get());
    closeVcbButtonStateUpdate(highVoltageScreenModel.getCloseVcbState().get());
  }

  private void openVcbButtonStateUpdate(boolean openVcbActive)
  {
    if (openVcbActive)
    {
      closeVcbButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
    else
    {
      closeVcbButtonProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
    }
  }

  private void closeVcbButtonStateUpdate(boolean closeVcbActive)
  {
    if (closeVcbActive)
    {
      openVcbButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
    else
    {
      openVcbButtonProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
    }
  }

  private void riseSelectedButtonStateUpdate(int pantoSelected)
  {
    if (pantoSelected == 1)
    {
      riseSelectedButtonProperty.set(TCMSUIConstants.COMMAND_AVAILABLE_CSS);
    }
    else if (pantoSelected == 2)
    {
      riseSelectedButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
    }
    else
    {
      riseSelectedButtonProperty.set(TCMSUIConstants.COMMAND_NOT_AVAILABLE_CSS);
    }
  }

  private void ciIsolateStateUpdate()
  {
    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      isolateCiBtn.setText(TCMSUIConstants.DE_ISOLATE_CI_TXT);
    }
    else
    {
      isolateCiBtn.setText(TCMSUIConstants.ISOLATE_CI_TXT);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void riseSelectedButtonAction(ActionEvent event)
  {
    

    if (highVoltageScreenModel.getRiseSelectedState().get() != 1
        || highVoltageScreenModel.getRiseSelectedState().get() != 2)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendHVCommandDelayReq(VDUInputs.RISE_SELECTED_PANTO_REQ, 2, 1);

    }

  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void pantoLowerAllButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.LOWER_ALL_PANTO_REQ);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.PANTO_BUTTON_LEFT_REQ, 0);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.PANTO_BUTTON_RIGHT_REQ, 0);
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.PANTO_BUTTON_MIDDLE_REQ, 0);

  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void openVcbButtonAction(ActionEvent event)
  {
    if (highVoltageScreenModel.getCloseVcbState().get())
    {
      openVcbButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.OPEN_VCB_REQ);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void closeVcbButtonAction(ActionEvent event)
  {
    if (highVoltageScreenModel.getOpenVcbState().get() && pantoSelected)
    {
      closeVcbButtonProperty.set(TCMSUIConstants.COMMAND_SELECTED_CSS);
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendButtonClickRequest(VDUInputs.CLOSE_VCB_REQ);
    }
  }

  /**
   * @param event
   *          unused
   */
  @FXML
  private void isolateCiButtonAction(ActionEvent event)
  {
    if (Objects.equals(ciState.get().getComponentState(), CIState.CI_ISOLATED.toString().toLowerCase()))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_CI_REQ, 0);
    }
    else
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.ISOLATE_CI_REQ, 1);
    }
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendHVCommandReq(VDUInputs.ISOLATE_CI_REQ_CAR,
        carIndex);

    TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
        .sendButtonClickRequest(VDUInputs.ISOLATE_CI_REAR_CAR_REQ);

  }

  @Override
  public void detachListeners()
  {
    highVoltageScreenModel.getCloseVcbState().removeListener(closeVcbButtonStateListener);
    highVoltageScreenModel.getOpenVcbState().removeListener(openVcbButtonStateListener);
    highVoltageScreenModel.getRiseSelectedState().removeListener(riseSelectedButtonStateListener);
  }

  public GridPane createCar(String fxmlName)
  {
    GridPane gridPane;
    FXMLLoader fxmlLoader = new FXMLLoader(ViewPackage.class.getResource(fxmlName));
    fxmlLoader.setController(this);
    try
    {
      gridPane = fxmlLoader.load();
    }
    catch (IOException exception)
    {
      logger.error(exception);
      throw new LoadingException(exception);
    }
    return gridPane;
  }

  private void pantoRaisedStateUpdate(ObjectPropertyBase<CarComponentStatesDO> pantoState)
  {

    if (Objects.equals(pantoState.get().getComponentState(), Pantograph.RAISED.toString().toLowerCase()))
    {
      pantoSelected = true;
    }
    else
    {
      pantoSelected = false;
    }
  }
}
