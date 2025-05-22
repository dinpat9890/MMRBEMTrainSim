package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.gui.control.NodePseudoClassProperty;
import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.TCMSStatusScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class TCMSStatusTCarMCarController extends AbstractTCMSController
{
  @FXML
  private Label carLbl;

  @FXML
  private Label rio1MLbl;

  @FXML
  private Label rio2SLbl;

  @FXML
  private Label rio12LineLbl;
  
  

  @FXML
  private Label  rio2SUpgradeLabel;
  
  @FXML
  private Label  rio1SUpgradeLabel;

  private String carLblString = ApplicationConstants.BLANK;

  private TCMSStatusScreenModel tcmsStatusScreenModel;

  private Integer carIndex;
  
 

  public TCMSStatusTCarMCarController(TCMSStatusScreenModel tcmsStatusScreenModel,
      CarConfigurationModel carConfig, String carLabel)
  {
    super();
    this.carLblString = carLabel;
    this.carIndex = carConfig.carIndexProperty().get();
    this.tcmsStatusScreenModel = tcmsStatusScreenModel;
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

    NodePseudoClassProperty rio1MStateProperty = new NodePseudoClassProperty(rio1MLbl);
    NodePseudoClassProperty rio2SStateProperty = new NodePseudoClassProperty(rio2SLbl);
    NodePseudoClassProperty rio12FaultStateProperty = new NodePseudoClassProperty(rio12LineLbl);
    
    NodePseudoClassProperty rio2SUpgradeProperty = new NodePseudoClassProperty(rio2SUpgradeLabel);
    NodePseudoClassProperty rio1SUpgradeeProperty = new NodePseudoClassProperty(rio1SUpgradeLabel);

  

    ObjectPropertyBase<CarComponentStatesDO> rio12LineFaultState = tcmsStatusScreenModel
        .rio12LineStatusProperty(carIndex);
    rio12LineFaultState.addListener(observable -> rio12FaultStateProperty
        .set(rio12LineFaultState.get().getComponentState().toLowerCase()));
    rio12FaultStateProperty.set(rio12LineFaultState.get().getComponentState().toLowerCase());
    
    ObjectPropertyBase<CarComponentStatesDO> rio1State = tcmsStatusScreenModel
        .rio1StatusProperty(carIndex);
    rio1State.addListener(
        observable -> {
          rio1SUpgradeeProperty.set(rio1State.get().getComponentState().toLowerCase());  
          rio1MStateProperty.set(rio1State.get().getComponentState().toLowerCase());
          
        });
    rio1SUpgradeeProperty.set(rio1State.get().getComponentState().toLowerCase());
    rio1MStateProperty.set(rio1State.get().getComponentState().toLowerCase());
    
    ObjectPropertyBase<CarComponentStatesDO> rio2State = tcmsStatusScreenModel
        .rio2StatusProperty(carIndex);
    rio2State.addListener(
        observable -> { rio2SUpgradeProperty.set(rio2State.get().getComponentState().toLowerCase());
        rio2SStateProperty.set(rio2State.get().getComponentState().toLowerCase());
          
        });
    rio2SUpgradeProperty.set(rio2State.get().getComponentState().toLowerCase());
    rio2SStateProperty.set(rio2State.get().getComponentState().toLowerCase());
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