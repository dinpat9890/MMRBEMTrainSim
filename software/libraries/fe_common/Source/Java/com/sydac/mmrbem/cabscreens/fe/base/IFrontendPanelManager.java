/*
 * ==================================================================
 * 
 * (C) Copyright 2016 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */

package com.sydac.mmrbem.cabscreens.fe.base;

import com.sydac.common.febe.frontend.FrontendModule;
import com.sydac.common.febe.frontend.IHubObjectCallback;
import com.sydac.common.sessiondata.BaseScenarioData;
import com.sydac.common.sessiondata.BaseSessionData;
import com.sydac.simcomms.Gateway;

/**
 * Manages the lifetime of and connections between GUI and Comms objects.
 *
 * @author Stanley Mladenov
 */
@SuppressWarnings("deprecation")
public interface IFrontendPanelManager
{

  /**
   * Notifies this object that a frontend will be required for the given
   * scenario/session/car.
   * <p>
   * Called for each frontend that is needed.
   * <p>
   * Should not create additional panels for a session once
   * {@link #startFrontends(String, Gateway, BaseScenarioData, BaseSessionData, boolean, IHubObjectCallback)}
   * has been called, unless the new frontends can be dynamically started.
   *
   * @param aGateway
   *          For accessing Comms.
   * @param aScenarioData
   *          Information about this scenario.
   * @param aSessionData
   *          Describes the session that will be joined.
   * @param carIndex
   *          The index of the car that we need a frontend for.
   */
  public void prepareFrontend(Gateway aGateway, BaseScenarioData aScenarioData, BaseSessionData aSessionData,
      int carIndex);

  /**
   * Begins monitoring Comms. Called once per session.
   *
   * @param aApplicationName
   *          For giving the Comms object a human-readable name to help identify
   *          it in CommsShow.
   * @param aGateway
   *          For accessing Comms.
   * @param aScenarioData
   *          Information about this scenario.
   * @param aSessionData
   *          Information about this session.
   * @param aIsSimulation
   *          Indicates if this is a simulation or replay.
   * @param aCallback
   *          Optional. A callback to monitor for hub object
   *          creation/destruction. Implementers should note that this is used
   *          by {@link FrontendModule} to determine when to make the
   *          application visible.
   */
  public void startFrontends(String aApplicationName, Gateway aGateway, BaseScenarioData aScenarioData,
      BaseSessionData aSessionData, boolean aIsSimulation, IHubObjectCallback aCallback);

  /**
   * Does end of session cleanup. Panels should now be discarded.
   */
  public void resetSession();

}
