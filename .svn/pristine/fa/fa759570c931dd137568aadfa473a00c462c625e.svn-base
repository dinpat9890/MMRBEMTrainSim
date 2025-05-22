package com.sydac.mmrbem.tcms.fe.gui.presenter;

import java.io.IOException;

import com.sydac.mmrbem.cabscreens.fe.base.LoadingException;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.view.ViewPackage;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class LowVoltageCommonCarController extends AbstractTCMSController
{

  @FXML
  private Label carLbl;

  private String carLblString = ApplicationConstants.BLANK;

  public LowVoltageCommonCarController(String carLabel)
  {
    super();
    this.carLblString = carLabel;
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
