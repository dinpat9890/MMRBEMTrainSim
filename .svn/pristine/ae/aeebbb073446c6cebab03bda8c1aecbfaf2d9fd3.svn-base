/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.tcms.backend.logic;

import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


import com.sydac.mmrbem.tcms.backend.comms.CommsBinding;
import com.sydac.mmrbem.tcms.backend.logic.handler.ActiveFaultsLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.AuxPowerSupplySystemLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.BatterySystemLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.BatterySystemTestScreenLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.BrakeLoopInterlockScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.BrakeSystemCommandsScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.BrakeSystemScreenLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.BrakeSystemTestScreenLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.DoorLoopInterlocksScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.DoorStatusHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.DoorSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.DoorSystemTestScreenLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.DoorsSystemCommandsScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.EmergencyBrakeInterlockScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.EnableToRunInterlockScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.EnergyConsumptionCountersLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.FireDetectionSystemStatusScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.FireSystemTestScreenLogiHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.FooterSubmenuPopupChangeHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.HVACCommandScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.HVACSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.HVACSystemTestScreenLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.HVSystemCommandScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.HeaderPanelChangeHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.HybridModeScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.LightSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.LoggedFaultsLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.LoginScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.LowVoltageCommandScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.LowVoltageSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.MediumVoltageCommandScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.MediumVoltageSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.MiscellaniaScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.OdometerScreenChangeHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.OperatingScreenChangeHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.PISSystemTestScreenLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.PantographInterlockScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.PisSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.PropulsionSystemScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.RBCommandScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.RouteScreenLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.ScreenChangeHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.SkipStationSettingScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.SpecialModesScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.SpeedLimitInterlockScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.SystemTestScreenLogicHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.TCMSEthernetConsistNetworkScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.TCMSStatusScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.TCMSStatusScreenUpgradeHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.TemperaturesScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.TrainViewScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.VCBInterlockScreenHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.VduBrightnessChangeHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.VduSelectionChangeHandler;
import com.sydac.mmrbem.tcms.backend.logic.handler.WFLSystemScreenHandler;

/**
 * {@link BusinessLogic} segregates application business logic to specific
 * classes that handles related functionality.
 *
 */
@Service
public class BusinessLogic
{
  /** reference to commsBinding */
  @Autowired
  private CommsBinding commsBinding;

  @Autowired
  private ScreenChangeHandler screenChangeHandler;

  @Autowired
  private LoginScreenHandler loginScreenHandler;

  @Autowired
  private VduSelectionChangeHandler vduSelectionChangeHandler;

  @Autowired
  private VduBrightnessChangeHandler vduBrightnessChangeHandler;

  @Autowired
  private FooterSubmenuPopupChangeHandler footerSubmenuPopupChangeHandler;

  @Autowired
  private PropulsionSystemScreenHandler propulsionSystemScreenHandler;

  @Autowired
  private DoorSystemScreenHandler doorSystemScreenHandler;

  @Autowired
  private BatterySystemLogicHandler batterySystemLogicHandler;

  @Autowired
  private AuxPowerSupplySystemLogicHandler apsSystemLogicHandler;

  @Autowired
  private BrakeSystemScreenLogicHandler brakeSystemScreenLogicHandler;

  @Autowired
  private DoorStatusHandler doorStatusHandler;

  @Autowired
  private TrainViewScreenHandler trainViewScreenHandler;

  @Autowired
  private OperatingScreenChangeHandler operatingScreenChangeHandler;

  @Autowired
  private HeaderPanelChangeHandler headerPanelChangeHandler;

  @Autowired
  private WFLSystemScreenHandler wflSystemScreenHandler;

  @Autowired
  private ActiveFaultsLogicHandler activeFaultsLogicHandler;

  @Autowired
  private FireSystemTestScreenLogiHandler fireSystemTestScreenLogiHandler;

  @Autowired
  private EnergyConsumptionCountersLogicHandler energyConsumptionCountersLogicHandler;

  @Autowired
  private BrakeSystemTestScreenLogicHandler brakeSystemTestScreenLogicHandler;

  @Autowired
  private DoorSystemTestScreenLogicHandler doorSystemTestScreenLogicHandler;

  @Autowired
  private HVACSystemTestScreenLogicHandler hvacSystemTestScreenLogicHandler;

  @Autowired
  private PISSystemTestScreenLogicHandler pisSystemTestScreenLogicHandler;

