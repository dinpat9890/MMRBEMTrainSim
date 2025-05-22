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

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.common.state.PecuCallStatus;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.PISSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class PISSystemTRightCarController extends AbstractTCMSController
{

  @FXML
  private Label pecuLbl1;

  @FXML
  private Label pecuLbl2;

  @FXML
  private Label pecuLbl3;

  @FXML
  private Label pecuLbl4;

  @FXML
  private Button pecuResetButton1;

  @FXML
  private Button pecuResetButton2;

  @FXML
  private Button pecuResetButton3;

  @FXML
  private Button pecuResetButton4;

  @FXML
  private Label paborLbl;

  @FXML
  private Label pabrLbl;

  private PISSystemScreenModel pisSystemScreenModel;

  private int carIndex;

  private NodePseudoClassProperty pecuLbl1Property;

  private NodePseudoClassProperty pecuLbl2Property;

  private NodePseudoClassProperty pecuLbl3Property;

  private NodePseudoClassProperty pecuLbl4Property;

  private NodePseudoClassProperty pecuResetButton1Property;

  private NodePseudoClassProperty pecuResetButton2Property;

  private NodePseudoClassProperty pecuResetButton3Property;

  private NodePseudoClassProperty pecuResetButton4Property;

  private ChangeListener<Number> callStatusListener;

  private ChangeListener<Number> callIdListener;

  private ChangeListener<Number> callVehicleIndexListener;

  private CarConfigurationModel carConfig;

  public PISSystemTRightCarController(CarConfigurationModel carConfig,
      PISSystemScreenModel pisSystemScreenModel, String carLabel, int index)
  {
    this.pisSystemScreenModel = pisSystemScreenModel;
    this.carIndex = index;
    this.carConfig = carConfig;

  }

  @Override
  public void initializeImpl()
  {

    showLabels();
    pecuLbl1Property = new NodePseudoClassProperty(pecuLbl1);
    pecuLbl2Property = new NodePseudoClassProperty(pecuLbl2);
    pecuLbl3Property = new NodePseudoClassProperty(pecuLbl3);
    pecuLbl4Property = new NodePseudoClassProperty(pecuLbl4);

    pecuLbl1.setText((PecuCallStatus.CALL_NORMAL).getButtonText() + " 1");
    pecuLbl2.setText((PecuCallStatus.CALL_NORMAL).getButtonText() + " 2");
    pecuLbl3.setText((PecuCallStatus.CALL_NORMAL).getButtonText() + " 3");
    pecuLbl4.setText((PecuCallStatus.CALL_NORMAL).getButtonText() + " 4");

    pecuResetButton1.setDisable(Boolean.TRUE);
    pecuResetButton2.setDisable(Boolean.TRUE);
    pecuResetButton3.setDisable(Boolean.TRUE);
    pecuResetButton4.setDisable(Boolean.TRUE);

    pecuResetButton1Property = new NodePseudoClassProperty(pecuResetButton1);
    pecuResetButton2Property = new NodePseudoClassProperty(pecuResetButton2);
    pecuResetButton3Property = new NodePseudoClassProperty(pecuResetButton3);
    pecuResetButton4Property = new NodePseudoClassProperty(pecuResetButton4);

    callIdListener = (observable, oldVal, newVal) -> {

      updateCallId();
    };
    pisSystemScreenModel.getPecuCallId().addListener(callIdListener);

    callVehicleIndexListener = (observable, oldVal, newVal) -> {

      updateCallId();
    };
    pisSystemScreenModel.getPecuCallVehicleIndex().addListener(callVehicleIndexListener);

    callStatusListener = (observable, oldVal, newVal) -> updateCallId();
    pisSystemScreenModel.getPecuCallStatus().addListener(callStatusListener);

    // updateVehicleIndex();

  }

  private void showLabels()
  {
    CarType carType = CarType.valueByCarTypeCode(carConfig.carTypeProperty().get());

    if (carType == CarType.DM)
    {

      paborLbl.setVisible(true);
      pabrLbl.setVisible(true);
    }
    else
    {
      paborLbl.setVisible(false);
      pabrLbl.setVisible(false);
    }
  }

  private void updateCallStatus1()
  {

    if (pisSystemScreenModel.getPecuCallId().get() == 1)
    {
      pecuLbl1Property.set(PecuCallStatus.valueOf(pisSystemScreenModel.getPecuCallStatus().get()).getCss());
      pecuLbl1.setText(
          PecuCallStatus.valueOf(pisSystemScreenModel.getPecuCallStatus().get()).getButtonText() + " 1");

      if (pisSystemScreenModel.getPecuCallStatus().get() == PecuCallStatus.CALL_ONGOING.getValue())
      {
        pecuResetButton1.setDisable(Boolean.FALSE);
        pecuResetButton1Property.set(PecuCallStatus.CALL_RESET.getCss());
        pecuResetButton1.setText(PecuCallStatus.CALL_RESET.getButtonText() + " 1");
      }
      else
      {
        pecuResetButton1.setDisable(Boolean.TRUE);
        pecuResetButton1Property.set(PecuCallStatus.CALL_RESET_DISABLE.getCss());

      }
    }

  }

  private void resetAllComps()
  {

    pecuLbl1Property.set((PecuCallStatus.CALL_NORMAL).getCss());
    pecuLbl2Property.set((PecuCallStatus.CALL_NORMAL).getCss());
    pecuLbl3Property.set((PecuCallStatus.CALL_NORMAL).getCss());
    pecuLbl4Property.set((PecuCallStatus.CALL_NORMAL).getCss());

    pecuLbl1.setText((PecuCallStatus.CALL_NORMAL).getButtonText() + " 1");
    pecuLbl2.setText((PecuCallStatus.CALL_NORMAL).getButtonText() + " 2");
    pecuLbl3.setText((PecuCallStatus.CALL_NORMAL).getButtonText() + " 3");
    pecuLbl4.setText((PecuCallStatus.CALL_NORMAL).getButtonText() + " 4");

    pecuResetButton1.setDisable(Boolean.TRUE);
    pecuResetButton1Property.set(PecuCallStatus.CALL_RESET_DISABLE.getCss());

    pecuResetButton1.setText((PecuCallStatus.CALL_RESET_DISABLE).getButtonText() + " 1");
    pecuResetButton2.setText((PecuCallStatus.CALL_RESET_DISABLE).getButtonText() + " 2");
    pecuResetButton3.setText((PecuCallStatus.CALL_RESET_DISABLE).getButtonText() + " 3");
    pecuResetButton4.setText((PecuCallStatus.CALL_RESET_DISABLE).getButtonText() + " 4");

    pecuResetButton2.setDisable(Boolean.TRUE);
    pecuResetButton2Property.set(PecuCallStatus.CALL_RESET_DISABLE.getCss());

    pecuResetButton3.setDisable(Boolean.TRUE);
    pecuResetButton3Property.set(PecuCallStatus.CALL_RESET_DISABLE.getCss());

    pecuResetButton4.setDisable(Boolean.TRUE);
    pecuResetButton4Property.set(PecuCallStatus.CALL_RESET_DISABLE.getCss());

  }

  private void updateCallId()
  {

    if (pisSystemScreenModel.getPecuCallVehicleIndex().get() == carIndex)
    {
      if (pisSystemScreenModel.getPecuCallId().get() == 1)
      {
        updateCallStatus1();
      }
      else if (pisSystemScreenModel.getPecuCallId().get() == 2)
      {
        updateCallStatus2();

      }
      else if (pisSystemScreenModel.getPecuCallId().get() == 3)
      {
        updateCallStatus3();

      }
      else if (pisSystemScreenModel.getPecuCallId().get() == 4)
      {
        updateCallStatus4();

      }
    }
    else
    {
      resetAllComps();
    }

  }

  private void updateCallStatus2()
  {

    if (pisSystemScreenModel.getPecuCallId().get() == 2)
    {
      pecuLbl2Property.set(PecuCallStatus.valueOf(pisSystemScreenModel.getPecuCallStatus().get()).getCss());
      pecuLbl2.setText(
          PecuCallStatus.valueOf(pisSystemScreenModel.getPecuCallStatus().get()).getButtonText() + " 2");
      if (pisSystemScreenModel.getPecuCallStatus().get() == PecuCallStatus.CALL_ONGOING.getValue())
      {
        pecuResetButton2.setDisable(Boolean.FALSE);
        pecuResetButton2Property.set(PecuCallStatus.CALL_RESET.getCss());
        pecuResetButton2.setText(PecuCallStatus.CALL_RESET.getButtonText() + " 2");
      }
      else
      {
        pecuResetButton2.setDisable(Boolean.TRUE);
        pecuResetButton2Property.set(PecuCallStatus.CALL_RESET_DISABLE.getCss());
      }

    }

  }

  private void updateCallStatus4()
  {

    if (pisSystemScreenModel.getPecuCallId().get() == 4)
    {
      pecuLbl4Property.set(PecuCallStatus.valueOf(pisSystemScreenModel.getPecuCallStatus().get()).getCss());
      pecuLbl4.setText(
          PecuCallStatus.valueOf(pisSystemScreenModel.getPecuCallStatus().get()).getButtonText() + " 4");
      if (pisSystemScreenModel.getPecuCallStatus().get() == PecuCallStatus.CALL_ONGOING.getValue())
      {
        pecuResetButton4.setDisable(Boolean.FALSE);
        pecuResetButton4Property.set(PecuCallStatus.CALL_RESET.getCss());
        pecuResetButton4.setText(PecuCallStatus.CALL_RESET.getButtonText() + " 4");
      }
      else
      {
        pecuResetButton4.setDisable(Boolean.TRUE);
        pecuResetButton4Property.set(PecuCallStatus.CALL_RESET_DISABLE.getCss());
      }

    }

  }

  private void updateCallStatus3()
  {

    if (pisSystemScreenModel.getPecuCallId().get() == 3)
    {
      pecuLbl3Property.set(PecuCallStatus.valueOf(pisSystemScreenModel.getPecuCallStatus().get()).getCss());
      pecuLbl3.setText(
          PecuCallStatus.valueOf(pisSystemScreenModel.getPecuCallStatus().get()).getButtonText() + " 3");

      if (pisSystemScreenModel.getPecuCallStatus().get() == PecuCallStatus.CALL_ONGOING.getValue())
      {
        pecuResetButton3.setDisable(Boolean.FALSE);
        pecuResetButton3Property.set(PecuCallStatus.CALL_RESET.getCss());
        pecuResetButton3.setText(PecuCallStatus.CALL_RESET.getButtonText() + " 3");
      }
      else
      {
        pecuResetButton3.setDisable(Boolean.TRUE);
        pecuResetButton3Property.set(PecuCallStatus.CALL_RESET_DISABLE.getCss());
      }

    }

  }

  @Override
  public void detachListeners()
  {
    // To Detach Listeners
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

  @FXML
  void onResetButtonAction(ActionEvent event)
  {
    if ((event.getSource().equals(pecuResetButton1)) || (event.getSource().equals(pecuResetButton2))
        || (event.getSource().equals(pecuResetButton3)) || (event.getSource().equals(pecuResetButton4)))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendButtonClickRequest(VDUInputs.PECU_RESET_REQ_BUTTON);
    }

  }
}
