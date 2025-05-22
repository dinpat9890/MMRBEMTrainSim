package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.LowVoltageScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class LowVoltageMCarController extends AbstractTCMSController
{
  @FXML
  private Label carLbl;

  @FXML
  private Label bcg1Lbl;

  @FXML
  private Label bcg2Lbl;

  @FXML
  private Label bicSwichLbl;

  @FXML
  private Label tccSwitchLbl;

  private String carLblString = ApplicationConstants.BLANK;

  private NodePseudoClassProperty bcg1StateProperty;

  private NodePseudoClassProperty bcg2StateProperty;

  private NodePseudoClassProperty bicSwitchStateProperty;

  private NodePseudoClassProperty tccSwitchStateProperty;

  private ObjectPropertyBase<CarComponentStatesDO> bcg1State;

  private ObjectPropertyBase<CarComponentStatesDO> bcg2State;

  private ObjectPropertyBase<CarComponentStatesDO> bicState;

  private ObjectPropertyBase<CarComponentStatesDO> tccState;

  private LowVoltageScreenModel lowVoltageScreenModel;

  private Integer carIndex;

  public LowVoltageMCarController(LowVoltageScreenModel lowVoltageScreenModel,
      CarConfigurationModel carConfig, String carLabel)
  {
    super();
    this.carLblString = carLabel;
    this.lowVoltageScreenModel = lowVoltageScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
  }

  @Override
  public void detachListeners()
  {
    // To Detach Listeners
  }

  @Override
  public void initializeImpl()
  {
    updatecarLabel(carLblString);

    bcg1StateProperty = new NodePseudoClassProperty(bcg1Lbl);
    bcg2StateProperty = new NodePseudoClassProperty(bcg2Lbl);
    bicSwitchStateProperty = new NodePseudoClassProperty(bicSwichLbl);
    tccSwitchStateProperty = new NodePseudoClassProperty(tccSwitchLbl);

    bcg1State = lowVoltageScreenModel.bcg1StatusProperty(carIndex);
    bcg1State
        .addListener(observable -> bcg1StateProperty.set(bcg1State.get().getComponentState().toLowerCase()));
    bcg1StateProperty.set(bcg1State.get().getComponentState().toLowerCase());

    bcg2State = lowVoltageScreenModel.bcg2StatusProperty(carIndex);
    bcg2State
        .addListener(observable -> bcg2StateProperty.set(bcg2State.get().getComponentState().toLowerCase()));
    bcg2StateProperty.set(bcg2State.get().getComponentState().toLowerCase());

    bicState = lowVoltageScreenModel.bicStatusProperty(carIndex);
    bicState.addListener(
        observable -> bicSwitchStateProperty.set(bicState.get().getComponentState().toLowerCase()));
    bicSwitchStateProperty.set(bicState.get().getComponentState().toLowerCase());

    tccState = lowVoltageScreenModel.tccStatusProperty(carIndex);
    tccState.addListener(
        observable -> tccSwitchStateProperty.set(tccState.get().getComponentState().toLowerCase()));
    tccSwitchStateProperty.set(tccState.get().getComponentState().toLowerCase());
  }

  private void updatecarLabel(String carLblString)
  {
    carLbl.setText(carLblString);
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
}
