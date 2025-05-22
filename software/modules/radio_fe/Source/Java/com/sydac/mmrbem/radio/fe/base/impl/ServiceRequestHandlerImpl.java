/*
 * ==================================================================
 * 
 * (C) Copyright 2022 Sydac Pty Ltd., all rights reserved. This is unpublished
 * proprietary source code of Sydac. The copyright notice above does not
 * evidence any actual or intended publication of such source code.
 * 
 * ==================================================================
 */
package com.sydac.mmrbem.radio.fe.base.impl;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import com.sydac.core.runtimedata.HubIO;
import com.sydac.mmrbem.radio.common.ScreenId;
import com.sydac.mmrbem.radio.fe.base.ServiceRequestHandler;
import com.sydac.peer.application.SimplePropertySetter;
import com.sydac.project.runtimedata.ProjectObjectConstants.RadioInputs;
import com.sydac.simcomms.CObject;
import com.sydac.simcomms.framework.GatewayProvider;

public class ServiceRequestHandlerImpl implements ServiceRequestHandler
{

  private SimplePropertySetter propertySetter;

  private ScheduledExecutorService scheduledExecutorService = Executors.newSingleThreadScheduledExecutor();

  @Override
  public void setHubValuesObject(CObject hubValues, GatewayProvider gatewayProvider)
  {
    this.propertySetter = new SimplePropertySetter(gatewayProvider.getGateway(), hubValues);
  }

  /*
   * Sends pulse value for given comms number. Sets the number to 'set' value
   * and then to 'reset' value after 100ms.
   */
  private void sendPulseRequest(final String number, final double set, final double reset)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), set);
    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(
        () -> propertySetter.setNumber(HubIO.createIOPropertyName(number), reset), 100,
        TimeUnit.MILLISECONDS);

  }

  /*
   * Sends pulse (1, 0) value for given comms number.
   */
  private void sendPulseRequest(final String number)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), true);
    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(
        () -> propertySetter.setNumber(HubIO.createIOPropertyName(number), false), 100,
        TimeUnit.MILLISECONDS);

  }

  /*
   * Sets value for given comms number.
   */
  @Override
  public void sendRequest(final String number, Integer val)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), val);
  }

  @Override
  public void sendButtonClickRequest(String buttonName)
  {
    sendPulseRequest(buttonName);
  }

  @Override
  public void sendRequest(String number, Double val)
  {
    propertySetter.setNumber(HubIO.createIOPropertyName(number), val);
    // reset the number after a delay of 100ms.
    scheduledExecutorService.schedule(
        () -> propertySetter.setNumber(HubIO.createIOPropertyName(number), false), 100,
        TimeUnit.MILLISECONDS);
  }

  @Override
  public void sendScreenChangeRequest(ScreenId screenId)
  {
    sendPulseRequest(RadioInputs.SCREEN_CHANGE_REQUEST, screenId.getId(), -1);
  }

}