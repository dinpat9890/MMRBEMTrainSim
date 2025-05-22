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

import java.text.DecimalFormat;

import com.sydac.mmrbem.cabscreens.fe.common.NodePseudoClassProperty;
import com.sydac.mmrbem.tcms.common.state.ApplicationConstants;
import com.sydac.mmrbem.tcms.common.state.DrivingModeEnum;
import com.sydac.mmrbem.tcms.common.state.TCMSConstants;
import com.sydac.mmrbem.tcms.common.state.TCMSModeEnum;
import com.sydac.mmrbem.tcms.common.state.TrainIndicatorStatusEnum;
import com.sydac.mmrbem.tcms.fe.base.utils.TCMSUtil;
import com.sydac.mmrbem.tcms.fe.common.TCMSUIConstants;
import com.sydac.mmrbem.tcms.fe.gui.AbstractTCMSController;
import com.sydac.mmrbem.tcms.fe.gui.binder.BatterySystemScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.HeaderPanelBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.OperatingScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.binder.RouteScreenBinder;
import com.sydac.mmrbem.tcms.fe.gui.model.BatterySystemScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.HeaderPanelModel;
import com.sydac.mmrbem.tcms.fe.gui.model.OperatingScreenModel;
import com.sydac.mmrbem.tcms.fe.gui.model.RouteScreenModel;

