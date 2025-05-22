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

import java.util.Observable;

import com.sydac.common.febe.frontend.IHubObjectCallback;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.framework.GatewayProvider;

/**
 * 
 * @author Nazim Oliyath
 * 
 */
public class HubObjectProvider extends Observable implements IHubObjectCallback
{
  public static final String HUB_INPUT_CHANGED = "HUB_INPUT_CHANGED"; //$NON-NLS-1$

  public static final String HUB_OUTPUT_CHANGED = "HUB_OUTPUT_CHANGED"; //$NON-NLS-1$

  public static final String HUB_VALUES_CHANGED = "HUB_VALUES_CHANGED"; //$NON-NLS-1$
  
  public static final String HUB_DESTROYED = "HUB_DESTROYED"; //$NON-NLS-1$

  private CObject hubInput;

  private CObject hubOutput;

  private CObject hubValues;
  
  private final GatewayProvider gatewayProvider;
  
  public HubObjectProvider(GatewayProvider gatewayProvider)
  {
    this.gatewayProvider = gatewayProvider;
  }

  /**
   * 
   * @return the gateway
   */
  public final GatewayProvider getGatewayProvider()
  {
    return gatewayProvider;
  }

  /**
   * @return the hubInput
   */
  public final CObject getHubInput()
  {
    return hubInput;
  }

  /**
   * @return the hubOutput
   */
  public final CObject getHubOutput()
  {
    return hubOutput;
  }

  /**
   * @return the hubValues
   */
  public final CObject getHubValues()
  {
    return hubValues;
  }

  @Override
  public void onHubInputCreation(CObject hubInput)
  {
    this.hubInput = hubInput;
    doNotify(HUB_INPUT_CHANGED);
  }

  @Override
  public void onHubOutputCreation(CObject hubOutput)
  {
    this.hubOutput = hubOutput;
    doNotify(HUB_OUTPUT_CHANGED);
  }

  @Override
  public void onHubValuesCreation(CObject hubValues)
  {
    this.hubValues = hubValues;
    doNotify(HUB_VALUES_CHANGED);
  }

  @Override
  public void onHubObjectDestruction()
  {
    doNotify(HUB_DESTROYED);
  }

  private void doNotify(String whatChanged)
  {
    setChanged();
    notifyObservers(whatChanged);
  }

}