package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.gui.control.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TCMSEthernetConsistNetworkScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class TCMSEthernetConsistNetworkDMCarController extends AbstractTCMSController
{

  @FXML
  private Label carLbl;

  @FXML
  private Label csALbl;

  @FXML
  private Label csBLbl;

  @FXML
  private Label csCLbl;

  @FXML
  private Label algLbl;

  @FXML
  private Label tbnLinesLbl;

  @FXML
  private Label tbnLbl;

  private String carLblString = ApplicationConstants.BLANK;

  private Integer carIndex;

  private TCMSEthernetConsistNetworkScreenModel tcmsEthernetConsistNetworkScreenModel;

  public TCMSEthernetConsistNetworkDMCarController(
      TCMSEthernetConsistNetworkScreenModel tcmsEthernetConsistNetworkScreenModel,
      CarConfigurationModel carConfig, String carLabel)
  {
    super();
    this.carLblString = carLabel;
    this.carIndex = carConfig.carIndexProperty().get();
    this.tcmsEthernetConsistNetworkScreenModel = tcmsEthernetConsistNetworkScreenModel;
  }

  @Override
  public void detachListeners()
  {
    // TODO Detach Listeners
  }

  @Override
  public void initializeImpl()
  {
    updateCarLabel(carLblString);

    NodePseudoClassProperty csAStateProperty = new NodePseudoClassProperty(csALbl);
    NodePseudoClassProperty csBStateProperty = new NodePseudoClassProperty(csBLbl);
    NodePseudoClassProperty csCStateProperty = new NodePseudoClassProperty(csCLbl);
    NodePseudoClassProperty algStateProperty = new NodePseudoClassProperty(algLbl);
    NodePseudoClassProperty tbnLineStateProperty = new NodePseudoClassProperty(tbnLinesLbl);
    NodePseudoClassProperty tbnStateProperty = new NodePseudoClassProperty(tbnLbl);

    ObjectPropertyBase<CarComponentStatesDO> csAState = tcmsEthernetConsistNetworkScreenModel
        .componentSwitchAStatusProperty(carIndex);
    csAState
        .addListener(observable -> csAStateProperty.set(csAState.get().getComponentState().toLowerCase()));
    csAStateProperty.set(csAState.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> csBState = tcmsEthernetConsistNetworkScreenModel
        .componentSwitchBStatusProperty(carIndex);
    csBState
        .addListener(observable -> csBStateProperty.set(csBState.get().getComponentState().toLowerCase()));
    csBStateProperty.set(csBState.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> csCState = tcmsEthernetConsistNetworkScreenModel
        .componentSwitchCStatusProperty(carIndex);
    csCState
        .addListener(observable -> csCStateProperty.set(csCState.get().getComponentState().toLowerCase()));
    csCStateProperty.set(csCState.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> algState = tcmsEthernetConsistNetworkScreenModel
        .algStatusProperty(carIndex);
    algState
        .addListener(observable -> algStateProperty.set(algState.get().getComponentState().toLowerCase()));
    algStateProperty.set(algState.get().getComponentState().toLowerCase());

    ObjectPropertyBase<CarComponentStatesDO> tbnState = tcmsEthernetConsistNetworkScreenModel
        .trainBackboneNodeStatusProperty(carIndex);
    tbnState
        .addListener(observable -> tbnStateProperty.set(tbnState.get().getComponentState().toLowerCase()));
    tbnStateProperty.set(tbnState.get().getComponentState().toLowerCase());

    tbnState.addListener(
        observable -> tbnLineStateProperty.set(tbnState.get().getComponentState().toLowerCase()));
    tbnLineStateProperty.set(tbnState.get().getComponentState().toLowerCase());
  }

  private void updateCarLabel(String carLblString)
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
