
package com.sydac.mmrbem.tcms.fe.gui.presenter;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.CarType;
import com.sydac.mmrbem.tcms.fe.base.TCMSFactory;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.FireDetectionSystemDetailsBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.CarConfigurationModel;
import com.sydac.mmrbem.tcms.fe.gui.model.FireDetectionSystemDetailsModel;
import com.sydac.mmrbem.tcms.fe.model.TrainConfigurationModel;
import com.sydac.project.runtimedata.ProjectObjectConstants.VDUInputs;

import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;

public class FireDetectionSystemDetailsController extends AbstractTCMSController
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

  @FXML
  private Button lhdCiButton;

  @FXML
  private Button lhdLtjbButton;

  @FXML
  private Button lhdDriverButton;

  private ChangeListener<Number> carsChangeListener;

  private ChangeListener<Number> hvac1StatusListener;

  private ChangeListener<Number> edbHeatAlarmStatusListener;

  private ChangeListener<Number> cabSmokeAlarmStatusListenr;

  private ChangeListener<Number> hvac1ButtonStatus;

  private ChangeListener<Number> edbAlarmButtonStatus;

  private ChangeListener<Number> cabAlarmButtonStauts;

  private ChangeListener<Number> saloonR1ButtonStatus;

  private ChangeListener<Number> saloonR2ButtonStatus;

  private ChangeListener<Number> saloonR3ButtonStatus;

  private ChangeListener<Number> saloonL1ButtonStatus;

  private ChangeListener<Number> saloonL2ButtonStatus;

  private ChangeListener<Number> saloonL3ButtonStatus;

  private ChangeListener<Number> hdHvac2ButtonStauts;

  private ChangeListener<Number> auxillaryButtonStauts;

  private ChangeListener<Number> endCubRR1ButtonStauts;

  private ChangeListener<Number> endCubRR2ButtonStauts;

  private ChangeListener<Number> endCubRL1ButtonStauts;

  private ChangeListener<Number> endCubRL2ButtonStauts;

  private ChangeListener<Number> lhdDriverDeskDisableStatus;

  private ChangeListener<Number> lhdLtjbDIsableVduStatus;

  private ChangeListener<Number> lhdCIDIsableStatus;

  private ChangeListener<Number> currentCarIndexListenr;

  private FireDetectionSystemDetailsModel fireDetectionSystemDetailsModel;

  private NodePseudoClassProperty hvac1StatusProperty;

  private NodePseudoClassProperty edbHeatAlarmStatusProperty;

  private NodePseudoClassProperty cabSmokeStatusProperty;

  private NodePseudoClassProperty hvacButtonProperty;

  private NodePseudoClassProperty edbAlarmButtonProperty;

  private NodePseudoClassProperty cabSmokeAlarmButtonProperty;

  private NodePseudoClassProperty saloonR1ButtonProperty;

  private NodePseudoClassProperty saloonR1Property;

  private NodePseudoClassProperty saloonR2ButtonProperty;

  private NodePseudoClassProperty saloonR2Property;

  private NodePseudoClassProperty saloonR3ButtonProperty;

  private NodePseudoClassProperty saloonR3Property;

  private NodePseudoClassProperty saloonL1ButtonProperty;

  private NodePseudoClassProperty saloonL1Property;

  private NodePseudoClassProperty saloonL2ButtonProperty;

  private NodePseudoClassProperty saloonL2Property;

  private NodePseudoClassProperty saloonL3ButtonProperty;

  private NodePseudoClassProperty saloonL3Property;

  private NodePseudoClassProperty hdHvac2ButtonProperty;

  private NodePseudoClassProperty hdHvac2Property;

  private NodePseudoClassProperty auxillaryButtonProperty;

  private NodePseudoClassProperty auxillaryProperty;

  private NodePseudoClassProperty endCubRR1ButtonProperty;

  private NodePseudoClassProperty endCubRR1Property;

  private NodePseudoClassProperty endCubRR2ButtonProperty;

  private NodePseudoClassProperty endCubRR2Property;

  private NodePseudoClassProperty endCubRL1ButtonProperty;

  private NodePseudoClassProperty endCubRL1Property;

  private NodePseudoClassProperty endCubRL2ButtonProperty;

  private NodePseudoClassProperty endCubRL2Property;

  private NodePseudoClassProperty lhdCIButtonProperty;

  private NodePseudoClassProperty lhdLtjbButtonProperty;

  private NodePseudoClassProperty lhdDriverDeskButtonProperty;

  private NodePseudoClassProperty lhdCILabelProperty;

  private NodePseudoClassProperty lhdLtjbLabelProperty;

  private NodePseudoClassProperty lhdDriverDeskLabelProperty;

  private String ACTIVE = "active";

  private String IN_ACTIVE = "inactive";

  private int hvac1Value = 0;

  private int cabAreaValue = 0;

  private int edbSpareBoxValue = 0;

  private int value1 = 0;

  private int value2 = 0;

  private int value3 = 0;

  private int value4 = 0;

  private int value5 = 0;

  private int value6 = 0;

  private int value7 = 0;

  private int value8 = 0;

  private int value9 = 0;

  private int value10 = 0;

  private int value11 = 0;

  private int value12 = 0;

  private int value13 = 0;

  private int value14 = 0;

  private int value15 = 0;

  private int currentCarIndex = 0;

  @Override
  public void detachListeners()
  {
    fireDetectionSystemDetailsModel.getCarType().removeListener(carsChangeListener);
  }

  @Override
  public void initializeImpl()
  {
    hvac1StatusProperty = new NodePseudoClassProperty(hvac1Label);
    edbHeatAlarmStatusProperty = new NodePseudoClassProperty(shdEDBSpareBoxLbl);
    cabSmokeStatusProperty = new NodePseudoClassProperty(shdCabAreaLbl);

    saloonL1Property = new NodePseudoClassProperty(saloonL1Label);
    saloonL1ButtonProperty = new NodePseudoClassProperty(saloonL1Button);

    saloonL2Property = new NodePseudoClassProperty(saloonL2Label);
    saloonL2ButtonProperty = new NodePseudoClassProperty(saloonL2Button);

    saloonL3Property = new NodePseudoClassProperty(saloonL3Label);
    saloonL3ButtonProperty = new NodePseudoClassProperty(saloonL3Button);

    saloonR1Property = new NodePseudoClassProperty(saloonR1Label);
    saloonR1ButtonProperty = new NodePseudoClassProperty(saloonR1Button);

    saloonR2Property = new NodePseudoClassProperty(saloonR2Label);
    saloonR2ButtonProperty = new NodePseudoClassProperty(saloonR2Button);

    saloonR3Property = new NodePseudoClassProperty(saloonR3Label);
    saloonR3ButtonProperty = new NodePseudoClassProperty(saloonR3Button);

    hdHvac2Property = new NodePseudoClassProperty(hdHvacLabel);
    hdHvac2ButtonProperty = new NodePseudoClassProperty(hdHvacButton);

    auxillaryProperty = new NodePseudoClassProperty(shdAuxiliaryDeskLbl);
    auxillaryButtonProperty = new NodePseudoClassProperty(shdAuxiliaryDeskBtn);

    endCubRR1Property = new NodePseudoClassProperty(shdEndCubicle1Lbl);
    endCubRR1ButtonProperty = new NodePseudoClassProperty(endCub1Button);

    endCubRR2Property = new NodePseudoClassProperty(shdEndCubicle2Lbl);
    endCubRR2ButtonProperty = new NodePseudoClassProperty(endCub2Button);

    endCubRL1Property = new NodePseudoClassProperty(shdEndCubicle3Lbl);
    endCubRL1ButtonProperty = new NodePseudoClassProperty(endCub3Button);

    endCubRL2Property = new NodePseudoClassProperty(shdEndCubicle4Lbl);
    endCubRL2ButtonProperty = new NodePseudoClassProperty(shdEndCubicle4Btn);

    hvacButtonProperty = new NodePseudoClassProperty(hvac1Button);
    edbAlarmButtonProperty = new NodePseudoClassProperty(shdEDBSpareBoxBtn);
    cabSmokeAlarmButtonProperty = new NodePseudoClassProperty(shdCabAreaBtn);

    lhdCIButtonProperty = new NodePseudoClassProperty(lhdCiButton);
    lhdCILabelProperty = new NodePseudoClassProperty(lhdLTJB1Lbl);

    lhdLtjbButtonProperty = new NodePseudoClassProperty(lhdLtjbButton);
    lhdLtjbLabelProperty = new NodePseudoClassProperty(lhdMTRLbl);

    lhdDriverDeskButtonProperty = new NodePseudoClassProperty(lhdDriverButton);
    lhdDriverDeskLabelProperty = new NodePseudoClassProperty(lhdSSU1Lbl);

    fireDetectionSystemDetailsModel = new FireDetectionSystemDetailsModel(scenarioCarIndex);
    tcmsScreenBinders.add(new FireDetectionSystemDetailsBinder(fireDetectionSystemDetailsModel));

    carsChangeListener = (observable, oldVal, newVal) -> updateCurrentCarIndex((Integer)newVal);
    fireDetectionSystemDetailsModel.getCurrentCarIndex().addListener(carsChangeListener);

    carsChangeListener = (observable, oldVal, newVal) -> updateLabelsAndButtons();
    fireDetectionSystemDetailsModel.getCarType().addListener(carsChangeListener);

    edbHeatAlarmStatusListener = (observable, oldVal, newVal) -> updateShdEndCubicleRL2Label((Integer)newVal);
    fireDetectionSystemDetailsModel.getEdbSpareBoxStatus().addListener(edbHeatAlarmStatusListener);

    cabSmokeAlarmStatusListenr = (observable, oldVal, newVal) -> updateCabSmokeAlarmLabel((Integer)newVal);
    fireDetectionSystemDetailsModel.getSaloonCabAreaStatus().addListener(cabSmokeAlarmStatusListenr);

    cabAlarmButtonStauts = (observable, oldVal, newVal) -> updateCabSmokeAlarmButton((Integer)newVal);
    fireDetectionSystemDetailsModel.getSaloonCabAreaButtonStatus().addListener(cabAlarmButtonStauts);

    edbAlarmButtonStatus = (observable, oldVal, newVal) -> updateShdEndCubicleRL2Button((Integer)newVal);
    fireDetectionSystemDetailsModel.getEdbSpareBoxButtonStatus().addListener(edbAlarmButtonStatus);

    saloonL1ButtonStatus = (observable, oldVal, newVal) -> update1ButtonStatus((Integer)newVal,
        saloonL1Property, saloonL1ButtonProperty, saloonL1Button);
    fireDetectionSystemDetailsModel.getShdSaloonL1Status().addListener(saloonL1ButtonStatus);

    saloonL2ButtonStatus = (observable, oldVal, newVal) -> update2ButtonStatus((Integer)newVal,
        saloonL2Property, saloonL2ButtonProperty, saloonL2Button);
    fireDetectionSystemDetailsModel.getShdSaloonL2Status().addListener(saloonL2ButtonStatus);

    saloonL3ButtonStatus = (observable, oldVal, newVal) -> update3ButtonStatus((Integer)newVal,
        saloonL3Property, saloonL3ButtonProperty, saloonL3Button);
    fireDetectionSystemDetailsModel.getShdSaloonL3Status().addListener(saloonL3ButtonStatus);

    saloonR1ButtonStatus = (observable, oldVal, newVal) -> update4ButtonStatus((Integer)newVal,
        saloonR1Property, saloonR1ButtonProperty, saloonR1Button);
    fireDetectionSystemDetailsModel.getShdSaloonR1Status().addListener(saloonR1ButtonStatus);

    saloonR2ButtonStatus = (observable, oldVal, newVal) -> update5ButtonStatus((Integer)newVal,
        saloonR2Property, saloonR2ButtonProperty, saloonR2Button);
    fireDetectionSystemDetailsModel.getShdSaloonR2Status().addListener(saloonR2ButtonStatus);

    saloonR3ButtonStatus = (observable, oldVal, newVal) -> update6ButtonStatus((Integer)newVal,
        saloonR3Property, saloonR3ButtonProperty, saloonR3Button);
    fireDetectionSystemDetailsModel.getShdSaloonR3Status().addListener(saloonR3ButtonStatus);

    hdHvac2ButtonStauts = (observable, oldVal, newVal) -> update7ButtonStatus((Integer)newVal,
        hdHvac2Property, hdHvac2ButtonProperty, hdHvacButton);
    fireDetectionSystemDetailsModel.getHdHvac2Status().addListener(hdHvac2ButtonStauts);

    auxillaryButtonStauts = (observable, oldVal, newVal) -> update8ButtonStatus((Integer)newVal,
        auxillaryProperty, auxillaryButtonProperty, shdAuxiliaryDeskBtn);
    fireDetectionSystemDetailsModel.getAuxillaryStatus().addListener(auxillaryButtonStauts);

    endCubRR1ButtonStauts = (observable, oldVal, newVal) -> update9ButtonStatus((Integer)newVal,
        endCubRR1Property, endCubRR1ButtonProperty, endCub1Button);
    fireDetectionSystemDetailsModel.getEndCubicleRR1().addListener(endCubRR1ButtonStauts);

    endCubRR2ButtonStauts = (observable, oldVal, newVal) -> update10ButtonStatus((Integer)newVal,
        endCubRR2Property, endCubRR2ButtonProperty, endCub2Button);
    fireDetectionSystemDetailsModel.getEndCubicleRR2().addListener(endCubRR2ButtonStauts);

    endCubRL1ButtonStauts = (observable, oldVal, newVal) -> update11ButtonStatus((Integer)newVal,
        endCubRL1Property, endCubRL1ButtonProperty, endCub3Button);
    fireDetectionSystemDetailsModel.getEndCubicleRL1().addListener(endCubRL1ButtonStauts);

    endCubRL2ButtonStauts = (observable, oldVal, newVal) -> update12ButtonStatus((Integer)newVal,
        edbHeatAlarmStatusProperty, edbAlarmButtonProperty, shdEDBSpareBoxBtn);
    fireDetectionSystemDetailsModel.getEndCubicleRL2().addListener(endCubRL2ButtonStauts);

    hvac1StatusListener = (observable, oldVal, newVal) -> updateHvac1Label((Integer)newVal);
    fireDetectionSystemDetailsModel.getHvac1Status().addListener(hvac1StatusListener);

    hvac1ButtonStatus = (observable, oldVal, newVal) -> updateHvacAlarmButton((Integer)newVal);
    fireDetectionSystemDetailsModel.getHvac1buttonStatus().addListener(hvac1ButtonStatus);

    lhdDriverDeskDisableStatus = (observable, oldVal, newVal) -> updateLhdDriverDeskDisable((Integer)newVal,
        lhdDriverDeskLabelProperty, lhdDriverDeskButtonProperty, lhdDriverButton);
    fireDetectionSystemDetailsModel.getLhdDriverDeskDisable().addListener(lhdDriverDeskDisableStatus);

    lhdCIDIsableStatus = (observable, oldVal, newVal) -> updateLhdCIDisable((Integer)newVal);
    fireDetectionSystemDetailsModel.getLhdCIDisable().addListener(lhdCIDIsableStatus);

    lhdLtjbDIsableVduStatus = (observable, oldVal, newVal) -> updateLhdLtjbDisable((Integer)newVal,
        lhdLtjbLabelProperty, lhdLtjbButtonProperty, lhdLtjbButton);
    fireDetectionSystemDetailsModel.getLhdLtjbDIsable().addListener(lhdLtjbDIsableVduStatus);

    updateHvac1Label(fireDetectionSystemDetailsModel.getHvac1Status().get());
    updateShdEndCubicleRL2Label(fireDetectionSystemDetailsModel.getEdbSpareBoxStatus().get());
    updateCabSmokeAlarmLabel(fireDetectionSystemDetailsModel.getSaloonCabAreaStatus().get());
    updateHvacAlarmButton(fireDetectionSystemDetailsModel.getHvac1buttonStatus().get());
    updateShdEndCubicleRL2Button(fireDetectionSystemDetailsModel.getEdbSpareBoxButtonStatus().get());
    updateCabSmokeAlarmButton(fireDetectionSystemDetailsModel.getSaloonCabAreaButtonStatus().get());
    updateLabelsAndButtons();
  }

  private void updateLhdLtjbDisable(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value14 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void updateLhdCIDisable(Integer newVal)
  {
    value15 = newVal;
    lhdCIButtonProperty.set(newVal == 0 ? "set" : "armed");
    lhdCILabelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    lhdCiButton.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void updateLhdDriverDeskDisable(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value13 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update1ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value4 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update2ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value5 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update3ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value6 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update4ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value1 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update5ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value2 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update6ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value3 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update7ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value7 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update8ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value8 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update9ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value9 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update10ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value10 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update11ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value11 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void update12ButtonStatus(Integer newVal, NodePseudoClassProperty labelProperty,
      NodePseudoClassProperty buttonProperty, Button buttonText)
  {
    value12 = newVal;
    buttonProperty.set(newVal == 0 ? "set" : "armed");
    labelProperty.set(newVal == 0 ? IN_ACTIVE : "enable");
    buttonText.setText(newVal == 0 ? "DISABLE" : "ENABLE");
  }

  private void updateCurrentCarIndex(Integer newVal)
  {
    currentCarIndex = newVal;
  }

  private void updateHvacAlarmButton(Integer newVal)
  {
    hvac1Value = newVal;
    boolean isDisabled = (newVal == 0);

    // Update button properties
    hvacButtonProperty.set(isDisabled ? "set" : "armed");
    hvac1Button.setText(isDisabled ? "DISABLE" : "ENABLE");

    // Update status property based on HVAC status and new value
    boolean isHvacActive = (fireDetectionSystemDetailsModel.getHvac1Status().get() == 1);
    hvac1StatusProperty.set(isDisabled ? (isHvacActive ? ACTIVE : IN_ACTIVE) : "enable");
  }

  private void updateHvac1Label(Integer newVal)
  {
    hvac1StatusProperty.set(newVal == 0 ? IN_ACTIVE : ACTIVE);
  }

  private void updateShdEndCubicleRL2Button(Integer newVal)
  {
    edbSpareBoxValue = newVal;
    boolean isDisabled = (newVal == 0);

    // Update button properties
    endCubRL2ButtonProperty.set(isDisabled ? "set" : "armed");
    shdEndCubicle4Btn.setText(isDisabled ? "DISABLE" : "ENABLE");

    // Update status property based on EDB Alarm status and new value
    boolean isHvacActive = (fireDetectionSystemDetailsModel.getEdbSpareBoxStatus().get() == 1);
    endCubRL2Property.set(isDisabled ? (isHvacActive ? ACTIVE : IN_ACTIVE) : "enable");
  }

  private void updateShdEndCubicleRL2Label(Integer newVal)
  {
    endCubRL2Property.set(newVal == 0 ? IN_ACTIVE : ACTIVE);
  }

  private void updateCabSmokeAlarmButton(Integer newVal)
  {
    cabAreaValue = newVal;
    boolean isDisabled = (newVal == 0);

    // Update button properties
    cabSmokeAlarmButtonProperty.set(isDisabled ? "set" : "armed");
    shdCabAreaBtn.setText(isDisabled ? "DISABLE" : "ENABLE");

    // Update status property based on EDB Alarm status and new value
    boolean isHvacActive = (fireDetectionSystemDetailsModel.getSaloonCabAreaStatus().get() == 1);
    cabSmokeStatusProperty.set(isDisabled ? (isHvacActive ? ACTIVE : IN_ACTIVE) : "enable");
  }

  private void updateCabSmokeAlarmLabel(Integer newVal)
  {
    cabSmokeStatusProperty.set(newVal == 0 ? IN_ACTIVE : ACTIVE);
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
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.HVAC_1_FIRE_DETECTOR_DISABLE_VDU_REQ, hvac1Value == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdCabAreaAction(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.CAB_SMOKE_DETECTOR_DISABLE_VDU_REQ, cabAreaValue == 0 ? 1 : 0);
    }
  }

  @FXML
  void onHdHvac2Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.HD_HVAC_2_BUTTON_REQ,
          value7 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onLhdApsAction(ActionEvent event)
  {}

  @FXML
  void onLhdEndCubicleAction(ActionEvent event)
  {}

  @FXML
  void onLhdLtjb1Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.LHD_CI_DISABLE_VDU_REQ,
          value15 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onLhdLtjb2Action(ActionEvent event)
  {}

  @FXML
  void onLhdMtrAction(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.LHD_LTJB_DISABLE_VDU_REQ,
          value14 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onLhdPebAction(ActionEvent event)
  {}

  @FXML
  void onLhdSsu1Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.LHD_DRIVER_DESK_DISABLE_VDU_REQ, value13 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onLhdSsu2Action(ActionEvent event)
  {}

  @FXML
  void onLhdVcbCbAction(ActionEvent event)
  {}

  @FXML
  void onShdAuxiliaryDeskAction(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.AUXILLARY_DESK_BUTTON_REQ,
          value8 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdEndCubicle1Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.END_CUBICLE_RR1_BUTTON_REQ,
          value9 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdEndCubicle2Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.END_CUBICLE_RR2_BUTTON_REQ,
          value10 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdEndCubicle3Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.END_CUBICLE_RL1_BUTTON_REQ,
          value11 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdSaloonL2Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.SHD_SALOON_L2_BUTTON_REQ,
          value5 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdSaloonL3Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.SHD_SALOON_L3_BUTTON_REQ,
          value6 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdSaloonR1Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.SHD_SALOON_R1_BUTTON_REQ,
          value1 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdSaloonR2Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.SHD_SALOON_R2_BUTTON_REQ,
          value2 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdSaloonR3Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.SHD_SALOON_R3_BUTTON_REQ,
          value3 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdSaloonL1Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.SHD_SALOON_L1_BUTTON_REQ,
          value4 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdEdbSpareBoxAction(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex).sendRequest(VDUInputs.END_CUBICLE_RL2_BUTTON_REQ,
          value12 == 0 ? 1 : 0);
    }
  }

  @FXML
  void onShdEndCubicle4Action(ActionEvent event)
  {
    CarType carType = getCarType();
    if (CarType.DM == carType)
    {
      TCMSFactory.getServiceRequestHandler(scenarioCarIndex)
          .sendRequest(VDUInputs.EDB_HEAT_ALARM_DISABLE_VDU_REQ, edbSpareBoxValue == 0 ? 1 : 0);
    }
  }
}
