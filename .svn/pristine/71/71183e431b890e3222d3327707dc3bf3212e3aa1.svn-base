/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.papis.backend.logic;

import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.mmrbem.papis.backend.comms.CommsBinding;
import com.sydac.mmrbem.papis.backend.logic.handler.EmergencyInformationScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.MainInterfaceScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.ManualModeAnnouncementScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.NextStationSelectionScreensHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.PassengerAlarmScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.PecuIsolateScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.RouteSettingScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.ScreenChangeHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.SkipStationSettingScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.SpecialInformationScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.StationSelectionScreensHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.SystemSettingsScreenHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.TerminalStationSelectionScreensHandler;
import com.sydac.mmrbem.papis.backend.logic.handler.TrainIdSettingScreenHandler;
import com.sydac.mmrbem.papis.common.ScreenId;

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
  private MainInterfaceScreenHandler mainInterfaceScreenHandler;

  @Autowired
  private SystemSettingsScreenHandler systemSettingsScreenHandler;

  @Autowired
  private TrainIdSettingScreenHandler trainIdSettingScreenHandler;

  @Autowired
  private RouteSettingScreenHandler routeSettingScreenHandler;

  @Autowired
  private StationSelectionScreensHandler stationSelectionScreensHandler;

  @Autowired
  private SkipStationSettingScreenHandler skipStationSettingScreenHandler;

  @Autowired
  private ManualModeAnnouncementScreenHandler manualModeAnnouncementScreenHandler;

  @Autowired
  private SpecialInformationScreenHandler specialInformationScreenHandler;

  @Autowired
  private EmergencyInformationScreenHandler emergencyInformationScreenHandler;

  @Autowired
  private PassengerAlarmScreenHandler passengerAlarmScreenHandler;

  @Autowired
  private TerminalStationSelectionScreensHandler terminalStationSelectionScreensHandler;

  @Autowired
  private NextStationSelectionScreensHandler nextStationSelectionScreensHandler;
  
  @Autowired
  private PecuIsolateScreenHandler pecuIsolateScreenHandler;

  /** Business Logic per screen */
  private List<AbstractFunctionalLogic> functionalLogics = new CopyOnWriteArrayList<>();

  /**
   * Instantiates a new business logic.
   *
   */
  public void init()
  {
    // sharedDataModel.setTrainId(commsBinding.getScenarioTrain().getScenarioTrainId());
    screenChangeHandler.register(ScreenId.MAIN_INTERFACE_SCREEN, mainInterfaceScreenHandler);
    screenChangeHandler.register(ScreenId.START_STATION_SELECTION_SCREEN, stationSelectionScreensHandler);
    screenChangeHandler.register(ScreenId.TERMINAL_STATION_SELECTION_SCREEN,
        terminalStationSelectionScreensHandler);
    screenChangeHandler.register(ScreenId.NEXT_STATION_SELECTION_SCREEN, nextStationSelectionScreensHandler);
    screenChangeHandler.register(ScreenId.SPECIAL_INFORMATION_SCREEN, specialInformationScreenHandler);
    screenChangeHandler.register(ScreenId.EMERGENCY_INFORMATION_SCREEN, emergencyInformationScreenHandler);
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
    functionalLogics.add(mainInterfaceScreenHandler);
    functionalLogics.add(systemSettingsScreenHandler);
    functionalLogics.add(trainIdSettingScreenHandler);
    functionalLogics.add(routeSettingScreenHandler);
    functionalLogics.add(stationSelectionScreensHandler);
    functionalLogics.add(skipStationSettingScreenHandler);
    functionalLogics.add(manualModeAnnouncementScreenHandler);
    functionalLogics.add(specialInformationScreenHandler);
    functionalLogics.add(emergencyInformationScreenHandler);
    functionalLogics.add(passengerAlarmScreenHandler);
    functionalLogics.add(terminalStationSelectionScreensHandler);
    functionalLogics.add(nextStationSelectionScreensHandler);
    functionalLogics.add(pecuIsolateScreenHandler);

    // add handlers to the list functionalLogics
    functionalLogics.stream().forEach(AbstractFunctionalLogic::attachListeners);
  }

  public void detachListeners()
  {
    if (!functionalLogics.isEmpty())
      functionalLogics.stream().forEach(AbstractFunctionalLogic::detachListeners);
  }

  public void attachPISBEOutputModels()
  {
    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attachPISBEOutputModels();
    }

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
