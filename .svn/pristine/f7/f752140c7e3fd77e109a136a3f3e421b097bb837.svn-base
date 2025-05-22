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

import java.util.function.Consumer;

import com.sydac.simcomms.CObject;
import com.sydac.simcomms.framework.GatewayProvider;

/**
 * Abstract facade for component interaction.
 *  
 * @author Nazim Oliyath
 *
 */
public interface ComponentManager
{

  /**
   * register the hubInputObject
   * 
   * @param hubInputObject hub input object
   */
  public void setHubInputObject(CObject hubInputObject);

  /**
   * register the hubValuesObject
   * @param hubValuesObject hub values object
   * @param gatewayProvider gateway Provider
   */
  public void setHubValuesObject(CObject hubValuesObject, GatewayProvider gatewayProvider);

  /**
   * Sets the given value comms
   * 
   * @param commsNumber comms Number
   * @param value value
   */
  public void setNumber(String commsNumber, double value);

  /**
   * Registers the incoming component with the manager
   * @param commsNumber comms number
   * @param consumer consumer
   */
  public void register(String commsNumber, Consumer<Double> consumer);

}
