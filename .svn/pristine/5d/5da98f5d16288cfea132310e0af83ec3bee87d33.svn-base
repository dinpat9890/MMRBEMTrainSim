/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.psd.backend.logic;

import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


import com.sydac.mmrbem.psd.backend.comms.CommsBinding;
import com.sydac.mmrbem.psd.backend.logic.handler.PsdPanelHandler;
import com.sydac.mmrbem.psd.backend.logic.handler.ScreenChangeHandler;

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
  private PsdPanelHandler psdPanelHandler;
  
  @Autowired
  private ScreenChangeHandler screenChangeHandler;
 
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
    

    // add handlers to the list functionalLogics
    functionalLogics.add(screenChangeHandler);
    functionalLogics.add(psdPanelHandler);
    functionalLogics.stream().forEach(AbstractFunctionalLogic::attachListeners);
  }

  public void detachListeners()
  {
    if (!functionalLogics.isEmpty())
      functionalLogics.stream().forEach(AbstractFunctionalLogic::detachListeners);
  }
  public void attchCbtcPlatformOutputsToModels()
  {
    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attchCbtcPlatformOutputsToModels();
    }
  }
  
  
  public void attchPiSToModels()
  {
    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.bindPisOutputsToModel();
    }
  }
  
  public void attchCbtcOnboardOutputsToModels()
  {
    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attchCbtcOnboardOutputsToModels();
    }
  }
}
