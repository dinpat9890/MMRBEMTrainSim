package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.data.CarComponentStatesDO;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.MediumVoltageSystemScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.beans.property.ObjectPropertyBase;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class LowVoltageTCarController extends AbstractTCMSController
{

  @FXML
  private Label carLbl;

  private String carLblString = ApplicationConstants.BLANK;

  private MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel;

  @FXML
  private Label auxCompLbl;

  private Integer carIndex;

  public LowVoltageTCarController(String carLabel, CarConfigurationModel carConfig,
      MediumVoltageSystemScreenModel mediumVoltageSystemScreenModel)
  {
    super();
    this.carLblString = carLabel;
    this.mediumVoltageSystemScreenModel = mediumVoltageSystemScreenModel;
    this.carIndex = carConfig.carIndexProperty().get();
  }

  @Override
  public void detachListeners()
  {
    // TODO document why this method is empty
  }

  @Override
  public void initializeImpl()
  {
   
    updateCarLabel(carLblString);
    NodePseudoClassProperty auxCompStateProperty = new NodePseudoClassProperty(auxCompLbl);
  
  
    ObjectPropertyBase<CarComponentStatesDO> auxCompState = mediumVoltageSystemScreenModel
        .auxCompStatusProperty(carIndex);
    auxCompState.addListener(
        observable -> auxCompStateProperty.set(auxCompState.get().getComponentState().toLowerCase()));
    auxCompStateProperty.set(auxCompState.get().getComponentState().toLowerCase());
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
