/*
 * ================================================================== (C)
 * Copyright 2020 Oktal-Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Oktal-Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.dmi.backend.logic;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.common.dataobjects.DBTrain;
import com.sydac.common.dataobjects.DBTrainElement;
import com.sydac.mmrbem.dmi.backend.comms.CommsBinding;
import com.sydac.mmrbem.dmi.backend.logic.handler.CrewIdPopupHandler;
import com.sydac.mmrbem.dmi.backend.logic.handler.DMISettingsHandler;
import com.sydac.mmrbem.dmi.backend.logic.handler.MainScreenHandler;
import com.sydac.mmrbem.dmi.backend.logic.handler.MenuPopupHandler;
import com.sydac.mmrbem.dmi.backend.logic.handler.ScreenChangeHandler;
import com.sydac.mmrbem.dmi.backend.logic.handler.TextMessageHandler;

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
  private MainScreenHandler mainScreenHandler;

  @Autowired
  private TextMessageHandler textMessageHandler;

  @Autowired
  private SharedDataModel sharedDataModel;

  @Autowired
  private CrewIdPopupHandler crewIdPopupHandler;

  @Autowired
  private MenuPopupHandler menuPopupHandler;

  @Autowired
  private DMISettingsHandler dmiSettingsHandler;

  /** Business Logic per screen */
  private List<AbstractFunctionalLogic> functionalLogics = new ArrayList<>();

  /**
   * Instantiates a new business logic.
   */
  public void init()
  {
    DBTrain train = commsBinding.getDbScenarioTrain().getTrain();
    Iterator<DBTrainElement> ite = train.getElements().iterator();
    sharedDataModel.setTrainId(train.getTrainId());
    while (ite.hasNext())
    {
      // Finding F1 and F2 vehicle ids
      DBTrainElement dbTrainElement = ite.next();
      dbTrainElement.loadCar().getCarType().getCodeName();

    }
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

  public void attchCbtcOnboardOutputsToModels()
  {
    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attchCbtcOnboardOutputsToModels();
    }
  }

  public void attchCbtcPlatformOutputsToModels()
  {
    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attchCbtcPlatformOutputsToModels();
    }
  }

  public void attachPisBeOutputsToModels()
  {
    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attachPisBeOutputsToModels();
    }
  }

  public void attachListener()
  {
    functionalLogics.add(screenChangeHandler);
    functionalLogics.add(mainScreenHandler);
    functionalLogics.add(textMessageHandler);
    functionalLogics.add(crewIdPopupHandler);
    functionalLogics.add(menuPopupHandler);
    functionalLogics.add(dmiSettingsHandler);

    functionalLogics.stream().forEach(AbstractFunctionalLogic::attachListeners);

  }

  public void detachListeners()
  {
    if (!functionalLogics.isEmpty())
      functionalLogics.stream().forEach(AbstractFunctionalLogic::detachListeners);
  }

}