  @Autowired
  private BatterySystemTestScreenLogicHandler batterySystemTestScreenLogicHandler;

  @Autowired
  private SystemTestScreenLogicHandler systemTestScreenLogicHandler;

  @Autowired
  private OdometerScreenChangeHandler odometerScreenChangeHandler;

  @Autowired
  private LightSystemScreenHandler lightSystemScreenHandler;

  @Autowired
  private HVACSystemScreenHandler hvacSystemScreenHandler;

  @Autowired
  private RouteScreenLogicHandler routeScreenLogicHandler;

  @Autowired
  private FireDetectionSystemStatusScreenHandler fireDetectionSystemStatusScreenHandler;

  @Autowired
  private LowVoltageCommandScreenHandler lowVoltageCommandScreenHandler;

  @Autowired
  private LowVoltageSystemScreenHandler lowVoltageSystemScreenHandler;

  @Autowired
  private TCMSEthernetConsistNetworkScreenHandler tcmsEthernetConsistNetworkScreenHandler;

  @Autowired
  private MediumVoltageSystemScreenHandler mediumVoltageSystemScreenHandler;

  @Autowired
  private SpeedLimitInterlockScreenHandler speedLimitInterlockScreenHandler;

  @Autowired
  private PantographInterlockScreenHandler pantographInterlockScreenHandler;

  @Autowired
  private VCBInterlockScreenHandler vcbInterlockScreenHandler;

  @Autowired
  private DoorLoopInterlocksScreenHandler doorLoopInterlocksScreenHandler;

  @Autowired
  private EmergencyBrakeInterlockScreenHandler ebLoopInterlockScreenHandler;

  @Autowired
  private TemperaturesScreenHandler temperaturesScreenHandler;

  @Autowired
  private BrakeSystemCommandsScreenHandler brakeSystemCommandsScreenHandler;

  @Autowired
  private DoorsSystemCommandsScreenHandler doorsSystemCommandsScreenHandler;

  @Autowired
  private HybridModeScreenHandler hybridModeScreenHandler;

  @Autowired
  private MiscellaniaScreenHandler miscellaniaScreenHandler;

  @Autowired
  private TCMSStatusScreenHandler tcmsStatusScreenHandler;

  @Autowired
  private HVSystemCommandScreenHandler highVoltageSystemCommandScreenHandler;

  @Autowired
  private SpecialModesScreenHandler specialModesScreenHandler;

  @Autowired
  private LoggedFaultsLogicHandler loggedFaultsLogicHandler;

  @Autowired
  private RBCommandScreenHandler rbCommandScreenHandler;
  
  @Autowired
  private MediumVoltageCommandScreenHandler mediumVoltageCommandScreenHandler;
  
  @Autowired
  private PisSystemScreenHandler pisSystemScreenHandler;
  
  @Autowired
  private HVACCommandScreenHandler hVACCommandScreenHandler;
  
  @Autowired
  private TCMSStatusScreenUpgradeHandler tcmsStatusScreenUpgradeHandler;
  
  @Autowired
  private   EnableToRunInterlockScreenHandler enableToRunInterlockScreenHandler;
  
  @Autowired
  private BrakeLoopInterlockScreenHandler brakeLoopInterlockScreenHandler;
  
  @Autowired
  private  SkipStationSettingScreenHandler skipStationSettingScreenHandler;

  /** Business Logic per screen */
  private List<AbstractFunctionalLogic> functionalLogics = new CopyOnWriteArrayList<>();

  /**
   * Instantiates a new business logic.
   *
   */
  public void init()
  {
    // sharedDataModel.setTrainId(commsBinding.getScenarioTrain().getScenarioTrainId());
  }

  /**
   * Performs business logic processing to determine the appropriate outputs to
   * the user.
   * <p>
   * This method must be called whenever something of note has happened, e.g.
   * when an input has changed, and periodically (at a minimum of 10Hz), so that
   * time-based events can occur.
   *
   * @param aSimTime
   *          The current simulated time in milliseconds.
   */
  public void process(long aSimTime)
  {
    getFunctionalLogics().forEach(functionalLogic -> functionalLogic.process(aSimTime));
  }

  /**
   * Detach all model on vehicle destruction
   * 
   * @param aVehicleIndex
   *          vehicle index
   */
  public void onVehicleObjectDestruction(int aVehicleIndex)
  {
    if (aVehicleIndex == commsBinding.getActiveVehicleIndex())
    {
      getFunctionalLogics().forEach(AbstractFunctionalLogic::detachListeners);
    }
  }

