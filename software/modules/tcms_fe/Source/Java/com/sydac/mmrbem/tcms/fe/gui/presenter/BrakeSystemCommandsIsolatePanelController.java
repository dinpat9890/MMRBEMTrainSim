package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TrainSideViewComponentStatusModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Button;
import javafx.scene.layout.GridPane;

public class BrakeSystemCommandsIsolatePanelController extends AbstractTCMSController
{

  @FXML
  private Button isolate1Btn;

  @FXML
  private Button isolate2Btn;

  private NodePseudoClassProperty bogie1PseudoClassProperty;

  private NodePseudoClassProperty bogie2PseudoClassProperty;

  private ObjectPropertyBase<CarComponentStatesDO> bogie1State;

  private ObjectPropertyBase<CarComponentStatesDO> bogie2State;

  protected TrainSideViewComponentStatusModel carComponentStatusModel;

  private Integer carIndex;

  public BrakeSystemCommandsIsolatePanelController(CarConfigurationModel carConfig,
      TrainSideViewComponentStatusModel carComponentStatusModel)
  {
    super();
    this.carIndex = carConfig.carIndexProperty().get();
    this.carComponentStatusModel = carComponentStatusModel;
  }

  @Override
  public void detachListeners()
  {
    // To Detach Listeners
  }

  @Override
  public void initializeImpl()
  {
    bogie1PseudoClassProperty = new NodePseudoClassProperty(isolate1Btn);
    bogie2PseudoClassProperty = new NodePseudoClassProperty(isolate2Btn);

    bogie1State = carComponentStatusModel.bogie1StatusProperty(carIndex);
    bogie2State = carComponentStatusModel.bogie2StatusProperty(carIndex);

    bogie1State.addListener(observable -> updateIsolateBogie1Button());
    bogie2State.addListener(observable -> updateIsolateBogie2Button());

    updateIsolateBogie1Button();
    updateIsolateBogie2Button();
  }

  private void updateIsolateBogie1Button()
  {
    if (TCMSUIConstants.DOOR_ISOLATED.equalsIgnoreCase(bogie1State.get().getComponentState()))
    {
      bogie1PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolate1Btn.setText("reset 1");
    }
    else
    {
      bogie1PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolate1Btn.setText("ISO 1");
    }

  }

  private void updateIsolateBogie2Button()
  {
    
    if (TCMSUIConstants.DOOR_ISOLATED.equalsIgnoreCase(bogie2State.get().getComponentState()))
    {
      bogie2PseudoClassProperty.set(TCMSUIConstants.DOOR_ISOLATED_PSEUDO_CLASS);
      isolate2Btn.setText("reset 2");
    }
    else
    {
      bogie2PseudoClassProperty.set(TCMSUIConstants.DOOR_NOT_ISOLATED_PSEUDO_CLASS);
      isolate2Btn.setText("ISO 2");
    }

  
  }

  @FXML
  private void onIsolateButtonAction(ActionEvent event)
  {
    TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPBSelectedIsolateCar(carIndex);
    if (event.getSource().equals(isolate1Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPBIsolateBogie1Req(
          bogie1State.get().getComponentState().equalsIgnoreCase(TCMSUIConstants.DOOR_ISOLATED)
              ? TCMSUIConstants.REINSERT_VALUE
              : TCMSUIConstants.ISOLATE_VALUE);
    }
    else if (event.getSource().equals(isolate2Btn))
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendPBIsolateBogie2Req(
          bogie2State.get().getComponentState().equalsIgnoreCase(TCMSUIConstants.DOOR_ISOLATED)
              ? TCMSUIConstants.REINSERT_VALUE
              : TCMSUIConstants.ISOLATE_VALUE);
    }
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
