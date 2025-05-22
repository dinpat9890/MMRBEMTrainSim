
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FireDetectionSystemDetailsBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FireDetectionSystemDetailsModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class FDSDetailsOtherCarsController extends AbstractTCMSController
{

  @FXML
  private Label shdAuxiliaryDeskLbl;

  @FXML
  private Button shdAuxiliaryDeskBtn;

  @FXML
  private GridPane cabAreaGrid;

  @FXML
  private Label shdCabAreaLbl;

  @FXML
  private Button shdCabAreaBtn;

  @FXML
  private Label shdEndCubicle1Lbl;

  @FXML
  private Label shdEndCubicle2Lbl;

  @FXML
  private Label shdEndCubicle3Lbl;

  @FXML
  private Label shdEndCubicle4Lbl;

  @FXML
  private Button shdEndCubicle4Btn;

  @FXML
  private Label shdEDBSpareBoxLbl;

  @FXML
  private Button shdEDBSpareBoxBtn;

  @FXML
  private Label lhdLTJB1Lbl;

  @FXML
  private Label lhdLTJB2Lbl;

  @FXML
  private Button lhdLTJB2Btn;

  @FXML
  private Label lhdEndCubicleLbl;

  @FXML
  private Button lhdEndCubicleBtn;

  @FXML
  private Label lhdMTRLbl;

  @FXML
  private Label lhdVCBCBLbl;

  @FXML
  private Button lhdVCBCBBtn;

  @FXML
  private Label lhdAPSLbl;

  @FXML
  private Button lhdAPSBtn;

  @FXML
  private Label lhdSSU1Lbl;

  @FXML
  private Label lhdSSU2Lbl;

  @FXML
  private Button lhdSSU2Btn;

  @FXML
  private Label lhdPEBLbl;

  @FXML
  private Label hvac1Label;

  @FXML
  private Button lhdPEBBtn;

  @FXML
  private Button hvac1Button;

  @FXML
  private Label saloonL1Label;

  @FXML
  private Label saloonL2Label;

  @FXML
  private Label saloonL3Label;

  @FXML
  private Label saloonR1Label;

  @FXML
  private Label saloonR2Label;

  @FXML
  private Label saloonR3Label;

  @FXML
  private Label hdHvacLabel;

  @FXML
  private Button saloonL1Button;

  @FXML
  private Button saloonL2Button;

  @FXML
  private Button saloonL3Button;

  @FXML
  private Button saloonR1Button;

  @FXML
  private Button saloonR2Button;

  @FXML
  private Button saloonR3Button;

  @FXML
  private Button hdHvacButton;

  @FXML
  private Button endCub1Button;

  @FXML
  private Button endCub2Button;

  @FXML
  private Button endCub3Button;

  private ChangeListener<Number> carsChangeListener;

  private FireDetectionSystemDetailsModel fireDetectionSystemDetailsModel;

  @Override
  public void detachListeners()
  {
    fireDetectionSystemDetailsModel.getCarType().removeListener(carsChangeListener);
  }

  @Override
  public void initializeImpl()
  {
    fireDetectionSystemDetailsModel = new FireDetectionSystemDetailsModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FireDetectionSystemDetailsBinder(fireDetectionSystemDetailsModel));

    carsChangeListener = (observable, oldVal, newVal) -> updateLabelsAndButtons();
    fireDetectionSystemDetailsModel.getCarType().addListener(carsChangeListener);

    updateLabelsAndButtons();
  }

  private void updateLabelsAndButtons()
  {
    CarType carType = getCarType();
    switch (carType)
    {
    case DM:
      updateDmCar();
      break;
    case T:
      updateTCar();
      break;
    case M:
      updateMCar();
      break;
    default:
      updateDmCar();
    }
  }

  private CarType getCarType()
  {
    TrainConfigurationModel trainConfigurationModel = TrainConfigurationController
        .getTrainConfigurationModelInstance(scenarioCarIndex);

    CarConfigurationModel carConfig = trainConfigurationModel
        .getCarConfig(fireDetectionSystemDetailsModel.getCarType().get());

    return CarType.valueByCarTypeCode(carConfig.carTypeProperty().get());
  }

  private void updateMCar()
  {
    updateShd(CarType.M);

    lhdLTJB1Lbl.setText("LHD - LTJB1");
    lhdMTRLbl.setText("LHD - CI");
    lhdSSU1Lbl.setText("LHD - PEB");
    lhdVCBCBLbl.setText("LHD - BCG");
    lhdSSU2Lbl.setText("LHD - BCB");

    lhdLTJB2Lbl.setVisible(true);
    lhdLTJB2Btn.setVisible(true);

    lhdVCBCBLbl.setVisible(true);
    lhdVCBCBBtn.setVisible(true);

    lhdSSU2Lbl.setVisible(true);
    lhdSSU2Btn.setVisible(true);

    lhdEndCubicleLbl.setVisible(true);
    lhdEndCubicleBtn.setVisible(true);

    lhdAPSLbl.setVisible(false);
    lhdAPSBtn.setVisible(false);

    lhdPEBLbl.setVisible(false);
    lhdPEBBtn.setVisible(false);
  }

  private void updateTCar()
  {
    updateShd(CarType.T);

    lhdLTJB1Lbl.setText("LHD - LTJB1");
    lhdMTRLbl.setText("LHD - MTR");
    lhdSSU1Lbl.setText("LHD - SSU1");
    lhdVCBCBLbl.setText("LHD - VCB-CB");
    lhdSSU2Lbl.setText("LHD - SSU2");

    lhdLTJB2Lbl.setVisible(true);
    lhdLTJB2Btn.setVisible(true);

    lhdVCBCBLbl.setVisible(true);
    lhdVCBCBBtn.setVisible(true);

    lhdSSU2Lbl.setVisible(true);
    lhdSSU2Btn.setVisible(true);

    lhdEndCubicleLbl.setVisible(true);
    lhdEndCubicleBtn.setVisible(true);

    lhdAPSLbl.setVisible(true);
    lhdAPSBtn.setVisible(true);

    lhdPEBLbl.setVisible(true);
    lhdPEBBtn.setVisible(true);
  }

  private void updateDmCar()
  {

    updateShd(CarType.DM);

    lhdLTJB1Lbl.setText("LHD - CI");
    lhdMTRLbl.setText("LHD - LTJB");
    lhdSSU1Lbl.setText("LHD - Driver Desk");

    lhdLTJB2Lbl.setVisible(false);
    lhdLTJB2Btn.setVisible(false);

    lhdVCBCBLbl.setVisible(false);
    lhdVCBCBBtn.setVisible(false);

    lhdSSU2Lbl.setVisible(false);
    lhdSSU2Btn.setVisible(false);

    lhdEndCubicleLbl.setVisible(false);
    lhdEndCubicleBtn.setVisible(false);

    lhdAPSLbl.setVisible(false);
    lhdAPSBtn.setVisible(false);

    lhdPEBLbl.setVisible(false);
    lhdPEBBtn.setVisible(false);
  }

  private void updateShd(CarType dm)
  {
    boolean isVisible;
    if (CarType.DM == dm)
    {
      isVisible = true;
      shdEndCubicle1Lbl.setText("SHD - End Cubicle (Rear Right-1)");
      shdEndCubicle2Lbl.setText("SHD - End Cubicle (Rear Right-2)");
      shdEndCubicle3Lbl.setText("SHD - End Cubicle (Rear Left-1)");
    }
    else
    {
      isVisible = false;
      shdEndCubicle1Lbl.setText("SHD - End Cubicle (Front Right)");
      shdEndCubicle2Lbl.setText("SHD - End Cubicle (Front Left)");
      shdEndCubicle3Lbl.setText("SHD - End Cubicle (Rear Left-EDB)");
    }

    shdEndCubicle4Lbl.setVisible(isVisible);
    shdEndCubicle4Btn.setVisible(isVisible);

    shdCabAreaLbl.setVisible(isVisible);
    shdCabAreaBtn.setVisible(isVisible);

    shdAuxiliaryDeskLbl.setVisible(isVisible);
    shdAuxiliaryDeskBtn.setVisible(isVisible);

    shdEDBSpareBoxLbl.setVisible(isVisible);
    shdEDBSpareBoxBtn.setVisible(isVisible);
  }

  @FXML
  void onHdHvac1Action(ActionEvent event)
  {

  }

  @FXML
  void onShdCabAreaAction(ActionEvent event)
  {

  }

  @FXML
  void onShdEdbSpareBoxAction(ActionEvent event)
  {

  }

  @FXML
  void onHdHvac2Action(ActionEvent event)
  {

  }

  @FXML
  void onLhdApsAction(ActionEvent event)
  {}

  @FXML
  void onLhdEndCubicleAction(ActionEvent event)
  {}

  @FXML
  void onLhdLtjb1Action(ActionEvent event)
  {}

  @FXML
  void onLhdLtjb2Action(ActionEvent event)
  {}

  @FXML
  void onLhdMtrAction(ActionEvent event)
  {}

  @FXML
  void onLhdPebAction(ActionEvent event)
  {}

  @FXML
  void onLhdSsu1Action(ActionEvent event)
  {}

  @FXML
  void onLhdSsu2Action(ActionEvent event)
  {}

  @FXML
  void onLhdVcbCbAction(ActionEvent event)
  {}

  @FXML
  void onShdAuxiliaryDeskAction(ActionEvent event)
  {

  }

  @FXML
  void onShdEndCubicle1Action(ActionEvent event)
  {

  }

  @FXML
  void onShdEndCubicle2Action(ActionEvent event)
  {

  }

  @FXML
  void onShdEndCubicle3Action(ActionEvent event)
  {

  }

  @FXML
  void onShdEndCubicle4Action(ActionEvent event)
  {

  }

  @FXML
  void onShdSaloonL2Action(ActionEvent event)
  {

  }

  @FXML
  void onShdSaloonL3Action(ActionEvent event)
  {

  }

  @FXML
  void onShdSaloonR1Action(ActionEvent event)
  {

  }

  @FXML
  void onShdSaloonR2Action(ActionEvent event)
  {

  }

  @FXML
  void onShdSaloonR3Action(ActionEvent event)
  {

  }

  @FXML
  void onShdSaloonL1Action(ActionEvent event)
  {

  }
}