import javafx.beans.value.ChangeListener;
import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class OperatingScreenController extends AbstractTCMSController
{
  @FXML
  private Label trainNumberLbl;

  @FXML
  private Label lineVoltageLbl;

  @FXML
  private Label batteryVoltageLbl;

  @FXML
  private Label odometerLbl;

  @FXML
  private Label trainTotalWeightLbl;

  @FXML
  private Label startStationLbl;

  @FXML
  private Label currentStationLbl;

  @FXML
  private Label destinationStationLbl;

  @FXML
  private Label nextStationLbl;

  @FXML
  private Label doorOpnNextStationLbl;

  @FXML
  private Label rescueModeStatusLbl;

  @FXML
  private Label jogModeStatusLbl;

  @FXML
  private Label enableToRunStatusLbl;

  @FXML
  private Label atcBypassStatusLbl;

  @FXML
  private Label shoreSupplyStatusLbl;

  @FXML
  private Label coupledStatusLbl;

  @FXML
  private Label tcmsAutoStatusLbl;

  @FXML
  private Label notchBrakingLbl;

  @FXML
  private Label notchPowerLbl;

  private ChangeListener<Number> trainNumberListener;

  private ChangeListener<Number> lineVoltageListener;

  private ChangeListener<Number> batteryVoltageListener;

  private ChangeListener<Number> odometerListener;

  private ChangeListener<Number> trainTotalWeightListener;

  private ChangeListener<String> startStationListener;

  private ChangeListener<String> currentStationListener;

  private ChangeListener<String> destinationStationListener;

  private ChangeListener<String> nextStationListener;

  private ChangeListener<String> doorOpnNextStationListener;

  private ChangeListener<String> rescueModeListener;

  private ChangeListener<String> jogModeListener;

  private ChangeListener<String> enableToRunListener;

  private ChangeListener<String> atcBypassListener;

  private ChangeListener<String> shoreSupplyListener;

  private ChangeListener<String> coupledListener;

  private ChangeListener<String> tcmsModeListener;

  private ChangeListener<Number> notchListener;

  private NodePseudoClassProperty rescueModeProperty;

  private NodePseudoClassProperty jogModeProperty;

  private NodePseudoClassProperty enableToRunProperty;

  private NodePseudoClassProperty atcBypassProperty;

  private NodePseudoClassProperty shoreSupplyProperty;

  private NodePseudoClassProperty coupledProperty;

  private NodePseudoClassProperty tcmsModeProperty;

  private OperatingScreenModel operatingScreenModel;

  private BatterySystemScreenModel batterySystemScreenModel;

  DecimalFormat odometerFormat = new DecimalFormat("###.##"); //$NON-NLS-1$

  DecimalFormat lineVoltageFormat = new DecimalFormat("###.#"); //$NON-NLS-1$

  private HeaderPanelModel headerPanelModel;

  private ChangeListener<Number> drivingModeListener;

  private ChangeListener<Number> tbcFeedBackListener;

  private RouteScreenModel routeScreenModel;
  
  private ChangeListener<String> routeTrainIdListener;

  @Override
  public void initializeImpl()
  {
    operatingScreenModel = new OperatingScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new OperatingScreenBinder(operatingScreenModel));

    batterySystemScreenModel = new BatterySystemScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new BatterySystemScreenBinder(batterySystemScreenModel));

    headerPanelModel = new HeaderPanelModel(scenarioCarIndex);
    tcmsScreenBinders.add(new HeaderPanelBinder(headerPanelModel));

    routeScreenModel = new RouteScreenModel(scenarioCarIndex);
    tcmsScreenBinders.add(new RouteScreenBinder(routeScreenModel));

    trainNumberListener = (observable, oldVal, newVal) -> updateTrainNumber();
    operatingScreenModel.getTrainNumber().addListener(trainNumberListener);

    lineVoltageListener = (observable, oldVal, newVal) -> updateLineVoltage((double)newVal);
    operatingScreenModel.getLineVoltage().addListener(lineVoltageListener);

    batteryVoltageListener = (observable, oldVal, newVal) -> updateBatteryVoltage((int)newVal);
    batterySystemScreenModel.getOpScreenBatteryVoltage().addListener(batteryVoltageListener);

    odometerListener = (observable, oldVal, newVal) -> updateOdometerValue((double)newVal);
    operatingScreenModel.getOdometerValue().addListener(odometerListener);

    trainTotalWeightListener = (observable, oldVal, newVal) -> updateTrainTotalWeight((int)newVal);
    operatingScreenModel.getTotalTrainWeight().addListener(trainTotalWeightListener);

    startStationListener = (observable, oldVal, newVal) -> updateStartStation(newVal);
    operatingScreenModel.getStartStation().addListener(startStationListener);

    currentStationListener = (observable, oldVal, newVal) -> updateCurrentStation(newVal);
    operatingScreenModel.getCurrentStation().addListener(currentStationListener);

    destinationStationListener = (observable, oldVal, newVal) -> updateDestinationStation(newVal);
    operatingScreenModel.getDestinationStation().addListener(destinationStationListener);

    nextStationListener = (observable, oldVal, newVal) -> updateNextStation(newVal);
    operatingScreenModel.getNextStation().addListener(nextStationListener);

    doorOpnNextStationListener = (observable, oldVal, newVal) -> updateDoorOpnNextStation(newVal);
    operatingScreenModel.getDoorOpeningNextStation().addListener(doorOpnNextStationListener);

    updateStartStation(operatingScreenModel.getStartStation().get());
    updateDestinationStation(operatingScreenModel.getDestinationStation().get());
    updateNextStation(operatingScreenModel.getNextStation().get());
    updateCurrentStation(operatingScreenModel.getCurrentStation().get());
    updateDoorOpnNextStation(operatingScreenModel.getDoorOpeningNextStation().get());

    notchListener = (observable, oldVal, newVal) -> updateNotchValue((int)newVal);
    operatingScreenModel.getNotchValue().addListener(notchListener);

    rescueModeListener = (observable, oldVal,
        newVal) -> updateRescueModeStatus(operatingScreenModel.getRescueMode().get());
    operatingScreenModel.getRescueMode().addListener(rescueModeListener);

    jogModeListener = (observable, oldVal,
        newVal) -> updateJogModeStatus(operatingScreenModel.getJogMode().get());
    operatingScreenModel.getJogMode().addListener(jogModeListener);

    enableToRunListener = (observable, oldVal,
        newVal) -> updateEnableToRunStatus(operatingScreenModel.getEnableToRun().get());
    operatingScreenModel.getEnableToRun().addListener(enableToRunListener);

    atcBypassListener = (observable, oldVal,
        newVal) -> updateAtcBypassStatus(operatingScreenModel.getAtcBypass().get());
    operatingScreenModel.getAtcBypass().addListener(atcBypassListener);

    shoreSupplyListener = (observable, oldVal,
        newVal) -> updateShoreSupplyStatus(operatingScreenModel.getShoreSupply().get());
    operatingScreenModel.getShoreSupply().addListener(shoreSupplyListener);

    coupledListener = (observable, oldVal,
        newVal) -> updateCoupledStatus(operatingScreenModel.getCoupled().get());
    operatingScreenModel.getCoupled().addListener(coupledListener);

    tcmsModeListener = (observable, oldVal,
        newVal) -> updateTcmsModeStatus(operatingScreenModel.getTcmsMode().get());
    operatingScreenModel.getTcmsMode().addListener(tcmsModeListener);

    // drivingModeListener = (observable, oldVal, newVal) ->
    // updateTbcFeedBackValue();
    // headerPanelModel.getDrivingMode().addListener(drivingModeListener);

    // tbcFeedBackListener = (observable, oldVal, newVal) ->
    // updateTbcFeedBackValue();
    // operatingScreenModel.getTcmsTbcFeedBackValue().addListener(tbcFeedBackListener);

    rescueModeProperty = new NodePseudoClassProperty(rescueModeStatusLbl);
    jogModeProperty = new NodePseudoClassProperty(jogModeStatusLbl);
    enableToRunProperty = new NodePseudoClassProperty(enableToRunStatusLbl);
    atcBypassProperty = new NodePseudoClassProperty(atcBypassStatusLbl);
    shoreSupplyProperty = new NodePseudoClassProperty(shoreSupplyStatusLbl);
    coupledProperty = new NodePseudoClassProperty(coupledStatusLbl);
    tcmsModeProperty = new NodePseudoClassProperty(tcmsAutoStatusLbl);

    updateRescueModeStatus(operatingScreenModel.getRescueMode().get());
    updateJogModeStatus(operatingScreenModel.getJogMode().get());
    updateEnableToRunStatus(operatingScreenModel.getEnableToRun().get());
    updateAtcBypassStatus(operatingScreenModel.getAtcBypass().get());
    updateShoreSupplyStatus(operatingScreenModel.getShoreSupply().get());
    updateCoupledStatus(operatingScreenModel.getCoupled().get());
    updateTcmsModeStatus(operatingScreenModel.getTcmsMode().get());
    updateNotchValue(operatingScreenModel.getNotchValue().get());
    updateOdometerValue(operatingScreenModel.getOdometerValue().get());
    
    routeTrainIdListener = (observable, oldVal, newVal) -> updateTrainNumber();
    routeScreenModel.getTrainId().addListener(routeTrainIdListener);
    updateTrainNumber();
  }

  private void updateTbcFeedBackValue()
  {

    if (headerPanelModel.getDrivingMode().get() == DrivingModeEnum.ATO.getValue())
    {
      updateNotchValue(operatingScreenModel.getTcmsTbcFeedBackValue().get());
    }
    else
    {
      updateNotchValue(operatingScreenModel.getNotchValue().get());

    }
  }

  @Override
  public void detachListeners()
  {
    operatingScreenModel.getTrainNumber().removeListener(trainNumberListener);
    operatingScreenModel.getLineVoltage().removeListener(lineVoltageListener);
    batterySystemScreenModel.getOpScreenBatteryVoltage().removeListener(batteryVoltageListener);
    operatingScreenModel.getOdometerValue().removeListener(odometerListener);
    operatingScreenModel.getTotalTrainWeight().removeListener(trainTotalWeightListener);
    operatingScreenModel.getStartStation().removeListener(startStationListener);
    operatingScreenModel.getNextStation().removeListener(nextStationListener);
    operatingScreenModel.getDestinationStation().removeListener(destinationStationListener);
    operatingScreenModel.getCurrentStation().removeListener(currentStationListener);
    operatingScreenModel.getDoorOpeningNextStation().removeListener(doorOpnNextStationListener);
    operatingScreenModel.getNotchValue().removeListener(notchListener);
    operatingScreenModel.getRescueMode().removeListener(rescueModeListener);
    operatingScreenModel.getJogMode().removeListener(jogModeListener);
    operatingScreenModel.getEnableToRun().removeListener(enableToRunListener);
    operatingScreenModel.getAtcBypass().removeListener(atcBypassListener);
    operatingScreenModel.getShoreSupply().removeListener(shoreSupplyListener);
    operatingScreenModel.getTcmsMode().removeListener(tcmsModeListener);
    operatingScreenModel.getCoupled().removeListener(coupledListener);
  }

  private void updateNotchValue(double newVal)
  {

    if (newVal < 0)
    {
      TCMSUtil.updateProgressBar(Math.abs(newVal), TCMSUIConstants.NOTCH_BRAKING_MAX_VALUE,
          TCMSUIConstants.NOTCH_BRAKING_MIN_VALUE, TCMSUIConstants.NOTCH_HEIGHT_VALUE, notchBrakingLbl);
      notchPowerLbl.setVisible(false);
      notchBrakingLbl.setVisible(true);
    }
    else if (newVal > 0)
    {
      TCMSUtil.updateProgressBar(Math.abs(newVal), TCMSUIConstants.NOTCH_POWER_MAX_VALUE,
          TCMSUIConstants.NOTCH_POWER_MIN_VALUE, TCMSUIConstants.NOTCH_HEIGHT_VALUE, notchPowerLbl);
      notchBrakingLbl.setVisible(false);
      notchPowerLbl.setVisible(true);
    }
    else
    {
      notchPowerLbl.setVisible(false);
      notchBrakingLbl.setVisible(false);
    }
  }

  private void updateTcmsModeStatus(String mode)
  {
    if (mode.isEmpty())
    {
      tcmsAutoStatusLbl.setText(TCMSModeEnum.AUTO.getModeName());
      tcmsModeProperty.set(TrainIndicatorStatusEnum.ACTIVE.getStatus());
    }
    else
    {
      tcmsAutoStatusLbl.setText(mode);
      tcmsModeProperty.set(TrainIndicatorStatusEnum.ACTIVE.getStatus());
    }
  }

  private void updateCoupledStatus(String cssClass)
  {
    coupledProperty.set(cssClass);
  }

  private void updateShoreSupplyStatus(String cssClass)
  {
    shoreSupplyProperty.set(cssClass);
  }

  private void updateAtcBypassStatus(String cssClass)
  {
    atcBypassProperty.set(cssClass);
  }

  private void updateEnableToRunStatus(String cssClass)
  {
    enableToRunProperty.set(cssClass);
  }

  private void updateJogModeStatus(String cssClass)
  {
    jogModeProperty.set(cssClass);
  }

  private void updateRescueModeStatus(String cssClass)
  {
    rescueModeProperty.set(cssClass);
  }

  private void updateDoorOpnNextStation(String doorOpeningSide)
  {
    doorOpnNextStationLbl.setText(doorOpeningSide);
  }

  private void updateNextStation(String nextStation)
  {
    if (nextStation != null)
    {
      nextStationLbl.setText(nextStation);
      if (nextStation.isEmpty())
      {
        nextStationLbl.setText(ApplicationConstants.STATION_DETAIL_NO_DATA);
      }
    }
  }

  private void updateDestinationStation(String destinationStation)
  {
    if (destinationStation != null)
    {
      destinationStationLbl.setText(destinationStation);
      if (destinationStation.isEmpty())
      {
        destinationStationLbl.setText(ApplicationConstants.STATION_DETAIL_NO_DATA);
      }
    }
  }

  private void updateCurrentStation(String currentStation)
  {
    if (currentStation != null)
    {
      currentStationLbl.setText(currentStation);
      if (currentStation.isEmpty())
      {
        currentStationLbl.setText(ApplicationConstants.STATION_DETAIL_NO_DATA);
      }
    }
  }

  private void updateStartStation(String startStation)
  {
    if (startStation != null)
    {
      startStationLbl.setText(startStation);
      if (startStation.isEmpty())
      {
        startStationLbl.setText(ApplicationConstants.STATION_DETAIL_NO_DATA);
      }
    }
  }

  private void updateTrainTotalWeight(int newVal)
  {
    trainTotalWeightLbl.setText(String.valueOf(newVal));
  }

  private void updateOdometerValue(double newVal)
  {
    odometerLbl.setText(String.valueOf(odometerFormat.format(newVal)));
  }

  private void updateBatteryVoltage(int newVal)
  {
    batteryVoltageLbl.setText(String.valueOf(newVal));
  }

  private void updateLineVoltage(double newVal)
  {
    lineVoltageLbl.setText(String.valueOf(lineVoltageFormat.format(newVal)));
  }

  private void updateTrainNumber()
  {
        
    if (routeScreenModel.getTrainId().get().equals(TCMSConstants.NO_TRAIN_ID_SELECTED))
    {
      trainNumberLbl.setText(String.valueOf(operatingScreenModel.getTrainNumber().get()));
    }
    else
    {
      trainNumberLbl.setText(routeScreenModel.getTrainId().get());
    }
  }
}
