/*
 * ==================================================================
 *
 * (C) Copyright 2022 Oktal Sydac Pvt Ltd., all rights reserved. This is
 * unpublished proprietary source code of Sydac. The copyright notice above does
 * not evidence any actual or intended publication of such source code.
 * ==================================================================
 */
package com.sydac.mmrbem.radio.backend.logic;

import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.sydac.mmrbem.radio.backend.comms.CommsBinding;
import com.sydac.mmrbem.radio.backend.logic.handler.CallInfoHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.CallRequestAndNavHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.ContactListScreenHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.KeyPadHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.MessageInBoxListScreenHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.MessageMainScreenHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.MessageOutBoxListScreenHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.PowerMenuAndNavHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.ScreenChangeHandler;
import com.sydac.mmrbem.radio.backend.logic.handler.StartupSequenceHandler;
import com.sydac.mmrbem.radio.common.ScreenId;

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
  private StartupSequenceHandler sequenceHandler;

  @Autowired
  private KeyPadHandler keyPadHandler;

  @Autowired
  private PowerMenuAndNavHandler powerMenuAndNavHandler;

  @Autowired
  private CallRequestAndNavHandler callRequestAndNavHandler;

  @Autowired
  private CallInfoHandler callInfoHandler;

  @Autowired
  private MessageMainScreenHandler messageMainScreenHandler;

  @Autowired
  private MessageInBoxListScreenHandler messageInBoxListScreenHandler;

  @Autowired
  private MessageOutBoxListScreenHandler messageOutBoxListScreenHandler;

  @Autowired
  private ContactListScreenHandler contactListScreenHandler;

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
    functionalLogics.add(sequenceHandler);
    functionalLogics.add(keyPadHandler);
    functionalLogics.add(powerMenuAndNavHandler);
    functionalLogics.add(callRequestAndNavHandler);
    functionalLogics.add(callInfoHandler);
    functionalLogics.add(messageMainScreenHandler);
    functionalLogics.add(messageInBoxListScreenHandler);
    functionalLogics.add(messageOutBoxListScreenHandler);
    functionalLogics.add(contactListScreenHandler);

    screenChangeHandler.register(ScreenId.MESSAGE_SCREEN, messageMainScreenHandler);

    screenChangeHandler.register(ScreenId.MESSAGE_INBOX_LIST_SCREEN, messageInBoxListScreenHandler);
    screenChangeHandler.register(ScreenId.MESSAGE_OUTBOX_LIST_SCREEN, messageOutBoxListScreenHandler);
    screenChangeHandler.register(ScreenId.CONTACT_SCREEN, contactListScreenHandler);
    screenChangeHandler.register(ScreenId.OUTBOX_MESSAGE_SCREEN, messageOutBoxListScreenHandler);

    // add handlers to the list functionalLogics
    functionalLogics.stream().forEach(AbstractFunctionalLogic::attachListeners);
  }

  public void detachListeners()
  {
    if (!functionalLogics.isEmpty())
      functionalLogics.stream().forEach(AbstractFunctionalLogic::detachListeners);
  }

  public void attachRadioIntercomOutputModels()
  {
    for (AbstractFunctionalLogic functionalLogic : functionalLogics)
    {
      functionalLogic.attachRadioIntercomOutputModels();
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