  protected List<AbstractFunctionalLogic> getFunctionalLogics()
  {
    return functionalLogics;
  }

  public void attachListener()
  {
    functionalLogics.add(screenChangeHandler);
    functionalLogics.add(loginScreenHandler);
    functionalLogics.add(vduSelectionChangeHandler);
    functionalLogics.add(vduBrightnessChangeHandler);
    functionalLogics.add(footerSubmenuPopupChangeHandler);
    functionalLogics.add(propulsionSystemScreenHandler);
    functionalLogics.add(doorSystemScreenHandler);
    functionalLogics.add(batterySystemLogicHandler);
    functionalLogics.add(apsSystemLogicHandler);
    functionalLogics.add(brakeSystemScreenLogicHandler);
    functionalLogics.add(doorStatusHandler);
    functionalLogics.add(trainViewScreenHandler);
    functionalLogics.add(operatingScreenChangeHandler);
    functionalLogics.add(headerPanelChangeHandler);
    functionalLogics.add(wflSystemScreenHandler);
    functionalLogics.add(activeFaultsLogicHandler);
    functionalLogics.add(fireSystemTestScreenLogiHandler);
    functionalLogics.add(energyConsumptionCountersLogicHandler);
    functionalLogics.add(brakeSystemTestScreenLogicHandler);
    functionalLogics.add(doorSystemTestScreenLogicHandler);
    functionalLogics.add(hvacSystemTestScreenLogicHandler);
    functionalLogics.add(pisSystemTestScreenLogicHandler);
    functionalLogics.add(batterySystemTestScreenLogicHandler);
    functionalLogics.add(systemTestScreenLogicHandler);
    functionalLogics.add(odometerScreenChangeHandler);
    functionalLogics.add(lightSystemScreenHandler);
    functionalLogics.add(hvacSystemScreenHandler);
    functionalLogics.add(routeScreenLogicHandler);
    functionalLogics.add(fireDetectionSystemStatusScreenHandler);
    functionalLogics.add(lowVoltageCommandScreenHandler);
    functionalLogics.add(lowVoltageSystemScreenHandler);
    functionalLogics.add(tcmsEthernetConsistNetworkScreenHandler);
    functionalLogics.add(mediumVoltageSystemScreenHandler);
    functionalLogics.add(speedLimitInterlockScreenHandler);
    functionalLogics.add(pantographInterlockScreenHandler);
    functionalLogics.add(vcbInterlockScreenHandler);
    functionalLogics.add(doorLoopInterlocksScreenHandler);
    functionalLogics.add(ebLoopInterlockScreenHandler);
    functionalLogics.add(temperaturesScreenHandler);
    functionalLogics.add(brakeSystemCommandsScreenHandler);
    functionalLogics.add(doorsSystemCommandsScreenHandler);
    functionalLogics.add(hybridModeScreenHandler);
    functionalLogics.add(miscellaniaScreenHandler);
    functionalLogics.add(tcmsStatusScreenHandler);
    functionalLogics.add(highVoltageSystemCommandScreenHandler);
    functionalLogics.add(specialModesScreenHandler);
    functionalLogics.add(loggedFaultsLogicHandler);
    functionalLogics.add(rbCommandScreenHandler);
    functionalLogics.add(mediumVoltageCommandScreenHandler);
    functionalLogics.add(pisSystemScreenHandler);
    functionalLogics.add(hVACCommandScreenHandler);
    functionalLogics.add(tcmsStatusScreenUpgradeHandler);
    functionalLogics.add(enableToRunInterlockScreenHandler);
    functionalLogics.add(brakeLoopInterlockScreenHandler);
    functionalLogics.add(skipStationSettingScreenHandler);
    // add handlers to the list functionalLogics
    functionalLogics.stream().forEach(AbstractFunctionalLogic::attachListeners);
  }

  public void detachListeners()
  {
    if (!functionalLogics.isEmpty())
      functionalLogics.stream().forEach(AbstractFunctionalLogic::detachListeners);
  }
  public void attachOHPOutPutsToModels()
  {

    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attachOHPOutPutsToModels();
    }

  }

  public void attachIntercomOutPutsToModels()
  {

    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attachIntercomOutPutsToModels();
    }

  }
}
